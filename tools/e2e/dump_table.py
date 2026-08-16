#!/usr/bin/env python3
"""Dump the active scene-4 item table (via stage-native's dump to 0x807FF000) to classify each
0x38-byte item as background vs foreground for the parasite approach."""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep
from e2e_helpers import reach_single_screen

DUMP = (0x807FF000, 0xC0)
STATE_REGION = (0x807FFF00, 0x40)
STATE = 0x807FFF14


def main():
    with Game(mods=["tnt_intro_skip", "tnt_stage_native"], region=DUMP) as g:
        reach_single_screen(g); _sleep(0.8)
        for _ in range(6):
            g.tap(Keys.DOWN); _sleep(0.25); g.tap(Keys.A); _sleep(0.4)
        _sleep(1.0)
        b = g.snapshot()
        w = lambda i: int.from_bytes(b[i*4:i*4+4], "little")
        tbl = w(0)
        count = w(41)
        print(f"table ptr = 0x{tbl:08X}  item count = {count}")
        print(f"{'idx':>3} {'flags':>6} {'sprite(+0)':>12} {'+0x08':>12} {'+0x0C':>12}")
        for i in range(10):
            fl = w(1 + i*4 + 0)
            s0 = w(1 + i*4 + 1)
            f8 = w(1 + i*4 + 2)
            fc = w(1 + i*4 + 3)
            term = " <TERM>" if (fl & 0x8000) else ""
            print(f"{i:>3} 0x{fl:04X} 0x{s0:08X} 0x{f8:08X} 0x{fc:08X}{term}")
            if fl & 0x8000:
                break
    return 0


if __name__ == "__main__":
    sys.exit(main())
