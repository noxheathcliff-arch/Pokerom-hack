# Outillage QA : émulateur headless et `make check`

Ce document décrit le banc de test sans écran du projet :

1. **`make check`** : la suite de tests unitaires et de combat de l'expansion, exécutée dans mGBA (`mgba-rom-test` + `mgba-rom-test-hydra`).
2. **`gbaplay`** : un lecteur GBA headless piloté par script (libmgba). Il envoie des entrées, prend des captures PNG, gère les sauvegardes batterie (`.sav`) et les savestates, lit et écrit la mémoire à partir des symboles et détecte les crashs et les gels.

Les binaires sont installés **hors du dépôt**, dans `/opt/mgba-tools`. Seules les sources et les scripts sont versionnés :

| Chemin | Rôle |
|---|---|
| `tools/qa/install_mgba_tools.sh` | Compile et installe mGBA (lib statique et `mgba-rom-test`), `mgba-rom-test-hydra` et `gbaplay` |
| `tools/qa/gbaplay/gbaplay.c`, `Makefile` | Sources de `gbaplay` (le binaire va dans `/opt/mgba-tools/bin`) |
| `tools/qa/sb_offsets.sh` | Calcule les offsets des structures de sauvegarde (flags, vars, nom…) avec le compilateur du projet |
| `tools/qa/run_smoke.sh` | Test de fumée complet : nouvelle partie, sauvegarde en jeu, redémarrage, CONTINUER |
| `tools/qa/scripts/*.txt` | Scripts d'entrées réutilisables |
| `qa_artifacts/` (git-ignoré) | Captures, logs, `.sav` produits par les runs |

---

## 1. Installation

Dépendances (Ubuntu/Debian) :

```sh
sudo apt-get install -y cmake ninja-build pkg-config libpng-dev zlib1g-dev libelf-dev libzstd-dev
```

Compilation et installation dans `/opt/mgba-tools` (environ 2 min sur 4 cœurs) :

```sh
tools/qa/install_mgba_tools.sh            # ou: tools/qa/install_mgba_tools.sh /autre/prefixe
export PATH=/opt/mgba-tools/bin:$PATH     # optionnel, voir § 2
```

Le script :

- clone `https://github.com/mgba-emu/mgba` dans `/opt/mgba-src/mgba` et se place sur le commit `dbffb46c4e7d2e7a2cbed7c3488cece4c2176d4c`. C'est le même commit que le binaire Linux précompilé `tools/mgba/mgba-rom-test` fourni par l'expansion (voir `tools/mgba/README.md`) ;
- compile sans Qt, SDL, OpenGL, FFmpeg ni Lua, avec `BUILD_ROM_TEST=ON` et `BUILD_STATIC=ON` ;
- installe `bin/mgba-rom-test`, `lib/libmgba.a` et `include/` ;
- enregistre dans `lib/mgba-cflags.txt` les `-D` utilisés pour compiler libmgba. **C'est indispensable** : `gbaplay` inclut des en-têtes internes de mGBA dont la disposition des structures dépend de ces defines (par ex. `USE_PTHREADS`). Sans eux, la sauvegarde flash est silencieusement cassée (bug rencontré puis corrigé pendant la mise au point) ;
- compile `mgba-rom-test-hydra` depuis `tools/mgba-rom-test-hydra/main.c` ;
- compile `gbaplay` (`make -C tools/qa/gbaplay`).

Pour recompiler seulement `gbaplay` après une modification : `make -C tools/qa/gbaplay` (variables `MGBA_PREFIX` et `BINDIR` disponibles).

## 2. `make check`

En amont, l'expansion **fournit déjà** un `mgba-rom-test` Linux précompilé dans `tools/mgba/` et compile `mgba-rom-test-hydra` automatiquement (`CHECK_TOOL_NAMES` dans `make_tools.mk`). La CI GitHub (`.github/workflows/build.yml`) lance simplement `make -j$(nproc) check`. Le `Makefile` (l. 228-235) choisit :

```make
ROMTEST ?= $(shell command -v mgba-rom-test 2>/dev/null || echo $(TOOLS_DIR)/mgba/mgba-rom-test)
ROMTESTHYDRA := $(shell command -v mgba-rom-test-hydra 2>/dev/null || echo $(TOOLS_DIR)/mgba-rom-test-hydra/mgba-rom-test-hydra)
```

Pour utiliser les binaires compilés depuis les sources, trois options :

```sh
make check -j4 ROMTEST=/opt/mgba-tools/bin/mgba-rom-test ROMTESTHYDRA=/opt/mgba-tools/bin/mgba-rom-test-hydra
# ou : PATH=/opt/mgba-tools/bin:$PATH make check -j4   (command -v les trouve en premier)
# ou : rien du tout -> binaire précompilé tools/mgba/mgba-rom-test (il fonctionne dans ce conteneur)
make check TESTS="Spikes"     # filtrer par nom de test
```

`make check` compile un ELF de test séparé (`build/emeraude-test`), le patche en mode headless, puis hydra lance N instances de `mgba-rom-test` en parallèle et affiche un résumé (`PASS`, `FAIL`, `KNOWN_FAILING`…).

**Résultat sur l'upstream vierge** (`/home/user/upstream`, pokeemeraude-expansion 1.16.4, avec les binaires de `/opt/mgba-tools`) : voir § 7.

## 3. `gbaplay` : utilisation

```
gbaplay [options] ROM [SCRIPT|-]
  -f, --frames N        exécute N frames (après le script)
  -s, --sav FILE        sauvegarde batterie : chargée au boot si elle existe, réécrite à la sortie
      --sav-out FILE    écrit la sauvegarde ailleurs que --sav
      --no-sav-write    ne jamais réécrire la sauvegarde
  -t, --state FILE      charge un savestate avant de commencer
  -o, --outdir DIR      dossier de base des chemins relatifs (captures, states, dumps)
      --syms FILE       fichier de symboles (.sym de `make syms`, sortie de `nm`, ou .map) ; répétable
      --defs FILE       constantes "NOM VALEUR" (ex. sortie de sb_offsets.sh) ; répétable
  -D NOM=VALEUR         constante pour les expressions
      --screenshot FILE capture à la fin
      --hang N          signale un écran inchangé pendant N frames
      --hang-fatal      arrête avec le code 4 en cas de gel
      --fatal-is-fail   arrête avec le code 6 si le jeu logue un FATAL (assert)
      --rtc EPOCH       heure de départ de la RTC (défaut 2026-01-01 12:00 UTC, avance avec le temps émulé) ; 'wall' = horloge hôte
      --bios FILE       vrai BIOS GBA (défaut : BIOS HLE de mGBA)
  -l, --log MASK        niveaux de log mGBA affichés (défaut 3 = FATAL|ERROR, 127 = tout)
  -v / -q               trace des commandes / moins de messages sur stderr
```

**Codes de sortie** : 0 OK, 1 erreur de chargement, 2 erreur de script, 3 au moins un `expect*` en échec, 4 gel (`--hang-fatal`), 5 crash CPU (saut vers une adresse invalide), 6 FATAL du jeu (`--fatal-is-fail`).

L'émulation n'est pas cadencée : elle tourne aussi vite que possible (≈ 1 700 frames/s ici, soit environ 28 fois le temps réel). La RTC est en « fake epoch » : elle part d'une date fixe et avance avec les frames émulées, ce qui rend les runs **déterministes**.

Sortie standard : lignes préfixées `[screenshot]`, `[PASS]`/`[FAIL]`, `[game LEVEL]` (logs du jeu), `[CRASH]`, `[HANG?]`, `[echo]`, puis une ligne finale `[gbaplay] done: …`.

### Exemples

```sh
# Captures rapides : 30 s de jeu, capture finale
gbaplay -f 1800 --screenshot /tmp/x.png pokeemeraude.gba

# Script avec symboles et offsets
arm-none-eabi-nm pokeemeraude.elf > qa_artifacts/rom.syms     # ou: make syms -> pokeemeraude.sym
tools/qa/sb_offsets.sh > qa_artifacts/offsets.defs
gbaplay --syms qa_artifacts/rom.syms --defs qa_artifacts/offsets.defs \
        -o qa_artifacts/run -s qa_artifacts/run/game.sav \
        pokeemeraude.gba tools/qa/scripts/new_game_and_save.txt

# Test de fumée complet (nouvelle partie -> sauvegarde -> power cycle -> continuer)
tools/qa/run_smoke.sh                       # ROM du dépôt
tools/qa/run_smoke.sh /home/user/upstream qa_artifacts/proof_upstream
```

## 4. Syntaxe des scripts d'entrées

Une commande par ligne. `#` commence un commentaire. Les arguments sont séparés par des espaces. Les **expressions** (adresses, valeurs) ne contiennent pas d'espace et acceptent :

- des nombres décimaux ou `0x…` ;
- des symboles (`gMain`, `CB2_Overworld`), des constantes `--defs`, `-D` ou `define` ;
- `+` et `-` ;
- `*expr`, qui lit un mot de 32 bits à l'adresse donnée (déréférencement de pointeur) ;
- des parenthèses.

Exemple : `*gSaveBlock1Ptr+SB1_FLAGS_OFFSET`.

| Commande | Effet |
|---|---|
| `press KEYS [n=2]` | maintient les touches n frames, puis les relâche 2 frames (réglable avec `gap N`) |
| `hold KEYS [n=30]` | maintient n frames, sans pause de relâchement |
| `wait N` / `waitsec S` | attend N frames ou S secondes (touches relâchées) |
| `release` | relâche tout |
| `screenshot F.png` | capture PNG 240x160 |
| `savestate F` / `loadstate F` | savestate mGBA (inclut la sauvegarde batterie et la RTC) |
| `writesave [F]` | écrit la sauvegarde batterie maintenant (défaut : `--sav`) |
| `reset` | reset logiciel (la sauvegarde batterie en mémoire est conservée) |
| `readmem EXPR LEN` | hexdump sur stdout |
| `dumpmem EXPR LEN F` | dump binaire dans un fichier |
| `read8/16/32 EXPR` | affiche une valeur |
| `write8/16/32 EXPR VAL` | écrit en mémoire (triche ou mise en place d'un test) |
| `expect8/16/32 EXPR VAL` | assertion : `[PASS]`/`[FAIL]`, code de sortie 3 en cas d'échec |
| `waitfor8/16/32 EXPR VAL MAX [KEY [PERIODE=8]]` | attend que la mémoire vaille VAL (au plus MAX frames), en martelant éventuellement KEY ; un dépassement compte comme un échec |
| `flag ID` / `expectflag ID 0\|1` | lit ou vérifie un flag sauvegardé (nécessite `gSaveBlock1Ptr` et `SB1_FLAGS_OFFSET`) |
| `var ID` / `expectvar ID VAL` | lit ou vérifie une var 0x4000-0x7FFF (nécessite `SB1_VARS_OFFSET`) |
| `define NOM EXPR` | définit une constante |
| `repeat N CMD…` | répète une commande |
| `include F` | inclut un autre script (chemin relatif au script courant) |
| `echo texte` | message horodaté (numéro de frame) |
| `pc` | affiche le PC |
| `hangcheck N` | active ou modifie la détection de gel en cours de script |
| `turbo`, `realtime` | acceptés mais sans effet (toujours en vitesse max) |
| `quit` | fin du script |

Touches disponibles : `A B SELECT START RIGHT LEFT UP DOWN R L`, combinables avec `+` (ex. `press A+B`).

**Méthode recommandée** : synchroniser sur l'état du jeu plutôt que sur des frames fixes. Le plus fiable est `gMain.callback2` (offset 4). Les pointeurs de fonction Thumb valent `adresse du symbole + 1` :

```
waitfor32 gMain+4 CB2_MainMenu+1 600 START 20     # martèle START jusqu'au menu principal
waitfor32 gMain+4 CB2_Overworld+1 6000 A 20       # martèle A jusqu'à l'overworld
```

Points d'attention constatés :

- Le texte s'affiche lentement. Un `A` appuyé pendant l'affichage ne fait qu'accélérer le texte : attendre ~240 frames avant de répondre à un OUI/NON.
- L'écran de nom passe en minuscules après la première lettre (animation) : attendre ~40 frames.
- Dans le camion, les commandes restent bloquées un moment après l'arrivée dans l'overworld : attendre ~1000 frames avant `START`.

## 5. Lire flags et vars en mémoire

Les blocs de sauvegarde sont alloués dynamiquement : `gSaveBlock1Ptr` et `gSaveBlock2Ptr` sont des **pointeurs** en IWRAM, et leur cible bouge (la position est aléatoire à chaque chargement). Il faut donc toujours passer par `*` :

```
readmem *gSaveBlock2Ptr 8                           # nom du joueur (encodage du jeu : 0xBB='A', 0xD5='a', 0xFF=fin)
read8   *gSaveBlock1Ptr+SB1_LOCATION_OFFSET         # mapGroup
read8   *gSaveBlock1Ptr+SB1_LOCATION_OFFSET+1       # mapNum
flag    FLAG_SYS_POKEMON_GET                        # bit (id%8) de flags[id/8]
var     VAR_LITTLEROOT_INTRO_STATE                  # u16 vars[id-0x4000]
```

Sources des symboles (adresses fixes) :

- `make syms` produit `pokeemeraude.sym` (format `adresse type taille nom`) ;
- `arm-none-eabi-nm pokeemeraude.elf > rom.syms` donne aussi les symboles `static` ;
- `pokeemeraude.map` (lignes `0xADRESSE nom`) ne contient que les symboles globaux.

En cas de doublons (symboles `static` homonymes comme `MainCB2`), la première occurrence est retenue : préférer alors une adresse explicite.

Les **offsets de structures** (`SB1_FLAGS_OFFSET`, `SB1_VARS_OFFSET`, etc.) ne figurent pas dans les fichiers de symboles. `tools/qa/sb_offsets.sh [PROJET]` compile un petit fichier C avec les en-têtes et les options du projet, puis extrait `offsetof()` et quelques constantes (`MAP_INSIDE_OF_TRUCK_*`, `FLAG_SYS_POKEMON_GET`, `VAR_LITTLEROOT_INTRO_STATE`…). Pour en ajouter, il suffit d'ajouter une ligne `D(NOM, expression C)`. Il faut **le relancer à chaque changement de `struct SaveBlock1/2`**. Valeurs sur l'upstream 1.16.4 : `SB1_FLAGS_OFFSET 4720`, `SB1_VARS_OFFSET 5020`, `SB1_LOCATION_OFFSET 4`, `SB2_PLAYERNAME_OFFSET 0`.

## 6. Logs du jeu, crashs et gels

- **Logs mGBA print** : quand le jeu écrit dans les registres de debug mGBA (`MgbaPrintf`/`DebugPrintf` avec `LOG_HANDLER_MGBA_PRINT`), chaque message sort sur stdout sous la forme `[game WARN] …`. Le script `tools/qa/scripts/selftest_logging_crash.txt` le vérifie. **Attention** : `include/config/general.h` définit `NDEBUG` par défaut, ce qui supprime `DebugPrintf` du ROM normal. Il faut le commenter (build de debug) pour voir les logs du jeu. Les tests de `make check` utilisent ce même canal.
- **Crash** : tout saut vers une adresse non mappée produit `[CRASH] frame N: Jumped to invalid address: … (PC=…)` et le code de sortie 5 (mGBA est configuré pour ne pas s'arrêter brutalement).
- **Gel** : `--hang N` signale `[HANG?]` quand l'image ne change pas pendant N frames. C'est une **heuristique** : un écran légitimement figé (menu principal, boîte de texte en attente d'une touche) déclenche aussi l'alerte. À n'activer que sur des phases où l'image doit bouger, ou avec un seuil large (`run_smoke.sh` utilise 1800 frames, soit 30 s, sans `--hang-fatal`). Un vrai blocage CPU (boucle infinie sans VBlank) fige aussi l'image et est donc détecté.

## 7. Preuve de fonctionnement (upstream 1.16.4, ROM `pokeemeraude.gba` vierge)

Commande : `tools/qa/run_smoke.sh /home/user/upstream qa_artifacts/proof_upstream`, **SMOKE: PASS**, 4,8 s au total.

Run 1 (`qa_artifacts/proof_upstream/run1_new_game/`, 8 195 frames) :

- `01_title.png` : écran titre, après l'intro de l'expansion (« Powered by PRET × RHH ») et l'intro Game Freak, passées avec START ;
- `02_main_menu.png` : NOUVELLE PARTIE / OPTIONS ;
- `03_birch_speech.png` : discours de Birch ;
- `04_naming_screen.png` : « VOTRE NOM? » avec « Abc » saisi ;
- `05_truck_overworld.png` : overworld, dans le camion (`MAP_INSIDE_OF_TRUCK` = groupe 25, n° 40, vérifié en mémoire) ;
- `06_start_menu.png`, `07_save_confirm.png` (« Voulez-vous sauvegarder la partie? »), `08_saved.png` (« Abc a sauvegardé… ») ;
- vérifications `[PASS]` : nom = `BB D6 D7` (« Abc »), genre = 0 (garçon), position = camion.

Puis `game.sav` (128 Kio, flash 1M) est écrit sur disque à la sortie de l'émulateur.

Run 2, power cycle : **nouveau processus** avec la même `game.sav` (`qa_artifacts/proof_upstream/run2_continue/`) :

- `02_main_menu.png` : CONTINUER, JOUEUR Abc, BADGES 0, DUREE JEU 0:00 ;
- `10_continue_overworld.png` : retour dans le camion ;
- `[PASS]` sur le nom, la carte et `FLAG_SYS_POKEMON_GET == 0`.

Le log complet est dans `qa_artifacts/proof_upstream/log.txt`.

Autotest (`tools/qa/scripts/selftest_logging_crash.txt`) : `[game WARN] hello` capturé, puis crash provoqué (`gMain.callback2 = 0x0F000001`), suivi de `[CRASH] … 0F000000` et du code de sortie 5. `--hang 300 --hang-fatal` sur le menu principal immobile donne `[HANG?]` et le code 4 : c'est le comportement attendu de l'heuristique, et c'est aussi la démonstration de sa limite.

**`make check` sur l'upstream** (binaires `/opt/mgba-tools`, `make check -j4`, log `/home/user/check_upstream.log`) : **EXIT 0, 9 min 57 s** (temps CPU 34 min 44 s). Résumé hydra : **PASSED 4937 / TOTAL 5553**, FAILED 0, TO_DO 595, KNOWN_FAILING 13, EXPECT_FAILING 8 (chiffres repris tels quels de la fin du log). Note : un premier lancement avait été interrompu par un redémarrage du conteneur (`/home/user/check_upstream_interrupted.log`, partiel, sans résumé).

## 8. Limites connues

- Pas d'audio (non capturé) ni de vidéo continue : uniquement des captures PNG ponctuelles.
- BIOS HLE par défaut. Le logo de boot du vrai BIOS n'apparaît pas ; `--bios` permet d'en utiliser un vrai.
- Les scripts à frames fixes restent fragiles si le hack change les timings (texte, animations). Il vaut mieux utiliser `waitfor` sur `gMain.callback2` ou sur une variable. Les scripts fournis supposent : l'intro de l'expansion active, un ROM en français (libellés), et un menu START sans POKéDEX ni POKéMON au début du jeu (2 × DOWN pour SAUVER).
- `flag`/`var` ne couvrent que les flags et vars sauvegardés (pas les vars spéciales 0x8000+, lisibles via leurs symboles `gSpecialVar_*`). Les flags temporaires restent lisibles via `SB1_FLAGS_OFFSET`.
- `reset` est un reset logiciel. Le vrai « power cycle » se fait en lançant **deux processus** avec le même `--sav`, ce que fait `run_smoke.sh`.
- La détection de gel est heuristique (voir § 6). La détection de crash ne couvre que les sauts vers une mémoire non mappée, pas les corruptions silencieuses.
- `make check` reste à la charge de l'orchestrateur sur le dépôt du hack (ne pas lancer `make` en parallèle d'un autre build).
