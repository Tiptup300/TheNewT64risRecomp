#include "modding.h"

// Unlock all Wonders at game start.  Bundled but OFF by default (opt-in cheat).
//
// The New Tetris unlocks its seven Wonders by cumulative "wonder lines" cleared,
// compared each frame against a threshold table (see wonders2 / D_800CF928, and
// the Rebalanced Wonder Requirements mod). Setting the *saved* total-wonder-lines
// above every threshold makes all seven Wonders unlocked/achieved from the start.
//
// Storage (traced from SaveData_Set/GetTotalWonderLines @ 0x8007BC90/0x8007BCB4):
// the 32-bit total is stored bit-split as a light anti-tamper measure —
//   even bits (mask 0xAAAAAAAA) at  saveBase + 0xF04
//   odd  bits (mask 0x55555555) at  saveBase + 0xF08
// and Get() OR's the two halves back together. The SaveData struct base pointer
// lives at 0x8011FCF0 (the value wonders2 loads before calling GetTotalWonderLines).
//
// NOTE: not yet verified in-game (unlock/progression needs a playthrough the
// headless harness can't drive) — enable it and confirm. Only modding.h is
// included (this runtime exports neither recomp_printf nor recomp_get_config_*,
// so the mod is a fixed toggle, not runtime-configurable).
#define SAVE_BASE_PTR 0x8011FCF0
#define UNLOCK_LINES  999999u   // exceeds every wonder threshold (stock max 499999)

RECOMP_HOOK("Game_Init") void tnt_unlock_all_wonders(void) {
    unsigned int base = *(volatile unsigned int*)SAVE_BASE_PTR;
    // Safety: only write through a plausible KSEG0 RAM pointer, so a wrong/uninit
    // base can never corrupt arbitrary memory.
    if (base < 0x80000000u || base >= 0x80800000u) {
        return;
    }
    *(volatile unsigned int*)(base + 0xF04) = UNLOCK_LINES & 0xAAAAAAAAu;
    *(volatile unsigned int*)(base + 0xF08) = UNLOCK_LINES & 0x55555555u;
}
