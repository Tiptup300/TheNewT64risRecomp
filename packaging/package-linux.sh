#!/usr/bin/env bash
# Package TntRecompiled into a self-contained, relocatable Linux tarball.
#
#   TheNewT64ris/
#     TheNewT64ris          (the binary, rpath $ORIGIN/lib)
#     assets/                (open-source UI fonts + rcss; NO game data)
#     lib/                   (bundled app-payload libs: SDL2, freetype, codecs)
#     TheNewT64ris.desktop
#     RUN.txt
#
# We DO NOT bundle the system / GPU / desktop stack (glibc, libGL/EGL/vulkan/drm,
# X11/Wayland, GTK/GLib/pango/cairo, dbus/systemd, pulse/alsa). Those must come
# from the host — every desktop distro (CachyOS, Fedora, …) provides them, and
# relocating GTK notoriously breaks its loaders and the file-open dialog. The
# Vulkan driver in particular MUST be the host's (it talks to the kernel GPU).
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BIN="${1:-$ROOT/build-cmake/TntRecompiled}"
ASSETS="${2:-$ROOT/assets}"
OUTDIR="${3:-$ROOT/dist}"
NAME="TheNewT64ris"
ARCH="$(uname -m)"

[ -f "$BIN" ] || { echo "error: binary not found: $BIN" >&2; exit 1; }
[ -d "$ASSETS" ] || { echo "error: assets not found: $ASSETS" >&2; exit 1; }

STAGE="$OUTDIR/$NAME"
rm -rf "$STAGE"
mkdir -p "$STAGE/lib"

cp "$BIN" "$STAGE/$NAME"
chmod +x "$STAGE/$NAME"
cp -r "$ASSETS" "$STAGE/assets"
cp "$ROOT/packaging/$NAME.desktop" "$STAGE/$NAME.desktop" 2>/dev/null || true
cp "$ROOT/packaging/RUN.txt"       "$STAGE/RUN.txt"       2>/dev/null || true

# Host-provided libs we must NOT bundle (basename regex, anchored per-token).
EXCLUDE='^(ld-linux.*|libc|libm|libmvec|libdl|libpthread|librt|libresolv|libgcc_s|libstdc\+\+|libatomic|linux-vdso'
EXCLUDE+='|libGL.*|libEGL.*|libGLX.*|libGLdispatch|libOpenGL|libvulkan.*|libdrm.*|libgbm.*'
EXCLUDE+='|libX11.*|libxcb.*|libXau|libXdmcp|libXext|libXrandr|libXrender|libXfixes|libXi|libXcursor|libXinerama|libXcomposite|libXdamage|libXss|libXRes|libXtst|libICE|libSM'
EXCLUDE+='|libwayland.*|libxkbcommon.*|libepoxy'
EXCLUDE+='|libgtk-3.*|libgdk-3.*|libgdk_pixbuf.*|libglib.*|libgobject.*|libgio.*|libgmodule.*|libgthread.*'
EXCLUDE+='|libpango.*|libcairo.*|libatk.*|libatspi|libharfbuzz.*|libfribidi|libthai|libdatrie|libgraphite2'
EXCLUDE+='|libfontconfig.*|libpixman.*|libglycin.*|libpng.*|liblcms2|libz|libbz2|libbrotli.*|libexpat|libffi|libpcre2.*'
EXCLUDE+='|libdbus.*|libsystemd.*|libudev.*|libselinux|libapparmor|libseccomp|libblkid|libmount|libuuid|libcap.*'
EXCLUDE+='|libasound.*|libpulse.*|libpulsecommon.*|libpipewire.*|libasyncns|libjack.*|libsndio.*'
# libdecor loads its own plugins from a system path; let the host provide it so
# those resolve (SDL falls back gracefully if it is absent). dbus is host-side.
EXCLUDE+='|libdecor.*|libdbus.*)'

echo "Bundling app-payload libs into $STAGE/lib ..."
ldd "$BIN" | awk '/=>/ {print $3} /ld-linux/ {print $1}' | grep -E '^/' | sort -u | while read -r so; do
    base="$(basename "$so")"
    stem="${base%%.so*}"
    if [[ "$stem" =~ $EXCLUDE ]]; then
        continue
    fi
    cp -Lv "$so" "$STAGE/lib/" || true
done

# rpath so the binary finds the bundled libs first, then falls back to the host.
if command -v patchelf >/dev/null 2>&1; then
    patchelf --set-rpath '$ORIGIN/lib' "$STAGE/$NAME"
    echo "set rpath \$ORIGIN/lib"
else
    echo "warning: patchelf not found; writing a run.sh wrapper instead"
    mv "$STAGE/$NAME" "$STAGE/$NAME.bin"
    cat > "$STAGE/$NAME" <<'EOF'
#!/usr/bin/env bash
here="$(cd "$(dirname "$0")" && pwd)"
export LD_LIBRARY_PATH="$here/lib:${LD_LIBRARY_PATH:-}"
exec "$here/TheNewT64ris.bin" "$@"
EOF
    chmod +x "$STAGE/$NAME"
fi

# Sanity-check the staged bundle before shipping it.
fail=0
[ -x "$STAGE/$NAME" ] || { echo "MISSING: executable $NAME" >&2; fail=1; }
[ -f "$STAGE/assets/fonts/primary.ttf" ] || { echo "MISSING: assets/fonts/primary.ttf" >&2; fail=1; }
[ -f "$STAGE/assets/recomp.rcss" ] || { echo "MISSING: assets/recomp.rcss" >&2; fail=1; }
ls "$STAGE"/lib/libSDL2-2.0.so* >/dev/null 2>&1 || { echo "MISSING: bundled libSDL2" >&2; fail=1; }
ls "$STAGE"/lib/libfreetype.so* >/dev/null 2>&1 || { echo "MISSING: bundled libfreetype" >&2; fail=1; }
[ "$fail" -eq 0 ] || { echo "package sanity check FAILED" >&2; exit 1; }

TARBALL="$OUTDIR/${NAME}-linux-${ARCH}.tar.gz"
( cd "$OUTDIR" && tar czf "$TARBALL" "$NAME" )
echo "packaged: $TARBALL"
ls -la "$TARBALL"
echo "bundled libs:"; ls "$STAGE/lib"
