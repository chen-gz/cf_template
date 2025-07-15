{
  description = "A C++ development environment";

  inputs = {
    # Changed from 'nixos-unstable' to the latest stable release
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-25.05";
  };

  outputs = { self, nixpkgs, ... }@inputs:
    let
      supportedSystems = [ "x86_64-linux" "aarch64-linux" "x86_64-darwin" "aarch64-darwin" ];
      forAllSystems = nixpkgs.lib.genAttrs supportedSystems;
      pkgsFor = forAllSystems (system: import nixpkgs { inherit system; });
    in
    {
      devShells = forAllSystems (system:
        let
          pkgs = pkgsFor.${system};
        in
        {
          default = pkgs.mkShell {
            buildInputs = with pkgs; [
              cmake
              gcc
              fish
            ];
            shellHook = ''
              # If the current shell is not fish, switch to it.
              if [ "$(basename $(ps -o comm= -p $$))" != "fish" ]; then
                exec fish
              fi
            '';
          };
        });
    };
}