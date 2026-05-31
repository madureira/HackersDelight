#!/usr/bin/env bash
set -euo pipefail

if [ $# -ne 1 ]; then
    echo "Usage: $0 <folder/file.c> (e.g. $0 Ch01/exe_2.c)"
    exit 1
fi

SRC="${1}"
BIN="${1%.c}"

if [ ! -f "$SRC" ]; then
    echo "Error: $SRC not found"
    exit 1
fi

clang -std=c11 -Wall -Wextra -o "$BIN" "$SRC"
"$BIN"
