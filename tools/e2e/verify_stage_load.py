#!/usr/bin/env python3
"""Regression for the stage-select mod: our screen navigates, launches, and the picked
stage's themed environment actually loads (the real selector is 0x8011EEF8, not g_currentSong).

PASS criteria (the parts that work and must keep working):
  - our own SELECT STAGE cursor moves on DOWN,
  - Accept launches into gameplay (scene 9),
  - the environment byte 0x8011EEF8 == the picked stage index.

INFORMATIONAL (a known, documented limitation -- NOT a failure): the SINGLE menu drawn
behind the overlay still reacts to input. RE established the menu populates+consumes
g_buttonsPressed inline inside Scene_Main's logic, past any RECOMP_HOOK boundary, so the
overlay cannot fully freeze it; the real fix is the engine-native transition screen that
hides the SINGLE screen (see docs/STAGE_SELECT_ENHANCEMENTS.md).
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep, DEFAULT_WATCHES
from e2e_helpers import reach_single_screen

SCRATCH = (0x807FFF00, 0x40)
STATE, CURSOR = 0x807FFF14, 0x807FFF18
ST_SHOWING = 1
THEME = (0x8011EEF8, 1)  # real environment selector


def scratch(g, addr):
    b = g.snapshot(); i = addr - SCRATCH[0]
    return int.from_bytes(b[i:i + 4], "little")


def open_screen(g):
    for _ in range(8):
        g.tap(Keys.DOWN); _sleep(0.3); g.tap(Keys.A)
        for _ in range(12):
            if scratch(g, STATE) == ST_SHOWING:
                return True
            if g.read("scene") == 9:
                return False
            _sleep(0.2)
    return scratch(g, STATE) == ST_SHOWING


def main():
    watches = dict(DEFAULT_WATCHES); watches["theme"] = THEME
    with Game(mods=["tnt_intro_skip", "tnt_stage_select"], region=SCRATCH,
              watches=watches) as g:
        reach_single_screen(g); _sleep(0.8)
        if not open_screen(g):
            print(f"FAIL: could not open SELECT STAGE (scene={g.read('scene')})"); return 1

        old_cursor0 = g.read("menu_cursor")
        mod_cursor0 = scratch(g, CURSOR)
        print(f"opened: old menu_cursor={old_cursor0} mod_cursor={mod_cursor0}")

        for i in range(4):
            g.tap(Keys.DOWN); _sleep(0.35)
        old_cursor1 = g.read("menu_cursor")
        mod_cursor1 = scratch(g, CURSOR)
        print(f"after 4xDOWN: old menu_cursor={old_cursor1} mod_cursor={mod_cursor1}")

        isolated = (old_cursor1 == old_cursor0)
        mod_moved = (mod_cursor1 != mod_cursor0)
        print(f"[info] underlying-menu-frozen={isolated} (known limitation if False), "
              f"mod-cursor-moved={mod_moved}")

        # pick current theme and confirm the real selector sticks. The Accept press can
        # miss (input is shared with the leaking menu behind), so retry a few times.
        target = scratch(g, CURSOR)
        launched = False
        for _try in range(4):
            g.tap(Keys.A)
            for _ in range(15):
                if g.read("scene") == 9:
                    launched = True; break
                _sleep(0.2)
            if launched:
                break
        _sleep(0.8)
        theme = g.read("theme")
        shot = g.shot("isolation_gameplay")
        print(f"launched={launched} picked={target} theme_byte={theme} shot={shot}")

        ok = mod_moved and launched and theme == target
        print("RESULT:", "PASS" if ok else "FAIL",
              "(env-load + nav + launch)" if ok else "")
        return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
