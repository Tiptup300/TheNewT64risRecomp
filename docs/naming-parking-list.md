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
