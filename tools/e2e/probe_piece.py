#!/usr/bin/env python3
"""probe_piece.py — map the ACTIVE PIECE struct fields by input, in gameplay.

The active piece is a heap struct reached via g_currentPiece_ptr @ 0x8011FB70 (it
lives around 0x8023xxxx, NOT in the static globals band). This probe dereferences that
pointer and reports which *offsets in the piece struct* each movement input reliably
moves, filtering gravity (which moves a field on its own) as control noise.

The strong signal we key on: an offset that RIGHT increases and LEFT decreases (or vice
versa) is the piece column/X. A field that A changes but LEFT/RIGHT don't is rotation.

Skips START (would pause) and hard-drop-y inputs that lock the piece and reallocate the
pointer mid-probe. Re-reads the pointer before every tap so a respawn can't misattribute.

    python3 tools/e2e/probe_piece.py            # default: LEFT/RIGHT/A/B/DOWN
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep
from e2e_helpers import reach_gameplay

PIECE_PTR = 0x8011FB70           # g_currentPiece_ptr
WIN_LO, WIN_HI = -0x20, 0x200    # offsets around the piece base we consider "the struct"
# Region must cover the gameplay heap where the piece/cubes/minos live. The heap base
# varies per run (seen at 0x80231e78 and 0x80285600), so scan a generous 1 MB window.
REGION = (0x80200000, 0x100000)  # 0x80200000 .. 0x80300000


def probe():
    inputs = [("LEFT", Keys.LEFT), ("RIGHT", Keys.RIGHT), ("A", Keys.A),
              ("B", Keys.B), ("DOWN", Keys.DOWN)]
    with Game(region=REGION) as g:
        reach_gameplay(g)
        base = g.read("piece_ptr")
        print(f"# gameplay scene={g.read('scene')}  piece_base=0x{base:08X}  region={hex(REGION[0])}:{REGION[1]:#x}\n")

        # gravity / animation noise floor: offsets that move with no input
        noise = set()
        for _ in range(8):
            b = g.read("piece_ptr")
            for a, _o, _n in g.find_changes(lambda: _sleep(0.4), settle=0.4):
                if WIN_LO <= a - b <= WIN_HI:
                    noise.add(a - b)
        print(f"# gravity noise offsets (subtracted): {sorted(hex(x) for x in noise)}\n")

        results = {}
        for name, sc in inputs:
            sets = []
            for _ in range(3):
                b = g.read("piece_ptr")
                changed = {}
                for a, o, n in g.find_changes(lambda: g.tap(sc), settle=0.4):
                    off = a - b
                    if WIN_LO <= off <= WIN_HI and off not in noise:
                        changed[off] = (o, n)
                sets.append(changed)
                # nudge back toward center so LEFT/RIGHT don't pin against a wall
                if name == "LEFT":  g.tap(Keys.RIGHT)
                if name == "RIGHT": g.tap(Keys.LEFT)
            common = set(sets[0])
            for s in sets[1:]:
                common &= set(s)
            results[name] = {off: sets[-1][off] for off in sorted(common)}
            print(f"[{name}] {len(common)} reliable offset(s)")
            for off in sorted(common):
                o, n = sets[-1][off]
                arrow = "+" if (n > o) else ("-" if n < o else "=")
                print(f"    +0x{off & 0xFFFF:04X}  {o:#010x} -> {n:#010x}  ({arrow})")

        # opposites: an offset LEFT and RIGHT both move in OPPOSITE directions = column/X
        print("\n# LEFT/RIGHT opposite-direction offsets (candidate piece column/X):")
        lr = set(results.get("LEFT", {})) & set(results.get("RIGHT", {}))
        for off in sorted(lr):
            lo, ln = results["LEFT"][off]
            ro, rn = results["RIGHT"][off]
            if (ln - lo) * (rn - ro) < 0:
                print(f"    +0x{off & 0xFFFF:04X}  LEFT {lo:#x}->{ln:#x}   RIGHT {ro:#x}->{rn:#x}")
        arot = set(results.get("A", {})) - set(results.get("LEFT", {})) - set(results.get("RIGHT", {}))
        print(f"# A-only offsets (candidate rotation): {[f'+0x{o & 0xFFFF:04X}' for o in sorted(arot)]}")


if __name__ == "__main__":
    probe()
