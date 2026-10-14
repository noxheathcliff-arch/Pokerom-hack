# ENGINE_CHANGES — modifications moteur du projet

> Base : pokeemeraude-expansion 1.16.4 (FR). Auteur : programmeur moteur. Dernière mise à jour : 2026-10-14 (brief v2).
> Toutes les modifications sont marquées `Hack:` dans le code (`grep -rn "Hack:" src include asm data/scripts`).
> Registre des flags/vars : [`FLAGS_VARS_REGISTRY.md`](FLAGS_VARS_REGISTRY.md) (source unique).
> Tests : `test/hack_engine.c` (tests unitaires) et `test/battle/hack_choose_lead.c` (tests de combat), lancés par `make check`.

## État par fonctionnalité (2026-10-14)

| Fonctionnalité | Compile | Testée comment | Résultat |
|---|---|---|---|
| A. Nettoyage (renommages neutres, titre `POKEMON HACK`, intro RHH off, classes « Heure Suspendue » retirées) | oui | build + smoke test + `make check` | OK |
| N1. Flag sans rencontres `FLAG_NO_WILD_ENCOUNTERS` | oui | tests unitaires (pêche avec témoin positif, Éclate-Roc, Doux Parfum/Miel, câblage `WE_FLAG_NO_ENCOUNTER`) | OK ; chemin « herbe » couvert par code upstream (non testé directement) |
| H1. Plafonds souples (valeurs provisoires) | oui | tests unitaires de la table | OK ; calcul d'EXP souple ignoré en test (voir H1) |
| H2. Difficulté `VAR_DIFFICULTY` | oui | lecture de code (tests upstream `trainer_control`) | OK |
| B. Joueur = Red/Leaf | oui | tests unitaires + capture émulateur (Red dans le camion) | OK ; course, dos en combat, Vélo Cross non vérifiés visuellement |
| C. Sprites terrain Kanto en Émeraude | oui | test unitaire (27 sprites non NULL) | OK ; **+241 Kio ROM** |
| D1. Combats refusables (refus enregistré, définitif, branche) | oui | tests unitaires + octets de la macro vérifiés dans la ROM | OK ; UI OUI/NON non testée en émulateur |
| D2. Choix du Pokémon de tête (dresseurs) | oui | tests unitaires + test de combat témoin | partiel (voir D2) ; menu non testé en émulateur ; combats sauvages non couverts |
| E. Affinités `addaffinity`/`subaffinity` | oui | tests unitaires (via `RUN_OVERWORLD_SCRIPT`) | OK |

## Résumé de vérification

| Vérification | Résultat |
|---|---|
| `make -j4` (ROM normale) | **EXIT 0** ; EWRAM 226 588 o (86,44 %, +4 o), IWRAM 28 376 o (inchangé, 86,60 %), ROM 26 792 064 o (79,85 % ; +242 Kio vs upstream, presque tout dû aux sprites Kanto) |
| `tools/qa/run_smoke.sh . qa_artifacts/smoke_engine_v3` | **SMOKE: PASS** (nouvelle partie → sauvegarde → redémarrage → CONTINUER) ; **aucun script QA modifié** (les scripts se synchronisent sur `gMain.callback2`, la suppression de l'intro RHH ne les casse pas) |
| `make check` | **EXIT 0 — PASSED 4 949 / TOTAL 5 566, FAILED 0** (upstream : 4 937 / 5 553, 0 échec) ; 1 test projet ignoré (ASSUME, voir H1) |
| En-tête ROM | `POKEMON HACK` / `BPEF` (vérifié dans `pokeemeraude.gba` à 0xA0) |

---

## A. Nettoyage et réglages de base

| Fichier | Changement | Pourquoi |
|---|---|---|
| `Makefile` | `TITLE ?= POKEMON HACK` (12 car. max), `GAME_CODE` **inchangé** `BPEF` | titre provisoire neutre ; garder un code `BPE?` pour que les émulateurs activent RTC + Flash 128K (TECHNICAL_AUDIT §2) |
| `include/config/general.h` | `EXPANSION_INTRO FALSE` | identité du hack ; l'intro RHH ne s'affiche plus (crédits RHH à garder ailleurs, README/crédits) |
| `include/constants/flags.h` | `0x20` → `FLAG_NO_WILD_ENCOUNTERS`, `0x21` → `FLAG_CHOOSE_BATTLE_LEAD` | voir §N1, §D2 |
| `include/constants/vars.h` | `0x40F7` → `VAR_DIFFICULTY` | §H2 |
| `test/heure_suspendue.c` → `test/hack_engine.c` | renommé, réécrit sans rien de spécifique à l'ancienne histoire | |
| Classes de dresseurs (Carillonneur/Veilleur) | **retirées** (revert des fichiers `battle_main.c`, `battle_message.c`, `international_string_util.c`, `pokemon.c`, `strings.c`, `constants/trainers.h`) | propres à l'histoire abandonnée |
| Effacement auto du flag de non-rencontre à chaque chargement de carte | **retiré** | n'était utile qu'au Figement ; un flag persistant est plus général (zones sûres, cinématiques, escortes) |

### `make release`
`make release` existe (Makefile l. 59-60, 160-163, 337) : objets dans `build/emeraude-release/`, sortie `pokeemeraude-release.gba`, `-DRELEASE` + LTO (`USE_LTO_ON_RELEASE ?= 1` dans `config.mk`) + `NDEBUG`. Effets : `DEBUG_OVERWORLD_MENU`, `DEBUG_BATTLE_MENU`, `DEBUG_POKEMON_SPRITE_VISUALIZER`, `I_SHOW_NO_ID_TRAINER` passent à FALSE (`DISABLED_ON_RELEASE`), Quickstart (SELECT à l'écran titre) désactivé (`include/quickstart.h`). **Non lancé** dans cette session (budget) : à faire avant toute livraison.

---

## N1. Aucune rencontre sauvage sous un flag (`FLAG_NO_WILD_ENCOUNTERS`)

**Constat :** l'expansion a déjà `WE_FLAG_NO_ENCOUNTER` (`include/config/wild_encounter.h`), mais il ne bloque que les rencontres **en marchant** (`ShouldDisableRandomEncounters`, `src/field_control_avatar.c`) et les **rencontres visibles** (`src/wild_encounter_ow.c`). Pêche, Éclate-Roc et Doux Parfum/Miel passaient encore.

| Fichier | Changement |
|---|---|
| `include/config/wild_encounter.h` | `WE_FLAG_NO_ENCOUNTER FLAG_NO_WILD_ENCOUNTERS` (réutilise le mécanisme upstream) |
| `src/wild_encounter.c` | nouvelle fonction `IsWildEncounterFlagSet()` ; retour anticipé dans `DoesCurrentMapHaveFishingMons()` (→ « Pas même une touche »), `RockSmashWildEncounter()` (`VAR_RESULT = FALSE`), `SweetScentWildEncounter()` (le Miel utilise le même effet → échec normal) |
| `include/wild_encounter.h` | prototype |

**Usage script :** `setflag FLAG_NO_WILD_ENCOUNTERS` … `clearflag FLAG_NO_WILD_ENCOUNTERS`. Le flag est **sauvegardé et persistant** : le script qui le pose doit l'effacer (par ex. dans le `ON_TRANSITION` des cartes voisines, ou à la fin de la séquence).
**Tests :** `test/hack_engine.c` — câblage `WE_FLAG_NO_ENCOUNTER == FLAG_NO_WILD_ENCOUNTERS` ; pêche : TRUE sans flag (témoin positif, Route 114), FALSE avec ; Éclate-Roc et Doux Parfum : 500 essais → aucune rencontre. **Non testé directement :** le chemin « pas dans l'herbe » (fonction `static` upstream) — couvert par lecture de code uniquement.

## H1. Plafonds de niveau souples

| Fichier | Changement |
|---|---|
| `include/config/caps.h` | `B_EXP_CAP_TYPE EXP_CAP_SOFT`, `B_LEVEL_CAP_TYPE LEVEL_CAP_FLAG_LIST`, `B_LEVEL_CAP_EXP_UP TRUE` |
| `src/caps.c` | table `sLevelCapFlagMap` : **valeurs provisoires** (15/19/24/29/33/38/44/50/58 sur les 8 badges puis le Maître ; 100 ensuite) + mode d'emploi en commentaire |

**Fonctionnement :** le plafond = valeur du **premier flag non posé** de la liste ; une fois tous posés → `MAX_LEVEL`. Au-dessus du plafond l'EXP est divisée (÷4 au plafond, ÷8 à +1… ÷64 à +4 et plus) ; en dessous, bonus (`B_LEVEL_CAP_EXP_UP`).
**Ajouter un jalon d'histoire :** insérer `{FLAG_<jalon>, <plafond>}` à sa place chronologique ; l'ordre doit être garanti dans **toutes** les parties (un flag posé hors ordre « saute » des paliers). N'importe quel flag sauvegardé convient (badge, `FLAG_DEFEATED_*`, flag d'histoire du registre). Pour une histoire non linéaire, préférer `LEVEL_CAP_VARIABLE` + une var mise à jour par script (`B_LEVEL_CAP_VARIABLE`).
**Tests :** plafond non décroissant le long des badges, `MAX_LEVEL` après le Maître. Les valeurs ne sont pas figées dans les tests (le design les réglera).
**Impact sur les tests upstream :** avec le plafond souple actif, 3 tests d'EXP upstream (`test/battle/exp.c`) échouaient (EXP divisée). `include/config/test.h` force donc `B_EXP_CAP_TYPE EXP_CAP_NONE` **dans la build de test uniquement** ; conséquence : le test du calcul d'EXP souple (`GetSoftLevelCapExpValue`) est ignoré (`ASSUME`) par `make check` — c'est du code upstream non modifié. `B_RARE_CANDY_CAP` laissé FALSE (décision design).

## H2. Difficulté (`B_VAR_DIFFICULTY`)

- `include/config/battle.h` : `B_VAR_DIFFICULTY VAR_DIFFICULTY` (0x40F7).
- **Sélection des équipes :** dans `src/data/trainers.party`, un second bloc avec le même `=== TRAINER_X ===` et `Difficulty: Hard` (ou `Easy`) définit la version alternative ; `trainerproc` génère `gTrainers[DIFFICULTY_*][TRAINER_X]`. `GetTrainerDifficultyLevel()` (`src/difficulty.c`) prend la version de la difficulté courante **si elle existe**, sinon `Normal`.
- **Initialisation :** `NewGameInitData` appelle déjà `SetCurrentDifficultyLevel(DIFFICULTY_NORMAL)` (upstream). ⚠ Sans cela la var vaudrait 0 = `DIFFICULTY_EASY`.
- **Script :** `setdifficulty DIFFICULTY_HARD` (ou `DIFFICULTY_NORMAL`) ; `getdifficulty` → `VAR_RESULT` ; `increasedifficulty` / `decreasedifficulty`.
- Non testé spécifiquement (le test système force `B_VAR_DIFFICULTY` sur une var de test ; les tests upstream `trainer_control` couvrent la sélection).

## H4. Arrêt de l'horloge (`OW_USE_FAKE_RTC` + `OW_FLAG_PAUSE_TIME`) — **non adopté**

Analyse du code (`src/fake_rtc.c`, `src/rtc.c`, `src/play_time.c`, `include/global.h`) :
- `OW_USE_FAKE_RTC TRUE` **remplace globalement** l'horloge matérielle : `RtcInit` ne lit plus la puce, l'heure est stockée en SaveBlock3 (`fakeRTC`, 8 o sur 1 623 libres) et avance seulement **pendant le jeu**, à chaque seconde de temps de jeu, d'un facteur `OW_ALTERED_TIME_RATIO` (GEN_LATEST = GEN_9 → **20 s de jeu par seconde réelle**, une journée = 72 min ; `GEN_8_PLA` = 60×, `TIME_DEBUG` = 1×).
- Conséquences : l'heure réelle est perdue (baies, marées, événements quotidiens, Mirage… suivent l'horloge interne et s'arrêtent console éteinte) ; la nouvelle partie démarre à 10 h ; plus de dépendance à la puce RTC (avantage sur linkers sans RTC) ; s'arrête si le compteur de temps de jeu est bloqué (999 h).
- `OW_FLAG_PAUSE_TIME` n'existe qu'avec la fausse RTC (`STATIC_ASSERT`) ; `fwdtime` / `FakeRtc_ForwardTimeTo` efface ce flag (pause → reprise).
- **Décision : non adopté.** Changement de rythme jour/nuit global = décision de design. Repli conseillé si besoin d'un « temps arrêté » local : effet cosmétique (teinte/météo/musique), sans toucher à l'horloge.

## Méga-Évolution : `ITEM_MEGA_RING`

- Nom FR dans cette base : **« Méga-Anneau »** (`src/data/items.h`, `[ITEM_MEGA_RING]`, poche Objets rares). (« Méga-Bracelet » = nom ROSA ; renommer `.name` si le design le veut.)
- Chemin : `CanMegaEvolve()` (`src/battle_util.c`) exige `CheckBagHasItem(ITEM_MEGA_RING, 1)` pour le joueur ; aucune autre condition (pas de flag). Les dresseurs adverses n'en ont pas besoin.
- Ligne de script : `giveitem ITEM_MEGA_RING`.

## Noms de classes de dresseurs (longueur)

`struct TrainerClass` (`include/data.h`) : `u8 name[13]` → **12 caractères maximum** (+ fin de chaîne). Les formes féminines peuvent être plus longues via `GetTrainerClassNameGenderSpecific()` (`src/international_string_util.c`, chaînes séparées, ex. `ELEVE`). Pour renommer une classe : changer la chaîne dans `gTrainerClasses` (`src/battle_main.c`) en gardant l'ID ; pour une musique de combat dédiée : `GetBattleBGM()` (`src/pokemon.c`). ⚠ `IsTrainerIdToSwap()` (`src/battle_message.c`) inverse classe et nom pour `TEAM_AQUA/MAGMA` (« SBIRE TEAM MAGMA ») : à retirer si ces classes sont renommées. **Test :** toutes les classes tiennent en 12 caractères.

---

## B. Le joueur incarne Red (sprites Kanto en Émeraude)

| Fichier | Changement |
|---|---|
| `include/config/overworld.h` | nouveau `OW_KANTO_PLAYER_AVATAR TRUE` |
| `include/constants/event_objects.h` | `PLAYER_AVATAR_KANTO = (IS_FRLG \|\| OW_KANTO_PLAYER_AVATAR)` choisit les sprites `RED_*` (garçon) / `GREEN_*` (fille, sprites de Leaf) au lieu de Brendan/May pour tous les états (marche, vélo, surf, plongée, CS, pêche, arrosoir, Cherche VS) |
| `src/trainer.c` | `GetEmeraldTrainerPic()` → `TRAINER_PIC_RED` / `TRAINER_PIC_LEAF` (dos en combat, sprites Kanto) |
| `src/pokemon.c` | `PlayerGenderToFrontTrainerPicId()` → classes `RED` / `LEAF` (portrait de face : carte dresseur, etc.) |
| `src/data/object_events/object_event_anims.h` | nouvelle table `sAnimTable_RedGreenNormal` : les feuilles Red/Green utilisent toujours les cadres de course FRLG (la table Brendan/May choisissait selon `IS_FRLG` → mauvais cadres en Émeraude) |
| `object_event_graphics_info.h` | Red/Green normal → `sAnimTable_RedGreenNormal` |

Brendan/May restent disponibles comme PNJ / rival (`GetRivalAvatarGraphicsIdByStateIdAndGender` utilise sa propre table en Émeraude).
**Preuve :** `qa_artifacts/smoke_red/run1_new_game/06_start_menu.png` (Red dans le camion) ; tests unitaires (ID de sprites par état/genre, `GetPlayerTrainerPic(MALE, VERSION_EMERALD) == TRAINER_PIC_RED`, face).
**Limites / à faire :**
- Vélo Cross et Vélo Course utilisent la même feuille `RED_BIKE` : les **figures du Vélo Cross** (wheelie, sauts) n'ont pas de cadres dédiés → risque d'affichage incorrect : ne pas donner le Vélo Cross, ou fournir des sprites.
- Le discours de Birch (choix du genre) montre encore Brendan/May ; l'intro devra être réécrite de toute façon.
- Animation de course et dos en combat **non vérifiés visuellement** (pas de combat dans le smoke test).

## C. Sprites Kanto en Émeraude

Les blocs `#if IS_FRLG` des données d'objets ont été **ouverts** (remplacés par un commentaire `Hack:`) dans : `object_event_graphics.h`, `object_event_graphics_info.h`, `object_event_graphics_info_pointers.h`, `object_event_pic_tables.h` et la liste des palettes de `src/event_object_movement.c`. Tous les PNJ FRLG sont donc disponibles en Émeraude avec leurs ID `OBJ_EVENT_GFX_*` existants et leurs palettes (système de palettes dynamiques par tag, inchangé). Coût ROM mesuré : 26 544 372 o → 26 791 292 o = **+246 920 o (+241 Kio)** pour l'ensemble des objets FRLG (≈ 6,4 Mio restent libres). Aucun impact IWRAM/EWRAM.
**Couverture du casting Kanto demandé :** les 8 champions d'arène de Kanto (Pierre/Brock, Ondine/Misty, Major Bob/Lt. Surge, Erika, Koga, Morgane/Sabrina, Auguste/Blaine, Giovanni), le Conseil 4 (Olga/Lorelei, Aldo/Bruno, Agatha, Peter/Lance), Chen, Blue, Red/Leaf, Sbires Rocket H/F, Léo/Bill, M. Fuji, Celio, Daisy : **tous utilisables** dans la build Émeraude (`OBJ_EVENT_GFX_*`, test unitaire). Le casting de Hoenn est natif.
**Liste demandée — sprites terrain présents (testés non NULL) :** BLUE, GIOVANNI, PROF_OAK, BROCK, MISTY, LT_SURGE, ERIKA, KOGA, SABRINA, BLAINE, LORELEI, BRUNO, AGATHA, LANCE, ROCKET_M, ROCKET_F, BILL, MR_FUJI, CELIO, DAISY (+ RED_*, GREEN_*).
**Portraits de combat (face) dans la build Émeraude** (tous non gardés par `IS_FRLG`) : Blue = `TRAINER_PIC_RIVAL_EARLY_FRLG` / `RIVAL_LATE_FRLG` / `CHAMPION_RIVAL_FRLG` ; Giovanni = `LEADER_GIOVANNI_FRLG` ; Chen = `PROFESSOR_OAK_FRLG` ; arènes Kanto = `LEADER_*_FRLG` ; Conseil = `ELITE_FOUR_*_FRLG` ; Rocket = `ROCKET_GRUNT_M/F_FRLG`. **Manquants :** Bill, M. Fuji, Celio, Daisy (jamais dresseurs dans FRLG).

## D1. Combats de dresseurs refusables (refus enregistré et définitif)

**Conception (opt-in par dresseur ; les combats importants restent `trainerbattle_single`, obligatoires) :** un bit `TRAINER_BATTLE_DECLINABLE` (0x80) dans l'octet `rivalBattleFlags` des paramètres de `trainerbattle` (inutilisé hors rival de début) ; le **flag de refus** et le **script de refus** sont rangés dans deux champs « dresseur B » (`defeatTextB`, `battleScriptRetAddrB`), qui ne sont lus que pour les combats à deux dresseurs (jamais refusables). Aucun nouveau mode, aucun changement de format.

**Macro :**
```
trainerbattle_single_declinable TRAINER_X, Intro, Defaite, FLAG_REFUS_X [, ScriptRefus [, event_script [, music]]]
```
- après le texte d'intro : « Accepter le combat ? » (OUI/NON) ;
- **NON** → `FLAG_REFUS_X` posé (sauvegardé), `VAR_RESULT = TRAINER_DECLINED_NOW` (1), musique de la carte restaurée, puis saut à `ScriptRefus` s'il est donné (sinon fin) ; le flag du dresseur **n'est pas** posé (pas de récompense) ;
- **refus définitif** : tant que `FLAG_REFUS_X` est posé, le dresseur **ne repère plus** le joueur (`src/trainer_see.c`) et, si on lui parle, **ne repose pas** la question : saut direct à `ScriptRefus` avec `VAR_RESULT = TRAINER_DECLINED_BEFORE` (2) (sinon fin silencieuse) ;
- le scénariste peut rouvrir le choix avec `clearflag FLAG_REFUS_X` ;
- `FLAG_REFUS_X = 0` : refus non enregistré (le dresseur redemandera ; à éviter pour une décision d'histoire).
- `ScriptRefus` démarre joueur **bloqué** : le terminer par `releaseall` + `end`.

**Exemple :**
```
Route1_EventScript_Montagnard::
	trainerbattle_single_declinable TRAINER_MONTAGNARD_1, Route1_Text_Intro, Route1_Text_Defaite, FLAG_REFUS_MONTAGNARD_1, Route1_EventScript_MontagnardRefus
	msgbox Route1_Text_ApresCombat, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_MontagnardRefus::
	goto_if_eq VAR_RESULT, TRAINER_DECLINED_BEFORE, Route1_EventScript_MontagnardDeja
	addaffinity VAR_REPUTATION_MONTAGNARDS, -5      @ exemple de conséquence
	msgbox Route1_Text_Dommage, MSGBOX_DEFAULT
	releaseall
	end
Route1_EventScript_MontagnardDeja::
	msgbox Route1_Text_TuAsRefuse, MSGBOX_DEFAULT
	releaseall
	end
```
Les flags `FLAG_REFUS_*` sont alloués par le design dans `FLAGS_VARS_REGISTRY.md` (un par décision).

| Fichier | Changement |
|---|---|
| `include/constants/battle.h` | `TRAINER_BATTLE_DECLINABLE 0x80`, `TRAINER_DECLINED_NOW 1`, `TRAINER_DECLINED_BEFORE 2` |
| `include/config/battle.h` | `B_DECLINABLE_TRAINER_BATTLES TRUE` (interrupteur global) |
| `asm/macros/event.inc` | macro `trainerbattle_single_declinable` |
| `data/scripts/trainer_battle.inc` | `EventScript_ShowTrainerIntroMsg` : contrôle « déjà refusé » avant l'intro ; question OUI/NON après ; `EventScript_AskAcceptTrainerBattle`, `EventScript_TrainerBattleAlreadyDeclined` |
| `src/battle_setup.c` | specials `IsTrainerBattleDeclinable`, `IsTrainerBattleAlreadyDeclined` ; natives `Script_TrainerBattleDeclinedNow/Before` (posent le flag, `VAR_RESULT`, sautent au script) ; `IsTrainerBattleDeclinedFromScriptPointer` |
| `src/trainer_see.c` | un dresseur dont le flag de refus est posé ne repère plus le joueur |
| `data/specials.inc` | 2 specials |

Non refusables : combats doubles, deux dresseurs qui repèrent en même temps, rival de début, revanches, `trainerbattle_no_intro`.
**Tests :** unitaires (`test/hack_engine.c` : bit lu ; « deux dresseurs » obligatoire ; flag de refus → plus de repérage ni de nouvelle question ; bit absent → flag ignoré). **Assemblage vérifié** : script temporaire avec la macro (avec et sans script de refus) compilé, octets contrôlés dans la ROM (`defeatTextB = 0x22`, `battleScriptRetAddrB` = adresse du script, `rivalBattleFlags = 0x80`), puis retiré. **Non testé en émulateur** (UI OUI/NON, musique) : aucun dresseur ne l'utilise encore ; à vérifier sur le premier dresseur scripté.

## D2. Choisir son Pokémon de tête

Rien d'équivalent dans l'expansion (`grep lead/ChooseLead/B_PARTY_SELECT`). Conception la plus simple et sûre : **on ne réordonne pas l'équipe** ; on mémorise l'emplacement choisi et on l'utilise une seule fois quand le combat fixe les Pokémon envoyés.

| Fichier | Changement |
|---|---|
| `include/config/battle.h` | `B_FLAG_CHOOSE_BATTLE_LEAD FLAG_CHOOSE_BATTLE_LEAD` (0 = fonction désactivée) |
| `data/scripts/trainer_battle.inc` | `EventScript_MaybeChooseBattleLead` appelé juste avant `dotrainerbattle` (combats avec et sans intro) : si le flag est posé et ≥ 2 Pokémon aptes → `special ChoosePartyMon` (menu d'équipe ; B = tête par défaut) |
| `src/battle_setup.c` | specials `ShouldChooseBattleLead`, `SetBattleLeadFromSelection` ; `ConsumeChosenBattleLead` (1 octet EWRAM, consommé au combat suivant) |
| `src/battle_controllers.c` | `SetBattlePartyIds` : en combat non lié/non enregistré/hors Zone de combat, le combattant 0 du joueur prend l'emplacement choisi s'il est apte |

**Activation :** `setflag FLAG_CHOOSE_BATTLE_LEAD` (option joueur à exposer : PNJ « coach », objet clé ou entrée du menu Options — l'intégration au menu Options, qui touche l'UI et la sauvegarde des options, est **différée**).
**Limites :** combats sauvages non couverts (ils partent du C sans script : un menu d'équipe à ce moment demanderait de réorganiser les transitions) ; revanches Cherche VS non couvertes ; en double, seul le Pokémon de gauche est choisi.
**Tests :** unitaires (`test/hack_engine.c` : proposé seulement avec le flag et ≥ 2 Pokémon aptes ; choix consommé une seule fois ; B = pas de choix) ; `test/battle/hack_choose_lead.c` : témoin (sans choix, l'emplacement 1 mène). Un test de combat « l'emplacement 2 mène » n'est **pas exprimable** avec le lanceur de tests actuel : il suppose que le Pokémon actif du joueur est l'emplacement 1 et signale « Illegal battle record » quand un autre est envoyé — ce qui a été observé et montre que la substitution s'applique, mais ce n'est pas un test vert. Menu d'équipe non testé en émulateur.

### Retirer un Pokémon de l'équipe (besoin futur D111)
Aucune commande de script dédiée dans l'expansion (pas de `removemon`). Briques C existantes : `ZeroMonData()` + `CompactPartySlots()` (utilisées par la pension, `StorePokemonInDaycare`) ; les échanges en jeu (`CreateInGameTradePokemon`) remplacent un Pokémon. Une commande `removepartymon SLOT` (native de ~10 lignes) sera simple à ajouter le moment venu. Non implémenté.

## E. Affinités / réputation (convention)

- **Stockage :** une var sauvegardée par relation/faction (allocation par le design, dans le registre). Plage conseillée 0..100, valeur neutre 50 (à poser au début de partie).
- **Macros** (`asm/macros/event.inc`, C : `src/script_affinity.c`) :
  - `addaffinity VAR, n[, min=0, max=100]` → `VAR = clamp(VAR + n, min, max)`, `VAR_RESULT` = nouvelle valeur ;
  - `subaffinity VAR, n[, min, max]`.
- **Seuils :** commandes existantes, pas de nouvelle commande : `goto_if_ge VAR, 70, Label`, `goto_if_lt VAR, 30, Label`, `call_if_ge`…
- **C :** `AddAffinityClamped(varId, delta, min, max)`.
- **Tests :** bornes haute/basse, plage personnalisée.

---

## Tests (`make check`)

Commande : `make check -j4 ROMTEST=/opt/mgba-tools/bin/mgba-rom-test ROMTESTHYDRA=/opt/mgba-tools/bin/mgba-rom-test-hydra` (log : `/home/user/check_engine.log`).

| | Upstream 1.16.4 | Projet (2026-10-14) |
|---|---|---|
| PASSED | 4 937 | **4 949** (+12 tests projet) |
| FAILED | 0 | **0** |
| KNOWN_FAILING / TO_DO / EXPECT_FAILING | 13 / 595 / 8 | 13 / 595 / 8 |
| ASSUMPTIONS_FAILED | 0 | 1 (`Level cap: soft cap reduces exp…`, volontaire : `EXP_CAP_NONE` en build de test) |
| TOTAL | 5 553 | 5 566 |

Historique : un passage intermédiaire avait 4 échecs (3 tests d'EXP upstream cassés par le plafond souple → corrigé par l'override de `config/test.h` ; 1 test « choix du meneur » inexprimable → remplacé par des tests unitaires).

## Fichiers touchés (résumé)

`Makefile`, `include/config/{battle,caps,general,overworld,test,wild_encounter}.h`, `include/constants/{battle,event_objects,flags,vars}.h`, `include/{battle_setup,wild_encounter,script_affinity}.h`, `src/{battle_controllers,battle_setup,caps,event_data,event_object_movement,pokemon,script_affinity,trainer,trainer_see,wild_encounter}.c`, `src/data/object_events/{object_event_anims,object_event_graphics,object_event_graphics_info,object_event_graphics_info_pointers,object_event_pic_tables}.h`, `asm/macros/event.inc`, `data/scripts/trainer_battle.inc`, `data/specials.inc`, `test/hack_engine.c`, `test/battle/hack_choose_lead.c`.
