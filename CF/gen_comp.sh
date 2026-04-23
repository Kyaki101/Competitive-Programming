#!/usr/bin/env bash

set -e

GCC="/opt/homebrew/bin/g++-14"
STD="gnu++20"

INCLUDES=(
  "-stdlib=libstdc++"
  "-isystem /opt/homebrew/opt/gcc/include/c++/14"
  "-isystem /opt/homebrew/opt/gcc/include/c++/14/aarch64-apple-darwin23"
  "-isystem /opt/homebrew/opt/gcc/lib/gcc/14/include"
  "-isystem /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include"
)

DIR="$(pwd)"
OUT="compile_commands.json"

echo "[" > "$OUT"

FIRST=true
for file in *.cpp; do
  [[ -e "$file" ]] || continue

  if [ "$FIRST" = true ]; then
    FIRST=false
  else
    echo "," >> "$OUT"
  fi

  echo "  {" >> "$OUT"
  echo "    \"directory\": \"$DIR\"," >> "$OUT"
  echo "    \"command\": \"$GCC -std=$STD ${INCLUDES[*]} -c\"," >> "$OUT"
  echo "    \"file\": \"$file\"" >> "$OUT"
  echo "  }" >> "$OUT"
done

echo "]" >> "$OUT"

echo "✔ Generated $OUT"

