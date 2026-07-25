#include "modding.h"
#include "recompconfig.h"

// Map/background selector. The game picks one of 8 backgrounds per game via
// func_800A35EC(0,7) in func_80090E08 and stores the index as a byte at
// 0x8011E4F8 (game_ptr->unkE4F8). This mod forces that byte to the configured
// map each frame, so you can play/test a specific background instead of random.
//
// Config "map" (Enum) indices: 0 = Random (off), 1..8 => map index 0..7.
// The index->name mapping (from the decomp's images.cfg order) is a best guess:
//   0 Main, 1 Mayan, 2 Japanese, 3 Egyptian, 4 Celtic, 5 African, 6 Greek, 7 Russian
// — verify in-game and relabel; that's exactly what this mod is for.
//
// NOTE: if the background is loaded once at game start (not re-read per frame),
// forcing the byte here may not switch the *current* game's background — tune the
// hook point after testing.
#define MAP_BYTE (*(volatile unsigned char*)0x8011E4F8)

RECOMP_HOOK("FUN_032F00_MVC_control_menu_choice_process") void tnt_force_map(void) {
    unsigned long sel = recomp_get_config_u32("map");   // 0 = Random/off, 1..8 => map 0..7
    if (sel >= 1 && sel <= 8) {
        MAP_BYTE = (unsigned char)(sel - 1);
    }
}
