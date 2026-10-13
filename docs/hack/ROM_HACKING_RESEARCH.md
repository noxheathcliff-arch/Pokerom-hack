# Recherche méthodes & outils de ROM hacking — décisions pour ce projet

> Base : **pokeemeraude-expansion 1.16.4** (traduction FR de `rh-hideout/pokeemerald-expansion`, commit amont `1b077e5c`).
> Environnement cible : conteneur Linux **headless** (pas de GUI), `arm-none-eabi-gcc`, Python 3.13, Go, cmake, réseau via proxy.
> Objectif du document : **des décisions**, pas de la théorie. Chaque section suit le gabarit :
> *Problème résolu · Ressources · Applicabilité (projet + headless) · Intégration · Vérification · Limites/alternatives.*
>
> Rédigé le 2026-10-13. Les affirmations issues du dépôt local sont référencées par chemin ; celles issues du web par URL.

---

## 0. Contraintes d'environnement constatées (à connaître avant tout)

| Ressource | État dans le conteneur | Conséquence |
|---|---|---|
| `github.com`, `raw.githubusercontent.com`, `pypi.org`, `proxy.golang.org` | Accessibles | On peut télécharger des binaires de release GitHub, du code source, des paquets Go/PyPI. |
| `*.github.io` (doc RHH, manuel Porymap), `mgba.io`, `pokepedia.fr`, `glama.ai` | **Bloqués par le proxy (403 CONNECT)** | Lire les sources équivalentes : `docs/` local (le site RHH est généré depuis ce dossier, cf. `docs/SUMMARY.md`, `docs/book.toml`), sources `.rst` de Porymap sur raw.githubusercontent, sources mGBA sur GitHub. |
| API GitHub via `gh` | Refusée pour les dépôts non attachés à la session | Utiliser les URLs `https://github.com/<o>/<r>/releases/latest/download/<asset>`. |
| `apt` | Paquets disponibles : `mgba-sdl`/`mgba-qt`/`libmgba-dev` **0.10.2**, `xvfb`, `lua5.4` | mGBA 0.10.2 n'a **pas** de frontend headless ni de `--script` (voir §6.4). |
| `tools/mgba/mgba-rom-test` (binaire Linux livré dans le dépôt) | Présent, aucune dépendance manquante (`ldd` OK) | `make check` est exécutable headless tel quel. |

---

## 1. Workflow décompilation (pret pokeemerald + expansion)

### 1.1 Documentation de référence
- **Problème résolu** : savoir *où* et *comment* modifier sans casser le build.
- **Ressources** : doc officielle RHH <https://rh-hideout.github.io/pokeemerald-expansion/> (bloquée ici) = **mêmes fichiers** que `docs/` du dépôt (`docs/SUMMARY.md` liste toutes les pages). Dépôt amont : <https://github.com/rh-hideout/pokeemerald-expansion>. Wiki pret (tutoriels communautaires, un peu datés) : <https://github.com/pret/pokeemerald/wiki/Tutorials> (miroir lisible : <https://code.heni.lol/decomp/emerald/wiki/Tutorials>).
- **Pages locales les plus utiles pour ce projet** (`docs/tutorials/`) :
  - `how_to_testing_system.md` — système de tests (`make check`, `GIVEN/WHEN/SCENE`, `OVERWORLD_SCRIPT`).
  - `how_to_time_of_day_encounters.md` — rencontres par moment de la journée.
  - `how_to_trainer_party_pool.md`, `how_to_new_trainer_slide.md`, `ai_flags.md` — dresseurs.
  - `how_to_new_pokemon.md`, `how_to_trainer_front_pic.md`, `how_to_trainer_back_pic.md` — ajout de contenu graphique.
  - `how_to_delete_vanilla_maps.md` — liste exacte des 4 endroits à toucher pour une map (vaut aussi pour en **ajouter** une).
  - `dns.md` (jour/nuit), `how_to_follower_npc.md`, `how_to_dynmultichoice.md`, `how_to_namebox.md`, `how_to_spots.md`, `how_to_dynamic_shop.md`, `how_to_overworld_wild_encounters.md`, `quickstart.md` (SELECT sur l'écran-titre pour démarrer une partie directement — utile en debug).
- **Applicabilité** : totale ; tout est texte/C/JSON, donc compatible headless.
- **Vérification** : `make` (build) ; les fichiers générés (`include/constants/map_groups.h`, `map_event_ids.h`, `layouts.h`, `src/data/wild_encounters.h`, `data/maps/*/events.inc`…) sont produits par `tools/mapjson`, `tools/wild_encounters`, `tools/trainerproc` (voir `map_data_rules.mk`, `Makefile` cibles `generated`).
- **Limites** : les docs RHH décrivent la branche anglaise ; dans ce dépôt les textes de scripts sont en français (ex. `data/maps/LittlerootTown/scripts.inc`, « MAMAN: {PLAYER}, on est là, chouchou! »).

### 1.2 Édition de maps **sans Porymap** (headless)

Porymap est une application Qt GUI (<https://github.com/huderlem/porymap>) ; elle n'a pas de mode CLI. Sous xvfb elle démarrerait mais serait inexploitable sans interaction humaine. **Décision : on édite les fichiers source directement**, Porymap restant optionnel pour un humain sur poste local (les formats sont identiques, donc aller-retour possible).

#### Fichiers impliqués
| Fichier | Rôle |
|---|---|
| `data/maps/<Map>/map.json` | En-tête (musique, météo, type, flags d'en-tête), connexions, **object_events, warp_events, coord_events, bg_events** |
| `data/maps/<Map>/scripts.inc` | Scripts ; doit définir le label `<Map>_MapScripts::` |
| `data/maps/map_groups.json` | Groupes de maps (`group_order` + listes) → numéros `MAP_*` |
| `data/layouts/layouts.json` | Déclaration des layouts (`id`, `width`, `height`, tilesets, chemins) |
| `data/layouts/<Layout>/map.bin` | **Blockdata** (nom réel du fichier ici : `map.bin`, pas `blockdata.bin`) |
| `data/layouts/<Layout>/border.bin` | Bordure 2×2 metatiles = 8 octets (vérifié : `LittlerootTown/border.bin` fait 8 o) |
| `data/event_scripts.s` | `.include "data/maps/<Map>/scripts.inc"` (à ajouter à la main) |
| `src/data/heal_locations.json` | si la map est un lieu de soin/fly |

#### Format blockdata (`map.bin`)
Tableau `width × height` de `u16` little-endian, ligne par ligne (Littleroot 20×20 → 800 o). Masques dans `include/global.fieldmap.h` :

| Bits | Masque | Contenu |
|---|---|---|
| 0–9 | `0x03FF` | ID de metatile (0–511 tileset primaire, 512–1023 secondaire ; `NUM_METATILES_IN_PRIMARY 512`, `NUM_METATILES_TOTAL 1024` dans `include/fieldmap.h`) |
| 10–11 | `0x0C00` | Collision (0 = passable, 1 = bloqué ; 2–3 inutilisés en pratique) |
| 12–15 | `0xF000` | Élévation 0–15 |

Sémantique de l'élévation (manuel Porymap, source : <https://raw.githubusercontent.com/huderlem/porymap/master/docsrc/manual/editing-map-collisions.rst>, rendu <https://huderlem.github.io/porymap/manual/editing-map-collisions.html>) :
- **0 = transition** (escaliers) : on peut y entrer depuis n'importe quelle élévation et en repartir vers n'importe laquelle.
- **1 = eau/surf** ; *on ne peut commencer/finir de surfer que depuis l'élévation 3*.
- **2–14 = niveaux** ; le joueur ne peut pas passer d'une élévation à une autre (falaises).
- **15 = multi-niveaux** (ponts) : mémorise l'élévation précédente.
- Collision 1 + élévation 0 = « impassable » générique, interactif depuis toutes les élévations (panneaux) — le type le plus courant pour les obstacles.
- Valeur typique d'herbe/sol extérieur : collision 0, élévation 3 (ex. `0x3xxx`) ; intérieurs souvent élévation 3 aussi. Les premiers mots de Littleroot sont `0x05D4` = metatile 468, collision 1, élévation 0 (arbres de bordure).

Le **comportement** d'un metatile (herbe haute, eau, porte, warp de tapis…) n'est **pas** dans le blockdata mais dans `metatile_attributes.bin` du tileset (bits 0–7 = behavior `MB_*` de `include/constants/metatile_behaviors.h`, bits 12–15 = type de couche ; `include/global.fieldmap.h`). Les tilesets Émeraude sont **dual-layer** (8 tuiles / metatile : `NUM_TILES_PER_METATILE 8` ; `petalburg/metatiles.bin` = 2304 o = 144 × 16 o).

Outil recommandé : petit script Python (pas de dépendance) pour lire/écrire une grille, par ex. :

```python
import struct
def load(path, w, h):
    raw = open(path, 'rb').read(); assert len(raw) == w*h*2
    return [list(struct.unpack_from(f'<{w}H', raw, y*w*2)) for y in range(h)]
def save(path, grid):
    open(path, 'wb').write(b''.join(struct.pack(f'<{len(r)}H', *r) for r in grid))
def block(metatile, collision=0, elevation=3):
    return (metatile & 0x3FF) | (collision & 3) << 10 | (elevation & 0xF) << 12
```
Pour « dessiner », on copie des rectangles de metatiles depuis une map existante utilisant les **mêmes tilesets** (les IDs n'ont de sens que relativement au couple primaire/secondaire du layout).

#### Événements dans `map.json` (format consommé par `tools/mapjson/mapjson.cpp`)
- **object_events** (max `OBJECT_EVENT_TEMPLATES_COUNT 64` par map, max `OBJECT_EVENTS_COUNT 16` objets chargés simultanément — `include/constants/global.h`). Champs : `graphics_id, x, y, elevation, movement_type, movement_range_x/y, trainer_type, trainer_sight_or_berry_tree_id, script, flag`, optionnel `local_id`, `type` (`object` par défaut ou `clone` avec `target_local_id`, `target_map`).
  - ⚠️ L'ID local émis est **l'index + 1** dans le tableau. **Toujours ajouter en fin de tableau** et donner un `local_id` (`"LOCALID_<MAP>_<NOM>"`) : `mapjson` génère `include/constants/map_event_ids.h`, et les scripts utilisent ces constantes au lieu de nombres magiques.
  - `flag` : si le flag est **set**, l'objet est **caché** (`FLAG_HIDE_…`). `"0"` = toujours visible.
  - Dresseur : `trainer_type: TRAINER_TYPE_NORMAL`, `trainer_sight_or_berry_tree_id: "<portée>"`, le script contient `trainerbattle_*`.
- **warp_events** : `x, y, elevation, dest_map, dest_warp_id`. `dest_warp_id` = **index (0-based) dans `warp_events` de la map de destination** → créer les warps par paires et ne jamais réordonner une liste existante. Le metatile sous le warp doit avoir un behavior de porte/tapis/escalier, sinon le warp ne se déclenche pas (comportement vanilla).
- **coord_events** : `type: "trigger"` avec `x, y, elevation, var, var_value, script` (déclenché quand `var == var_value`) ou `type: "weather"` avec `weather`.
- **bg_events** : `sign` (`player_facing_dir`, `script`), `hidden_item` (`item`, `flag`, optionnels `quantity` défaut 1, `underfoot` défaut FALSE), `secret_base` (`secret_base_id`).
- **connections** : `{map, offset, direction}` — à déclarer **dans les deux maps** (sens opposés), les dimensions doivent être cohérentes.

#### Recette : créer une nouvelle map + layout (headless)
1. Copier un layout proche : `data/layouts/<Src>/` → `data/layouts/<New>/` (map.bin, border.bin) ; ajouter l'entrée dans `data/layouts/layouts.json` (`id: LAYOUT_<NEW>`, `name: <New>_Layout`, dimensions, tilesets, chemins, `layout_version: "emerald"`). Si on change `width/height`, régénérer `map.bin` à la bonne taille.
2. Copier `data/maps/<Src>/map.json` → `data/maps/<New>/map.json`, changer `id` (`MAP_<NEW>`), `name` (`<New>`, = nom du dossier), `layout`, vider/adapter les événements.
3. Créer `data/maps/<New>/scripts.inc` avec au minimum :
   ```
   <New>_MapScripts::
   	.byte 0
   ```
4. Ajouter `"<New>"` **en fin** d'un groupe de `data/maps/map_groups.json` (ou un nouveau groupe en fin de `group_order`). Insérer au milieu décale les numéros de map → **casse les sauvegardes existantes** et les références numériques.
5. Ajouter `.include "data/maps/<New>/scripts.inc"` dans `data/event_scripts.s`.
6. Après suppression/renommage de layouts : `touch data/layouts/layouts.json` (`docs/tutorials/how_to_delete_vanilla_maps.md`).
7. Build : `mapjson` valide les types d'événements et échoue avec un message explicite (`FATAL_ERROR("Unknown object event type…")`).

- **Vérification** : build OK ; contrôle visuel via capture d'écran émulateur (§6.4) ; linter maison (§9) qui vérifie bornes x/y, cohérence `dest_warp_id`, existence des labels de script et des flags.
- **Limites** : pas de rendu visuel sans émulateur ; dessin de grandes zones fastidieux → privilégier la dérivation de maps existantes et la copie de blocs. Pour une vraie création graphique, un humain avec Porymap en local, puis commit des fichiers.

### 1.3 Poryscript
- **Problème résolu** : écrire les scripts dans un langage structuré (`if/else`, `while`, `switch`, `mapscripts`, `text`, `movement`) compilé en `.inc` ; **retour à la ligne automatique** des textes selon la largeur réelle en pixels de la police (`format()`). Dépôt : <https://github.com/huderlem/poryscript>.
- **Ressources** : binaire `poryscript-linux.zip` téléchargeable (<https://github.com/huderlem/poryscript/releases/latest/download/poryscript-linux.zip>), ou `go build` (Go présent), ou sous-module + `TOOL_NAMES` dans `make_tools.mk` (méthode documentée dans le README).
- **Applicabilité / headless — testé dans ce conteneur** : version **3.6.1**, s'exécute sans GUI. Test sur un texte français : accents gérés, découpe correcte avec `\n` / `\l` / `$` :
  ```
  .string "Bonjour {PLAYER}! Ça va? Le PROF. SEKO\n"
  .string "t'attend au laboratoire depuis très\l"
  .string "longtemps, dépêche-toi vite!$"
  ```
  `font_config.json` livré : police `1_latin_rse`, `maxLineLength 208` px, `numLines 2`, largeurs connues pour `é è à ç ê ô œ É` (6 px), espace 3 px.
- **Intégration** : règle Makefile `data/%.inc: data/%.pory` + `AUTO_GEN_TARGETS` (README §Installation). Poryscript émet des *line markers* (`# 2 "fichier.pory"`) pour des erreurs pointant le `.pory` (`-lm`, défaut true).
- **Vérification** : comparer l'`.inc` généré ; build ; tests de script (§6.2).
- **Limites** : ajoute un outil au pipeline (version à figer). Les `.inc` vanilla existants restent en assembleur — on ne convertit pas l'existant. Un script Poryscript se termine implicitement par `return` (cf. sortie testée) : écrire `end` explicitement pour les scripts d'événements. `format()` ne connaît pas les variables dynamiques (`{PLAYER}` compte pour sa largeur de placeholder, pas 7 caractères réels) : garder une marge.
- **Décision** : **Oui, adopter Poryscript pour les nouvelles maps/scripts du hack** (`data/maps/<New>/scripts.pory`), principalement pour `format()` (supprime la classe de bugs « texte qui déborde ») et la lisibilité des conditions. Garder l'assembleur `.inc` pour retoucher des scripts vanilla. Alternative si l'équipe refuse un outil de plus : `.inc` brut + linter de largeur de texte (§9) + test `GetStringWidth` (§6.2).

### 1.4 Porytiles (compilation de tilesets)
- **Problème résolu** : transformer des PNG RGBA en couches (bottom/middle/top) en `tiles.png` indexé + `metatiles.bin` + `metatile_attributes.bin` + `palettes/` + `anim/` directement utilisables par le décomp et Porymap. Dépôt : <https://github.com/grunt-lucas/porytiles>.
- **Ressources** : releases Linux **statiquement liées** depuis v2.0.0 (binaires `porytiles` et `porytiles-legacy`) — <https://github.com/grunt-lucas/porytiles/releases> ; installable aussi via Homebrew Linux.
- **Applicabilité** : CLI pure → headless OK. Emeraude = dual-layer : passer `-dual-layer` (exemple wiki : `porytiles-legacy compile-secondary -dual-layer -Wall -o <projet>/data/tilesets/secondary/<nom> <src_secondaire> <src_primaire> <projet>/include/constants/metatile_behaviors.h`, <https://github.com/grunt-lucas/porytiles/wiki/Compiling-A-Secondary-Tileset>). `attributes.csv` optionnel pour les behaviors.
- **Intégration** : sortie dans `data/tilesets/secondary/<nom>/`, puis déclarer le tileset dans `src/data/tilesets/headers.h`, `graphics.h` (`INCGFX_U32(... ".4bpp.fastSmol" ...)`), `metatiles.h` (modèle : `gTileset_Petalburg`).
- **Vérification** : build + capture d'écran in-game ; Porytiles émet des warnings (`-Wall`) sur palettes/tuiles.
- **Limites** : nécessite des **assets graphiques** (pixel art) — Claude ne produit pas d'art de qualité ; la v2 a une CLI différente de `porytiles-legacy` (le wiki documente legacy). Recompiler le secondaire si le primaire change.
- **Décision** : **Ne pas l'utiliser au départ** ; réutiliser les tilesets vanilla. L'adopter seulement si un nouveau tileset (assets Team Aqua, §8) est requis.

### 1.5 Tilemap Studio
- **Problème résolu** : édition de tilemaps (écrans de titre, fonds UI, cartes de région) pour GB/GBC/GBA/NDS… supportant les projets pret. <https://github.com/Rangi42/tilemap-studio> (C++/FLTK ; paquet Flathub communautaire : <https://flathub.org/fr/apps/io.github.Rangi42.tilemap-studio>).
- **Applicabilité** : **GUI uniquement** → inutilisable headless. Pour des tilemaps UI on peut manipuler les `.bin` en Python (u16 : tile 0–9, flip H 10, flip V 11, palette 12–15).
- **Décision** : **Hors périmètre** ; ne s'applique pas aux maps overworld.

---

## 2. Scripting d'événements — bonnes pratiques

### 2.1 Flags et vars
| Type | Plage | Persistance | Usage |
|---|---|---|---|
| `FLAG_TEMP_1`…`FLAG_TEMP_1F` | `TEMP_FLAGS_START` | **Remis à 0 à chaque changement de map** | états locaux (« déjà parlé pendant cette visite ») ; `FLAG_TEMP_E` est réservé par les followers |
| `VAR_TEMP_0`…`VAR_TEMP_F` | `0x4000–0x400F` | Remis à 0 au changement de map | cutscenes locales, triggers temporaires |
| `VAR_0x8000`…, `VAR_RESULT` | vars spéciales | non sauvegardées | arguments de `special`, résultats |
| `FLAG_UNUSED_0x…` | 381 entrées `FLAG_UNUSED_*` dans `include/constants/flags.h` | sauvegardés | **réservoir de nos flags persistants** |
| `VAR_UNUSED_*` | 29 entrées dans `include/constants/vars.h` | sauvegardées | nos vars d'histoire |
| Trainer flags | `TRAINER_FLAGS_START 0x500` | sauvegardés | gérés par `trainerbattle` |
| Daily flags | `DAILY_FLAGS_START` | reset quotidien | événements journaliers |

Règles :
- **Renommer** un `FLAG_UNUSED_0xNNN` en `FLAG_<HACK>_<NOM>` (via `#define` dans `include/constants/flags.h`), ne jamais réutiliser un flag vanilla « qui semble inutile » : beaucoup sont lus en C (`grep -rn FLAG_X src data`).
- Avant de prendre un `FLAG_UNUSED`, vérifier qu'aucune config ne l'utilise (`grep -rn "FLAG_UNUSED_0x0NN" include/config src`) : les configs expansion (`OW_FLAG_*`, `B_FLAG_*`, `DN_FLAG_*`, `B_VAR_DIFFICULTY`…) valent `0` par défaut et doivent être **pointées vers un flag/var libre** quand on les active.
- Préférer **une var d'état par arc narratif** (`VAR_<LIEU>_STATE` 0,1,2…, à la manière de `VAR_LITTLEROOT_TOWN_STATE` dont les états sont commentés en tête de `LittlerootTown/scripts.inc`) plutôt qu'une pluie de flags : un coord_event teste `var == var_value`, et l'ordre est explicite.
- `setflag/clearflag/checkflag` ; `goto_if_set FLAG, Label` / `goto_if_unset` ; `setvar/addvar/compare` + `goto_if_eq`.

### 2.2 Visibilité des objets
- Le champ `flag` d'un object_event cache l'objet quand le flag est **set** au **chargement** de la map.
- Pendant un script : `removeobject LOCALID_X` (cache **et** set le flag) / `addobject LOCALID_X` (clear le flag et affiche) — vérifier dans `asm/macros/event.inc`. Pour changer l'état sans recharger : `setflag` + `removeobject`, ou `clearflag` + `addobject`.
- Positions persistantes : `setobjectxyperm` (en `ON_TRANSITION`) ; mouvement : `applymovement LOCALID_X, Movement` + `waitmovement 0`.

### 2.3 Map scripts (`include/constants/map_scripts.h` — ordre d'exécution à l'entrée)
1. `ON_DIVE_WARP` — plongée.
2. **`ON_TRANSITION`** — pendant la transition : set de flags/vars propres à la map, météo, positions d'objets, `setflag FLAG_HIDE_...`. **Le bon endroit pour décider qui est visible.**
3. **`ON_LOAD`** — layout chargé, pas encore dessiné : `setmetatile` (portes ouvertes, rochers cassés…).
4. `ON_RESUME` — fin de chargement **et** à chaque retour au terrain (après menu/combat) : cacher un Pokémon statique vaincu, maintenir un état.
5. `ON_WARP_INTO_MAP_TABLE` — table `map_script_2 VAR, valeur, Script` : orientation/visibilité du joueur à l'arrivée.
6. **`ON_FRAME_TABLE`** — table `map_script_2 VAR, valeur, Script` évaluée chaque frame après le fondu : **cutscenes automatiques à l'entrée**. Seul le premier script dont la condition est vraie s'exécute. Seul type *non* exécuté en contexte immédiat (<https://github-wiki-see.page/m/pret/pokeemerald/wiki/Random-Info,-Tips,-and-Tricks>).
7. `ON_RETURN_TO_FIELD` — uniquement au retour au terrain.

Syntaxe (exemple réel `data/maps/LittlerootTown/scripts.inc`) :
```
X_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, X_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, X_OnFrame
	.byte 0
X_OnFrame:
	map_script_2 VAR_X_STATE, 0, X_EventScript_Intro
	.2byte 0
```
Règles : les scripts `ON_TRANSITION/ON_LOAD/ON_RESUME` s'exécutent en contexte immédiat → **pas de `msgbox`, `applymovement`, `delay`, `waitstate`** dedans, uniquement des commandes instantanées, terminées par `end`.

### 2.4 Éviter les softlocks
- Toute cutscene `ON_FRAME_TABLE` **doit modifier la var testée** (sinon elle se relance en boucle chaque frame). Idem coord_event : changer `var` après exécution.
- `lock`/`lockall` ↔ `release`/`releaseall` sur **toutes** les branches ; `faceplayer` après `lock` pour un PNJ.
- `applymovement` toujours suivi de `waitmovement` ; mouvements terminés par `step_end`.
- Ne pas bloquer le seul passage avec un objet dont le flag n'est jamais set ; vérifier qu'un PNJ bloqueur disparaît dans *tous* les chemins de l'histoire.
- Warps : pas de warp qui renvoie sur une case warp (boucle) ; vérifier la case d'arrivée praticable.
- Combats obligatoires : penser au cas défaite (`trainerbattle_*` gère le whiteout ; un `setflag` d'histoire placé avant le combat peut rendre l'événement non rejouable).
- Ne pas dépendre d'une map supprimée : entrer dans une map connectée à une map absente **gèle le jeu** (`how_to_delete_vanilla_maps.md`, « Known issues »).
- Tester via le menu debug (`DEBUG_OVERWORLD_MENU`, R+START, actif hors `make release` — `include/config/debug.h`) et via automatisation (§6.4).

### 2.5 Combats de dresseurs (`asm/macros/event.inc`)
| Macro | Usage |
|---|---|
| `trainerbattle_single TRAINER, IntroText, DefeatText[, EventScriptAprès][, music]` | Dresseur standard (vision ou interaction) |
| `trainerbattle_double TRAINER, Intro, Defeat, NotEnoughMonsText[, ...]` | Combat double avec un seul dresseur |
| `trainerbattle_no_intro TRAINER, DefeatText` | Combat scénarisé lancé après un dialogue |
| `trainerbattle_two_trainers A, DefeatA, B, DefeatB` | Deux dresseurs qui voient le joueur |
| `trainerbattle_rematch[_double]` | Revanches (Vs Seeker, `docs/tutorials/vs_seeker.md`) |
| `trainerbattle_earlyrival TRAINER, flags, Defeat, Victory` | Rival (défaite non fatale) |

Après la macro, le script continue seulement quand le dresseur est déjà battu (texte « après combat »). Le trainer flag est set automatiquement.

### 2.6 Boîtes de texte
- Contrôles (`charmap.txt`) : `\n` (FE) = ligne suivante ; `\l` (FA) = défilement d'une ligne (attend un appui) ; `\p` (FB) = nouvelle boîte après appui ; `$` (FF) = fin de chaîne.
- Règle de rédaction : **2 lignes visibles par boîte**. Dans une boîte : 1re rupture `\n`, ruptures suivantes `\l` ; changement de boîte `\p`. Conforme au texte vanilla FR (ex. `LittlerootTown_Text_OurNewHomeLetsGoInside`).
- Largeur : **~208 px utiles** (valeur Poryscript `maxLineLength` pour `1_latin_rse`, <https://github.com/huderlem/poryscript>) ; avec ~6 px par lettre et 3 px par espace ⇒ **≈ 35 caractères par ligne en pratique** (prudence : `{PLAYER}` jusqu'à 7 caractères, `{STR_VAR_1}` variable). Les lignes FR vanilla font ~32–38 caractères.
- `msgbox Text, MSGBOX_NPC` (lock+faceplayer+release intégrés), `MSGBOX_SIGN`, `MSGBOX_DEFAULT`, `MSGBOX_YESNO` (résultat dans `VAR_RESULT`), `MSGBOX_AUTOCLOSE`.
- Expansion : `docs/tutorials/how_to_namebox.md` (boîte de nom du locuteur).

### 2.7 Caractères français (`charmap.txt`)
- Présents : `À Á Â Ç È É Ê Ë Ì Î Ï Ò Ó Ô Œ Ù Ú Û Ñ ß à á â ç è é ê ë ì î ï ò ó ô œ ù ú û ñ Ä Ö Ü ä ö ü º ª ¿ ¡ … ‘ ’ “ ”`, `NBSP` (39), `'` = `’` (B4), `PK`, `PKMN`, `LV`.
- **Absents** : `« »`, `æ Æ`, `ÿ Ÿ`. → Utiliser `“ ”` ou `"` pour les citations (convention à figer) ; jamais de `«`.
- Convention vanilla FR observée : **pas d'espace avant `! ? : ;`** (« chouchou! ») — économise de la largeur ; s'y tenir pour la cohérence. « POKéMON » s'écrit avec `é` minuscule, comme dans le jeu original.
- Noms : se référer à Poképédia (§8) pour les noms officiels FR (espèces, lieux, objets).

---

## 3. Dresseurs (expansion)

### 3.1 `src/data/trainers.party` (format Showdown)
- **Problème résolu** : définir dresseurs et équipes en texte lisible, compilé par `tools/trainerproc` (`trainer_rules.mk`). Format décrit en tête du fichier et compatible avec les exports Showdown (<https://github.com/smogon/pokemon-showdown/blob/master/sim/TEAMS.md>).
- **Structure** : `=== TRAINER_XXX ===` puis champs dresseur, ligne vide, puis Pokémon séparés par une ligne vide :
  ```
  === TRAINER_ROXANNE_1 ===
  Name: ROXANNE
  Class: Leader
  Pic: Leader Roxanne
  Gender: Female
  Music: Female
  Items: Potion / Potion
  Double Battle: No
  AI: Basic Trainer

  Nosepass @ Oran Berry
  Level: 15
  IVs: 24 HP / 24 Atk / 24 Def / 24 SpA / 24 SpD / 24 Spe
  - Block
  - Harden
  ```
- Champs dresseur acceptés (message d'erreur de `tools/trainerproc/main.c`) : `Name, Class, Pic, Back Pic, Gender, Music, Items, Battle Type, Difficulty, Party Size, Multi Party, Pool Rules, Pool Pick Functions, Pool Prune, AI` (+ `Mugshot`, `Starting Status`, `Copy Pool`). Champs Pokémon : `Level` (défaut 100 !), `Ability, IVs` (défaut 31), `EVs, Ball, Happiness, Nature, Shiny, Dynamax Level, Gigantamax, Tera Type, Tags`, moves `- Move` en dernier (sinon les 4 derniers appris au niveau).
- ⚠️ Commentaires uniquement en `/* */` (pas `//`). **Toujours préciser `Level`** (défaut 100) et IVs pour l'équilibrage. Les noms d'espèces/attaques s'écrivent en **anglais** (ou constantes `SPECIES_*`) : c'est l'identifiant, pas le texte affiché. `Name:` est le texte affiché (≤ 10 caractères, 12 en police étroite ; tronqué silencieusement).
- Fichiers : `trainers.party` (Émeraude), `trainers_frlg.party`, `battle_partners.party`, `debug_trainers.party`.
- **Vérification** : build (trainerproc signale les erreurs de syntaxe avec la position) ; tests `AI_SINGLE_BATTLE_TEST` si une IA spécifique doit être garantie.

### 3.2 IA (`docs/tutorials/ai_flags.md`, `include/constants/battle_ai.h`)
- `AI: Basic Trainer` = `CHECK_BAD_MOVE | TRY_TO_FAINT | CHECK_VIABILITY`.
- `AI: Smart Trainer` = Basic + `OMNISCIENT | SMART_SWITCHING | SMART_MON_CHOICES | PP_STALL_PREVENTION | SMART_TERA | RANDOMIZE_SWITCHIN`.
- Utiles : `Ace Pokemon` (dernier Pokémon gardé), `Prefer Status Moves`, `Predict Switch`… (liste et effets dans `ai_flags.md`).
- **Décision** : dresseurs de route → `Basic Trainer` ; champions/rival/boss → `Smart Trainer` + `Ace Pokemon`.

### 3.3 Party pools (`docs/tutorials/how_to_trainer_party_pool.md`)
Équipe tirée d'un pool (avec `Party Size`, `Pool Rules`, `Tags` Lead/Ace…). Utile pour la rejouabilité ; **ne pas l'utiliser pour les combats scénarisés** (équilibrage non déterministe, tests plus durs).

### 3.4 Trainer slides (`docs/tutorials/how_to_new_trainer_slide.md`)
Répliques en combat (avant Méga-évolution, dernier Pokémon, PV bas…), dans `src/trainer_slide.c` (`sTrainerSlides[DIFFICULTY][TRAINER][SLIDE]`, `COMPOUND_STRING("...{PAUSE_UNTIL_PRESS}")`). Bon rapport coût/effet pour les champions.

### 3.5 Difficulté
`include/constants/difficulty.h` : `DIFFICULTY_EASY, NORMAL, HARD` ; champ `Difficulty:` dans `.party` pour des variantes d'un même dresseur ; activée par `B_VAR_DIFFICULTY` (`include/config/battle.h`, à pointer vers une var libre et à régler après `NewGameInitData`). **Décision : ne pas activer en v1** (triple le travail d'équilibrage).

---

## 4. Rencontres sauvages

### 4.1 `src/data/wild_encounters.json`
- Groupe `gWildMonHeaders` (`for_maps: true`) avec `fields` : `land_mons` (12 slots, taux 20/20/10/10/10/10/5/5/4/4/1/1), `water_mons` (5), `rock_smash_mons` (5), `fishing_mons` (10, sous-groupes `old_rod [0,1]`, `good_rod [2,3,4]`, `super_rod [5..9]`).
- Entrée : `{"map": "MAP_X", "base_label": "gX", "land_mons": {"encounter_rate": 20, "mons": [{"min_level", "max_level", "species"} ×12]}}`. Les slots sont **positionnels** : il faut exactement le nombre de slots du field.
- Généré par `tools/wild_encounters/wild_encounters_to_header.py` → `src/data/wild_encounters.h`.

### 4.2 Rencontres selon l'heure (`docs/tutorials/how_to_time_of_day_encounters.md`)
- `OW_TIME_OF_DAY_ENCOUNTERS` (`include/config/overworld.h`, défaut FALSE). Si TRUE : dupliquer l'entrée avec un `base_label` suffixé `_Morning`, `_Day`, `_Evening`, `_Night`. Sans suffixe → créneau de repli `OW_TIME_OF_DAY_FALLBACK` (défaut `TIME_MORNING`) ; `OW_TIME_OF_DAY_DISABLE_FALLBACK` contrôle le repli quand une table est vide.
- Script de migration : `migration_scripts/add_time_based_encounters.py`.
- **Décision** : à activer seulement si la narration l'exige ; sinon rester vanilla (moins de données, moins de tests).

### 4.3 DexNav (`include/config/dexnav.h`)
`DEXNAV_ENABLED FALSE` ; si TRUE, **tous** les `DN_FLAG_*`/`DN_VAR_*` doivent être non nuls (flags/vars libres) et un field `hidden_mons` doit être ajouté (ordre défini dans `struct WildEncounterTypes`, `include/wild_encounter.h`). `USE_DEXNAV_SEARCH_LEVELS` : « POSSIBLY EXCEEDS SAVEBLOCK SPACE » (1 octet/espèce). **Décision : désactivé.**

### 4.4 Rencontres visibles
`docs/tutorials/how_to_overworld_wild_encounters.md` (Pokémon visibles en overworld). Option à évaluer plus tard.

---

## 5. Espèces, graphismes, taille ROM

- **Limite** : `ld_script_modern.ld` déclare `ROM LENGTH = 32M`, `EWRAM 256K`, `IWRAM 32K`. Dépassement ⇒ erreur de linker « region `ROM' overflowed » — échec dur, pas de troncature ; un émulateur refuse aussi une ROM >32 Mo (signalé par la communauté : <https://www.pokecommunity.com/threads/exactly-how-much-can-one-shove-into-a-rom-hack.338053>).
- **Leviers de taille** :
  - `include/config/species_enabled.h` : `P_GEN_1_POKEMON` … `P_GEN_9_POKEMON` (tous TRUE par défaut), méga-évolutions, évolutions cross-gen ; familles individuelles via les `P_FAMILY_*`. Désactiver les générations inutiles réduit fortement la taille et le temps de build.
  - `OW_POKEMON_OBJECT_EVENTS TRUE` (sprites overworld de toutes les espèces) et `OW_FOLLOWERS_ENABLED FALSE` (`include/config/overworld.h`) — les sprites OW pèsent lourd.
  - Compression : le build utilise `.lz` (gbagfx), `.smol` / `.fastSmol` / `.smolTM` (`tools/compresSmol`, règles dans `Makefile` l.433–436) ; les tilesets utilisent `.4bpp.fastSmol` (`src/data/tilesets/graphics.h`). Rien à faire sauf choisir le bon suffixe pour les nouveaux assets (copier le modèle existant).
- **Ajout d'espèce/graphisme** : `docs/tutorials/how_to_new_pokemon.md` ; dresseurs : `how_to_trainer_front_pic.md`, `how_to_trainer_back_pic.md` ; sprites PNG indexés 16 couleurs.
- **Vérification** : `arm-none-eabi-size` / fichier `.map` du build pour suivre l'occupation ROM et EWRAM à chaque PR ; test `test/save.c` pour les tailles de sauvegarde (§7).
- **Décision** : garder toutes les espèces au début (les noms FR sont déjà traduits dans la base) ; surveiller la taille ; si on approche ~28 Mo, désactiver les générations non utilisées.

---

## 6. Tests

### 6.1 Système de tests expansion (`make check`)
- **Problème résolu** : tests unitaires/intégration exécutés **dans une ROM de test** sous émulateur headless.
- **Mécanique** (`Makefile` l.362–365) : build `pokeemerald-test.elf` (`ld_script_test.ld`), patch `gTestRunnerHeadless=1` via `tools/patchelf`, exécution par `tools/mgba-rom-test-hydra` (parallélise, compilé depuis `tools/mgba-rom-test-hydra/main.c`) sur `tools/mgba/mgba-rom-test` (binaire Linux mGBA fourni, source : <https://github.com/mgba-emu/mgba/tree/dbffb46c4e7d2e7a2cbed7c3488cece4c2176d4c>). Timeout par test : 60 s (`test/test_runner.c`, `TIMEOUT_SECONDS`) ⇒ une boucle infinie devient un `TIMEOUT` au lieu de bloquer la CI.
- **Commandes** (`docs/tutorials/how_to_testing_system.md`) : `make check -j` ; filtre `make check TESTS="Spikes"` ; build seul `make pokeemerald-test.elf TESTS="..."`.
- **Syntaxe combat** : `SINGLE_BATTLE_TEST("nom") { GIVEN { ASSUME(...); PLAYER(SPECIES_X) { Moves(...); } OPPONENT(...); } WHEN { TURN { MOVE(player, MOVE_X); } } SCENE { ANIMATION(...); MESSAGE("..."); HP_BAR(...); NOT STATUS_ICON(...); } THEN { EXPECT_EQ(...); } }` ; aussi `DOUBLE_BATTLE_TEST`, `AI_SINGLE_BATTLE_TEST` + `AI_FLAGS(...)`, `PARAMETRIZE`, `PASSES_RANDOMLY`, `KNOWN_FAILING`, `WITH_CONFIG(B_..., GEN_x)`, `FLAG_SET`.
  - ⚠️ `MESSAGE("...")` compare le texte affiché : dans ce dépôt traduit, les messages sont **en français** ; nos tests doivent utiliser les chaînes FR.
- **Applicabilité** : 100 % headless, déjà outillé. Coût : build test complet long (des milliers de tests amont) → filtrer avec `TESTS=`.

### 6.2 Tests de scripts overworld (`include/test/overworld_script.h`, `test/script.c`)
- `OVERWORLD_SCRIPT(cmd; cmd; ...)` compile un script inline (les macros de `asm/macros/event.inc` sont disponibles) ; `RUN_OVERWORLD_SCRIPT(...)` l'exécute en contexte immédiat ; `Script_HasNoEffect(script)` vérifie l'absence d'effet visible.
- Exemple (style `test/pokemon.c`) :
  ```c
  TEST("Mon événement donne la récompense une seule fois")
  {
      RUN_OVERWORLD_SCRIPT(
          setflag FLAG_HACK_MET_X;
          checkflag FLAG_HACK_MET_X;
      );
      EXPECT(FlagGet(FLAG_HACK_MET_X));
  }
  ```
  On peut aussi appeler un **script réel par son label** (`RunScriptImmediately(MyMap_EventScript_Foo)` après `extern const u8 MyMap_EventScript_Foo[];`) tant qu'il n'utilise que des commandes « immédiates ».
- **Limite** : « The overworld is not available » — `givemon`, flags, vars, objets du sac OK ; **pas** `addobject`, `applymovement`, `msgbox`/`waitstate`, warps. Ces aspects se testent par émulation (§6.4).
- **Test de largeur de texte** : `test/text.c` utilise `GetStringWidth(fontId, str, 0)` avec `EXPECT_LE(..., widthPx)` — modèle direct pour un test « toutes les lignes de nos textes ≤ 208 px ».

### 6.3 Options d'automatisation d'émulateur headless
| Option | Headless ? | Disponibilité ici | Verdict |
|---|---|---|---|
| `mgba-rom-test` (fourni) | Oui | Présent | Pour `make check` ; sort sur un SWI/registre (`-S`, `-R`) — pas d'entrées scriptées. |
| **mGBA `mgba-headless` + Lua (`--script FILE`)** | **Oui, natif** | À compiler depuis la branche `master` de mGBA (`-DBUILD_HEADLESS=ON`, `ENABLE_SCRIPTING`, `USE_LUA`) — option ajoutée après 0.10 (CHANGES « 0.11.0 (Future) » : *"Headless" frontend for running tests, automation, etc.* et *Add support for running scripts at startup* ; <https://raw.githubusercontent.com/mgba-emu/mgba/master/CHANGES>, <https://raw.githubusercontent.com/mgba-emu/mgba/master/src/platform/headless-main.c>) | **Retenu** pour les tests de bout en bout. |
| mgba-qt 0.10.2 (apt) + Lua sous `xvfb-run` | Pseudo | apt OK | Scripting Lua introduit en 0.10, lancé depuis le menu *Tools → Scripting* (<https://mgba.io/docs/scripting.html>, <https://mgba.io/2022/10/11/mgba-0.10.0>) ; pas d'exécution au démarrage en 0.10 ⇒ fragile. Écarté. |
| libmgba C API (`libmgba-dev` 0.10.2 ou build master) | Oui | apt OK | Contrôle total (core->runFrame, setKeys, mémoire) mais à écrire en C. Solution de repli si Lua insuffisant. |
| Bindings Python `mgba` (PyPI 0.10.2) | Oui | Roues **cp310/cp311 uniquement**, Python ici = 3.13 ; auteur non renseigné (<https://pypi.org/project/mgba/>) ; `BUILD_PYTHON` existe dans le CMake mGBA | Écarté (version Python incompatible, provenance incertaine). |
| BizHawk | Non | Linux = Mono, « work-in-progress… not ready for anything that needs accuracy », Lua manquant sur certaines builds (<https://tasvideos.org/HomePages/YoshiRulz/BizHawk>) | **Non faisable.** |

### 6.4 Recette `mgba-headless` + Lua (proposée)
Build (une fois, hors dépôt du hack) :
```sh
git clone --depth 1 https://github.com/mgba-emu/mgba /opt/src/mgba
apt-get install -y liblua5.4-dev libpng-dev zlib1g-dev   # si nécessaire
cmake -S /opt/src/mgba -B /opt/build/mgba -DBUILD_HEADLESS=ON -DBUILD_QT=OFF -DBUILD_SDL=OFF \
      -DUSE_LUA=ON -DENABLE_SCRIPTING=ON -DCMAKE_BUILD_TYPE=Release
cmake --build /opt/build/mgba -j4   # produit mgba-headless
```
API Lua disponible (vérifiée dans `src/core/scripting.c` de mGBA) : `emu:read8/16/32`, `emu:readRange`, `emu:write8/16/32`, `emu:setKeys/addKey/clearKey`, `emu:runFrame`, `emu:currentFrame`, `emu:saveStateFile/loadStateFile/saveStateSlot`, `emu:screenshot(path)`, `emu:reset`, `emu:loadSaveFile` ; `callbacks:add("frame", fn)`, `console:log`. Docs : <https://mgba.io/docs/scripting.html>.

Squelette de scénario :
```lua
-- run: mgba-headless --script scenario.lua pokeemerald.gba
local A = 0x01  -- C.GBA_KEY.A
local f = 0
local steps = { {frame=600, keys=A}, {frame=620, keys=0} }   -- inputs horodatés
callbacks:add("frame", function()
  f = f + 1
  for _, s in ipairs(steps) do if s.frame == f then emu:setKeys(s.keys) end end
  if f == 3000 then
    emu:screenshot("out/end.png")
    local v = emu:read16(VAR_ADDR)        -- adresse calculée depuis l'ELF
    console:log(string.format("RESULT var=%d", v))
    os.exit(v == 2 and 0 or 1)            -- code de sortie lisible par la CI
  end
end)
```
- **Adresses** : `arm-none-eabi-nm pokeemerald.elf | grep -E 'gSaveBlock1Ptr|gMain$|sGlobalScriptContextStatus'` (les symboles `static` apparaissent aussi). `gSaveBlock1Ptr` est un pointeur : lire l'adresse puis ajouter l'`offsetof` des champs (`flags`, `vars`, `location`, `pos`), calculé par un petit fichier C compilé avec `arm-none-eabi-gcc -I include` (ex. `asm(".equ OFF_FLAGS, %c0" :: "i"(offsetof(struct SaveBlock1, flags)));` puis lecture du `.s`).
- **Partir d'un savestate** (`--savestate` / `emu:loadStateFile`) positionné devant l'événement plutôt que de rejouer l'intro. Attention : un savestate est lié au build (adresses) — les régénérer après changement de layout mémoire ; préférer une **sauvegarde .sav** + `Quickstart`/menu debug pour se placer.
- **Détection de softlock** (heuristiques combinables) : (a) la position joueur (`gSaveBlock1Ptr->pos`) et la map ne changent pas pendant N s malgré des entrées directionnelles ; (b) `sGlobalScriptContextStatus` reste « running » plus de N s sans entrée attendue ; (c) captures d'écran successives identiques (hash) pendant N s alors qu'on presse A/B ; (d) timeout global du scénario. Échec ⇒ code ≠ 0 + capture.
- **Logs** : `DebugPrintf` est actif hors release (`LOG_HANDLER_MGBA_PRINT`, `include/config/general.h`) → instrumenter un script C en debug et lire la sortie de l'émulateur.
- **Save/load** : scénario « faire l'événement → sauvegarder via menu → `emu:reset` → charger → vérifier flag/var » ; complété par `test/save.c` (tailles des SaveBlocks).

---

## 7. Pièges fréquents

| Piège | Symptôme | Prévention / détection |
|---|---|---|
| **Débordement SaveBlock** | Build échoue (`STATIC_ASSERT(sizeof(struct SaveBlock1) <= …, SaveBlock1FreeSpace)` dans `src/save.c` l.80–83) | Ne pas ajouter de champs à la légère ; réutiliser `FLAG_UNUSED`/`VAR_UNUSED`. Fixer les tailles attendues dans `test/save.c` (`T_SAVEBLOCK1_SIZE 15568`, `T_SAVEBLOCK2_SIZE 3884`, `T_POKEMONSTORAGE_SIZE 34144`) : le test casse si la structure bouge (compatibilité des sauvegardes). Espace supplémentaire possible (pieds de secteurs) : <https://github-wiki-see.page/m/pret/pokeemerald/wiki/Reuse-filler-save-space-for-Variables-and-Flags> — à n'utiliser qu'en dernier recours. |
| **Débordement EWRAM/IWRAM** | Linker : « region `EWRAM' overflowed » | Pas de gros buffers globaux ; utiliser `AllocZeroed`/`Free`. |
| **ROM > 32 Mo** | « region `ROM' overflowed » | §5. |
| **Réutilisation de flags/vars** | Événements qui se déclenchent/disparaissent ailleurs | Registre des flags du hack (une section de `flags.h` + doc) ; `grep` avant usage ; ne jamais réutiliser un flag vanilla. |
| **Événements vanilla qui se redéclenchent** | Cutscenes vanilla (`ON_FRAME_TABLE`, coord_events, `VAR_*_STATE`) qui se lancent sur nos maps modifiées | Lors de la modification d'une map vanilla, relire `map_script`/`coord_events`, neutraliser via la var d'état plutôt que supprimer à moitié ; `grep -rn MAP_<X> src data` (références C, ex. `src/field_specials.c`). |
| **Insertion au milieu des listes** | object local IDs, `dest_warp_id`, numéros de map décalés ; saves cassées | Toujours **ajouter en fin** (objets, warps, maps dans un groupe). |
| **Texte qui déborde** | Lettres coupées / hors boîte | Poryscript `format()` ; test `GetStringWidth` ; linter. |
| **Caractère absent de la charmap** | Erreur `preproc` au build (« unknown character ») | Liste §2.7. |
| **Collisions/élévations** | Joueur bloqué, marche sur l'eau, traverse les murs | Valider le blockdata (§9) : bords de map, cases de warp/arrivée passables, cohérence élévation 3 autour de l'eau. |
| **Objets > 16 visibles** | Objets qui n'apparaissent pas | `OBJECT_EVENTS_COUNT 16`. |
| **Scripts d'en-tête non immédiats** | Freeze au chargement | Pas de `msgbox`/`applymovement` dans `ON_TRANSITION/ON_LOAD/ON_RESUME`. |
| **Map connectée à une map supprimée** | Gel du jeu | `how_to_delete_vanilla_maps.md` ; mapjson ignore les connexions vers des maps absentes. |
| **Configs à 0** | Fonction activée mais inopérante (DexNav, difficulté, etc.) | Activer une config ⇒ lui attribuer un flag/var libre. |

---

## 8. Ressources communautaires

| Ressource | Usage | URL |
|---|---|---|
| Doc RHH (expansion) | Référence principale (= `docs/` local) | <https://rh-hideout.github.io/pokeemerald-expansion/> |
| Dépôt expansion / issues / changelogs | Bugs connus, migrations (`migration_scripts/`) | <https://github.com/rh-hideout/pokeemerald-expansion> |
| Discord RHH (ROM Hacking Hideout) | Support, `#expansion-help` ; lien depuis le README amont. Pas accessible depuis le conteneur. | via README de <https://github.com/rh-hideout/pokeemerald-expansion> |
| Wiki pret pokeemerald | Tutoriels décomp (scripts, save, astuces) | <https://github.com/pret/pokeemerald/wiki> (miroir <https://code.heni.lol/decomp/emerald/wiki/Tutorials>) |
| PokéCommunity | Forum (tutoriel de scripting décomp, fils d'aide) | <https://www.pokecommunity.com/threads/scripting-tutorial.416800/> |
| **Team Aqua's Asset Repo** | Assets libres pour hacks Gen 3 décomp : trainer front/back sprites, overworld trainer/objet/Pokémon, tilesets, battle backgrounds, UI, audio. « All assets are both free to use and edit by default » ; **créditer l'auteur** (README par dossier). | <https://github.com/TeamAquasHideout/Team-Aquas-Asset-Repo> |
| Poképédia | Noms FR officiels (espèces, lieux, objets, attaques) | <https://www.pokepedia.fr/Liste_des_Pokémon> (bloqué ici ; repli : <https://bulbapedia.bulbagarden.net/wiki/List_of_French_Pok%C3%A9mon_names>) |
| Porymap (manuel) | Sémantique collision/élévation, événements | <https://huderlem.github.io/porymap/manual/> (sources `docsrc/manual/*.rst` sur raw.githubusercontent) |
| Poryscript | Langage de script | <https://github.com/huderlem/poryscript> |
| Porytiles | Compilation de tilesets | <https://github.com/grunt-lucas/porytiles> |
| mGBA | Émulateur, scripting Lua, headless | <https://github.com/mgba-emu/mgba>, <https://mgba.io/docs/scripting.html> |

Assets Team Aqua : vérifier pour chaque asset palette (16 couleurs indexées), dimensions (OW 16×32/32×32 ; trainer front 64×64), et la mention de crédit ; tenir un `CREDITS` du hack.

---

## 9. Décisions recommandées pour ce projet

1. **Outils adoptés**
   - Build/test : `make` et `make check TESTS="..."` (déjà fonctionnels headless avec `tools/mgba/mgba-rom-test`).
   - **Poryscript 3.6.1** (binaire Linux GitHub, figé dans `tools/poryscript/` avec `font_config.json`/`command_config.json`, règle `%.pory → %.inc` dans le Makefile) **pour tous les nouveaux scripts** ; `.inc` brut pour retoucher les scripts vanilla.
   - **mGBA `mgba-headless` (build master, Lua)** pour les tests de bout en bout ; libmgba en repli.
   - **Pas** de Porymap, Tilemap Studio, BizHawk, bindings Python mGBA dans le conteneur. Porytiles seulement si un nouveau tileset est nécessaire.
2. **Édition de maps** : édition directe de `map.json` (événements ajoutés **en fin de tableau**, `local_id` systématique, warps par paires), `map.bin` via un utilitaire Python (encodage `metatile | collision<<10 | elevation<<12`), nouvelles maps dérivées par copie d'une map vanilla aux mêmes tilesets, ajout **en fin** de groupe dans `map_groups.json` + `.include` dans `data/event_scripts.s`.
3. **Linter maison** `tools/hack_lint.py` (stdlib Python uniquement), lancé avant chaque build/PR : JSON valide ; x/y dans les bornes du layout ; taille de `map.bin` = w×h×2 ; `dest_map` existe et `dest_warp_id` < nombre de warps de la destination ; labels `script` définis dans un `.inc`/`.pory` ; flags/vars référencés définis et non utilisés par une autre map du hack ; ≤ 64 objets ; connexions réciproques ; caractères des `.string` présents dans `charmap.txt` ; largeur de ligne estimée ≤ 208 px avec les largeurs de `font_config.json`.
4. **Conventions de scripting** : une `VAR_<ARC>_STATE` par arc narratif ; flags persistants pris dans `FLAG_UNUSED_*` et renommés avec un préfixe du hack, registrés dans un tableau de doc ; `FLAG_TEMP_*`/`VAR_TEMP_*` pour l'état local ; toute cutscene `ON_FRAME_TABLE`/coord_event modifie sa var de déclenchement ; aucun script bloquant dans les map scripts immédiats.
5. **Textes** : 2 lignes/boîte, `\n` puis `\l`, `\p` entre boîtes ; ~35 caractères/ligne max ; pas de `« »` ni `æ` ; pas d'espace avant la ponctuation haute (convention vanilla FR) ; noms officiels vérifiés sur Poképédia.
6. **Dresseurs** : `trainers.party` avec `Level` et `IVs` explicites ; `Basic Trainer` sur les routes, `Smart Trainer` + `Ace Pokemon` pour champions/rival ; trainer slides pour les combats-clés ; ni party pools ni difficulté en v1.
7. **Rencontres** : `wild_encounters.json` vanilla étendu (slots exacts) ; time-of-day et DexNav désactivés tant que non requis.
8. **Taille/sauvegarde** : suivre la taille ROM/EWRAM à chaque build ; mettre à jour `test/save.c` avec nos tailles de SaveBlock et le garder vert (compatibilité des sauvegardes entre versions du hack).
9. **Stratégie de test (pyramide)** : (a) linter statique à chaque changement ; (b) tests `TEST()` + `RUN_OVERWORLD_SCRIPT` pour la logique de flags/vars/dons, et test `GetStringWidth` sur nos textes ; (c) `SINGLE_BATTLE_TEST`/`AI_SINGLE_BATTLE_TEST` pour les combats scénarisés atypiques ; (d) scénarios `mgba-headless` + Lua (entrées horodatées, lecture des flags/vars via adresses issues de l'ELF, détection de softlock par position/écran figés, captures PNG en artefact, cycle sauvegarde→reset→chargement).
10. **Assets** : Team Aqua's Asset Repo pour sprites dresseurs/OW avec crédits tenus à jour ; pas de création graphique par l'IA.
