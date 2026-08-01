#!/usr/bin/env python3
"""Navigation test: prove input injection works E2E and observe the scene machine.

Boots to the attract flythrough, then holds START to advance toward the menu and
asserts the input actually changed game state (scene / init flags). Also prints the
observed scene transitions so we learn/verify the scene machine.

Run:  python3 tools/e2e/test_navigate.py
"""
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, GameError


def observe_scenes(g, seconds, label):
    """Log distinct scene values seen over `seconds`."""
    seen, last = [], None
    end = time.monotonic() + seconds
    while time.monotonic() < end and g.alive():
        s = g.read("scene")
        if s != last:
            seen.append((round(g.frame()), s))
            last = s
        g.wait_frames(1)
    print(f"  [{label}] scene timeline (frame,scene): {seen}")
    return seen


def main():
    with Game() as g:
        g.wait_alive(timeout=40)
        g.wait_for("scene", lambda v: v == 3, timeout=40, desc="attract flythrough")
        print("at attract; observing the idle attract cycle for 8s...")
        observe_scenes(g, 8, "idle")

        before = g.state()
        print(f"state before input: {before}")

        # Hold START ~3s to land the press on the title (a brief tap can fall in a
        # transition). Per CLAUDE.md, holding Start on the title advances to the menu.
        print("holding START for 3s...")
        g.press(Keys.START, hold=3.0)

        after_scenes = observe_scenes(g, 6, "after START")
        after = g.state()
        print(f"state after input: {after}")

        if g.crashed():
            raise GameError(f"game crashed during navigation (code {g.proc.poll()}) — "
                            f"see {g.log_path}. If it hit scene 4, this is the known "
                            f"scene-4 crash; try test_crash_guard.py.")

        # Input connectivity: SOMETHING should have changed (scene advanced, a new
        # scene appeared, or an init/mode flag flipped). If nothing changed at all,
        # the input channel isn't reaching the game.
        changed = (after.get("scene") != before.get("scene")
                   or after.get("scene_changed") != before.get("scene_changed")
                   or after.get("game_init") != before.get("game_init")
                   or after.get("game_mode") != before.get("game_mode")
                   or len({s for _, s in after_scenes}) > 1)
        assert changed, ("holding START produced no observable state change — the "
                         "input channel may not be reaching the game")
        print("PASS: input injection reached the game (state changed after START)")
        return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except (GameError, TimeoutError, AssertionError) as e:
        print(f"FAIL: {e}")
        sys.exit(1)
