# Naming & organization methodology for a static-recompilation RE project

A generic write-up of how we keep function/variable names and the source hierarchy legible while
reverse-engineering a statically-recompiled console game. Console/game-agnostic — the specifics
(prefixes, domains) are examples; the *system* is the point.

## 1. One canonical source of truth: the symbol map

All names live in a **symbol map** (we use two TOML files: one for functions, one for data
symbols), keyed by address. This — not the generated source — is where you rename. The recompiled
`.c` is regenerated/re-bucketed from the map, so the map is the single place a name is defined.

- Rename in the map, then regenerate. Never hand-edit a name in the generated code.
- Keep functions and data in **separate** maps; they have different gates (see §5).
- Every symbol has a unique address; the map is the authority on "what is at 0xXXXX".

## 2. Function naming convention

`Subsystem_VerbObject`, PascalCase, subsystem prefix first:

- `Scene_Main`, `Controller_GetStatus`, `MobileCubes_Move`, `CubeTiles_EmitTileRenderMode`,
  `Board_FindLastOccupiedRow`.
- The **prefix is a namespace** — it groups the function and drives the folder hierarchy (§4).
  Pick one prefix per subsystem and stay consistent (`Scene_*`, `Audio_*`, `Gfx_*`).
- **Leave standard-library / SDK functions at their real names** (`osCreateThread`, `guRotateRPYF`,
  `memcpy`). Don't invent names for code you can identify as the platform SDK — recognizing it *is*
  the naming.
- **Placeholders are first-class.** For code you haven't cracked, use a descriptive placeholder that
  encodes what you *do* know rather than a generic `func_80xxxx`:
  `game_over_display_stuff_huge_function`, `weird_lots_of_magic_number_setting_66xrefs`. Include a
  hint (behavior, size, or xref count) so the next pass knows where to dig. A good placeholder is a
  to-do list item; `sub_1234` is not.

## 3. Variable / global naming convention

- Globals: `g_` prefix + `Subsystem`/role + camelCase tail — `g_currentScene`, `g_buttonsPressed`,
  `g_sceneMainState`. The prefix makes globals grep-able and distinct from locals.
- Pointers: a `_ptr` suffix when it matters (`g_currentPiece_ptr`). Tables/arrays: `Tbl`/`Buf`
  (`g_drawParamPresetTbl`, `g_sceneViewObjBuf`).
- Same placeholder discipline as functions for data you haven't identified.

## 4. Hierarchy: bucket by subsystem prefix

Source is laid out `Recompiled/<domain>/<subsystem>.c`. A function's **prefix decides its bucket**,
so naming and sorting are the same act. Example domain set:

```
ai/  audio/  core/  gameplay/  graphics/  misc/  modes/  system/
```

- **Domain** = broad area (graphics, gameplay, system). **Subsystem** = the prefix's file
  (`graphics/CubeTiles.c`, `core/Scene.c`).
- A tool **re-buckets automatically from the current names** — rename a function's prefix and rerun
  it, and the function moves to the right file. This keeps the hierarchy a *projection* of the
  names, never hand-maintained. Re-run it after any regen or prefix-changing rename.
- `misc/` is the honest holding pen for not-yet-classified code; shrinking it is a progress signal.

## 5. Gate every rename (never silently break the build)

Renaming must not change behavior or break the build. Each rename passes a check before commit:

- **Function symbol invariant:** every recompiled function is defined *exactly once* — no
  duplicate/missing symbols. A rename that collides or drops a symbol fails the build/link. This is
  the definitive "did I break it" check and runs headless in seconds (no emulator/GPU).
- **Data symbol lint:** no duplicate addresses, valid names, addresses in range.
- One green/red command runs both + a configure/build/link. Commit only on green; one rename set
  per commit; note old→new in the commit message.

## 6. Names are *living* — refine as you learn

The biggest legibility win is treating names as provisional and fixing them the moment you learn
more:

- When a name is vague, generic, or turns out **wrong** (static RE or live testing reveals the real
  role), rename it *in that same pass* — don't leave a known-bad name "for later."
- **Cross-validated corrections are best:** static disassembly + a live runtime observation both
  pointing at the same role. E.g. a byte you *thought* was "song index" turns out to select the
  visible level — rename it and note the correction.
- Record the correction (commit message / a running notes file) so a wrong earlier belief doesn't
  get re-derived.

## 7. Tooling that makes it sustainable

Small scripts over the symbol map + generated source:

- **Safe rename** — renames in the map + regenerates, then runs the gate (§5). The only sanctioned
  way to rename.
- **Re-bucket** — re-sorts functions into the domain/subsystem hierarchy from current prefixes (§4).
- **Call graph** — a function's callers/callees + call tree. *The* fastest way to understand a
  subsystem before you name it: name the entry points, then walk outward.
- **Complexity ranking** — sort functions by cyclomatic complexity to pick high-value targets.
- **Coverage report** — % named vs placeholder, per subsystem. Your burndown metric; it also shows
  which files are still mostly `misc`/placeholder.
- **Cross-reference / data-xref** — who reads/writes a given global; essential for naming data by
  its actual use.

## 8. Suggested workflow for a new subsystem

1. Pick an entry point (a function you can identify from behavior or an SDK call).
2. Call-graph outward; give the cluster a **prefix** and provisional names.
3. Re-bucket so the cluster lands in one file.
4. Verify against runtime behavior where you can; correct names (cross-validate).
5. Gate + commit; watch the coverage metric move.

**Core principle:** the symbol map is the source of truth, the folder hierarchy is a *projection*
of the names, names are living and cross-validated, and **every rename is gated so legibility work
can never break the build.**
