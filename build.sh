#!/usr/bin/env bash
set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$SCRIPT_DIR/build"
OXT="$SCRIPT_DIR/libreai.oxt"

echo "==> Configuring…"
cmake -S "$SCRIPT_DIR" -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS="-fvisibility=hidden" -Wno-dev 2>&1 | tail -3

echo "==> Compiling…"
cmake --build "$BUILD_DIR" --parallel "$(nproc)"

echo "==> Packaging libreai.oxt…"
cp "$BUILD_DIR/libreai.so" "$SCRIPT_DIR/libreai.so"
rm -f "$OXT"
cd "$SCRIPT_DIR"
zip -r "$OXT" \
    META-INF/       \
    description.xml \
    description-en.txt \
    Addons.xcu      \
    Jobs.xcu        \
    libreai.so      \
    icons/
echo "==> Built: $OXT"

if [[ "${1:-}" == "--install" ]]; then
    echo "==> Installing…"
    unopkg remove org.libreai 2>/dev/null || true
    unopkg add -f "$OXT"
    echo "==> Done. Restart LibreOffice to activate."
fi
