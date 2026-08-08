"""Main-menu navigation (scene 4)."""
from harness import Keys, _sleep


def _reach_menu(g):
    g.wait_alive(timeout=40)
    g.wait_for("scene", lambda v: v == 3, timeout=40, desc="attract")
    g.press(Keys.START, hold=3.0)
    g.wait_for("scene", lambda v: v == 4, timeout=15, desc="main menu hub")
    _sleep(1.0)


def test_three_selectable_items_one_pad(game):
    """With 1 controller, DOWN cycles the 3 selectable items 3->5->6 (MULTI
    PLAYER @4 is greyed and skipped)."""
    g = game(controllers=1)
    _reach_menu(g)
    assert g.read("scene") == 4
    seq = [g.read("menu_cursor")]
    for _ in range(6):
        g.tap(Keys.DOWN)
        seq.append(g.read("menu_cursor"))
    visited = sorted(set(v for v in seq if v is not None))
    assert visited == [3, 5, 6], f"expected [3,5,6], got {visited} (seq={seq})"


def test_multiplayer_unlocked_with_two_pads(game):
    """MULTI PLAYER (cursor 4) becomes selectable with a 2nd controller."""
    g = game(controllers=2)
    _reach_menu(g)
    visited = set()
    for _ in range(8):
        g.tap(Keys.DOWN)
        visited.add(g.read("menu_cursor"))
    assert 4 in visited, f"MULTI PLAYER should be selectable with 2 pads; got {sorted(visited)}"
