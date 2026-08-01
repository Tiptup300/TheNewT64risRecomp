#!/usr/bin/env python3
"""Reach the Data / save-profile screen and characterize it: which main-menu item
opens it, its pak state (no-pak?), and — via RAM-diff on Up/Down — the save-screen
menu OBJECT region (so we can force the name-entry sub-state obj+0x5D=1 for testing)."""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep

REPO = Path(__file__).resolve().parent.parent.parent
REGION = (0x800CE000, 0x51000)


def main():
    with Game(region=REGION) as g:
        g.wait_alive(40)
        g.wait_for("scene", lambda v: v == 3, 40, desc="attract")
        g.press(Keys.START, hold=3.0)
        g.wait_for("scene", lambda v: v == 4, 15, desc="menu hub")
        _sleep(1.0)

        for i in range(3):
            cur = g.read("menu_cursor")
            print(f"\n### enter main item {i} (cursor={cur}) ###")
            g.press(Keys.A, hold=0.4); _sleep(1.2)
            if g.crashed():
                print(f"   crashed on A (code {g.proc.poll()}); skipping"); break
            st = g.state()
            print(f"   scene={st.get('scene')} save_cursor={st.get('save_cursor')} "
                  f"pak_files={st.get('pak_files')} obj_render_enable={st.get('obj_render_enable')}")
            # Is this the save screen? Probe Up/Down and see what moves (RAM-diff).
            chg_down = g.find_changes(lambda: g.press(Keys.DOWN, hold=0.3))
            # words near the known save-screen bss (0x800D3Dxx) or a heap object:
            interesting = [(a, o, n) for a, o, n in chg_down
                           if 0x800D3D00 <= a <= 0x800D3E40 or a >= 0x80120000]
            print(f"   DOWN moved {len(chg_down)} words; near save-state/heap: "
                  f"{[(hex(a), o, n) for a, o, n in interesting[:8]]}")
            g.press(Keys.B, hold=0.4); _sleep(1.0)
            if g.crashed():
                print("   crashed on B"); break
            print(f"   B -> scene={g.read('scene')}")
            g.press(Keys.DOWN, hold=0.25); _sleep(0.3)
    print("\ndone.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
