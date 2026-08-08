"""Boot + mod-isolation smoke tests."""


def test_boots_to_attract(game):
    g = game()
    g.wait_alive(timeout=40)
    g.wait_for("scene", lambda v: v == 3, timeout=40, desc="attract flythrough")
    assert not g.crashed()


def test_no_mods_loaded_by_default(game):
    """A default run must load ZERO mods — proves tests don't inherit the user's
    installed mods. 'Opening mod ...' is logged for every mod present in the mods
    dir, so an isolated empty mods dir must produce none."""
    g = game()
    g.wait_alive(timeout=40)
    g.wait_for("scene", lambda v: v == 3, timeout=40)
    opened = [ln for ln in g.log_path.read_text().splitlines()
              if ln.startswith("Opening mod")]
    assert opened == [], f"expected zero mods, got: {opened}"
