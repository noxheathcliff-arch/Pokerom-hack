# Instructions
Les instructions d'installation pour chaque système d'exploitation pris en charge peuvent être trouvées dans leurs répertoires respectifs sous `docs/install/`.
Les liens vers ceux-ci se trouvent sous chaque titre.
Ce fichier ne contient qu'une courte introduction à chaque système pris en charge.
Si vous rencontrez des problèmes, demandez de l'aide sur le Discord de RHH ou Pokémon Rom-Hacking FR (voir [README.md](README.md)).

Après avoir terminé les instructions d'installation pour votre système d'exploitation, passez à la [Compilation de pokeemeraude-expansion](#compilation-de-pokeemeraude-expansion).

## Windows
**Windows nécessite l'un des systèmes suivants pour compiler le projet**

**Une note d'avertissement**: Comme Windows 7 et Windows 8 ne sont officiellement pas pris en charge par Microsoft, certains mainteneurs ne sont pas disposés à maintenir les instructions pour Windows 7/8. Ainsi, ces instructions peuvent ne plus être valables à l'avenir avec des corrections prenant plus de temps que les corrections pour les instructions Windows 10/11.

Sur Windows, le projet peut être compilé en utilisant les systèmes suivants:
- WSL2, le plus rapide
- WSL1, 7 fois plus lent que WSL2
- Msys2, 20 fois plus lent que WSL2
- Cygwin, 30 fois plus lent que WSL2

**NOTE**: Seuls les systèmes WSL sont recommandés.

[Instructions d'installation WSL](docs/install/windows/WSL.md)

[Instructions d'installation Msys2](docs/install/windows/MSYS2.md)

[Instructions d'installation Cygwin](docs/install/windows/CYGWIN.md)

## Linux
Le projet peut être compilé sur n'importe quelle distribution Linux.
Les distributions avec instructions:
- [Ubuntu](docs/install/linux/UBUNTU.md)
- [Debian](docs/install/linux/DEBIAN.md)
- [Arch Linux](docs/install/linux/ARCH_LINUX.md)
- [NixOS](docs/install/linux/NIXOS.md)
- [Fedora](docs/install/linux/FEDORA.md)

Les autres distributions doivent déduire quoi faire à partir des [instructions générales](docs/install/linux/OTHERS.md).

## Mac
Il y a quelques instructions supplémentaires pour que le système de test fonctionne.

[Instructions d'installation sur Mac](docs/install/mac/MAC_OS.md)

## ChromeOS
Uniquement testé sur les systèmes basés sur x86_64.

[Instructions d'installation sur Chrome OS](docs/install/chromeos/CHROME_OS.md)

# Compilation de pokeemeraude-expansion
Suivez ces étapes pour compiler `pokeemeraude-expansion`.
1. Naviguez jusqu'au répertoire dans lequel vous souhaitez conserver le projet, en tenant compte des limitations spécifiques au système.
2. Téléchargez `pokeemeraude-expansion` avec `git`:

```bash
git clone https://github.com/pokehacking-fr/pokeemeraude-expansion
```
3. Naviguez dans le répertoire du projet:

```bash
cd pokeemeraude-expansion
```
4. Compilez le projet.

```bash
make
```
5. Si tout s'est bien passé, quelque chose de très similaire à ceci devrait être vu.

    ```bash
    arm-none-eabi-ld: warning: ../../pokeemeraude.elf has a LOAD segment with RWX permissions
    Memory region         Used Size  Region Size  %age Used
            EWRAM:      226588 B       256 KB     86.44%
            IWRAM:       28384 B        32 KB     86.62%
            ROM:    26546432 B        32 MB     79.11%
    cd build/emeraude && arm-none-eabi-ld -Map ../../pokeemeraude.map --print-memory-usage --gc-sections -T ../../ld_script_modern.ld -o ../../pokeemeraude.elf <objs> <libs> | cat
    tools/gbafix/gbafix pokeemeraude.elf -t"POKEMON EMER" -cBPEF -m01 -r0 --silent
    arm-none-eabi-objcopy -O binary pokeemeraude.elf pokeemeraude.gba
    tools/gbafix/gbafix pokeemeraude.gba -p --silent
    ```
    Et la ROM compilée sera dans le répertoire sous le nom `pokeemeraude.gba`.

# Guidance à la compilation

## Compilation parallèle
Voir [la documentation GNU](https://www.gnu.org/software/make/manual/html_node/Parallel.html) et [ce fil Stack Exchange](https://unix.stackexchange.com/questions/208568) pour plus d'informations.

Pour accélérer la compilation, obtenez d'abord la valeur de `nproc` en exécutant la commande suivante:
```bash
nproc
```

Les compilations peuvent ensuite être accélérées en exécutant la commande suivante:
```console
make -j<résultat de nproc>
```

Remplacez `<résultat de nproc>` par le nombre que la commande `nproc` a renvoyé.

`nproc` n'est pas disponible sur macOS. L'alternative est `sysctl -n hw.ncpu` ([fil Stack Overflow pertinent](https://stackoverflow.com/questions/1715580)).

### Autres outils

Pour compiler en utilisant un autre outil que devkitARM, remplacez la variable d'environnement `TOOLCHAIN` par le chemin vers votre outil, qui doit contenir le sous-répertoire `bin`.
```bash
make TOOLCHAIN="/path/to/toolchain/here
```

La commande suivante est un exemple:
```bash
make TOOLCHAIN="/usr/local/arm-none-eabi"
```

Pour compiler la version `moderne` avec cet outil, les sous-répertoires `lib`, `include` et `arm-none-eabi` doivent également être présents.

### Compiler avec des infos de débogage

Pour compiler **pokeemeraude.elf** avec des symboles de débogage et une optimisation compatible avec le débogage sous un outil moderne:
```bash
make debug
```

# Migrer depuis pokeemeraude

1. Définissez pokehacking-fr comme un dépôt distant git
```bash
git remote add pokehacking-fr https://github.com/pokehacking-fr/pokeemeraude-expansion
```

2. Tirez (`pull`) la branche souhaitée
```bash
git pull pokehacking-fr master
```

Si vous n'êtes pas sur la dernière version de pokeemeraude de Qigast, vous devriez vous attendre à certains conflits de fusion (merge conflicts) que vous devrez résoudre. Une fois terminé, vous utiliserez **pokeemeraude-expansion**.

# Mettre à jour votre copie de pokeemeraude-expansion

1. Définissez pokehacking-fr comme un dépôt distant git
```bash
git remote add pokehacking-fr https://github.com/pokehacking-fr/pokeemeraude-expansion
```

2. Vérifiez votre version actuelle
Votre copie locale du [changelog](docs/CHANGELOG.md) sera mise à jour avec la version sur laquelle votre dépôt se trouve.

3. Sélectionnez la version cible
Nous recommandons de mettre à jour progressivement vers la version suivante en utilisant l'ordre ci-dessous.
Si vous êtes sur une version antérieure à 1.6.2, vous devriez cibler 1.6.2.
    * 1.6.2
    * 1.7.4
    * 1.8.3
    * 1.9.4
    * 1.10.3

Par exemple, si votre version est 1.7.0, vous devriez mettre à jour vers 1.7.4.

4. Tirez (`pull`) la version cible
```bash
git pull pokehacking-fr expansion/X.Y.Z # Remplacez X, Y et Z avec la version cible, comme `1.9.3` 
```

Vous pourriez avoir des conflits de fusion (merge conflicts) que vous devrez résoudre.

Si vous avez ciblé une version spécifique qui n'est pas la dernière version répertoriée sur la page [tags](https://github.com/rh-hideout/pokeemerald-expansion/tags), vous devriez répéter les étapes 3 et 4 jusqu'à ce que vous le soyez.

# Outils additionnels utiles

* [porymap](https://github.com/huderlem/porymap) pour visualiser et modifier les maps.
* [porytiles](https://github.com/grunt-lucas/porytiles) pour ajouter de nouvelles metatiles pour les maps.
* [poryscript](https://github.com/huderlem/poryscript) pour le scripting. ([Extension VS Code](https://marketplace.visualstudio.com/items?itemName=karathan.poryscript))
* [Tilemap Studio](https://github.com/Rangi42/tilemap-studio) pour visualiser et modifier les tilemaps.
