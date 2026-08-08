#!/usr/bin/env python3
"""Drive the full path main menu -> ONE PLAYER -> SINGLE -> ACCEPT -> GAMEPLAY, to
confirm the menu system maps all the way into a running game (scene 9) and whether
starting a game the NORMAL way hits the scene-4 setup crash (it should NOT — that
crash is only when scene 4 is entered without its resource load).

Screenshots each transition. Run: python3 tools/e2e/test_to_gameplay.py
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, GameError, _sleep


def main():
    with Game(controllers=1) as g:
        g.wait_alive(timeout=40)
        g.wait_for("scene", lambda v: v == 3, timeout=40, desc="attract")
        g.press(Keys.START, hold=3.0)
        g.wait_for("scene", lambda v: v == 4, timeout=15, desc="main menu")
        _sleep(1.0)
        # ONE PLAYER is the start item (cursor 3).
        while g.read("menu_cursor") != 3:
            g.tap(Keys.DOWN)
        g.tap(Keys.A); _sleep(1.3)                 # -> SINGLE setup screen
        g.shot("g1_single")
        print(f"SINGLE screen: scene={g.read('scene')}")

        # SINGLE screen: NAME is a profile dropdown (Up/Down cycles it); A accepts
        # NAME and reveals a START row; then DOWN walks to START and A launches. A on
        # the OPPONENT/GAME value rows only toggles their value, so walk with DOWN.
        g.tap(Keys.A); _sleep(0.6)                 # accept NAME=GUEST -> START appears
        reached = False
        for i in range(6):                          # DOWN toward START, pressing A each stop
            g.tap(Keys.DOWN); _sleep(0.4)
            g.tap(Keys.A)
            for _ in range(25):
                if g.crashed():
                    raise GameError(f"CRASHED starting the game (code {g.proc.poll()}) "
                                    f"at step {i}; scene={g.read('scene')}. See {g.log_path}")
                if g.read("scene") == 9:
                    reached = True
                    break
                _sleep(0.2)
            g.shot(f"g2_step{i}_scene{g.read('scene')}")
            print(f"  step {i}: scene={g.read('scene')} game_mode={g.read('game_mode')} "
                  f"frame_counter={g.read('frame_counter')}")
            if reached:
                break

        assert reached, f"did not reach gameplay (scene 9); ended at scene {g.read('scene')}"
        # We're in the gameplay scene. Give it a moment (there's a brief ready state)
        # and confirm it stays alive in scene 9 — that's the definitive "reached
        # gameplay" signal; the frame counter is logged as extra info.
        f0 = g.read("frame_counter")
        _sleep(3.0)
        f1 = g.read("frame_counter")
        g.shot("g3_gameplay")
        print(f"gameplay: scene={g.read('scene')}, frame_counter {f0} -> {f1}")
        assert not g.crashed(), "crashed shortly into gameplay"
        assert g.read("scene") == 9, "left the gameplay scene unexpectedly"
        print("PASS: menu -> ONE PLAYER -> SINGLE -> START -> gameplay (scene 9); no crash")
        return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except (GameError, TimeoutError, AssertionError) as e:
        print(f"FAIL: {e}")
        sys.exit(1)
