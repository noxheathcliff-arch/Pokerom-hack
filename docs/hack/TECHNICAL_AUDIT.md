# TECHNICAL_AUDIT.md — Audit technique de la base

> Base : pokeemeraude-expansion **1.16.4** (traduction FR de pokeemerald-expansion), upstream `1b077e5c`, import `819d7b3`.
> Auteur : Architecte technique (Phase A). Date : 2026-10-13.
> Légende : **[V]** = vérifié dans le code / la build ; **[I]** = inféré (à confirmer).

---

## 0. Chiffres clés (décisionnels)

| Élément | Valeur | Source |
|---|---|---|
| Build de référence (upstream non modifié, `make -j4`) | EXIT 0, ~4 min 15 s (4 cœurs) | `/home/user/build_baseline.log` [V] |
| EWRAM | 226 584 o / 256 Kio (**86.43 %**) → **35 560 o libres** | log l.33914 [V] |
| IWRAM | 28 376 o / 32 Kio (**86.60 %**) → **4 392 o libres** | log l.33915 [V] |
| ROM | 26 549 676 o / 32 Mio (**79.12 %**) → **≈ 6,68 Mio libres** | log l.33916 [V] |
| Espèces activées | **1 571** entrées `gSpeciesInfo` avec `baseHP>0` (sur 1 572 ID hors NONE) ; les **1 025** espèces nationales Gen 1–9 + toutes les formes (Méga, Gmax, régionales…) ; seule désactivée : `SPECIES_LUGIA_SHADOW` (1435) | lecture de `gSpeciesInfo` dans `upstream/pokeemeraude.gba` (0x086EC70C, 1574 × 264 o) [V] |
| Flags libres (`FLAG_UNUSED_*`, branche Émeraude) | **373** définis, dont 0x71 encore lu par CaveOfOrigin → **372 réellement libres** (+ ~30 « leftovers » R/S recyclables) | `include/constants/flags.h` [V] |
| Vars libres (0x4000–0x40FF) | **55** (22 `VAR_UNUSED_*` + 33 vars d'état nommées mais marquées « Unused Var », aucune référencée) | `include/constants/vars.h` [V] |
| Flags dresseurs libres | **9** (855 dresseurs / 864 slots, 0x500–0x85F) | `include/constants/opponents.h:862-868` [V] |
| Sauvegarde libre | SB1 **376 o**, SB2 **120 o**, SB3 **1 623 o**, PC **1 568 o** (+ jusqu'à 3 790 o libérables via `config/save.h`) | `sizeof` calculés avec arm-none-eabi-gcc [V] |
| ROM de base / baserom | **Aucune requise** | Makefile [V] |

---

## 1. Architecture du dépôt [V]

| Dossier | Rôle |
|---|---|
| `src/` | Code C du moteur (≈ tout le jeu). `src/data/` = données C (espèces, objets, attaques, dresseurs `.party`, rencontres JSON…). |
| `include/` | En-têtes ; `include/config/*.h` = interrupteurs de fonctionnalités ; `include/constants/*.h` = constantes (flags, vars, espèces, objets…). |
| `data/` | Assembleur de données : scripts d'événements (`event_scripts.s`, `data/scripts/*.inc`), cartes (`data/maps/<Carte>/map.json + scripts.inc`), layouts (`data/layouts/`), textes partagés (`data/text/*.inc`), scripts de combat. |
| `asm/macros/` | Macros GNU as : `event.inc` (393 macros de script), `battle_script.inc`, etc. |
| `graphics/`, `sound/` | PNG/PAL convertis par `gbagfx`, MIDI → `mid2agb`, WAV → `wav2agb`. |
| `tools/` | Outils hôtes compilés automatiquement par le Makefile (voir TOOLS_AND_COMMANDS.md). |
| `test/` | 959 fichiers `.c`, ≈ 6 000 tests (batailles, IA, objets, save…), lancés par `make check`. |
| `dev_scripts/`, `migration_scripts/` | Scripts Python d'entretien (ex. `dev_scripts/delete_frlg_maps.py`). |
| `docs/` | Doc upstream (mdBook) + `docs/tutorials/*.md` (très utile : trainer pools, followers, DNS, OWE, VS Seeker, testing…). `docs/hack/` = docs du projet. |

Fichiers générés (gitignorés, recréés par `make generated`) : `include/constants/{map_groups,layouts,map_event_ids,heal_locations,region_map_sections,wild_encounter,script_commands}.h`, `src/data/{trainers,trainers_frlg,battle_partners,debug_trainers,heal_locations,map_group_count,wild_encounters,tutor_moves}.h`, `src/data/pokemon/teachable_learnsets.h`, `data/maps/*/{header,events,connections}.inc`, `data/maps/{groups,headers,events,connections}.inc`, `data/layouts/layouts*.inc`.

---

## 2. Production de la ROM [V]

- **Aucune ROM de base n'est nécessaire.** Le Makefile ne référence aucun `baserom.gba` ; la ROM est entièrement compilée depuis les sources. Les seuls `.gba` du dépôt sont `data/mb_berry_fix.gba`, `data/mb_colosseum.gba`, `data/mb_ereader.gba` (binaires *multiboot* inclus dans les données, pas une base).
- `rom.sha1` ne sert qu'à `make compare` (non pertinent en build moderne ; SHA1 ≠ attendu = normal).
- **La ROM US jointe par l'utilisateur n'est pas arrivée : cela ne bloque rien** (ni build, ni tests). Seule conséquence : impossible de comparer/contrôler l'empreinte de cette ROM.
- Chaîne (Makefile l.540–590) : `.c` → `cc1` (`-O2 -mthumb -Werror …`) → `.o` ; `.s/.inc` → `preproc` (charmap) → `cpp` → `preproc` → `as` ; link `arm-none-eabi-ld -T ld_script_modern.ld --gc-sections` → `pokeemeraude.elf` → `gbafix` (en-tête) → `objcopy -O binary` → `pokeemeraude.gba` → `gbafix -p` (padding, taille fichier 32 Mio).
- Sorties : `pokeemeraude.gba/.elf/.map` (build normal), `pokeemeraude-release.gba` (`make release`, LTO + `-DRELEASE` + NDEBUG), `pokeemeraude-test.elf` (`make check`). Objets dans `build/emeraude[-release|-debug|-test]/`.

### En-tête ROM [V]
Makefile l.1–5 et l.24–26 :
```
TITLE     ?= POKEMON EMER     # 12 car. max
GAME_CODE ?= BPEF             # 4 car. (B=… P=Pokémon E=Emerald F=Français)
MAKER_CODE := 01              # 2 car.
REVISION   := 0
```
Écrit par `tools/gbafix/gbafix $@ -t"$(TITLE)" -c$(GAME_CODE) -m$(MAKER_CODE) -r$(REVISION)` (l.353, 577, 584). `src/rom_header.s` ne contient que des espaces réservés. `GAME_LANGUAGE = LANGUAGE_FRENCH` (`include/constants/global.h:79`) ; en-tête RHH (`src/rom_header_rhh.c`) expose version/NUM_SPECIES.

**Changer titre/code** : soit éditer l.2–3 du Makefile, soit `make TITLE="MON HACK" GAME_CODE=XXXX` (les `?=` sont surchargeables ; `MAKER_CODE` aussi en ligne de commande).
**Risque [V/I]** : mGBA (et la plupart des émulateurs) choisit le type de sauvegarde (Flash 128 Ko) et l'**horloge RTC** via une table indexée par game code ; la table de `mgba-rom-test` contient `BPEE BPEF BPED BPES BPEI BPEJ BPEP` [V, `strings`]. Un code inédit peut perdre l'activation automatique de la RTC (cycle jour/nuit, baies, marées) [I]. **Recommandation : garder `BPEF` (ou un code de la famille BPE?) et ne changer que `TITLE`**, ou tester explicitement RTC + save sur émulateur cible.

### Modes Émeraude / FRLG [V]
- Makefile l.7–21 : `make firered` / `make leafgreen` (ou `BUILD=firered`) → `-DFIRERED`, `MAP_VERSION=firered`, code BPRF/BPGF. Par défaut : `EMERALD`, `MAP_VERSION=emerald`.
- `IS_FRLG` (`include/constants/global.h:67-77`) pilote ~67 fichiers.
- **Les données FRLG ne sont PAS liées dans la build Émeraude** : `mapjson groups` exclut les cartes `region != REGION_HOENN` (`tools/mapjson/mapjson.cpp:743-746`), les layouts `layout_version: frlg` sont remplacés par `NULL` (l.783-785, 841), les scripts FRLG sont sous `.if IS_FRLG` (`data/event_scripts.s:603`), tilesets FRLG sous `#if IS_FRLG` (`src/data/tilesets/graphics.h:1602`, `headers.h:31`). Mais leurs PNG sont **convertis** pendant la build (temps de build, pas d'espace ROM).
- Volumétrie : 939 cartes (518 Hoenn, 421 Kanto), 785 layouts (441 emerald, 344 frlg), 75 groupes.
- Option : `python3 dev_scripts/delete_frlg_maps.py` (supprime cartes/layouts `_Frlg` et nettoie `event_scripts.s`) — accélère la build et simplifie Porymap ; **décision à prendre par l'orchestrateur** (diff énorme, fusion upstream plus difficile).

---

## 3. Pipeline cartes [V]

- Par carte : `data/maps/<Nom>/map.json` (id `MAP_*`, `layout`, `music`, `region`, `region_map_section`, `weather`, `map_type`, flags cycling/running/escaping, `battle_scene`, `connections[]`, `object_events[]`, `warp_events[]`, `coord_events[]`, `bg_events[]`) + `scripts.inc` (scripts **et** textes de la carte).
- `data/maps/map_groups.json` : ordre des groupes et des cartes (détermine `MAP_GROUP/MAP_NUM`).
- `data/layouts/layouts.json` : `id`, `name`, `width/height`, `primary_tileset`, `secondary_tileset`, `border_filepath`, `blockdata_filepath` (`.bin` = u16 par bloc), `layout_version`.
- Règles : `map_data_rules.mk`. `mapjson map emerald` → `header.inc/events.inc/connections.inc` par carte ; `mapjson groups` → `groups.inc, headers.inc, events.inc, connections.inc` + `include/constants/map_groups.h` ; `mapjson layouts` → `layouts.inc, layouts_table.inc, layouts.h` ; `mapjson event_constants` → `map_event_ids.h` (`LOCALID_*`).
- **Ajout de carte** : dossier + `map.json` + `scripts.inc`, entrée dans `map_groups.json`, layout dans `layouts.json` (+ `.bin`), **ligne `.include "data/maps/<Nom>/scripts.inc"` dans `data/event_scripts.s`** (fait automatiquement par Porymap, à la main sinon), `"region": "REGION_HOENN"` (sinon exclue !). Rencontres : `src/data/wild_encounters.json` (→ `tools/wild_encounters/wild_encounters_to_header.py`). Points de soin : `src/data/heal_locations.json`. Région/MAPSEC : `src/data/region_map/region_map_sections.json`.
- Début de partie : `src/new_game.c:136-143` (`WarpToTruck` → `MAP_INSIDE_OF_TRUCK`) et `NewGameInitData` l.161.

## 4. Pipeline dresseurs [V]

- Source : `src/data/trainers.party` (855 blocs `=== TRAINER_X ===`), format type Showdown documenté en tête du fichier (l.1–70). Champs dresseur : `Name, Class, Pic, Back Pic, Gender, Music, Items, Battle Type / Double Battle, AI, Mugshot, Starting Status, Multi Party, Difficulty, Party Size, Pool Rules, Pool Pick Functions, Pool Prune, Copy Pool, Macro`. Champs Pokémon : `Espèce (Surnom) (M/F) @ Objet`, `Level, Ability, IVs, EVs, Ball, Happiness, Nature, Shiny, Dynamax Level, Gigantamax, Tera Type, Tags`, puis `- Attaque` (max 4, en dernier).
- Règle : `trainer_rules.mk` → `cpp -traditional-cpp | tools/trainerproc/trainerproc -o src/data/trainers.h`. Aussi `battle_partners.party`, `debug_trainers.party`, `trainers_frlg.party`.
- IA vanilla : 640× `Check Bad Move`, 173× `Basic Trainer`, quelques `Risky`/`Force Setup First Turn` ; jamais `Smart Trainer` (`include/constants/battle_ai.h:46-49`). Ex. Roxanne : `src/data/trainers.party:4793` (IV 12, niv. 12-15, IA Basic).
- Constantes `TRAINER_*` : `include/constants/opponents.h` (TRAINERS_COUNT_EMERALD 855, MAX 864 ; chaque dresseur = 1 flag ; augmenter MAX coûte des flags/sauvegarde).
- Difficulté : `Difficulty: Easy|Normal|Hard` par bloc (`include/constants/difficulty.h`), sélectionnée via `B_VAR_DIFFICULTY` (=0 → toujours Normal).

## 5. Texte, charmap, limites [V]

- `charmap.txt` : accents FR complets (À Â Ç È É Ê Ë Î Ï Ô Œ Ù Û à â ç è é ê ë î ï ô œ ù û, + Ä Ö Ü ä ö ü ñ ¿ ¡ … “ ” ‘ ’ ♂ ♀). **Pas de « » guillemets français** (absents de la charmap → erreur preproc ; utiliser “ ”).
- Contrôles : `\n` (ligne 2), `\l` (défilement), `\p` (nouveau paragraphe), `$` fin de chaîne (implicite en fin de `.string`). Placeholders : `{PLAYER}` (≤ 7 car., `PLAYER_NAME_LENGTH`), `{RIVAL}`, `{STR_VAR_1..3}`, `{KUN}`, `{COLOR …}`, `{FONT_*}`, `{PAUSE n}`, `{PAUSE_UNTIL_PRESS}`, `{SPEAKER}`, `{PKMN}`, `{LV}`.
- Boîte de dialogue : fenêtre 27 tuiles = **216 px** (`src/menu.c:80-90`), police `FONT_NORMAL` à chasse variable (`src/fonts.c:148`, minuscules 5–6 px, majuscules 6 px, espace 3 px) → **≈ 35–38 caractères/ligne, 2 lignes visibles par boîte**. Mesure sur le texte FR vanilla : p99 = 208 px, max ≈ 216 px. **Règle projet : ≤ 208 px par ligne** ; compter `{PLAYER}` = 42 px, `{STR_VAR_x}` ≈ 60 px. Script de mesure : voir TOOLS_AND_COMMANDS.md §5.
- Noms : `POKEMON_NAME_LENGTH 12`, `TRAINER_NAME_LENGTH 10`.
- Textes de combat : retour à la ligne automatique (`BreakStringAutomatic`, `src/battle_message.c:3674`) ; **pas** pour les dialogues terrain.
- Boîte de nom (namebox) : macro `setspeaker` (`asm/macros/event.inc:2853`), config `include/config/name_box.h`.

## 6. Macros de script (`asm/macros/event.inc`, 393 macros) [V]

Les plus utiles : `msgbox` (l.2140 ; types `MSGBOX_NPC/DEFAULT/SIGN/YESNO/AUTOCLOSE`), `giveitem` (2149), `givemon` (1060, IV/EV/nature/ball/shiny optionnels), `createmon` (1122), `trainerbattle_single/double/rematch/no_intro/two_trainers` (786–825), `settrainerflag/cleartrainerflag` (857/863), `setwildbattle`+`dowildbattle` (1644/1655), `warp` (477), `applymovement` (643), `setflag/setvar` (338/155), `goto_if_set`, `call_if_eq` (1997/2060), `multichoice` (946), `dynmultichoice` (1966), `checkitem` (590), `checkspecies` (2567), `setrespawn` (1467), `callnative` (273), `special` (296), `setdifficulty/getdifficulty/increasedifficulty` (2595–2609), `setfollowernpc` (2769), `hidefollower` (2590), `vsseeker_rematchid` (2873), `setspeaker` (2853). Table des opcodes : `data/script_cmd_table.inc` → `include/constants/script_commands.h` (généré).

## 7. Flags et variables [V]

- **Flags** (`include/constants/flags.h`, branche Émeraude l.52–2437 ; FRLG via `flags_frlg.h`) :
  - temp 0x00–0x1F (remis à zéro à chaque carte ; 0x5–0xD, 0xF, 0x10 libres) ;
  - histoire/objets/cachés/HIDE 0x20–0x4FF ; dresseurs 0x500–0x85F ; système 0x860–0x91F ; quotidiens 0x920–0x95F ; spéciaux 0x4000–0x407F (non sauvegardés).
  - Libres (`FLAG_UNUSED_*`) : **251** en 0x20–0x4FF, **70** en système, **52** quotidiens. Plages contiguës : `0x20–0x4F (48)`, `0x264–0x2BB (88)`, `0x493–0x4EF (93)`, `0x8E5–0x91F (59)`, `0x935–0x95F (43)` ; isolés : 0x54-55, 0x68, 0xE9, 0x1AA-1AB, 0x1DA, 0x1DE-1E3, 0x2D9, 0x468, 0x470, 0x472, 0x479, 0x4F9-4FA, 0x4FF, 0x863, 0x881-887, 0x88E-88F, 0x8E3, 0x923-929, 0x933. **Ne pas utiliser 0x71** (lu par `data/maps/CaveOfOrigin_*/scripts.inc:6`). Attention : les flags « quotidiens » sont remis à zéro chaque jour (`DAILY_FLAGS_START`, l.1573).
  - Recyclables (leftovers R/S, ~30) : 0x64, 0x96, 0xC2, `FLAG_WONDER_CARD_UNUSED_1..17` (0x13D–0x14D, « référencés mais jamais posés »), 0x339, 0x409, 0x465–0x467, 0x46D, SYS 0x897–0x899.
- **Vars** (`include/constants/vars.h`) : 0x4000–0x400F temp ; 0x4010–0x40FF sauvegardées ; 0x8000–0x8015 spéciales. Libres : `VAR_UNUSED_0x404E, 0x4083, 0x408B, 0x4091, 0x409B, 0x409D, 0x40A1, 0x40A8, 0x40B8, 0x40BB, 0x40DB, 0x40DC, 0x40E5, 0x40F7–0x40FF` (22) + 33 vars d'état marquées « Unused Var » (VAR_DEWFORD_TOWN_STATE, VAR_ROUTE102..134_STATE partiellement, etc. — vérifiées non référencées).
- Les fonctionnalités de config qui demandent un flag/var (level cap var, DexNav, Tera Orb, Exp. Share, VS Seeker, difficulté, no-whiteout…) valent **toutes 0** : il faudra leur attribuer des `FLAG_UNUSED_*`/`VAR_UNUSED_*` renommés.

## 8. Structure narrative Hoenn (à remplacer/réutiliser) [V]

| Jalon | Flag / var | Où |
|---|---|---|
| Intro camion → maison → horloge | `VAR_LITTLEROOT_INTRO_STATE` (0x4092, états 1–7) | `data/maps/LittlerootTown/scripts.inc:12-20` |
| Bourg | `VAR_LITTLEROOT_TOWN_STATE` (0x4050), `VAR_LITTLEROOT_RIVAL_STATE`, `VAR_LITTLEROOT_HOUSES_STATE_MAY/BRENDAN` | idem l.6-30 |
| Starter / sauvetage Birch | `FLAG_SYS_POKEMON_GET`, `FLAG_RESCUED_BIRCH` (0x52), `VAR_STARTER_MON` (0x4023) | `Route101/scripts.inc:221-222` |
| Pokédex | `FLAG_ADVENTURE_STARTED` (0x74), `FLAG_SYS_POKEDEX_GET`, `VAR_BIRCH_LAB_STATE` | `LittlerootTown_ProfessorBirchsLab/scripts.inc:519,546` |
| Chaussures de course | `FLAG_SYS_B_DASH` | `LittlerootTown/scripts.inc:890` |
| PokéNav | `FLAG_SYS_POKENAV_GET` | `RustboroCity_DevonCorp_3F/scripts.inc:55` |
| Badges 1→8 | `FLAG_BADGE01_GET`…`08` (0x867–0x86E) ; `FLAG_DEFEATED_*_GYM` (0x4F0–0x4F7) | Rustboro_Gym:19, Dewford_Gym:151, Mauville_Gym:94, Lavaridge_Gym_1F:62, Petalburg_Gym:380, Fortree_Gym:35, Mossdeep_Gym:71, Sootopolis_Gym_1F:98 |
| Arène de Norman | `VAR_PETALBURG_GYM_STATE` (0x4085) | |
| Équipes Aqua/Magma, légendaires | `VAR_WEATHER_INSTITUTE_STATE`, `VAR_MT_PYRE_STATE`, `FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT` (0x6F), `FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN` (0x81), `VAR_SEAFLOOR_CAVERN_STATE`, `VAR_SOOTOPOLIS_CITY_STATE`, `VAR_SKY_PILLAR_STATE` | |
| Ligue | `VAR_ELITE_4_STATE` (0x409C), `FLAG_IS_CHAMPION` (`data/scripts/hall_of_fame.inc:3`), `FLAG_SYS_GAME_CLEAR`, `FLAG_SYS_NATIONAL_DEX` | |

**Badges ↔ CS (capacités de terrain)** : `src/field_move.c:11-63` (`IsFieldMoveUnlocked_*`) — Émeraude : Coupe=B1, Flash=B2, Éclate-Roc=B3, Force=B4, Surf=B5, Vol=B6, Plongée=B7, Cascade=B8 ; Escalade si `OW_ROCK_CLIMB_FIELD_MOVE`, Téléport/Tunnel toujours. Modifier ces fonctions pour un autre ordre de badges.
**Badges ↔ obéissance** : `src/battle_util.c:5645-5662` (B8 = tout obéit). **Badges ↔ level cap** (si activé) : `src/caps.c:10-21` (15/19/24/29/31/33/42/46/58). **Badges ↔ boost de stats** : désactivé (B_BADGE_BOOST = GEN_LATEST). Debug : `data/scripts/debug.inc:41-48` pose tous les badges.

## 9. Budget sauvegarde [V]

| Bloc | Taille utilisée | Capacité | Libre |
|---|---|---|---|
| SaveBlock2 | 3 848 o | 3 968 (1 secteur) | **120 o** |
| SaveBlock1 | 15 496 o | 15 872 (4 secteurs) | **376 o** |
| SaveBlock3 (morceaux de 116 o dans 14 secteurs) | 1 o (`dexNavChain`) | 1 624 | **1 623 o** |
| PokemonStorage | 34 144 o | 35 712 (9 secteurs) | 1 568 o |

`STATIC_ASSERT` : `src/save.c:80-82`. SB3 (`include/global.h:256-274`) accueille Fake RTC, NPC follower, flags de description d'objets (`OW_ITEM_DESCRIPTIONS_FIRST_TIME`), `USE_DEXNAV_SEARCH_LEVELS` (= NUM_SPECIES = **1 573 o → tient à peine seul**), arbres à Noigrume. `include/config/save.h` peut libérer jusqu'à 3 790 o (Mystery Gift 876 o, ramScript 1 104 o, Record Mixing 1 032 o…). Flags/vars supplémentaires = SB1.

## 10. Tests (`make check`) [V]

- `make check` (Makefile l.362-365) compile `pokeemeraude-test.elf` (`-DTESTING=1`, `ld_script_test.ld`, configs forcées par `include/config/test.h` — toutes formes/espèces activées), le patche (`tools/patchelf`), puis lance `mgba-rom-test-hydra` + `mgba-rom-test` en headless (parallélisé). Filtre : `make check TESTS="Spikes"`.
- Binaire `tools/mgba/mgba-rom-test` (x86-64 Linux, préconstruit, fonctionne) [V] ; hydra compilé depuis `tools/mgba-rom-test-hydra`. L'agent QA a aussi construit `/opt/mgba-tools/bin/{mgba-rom-test,mgba-rom-test-hydra,gbaplay}`. Le Makefile prend d'abord ceux du `PATH`.
- Ne nécessite **aucun BIOS ni ROM externe**.

## 11. Menu debug et build release [V]

- `include/config/debug.h:5,11,15` : `DEBUG_OVERWORLD_MENU` (R+START), `DEBUG_BATTLE_MENU` (SELECT en combat), `DEBUG_POKEMON_SPRITE_VISUALIZER` = `DISABLED_ON_RELEASE` → **actifs dans `make`, désactivés par `make release`** (`include/constants/global.h:11-17`). Idem `I_SHOW_NO_ID_TRAINER`, Quickstart (`include/quickstart.h:6-10`, SELECT à l'écran titre), printf mGBA (`include/config/general.h`).
- **Livraison = `make release`** (`pokeemeraude-release.gba`, LTO, NDEBUG). Vérifier en release que rien ne dépend du menu debug. Pour forcer en build normal : mettre `FALSE` dans `debug.h`.
- `EXPANSION_INTRO TRUE` (`general.h`) : intro RHH après le copyright — à désactiver/remplacer pour l'identité du hack (crédits RHH/Qigast à conserver ailleurs, cf. README).

## 12. Risques techniques identifiés

1. **IWRAM 86.6 % (4,3 Ko libres)** : éviter tout nouveau code/données `IWRAM_DATA`/ARM. EWRAM 35 Ko libres : prudence avec gros buffers.
2. **Game code** : changer `BPEF` peut casser la détection RTC/Flash sur émulateur [I] — tester.
3. `include/config/caps.h:28` : commentaire collé à la ligne (`…apply#define B_EV_CAP_VARIABLE 12`) ; la vraie définition est l.29 (`B_EV_CAP_VARIABLE 8`, var invalide). Sans effet tant que `B_EV_CAP_TYPE = EV_CAP_NONE` ; **à corriger avant d'activer les caps EV**.
4. Gimmicks (Méga/Z/Dynamax/Tera) inaccessibles au joueur sans objets clés/flags (voir FEATURE_INVENTORY.md).
5. 9 flags dresseurs libres seulement : un hack avec beaucoup de nouveaux dresseurs doit **réutiliser des slots TRAINER_* vanilla** (recommandé) ou augmenter `MAX_TRAINERS_COUNT_EMERALD` (déplacer SYSTEM_FLAGS → casse la compatibilité de save, acceptable pour un nouveau jeu mais refaire le budget).
6. Avertissements build : 203× `bKGD invalid index` + 3× `iCCP` (libpng, bénins). `-Werror` est actif : tout warning C nouveau casse la build.
