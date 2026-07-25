# Plan: name & map the whole recompiled codebase

**Status:** ready to execute in batches across sessions. Self-contained.

## Context & goal

The recompiled game is ~1430 functions; **544 (38%) carry meaningful names**,
886 are still address placeholders (`func_8006xxxx`, `FUN_*`). The goal is to
systematically name and organize the rest so the codebase is a navigable map of
the game — using the tooling and struct/callgraph knowledge already built up.

**Non-negotiables** (same as every prior batch):
- `tnt.syms.toml` is the **canonical** source of truth. Rename there, then mirror
  the exact token into the generated files (`RecompiledFuncs/**/*.c`, `funcs.h`,
  `lookup.cpp`, `recomp_overlays.inl`) with a word-boundary `sed`. Never edit
  function *bodies* — they're mechanical register-level C.
- **Only apply high / med-high confidence names.** Low-confidence guesses
  propagate wrong context to callers; defer them.
- **Every batch gated green** by `tools/verify.sh`; one commit per batch.

## The toolkit (built this campaign)

| tool | use in this campaign |
|---|---|
| `tools/verify.sh` | green/red gate — run after every batch (symbol invariant + build+link). Headless; the link proves rename consistency. |
| `tools/callgraph.py <fn> [--callers/--callees -d N]` | **the key tool for the hard tier** — a placeholder's named callers/callees usually reveal its purpose. |
| `tools/complexity.py` | rank functions. Low complexity = fast near-certain names; high = core logic (name last, with callgraph context). Regenerates `FUNCTION_COMPLEXITY.md`. |
| `tools/reorganize_recompiled.py` | domain hierarchy + `FUNC_DOMAIN_OVERRIDE`. Re-run to re-bucket when a rename changes a prefix (then reconfigure cmake). |
| `FUNCTION_INDEX.md` / `FUNCTION_COMPLEXITY.md` | derived data; regenerate when stale. |
| `tools/rename_sym.py` | **guarded rename** — `--func`/`--data`/`--map` (atomic batch). Preflights refuse collisions/missing source (prevents the dup-symbol link fail); does the whole-word substitution across all artifacts for you; flags NEEDS-REORG on a prefix change. Use this instead of hand-`sed`. |
| `tools/dataxref.py` | **the variable engine** — reconstructs the absolute global address of every data access (`lui`+offset) and joins it to `tnt.datasyms.toml`. `--func` (globals a fn touches) → name them; `--addr` (every fn touching a global) → cross-confirm + spread context. Read-only. |
| `tools/datacoverage.py` | variable-naming progress for `tnt.datasyms.toml` + `--check` lint (the datasym-side gate; datasyms aren't in the link). |

### The recursive loop (functions ⇄ variables)
The batch loop below is now closed into a recursion by `dataxref.py`: after naming a
function, run `dataxref.py --func` to name the globals it touches (fn→var); then
`dataxref.py --addr <named-global>` lists every other function touching it, which
contextualizes nearby placeholders (var→fn). A cluster is "done for now" when a
batch yields < 3 confident names; deferred placeholders get **re-activated** in a
later sweep once a neighbor/global they touch has been named. Functions target
~100% *statically inferable* (honest — genuine evidence-less residue is parked in
`docs/naming-parking-list.md`, not force-named); variables target ≥50%
(`datacoverage.py`), reached largely as a byproduct of the `system` clusters.
**Variable-side gate:** `datacoverage.py --check` every batch + build a mod that
references a renamed sym (`data_reference_syms_files`) so a broken name fails
packaging — the datasym analogue of the link.

Prior struct-offset maps (reuse in agent prompts): Board/BoardP cell (`+0x1`
type, `7`=empty, `+0x2` group id, `+0x3` multisquare idx, `+0x4` ring next,
`+0x9/0xA` x/y, `+0xC` cube ptr), Minos instance, Garbage/Smoke, Multisquare
(44-entry mgr @0x8011FBA0), GhostPiece, SaveData (0x1900 record, 3 SRAM banks).

## The repeatable batch loop

1. **Pick** target subsystem(s) from the priority list below.
2. **Context** (hard functions): `callgraph.py <fn> --callers` and `--callees`
   to see named neighbors; pull the subsystem's rows from `FUNCTION_COMPLEXITY.md`
   (name low-complexity leaves first — they give context for the callers).
3. **Dispatch** agent(s): batch several files per agent (token-thrifty), give the
   subsystem gloss + known struct offsets + convention, demand terse output and
   **high/med only, skip the rest silently**.
4. **Guarded rename**: for each proposed name, assert the target is free and the
   source exists exactly once; `sed -e 's/\bOLD\b/NEW/g'` across
   `git ls-files RecompiledFuncs tnt.syms.toml`.
5. **`./tools/verify.sh`** → GREEN.
6. **Commit** (descriptive, list the renames).
7. **Track** coverage (Phase 0 tool).

Conventions: game code `Subsystem_PascalCaseVerb`; math `vecN_op` / `mtx4_op`
snake_case; keep the existing subsystem prefix unless the function truly belongs
elsewhere (then it re-buckets on the next reorganize).

## Phase 0 — prep (once)

- Add `tools/coverage.py`: prints per-subsystem `named/total` and overall %, so
  progress is measurable each session (the ad-hoc script already exists — promote it).
- Regenerate `FUNCTION_INDEX.md` + `FUNCTION_COMPLEXITY.md` so priorities reflect
  current names.

## Phases (priority order)

**Phase A — breadth over medium subsystems** (confident, batch 3–4 files/agent).
The bulk of remaining game-logic names. Targets (remaining placeholders):
gamefinish (19), Bag63 (18), Game (11), BoardP (16), MobilePiece (12), Minos
(12), Multisquare (9), Landfill (9), PieceHold (9), SaveData (11), NextPieces
(11), LineEffect (11), EndScroller (9), wonders1 (12), CubeTiles (21), Audio2
(22), Audio. Two passes each (leaves first, then callers).

**Phase B — depth on hard gameplay/graphics** (one agent per subsystem, deep read
+ callgraph context + struct offsets): CurrentPiece (21 — rotation/lock logic),
KeySpin (26 — input→move/rotate), PFGFX (40 — DL builders), displayText (33),
Color (13 — huge text-render functions).

**Phase C — AI cluster** (deepest; recursive, cross-referenced):
aisquarelist (45), aiplayer. Use callgraph heavily — these evaluate board/piece
state, so their callees (BoardP/CurrentPiece, now named) anchor them.

**Phase D — structural refinements**:
- Split `gameplay/Garbage.c` — it's really 3–4 subsystems (Garbage state, a
  blocks effect, a smoke/fire particle sim, image compositing). Introduce
  `Smoke_*`/`Particle_*`/`GarbageFx_*`/`ImageRect_*` prefixes (map them in
  `DOMAINS`), re-run reorganize.
- Materialize the math split (`vec4`/`mtx4`/`mtx3` already mapped) by re-running
  reorganize; verify domains + green.

**Phase E — library tier** (match against *references*, not blind RE):
`_libultra` (114 — N64 SDK: `os*`, `gu*` matrix, `al*` audio, string/mem — match
known libultra signatures), `lzo`/`lzo1x` (the public LZO source), `Dcm`/`h2o`
(audio codec), `n64Heap` (17 — allocator API). Different skill: pattern-match to
known open-source, not infer from scratch.

**Phase F — propagation second sweep**: after A–E, re-run agents on subsystems
where many neighbors are now named. Functions deferred as low-confidence become
nameable once their callers/callees have names. Iterate until dry.

**Phase G — `frametime` (222) & the adjacency residue**: this is the vram-catch-
all, not a real subsystem — unlabeled functions that merely trailed named ones.
For each, `callgraph.py --callers` to find its true owner, then either name it in
place or (better) let a future reorganize re-home it once a nearby anchor is
named. Lowest ROI; do last or leave address-named.

**Phase H — wrap**: full `verify.sh --boot` (runtime smoke), regenerate the
indexes, write the pinned README **"How to Improve the Game Source Code"** guide,
final push.

## Within a subsystem: leaves-first, two passes

Use `FUNCTION_COMPLEXITY.md` filtered to the subsystem. Pass 1 names the
low-complexity leaves (getters/setters/init/alloc — near-certain). Pass 2 re-reads
the higher-complexity orchestrators, now that their callees are named (via
callgraph), and names those. This two-pass rhythm is why the campaign converges.

## Guardrails & risks

- Green gate catches any dangling reference from a missed rename token; rollback
  is `git checkout -- RecompiledFuncs tnt.syms.toml`.
- Case-insensitive filename collisions and prefix churn are handled by the
  reorganizer (only relevant when re-running it, i.e. Phase D).
- Token discipline: batch files per agent, terse tables, high/med only. Declining
  agent yield (agents skipping ~most functions) is the signal a subsystem is
  "done for now" — move on rather than force low-confidence names.

## Success milestones

1. Game-logic domains (core/gameplay/graphics/audio/modes/ai) each **>80% named**.
2. Structural splits done (Garbage, math); `reorganize` clean, no `misc/`.
3. Library tier addressed or explicitly parked with a note.
4. README guide written, indexes regenerated, `verify.sh --boot` green, pushed.

Realistic outcome: most of the ~886 become confidently named over several
sessions; a residue (functions whose purpose needs *runtime* tracing) stays
address-named — acceptable, and the callgraph makes even those navigable.
