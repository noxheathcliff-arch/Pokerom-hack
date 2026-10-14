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
| `B_VAR_LAST_DECLINED_TRAINER` | reçoit l'ID `TRAINER_*` du dernier dresseur refusé | `0` (désactivé) ; allouer une var si un script doit réagir à un refus |
| `OW_FLAG_PAUSE_TIME` | pause de l'horloge (exige `OW_USE_FAKE_RTC`) | **non adopté** (voir ENGINE_CHANGES.md §H4) |
| `WE_FLAG_NO_CATCHING`, `WE_FLAG_NO_RUNNING`, `B_FLAG_NO_WHITEOUT`… | voir `include/config/*.h` | à allouer ici si le design en a besoin |

## Historique

| Date | Changement |
|---|---|
| 2026-10-13 | Création (prototype « Heure Suspendue ») : 0x20, 0x40F7 |
| 2026-10-14 | Brief v2 : renommage neutre (`FLAG_FIGEMENT_ACTIF` → `FLAG_NO_WILD_ENCOUNTERS`, `VAR_HS_DIFFICULTE` → `VAR_DIFFICULTY`) ; ajout 0x21 `FLAG_CHOOSE_BATTLE_LEAD` |
