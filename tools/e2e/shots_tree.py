#!/usr/bin/env python3
"""Screenshot each reachable main-menu submenu (2 controllers so MULTI PLAYER is
selectable). Enters each item with A, captures, backs out with B — no game start."""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep

ITEMS = [(3, "1_oneplayer"), (4, "2_multiplayer"), (5, "3_wonders"), (6, "4_options")]


def goto(g, target, max_taps=8):
    for _ in range(max_taps):
        if g.read("menu_cursor") == target:
            return True
        g.tap(Keys.DOWN)
    return g.read("menu_cursor") == target


def main():
    with Game(controllers=2) as g:
        g.wait_alive(40)
        g.wait_for("scene", lambda v: v == 3, 40, desc="attract")
        g.press(Keys.START, hold=3.0)
        g.wait_for("scene", lambda v: v == 4, 15, desc="menu hub")
        _sleep(1.0)
        g.shot("00_mainmenu")
        for cur, name in ITEMS:
            if not goto(g, cur):
                print(f"   could not reach cursor {cur} ({name}); at {g.read('menu_cursor')}")
                continue
            g.shot(f"{name}_highlight")
            g.tap(Keys.A); _sleep(1.3)
            if g.crashed():
                print(f"   {name}: A -> CRASH (code {g.proc.poll()})"); break
            sc = g.read("scene")
            g.shot(f"{name}_entered")
            print(f"   {name}: A -> scene={sc}, captured")
            # peek one step down inside the submenu, then back out
            g.tap(Keys.DOWN); _sleep(0.5); g.shot(f"{name}_inside")
            g.tap(Keys.B); _sleep(1.0)
            if g.crashed():
                print(f"   {name}: B -> crash"); break
            # if we changed scene (e.g. wonders scene 7), press B again to return
            if g.read("scene") != 4:
                g.tap(Keys.B); _sleep(1.0)
            print(f"   {name}: B -> back to scene={g.read('scene')} cursor={g.read('menu_cursor')}")
    print("done. shots in /tmp/tnt_e2e/*.png")
    return 0


if __name__ == "__main__":
    sys.exit(main())
