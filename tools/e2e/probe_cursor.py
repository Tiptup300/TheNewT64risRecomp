#!/usr/bin/env python3
"""Probe the main-menu cursor: reach the menu, step DOWN then UP, log the cursor
proxy (menu_cursor) each step to reveal the item count and wrap behavior."""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep


def main():
    with Game() as g:
        g.wait_alive(40)
        g.wait_for("scene", lambda v: v == 3, 40, desc="attract")
        g.press(Keys.START, hold=3.0)
        g.wait_for("scene", lambda v: v == 4, 15, desc="menu hub")
        _sleep(1.0)
        seq = [("start", g.read("menu_cursor"))]
        for i in range(8):
            g.press(Keys.DOWN, hold=0.25)
            _sleep(0.25)
            seq.append((f"down{i+1}", g.read("menu_cursor")))
        for i in range(8):
            g.press(Keys.UP, hold=0.25)
            _sleep(0.25)
            seq.append((f"up{i+1}", g.read("menu_cursor")))
        print("cursor (menu_cursor @0x800D3D00) through DOWN x8 then UP x8:")
        for label, v in seq:
            print(f"   {label:>7}: {v}")
        vals = [v for _, v in seq if v is not None]
        print(f"distinct values: {sorted(set(vals))}  (range hints at menu item count)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
