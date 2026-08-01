#!/usr/bin/env python3
"""Smoke test: the game boots headless and reaches the attract flythrough.

Validates the whole E2E pipeline end to end: launch -> state bridge heartbeat ->
read game RAM -> assert scene progression. No input needed (auto-boot -> attract).

Run:  python3 tools/e2e/test_smoke.py
Exit: 0 on pass, 1 on fail.
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, GameError


def main():
    with Game() as g:
        print("launched; waiting for first frames...")
        g.wait_alive(timeout=40)
        print(f"rendering. frame={g.frame()} state={g.state()}")

        # Boot sequence walks scenes 0/1/2 (branding) -> 3 (attract flythrough).
        scene = g.wait_for("scene", lambda v: v == 3, timeout=40,
                           desc="attract flythrough (scene 3)")
        st = g.state()
        print(f"reached attract: scene={scene}  full state={st}")

        # Sanity: the object-slot buffer pointer should be a real KSEG0 ptr or 0
        # (0 only transiently); assert we're actually running the game loop.
        assert g.frame() > 0, "no heartbeat"
        assert scene == 3, f"expected attract scene 3, got {scene}"
        print("PASS: booted to the attract flythrough")
        return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except (GameError, TimeoutError, AssertionError) as e:
        print(f"FAIL: {e}")
        sys.exit(1)
