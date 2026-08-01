#!/usr/bin/env python3
"""Map what each of the 3 main-menu items opens: for each cursor position, press A,
capture the submenu's signature (scene_main_state + which named scene globals it
sets), then B back out. Detects if an item starts a game (crash / leaves scene 4)."""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep

REPO = Path(__file__).resolve().parent.parent.parent
REGION = (0x800CE000, 0x51000)


def load_names():
    names = {}
    for line in (REPO / "tnt.datasyms.toml").read_text().splitlines():
        m = re.search(r'name = "([^"]+)", vram = (0x[0-9A-Fa-f]+)', line)
        if m and not m.group(1).startswith("D_"):
            names[int(m.group(2), 16)] = m.group(1)
    return names


def nearest(names, addr):
    best = max((a for a in names if a <= addr), default=None)
    if best is None or addr - best > 0x40:
        return None
    return names[best]


def main():
    names = load_names()
    with Game(region=REGION) as g:
        g.wait_alive(40)
        g.wait_for("scene", lambda v: v == 3, 40, desc="attract")
        g.press(Keys.START, hold=3.0)
        g.wait_for("scene", lambda v: v == 4, 15, desc="menu hub")
        _sleep(1.0)

        # visit each cursor position (main menu cycles 3->5->6)
        for i in range(3):
            cur = g.read("menu_cursor")
            print(f"\n### main-menu item {i} (cursor={cur}) ###")
            enter = g.find_changes(lambda: g.press(Keys.A, hold=0.4))
            if g.crashed():
                print(f"   A -> CRASH (code {g.proc.poll()}) — this item starts a game/"
                      f"unsafe scene. Stopping.")
                break
            sc = g.read("scene")
            named_hits = sorted({nearest(names, a) for a, _, _ in enter
                                 if nearest(names, a) and "g_scene" in (nearest(names, a) or "")})
            print(f"   A -> scene={sc} scene_main_state={g.read('scene_main_state')} "
                  f"({len(enter)} words changed)")
            print(f"   named scene globals touched: {named_hits[:12]}")
            # back out
            g.press(Keys.B, hold=0.4); _sleep(0.8)
            if g.crashed():
                print("   B -> crashed backing out"); break
            print(f"   B -> back to scene={g.read('scene')} cursor={g.read('menu_cursor')}")
            g.press(Keys.DOWN, hold=0.25); _sleep(0.3)  # advance to next item
    print("\ndone.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
