#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
OXT="$SCRIPT_DIR/libreai.oxt"
VERSION="1.0.0"
PKG="libreai_${VERSION}_amd64"
STAGING="$SCRIPT_DIR/$PKG"

# Require the .oxt to exist
if [[ ! -f "$OXT" ]]; then
    echo "ERROR: libreai.oxt not found — run build.sh first"
    exit 1
fi

rm -rf "$STAGING"

# ── Directory tree ────────────────────────────────────────────────────────────
install -d "$STAGING/DEBIAN"
install -d "$STAGING/usr/share/libreai"
install -d "$STAGING/usr/share/doc/libreai"

# Extension bundle
install -m 644 "$OXT" "$STAGING/usr/share/libreai/libreai.oxt"

# ── DEBIAN/control ────────────────────────────────────────────────────────────
cat > "$STAGING/DEBIAN/control" <<EOF
Package: libreai
Version: $VERSION
Architecture: amd64
Maintainer: LibreAI <devilish84@gmail.com>
Depends: libreoffice-writer, libqt6widgets6, libqt6network6, libqt6gui6, libqt6core6, libqt6dbus6
Recommends: ollama
Description: LibreAI — AI writing assistant for LibreOffice Writer
 Adds an AI chat window to LibreOffice Writer with support for
 Ollama (local), OpenAI, and Anthropic Claude. Lets you grab
 selected text, send it to an AI model, and apply the response
 back to your document.
EOF

# ── DEBIAN/postinst ───────────────────────────────────────────────────────────
cat > "$STAGING/DEBIAN/postinst" <<'EOF'
#!/bin/bash
set -e
OXT=/usr/share/libreai/libreai.oxt

# Install for the invoking user if run via sudo, otherwise system-wide
if [[ -n "${SUDO_USER:-}" ]]; then
    sudo -u "$SUDO_USER" unopkg remove org.libreai 2>/dev/null || true
    sudo -u "$SUDO_USER" unopkg add -f "$OXT"
else
    unopkg remove --shared org.libreai 2>/dev/null || true
    unopkg add --shared -f "$OXT"
fi

echo "LibreAI installed. Restart LibreOffice to activate."
exit 0
EOF
chmod 755 "$STAGING/DEBIAN/postinst"

# ── DEBIAN/prerm ──────────────────────────────────────────────────────────────
cat > "$STAGING/DEBIAN/prerm" <<'EOF'
#!/bin/bash
set -e

if [[ -n "${SUDO_USER:-}" ]]; then
    sudo -u "$SUDO_USER" unopkg remove org.libreai 2>/dev/null || true
else
    unopkg remove --shared org.libreai 2>/dev/null || true
fi

exit 0
EOF
chmod 755 "$STAGING/DEBIAN/prerm"

# ── Copyright ─────────────────────────────────────────────────────────────────
cat > "$STAGING/usr/share/doc/libreai/copyright" <<EOF
LibreAI $VERSION
Copyright $(date +%Y) LibreAI contributors
License: MIT
EOF

# ── Build the .deb ────────────────────────────────────────────────────────────
echo "==> Building .deb…"
dpkg-deb --build --root-owner-group "$STAGING"
echo "==> Done: $SCRIPT_DIR/${PKG}.deb"
echo ""
echo "Install with:"
echo "  sudo dpkg -i ${PKG}.deb"
