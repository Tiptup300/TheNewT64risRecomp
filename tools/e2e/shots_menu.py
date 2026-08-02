#!/usr/bin/env python3
"""Capture screenshots of the actual menu screens (RAM + picture together)."""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep


def snap(g, name):
    p = g.shot(name)
    print(f"   [{name}] scene={g.read('scene')} cursor={g.read('menu_cursor')} -> {p}")
    return p


def main():
    with Game() as g:
        g.wait_alive(40)
        g.wait_for("scene", lambda v: v == 3, 40, desc="attract")
        _sleep(1.0); snap(g, "01_attract")
        g.press(Keys.START, hold=3.0)
        g.wait_for("scene", lambda v: v == 4, 15, desc="menu hub")
        _sleep(1.0); snap(g, "02_mainmenu")
        # capture the highlight at each of the 3 cursor positions
        snap(g, "03_item_A")
        g.press(Keys.DOWN, hold=0.25); _sleep(0.4); snap(g, "04_item_B")
        g.press(Keys.DOWN, hold=0.25); _sleep(0.4); snap(g, "05_item_C")
        # enter the first item's submenu
        g.press(Keys.DOWN, hold=0.25); _sleep(0.4)   # back to item A
        g.press(Keys.A, hold=0.4); _sleep(1.2); snap(g, "06_submenu_A")
        g.press(Keys.B, hold=0.4); _sleep(1.0)
    print("done.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
