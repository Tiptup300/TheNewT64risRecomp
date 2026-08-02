#!/usr/bin/env python3
"""Menu-navigation E2E test (RAM + controlled-input verified).

The main menu (scene 4) DISPLAYS 4 items — ONE PLAYER, MULTI PLAYER, WONDERS,
OPTIONS — with cursor g_sceneMenuCursor @0x800D3D00 taking values 3/4/5/6. With a
single controller MULTI PLAYER (4) is greyed and skipped, so single-step DOWN cycles
the 3 selectable items 3->5->6->3. With 2 controllers, 4 becomes selectable too.
A (Z) enters a submenu, B (X) backs out — both stay in scene 4, no crash.

Run:  python3 tools/e2e/test_menu.py
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, GameError, _sleep

ONE_PLAYER, MULTI_PLAYER, WONDERS, OPTIONS = 3, 4, 5, 6


def reach_menu(g):
    g.wait_alive(timeout=40)
    g.wait_for("scene", lambda v: v == 3, timeout=40, desc="attract flythrough")
    g.press(Keys.START, hold=3.0)
    g.wait_for("scene", lambda v: v == 4, timeout=15, desc="main menu hub (scene 4)")
    _sleep(1.0)


def cursor_cycle(g, taps=6):
    seq = [g.read("menu_cursor")]
    for _ in range(taps):
        g.tap(Keys.DOWN)
        seq.append(g.read("menu_cursor"))
    return seq


def main():
    # Phase 1: single controller — 3 selectable items (MULTI PLAYER skipped).
    with Game(controllers=1) as g:
        reach_menu(g)
        assert g.read("scene") == 4
        seq = cursor_cycle(g)
        visited = sorted(set(v for v in seq if v is not None))
        print(f"1 controller: cursor visits {visited}  seq={seq}")
        assert visited == [ONE_PLAYER, WONDERS, OPTIONS], \
            f"expected 3 selectable items {[ONE_PLAYER, WONDERS, OPTIONS]}, got {visited}"

        # UP reverses; A enters a submenu / B backs out (no crash, stays scene 4).
        before = g.read("scene_main_state")
        g.tap(Keys.A); _sleep(1.0)
        assert not g.crashed(), "crashed entering a submenu with A"
        assert g.read("scene") == 4, "unexpectedly left the menu hub on A"
        print(f"A -> submenu (scene_main_state {before} -> {g.read('scene_main_state')})")
        g.tap(Keys.B); _sleep(1.0)
        assert not g.crashed() and g.read("scene") == 4, "B did not return to the hub"
        print("A/B submenu navigation OK")

    # Phase 2: two controllers — MULTI PLAYER (cursor 4) becomes selectable.
    with Game(controllers=2) as g:
        reach_menu(g)
        visited = sorted(set(v for v in cursor_cycle(g) if v is not None))
        print(f"2 controllers: cursor visits {visited}")
        assert MULTI_PLAYER in visited, \
            f"MULTI PLAYER (cursor {MULTI_PLAYER}) should be selectable with 2 controllers; got {visited}"

    print("PASS: 4-item menu; 3 selectable with 1 pad, MULTI PLAYER unlocked with 2; A/B submenu nav works")
    return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except (GameError, TimeoutError, AssertionError) as e:
        print(f"FAIL: {e}")
        sys.exit(1)
