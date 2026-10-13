# FEATURE_INVENTORY.md — Inventaire des fonctionnalités (configs)

> Base pokeemeraude-expansion 1.16.4. Toutes les valeurs ci-dessous sont **lues dans `include/config/*.h`** [V] sauf mention [I].
> `GEN_LATEST = GEN_9` (`general.h`). Un interrupteur « flag/var = 0 » signifie **fonction désactivée tant qu'on n'y affecte pas un `FLAG_UNUSED_*` / `VAR_UNUSED_*`**.
> Les flags valant 0 : `FlagGet(0)` renvoie toujours FALSE (`src/event_data.c:227-273`).

## 1. Espèces (`species_enabled.h`) [V]

- `P_GEN_1_POKEMON` … `P_GEN_9_POKEMON` = **TRUE** (l.9-17) ; 539 `P_FAMILY_*` tous dérivés de leur génération (aucun forcé à FALSE).
- Formes : `P_MEGA_EVOLUTIONS`, `P_PRIMAL_REVERSIONS`, `P_ULTRA_BURST_FORMS`, `P_GIGANTAMAX_FORMS`, `P_TERA_FORMS`, `P_GEN_9_MEGA_EVOLUTIONS` (Z-A), `P_FUSION_FORMS`, `P_REGIONAL_FORMS` (Alola/Galar/Hisui/Paldea), `P_PIKACHU_EXTRA_FORMS`, `P_CROSS_GENERATION_EVOS`, `P_NEW_EVOS_IN_REGIONAL_DEX` = **TRUE** (l.20-55).
- **Comptage (lu dans la ROM de référence)** : 1 571 entrées actives sur 1 572 ID ; **1 025 espèces nationales** ; seule inactive : Lugia Obscur (1435). 88 ID Méga, 37 ID Gigamax.
- Réduire la ROM : désactiver des familles ici (préféré à `P_CRIES_ENABLED FALSE`). ROM libre actuelle ≈ 6,7 Mio, donc pas nécessaire a priori.

## 2. Interrupteurs par fichier de config

### general.h
`GEN_LATEST GEN_9` ; `BUGFIX` défini ; `EXPANSION_INTRO TRUE` (intro RHH) ; `UNITS_METRIC` ; `CHAR_DEC_SEPARATOR CHAR_PERIOD` (en FR on attendrait `CHAR_COMMA`, cosmétique) ; `AUTO_LOWERCASE_KEYBOARD GEN_LATEST` ; printf mGBA hors release (`LOG_HANDLER_MGBA_PRINT`).

### battle.h (424 l.) — l'essentiel en GEN_9
- Mécaniques : crit/paralysie/brûlure/exp **Gen 9** (`B_EXP_CATCH`, `B_SPLIT_EXP` = Exp. partagée Gen6+, `B_SCALED_EXP`), `B_BADGE_BOOST` Gen9 (= pas de boost de badges), `B_OBEDIENCE_MECHANICS` Gen9.
- Flags (l.251-263) : boosts de badges (inactifs car Gen9), `B_FLAG_INVERSE_BATTLE 0`, `B_FLAG_AI_VS_AI_BATTLE 0`, `B_FLAG_DYNAMAX_BATTLE 0`, `B_FLAG_TERA_ORB_CHARGED 0`, `B_FLAG_TERA_ORB_NO_COST 0`, `B_FLAG_SLEEP_CLAUSE 0`, `B_FLAG_NO_WHITEOUT 0`.
- Vars (l.268-280) : `B_VAR_WILD_AI_FLAGS 0`, **`B_VAR_DIFFICULTY 0`**, `B_VAR_NO_BAG_USE 0`, `B_FLAG_SKY_BATTLE 0`, `B_VAR_SKY_BATTLE 0`.
- QoL combat (l.321-335) : `B_FAST_INTRO_PKMN_TEXT TRUE`, `B_FAST_INTRO_NO_SLIDE FALSE`, `B_FAST_HP_DRAIN TRUE`, `B_FAST_EXP_GROW TRUE`, `B_SHOW_TARGETS TRUE`, `B_SHOW_CATEGORY_ICON TRUE`, `B_SHOW_MOVE_DESCRIPTION TRUE` (touche L), `B_WAIT_TIME_MULTIPLIER 16` (vanilla ; baisser = combats plus rapides), `B_QUICK_MOVE_CURSOR_TO_RUN FALSE`, **`B_RUN_TRAINER_BATTLE TRUE`** (fuir un dresseur = défaite/whiteout), `B_SHOW_TYPES SHOW_TYPES_NEVER` (l.400), `B_SHOW_EFFECTIVENESS SHOW_EFFECTIVENESS_SEEN` (l.406), `B_LAST_USED_BALL TRUE` (R), `B_CATCH_SWAP_INTO_PARTY Gen9`, `B_CRITICAL_CAPTURE TRUE`.
- Divers : `B_SLEEP_CLAUSE FALSE` (l.364), `B_TRAINERS_KNOCK_OFF_ITEMS TRUE`, `B_TRAINER_MON_RANDOM_ABILITY FALSE`, `B_MULTI_HALF_TEAMS FALSE`, `B_USE_FROSTBITE FALSE`, `B_AFFECTION_MECHANICS TRUE`, `B_PREFERRED_ICE_WEATHER BOTH`, `B_TERRAIN_BG_CHANGE TRUE`.
- Party pools (l.414-422) : `B_POOL_SETTING_CONSISTENT_RNG FALSE`, toutes les clauses FALSE.

### ai.h
Uniquement des seuils/probabilités (switch %, `AI_ROLL_*`, `PREDICT_SWITCH_CHANCE 50`, `PREDICT_MOVE_CHANCE 100`, tera…). **Les drapeaux d'IA se choisissent par dresseur** (`AI:` dans `trainers.party`, constantes `include/constants/battle_ai.h`). Préréglages : `Basic Trainer` = CheckBadMove|TryToFaint|CheckViability ; `Smart Trainer` = Basic + Omniscient + SmartSwitching + SmartMonChoices + PPStallPrevention + SmartTera + … ; `Prediction`, `Assumptions`. Vanilla : 640 dresseurs en `Check Bad Move` seul.

### caps.h
`B_EXP_CAP_TYPE EXP_CAP_NONE` (l.14), `B_LEVEL_CAP_TYPE LEVEL_CAP_NONE` (l.15), `B_LEVEL_CAP_VARIABLE 0`, `B_RARE_CANDY_CAP FALSE`, `B_LEVEL_CAP_EXP_UP FALSE`, `B_EV_CAP_TYPE EV_CAP_NONE` (l.28, **ligne corrompue : commentaire fusionné avec une 2e définition**), `B_EV_CAP_VARIABLE 8` (l.29, invalide), `B_EV_ITEMS_CAP FALSE`. Tables par badge : `src/caps.c:10-21` (niveaux) et `:87-97` (EV).

### debug.h
`DEBUG_OVERWORLD_MENU`, `DEBUG_BATTLE_MENU`, `DEBUG_POKEMON_SPRITE_VISUALIZER` = `DISABLED_ON_RELEASE` ; touche `R` + START ; `DEBUG_OVERWORLD_IN_MENU FALSE` ; `DEBUG_AI_DELAY_TIMER FALSE`.

### dexnav.h
`DEXNAV_ENABLED FALSE`, `USE_DEXNAV_SEARCH_LEVELS FALSE` (1 o/espèce en SB3 = 1 573 o), `DN_FLAG_SEARCHING/DEXNAV_GET/DETECTOR_MODE 0`, `DN_VAR_SPECIES/STEP_COUNTER 0` (**tous requis non nuls si activé**).

### follower_npc.h
`FNPC_ENABLE_NPC_FOLLOWERS FALSE` (agrandit SB3), flags soin/combat sauvage partenaire 0, `FNPC_NPC_FOLLOWER_PARTY_PREVIEW TRUE`, etc.

### overworld.h
`OW_RUNNING_INDOORS GEN_LATEST` (l.5, **course en intérieur ON**), `SLOW_MOVEMENT_ON_STAIRS FALSE`, `OW_POISON_DAMAGE Gen9` (pas de dégâts), `OW_WHITEOUT_CUTSCENE Gen9`, `OW_DEFOG_FIELD_MOVE/OW_ROCK_CLIMB_FIELD_MOVE FALSE`, `OW_CHOOSE_FROM_PC_AND_PARTY TRUE`, `OW_SHOW_ITEM_DESCRIPTIONS OFF` (l.21), PC Gen9 (`OW_PC_HEAL` = pas de soin au dépôt), baies Gen3 (mutations/humidité OFF), **`OW_POKEMON_OBJECT_EVENTS TRUE`** (l.50), `OW_GFX_COMPRESS TRUE`, **`OW_FOLLOWERS_ENABLED FALSE`** (l.61), `B_FLAG_FOLLOWERS_DISABLED 0`, temps : `OW_TIMES_OF_DAY Gen9`, `OW_USE_FAKE_RTC FALSE` (l.93), `OW_TIME_OF_DAY_ENCOUNTERS FALSE` (l.95), **`OW_ENABLE_DNS TRUE`** (l.102, teinte jour/nuit), `OW_OBJECT_VANILLA_SHADOWS FALSE`, flags `OW_FLAG_PAUSE_TIME/NO_TRAINER_SEE/NO_COLLISION/POKE_RIDER 0` (l.110-113), **`OW_POPUP_GENERATION GEN_3`** (l.118 ; GEN_5 = popups BW2), `OW_REMATCH_BADGE_COUNT 5`, `OW_AMBIENT_CRIES VANILLA`.

### wild_encounter.h
`WE_VANILLA_RANDOM TRUE`, `WE_FLAG_NO_ENCOUNTER 0`, **`WE_DOUBLE_WILD_CHANCE 0`** (l.9), `WE_FLAG_FORCE_DOUBLE_WILD 0`, `WE_SMART_WILD_AI_FLAG 0`, `WE_FLAG_NO_CATCHING 0`, `WE_FLAG_NO_RUNNING 0`, **`WE_OW_ENCOUNTERS FALSE`** (l.20, rencontres visibles ; recommande `OW_GFX_COMPRESS FALSE` si activé) + ~20 options OWE.

### item.h
`I_SHINY_CHARM_ADDITIONAL_ROLLS 2`, `I_KEY_ESCAPE_ROPE Gen9` (Corde Sortie = objet clé), `I_REUSABLE_TMS FALSE` (l.26), **`I_EXP_SHARE_FLAG 0` / `I_EXP_SHARE_ITEM GEN_5`** (l.31-32 ; mais `B_SPLIT_EXP` Gen9), `VAR_LAST_REPEL_LURE_USED 0`, `I_REPEL_LURE_MENU TRUE`, **`I_VS_SEEKER_CHARGING 0`** (l.40 : VS Seeker désactivé, rematches via Match Call), `I_ORAS_DOWSING_FLAG 0`, `I_USE_EVO_HELD_ITEMS_FROM_BAG FALSE`, prix/vente Gen9 (vente = 1/4).

### pokemon.h
Données Gen9 (types/stats/talents/learnsets `P_LVL_UP_LEARNSETS GEN_LATEST`), éclosion niv. 1, `P_FRIENDSHIP_EVO_THRESHOLD` Gen9 (160), `P_CRIES_ENABLED TRUE`, `P_FOOTPRINTS TRUE`, sprites style Gen4/5 (`P_GBA_STYLE_SPECIES_GFX FALSE`), `P_EV_CAP` 252, `P_SHOW_TERA_TYPE GEN_8` (type Téra masqué au résumé), `P_CAN_FORGET_HIDDEN_MOVE FALSE`, `P_LEGENDARY_PERFECT_IVS` Gen9, `P_FLAG_FORCE_SHINY/NO_SHINY 0`, `P_LEARNSET_HELPER_TEACHABLE TRUE` (CT/tuteurs générés par script Python).

### summary_screen.h
`P_SUMMARY_SCREEN_NATURE_COLORS TRUE`, `P_SUMMARY_SCREEN_RENAME TRUE`, `P_SUMMARY_SCREEN_IV_EV_INFO FALSE` (l.9), `P_FLAG_SUMMARY_SCREEN_IV_EV_INFO 0`, `P_ENABLE_MOVE_RELEARNERS FALSE` (l.33), `P_SUMMARY_SCREEN_MOVE_RELEARNER TRUE` (l.51 : réapprentissage depuis le résumé).

### pokedex_plus_hgss.h
`POKEDEX_PLUS_HGSS FALSE` (+ options décapé/dark mode FALSE).

### save.h
`SKIP_SAVE_CONFIRMATION FALSE` ; tous les `FREE_*` FALSE (libérables : SB1 2 516 o, SB2 1 274 o ; total 3 790 o).

### Autres
- `text.h` : `AUTO_SCROLL_TEXT FALSE`, modificateurs de vitesse = 1, `TEXT_SPEED_INSTANT FALSE`, `FLAG_TEXT_SPEED_INSTANT 0`.
- `name_box.h` : `OW_FLAG_SUPPRESS_NAME_BOX 0`, `OW_NAME_BOX_USE_DYNAMIC_WIDTH TRUE`, `OW_NAME_BOX_NPC_TRAINER FALSE`.
- `quickstart.h` : `ENABLE_QUICKSTART TRUE` (SELECT à l'écran titre, hors release).
- `map_preview_screen.h` : `MPS_ENABLE_MAP_PREVIEWS IS_FRLG` (=FALSE en Émeraude).
- `fishing.h` : morsure Gen9, mini-jeu Gen3, chaînes/proximité FALSE.
- `pokerus.h` : `P_POKERUS_ENABLED TRUE`, Gen9.
- `contest.h` : catégories/effets Gen9.
- `test.h` : surcharges **uniquement** sous `TESTING` (active toutes formes/espèces pour `make check`).

## 3. Tableau des mécaniques majeures

| Mécanique | Disponibilité technique réelle | Statut initial | Dépendances | Risques | Comment tester |
|---|---|---|---|---|---|
| Méga-Évolution | Complète (88 formes, sprites, cris `P_MODIFIED_MEGA_CRIES`) | Données ON ; **joueur bloqué** : nécessite `ITEM_MEGA_RING` dans le sac (`src/battle_util.c:8476-8480`) ; aucun script ne le donne | Méga-Gemme tenue ; Bracelet Méga ; dresseurs IA : Méga-Gemme dans `trainers.party` | Équilibrage ; objets à placer | Debug menu → donner Mega Ring + Lucarite ; `make check TESTS="Mega"` |
| Z-Moves | Complète | Bloqué joueur : `ITEM_Z_POWER_RING` requis (`src/battle_z_move.c:121,187`) | Cristal Z tenu | Équilibrage | Debug : donner anneau + cristal ; tests `Z-Move` |
| Dynamax / Gigamax | Complète (37 formes Gmax) | **Doublement bloqué joueur** : `ITEM_DYNAMAX_BAND` + `B_FLAG_DYNAMAX_BATTLE` (=0 ⇒ impossible) (`src/battle_dynamax.c:84-89`) ; flag effacé en sortie de combat (`src/overworld.c:454`). IA : `Dynamax Level`/`Gigantamax` dans le `.party` | Flag libre à assigner, script qui le pose avant le combat | Hors esprit GBA ; animations lourdes | Assigner flag, debug donner bracelet, `setflag` puis combat |
| Téracristal | Complète | Bloqué joueur : `ITEM_TERA_ORB` + `B_FLAG_TERA_ORB_CHARGED` (=0 ⇒ jamais chargé) (`src/battle_terastal.c:77-87`) ; IA : `Tera Type:` dans le `.party` | 1–2 flags ; recharge au soin (`src/script_pokemon_util.c:47`) | Type Téra masqué (`P_SHOW_TERA_TYPE GEN_8`) | Assigner flags, donner orbe, combattre |
| Primo-Résurgence | Complète (Groudon/Kyogre + Orbes) | ON : déclenché à l'entrée en combat si Orbe tenu, aucun objet clé (`src/battle_util.c:4845`, `src/data/pokemon/form_change_tables.h:739,750`) | Orbe Rouge/Bleu tenu | — | Donner Kyogre + Orbe Bleu via debug |
| Ultra-Explosion | Complète (Necrozma) | Bloqué joueur : `ITEM_Z_POWER_RING` (`src/battle_util.c:8520`) | Ultranecrozium Z | — | Debug |
| Level caps | Implémenté (`src/caps.c`) | **OFF** (`EXP_CAP_NONE`, `LEVEL_CAP_NONE`) | Choisir HARD/SOFT + FLAG_LIST (table badges) ou VARIABLE (+ var libre) ; `B_RARE_CANDY_CAP` | Table par défaut calée sur Hoenn vanilla | Modifier config, gagner exp au-delà du cap |
| EV caps | Implémenté | OFF | Corriger `caps.h:28-29` d'abord | Ligne corrompue | idem |
| Jour/nuit | RTC + DNS | **Teinte ON** (`OW_ENABLE_DNS TRUE`) ; rencontres par moment OFF | RTC émulateur (game code BPE?) ; `OW_TIME_OF_DAY_ENCOUNTERS` + `wild_encounters.json` | `OW_POPUP_BW_ALPHA_BLEND` incompatible DNS | Changer l'heure (debug / RTC émulateur) |
| Pokémon suiveurs | Complète (sprites OW toutes espèces) | **OFF** | `OW_POKEMON_OBJECT_EVENTS TRUE` (déjà) ; scripts à adapter (`hidefollower`) | VRAM, cutscenes | Mettre TRUE, marcher/warp/surf |
| PNJ suiveurs | Complète (`setfollowernpc`) | OFF | SB3 (`NPCFollower`) ; flags optionnels | Combats partenaire | `docs/tutorials/how_to_follower_npc.md` |
| DexNav | Complète | OFF | 3 flags + 2 vars non nuls ; search levels = 1 573 o SB3 | Budget SB3 | Activer, menu start |
| Pokédex HGSS | Complète | OFF | `POKEDEX_PLUS_HGSS` | Textes UI à traduire/vérifier | Ouvrir Pokédex |
| Doubles sauvages | Complète | OFF (0 %) | `WE_DOUBLE_WILD_CHANCE` ou flag forcé | — | Mettre 100 %, herbe |
| Combat inversé | Complète | OFF (flag 0) | 1 flag | — | `make check TESTS="Inverse"` |
| Sky Battles | Complète | OFF | flag + var | — | tests |
| Party pools dresseurs | Complète (trainerproc `Party Size`, `Pool Rules`…) | Non utilisés par les dresseurs vanilla | `docs/tutorials/how_to_trainer_party_pool.md` | RNG non reproductible (`B_POOL_SETTING_CONSISTENT_RNG FALSE`) | Créer un dresseur pool, combattre plusieurs fois |
| Trainer slides | Complète (`src/trainer_slide.c`) | Tables vides (l.60-72) | Textes par dresseur/difficulté | — | `docs/tutorials/how_to_new_trainer_slide.md` ; tests |
| Drapeaux d'IA | Complète (34 flags) | Vanilla faible (Check Bad Move) | Par dresseur | Smart = omniscient | `make check` (tests IA) ; combats |
| Clause sommeil | Complète | OFF | `B_SLEEP_CLAUSE` ou flag | IA doit avoir CHECK_BAD_MOVE | tests |
| Rencontres visibles (OWE) | Complète | OFF | `OW_POKEMON_OBJECT_EVENTS` ; conseillé `OW_GFX_COMPRESS FALSE` | VRAM, perf | `docs/tutorials/how_to_overworld_wild_encounters.md` |
| Popups carte BW | Complète | OFF (GEN_3) | `OW_POPUP_GENERATION GEN_5` | Alpha + DNS = glitchs | Entrer sur une carte |
| Multichoix dynamique | Complète (`dynmultichoice`, event.inc:1966) | Dispo | — | — | Script test |
| VS Seeker | Complète | OFF (`I_VS_SEEKER_CHARGING 0`) ; Match Call actif | flag ; `vsseeker_rematchid` | Remplace Match Call | `docs/tutorials/vs_seeker.md` |
| Randomizer | **Absent** (seul « random mon generator » pour dresseurs pools / Pyramide : `BATTLE_PYRAMID_RANDOM_ENCOUNTERS`) | — | — | — | — |
| Nuzlocke | **Absent** (aucune occurrence) | — | Briques : `WE_FLAG_NO_CATCHING`, `B_FLAG_NO_WHITEOUT`, level caps | À coder | — |
| Difficulté | Implémenté (`src/difficulty.c`, `Difficulty:` par dresseur, Easy/Normal/Hard, macros `setdifficulty`…) | OFF (`B_VAR_DIFFICULTY 0`) | 1 var libre ; régler **après** `NewGameInitData` | Triple saisie des équipes | `make check` (TESTING_VAR_DIFFICULTY) |
| Refuser un dresseur / choisir son leader | **Absent** (pas de config). Seul proche : `OW_FLAG_NO_TRAINER_SEE` (dresseurs ne voient plus le joueur) ; IA `RANDOMIZE_PARTY_INDICES` | — | 1 flag | — | Debug « toggle trainer see » |
| Options combat rapide | `B_FAST_*` TRUE, `B_WAIT_TIME_MULTIPLIER 16` | Partiellement ON | — | — | — |
| Course en intérieur | `OW_RUNNING_INDOORS Gen9` | **ON** | Chaussures (`FLAG_SYS_B_DASH`) | — | Courir dans un bâtiment |
| Exp. Share Gen6+ | `B_SPLIT_EXP` Gen9 actif ; objet clé `I_EXP_SHARE_FLAG 0` | Partiel | 1 flag | — | — |
| Réapprentissage | Résumé ON ; relearners OFF | Partiel | — | — | Écran résumé > capacités |
| Fuite des combats dresseurs | `B_RUN_TRAINER_BATTLE TRUE` | **ON** (= défaite) | — | Exploit ? (perte d'argent) | Fuir un dresseur |
| Description d'objets OW | Implémenté | OFF | `FIRST_TIME` = save-breaking (SB3) | — | — |
| Menu debug | ON hors release | ON | `make release` le coupe | Ne pas livrer build normale | R+START |
