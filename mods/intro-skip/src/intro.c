#include "modding.h"
#include "recompconfig.h"   // recomp_get_config_u32 (registered via register_ext_base_export)

// Configurable intro skip. "skip_to" enum (see mod.toml):
//   0 Off      — don't skip (normal N64 logo -> publisher -> attract...)
//   1 Attract  — skip the branding screens to the attract flythrough
//
// The top-level scene is a byte at 0x800CFEE8, dispatched by
// FUN_032F00_MVC_control_menu_choice_process. Boot scenes 0/1/2 = branding,
// 3 = attract flythrough, 4 = menu hub. 0x800CFD48 is the "scene changed" flag.
//
// NOTE: only Off/Attract are offered. Forcing the menu-hub scene (4) directly
// crashes — func_80090E08 -> func_8009EED4 segfaults on an unset scene pointer
// because jumping straight to scene 4 bypasses its setup (a separate bug being
// investigated). "Attract" (scene 3) is self-contained and safe.
#define SCENE       (*(volatile unsigned char*)0x800CFEE8)
#define SCENE_FLAG  (*(volatile unsigned char*)0x800CFD48)

RECOMP_HOOK("FUN_032F00_MVC_control_menu_choice_process") void tnt_skip_intro(void) {
    unsigned long mode = recomp_get_config_u32("skip_to");
    if (mode == 0) return;                 // Off
    // Attract (default): fast-forward the branding scenes to the flythrough.
    if (SCENE <= 2) {
        SCENE = 3;
        SCENE_FLAG = 1;
    }
}
