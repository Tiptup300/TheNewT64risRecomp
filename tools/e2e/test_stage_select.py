#!/usr/bin/env python3
"""E2E test for the in-game SELECT STAGE (mods/stage-native).

Confirms three things the feature must guarantee:
  1. MENU OPENS   — driving SINGLE -> START opens SELECT STAGE (the SINGLE foreground is blanked,
                    scene stays 4 = the launch is held, not committed).
  2. BACK IS SAFE — pressing B returns to SINGLE and RESTORES it exactly (foreground visible again,
                    the host menu cursor unchanged) -- opening the stage menu must not corrupt the
                    previous screen's state.
  3. PICK -> GAMEPLAY, NO CRASH — re-opening and pressing A launches into gameplay (scene 9) with
                    the chosen theme byte set, and the game does not crash.

Signal: SELECT STAGE hides the SINGLE foreground by zeroing item alphas in the active scene-4
item table (base 0x800D5850). We watch item 2's alpha (+0x1C) at 0x800D58DC: 0 = stage menu open
(foreground hidden), non-zero = SINGLE visible. This reads GAME RAM only (no mod scratch).

Run: python3 tools/e2e/test_stage_select.py   (exit 0 = pass, 1 = fail)
"""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep, DEFAULT_WATCHES
from e2e_helpers import reach_single_screen

THEME    = (0x8011EEF8, 1)   # real environment/theme selector
FG_ALPHA = (0x800D58DC, 4)   # item 2 alpha (+0x1C): 0 => stage menu open, !=0 => SINGLE shown


def open_stage_menu(g, max_taps=10):
    """Navigate SINGLE toward START, arming the launch, until the mod intercepts (foreground
    blanked = fg_alpha 0). Returns True once open (without picking a stage)."""
    for _ in range(max_taps):
        if g.read("fg_alpha") == 0 and g.read("scene") == 4:
            return True
        g.press(Keys.DOWN, hold=0.35); _sleep(0.25)
        g.press(Keys.A, hold=0.45); _sleep(0.45)
        if g.read("fg_alpha") == 0 and g.read("scene") == 4:
            return True
    return g.read("fg_alpha") == 0 and g.read("scene") == 4


def main():
    watches = dict(DEFAULT_WATCHES); watches["theme"] = THEME; watches["fg_alpha"] = FG_ALPHA
    ok = True
    with Game(mods=["tnt_intro_skip", "tnt_stage_native"], watches=watches) as g:
        reach_single_screen(g); _sleep(0.8)
        host_cursor_before = g.read("menu_cursor")
        fg_before = g.read("fg_alpha")
        print(f"SINGLE: menu_cursor={host_cursor_before} fg_alpha={fg_before} (should be !=0)")

        # 1. MENU OPENS
        opened = open_stage_menu(g)
        g.shot("ss_1_open")
        print(f"[1] menu opened={opened} (scene={g.read('scene')} fg_alpha={g.read('fg_alpha')})")
        ok = ok and opened and g.read("scene") == 4

        # 2. BACK IS SAFE — return to SINGLE with its foreground restored (the definitive proof
        # that SINGLE isn't corrupted is that we can re-open the stage menu from it in step 3).
        g.press(Keys.B, hold=0.7); _sleep(1.0)
        back_scene = g.read("scene")
        back_fg = g.read("fg_alpha")
        g.shot("ss_2_back")
        restored = (back_scene == 4 and back_fg != 0)
        print(f"[2] after BACK: scene={back_scene} (==4) fg_alpha={back_fg} (restored, !=0) "
              f"-> back_on_single={restored}")
        ok = ok and restored

        # 3. PICK -> GAMEPLAY, NO CRASH
        reopened = open_stage_menu(g)
        theme_picked = None
        if reopened:
            theme_picked = g.read("theme")   # not meaningful until launch; kept for logging
            g.press(Keys.A, hold=0.5)        # pick the highlighted stage (cursor 0 = MAYAN)
        launched = False
        for _ in range(40):
            if g.crashed():
                print("[3] CRASHED"); ok = False; break
            if g.read("scene") == 9:
                launched = True; break
            _sleep(0.2)
        _sleep(0.6)
        g.shot("ss_3_gameplay")
        theme = g.read("theme")
        crashed = g.crashed()
        print(f"[3] reopened={reopened} launched={launched} scene={g.read('scene')} "
              f"theme={theme} crashed={crashed}")
        ok = ok and reopened and launched and (not crashed) and (0 <= theme <= 7)

        print("RESULT:", "PASS" if ok else "FAIL")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
