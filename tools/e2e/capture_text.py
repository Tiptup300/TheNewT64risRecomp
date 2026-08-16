#!/usr/bin/env python3
"""Read the strings stage-native captured (displayText hook -> 0x807FF100) to identify the
mystery held-state text."""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep
from e2e_helpers import reach_single_screen

CAP = (0x807FF100, 0xA0)


def main():
    with Game(mods=["tnt_intro_skip", "tnt_stage_native"], region=CAP) as g:
        reach_single_screen(g); _sleep(0.8)
        for _ in range(6):
            g.tap(Keys.DOWN); _sleep(0.25); g.tap(Keys.A); _sleep(0.4)
        _sleep(1.2)
        b = g.snapshot()
        for i in range(6):
            rec = b[i*24:(i+1)*24]
            x, y = rec[0], rec[1]
            s = rec[2:22].split(b"\x00")[0]
            if not s:
                continue
            printable = "".join(chr(c) if 32 <= c < 127 else f"\\x{c:02x}" for c in s)
            print(f"x={x:3d} y={y:3d}  '{printable}'")
    return 0


if __name__ == "__main__":
    sys.exit(main())
