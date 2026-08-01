# Naming parking list

Functions/globals deferred during the recursive naming loop (see
`docs/naming-campaign-plan.md`) because they lack enough **static** evidence to name
with high/med confidence. This is the honest residue behind the "~100%" target — we
do NOT force meaningless names onto these.

A parked entry is **re-activated** in a later sweep when its context changes:
`dataxref.py --func` shows it now shares a *named* global with a named cluster, OR
`callgraph.py --callers` now shows a named caller. Re-check parked entries after
each cluster completes.

`reason` values:
- `low-conf` — some evidence, but not enough yet; likely nameable after neighbors are named.
- `runtime` — no static evidence at all (e.g. every global it touches is a
  dynamically-derived pointer); would need emulator/boot tracing. Parked indefinitely.

| symbol | cluster | reason | named-neighbor snapshot | notes |
|---|---|---|---|---|
| func_8007D25C, func_8007D458 | (was system/SaveData.c) | low-conf | mostly resolved | The SaveData.c "math/effect" block turned out to be an **animated 3D backdrop system** — resolved on the second sweep: Gfx_RenderBackground3D (DA00), Gfx_InitBackground3D (CF40), Gfx_RandomizeBackgroundGrid (C8B0), Scene_SetScene4 (D214), + the earlier Math_*/Mtx_* names. Only these 2 helpers remain unpinned. |
| ~160 functions in system/frametime.c (the vram catch-all) | system/frametime | runtime | none / multi-subsystem | Triaged all ~216: only ~10-23 pin to a single owning subsystem via a named caller (those were named + re-homed); 63 have NO callers AND NO callees; ~56 touch only external os*/math or MULTIPLE subsystems (shared utilities). The remaining ~160 have no static evidence — need emulator/boot tracing or behavioral RE. This is the bulk of the honest residue: it caps the realistic STATIC function ceiling at ~78-82%, not ~100%. Revisit only with a runtime trace. |
| ~5 AI funcs mis-bucketed in misc/Controller.c (FUN_003E40_*, FUN_004220_*) | misc/Controller | low-conf | aisquarelist_* callees | Call aisquarelist_*/CurrentPiece_TestTransform — AI board-model logic, not controller. Name under an AI prefix in an aisquarelist-focused batch, then reorganize re-homes them. |
| ~74 funcs in graphics/CubeTiles.c | graphics/CubeTiles | runtime/low-conf | ObjInit/ObjDraw/camera/asset families named | The CubeTiles object lib's residue is ~9 byte-identical no-op virtual-handler variants (`return 0` / `if(-1) heapfree else AssetRelease`) that are individually indistinguishable, plus large matrix/trig transform builders (sinf/cosf/guNormalize/guMtxF2L) with no precise static identity, plus empty stubs. Named the ~25 with clear roles; the rest is genuine residue. |

## Variable (datasym) naming — honest STATIC ceiling reached (~76%)

The variable metric plateaued at **695/915 named (76.0%)** after 3 dedicated data
waves (15 agents) + the incidental harvest from function waves. The target of 88%
is **not reachable by static naming**, for a structural reason confirmed repeatedly:

- **State lives in heap structs behind named pointers.** Core game state (score/
  level/lines via `g_gameStats_ptr`), the piece/board model (`g_currentPiece_ptr`,
  `g_boardPieces_ptr`), the audio manager/song player (`g_audioMgr`, `g_songPlayer`),
  the scene object-view instances — all are reached as `base + offset`. The
  flat-address recompiler emits a separate `D_xxxxxxxx` datasym for *each* interior
  field, inflating the denominator with entries that are **not standalone variables**
  and cannot be given a meaningful standalone name.
- **ROM `.rodata` strings/tables are content-defined.** ~17–27 remaining placeholders
  are format/display strings and coefficient tables whose *content* lives in ROM data
  (which this project must never commit or read) — the recompiled code references them
  only by address, so they are unnameable from code alone.
- **111 of the 220 remaining placeholders are referenced by NO named function** (pure
  data-relocation targets or referenced only by other placeholders) — zero code
  context to name from.

What WAS named is the genuine standalone-global population: OS/thread/message-queue
globals, audio heap/thread/DMA companions, VI-mode + bg3d animation state, fault
handler block, playfield draw-object + color-table arrays (index-named on confirmed
boundaries), data-menu/controller-pak state, screen-fade pairs, text cursors,
sine/rand tables, per-mode presets. Going beyond ~76% would require **runtime/
behavioral RE** (observing heap struct layouts live) or reading ROM data — neither
is in scope. This caps the honest STATIC variable ceiling at ~76–80%.
