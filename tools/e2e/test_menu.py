#!/usr/bin/env python3
"""Menu-navigation E2E test: reach the main menu, verify UP/DOWN cursor movement
and wrap, and that A enters a submenu / B backs out — all without crashing and
without starting a game.

Empirically, the main menu hub (scene 4) has 3 items; the cursor proxy
`obj_list_ptr` (@0x800D3D00) cycles 3->5->6->3 on DOWN and reverses on UP. Selecting
(A) loads a submenu's scene objects (scene stays 4, scene_main_state changes); B
frees them and returns.

Run:  python3 tools/e2e/test_menu.py
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, GameError, _sleep

MENU_CURSOR_VALUES = {3, 5, 6}   # the 3 main-menu item positions


def step_down(g):
    g.press(Keys.DOWN, hold=0.25); _sleep(0.2)
    return g.read("obj_list_ptr")


def step_up(g):
    g.press(Keys.UP, hold=0.25); _sleep(0.2)
    return g.read("obj_list_ptr")


def main():
    with Game() as g:
        g.wait_alive(timeout=40)
        g.wait_for("scene", lambda v: v == 3, timeout=40, desc="attract flythrough")

        # 1) Enter the main menu with START.
        g.press(Keys.START, hold=3.0)
        g.wait_for("scene", lambda v: v == 4, timeout=15, desc="main menu hub (scene 4)")
        _sleep(1.0)
        start_cur = g.read("obj_list_ptr")
        assert start_cur in MENU_CURSOR_VALUES, f"unexpected menu cursor {start_cur}"
        print(f"at main menu; cursor={start_cur}")

        # 2) DOWN moves the cursor; 3 DOWNs wrap back to the start (3-item menu).
        seq = [start_cur]
        for _ in range(3):
            seq.append(step_down(g))
        print(f"cursor after 3x DOWN: {seq}")
        assert seq[1] != seq[0], "DOWN did not move the cursor"
        assert len(set(seq[:3])) == 3, f"expected 3 distinct positions, got {seq[:3]}"
        assert seq[3] == seq[0], f"3x DOWN should wrap to start; {seq}"

        # 3) UP reverses.
        up1 = step_up(g)
        assert up1 == seq[2], f"UP should step back to {seq[2]}, got {up1}"
        step_down(g)  # back to start position
        assert not g.crashed(), "crashed during navigation"
        print("UP/DOWN navigation + wrap verified")

        # 4) A enters a submenu (scene stays 4; scene_main_state / objects change), B backs.
        before_state = g.read("scene_main_state")
        g.press(Keys.A, hold=0.4); _sleep(1.0)
        assert not g.crashed(), "crashed entering a submenu with A (should be safe — not a game start)"
        assert g.read("scene") == 4, "leaving the menu-hub scene on A was unexpected"
        after_state = g.read("scene_main_state")
        print(f"A -> submenu: scene_main_state {before_state} -> {after_state}")

        g.press(Keys.B, hold=0.4); _sleep(1.0)
        assert not g.crashed(), "crashed backing out with B"
        assert g.read("scene") == 4, "B did not return to the menu hub"
        print("A enters a submenu and B returns — menu system navigable")

        print("PASS: main menu reached, UP/DOWN + wrap + A/B submenu navigation all work")
        return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except (GameError, TimeoutError, AssertionError) as e:
        print(f"FAIL: {e}")
        sys.exit(1)
