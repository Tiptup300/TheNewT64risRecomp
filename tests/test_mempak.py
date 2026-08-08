"""Controller-Pak (mem-pak) HLE: creation, relocation, and persistence across a
relaunch — verified deterministically through the real game binary.

The game calls osPfsInitPak during boot (SaveData_InitMotors), so a simple boot
exercises the pak create/load path — no fragile menu driving needed. These tests
assert on the on-disk image using the format pak.cpp persists (16 x 32-byte dir
entries at offset 0; byte0 of each = "used").

NOTE: the *interactive* create-profile flow (name-entry keyboard -> osPfsAllocateFile)
is verified by RE (docs/MENU_TREE.md) but is not UI-automatable in this WSLg setup
(screenshots are occluded and blind keyboard nav is unreliable). These tests instead
prove the write(flush)/load/persistence layer that flow depends on, end to end.
"""
import struct
from pathlib import Path

from harness import _sleep

CONFIG_SUBPATH = Path(".local/share/N64Recomp/TheNewTiptris")
PAK_SIZE = 32 * 1024
DIR_ENTRY = 32


def _mempak(g):
    return g.data_home / CONFIG_SUBPATH / "mempak.bin"


def _used(image: bytes) -> int:
    return sum(1 for i in range(16) if image[i * DIR_ENTRY] == 1)


def _seed(path: Path, n: int):
    """Write `n` used files in the exact on-disk layout pak.cpp uses."""
    img = bytearray(PAK_SIZE)
    for i in range(n):
        e = i * DIR_ENTRY
        img[e] = 1                                       # used
        struct.pack_into("<H", img, e + 0x02, 0x3031)    # company_code
        struct.pack_into("<I", img, e + 0x04, 0x54455354)  # game_code
        nm = b"PROFILE%d" % i
        img[e + 0x08:e + 0x08 + len(nm)] = nm            # game_name[16]
        img[e + 0x18:e + 0x1B] = b"P.O"                  # ext_name[4]
        struct.pack_into("<I", img, e + 0x1C, 256)       # size
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(img)


def _boot(g):
    g.wait_alive(timeout=40)
    g.wait_for("scene", lambda v: v == 3, timeout=90, desc="attract")


def _wait_file(p: Path, timeout=12.0) -> bool:
    for _ in range(int(timeout / 0.5)):
        if p.exists():
            return True
        _sleep(0.5)
    return p.exists()


def test_mempak_created_at_config_dir(game):
    """Booting creates the mem-pak at the game's CONFIG dir (relocated off $HOME),
    as a valid empty 32KB image."""
    g = game()
    _boot(g)
    mp = _mempak(g)
    assert _wait_file(mp), f"mem-pak not created at config dir: {mp}"
    img = mp.read_bytes()
    assert len(img) == PAK_SIZE, f"unexpected pak size {len(img)}"
    assert _used(img) == 0, "a fresh pak should have 0 files"
    assert not g.crashed()


def test_seeded_pak_survives_relaunch(game):
    """A pak written to disk persists across a relaunch and the game loads it
    (osPfsInitPak -> pak_load) without crashing or corrupting it. Regression guard for
    the sign-extension crash + proof the on-disk format round-trips through the game."""
    g1 = game()
    _boot(g1)
    mp = _mempak(g1)
    assert _wait_file(mp), f"mem-pak not created: {mp}"
    g1.stop()

    _seed(mp, 2)
    assert _used(mp.read_bytes()) == 2

    # relaunch on the SAME isolated data dir
    g2 = game()
    _boot(g2)
    _sleep(2.0)
    assert not g2.crashed(), "game crashed loading a seeded pak"
    img = mp.read_bytes()
    assert len(img) == PAK_SIZE, "pak size changed across relaunch"
    assert _used(img) == 2, "seeded pak entries did not survive the relaunch"
