#include "modding.h"
#include "recomputils.h"

// Entry hook for Game_Init (a one-shot startup init in core/Game.c). Entry hooks
// run just before the target function. This one only prints, to prove the mod
// loaded and its hook fired — it reads no arguments and changes no state.
//
// "Game_Init" must exist in the function reference symbols (tnt.syms.toml) or
// RecompModTool fails the build.
RECOMP_HOOK("Game_Init") void tnt_hello_on_game_init(void) {
    recomp_printf("[tnt_hello_world] mod loaded — Game_Init hook fired\n");
}
