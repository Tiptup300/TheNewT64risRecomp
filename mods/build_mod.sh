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
# the mod dir. It emits mod.json + mod_syms.bin + mod_binary.bin into build/ and
# then zips them into <mod_filename>.nrm (via the system `zip` on Linux).
echo "  NRM  $MOD"
( cd "$MOD_DIR" && "$MODTOOL" mod.toml build ) || true

# Determine the expected output name from the toml.
mod_filename="$(sed -n 's/^[[:space:]]*mod_filename[[:space:]]*=[[:space:]]*"\(.*\)".*/\1/p' "$MOD_DIR/mod.toml" | head -1)"
nrm="$BUILD/${mod_filename}.nrm"

# Fallback: if system `zip` is missing, RecompModTool leaves the three files but
# can't package them. Zip them ourselves so the pipeline works without `zip`.
if [ ! -f "$nrm" ]; then
    if [ -f "$BUILD/mod.json" ] && [ -f "$BUILD/mod_syms.bin" ] && [ -f "$BUILD/mod_binary.bin" ]; then
        echo "  ZIP  (python fallback — system 'zip' not found)"
        ( cd "$BUILD" && python3 -c "import zipfile,sys; z=zipfile.ZipFile(sys.argv[1],'w',zipfile.ZIP_DEFLATED); [z.write(f) for f in ('mod.json','mod_syms.bin','mod_binary.bin')]; z.close()" "${mod_filename}.nrm" )
    else
        echo "error: RecompModTool did not emit mod artifacts; see output above" >&2
        exit 1
    fi
fi

echo "built: $nrm"
