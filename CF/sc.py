#!/usr/bin/env python3
import os
import json
import sys

def generate_compile_commands(root_dir):
    commands = []
    root_dir = os.path.abspath(root_dir)
    
    for dirpath, dirnames, filenames in os.walk(root_dir):
        for filename in filenames:
            if filename.endswith('.cpp'):
                full_path = os.path.join(dirpath, filename)
                commands.append({
                    "directory": dirpath,
                    "command": f"/opt/homebrew/bin/g++-14 -std=gnu++20 -I/opt/homebrew/opt/gcc/include/c++/14 -I/opt/homebrew/opt/gcc/include/c++/14/aarch64-apple-darwin23 -I/opt/homebrew/opt/gcc/lib/gcc/14/include -c {filename}",
                    "file": full_path
                })
    
    return commands

if __name__ == "__main__":
    root = sys.argv[1] if len(sys.argv) > 1 else "."
    commands = generate_compile_commands(root)
    
    with open("compile_commands.json", "w") as f:
        json.dump(commands, f, indent=2)
    
    print(f"Generated compile_commands.json with {len(commands)} entries")
