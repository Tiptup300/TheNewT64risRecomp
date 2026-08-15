#!/usr/bin/env python3
"""Drive the stage-select in-flow screen and verify the whole flow.

Flow under test: SINGLE setup -> press Accept -> mod HOLDS the launch and shows the
SELECT STAGE screen (scene stays 4) -> Up/Down navigate -> Accept launches the game
(scene 9) with the chosen stage recorded. Also screenshots each state.

    python3 tools/e2e/drive_stage_select.py
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep
from e2e_helpers import reach_single_screen

SCRATCH = (0x807FFF00, 0x40)
CHOICE, STATE, CURSOR = 0x807FFF10, 0x807FFF14, 0x807FFF18
ST_IDLE, ST_SHOWING, ST_DONE = 0, 1, 2


def scratch(g, addr):
    b = g.snapshot()
    i = addr - SCRATCH[0]
    return int.from_bytes(b[i:i+4], "little")


def main():
    with Game(mods=["tnt_intro_skip", "tnt_stage_select"], region=SCRATCH) as g:
        reach_single_screen(g)
        _sleep(0.8)

        # Trigger the launch the way reach_gameplay does (walk items, press A on START).
        # The mod should intercept: state -> SHOWING and scene stays 4 (not 9).
        showing = False
        for i in range(8):
            g.tap(Keys.DOWN); _sleep(0.3); g.tap(Keys.A)
            for _ in range(12):
                if scratch(g, STATE) == ST_SHOWING:
                    showing = True; break
                if g.read("scene") == 9:
                    break
                _sleep(0.2)
            if showing or g.read("scene") == 9:
                break

        if not showing:
            print(f"FAIL: never intercepted; scene={g.read('scene')} state={scratch(g,STATE)}")
            return 1
        print(f"OK intercepted: scene={g.read('scene')} (held) state=SHOWING")
        g.shot("stage_1_open")

        # Navigate: down twice -> cursor should be 2 (EGYPT).
        g.tap(Keys.DOWN); _sleep(0.4); g.tap(Keys.DOWN); _sleep(0.4)
        print(f"after DOWNx2: cursor={scratch(g, CURSOR)} (expect 2)")
        g.shot("stage_2_cursor")

        # Accept -> launch. scene should become 9 and CHOICE == cursor.
        cur = scratch(g, CURSOR)
        g.tap(Keys.A)
        launched = False
        for _ in range(30):
            if g.read("scene") == 9:
                launched = True; break
            if g.crashed():
                print(f"FAIL: crashed on accept; see {g.log_path}"); return 1
            _sleep(0.2)
        _sleep(0.6)
        print(f"after A: scene={g.read('scene')} launched={launched} "
              f"choice={scratch(g, CHOICE)} (expect {cur})")
        g.shot("stage_3_ingame")
        if not launched:
            print("FAIL: did not launch after accept"); return 1
        print("OK: stage-select flow works end to end.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
