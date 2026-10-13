# Instructions d'installation Windows pour WSL
## Choisir la version de WSL
Si vous devez stocker votre projet sur le système de fichiers Windows (sous /mnt/c/), vous devriez utiliser WSL1.
Si vous voulez les meilleures performances et le moins de problèmes avec Windows interférant avec la compilation du projet, utilisez WSL2 et stockez le projet sur le système de fichiers Linux (sous ~/).

## Installer WSL
1. Ouvrez [Windows Powershell **en tant qu'administrateur**](https://i.imgur.com/QKmVbP9.png), et exécutez les commandes suivantes (clic droit ou Shift+Insert est coller dans Powershell).

```powershell
wsl --install -d Ubuntu --enable-wsl1
```

2. Quand le processus est terminé, redémarrez votre machine.

### WSL1
3. Ouvrez Windows Powershell **en tant qu'administrateur** encore une fois (after le redémarrage), et exécutez la commande suivante pour qu'Ubuntu utilise WSL1.

```powershell
wsl --set-version Ubuntu 1
```

### WSL2
3. Ouvrez Windows Powershell **en tant qu'administrateur** encore une fois (after le redémarrage), et exécutez la commande suivante pour qu'Ubuntu utilise WSL2.

```powershell
wsl --set-version Ubuntu 2
```

<details>
    <summary><i>Note...</i></summary>

>   WSL peut s'ouvrir automatiquement après le redémarrage, mais vous pouvez l'ignorer pour l'instant.
</details>

## Installer les dépendances
Quelques conseils avant de continuer:
- Dans WSL, vous pouvez **copier/coller** en utilisant:
    - **clic droit** (sélection + clic droit pour copier, clic droit sans sélection pour coller)
    - **Ctrl+Shift+C/Ctrl+Shift+V** (activé en cliquant avec le bouton droit sur la barre de titre, en allant dans Propriétés, puis en cochant la case à côté de "Utiliser Ctrl+Shift+C/V comme Copier/Coller").
- Certaines des commandes que vous exécuterez demanderont votre mot de passe WSL et/ou une confirmation pour effectuer l'action indiquée. C'est à prévoir, il suffit d'entrer votre mot de passe WSL et/ou l'action oui (`yes`) si nécessaire.

1. Ouvrez **Ubuntu** (par exemple en utilisant le menu Démarrer).
2. WSL/Ubuntu configurera sa propre installation lorsqu'il s'exécutera pour la première fois. Une fois que WSL/Ubuntu a terminé l'installation, il vous demandera un nom d'utilisateur et un mot de passe (à saisir).
<details>
    <summary><i>Note...</i></summary>

>   Quand vous saisissez le mot de passe, il n'y aura pas de réponse visible, mais le terminal lira toujours l'entrée.
</details>

3. Mettez à jour WSL/Ubuntu avant de continuer. Pour ce faire, exécutez les commandes suivantes. Ces commandes prendront probablement beaucoup de temps à se terminer:

```bash
sudo apt update && sudo apt upgrade
```

4. Certains paquets sont requis pour compiler pokeemeraude-expansion. Installez ces paquets en exécutant la commande suivante:

```bash
sudo apt install build-essential binutils-arm-none-eabi gcc-arm-none-eabi libnewlib-arm-none-eabi git libpng-dev python3
```

## Choisir un emplacement pour stocker pokeemeraude-expansion, WSL1
WSL possède son propre système de fichiers qui n'est pas accessible nativement depuis Windows, mais les fichiers Windows *sont* accessibles depuis WSL. Ainsi, vous allez vouloir stocker pokeemeraude-expansion dans Windows. 

Par exemple, disons que vous voulez stocker pokeemeraude-expansion dans **C:\Users\\_\<user>_\Desktop\decomps**. Tout d'abord, assurez-vous que le dossier existe déjà. Ensuite, entrez cette commande pour **changer de répertoire** vers ledit dossier, où *\<user>* est votre nom d'utilisateur **Windows**:

```bash
cd /mnt/c/Users/<user>/Desktop/decomps
```

<details>
    <summary><i>Notes...</i></summary>

>   Note 1: Le disque C:\ de Windows s'appelle /mnt/c/ dans WSL.
>   Note 2: Si le chemin contient des espaces, le chemin doit être entouré de guillemets, par exemple `cd "/mnt/c/users/<user>/Desktop/decomp folder"`.
>   Note 3: Les noms de chemin Windows ne sont pas sensibles à la casse, donc respecter la capitalisation n'est pas nécessaire.
</details>

## Choosing a location to store pokeemerald Expansion, WSL2
WSL possède son propre système de fichiers qui n'est pas accessible nativement depuis Windows, mais les fichiers Windows *sont* accessibles depuis WSL. Mais accéder aux fichiers sur le système de fichiers Windows avec WSL2 est très lent, vous allez donc vouloir stocker pokeemeraude-expansion dans WSL2.
Pour accéder aux fichiers sur le système de fichiers WSL depuis Windows, vous devez ouvrir le système de fichiers WSL en tant que stockage en réseau dans l'explorateur de fichiers, il devrait se trouver en bas de la barre latérale gauche sous "Ubuntu".

Maintenant, vous allez vous assurer que vous êtes dans le système de fichiers WSL, puis créer le dossier pour les décomps s'il n'existe pas déjà, puis entrer dans ce dossier. Pour ce faire, exécutez les commandes suivantes:

```bash
cd ~/
mkdir decomps
cd decomps
```
