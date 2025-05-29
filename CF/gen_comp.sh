#!/bin/bash
# generate_compile_commands.sh
# Usage: ./generate_compile_commands.sh > compile_commands.json

echo "["

first=1
for file in *.cpp; do
    [ "$first" -eq 0 ] && echo ","
    first=0
    echo "  {"
    echo "    \"directory\": \"$(pwd)\","
    echo "    \"command\": \"/opt/homebrew/bin/g++-14 -std=gnu++20 -I/opt/homebrew/opt/gcc/include/c++/14 -I/opt/homebrew/opt/gcc/include/c++/14/aarch64-apple-darwin23 -I/opt/homebrew/opt/gcc/lib/gcc/14/include -c $file\","
    echo "    \"file\": \"$file\""
    echo "  }"
done

echo "]"

