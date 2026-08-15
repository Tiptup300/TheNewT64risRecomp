# MODDING.md — how to mod The New T64ris (Recompiled)

The authoritative guide to writing mods for this port. It builds on `mods/README.md`
(build/install mechanics) and `docs/GAME_STATE_MAP.md` (what to read/write). Read this
once; then the five example mods under `mods/` are copy-paste starting points.

> **Legal/naming:** this is **The New T64ris** by **H2O**. Never ship game data.

---

## 1. The two ways a mod changes the game

Everything a mod does comes down to one of two macros from `modding.h`.

### `RECOMP_HOOK("GameFn")` — run code *around* a game function, **RAM writes only**

```c
RECOMP_HOOK("Scene_Update") void my_hook(void) { /* ... */ }
```

The hook runs **just before** the game function body. You may **read any game RAM and
write any game RAM**, but you **cannot change what the game function computes** by
writing to registers/args — the runtime **saves the guest CPU context before the hook
and restores it after** (`lib/N64ModernRuntime/librecomp/src/mod_hooks.cpp`: the hook
context is pushed on entry and copied back on exit). So a hook that sets `ctx->rN` has
no lasting effect; only its writes to game memory survive.

- **`RECOMP_HOOK("Fn")`** — fires at entry. Read the args by matching `Fn`'s signature.
- **`RECOMP_HOOK_RETURN("Fn")`** — fires at the return. Read the return value with the
  `recomphook_get_return_*` helpers (these *are* exported; see §5).

Use a hook when the change is expressible as "before/after this runs, force some RAM to
a value" — e.g. rewrite a data table (`wonders-rebalance`), force a state byte every
frame (`intro-skip`, `map-select`), or repoint a null buffer (`scene-crash-guard`).

### `RECOMP_PATCH` — **replace** a game function entirely

```c
RECOMP_PATCH void Scene_Update(void) { /* your full reimplementation */ }
```

The mod function **must be named exactly like the game function it replaces** and match
its signature. It runs *instead of* the original — you own control flow and registers,
so this is the only way to change what a function returns or skip its work. It is also
the sharp tool: you are now responsible for everything the original did. Call the
original's collaborators yourself if you still need them. Use `RECOMP_FORCE_PATCH` to
override even when another mod also patches the same function.

**Rule of thumb:** reach for `RECOMP_HOOK` first (safe, composable, RAM-only). Escalate
to `RECOMP_PATCH` only when you must change the function's *result* or *control flow*.

---

## 2. Reaching game memory

The recompiled game is 8 MB of N64 RDRAM living inside the runtime's address space.
KSEG0 addresses (`0x8xxxxxxx`) are valid pointers *inside a hook/patch* — the
recompiler maps them to the game's RAM. Two ways to name a location:

**Raw pointer** (fastest to write, no symbol needed):
```c
#define SCENE (*(volatile unsigned char*)0x800CFEE8)   // g_currentScene
SCENE = 3;
```
Always mark game-RAM pointers `volatile` — the value changes underneath you (the game
writes it too), and you don't want the compiler caching or reordering the access.

**By symbol name** (safer — a typo is a *build* error, and it documents intent):
```c
extern volatile unsigned int g_wonderLineThresholds[7];   // from tnt.datasyms.toml
g_wonderLineThresholds[i] = ...;
```
This requires `data_reference_syms_files = ["../../tnt.datasyms.toml"]` in `mod.toml`.
RecompModTool resolves the name to the address at build time. Prefer this for any
address that has a name in `tnt.datasyms.toml` (699 named globals).

**Scratch RAM.** Need a few bytes of your own? RDRAM above the game's used region is
free: `0x807FFF00` (just under 8 MB, used by `hello` as a sentinel) or `0x80900000`
(past 8 MB but inside the runtime's 512 MB map, used by `scene-crash-guard` as a
crash-absorbing scratch buffer). The game never touches either.

---

## 3. Config options (per-mod settings in the Mods menu)

Declare options in `mod.toml`; read them at runtime with `recompconfig.h`. This is how
a mod becomes user-tunable without a rebuild.

```toml
[[manifest.config_options]]
id = "skip_to"
name = "Skip intro to"
type = "Enum"
options = [ "Off", "Attract" ]
default = "Off"
```
```c
#include "recompconfig.h"
unsigned long mode = recomp_get_config_u32("skip_to");   // enum -> index
```
`recomp_get_config_u32` / `_double` / `_string` are exported (unlike most of
`recomputils.h` — see §5). See `intro-skip` (enum) and `map-select` (enum→song index).

---

## 4. Build & install (recap — full detail in `mods/README.md`)

```bash
./mods/build_mod.sh <dir>      # clang -target mips -> mips-linux-gnu-ld -> RecompModTool
                               # -> mods/<dir>/build/<mod_filename>.nrm    (NO ROM needed)
```
Install: drop the `.nrm` in `~/.local/share/N64Recomp/TheNewTiptris/mods/`, or use the
in-game **Mods** menu. `enabled_by_default = true` auto-enables a bundled mod. Any name
you hook/patch **must exist in `tnt.syms.toml`** or the build fails — find the right
target with `tools/callgraph.py <fn>`.

---

## 5. Pitfalls (read before you debug for an hour)

- **Do NOT include `recomputils.h`.** This runtime's pinned `librecomp` exports only a
  small import set. `recomputils.h` declares `recomp_printf` and friends as *used*
  imports, so including it makes the mod **fail to load** with `Imported function not
  found`. Include **only** `modding.h` (+ `recompconfig.h` if you read config). Write
  your own small typedefs instead of pulling `PR/ultratypes.h` through `recomputils.h`.
- **No mod-side logging.** `recomp_printf` is not exported. To observe a hook firing,
  **write a sentinel to scratch RAM** and watch it (the `hello` pattern) — the E2E
  harness (`tools/e2e/harness.py`) can watch/read any address.
- **Hooks can't change the game's computation.** Registers are restored after the hook
  (§1). If you need to change a return value or skip work, use `RECOMP_PATCH`.
- **Never blindly write `g_currentScene = 4`.** Jumping straight to the menu-hub/play
  scene bypasses its resource-load step, leaving object buffers null →
  `Scene_SetupObjectMatrices` SIGSEGVs. Only advance to *self-contained* scenes (e.g.
  attract = 3), or go through the game's own transition. See `scene-crash-guard` and
  `docs/GAME_STATE_MAP.md` for the full crash chain.
- **Exported functions you *can* call:** `recomp_alloc`, `recomp_free`, the
  `recomp_get_config_*` + save-path helpers, and `recomphook_get_return_*`. That's it.

---

## 6. Hook-point catalog — where to attach, and what each is good for

The best target depends on *when* you want to act. Confirm any signature with
`tools/callgraph.py <fn>` before matching args. (Addresses/roles: `tnt.syms.toml`.)

| Hook point | Fires | Good for |
|---|---|---|
| `Game_Init` | once, at session start | one-shot setup: rewrite static data tables, drop a sentinel. Static game data is resident by now. (`wonders-rebalance`, `hello`.) |
| `Scene_Update` | every frame, top-level scene dispatch | per-frame policy: force a state byte, gate on the current scene, skip branding. The workhorse hook. (`intro-skip`, `map-select`.) |
| `Scene_Init` | on each scene load/teardown | react to scene *transitions*: allocate/validate per-scene buffers (the Phase-5 crash-guard idea targets here). |
| `Scene_Main` (`0x80099674`) | scene-4 menu widget engine | menu logic: read the item table / cursor, react to a selection. Basis for a custom menu screen. |
| `Scene_SetupObjectMatrices` (`0x8009EED4`) | per scene setup, 16× | low-level scene object setup; used by `scene-crash-guard` to repoint a null buffer. |
| gameplay tick / input poll | per frame during play | read the active piece / board, react to input edges (`g_buttonsPressed`). See `docs/GAME_STATE_MAP.md` for the pointers. |

To discover more targets: `tools/callgraph.py <fn> --callers` (who calls it) / `--callees`
(what it calls), and `tools/complexity.py` to find the meaty functions worth hooking.

---

## 7. The example mods, as a cookbook

Each is tiny, builds with `build_mod.sh`, and demonstrates exactly one technique:

| Mod | Technique | One-liner |
|---|---|---|
| `mods/hello` | minimal hook, no imports | write a sentinel on `Game_Init` — proves the toolchain + a hook firing without logging. |
| `mods/wonders-rebalance` | RAM-write hook + named datasym + safety guard | rewrite a 7-entry data table once, only if it matches known stock values first. |
| `mods/intro-skip` | hook + config enum + scene gating | force the scene byte forward each frame, per a config option. |
| `mods/map-select` | hook + config + named datasym | force `g_currentSong` from a config selection; documents the per-frame-forcing caveat. |
| `mods/scene-crash-guard` | hook as a null-pointer guard | repoint a null buffer to scratch RAM; documents a real crash chain (and why it's only a partial fix). |

**Start a new mod** by copying the closest one, then: rename in `mod.toml` (`id`,
`mod_filename`, `display_name`), rename the `src/*.c`, change the hook target + body,
and `./mods/build_mod.sh <yourdir>`. A one-line pytest under `tools/e2e/` that the mod
loads (see `test_crash_guard.py` for the A/B pattern) keeps it honest.

---

## 8. See also

- `mods/README.md` — build toolchain, manifest fields, provenance/licensing.
- `docs/GAME_STATE_MAP.md` — the state reference: scenes, input mask, gameplay structs,
  every address confirmed by driving input and watching RAM.
- `docs/MENU_TREE.md` / `docs/MENU_OBSERVED.md` / `docs/MENU_MAP.md` — the front-end map.
- `docs/ADDING-A-MENU-SCREEN.md` — (if present) how a new scene-4 screen is built.
- `tools/e2e/README.md` — driving the game headless to test a mod.
