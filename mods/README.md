# Mods

TntRecomp uses the standard N64Recomp mod system (the same one Zelda64Recomp and
other Recomp ports use). Mods are `.nrm` packages dropped into the game's mods
folder; the runtime loads them, applies their hooks/patches, and exposes them in
the in-game **Mods** menu (enable/disable, per-mod config, install).

A mod is a little C code that hooks or replaces game functions. It's compiled to
**MIPS** (the CPU the recompiled game runs as), then packaged with a manifest.
**Building a mod needs no ROM** — only `tnt.syms.toml` (the game's function
symbols, in the repo root). The ROM is only needed to *run* the game and test a
mod live.

## Layout

```
mods/
  common/
    include/            vendored mod SDK headers (CC0) + minimal PR/ultratypes.h
      modding.h           RECOMP_HOOK / RECOMP_PATCH / RECOMP_EXPORT / ...
      recomputils.h       recomp_printf, recomp_alloc, return-value helpers
      recompconfig.h      recomp_get_config_* (read a mod's config options)
      PR/ultratypes.h     s8/u8/.../f32 aliases (self-contained; we have no decomp)
    mod.ld              linker script (sections pass through; discards junk)
    LICENSE-CC0         license for the vendored headers/mod.ld
  build_mod.sh          build one mod: C -> MIPS ELF -> .nrm
  hello/                pipeline-validation mod (hooks Game_Init, prints a line)
    mod.toml            manifest + build inputs
    src/hello.c
```

## Toolchain

- **clang** (already required to build the project) — emits MIPS via `-target mips`.
- **`mips-linux-gnu-ld`** (from `binutils-mips-linux-gnu`, already in the setup).
- **`RecompModTool`** — packages the ELF into a `.nrm`. Not built by the main
  CMake; build it once:
  ```bash
  cmake -S lib/N64ModernRuntime/N64Recomp -B build-modtool \
      -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -G Ninja -DCMAKE_BUILD_TYPE=Release
  cmake --build build-modtool --target RecompModTool -j
  ```
- **`zip`** — RecompModTool uses it to package the `.nrm` on Linux
  (`sudo apt-get install -y zip`). If it's missing, `build_mod.sh` falls back to
  zipping with Python, so it's optional.

## Build a mod

```bash
./mods/build_mod.sh hello        # -> mods/hello/build/tnt_hello_world.nrm
```

Then copy the `.nrm` into the game's mods folder (`<config dir>/mods/`, e.g.
`~/.config/<app>/mods/`) or install it from the in-game Mods menu, and enable it.

## Writing a mod

Include `modding.h` and tag a function with a section macro:

```c
#include "modding.h"

// Runs just before the game's Game_Init.
RECOMP_HOOK("Game_Init") void my_hook(void) {
    // Reach game memory with raw KSEG0 pointers; the recompiler translates
    // these to game-RAM accesses.
    *(volatile unsigned int*)0x800CF928 = 9300;
}
```

> **Runtime import limitation.** This build's pinned `librecomp` exports only a
> small set of mod-callable functions: `recomp_alloc`, `recomp_free`, the
> `recomp_get_config_*` / config + save-path helpers, and `recomphook_get_return_*`.
> It does **not** export `recomp_printf` (no mod-side logging) or
> `recomp_is_dependency_met`. Because `recomputils.h` declares `recomp_printf`
> (and the others) as *used* imports, including `recomputils.h` makes a mod
> **fail to load** with `Imported function not found`. So mods here include only
> `modding.h` and access game state via raw pointers. Provide your own small
> typedefs instead of pulling in `PR/ultratypes.h` through `recomputils.h`.

Key macros (`modding.h`):
- `RECOMP_HOOK("Fn")` / `RECOMP_HOOK_RETURN("Fn")` — run before / at the return of
  game function `Fn` (read its args by matching its signature; don't change control flow).
- `RECOMP_PATCH` / `RECOMP_FORCE_PATCH` — replace a game function entirely (the mod
  function must be named the same as the game function it replaces).
- `RECOMP_EXPORT`, `RECOMP_IMPORT`, `RECOMP_CALLBACK`, `RECOMP_DECLARE_EVENT` — for
  inter-mod APIs and events.

Any function name you hook or patch **must exist in `tnt.syms.toml`** or the build
fails. Use `tools/callgraph.py` to find the right function to target.

### Manifest (`mod.toml`)

`[manifest]` needs `id`, `version`, `display_name`, `authors`, `minimum_recomp_version`,
and `game_id = "tnt"` (this game's `mod_game_id`). Add `enabled_by_default = true`
to auto-enable a bundled mod. `[[manifest.config_options]]` entries become the
per-mod settings shown in the Mods menu (readable at runtime via `recompconfig.h`).

`[inputs]` needs `elf_path`, `mod_filename`, `func_reference_syms_file`
(= `../../tnt.syms.toml`), and `data_reference_syms_files` (may be `[]`).

## Provenance / licensing

`common/include/{modding,recomputils,recompconfig}.h` and `common/mod.ld` are
vendored verbatim from the CC0-licensed
[MMRecompModTemplate](https://github.com/Zelda64Recomp/MMRecompModTemplate)
(see `common/LICENSE-CC0`). `PR/ultratypes.h` is a minimal self-contained subset
written for this repo (we have no decomp to pull the SDK header from).
