"""Pytest fixtures for headless, mod-isolated game tests.

Every test runs the game with HOME + XDG_DATA_HOME redirected to a throwaway
per-test dir (pytest's `tmp_path`), so it never reads or writes the user's real
`~/.local/share/N64Recomp/...` mods, saves, or mem-pak. Mods are strictly opt-in:

    def test_x(game):
        g = game()                       # zero mods (default)
        g = game(mods=["intro-skip"])    # only this mod, built + enabled

`mods` entries are directory names under `mods/`. Each is built on demand
(`mods/build_mod.sh`) and its `.nrm` seeded into the isolated `mods/` dir with a
`mods.json` that enables exactly those mods. Nothing else is ever loaded.
"""
import json
import re
import shutil
import subprocess
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
MODS_DIR = REPO / "mods"
E2E = REPO / "tools" / "e2e"
# Make the existing harness importable (also lets test modules do `from harness ...`).
sys.path.insert(0, str(E2E))

from harness import Game, Keys, GameError, _sleep  # noqa: E402,F401

CONFIG_SUBPATH = Path(".local/share/N64Recomp/TheNewTiptris")
REAL_CONFIG = Path.home() / CONFIG_SUBPATH
# Config files copied (read-only) from the machine's real install so the isolated
# run boots with proven-good settings. We deliberately do NOT copy mods.json — the
# fixture writes the isolated one. Without this, the game generates first-run
# graphics defaults (res_option "Auto", rr_option "Display") that crash under Dozen.
BASELINE_JSONS = ("graphics.json", "controls.json", "general.json", "sound.json")


def _toml_field(mod_dir: str, field: str):
    toml = (MODS_DIR / mod_dir / "mod.toml").read_text()
    m = re.search(rf'^\s*{field}\s*=\s*"(.*?)"', toml, re.M)
    return m.group(1) if m else None


def _manifest_id(mod_dir: str):
    """The mod id the runtime enables by — the `id` under [manifest]."""
    toml = (MODS_DIR / mod_dir / "mod.toml").read_text()
    sec = re.search(r'\[manifest\](.*?)(\n\[|\Z)', toml, re.S)
    body = sec.group(1) if sec else toml
    m = re.search(r'^\s*id\s*=\s*"(.*?)"', body, re.M)
    return m.group(1) if m else None


def _newest_src_mtime(mod_dir: Path) -> float:
    best = 0.0
    for p in mod_dir.rglob("*"):
        if p.is_file() and "build" not in p.parts:
            best = max(best, p.stat().st_mtime)
    return best


def _build_mod(mod_dir: str) -> Path:
    """Build mods/<mod_dir> if its .nrm is missing/stale; return the .nrm path."""
    d = MODS_DIR / mod_dir
    assert (d / "mod.toml").exists(), f"no mod.toml in {d}"
    fname = _toml_field(mod_dir, "mod_filename") or mod_dir
    nrm = d / "build" / f"{fname}.nrm"
    if (not nrm.exists()) or nrm.stat().st_mtime < _newest_src_mtime(d):
        r = subprocess.run([str(MODS_DIR / "build_mod.sh"), mod_dir],
                           cwd=str(REPO), capture_output=True, text=True)
        if r.returncode != 0 or not nrm.exists():
            raise RuntimeError(
                f"mod build failed for {mod_dir}:\n{r.stdout}\n{r.stderr}")
    return nrm


def _seed_baseline_config(config_dir: Path):
    """Copy the machine's known-good graphics/controls/etc. into the isolated config
    dir (read-only wrt the real install) so the game boots with proven settings
    instead of flaky first-run defaults. mods.json is intentionally excluded."""
    copied = []
    for name in BASELINE_JSONS:
        src = REAL_CONFIG / name
        if src.exists():
            shutil.copy2(src, config_dir / name)
            copied.append(name)
    if "graphics.json" not in copied:
        # No machine config to borrow (e.g. CI). Write minimal safe graphics so the
        # game doesn't emit res "Auto"/rr "Display" (Dozen-crashing) defaults.
        (config_dir / "graphics.json").write_text(json.dumps({
            "ar_option": "Original", "hr_option": "Original",
            "res_option": "Original", "rr_option": "Original",
            "ds_option": "Original", "msaa_option": "None",
        }, indent=4))


def _seed_mods(config_dir: Path, mod_dirs) -> list:
    """Seed the isolated mods/ dir with exactly `mod_dirs`; return enabled ids."""
    mods_dir = config_dir / "mods"
    mods_dir.mkdir(parents=True, exist_ok=True)
    enabled = []
    for md in mod_dirs:
        nrm = _build_mod(md)
        shutil.copy2(nrm, mods_dir / nrm.name)
        enabled.append(_manifest_id(md) or nrm.stem)
    (config_dir / "mods.json").write_text(json.dumps(
        {"enabled_mods": enabled, "mod_order": enabled, "latest_game_mode": ""},
        indent=4))
    return enabled


@pytest.fixture
def game(tmp_path):
    """Factory fixture: `game(mods=[...], **Game kwargs)` -> a started Game.

    Runs isolated (own HOME/XDG_DATA_HOME + workdir under tmp_path). All games
    created in a test are stopped at teardown.
    """
    started = []

    def _make(mods=(), **kwargs):
        data_home = tmp_path / "home"
        config_dir = data_home / CONFIG_SUBPATH
        config_dir.mkdir(parents=True, exist_ok=True)
        _seed_baseline_config(config_dir)
        _seed_mods(config_dir, mods)
        g = Game(data_home=data_home, workdir=tmp_path / "work", **kwargs)
        g.start()
        started.append(g)
        return g

    yield _make
    for g in started:
        try:
            g.stop()
        except Exception:
            pass
