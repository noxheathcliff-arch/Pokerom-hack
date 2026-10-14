# task.md — Suivi central du projet

> Source de vérité du **suivi**. Le design vit dans `GAME_DESIGN_BIBLE.md` (+ docs liés).
> Toute session future reprend d'ici. Dernière mise à jour : 2026-10-14.

## 0. Changement de direction (2026-10-14)
Le brief v2 remplace le brief v1. Le design « Heure Suspendue » est **abandonné** et archivé (`archive/heure_suspendue/`).
Ce qui reste valable et réutilisé : audit d'environnement, toolchain, harnais QA, recherches (technique, assets, IA, stratégie, lore),
`GM_METHOD.md`, l'agent persistant GM, les leçons techniques des revues (chaîne de portes vanilla, CS Plongée, plafonds, soins, ID de dresseurs),
et le prototype moteur (plafonds souples, variable de difficulté, flag anti-rencontres, noms de classe longs).

### Exigences fermes du brief v2
1. Cartes de Hoenn conservées ; la créativité porte sur scripts/histoire/systèmes. Pas de refonte de level design.
2. Red et des personnages de Kanto à Hoenn, avec Brice ; présence justifiée par l'intrigue et le lore ; sprites Kanto (pokefirered).
3. Réécriture complète de l'aventure (intro, scripts, dialogues, événements, quêtes, fins, postgame).
4. **≥ 101 décisions significatives implémentées et vérifiables** + `DECISION_LEDGER.md`.
5. Systèmes cachés sélectifs (relations, réputation de factions, états du monde) qui influencent réellement le jeu.
6. Maturité par les compromis et conséquences crédibles ; pas de moralisation.
7. Progression qui ne se réduit pas aux badges.
8. Rééquilibrage complet : sauvages, objets, quêtes, dresseurs, IA ; pas de farm comme solution.
9. Fonctionnalités : refuser certains combats ; choisir le Pokémon de tête (option) ; QoL justifiée.
10. Plusieurs fins distinctes + postgame.
11. **Budget Claude Pro** : pas de gaspillage ; aucune dépense payante.
12. ROM compilée, testée, livrée en privé ; jamais de ROM dans le dépôt public.


### Addendum utilisateur (2026-10-14, v2.1) — exigences fermes supplémentaires
13. **Toutes les espèces Gen 1→9** présentes et **expliquées par l'intrigue**, avec une **intervention de légendaire** et les **troubles causés par l'apparition des nouveaux Pokémon** (écologie, société).
14. **Intrigue beaucoup plus complexe, en couches** : le joueur ne connaît pas dès le départ toutes les causes ; révélations progressives.
15. **Tout le casting majeur de Kanto** (Prof. Chen, Blue, les 8 champions, le Conseil 4, Giovanni, etc.) **et de Hoenn**, **aucun figurant** : chacun a sa place narrative, une vraie personnalité, des objectifs (égoïstes ou non) ; relations entre eux développées ; lore et mythologie Pokémon.
16. **Affrontements hors badges** : défis libres, combats scénarisés ; **équipes adaptatives** (variantes selon l'avancée/les choix), construites au mieux sur les Gen 1→9 (ex. Olga du Conseil 4 : meilleure équipe possible selon son identité).
17. Recherche dédiée sur la **scénarisation** (films, grands jeux vidéo).
Réponse d'organisation : agents « Storycraft » et « Cast & Canon » (en cours) → refonte v3 du GM principal (colonne vertébrale + mystère en couches), puis GM secondaires par domaine (casting/relations, combats/équipes adaptatives, décisions/systèmes, distribution des espèces & écologie), puis critiques.

## 1. Constat d'environnement
| Capacité | État |
|---|---|
| Dépôt cible | `noxheathcliff-arch/Pokerom-hack` (**public**), branche `ccr-5b2ad437-a1o6hr` |
| Base | pokeemeraude-expansion 1.16.4 FR @1b077e5c, compilée depuis les sources (aucune ROM de base requise) |
| ROM US jointe | **toujours non reçue** (brief v1 et v2) — sans impact sur la construction ; empreinte invérifiable |
| Skill GM (JSON) | lu intégralement ; extrait dans `.gm_skill/` (ignoré) ; agent persistant `.claude/agents/game-mechanics-director.md` |
| pokefirered | les sprites OW/combat de Kanto sont **déjà dans l'expansion** (import FRLG) : Red (jeu complet), Leaf, Blue, Giovanni, Chen, 8 champions, Conseil 4, Rocket, Bill, M. Fuji, Celio… derrière `IS_FRLG` ; à débloquer dans le build Émeraude |
| Toolchain / QA | arm-none-eabi-gcc 13.2 ; mGBA headless `gbaplay` + `mgba-rom-test` (/opt/mgba-tools, script `tools/qa/install_mgba_tools.sh`) |
| Sous-agents | disponibles ; **limite d'usage atteinte 2 fois** (≈ fenêtres de 5 h) → parallélisme réduit, agents réutilisés |
| Livraison | ROM via envoi de fichier privé (`SendUserFile`) |

## 2. Décisions structurantes
| # | Décision | Raison |
|---|---|---|
| D1 | Base Émeraude FR expansion 1.16.4 | fourni |
| D2 | Jeu en français | base FR |
| D3 | Skill appliqué via agent GM persistant | brief §2 |
| D4 | Monde = 518 cartes Hoenn ; cartes Kanto non compilées en Émeraude | brief v2 §4 |
| D5 | GAME_CODE `BPEF` conservé (Flash 128K + RTC), seul `TITLE` change | compat émulateurs |
| D6 | Livraison `make release` (debug off) ; `EXPANSION_INTRO FALSE` (fait) | qualité |
| D7 | Texte ≤ 208 px/ligne, 2 lignes/boîte, “ ” au lieu de « » | moteur |
| D8 | Nouveaux dresseurs = ID vanilla recyclés (9 slots libres) | budget |
| D9 | Sprites Kanto : déblocage des assets FRLG déjà présents (provenance pret/pokefirered via expansion) plutôt que copie | coût/risque |
| D11 | Direction **Pokémon Cendres** : joueur = Red (muet), année 1 après RFVF, réfugiés de Cramois'Île à Hoenn ; Brice voix/partenaire ; Méga seule | NARRATIVE_DIRECTIONS v2 |
| D10 | Budget : agents peu nombreux, réutilisés (SendMessage), prompts ciblés ; travail d'intégration fait par l'orchestrateur | Claude Pro |

## 3. Plan d'exécution (brief v2 §20)
| Étape | Contenu | Statut |
|---|---|---|
| 1 | Environnement, fichiers, compatibilité | ✅ |
| 2 | Examen expansion + pokefirered | ✅ (complément Kanto en cours) |
| 3 | Skill GM + organisation | ✅ (`GM_METHOD.md`) ; `EXPERIENCE_INTENT.md` à réviser pour choix/maturité |
| 4 | Lore + vision | ✅ addendum Kanto (§8) ; direction « Cendres » choisie (88.8/100) |
| 5 | Scénario complet + système de choix | ✅ v2.0 conçue ; ⏳ revue indépendante (2 critiques) puis arbitrage |
| 6 | DECISION_LEDGER (≥ 101) + systèmes cachés | 120 décisions **proposées** (0 implémentée) ; ⏳ audit décision par décision |
| 7 | Événements, dialogues, quêtes, combats, rencontres | ⏳ |
| 8 | Tranche représentative implémentée et testée | ⏳ |
| 9 | Contenu complet | ⏳ |
| 10 | Tests, corrections, livraison | ⏳ |

## 4. Organisation des agents (rôles réutilisés)
| Rôle | Livrables | Statut |
|---|---|---|
| Game Mechanics Director (persistant) | bible v2, ledger, systèmes, arbitrages, revues GM des productions | à relancer |
| Lore Kanto/Hoenn | addendum `LORE_DOSSIER.md` (chronologie, Red, Kanto) | à lancer |
| Moteur / systèmes | joueur = Red, sprites Kanto, refus de combat, choix du Pokémon de tête, helpers de relation, plafonds/difficulté | prototype en place (build OK) |
| Critiques indépendants | revue bible v2 + ledger | après bible v2 |
| Scénaristes / intégrateurs | scripts par segment | après tranche |
| QA | tests de branches, ledger, régression, émulateur | continu |

## 5. Résultats de tests / preuves
| Date | Test | Résultat |
|---|---|---|
| 10-13 | `make check` upstream | EXIT 0, 9 min 57 s : 4937 PASS, 595 TO_DO, 13 KNOWN_FAILING, 8 EXPECT_FAILING, **0 échec** |
| 10-13 | Smoke émulateur upstream (nouvelle partie → sauvegarde → redémarrage → CONTINUER) | SMOKE: PASS, revérifié par l'orchestrateur |
| 10-13 | Build upstream non modifié | EXIT 0, 4 min 15 s ; EWRAM 86.43 %, IWRAM 86.60 %, ROM 79.12 % ; seuls avertissements libpng bénins |
| 10-14 | Build projet avec prototype moteur (plafonds, difficulté, flag anti-rencontres, classes) | EXIT 0 (`/home/user/build_wip.log`) ; non testé en émulateur |
| 10-14 | Socle moteur v2 (joueur Red, sprites Kanto, combats refusables, choix du Pokémon de tête, helpers d'affinité, plafonds, difficulté) | build EXIT 0 (ROM 79.85 %, +241 Kio sprites Kanto) ; `make check` 4949 PASS / 0 échec / 1 assumption (test exp désactivé en build test) ; smoke PASS ; capture de Red dans le camion vérifiée par l'orchestrateur. Non vérifié à l'écran : refus de combat, menu du Pokémon de tête, dos de Red en combat |
| 10-13 | `validate_trainers.py --learnsets` sur trainers.party vanilla | 855 dresseurs, 0 erreur, 2 avertissements vanilla |

## 6. Blocages et solutions
| Blocage | Impact | Solution |
|---|---|---|
| Limite d'usage Claude Pro (2 interruptions) | pauses ~4–5 h, agents coupés | commits fréquents ; agents réutilisés ; parallélisme ≤ 3 |
| ROM US jointe non reçue | empreinte invérifiable | sans impact (compilation depuis les sources) |
