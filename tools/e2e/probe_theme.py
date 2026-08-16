#!/usr/bin/env python3
"""Resolve the stage-select determinism contradiction.

Force the SAME theme (T) via the stage-select mod across several launches; each run read
g_currentSong at gameplay and screenshot the background. If the byte==T every run and the
3 screenshots show the SAME environment, the theme is pinned (earlier Russia/Egypt was a
fluke or wrong index). If the screenshots differ, the force isn't controlling the theme.
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep
from e2e_helpers import reach_single_screen

SCRATCH = (0x807FFF00, 0x40)
STATE, CURSOR = 0x807FFF14, 0x807FFF18
ST_SHOWING = 1
TARGET = 6   # RUSSIA
RUNS = 3


def scratch(g, addr):
    b = g.snapshot(); i = addr - SCRATCH[0]
    return int.from_bytes(b[i:i+4], "little")


def trigger(g):
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
    for run in range(RUNS):
        with Game(mods=["tnt_intro_skip", "tnt_stage_select"], region=SCRATCH) as g:
            reach_single_screen(g); _sleep(0.8)
            if not trigger(g):
                print(f"run{run}: FAILED to open screen (scene={g.read('scene')})"); continue
            for _ in range(10):
                if scratch(g, CURSOR) == TARGET:
                    break
                g.tap(Keys.DOWN); _sleep(0.35)
            g.tap(Keys.A)
            launched = False
            for _ in range(40):
                if g.read("scene") == 9:
                    launched = True; break
                _sleep(0.2)
            _sleep(0.8)
            shot = g.shot(f"theme_run{run}")
            print(f"run{run}: launched={launched} cursor={scratch(g, CURSOR)} "
                  f"song={g.read('song')} shot={shot}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
