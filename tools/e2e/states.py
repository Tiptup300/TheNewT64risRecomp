#!/usr/bin/env python3
"""states.py — the one shared source of truth for the game's states and key RAM.

Both the harness/probe tooling and human docs (`docs/GAME_STATE_MAP.md`) draw from
this. Each address here has been *reproduced* — driven by input and watched to change,
or read across a known transition — not guessed. Keep it that way: only add an address
after `probe_inputs.py` (or a test) has shown it move for the reason stated.

    from states import GLOBALS, SCENES, STATE_KEYS
    addr, width, desc = GLOBALS["scene"]

`GLOBALS` mirrors harness.DEFAULT_WATCHES (kept in sync) plus gameplay pointers; it is
the canonical (name -> (addr, width, meaning)) table. `SCENES` names the scene-byte
values. `STATE_KEYS` lists, per named state (see e2e_helpers.STATES), the globals most
worth watching there.
"""

# ---------------------------------------------------------------------------
# Named globals: name -> (address, width_bytes, meaning). Reproduced addresses only.
# ---------------------------------------------------------------------------
GLOBALS = {
    # --- top-level scene machine ---
    "scene":            (0x800CFEE8, 1, "g_currentScene — top-level scene id (see SCENES)"),
    "scene_changed":    (0x800CFD48, 1, "g_sceneChanged — set to 1 to force a scene transition"),

    # --- session / mode ---
    "song":             (0x8011E4F8, 1, "g_currentSong — music track index 0..7"),
    "game_mode":        (0x80110A01, 1, "g_gameMode"),
    "game_init":        (0x80110A02, 1, "g_gameInitialized — 1 after Game_Init"),
    "players":          (0x8011EF20, 1, "g_playercount"),
    "game_type":        (0x8011EEEC, 1, "g_selectedGameType"),
    "frame_counter":    (0x801109F4, 4, "g_gameFrameCounter — in-game frame tick"),

    # --- scene-4 menu widget engine ---
    "menu_hub_state":   (0x800D7520, 4, "g_menuHubState"),
    "menu_cursor":      (0x800D3D00, 4, "g_sceneMenuCursor — main-menu item index (UP/DOWN move it)"),
    "menu_prev_cursor": (0x800D3D10, 4, "g_sceneMenuPrevCursor"),
    "scene_main_state": (0x800D3D24, 4, "g_sceneMainState — changes on A (submenu enter)"),
    "obj_render_enable":(0x800D3D94, 4, "g_sceneObjRenderEnable — input/render lock"),

    # --- data/profile (controller-pak) screen ---
    "save_cursor":      (0x800D3DEC, 1, "g_saveDataScreenCursor — file-list highlight"),
    "pak_files":        (0x80110580, 4, "g_dataMenuPakFileCount"),

    # --- scene object system (the scene-4 crash pointer) ---
    "obj_slot_buf":     (0x80129200, 4, "g_sceneObjSlotMatrixBuf — null when scene 4 entered w/o setup -> SIGSEGV"),

    # --- gameplay (scene 9) pointers; fields confirmed by probe_inputs.py gameplay ---
    "piece_ptr":        (0x8011FB70, 4, "g_currentPiece_ptr — active piece struct (pos/rot move on L/R/A)"),
    "mobile_cubes_ptr": (0x8011FBF0, 4, "g_mobileCubes_ptr — locked/board cubes"),
    "minos_ptr":        (0x8011FC10, 4, "g_minos_ptr"),
    "buttons_pressed":  (0x8011EF54, 4, "g_buttonsPressed — per-frame edge-triggered input mask"),
}

# ---------------------------------------------------------------------------
# Scene-byte values (g_currentScene @ 0x800CFEE8).
# ---------------------------------------------------------------------------
SCENES = {
    0:  "branding (N64 logo)",
    1:  "branding (publisher)",
    2:  "intro cube-tiles",
    3:  "attract flythrough / title",
    4:  "main menu hub (widget engine)",
    7:  "wonders hall",
    8:  "wonders (sub)",
    9:  "gameplay (active)",
    10: "game over",
    11: "pause menu",
    12: "attract demo (auto-play)",
    13: "attract demo (auto-play)",
    14: "options / data",
    16: "credits",
}

# ---------------------------------------------------------------------------
# Per-state watch hints: which GLOBALS matter most in each e2e_helpers state.
# ---------------------------------------------------------------------------
STATE_KEYS = {
    "attract":  ["scene", "scene_changed", "song"],
    "menu":     ["scene", "menu_cursor", "menu_prev_cursor", "scene_main_state", "menu_hub_state"],
    "single":   ["scene", "menu_cursor", "scene_main_state", "game_type", "players"],
    "gameplay": ["scene", "piece_ptr", "mobile_cubes_ptr", "buttons_pressed", "frame_counter"],
    "wonders":  ["scene", "menu_cursor", "song"],
    "pause":    ["scene", "obj_render_enable", "frame_counter"],
}


def scene_name(v):
    return SCENES.get(v, f"scene {v} (unmapped)")


if __name__ == "__main__":
    print(f"{len(GLOBALS)} globals, {len(SCENES)} named scenes, {len(STATE_KEYS)} states\n")
    for name, (addr, width, desc) in GLOBALS.items():
        print(f"  {name:<18} 0x{addr:08X} /{width}  {desc}")
