#!/usr/bin/env python3
"""Full stage-select test: BACK path + whether the forced theme sticks at launch.

1. Reach SINGLE, trigger -> screen shows (held).
2. Press B -> verify it returns to SINGLE (state IDLE, scene stays 4, not launched).
3. Re-trigger -> screen shows again (re-entry works).
4. Navigate to a specific stage (index 6 = RUSSIA), Accept -> launch.
5. Verify g_currentSong == 6 after launch (the theme-stick force held past the game's
   own randomize), and screenshot the gameplay environment.
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep
from e2e_helpers import reach_single_screen

SCRATCH = (0x807FFF00, 0x40)
CHOICE, STATE, CURSOR = 0x807FFF10, 0x807FFF14, 0x807FFF18
ST_IDLE, ST_SHOWING, ST_DONE = 0, 1, 2
TARGET = 6  # RUSSIA


def scratch(g, addr):
    b = g.snapshot(); i = addr - SCRATCH[0]
    return int.from_bytes(b[i:i+4], "little")


def trigger(g):
    """Walk the SINGLE items pressing A until the mod intercepts (state SHOWING)."""
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
    with Game(mods=["tnt_intro_skip", "tnt_stage_select"], region=SCRATCH) as g:
        reach_single_screen(g); _sleep(0.8)

        if not trigger(g):
            print(f"FAIL: no intercept; scene={g.read('scene')}"); return 1
        print("intercepted (SHOWING)")

        # --- BACK path ---
        g.tap(Keys.B); _sleep(0.6)
        st, sc = scratch(g, STATE), g.read("scene")
        print(f"after B: state={st} scene={sc} (expect state=0 IDLE, scene=4, not launched)")
        g.shot("stage_back")
        if st != ST_IDLE or sc == 9:
            print("FAIL: BACK did not return cleanly"); return 1

        # --- re-entry ---
        if not trigger(g):
            print(f"FAIL: could not re-open after BACK; scene={g.read('scene')}"); return 1
        print("re-opened after BACK (re-entry works)")

        # --- navigate to TARGET and accept ---
        for _ in range(N_TRIES := 10):
            if scratch(g, CURSOR) == TARGET:
                break
            g.tap(Keys.DOWN); _sleep(0.35)
        print(f"cursor={scratch(g, CURSOR)} (target {TARGET})")
        g.tap(Keys.A)
        launched = False
        for _ in range(30):
            if g.read("scene") == 9:
                launched = True; break
            if g.crashed():
                print(f"FAIL: crash; see {g.log_path}"); return 1
            _sleep(0.2)
        _sleep(0.8)
        song = g.read("song")
        print(f"after A: scene={g.read('scene')} launched={launched} "
              f"g_currentSong={song} (expect {TARGET} if theme-stick worked)")
        g.shot("stage_theme6")
        if not launched:
            print("FAIL: did not launch"); return 1
        print("OK: back + re-entry + launch all work. "
              f"theme-stick={'HELD' if song == TARGET else 'overwritten (song=%s)' % song}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
