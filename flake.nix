{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs?rev=36864ed72f234b9540da4cf7a0c49e351d30d3f1";
  };
  outputs =
    { nixpkgs, ... }:
    let
      systems = [
        "aarch64-darwin"
        "x86_64-linux"
      ];
      forAllSystems = nixpkgs.lib.genAttrs systems;
    in
    {
      devShells = forAllSystems (
        system:
        let
          pkgs = import nixpkgs {
            inherit system;
          };
        in
        {
          default = pkgs.mkShell {
            buildInputs = with pkgs; [
              qmk
            ];
          };
        }
      );
    };
}
