# ENCOUNTERS_PLAN — Espèces et écologie (brief D, *Pokémon Confluence*)

> Auteur : GM secondaire « Espèces et écologie », sous l'autorité du GMD. Date : 2026-10-14. Statut : **S1/S2 — proposé**. Rien n'est implémenté dans la ROM. Toute mécanique ici est une `HYPOTHÈSE` jusqu'à la porte prototype (`GM_METHOD` §4.12).
> Sources lues : `SPEC_BRIEFS.md` §0 et brief D ; bible §1–§14 ; `ASSET_INVENTORY.md` §1 et §7 ; `TECHNICAL_AUDIT.md` §0 et §3 ; `FEATURE_INVENTORY.md` ; `LORE_DOSSIER.md` §4.2–4.3 et §8.7. Code lu (lecture seule) : `src/data/wild_encounters.json`, `tools/wild_encounters/wild_encounters_to_header.py`, `src/wild_encounter.c`, `src/tv.c`, `include/global.h`, `include/config/overworld.h`, `include/constants/{species,pokedex,rtc,wild_encounter}.h`, `src/data/pokemon/species_info/*`, `src/data/trade.h`, `src/pokedex_area_screen.c`.
> Livrables associés (tables de travail) :
> - `docs/hack/data/encounter_roster_v1.csv` : chaque table × méthode → natifs, arrivants de jour, arrivants de nuit, niveaux, chapitre (généré, à affiner à la main) ;
> - `docs/hack/data/species_channels.csv` : registre de couverture (une ligne par canal planifié) ;
> - `tools/qa/check_species_coverage.py` : vérificateur de couverture (voir §11).
> Noms FR des espèces : ceux du champ `speciesName` du dépôt (build FR). Les noms Gen 8–9 sont marqués ◐ globalement : ils viennent du dépôt, pas d'une vérification officielle, et la police tronque parfois (à relire par le brief A).

---

## 0. Verdict en une page

**Question.** Peut-on rendre les 1 025 espèces Gen 1–9 obtenables dans **chaque** fin, avec des cartes Hoenn inchangées, sans farm et avec une écologie lisible ?

**Réponse : oui, et sans forcer.** Le goulot n'est pas la capacité des tables. C'est la **répartition** : les régions d'origine sont mal proportionnées aux zones de leurs nœuds (Kanto–Johto et Paldea manquent d'herbe), et une poignée d'espèces ont des évolutions impossibles à Hoenn.

| Mesure | Valeur | Source |
|---|---|---|
| Familles d'évolution, nationales 1–1025 | **541** | calcul sur `species_info` (familles fusionnées par évolutions) |
| … natives de Hoenn (dex Hoenn, hors starters et fossiles) | 90 | `FOREACH_SPECIES_IN_HOENN_DEX_ORDER` |
| … étrangères non légendaires (P1) | 290 | idem |
| … starters (9 régions × 3) | 27 | cadeaux |
| … fossiles | 15 | Devon |
| … légendaires (66) + fabuleux (23) | 89 | P3, sites par fin |
| … Ultra-Chimères (10) + Paradoxes (20) | 30 | P2, anomalies |
| **Familles à placer en sauvage** (natifs + P1) | **380** (+ 10 formes régionales indispensables) | — |
| Tables Hoenn utilisables (hors inutilisées et Grotte Métamo) | **112 en-têtes** : 83 herbe, 55 surf, 53 pêche, 6 Éclate-Roc | `wild_encounters.json` |
| Emplacements, 1 état × 1 moment | **1 831** (996 + 275 + 530 + 30) | 12 / 5 / 10 / 5 par méthode |
| + 7 tables Éclate-Roc ajoutables (rochers déjà présents) | +35 | `OBJ_EVENT_GFX_BREAKABLE_ROCK` dans 13 cartes Hoenn |
| Capacité réaliste en espèces **distinctes** (règle de rareté du §2, 1 état, jour seul) | **≈ 560** | 7 arrivants + 5 natifs par herbe, 3+2 surf, 6+4 pêche, 3+2 roche |
| Placement réel du brouillon v1 | 325 familles sauvages + 51 au Safari + 2 postgame | `encounter_roster_v1.csv` |
| Couverture prouvée par le plan | **1 025 / 1 025 dans F1, F2, F3, F4 et F5** | `check_species_coverage.py --plan … --strict` → code 0 |
| Couverture du jeu vanilla (même script, sans plan) | 269 / 1 025 | même script, sans `--plan` |

**Conclusion pour le GMD.** Les tables de jour **suffisent** à la couverture. E-TOD n'est pas nécessaire pour le compte ; je le recommande quand même, **limité à des variantes « nuit »**, pour deux raisons de jeu : soulager Kanto–Johto sur 4 petites routes d'herbe, et rendre l'observation payante (§2.4). E-ECO est **nécessaire** pour la bible (états de zone), pas pour la couverture : je propose une règle qui rend la couverture **indépendante des états** (§4.1). E-OUT est nécessaire pour les anneaux de l'histoire, jamais comme canal unique.

**Décisions du GMD requises avant de remplir les tables** (détail §13) :
1. Valider la règle « ensemble d'espèces constant entre états, seules les raretés changent » (§4.1).
2. Valider le 4e état ABATTU, gratuit en stockage (2 flags = 4 valeurs) (§4.2).
3. Valider le Parc Safari comme **réserve d'arrivants saisis**, exclu du calcul des 80 % (§3.3).
4. Trancher le conflit Mewtwo « laisser » contre l'invariant 9 (§9.4).
5. Valider R110 dans la zone Unys (la bible la met dans deux nœuds) (§3.2).

---

## 1. Analyse de capacité (sortie 1)

### 1.1 Ce que le moteur permet, vérifié dans le code

| Mécanisme | Constat dans le dépôt | Conséquence |
|---|---|---|
| Format des tables | `wild_encounters.json`, groupe `gWildMonHeaders` ; champs `land_mons` (12), `water_mons` (5), `rock_smash_mons` (5), `fishing_mons` (10 : vieille canne 0–1, super canne 2–4, méga canne 5–9). Taux herbe 20/20/10/10/10/10/5/5/4/4/1/1 ; surf et roche 60/30/5/4/1 ; pêche 70/30 · 60/20/20 · 40/40/15/4/1 | 12 espèces distinctes au plus par table d'herbe ; les deux derniers emplacements font 1 % chacun |
| Champ « hidden_mons » | la structure `WildEncounterTypes` a `hiddenMonsInfo` (DexNav) ; le JSON ne déclare pas ce champ | réserve de capacité **non retenue** (DexNav désactivé, coût SB3 de 1 573 o pour les niveaux de recherche) |
| Moment de la journée | `OW_TIME_OF_DAY_ENCOUNTERS FALSE` (`overworld.h` l.96). Le générateur lit le suffixe du label : `_Morning`, `_Day`, `_Evening`, `_Night`. Sans suffixe, la table va au moment de repli (`OW_TIME_OF_DAY_FALLBACK TIME_MORNING`). Un moment sans table retombe sur le repli (`GetTimeOfDayForEncounters`) | activer = **une ligne de config**. On n'écrit que les variantes `_Night` voulues ; les autres moments retombent sur la table de base |
| Piège du générateur | la détection du moment se fait par **sous-chaîne** du label (`"Day" in base_label`) | aucun label ne doit contenir `Morning`, `Day`, `Evening` ou `Night` ailleurs qu'en suffixe. Suffixes d'état proposés : `_Mixte`, `_Restaure`, `_Abattu` |
| Plusieurs tables par carte | le JSON accepte plusieurs entrées pour la même `map` (labels différents) ; elles deviennent des en-têtes **consécutifs**. `GetCurrentMapWildMonHeaderId()` renvoie le **premier** ; seule la Grotte Métamo ajoute `VarGet(VAR_ALTERING_CAVE_WILD_SET)` à l'indice (`wild_encounter.c` l.447–455) | le format porte déjà les tables alternatives ; il manque **seulement** le sélecteur général (E-ECO, §12) |
| Épidémies | SaveBlock1 : `outbreakPokemonSpecies`, `outbreakLocationMapNum/Group`, `outbreakPokemonLevel`, `outbreakPokemonMoves[4]`, `outbreakPokemonProbability`, `outbreakDaysLeft` (`global.h` l.1150–1159). Testées **seulement sur l'herbe** et le Doux Parfum (`wild_encounter.c` l.774, l.951). Les attaques sont copiées telles quelles (`SetUpMassOutbreakEncounter`). La télé lance des épidémies vanilla au hasard (`TryStartRandomMassOutbreak`, `tv.c` l.1105) et les décompte par jour | **une seule** épidémie active. Il faut un special qui la pose (et remplit les attaques), un qui l'efface, et couper le tirage télé (E-OUT, §12) |
| Barpivot | `CheckFeebasAtCoords` : 6 tuiles de la R119 tirées d'une graine | gardé tel quel (natif, enquête d'observation) |
| Statiques et cadeaux | `setwildbattle` + `dowildbattle`, `givemon`, `giveegg` ; les scripts vanilla en ont déjà (Regis, Rayquaza, Kecleon, Électrode…) | légendaires, anomalies, cadeaux : du **script**, pas des tables |
| Échanges en jeu | `src/data/trade.h` (`sInGameTrades`, champ `.species` reçu, `.requestedSpecies`) | table extensible (données ROM) |
| Écran d'aire du Pokédex | `pokedex_area_screen.c` l.336–349 parcourt **tous** les en-têtes | il affichera les espèces de tous les états d'une carte : accepté, c'est le « possible ici » du recensement |
| Évolutions | 26 évolutions par échange, toutes doublées par le Fil de Liaison (`ITEM_LINKING_CORD`), **sauf** Carabing ↔ Escargaume (partenaire exigé). Évolutions **bloquées hors région** : Ursaring → **Ursaking** (Ursaluna, `IF_REGION REGION_HISUI`), et les formes Alola/Galar/Hisui obtenues par évolution (Raichu-A, Noadkoko-A, Ossatueur-A, Smogogo-G, M. Mime-G, finales de Hisui). Conditions de lieu **déjà sur Hoenn** : Magnézone, Tarinorme, Lucanon (`MAPSEC_NEW_MAUVILLE`), Phyllali (Bois Clémenti), Givrali et Crabominable (salle de glace de Tréfonds) | Ursaluna et M. Mime-G **doivent** avoir un canal direct ; New Lavandia et la salle de glace doivent rester accessibles au postgame dans toutes les branches |
| Conditions particulières | Charmilly (tourner sur soi), Gromago (999 Pièces de Mordudor) : `EVO_SPIN`, `IF_BAG_ITEM_COUNT`, `IF_USED_MOVE_X_TIMES` (Cerbyllin : Sprint Bouclier ×20, Courrousinge : Poing de Colère ×20), `EVO_SCRIPT_TRIGGER` (Tutétékri : arche maudite ; Shifours : rouleaux), `IF_KNOWS_MOVE` (Pomdorochi : Cri Draconique ; Farigiraf, Deusolourdo) | **Sprint Bouclier** et **Cri Draconique** ne s'apprennent pas par niveau (`level_up_learnsets/gen_9.h`) : il faut un **tuteur** ; deux **déclencheurs de script** à poser sur des cartes |

### 1.2 Combien d'espèces faut-il placer ?

Le joueur n'a pas besoin de rencontrer chaque espèce : il lui suffit d'**un** membre d'une famille, puis de l'élevage (retour à la forme de base, y compris les bébés : `P_INCENSE_BREEDING GEN_LATEST`, aucun encens requis) et de l'évolution. Le décompte se fait donc **par famille**.

| Origine | G1 | G2 | G3 | G4 | G5 | G6 | G7 | G8 | G9 | Total |
|---|---|---|---|---|---|---|---|---|---|---|
| Natifs Hoenn | 22 | 10 | 58 | — | — | — | — | — | — | 90 |
| Étrangers P1 | 45 | 32 | — | 27 | 65 | 29 | 31 | 30 | 38 | **290** |
| Starters | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 27 |
| Fossiles | 3 | — | 2 | 2 | 2 | 2 | — | 4 | — | 15 |
| Légendaires / fabuleux | 5 | 6 | 10 | 13 | 12 | 6 | 12 | 11 | 11 | 89 (66 + 23) |
| UC / Paradoxes | — | — | — | — | — | — | 10 | — | 20 | 30 |

**Formes régionales indispensables** (une évolution n'existe qu'à partir d'elles) : Miaouss-G (→ Berserkatt), Canarticho-G (→ Palarticho), Corayon-G (→ Corayôme), Zigzaton-G (→ Ixon), M. Mime-G (→ M. Glaquette), Tutafeh-G (→ Tutétékri), Farfuret-H (→ Farfurex), Qwilfish-H (→ Qwilpik), Axoloto-P (→ Terraiste), Bargantua Blanc (→ Paragruel), plus Mordudor (→ Gromago, 999 pièces). Ursaking n'a **aucun** chemin d'évolution à Hoenn : rencontre directe. Les autres formes régionales sont **cosmétiques pour la couverture** (§5).

### 1.3 Capacité, méthode par méthode

Hypothèse de remplissage (règle de rareté §2) : une table d'herbe contient 5 natifs et 7 arrivants distincts ; surf 2 + 3 ; pêche 4 + 6 ; Éclate-Roc 2 + 3.

| Méthode | En-têtes | Emplacements | Arrivants distincts possibles (jour) | Commentaire |
|---|---|---|---|---|
| Herbe / grotte | 83 | 996 | 83 × 7 = **581** | dont 41 en-têtes de donjons à étages (Mont Mémoria 8, Caverne Fondmer 8, Planque Magma 8, Tréfonds 5, Site Météore 5…) : on compte 3–4 nouveautés par étage, pas 7 → **≈ 420** réalistes |
| Surf | 55 | 275 | 165 | les chenaux se ressemblent : ≈ 60 réalistes |
| Pêche | 53 | 530 | 318 | ≈ 90 réalistes (même logique) |
| Éclate-Roc | 6 (+7) | 30 (+35) | 39 | ≈ 25 |
| **Total réaliste** | | | | **≈ 560 > 380 familles sauvages** |
| Gain E-TOD (nuit seulement) | ×2 en-têtes au plus | +996 en herbe | +3 arrivants nocturnes par table d'herbe ≈ **+200** | utile surtout à Kanto–Johto (4 routes d'herbe pour 77 familles) |
| Gain E-ECO (3 ou 4 états, 6 zones) | ×3–4 sur les cartes des zones | — | **0 compté** (règle §4.1 : on ne compte jamais une espèce qui n'existe que dans un état) | la capacité d'E-ECO sert la **lisibilité**, pas le compte |
| Gain E-OUT | 1 slot actif | — | **0 compté** comme canal unique ; accès **précoce** à 20 espèces de l'histoire et rotation postgame (§7) | |
| Safari (6 zones) | 6 | 72 + 25 | 51 placées en v1 | réserve d'arrivants saisis (§3.3) |

**Contraintes qui pèsent plus que le nombre d'emplacements :**
1. **Kanto–Johto** (77 familles) n'a que 4 routes d'herbe dans son aire (R101–R104). Réponse : variantes de nuit, pêche et surf de la côte sud, Safari-réserve, épidémies de Poivressel (ch. 1–4), dons de la Mission Indigo.
2. **Paldea** (38 familles) a des mers et des grottes, presque pas d'herbe (Île Mirage seulement). Réponse : les espèces marines et cavernicoles de Paldea dans Z-05 ; les espèces d'herbe par les **épidémies du relais** (ch. 10+, signe visible de la surcharge) et en permanence sur l'Île Mirage et au postgame.
3. **Le palier de puissance contre l'ordre des zones.** Les zones précoces (Z-01, Z-02) ne peuvent pas loger les espèces fortes sans casser la courbe. Réponse : les espèces de palier C (§2.2) d'une zone précoce passent par le Safari ou par une épidémie tardive dans leur zone.
4. **Accès par capacité.** Les tables de surf de Z-01 à Z-03 ne servent qu'après Surf (ch. 7) ; la pêche dépend des cannes (Vieille ch. 2, Super ch. 8, Méga ch. 10). Les niveaux suivent la méthode, pas la carte (§2.3).

---
## 2. Principes (rareté, progression, anti-farm, niveaux)

### 2.1 Clause de contrat du système « Rencontres et écologie »
**Système :** tables sauvages + états de zone + anneaux (épidémies) + anomalies + sites légendaires.
**Structure dominante :** hybride. Émergence au micro (quelle espèce sort, quelle équipe le joueur construit) ; progression au macro (quelles régions arrivent quand, palier de puissance par chapitre).
**Famille dominante :** économie interne (l'équipe comme portefeuille ; l'information sur l'origine comme ressource), au service de la tactique (options contre le prochain combat).
**Économie interne :**
- ressources : membres d'équipe (source : captures, dons ; convertisseur : évolution, élevage ; puits : la boîte, l'inactivité), **information d'origine** (source : rencontres et recensement de Brice ; convertisseur : la carte de Brice → preuve R2 ; puits : aucun, c'est une connaissance), temps (jour/nuit), accès (capacités de terrain, cannes) ;
- patterns : Slow Cycle (anneaux par chapitre ; nuit), Playing Style Reinforcement (le joueur garde les arrivants qu'il a choisis), Stopping Mechanism (plafond : capturer plus haut ne sert à rien) ;
- feedback : **négatif** sur la puissance (niveaux sauvages sous le plafond, pas d'EXP au-delà du plafond) ; **aucune boucle** entre captures et état de zone (anti-dominance « tout capturer », bible §11.3).
**Espace de possibilités :** large (≥ 2 réponses d'équipe à chaque combat majeur, §10) et profond (l'origine des espèces est un **indice** : une zone donne une région dominante).
**Stratégies dominantes cherchées :** voir §2.5.
**Signification (4 couches) :** effet = une table change ; fiction = des anneaux amènent et emportent ; appris = « ce que je vois ici dit d'où vient la fuite » ; thème = appartenir se négocie et tout échange a un prix (le natif emblématique qui disparaît, puis revient — ou pas).
**Ce qui reste à apprendre après la première solution :** la nuit, les états, les anomalies P2 (qui dépendent de `PA`), puis la carte complète des origines au postgame.

### 2.2 Paliers de puissance et de rareté
Le palier est calculé par script (`fam.json` → colonne `tier` du CSV) à partir de la **somme des stats de base** de la forme sauvage et de la finale.

| Palier | Règle | Chapitre au plus tôt | Emplacement |
|---|---|---|---|
| A | forme sauvage < 330 | ch. 0 | dominant (20 %) ou commun (10 %) |
| B | 330–449 | ch. 1 | commun (10 %) ou peu commun (5 %) |
| C | ≥ 450, ou deux stades avec finale ≥ 540 (Insécateur, Ronflex, Tauros, Lokhlass…) | **ch. 5** | rare (4 %) ou très rare (1 %) |
| P | pseudo-légendaires (Minidraco, Embrylex, Draby, Terhal, Griknot, Solochi, Mucuscule, Bébécaille, Fantyrm, Frigodo) | **ch. 8** (bible : aucun avant le ch. 8) | très rare (1 %), Safari-réserve ou épidémie bornée |

Exceptions natives assumées : Draby (Site Météore, accès réel au ch. 12 par Cascade) et Terhal (don de Pierre Rochard, ch. 10) respectent déjà la règle.

### 2.3 Niveaux contre plafonds
Règle : **niveau max sauvage = plafond à l'entrée du chapitre − 2** ; plage de 4–5 niveaux. Les niveaux suivent le chapitre **d'accès à la méthode** (ex. : le surf de la R104 ne sert qu'au ch. 7, il est donc au niveau du ch. 7).

| Ch. | Plafond à l'entrée → sortie (bible §8.3) | Niveaux sauvages |
|---|---|---|
| 0 | 14 | 3–6 |
| 1 | 14 → 18 | 7–12 |
| 2 | 18 → 20 | 11–16 |
| 3 | 20 → 22 | 14–18 |
| 4 | 22 → 27 | 17–21 |
| 5 | 27 → 29 | 21–25 |
| 6 | 29 → 32 | 24–27 |
| 7 | 32 → 35 | 27–30 |
| 8 | 35 → 40 | 30–33 |
| 9 | 40 → 44 | 34–38 |
| 10 | 44 → 49 | 38–42 |
| 11 | 49 → 51 | 42–47 |
| 12 | 51 → 53 | 45–49 |
| 13–14 | 53 → 60 | 49–54 |
| Postgame | 60 → 75 → 100 | 58–70 (Safari ext., cartes postgame, rotation d'anneaux) |

Conséquence voulue : une capture tardive dans une zone précoce est faible. Le joueur choisit entre **diversité** (capturer bas, entraîner sous plafond) et **efficacité** (capturer dans la zone du chapitre). Cette tension est saine **si** le Multi Exp (Gen 6+, toute l'équipe) existe : demande au brief C (QoL), sinon le plafond transforme chaque nouvelle recrue en corvée.

### 2.4 Jour et nuit (E-TOD, version minimale)
- On active `OW_TIME_OF_DAY_ENCOUNTERS TRUE` et on n'écrit que des variantes `_Night`. Matin, jour et soir utilisent la table de base (repli).
- Une variante de nuit change **3 à 4** emplacements : nocturnes (Spectre, Ténèbres, hiboux, chauves-souris) à la place d'arrivants diurnes. Les natifs ne changent pas la nuit, pour que l'état de zone reste lisible.
- Aucune espèce **n'existe que la nuit** sans être annoncée : Brice note les espèces nocturnes dans le recensement (« Vue à la nuit tombée »), et chaque route à variante nocturne a un PNJ de soirée qui le dit en une boîte. Reconnaissance plutôt que rappel.
- Risque : un joueur qui joue toujours de jour. Contre-pression : toutes les espèces nocturnes ont aussi un canal de jour ailleurs ou au postgame (vérifié par le registre, colonne `method`).

### 2.5 Dominance et anti-farm
| Raccourci du joueur | Jusqu'où il marche | Contre-pression |
|---|---|---|
| « Je capture tout pour restaurer la zone » | jamais | l'état ne lit **aucun** compteur de captures (bible §5.4) ; il lit l'issue de mission et la motion 2 |
| « Je farme les épidémies pour l'EXP » | jamais | niveaux d'épidémie = plafond − 3 ; une épidémie dure jusqu'au jalon suivant ou 3 jours ; pas d'EXP au-delà du plafond |
| « Je capture le pseudo-légendaire tôt » | impossible avant le ch. 8 | palier P ; 1 % ; Safari (pas de combat, donc pas d'affaiblissement) ou épidémie bornée |
| « Je prends l'espèce la plus forte de la route » | marche partiellement | paliers ; la route propose 1–2 options **contre le prochain combat**, pas « la meilleure » ; les dresseurs de route (brief B) testent ce que la table permet |
| « Je sauvegarde devant le légendaire et je le KO » | sans perte | un légendaire ou une anomalie KO **revient** au prochain passage (aucune espèce perdue : invariant 9) |
| « Je recharge le Kiosque pour voir l'anneau » | sans gain | le Kiosque n'ajoute pas d'espèce sauvage ; il pousse `PA`, qui avance les anomalies (coût réel, §8) |

---

## 3. Nœuds → zones (sortie 3)

### 3.1 Les six zones `Z-01`–`Z-06` (découpage fixé ici, S1)
| Zone | Nom | Nœud (bible §5.3) | Régions d'origine | Cartes à rencontres (tables) | Mission de zone | Natif emblématique |
|---|---|---|---|---|---|---|
| **Z-01** | Littoral sud | Poivressel | Kanto, Johto | R101, R102, R103, R104, chenaux 105–109 et 134, Myokara, Poivressel, Clémenti-ville (pêche), Épave | ch. 2, pêcheries de Myokara | **Goélise** (Wingull) |
| **Z-02** | Mérouville et mines | Mérouville (Devon) | Kalos, Galar | Bois Clémenti, R115, R116, Tunnel Mérazon, Grotte Granite (4 cartes) | ch. 1, mines de Devon | **Skitty** (R116) |
| **Z-03** | Lavandia, centrale et désert | Lavandia | Unys | R110, New Lavandia (2), R117, R118, R111 (désert), Tour Mirage (4) | ch. 4 → ch. 7, vergers de Vergazon (+ quête du désert, ch. 5) | **Dynavolt** (Electrike) |
| **Z-04** | Forêts du nord et Nénucrique | Nénucrique | Sinnoh, Alola | R119, R120, R121, R122, R123, Nénucrique, Mont Mémoria (8) | ch. 8, canopée de Cimetronelle | **Tropius** |
| **Z-05** | Mers de l'est | Algatia (relais) | Paldea (+ surcharge P2) | chenaux 124–133, Algatia, Atalanopolis, Pacifiville, Éternara, fonds 124 et 126, Tréfonds (5), Caverne Fondmer (9), Grotte Originelle (2), Route Victoire (3) | ch. 10–11, mers et câble | **Wailmer** |
| **Z-06** | Cendres et volcan | aucun nœud | natifs ; troupeau déplacé par Magma ; P2 tardif | R112, Chemin Ardent, Sentier Sinuroc, R113, R114, Site Météore (5), Planque Magma (8) | ch. 6, démonstration de Magma à Vermilava | **Chamallot** (Numel) |
| *Réserve* | Parc Safari | — (introduction humaine) | toutes | 6 secteurs | — | — |
| *Postgame* | Pilier Céleste 1F/3F/5F, Voie du Désert, Grotte Atelier | — | toutes | 6 | — | — |

### 3.2 Écarts à la bible, assumés et signalés
- **R110** est listée dans deux nœuds (Poivressel 104–110 et Lavandia 110–111). Je la mets en **Z-03** : les anneaux sont « groupés autour de la centrale » (ch. 4) et New Lavandia est sous la R110. Kanto–Johto récupère R101–R103, que la bible n'attribue pas. Coût : nul pour l'histoire ; à valider (§13).
- **R111 (désert)** reste en Z-03 (Unys), conforme à §5.3. Les « fouisseurs » de la bible §5.4 sont les espèces du Désert Délassant d'Unys (Mascaïman, Rototaupe, Darumarond, Maracachi, Crabicoque, Cryptéro, Tutafeh) : cohérence canon forte.
- **R112, Chemin Ardent, Sentier Sinuroc, Mont Chimnée** ne sont dans aucun nœud de §5.3 : je les range en Z-06 avec R113–R114 et le Site Météore (zone « sans nœud »).
- **Route Victoire, Grotte Originelle, Caverne Fondmer** : rattachées à Z-05 (géographie de l'est).

### 3.3 La règle des 80 % et le Parc Safari
- Calcul sur les **tables permanentes** d'une zone (les épidémies sont des événements annoncés avec leur origine, hors calcul).
- Résultat du brouillon v1 : **100 %** des arrivants des tables de Z-01 à Z-05 viennent des régions de leur nœud. Z-06 n'a qu'un arrivant (Frison, Unys) : il est **déplacé par Magma** (ch. 6), c'est l'écart justifié de la zone.
- Le « bruit » (≤ 20 %) est **réservé** à l'écriture finale : 2–3 espèces Kanto–Johto par zone (les premiers anneaux datent de trois mois ; elles ont migré). C'est ce bruit qui empêche le joueur de conclure trop vite, sans détruire l'indice R2.
- **Parc Safari = réserve d'arrivants saisis.** Fiction : le Rempart et la Mission confient au Safari de Nénucrique les arrivants capturés lors des abattages et des saisies du marché noir (lien avec Nénucrique, ch. 9). Canon : le Safari d'Émeraude contient déjà des espèces de Johto (`LORE_DOSSIER` §8.7 rang 2). Règle : le Safari est **exclu** du calcul des 80 %, et il est annoncé comme « mélangé » par un panneau et un PNJ du Rempart. Sens : la réserve est une prison douce ; un PNJ de l'Intégration le dit, un PNJ du Rempart le défend.

---
## 4. États d'écosystème et tables alternatives (sortie 4)

### 4.1 Règle de couverture indépendante des états (proposée au GMD)
**Une table alternative ne retire jamais une espèce : elle change sa rareté.** L'ensemble des espèces d'une carte est le même dans tous les états ; seuls les emplacements (donc les taux) et la densité (`encounter_rate`) changent.
- Effet : la couverture ne dépend ni des missions de zone ni de la fin. L'invariant 9 tient par construction.
- Effet lisible : au moins 3 emplacements changent entre deux états, dont le **natif emblématique**, qui passe de 1 % à 20 % (ou l'inverse). Le joueur le voit en 10 rencontres.
- Coût : on ne peut pas « faire disparaître » un arrivant. On le rend rare (1 %). C'est plus honnête dans la fiction : un arrivant installé ne s'efface pas.

### 4.2 Les états et la répartition des 12 emplacements d'herbe
Taux : 20, 20 | 10, 10, 10, 10 | 5, 5 | 4, 4 | 1, 1.

| Emplacements | ENVAHI | MIXTE | RESTAURÉ | ABATTU (proposé) |
|---|---|---|---|---|
| 0–1 (40 %) | 2 arrivants dominants | 1 natif commun + 1 arrivant dominant | **natif emblématique** + 1 natif commun | 2 natifs communs (doublés) |
| 2–5 (40 %) | 2 arrivants + 2 natifs communs | 2 natifs + 2 arrivants | 3 natifs + 1 arrivant installé | 4 natifs (doublons autorisés) |
| 6–7 (10 %) | 2 arrivants | natif emblématique + 1 arrivant | 2 arrivants installés | 2 arrivants |
| 8–9 (8 %) | 1 natif + 1 arrivant | 2 arrivants | 2 arrivants | 2 arrivants |
| 10–11 (2 %) | **natif emblématique** + 1 arrivant rare | 2 arrivants rares | les 2 arrivants dominants d'avant | 2 arrivants rares |
| `encounter_rate` | ×1 | ×1 | ×1 | **×0,5** (la route est vide : on a abattu) |

Surf (60/30/5/4/1) : ENVAHI = arrivant 60 %, natif 30 % ; RESTAURÉ = natif 60 % ; ABATTU = densité ×0,5. Pêche : la vieille canne reste native (Magicarpe, Tentacool) dans tous les états ; super et méga cannes suivent la règle de l'herbe.

**ABATTU** est la signature mécanique du Rempart (bible §7 : « tables abattues : moins d'arrivants **et** de natifs »). Les 2 flags par zone de la bible donnent 4 valeurs : l'état ABATTU ne coûte **aucun** stockage. Sans lui, la politique du Rempart n'a pas de trace dans les règles.

### 4.3 Qui écrit l'état (interface brief C)
- État de départ de chaque zone : **ENVAHI**.
- La mission de zone (§7.2) écrit l'état de base : une issue = un état. Une mission non faite au moment du jalon de fin de chapitre écrit **MIXTE** (l'arrivée se tasse d'elle-même) : aucun état orphelin, jalon posé dans toutes les branches.
- La **motion 2 du Sommet** (ch. 12) applique un glissement global, écrit au ch. 13 : REMPART : MIXTE → ABATTU ; INTÉGRATION : ENVAHI → MIXTE, ABATTU → MIXTE ; MARCHÉ : aucun glissement (les arrivants restent une ressource).
- Stockage demandé par nom logique : `ECO_Z01` … `ECO_Z06`, 2 bits chacun (0 ENVAHI, 1 MIXTE, 2 RESTAURÉ, 3 ABATTU). Une seule var de 16 bits suffit pour les 6 zones (E-BITS) : **1 var** au lieu de 12 flags.
- Lecteurs : E-ECO (tables), PNJ de zone (saillance), diaporama d'épilogue, `rP` (prix locaux, brief C).

### 4.4 Prototype exigé par la bible (§11.4) : R116
| Emplacement | ENVAHI (ch. 1) | MIXTE | RESTAURÉ | ABATTU |
|---|---|---|---|---|
| 20 % | Moumouton ◐ (Galar) | Chuchmur | **Skitty** | Chuchmur |
| 20 % | Sapereau ◐ (Kalos) | Moumouton | Chuchmur | Nirondelle |
| 10 % ×4 | Psystigri, Hélionceau, Nirondelle, Chuchmur | Nirondelle, Ningale, Psystigri, Sapereau | Nirondelle, Ningale, Medhyèna, Psystigri | Chuchmur, Nirondelle, Ningale, Medhyèna |
| 5 % ×2 | Galvaran, Minisange | **Skitty**, Hélionceau | Sapereau, Hélionceau | Psystigri, Sapereau |
| 4 % ×2 | Ningale, Sucroquin | Galvaran, Minisange | Galvaran, Minisange | Hélionceau, Galvaran |
| 1 % ×2 | **Skitty**, Zigzaton de Galar | Sucroquin, Zigzaton de Galar | Moumouton, Sucroquin | Minisange, Zigzaton de Galar |
| Nuit (remplace 3) | Goupilou, Miaouss de Galar, Morpeko ◐ | idem | idem | idem |

Critère (bible) : ≥ 3 emplacements changent entre deux états et le natif emblématique en fait partie. Ici, entre ENVAHI et RESTAURÉ : 9 emplacements changent, Skitty passe de 1 % à 20 %. Test : save au ch. 1 avant la mission, 50 rencontres par état, compter Skitty (attendu : ≈ 0–1 contre ≈ 10).

---
## 5. Politique des formes (sortie 2)

| Cas | Option retenue | Raison |
|---|---|---|
| **Formes régionales d'Alola, Galar, Paldea** | sauvages **dans la zone du nœud de leur région** (Alola → Z-04, Galar → Z-02, Paldea → Z-05), à côté de la forme native quand elle existe (Zigzaton de Galar sur la R116 à côté du Zigzaton de Hoenn) | indice visuel de R2 très lisible : « le même Pokémon, mais d'ailleurs » |
| Formes régionales **indispensables** (§1.2) | canal direct obligatoire, comptées dans la couverture | sans elles, 10 espèces sont inobtenables |
| Formes régionales **obtenues par évolution dans leur région** (Raichu-A, Noadkoko-A, Ossatueur-A, Smogogo-G, finales de Hisui) | **non comptées** (l'espèce nationale est couverte par sa forme normale) ; option : dresseurs du brief B et échanges en jeu postgame | le moteur bloque l'évolution hors région (`IF_REGION`) ; on ne modifie pas les données d'espèces |
| **Hisui** (Caninos-H, Voltorbe-H, Zorua-H, Farfuret-H, Qwilfish-H, Bargantua Blanc, et Ursaking direct) | **anomalies P2** (Sinnoh ancien), à partir du ch. 8, rares, localisées, croissantes avec `PA` | bible §5.2 (P2) |
| **Paradoxes** (20) et **Ultra-Chimères** (10) | anomalies P2 (statiques scriptées, puis sites permanents au postgame) | bible §5.2 ; §8 |
| Formes **cosmétiques** (Zarbi, Prismillon, Flabébé, Couafarel, Charmilly, Sancoki/Tritosor Est-Ouest, Cerfrousse/Vivaldaim saisons…) | une seule forme au minimum, **exclues du compte** ; Prismillon : motif Fantaisie (`P_SCATTERBUG_LINE_FORM_BREED`) | le compte porte sur les 1 025 entrées nationales |
| **Méga** | objets (Méga-Gemmes), pas espèces ; politique du brief B (après le ch. 8) | bible §1 |
| Gigamax, Téra, Totem | hors périmètre (Téra et Dynamax « existent ailleurs ») | bible §1 |
| Formes de combat (Météno, Froussardine, Mimiqui…) | rien à faire | moteur |

---

## 6. Plan par zone (sorties 4, 5 et 8)

Lecture des tables : `Méth.` = L herbe/grotte, W surf, F pêche, R Éclate-Roc ; le chapitre est celui d'**accès à la méthode** ; ᶜ = palier C, ᴾ = palier P. Les natifs sont ceux de la table vanilla (familles fusionnées), plus quelques natifs replacés (Hypotrempe, Loupio, Corayon, Arakdo, Méditikka, Rosélia, Mangriff, Séléroc, Coquiperl, Relicanth). Les arrivants sont placés par le script de répartition (région du nœud, habitat, palier, charge par table), puis épinglés à la main là où la bible demande une perturbation précise. **C'est un brouillon v1 : la colonne d'état (§4.2) s'applique à chaque ligne d'herbe.** Le détail exhaustif (niveaux, rôles) est dans `docs/hack/data/encounter_roster_v1.csv`.


#### Tables — Z01

| Carte | Méth. (ch.) | Niv. | Natifs | Arrivants (jour) | Arrivants (nuit) |
|---|---|---|---|---|---|
| Route101 | L (0) | 3–6 | Chenipotte, Medhyèna, Zigzaton | Taupiqueur, Chenipan, Piafabec, Nidoran♂, Chétiflor, Fouinette, Pomdepik | Fantominus, Mimitoss, Hoothoot |
| Route102 | L (0) | 3–6 | Zigzaton, Medhyèna, Chenipotte, Nénupiot, Tarsal, Arakdo | Osselait, Aspicot, Abo, Paras, Noeunoeuf, Coxy, Snubbull | Rattata, Miaouss, Mimigal |
| Route102 | W (7) | 27–30 | Marill, Poissirène |  |  |
| Route102 | F (2) | 11–16 | Écrapince, Magicarpe, Poissirène |  |  |
| Route103 | L (0) | 3–6 | Goélise, Medhyèna, Zigzaton | Marcacrin, Roucool, Nidoran♀, Férosinge, Évoli, Granivol | Mélofée, Soporifik |
| Route103 | W (7) | 27–30 | Goélise, Tentacool |  |  |
| Route103 | F (2) | 11–16 | Wailmer, Magicarpe, Tentacool, Carvanha |  |  |
| Route104 | L (1) | 7–12 | Goélise, Medhyèna, Marill, Nirondelle, Chenipotte | Onix, Simularbre, Caninos, Ponyta, Canarticho, Excelangue, Saquedeneu, Porygon | Feuforêve, Farfuret, Cornèbre |
| Route104 | W (7) | 27–30 | Goélise |  |  |
| Route104 | F (2) | 11–16 | Magicarpe |  |  |
| Route105 | W (7) | 27–30 | Goélise, Tentacool | Lokhlassᶜ |  |
| Route105 | F (7) | 27–30 | Wailmer, Magicarpe, Tentacool | Démantaᶜ |  |
| Route106 | W (7) | 27–30 | Goélise, Tentacool | Otaria |  |
| Route106 | F (2) | 11–16 | Wailmer, Magicarpe, Tentacool | Krabby |  |
| Route107 | W (7) | 27–30 | Goélise, Tentacool | Kokiyas |  |
| Route107 | F (7) | 27–30 | Wailmer, Magicarpe, Tentacool | Qwilfish |  |
| Route108 | W (7) | 27–30 | Goélise, Tentacool |  |  |
| Route108 | F (7) | 27–30 | Wailmer, Magicarpe, Tentacool |  |  |
| Route109 | W (7) | 27–30 | Goélise, Tentacool |  |  |
| Route109 | F (3) | 14–18 | Wailmer, Magicarpe, Tentacool | Ptitard |  |
| Route134 | W (7) | 27–30 | Goélise, Tentacool |  |  |
| Route134 | F (7) | 27–30 | Wailmer, Magicarpe, Tentacool, Carvanha |  |  |
| DewfordTown | W (7) | 27–30 | Goélise, Tentacool |  |  |
| DewfordTown | F (2) | 11–16 | Wailmer, Magicarpe, Tentacool | Krabby |  |
| SlateportCity | W (7) | 27–30 | Goélise, Tentacool |  |  |
| SlateportCity | F (3) | 14–18 | Wailmer, Magicarpe, Tentacool | Ramoloss |  |
| PetalburgCity | W (7) | 27–30 | Marill |  |  |
| PetalburgCity | F (2) | 11–16 | Écrapince, Magicarpe, Poissirène | Cadoizo |  |
| AbandonedShip_Rooms_B1F | W (7) | 27–30 | Tentacool |  |  |
| AbandonedShip_Rooms_B1F | F (7) | 27–30 | Tentacool, Magicarpe |  |  |
| AbandonedShip_HiddenFloorCorridors | W (10) | 38–42 | Tentacool |  |  |
| AbandonedShip_HiddenFloorCorridors | F (10) | 38–42 | Tentacool, Magicarpe |  |  |

#### Tables — Z02

| Carte | Méth. (ch.) | Niv. | Natifs | Arrivants (jour) | Arrivants (nuit) |
|---|---|---|---|---|---|
| PetalburgWoods | L (1) | 7–12 | Chenipotte, Medhyèna, Balignon, Nirondelle, Parecool | Tournicoton, Moumouton, Voltoutou, Verpom, Grillepattes, Bibichut, Crèmy |  |
| Route116 | L (1) | 7–12 | Medhyèna, Nirondelle, Ningale, Skitty, Chuchmur | Hélionceau, Cabriolaine, Psystigri, Sucroquin, Sapereau, Galvaran, Minisange | Morpeko, Goupilou |
| RusturfTunnel | L (1) | 7–12 | Chuchmur | Charbi, Frissonille | Pitrouille |
| RusturfTunnel | R (4) | 17–21 |  | Dunaja |  |
| GraniteCave_1F | L (2) | 11–16 | Makuhita, Racaillou, Nosferapti, Abra | Charibari | Monorpale |
| GraniteCave_B1F | L (2) | 11–16 | Ténéfix, Galekid, Nosferapti, Makuhita, Abra | Charbi | Brocélôme |
| GraniteCave_StevensRoom | L (2) | 11–16 | Makuhita, Galekid, Nosferapti, Abra | Grelaçon | Théffroi |
| GraniteCave_B2F | L (2) | 11–16 | Ténéfix, Galekid, Nosferapti, Abra | Strassieᶜ |  |
| GraniteCave_B2F | R (4) | 17–21 | Racaillou, Tarinor |  |  |
| Route115 | L (1) | 7–12 | Nirondelle, Goélise, Tylton, Rondoudou | Floette, Pandespiègle, Fluvetin, Dedenne, Passerouge, Rongourmand, Larvadar | Sonistrelle, Grimalin |
| Route115 | W (7) | 27–30 | Goélise, Tentacool | Nigosierᶜ, Bekaglaçonᶜ, Opermine |  |
| Route115 | F (2) | 11–16 | Wailmer, Magicarpe, Tentacool | Flingouste, Wattapik, Sepiatop, Venalgue, Khélocrok, Embrochet |  |

#### Tables — Z03

| Carte | Méth. (ch.) | Niv. | Natifs | Arrivants (jour) | Arrivants (nuit) |
|---|---|---|---|---|---|
| Route110 | L (3) | 14–18 | Dynavolt, Gloupti, Négapi, Goélise, Posipi | Zébibron, Emolga, Lewsor, Pyronille, Ratentif, Poichigeon, Venipatte | Zorua, Chovsourir |
| Route110 | W (7) | 27–30 | Goélise, Tentacool | Bargantuaᶜ, Limondeᶜ |  |
| Route110 | F (3) | 14–18 | Wailmer, Magicarpe, Tentacool | Viskuse |  |
| NewMauville_Entrance | L (4) | 17–21 | Voltorbe, Magnéti | Statitik, Miamiasme, Scrutella, Carabing, Grindur, Escargaume | Funécire |
| NewMauville_Inside | L (4) | 17–21 | Voltorbe, Magnéti | Anchwatt, Chinchidou, Nucléos, Trompignon, Coupenotte |  |
| Route117 | L (4) | 17–21 | Lumivole, Mystherbe, Medhyèna, Marill, Muciole, Rosélia | Feuillajou, Flamajou, Kungfouine, Sorbébé, Ponchiot, Charpenti, Doudouvet | Vostourno |
| Route117 | W (7) | 27–30 | Marill, Poissirène, Arakdo | Flotajou |  |
| Route117 | F (4) | 17–21 | Écrapince, Magicarpe, Poissirène | Tritonde |  |
| Route118 | L (4) | 17–21 | Goélise, Zigzaton, Dynavolt, Kecleon | Nanméouïe, Vivaldaim, Furaiglon, Polarhume, Munna, Larveyette, Chlorobule | Chacripan |
| Route118 | W (7) | 27–30 | Goélise, Tentacool | Mamanboᶜ |  |
| Route118 | F (4) | 17–21 | Carvanha, Magicarpe, Tentacool | Couaneton |  |
| Route111 | L (6) | 24–27 | Sabelette, Kraknoix, Balbuto, Cacnea | Mascaïman, Darumarond, Maracachiᶜ | Scalpion |
| Route111 | W (7) | 27–30 | Marill, Poissirène |  |  |
| Route111 | F (4) | 17–21 | Barloche, Magicarpe, Poissirène |  |  |
| Route111 | R (6) | 24–27 | Racaillou | Rototaupe, Tic |  |
| MirageTower_1F | L (6) | 24–27 | Sabelette, Kraknoix | Rototaupe, Baggiguane, Aflamanoirᶜ | Gringolem |
| MirageTower_2F | L (6) | 24–27 | Sabelette, Kraknoix | Cryptéroᶜ, Judokrakᶜ, Fermiteᶜ |  |
| MirageTower_3F | L (6) | 24–27 | Sabelette, Kraknoix | Hexagelᶜ, Karacléeᶜ |  |
| MirageTower_3F | R (6) | 24–27 |  | Crabicoque |  |
| MirageTower_4F | L (6) | 24–27 | Sabelette, Kraknoix | Tutafeh, Drakkarminᶜ |  |
| MirageTower_4F | R (6) | 24–27 |  | Nodulithe |  |

#### Tables — Z04

| Carte | Méth. (ch.) | Niv. | Natifs | Arrivants (jour) | Arrivants (nuit) |
|---|---|---|---|---|---|
| Route119 | L (8) | 30–33 | Zigzaton, Mystherbe, Tropiusᶜ, Kecleon | Étourmi, Picassaut, Pijako, Crabagarre, Météno, Cheniti, Ceribou |  |
| Route119 | W (8) | 30–33 | Goélise, Tentacool |  |  |
| Route119 | F (8) | 30–33 | Carvanha, Magicarpe, Tentacool |  |  |
| Route120 | L (8) | 30–33 | Medhyèna, Mystherbe, Marill, Absolᶜ, Kecleon | Étourmi, Laporeille, Motisma, Nounourson, Lixy, Apitrini, Cradopaud |  |
| Route120 | W (8) | 30–33 | Marill, Poissirène |  |  |
| Route120 | F (8) | 30–33 | Barloche, Magicarpe, Poissirène |  |  |
| Route121 | L (9) | 34–38 | Medhyèna, Mystherbe, Goélise, Polichombr, Kecleon | Lucarioᶜ, Plumelineᶜ, Gouroutanᶜ, Dodoalaᶜ, Draïeulᶜ, Blizzi, Togedemaru | Rapion, Crikzik, Moufouette |
| Route121 | W (9) | 34–38 | Goélise, Tentacool |  |  |
| Route121 | F (9) | 34–38 | Wailmer, Magicarpe, Tentacool |  |  |
| Route122 | W (9) | 34–38 | Goélise, Tentacool | Mustébouée, Keunotor, Araqua |  |
| Route122 | F (9) | 34–38 | Wailmer, Magicarpe, Tentacool, Carvanha | Denticrisseᶜ, Sancoki, Sovkipou |  |
| Route123 | L (9) | 34–38 | Medhyèna, Mystherbe, Goélise, Polichombr, Kecleon | Vortenteᶜ, Guérilandeᶜ, Quartermacᶜ, Boumataᶜ, Hippopotas, Tiboudet, Pachirisu | Rocabot, Chaglam, Spododo |
| Route123 | W (9) | 34–38 | Goélise, Tentacool |  |  |
| Route123 | F (9) | 34–38 | Wailmer, Magicarpe, Tentacool |  |  |
| LilycoveCity | W (9) | 34–38 | Goélise, Tentacool | Concombaffe, Vorastérie |  |
| LilycoveCity | F (9) | 34–38 | Wailmer, Magicarpe, Tentacool, Stari | Écayon, Froussardine |  |
| MtPyre_1F | L (9) | 34–38 | Polichombr | Archéomire, Tritox | Spiritombᶜ |
| MtPyre_2F | L (9) | 34–38 | Polichombr, Méditikka | Manglouton, Croquine | Sinistrailᶜ |
| MtPyre_3F | L (9) | 34–38 | Polichombr | Larvibule |  |
| MtPyre_4F | L (9) | 34–38 | Polichombr, Skelénox | Mimiquiᶜ |  |
| MtPyre_5F | L (9) | 34–38 | Polichombr, Skelénox | Bombydou |  |
| MtPyre_6F | L (9) | 34–38 | Polichombr, Skelénox | Mimantis |  |
| MtPyre_Exterior | L (9) | 34–38 | Polichombr, Goupix, Goélise | Baudrive |  |
| MtPyre_Summit | L (9) | 34–38 | Polichombr, Skelénox, Éokoᶜ | Bacabouh |  |

#### Tables — Z05

| Carte | Méth. (ch.) | Niv. | Natifs | Arrivants (jour) | Arrivants (nuit) |
|---|---|---|---|---|---|
| Route124 | W (10) | 38–42 | Goélise, Tentacool | Zapétrel |  |
| Route124 | F (10) | 38–42 | Wailmer, Magicarpe, Tentacool, Carvanha, Loupio |  |  |
| Route125 | W (10) | 38–42 | Goélise, Tentacool |  |  |
| Route125 | F (10) | 38–42 | Wailmer, Magicarpe, Tentacool, Carvanha |  |  |
| Route126 | W (10) | 38–42 | Goélise, Tentacool |  |  |
| Route126 | F (10) | 38–42 | Wailmer, Magicarpe, Tentacool, Carvanha | Oyacataᶜ, Nigirigonᶜ |  |
| Route127 | W (10) | 38–42 | Goélise, Tentacool |  |  |
| Route127 | F (10) | 38–42 | Wailmer, Magicarpe, Tentacool, Carvanha |  |  |
| Route128 | W (10) | 38–42 | Goélise, Tentacool | Taupikeau |  |
| Route128 | F (10) | 38–42 | Wailmer, Magicarpe, Lovdisc, Tentacool, Corayon |  |  |
| Route129 | W (7) | 27–30 | Goélise, Tentacool | Dofin |  |
| Route129 | F (10) | 38–42 | Wailmer, Magicarpe, Tentacool, Carvanha |  |  |
| Route130 | L (14) | 49–54 | Qulbutoké | Motorizardᶜ, Flamenrouleᶜ, Tapatoès, Terracool, Gourmelet, Tissenboule, Lilliterelle | Lestombaileᶜ, Grondogue, Gribouraigne |
| Route130 | W (7) | 27–30 | Goélise, Tentacool | Délestinᶜ |  |
| Route130 | F (10) | 38–42 | Wailmer, Magicarpe, Tentacool, Carvanha |  |  |
| Route131 | W (7) | 27–30 | Goélise, Tentacool | Têtampoule |  |
| Route131 | F (10) | 38–42 | Wailmer, Magicarpe, Tentacool, Carvanha |  |  |
| Route132 | W (7) | 27–30 | Goélise, Tentacool |  |  |
| Route132 | F (7) | 27–30 | Wailmer, Magicarpe, Tentacool, Carvanha, Hypotrempe |  |  |
| Route133 | W (7) | 27–30 | Goélise, Tentacool |  |  |
| Route133 | F (7) | 27–30 | Wailmer, Magicarpe, Tentacool, Carvanha |  |  |
| MossdeepCity | W (10) | 38–42 | Goélise, Tentacool |  |  |
| MossdeepCity | F (10) | 38–42 | Wailmer, Magicarpe, Tentacool, Carvanha |  |  |
| SootopolisCity | W (12) | 45–49 | Magicarpe |  |  |
| SootopolisCity | F (12) | 45–49 | Magicarpe, Tentacool |  |  |
| PacifidlogTown | W (7) | 27–30 | Goélise, Tentacool |  |  |
| PacifidlogTown | F (7) | 27–30 | Wailmer, Magicarpe, Tentacool, Carvanha |  |  |
| EverGrandeCity | W (14) | 49–54 | Goélise, Tentacool |  |  |
| EverGrandeCity | F (14) | 49–54 | Wailmer, Magicarpe, Lovdisc, Tentacool |  |  |
| Underwater_Route124 | W (10) | 38–42 | Coquiperl, Relicanthᶜ, Loupio |  |  |
| Underwater_Route126 | W (12) | 45–49 | Coquiperl, Relicanthᶜ |  |  |
| ShoalCave_LowTideEntranceRoom | L (11) | 42–47 | Nosferapti, Obalie | Craparoiᶜ | Virovent |
| ShoalCave_LowTideEntranceRoom | W (11) | 42–47 | Obalie, Tentacool |  |  |
| ShoalCave_LowTideEntranceRoom | F (11) | 42–47 | Wailmer, Magicarpe, Tentacool |  |  |
| ShoalCave_LowTideInnerRoom | L (11) | 42–47 | Nosferapti, Obalie | Ferdeterᶜ | Toutombe |
| ShoalCave_LowTideInnerRoom | W (11) | 42–47 | Obalie, Tentacool |  |  |
| ShoalCave_LowTideInnerRoom | F (11) | 42–47 | Wailmer, Magicarpe, Tentacool |  |  |
| ShoalCave_LowTideStairsRoom | L (11) | 42–47 | Nosferapti, Obalie | Germéclat | Mordudor |
| ShoalCave_LowTideLowerRoom | L (11) | 42–47 | Nosferapti, Obalie | Selutin | Poltchageist |
| ShoalCave_LowTideIceRoom | L (11) | 42–47 | Nosferapti, Obalie, Stalgamin | Piétacé |  |
| SeafloorCavern_Entrance | W (11) | 42–47 | Nosferapti, Tentacool |  |  |
| SeafloorCavern_Entrance | F (11) | 42–47 | Wailmer, Magicarpe, Tentacool |  |  |
| SeafloorCavern_Room1 | L (11) | 42–47 | Nosferapti | Forgerette |  |
| SeafloorCavern_Room1 | R (11) | 42–47 |  | Vrombi |  |
| SeafloorCavern_Room2 | L (11) | 42–47 | Nosferapti | Pohm |  |
| SeafloorCavern_Room3 | L (11) | 42–47 | Nosferapti | Compagnol |  |
| SeafloorCavern_Room4 | L (11) | 42–47 | Nosferapti | Pâtachiot |  |
| SeafloorCavern_Room5 | L (11) | 42–47 | Nosferapti | Olivini |  |
| SeafloorCavern_Room6 | L (11) | 42–47 | Nosferapti | Charbambin |  |
| SeafloorCavern_Room6 | W (11) | 42–47 | Nosferapti, Tentacool |  |  |
| SeafloorCavern_Room6 | F (11) | 42–47 | Wailmer, Magicarpe, Tentacool |  |  |
| SeafloorCavern_Room7 | L (11) | 42–47 | Nosferapti | Pimito |  |
| SeafloorCavern_Room7 | W (11) | 42–47 | Nosferapti, Tentacool |  |  |
| SeafloorCavern_Room7 | F (11) | 42–47 | Wailmer, Magicarpe, Tentacool |  |  |
| SeafloorCavern_Room8 | L (11) | 42–47 | Nosferapti | Léboulérou |  |
| CaveOfOrigin_Entrance | L (12) | 45–49 | Nosferapti | Flotillon |  |
| CaveOfOrigin_1F | L (12) | 45–49 | Nosferapti, Ténéfix |  |  |
| VictoryRoad_1F | L (14) | 49–54 | Nosferapti, Makuhita, Galekid, Chuchmur, Méditikka |  |  |
| VictoryRoad_B1F | L (14) | 49–54 | Galekid, Nosferapti, Makuhita, Mysdibule |  |  |
| VictoryRoad_B1F | R (14) | 49–54 | Racaillou |  |  |
| VictoryRoad_B2F | L (14) | 49–54 | Galekid, Nosferapti, Ténéfix, Mysdibule |  |  |
| VictoryRoad_B2F | W (14) | 49–54 | Nosferapti |  |  |
| VictoryRoad_B2F | F (14) | 49–54 | Barloche, Magicarpe, Poissirène |  |  |

#### Tables — Z06

| Carte | Méth. (ch.) | Niv. | Natifs | Arrivants (jour) | Arrivants (nuit) |
|---|---|---|---|---|---|
| Route112 | L (5) | 21–25 | Chamallot, Marill | Frisonᶜ |  |
| FieryPath | L (5) | 21–25 | Chartorᶜ, Chamallot, Smogo, Machoc, Tadmorv |  |  |
| JaggedPass | L (6) | 24–27 | Chamallot, Spoink, Machoc | Frisonᶜ |  |
| Route113 | L (5) | 21–25 | Spinda, Limagma, Airmureᶜ |  |  |
| Route114 | L (5) | 21–25 | Nénupiot, Tylton, Séviperᶜ, Grainipiot, Mangriffᶜ |  |  |
| Route114 | W (7) | 27–30 | Marill, Poissirène |  |  |
| Route114 | F (5) | 21–25 | Barloche, Magicarpe, Poissirène |  |  |
| Route114 | R (5) | 21–25 | Racaillou |  |  |
| MeteorFalls_1F_1R | L (5) | 21–25 | Nosferapti, Solarocᶜ, Sélérocᶜ |  |  |
| MeteorFalls_1F_1R | W (7) | 27–30 | Solarocᶜ, Nosferapti |  |  |
| MeteorFalls_1F_1R | F (5) | 21–25 | Barloche, Magicarpe, Poissirène |  |  |
| MeteorFalls_1F_2R | L (12) | 45–49 | Nosferapti, Solarocᶜ |  |  |
| MeteorFalls_1F_2R | W (12) | 45–49 | Solarocᶜ, Nosferapti |  |  |
| MeteorFalls_1F_2R | F (12) | 45–49 | Barloche, Magicarpe, Poissirène |  |  |
| MeteorFalls_B1F_1R | L (12) | 45–49 | Nosferapti, Solarocᶜ |  |  |
| MeteorFalls_B1F_1R | W (12) | 45–49 | Solarocᶜ, Nosferapti |  |  |
| MeteorFalls_B1F_1R | F (12) | 45–49 | Barloche, Magicarpe, Poissirène |  |  |
| MeteorFalls_B1F_2R | L (12) | 45–49 | Nosferapti, Drabyᴾ, Solarocᶜ |  |  |
| MeteorFalls_B1F_2R | W (12) | 45–49 | Solarocᶜ, Nosferapti |  |  |
| MeteorFalls_B1F_2R | F (12) | 45–49 | Barloche, Magicarpe, Poissirène |  |  |
| MeteorFalls_StevensCave | L (12) | 45–49 | Nosferapti, Solarocᶜ |  |  |
| MagmaHideout_1F | L (6) | 24–27 | Racaillou, Chartorᶜ |  |  |
| MagmaHideout_2F_1R | L (6) | 24–27 | Racaillou, Chartorᶜ |  |  |
| MagmaHideout_2F_2R | L (6) | 24–27 | Racaillou, Chartorᶜ |  |  |
| MagmaHideout_2F_3R | L (6) | 24–27 | Racaillou, Chartorᶜ |  |  |
| MagmaHideout_3F_1R | L (6) | 24–27 | Racaillou, Chartorᶜ |  |  |
| MagmaHideout_3F_2R | L (6) | 24–27 | Racaillou, Chartorᶜ |  |  |
| MagmaHideout_3F_3R | L (6) | 24–27 | Racaillou, Chartorᶜ |  |  |
| MagmaHideout_4F | L (6) | 24–27 | Racaillou, Chartorᶜ |  |  |

#### Tables — SAF

| Carte | Méth. (ch.) | Niv. | Natifs | Arrivants (jour) | Arrivants (nuit) |
|---|---|---|---|---|---|
| SafariZone_South | L (9) | 34–38 | Mystherbe, Qulbutoké, Girafarigᶜ, Pikachu, Natu | Embrylexᴾ, Griknotᴾ, Fantyrmᴾ, Frigodoᴾ, Solochiᴾ, Mucusculeᴾ, Bébécailleᴾ, Lippoutouᶜ |  |
| SafariZone_Southwest | L (9) | 34–38 | Mystherbe, Qulbutoké, Girafarigᶜ, Pikachu, Natu | Trousselinᶜ, Dolmanᶜ, Duralugonᶜ, Kickleeᶜ, Leveinardᶜ, Kangourexᶜ, M. Mimeᶜ, Insécateurᶜ |  |
| SafariZone_Southwest | W (9) | 34–38 | Psykokwak | Minidracoᴾ, Poulpaf |  |
| SafariZone_Southwest | F (9) | 34–38 | Poissirène, Magicarpe |  |  |
| SafariZone_North | L (9) | 34–38 | Mystherbe, Natu, Phanpy, Scarhinoᶜ | Élektekᶜ, Magmarᶜ, Taurosᶜ, Ronflexᶜ, Couafarelᶜ, Brutalibréᶜ, Salarsenᶜ, Hexadronᶜ |  |
| SafariZone_North | R (9) | 34–38 | Racaillou |  |  |
| SafariZone_Northwest | L (9) | 34–38 | Mystherbe, Doduo, Rhinocorne, Scarabruteᶜ | Wimessirᶜ, Togetic, Yanma, Zarbi, Insolourdo |  |
| SafariZone_Northwest | W (9) | 34–38 | Psykokwak |  |  |
| SafariZone_Northwest | F (9) | 34–38 | Poissirène, Magicarpe |  |  |
| SafariZone_Southeast | L (post) | 58–70 | Tournegrin, Wattouat, Cerfrousseᶜ, Scorplane, Capumain |  |  |
| SafariZone_Southeast | W (post) | 58–70 | Marill, Axoloto |  |  |
| SafariZone_Southeast | F (post) | 58–70 | Rémoraid, Poissirène, Magicarpe |  |  |
| SafariZone_Northeast | L (post) | 58–70 | Capumain, Teddiursa, Malosse, Écrémeuhᶜ, Tournegrin |  |  |
| SafariZone_Northeast | R (post) | 58–70 | Caratrocᶜ |  |  |

#### Tables — POST

| Carte | Méth. (ch.) | Niv. | Natifs | Arrivants (jour) | Arrivants (nuit) |
|---|---|---|---|---|---|
| SkyPillar_1F | L (post) | 58–70 | Balbuto, Ténéfix, Nosferapti, Polichombr |  |  |
| SkyPillar_3F | L (post) | 58–70 | Balbuto, Ténéfix, Nosferapti, Polichombr |  |  |
| SkyPillar_5F | L (post) | 58–70 | Balbuto, Tylton, Ténéfix, Nosferapti, Polichombr |  |  |
| DesertUnderpass | L (post) | 58–70 | Métamorph, Chuchmur |  |  |
| ArtisanCave_1F | L (post) | 58–70 | Queulorior |  |  |
| ArtisanCave_B1F | L (post) | 58–70 | Queulorior |  |  |
