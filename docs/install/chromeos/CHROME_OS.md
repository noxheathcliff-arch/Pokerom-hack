# Instructions d'installation pour Chrome OS

1. Activez le terminal Linux en suivant les instructions sur [cette page](https://chromeos.dev/en/productivity/terminal). Assurez-vous d'allouer suffisamment d'espace pour l'installation de Linux.
2. Après l'installation du terminal Linux, exécutez la commande suivante dans le terminal pour mettre à jour et mettre à niveau le terminal Linux:

```bash
sudo apt update && apt upgrade
```
3. Ensuite, installez toutes les dépendances en exécutant la commande suivante:

```bash
sudo apt install build-essential binutils-arm-none-eabi gcc-arm-none-eabi libnewlib-arm-none-eabi git libpng-dev python3
```
**NOTE**: Le projet doit être conservé dans un répertoire à l'intérieur du système de fichiers Linux, par exemple sous `~/Decomps/pokeemeraude-expansion`
