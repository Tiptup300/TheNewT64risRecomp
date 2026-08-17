#!/usr/bin/env python3
"""Test whether the held-state garbled text was caused by the mod's scratch-RAM writes (top of
RDRAM). This mod version writes NO scratch; arm the launch and screenshot on a timer."""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep
from e2e_helpers import reach_single_screen


def main():
    with Game(mods=["tnt_intro_skip", "tnt_stage_native"]) as g:
        reach_single_screen(g); _sleep(0.8)
        for _ in range(6):
            g.tap(Keys.DOWN); _sleep(0.25); g.tap(Keys.A); _sleep(0.4)
            if g.read("scene") == 9:
                break
        _sleep(1.2)
        print("scene:", g.read("scene"), "shot:", g.shot("native_noscratch"))
    return 0


if __name__ == "__main__":
    sys.exit(main())
