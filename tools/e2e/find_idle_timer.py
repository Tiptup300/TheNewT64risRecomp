#!/usr/bin/env python3
"""Find the menu attract-idle countdown: on scene 4 with NO input, report words that
change MONOTONICALLY (a timer), separating them from oscillating animation noise."""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, _sleep
from e2e_helpers import reach_menu

REGION = (0x800D0000, 0x00010000)   # menu-state band


def words(b):
    return [int.from_bytes(b[i:i+4], "little") for i in range(0, len(b) - 3, 4)]


def main():
    with Game(region=REGION, mods=["tnt_intro_skip"]) as g:
        reach_menu(g)
        _sleep(0.5)
        samples = []
        for _ in range(8):
            samples.append(words(g.snapshot()))
            _sleep(1.0)
            if g.read("scene") != 4:
                print(f"# left scene 4 after {len(samples)} samples (idled out)"); break
        n = min(len(s) for s in samples)
        mono = []
        for i in range(n):
            seq = [s[i] for s in samples]
            d = [seq[k+1] - seq[k] for k in range(len(seq)-1)]
            if all(x > 0 for x in d) or all(x < 0 for x in d):   # strictly monotonic
                if len(set(seq)) > 2:  # actually moving
                    mono.append((REGION[0] + i*4, seq[0], seq[-1], "inc" if d[0] > 0 else "dec"))
        print(f"# {len(samples)} samples, {len(mono)} monotonic word(s):")
        for addr, a, b, dirn in mono:
            print(f"    0x{addr:08X}  {a} -> {b}  ({dirn})")
    return 0


if __name__ == "__main__":
    sys.exit(main())
