#!/usr/bin/env python3
"""Reusable reach-helpers + input catalog for driving the game to a known state.

Part of the modding framework: one function per game state, each robust to the
attract-demo cycle (scene 3 recurs, and boot can land on the demo). Import these in
tests and probes instead of re-deriving the navigation each time.

    from e2e_helpers import reach_menu, reach_gameplay, INPUTS
"""
from harness import Keys, GameError, _sleep

# Named inputs -> SDL scancode, for systematic probing (see probe_inputs.py).
INPUTS = {
    "A":     Keys.A,      # Z  — accept / confirm / rotate
    "B":     Keys.B,      # X  — back / cancel / rotate other way
    "START": Keys.START,  # Enter — pause / advance
    "UP":    Keys.UP,
    "DOWN":  Keys.DOWN,
    "LEFT":  Keys.LEFT,
    "RIGHT": Keys.RIGHT,
}


def reach_attract(g, timeout=90):
    """Wait until the title screen (scene 3) is showing. Tolerant of the attract
    cycle (3 <-> 12/13): scene 3 recurs, so we just wait for it to come around."""
    g.wait_alive(timeout=40)
    return g.wait_for("scene", lambda v: v == 3, timeout=timeout, desc="attract title")


def reach_menu(g, attempts=4):
    """Title (3) -> main menu hub (4). Robust to landing on the demo: press START
    only while on scene 3, and retry the whole handshake if we don't reach 4."""
    for _ in range(attempts):
        reach_attract(g)
        g.press(Keys.START, hold=3.0)
        try:
            g.wait_for("scene", lambda v: v == 4, timeout=8, desc="menu hub")
            _sleep(1.0)
            return
        except TimeoutError:
            continue
    raise GameError("could not reach the menu hub after retries")


def reach_single_screen(g):
    """Main menu -> ONE PLAYER -> SINGLE, name accepted, START visible."""
    reach_menu(g)
    for _ in range(8):
        if g.read("menu_cursor") == 3:      # ONE PLAYER
            break
        g.tap(Keys.DOWN)
    g.tap(Keys.A); _sleep(1.3)              # SINGLE setup screen
    g.tap(Keys.A); _sleep(0.6)              # accept NAME=GUEST -> START appears


def reach_gameplay(g):
    """Full proven path into gameplay (scene 9)."""
    reach_single_screen(g)
    for i in range(6):
        g.tap(Keys.DOWN); _sleep(0.4); g.tap(Keys.A)
        for _ in range(25):
            if g.crashed():
                raise GameError(f"crashed starting the game at step {i}; "
                                f"scene={g.read('scene')}; see {g.log_path}")
            if g.read("scene") == 9:
                _sleep(0.5)
                return
            _sleep(0.2)
    raise GameError(f"did not reach gameplay; scene={g.read('scene')}")


def reach_wonders(g):
    """Main menu -> WONDERS (cursor 5) -> A -> scene 7 (the wonders hall)."""
    reach_menu(g)
    for _ in range(8):
        if g.read("menu_cursor") == 5:
            break
        g.tap(Keys.DOWN)
    g.tap(Keys.A)
    g.wait_for("scene", lambda v: v in (7, 8), timeout=8, desc="wonders")
    _sleep(1.0)


def reach_pause(g):
    """Gameplay (9) -> pause (11) via START. Returns True if scene 11 was seen."""
    reach_gameplay(g)
    _sleep(1.0)
    g.tap(Keys.START)
    try:
        g.wait_for("scene", lambda v: v == 11, timeout=6, desc="pause")
        return True
    except TimeoutError:
        return False


# Registry: name -> (reach function, description). Lets a probe target any state.
STATES = {
    "attract":  (reach_attract, "title / attract flythrough (scene 3)"),
    "menu":     (reach_menu, "main menu hub (scene 4)"),
    "single":   (reach_single_screen, "ONE PLAYER SINGLE setup screen"),
    "gameplay": (reach_gameplay, "active gameplay (scene 9)"),
    "wonders":  (reach_wonders, "wonders hall (scene 7)"),
    "pause":    (reach_pause, "pause menu (scene 11)"),
}
