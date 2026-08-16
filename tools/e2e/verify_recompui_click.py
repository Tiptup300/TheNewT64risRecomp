#!/usr/bin/env python3
"""Interactive check: with the recompui panel shown, pressing Accept should click the focused
COUNT +1 button and (via recomp_run_ui_callbacks) bump the counter. Screenshot before/after."""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep
from e2e_helpers import reach_menu


def main():
    with Game(mods=["tnt_intro_skip", "tnt_recompui_demo"]) as g:
        reach_menu(g)
        _sleep(2.0)
        print("before:", g.shot("click_before"))
        for i in range(3):
            g.press(Keys.A, hold=0.5)   # accept -> click focused button
            _sleep(0.6)
        _sleep(0.5)
        print("after :", g.shot("click_after"))
        return 0


if __name__ == "__main__":
    sys.exit(main())
