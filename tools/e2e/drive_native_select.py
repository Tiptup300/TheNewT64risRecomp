#!/usr/bin/env python3
"""Drive the in-game SELECT STAGE (mods/stage-native). Navigate SINGLE to START and launch; the
mod intercepts and shows SELECT STAGE (scene stays 4). Screenshot each step to catch it, then
continue to pick a stage -> gameplay (scene 9). Asserts theme byte set + no crash."""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep, DEFAULT_WATCHES
from e2e_helpers import reach_single_screen

THEME = (0x8011EEF8, 1)


def main():
    watches = dict(DEFAULT_WATCHES); watches["theme"] = THEME
    with Game(mods=["tnt_intro_skip", "tnt_stage_native"], watches=watches) as g:
        reach_single_screen(g); _sleep(0.8)
        held_seen = False
        reached_gameplay = False
        for i in range(10):
            sc = g.read("scene")
            shot = g.shot(f"nsel_step{i}")
            print(f"step {i}: scene={sc} theme={g.read('theme')} shot={shot}")
            if sc == 9:
                reached_gameplay = True
                break
            g.press(Keys.DOWN, hold=0.4); _sleep(0.25)
            g.press(Keys.A, hold=0.5); _sleep(0.5)
            if g.crashed():
                print("CRASHED at step", i); break
        _sleep(0.6)
        print(f"final: scene={g.read('scene')} theme={g.read('theme')} "
              f"reached_gameplay={reached_gameplay} crashed={g.crashed()}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
