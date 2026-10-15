# FLAGS_VARS_REGISTRY — registre unique des flags et vars du projet

> **Règle :** tout flag ou var utilisé par le projet est d'abord inscrit ici (ID, nom, propriétaire, usage), puis défini dans `include/constants/flags.h` / `vars.h` en **remplaçant** la ligne `FLAG_UNUSED_*` / `VAR_UNUSED_*` correspondante. Aucun agent n'alloue d'ID sans mettre ce fichier à jour dans le même commit.
> Plages libres de référence : `docs/hack/TECHNICAL_AUDIT.md` §7. Ne jamais utiliser `0x71` (lu par CaveOfOrigin).

## Plages réservées (convention)

| Plage | Réservée à | Remarque |
|---|---|---|
| Flags `0x20–0x2F` | Moteur / systèmes (programmeur moteur) | sauvegardés |
| Flags `0x30–0x4F`, `0x264–0x2BB`, `0x493–0x4EF` | Histoire, choix du joueur, PNJ (design / scénaristes) | sauvegardés ; allocation au fil des besoins |
| Vars `0x40F7–0x40FF` | Moteur / systèmes | sauvegardées |
| Autres `VAR_UNUSED_*` (0x404E, 0x4083, 0x408B, 0x4091, 0x409B, 0x409D, 0x40A1, 0x40A8, 0x40B8, 0x40BB, 0x40DB, 0x40DC, 0x40E5) | Histoire, affinités, factions | voir convention « affinités » dans ENGINE_CHANGES.md §E |

## Flags alloués

| ID | Nom | Propriétaire | Usage | Posé / effacé par |
|---|---|---|---|---|
| `0x20` | `FLAG_NO_WILD_ENCOUNTERS` | Programmeur moteur | Branché sur `WE_FLAG_NO_ENCOUNTER` : tant qu'il est posé, **aucune rencontre sauvage** (herbe, eau, pêche, Éclate-Roc, Doux Parfum / Miel, rencontres visibles). Persistant (sauvegardé) : le script qui le pose doit l'effacer. Aussi basculable depuis le menu debug (Flags/Vars → Encounter). | scripts (`setflag`/`clearflag`) |
| `0x21` | `FLAG_CHOOSE_BATTLE_LEAD` | Programmeur moteur | Branché sur `B_FLAG_CHOOSE_BATTLE_LEAD` : tant qu'il est posé, le joueur choisit son Pokémon de tête avant chaque combat de dresseur scripté. Option joueur à exposer (PNJ, objet ou menu Options plus tard). | scripts / futur menu |

## Vars allouées

| ID | Nom | Propriétaire | Usage |
|---|---|---|---|
| `0x40F7` | `VAR_DIFFICULTY` | Programmeur moteur | `B_VAR_DIFFICULTY` : niveau de difficulté (`DIFFICULTY_EASY=0`, `NORMAL=1`, `HARD=2`). Mis à `DIFFICULTY_NORMAL` par `NewGameInitData` (upstream). Changer avec `setdifficulty DIFFICULTY_HARD`. |

## Configs moteur qui attendent encore un flag/var (non alloués)

| Config | Effet | Statut |
|---|---|---|
| `FLAG_REFUS_*` (argument de `trainerbattle_single_declinable`) | un flag sauvegardé par combat refusable (refus définitif) | **alloués** : `FLAG_CF_REFUS_*` (12) |
| `OW_FLAG_PAUSE_TIME` | pause de l'horloge (exige `OW_USE_FAKE_RTC`) | **non adopté** (voir ENGINE_CHANGES.md §H4) |
| `B_FLAG_NO_WHITEOUT`, `I_EXP_SHARE_FLAG` | défaite sans K.O. ; Multi Exp. | **branchés** : `FLAG_CF_NO_WHITEOUT`, `FLAG_CF_EXP_SHARE` |
| `WE_FLAG_NO_CATCHING`, `WE_FLAG_NO_RUNNING`… | voir `include/config/*.h` | à allouer ici si le design en a besoin |


## Allocation définitive *Confluence* (2026-10-14, programmeur moteur)

**Comptes :** vars **44 / 45** (budget GAME_SYSTEMS §14) ; flags nommés **108** (2 moteur + 12 refus + 8 jalons/systèmes + 24 Dossier + 62 états d'histoire) + **93** de visibilité réservés = **201 / 260**. **Aucun `FLAG_HIDE_*` vanilla recyclé** : GAME_SYSTEMS §14 annonce 40 recyclages « liste au registre », mais aucune liste n'existe ; on réserve donc des ID neufs (règle du brief moteur). Le recyclage reste possible plus tard, carte par carte, avec preuve grep (aucun lecteur C).

**Preuve « libre » (reproductible) :**
- *Vars :* chaque ancien nom (`VAR_UNUSED_*`, `VAR_*_STATE // Unused Var`) : `grep -rlw NOM data src asm test include` → seule occurrence `include/constants/vars.h` (0x404E : un commentaire `// Eg:` de `config/battle.h`). Recherche aussi de l'ID brut (`0x40xx`) : aucune utilisation hors `vars_frlg.h`.
- **Piège trouvé :** `include/constants/vars_frlg.h` est inclus **sans garde** dans la build Émeraude ; ses alias FRLG des mêmes ID sont donc actifs. Vérification ID par ID des alias FRLG dans le code partagé : `0x406E` (`VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE`) est **remis à 0 par `src/overworld.c`** à chaque vol / téléport / K.O. ; `0x4073` est écrit et lu par `src/trainer_fan_club.c` ; `0x4068` est écrit par `data/scripts/hall_of_fame_frlg.inc` (inclus en Émeraude). Ces **trois ID sont exclus**. Les autres alias FRLG ne sont utilisés que dans des scripts `_Frlg` (sous `.if IS_FRLG`) ou dans le cheat debug FRLG (`if (IS_FRLG)`).
- *Flags :* les 227 `FLAG_UNUSED_0x*` des plages 0x22–0x4F, 0x264–0x2BB, 0x493–0x4EF : aucune référence hors `flags.h` (seulement des commentaires `// Eg:` des configs). `flags_frlg.h` n'est inclus que si `IS_FRLG` : ses alias ne sont pas actifs en Émeraude.

### Vars *Confluence* (44)
| ID | Nom | Usage | Ancien nom (preuve : `grep -rw` sans référence hors `vars.h`) |
|---|---|---|---|
| `0x404E` | `VAR_CF_D04` | slots de decision D033-D040 (2 bits) | `VAR_UNUSED_0x404E` |
| `0x4052` | `VAR_CF_BR` | relation 0-100 | `VAR_DEWFORD_TOWN_STATE` |
| `0x4055` | `VAR_CF_BL` | relation 0-100 | `VAR_VERDANTURF_TOWN_STATE` |
| `0x4056` | `VAR_CF_FL` | relation 0-100 | `VAR_PACIFIDLOG_TOWN_STATE` |
| `0x4059` | `VAR_CF_PR` | relation 0-100 | `VAR_MAUVILLE_CITY_STATE` |
| `0x405B` | `VAR_CF_PE` | relation 0-100 | `VAR_FORTREE_CITY_STATE` |
| `0x405C` | `VAR_CF_AM` | relation 0-100 | `VAR_LILYCOVE_CITY_STATE` |
| `0x405F` | `VAR_CF_TI` | relation 0-100 | `VAR_EVER_GRANDE_CITY_STATE` |
| `0x4061` | `VAR_CF_GI` | relation 0-100 | `VAR_ROUTE102_STATE` |
| `0x4062` | `VAR_CF_HO` | relation 0-100 | `VAR_ROUTE103_STATE` |
| `0x4064` | `VAR_CF_REP_L` | reputation 0-100 | `VAR_ROUTE105_STATE` |
| `0x4065` | `VAR_CF_REP_C` | reputation 0-100 | `VAR_ROUTE106_STATE` |
| `0x4066` | `VAR_CF_REP_M` | reputation 0-100 | `VAR_ROUTE107_STATE` |
| `0x4067` | `VAR_CF_REP_A` | reputation 0-100 | `VAR_ROUTE108_STATE` |
| `0x406A` | `VAR_CF_REP_I` | reputation 0-100 | `VAR_ROUTE111_STATE` |
| `0x406B` | `VAR_CF_REP_G` | reputation 0-100 | `VAR_ROUTE112_STATE` |
| `0x406C` | `VAR_CF_REP_P` | reputation 0-100 | `VAR_ROUTE113_STATE` |
| `0x406D` | `VAR_CF_PA` | etat systeme | `VAR_ROUTE114_STATE` |
| `0x4070` | `VAR_CF_RK` | etat systeme | `VAR_ROUTE117_STATE` |
| `0x4075` | `VAR_CF_CHAPTER` | etat systeme | `VAR_ROUTE122_STATE` |
| `0x4076` | `VAR_CF_ECO` | etat systeme | `VAR_ROUTE123_STATE` |
| `0x4077` | `VAR_CF_WORLD` | etat systeme | `VAR_ROUTE124_STATE` |
| `0x4078` | `VAR_CF_BVCOUNT` | etat systeme | `VAR_ROUTE125_STATE` |
| `0x4079` | `VAR_CF_SUMMIT` | etat systeme | `VAR_ROUTE126_STATE` |
| `0x407A` | `VAR_CF_CLIMAX` | etat systeme | `VAR_ROUTE127_STATE` |
| `0x407C` | `VAR_CF_FIN` | etat systeme | `VAR_ROUTE129_STATE` |
| `0x407D` | `VAR_CF_STANCE` | etat systeme | `VAR_ROUTE130_STATE` |
| `0x407E` | `VAR_CF_D00` | slots de decision D001-D008 (2 bits) | `VAR_ROUTE131_STATE` |
| `0x407F` | `VAR_CF_D01` | slots de decision D009-D016 (2 bits) | `VAR_ROUTE132_STATE` |
| `0x4080` | `VAR_CF_D02` | slots de decision D017-D024 (2 bits) | `VAR_ROUTE133_STATE` |
| `0x4081` | `VAR_CF_D03` | slots de decision D025-D032 (2 bits) | `VAR_ROUTE134_STATE` |
| `0x4083` | `VAR_CF_D05` | slots de decision D041-D048 (2 bits) | `VAR_UNUSED_0x4083` |
| `0x408B` | `VAR_CF_D06` | slots de decision D049-D056 (2 bits) | `VAR_UNUSED_0x408B` |
| `0x4091` | `VAR_CF_D07` | slots de decision D057-D064 (2 bits) | `VAR_UNUSED_0x4091` |
| `0x409B` | `VAR_CF_D08` | slots de decision D065-D072 (2 bits) | `VAR_UNUSED_0x409B` |
| `0x409D` | `VAR_CF_D09` | slots de decision D073-D080 (2 bits) | `VAR_UNUSED_0x409D` |
| `0x40A1` | `VAR_CF_D10` | slots de decision D081-D088 (2 bits) | `VAR_UNUSED_0x40A1` |
| `0x40A8` | `VAR_CF_D11` | slots de decision D089-D096 (2 bits) | `VAR_UNUSED_0x40A8` |
| `0x40B8` | `VAR_CF_D12` | slots de decision D097-D104 (2 bits) | `VAR_UNUSED_0x40B8` |
| `0x40BB` | `VAR_CF_D13` | slots de decision D105-D112 (2 bits) | `VAR_UNUSED_0x40BB` |
| `0x40DB` | `VAR_CF_D14` | slots de decision D113-D120 (2 bits) | `VAR_UNUSED_0x40DB` |
| `0x40DC` | `VAR_CF_D15` | slots de decision D121-D128 (2 bits) | `VAR_UNUSED_0x40DC` |
| `0x40E5` | `VAR_CF_D16` | slots de decision D129-D131 (2 bits) | `VAR_UNUSED_0x40E5` |
| `0x40F8` | `VAR_CF_CAP` | B_LEVEL_CAP_VARIABLE (plafond de niveau) | `VAR_UNUSED_0x40F8` |

Libres restantes : `0x40F9`–`0x40FF` (7). Exclues (alias FRLG actifs, voir plus haut) : `0x4068`, `0x406E`, `0x4073`.

**Valeurs de départ** (`CF_InitVars`, appelé par `NewGameInitData`) : relations 50 sauf `HO` 20 ; réputations 50 ; `PA` 20 ; `RK` 20 ; `CAP` 14 ; tout le reste 0.

**Bits (via `getbits` / `setbits`, ENGINE_CHANGES §E-BITS) :** `ECO` = zone Z-0n en bits `2(n-1)`..`2(n-1)+1` (0 ENVAHI, 1 MIXTE, 2 RESTAURÉ, 3 ABATTU) ; `WORLD`, `BVCOUNT`, `STANCE`, `SUMMIT`, `CLIMAX`, `FIN` : disposition GAME_SYSTEMS §2. **Décisions :** Dnnn → `VAR_CF_D(⌊(n−1)/8⌋)`, bits `2·((n−1) mod 8)` ; les 17 vars ne sont **pas** contiguës : toujours passer par `setdecision` / `checkdecision` (table en C).

### Flags *Confluence* nommés (108)
| ID | Nom | Usage |
|---|---|---|
| `0x22` | `FLAG_CF_EXP_SHARE` | I_EXP_SHARE_FLAG: Multi Exp. active (GAME_SYSTEMS 13) |
| `0x23` | `FLAG_CF_NO_WHITEOUT` | B_FLAG_NO_WHITEOUT: defaite sans retour au Centre (combats a deux issues) |
| `0x30` | `FLAG_CF_REFUS_FLORA1` | refus definitif (trainerbattle_single_declinable) |
| `0x31` | `FLAG_CF_REFUS_ALDO` | refus definitif (trainerbattle_single_declinable) |
| `0x32` | `FLAG_CF_REFUS_BOB` | refus definitif (trainerbattle_single_declinable) |
| `0x33` | `FLAG_CF_REFUS_KOGA` | refus definitif (trainerbattle_single_declinable) |
| `0x34` | `FLAG_CF_REFUS_PETER` | refus definitif (trainerbattle_single_declinable) |
| `0x35` | `FLAG_CF_REFUS_ONDINE` | refus definitif (trainerbattle_single_declinable) |
| `0x36` | `FLAG_CF_REFUS_BRICE4` | refus definitif (trainerbattle_single_declinable) |
| `0x37` | `FLAG_CF_REFUS_TIMMY` | refus definitif (trainerbattle_single_declinable) |
| `0x38` | `FLAG_CF_REFUS_GIO1` | refus definitif (trainerbattle_single_declinable) |
| `0x39` | `FLAG_CF_REFUS_GIO2` | refus definitif (trainerbattle_single_declinable) |
| `0x3A` | `FLAG_CF_REFUS_BLUE1` | refus definitif (trainerbattle_single_declinable) |
| `0x3B` | `FLAG_CF_REFUS_BLUE2` | refus definitif (trainerbattle_single_declinable) |
| `0x3C` | `FLAG_CF_M_PLANQUE` | jalon / systeme |
| `0x3D` | `FLAG_CF_M_MEMORIA` | jalon / systeme |
| `0x3E` | `FLAG_CF_M_FONDMER` | jalon / systeme |
| `0x3F` | `FLAG_CF_M_CLIMAX` | jalon / systeme |
| `0x40` | `FLAG_CF_KIOSK_OUVERT` | jalon / systeme |
| `0x41` | `FLAG_CF_HOOPA_SUIVEUR` | jalon / systeme |
| `0x42` | `FLAG_CF_HIDDEN_ENDING` | jalon / systeme |
| `0x43` | `FLAG_CF_GIO_DISSOUT` | jalon / systeme |
| `0x264` | `FLAG_CF_DOS_JOURNAL_NOEUD` | Dossier, piece facultative |
| `0x265` | `FLAG_CF_DOS_CLOCHETTE_PIKO` | Dossier, piece facultative |
| `0x266` | `FLAG_CF_DOS_AFFICHE_SYLPHE` | Dossier, piece facultative |
| `0x267` | `FLAG_CF_DOS_HORAIRE_R116` | Dossier, piece facultative |
| `0x268` | `FLAG_CF_DOS_ECLATS` | Dossier, piece facultative |
| `0x269` | `FLAG_CF_DOS_SCHEMA_CABLE` | Dossier, piece facultative |
| `0x26A` | `FLAG_CF_DOS_TRACE_ANNEAU` | Dossier, piece facultative |
| `0x26B` | `FLAG_CF_DOS_CARNET_PRIMES` | Dossier, piece facultative |
| `0x26C` | `FLAG_CF_DOS_JOURNAUX` | Dossier, piece facultative |
| `0x26D` | `FLAG_CF_DOS_ETOILES` | Dossier, piece facultative |
| `0x26E` | `FLAG_CF_DOS_SCEAUX_ANCIENS` | Dossier, piece facultative |
| `0x26F` | `FLAG_CF_DOS_HORAIRE_VENDU` | Dossier, piece facultative |
| `0x270` | `FLAG_CF_DOS_LAMBDA` | Dossier, piece facultative |
| `0x271` | `FLAG_CF_DOS_DONNEES_INSTITUT` | Dossier, piece facultative |
| `0x272` | `FLAG_CF_DOS_VISION` | Dossier, piece facultative |
| `0x273` | `FLAG_CF_DOS_ARTICLE_CHEN` | Dossier, piece facultative |
| `0x274` | `FLAG_CF_DOS_PLAN_CABLE` | Dossier, piece facultative |
| `0x275` | `FLAG_CF_OBJ_LETTRE_FERRAND` | Dossier, piece facultative |
| `0x276` | `FLAG_CF_DOS_VOIX_RELAIS` | Dossier, piece facultative |
| `0x277` | `FLAG_CF_DOS_PREDICTEUR` | Dossier, piece obligatoire |
| `0x278` | `FLAG_CF_DOS_BATTEMENT` | Dossier, piece obligatoire |
| `0x279` | `FLAG_CF_DOS_INSCRIPTION` | Dossier, piece obligatoire |
| `0x27A` | `FLAG_CF_DOS_REGISTRE` | Dossier, piece obligatoire |
| `0x27B` | `FLAG_CF_DOS_GARDIENNE` | Dossier, piece obligatoire |
| `0x27C` | `FLAG_CF_ALDO_RESPECT` | etat d histoire (brief C) |
| `0x27D` | `FLAG_CF_AUGUSTE_DOUTE` | etat d histoire (brief C) |
| `0x27E` | `FLAG_CF_BLUE_LIBRE` | etat d histoire (brief C) |
| `0x27F` | `FLAG_CF_BOB_QUARTIER` | etat d histoire (brief C) |
| `0x280` | `FLAG_CF_BOB_RESPECT` | etat d histoire (brief C) |
| `0x281` | `FLAG_CF_BOIS_SAUVES` | etat d histoire (brief C) |
| `0x282` | `FLAG_CF_BRICE_DEFERE` | etat d histoire (brief C) |
| `0x283` | `FLAG_CF_BRICE_PARLE` | etat d histoire (brief C) |
| `0x284` | `FLAG_CF_BRICE_PUBLIE` | etat d histoire (brief C) |
| `0x285` | `FLAG_CF_BROCK_PROTEGES` | etat d histoire (brief C) |
| `0x286` | `FLAG_CF_CABLE_COUPE` | etat d histoire (brief C) |
| `0x287` | `FLAG_CF_CHEN_CONFRONTE` | etat d histoire (brief C) |
| `0x288` | `FLAG_CF_CHEN_LETTRE_MONTREE` | etat d histoire (brief C) |
| `0x289` | `FLAG_CF_CIVILS_CENTRE` | etat d histoire (brief C) |
| `0x28A` | `FLAG_CF_CIVILS_PORT` | etat d histoire (brief C) |
| `0x28B` | `FLAG_CF_CIVILS_PREPARES` | etat d histoire (brief C) |
| `0x28C` | `FLAG_CF_COPIE_REPRISE` | etat d histoire (brief C) |
| `0x28D` | `FLAG_CF_CREDIT_PARTAGE` | etat d histoire (brief C) |
| `0x28E` | `FLAG_CF_DINER_APAISE` | etat d histoire (brief C) |
| `0x28F` | `FLAG_CF_DUO_BRICE` | etat d histoire (brief C) |
| `0x290` | `FLAG_CF_DUO_PETER` | etat d histoire (brief C) |
| `0x291` | `FLAG_CF_DUO_PR` | etat d histoire (brief C) |
| `0x292` | `FLAG_CF_ERIKA_CONTRAT` | etat d histoire (brief C) |
| `0x293` | `FLAG_CF_FLORA_DESOBEIT` | etat d histoire (brief C) |
| `0x294` | `FLAG_CF_FLORA_DOUTE` | etat d histoire (brief C) |
| `0x295` | `FLAG_CF_FRAGMENT_DOYENNE` | etat d histoire (brief C) |
| `0x296` | `FLAG_CF_FUJI_ATTEND` | etat d histoire (brief C) |
| `0x297` | `FLAG_CF_GIO_TEMOIN` | etat d histoire (brief C) |
| `0x298` | `FLAG_CF_HOOPA_CONFIE` | etat d histoire (brief C) |
| `0x299` | `FLAG_CF_HOOPA_SOIGNE` | etat d histoire (brief C) |
| `0x29A` | `FLAG_CF_INFO_ENTREPOT` | etat d histoire (brief C) |
| `0x29B` | `FLAG_CF_INSIGNE` | etat d histoire (brief C) |
| `0x29C` | `FLAG_CF_JEANNINE_ALLIEE` | etat d histoire (brief C) |
| `0x29D` | `FLAG_CF_KOGA_AVEU` | etat d histoire (brief C) |
| `0x29E` | `FLAG_CF_LAMBDA_DEMASQUE` | etat d histoire (brief C) |
| `0x29F` | `FLAG_CF_LAMBDA_REMARQUE` | etat d histoire (brief C) |
| `0x2A0` | `FLAG_CF_LEO_INSIDER` | etat d histoire (brief C) |
| `0x2A1` | `FLAG_CF_MARCO_ALLIE` | etat d histoire (brief C) |
| `0x2A2` | `FLAG_CF_MARC_SAGES` | etat d histoire (brief C) |
| `0x2A3` | `FLAG_CF_MEWTWO_CAPTURE` | etat d histoire (brief C) |
| `0x2A4` | `FLAG_CF_MEWTWO_LIBRE` | etat d histoire (brief C) |
| `0x2A5` | `FLAG_CF_MORGANE_ALLIEE` | etat d histoire (brief C) |
| `0x2A6` | `FLAG_CF_OLGA_LOKHLASS` | etat d histoire (brief C) |
| `0x2A7` | `FLAG_CF_ONDINE_MISSION` | etat d histoire (brief C) |
| `0x2A8` | `FLAG_CF_PETER_ASSUME` | etat d histoire (brief C) |
| `0x2A9` | `FLAG_CF_PETER_RESPECT` | etat d histoire (brief C) |
| `0x2AA` | `FLAG_CF_PETITION` | etat d histoire (brief C) |
| `0x2AB` | `FLAG_CF_PRET_CIVILS` | etat d histoire (brief C) |
| `0x2AC` | `FLAG_CF_PR_ACCUSE` | etat d histoire (brief C) |
| `0x2AD` | `FLAG_CF_PR_PREUVE` | etat d histoire (brief C) |
| `0x2AE` | `FLAG_CF_REL_AMA_ARAGON` | etat d histoire (brief C) |
| `0x2AF` | `FLAG_CF_REL_AUGUSTE_FUJI` | etat d histoire (brief C) |
| `0x2B0` | `FLAG_CF_REL_CHEN_SEKO` | etat d histoire (brief C) |
| `0x2B1` | `FLAG_CF_REL_ONDINE_ARTHUR` | etat d histoire (brief C) |
| `0x2B2` | `FLAG_CF_RITE_PREPARE` | etat d histoire (brief C) |
| `0x2B3` | `FLAG_CF_RITE_PROTEGE` | etat d histoire (brief C) |
| `0x2B4` | `FLAG_CF_SARAH_DOUTE` | etat d histoire (brief C) |
| `0x2B5` | `FLAG_CF_SARAH_TEMOIN` | etat d histoire (brief C) |
| `0x2B6` | `FLAG_CF_STANCE_ERIKA_INT` | etat d histoire (brief C) |
| `0x2B7` | `FLAG_CF_STANCE_MAX_ECOUTE` | etat d histoire (brief C) |
| `0x2B8` | `FLAG_CF_TIMMY_SAUVE` | etat d histoire (brief C) |
| `0x2B9` | `FLAG_CF_VOTE_ABATTAGE` | etat d histoire (brief C) |

Alias : `FLAG_CF_PLANQUE_RESOLUE` = `FLAG_CF_M_PLANQUE` ; `FLAG_CF_FONDMER_DONE` = `FLAG_CF_M_FONDMER`.
Non alloués (stockés ailleurs) : `PIKA_BLESSE` / `PIKA_EQUIPE` (WORLD b14-15), `PHRASE_SOMMET` (SUMMIT b14), positions Chen / Sylphe / Koga–Peter / Arthur (STANCE) ; `REFUS_OLGA` / `REFUS_AGATHA` rejetés (ARBITRATION_V3 C7 : macro avec flag de refus 0).
Libres restants : `0x24`–`0x2F` (12, moteur), `0x44`–`0x4F` (12, histoire), `0x2BA`–`0x2BB` (2), + `0x8E5`–`0x91F` (59) non touchés.

### Bloc de visibilité réservé (93)
`FLAG_CF_VIS_00` (`0x493`) … `FLAG_CF_VIS_92` (`0x4EF`), bornes `FLAG_CF_VIS_START` / `FLAG_CF_VIS_END`. Attribution aux objets par les scénaristes, en notant ici « VIS_nn → carte, objet ». Rappel : flag de visibilité posé = objet **caché**.

**Démo ch. 0–1 (GMD, 2026-10-15, `SLICE_DEMO_CH0-1.md` §3) :** VIS_00 Marco (plage R104) · VIS_01 Ciléo (plage) · VIS_02 Ciléo (maison de Marco) · VIS_03 Ciléo (QG, si D006 a) · VIS_04 Ciléo (Devon 3F) · VIS_05 Pikachu blessé (labo) · VIS_06 Brice (R101) · VIS_07 Brice (R103) · VIS_08 arrivants R101 · VIS_09 brigadier R103 · VIS_10 barrage du Bois (R104) · VIS_11 brigadier QG · VIS_12 brigadiers portes du QG · VIS_13 brigadier R116 (filets, D016 a) · VIS_14 mur R115 · VIS_15 mur R116 est · VIS_16 Zigzaton de Galar (R103) · VIS_17 Norman (QG) · VIS_18 Flora (QG) · VIS_19 Flora (Bois) · VIS_20 Flora (R116, D014 c) · VIS_21 brigade du Bois · VIS_22 arrivants du Bois (scène) · VIS_23 arrivants du Bois sauvés · VIS_24 passante (affiche) · VIS_25 Ferrand (R116) · VIS_26 Léo (Devon 3F) · VIS_27 Lanette (Devon 3F) · VIS_28 voleur (sortie Devon) · VIS_29 voleur (Centre de Mérouville) · VIS_30 voleur (R116) · VIS_31 Roxanne (mines) · VIS_32 Pierre (mines) · VIS_33 mineurs · VIS_34 Charbi et Strassie · VIS_35 Lance (Rocket) · VIS_36 sbire A · VIS_37 sbire B · VIS_38 ex-mineur rentré (Mérouville). VIS_39 dresseurs R102–R104 (cachés jusqu’au ch. 1) · VIS_40 brigadier (mini-scène de Clémenti, D006 b) · VIS_41 Ciléo (même mini-scène) · VIS_42–92 restent libres.

## Historique

| Date | Changement |
|---|---|
| 2026-10-13 | Création (prototype « Heure Suspendue ») : 0x20, 0x40F7 |
| 2026-10-14 | Allocation *Confluence* : 44 vars `VAR_CF_*`, 108 flags `FLAG_CF_*`, 93 flags de visibilité réservés (programmeur moteur) |
| 2026-10-14 | Brief v2 : renommage neutre (`FLAG_FIGEMENT_ACTIF` → `FLAG_NO_WILD_ENCOUNTERS`, `VAR_HS_DIFFICULTE` → `VAR_DIFFICULTY`) ; ajout 0x21 `FLAG_CHOOSE_BATTLE_LEAD` |
| 2026-10-15 | Démo ch. 0–1 : attribution `FLAG_CF_VIS_00`–`VIS_38` (GMD) |

**Démo ch. 1 (implémentation, 2026-10-15) :** VIS_42 dresseurs de l’arène-QG de Clémenti (cachés) · VIS_43 Brice au Centre de Mérouville (C11). Variables vanilla réutilisées comme états de scène (scripts vanilla neutralisés) : `VAR_STEVENS_HOUSE_STATE` (C1 : 0→1), `VAR_PETALBURG_WOODS_STATE` (C3 : 0→1), `VAR_RUSTBORO_CITY_STATE` (C4 : 0→10, C7 : 10→11), `VAR_DEVON_CORP_3F_STATE` (C6 : 0→1), `VAR_RUSTURF_TUNNEL_STATE` (C8 : 0→1), `VAR_ROUTE116_STATE` (C10 : 0→2, C11 : 2→3).
