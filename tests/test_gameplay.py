"""Full path into gameplay. Also a regression guard for the Controller-Pak crash:
starting a game runs SaveData_InitMotors -> osPfsInitPak against a FRESH isolated
mem-pak, which used to SIGSEGV before the pak.cpp sign-extension fix."""
from harness import Keys, GameError, _sleep


def test_one_player_start_reaches_gameplay(game):
    g = game(controllers=1)
    g.wait_alive(timeout=40)
    g.wait_for("scene", lambda v: v == 3, timeout=40, desc="attract")
    g.press(Keys.START, hold=3.0)
    g.wait_for("scene", lambda v: v == 4, timeout=15, desc="main menu")
    _sleep(1.0)
    while g.read("menu_cursor") != 3:      # ONE PLAYER
        g.tap(Keys.DOWN)
    g.tap(Keys.A); _sleep(1.3)             # -> SINGLE setup screen
    g.tap(Keys.A); _sleep(0.6)             # accept NAME=GUEST -> START appears

    reached = False
    for i in range(6):                     # walk DOWN to START, pressing A each stop
        g.tap(Keys.DOWN); _sleep(0.4); g.tap(Keys.A)
        for _ in range(25):
            if g.crashed():
                raise GameError(
                    f"CRASHED starting the game (code {g.proc.poll()}) at step {i}; "
                    f"scene={g.read('scene')}. See {g.log_path}")
            if g.read("scene") == 9:
                reached = True
                break
            _sleep(0.2)
        if reached:
            break

    assert reached, f"did not reach gameplay (scene 9); ended at scene {g.read('scene')}"
    _sleep(2.0)
    assert not g.crashed(), "crashed shortly into gameplay"
    assert g.read("scene") == 9, "left the gameplay scene unexpectedly"
