#!/usr/bin/env python3
"""Stage-1 mechanism probe: does Scene_LoadScreen called from a mod replace the SINGLE screen
with a real in-game screen on the block background? Reach SINGLE, arm the launch, screenshot."""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep
from e2e_helpers import reach_single_screen

SCRATCH = (0x807FFF00, 0x40)
STATE = 0x807FFF14


def sc(g, addr):
    b = g.snapshot(); i = addr - SCRATCH[0]
    return int.from_bytes(b[i:i+4], "little")


def main():
    with Game(mods=["tnt_intro_skip", "tnt_stage_native"], region=SCRATCH) as g:
        reach_single_screen(g); _sleep(0.8)
        print("before-arm scene:", g.read("scene"), "state:", sc(g, STATE))
        # arm the launch: press Accept a few times (DOWN->A is the START path)
        for _ in range(6):
            g.tap(Keys.DOWN); _sleep(0.25); g.tap(Keys.A); _sleep(0.4)
            if sc(g, STATE) == 1:
                break
        _sleep(1.2)
        print("after-arm  scene:", g.read("scene"), "state:", sc(g, STATE))
        print("shot:", g.shot("native_stage1"))
        log = Path(g.log_path).read_text(errors="ignore").splitlines()
        crash = [l for l in log if "SIGSEGV" in l or "abort" in l.lower() or "crash" in l.lower()]
        print("crash lines:", crash[-3:] if crash else "none")
        return 0


if __name__ == "__main__":
    sys.exit(main())
