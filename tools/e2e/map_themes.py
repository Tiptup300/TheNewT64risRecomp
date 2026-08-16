#!/usr/bin/env python3
"""Map the engine's real theme order: for each stage index 0..7, drive the stage-select
mod to pick it, launch, and screenshot the gameplay environment. The 0x8011EEF8 byte is the
proven environment selector; this tells us which theme each index actually loads so the
mod's STAGE_NAMES can be put in the correct order.
"""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep
from e2e_helpers import reach_single_screen

SCRATCH = (0x807FFF00, 0x40)
STATE, CURSOR = 0x807FFF14, 0x807FFF18


def sc(g, addr):
    b = g.snapshot(); i = addr - SCRATCH[0]
    return int.from_bytes(b[i:i+4], "little")


def open_screen(g):
    for _ in range(8):
        g.tap(Keys.DOWN); _sleep(0.3); g.tap(Keys.A)
        for _ in range(12):
            if sc(g, STATE) == 1:
                return True
            if g.read("scene") == 9:
                return False
            _sleep(0.2)
    return sc(g, STATE) == 1


def run_one(idx):
    with Game(mods=["tnt_intro_skip", "tnt_stage_select"], region=SCRATCH) as g:
        reach_single_screen(g); _sleep(0.8)
        if not open_screen(g):
            print(f"idx{idx}: could not open"); return
        for _ in range(12):
            if sc(g, CURSOR) == idx:
                break
            g.tap(Keys.DOWN); _sleep(0.35)
        launched = False
        for _try in range(4):
            g.tap(Keys.A)
            for _ in range(15):
                if g.read("scene") == 9:
                    launched = True; break
                _sleep(0.2)
            if launched:
                break
        _sleep(1.2)
        shot = g.shot(f"theme_idx{idx}")
        print(f"idx{idx}: cursor={sc(g, CURSOR)} theme_byte={g.read('theme')} "
              f"launched={launched} shot={shot}")


def main():
    only = [int(a) for a in sys.argv[1:]] or list(range(8))
    for idx in only:
        run_one(idx)
    return 0


if __name__ == "__main__":
    # theme byte watch injected via DEFAULT+extra
    from harness import DEFAULT_WATCHES
    DEFAULT_WATCHES["theme"] = (0x8011EEF8, 1)
    sys.exit(main())
