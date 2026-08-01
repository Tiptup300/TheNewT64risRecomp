// Stubs for a few libultra functions that N64Recomp renames to `*_recomp` and
// delegates to the runtime, but that this librecomp build does not provide.
// These are Controller-Pak (mempak) helpers and a debug printf — not needed for
// core gameplay (The New T64ris saves via EEPROM). Stubbed as no-ops for now.
#include "recomp.h"

extern "C" {

void rmonPrintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    // Debug monitor printf — no-op.
}

void __osContAddressCrc_recomp(uint8_t* rdram, recomp_context* ctx) {
    // Controller Pak address CRC — no-op (return 0 in v0).
    ctx->r2 = 0;
}

void __osContRamRead_recomp(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = 0;
}

void __osContRamWrite_recomp(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = 0;
}

}
