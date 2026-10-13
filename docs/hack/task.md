# task.md — Suivi central du projet de ROM hack

> Source de vérité du **suivi** (pas du design : voir `GAME_DESIGN_BIBLE.md`).
> Mis à jour par l'orchestrateur à chaque jalon. Toute session future reprend d'ici.

## 1. Objectif et critères d'achèvement
Livrer une ROM hack Pokémon GBA complète (base pokeemeraude-expansion 1.16.4, build Émeraude FR), compilée, testée sur émulateur,
avec une histoire originale complète conçue par le Game Mechanics Director selon le skill Game Mechanics (pipeline Milo Hartmann).

Critères de livraison (cf. brief §10.7 / §13) :
- [ ] Compilation propre finale (`make -j4`), avertissements examinés
- [ ] ROM identifiée (titre, game code, SHA1 consigné), taille plausible
- [ ] Tests `make check` exécutés, résultats consignés
- [ ] Tests émulateur : boot, nouvelle partie, intro, déplacements, combats sauvages/dresseurs, événements majeurs, sauvegarde/reprise
- [ ] Vérifications statiques (dresseurs, scripts, textes, drapeaux, warps)
- [ ] Aucun bug bloquant connu non traité
- [ ] Documentation : bible, personnages, cartes/progression, combats majeurs, mécaniques, build, tests, limites

## 2. Constat d'environnement (audit du 2026-10-13)
| Capacité | État | Preuve / remarque |
|---|---|---|
| Dépôt cible | `noxheathcliff-arch/Pokerom-hack`, **public**, branche `ccr-5b2ad437-a1o6hr`, push OK | push du commit d'import 819d7b3 |
| Dépôt source | clone `pokehacking-fr/pokeemeraude-expansion` @1b077e5c (v1.16.4, FR) | lecture seule, copie dans `/home/user/upstream` |
| ROM jointe (US) | **non reçue** (« 1 of 2 attachments did not arrive ») | la base se compile intégralement depuis les sources : non bloquant pour la construction ; aucune vérification d'empreinte de la ROM fournie possible |
| Skill Game Mechanics (JSON 566 Ko) | lu ; extrait dans `.gm_skill/` (ignoré par git) | persona_core + 24 docs Adams&Dormans + 12 chapitres Koster |
| Toolchain | `arm-none-eabi-gcc 13.2` installé via apt, make, python3, git | |
| Réseau | OK via proxy (GitHub, apt, web) | |
| Sous-agents | Agent tool disponible, exécution parallèle en arrière-plan confirmée (6 simultanés) | |
| Émulateur | à construire (mGBA headless) — tâche QA-Tooling | |
| Livraison binaire | `SendUserFile` (privé) — la ROM ne sera **jamais** poussée dans le dépôt public | |
| Persistance | conteneur éphémère : tout ce qui compte doit être commité/poussé | |

Règles de confidentialité : dépôt public ⇒ jamais de `.gba`, `.sav`, ni du contenu du skill JSON / du livre dans git.

## 3. Décisions structurantes
| # | Décision | Raison | Date |
|---|---|---|---|
| D1 | Base = build Émeraude FR de pokeemeraude-expansion 1.16.4 | fourni, complet, FR natif | 10-13 |
| D2 | Langue du jeu : français | base FR, brief en FR | 10-13 |
| D4 | Monde physique = les 518 cartes de Hoenn (réhabillées/renommées si besoin). Cartes Kanto/Sevii exclues (non compilées en build Émeraude, cf. ASSET_INVENTORY §1). Musiques MUS_RG_* et 159 portraits de dresseurs (dont Kanto) utilisables. | coût/risque d'un portage FRLG ; pas d'éditeur graphique | 10-13 |
| D5 | Garder GAME_CODE `BPEF` (détection Flash 128K + RTC par les émulateurs) ; ne changer que `TITLE` (≤ 12 car.) | TECHNICAL_AUDIT | 10-13 |
| D6 | Livraison via `make release` (debug menu/quickstart off, LTO) ; `EXPANSION_INTRO` à désactiver | TECHNICAL_AUDIT | 10-13 |
| D7 | Règle texte : ≤ 208 px par ligne (police variable, boîte 216 px), pas de « » (utiliser “ ”) ; vérification automatique | TECHNICAL_AUDIT §texte | 10-13 |
| D8 | Nouveaux dresseurs : réutiliser les ID TRAINER_* vanilla (9 slots libres seulement) ou étendre la table si nécessaire | TECHNICAL_AUDIT | 10-13 |
| D3 | Le skill est appliqué par un agent persistant `.claude/agents/game-mechanics-director.md` | exigence §3.2 | 10-13 |

## 4. Organisation de l'équipe (agents)
Phase A (audit/recherche, en parallèle) :
- Architecte technique → `TECHNICAL_AUDIT.md`, `FEATURE_INVENTORY.md`, `TOOLS_AND_COMMANDS.md`
- Inventaire assets → `ASSET_INVENTORY.md`
- Recherche méthodes ROM hacking → `ROM_HACKING_RESEARCH.md`
- Ingénieur outillage QA → harnais mGBA headless + `make check` → `QA_TOOLING.md`
- Recherche lore & ressources → `LORE_DOSSIER.md`
- Stratégie compétitive & IA → `AI_AUDIT.md`, `STRATEGY_RESEARCH.md`, `tools/qa/validate_trainers.py`

Phase B+ : Game Mechanics Director, critiques narratifs indépendants, superviseurs de domaine, agents de production, QA. (complété au fil de l'eau)

## 5. Tâches
### Terminées
- [x] Audit environnement (§2)
- [x] Import de la base dans le dépôt + push
- [x] Lecture du skill, extraction, définition d'agent persistant
- [x] GM Director : onboarding complet (37 fichiers du skill) → `GM_METHOD.md`, `EXPERIENCE_INTENT.md`
- [x] `ROM_HACKING_RESEARCH.md`, `AI_AUDIT.md`, `ASSET_INVENTORY.md` (à finaliser), mGBA headless + mgba-rom-test construits (/opt/mgba-tools)

### En cours
- [ ] Phase A (6 agents)
- [ ] Build de référence de la base non modifiée

### Restantes (macro)
- [ ] Phase B : vision, directions narratives, bible, critiques, version de référence
- [ ] Phase C : préproduction (cartes/progression, personnages/dresseurs, rencontres/objets, combats majeurs, mécaniques/QoL)
- [ ] Phase D : vertical slice compilée + testée
- [ ] Phase E : production complète
- [ ] Phase F : QA finale
- [ ] Phase G : livraison

## 6. Résultats de tests / preuves
| Date | Test | Résultat |
|---|---|---|
| 10-13 | Build de référence upstream non modifié (`make -j4`) | EXIT 0, 4 min 15 s. EWRAM 86.43 %, IWRAM 86.60 %, ROM 26 549 676 o / 32 Mo (79.12 %). Avertissements : 203× `bKGD: invalid index` + 3× `iCCP` (métadonnées PNG libpng, préexistants, bénins). SHA1 `ff2de54c…` (≠ rom.sha1 qui vise un autre profil de build ; non significatif). |

## 7. Blocages et solutions
| Blocage | Impact | Solution |
|---|---|---|
| Limite d'usage API atteinte (17:4x→21:50 UTC) : 6 agents de phase A interrompus | ~4 h de pause ; livrables partiels | sorties partielles commitées ; agents relancés avec leur contexte à 21:51 ; réduire le parallélisme et privilégier des prompts économes |
| ROM US jointe non reçue | aucune vérification d'empreinte de la ROM fournie | sans impact sur la construction (décompilation) ; documenté |
