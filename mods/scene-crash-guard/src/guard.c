#include "modding.h"

// Scene-4 / start-playing crash guard (EXPERIMENTAL — untested at runtime).
//
// ROOT CAUSE (full RE): Scene_SetupObjectMatrices (0x8009EED4) loops 16 object
// slots (stride 0x1D0) and unconditionally writes matrices (guTranslate/guMtxF2L
// stores) into the scene-object slot buffer whose pointer is the fixed global
// field g_sceneObjSlotMatrixBuf @ 0x80129200 (= scene-object table 0x801290D0 +
// 0x130). That buffer is n64HeapAlloc'd only by Scene_AllocObjectBuffers via the
// NORMAL scene resource-load path, and is freed+NULLED by Scene_FreeObjectBuffers
// (which Scene_Init calls at teardown). If the menu-hub / play scene
// (g_currentScene 0x800CFEE8 == 4) is entered WITHOUT that load step — e.g. the
// attract demo starting a game — the pointer is null, so the store address folds
// (via the unmasked MEM_W) ~2GB into the runtime's PROT_NONE guard region → SIGSEGV.
//
// GUARD: Scene_SetupObjectMatrices runs 16x per setup; this hook fires at its entry.
// When the slot-buffer pointer is null, we point it at unused RDRAM just past the
// 8MB game region (0x80900000 — mapped/writable within the recomp's 512MB window,
// never touched by an 8MB-RAM N64 game). The 16 * 0x1D0 = 0x1D00 bytes of matrix
// stores then land there harmlessly instead of faulting. The scene is already
// broken (it was never set up), so the garbage matrices don't matter — this only
// converts a hard crash into "renders nothing / recovers". The next proper scene
// load overwrites [0x130] with a real allocation, so the scratch value is transient.
//
// SAFE BY CONSTRUCTION: the `if` is false whenever the buffer is a real allocation,
// so normal gameplay is completely unaffected — the guard acts ONLY in the
// already-crashing null state. Disabled by default; enable to test the skip-to-menu
// / attract-demo paths. Verify in-game (a clean display is needed).
#define OBJ_SLOT_MATRIX_BUF (*(volatile unsigned int*)0x80129200)  // g_sceneObjSlotMatrixBuf
#define SAFE_SCRATCH        0x80900000u  // unused RDRAM past 8MB, inside the 512MB map

RECOMP_HOOK("Scene_SetupObjectMatrices") void tnt_scene4_crash_guard(void) {
    if (OBJ_SLOT_MATRIX_BUF == 0) {
        OBJ_SLOT_MATRIX_BUF = SAFE_SCRATCH;
    }
}
