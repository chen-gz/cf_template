{ pkgs, lib, config, inputs, ... }:

{
  # https://devenv.sh/packages/
  packages = [
    pkgs.clang-tools
    pkgs.zig
  ];

  # https://devenv.sh/scripts/
  scripts.run.exec = "zig build run";
  scripts.compdb.exec = "./gen_compdb.sh";

  # https://devenv.sh/basics/
  enterShell = ''
    export ZIG_GLOBAL_CACHE_DIR="$PWD/.zig-cache/global"
    echo 'Welcome to the devenv shell!'
  '';
}

