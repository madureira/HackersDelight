#!/usr/bin/env sh
set -eu

TARGET_DIR="${1:-.}"

echo "These files will be removed:"

# Preview first:
find "$TARGET_DIR" \
  -path "$TARGET_DIR/.git" -prune -o \
  -type f ! -name "*.*" -print

echo "Removing compiled binaries..."

find "$TARGET_DIR" \
  -path "$TARGET_DIR/.git" -prune -o \
  -type f ! -name "*.*" -print0 | xargs -0 rm -f

echo "Done."
