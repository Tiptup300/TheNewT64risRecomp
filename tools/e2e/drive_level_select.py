#!/usr/bin/env python3
"""Drive mods/new-screen-poc's LEVEL SELECT overlay and screenshot each state.

Uses the N64 C-buttons (injected via their SDL scancodes) so the overlay never fights
the live menu. Captures: closed menu -> open -> cursor moved -> OK -> closed again.

    python3 tools/e2e/drive_level_select.py
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, _sleep
from e2e_helpers import reach_menu

# C-button SDL scancodes (from controls.json): W/S/A/D
C_UP, C_DOWN, C_LEFT, C_RIGHT = 26, 22, 4, 7


def tap(g, sc, label=""):
    g.press(sc, hold=0.35); g.release(); _sleep(0.5)


def main():
    with Game(mods=["tnt_intro_skip", "tnt_new_screen_poc"]) as g:
        reach_menu(g)
        _sleep(0.8)
        g.shot("ls_0_closed"); print("shot ls_0_closed (plain menu)")

        tap(g, C_UP);    g.shot("ls_1_open");    print("C-Up -> ls_1_open (expect LEVEL SELECT list)")
        tap(g, C_DOWN);  tap(g, C_DOWN)
        g.shot("ls_2_cursor3"); print("C-Down x2 -> ls_2_cursor3 (cursor on LEVEL 3)")
        tap(g, C_RIGHT); g.shot("ls_3_ok3");     print("C-Right -> ls_3_ok3 (expect OK - LEVEL 3 banner)")
        tap(g, C_LEFT);  g.shot("ls_4_closed");  print("C-Left -> ls_4_closed (overlay gone)")

        if g.crashed():
            print(f"FAIL: crashed (code {g.proc.poll()}); see {g.log_path}"); return 1
        print(f"OK survived; scene={g.read('scene')}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
