#!/usr/bin/env python3
"""POC test: does mods/new-screen-poc draw custom text on the menu (and not crash)?

Stage-1 question: can a mod CALL a game function (displayText_XY_RGBA_2, via an indirect
jalr to its guest address) from a Scene_Main return hook? If the game reaches the menu
(scene 4) with the mod enabled and does NOT crash, the call mechanism works; the
screenshot then confirms the text renders.

    python3 tools/e2e/test_new_screen.py
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, _sleep
from e2e_helpers import reach_menu

POC = "tnt_new_screen_poc"


def main():
    with Game(mods=["tnt_intro_skip", POC]) as g:
        reach_menu(g)
        _sleep(1.0)
        if g.crashed():
            print(f"FAIL: crashed reaching/holding menu with {POC} (code {g.proc.poll()}); "
                  f"the indirect call into the game fn likely isn't dispatched. See {g.log_path}")
            return 1
        sc = g.read("scene")
        shot = g.shot("new_screen_poc")
        print(f"OK: survived on scene={sc} with {POC} enabled. shot={shot}")
        print("   -> view the shot; expect 'MOD SCREEN POC' drawn top-left on the menu.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
