#include "modding.h"

// Skip the two intro branding screens (the N64 logo and the H2O / Blue Planet
// Software publisher-credits screen).
//
// The game runs a top-level scene state machine: a single byte at 0x800CFEE8
// selects the current scene every frame, dispatched by
// FUN_032F00_MVC_control_menu_choice_process via a jump table at 0x800DD7C0.
// Boot starts at scene 0 and plays the branding scenes (the low scene values)
// before reaching scene 3 — the post-branding attract sequence that flows on to
// the title ("PRESS START") and the menu.
//
// Hooking the dispatcher and fast-forwarding the branding scenes to scene 3
// lands the player exactly where a normal intro would continue, minus the two
// logo screens. 0x800CFD48 is the "scene changed" flag the game sets on every
// top-level transition; we set it too so the renderer is notified.
//
// Only modding.h is included on purpose: this runtime does not export
// recomp_printf / the recomputils.h import set, so pulling in recomputils.h
// would make the mod fail to load. Game memory is reached via raw KSEG0
// pointers, which the recompiler translates to game-RAM accesses.
#define SCENE       (*(volatile unsigned char*)0x800CFEE8)
#define SCENE_FLAG  (*(volatile unsigned char*)0x800CFD48)

RECOMP_HOOK("FUN_032F00_MVC_control_menu_choice_process") void tnt_skip_intro(void) {
    unsigned char s = SCENE;
    if (s <= 2) {          // branding scenes 0/1/2
        SCENE = 3;         // post-branding attract (continues to title/menu)
        SCENE_FLAG = 1;    // notify: top-level scene changed
    }
}
