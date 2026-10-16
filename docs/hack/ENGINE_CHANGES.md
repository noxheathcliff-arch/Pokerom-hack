# ENGINE_CHANGES — modifications moteur du projet

> Base : pokeemeraude-expansion 1.16.4 (FR). Auteur : programmeur moteur. Dernière mise à jour : 2026-10-14 (brief v2).
> Toutes les modifications sont marquées `Hack:` dans le code (`grep -rn "Hack:" src include asm data/scripts`).
> Registre des flags/vars : [`FLAGS_VARS_REGISTRY.md`](FLAGS_VARS_REGISTRY.md) (source unique).
> Tests : `test/hack_engine.c` (tests unitaires) et `test/battle/hack_choose_lead.c` (tests de combat), lancés par `make check`.

## État par fonctionnalité (2026-10-14)

| Fonctionnalité | Compile | Testée comment | Résultat |
|---|---|---|---|
| A. Nettoyage (renommages neutres, titre `CONFLUENCE` (CF-23), intro RHH off, classes « Heure Suspendue » retirées) | oui | build + smoke test + `make check` | OK |
| N1. Flag sans rencontres `FLAG_NO_WILD_ENCOUNTERS` | oui | tests unitaires (pêche avec témoin positif, Éclate-Roc, Doux Parfum/Miel, câblage `WE_FLAG_NO_ENCOUNTER`) | OK ; chemin « herbe » couvert par code upstream (non testé directement) |
| H1. Plafonds souples (valeurs provisoires) | oui | tests unitaires de la table | OK ; calcul d'EXP souple ignoré en test (voir H1) |
| H2. Difficulté `VAR_DIFFICULTY` | oui | lecture de code (tests upstream `trainer_control`) | OK |
| B. Joueur = Red/Leaf | oui | tests unitaires + captures émulateur | OK ; **dos de Red en combat vérifié** (2026-10-15) ; course, Vélo Cross non vérifiés |
| C. Sprites terrain Kanto en Émeraude | oui | test unitaire (27 sprites non NULL) | OK ; **+241 Kio ROM** |
| D1. Combats refusables (refus enregistré, définitif, branche) | oui | tests unitaires + **émulateur (gbaplay)** | OK : question « Accepter le combat ? » OUI/NON affichée, NON → flag posé + script de refus exécuté (2026-10-15) |
| D2. Choix du Pokémon de tête (dresseurs) | oui | tests unitaires + **émulateur** | OK : menu d'équipe après OUI, emplacement 2 (Pikachu) envoyé en tête ; combats sauvages non couverts |
| E. Affinités `addaffinity`/`subaffinity` | oui | tests unitaires (via `RUN_OVERWORLD_SCRIPT`) | OK |
| CF-1..7. *Confluence* : allocation, E-CAP, E-BITS/décisions, E-REPREL, E-REMOVE, E-NATIVE, E-ADAPT, E-ECO, E-TOD, E-OUT, E-LEDGER | oui | `test/hack_confluence.c` (18/18) + smoke | OK ; E-ECO/E-OUT/E-TOD/E-ADAPT/E-NATIVE/E-LEDGER livrés et testés mais hors démo |

## Résumé de vérification

| Vérification | Résultat |
|---|---|
| `make -j4` (ROM normale) | **EXIT 0** ; EWRAM 226 588 o (86,44 %, +4 o), IWRAM 28 376 o (inchangé, 86,60 %), ROM 26 792 064 o (79,85 % ; +242 Kio vs upstream, presque tout dû aux sprites Kanto) |
| `tools/qa/run_smoke.sh . qa_artifacts/smoke_engine_v3` | **SMOKE: PASS** (nouvelle partie → sauvegarde → redémarrage → CONTINUER) ; **aucun script QA modifié** (les scripts se synchronisent sur `gMain.callback2`, la suppression de l'intro RHH ne les casse pas) |
| `make check` | **EXIT 0 — PASSED 4 949 / TOTAL 5 566, FAILED 0** (upstream : 4 937 / 5 553, 0 échec) ; 1 test projet ignoré (ASSUME, voir H1) |
| En-tête ROM | `CONFLUENCE` / `BPEF` (avant CF-23 : `POKEMON HACK`) (vérifié dans `pokeemeraude.gba` à 0xA0) |

---

## A. Nettoyage et réglages de base

| Fichier | Changement | Pourquoi |
|---|---|---|---|
| `Makefile` | `TITLE ?= CONFLUENCE` (12 car. max ; `POKEMON HACK` avant CF-23), `GAME_CODE` **inchangé** `BPEF` | titre provisoire neutre ; garder un code `BPE?` pour que les émulateurs activent RTC + Flash 128K (TECHNICAL_AUDIT §2) |
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

### D1b. Combats de scène (coord event / script sans objet dresseur)
`trainerbattle_*` normal exige un objet dresseur (assert « called from player », pas de reprise du script après combat). Pour tout combat lancé depuis un coord event ou une scène :
- `trainerbattle_scene_declinable TRAINER, Intro, Défaite, FLAG_REFUS [, ScriptRefus]` et `trainerbattle_scene_no_intro TRAINER, Défaite` (`asm/macros/event.inc`) ; bit `TRAINER_BATTLE_SCENE 0x40` dans `rivalBattleFlags` ; `BattleSetup_ConfigureTrainerBattle` route vers `EventScript_DoSceneTrainerBattle` / `...NoIntro...` (`trainer_battle.inc`) : pas de faceplayer/reveal/orientation ;
- le script **continue à l'instruction suivante** après victoire ET défaite (poser `FLAG_CF_NO_WHITEOUT` avant ; lire le résultat par `goto_if_set TRAINER_FLAGS_START + TRAINER`) ; le refus saute à `ScriptRefus` (qui doit terminer le script).
- `CB2_EndScriptedWildBattle` respecte aussi `B_FLAG_NO_WHITEOUT` (combat sauvage scripté perdu → le script reprend, sans blackout). Penser à `special HealPlayerParty`.
- Coord events « toujours actifs » : utiliser `var: VAR_TEMP_x, var_value: 0` (jamais `TRIGGER_RUN_IMMEDIATELY`, qui exécute le script sans msgbox/lock).

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

## CF. Aides moteur *Confluence* (brief moteur v3, 2026-10-14)

Code : `src/confluence.c`, `include/confluence.h`, `include/constants/confluence.h` (constantes `DEC_*`, `ECO_*`, aussi incluses dans les scripts via `data/event_scripts.s`). Macros : fin de `asm/macros/event.inc`. Specials : fin de `data/specials.inc`. Tests : `test/hack_confluence.c`. Tout est en ROM ; seule donnée de sauvegarde ajoutée : 16 o en SaveBlock3 (E-LEDGER). Les arguments marqués « var ou valeur » acceptent l'un ou l'autre (`VarGet`).

### CF-1. Allocation des flags / vars
Table définitive et preuve grep : `FLAGS_VARS_REGISTRY.md` § « Allocation définitive ». 44 vars `VAR_CF_*` (budget 45), 108 flags `FLAG_CF_*` nommés + 93 flags de visibilité réservés (`FLAG_CF_VIS_00..92`). **Piège découvert :** `vars_frlg.h` est inclus sans garde en Émeraude ; `0x406E` est remis à 0 par `overworld.c` à chaque vol/K.O. (alias FRLG) → `0x406E`, `0x4073`, `0x4068` exclus. Aucun `FLAG_HIDE_*` recyclé (pas de liste au design).
Branchements : `I_EXP_SHARE_FLAG = FLAG_CF_EXP_SHARE` (`config/item.h`), `B_FLAG_NO_WHITEOUT = FLAG_CF_NO_WHITEOUT` (`config/battle.h`). Valeurs de départ posées par `CF_InitNewGameVars()` (appel ajouté dans `NewGameInitData`, `src/new_game.c`).

### CF-2. E-CAP (plafond variable)
- `include/config/caps.h` : `B_LEVEL_CAP_TYPE LEVEL_CAP_VARIABLE`, `B_LEVEL_CAP_VARIABLE VAR_CF_CAP` ; EXP souple inchangée (`EXP_CAP_SOFT`, `B_LEVEL_CAP_EXP_UP`). La table de flags de `src/caps.c` (§H1) n'est plus lue.
- `src/caps.c` : garde-fou : var à 0 (sauvegarde antérieure) ou > 100 → plafond 100.
- Nouvelle partie : 14. Script : `raisecap 18` (ou `raisecap VAR_x`) → `VAR_CF_CAP = max(actuel, n)`, jamais de baisse ; `VAR_RESULT` = plafond. Special équivalent : `setvar VAR_0x8004, 18` + `special CF_RaiseCap`. Le script `CF_RaiseCap::` proposé par GAME_SYSTEMS §7 devient inutile.
- **Tests :** monotone, argument var, borne 100, var nulle = pas de plafond ; config branchée.

### CF-3. E-BITS et décisions
- `getbits VAR, shift, width` → `VAR_RESULT` ; `setbits VAR, shift, width, valeur` (n'écrit que son champ, valeur masquée). Specials : `CF_GetBits` (0x8004 var, 0x8005 décalage, 0x8006 largeur) / `CF_SetBits` (+ 0x8007 valeur).
- **Décisions** (D001..D131 → `VAR_CF_D00..D16`, 2 bits, table en C car les vars ne sont pas contiguës) :
  - `setdecision 27, DEC_B` → **écrit une seule fois** ; `VAR_RESULT = TRUE` si enregistrée maintenant, `FALSE` si déjà prise (ou arguments invalides) ;
  - `checkdecision 27` → `VAR_RESULT` = 0 (non prise), `DEC_A`=1, `DEC_B`=2, `DEC_C`=3 (aussi « refus » des combats refusables, DECISION_LEDGER règle 7) ;
  - `setdecision_once 27, DEC_B, Label_Deja` : enregistre puis saute à `Label_Deja` si elle était déjà prise. **Usage type** (garde à usage unique de tous les deltas) :
```
CF_D027_OptionB::
	setdecision_once 27, DEC_B, CF_D027_Fin
	addaffinity VAR_CF_BL, 3
	subaffinity VAR_CF_REP_C, 2
CF_D027_Fin::
	...
```
- **Tests :** champ isolé, masquage, argument var, specials ; les 131 décisions ont des slots distincts (aller-retour des 131) ; D001 = D00 b0-1, D131 = D16 b4-5 ; écriture unique ; `setdecision_once`.

### CF-4. E-REPREL
`repstanding VAR_CF_REP_G` → `VAR_RESULT = rG − moyenne(7) + 100` (100 = moyenne ; division tronquée vers 0). Special `CF_RepStanding` (0x8004 = la var). Seuils : `S ≥ +3` ⇔ `goto_if_ge VAR_RESULT, 103, …`. C : `CF_GetRepStanding()` (valeur signée). **Tests :** neutre = 100, cas chiffrés, « plaire à tous » = 0.

### CF-5. E-REMOVE, E-NATIVE, E-ADAPT
- `removepartymon SLOT` (0-5) : `ZeroMonData` + `CompactPartySlots` + recompte ; `VAR_RESULT = FALSE` si slot vide ou si plus aucun Pokémon hors Œuf ne resterait. (Le Pokémon disparaît : le scénario le transfère d'abord ailleurs s'il doit revenir.)
- `ishoennnative SPECIES` → `VAR_RESULT` : espèce du Pokédex de Hoenn, **hors formes régionales étrangères** (Zigzaton de Galar = arrivant). Pikachu (dex Hoenn d'Émeraude) compte comme natif.
- `getdominanttype` → `VAR_RESULT = TYPE_*`, `VAR_0x8000` = paquet 1 (A) / 2 (B) / 3 (C) de COMBAT_DESIGN §5.3. **Règle (COMBAT_DESIGN §5.3, arbitrage E-ADAPT, qui prime sur « fréquence pondérée par niveau » du brief moteur) :** pour chaque Pokémon apte (non-Œuf, PV > 0) : +2 au type 1, +1 au type 2 (un monotype ne donne que +2) ; score max gagne ; égalité → type 1 du Pokémon de tête (premier apte) s'il est à égalité, sinon le premier type rencontré dans l'ordre de l'équipe ; équipe vide → `TYPE_NONE`. Types hors table (Stellaire…) → paquet B.
- **Tests :** compaction, refus du dernier ; natifs / non-natifs / forme de Galar ; égalité → tête, PV 0 ignorés, paquets.

### CF-6. E-ECO, E-TOD, E-OUT
- **E-ECO** : `GetCurrentMapWildMonHeaderId()` (`src/wild_encounter.c`) compte les en-têtes **consécutifs** de la carte et ajoute `CF_GetEcoHeaderOffset()` = état de la zone (0 ENVAHI, 1 MIXTE, 2 RESTAURÉ, 3 ABATTU) lu dans `VAR_CF_ECO` (zone n = bits `2(n−1)`). Table {carte → zone} `sEcoZoneMaps` (`src/confluence.c`, ENCOUNTERS_PLAN §3.1, ~95 cartes). Un état sans table propre retombe sur la table de base. Grotte Métamo inchangée.
  - **Données :** dans `src/data/wild_encounters.json`, mettre pour la carte des entrées **consécutives** `gRoute116`, `gRoute116_Mixte`, `gRoute116_Restaure`, `gRoute116_Abattu`, chacune avec **toutes** ses méthodes. **Échantillon livré :** `gRoute116_Mixte` (copie de la R116 vanilla, Skitty passé de 1 % à 20 %) — **provisoire**, à remplacer par la table §4.4.
  - Écrire un état : `setbits VAR_CF_ECO, 2, 2, ECO_RESTAURE` (Z-02).
- **E-TOD** : `OW_TIME_OF_DAY_ENCOUNTERS TRUE` (`config/overworld.h`), repli `TIME_MORNING`, `DISABLE_FALLBACK FALSE` : une carte sans table `_Night` garde sa table unique à toute heure. Ajouter `gRoute116_Night` (et `gRoute116_Mixte_Night`…) pour une variante de nuit. ⚠ Aucun label ne doit contenir `Morning`, `Day`, `Evening`, `Night` ailleurs qu'en suffixe (vérifié : aucun label actuel). Coût : +~2 Ko ROM (en-têtes ×4). Test RTC réel sur mGBA : **non fait** (la logique d'heure est upstream).
- **E-OUT** : `setringoutbreak SPECIES, MAP_X, niveau[, proba=50[, jours=0[, att1..att4]]]` (jours 0 = jusqu'à `clearringoutbreak`, stocké 0xFFFF) ; attaques 0 → les 4 dernières attaques apprises par niveau. Specials `SetRingOutbreak` (0x8004 espèce, 0x8005 carte = constante `MAP_*`, 0x8006 niveau, 0x8007 proba) et `ClearRingOutbreak`. Utilise les champs vanilla de SaveBlock1 (aucune sauvegarde nouvelle) ; rencontres d'herbe uniquement (moteur vanilla). Épidémie télé aléatoire coupée : `OW_RANDOM_TV_OUTBREAKS FALSE` (`config/overworld.h`, garde dans `TryStartRandomMassOutbreak`, `src/tv.c`).
- **Tests :** R116 MIXTE → en-tête +1 (même carte, autre table) ; ABATTU sans table → base ; autre zone sans effet ; carte à table unique insensible ; aucune carte n'a > 4 en-têtes ; épidémie : champs, attaques ⊂ apprentissage ≤ niveau, test de rencontre sur la bonne carte seulement, attaques explicites, effacement, special.

### CF-7. E-LEDGER
`u8 cfStaticLedger[16]` à la fin de `struct SaveBlock3` (`include/global.h`), remis à 0 par `ClearSav3` à la nouvelle partie. `checkledger N` → `VAR_RESULT` ; `setledger N[, FALSE]` ; specials `LedgerGet` / `LedgerSet` (0x8004 = index 0..127). Attribution des 128 index : ENCOUNTERS_PLAN (à inscrire au registre). `test/save.c` : `T_SAVEBLOCK3_SIZE` 4 → 20. **Tests :** bits 0/127, hors borne ignoré, specials, octet attendu.

### CF-8. Démo ch. 0–1 : E-CLEARPARTY, SPAWN, suiveurs PNJ
- `clearparty` : vide toute l'équipe (`ZeroPlayerPartyMons` + recompte), **sans** garde ; le script doit redonner un Pokémon avant tout combat (ou garder `FLAG_NO_WILD_ENCOUNTERS`). Test unitaire.
- **SPAWN** (`src/new_game.c`, `WarpToTruck`) : la nouvelle partie démarre sur `MAP_ROUTE104` en (`CF_SPAWN_X`, `CF_SPAWN_Y`) = **(15, 57)** (`include/constants/confluence.h`) — la spec disait (13, 57), qui est **dans l'eau** (capture du smoke test) ; (15, 57) = premier sable. Orientation : par défaut (bas) ; tourner vers le haut dans le script `ON_LOAD`/`ON_FRAME` de la R104. `VAR_LITTLEROOT_INTRO_STATE` = 6 (désactive camion/Maman). Scripts QA mis à jour (`sb_offsets.sh` : `MAP_ROUTE104_*` ; `new_game_to_truck.txt` et `continue_from_save.txt` attendent la R104). Smoke : PASS.
- `FNPC_ENABLE_NPC_FOLLOWERS TRUE` (`config/follower_npc.h`) pour `setfollowernpc` (Hoopa, 2 contre 1). SaveBlock3 : 44 o en build de test (`test/save.c`). **2 contre 1 non vérifié en émulateur** (différé : le combat de test n'a pas pu être gagné en script dans le temps imparti).
- Preuves émulateur (script temporaire sur les cartons du camion, retiré) : captures `qa_artifacts/cf_emu/` (`d1_yesno.png`, `e2_party.png`, `f4.png` dos de Red, `g2.png` Pikachu en tête). Note : `trainerbattle` doit être lancé depuis un **objet** (assert `battle_setup.c:1252` sinon). Dans les tests `RUN_OVERWORLD_SCRIPT`, ne pas utiliser le label local `1:` (pris par l'enveloppe).

### CF-9. Prologue mis en scène (P1–P6)
- **Obéissance** (`src/battle_util.c`, `GetAttackerObedienceForAction`) : tant que `VAR_CF_CHAPTER == 0`, l'équipe du prologue (niv. 62+, sans badge) obéit toujours (`OBEYS`). Dès le ch. 1, règles vanilla (badges).
- **Intro sautée** (`src/main_menu.c`) : `Task_NewGameBirchSpeech_Init` règle sexe = garçon, nom = « RED », fondu au noir puis `CB2_NewGame` ; l'ancien discours du Prof. est conservé en `UNUSED` (`Task_NewGameBirchSpeech_InitVanilla`).
- **Pas de séquence du camion** (`src/overworld.c`, `CB2_NewGame`) : `gFieldCallback = FieldCB_WarpExitFadeFromBlack` (le départ se fait sur la plage R104 ; `ExecuteTruckSequence` bloquait le joueur ~700 images avant que P1 ne démarre).
- **Nouvelle partie** (`CF_DemoNewGameInit`) : camions de déménagement cachés (`FLAG_HIDE_LITTLEROOT_TOWN_*_TRUCK`, ils étaient traversables) ; VIS_86–92 posés (objets de mise en scène révélés par script).
- **Boîte de nom** : `setspeaker <label ROM>` avant chaque réplique (chaînes `CF_N0_*` locales à `cf_prologue.inc`, aucune entrée ajoutée à `speaker_names.h`) ; `setspeaker 0` pour la narration. Le nom est remis à zéro par `closemessage`. Pikachu du prologue : `gender=MON_MALE`.

---

### CF-10. Dresseurs de route refusables (CF-ROUTE-DECLINE)

- Config : `B_DECLINABLE_ROUTE_TRAINERS` (`include/config/battle.h`, TRUE).
- Tout `trainerbattle_single` / `trainerbattle_double` (modes `SINGLE`, `DOUBLE`, `CONTINUE_SCRIPT`, `CONTINUE_SCRIPT_DOUBLE` — pas les variantes `NO_MUSIC` ni les combats de scène) lancé par un dresseur de carte ayant un type de vue (`trainer_type` ≠ NONE : dresseurs de route, de grotte, d'arène) demande « Accepter le combat ? » après la réplique d'intro (`IsAutoDeclinableParam`, `src/battle_setup.c`). Réutilise le chemin de `trainerbattle_single_declinable` (`EventScript_AskAcceptTrainerBattle`).
- Refus : réplique « Dommage… Reviens quand tu seras prêt pour un combat ! » (quand il n'y a pas de `decline_script`), aucun combat, drapeau de dresseur **non** posé. Le local ID est mémorisé dans un masque EWRAM (`sDeclinedTrainerLocalIds`, 256 bits) : `CheckTrainer` (`src/trainer_see.c`) ignore ce dresseur jusqu'au prochain chargement de carte (`ClearDeclinedTrainersOnMap`, appelé dans `LoadMapFromWarp`/`LoadMapFromCameraTransition`, `src/overworld.c`) → pas de boucle de repérage. Lui parler repropose le combat. S'applique aussi aux `trainerbattle_single_declinable` sans drapeau de refus.
- Restent obligatoires : champions et boss (`TRAINER_TYPE_NONE` et/ou variante `NO_MUSIC`), combats de scène, `trainerbattle_no_intro`, revanches, deux dresseurs repérant le joueur en même temps, Pyramide/Trainer Hill.

### CF-11. Pose de repos de Red (avatar figé sur une image de marche)
- **Symptôme :** après une marche (script ou manette), Red restait parfois figé sur une image « jambe en avant ».
- **Cause :** la table d'animations `sAnimTable_RedGreenNormal` (ajoutée pour l'avatar Kanto, voir commit « Red avatar ») n'était pas inscrite dans `sStepAnimTables` (`src/data/object_events/object_event_anims.h`). `GetStepAnimTable` renvoyait `NULL`, donc `SetStepAnim` (utilisé par toutes les actions `face_*`, l'arrêt du joueur et `turnobject`) ne ramenait jamais l'animation sur une image de repos et `SetStepAnimHandleAlternation` n'alternait plus les pas : l'image affichée était celle où l'animation de marche avait été mise en pause.
- **Correctif :** entrée `{ sAnimTable_RedGreenNormal, animPos = {1, 3, 0, 2} }` (mêmes positions que `sAnimTable_BrendanMayNormal`, même disposition des 9 premières images). Aucune modification de code moteur.

### CF-12. Correctifs QA de la démo (2026-10-15)
- **Suiveur PNJ (Brice)** (`src/confluence.c`, specials) : `CF_ShowFollowerNPC` le montre sur la case du joueur après un warp ; `CF_PlaceFollowerNPC` le pose en (`VAR_0x8004`, `VAR_0x8005`), tourné vers `VAR_0x8006` (macro `cf_bplace`) ; `CF_RevealFollowerNPC` le montre derrière ou à côté du joueur s’il est encore invisible (appelé par `cf_bsay`, `cf_bexcl`, `cf_bmove` et `CF_C4_Leave`), ce qui évite que Brice parle sans être affiché.
- **`CF_StepAwayDir`** : `VAR_RESULT` = direction d’un pas libre pour s’écarter de l’interlocuteur (opposé d’abord, puis les côtés), `DIR_NONE` sinon (choix « Partir » de C5).
- **`cf_confirm retry`** (macro, `cf_prologue.inc`) : demande « Tu es sûr ? » après chaque choix narratif du prologue et du ch. 1 ; Non relance le menu, Oui rend le choix d’origine dans `VAR_RESULT` (sauvé dans `VAR_0x800B`).
- **Noms des poches** (`src/data/script_menu.h`) : OBJETS / OBJETS CLÉS / CT & CS / BAIES.
- **Portails animés** : trois graphismes 32×32 à 4 images (`graphics/object_events/pics/misc/cf_portal_{front,side,tilted}.png`), `OBJ_EVENT_GFX_CF_PORTAL_FRONT/SIDE/TILTED`. Les objets inanimés jouent toujours l’animation 0 : la table `sAnimTable_CfPortalSpin` (`object_event_anims.h`) remplit toutes les entrées `[0 ... ANIM_STD_COUNT - 1]` avec une boucle de 4 images (10 images par frame).
- **Texte** (`data/text/trainers.inc`) : intro et revanche de Calvin se terminent par « Alors, tu relèves mon défi? » (cohérent avec le combat refusable).
- **Carte** : panneau (métatuile 0x003, collision) en (16, 52) à Mérouville pour l’affiche de C4 ; Ferrand en `OBJ_EVENT_GFX_SCIENTIST_2` (Devon 2F, R116).

### CF-13. Correctifs QA, round 2 (2026-10-16)
- **`CF_FaceEachOther`** (`src/confluence.c`, special) : tourne l’un vers l’autre les objets de local id `VAR_0x8000` et `VAR_0x8001` (axe dominant, vertical en cas d’égalité ; objets invisibles ignorés). Macros `cf_talk a, b` et `cf_face id` (= `cf_talk LOCALID_PLAYER, id`) dans `cf_chapter1.inc` ; elles écrasent `VAR_0x8000`–`0x8001`. Utilisées avant chaque réplique où le locuteur et Red ne se faisaient pas face (prologue, C4, C6, C10, mur R115, Ciléo à Clémenti).
- **`CF_FollowerSideDir`** (special) : `VAR_RESULT` = `DIR_WEST`/`DIR_EAST` si Brice (suiveur PNJ) est juste sous Red et peut faire un pas de côté sur une case libre, `DIR_NONE` sinon. Brice s’écarte avant une émote pour que la bulle ne recouvre pas la tête de Red.
- **Pokémon en cage (R116, C10)** : `OBJ_EVENT_GFX_CF_CAGED_PIKACHU/EEVEE/RATTATA` (32×32, `graphics/object_events/pics/misc/cf_caged.png`, généré par `tools/qa/make_cf_caged.py`), palette `OBJ_EVENT_PAL_TAG_CF_CAGE` = 0x1170 (inscrite dans `sObjectEventSpritePalettes`, `src/event_object_movement.c`). Objets `LOCALID_CF_R116_CAGE_1–3` (VIS_46).
- **Clochette** : `ITEM_CLOCHETTE` = 874, objet rare (poche OBJ. RARES) remis au prologue.
- **Nom de poche** (`src/data/script_menu.h`) : `STDSTRING_KEYITEMS` = « OBJ. RARES », comme l’étiquette du sac (remplace « OBJETS CLÉS » de CF-12).
- **Tunnel Mérazon** (`data/maps/RusturfTunnel/map.json`) : météo `WEATHER_NONE` (le brouillard horizontal délavait tout l’écran).
- Fichiers : `src/confluence.c`, `include/confluence.h`, `data/specials.inc`, `include/constants/event_objects.h`, `src/data/object_events/{object_event_graphics,object_event_graphics_info,object_event_graphics_info_pointers,object_event_pic_tables}.h`, `src/event_object_movement.c` (1 ligne : palette).

### CF-14. Pokémon sauvages tous femelles (graine du RNG)
- **Symptôme :** tous les Pokémon sauvages étaient femelles.
- **Cause :** en vanilla, le RNG est semé (et son avance à chaque frame débloquée, `sRngLoopUnlocked`) par `SeedRngAndSetTrainerId` sur l’écran de nom, que le hack saute. `gRngValue` restait à l’état initial : `Random()` donnait toujours la même courte suite de petites valeurs, l’octet de genre de la personnalité était bas, d’où des femelles partout (et la moitié basse de l’ID dresseur valait toujours 0). Les dresseurs ne sont pas touchés : le genre de leurs Pokémon vient d’un hachage de l’équipe (`GeneratePartyHash`) ou du genre imposé dans les données, pas de l’état du RNG.
- **Correctif :** `StartTimer1()` dans `InitMainMenu` (`src/main_menu.c`) et `CF_SeedRngFromMainMenu()` (`src/confluence.c`) appelé dans `Task_HandleMainMenuAPressed` avant le `switch (action)` (couvre Nouvelle partie **et** Continuer). La fonction appelle `SeedRngAndSetTrainerId()` (Timer1 → graine + moitié basse de l’ID) puis mélange `gMain.vblankCounter1` et l’heure RTC dans `SeedRng`/`SeedRng2`.
- **Vérifié :** test `Wild genders: Route 104 grass…` (les deux genres sortent) ; gbaplay : `sRngLoopUnlocked = 1`, `gRngValue` avance à chaque frame, et deux délais différents au menu (10 / 37 frames) donnent des graines, ID (0xAC0C / 0x4B12) et personnalités différentes.

### CF-15. Obéissance : tous les Pokémon obéissent
- `CF_ALWAYS_OBEY` (`include/confluence.h`, `TRUE`). Dans `GetAttackerObedienceForAction` (`src/battle_util.c`), le test « prologue seulement » (`VAR_CF_CHAPTER == 0`) est remplacé par `if (CF_ALWAYS_OBEY) return OBEYS;` : un Pokémon capturé ou échangé obéit à tout niveau, sans badge. Mettre la macro à `FALSE` rend la règle vanilla.

### CF-16. EXP pour toute l’équipe (pleine, non partagée)
- `CF_IsFullPartyExpEnabled()` (`src/confluence.c`) : toujours vrai en jeu (indépendant de `FLAG_CF_EXP_SHARE`) ; en build de test, piloté par `CF_FLAG_FULL_PARTY_EXP` (= `TESTING_FLAG_UNUSED_3`) pour que les tests d’EXP upstream gardent le comportement vanilla.
- `Cmd_getexp` (`src/battle_script_commands.c`) : chaque membre non K.O. (hors œuf) compte comme porteur de Multi Exp ; `expShareExpValue` = EXP complète (pas de division par le nombre de participants). Les Pokémon envoyés reçoivent la même valeur (pas de cumul). Le plafond de niveau (`GetSoftLevelCapExpValue`) s’applique toujours par Pokémon : au plafond, l’EXP est réduite comme avant.
- **Messages :** même chemin que le Multi Exp Gen 6 : un message « X gagne N Points d’Exp. » par Pokémon envoyé, puis **un seul** « Le reste de l’équipe gagne aussi des Points d’Expérience! » (`STRINGID_TEAMGAINEDEXP`, `src/battle_message.c`, texte raccourci). Les montées de niveau (et apprentissages d’attaque) de chaque Pokémon restent affichées. `test/battle/exp.c` suit le nouveau texte.
- **Tests :** `test/battle/hack_exp.c` (2 tests) : même EXP pour tous, rien pour le K.O., message unique ; témoin sans le flag.

### CF-17. Niveaux sauvages selon le niveau max de l’équipe
- `ChooseWildMonLevel` (`src/wild_encounter.c`) passe son résultat dans `CF_ScaleWildMonLevel(niveau vanilla, min du slot)`.
- Règle (T = plus haut niveau de l’équipe, œufs exclus, `CF_GetPlayerTopLevel`) : 3 % (`CF_WILD_TOP_LEVEL_CHANCE`) au niveau T, sinon uniforme entre T−1 et T−3 ; jamais au-dessus de T ; jamais sous le minimum vanilla du slot (si ce minimum dépasse T, il l’emporte). Exemple : T = 11 → 8–10, 11 environ 3 %.
- Désactivé au prologue (`VAR_CF_CHAPTER == 0`, équipe niv. 62+ et combats mis en scène) et en build de test sauf si `CF_FLAG_LEVEL_SCALING` (= `TESTING_FLAG_UNUSED_4`).
- **Tests :** 3 tests `Wild levels: …` (1000 tirages dans [8, 11] pour T = 11, niveau 11 dans 1–6 % ; plancher du slot ; valeur vanilla au prologue / sans le flag).

### CF-18. Niveaux des dresseurs selon le niveau max de l’équipe
- `CreateNPCTrainerPartyFromTrainer` (`src/battle_main.c`) : `CF_GetTrainerLevelShift` calcule un décalage, appliqué à **toute** l’équipe par `CF_ApplyTrainerLevelShift` (min. 1). L’équipe écrite reste telle quelle (espèces, écarts entre les Pokémon, as au-dessus du reste) ; seule une équipe dont le plus haut Pokémon dépasse la cible est abaissée pour que ce Pokémon tombe sur la cible. Une équipe plus faible n’est **jamais** remontée (plus d’alignement automatique sur le niveau du joueur).
- **Cible :** dresseurs normaux T−1 à T−3, T dans 5 % des combats (`CF_TRAINER_TOP_LEVEL_CHANCE`) ; boss et combats d’histoire = T au maximum.
- **Boss** (`CF_IsBossTrainer`) : toute équipe avec `AI_FLAG_ACE_POKEMON` (tous les combats scénarisés du hack) ou classe Champion d’arène, Conseil 4, Maître, Rival, Admin/Chef Aqua et Magma (et équivalents FRLG).
- Pas de décalage en link, combat enregistré ou Zone de combat ; désactivé au prologue et en test comme CF-17.
- **Tests :** 3 tests `Trainer levels: …` sur des dresseurs locaux (le build de test n’a pas `gTrainers`) : définition des boss ; 100 équipes d’un sbire (plus haut dans [T−3, T], T rare, écarts conservés) ; as du rival plafonné à T, jamais remonté, inchangé sans le flag.

### CF-19. Boutique : texte résiduel sous le Oui/Non
- **Symptôme :** à l’achat, le reste de « Ça fera 200₽… » restait affiché dans la boîte Oui/Non.
- **Cause :** `sShopBuyMenuYesNoWindowTemplates.baseBlock = 0x020E` chevauchait les tuiles de `WIN_MESSAGE` (base 0x01BC, 27×4 tuiles → jusqu’à 0x0227) : la fenêtre Oui/Non dessinait dans les tuiles du message.
- **Correctif :** `baseBlock = 0x0228` (`src/shop.c`), juste après la fenêtre de message (VRAM libre jusqu’au cadre de la boîte). Vente : passe par le menu Oui/Non standard du sac, non concerné. `gText_ThatItemIsSoldOut` (`src/strings.c`) coupé en deux lignes (≤ 212 px chacune). Les autres textes de confirmation de la boutique tiennent dans 2 × 212 px.

### CF-20. Audit de l'affichage des PP (aucun défaut propre au hack)
- **Signalement :** « l'affichage des PP est parfois faux » (menu d'attaque en combat et/ou résumé).
- **Vérifié à l'émulateur (gbaplay, ROM du worktree) :** menu d'attaque du combat du prologue : Tonnerre « PP 15/15 », Fatal-Foudre « PP 10/10 » ; résumé : « PP 35/35 » (mise en page vanilla). Après un Tonnerre, le combat se termine (K.O. en un coup) ; la décrémentation en combat est du code upstream couvert par ses tests.
- **Chemins du hack qui créent un jeu d'attaques, tous relus :** `givemon … move1=…` de l'équipe de Red (`ScriptGiveMonParameterized` → `SetMonMoveSlot`, qui pose les PP) ; équipes de dresseurs CF-18 (seul le niveau passé à `CreateMon` change, les attaques et PP sont posés ensuite par le code upstream) ; épidémies (`SetMonMoveSlot` vanilla, `wild_encounter.c`) ; niveaux sauvages CF-17 (niveau seulement) ; CF-16 (EXP seulement) ; `CF_RemovePartyMon` (copie/zéro de structures entières) ; choix du meneur (indices seulement) ; textes de combat (aucun texte de PP modifié). Aucun ne laisse des PP incohérents avec l'attaque.
- **Garde-fous :** 2 tests `PP: …` (`test/hack_engine.c`) : l'équipe `givemon` du prologue et une équipe de dresseur décalée par CF-18 ont des PP égaux à `CalculatePPWithBonus` pour chaque emplacement (0 pour un emplacement vide).
- Si le défaut réapparaît, noter le Pokémon, l'attaque, l'écran et le moment (après un level-up, une capture, un échange de place…) : rien dans le code du hack ne touche aux PP.

### CF-21. Chaussures de course dès le départ
- `CF_DemoNewGameInit` (`src/confluence.c`, appelé par `NewGameInitData`) : `FlagSet(FLAG_SYS_B_DASH)`. En vanilla, le flag n'est posé que par Maman à Bourg-en-Vol (`data/maps/LittlerootTown/scripts.inc`), scène que la démo ne joue jamais.

### CF-22. Carte dresseur : portrait de Red / Leaf
- **Symptôme :** la carte dresseur montrait Brendan (ou May) au lieu de Red.
- **Cause :** `src/trainer_card.c` choisit le portrait dans sa propre table `sTrainerPicFacilityClass[CARD_TYPE_EMERALD]` (Brendan/May) au lieu de `PlayerGenderToFrontTrainerPicId` (corrigé en B).
- **Correctif :** `[MALE] = OW_KANTO_PLAYER_AVATAR ? FACILITY_CLASS_RED : FACILITY_CLASS_BRENDAN`, idem `LEAF`/`MAY`. La palette est celle du portrait choisi (vérifié à l'émulateur : Red net, bonnes couleurs).
- **Badge de Roche (ch. 1) :** le badge 1 (`FLAG_BADGE01_GET`) s'affiche avec son sprite vanilla sur le verso de la carte (vérifié à l'émulateur). Les graphismes de badges ne sont utilisés que par `trainer_card.c` : aucun autre écran à corriger.

### CF-23. Titre « CONFLUENCE », Rappels de nature, divers
- **Titre :** en-tête ROM `TITLE ?= CONFLUENCE` (`Makefile`, vérifié : `CONFLUENCE\0\0BPEF` à 0xA0) ; crédits : `sCreditsText_PkmnEmeraldVersion` = « POKéMON VERSION CONFLUENCE » (`src/data/credits.h`). Le code du jeu (`GAME_CODE`, `VERSION_EMERALD`) est inchangé.
- **Aromates (mints) variés** sur les cartes de la démo (flags des objets conservés) :

| Carte | Objet avant | Objet après |
|---|---|---|
| Route 104 (ball visible) | `ITEM_X_ACCURACY` | `ITEM_ADAMANT_MINT` |
| Route 104 (caché) | `ITEM_HEART_SCALE` | `ITEM_BOLD_MINT` |
| Bois Clémenti | `ITEM_X_ATTACK` | `ITEM_JOLLY_MINT` |
| Route 116 (ball visible) | `ITEM_X_SPECIAL` | `ITEM_MODEST_MINT` |
| Route 116 (caché) | `ITEM_BLACK_GLASSES` | `ITEM_CALM_MINT` |
| Tunnel Mérazon | `ITEM_POKE_BALL` | `ITEM_TIMID_MINT` |

### CF-24. Textes de variation de stats en français naturel
- **Avant :** « Ah, Attaque du PIKACHU augmente! » (article « du » faux devant un surnom, « Ah, » parasite).
- **Après :** `STRINGID_STATROSE` / `STRINGID_STATFELL` = « {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} augmente/baisse{B_BUFF2}! », `gText_DefendersStatRose` idem avec `{B_DEF_NAME_WITH_PREFIX}`, `gText_PkmnsXPreventsSwitching` « du » → « de » (`src/battle_message.c`). `sText_Accuracy` / `sText_Evasiveness` capitalisés (« Précision », « Esquive ») comme les autres noms de stats, car ils ouvrent désormais la phrase.
- Tests : les 108 fichiers de `test/` qui attendent ces textes suivent (« X de … », Précision/Esquive en tête).

### CF-25. Intro des combats de dresseurs, classe « SBIRE ROCKET »
- `sText_Trainer1WantsToBattle` = « {B_TRAINER1_NAME_WITH_CLASS}\nveut se battre! », `sText_TwoTrainersWantToBattle` = « X et\nY\lveulent se battre! » (au lieu de « Un combat est lancé par … ») ; `test/battle/battle_message.c` suit.
- `gTrainerClasses[TRAINER_CLASS_TEAM_ROCKET_FRLG]` : « TEAM ROCKET » → « ROCKET » (`src/battle_main.c`). `IsTrainerIdToSwap` inverse classe et nom pour cette classe : l'intro affiche « SBIRE ROCKET » (nom de dresseur « SBIRE ») au lieu de « SBIRE TEAM ROCKET ».

### CF-26. « DURÉE JEU »
- `gText_TrainerCardTime`, `gText_SavingTime` (`src/strings.c`) et `gText_ContinueMenuTime` (`src/main_menu.c`) : « DUREE JEU » → « DURÉE JEU » (É = 0x06 dans `charmap.txt`, même largeur que E : 51 px).

### CF-27. Brice suiveur : pas de proposition de soin si l'équipe va bien
- Special `CF_PartyNeedsHeal` (`src/confluence.c`, `data/specials.inc`) : `VAR_RESULT` = TRUE si un Pokémon (hors œuf) a perdu des PV, a un statut ou a dépensé des PP (`CalculatePPWithBonus`).
- `CF_Brice_FollowerTalk` (`data/scripts/cf_brice_follower.inc`) : si FALSE, Brice dit « Tout le monde est en pleine forme. On continue ? » sans Oui/Non ni soin.

### CF-28. Anciennes sauvegardes : script de Brice suiveur restauré
- **Symptôme :** une sauvegarde faite avant le branchement de `CF_Brice_FollowerTalk` garde `NPCfollower.script = NULL` (SaveBlock3) : parler à Brice ne fait rien.
- **Correctif :** `CF_RepairFollowerNPCScript` (`src/confluence.c`), appelé en tête de `CreateFollowerNPCAvatar` (`src/follower_npc.c`, au chargement de chaque carte) : si un suiveur existe, que son script est NULL et que son sprite est `OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL` (Brice, seul suiveur PNJ du hack), le script redevient `CF_Brice_FollowerTalk`. Aucun autre champ ni format de sauvegarde modifié.

## Tests (`make check`)

Commande : `make check -j4 ROMTEST=/opt/mgba-tools/bin/mgba-rom-test ROMTESTHYDRA=/opt/mgba-tools/bin/mgba-rom-test-hydra` (log : `/home/user/check_engine.log`).

| | Upstream 1.16.4 | Projet (2026-10-14) | Projet (2026-10-16, CF-13 à CF-19) | Projet (CF-20 à CF-23) |
|---|---|---|---|---|
| PASSED | 4 937 | **4 949** (+12 tests projet) | **4 976** (dont 2 `hack_exp` + 7 `hack_engine` CF-14/17/18) | **4 978** (+2 `PP: …`) |
| FAILED | 0 | **0** | **0** | **0** |
| KNOWN_FAILING / TO_DO / EXPECT_FAILING | 13 / 595 / 8 | 13 / 595 / 8 | 13 / 595 / 8 | 13 / 595 / 8 |
| ASSUMPTIONS_FAILED | 0 | 1 (`Level cap: soft cap reduces exp…`, volontaire : `EXP_CAP_NONE` en build de test) | 1 (idem) | 1 (idem) |
| TOTAL | 5 553 | 5 566 | 5 593 | 5 595 |

Historique : un passage intermédiaire avait 4 échecs (3 tests d'EXP upstream cassés par le plafond souple → corrigé par l'override de `config/test.h` ; 1 test « choix du meneur » inexprimable → remplacé par des tests unitaires).

## Fichiers touchés (résumé)

`Makefile`, `include/config/{battle,caps,general,overworld,test,wild_encounter}.h`, `include/constants/{battle,event_objects,flags,vars}.h`, `include/{battle_setup,wild_encounter,script_affinity}.h`, `src/{battle_controllers,battle_setup,caps,event_data,event_object_movement,overworld,pokemon,script_affinity,trainer,trainer_see,wild_encounter}.c`, `src/data/object_events/{object_event_anims,object_event_graphics,object_event_graphics_info,object_event_graphics_info_pointers,object_event_pic_tables}.h`, `asm/macros/event.inc`, `data/scripts/trainer_battle.inc`, `data/specials.inc`, `test/hack_engine.c`, `test/battle/hack_choose_lead.c`. CF-13 à CF-19 : `include/confluence.h`, `src/{confluence,main_menu,wild_encounter,battle_main,battle_util,battle_script_commands,battle_message,shop,strings}.c`, `test/hack_engine.c`, `test/battle/{exp,hack_exp}.c`. CF-20 à CF-23 : `Makefile`, `src/{confluence,trainer_card}.c`, `src/data/credits.h`, `data/maps/{Route104,PetalburgWoods,Route116,RusturfTunnel}/map.json`, `test/hack_engine.c`. CF-24 à CF-28 : `include/confluence.h`, `src/{battle_message,battle_main,confluence,follower_npc,main_menu,strings}.c`, `data/specials.inc`, `data/scripts/cf_brice_follower.inc`, `test/battle/**` (textes attendus).
