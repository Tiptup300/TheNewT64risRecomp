#!/usr/bin/env python3
"""E2E harness for The New T64ris : Recompiled.

Drives the headless game end-to-end: launch, observe game RAM (wait on / assert
state), and inject controller input to navigate menus and play. Built on two
runtime channels already in the app:
  - TNT_STATE  (state bridge, src/main.cpp): the app rewrites an output file each
    frame with the current values of a watch-list of RAM addresses, plus a
    "_frame" liveness heartbeat.
  - TNT_INPUT  (input overlay, RecompFrontend patch): the app ORs the SDL
    scancodes listed in a file onto the keyboard each poll (level-triggered:
    write to hold, empty to release).

Typical use:

    from harness import Game, Keys
    with Game(rom=ROM) as g:
        g.wait_alive()
        g.wait_for("scene", lambda v: v == 3, desc="attract flythrough")
        g.press(Keys.START, hold=2.0)           # advance past the title
        g.wait_for("scene", lambda v: v == 4, timeout=15, desc="menu hub")

Pacing uses select() (not time.sleep) so it is immune to this env's SIGSTKFLT
'sleep' block. Requires a working display (WSLg): if the session's display is
wedged, launches fail — a `wsl --shutdown` + relaunch clears it.
"""
import os
import select
import signal
import subprocess
import time
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent.parent
BIN = REPO / "build-cmake" / "TntRecompiled"
DZN = REPO / "dzn" / "dzn_icd.json"
DEFAULT_ROM = Path.home() / ".local/share/N64Recomp/TheNewTiptris/tnt.n64.us.z64"


class Keys:
    """SDL scancodes for the default keyboard mapping (input_type 1)."""
    START = 40   # RETURN
    A = 29       # Z  (accept)
    B = 27       # X  (back)
    UP = 82
    DOWN = 81
    LEFT = 80
    RIGHT = 79


# Curated default watches: name -> (guest_addr, width). All from tnt.datasyms.toml.
DEFAULT_WATCHES = {
    "scene":         (0x800CFEE8, 1),  # g_currentScene: 0/1/2 branding, 3 attract, 4 menu-hub
    "scene_changed": (0x800CFD48, 1),  # g_sceneChanged
    "song":          (0x8011E4F8, 1),  # g_currentSong (0..7)
    "game_mode":     (0x80110A01, 1),  # g_gameMode
    "game_init":     (0x80110A02, 1),  # g_gameInitialized
    "players":       (0x8011EF20, 1),  # g_playercount
    "frame_counter": (0x801109F4, 4),  # g_gameFrameCounter (in-game frames)
    "obj_slot_buf":  (0x80129200, 4),  # g_sceneObjSlotMatrixBuf (the scene-4 crash pointer)
    # menu navigation state (found via RAM-diff exploration):
    "menu_hub_state": (0x800D7520, 4),  # g_menuHubState
    "menu_cursor":   (0x800D3D00, 4),  # g_sceneMenuCursor — main-menu widget index (UP/DOWN)
    "menu_prev_cursor":   (0x800D3D10, 4),  # g_sceneMenuPrevCursor
    "scene_main_state": (0x800D3D24, 4),  # g_sceneMainState — changes on A (submenu enter)
    "game_type":      (0x8011EEEC, 1),  # g_selectedGameType
    # save/data (profile) screen state:
    "save_cursor":    (0x800D3DEC, 1),  # g_saveDataScreenCursor (file-list highlight)
    "obj_render_enable": (0x800D3D94, 4),  # g_sceneObjRenderEnable (input lock)
    "pak_files":      (0x80110580, 4),  # g_dataMenuPakFileCount
    # gameplay (scene 9) pointers — the piece struct is heap-allocated (~0x8023xxxx):
    "piece_ptr":      (0x8011FB70, 4),  # g_currentPiece_ptr -> active piece struct
    "mobile_cubes_ptr": (0x8011FBF0, 4),  # g_mobileCubes_ptr -> locked/board cubes
    "minos_ptr":      (0x8011FC10, 4),  # g_minos_ptr
    "buttons_pressed": (0x8011EF54, 4),  # g_buttonsPressed — per-frame edge-input mask
}


def _sleep(dt):
    """time.sleep replacement that survives the SIGSTKFLT 'sleep' block."""
    if dt > 0:
        select.select([], [], [], dt)


def _pspath(name):
    return REPO / "build-cmake" / name  # unused; kept for clarity


class GameError(RuntimeError):
    pass


class Game:
    def __init__(self, rom=DEFAULT_ROM, watches=None, workdir=None, no_autoboot=False,
                 env=None, logfile=None, mods=None, region=None, controllers=1,
                 data_home=None):
        self.controllers = controllers
        self.rom = Path(rom)
        # data_home: when set, the game runs with HOME + XDG_DATA_HOME redirected
        # here, so its entire config/mods/saves tree (incl. the mem-pak) is isolated
        # from the user's real ~/.local/share. The caller (e.g. the pytest fixtures)
        # is responsible for seeding <data_home>/.local/share/N64Recomp/TheNewTiptris/
        # (mods/ + mods.json). This is how tests avoid touching / inheriting the
        # user's installed mods. When None, legacy behavior (edits the real mods.json).
        self.data_home = Path(data_home) if data_home else None
        self.watches = dict(DEFAULT_WATCHES if watches is None else watches)
        # region: (base_addr, length) to snapshot for RAM-diff discovery, or None.
        self.region = region
        self.no_autoboot = no_autoboot
        self.extra_env = dict(env or {})
        # mods: None = leave the installed mods.json untouched; a list of mod ids
        # = set enabled_mods to exactly that list for this run (restored on stop),
        # so a test can A/B a mod (e.g. the crash guard) deterministically.
        self.mods = mods
        self._mods_json = Path.home() / ".local/share/N64Recomp/TheNewTiptris/mods.json"
        self._mods_backup = None
        self.workdir = Path(workdir or (os.environ.get("TMPDIR", "/tmp") + "/tnt_e2e"))
        self.workdir.mkdir(parents=True, exist_ok=True)
        self.state_path = self.workdir / "state.txt"
        self.watch_path = self.workdir / "watch.txt"
        self.input_path = self.workdir / "input.txt"
        self.poke_path = self.workdir / "poke.txt"
        self.log_path = Path(logfile) if logfile else (self.workdir / "game.log")
        self.proc = None

    # ---- lifecycle --------------------------------------------------------
    def _heal_dzn(self):
        if not DZN.exists():
            return
        want = f'"{DZN.parent}/libvulkan_dzn.so"'
        txt = DZN.read_text()
        if want not in txt:
            import re
            DZN.write_text(re.sub(r'"library_path": "[^"]*"',
                                  f'"library_path": "{DZN.parent}/libvulkan_dzn.so"', txt))

    def _apply_mods(self):
        if self.mods is None or not self._mods_json.exists():
            return
        import json
        self._mods_backup = self._mods_json.read_text()
        d = json.loads(self._mods_backup)
        d["enabled_mods"] = list(self.mods)
        self._mods_json.write_text(json.dumps(d, indent=4))

    def _restore_mods(self):
        if self._mods_backup is not None:
            self._mods_json.write_text(self._mods_backup)
            self._mods_backup = None

    def start(self):
        if not BIN.exists():
            raise GameError(f"binary not built: {BIN}")
        if not self.rom.exists():
            raise GameError(f"ROM not found: {self.rom}")
        self._heal_dzn()
        if self.data_home is None:
            self._apply_mods()  # legacy: mutate the real mods.json (non-isolated)
        # write the watch list + clear the input/state files
        self.watch_path.write_text(
            "".join(f"{n} 0x{a:08X} {w}\n" for n, (a, w) in self.watches.items()))
        self.input_path.write_text("")
        self.poke_path.write_text("")
        if self.state_path.exists():
            self.state_path.unlink()

        env = dict(os.environ)
        # Isolated data dir: redirect HOME + XDG_DATA_HOME so SDL's pref path
        # (config/mods/saves) and pak.cpp's $HOME-based mempak both land under a
        # throwaway tree, never the user's real ~/.local/share. TNT_ROM is absolute,
        # so ROM loading is unaffected by the HOME change.
        if self.data_home is not None:
            self.data_home.mkdir(parents=True, exist_ok=True)
            env["HOME"] = str(self.data_home)
            env["XDG_DATA_HOME"] = str(self.data_home / ".local" / "share")
        # Force SDL's dummy audio driver for headless testing: the WSLg PulseAudio
        # bridge is intermittent and the app's audio init can stall when it's down,
        # blocking boot. Audio is irrelevant to E2E; dummy always inits instantly.
        # (main.cpp only forces pulseaudio when SDL_AUDIODRIVER is unset.)
        env.setdefault("SDL_AUDIODRIVER", "dummy")
        env["TNT_CONTROLLERS"] = str(self.controllers)
        env["TNT_STATE_OUT"] = str(self.state_path)
        env["TNT_STATE_WATCH"] = str(self.watch_path)
        env["TNT_INPUT"] = str(self.input_path)
        env["TNT_STATE_POKE"] = str(self.poke_path)
        if self.region is not None:
            env["TNT_STATE_REGION"] = f"0x{self.region[0]:08X} {self.region[1]}"
        if DZN.exists():
            env["VK_ICD_FILENAMES"] = str(DZN)
        if self.no_autoboot:
            env["TNT_NO_AUTOBOOT"] = "1"
        else:
            env["TNT_ROM"] = str(self.rom)
        env.update({k: str(v) for k, v in self.extra_env.items()})

        self.log = open(self.log_path, "w")
        self.proc = subprocess.Popen([str(BIN)], env=env, cwd=str(REPO),
                                     stdout=self.log, stderr=subprocess.STDOUT,
                                     start_new_session=True)
        return self

    def stop(self):
        if self.proc and self.proc.poll() is None:
            try:
                os.killpg(os.getpgid(self.proc.pid), signal.SIGKILL)
            except ProcessLookupError:
                pass
        if getattr(self, "log", None):
            self.log.close()
        self._restore_mods()

    def __enter__(self):
        return self.start()

    def __exit__(self, *exc):
        self.stop()

    def alive(self):
        return self.proc is not None and self.proc.poll() is None

    def crashed(self):
        """True if the process exited (a crash exits non-zero / on signal)."""
        return self.proc is not None and self.proc.poll() is not None

    # ---- state observation ------------------------------------------------
    def state(self):
        """Parse the latest atomic state dump -> dict[str,int]. {} if none yet."""
        try:
            txt = self.state_path.read_text()
        except (FileNotFoundError, ValueError):
            return {}
        out = {}
        for line in txt.splitlines():
            if "=" in line:
                k, _, v = line.partition("=")
                try:
                    out[k] = int(v)
                except ValueError:
                    pass
        return out

    def read(self, name):
        return self.state().get(name)

    def frame(self):
        return self.state().get("_frame", 0)

    def wait_alive(self, timeout=30.0):
        """Wait until the game is rendering (heartbeat advancing)."""
        deadline = time.monotonic() + timeout
        start_frame = -1
        while time.monotonic() < deadline:
            if self.crashed():
                raise GameError(f"game exited (code {self.proc.poll()}) before first frame; see {self.log_path}")
            f = self.frame()
            if start_frame < 0 and f > 0:
                start_frame = f
            if start_frame >= 0 and f > start_frame + 1:
                return True
            _sleep(0.05)
        raise TimeoutError(f"game did not start rendering within {timeout}s (see {self.log_path})")

    def wait_for(self, name, pred, timeout=20.0, desc=None, poll=0.03):
        """Poll until pred(state[name]) is true; returns the value. Raises on timeout/crash."""
        deadline = time.monotonic() + timeout
        last = None
        while time.monotonic() < deadline:
            if self.crashed():
                raise GameError(f"game crashed (code {self.proc.poll()}) while waiting for "
                                f"{desc or name}; last {name}={last}; see {self.log_path}")
            st = self.state()
            last = st.get(name)
            if last is not None and pred(last):
                return last
            _sleep(poll)
        raise TimeoutError(f"timeout ({timeout}s) waiting for {desc or name} "
                           f"(last {name}={last}); see {self.log_path}")

    # ---- input injection --------------------------------------------------
    def hold(self, *scancodes):
        """Hold the given scancodes (level-triggered; call release() to let go)."""
        self.input_path.write_text(" ".join(str(int(s)) for s in scancodes) + "\n")

    def release(self):
        self.input_path.write_text("")

    # ---- state poke (force game RAM) --------------------------------------
    def poke(self, addr, width, value):
        """Continuously force *addr = value (held until clear_pokes()). width 1/2/4."""
        self.poke_path.write_text(f"0x{addr:08X} {width} {value}\n")

    def poke_lines(self, lines):
        """Force multiple addresses: lines = [(addr,width,value), ...]."""
        self.poke_path.write_text("".join(f"0x{a:08X} {w} {v}\n" for a, w, v in lines))

    def clear_pokes(self):
        self.poke_path.write_text("")

    def press(self, *scancodes, hold=1.0, release=True):
        """Hold scancodes for `hold` seconds, then release (unless release=False)."""
        self.hold(*scancodes)
        _sleep(hold)
        if release:
            self.release()

    def tap(self, *scancodes, settle=0.25):
        """A SINGLE-STEP press: short enough (a few frames) that the game sees one
        edge and moves exactly one item — avoids the auto-repeat that a long hold
        triggers (which skips menu items). Use for menu cursor nav."""
        self.hold(*scancodes)
        _sleep(0.05)          # ~3 frames: one edge, below the auto-repeat threshold
        self.release()
        _sleep(settle)        # let the move + animation settle before reading

    def wait_frames(self, n):
        """Wait for n rendered frames (heartbeat ticks)."""
        start = self.frame()
        self.wait_for("_frame", lambda f: f >= start + n, timeout=max(5.0, n / 30.0 + 2))

    # ---- visual capture (WSLg window via Windows-side winburst.ps1) --------
    def shot(self, name="shot"):
        """Capture the current game window to a PNG and return the local path
        (or None). Uses winburst.ps1 (matches the game window title, crops to the
        window rect). Lets us VISUALLY verify a screen, not just RAM.

        Match on "T64ris" (unique to "The New T64ris : Recompiled"), NOT "Recompiled":
        a wedged half-initialized instance keeps the ultramodern default title
        "Xbox Recompiled Game", and matching "Recompiled" would capture that blank
        zombie window instead of the game. "T64ris" can only match the real window."""
        winout = f"C:\\Users\\Public\\tnt_shot_{name}"
        try:
            subprocess.run(["powershell.exe", "-NoProfile", "-ExecutionPolicy", "Bypass",
                            "-File", "C:\\Users\\Public\\winburst.ps1",
                            "T64ris", winout, "2", "120", "25"],
                           capture_output=True, timeout=40)
        except Exception:
            return None
        src = Path(f"/mnt/c/Users/Public/tnt_shot_{name}")
        pngs = sorted(src.glob("*.png")) if src.exists() else []
        if not pngs:
            return None
        dst = self.workdir / f"{name}.png"
        dst.write_bytes(pngs[-1].read_bytes())
        return dst

    # ---- RAM-diff discovery (needs region=(base,len)) ---------------------
    def snapshot(self):
        """Read the current region snapshot as bytes (needs region set)."""
        return (self.workdir / "state.txt.region").read_bytes()

    def diff(self, before, after, changed_only=True):
        """Diff two region snapshots word-by-word -> [(addr, old, new)]."""
        base = self.region[0]
        out = []
        n = min(len(before), len(after)) // 4
        for i in range(n):
            o = int.from_bytes(before[i*4:i*4+4], "little")
            a = int.from_bytes(after[i*4:i*4+4], "little")
            if not changed_only or o != a:
                out.append((base + i*4, o, a))
        return [x for x in out if x[1] != x[2]] if changed_only else out

    def find_changes(self, action, settle=0.4):
        """Snapshot, run action(), settle, snapshot, return changed [(addr,old,new)].
        Use to discover which globals an input mutates (e.g. cursor)."""
        self.wait_frames(2)
        before = self.snapshot()
        action()
        _sleep(settle)
        after = self.snapshot()
        return self.diff(before, after)
