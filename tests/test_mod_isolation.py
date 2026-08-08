"""Explicit mod selection + isolation from the user's installed mods."""


def _boot(g):
    g.wait_alive(timeout=40)
    g.wait_for("scene", lambda v: v == 3, timeout=40, desc="attract")


def test_requested_mod_is_loaded(game):
    """A test that asks for a mod gets exactly that mod loaded (enabled)."""
    g = game(mods=["intro-skip"])
    _boot(g)
    log = g.log_path.read_text()
    assert "Loading mod tnt_intro_skip" in log, \
        f"requested mod was not loaded/enabled:\n{log[-800:]}"


def test_user_installed_mods_do_not_leak(game):
    """When a test requests one mod, the user's OTHER installed mods must not be
    present — proof the run is isolated, not reading ~/.local/share."""
    g = game(mods=["intro-skip"])
    _boot(g)
    log = g.log_path.read_text()
    for leaked in ("tnt_wonders_rebalance", "tnt_map_select", "tnt_scene_crash_guard"):
        assert f"Opening mod {leaked}" not in log, f"leaked user mod: {leaked}"
