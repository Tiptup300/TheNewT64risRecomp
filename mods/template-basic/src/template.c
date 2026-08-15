#include "modding.h"
#include "recompconfig.h"   // recomp_get_config_u32 — reading a config option (exported)

// =============================================================================
// template-basic — the canonical "copy me" starting point for a TntRecomp mod.
// =============================================================================
// It demonstrates, in one place, the five moves almost every mod makes:
//   (1) hook a per-frame game function       -> RECOMP_HOOK("Scene_Update")
//   (2) read a user config option            -> recomp_get_config_u32("enabled")
//   (3) gate on the current game state        -> only act during gameplay (scene 9)
//   (4) read edge-triggered input             -> g_buttonsPressed mask
//   (5) write game RAM safely                 -> a sentinel in unused scratch RAM
//
// The EFFECT here is intentionally trivial and 100% safe: when enabled, during
// gameplay, it counts how many times you press the A button into a scratch word.
// Nothing about the game changes. Swap step (5) for a real game-RAM write once you
// know what you want to do (see docs/GAME_STATE_MAP.md for addresses, and
// docs/MODDING.md for the hook-vs-patch rules and pitfalls).
//
// IMPORTANT (this runtime): include ONLY modding.h and (optionally) recompconfig.h.
// Including recomputils.h makes the mod fail to load ("Imported function not found")
// because this build doesn't export recomp_printf et al. There is no mod-side
// logging — observe effects by watching RAM (this mod's scratch word, below).
// A RECOMP_HOOK may read and write game RAM but CANNOT change what the hooked
// function computes (the CPU context is restored after the hook). Use RECOMP_PATCH
// for that.

// --- game RAM this mod touches (names/addresses from docs/GAME_STATE_MAP.md) ---
#define SCENE            (*(volatile unsigned char*)0x800CFEE8)  // g_currentScene
#define BUTTONS_PRESSED  (*(volatile unsigned int*)0x8011EF54)   // g_buttonsPressed (edge mask)
#define SCENE_GAMEPLAY   9

// The A button's bit in the N64 controller mask. (Confirm the exact bit against
// g_buttonsPressed with tools/e2e/probe_inputs.py if you rely on it; 0x8000 is the
// standard N64 A-button bit.)
#define BTN_A            0x8000u

// --- this mod's own scratch RAM (unused by the game; safe to read/write) ---
// 0x807FFF00 is well inside 8 MB RDRAM and outside the game's used data — the same
// scratch the `hello` mod uses as a validation marker. Watch it with the harness:
//   Game(...).read of address 0x807FFF00, or add it to DEFAULT_WATCHES.
#define A_PRESS_COUNT    (*(volatile unsigned int*)0x807FFF00)

// Track the previous frame's mask ourselves so we count edges (press, not hold)
// even if the game's mask is level- rather than edge-triggered for our purposes.
static unsigned int s_prev_buttons = 0;

// Scene_Update runs once per frame and dispatches the whole game by scene id — the
// workhorse hook point (see docs/MODDING.md §6). We do the least work possible here.
RECOMP_HOOK("Scene_Update") void tnt_template_tick(void) {
    // (2) config: a single Enum option "enabled" = { Off, On } -> 0 or 1.
    if (recomp_get_config_u32("enabled") == 0) {
        return;
    }

    // (3) state gate: only act during active gameplay.
    if (SCENE != SCENE_GAMEPLAY) {
        s_prev_buttons = 0;   // reset edge tracking when we leave gameplay
        return;
    }

    // (4) read input and detect a fresh A-button edge (down this frame, up last).
    unsigned int buttons = BUTTONS_PRESSED;
    unsigned int fresh = buttons & ~s_prev_buttons;
    s_prev_buttons = buttons;

    // (5) safe write: bump our own scratch counter on each A press.
    if (fresh & BTN_A) {
        A_PRESS_COUNT = A_PRESS_COUNT + 1;
    }
}
