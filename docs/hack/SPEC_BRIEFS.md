# SPEC_BRIEFS — briefs des GM spécialistes (v3, *Pokémon Confluence*)

> Émetteur : Game Mechanics Director (GMD). Date : 2026-10-14. Source de vérité : `GAME_DESIGN_BIBLE.md` v3.0 (ci-dessous « la bible »).
> Méthode obligatoire : `GM_METHOD.md`. Avant de livrer, chaque spécialiste remplit la checklist universelle (§6.1) et sa checklist de domaine (§6.2). Un livrable sans checklist est renvoyé sans lecture.
> **Budget Claude Pro.** Lire **uniquement** les entrées listées. Écrire dense. Ne pas recopier la bible : la référencer (`bible §x`). Aucun extrait du corpus privé `.gm_skill/` dans un fichier suivi.
> **Interdits** (rejet immédiat) : pattern présenté comme solution automatique ; liste de mécaniques sans les décisions qu'elles créent ; complexité confondue avec profondeur ; contenu ajouté pour masquer une boucle faible ; « testé » ou « implémenté » affirmé sans preuve.
> **Désaccord avec la bible :** on ne la contourne pas en silence. On écrit le conflit, sa cause, une alternative et son coût, et on remonte au GMD.

---

## 0. Conventions partagées (les quatre briefs)

| Objet | Convention |
|---|---|
| Personnages | `C-01`… : l'ordre et la liste sont fixés par le brief A en S1 (§0.2). Rangs A/B/C selon bible §9 |
| Zones écologiques | `Z-01` à `Z-06` (bible §11.1) : le découpage est fixé par le brief D en S1 |
| Décisions | `D001`–`D131` (bible §8.3, budgets par chapitre) ; classes de coût **S**, **M**, **L** ; types **E** (explicite) et **D** (discret) |
| Équipes | `T-<perso>-<palier><variante>` (ex. `T-BLUE-T2B`) ; paliers T1–T5 (bible §10) |
| Flags et vars | `FLAG_CF_*` et `VAR_CF_*`. **Seul le brief C alloue** les ID ; il les inscrit dans `FLAGS_VARS_REGISTRY.md`. Les autres briefs demandent des états **par nom logique** (ex. « `STANCE_ONDINE` à 3 valeurs ») |
| Systèmes | abréviations de la bible §11.1 (`BR`, `BL`, `HO`, `rL`, `PA`, `RK`, …) |
| Texte FR | ≤ 208 px par ligne, 2 lignes par boîte, une idée par boîte, “ ” ; un échantillon de réplique doit tenir dans une boîte |
| Étiquettes de lore | `CANON (jeu)` / `HYPOTHÈSE` sur tout fait de lore |
| Statuts | `proposé` → `implémenté` → `testé` → `validé` (seul le GMD valide) |

### 0.1 Interfaces (qui fournit quoi à qui)
| Fournisseur → Consommateur | Objet | Point de synchro |
|---|---|---|
| A → C | positions par personnage (axes A/B), pulsations (carte, chapitre), scènes de témoin, relations PNJ–PNJ déplaçables | S1 |
| A → B | identité de combat (noyau canonique, ce que l'équipe raconte), variantes de position | S1 |
| C → A, B, D | noms logiques et ID alloués des états ; table des sélecteurs de variante ; jalons de plafond ; décisions qui touchent un personnage, une équipe ou une zone | S1 (brouillon), S2 (final) |
| C → B | combats refusables qui sont des décisions (flag de refus, script de refus, conséquence) | S2 |
| D → B | espèces disponibles pour le joueur avant chaque combat majeur (options d'équipe), espèces cohérentes pour les satellites de chaque personnage (origine ou nœud) | S1 |
| D → C | missions de zone et leurs issues → états `Z-xx` ; épidémies d'anneaux liées à `PA` ; conditions des légendaires par fin | S1 |
| B → C | combats à deux issues (ce que chaque issue écrit), combats qui servent de jalon | S2 |
| Tous → GMD | livrable + checklist + liste des conflits avec la bible | S2 |

**S1** = premier passage à environ 50 % (squelettes, tables, ID logiques). **S2** = livraison. Après S1, aucun spécialiste ne change un nom logique publié sans prévenir les autres.

---

## Brief A — DISTRIBUTION ET RELATIONS → `CHARACTER_AND_LORE.md` v3

**Portée.**
- Tous les personnages de la bible §9 :
  - noyau (rang A) ;
  - Mission Indigo et Kanto ;
  - Hoenn ;
  - commandants Rocket ;
  - rangs C ;
  - Hoopa et Rayquaza comme « personnages » muets.
- La toile relationnelle.
- Les guides de voix.
- Le lore et la mythologie (Voleur d'Anneaux, Fiole, Pilier Céleste, Peuple du Météore, les sceaux anciens de Bayar).
- La chronologie détaillée.
- Les règles de lore.

**Hors portée :** équipes (brief B), mécanique des décisions (brief C), espèces (brief D).

**Entrées (seulement) :**
- bible §0–§9 et §12–§13 ;
- `CAST_DOSSIER.md` (fiches, §4 matrice, §5 assets) ;
- `LORE_DOSSIER.md` §8 (et §1.3, §1.6, §7 n° 1, 2, 5, 13, 20, 25 si besoin) ;
- `STORYCRAFT_RESEARCH.md` §2 et §4 ;
- `reviews/REVIEW_V2_NARRATIVE.md` (défauts N1–N23 à ne pas reproduire).

**Sorties :**
1. **Fiche par personnage.** Rang A ≈ 1 page ; rang B ≈ ½ page ; rang C ≈ 8 lignes. Champs :
   - ID, noms FR/EN, rang, étiquettes canon ;
   - fonction narrative ;
   - **veut → besoin**, faiblesse qui crée le conflit ;
   - **agenda** (É/A/M) et **réponse au test du figurant** (« sans Red, demain il… ») ;
   - positions axe A / axe B **et ce qui peut les déplacer** (preuve, relation, événement) ;
   - alliances et rivalités **avec des PNJ** (au moins une de chaque) ;
   - **pulsations** : carte, chapitre, déclencheur, ce qu'on voit, action du joueur ;
   - **scène qui définit** (8–15 boîtes) ;
   - **table de saillance** (3–5 répliques selon l'état, la plus spécifique gagne) ;
   - ce que son équipe raconte (pour le brief B) ;
   - écho d'épilogue par fin (F1–F5) ;
   - contrainte canon (avenir en année 3) ;
   - asset (pic, OW, repli).
2. **Guide de voix** par rang A et B : 3 traits, 3 tics ou interdits, **3 répliques d'exemple dans les limites de la boîte**. Plus Brice parlant pour Red : comment il traduit les 5 gestes, et ses maladresses.
3. **Toile relationnelle** : matrice de tous les majeurs (F, R, M, A, E, C), plus la liste des relations **déplaçables** par le joueur (au moins 5 ; bible §9), plus au moins 6 **scènes de témoin**.
4. **Lore et mythologie** :
   - la légende du Voleur d'Anneaux et le texte de l'inscription du Mont Mémoria ;
   - les règles H1–H4 et Y1–Y3 écrites comme le monde les raconte (conte, loi, choix) ;
   - le parallèle avec les sceaux anciens (Regis) ;
   - la culture du Peuple du Météore ;
   - Passerelle (histoire, nœuds, contrats) ;
   - **chronologie détaillée** cohérente avec bible §3.1.
5. **Registre des promesses** (plants et récoltes) pour R1–R4, Q1–Q5 et les indices de la bible §4.3 : ID, plant, rappel, récolte.
6. **Table « qui gagne si X échoue »** complétée (bible §7).

**Critères d'acceptation :**
- 100 % des personnages de la bible §9 sont couverts. Rang A ≥ 6 scènes, rang B ≥ 4 pulsations, rang C ≥ 2 scènes + un écho. Aucun personnage sans agenda ni relation PNJ.
- Les 8 Champions de Kanto (Giovanni compris), le Conseil 4 de Kanto, Chen, Blue, Léo, Fuji, Ciléo, le Président de Sylphe et les 4 commandants Rocket ont **une raison concrète d'être à Hoenn** et **un désaccord** avec au moins un autre personnage majeur.
- Avenir canonique respecté (bible §3). Aucune théorie de fans présentée comme canon. Toute invention porte l'étiquette HYPOTHÈSE.
- Aucun personnage ne pense ce que Red lui dicte : toute position déplaçable l'est par une **preuve, une relation ou un événement**, jamais par simple choix de menu (leçon N12).
- Personne ne résout le conflit central à la place du joueur. Personne n'a entièrement raison, sauf la Rocket qui est l'égoïsme lisible.
- Répliques d'exemple vérifiées contre la limite de 208 px (compte par la police : `tools/` ou calcul manuel déclaré).
- Les défauts N1–N23 des revues ne se reproduisent pas : chacun est relu et coché.

**Taille cible :** 70–110 Ko.

---

## Brief B — COMBAT ET ÉQUIPES ADAPTATIVES → `COMBAT_DESIGN.md` v3

**Portée :**
- toutes les équipes des dresseurs majeurs, par rencontre : arènes, rivaux, Défis Indigo, Tournoi des Confluences, duels d'histoire, climax, Ligue (selon la fin), postgame T5 ;
- les sélecteurs de variante ;
- les flags d'IA ;
- la politique Méga ;
- l'arc de maîtrise du combat (remplace `EXPERIENCE_INTENT` §7) ;
- l'allocation des ID de dresseurs recyclés ;
- les principes pour les dresseurs de route (qui enseignent ce que le prochain combat majeur teste).

**Hors portée :** la distribution des espèces sauvages (brief D), la logique des décisions (brief C).

**Entrées (seulement) :**
- bible §2.1, §8, §9 (colonne Combats), §10, §12–§14 ;
- `CAST_DOSSIER.md` (équipes canoniques, identités, concepts) ;
- `GM_METHOD.md` §4.2, §4.5, §4.10, §5.4 ;
- `ENGINE_CHANGES.md` §H1, H2, D1, D2 ;
- `AI_AUDIT.md` (flags d'IA disponibles) ;
- `TECHNICAL_AUDIT.md` §4 ;
- `tools/qa/validate_trainers.py` ;
- les sorties S1 des briefs A, C et D.

**Sorties :**
1. **Arc de maîtrise par palier** (T1–T5) : pattern appris, signal de routine, réponse (nouveau contexte, nouvelle interaction, variabilité, contrainte).
2. **Table des rencontres** : chaque combat majeur avec chapitre, carte, palier, obligatoire / à deux issues / refusable, jalon de plafond éventuel, ID recyclé.
3. **Équipes** au format `trainers.party` (Showdown). Pour chaque personnage majeur :
   - noyau canonique, puis satellites Gen 1–9 **justifiés** (origine conforme à la bible §5.3, ou au passé du personnage, ou à une décision) ;
   - variantes de position (A/B/…) ;
   - une variante de difficulté `Hard` pour les combats majeurs (`B_VAR_DIFFICULTY`) ;
   - au minimum ces variantes :
     - Blue : 3 contre-équipes par type dominant (E-ADAPT) × paliers T1–T4, plus T5 ;
     - Brice : 3 voies (`BV`) × starter ;
     - Timmy et Pierre (Brock) : avec ou sans l'arrivant sauvé ;
     - Olga : avec ou sans ses Lokhlass ;
     - Peter : avec ou sans le Drattak ;
     - Amaryllis au climax : avec ou sans l'anomalie P2 ;
     - Maître : Pierre Rochard **et** Marc.
4. **Fiche combat majeur** (`GM_METHOD` §5.4) pour chaque combat d'histoire, arène, rival et climax. Elle comprend :
   - la préparation possible et l'endroit où elle s'obtient ;
   - au moins 2 plans de victoire ;
   - une part de hasard faible dans le verdict ;
   - la checklist « présence du fun ».
5. **Flags d'IA par palier**, justifiés par l'intention (jamais « le maximum partout »).
6. **Allocation des ID** : liste des ID vanilla recyclés (revanches, Magma/Aqua, rivaux, libres) → `T-…`. Zéro collision, compte restant.
7. **Politique Méga** : qui, quand (après le ch. 8), quelle gemme, et comment c'est annoncé.
8. **Dresseurs de route** : principes par chapitre (ce qu'ils enseignent), niveaux par rapport au plafond, sbires Rocket et brigades du Rempart comme couches de faction.

**Critères d'acceptation :**
- `validate_trainers.py --learnsets` : **0 erreur** sur toutes les équipes livrées (log joint).
- Niveaux ≤ plafond + 2 (As + 3) au moment du combat, vérifiés contre la table des jalons du brief C.
- Chaque combat d'histoire a ≥ 2 plans de victoire, et la victoire ne tient pas à un seul jet (OHKO, sommeil long, etc.).
- Chaque équipe d'un personnage majeur **raconte sa position**. Le changement de variante est visible et explicable après coup.
- Aucune espèce, donnée ou animation modifiée. Pas de Mewtwo pour la Rocket ni pour Giovanni. Pas de légendaire dans une équipe de PNJ pendant l'histoire, sauf décision du GMD (anomalie P2 d'Amaryllis : Ultra-Chimère ou Paradoxe non légendaire, à justifier).
- Les combats refusables-décisions utilisent `trainerbattle_single_declinable` avec un flag de refus fourni par le brief C. Aucun combat obligatoire n'est refusable.
- Pas de rentabilité au farm : aucune récompense d'EXP au-delà du plafond, revanches désactivées jusqu'au postgame.
- Budget d'ID respecté, avec un compte affiché.

**Taille cible :** 60–100 Ko, plus `trainers.party` en annexe de travail (fichier source à intégrer seulement après validation).

---

## Brief C — DÉCISIONS ET SYSTÈMES → `DECISION_LEDGER.md` (+ `DECISION_LEDGER_ACT0-1.md`, `_ACT2.md`, `_ACT3.md`, `_POST.md`) et `GAME_SYSTEMS.md` v3

**Portée :**
- les 131 décisions listées (≥ 115 robustes), selon les budgets par chapitre de la bible §8.3 ;
- les systèmes cachés (bible §11) ;
- le Sommet (3 motions, négociation par gestes, option défendue distincte du résultat) ;
- le climax (affectation, résultat de la Fiole) ;
- les **conditions formelles des fins** (bible §12), exhaustives et exclusives ;
- les plafonds par jalons ;
- l'économie (argent, Kiosque, puits) ;
- les quêtes ;
- la QoL ;
- **l'allocation de tous les flags et vars** (`FLAGS_VARS_REGISTRY.md`) ;
- la table de traversée par branche (aucun softlock) ;
- la table « lectures par carte ».

**Entrées (seulement) :**
- bible (intégrale) ;
- `reviews/REVIEW_V2_SYSTEMS.md` (S1–S20 : la grille VALIDE / FAIBLE / DOUBLON / NON-IMPL. s'applique telle quelle) ;
- `STORYCRAFT_RESEARCH.md` §3 et §8.2 ;
- `ENGINE_CHANGES.md` ;
- `FLAGS_VARS_REGISTRY.md` ;
- `TECHNICAL_AUDIT.md` §7 et §9 ;
- `archive/cendres_v2/GAME_DESIGN_BIBLE.md` §10 (table des portes vanilla à re-vérifier) ;
- les sorties S1 des briefs A, B et D.

**Sorties :**
1. **Règles du registre**, reprises de la v2 et durcies :
   - champs : `ID · Type E/D · Classe S/M/L · Déclencheur · Options · Prérequis · Stockage · Immédiat · Différé / contenu affecté · Systèmes (deltas) · Fins · Test · Statut` ;
   - pour chaque option, **un gain et une perte dans deux systèmes différents** ;
   - délais de conséquence visés : environ 50 % immédiats, 35 % différés courts, 15 % différés longs ;
   - un signal de mémoire pour les classes M et L.
2. **131 décisions.** Au moins 30 % discrètes. Environ 5 % de classe L, dont les décisions L de la bible §8.3. Les combats refusables passent par la macro D1.
3. **`GAME_SYSTEMS.md` v3** :
   - spécification de chaque système : stockage, bornes, valeur de départ, écrivains, **lecteurs**, seuils ;
   - **tableau de cumul** (maximum atteignable par chapitre) qui justifie chaque seuil ;
   - Sommet (votants, conditions relatives, au moins 3 votants potentiels par option, au moins une condition coûteuse ailleurs) ;
   - climax (affectation, répliques de veillée qui annoncent chaque seuil, résultat déterministe) ;
   - fins (ordre d'évaluation, chemins témoins pour **chaque** fin et chaque variante sociale) ;
   - plafonds (`LEVEL_CAP_VARIABLE`, script commun de montée, **jalon posé dans toutes les branches**) ;
   - économie (sources et puits par chapitre, plafond du Kiosque) ;
   - quêtes ; QoL.
4. **Allocation** des flags et vars dans `FLAGS_VARS_REGISTRY.md` :
   - ID, nom, propriétaire, lecteurs ;
   - vars ≤ 45 sur les 54 libres, plus des vars vanilla recyclées (**liste prouvée par grep** : aucun lecteur vanilla restant) ;
   - choix à 3 options rangés en bits (E-BITS) ;
   - flags ≤ 260, plus des `FLAG_HIDE_*` recyclés dont les lecteurs sont listés.
5. **Table de traversée par branche** : capacités requises, donneurs, soins (≤ 2 cartes), portes vanilla touchées (avec preuve par grep), et **cas de softlock** examinés (Plongée ouvre la Caverne Fondmer et Atalanopolis, refus, défaites, retour arrière).
6. **Table « lectures par carte »** : chaque carte, les états qu'elle lit, ce qui change.
7. **Analyse de dominance** (`GM_METHOD` §6.1) :
   - le « chemin doré » simulé à partir des maxima, avec la preuve qu'il **ne** donne **pas** tout ;
   - « payer toujours » ;
   - « plaire à tous » ;
   - « tout capturer » ;
   - « farmer ».
8. **Liste des aides moteur requises** (E-*) avec, pour chacune, la décision ou le système qui l'exige.

**Critères d'acceptation :**
- ≥ 115 décisions **VALIDE** selon la grille de `REVIEW_V2_SYSTEMS` §1, en lecture stricte, avec le décompte affiché. Aucune NON-IMPL. **comptée**. Les doublons et les cosmétiques sont listés mais **non comptés**.
- Zéro état écrit sans lecteur. Chaque delta est gardé par un flag à usage unique.
- Toutes les fins (F1–F5 × 3 variantes sociales) atteignables, avec un chemin témoin pour chacune. Évaluation exhaustive et exclusive.
- Aucune fin ni variante n'est accessible par une victoire de combat seule (invariant 4).
- Chaque jalon de plafond est posé dans toutes les branches (y compris refus, défaite et fuite). La montée est monotone.
- Budget vars et flags respecté, avec le compte affiché. Aucun ID alloué hors `FLAGS_VARS_REGISTRY.md`.
- Chaque décision a un test reproductible : état de départ, séquence, observation, vars attendues.
- Les défauts S1–S20 de la revue systèmes ne se reproduisent pas (cochés un par un).

**Taille cible :** registre de 80–120 Ko au total ; `GAME_SYSTEMS` de 30–50 Ko.

---

## Brief D — ESPÈCES ET ÉCOLOGIE → `ENCOUNTERS_PLAN.md`

**Portée :**
- la **répartition des 1 025 espèces Gen 1–9** (formes : politique à définir) à travers Hoenn :
  - sauvages : herbe, surf, pêche (3 cannes), Éclate-Roc ;
  - par moment de la journée si E-TOD est retenu ;
  - épidémies d'anneaux ;
  - Parc Safari ;
  - cadeaux, échanges en jeu, fossiles, œufs, évolutions ;
  - légendaires et fabuleux au postgame, **par fin** ;
- les états d'écosystème `Z-01`–`Z-06` (tables alternatives) ;
- les missions de zone ;
- les événements de perturbation ;
- la rareté ;
- les niveaux au regard des plafonds ;
- les options d'équipe pour chaque prochain défi.

**Entrées (seulement) :**
- bible §1, §2.2, §5, §6, §8, §11.1, §12.4, §13 (invariants 6, 8, 9) et §14 ;
- `LORE_DOSSIER.md` §8.7 et §4.2–4.3 (formes, fossiles) ;
- `GM_METHOD.md` §4.3, §4.5 et §6.2 (économie, rencontres) ;
- `TECHNICAL_AUDIT.md` §3 ;
- `src/data/wild_encounters.json` (lecture : capacité par carte) ;
- `include/config/overworld.h` (`OW_TIME_OF_DAY_ENCOUNTERS`) ;
- `include/global.h` (champs d'épidémie) ;
- les sorties S1 des briefs B et C.

**Sorties :**
1. **Analyse de capacité.**
   - Cartes à rencontres, et emplacements par méthode : 12 herbe, 5 surf, 10 pêche, 5 Éclate-Roc.
   - Espèces de base à placer, comparées au nombre d'emplacements.
   - Gain apporté par E-TOD, par les tables alternatives E-ECO et par les épidémies E-OUT.
   - Conclusion : faisable, ou liste des compromis avec leur coût. **Décision du GMD requise avant de remplir les tables.**
2. **Politique des formes :**
   - formes régionales et de Hisui ;
   - Paradoxes et Ultra-Chimères (palier P2) ;
   - formes cosmétiques (exclues du compte si le moteur les traite comme une seule espèce) ;
   - Méga (objets, pas espèces) ;
   - l'option retenue pour chaque cas.
3. **Carte nœuds → zones** (bible §5.3) appliquée. Au moins 80 % des espèces étrangères sauvages d'une zone viennent des régions de son nœud ; l'écart est justifié comme du bruit.
4. **Tables par carte et par état** :
   - ENVAHI : natifs raréfiés, arrivants dominants ;
   - MIXTE ;
   - RESTAURÉ : natifs de retour, quelques arrivants installés ;
   - au moins 3 emplacements changent entre états, dont **un natif emblématique**.
   Le format reste près de `wild_encounters.json` (taux, niveaux min/max). Les natifs de Hoenn emportés par la loi d'échange sont signalés.
5. **Rareté et progression** :
   - paliers de rareté ;
   - aucune espèce pseudo-légendaire de base avant le ch. 8 (sauf décision du GMD) ;
   - niveaux sauvages 2 à 4 sous le plafond ;
   - chaque route offre 1 ou 2 **options d'équipe** pour le combat majeur suivant (croisé avec le brief B).
6. **Épidémies d'anneaux** (E-OUT) : calendrier par chapitre et par `PA`, espèce, carte, niveau ; apparition des anomalies P2 à partir du ch. 8, croissante avec `PA`.
7. **Missions de zone** (une par `Z-xx`) : déclencheur, approches possibles (≥ 2), issues → état de zone. La décision correspondante est **transmise au brief C** ; elle n'est jamais un compteur de captures.
8. **Perturbations écologiques et sociales** (bible §5.4) : espèces exactes, effets en PNJ, prix, barrages, et lecteurs demandés au brief C.
9. **Légendaires et fabuleux** :
   - pour chaque espèce, le **canal par fin** (F1–F5) ;
   - le lieu (lieux Mirages / anneaux sur cartes existantes, ex. Île du Sud, Île Lointaine, Île Aurore, Roc Nombri, Pilier Céleste, Grotte Originelle, Tour Mirage) ;
   - la condition ;
   - les exceptions de l'histoire (Hoopa, Rayquaza, Latios et Latias) ;
   - **preuve que chaque espèce est obtenable dans chaque fin**.
10. **Cadeaux et starters des autres régions** : qui les donne, quand, pourquoi (en lien avec le brief A), et équilibre.
11. **Table de couverture finale** : les 1 025 espèces → méthode(s), carte(s), chapitre le plus tôt, fin(s). Script de vérification proposé (comptage depuis le JSON et les scripts).

**Critères d'acceptation :**
- **100 % des espèces Gen 1–9 obtenables dans chaque fin**, prouvé par la table de couverture et par un comptage scriptable.
- L'origine des espèces est cohérente avec les nœuds (≥ 80 % par zone). L'indice de R2 est lisible : une zone donne une région dominante.
- Aucun farm rentable : niveaux sous le plafond, aucun objet d'EXP en boucle, épidémies bornées.
- Les états d'écosystème changent au moins 3 emplacements visibles, dont un natif emblématique. L'état n'est jamais piloté par le nombre de captures.
- Chaque combat majeur a au moins 2 réponses d'équipe disponibles avant lui, que le joueur peut construire à partir de ce qu'il rencontre (croisé avec le brief B).
- Aucune espèce, donnée ou sprite modifiés. Les espèces sont nommées en FR, avec une vérification des noms Gen 8–9 signalée (◐).
- Les limites techniques sont respectées, ou les compromis sont validés par le GMD. Les aides moteur requises (E-TOD, E-ECO, E-OUT) sont listées avec leur nécessité.

**Taille cible :** 60–120 Ko, plus les tables de travail (CSV acceptés dans `docs/hack/data/` si besoin).

---

## Ordre et revue
1. Les quatre briefs démarrent en parallèle. **S1** à ≈ 50 % : publication des tables d'interface (§0.1).
2. Le GMD arbitre les conflits de S1 en une passe (bible changelog).
3. **S2** : livraison, puis revue du GMD (`GM_METHOD` §6.3, échelle §6.4).
4. Ensuite, revues critiques indépendantes (narration, systèmes), puis la tranche représentative (ch. 0–2) en production.
