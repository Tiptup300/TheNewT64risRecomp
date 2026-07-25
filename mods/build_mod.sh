#!/usr/bin/env bash
#
# Build one TntRecomp mod:  mod C  ->  MIPS ELF  ->  .nrm
#
#   ./mods/build_mod.sh <mod-dir>        # e.g. ./mods/build_mod.sh hello
#
# Toolchain (override via env): CC=clang  LD=mips-linux-gnu-ld
#   MODTOOL=<path to RecompModTool>   (default: build-modtool/RecompModTool)
#
# Building a .nrm needs NO ROM — only tnt.syms.toml (the function reference
# symbols). The ROM is only needed to run the game and test the mod.
#
set -euo pipefail

MODS_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$MODS_DIR/.." && pwd)"
COMMON="$MODS_DIR/common"

MOD="${1:?usage: build_mod.sh <mod-dir>}"
MOD_DIR="$MODS_DIR/$MOD"
[ -f "$MOD_DIR/mod.toml" ] || { echo "error: no mod.toml in $MOD_DIR" >&2; exit 1; }

CC="${CC:-clang}"
LD="${LD:-mips-linux-gnu-ld}"
MODTOOL="${MODTOOL:-$REPO_ROOT/build-modtool/RecompModTool}"
[ -x "$MODTOOL" ] || { echo "error: RecompModTool not found at $MODTOOL (build it first)" >&2; exit 1; }

# clang MIPS recipe (from the upstream recomp mod template). -nostdinc: mods link
# against the recompiler runtime, not a libc; our headers live under common/include.
CFLAGS=(
    -target mips -mips2 -mabi=32 -O2 -G0
    -mno-abicalls -mno-odd-spreg -mno-check-zero-division
    -fomit-frame-pointer -ffast-math -fno-unsafe-math-optimizations
    -fno-builtin-memset -ffunction-sections
    -Wall -Wextra -Wno-unused-parameter
    -nostdinc -I "$COMMON/include" -I "$MOD_DIR/include"
)

# The .recomp_* sections pass through untouched; mod.ld only discards junk.
LDFLAGS=(
    -nostdlib -T "$COMMON/mod.ld"
    --unresolved-symbols=ignore-all --emit-relocs -e 0
    --gc-sections
)

BUILD="$MOD_DIR/build"
rm -rf "$BUILD"; mkdir -p "$BUILD"

shopt -s nullglob
srcs=( "$MOD_DIR"/src/*.c )
[ ${#srcs[@]} -gt 0 ] || { echo "error: no .c sources in $MOD_DIR/src" >&2; exit 1; }

objs=()
for src in "${srcs[@]}"; do
    obj="$BUILD/$(basename "${src%.c}").o"
    echo "  CC   $(basename "$src")"
    "$CC" "${CFLAGS[@]}" -c "$src" -o "$obj"
    objs+=( "$obj" )
done

echo "  LD   mod.elf"
"$LD" "${objs[@]}" "${LDFLAGS[@]}" -Map "$BUILD/mod.map" -o "$BUILD/mod.elf"

# RecompModTool resolves the toml's relative paths from its CWD, so run it from
# the mod dir. It emits mod.json + mod_syms.bin + mod_binary.bin into build/.
echo "  NRM  $MOD"
( cd "$MOD_DIR" && "$MODTOOL" mod.toml build ) || true

mod_filename="$(sed -n 's/^[[:space:]]*mod_filename[[:space:]]*=[[:space:]]*"\(.*\)".*/\1/p' "$MOD_DIR/mod.toml" | head -1)"
nrm="$BUILD/${mod_filename}.nrm"

if [ ! -f "$BUILD/mod.json" ] || [ ! -f "$BUILD/mod_syms.bin" ] || [ ! -f "$BUILD/mod_binary.bin" ]; then
    echo "error: RecompModTool did not emit mod artifacts; see output above" >&2
    exit 1
fi

# RecompModTool DROPS enabled_by_default from the output manifest, and the runtime
# defaults a field-less manifest to ENABLED (mod_manifest.cpp) — so a bundled
# "off by default" mod would wrongly start on. Re-inject it from the mod.toml.
ebd="$(sed -n 's/^[[:space:]]*enabled_by_default[[:space:]]*=[[:space:]]*\(true\|false\).*/\1/p' "$MOD_DIR/mod.toml" | head -1)"
if [ -n "$ebd" ]; then
    echo "  FIX  enabled_by_default=$ebd (RecompModTool omits it)"
    python3 -c "import json,sys; p=sys.argv[1]; d=json.load(open(p)); d['enabled_by_default']=(sys.argv[2]=='true'); json.dump(d,open(p,'w'),indent=4)" "$BUILD/mod.json" "$ebd"
fi

# Always (re)package with Python so the injected mod.json is authoritative,
# whether or not the system `zip` already produced an .nrm.
echo "  ZIP  $mod_filename.nrm"
rm -f "$nrm"
( cd "$BUILD" && python3 -c "import zipfile,sys; z=zipfile.ZipFile(sys.argv[1],'w',zipfile.ZIP_DEFLATED); [z.write(f) for f in ('mod.json','mod_syms.bin','mod_binary.bin')]; z.close()" "${mod_filename}.nrm" )

echo "built: $nrm"
