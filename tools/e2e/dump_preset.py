#!/usr/bin/env python3
"""Dump g_pfDrawParamPresetTbl (@0x800D0930, 8 themes x 0x60) to see each theme's
descriptor fields (candidate sprite ids at +0x0 / +0x1C of each 0x20-byte descriptor)."""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, _sleep

BASE = 0x800D0930
REGION = (0x800D0900, 0x360)


def w(snap, addr):
    i = addr - REGION[0]
    return int.from_bytes(snap[i:i+4], "little")


def main():
    with Game(region=REGION) as g:
        g.wait_alive(40)
        g.wait_for("scene", lambda v: v >= 3, 60, desc="past boot")
        _sleep(1.0)
        s = g.snapshot()
        print(f"# g_pfDrawParamPresetTbl @ {hex(BASE)} (8 themes x 0x60)")
        for t in range(8):
            rec = BASE + t * 0x60
            fields = []
            for d in (0x00, 0x20, 0x40):        # three descriptors
                fields.append((f"+{d:#x}.0", w(s, rec + d + 0x00)))
                fields.append((f"+{d:#x}.1C", w(s, rec + d + 0x1C)))
                fields.append((f"+{d:#x}.5", (w(s, rec + d + 0x04) >> 24) & 0xFF))  # byte at +0x5-ish
            print(f"theme {t}: " + "  ".join(f"{k}={v:#x}" for k, v in fields[:6]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
