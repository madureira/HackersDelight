#!/usr/bin/env sh
set -eu

TARGET_DIR="${1:-.}"

# Absolute path to THIS script
SCRIPT_PATH="$(cd -P -- "$(dirname -- "$0")" && pwd -P)/$(basename -- "$0")"

echo "These files will be removed:"

# Preview first:
find "$TARGET_DIR" \
  -path "$TARGET_DIR/.git" -prune -o \
  -type f -perm -111 ! -samefile "$SCRIPT_PATH" -print

echo "Removing executable files..."

# Uncomment to delete:
find "$TARGET_DIR" \
  -path "$TARGET_DIR/.git" -prune -o \
  -type f -perm -111 ! -samefile "$SCRIPT_PATH" -delete

echo "Done."
