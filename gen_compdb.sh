#!/bin/sh
echo "[
  {
    \"directory\": \"$PWD\",
    \"command\": \"zig c++ -std=c++23 -DDEBUG -c main.cpp\",
    \"file\": \"main.cpp\"
  }
]" > compile_commands.json
