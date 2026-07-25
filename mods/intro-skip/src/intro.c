#include "modding.h"
#include "recompconfig.h"   // recomp_get_config_u32 (registered via register_ext_base_export)

// Configurable intro skip. A "skip_to" enum config option (see mod.toml) chooses
// how far the intro fast-forwards:
//   0 Off        — don't skip anything (normal N64 logo -> publisher -> attract...)
//   1 Publisher  — skip the N64 logo, stop on the H2O/Blue Planet publisher screen
//   2 Attract    — skip both branding screens to the attract flythrough (default)
//   3 Start menu — skip to the title / PRESS START
//   4 Menu       — skip to the main menu hub
//
// The top-level scene is a byte at 0x800CFEE8, dispatched by
// FUN_032F00_MVC_control_menu_choice_process (jump table 0x800DD7C0). Boot scenes:
// 0/1/2 = branding, 3 = attract flythrough, 4 = menu hub. 0x800CFD48 is the
// "scene changed" flag the game sets on transitions.
//
// NOTE: the exact scene for "publisher" vs "start menu" vs "menu" is inferred and
// not yet verified in-game — tune the target values below once confirmed.
#define SCENE       (*(volatile unsigned char*)0x800CFEE8)
#define SCENE_FLAG  (*(volatile unsigned char*)0x800CFD48)

static void go(unsigned char target) {
    SCENE = target;
    SCENE_FLAG = 1;   // notify: top-level scene changed
}

RECOMP_HOOK("FUN_032F00_MVC_control_menu_choice_process") void tnt_skip_intro(void) {
    unsigned long mode = recomp_get_config_u32("skip_to");
    unsigned char s = SCENE;
    switch (mode) {
        case 0: /* Off */                                         return;
        case 1: /* Publisher */  if (s == 0)  go(1);              return;
        case 2: /* Attract   */  if (s <= 2)  go(3);              return;
        case 3: /* Start menu*/  if (s <= 3)  go(4);              return;
        case 4: /* Menu      */  if (s <= 3)  go(4);              return;
        default:                 if (s <= 2)  go(3);              return;
    }
}
