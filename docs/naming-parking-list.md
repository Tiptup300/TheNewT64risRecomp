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
| func_8007C8B0, func_8007CF40, func_8007D214, func_8007D25C, func_8007D458, func_8007DA00 | system/SaveData.c | low-conf | (partly resolved) | Remaining 6 of the math/effect block co-located in SaveData.c. 5 were named (Math_CosineRadialGrid, Math_AdvanceWrapAngles, Math_GridMagnitude, Math_ApplySineWave, Mtx_FromEulerToGfx) and re-homed. These 6 are setup/aggregators mixing scene+save+libultra calls (func_8007DA00 is a broad per-frame aggregator) — need call-graph context once neighbors settle. |
| ~160 functions in system/frametime.c (the vram catch-all) | system/frametime | runtime | none / multi-subsystem | Triaged all ~216: only ~10-23 pin to a single owning subsystem via a named caller (those were named + re-homed); 63 have NO callers AND NO callees; ~56 touch only external os*/math or MULTIPLE subsystems (shared utilities). The remaining ~160 have no static evidence — need emulator/boot tracing or behavioral RE. This is the bulk of the honest residue: it caps the realistic STATIC function ceiling at ~78-82%, not ~100%. Revisit only with a runtime trace. |
| ~5 AI funcs mis-bucketed in misc/Controller.c (FUN_003E40_*, FUN_004220_*) | misc/Controller | low-conf | aisquarelist_* callees | Call aisquarelist_*/CurrentPiece_TestTransform — AI board-model logic, not controller. Name under an AI prefix in an aisquarelist-focused batch, then reorganize re-homes them. |
