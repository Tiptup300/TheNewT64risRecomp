#include "modding.h"

// Pipeline-validation mod: hooks Game_Init to prove the mod toolchain works
// (clang -> MIPS ELF -> RecompModTool -> .nrm, loaded and its hook applied).
//
// NOTE: this runtime (pinned librecomp) does not export recomp_printf or the
// rest of the recomputils.h import set, so a mod that includes recomputils.h
// fails to load with "Imported function not found". This mod therefore includes
// only modding.h and does something observable without any imports: it writes a
// sentinel to a scratch word in game RAM so a hook firing can be confirmed
// (e.g. via a memory watch) without needing a logging function.
//
// 0x807FFF00 is well inside RDRAM (8 MB) and outside the game's used data, used
// here only as a harmless scratch marker for validation.
#define HELLO_MARKER (*(volatile unsigned int*)0x807FFF00)

RECOMP_HOOK("Game_Init") void tnt_hello_on_game_init(void) {
    HELLO_MARKER = 0x48454C4F; // "HELO"
}
