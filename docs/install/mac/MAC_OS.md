# Instructions d'installation pour MacOS
1. Si l'outil de ligne de commande Xcode n'est pas installé, téléchargez l'outil [ici](https://developer.apple.com/xcode/resources/), ouvrez votre terminal et exécutez la commande suivante:

```bash
xcode-select --install
```

2.  - Si libpng **n'est pas installé**, alors allez à l'[Installation de libpng (macOS)](#installation-de-libpng-macos).
    - Si pkg-config **n'est pas installé**, alors allez à l'[Installation de pkg-config (macOS)](#installation-de-pkg-config-macos).
    - Si devkitARM **n'est pas installé**, alors allez à l'[Installation de devkitARM (macOS)](#installation-de-devkitarm-macos).

3. **Optionnel: Pour exécuter les tests**, si l'environnement homebrew n'est pas installé, installez le gestionnaire de paquets en utilisant [cette référence](https://brew.sh). Ouvrez votre terminal et exécutez les commandes suivantes:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
brew install coreutils
```

4. **Optionnel: Pour exécuter les tests via Rosetta**
    - Vous ne voudrez probablement pas faire cela car c'est beaucoup plus lent. La plupart des utilisateurs peuvent utiliser les outils natifs, mais certains peuvent avoir d'autres raisons d'utiliser ce setup comme le travail avec des outils personnalisés uniquement pour Intel.
    - Vous aurez besoin d'une installation homebrew compatible Intel. Comprendre comment en obtenir une peut être trouvé [ici](https://github.com/Homebrew/brew/issues/9173#issuecomment-729206868).
    - Installez `coreutils` comme à l'étape 3, mais en utilisant votre installation homebrew compatible Intel.

### Installation de libpng (macOS)
<details>
    <summary><i>Note pour les utilisateurs expérimentés...</i></summary>

>   Ce guide installe libpng via Homebrew car c'est la méthode la plus simple, mais les utilisateurs expérimentés peuvent installer libpng par d'autres moyens s'ils le souhaitent.
</details>

1. Ouvrez le Terminal.
2. Si Homebrew n'est pas installé, installez [Homebrew](https://brew.sh/) en suivant les instructions sur le site Web.
3. Exécutez la commande suivante pour installer libpng.

    ```bash
    brew install libpng
    ```
    libpng est maintenant installé.

    Continuez vers l'[Installation de pkg-config (macOS)](#installation-de-pkg-config-macos) si **pkg-config n'est pas installé**. Sinon, continuez vers l'[Installation de devkitARM (macOS)](#installation-de-devkitarm-macos) si **devkitARM n'est pas installé**.

### Installation de pkg-config (macOS)
<details>
    <summary><i>Note pour les utilisateurs expérimentés...</i></summary>

>   Ce guide installe pkg-config via Homebrew car c'est la méthode la plus simple, mais les utilisateurs expérimentés peuvent installer pkg-config par d'autres moyens s'ils le souhaitent.
</details>

1. Ouvrez le Terminal.
2. Si Homebrew n'est pas installé, installez [Homebrew](https://brew.sh/) en suivant les instructions sur le site Web.
3. Exécutez la commande suivante pour installer pkg-config.

    ```bash
    brew install pkg-config
    ```
    pkg-config est maintenant installé.

    Continuez vers l'[Installation de devkitARM (macOS)](#installation-de-devkitarm-macos) si **devkitARM n'est pas installé**. Sinon, continuez vers l'[Installation de Python (macOS)](#installation-de-python-macos) si **Python n'est pas installé**.

### Installation de devkitARM (macOS)
1. Téléchargez le paquet `devkitpro-pacman-installer.pkg` depuis [ici](https://github.com/devkitPro/pacman/releases).
2. Ouvrez le paquet pour installer devkitPro pacman.
3. Dans le Terminal, exécutez les commandes suivantes pour installer devkitARM:

    ```bash
    sudo dkp-pacman -Sy
    sudo dkp-pacman -S gba-dev
    sudo dkp-pacman -S devkitarm-rules
    ```

    La commande avec gba-dev vous demandera de sélectionner les paquets à installer. Appuyez simplement sur Entrée pour installer tous ceux-ci, suivi de Y pour procéder à l'installation.

4. Après l'installation des outils, devkitARM doit maintenant être accessible depuis n'importe où par le système. Pour ce faire, exécutez les commandes suivantes:

    ```bash
    export DEVKITPRO=/opt/devkitpro
    echo "export DEVKITPRO=$DEVKITPRO" >> ~/.zshrc
    export DEVKITARM=$DEVKITPRO/devkitARM
    echo "export DEVKITARM=$DEVKITARM" >> ~/.zshrc

    echo "if [ -f ~/.zshrc ]; then . ~/.zshrc; fi" >> ~/.zprofile
    ```
    *Note: Depuis macOS 10.15, le shell Unix par défaut est maintenant zsh. Si vous avez migré d'une version plus ancienne de macOS, vous utilisez peut-être encore bash. Vous pouvez vérifier en exécutant `echo $0` dans le terminal.*
    <details>
        <summary><i>Si votre terminal utilise bash au lieu de zsh...</i></summary>

    ```bash
    export DEVKITPRO=/opt/devkitpro
    echo "export DEVKITPRO=$DEVKITPRO" >> ~/.bashrc
    export DEVKITARM=$DEVKITPRO/devkitARM
    echo "export DEVKITARM=$DEVKITARM" >> ~/.bashrc

    echo "if [ -f ~/.bashrc ]; then . ~/.bashrc; fi" >> ~/.bash_profile
    ```
    </details>

### Installation de Python (macOS)
1. Téléchargez le dernier paquet Python depuis [ici](https://www.python.org/downloads/).
2. Ouvrez le paquet pour installer Python.

Python est maintenant installé.

