# Instructions d'installation pour NixOS
## Installer les dépendances
Executez la commande suivante pour démarrer un shell interactif avec les paquets nécessaires:
```bash
nix-shell -p pkgsCross.arm-embedded.stdenv.cc git pkg-config libpng
```
