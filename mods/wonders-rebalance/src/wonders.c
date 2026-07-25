#include "modding.h"

// Wonders line-requirement rebalance.
//
// The seven Wonders each require a cumulative line count. The stock values ramp
// absurdly (…99999, 249999, 499999). This mod rewrites them to a gentler curve.
//
// Those requirements live in a single 7-entry table in game RAM at 0x800CF928,
// read via the `lui 0x800D` / `lw -0x6D8` pattern in modes/wonders2.c (8 call
// sites) and used by both the "lines remaining" display and the completion
// checks. Rewriting the table once at startup rebalances every reader
// consistently — there is no single getter to patch instead.
//
// Address derivation: wonders2_GetLinesRemainingToWonder computes the element
// address as (0x800D0000 - 0x6D8) + wonder_index*4, so table base = 0x800CF928.
//
// Only modding.h is included: this runtime doesn't export the recomputils.h
// import set (recomp_printf etc.), so including it would make the mod fail to
// load. Game memory is reached via raw KSEG0 pointers, which the recompiler
// translates to game-RAM accesses.
#define WONDER_THRESHOLDS 0x800CF928
#define WONDER_COUNT 7

// Stock values, ascending by wonder. We verify against these before writing so a
// wrong address or an unexpected ROM revision can never corrupt memory.
static const unsigned int kOriginal[WONDER_COUNT] = {
    2499, 7499, 19999, 49999, 99999, 249999, 499999
};

// Rebalanced values (from TODO): a smoother ramp topping out at the same 99999.
static const unsigned int kRebalanced[WONDER_COUNT] = {
    2499, 9300, 20061, 34611, 52838, 74657, 99999
};

// Game_Init runs once when a game session starts. The threshold table is static,
// always-resident game data, so it's present by now; re-applying each session is
// harmless and robust.
RECOMP_HOOK("Game_Init") void tnt_wonders_rebalance(void) {
    volatile unsigned int* table = (volatile unsigned int*)WONDER_THRESHOLDS;

    // Safety guard: only patch a table that matches the known stock values.
    for (int i = 0; i < WONDER_COUNT; i++) {
        if (table[i] != kOriginal[i]) {
            return;
        }
    }

    for (int i = 0; i < WONDER_COUNT; i++) {
        table[i] = kRebalanced[i];
    }
}
