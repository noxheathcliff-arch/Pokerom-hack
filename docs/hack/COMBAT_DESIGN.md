# COMBAT_DESIGN — *Pokémon Confluence* (v3.0, brief B)

> Propriétaire : GMD secondaire « Combat et équipes adaptatives ». Autorité : `GAME_DESIGN_BIBLE.md` v3.0 (« bible »). Méthode : `GM_METHOD.md`.
> Statut : **proposé** (conception). Aucune équipe n'est intégrée à `src/data/trainers.party` ; rien n'est implémenté ni testé en ROM. Seule preuve fournie : validation statique (§13).
> Annexe de travail (source unique des équipes) : `docs/hack/data/teams_v3.party` (format `trainers.party`, Showdown), générée par `docs/hack/data/teams_v3_gen.py` (données + règles Normal → Hard). Les fiches de ce document montrent les équipes Normal en clair ; l'annexe contient **toutes** les variantes, Normal et Hard.
> Entrées lues : bible §2, §5, §7–§14 ; `SPEC_BRIEFS` §0 et brief B ; `GM_METHOD` §4.2, §4.5, §4.10, §5.4, §6 ; `CHARACTER_AND_LORE` §1 ; `ENCOUNTERS_PLAN` §2.2–2.3, §8, §10.4–10.5 ; `STRATEGY_RESEARCH` ; `AI_AUDIT` ; `CAST_DOSSIER` (équipes canoniques) ; `ENGINE_CHANGES` H1, H2, D1, D2 ; `TECHNICAL_AUDIT` §4 ; `include/constants/opponents.h`, `src/battle_setup.c` (`gRematchTable`).
> Les sorties du brief C (ID de flags/vars, table définitive des jalons) n'existent pas encore : ce document demande des états **par nom logique** (§11) et s'aligne sur les jalons de la bible §8.3.

## Sommaire
0. Intention, clause de contrat, sémiotique
1. Arc de maîtrise T1–T5 (remplace `EXPERIENCE_INTENT` §7)
2. Modèle de paliers, niveaux et règles de construction
3. Flags d'IA par palier et par personnalité
4. Table des rencontres (tous les combats majeurs)
5. Sélecteurs de variante (quel état choisit quelle équipe)
6. Politique Méga
7. Équipes par personnage (identité, rencontres, variantes, menaces, réponses)
8. Fiches combat majeur (21 fiches, `GM_METHOD` §5.4)
9. Mode Difficile (`Difficulty: Hard`) : règles de dérivation
10. Dresseurs de route et couches de faction
11. Interface avec les briefs A, C, D (états demandés, combats à deux issues)
12. Allocation des ID de dresseurs
13. Validation (log) et tests d'acceptation
14. Conflits avec la bible et décisions demandées au GMD
15. Checklists `GM_METHOD` §6.1 et §6.2
16. Changelog

---

## 0. Intention, clause de contrat, sémiotique

**Intention (rattachée à bible §2) :** chaque combat majeur est une **question posée par un personnage**, et son équipe est sa réponse à la crise. Le joueur gagne en **lisant** l'équipe (observer → hypothèse → préparer → vérifier), jamais en surniveau. La force de l'équipe ne règle aucun problème politique (invariant 4) : un combat écrit un état (§11.2) ou ouvre une scène ; il ne décide pas d'une politique.

**Comportement visé (observable) :** avant un combat majeur, le joueur **change 1 ou 2 membres** de son équipe, ou leurs capacités, en réponse à un indice vu avant (PNJ, route, réplique). Pendant le combat, il **change de Pokémon** au moins une fois pour une raison de type, de talent ou de tempo.

**Clause de contrat (système « Combats majeurs et équipes adaptatives ») :**
- **Structure dominante :** émergence locale (règles de combat, talents, objets, IA) dans un cadre de progression (paliers T1–T5 liés aux jalons de plafond).
- **Famille mécanique :** manœuvre tactique ; co-dominée par l'économie interne de l'équipe (PV/PP/objets entre deux soins, 6 places, plafond).
- **Économie interne :** sources = captures (tables par zone), CT et tuteurs, objets placés ; convertisseur = l'EXP plafonnée (souple) ; puits = PV/PP pendant les séquences sans soin (raid, Centre Spatial, climax), objets consommés. Information : l'équipe du boss est **annoncée** (réplique, PNJ, dresseurs de route qui la préfigurent).
- **Espace de possibilités :** ≥ 2 plans de victoire par combat majeur (fiches §8) ; l'adversaire adaptatif (Blue, Peter, Giovanni) déplace la meilleure réponse selon l'équipe du joueur.
- **Stratégies dominantes recherchées :** « le starter surentraîné » (contre-pression : plafond, Fermeté, Intimidation, équipes qui couvrent leur faiblesse) ; « un seul type super efficace » (E-ADAPT, satellites hors type) ; « un boost puis tout balayer » (priorité adverse, `Smart Mon Choices` pour achever après un KO, Inconscient et Buée Noire chez Ondine et Juan) ; « farmer les dresseurs » (EXP plafonnée, pas de revanche avant le postgame).
- **Contrebalancement :** plafond souple (H1) ; satellites de couverture ; IA qui change de Pokémon (à partir de T2) mais **sans omniscience** sauf les télépathes (§3.2).
- **Signification :** l'équipe **raconte la position** (bible §10, `CHARACTER_AND_LORE` §1.6) : natifs (Rempart), arrivants rencontrés à Hoenn (Intégration), imports achetés (Marché), pièces anciennes (Gardiens). Ce que le joueur a fait (sauvé, abattu, rendu) **se voit dans les équipes** adverses.

**Sémiotique (4 couches) des mécanismes de combat propres à ce document :**

| Mécanisme | Effet mécanique | Sens fictionnel | Sens appris | Sens thématique |
|---|---|---|---|---|
| E-ADAPT (Blue, Peter, Giovanni) | l'équipe adverse change selon le type dominant du joueur | ils ont **étudié** Red : Blue par jalousie, Peter par méthode, Giovanni par mépris | « une équipe monotype se fait lire » | celui qui ne regarde que sa force devient prévisible |
| Satellite « sauvé » (Pierre, Timmy, Olga, Peter) | un Pokémon de plus (ou différent) dans l'équipe adverse | l'arrivant que Red a sauvé se bat aux côtés de celui qui l'a recueilli | « mes actes se voient chez les autres » | tout échange a deux côtés : le sauvé n'est plus à moi |
| Plafond par jalons | EXP ÷4 à ÷64 au-delà | accréditation de crise | « la force se borne » | même Red ne force pas le monde |
| Omniscience des télépathes (Morgane, Lévy et Tatia, Capucine) | l'IA connaît les capacités et objets du joueur | ils **lisent** l'esprit | « contre eux, la surprise ne marche pas : il faut une équipe honnête » | voir l'avenir n'est pas le décider (Morgane) |
| Méga d'un seul Pokémon désigné | une forme Méga au premier tour | pierre du Peuple du Météore ou de Devon | « le pic de puissance est visible et unique » | la puissance empruntée a une origine (ROSA) |
| Refuser un Défi (D1) | pas de combat, flag de refus | geste de Red | « ne pas se battre est un acte » | la force n'est pas toujours la réponse |

---

## 1. Arc de maîtrise T1–T5 (remplace `EXPERIENCE_INTENT` §7)

Règle de travail (`GM_METHOD` §4.10) : chaque palier enseigne **un** motif principal, le combine avec un ancien, et change le contexte **avant** la routine. Jamais « plus de PV ».

| Palier (ch., plafonds) | Motif principal appris | Où il est introduit sans risque → exigé | Signal de routine attendu | Réponse (type) |
|---|---|---|---|---|
| **T1** (ch. 0–4 ; 14–25) | types et STAB ; **une** menace par combat ; choix de la tête (D2) | dresseurs de route R102–R104 (2 Pokémon, `Sequence Switching`) → Roxanne (Fermeté : le coup unique ne suffit pas) → Bastien (Gonflette : punir le setup) → Blue 1 (il lit ton type dominant) → Voltère (paralysie + Explosion annoncée) → raid du Tunnel (attrition sans soin) | « mon starter super efficace bat tout » (dès Bastien) | **nouveau contexte** : Blue 1 (E-ADAPT) ; **nouvelle interaction** : Fermeté, Intimidation (Arcanin de Blue), Absorb Volt (Voltère) |
| **T2** (ch. 5–8a ; 27–37) | **conditions de terrain** : météo (soleil d'Adriane, pluie de Brice), premier **double à enjeu** (Amaryllis contre Red et Peter ; le double sans enjeu est l'exercice de Major Bob au ch. 4), tempo (Paresse de Monaflèmit chez Norman) | exercice de Major Bob (ch. 4, refusable) → doubles de route R111/R112 → Site Météore (2 contre 1) ; Chemin Ardent (Chartor de route) → Adriane ; R117 (un Monaflèmit de route) → Norman | « je tape le plus fort chaque tour » (dès Norman) | **nouvelle contrainte** : Norman (Paresse : attendre est un coup) ; **variabilité** : Giovanni incognito (3 Pokémon, priorité) |
| **T3** (ch. 8–12 ; 37–53) | **contrôle** : Méga (intro ch. 8, R120), pièges d'entrée (Alizée) et nettoyage (Tour Rapide), écrans et neige (Olga), Distorsion (Lévy et Tatia), Relais (Juan), Illusion (Lambda) | chaque mécanique apparaît d'abord chez un dresseur de route **du même chapitre** (§10) | « ma Méga / mon meilleur Pokémon porte tout » | **nouvel espace de décision** : Défis Indigo variables, E-ADAPT de Peter, combats en série sans soin (Centre Spatial) |
| **T4** (ch. 13–14 ; 53–60) | **synthèse** : une thématique + une mécanique par adversaire ; série de combats sans soin (Pilier, Ligue) ; plusieurs plans de victoire | veillée (soin forcé) → climax (2 combats d'affilée) → Route Victoire (Blue) → Ligue | « je connais les ficelles » | **nouveau contexte** : l'équipe d'Amaryllis change avec `PA` (anomalie P2) ; Maître différent selon l'état (Pierre Rochard **ou** Marc) |
| **T5** (postgame ; 75) | **optimisation** : équipes complètes, EV, Méga, IA de prédiction ; lead variable (Zone de Combat) | Défis T5 (les mêmes personnages, équipes complètes) → Zone de Combat (Têtes) → dernier duel de Giovanni | « j'ai l'équipe qui bat tout » | **variabilité** : `Randomize Party Indices` aux Têtes ; Blue/Peter/Giovanni adaptatifs ; pools de la Zone |

**Ce qu'il reste à apprendre après la première solution :** une victoire contre Blue 1 apprend « la diversité bat l'adaptation » ; Blue 2 et Peter montrent que l'adaptation vise le **type dominant**, donc que l'on peut **l'appâter** (dominante en façade, dégâts ailleurs) : c'est une découverte d'expert voulue, pas un exploit (§5.3).

---

## 2. Modèle de paliers, niveaux et règles de construction

### 2.1 Plafonds en vigueur (bible §8.3) et niveaux des combats majeurs
Règle d'équité (critère du brief) : au moment du combat, **équipe ≤ plafond + 2, As ≤ plafond + 3**. Règle de calibrage (plus stricte, appliquée partout) :

| Palier | Équipe adverse | As | Exceptions |
|---|---|---|---|
| T1 | plafond − 3 … plafond | plafond + 1 | Brice R103 (premier combat) : niveaux 5–6 |
| T2 | plafond − 2 … plafond | plafond + 1 ; + 2 pour Champions, rivaux et chefs (Max, Giovanni, Amaryllis en 2 contre 1) | — |
| T3 | plafond − 1 … plafond + 1 | plafond + 2 | — |
| T4 | plafond … plafond + 2 | plafond + 3 (Maître seulement) | — |
| T5 | 75 … 77 | 78 | — |

Le « plafond en vigueur » est celui **avant** que le jalon du combat soit posé (le combat qui donne le badge 1 se joue au plafond 14).

| Jalon (bible §8.3) | Plafond après | Combats majeurs joués **sous** le plafond précédent |
|---|---|---|
| départ | 14 | Brice R103, Flora (Bois), Roxanne |
| badge 1 | 18 | Pierre (Brock), Bastien |
| badge 2 | 20 | Aldo, Blue 1, finale du Tournoi T1 |
| Blue 1 réglé ou sortie de Poivressel | 22 | Brice R110, Voltère, Major Bob |
| badge 3 | 25 | raid du Tunnel (Lance (Rocket)) |
| raid | 27 | Amaryllis ch. 5 (Site Météore) |
| Site Météore | 29 | Kelvin, Courtney, Max, Giovanni incognito, Adriane |
| badge 4 | 32 | Auguste, Timmy, Flora (Vergazon), Erika, Tournoi T2 (Blue) |
| R2 | 33 | Norman |
| badge 5 | 35 | Brice R119, Sarah (Institut) |
| Institut | 37 | Koga (piège), Alizée, Jeannine |
| badge 6 | 40 | Blue 2, nuit du marché (Matthieu ou Lance (Rocket) au port), Agatha, Lance (Rocket) au Mont Mémoria |
| planque Aqua | 42 | (rien de nouveau) |
| Mont Mémoria | 44 | Ondine, Olga, Lévy et Tatia, Morgane |
| badge 7 | 47 | Centre Spatial : Ariane, Lambda, Amaryllis ch. 10 ; Défis de Peter et Koga |
| Centre Spatial | 49 | Fondmer : Sarah, Arthur, Ondine (camp Aqua), Aldo |
| Fondmer | 51 | Juan |
| badge 8 | 53 | Brice ch. 12, climax : Ariane, Amos, Amaryllis ch. 13 |
| climax | 56 | Blue final, Conseil 4, Maître |
| Maître | 60 → postgame 75 | tous les combats T5 (niveaux fixes 75–78, même quand le plafond passe à 100) |

**Dépendance :** si le brief C déplace un jalon, la table §4 donne pour chaque combat le jalon dont il dépend ; on recalcule les niveaux avec la règle ci-dessus (le générateur prend le plafond en paramètre).

### 2.2 Règles de construction (bible §10)
1. **Noyau canonique** (2–3 espèces `CAST_DOSSIER`) toujours présent, à tous les paliers où l'espèce existe au niveau voulu.
2. **Satellites justifiés** : (a) origine conforme au nœud où le personnage agit (bible §5.3, `ENCOUNTERS_PLAN` §3.1, §10.5) ; (b) passé canonique du personnage ; (c) décision du joueur. La justification est écrite à côté de chaque satellite (§7).
3. **Pas de légendaire** en équipe de PNJ pendant l'histoire ; anomalie P2 d'Amaryllis = Ultra-Chimère non légendaire (Mouscoto ou Engloutyran, §7.5) ; Paradoxes réservés au postgame. **Pas de Mewtwo** pour la Rocket ni pour Giovanni. **Pseudo-légendaires** chez les PNJ : jamais avant le ch. 8 (symétrie avec `ENCOUNTERS_PLAN` §2.2), sauf Drattak (Salamence) d'Amaryllis et Draco du Peuple du Météore (natifs, canon ROSA) : Draby/Drackhaus au ch. 5, Drattak au ch. 10.
4. **Téracristal : aucun** (Tera Type jamais renseigné). **Méga** : §6.
5. **Talents** : toujours précisés (sans `Ability:`, le moteur prend le slot 0 : `B_TRAINER_MON_RANDOM_ABILITY FALSE`).
6. **Hasard du verdict borné** : pas d'attaque OHKO, pas de Hypnose/Grobisou chez un boss, pas de Roche Royale ni Griffe Rasoir, pas de Lilliput/Reflet ; sommeil seulement par Spore/Poudre Dodo d'un seul Pokémon et avec la clause de sommeil (`B_SLEEP_CLAUSE TRUE`, demandé §11) ; au plus **une** Ceinture Force par équipe ; jamais Ceinture Force + Fermeté sur le même Pokémon.
7. **Objets de sac** (`Items:`) : T1 1–2 Potion/Super Potion (Champions seulement) ; T2 2 Super Potion ; T3 2 Hyper Potion ; T4 2 Hyper Potion + 1 Total Soin ; T5 2 Potion Max + 1 Rappel Max (Défis T5 : aucun). Rivaux et Rocket : aucun objet de sac (ils n'ont pas de temps à perdre ; lisibilité).
8. **IV / EV (Normal)** : T1 IV 15, T2 IV 20, T3 IV 25, T4 IV 31 + EV 128/128 selon le rôle, T5 IV 31 + EV 252/252/4. Le mode Difficile dérive automatiquement (§9).
9. **Capacités** : toutes apprenables par l'espèce (niveau, œuf, CT/tuteur Gen 1–9), vérifiées par `validate_trainers.py --learnsets --strict-levels` (§13). Un PNJ peut connaître une capacité de CT absente du jeu du joueur : c'est permis par le moteur, mais signalé dans la fiche quand le joueur ne peut pas l'imiter.

---

## 3. Flags d'IA par palier et par personnalité

### 3.1 Jeux de flags (justifiés par l'intention, jamais « le maximum partout »)
Base de lecture : `AI_AUDIT` §2–§3. `OMNISCIENT` est **exclu** partout sauf §3.2. `Smart Trainer` n'est jamais utilisé tel quel (il inclut `OMNISCIENT`).

| Code | Ligne `AI:` | Pour qui | Intention |
|---|---|---|---|
| **AI-R0** | `Check Bad Move / Try To Faint` | dresseurs de route ch. 0–2 | pas d'erreur grossière ; lisible |
| **AI-R1** | `Basic Trainer` | route ch. 3–8, sbires | choix cohérent, pas de changement |
| **AI-R2** | `Basic Trainer / Smart Mon Choices / HP Aware` | Topdresseurs, mini-boss, route ch. 9+ | *revenge kill* après KO ; pas de changement volontaire |
| **AI-G1** | `Basic Trainer / Sequence Switching / Ace Pokemon` | Brice R103, Roxanne, Bastien, Flora ch. 1 | ordre fixe, As en dernier : on apprend les types |
| **AI-G2** | `Basic Trainer / Smart Switching / Ace Pokemon / HP Aware / Assume Stab` | Champions 3–8, Défis T1–T3, admins | changement raisonné, connaissance plausible (STAB vu) |
| **AI-RV** | `Basic Trainer / Smart Switching / Ace Pokemon / Know Opponent Party / Assumptions` | Brice (le recensement), Blue (il a observé Red) | ils **connaissent tes espèces**, pas tes sets |
| **AI-V** | `Basic Trainer / Smart Switching / Powerful Status / Ace Pokemon / Assumptions` | commandants Rocket, Max, Arthur, Amaryllis ch. 5 | météo, pièges, statut appuyés : la faction impose ses conditions |
| **AI-B** | `Basic Trainer / Smart Switching / Smart Mon Choices / Ace Pokemon / Assumptions / Predict Switch / PP Stall Prevention` | Giovanni, Peter, Amaryllis ch. 10/13, Ariane ch. 13, Blue final | premier contact avec la prédiction ; compensé par les répliques-indices |
| **AI-E** | AI-B + `HP Aware / Predict Incoming Mon / Predict Move` | Conseil 4, Maître, Défis T5 | plafond de l'IA honnête |
| **AI-Z** | AI-E + `Randomize Party Indices` (sans `Ace Pokemon`) | Têtes de la Zone T5 | tête variable : la préparation unique ne suffit plus |

### 3.2 Modificateurs de personnalité (un seul par personnage)
| Modificateur | Personnages | Raison (identité `CHARACTER_AND_LORE` §1.6) |
|---|---|---|
| `Risky` | Blue, Lance (Rocket), Damien, Bastien | fanfaron, cruel, joueur, impulsif : tente le KO limite (fenêtre pour le joueur) |
| `Conservative` | Pierre Rochard, Juan, Olga, Roxanne | prudents : ne visent le KO qu'à 100 % |
| `Prefer Status Moves` | Koga (COUVERT), Erika, Ariane | statut et parfum : l'usure est leur langage |
| `Force Setup First Turn` | Amaryllis (Danse Draco tour 1 : tell), Juan (Relais) | le premier tour **annonce** le plan |
| `Prefer Baton Pass` | Juan | « l'art du combat » : il passe la danse |
| `Will Suicide` | Voltère (Explosion canon), sbires Rocket « kamikazes » d'élite | annoncé par réplique (« Ça va faire boum ! ») |
| `Omniscient` | **Morgane, Lévy et Tatia, Capucine** uniquement | télépathes : ils lisent tes capacités ; la réplique d'avant-combat le dit ; contre-jeu : capacités honnêtes, pas de piège (§8) |
| `Attacks Partner` | aucun (réservé au postgame si un duo rival le justifie) | — |

Interdits : `Conservative` + `Risky` (s'annulent) ; `Negate Unaware` (handicap) ; `Randomize Party Indices` + `Ace Pokemon` (déplace l'As) ; `Stall` (inachevé dans le code).

---

## 4. Table des rencontres (tous les combats majeurs)

Légende : **O** obligatoire ; **2I** à deux issues racontées (victoire et défaite continuent l'histoire) ; **R** refusable (`trainerbattle_single_declinable`, flag de refus fourni par le brief C ; nom du brouillon C entre parenthèses) ; **P** partenaire de duo. « Jalon » = le combat **pose** ce jalon de plafond (bible §8.3) dans toutes ses issues. ID : voir §12 et `docs/hack/data/teams_v3_ids.csv` (ID exact par équipe).

| # | Ch. | Carte | Adversaire | Palier (plafond) | Type | Décision (brouillon C) | Jalon | Équipes (§7) |
|---|---|---|---|---|---|---|---|---|
| 1 | 0 | R103 | Brice 1 | T1 (14, niv. 4–6) | 2I | — | — | `T-BRICE-T1-R103-{T,M,G}` |
| 2 | 1 | Bois Clémenti | Flora 1 (brigade) | T1 (14) | R | D008 | — | `T-FLORA-T1` |
| 3 | 1 | Mérouville, arène | Roxanne | T1 (14) | O | — | badge 1 → 18 | `T-ROXANNE-T1` |
| 4 | 1 | Mérouville, mines | Pierre (Brock), Défi | T1 (18) | R | (à créer : `REFUS_PIERRE`) | — | `T-PIERRE-T1-{SANS,AVEC}` |
| 5 | 2 | Myokara, arène | Bastien | T1 (18) | O | — | badge 2 → 20 | `T-BASTIEN-T1` |
| 6 | 2 | Myokara, plage | Aldo, Défi | T1 (20) | R | D022 | — | `T-ALDO-T1` |
| 7 | 3 | Poivressel, Tente de Scott | Blue 1 (E-ADAPT) | T1 (20) | R | D027 | Blue 1 réglé → 22 | `T-BLUE-T1{A,B,C}` |
| 8 | 3–4 | Tente de Scott | Tournoi T1, finale : Jeannine | T1 (20) | R | — (contenu) | — | `T-JEANNINE-T1` |
| 9 | 4 | R110 | Brice 2 | T1 (22) | 2I | — | — | `T-BRICE-T1-R110-{T,M,G}` |
| 10 | 4 | Lavandia, arène | Voltère | T1 (22) | O | — | badge 3 → 25 | `T-VOLTERE-T1` |
| 11 | 4 | Lavandia, périmètre | Major Bob, exercice (double) | T1 (22) | R | D043 | — | `T-MAJORBOB-T1` |
| 12 | 4 | Tunnel Mérazon | Lance (Rocket), fin du raid | T1 (25) | 2I | (raid L, C) | raid → 27 | `T-LANCE-T1` |
| 13 | 5 | Chutes Météore 1F | Amaryllis 1 (seule **ou** 2 contre 1 avec Peter) | T2 (27) | 2I | D050 | Site Météore → 29 | `T-AMARYLLIS-T2-{SEULE,DUO}` ; partenaire `P-PETER-CH5` |
| 14 | 6 | Mont Chimnée | Kelvin, puis Max | T2 (29) | 2I | D054 (saboter / dénoncer) | — | `T-KELVIN-T2`, `T-MAX-T2` |
| 15 | 6 | Planque Magma | Courtney | T2 (29) | O | D059 | — | `T-COURTNEY-T2` |
| 16 | 6 | Chemin Ardent | Giovanni incognito (3 Pokémon) | T2 (29) | R | D056 | — | `T-GIOVANNI-T2` |
| 17 | 6 | Vermilava, arène | Adriane | T2 (29) | O | — | badge 4 → 32 | `T-ADRIANE-T2` |
| 18 | 6 | Vermilava, sources | Auguste, Défi | T2 (32) | R | (à créer : `REFUS_AUGUSTE`) | — | `T-AUGUSTE-T2` |
| 19 | 7 | Vergazon | Flora 2 (brigade) | T2 (32) | 2I | D064 a (défendre Timmy) | — | `T-FLORA-T2` |
| 20 | 7 | Vergazon | Erika, Défi | T2 (32) | R | (à créer : `REFUS_ERIKA`) | — | `T-ERIKA-T2-{MARCHE,INTEG}` |
| 21 | 5–8 | Tente de Scott | Tournoi T2, finale : Blue | T2 (32) | R | — | — | `T-BLUE-T2{A,B,C}` |
| 22 | 7 | Clémenti, arène (QG) | Norman | T2 (33) | O | — | badge 5 → 35 | `T-NORMAN-T2` |
| 23 | 8 | R119 | Brice 3 (voie `BV`) | T2 (35) | 2I | — | — | `T-BRICE-T2-R119-{BV}-{T,M,G}` (9) |
| 24 | 8 | Institut Météo | Sarah 1 | T2 (35) | O | — | Institut → 37 | `T-SARAH-T2` |
| 25 | 8 | Cimetronelle, canopée | Koga, piège (si Red lui dispute Hoopa par le combat) | T2 (37) | 2I | D075 a | — | `T-KOGA-T2-PIEGE` |
| 26 | 8 | Cimetronelle | Koga, Défi « sans rancune » | T2 (37) | R | D081 | — | `T-KOGA-T2-DEFI` |
| 27 | 8 | Cimetronelle, arène | Alizée | T2 (37) | O | — | badge 6 → 40 | `T-ALIZEE-T2` |
| 28 | 8 | R120 | duo avec Pierre Rochard (présentation de la Méga) | T3 (40) | P | — | — | partenaire `P-PIERREROCHARD-CH8` (adversaires : sbires) |
| 29 | 9 | Nénucrique, toit | Blue 2 | T3 (40) | R | D084 | — | `T-BLUE-T3{A,B,C}` |
| 30 | 9 | Planque Aqua | Matthieu (branche « raid de la Ligue ») | T3 (40) | O dans la branche | D082 b | planque → 42 | `T-MATTHIEU-T3` |
| 31 | 9 | Port de Nénucrique | coup de filet (double avec Olga contre sbires) | T3 (40) | P | D082 a | planque → 42 | partenaire `P-OLGA-CH9` |
| 32 | 9 | Mont Mémoria, sommet | Lance (Rocket) 2 | T3 (42) | 2I | (rite) | Mont Mémoria → 44 | `T-LANCE-T3` |
| 33 | 9 | Mont Mémoria | Agatha : rite profané (H) **ou** Défi après le rite | T3 (40 / 44) | 2I / R | (à créer) | — | `T-AGATHA-T3-{PROFANE,RITE}` |
| 34 | 9–10 | Nénucrique, port | Ondine, Défi | T3 (44) | R | (à créer : `REFUS_ONDINE1`) | — | `T-ONDINE-T3` |
| 35 | 9–10 | Nénucrique | Olga, Défi (avec ou sans Lokhlass) | T3 (44) | R | (à créer : `REFUS_OLGA`) | — | `T-OLGA-T3-{AVEC,SANS}` |
| 36 | 10 | Algatia, arène | Lévy et Tatia (double) | T3 (44) | O | — | badge 7 → 47 | `T-LEVYTATIA-T3` |
| 37 | 10 | Algatia | Morgane, Défi | T3 (44) | R | (à créer : `REFUS_MORGANE`) | — | `T-MORGANE-T3` |
| 38 | 10 | Centre Spatial 1F/2F | Ariane, puis Lambda (faux Giovanni), **série sans soin** | T3 (47) | 2I | D095 | Centre Spatial → 49 | `T-ARIANE-T3-RK{BAS,HAUT}`, `T-LAMBDA-T3` ; partenaire selon relations |
| 39 | 10 | Centre Spatial, toit | Amaryllis 2 | T3 (47) | 2I | — | — | `T-AMARYLLIS-T3` |
| 40 | 10 | Algatia | Peter, Défi Indigo (E-ADAPT × Drattak) | T3 (47) | R | D100 | — | `T-PETER-T3{A,B,C}-{DRATTAK,KANTO}` (6) |
| 41 | 11 | Caverne Fondmer | Sarah 2 (si elle reste) ; Ondine (camp Aqua) ; Arthur | T3 (49) | 2I / R (Ondine) | D102, D104 | Fondmer → 51 | `T-SARAH-T3`, `T-ONDINE-T3-AQUA`, `T-ARTHUR-T3-{COUPE,NEGOCIE}` |
| 42 | 11 | Caverne Fondmer ou Tente | Aldo (escorte) ou finale du Tournoi T3 | T3 (49) | R | — | — | `T-ALDO-T3` |
| 43 | 12 | Atalanopolis, arène | Juan | T3 (51) | O | — | badge 8 → 53 | `T-JUAN-T3` |
| 44 | 12 | Atalanopolis | Brice 4, duel avant le vote | T3 (53) | R | D111 | — | `T-BRICE-T3-CH12-{BV}-{T,M,G}` (9) |
| 45 | 13 | Centre Spatial (relais) | Ariane 2 ; Amos (si `RK` haut) | T4 (53) | 2I | climax (C) | climax → 56 | `T-ARIANE-T4-RK{BAS,HAUT}`, `T-AMOS-T4` |
| 46 | 13 | Pilier Céleste | Amaryllis 3 (avec ou sans anomalie P2) ; puis Rayquaza (sauvage, gagner du temps) | T4 (53) | 2I | D121 | climax → 56 | `T-AMARYLLIS-T4`, `T-AMARYLLIS-T4-P2` |
| 47 | 14 | Route Victoire | Timmy (avec ou sans son arrivant) | T4 (56) | R | D124 | — | `T-TIMMY-T4-{SAUVE,PERDU}` |
| 48 | 14 | Route Victoire | Blue final (E-ADAPT × `STANCE_BLUE`) | T4 (56) | O | (D123 avant) | — | `T-BLUE-T4{A,B,C}-{SCOTT,LIBRE}` (6) |
| 49 | 14 | Ligue | Damien, Spectra, Glacia, Aragon | T4 (56) | O | — | — | `T-DAMIEN-T4` … `T-ARAGON-T4` |
| 50 | 14 | Ligue | Maître : Pierre Rochard (PROTÈGE / ACCUSE) **ou** Marc | T4 (56) | O | (Sommet : `STANCE_PR`, démission) | Maître → 60 | `T-PIERREROCHARD-T4-{PROTEGE,ACCUSE}`, `T-MARC-T4` |
| 51 | P | Bourg-en-Vol, Zone, sites | Défis T5 (tous), Giovanni (dernier duel), Chen, Têtes, Tournoi final (Brice **ou** Blue) | T5 (75) | R | D127, D130 | postgame → 100 | tous les `*-T5*` |

**Bilan :** 51 rencontres majeures, 38 personnages adverses distincts, **175 équipes** (variantes comprises) + 175 blocs `Difficulty: Hard` + 3 partenaires. Aucun combat obligatoire n'est refusable ; aucune défaite n'est imposée (les combats d'histoire sont **O** ou **2I**).

**Arbitrage v3.1 (C7) :** seuls D022, D043, D081 et D100 sont des décisions ; Pierre, Auguste, Erika, Ondine 1, Olga et Morgane sont des Défis de **contenu** (macro, flag de refus 0, le Défi reste proposé) ; le combat d'Agatha « rite profané » est un combat d'histoire. La recommandation ci-dessous (flags pour Olga et Agatha) est rejetée.

**Combats refusables sans décision du brouillon C** (Pierre, Auguste, Erika, Ondine 1, Olga, Morgane, Agatha-rite) : demande au brief C (§11.1) soit de créer la décision (un flag de refus + un lecteur), soit de les traiter comme **Défis non comptés** (refus sans flag : le Défi reste proposé). Recommandation : flag de refus pour Olga et Agatha (ils écrivent un état lu au Sommet), pas de flag pour les autres.

---

## 5. Sélecteurs de variante

Ordre (bible §10) : **palier → position → décision → type dominant**. Le script choisit l'ID par `switch` sur les états, puis lance `trainerbattle` ; aucune équipe n'est construite à la volée.

### 5.1 Table des sélecteurs (états demandés au brief C par nom logique)
| Personnage | État lu (nom logique) | Valeurs → équipe | Où l'état est écrit | Lisible comment (avant ou après) |
|---|---|---|---|---|
| Brice | `STARTER_RED` (var vanilla du starter) | Red a Arcko → clé `T` ; Red a Poussifeu → clé `M` ; Red a Gobou → clé `G` (note ci-dessous) | ch. 0 | Brice le dit : « J'ai pris celui qui te bat. » |
| Brice | `BV` (0–3) | PROTÉGER / ACCUEILLIR / COMPRENDRE (0 = PROTÉGER par défaut) | calcul C (ch. 5–8) | son équipe : natifs, arrivants protégés, espèces rares |
| Blue | `EADAPT_TYPE` (E-ADAPT → `VAR_RESULT`) | paquet A / B / C (§5.3) | calculé juste avant le combat | réplique : « Ton équipe sent le Feu. J'ai ce qu'il faut. » |
| Blue | `STANCE_BLUE` {SCOTT, LIBRE} | ch. 14 et T5 : Scalpereur (import de Scott) **ou** Tauros (Bourg Palette) | W6 ch. 9 + `BL` | il le dit en sortant le Tauros : « Celui-là, c'est pas Scott qui me l'a vendu. » |
| Flora | `FL` + flag de bascule (D122) | T5 : FIDÈLE / BASCULÉE | ch. 13 | équipe mixte : les arrivants de Vergazon |
| Timmy | `TIMMY_SAUVE` (D038, D064) | SAUVE / PERDU | ch. 4–7 | Feuiloutan (son Feuillajou évolué) présent ou absent ; au T4, Delcatty à sa place |
| Pierre (Brock) | état `Z-02` ≠ ABATTU (mission des mines) | AVEC / SANS Charbi | ch. 1 | Charbi dans son équipe ; au T5, Monthracite |
| Erika | `STANCE_ERIKA` {MAR, INT} | MARCHE / INTEG | ch. 4–7 | Chlorobule (la fleur du contrat) **ou** Rosélia de Vergazon |
| Koga | `REL_KOGA_PETER` {DÉMASQUÉ, COUVERT, IGNORÉ} | PROPRE / PIÈGES (COUVERT = IGNORÉ) | ch. 10 (W10) | il ne pose aucun piège quand il est démasqué |
| Olga | `OLGA_LOKHLASS` (D082 a) | AVEC / SANS | ch. 9 | Lokhlass (As) **ou** Dimoret : elle chasse |
| Ondine | `REL_ONDINE_ARTHUR` sans `ONDINE_MISSION` | ch. 11 : combat AQUA (D104) ; T5 : AQUA / MISSION | ch. 9–11 | Démanta, Denticrisse, Superdofin : les bancs qu'elle a libérés |
| Auguste | `REL_AUGUSTE_FUJI` | T5 : MAGMA / FUJI | ch. 9 | Camérupt prêté par Magma **ou** Ossatueur d'Alola (le deuil de Lavanville) |
| Agatha | issue du rite (ch. 9) | PROFANÉ (H) / RITE (Défi) | ch. 9 | elle combat en colère (Spiritomb) ou elle transmet (Grodrive) |
| Peter | `D050` (respect du Site) + `EADAPT_TYPE` | DRATTAK / KANTO × A / B / C | ch. 5 ; avant le combat | Drattak (cadeau du Peuple du Météore) **ou** second Dracolosse |
| Giovanni | `EADAPT_TYPE` | T5 : A / B / C | avant le combat | Corboss, Hippodocus ou Tyranocif : « Je t'ai regardé. » |
| Amaryllis | `D050` (ch. 5) ; `PA` ≥ seuil P2 (ch. 13) | SEULE / DUO ; T4 / T4-P2 | ch. 5 ; ch. 13 | l'Engloutyran remplace l'Altaria : le ciel déchiré se voit |
| Ariane | `RK` ≥ seuil (C) | RKBAS (4–5 Pokémon) / RKHAUT (6, dont 2 « rachetés ») | ch. 10, ch. 13 | Chacripan et Grimalin : ce qu'on achète aux ruinés |
| Arthur | `STANCE_ARTHUR` {NÉGOCIE, COUPE} (D102) | COUPE / NEGOCIE | ch. 11 | arrivants marins libérés (Oyacata, Démanta) **ou** natifs |
| Pierre Rochard | `STANCE_PR` (père : PROTÈGE / ACCUSE) ; démission (F2) | PROTEGE / ACCUSE ; sinon Marc | ch. 12 ; fin | le fossile de Devon (Armaldo) disparaît s'il accuse |
| Amos | `RK` ≥ seuil haut | présent / absent | ch. 13 | — |
| Matthieu | D082 = b | présent / absent | ch. 9 | — |

**Note de cohérence (starters de Brice).** Les ID vanilla `TRAINER_BRENDAN_*_<STARTER>` nomment le starter **de Brice** : Red a Arcko → Brice a Poussifeu (`_TORCHIC`, clé `T`) ; Red a Poussifeu → Brice a Gobou (`_MUDKIP`, clé `M`) ; Red a Gobou → Brice a Arcko (`_TREECKO`, clé `G`). La clé (`T`, `M`, `G`) est le suffixe des équipes `T-BRICE-*`.

### 5.2 Lisibilité du changement de variante (critère du brief)
Chaque variante a **un signe visible avant ou pendant le combat**, et une réplique d'après-combat qui le rend intelligible après coup (exemple Olga AVEC : « Ils m'ont reconnue tout de suite. / Merci de me les avoir rendus. » ; SANS : « Je n'ai plus rien à protéger ici. / Alors je chasse. »). Les répliques complètes relèvent du brief A ; ce document fixe **ce que l'équipe montre**.

### 5.3 E-ADAPT : le type dominant et les trois paquets
**Calcul demandé (aide moteur E-ADAPT, code en ROM) :** pour chaque Pokémon apte de l'équipe, +2 à son type 1 et +1 à son type 2 ; le type au score maximal gagne ; égalité → type 1 du Pokémon de tête. Résultat : `VAR_RESULT = TYPE_*`. Le script convertit en paquet :

| Paquet | Type dominant du joueur | Ce que l'adversaire ajoute (Blue / Peter / Giovanni) | Pourquoi |
|---|---|---|---|
| **A** | Plante, Insecte, Glace, Fée, Psy, Spectre, Dragon | Arcanin + Corvaillus / Pondralugon (Archaludon) / Corboss | Feu, Acier, Vol, Ténèbres : ils frappent ou résistent ces types |
| **B** | Feu, Roche, Acier, Électrik, Normal, Ténèbres | Léviator + Minotaupe / Carchacrok / Hippodocus | Eau et Sol : immunité Électrik, dégâts Feu/Roche/Acier |
| **C** | Eau, Sol, Vol, Poison, Combat | Noadkoko + Zéblitz / Pomdorochi (Hydrapple) / Tyranocif | Plante, Électrik, Psy, Roche |

**Équité et exploitation voulue.** Le calcul ne lit que les **types**, pas les capacités : un joueur qui met une dominante en façade et ses dégâts ailleurs **déjoue** l'adaptation. C'est la découverte d'expert du palier T3 (§1), pas un exploit : elle demande de lire le système. Aucun adversaire n'a deux paquets à la fois ; le noyau (Roucarnage, Alakazam, Rhinoféros chez Blue) ne change jamais, pour que la préparation reste possible.

---

## 6. Politique Méga

| Règle | Contenu |
|---|---|
| Introduction | ch. 8, R120 : Pierre Rochard remet le Méga-Anneau (`ITEM_MEGA_RING`, `ENGINE_CHANGES` §Méga) **et** combat en duo à côté de Red avec un Métang (sa Méga n'apparaît qu'au ch. 14) ; la scène montre une Méga-Évolution de démonstration (script, pas combat) |
| Avant | **aucune** Méga adverse avant le plafond 40 (contrôle automatique du générateur : `check_levels`) |
| Une par équipe | une seule Méga-Gemme par équipe désignée (contrôle automatique) ; la Méga arrive au **premier tour** de sortie (`AI_AUDIT` §6) : c'est le signe, il n'y a pas de surprise |
| Désignés pendant l'histoire | Amaryllis (Méga-Drattak, ch. 10 et 13), Arthur (Méga-Sharpedo, ch. 11), Peter (Méga-Léviator, ch. 10), Timmy (Méga-Gallame, ch. 14, canon ROSA), Blue (Méga-Roucarnage, ch. 14), Spectra (Méga-Branette, ch. 14), Pierre Rochard (Méga-Métalosse, ch. 14) |
| Sans Méga, par sens | Giovanni (« rien d'emprunté, même pas une pierre »), Marc (« la beauté sans artifice »), Glacia et Aragon au ch. 14 (deux Méga Dragon/Glace d'affilée tueraient la surprise ; ils l'ont en T5), Juan, Lévy et Tatia (leur gimmick est la Distorsion) |
| Postgame (T5) | Champions et Mission : Bastien (Charmina), Voltère (Élecsprint), Adriane (Camérupt), Alizée (Altaria), Lévy et Tatia (Gardevoir), Pierre (Brock) (Steelix), Olga (Flagadoss), Morgane (Alakazam), Damien (Absol), Glacia (Oniglali), Aragon (Drattak), Max (Camérupt) |
| Annonce | réplique d'avant-combat qui nomme la pierre (« Cette pierre vient du Peuple du Météore. ») ; pour le joueur, l'option Méga apparaît dans le menu de combat dès le Méga-Anneau |

---

## 7. Équipes par personnage

Lecture : **Identité** (ce que l'équipe raconte, `CHARACTER_AND_LORE` §1.6) · **Rencontres** (§4) · **Variantes** (espèce niveau, talent ou objet clé ; ensembles complets dans l'annexe) · **IA** (§3) · **Plan** de l'adversaire · **Menaces → réponses** du joueur (espèces et outils **disponibles à ce moment**, chapitre d'accès selon `encounter_roster_v1.csv` et `ENCOUNTERS_PLAN` §10.4) · **Victoire** (≥ 2 plans pour un combat d'histoire) · **Tests** (en plus du socle §13.3). Noms d'espèces en français dans le texte ; l'annexe utilise les noms anglais du moteur.

### 7.1 Rivaux

**C-02 Brice.** *Identité :* un recenseur combat avec ce qu'il a compté ; son starter bat le tien (il l'a choisi pour ça, canon) ; à partir du ch. 8, sa voie `BV` se lit dans l'équipe.
- *Rencontres :* #1 R103, #9 R110, #23 R119, #44 Atalanopolis (refusable, D111), postgame (finale du Tournoi, D130 a).
- *Variantes :* R103 : Goélise 4, starter 6. R110 : Goélise 20, Dynavolt 20, starter (2e stade) 23. R119 (×9) : Bekipan 34 (Crachin) + PROTÉGER {Tropius 33, Élecsprint 34 (Paratonnerre), Linéon 33} / ACCUEILLIR {Pharamp 34, Scarhino 34 (Cran), Moumouflon 33 (Toison Épaisse)} / COMPRENDRE {Absol 34, Relicanth 33, Arcanin de Hisui 34} + starter final 37. Ch. 12 (×9) : Bekipan 53 + PROTÉGER {Ludicolo (Glissade), Élecsprint, Libégon, Tropius} / ACCUEILLIR {Pharamp, Scarhino (Orbe Flamme), Moumouflon, Brutalibré (Délestage)} / COMPRENDRE {Absol, Relicanth (Fracass'Tête), Arcanin de Hisui, Morphéo (Météo)} + starter 55. T5 : mêmes équipes 75–78, starter avec talent caché (Turbo, Délestage).
- *IA :* AI-G1 (R103), AI-RV ensuite (il connaît tes espèces : son recensement), AI-E en T5.
- *Plan :* R119 et ch. 12 : **pluie** (Bekipan en tête, Crachin) ; PROTÉGER = pluie offensive (Glissade) ; ACCUEILLIR = résistance (Toison Épaisse, Cran) ; COMPRENDRE = surprises (Météo, Fracass'Tête sans recul).
- *Menaces → réponses :* pluie + starter Eau : Électrik (Dynavolt ch. 3, Zéblitz ch. 3, Magnéti ch. 4), Plante (Nénupiot ch. 0) ; Arcanin de Hisui (Feu/Roche) : Sol, Eau, Combat (Makuhita ch. 2) ; Scarhino avec Orbe Flamme : Vol (Hélédelle), Feu, Psy (Tarsal ch. 0 → Gardevoir).
- *Victoire :* (1) retirer Bekipan tôt et jouer hors pluie ; (2) jouer avec la pluie (Absorb Eau, Électrik) et battre le starter avec la couverture.
- *Tests :* les 33 variantes se lancent selon `STARTER_RED` × `BV` ; Bekipan est toujours en tête.

**C-03 Blue.** *Identité :* **un champion qui achète** : noyau canonique (Roucarnage, Alakazam, Rhinoféros) et satellites importés par Scott, choisis contre **toi**.
- *Rencontres :* #7 Tente de Scott (R, D027), #21 finale du Tournoi T2, #29 toit de Nénucrique (R, D084), #48 Route Victoire (O), postgame (Tournoi, D130 b).
- *Variantes :* tableau ci-dessous (paquets §5.3).

| Palier | Noyau | Paquet A | Paquet B | Paquet C | Flex | As |
|---|---|---|---|---|---|---|
| T1 (20) | Roucoups 20 | Caninos 20, Bleuseille 19 | Léviator 20, Rototaupe 19 | Noeunoeuf 19, Zébibron 20 | — | Kadabra 21 |
| T2 (32) | Roucarnage 32, Rhinocorne 31 | Arcanin 32, Bleuseille 31 | Léviator 32, Minotaupe 31 | Noadkoko 31, Zéblitz 32 | — | Alakazam 34 |
| T3 (40) | Roucarnage 41, Rhinoféros 40 (Évoluroc) | Arcanin 41, Corvaillus 40 | Léviator 41, Minotaupe 40 | Noadkoko 40, Zéblitz 41 | Scalpion 40 (import) | Alakazam 42 |
| T4 (56) | Rhinastoc 57 (Vulné-Assurance), Alakazam 57 | Arcanin 57 (Bandeau), Corvaillus 56 | Léviator 57, Minotaupe 56 (Ceinture Force) | Noadkoko 56, Zéblitz 57 (Lunettes) | Scalpereur 56 (SCOTT) **ou** Tauros 56 (LIBRE) | Méga-Roucarnage 58 |
| T5 (75) | idem, 75–76 | | | | idem | Méga-Roucarnage 78 |

- *IA :* AI-RV + `Risky` (T1–T3 : il tente le KO de justesse), AI-B (T4), AI-E (T5).
- *Plan :* le paquet frappe ta dominante ; Alakazam (Garde Magik) fait le ménage ; au T4, Méga-Roucarnage (Ouragan sans échec) arrive en dernier.
- *Menaces → réponses (T1, ch. 3) :* Kadabra : Ténèbres et Spectre (Medhyèna ch. 0, Farfuret ch. 1), Insecte ; Intimidation de Caninos/Léviator : attaquants spéciaux (Tarsal, Nénupiot) ; **la diversité** est la réponse (ENCOUNTERS §10.4). T4 : Méga-Roucarnage : Roche (Racaillou ch. 2 → Grolem), Électrik, Glace (Stalgamin, Blizzi ch. 9) ; Scalpereur : Combat (Makuhita, Charpenti ch. 4), Sol, Feu.
- *Victoire :* (1) équipe sans dominante (aucun paquet n'a d'avantage) ; (2) **dominante en façade** (Blue choisit un paquet qui ne voit pas tes vrais attaquants, §5.3).
- *Tests :* une équipe monotype Eau déclenche le paquet C ; une équipe à 2 Eau + 4 autres types différents déclenche C mais Zéblitz ne voit que deux cibles.

**C-11 Flora.** *Identité :* la brigade : des natifs disciplinés ; si elle bascule, les arrivants de Vergazon.
- *Rencontres :* #2 Bois Clémenti (R, D008), #19 Vergazon (D064 a), postgame (T5 FIDÈLE / BASCULÉE).
- *Variantes :* T1 : Zigzaton 11, Medhyèna 12, Nirondelle 14. T2 : Grahyèna 31 (Intimidation), Chartor 31, Mangriff 32, Hélédelle 33 (Cran). T5 FIDÈLE : Grahyèna, Chartor (Sécheresse), Chapignon (Spore), Mangriff (Orbe Toxique), Élecsprint, Hélédelle (Orbe Flamme) ; BASCULÉE : Haydaim (Herbivore), Manternel (Toile Gluante) à la place de Chartor et Chapignon.
- *IA :* AI-G1 (T1), AI-G2 (T2), AI-E (T5). *Plan :* Intimidation puis Hélédelle Cran (au T5 : statut auto-infligé, Façade).
- *Menaces → réponses (ch. 7) :* Hélédelle : Roche (Racaillou), Électrik (Dynavolt), Glace ; Mangriff : Combat (Makuhita, Charpenti), Intimidation adverse ; Chartor : Eau, Sol.
- *Victoire :* (1) neutraliser Hélédelle (Électrik ou Roche) ; (2) Brûlure/paralysie interdite contre Cran : jouer KO direct.
- *Tests :* D008 refus → `FLAG_CF_REFUS_FLORA1` (nom C), aucune EXP ; T5 BASCULÉE seulement si le flag de bascule (D122) est posé.

**C-33 Timmy.** *Identité :* un enfant et son ami condamné ; il veut savoir s'il « peut ».
- *Rencontres :* #47 Route Victoire (R, D124), postgame (Zone de Combat si D124 b).
- *Variantes :* T4 : Roserade 56, Altaria 57, Magnézone 57, **Feuiloutan 56 (SAUVÉ) ou Delcatty 56 (PERDU)**, Méga-Gallame 58 (canon ROSA). T5 : idem 75–78, + Gardevoir (PERDU).
- *IA :* AI-G2 (il apprend), AI-E (T5). *Plan :* Méga-Gallame (Coupant) en dernier ; Magnézone piège tes Acier (Magnépiège).
- *Menaces → réponses :* Méga-Gallame : Vol, Spectre, Fée (Mélofée, Fluvetin) ; Magnézone : Sol, Feu, Combat.
- *Victoire :* (1) garder un Spectre ou un Vol pour l'As ; (2) frapper Altaria (Glace, Fée) avant Cotogarde.
- *Tests :* SAUVÉ si `TIMMY_SAUVE` (D038/D064) ; sinon PERDU.

### 7.2 Champions de Hoenn (badges, puis T5)

**C-37 Roxanne** (badge 1, plafond 14). *Identité :* la pédagogue : « un seul coup ne suffit pas ». Racaillou 12, Galekid 13 (Fermeté), Tarinor 15 (Fermeté, Baie Oran). AI-G1 + `Conservative`. *Plan :* Fermeté encaisse le coup unique, Tomberoche ralentit. *Menaces → réponses :* Fermeté : attaques multiples, statut, deux coups (Nénupiot ch. 0, Férosinge ch. 0, Osselait ch. 0, Snubbull ch. 0) ; Tomberoche : Pokémon rapide ou le plus lourd en tête (D2). *Victoire :* (1) Plante/Eau en deux coups ; (2) Combat (Férosinge) en série. *T5 :* Grolem (Baie Chérim), Vacilys, Armaldo, Galeking (Vulné-Assurance), Solaroc (Distorsion), Tarinorme (As). Natifs seulement (Rempart prudent).

**C-38 Bastien** (badge 2, plafond 18). *Identité :* il défend les arrivants : deux Kantoniens (Férosinge, Machoc) et son Makuhita. Férosinge 17, Machoc 17 (Cran), Makuhita 19 (Isograisse, Gonflette). AI-G1 + `Risky`. *Plan :* Gonflette au premier tour sûr. *Menaces → réponses :* Gonflette : Vol (Nirondelle, Roucool ch. 0), Psy (Tarsal ch. 0, Abra ch. 2), Rugissement/Grondement (baisse d'Attaque), Brûlure (Ponyta ch. 1). *Victoire :* (1) Psy/Vol avant le boost ; (2) faire baisser l'Attaque puis user. *T5 :* Kapoera, Tartard, Lucario, Bétochef, Hariyama, Méga-Charmina.

**C-39 Voltère** (badge 3, plafond 22). *Identité :* le bâtisseur qui fait travailler les arrivants : l'Emolga « attrapé dans un transformateur ». Voltorbe 21 (Destruction, `Will Suicide`), Emolga 21 (Frotte-Frimousse : paralysie), Magnéton 22 (Fermeté), Élecsprint 23 (**Paratonnerre**). AI-G2. *Plan :* paralyser, puis Élecsprint absorbe ton Électrik ; Voltorbe explose quand il va tomber (réplique : « Ça va faire boum ! »). *Menaces → réponses :* Emolga (immunisé Sol) : Roche (Racaillou ch. 2), Glace (Frissonille ch. 1, Polarhume ch. 4) ; Paratonnerre : ne pas envoyer d'Électrik ; Sol : Osselait (ch. 0), Taupiqueur (ch. 0), Grolem (ch. 2). *Victoire :* (1) Sol pour 3 sur 4 + Roche/Glace pour Emolga ; (2) Total Soin et vitesse. *T5 :* Électrode (écrans), Emolga, Motisma Chaleur (Mouchoir), Magnézone, Élekable, Méga-Élecsprint.

**C-40 Adriane** (badge 4, plafond 29). *Identité :* sauver les sources ; le feu de Hoenn. Chartor 29 (**Sécheresse**, en tête), Chamallot 28 (Simple), Limagma 28, Camérupt 31. AI-G2. *Plan :* soleil 5 tours, Feu ×1,5. *Menaces → réponses :* soleil : Eau affaiblie (×0,5) → Sol et Roche (Racaillou, Galekid ch. 2, Barloche ch. 4) ; changer la météo (Bekipan Crachin : Goélise ch. 0 évolue au 25) ; attendre 5 tours (Abri). *Victoire :* (1) KO de Chartor avant tout ; (2) Crachin/Danse Pluie. *T5 :* Chartor, Feunard, Monthracite, Pyrax, Flambusard, Méga-Camérupt.

**C-32 Norman** (badge 5, plafond 33). *Identité :* l'ordre qui tient un tour sur deux. Vigoroth 32 (Encore), Linéon 32 (Ventre Plein **annoncé** : « Tu as le temps d'un tour. »), Brouhabam 32 (**Querelleur** : ses attaques Normal touchent les Spectres), Monaflèmit 35 (**Absentéisme**). AI-G2. *Plan :* Monaflèmit frappe un tour sur deux ; Encore piège tes boosts. *Menaces → réponses :* Monaflèmit : Abri/Détection le tour où il frappe, Brûlure, Combat (Makuhita, Charpenti) ; Querelleur : ne pas compter sur un Spectre seul. *Victoire :* (1) rythme : frapper pendant le tour de paresse ; (2) Combat ×2. *T5 :* Kecleon (Protéen), Linéon, Brouhabam (Lunettes), Mangriff, Hélédelle, Monaflèmit (Bandeau).

**C-41 Alizée** (badge 6, plafond 37). *Identité :* la gardienne de la canopée : natifs volants. Airmure 36 (**Picots**, Cyclone), Bekipan 35, Tropius 36, Hélédelle 36, Altaria 39 (Danse Draco). AI-G2. *Plan :* Picots + Cyclone usent l'équipe ; Altaria se booste en dernier. *Préparation :* Tentacool (pêche R103, ch. 2) apprend **Tour Rapide** ; Grosses Bottes placées à l'Institut Météo (demande C/D). *Menaces → réponses :* Picots : Tour Rapide, Tentacool/Minotaupe ; Altaria : Glace (Polarhume ch. 4, Sorbébé ch. 4), Fée (Snubbull, Fluvetin) ; Vol : Électrik (Zéblitz, Statitik ch. 4). *Victoire :* (1) nettoyer les Picots et jouer l'Électrik ; (2) ignorer les Picots et KO vite (équipe offensive). *T5 :* Airmure (Casque Brut), Xatu (Miroir Magik), Bekipan (Crachin), Tropius, Hélédelle, Méga-Altaria.

**C-42 Lévy et Tatia** (badge 7, double, plafond 44). *Identité :* télépathes qui entendent la « voix » du relais. Solaroc 44 + Séléroc 44 (**Distorsion**), Kaorine 45, Farigiraf 46 (Queue Armure : bloque la priorité). AI-G2 + `Omniscient` + `Double Ace`. *Plan :* Distorsion au tour 1 ; les lents frappent d'abord 5 tours. *Menaces → réponses :* Distorsion : Provoc (Farfuret ch. 1), Abri pour gâcher 5 tours, Pokémon lents (Galekid, Tartard), KO d'un poseur (Ténèbres : Zorua ch. 3, Chacripan ch. 4 ; Insecte : Statitik ch. 4). Omniscience : annoncée (« On t'entend penser. ») ; contre-jeu : équipe **honnête**, pas de piège. *Victoire :* (1) Provoc sur les poseurs ; (2) jouer lent sous Distorsion. *T5 :* Wimessir (Créa-Psy, Par Ici), Carmadura (Vaste Pouvoir), Solaroc, Séléroc, Farigiraf, Méga-Gardevoir.

**C-36 Juan** (badge 8, plafond 51). *Identité :* l'arbitre élégant : la danse passe de l'un à l'autre. Mustéflott 50 (Gonflette + **Relais**), Barbicha 50 (Danse Draco), Kaimorse 51, Colhomard 51 (Danse Lames), Hyporoi 53. AI-G2 + `Conservative` + `Prefer Baton Pass` + `Force Setup First Turn`. *Plan :* chaque Pokémon se booste ; Mustéflott passe ses boosts. *Menaces → réponses :* chaînes de boosts : **Buée Noire** (Tentacool, Smogo), **Hurlement/Cyclone** (Caninos ch. 1, Airmure ch. 5), **Inconscient** (Maraiste : Safari), Provoc, Encore (Vigoroth), coups critiques. *Victoire :* (1) phazer ou Buée Noire ; (2) KO avant le deuxième boost (Électrik, Plante). *T5 :* Mustéflott (Ceinture Force), Lanturn, Barbicha, Kaimorse, Colhomard, Hyporoi.

### 7.3 Mission Indigo et Kanto (Défis refusables, sauf mention)

**C-12 Pierre (Brock)** (plafond 18). *Identité :* l'éleveur de roche, défensif ; ceux que Red a sauvés aux mines se battent à ses côtés. SANS : Racaillou 16, Simularbre 16 (Johto), Onix 19 (Fermeté). AVEC : + **Charbi 16** (l'arrivant des mines, Galar). AI-G2. *Plan :* Fermeté et Étreinte usent. *Menaces → réponses :* Onix : Eau/Plante (Nénupiot, Marill ch. 1) ; Charbi (Roche/Feu au T5) : Eau, Sol. *Victoire :* (1) Eau/Plante ; (2) Combat (Férosinge). *T5 :* Grolem, Kabutops, Amonistar (Exuviation, Herbe Blanche), Simularbre, Strassie (SANS) ou Monthracite (AVEC), Méga-Steelix. Fossiles Nautile/Dôme : ceux qu'il échange au ch. 3 (`ENCOUNTERS_PLAN` §10.2).

**C-21 Aldo** (plafond 20 ; 49 ; T5). *Identité :* le corps et l'honnêteté ; **aucun arrivant** : ses Pokémon sont venus avec lui par bateau. T1 : Onix 18, Tygnon 19, Kicklee 19, Machopeur 21. T3 (escorte de Fondmer ou finale du Tournoi T3) : Kapoera, Kicklee (Téméraire), Tygnon (Veste de Combat), Steelix, Mackogneur 51. T5 : + Courrousinge (son Colossinge, évolué). AI-G2. *Plan :* coups physiques directs, aucune ruse. *Menaces → réponses :* Psy (Tarsal, Abra), Vol, Fée ; Intimidation (Medhyèna) ; T3 Mackogneur Cran : ne pas le brûler. *Victoire :* (1) Psy rapide ; (2) murs physiques (Galekid, Airmure).

**C-14 Major Bob** (plafond 22, double). *Identité :* le logisticien militaire : un **exercice**, pas un combat. Voltorbe 21, Magnéti 21, Élektek 21, Raichu 23 (Bluff, Toile Élek). Double, AI-G2. *Intention :* **premier double, sans enjeu** (refusable, aucune conséquence lourde : D043). *Menaces → réponses :* Bluff + Toile Élek (vitesse) : Sol (Osselait, Taupiqueur), Abri ; en double, attaques ciblées plutôt que de zone. *Victoire :* (1) concentrer deux attaques sur Raichu ; (2) Sol + Vol en duo. *T5 :* Électrode (écrans), Voltali, Magnézone, Élekable, Pharamp, Raichu (As).

**C-15 Erika** (plafond 32). *Identité :* la parfumeuse d'affaires : MARCHÉ aligne la fleur du contrat (Chlorobule → **Fragilady**, Unys) ; INTÉGRATION aligne les plantes des vergers (Rosélia). Saquedeneu 31, Empiflor 32 (Poudre Dodo, une seule dormeuse), Rafflesia 32, Fragilady 34 (Papillodanse) **ou** Rosélia 32 + Rafflesia 34. AI-G2 + `Prefer Status Moves`. *Plan :* statut d'abord (Para-Spore, Poudre Dodo sous clause de sommeil), puis Papillodanse. *Menaces → réponses :* Feu (Ponyta, Caninos ch. 1, Chamallot ch. 5), Vol, Poison ; Lilliput interdit ; Baie Prine/Total Soin. *Victoire :* (1) Feu/Vol rapide ; (2) Insecte/Poison résistants au statut. *T5 :* Bouldeneu (Régé-Force), Empiflor, Joliflor, Cotovol, Fragilady (MARCHÉ) ou Roserade (INT), Rafflesia (As).

**C-16 Koga** (plafond 37 ; 47 ; T5). *Identité :* l'espion : l'attrition et les pièges ; démasqué, il joue « propre ». Piège (ch. 8, si Red se bat pour Hoopa) : Foretress 36 (Pics Toxik), Migalos 36 (Fil Toxique), Nostenfer 37, Smogogo 39. Défi « sans rancune » (D081) : Nostenfer, Aéromite, Moufflair, Smogogo 38 (aucun piège). Revanche ch. 10 (§14 C2) : PROPRE {Nostenfer, Drascore, Coatox, Grotadmorv, Smogogo} / PIÈGES {Foretress (Picots, Pics Toxik), Migalos (Toile Gluante), Nostenfer, Drascore, Smogogo}. AI-G2 + `Prefer Status Moves` (sauf PROPRE). *Menaces → réponses :* Pics Toxik : Poison au sol (Tentacool, qui les **absorbe**), Acier (Galekid), Tour Rapide ; Toxik : Total Soin, Baie Pêcha, Rune Protect ; Smogogo (Lévitation) : Psy, Feu. *Victoire :* (1) Tentacool absorbe, Psy frappe ; (2) offensive rapide avant l'usure.

**C-17 Jeannine** (finale du Tournoi T1, plafond 20 ; T5). *Identité :* la fille qui imite trop bien. Nosferapti 19, Mimitoss 19, Mimigal 19 (Johto), Smogo 21. *Menaces → réponses :* Psy (Tarsal, Abra), Sol, Vol. *T5 :* Prédastérie, Aéromite, Migalos, Malamandre, Smogogo, Nostenfer.

**C-18 Morgane** (plafond 44 ; T5). *Identité :* elle **prévoit** : écrans, Prescience. M. Mime 43 (Protection, Mur Lumière), Archéodong 44 (Prescience), Tapatoès 44 (Paldea : Opportuniste), Alakazam 46. AI-G2 + **`Omniscient`** (annoncé : « Je sais ce que tu vas faire. Toi aussi, d'ailleurs. »). *Plan :* écrans, Prescience à retardement, Plénitude. *Menaces → réponses :* écrans : Casse-Brique (CT), attendre 5 tours, Ténèbres (Zorua, Chacripan, Scalpion ch. 6) ; Prescience : changer de Pokémon au bon tour (le message l'annonce). *Victoire :* (1) Ténèbres physiques ; (2) Provoc sur M. Mime. *T5 :* M. Mime, Archéodong (Distorsion), Tapatoès, Forgelina (Miroir Magik), Aéromite, Méga-Alakazam.

**C-19 Auguste** (plafond 32 ; T5). *Identité :* feu de laboratoire, chaleur contenue ; ch. 6 il porte encore le **Camérupt prêté par Magma**. Galopa 31, Magmar 31, Camérupt 30, Arcanin 33 (Intimidation). AI-G2. *Menaces → réponses :* Eau (Marill, Wailmer ch. 2, Barloche ch. 4), Roche, Sol. *T5 :* Galopa, Maganon, Feunard (Sécheresse), Pyroli, **Camérupt (MAGMA) ou Ossatueur d'Alola (FUJI : le deuil de Lavanville)**, Arcanin.

**C-20 Olga** : voir fiche §8.13 (combat à forte identité ; équipe optimale de Glace).

**C-13 Ondine** (plafond 44 ; 49 ; T5). *Identité :* offensive Eau ; elle aligne les bancs qu'elle a **libérés**. Défi (ch. 9–10) : Akwakwak 43 (Ciel Gris), Maraiste 44 (**Inconscient**), Démanta 44 (le banc libéré), Staross 46 (Analyste). Camp Aqua (ch. 11, D104) : + Denticrisse 49 (Alola). AI-G2 (Défi), AI-V (camp Aqua). *Menaces → réponses :* Staross : Ténèbres, Spectre, Électrik ; Maraiste (Inconscient : tes boosts ne comptent pas) : Plante (Nénupiot → Ludicolo), attaques fortes sans boost. *T5 :* AQUA {Akwakwak (Lunettes), Maraiste, Démanta, Denticrisse, Superdofin, Staross} / MISSION {Akwakwak, Maraiste, Aquali, Krabboss, Tentacruel, Staross}.

**C-22 Agatha** (plafond 40 / 44 ; T5). *Identité :* le deuil qui mord. PROFANÉ (combat d'histoire, rite profané par Lance (Rocket)) : Arbok 39, Nostenfer 40, Magirêve 40, **Spiritomb 41** (les âmes enfermées), Ectoplasma 42 ; AI-B (colère). RITE (Défi, elle transmet) : Arbok, **Grodrive 43** (elle emporte les âmes), Magirêve, Ectoplasma 46 ; AI-G2. *Menaces → réponses :* Spectre : Ténèbres (Medhyèna, Zorua **la nuit**, Chacripan), Spectre (Polichombr ch. 9) ; **la nuit est la clé** (ENCOUNTERS §10.4, E-TOD) ; Feu Follet : Pokémon spéciaux. *T5 :* Arbok, Nostenfer, Grodrive, Spiritomb, Magirêve (Lunettes Choix), Ectoplasma (sans Méga : Marque Ombre interdit, piège sans issue).

**C-07 Peter** (plafond 47 ; T5). *Identité :* l'autorité de Kanto, vieille et lourde ; s'il a respecté le Site Météore (D050), le Peuple du Météore lui a confié un **Drattak**. Ptéra 46 (Ceinture Force, Piège de Roc), Dracaufeu 46, **paquet E-ADAPT 46** (A : Pondralugon, Acier/Dragon ; B : Carchacrok ; C : Pomdorochi, Plante/Dragon), **Drattak 47 (DRATTAK) ou Dracolosse 47 (KANTO)**, Méga-Léviator 47 (Brise Moule), Dracolosse 48 (Multiécaille, Vulné-Assurance). AI-B. *Plan :* Piège de Roc, Danse Draco, la Méga au premier tour. *Menaces → réponses (ch. 10) :* Dragons : Glace (Blizzi ch. 9, Polarhume ch. 4, Sorbébé ch. 4, Mammochon via Marcacrin ch. 0), Fée (Snubbull, Fluvetin, Flabébé ch. 1), Dragon (Safari ch. 9) ; Multiécaille : casser à pleine vie avec deux coups (Picots, Piège de Roc, Éclats Glace) ; Vulné-Assurance : **ne pas** taper Dracolosse en super efficace faible ; un seul gros coup. *Victoire :* (1) Glace + Fée ; (2) contrôle de vitesse et KO avant Danse Draco. *T5 :* même structure, 75–78.

**C-06 Giovanni** : voir fiche §8.8 (incognito ch. 6) et §8.21 (dernier duel, T5).

### 7.4 Antagonistes

**C-05 Amaryllis** : fiches §8.6 (ch. 5), §8.17 (ch. 10), §8.19 (ch. 13). Aster = son Chuchmur (CANON ROSA) : Ramboum au ch. 5, Brouhabam ensuite. Équipe canonique ROSA reprise au ch. 10 : Rexillius, Bruyverne, Muplodocus, Brouhabam (Aster), Altaria, Méga-Drattak.

**C-28 Ariane** (plafond 47 ; 53). *Identité :* ce qu'on achète aux ruinés. RK BAS : Arbok, Rafflesia, Grotadmorv, Corboss (As). RK HAUT : + **Chacripan** (Léopardus) et **Grimalin** (Angoliath, Farceur) « rachetés ». Climax RK BAS : + Coatox. AI-V (ch. 10) / AI-B (ch. 13) + `Prefer Status Moves`. *Plan :* Intimidation, Regard Médusant, écrans de Farceur. *Menaces → réponses :* Poison : Sol, Psy ; Angoliath (Fée/Ténèbres) : Acier, Poison ; Corboss (Impudence) : Électrik, Roche, Glace. *Victoire :* (1) Sol + Électrik ; (2) Casse-Brique/Anti-Brume contre les écrans.

**C-29 Lambda** (plafond 47). *Identité :* l'imposture lisible. Zoroark 47 (**Illusion** : il apparaît en Persian), Smogogo 46, **Métamorph 46 (Imposteur)**, Persian 48. AI-V + `Will Suicide`. *Tell :* « Persian » utilise Explosion Nocturne (Ténèbres) ; Giovanni l'a annoncé (« Mon Persian ne connaît pas ça. »). *Menaces → réponses :* Imposteur copie ta tête : mener avec un Pokémon faible ou un Pokémon qui gagne le miroir (Combat contre Zoroark) ; Fée/Combat/Insecte contre Zoroark. *Victoire :* (1) lire l'Illusion (l'efficacité affichée trahit le type) ; (2) tête « sacrifiable » contre Métamorph.

**C-30 Lance (Rocket)** (plafond 25 ; 40). *Identité :* les primes : il aligne ce qu'il chasse. Raid (ch. 4, série sans soin) : Goupilou 23, Nosferalto 24, Smogogo 26. Mont Mémoria (ch. 9) : Roublenard 39, Rhinolove 39 (Simple), Moufflair 40, Nostenfer 40, Smogogo 42. AI-V + `Risky`. *Menaces → réponses :* raid : Psy (Abra, Tarsal), Sol (Osselait, Taupiqueur), Toxik : Total Soin ; ch. 9 : Psy, Sol, Électrik.

**C-31 Amos** (plafond 53, si `RK` haut). Nostenfer, Smogogo, Scalpion (Évoluroc), Démolosse 55. AI-V. *Menaces → réponses :* Combat, Eau, Sol.

**C-47 Max** (plafond 29 ; T5). *Identité :* la gestion par la force tellurique ; **Frison** = le troupeau qu'il a déplacé. Grahyèna 28, Escroco 27 (Impudence), Frison 28 (Herbivore), Camérupt 31. AI-V. *Menaces → réponses :* Eau (Marill, Wailmer), Combat contre Frison (Makuhita ch. 2), Plante absorbée par Herbivore : ne pas l'utiliser contre Frison. *T5 :* Chartor (Sécheresse), Grahyèna, Nostenfer, Crocorible, Frison, Méga-Camérupt.

**C-49 Kelvin, C-50 Courtney** (plafond 29). Kelvin : Nosferalto 27, Chamallot 27, Grahyèna 29. Courtney : Smogo 27, Grahyèna 27, Camérupt 29. AI-V. Couches de faction ; aucune variante.

**C-48 Arthur** (plafond 49 ; T5). *Identité :* la mer libre et vorace. COUPE : Grahyèna, Nostenfer, **Oyacata** (Inconscient, Paldea), **Démanta**, Grotadmorv + Méga-Sharpedo 51 (Turbo). NÉGOCIE : Grahyèna, Nostenfer, Wailord, Colhomard, Grotadmorv + Méga-Sharpedo. AI-V. *Plan :* Méga-Sharpedo (talent Méga : Mâchoire Forte, Mâchouille et Crocs Givre ×1,5) frappe fort et vite dès son entrée. *Menaces → réponses :* Sharpedo est fragile en défense : priorité (Vive-Attaque, Pisto-Poing), Électrik, Combat, Fée (Fluvetin) ; Oyacata (Inconscient) : Plante/Électrik spéciales. *Victoire :* (1) KO de Sharpedo à son entrée (priorité ou Pokémon plus rapide) ; (2) mur physique + Feu Follet.

**C-52 Sarah** (plafond 35 ; 49). Institut : Wailmer 33, Grahyèna 34, Sharpedo 36. Fondmer (si elle reste) : Prédastérie (Alola), Grahyèna, Wailord, Sharpedo 50. AI-V. *Menaces → réponses :* Électrik (Dynavolt, Zéblitz), Plante.

**C-51 Matthieu** (plafond 40, branche D082 b). Grahyèna, Nostenfer, Wailord, Sharpedo 42. AI-V.

### 7.5 Ligue (ch. 14) et Maître
Conseil 4 : chaque membre = **une thématique + une mécanique** (`STRATEGY_RESEARCH` §7, étape 11). Soin entre deux combats : non (Ligue vanilla) ; objets du joueur : oui.

| Membre | Thème | Mécanique enseignée | Équipe T4 (56–58) | Réponses (disponibles avant le ch. 14) |
|---|---|---|---|---|
| **Damien** | Ténèbres, le marché | **Farceur** et Encore (Léopardus), Coup Bas | Léopardus, Roublenard (Embusqué), Grahyèna, Cacturne (Picots), Tengalice, Absol | Fée, Combat, Insecte ; Vitesse > Coup Bas : attaques de statut au bon tour |
| **Spectra** | Spectre, le Mont Mémoria | **Feu Follet** et attrition ; Méga-Branette (Farceur) | Ténéfix (Farceur), Grodrive, Mimiqui (Fantômasque), Magirêve, Noctunoir, Méga-Branette | Ténèbres, Spectre, attaquants spéciaux (immunes à la brûlure côté dégâts) |
| **Glacia** | Glace, l'arrivante | **boosts** : Papillodanse (Beldeneige), Cognobidon (Balbalèze), Danse Draco (Glaivodo) | Oniglali (Ceinture Force, Picots), Kaimorse, Séracrawl (Fermeté, Big Splash), Balbalèze, Beldeneige (Écailles Glacées), Glaivodo | Feu, Combat, Acier, Roche ; Buée Noire, Hurlement contre les boosts |
| **Aragon** | Dragon, le vieux marin | **Intimidation** et murs de Dragon ; Dragon de mer (Kravarech) | Altaria, Libégon (Mouchoir), Kravarech (Adaptabilité), Tranchodon, Carchacrok, Drattak | Glace, Fée, Dragon ; Éclats Glace contre Drattak après Danse Draco |
| **Maître Pierre Rochard** | Acier et pierres de Hoenn ; fossiles de Devon | Méga-Métalosse ; Picots + Piège de Roc | Airmure, Kaorine, Galeking, Vacilys, **Armaldo (PROTÈGE) / Tarinorme (ACCUSE)**, Méga-Métalosse 59 | Feu, Sol, Eau, Combat ; Tour Rapide |
| **Maître Marc** | Eau, la beauté qui dure | **pluie** (Bekipan) + Glissade ; Milobellus (Écaille Spéciale) ; **aucune Méga** | Bekipan, Tentacruel, Ludicolo, Léviator, Oratoria, Milobellus 59 | Électrik, Plante ; changer la météo ; Provoc contre Soin |

---

## 8. Fiches combat majeur (`GM_METHOD` §5.4)

Équipes en mode Normal (lignes IV omises : IV du palier, §2.2 ; EV absents en T1–T3). Les autres variantes sont dans l'annexe. « Fun » = checklist « présence du fun » (`GM_METHOD` §4.10) : préparation · plusieurs voies · environnement · règles claires · plusieurs capacités · skill · plusieurs issues · anti-farm · échec = nouvelle tentative.

### 8.1 Roxanne — badge 1 (T1, plafond 14, Mérouville)

`T-ROXANNE-T1`
```
=== TRAINER_ROXANNE_1 ===
Name: ROXANNE
Class: Leader
Pic: Leader Roxanne
Gender: Female
Music: Female
Items: Potion
Battle Type: Singles
AI: Basic Trainer / Sequence Switching / Ace Pokemon / Conservative

Geodude
Level: 12
Ability: Sturdy
Impish Nature
- Tackle
- Defense Curl
- Rock Throw
- Rock Tomb

Aron
Level: 13
Ability: Sturdy
Impish Nature
- Tackle
- Harden
- Metal Claw
- Headbutt

Nosepass @ Oran Berry
Level: 15
Ability: Sturdy
Bold Nature
- Rock Tomb
- Thunder Wave
- Harden
- Tackle
```
**Intention :** premier examen : le joueur découvre que le type ne suffit pas quand l'adversaire **encaisse** (Fermeté). **Pattern :** types/STAB + « deux coups valent mieux qu'un ».
**Préparation :** élèves de l'École des Dresseurs (2 dresseurs à Racaillou et Tarinor de route, `Sequence Switching`) ; options Nénupiot (R102), Férosinge (R103), Osselait, Marcacrin, Snubbull (ch. 0) (`ENCOUNTERS_PLAN` §10.4). Potion de l'École.
**Rôles :** Racaillou (mur lent), Galekid (Fermeté, Acier : piège pour les Combat faibles), Tarinor (As, Fermeté + Cage-Éclair, Baie Oran).
**IA :** AI-G1 + `Conservative` : ordre fixe, l'As en dernier, aucune prise de risque.
**Gimmick :** Fermeté (annoncée par Roxanne : « Une roche ne tombe jamais d'un seul coup. ») et affichée par le moteur à l'activation.
**Dominante prévisible :** « mon starter Eau/Plante tape fort » → contre-pression : Fermeté laisse 1 PV, Tomberoche ralentit ; il faut un deuxième coup, une attaque multiple ou un statut.
**Plans de victoire :** (1) Plante/Eau + un second attaquant pour finir ; (2) Combat (Férosinge) qui enchaîne, Galekid compris ; (3) Snubbull (Intimidation) + usure.
**Hasard :** faible (aucune attaque à précision < 90, aucun critique augmenté).
**Fun :** prép O · plusieurs voies O · environnement N (combat-tutoriel déclaré) · règles claires O · plusieurs capacités O · skill O · plusieurs issues O · anti-farm O · échec = nouvelle tentative O.
**Tests :** une équipe « starter seul » échoue au moins une fois sur Tarinor ; une équipe à 2 types gagne en ≤ 2 essais.

### 8.2 Bastien — badge 2 (T1, plafond 18, Myokara)

`T-BASTIEN-T1`
```
=== TRAINER_BRAWLY_1 ===
Name: BASTIEN
Class: Leader
Pic: Leader Brawly
Gender: Male
Music: Male
Items: Super Potion
Battle Type: Singles
AI: Basic Trainer / Sequence Switching / Ace Pokemon / Risky

Mankey
Level: 17
Ability: Vital Spirit
Jolly Nature
- Karate Chop
- Fury Swipes
- Low Kick
- Leer

Machop
Level: 17
Ability: Guts
Adamant Nature
- Karate Chop
- Low Kick
- Leer
- Rock Smash

Makuhita @ Sitrus Berry
Level: 19
Ability: Thick Fat
Adamant Nature
- Arm Thrust
- Bulk Up
- Fake Out
- Vital Throw
```
**Intention :** punir le **setup** (Gonflette) avant qu'il punisse. **Pattern :** statut et baisses de stats (`STRATEGY_RESEARCH` §7, étape 3).
**Préparation :** dresseurs de la salle de Myokara (un Makuhita qui se booste, un Machoc à Cran) ; Psy (Tarsal ch. 0, Abra Grotte Granite ch. 2), Vol (Nirondelle, Goélise), Ponyta (Feu, brûlure ch. 1).
**Rôles :** Férosinge (vitesse), Machoc (Cran : ne pas l'empoisonner), Makuhita (As : Isograisse, Gonflette, Bluff, Baie Sitrus).
**IA :** AI-G1 + `Risky` (le surfeur tente le gros coup : fenêtre d'erreur pour le joueur).
**Gimmick :** Gonflette au premier tour sûr (le setup « quand c'est sûr » de `Check Viability`) ; Bastien l'annonce : « La vague monte avant de tomber ! »
**Dominante prévisible :** statut sur tout → contre-pression : Cran (Machoc).
**Plans de victoire :** (1) Psy/Vol avant le boost ; (2) Rugissement/Grimace + mur ; (3) brûlure sur Makuhita (pas sur Machoc).
**Hasard :** faible (Bluff = premier tour seulement, prévisible).
**Fun :** O partout sauf environnement N (déclaré).
**Tests :** le joueur qui empoisonne Machoc voit Cran s'activer (message moteur) ; Makuhita se booste au tour 1 si le joueur ne menace pas de KO.

### 8.3 Blue 1 — Tente de Scott (T1, plafond 20, Poivressel ; refusable D027)

`T-BLUE-T1A`
```
=== TRAINER_ROSE_3 ===
Name: BLUE
Class: Rival Late Frlg
Pic: Rival Late Frlg
Gender: Male
Music: Male
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Ace Pokemon / Know Opponent Party / Assumptions / Risky

Pidgeotto
Level: 20
Ability: Keen Eye
Jolly Nature
- Wing Attack
- Quick Attack
- Feather Dance
- Twister

Growlithe
Level: 20
Ability: Intimidate
Adamant Nature
- Bite
- Ember
- Flame Wheel
- Roar

Corvisquire
Level: 19
Ability: Keen Eye
Jolly Nature
- Pluck
- Fury Attack
- Power Trip
- Scary Face

Kadabra @ Twisted Spoon
Level: 21
Ability: Synchronize
Timid Nature
- Psybeam
- Confusion
- Disable
- Reflect
```
**Intention :** le rival **lit ton équipe**. Première rencontre avec l'adaptation : la diversité bat la spécialisation. **Pattern :** équipe équilibrée, choix de tête (D2).
**Préparation :** Blue parade à la Tente avant le combat (« Montre-moi ce que t'as. ») et commente ta dominante en une boîte ; options variées (Férosinge, Pandespiègle R115, Caninos, Makuhita ; ENCOUNTERS §10.4). Le refus est une décision (D027).
**Équipe affichée :** paquet A (dominante Plante/Insecte/Glace/Fée/Psy/Spectre/Dragon) ; B et C dans l'annexe (`T-BLUE-T1B`, `T-BLUE-T1C`).
**Rôles :** Roucoups (vitesse, Danse Plumes), Caninos (Intimidation), Bleuseille (Vol, Assurance), Kadabra (As, frappe spéciale fragile).
**IA :** AI-RV + `Risky` : il connaît tes espèces (lore : il t'observe) et tente le KO limite.
**Gimmick :** E-ADAPT (§5.3), annoncé.
**Dominante prévisible :** monotype → contre-pression : le paquet. Exploitation d'expert (voulue) : dominante en façade.
**Plans de victoire :** (1) équipe sans dominante ; (2) Ténèbres/Spectre/Insecte contre Kadabra et mur physique contre Intimidation ; (3) refuser (et payer en `BL`).
**Hasard :** faible ; `Risky` crée des KO ratés **en faveur** du joueur.
**Fun :** O partout (l'environnement = la Tente : public, réplique de Scott ; le paquet change le défi).
**Tests :** dominante Eau → `T-BLUE-T1C` ; dominante Feu → `T-BLUE-T1B` ; égalité → type 1 de la tête ; refus → flag C, jalon 22 posé quand même à la sortie de Poivressel.

### 8.4 Voltère — badge 3 (T1, plafond 22, Lavandia)

`T-VOLTERE-T1`
```
=== TRAINER_WATTSON_1 ===
Name: VOLTERE
Class: Leader
Pic: Leader Wattson
Gender: Male
Music: Male
Items: Super Potion / Super Potion
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Ace Pokemon / HP Aware / Assume Stab / Will Suicide

Voltorb
Level: 21
Ability: Static
Timid Nature
- Spark
- Sonic Boom
- Self-Destruct
- Charge

Emolga
Level: 21
Ability: Static
Jolly Nature
- Nuzzle
- Acrobatics
- Quick Attack
- Shock Wave

Magneton
Level: 22
Ability: Sturdy
Modest Nature
- Spark
- Sonic Boom
- Thunder Wave
- Metal Sound

Manectric @ Sitrus Berry
Level: 23
Ability: Lightning Rod
Timid Nature
- Shock Wave
- Bite
- Howl
- Quick Attack
```
**Intention :** l'Électrik se combat avec le **Sol**, mais Voltère a prévu un Pokémon que le Sol ne touche pas. **Pattern :** immunités (Paratonnerre, Vol), paralysie.
**Préparation :** la centrale (Nouvelle Lavandia : Magnéti, Statitik, Anchwatt ch. 4) ; Sol : Osselait, Taupiqueur (ch. 0), Grolem via Racaillou (ch. 2), Barloche (ch. 4) ; Roche/Glace contre Emolga (Racaillou, Frissonille ch. 1, Polarhume ch. 4) ; Total Soin en boutique.
**Rôles :** Voltorbe (Destruction quand il va tomber), Emolga (Frotte-Frimousse : paralysie à coup sûr ; immunisé Sol), Magnéton (Fermeté), Élecsprint (As, **Paratonnerre** : il absorbe ton Électrik).
**IA :** AI-G2 + `Will Suicide`.
**Gimmick :** Explosion annoncée (« Ça va faire boum ! »).
**Dominante prévisible :** « tout Sol » → contre-pression : Emolga ; « mon Électrik » → Paratonnerre.
**Plans de victoire :** (1) Sol + un Roche/Glace pour Emolga ; (2) murs spéciaux + Total Soin ; (3) Plante/Électrik neutres en vitesse.
**Hasard :** la paralysie (25 % de perte de tour) est un aléa d'**output** : borné par Total Soin et un seul paralyseur.
**Fun :** O partout (environnement : la centrale prépare les types).
**Tests :** Emolga ne subit aucun dégât de Sol ; Voltorbe utilise Destruction quand il est sous 30 % (flag `Will Suicide`).

### 8.5 Raid du Tunnel Mérazon — Lance (Rocket) (T1, plafond 25 ; deux issues)

`T-LANCE-T1`
```
=== TRAINER_MIGUEL_5 ===
Name: LANCE
Class: Team Rocket Frlg
Pic: Rocket Grunt M Frlg
Gender: Male
Music: Suspicious
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Powerful Status / Ace Pokemon / Assumptions / Risky

Nickit
Level: 23
Ability: Unburden
Jolly Nature
- Quick Attack
- Snarl
- Thief
- Assurance

Golbat
Level: 24
Ability: Inner Focus
Jolly Nature
- Poison Fang
- Wing Attack
- Bite
- Haze

Weezing @ Black Sludge
Level: 26
Ability: Levitate
Bold Nature
- Sludge
- Clear Smog
- Toxic
- Self-Destruct
```
**Intention :** l'**attrition** : une série (3 sbires + Lance) sans soin, avec Brice à côté (prédicteur). **Pattern :** gérer PV/PP/objets entre deux combats.
**Préparation :** la décision L du ch. 4 (approche du raid, brief C) fixe le nombre de sbires (2 à 4) ; Psy (Abra, Tarsal), Sol (Osselait, Taupiqueur) ; Total Soin ; la route R116 a montré deux sbires Poison (`Toxik`).
**Rôles :** Goupilou (vole l'objet : Larcin), Nosferalto (vitesse, Crochetvenin), Smogogo (As : Toxik, Purédpois, Destruction).
**IA :** AI-V + `Risky`.
**Gimmick :** aucun ; la difficulté est la série.
**Dominante prévisible :** « soigner entre chaque combat » → contre-pression : pas de soin ; mais Brice soigne **une fois** si `BR` ≥ 50 (lisible : il le propose).
**Plans de victoire :** (1) Psy/Sol pour finir vite ; (2) mur + Total Soin ; (3) issue « défaite » : Lance s'enfuit avec la cargaison, le raid échoue, l'histoire continue (jalon 27 posé).
**Hasard :** faible ; aucune baisse de précision (Brouillard retiré).
**Fun :** O partout.
**Tests :** les deux issues posent le jalon 27 ; aucune issue ne bloque la R116.

### 8.6 Amaryllis 1 — Chutes Météore (T2, plafond 27 ; D050)

`T-AMARYLLIS-T2-SEULE`
```
=== TRAINER_KAREN_3 ===
Name: AMARYLLIS
Class: Dragon Tamer
Pic: Dragon Tamer
Gender: Female
Music: Female
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Powerful Status / Ace Pokemon / Assumptions / Force Setup First Turn

Aster (Loudred)
Level: 26
Ability: Scrappy
Modest Nature
- Uproar
- Bite
- Howl
- Stomp

Altaria
Level: 26
Ability: Natural Cure
Adamant Nature
- Dragon Breath
- Peck
- Mist
- Take Down

Shelgon @ Sitrus Berry
Level: 28
Ability: Rock Head
Adamant Nature
- Dragon Breath
- Headbutt
- Protect
- Zen Headbutt
```

`T-AMARYLLIS-T2-DUO`
```
=== TRAINER_KAREN_4 ===
Name: AMARYLLIS
Class: Dragon Tamer
Pic: Dragon Tamer
Gender: Female
Music: Female
Battle Type: Doubles
AI: Basic Trainer / Smart Switching / Powerful Status / Ace Pokemon / Assumptions

Aster (Loudred)
Level: 27
Ability: Scrappy
Modest Nature
- Uproar
- Bite
- Howl
- Echoed Voice

Altaria
Level: 27
Ability: Natural Cure
Adamant Nature
- Dragon Breath
- Peck
- Mist
- Take Down

Vibrava
Level: 27
Ability: Levitate
Jolly Nature
- Bulldoze
- Dragon Breath
- Bite
- Sand Tomb

Shelgon @ Sitrus Berry
Level: 29
Ability: Rock Head
Adamant Nature
- Dragon Breath
- Headbutt
- Protect
- Zen Headbutt
```
**Intention :** la croyante **teste** Red : « es-tu de la région du voleur ? » ; la forme du combat dit la position choisie à W1. **Pattern :** premier double à enjeu (2 contre 1) **ou** duel de Dragons.
**Préparation :** W1 juste avant (désigner Aragon → combat seul, respect ; partir avec Peter → 2 contre 1, Peter partenaire `P-PETER-CH5`) ; Glace (Marcacrin, Frissonille, Polarhume, Sorbébé), Fée (Snubbull, Fluvetin, Flabébé) ; doubles de route R111/R112.
**Rôles :** Aster/Ramboum (Querelleur : touche les Spectres), Altaria, Vibrava (duo : Lévitation), Draby évolué en Drackhaus (As, Tête de Roc).
**IA :** AI-V + `Force Setup First Turn` (seule) ; AI-V (duo, logique double automatique).
**Gimmick :** 2 contre 1 (moteur : `BATTLE_TWO_VS_ONE_OPPONENT`). **Arbitrage v3.1 : pas de nouvelle macro** : Peter en suiveur partenaire (`setfollowernpc … battlePartner`) puis `trainerbattle` simple, ce qui donne `opponentB = 0xFFFF` (`src/battle_setup.c` l. 1419–1423) ; à vérifier en émulateur.
**Dominante prévisible :** en duo, laisser Peter faire → contre-pression : Peter est au niveau 27–28, il ne gagne pas seul ; l'IA d'Amaryllis vise le plus faible des deux.
**Plans de victoire :** (1) Glace/Fée ; (2) en duo, concentrer deux attaques sur Drackhaus ; (3) l'issue « défaite » est racontée (elle part : « Pas encore. »), jalon 29 posé.
**Hasard :** faible.
**Fun :** O partout (environnement : la grotte et le choix W1 changent la forme du combat).
**Tests :** D050 a → `T-AMARYLLIS-T2-SEULE` ; D050 b → `-DUO` + partenaire ; les deux issues posent le jalon.

### 8.7 Adriane — badge 4 (T2, plafond 29, Vermilava)

`T-ADRIANE-T2`
```
=== TRAINER_FLANNERY_1 ===
Name: ADRIANE
Class: Leader
Pic: Leader Flannery
Gender: Female
Music: Female
Items: Super Potion / Super Potion
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Ace Pokemon / HP Aware / Assume Stab

Torkoal
Level: 29
Ability: Drought
Bold Nature
- Flame Wheel
- Body Slam
- Will-O-Wisp
- Curse

Numel
Level: 28
Ability: Simple
Modest Nature
- Flame Burst
- Magnitude
- Growth
- Amnesia

Magcargo
Level: 28
Ability: Flame Body
Bold Nature
- Flame Burst
- Rock Slide
- Amnesia
- Recover

Camerupt @ Charcoal
Level: 31
Ability: Solid Rock
Modest Nature
- Flame Burst
- Earth Power
- Rock Slide
- Amnesia
```
**Intention :** la **météo** comme règle du terrain : un poseur, deux profiteurs. **Pattern :** météo (`STRATEGY_RESEARCH` §7, étape 5).
**Préparation :** Chemin Ardent (un Chartor de route à Sécheresse) ; Sol/Roche (Galekid, Racaillou ch. 2, Barloche ch. 4, Escroco ch. 6), Eau malgré le soleil (Wailmer), Bekipan (Crachin, Goélise ch. 0 → niveau 25).
**Rôles :** Chartor (tête, Sécheresse), Chamallot (Simple + Amnésie : se booste vite), Limagma (mur), Camérupt (As, Tellurique, Roche Solide).
**IA :** AI-G2.
**Gimmick :** soleil 5 tours (le joueur peut **attendre** : Abri, changements).
**Dominante prévisible :** « mon Eau gagne » → contre-pression : Eau ×0,5 au soleil ; Camérupt (Roche Solide) encaisse.
**Plans de victoire :** (1) KO de Chartor puis Eau ; (2) Crachin : retourner la météo ; (3) Sol/Roche qui ignorent le soleil.
**Hasard :** faible.
**Fun :** O partout.
**Tests :** le soleil s'active au premier tour ; un Bekipan en tête l'annule.

### 8.8 Giovanni incognito — Chemin Ardent (T2, plafond 29 ; refusable D056)

`T-GIOVANNI-T2`
```
=== TRAINER_JACKI_4 ===
Name: GIOVANNI
Class: Boss Frlg
Pic: Leader Giovanni Frlg
Gender: Male
Music: Male
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Smart Mon Choices / Ace Pokemon / Assumptions / Predict Switch / PP Stall Prevention

Persian
Level: 28
Ability: Technician
Jolly Nature
- Fake Out
- Bite
- Feint
- Power Gem

Nidoking
Level: 29
Ability: Sheer Force
Modest Nature
- Earth Power
- Sludge Wave
- Thunderbolt
- Ice Beam

Rhydon @ Eviolite
Level: 31
Ability: Lightning Rod
Adamant Nature
- Rock Slide
- Bulldoze
- Megahorn
- Scary Face
```
**Intention :** l'homme au Persian se mesure : trois Pokémon, aucun objet de sac, aucune excuse. Une **rencontre**, pas une épreuve imposée. **Pattern :** respect de la force pure ; priorité (Bluff) et couverture (Nidoking).
**Préparation :** il est vu au ch. 3 (marché) et au ch. 6 (il corrige des sbires) ; Eau/Plante/Glace contre Sol ; Psy contre Nidoking ; Intimidation (Medhyèna).
**Rôles :** Persian (Technicien, Bluff, Ruse), Nidoking (Sans Limite : Telluriforce, Cradovague, couverture Tonnerre et Laser Glace), Rhinoféros (Évoluroc, Paratonnerre).
**IA :** AI-B (première prédiction du jeu : il **lit** le changement 1 fois sur 2).
**Gimmick :** aucun ; la réplique dit tout : « Trois. C'est assez pour savoir. »
**Dominante prévisible :** « mon Eau tue Rhinoféros » → contre-pression : Nidoking (Tonnerre) et la prédiction.
**Plans de victoire :** (1) Eau/Plante + un Psy ; (2) murs + statut ; (3) refuser (`GI` −, mais aucune perte de jeu).
**Hasard :** faible.
**Fun :** O partout.
**Tests :** refus → flag C, Giovanni ne repère plus le joueur ; victoire → `GI` + (C).

### 8.9 Max — Mont Chimnée (T2, plafond 29 ; D054 saboter ou dénoncer)

`T-MAX-T2`
```
=== TRAINER_MAXIE_MT_CHIMNEY ===
Name: MAX
Class: Magma Leader
Pic: Magma Leader Maxie
Gender: Male
Music: Magma
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Powerful Status / Ace Pokemon / Assumptions

Mightyena
Level: 28
Ability: Intimidate
Adamant Nature
- Crunch
- Fire Fang
- Howl
- Take Down

Krokorok
Level: 27
Ability: Moxie
Jolly Nature
- Bulldoze
- Crunch
- Sand Tomb
- Scary Face

Bouffalant
Level: 28
Ability: Sap Sipper
Adamant Nature
- Head Charge
- Revenge
- Rock Slide
- Scary Face

Camerupt @ Charcoal
Level: 31
Ability: Solid Rock
Modest Nature
- Flame Burst
- Earth Power
- Rock Slide
- Amnesia
```
**Intention :** le technocrate défend sa démonstration ; son équipe montre ce qu'elle a fait (Frison = le troupeau déplacé). **Pattern :** Intimidation + Impudence ; lire les talents (Herbivore).
**Préparation :** Kelvin juste avant (Grahyèna, Intimidation) ; le médecin du chantier soigne (bible §8.3) ; Eau (Wailmer, Marill), Combat (Makuhita), Psy.
**Rôles :** Grahyèna (Intimidation), Escroco (Impudence : chaque KO l'accélère), Frison (Herbivore : absorbe la Plante), Camérupt (As).
**IA :** AI-V.
**Dominante prévisible :** Plante contre Sol/Feu → contre-pression : Frison (Herbivore) et Camérupt (Feu).
**Plans de victoire :** (1) Eau + Combat ; (2) murs physiques contre l'Intimidation répétée ; (3) défaite racontée : la démonstration a lieu, D054 garde ses effets, l'histoire continue.
**Hasard :** faible. **Fun :** O partout (le chantier et l'anneau déclenché font l'environnement).
**Tests :** combat présent seulement en D054 b/c ; aucune issue ne bloque le téléphérique.

### 8.10 Norman — badge 5 (T2, plafond 33, Clémenti/QG du Rempart)

`T-NORMAN-T2`
```
=== TRAINER_NORMAN_1 ===
Name: NORMAN
Class: Leader
Pic: Leader Norman
Gender: Male
Music: Male
Items: Super Potion / Super Potion
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Ace Pokemon / HP Aware / Assume Stab

Vigoroth
Level: 32
Ability: Vital Spirit
Jolly Nature
- Slash
- Bulk Up
- Encore
- Fury Swipes

Linoone
Level: 32
Ability: Gluttony
Jolly Nature
- Headbutt
- Slash
- Pin Missile
- Belly Drum

Exploud
Level: 32
Ability: Scrappy
Modest Nature
- Hyper Voice
- Bite
- Stomp
- Howl

Slaking @ Sitrus Berry
Level: 35
Ability: Truant
Adamant Nature
- Body Slam
- Slack Off
- Shadow Claw
- Facade
```
**Intention :** l'ordre qui tient un tour sur deux : **attendre est un coup**. **Pattern :** tempo (Absentéisme), Encore, Ventre Plein annoncé.
**Préparation :** R117 (un Monaflèmit de route) ; Combat (Makuhita, Charpenti ch. 4, Scalpion ch. 6), Abri/Détection (CT), Feu Follet.
**Rôles :** Vigoroth (Encore : piège tes boosts), Linéon (Ventre Plein : « Tu as le temps d'un tour. »), Brouhabam (Querelleur), Monaflèmit (As, Absentéisme).
**IA :** AI-G2.
**Dominante prévisible :** « je frappe le plus fort chaque tour » → contre-pression : Encore et Monaflèmit qui encaisse ; « mon Spectre bloque Normal » → Querelleur.
**Plans de victoire :** (1) Abri le tour où Monaflèmit frappe, frapper pendant sa paresse ; (2) Combat ×2 ; (3) brûlure.
**Hasard :** faible. **Fun :** O partout sauf environnement N (déclaré : le décor du QG n'agit pas).
**Tests :** Linéon utilise Ventre Plein si le joueur ne menace pas de KO ; Monaflèmit ne frappe qu'un tour sur deux.

### 8.11 Brice 3 — R119 (T2, plafond 35 ; variante `BV` × starter)

`T-BRICE-T2-R119-PROTEGER-T`
```
=== TRAINER_BRENDAN_ROUTE_119_TORCHIC ===
Name: BRICE
Class: Rival
Pic: Brendan
Gender: Male
Music: Male
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Ace Pokemon / Know Opponent Party / Assumptions

Pelipper
Level: 34
Ability: Drizzle
Modest Nature
- Water Pulse
- Air Cutter
- Protect
- Roost

Tropius
Level: 33
Ability: Harvest
Adamant Nature
- Leaf Tornado
- Air Slash
- Stomp
- Synthesis

Manectric
Level: 34
Ability: Lightning Rod
Timid Nature
- Thunder Fang
- Discharge
- Bite
- Howl

Linoone
Level: 33
Ability: Pickup
Jolly Nature
- Headbutt
- Slash
- Pin Missile
- Rest

Blaziken @ Charcoal
Level: 37
Ability: Blaze
Adamant Nature
- Blaze Kick
- Double Kick
- Aerial Ace
- Bulk Up
```
**Intention :** Brice a changé : son équipe dit **ce qu'il a vu** (`BV`). **Pattern :** pluie (poseur + profiteurs) et lecture de la voie.
**Préparation :** la pluie de la R119 (la route est déjà sous la pluie : le terrain annonce le thème) ; Électrik (Dynavolt, Zéblitz, Magnéti), Plante (Nénupiot).
**Équipe affichée :** PROTÉGER, Brice a Poussifeu (Red a Arcko) ; 8 autres dans l'annexe.
**Rôles :** Bekipan (Crachin, tête), Tropius, Élecsprint (Paratonnerre : il te prend l'Électrik !), Linéon, Braségali (As).
**IA :** AI-RV.
**Dominante prévisible :** Électrik contre la pluie → contre-pression : Élecsprint (PROTÉGER), Pharamp (ACCUEILLIR), Paratonnerre ; il faut une **deuxième** réponse (Plante, Roche).
**Plans de victoire :** (1) KO de Bekipan puis jeu neutre ; (2) Plante + Roche ; (3) défaite racontée (Brice : « Tu vois ? Je compte aussi. »).
**Hasard :** faible. **Fun :** O partout.
**Tests :** les 9 variantes ; `BV` = 0 → PROTÉGER par défaut.

### 8.12 Alizée — badge 6 (T2, plafond 37, Cimetronelle)

`T-ALIZEE-T2`
```
=== TRAINER_WINONA_1 ===
Name: ALIZEE
Class: Leader
Pic: Leader Winona
Gender: Female
Music: Female
Items: Super Potion / Super Potion
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Ace Pokemon / HP Aware / Assume Stab

Skarmory
Level: 36
Ability: Sturdy
Impish Nature
- Spikes
- Steel Wing
- Whirlwind
- Air Cutter

Pelipper
Level: 35
Ability: Keen Eye
Bold Nature
- Water Pulse
- Air Cutter
- Protect
- Stockpile

Tropius
Level: 36
Ability: Chlorophyll
Adamant Nature
- Leaf Tornado
- Air Slash
- Stomp
- Synthesis

Swellow
Level: 36
Ability: Guts
Jolly Nature
- Aerial Ace
- Quick Attack
- Endeavor
- Agility

Altaria @ Sitrus Berry
Level: 39
Ability: Natural Cure
Adamant Nature
- Dragon Dance
- Dragon Breath
- Aerial Ace
- Roost
```
**Intention :** l'usure par le terrain : Picots + Cyclone. **Pattern :** pièges d'entrée et nettoyage (`STRATEGY_RESEARCH` §7, étape 6) : l'outil existe avant l'examen.
**Préparation :** Tentacool (pêche R103 dès le ch. 2) apprend Tour Rapide ; Grosses Bottes à l'Institut Météo (demande C/D) ; Électrik (Zéblitz, Statitik), Glace (Polarhume, Sorbébé), Roche.
**Rôles :** Airmure (Fermeté, Picots, Cyclone), Bekipan, Tropius, Hélédelle (Cran), Altaria (As, Danse Draco).
**IA :** AI-G2.
**Dominante prévisible :** « je change souvent » → contre-pression : Picots + Cyclone. 
**Plans de victoire :** (1) Tour Rapide puis Électrik ; (2) ignorer les Picots, équipe offensive, KO vite ; (3) Glace/Fée contre Altaria avant le deuxième boost.
**Hasard :** Lame d'Air/Tranch'Air (apeurement 30 % sur Lame d'Air seulement chez Tropius) : borné.
**Fun :** O partout.
**Tests :** Airmure pose Picots au tour 1 ; Cyclone force un changement ; Tour Rapide les retire.

### 8.13 Olga — Défi Indigo (T3, plafond 44, Nénucrique) et T5 : l'équipe de Glace optimale

`T-OLGA-T3-AVEC`
```
=== TRAINER_NOB_5 ===
Name: OLGA
Class: Elite Four Frlg
Pic: Elite Four Lorelei Frlg
Gender: Female
Music: Female
Items: Hyper Potion / Hyper Potion
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Ace Pokemon / HP Aware / Assume Stab / Conservative

Ninetales-Alola @ Light Clay
Level: 44
Ability: Snow Warning
Timid Nature
- Aurora Veil
- Freeze-Dry
- Moonblast
- Encore

Cloyster @ White Herb
Level: 44
Ability: Skill Link
Jolly Nature
- Shell Smash
- Icicle Spear
- Rock Blast
- Ice Shard

Slowbro @ Leftovers
Level: 44
Ability: Regenerator
Bold Nature
- Scald
- Ice Beam
- Slack Off
- Psyshock

Mamoswine @ Life Orb
Level: 45
Ability: Thick Fat
Adamant Nature
- Icicle Crash
- Earthquake
- Ice Shard
- Stealth Rock

Lapras @ Sitrus Berry
Level: 46
Ability: Water Absorb
Modest Nature
- Freeze-Dry
- Surf
- Thunderbolt
- Perish Song
```

`T-OLGA-T3-SANS`
```
=== TRAINER_DALTON_2 ===
Name: OLGA
Class: Elite Four Frlg
Pic: Elite Four Lorelei Frlg
Gender: Female
Music: Female
Items: Hyper Potion / Hyper Potion
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Ace Pokemon / HP Aware / Assume Stab / Conservative

Ninetales-Alola @ Light Clay
Level: 44
Ability: Snow Warning
Timid Nature
- Aurora Veil
- Freeze-Dry
- Moonblast
- Encore

Cloyster @ White Herb
Level: 44
Ability: Skill Link
Jolly Nature
- Shell Smash
- Icicle Spear
- Rock Blast
- Ice Shard

Slowbro @ Leftovers
Level: 44
Ability: Regenerator
Bold Nature
- Scald
- Ice Beam
- Slack Off
- Psyshock

Weavile @ Life Orb
Level: 45
Ability: Pressure
Jolly Nature
- Triple Axel
- Knock Off
- Ice Shard
- Low Kick

Mamoswine @ Life Orb
Level: 46
Ability: Thick Fat
Adamant Nature
- Icicle Crash
- Earthquake
- Ice Shard
- Stealth Rock
```

`T-OLGA-T5-AVEC`
```
=== TRAINER_DALTON_3 ===
Name: OLGA
Class: Elite Four Frlg
Pic: Elite Four Lorelei Frlg
Gender: Female
Music: Female
Items: Max Potion / Max Potion
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Smart Mon Choices / Ace Pokemon / Assumptions / Predict Switch / PP Stall Prevention / HP Aware / Predict Incoming Mon / Predict Move / Conservative

Ninetales-Alola @ Light Clay
Level: 75
Ability: Snow Warning
Timid Nature
- Aurora Veil
- Freeze-Dry
- Moonblast
- Encore

Sandslash-Alola @ Heavy-Duty Boots
Level: 75
Ability: Slush Rush
Jolly Nature
- Triple Axel
- Iron Head
- Earthquake
- Rapid Spin

Cloyster @ White Herb
Level: 76
Ability: Skill Link
Jolly Nature
- Shell Smash
- Icicle Spear
- Rock Blast
- Ice Shard

Mamoswine @ Never-Melt Ice
Level: 76
Ability: Thick Fat
Adamant Nature
- Icicle Crash
- Earthquake
- Ice Shard
- Stealth Rock

Lapras @ Leftovers
Level: 76
Ability: Water Absorb
Modest Nature
- Freeze-Dry
- Sparkling Aria
- Thunderbolt
- Perish Song

Slowbro @ Slowbronite
Level: 78
Ability: Regenerator
Bold Nature
- Scald
- Ice Beam
- Slack Off
- Calm Mind
```
**Intention :** « une île froide qui protège ». Olga ne frappe pas d'abord : elle **installe** (neige, Voile Aurore), puis l'attaquant d'Exuviation balaie. Son équipe dit si Red lui a rendu ses Lokhlass (D082 a).
**Raisonnement (meilleure équipe que son identité permet, Gen 1–9) :**
- Glace subit 4 faiblesses (Feu, Combat, Roche, Acier) et résiste mal. La réponse optimale n'est pas « plus de Glace » mais **neige + Voile Aurore** (Feunard d'Alola, Alerte Neige : défense ×1,5 pour la Glace, dégâts ÷2 pendant 5 tours, 8 avec Lumargile) et **une couverture qui frappe ses propres contres** : Mammochon (Séisme : Feu, Roche, Acier), Flagadoss (Psy : Combat ; Eau : Feu, Roche), Lokhlass (Absorb Eau, Lyophilisation : l'Eau).
- **Crustabri** (Multi-Coups + Exuviation : Stalactite ×5 à coup sûr, Boule Roc contre Feu) est le balayeur : déterministe (pas de hasard de répétition), et punissable (Aqua-Jet, Pisto-Poing, Éclats Glace, Fermeté).
- **Sabelette d'Alola** (T5 : Chasse-Neige, vitesse ×2 sous la neige ; Tour Rapide) ajoute le contrôle des pièges et la vitesse.
- **Méga-Flagadoss** (T5, Kanto, canon) est l'As défensif : Régé-Force avant la Méga, Coque Armure ensuite, Plénitude.
- Origines : Feunard et Sabelette d'**Alola**, Mammochon et Dimoret de **Sinnoh** = nœud de Nénucrique (bible §5.3) où elle traque le marché noir ; Crustabri, Flagadoss, Lokhlass = canon Kanto/Sevii.
- Exclus volontairement : Glaivodo (réservé à Glacia, l'arrivante) ; Lippoutou (Grobisou = sommeil au hasard) ; Kyurem (légendaire).
**Variantes :** AVEC : Lokhlass (As, Absorb Eau, Requiem : un compte à rebours **lisible**). SANS : Dimoret (Triple Axel, Sabotage) : elle chasse ; l'As devient Mammochon. T5 : 6 Pokémon, Méga-Flagadoss.
**Préparation :** Feu (Caninos, Ponyta ch. 1, Chamallot ch. 5), Combat (Makuhita, Charpenti, Scalpion), Acier (Galekid, Magnéti), Roche (Racaillou) ; **Casse-Brique** (CT) ou Anti-Brume contre le Voile ; Tour Rapide ; Total Soin.
**IA :** AI-G2 + `Conservative` (elle ne vise le KO qu'à coup sûr : elle installe d'abord).
**Gimmick :** Voile Aurore (annoncé : « Ici, il neige pour moi. ») ; Exuviation (l'Herbe Blanche est visible au moment où elle annule la baisse).
**Dominante prévisible :** « Feu partout » → contre-pression : Flagadoss, Lokhlass, Mammochon (Isograisse) ; « je frappe à travers le Voile » → les dégâts sont divisés par deux 5 tours.
**Plans de victoire :** (1) KO de Feunard d'Alola au premier tour (Acier, Roche, Feu) : pas de Voile ; (2) attendre le Voile (Abri, changements, murs), puis frapper ; (3) punir Crustabri après Exuviation (priorité, Fermeté, Feu) ; (4) Casse-Brique sur le Voile.
**Hasard :** faible (Multi-Coups fixe à 5 ; aucune attaque < 90 % ; Blizzard absent).
**Fun :** O partout (la neige change le terrain ; deux formes d'équipe selon D082).
**Tests :** neige au premier tour ; Voile Aurore échoue sans neige ; AVEC si `OLGA_LOKHLASS` ; T5 : Méga-Flagadoss au premier tour de sa sortie.

### 8.14 Lévy et Tatia — badge 7 (T3, double, plafond 44, Algatia)

`T-LEVYTATIA-T3`
```
=== TRAINER_TATE_AND_LIZA_1 ===
Name: LEVY&TATIA
Class: Leader
Pic: Leader Tate And Liza
Gender: Male
Music: Female
Items: Hyper Potion / Hyper Potion
Battle Type: Doubles
AI: Basic Trainer / Smart Switching / Ace Pokemon / HP Aware / Assume Stab / Omniscient / Double Ace Pokemon

Solrock
Level: 44
Ability: Levitate
Relaxed Nature
- Trick Room
- Rock Slide
- Psychic
- Flare Blitz

Lunatone
Level: 44
Ability: Levitate
Quiet Nature
- Trick Room
- Psychic
- Ice Beam
- Moonblast

Claydol @ Sitrus Berry
Level: 45
Ability: Levitate
Quiet Nature
- Earth Power
- Psychic
- Ally Switch
- Reflect

Farigiraf @ Sitrus Berry
Level: 46
Ability: Armor Tail
Quiet Nature
- Twin Beam
- Hyper Voice
- Trick Room
- Protect
```
**Intention :** les télépathes **lisent** Red ; la Distorsion inverse la vitesse. **Pattern :** contrôle de vitesse en double.
**Préparation :** doubles de route à Algatia ; Ténèbres (Zorua, Chacripan, Farfuret : **Provoc**), Insecte (Statitik), Spectre (Polichombr ch. 9) ; Pokémon lents (Galekid, Tartard).
**Rôles :** Solaroc + Séléroc (poseurs de Distorsion), Kaorine (Interversion), Farigiraf (Queue Armure : pas de priorité contre eux).
**IA :** AI-G2 + **`Omniscient`** (annoncé : « On t'entend penser. ») + `Double Ace`.
**Dominante prévisible :** « je suis rapide » → contre-pression : Distorsion ; « priorité » → Queue Armure.
**Plans de victoire :** (1) Provoc sur les poseurs au tour 1 ; (2) jouer lent sous Distorsion ; (3) Abri × 2 pour user les 5 tours.
**Hasard :** faible. **Fun :** O partout. **Tests :** Distorsion au tour 1 ; aucune priorité ne passe contre Farigiraf.

### 8.15 Peter — Défi Indigo (T3, plafond 47, Algatia ; D100)

`T-PETER-T3A-DRATTAK`
```
=== TRAINER_ETHAN_4 ===
Name: PETER
Class: Elite Four Frlg
Pic: Elite Four Lance Frlg
Gender: Male
Music: Male
Items: Hyper Potion / Hyper Potion
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Smart Mon Choices / Ace Pokemon / Assumptions / Predict Switch / PP Stall Prevention

Aerodactyl @ Focus Sash
Level: 46
Ability: Pressure
Jolly Nature
- Stone Edge
- Earthquake
- Stealth Rock
- Taunt

Charizard @ Life Orb
Level: 46
Ability: Blaze
Timid Nature
- Flamethrower
- Air Slash
- Dragon Pulse
- Roost

Archaludon @ Leftovers
Level: 46
Ability: Stamina
Modest Nature
- Flash Cannon
- Dragon Pulse
- Body Press
- Thunderbolt

Salamence @ Life Orb
Level: 47
Ability: Intimidate
Adamant Nature
- Dragon Dance
- Dual Wingbeat
- Earthquake
- Outrage

Gyarados @ Gyaradosite
Level: 47
Ability: Intimidate
Adamant Nature
- Dragon Dance
- Waterfall
- Crunch
- Earthquake

Dragonite @ Weakness Policy
Level: 48
Ability: Multiscale
Adamant Nature
- Dragon Dance
- Outrage
- Extreme Speed
- Fire Punch
```
**Intention :** l'autorité de Kanto, lourde et adaptative ; ce que Red a fait au Site Météore se voit (Drattak). **Pattern :** Dragons, Multiécaille, Vulné-Assurance ; E-ADAPT.
**Préparation :** Peter dit sa règle (« Je regarde ce que tu portes. ») ; Glace (Blizzi ch. 9, Polarhume, Sorbébé, Marcacrin → Mammochon), Fée (Snubbull, Fluvetin, Flabébé), Dragons du Safari (ch. 9) ; Tour Rapide contre Piège de Roc.
**Équipe affichée :** paquet A + Drattak ; 5 autres dans l'annexe.
**Rôles :** Ptéra (Ceinture Force, Piège de Roc, Provoc), Dracaufeu, Pondralugon (paquet A : Acier/Dragon), Drattak, Méga-Léviator (Brise Moule), Dracolosse (As, Multiécaille, Vulné-Assurance).
**IA :** AI-B.
**Gimmick :** Méga-Léviator au premier tour de sa sortie.
**Dominante prévisible :** « Glace sur tout » → contre-pression : Vulné-Assurance + Multiécaille sur l'As ; Pondralugon (Acier) résiste.
**Plans de victoire :** (1) casser Multiécaille par Piège de Roc/Éclats Glace puis un vrai coup ; (2) Fée contre les Dragons, Électrik contre Léviator ; (3) contrôle de vitesse (Toile Élek, Cage-Éclair) avant Danse Draco.
**Hasard :** faible. **Fun :** O partout. **Tests :** 6 variantes ; Drattak seulement si D050 a (respect) ; Méga au premier tour.

### 8.16 Centre Spatial — Ariane puis Lambda (T3, plafond 47 ; série sans soin ; D095)

`T-ARIANE-T3-RKHAUT`
```
=== TRAINER_MIGUEL_3 ===
Name: ARIANE
Class: Team Rocket Frlg
Pic: Rocket Grunt F Frlg
Gender: Female
Music: Suspicious
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Powerful Status / Ace Pokemon / Assumptions / Prefer Status Moves

Arbok
Level: 46
Ability: Intimidate
Adamant Nature
- Gunk Shot
- Glare
- Crunch
- Coil

Vileplume
Level: 46
Ability: Chlorophyll
Calm Nature
- Giga Drain
- Sludge Bomb
- Stun Spore
- Moonblast

Liepard
Level: 46
Ability: Prankster
Timid Nature
- Fake Out
- Thunder Wave
- Knock Off
- Encore

Grimmsnarl @ Light Clay
Level: 46
Ability: Prankster
Careful Nature
- Reflect
- Light Screen
- Spirit Break
- Thunder Wave

Muk
Level: 46
Ability: Stench
Adamant Nature
- Gunk Shot
- Knock Off
- Shadow Sneak
- Curse

Honchkrow @ Life Orb
Level: 48
Ability: Moxie
Adamant Nature
- Brave Bird
- Sucker Punch
- Night Slash
- Heat Wave
```

`T-LAMBDA-T3`
```
=== TRAINER_TABITHA_MOSSDEEP ===
Name: LAMBDA
Class: Team Rocket Frlg
Pic: Leader Giovanni Frlg
Gender: Male
Music: Suspicious
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Powerful Status / Ace Pokemon / Assumptions / Will Suicide

Zoroark @ Life Orb
Level: 47
Ability: Illusion
Timid Nature
- Night Daze
- Flamethrower
- Focus Blast
- Nasty Plot

Weezing
Level: 46
Ability: Levitate
Bold Nature
- Sludge Bomb
- Will-O-Wisp
- Flamethrower
- Explosion

Ditto @ Choice Scarf
Level: 46
Ability: Imposter
Relaxed Nature
- Transform

Persian
Level: 48
Ability: Technician
Jolly Nature
- Fake Out
- Bite
- Feint
- Power Gem
```
**Intention :** l'assaut du relais : deux combats d'affilée, et une imposture à **lire**. **Pattern :** attrition + Illusion (lire l'efficacité affichée).
**Préparation :** partenaire selon les relations (Pierre Rochard, Peter ou Brice ; brief C) pour les sbires ; Sol, Électrik, Combat ; Giovanni a dit au ch. 9 : « Mon Persian ne connaît pas les attaques des ténèbres. »
**Rôles (Ariane, RK HAUT) :** Arbok (Intimidation, Regard Médusant), Rafflesia, Léopardus (Farceur : Bluff, Cage-Éclair), Angoliath (Farceur : écrans), Grotadmorv, Corboss (As, Impudence). RK BAS : sans Léopardus ni Angoliath (4 Pokémon) : la Rocket faible se voit.
**Rôles (Lambda) :** Zoroark (Illusion : il apparaît en **Persian**), Smogogo (Explosion), Métamorph (Imposteur, Mouchoir), Persian (vrai, en dernier).
**IA :** AI-V + `Prefer Status Moves` (Ariane) ; AI-V + `Will Suicide` (Lambda).
**Dominante prévisible :** « je joue comme contre Giovanni » (Combat contre Persian) → contre-pression : le « Persian » est Zoroark : la surprise se lit à l'efficacité affichée (Combat super efficace sur un « Persian ») ; Métamorph copie ta tête.
**Plans de victoire :** (1) Sol + Électrik contre Ariane, Casse-Brique contre les écrans ; (2) lire l'Illusion (l'efficacité affichée trahit le type) et mener avec un Pokémon sacrifiable contre Métamorph ; (3) défaite racontée : la Rocket entre au relais, Ciléo ferme le cœur (le jalon 49 est posé).
**Hasard :** faible ; Explosion annoncée par Lambda (« Rideau ! »).
**Fun :** O partout. **Tests :** RK ≥ seuil → `RKHAUT` ; Zoroark apparaît en Persian ; jalon 49 dans toutes les issues.

### 8.17 Amaryllis 2 — Centre Spatial (T3, plafond 47)

`T-AMARYLLIS-T3`
```
=== TRAINER_KAREN_5 ===
Name: AMARYLLIS
Class: Dragon Tamer
Pic: Dragon Tamer
Gender: Female
Music: Female
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Smart Mon Choices / Ace Pokemon / Assumptions / Predict Switch / PP Stall Prevention / Force Setup First Turn

Tyrantrum @ Life Orb
Level: 47
Ability: Strong Jaw
Adamant Nature
- Psychic Fangs
- Head Smash
- Dragon Claw
- Dragon Dance

Noivern @ Sitrus Berry
Level: 47
Ability: Infiltrator
Timid Nature
- Boomburst
- Air Slash
- Dragon Pulse
- Super Fang

Goodra @ Assault Vest
Level: 47
Ability: Sap Sipper
Modest Nature
- Draco Meteor
- Sludge Bomb
- Thunderbolt
- Fire Blast

Aster (Exploud) @ Choice Specs
Level: 48
Ability: Scrappy
Modest Nature
- Boomburst
- Fire Blast
- Focus Blast
- Surf

Altaria @ Leftovers
Level: 48
Ability: Natural Cure
Bold Nature
- Dragon Pulse
- Moonblast
- Roost
- Cotton Guard

Salamence @ Salamencite
Level: 49
Ability: Intimidate
Jolly Nature
- Dragon Dance
- Double-Edge
- Earthquake
- Roost
```
**Intention :** on la surprend à acheter des transferts ; la croyante montre toute sa force (équipe canonique ROSA, Méga-Drattak). **Pattern :** Méga adverse + Danse Draco annoncée.
**Préparation :** la série du Centre Spatial vient d'avoir lieu : **soin** au Centre Pokémon d'Algatia avant le toit (ce combat est séparé de la série) ; Glace, Fée, Dragon ; Intimidation.
**Rôles :** Rexillius (Prognathe, Danse Draco), Bruyverne (Infiltration), Muplodocus (Veste de Combat), Aster/Brouhabam (Lunettes, Querelleur), Altaria (Cotogarde), Méga-Drattak (As, Peau Céleste : Damoclès devient Vol).
**IA :** AI-B + `Force Setup First Turn` (Danse Draco au premier tour : tell).
**Dominante prévisible :** « Glace règle tout » → contre-pression : Muplodocus et Brouhabam (Lance-Flammes) ; Rexillius (Roche).
**Plans de victoire :** (1) Glace/Fée rapides ; (2) punir Danse Draco par la priorité (Éclats Glace) ou Intimidation ; (3) défaite racontée (« Tu entends ? Il compte. »).
**Hasard :** Fracass'Tête (Rexillius) précision 80 % : seul coup imprécis, sur un Pokémon non-As.
**Fun :** O partout. **Tests :** Méga au premier tour ; Danse Draco au premier tour sûr.

### 8.18 Juan — badge 8 (T3, plafond 51, Atalanopolis)

`T-JUAN-T3`
```
=== TRAINER_JUAN_1 ===
Name: JUAN
Class: Leader
Pic: Leader Juan
Gender: Male
Music: Male
Items: Hyper Potion / Hyper Potion
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Ace Pokemon / HP Aware / Assume Stab / Conservative / Prefer Baton Pass / Force Setup First Turn

Floatzel
Level: 50
Ability: Water Veil
Jolly Nature
- Bulk Up
- Baton Pass
- Aqua Jet
- Waterfall

Whiscash
Level: 50
Ability: Oblivious
Adamant Nature
- Dragon Dance
- Earthquake
- Waterfall
- Zen Headbutt

Walrein
Level: 51
Ability: Thick Fat
Modest Nature
- Surf
- Ice Beam
- Protect
- Rest

Crawdaunt @ Life Orb
Level: 51
Ability: Adaptability
Adamant Nature
- Crabhammer
- Knock Off
- Swords Dance
- Aqua Jet

Kingdra @ Sitrus Berry
Level: 53
Ability: Swift Swim
Adamant Nature
- Dragon Dance
- Waterfall
- Outrage
- Iron Head
```
**Intention :** l'arbitre élégant : la danse passe de l'un à l'autre. **Pattern :** outils **anti-boost** (Buée Noire, Hurlement, Inconscient, Provoc, Encore).
**Préparation :** Fondmer juste avant (Sarah : Prédastérie à Buée Noire montre l'outil) ; Tentacool (Buée Noire), Caninos/Airmure (Hurlement/Cyclone), Maraiste (Inconscient, Safari), Vigoroth (Encore), Électrik et Plante.
**Rôles :** Mustéflott (Gonflette + Relais), Barbicha (Danse Draco), Kaimorse, Colhomard (Danse Lames), Hyporoi (As, Danse Draco, Glissade).
**IA :** AI-G2 + `Conservative` + `Prefer Baton Pass` + `Force Setup First Turn`.
**Dominante prévisible :** « un gros attaquant » → contre-pression : les boosts passent plus vite que tu ne frappes.
**Plans de victoire :** (1) phazer/Buée Noire au bon tour ; (2) Inconscient (Maraiste) ; (3) KO avant le deuxième boost (Électrik).
**Hasard :** faible (aucun coup critique augmenté). **Fun :** O partout. **Tests :** Mustéflott utilise Relais après un boost ; Buée Noire annule tout.

### 8.19 Amaryllis 3 — Pilier Céleste, climax (T4, plafond 53 ; anomalie P2 selon `PA`)

`T-AMARYLLIS-T4-P2`
```
=== TRAINER_ANNA_AND_MEG_3 ===
Name: AMARYLLIS
Class: Dragon Tamer
Pic: Dragon Tamer
Gender: Female
Music: Female
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Smart Mon Choices / Ace Pokemon / Assumptions / Predict Switch / PP Stall Prevention / Force Setup First Turn

Tyrantrum @ Life Orb
Level: 53
Ability: Strong Jaw
Adamant Nature
- Psychic Fangs
- Head Smash
- Dragon Claw
- Dragon Dance

Noivern @ Sitrus Berry
Level: 53
Ability: Infiltrator
Timid Nature
- Boomburst
- Air Slash
- Dragon Pulse
- Super Fang

Goodra @ Assault Vest
Level: 53
Ability: Sap Sipper
Modest Nature
- Draco Meteor
- Sludge Bomb
- Thunderbolt
- Fire Blast

Aster (Exploud) @ Choice Specs
Level: 54
Ability: Scrappy
Modest Nature
- Boomburst
- Fire Blast
- Focus Blast
- Surf

Guzzlord @ Leftovers
Level: 54
Ability: Beast Boost
Brave Nature
- Knock Off
- Dragon Tail
- Heavy Slam
- Drain Punch

Salamence @ Salamencite
Level: 55
Ability: Intimidate
Jolly Nature
- Dragon Dance
- Double-Edge
- Earthquake
- Roost
```
**Intention :** la Nuit des Anneaux : elle accueille Rayquaza. Si la pression des anneaux est haute, **le ciel déchiré se voit dans son équipe** : un Engloutyran (Ultra-Chimère non légendaire) remplace Altaria. Le combat ne décide rien (invariant 4) : il gagne du temps (Y3).
**Préparation :** veillée (soin forcé) ; la Doyenne soigne avant le Pilier ; les anomalies P2 vues depuis le ch. 8 ont montré les Ultra-Chimères ; Fée (Snubbull, Fluvetin, Mélofée : ×4 contre Engloutyran), Glace, Combat.
**Rôles :** Rexillius, Bruyverne, Muplodocus, Brouhabam (Aster), **Engloutyran** (Boost Chimère : chaque KO augmente sa meilleure stat), Méga-Drattak (As).
**IA :** AI-B + `Force Setup First Turn`.
**Dominante prévisible :** « je garde mon meilleur pour la fin » → contre-pression : Engloutyran (PV énormes) use l'équipe.
**Plans de victoire :** (1) Fée contre Engloutyran et Drattak ; (2) Glace + priorité ; (3) défaite racontée : Rayquaza arrive plus tôt, l'évaluation de la Fiole (bible §12.2) suit son cours, jalon 56 posé.
**Hasard :** faible. **Fun :** O partout (le ciel, l'anomalie, Rayquaza qui arrive).
**Tests :** `PA` ≥ seuil P2 → `-P2` ; sinon `T-AMARYLLIS-T4` ; jalon 56 dans toutes les issues.

### 8.20 Blue final — Route Victoire (T4, plafond 56 ; obligatoire)

`T-BLUE-T4A-SCOTT`
```
=== TRAINER_LOLA_4 ===
Name: BLUE
Class: Rival Late Frlg
Pic: Champion Rival Frlg
Gender: Male
Music: Male
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Smart Mon Choices / Ace Pokemon / Assumptions / Predict Switch / PP Stall Prevention / Risky

Rhyperior @ Weakness Policy
Level: 57
Ability: Solid Rock
Adamant Nature
- Stone Edge
- Earthquake
- Megahorn
- Ice Punch

Alakazam @ Life Orb
Level: 57
Ability: Magic Guard
Timid Nature
- Psychic
- Shadow Ball
- Focus Blast
- Nasty Plot

Arcanine @ Choice Band
Level: 57
Ability: Intimidate
Adamant Nature
- Flare Blitz
- Crunch
- Extreme Speed
- Wild Charge

Corviknight @ Leftovers
Level: 56
Ability: Pressure
Impish Nature
- Brave Bird
- Iron Head
- Roost
- Bulk Up

Kingambit @ Black Glasses
Level: 56
Ability: Supreme Overlord
Adamant Nature
- Kowtow Cleave
- Iron Head
- Sucker Punch
- Swords Dance

Pidgeot @ Pidgeotite
Level: 58
Ability: Big Pecks
Timid Nature
- Hurricane
- Heat Wave
- Roost
- U-turn
```
**Intention :** la dernière question du rival : a-t-il appris à **aimer ses Pokémon** (LIBRE : Tauros de Bourg Palette) ou seulement à les acheter (SCOTT : Scalpereur) ? **Pattern :** synthèse : adaptation + Méga + objets.
**Préparation :** Blue l'annonce (« J'ai tout revu. Ta dominante, je la connais. ») ; Roche, Électrik, Glace contre Méga-Roucarnage ; Combat contre Scalpereur ; Inconscient contre Vulné-Assurance.
**Équipe affichée :** paquet A, SCOTT ; 5 autres dans l'annexe.
**Rôles :** Rhinastoc (Vulné-Assurance : ne pas le taper faiblement en super efficace), Alakazam, paquet (Arcanin Bandeau, Corvaillus), Scalpereur (Général Suprême) ou Tauros (Bandeau), Méga-Roucarnage (As, Annule Garde : Ouragan touche toujours).
**IA :** AI-B + `Risky`.
**Dominante prévisible :** dominante en façade → contre-pression : le noyau change peu, la façade marche, mais Alakazam et Rhinastoc couvrent large.
**Plans de victoire :** (1) Roche/Électrik pour l'As, Combat pour Scalpereur ; (2) dominante en façade ; (3) murs + Feu Follet.
**Hasard :** faible ; `Risky` = KO ratés en faveur du joueur. **Fun :** O partout. **Tests :** 6 variantes ; LIBRE si `STANCE_BLUE` = LIBRE.

### 8.21 Giovanni — le dernier duel (T5, postgame ; refusable D127)

`T-GIOVANNI-T5A`
```
=== TRAINER_JACKI_5 ===
Name: GIOVANNI
Class: Boss Frlg
Pic: Leader Giovanni Frlg
Gender: Male
Music: Male
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Smart Mon Choices / Ace Pokemon / Assumptions / Predict Switch / PP Stall Prevention / HP Aware / Predict Incoming Mon / Predict Move

Persian @ Choice Band
Level: 75
Ability: Technician
Jolly Nature
- Fake Out
- Knock Off
- U-turn
- Play Rough

Dugtrio @ Focus Sash
Level: 75
Ability: Arena Trap
Jolly Nature
- Earthquake
- Sucker Punch
- Stone Edge
- Memento

Nidoqueen @ Leftovers
Level: 75
Ability: Sheer Force
Modest Nature
- Earth Power
- Sludge Wave
- Ice Beam
- Stealth Rock

Nidoking @ Life Orb
Level: 76
Ability: Sheer Force
Timid Nature
- Earth Power
- Sludge Wave
- Ice Beam
- Thunderbolt

Honchkrow @ Life Orb
Level: 76
Ability: Moxie
Adamant Nature
- Brave Bird
- Sucker Punch
- Night Slash
- Heat Wave

Rhyperior @ Weakness Policy
Level: 78
Ability: Solid Rock
Adamant Nature
- Earthquake
- Stone Edge
- Megahorn
- Rock Polish
```
**Intention :** « une dernière fois, sans rien d'importé ». Pas de Méga, pas de Mewtwo, pas d'arrivant : un empire réduit à ce qu'il porte. **Pattern :** optimisation T5 ; Piège Sable (Triopikeur) ; E-ADAPT.
**Préparation :** sa réplique annonce Triopikeur (« Personne ne quitte ce terrain. ») ; Vol/Lévitation contre Piège Sable ; Eau, Plante, Glace ; Inconscient.
**Équipe affichée :** paquet A (Corboss) ; B (Hippodocus), C (Tyranocif) dans l'annexe.
**Rôles :** Persian (Bluff, Demi-Tour), Triopikeur (Piège Sable, Ceinture Force), Nidoqueen (Piège de Roc), Nidoking (Sans Limite), paquet, Rhinastoc (As, Vulné-Assurance).
**IA :** AI-E.
**Plans de victoire :** (1) Lévitation/Vol + Eau ; (2) KO de Triopikeur avant qu'il piège ton mur ; (3) Inconscient contre les boosts.
**Hasard :** faible. **Fun :** O partout. **Tests :** refus → D127 c ; victoire → sbires retirés (C).

### 8.22 Maître — Pierre Rochard (PROTÈGE / ACCUSE) ou Marc (T4, plafond 56)

`T-PIERREROCHARD-T4-PROTEGE`
```
=== TRAINER_STEVEN ===
Name: PIERRE R.
Class: Champion
Pic: Steven
Gender: Male
Music: Male
Items: Hyper Potion / Hyper Potion / Full Restore
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Smart Mon Choices / Ace Pokemon / Assumptions / Predict Switch / PP Stall Prevention / HP Aware / Predict Incoming Mon / Predict Move / Conservative

Skarmory @ Rocky Helmet
Level: 56
Ability: Sturdy
Impish Nature
- Spikes
- Brave Bird
- Roost
- Whirlwind

Claydol @ Leftovers
Level: 56
Ability: Levitate
Relaxed Nature
- Earthquake
- Psychic
- Stealth Rock
- Rapid Spin

Aggron @ Sitrus Berry
Level: 57
Ability: Sturdy
Adamant Nature
- Heavy Slam
- Stone Edge
- Earthquake
- Rock Polish

Cradily @ Leftovers
Level: 57
Ability: Storm Drain
Calm Nature
- Giga Drain
- Rock Slide
- Recover
- Toxic

Armaldo @ Life Orb
Level: 58
Ability: Battle Armor
Adamant Nature
- Stone Edge
- X-Scissor
- Earthquake
- Swords Dance

Metagross @ Metagrossite
Level: 59
Ability: Clear Body
Jolly Nature
- Meteor Mash
- Zen Headbutt
- Earthquake
- Bullet Punch
```

`T-MARC-T4`
```
=== TRAINER_WALLACE ===
Name: MARC
Class: Champion
Pic: Champion Wallace
Gender: Male
Music: Male
Items: Hyper Potion / Hyper Potion / Full Restore
Battle Type: Singles
AI: Basic Trainer / Smart Switching / Smart Mon Choices / Ace Pokemon / Assumptions / Predict Switch / PP Stall Prevention / HP Aware / Predict Incoming Mon / Predict Move

Pelipper @ Damp Rock
Level: 56
Ability: Drizzle
Bold Nature
- Hurricane
- Scald
- Roost
- U-turn

Tentacruel @ Black Sludge
Level: 56
Ability: Clear Body
Timid Nature
- Scald
- Sludge Bomb
- Rapid Spin
- Toxic Spikes

Ludicolo @ Life Orb
Level: 57
Ability: Swift Swim
Modest Nature
- Hydro Pump
- Giga Drain
- Ice Beam
- Fake Out

Gyarados @ Sitrus Berry
Level: 57
Ability: Intimidate
Adamant Nature
- Dragon Dance
- Waterfall
- Earthquake
- Ice Fang

Primarina @ Leftovers
Level: 58
Ability: Torrent
Modest Nature
- Sparkling Aria
- Moonblast
- Psychic
- Calm Mind

Milotic @ Leftovers
Level: 59
Ability: Marvel Scale
Bold Nature
- Scald
- Recover
- Ice Beam
- Haze
```
**Intention :** la Ligue est l'**écho** de la fin : qui est Maître dépend de l'histoire (Pierre Rochard démissionne en F2 : Marc). L'équipe de Pierre Rochard dit s'il a accusé son père (le fossile de Devon disparaît).
**Préparation :** le Conseil 4 vient d'enseigner Farceur, Feu Follet, boosts, Intimidation ; Feu, Sol, Combat, Eau contre l'Acier ; Électrik et Plante contre la pluie de Marc.
**Rôles (Pierre Rochard) :** Airmure (Picots), Kaorine (Piège de Roc, Tour Rapide), Galeking, Vacilys, Armaldo **ou** Tarinorme, Méga-Métalosse 59 (Griffe Dure).
**Rôles (Marc) :** Bekipan (Crachin), Tentacruel (Pics Toxik), Ludicolo (Glissade), Léviator (Danse Draco), Oratoria, Milobellus 59 (Écaille Spéciale, Buée Noire). Aucune Méga.
**IA :** AI-E + `Conservative` (Pierre Rochard) ; AI-E (Marc).
**Plans de victoire :** Pierre Rochard : (1) Feu/Sol contre l'Acier ; (2) Tour Rapide puis offensive ; Marc : (1) retirer Bekipan et jouer hors pluie ; (2) Électrik/Plante sous la pluie avec Absorb Eau.
**Hasard :** faible. **Fun :** O partout. **Tests :** `STANCE_PR` ACCUSE → Tarinorme ; démission → `T-MARC-T4` ; jalon 60.

---

## 9. Mode Difficile (`Difficulty: Hard`, `B_VAR_DIFFICULTY` = `VAR_DIFFICULTY`, `ENGINE_CHANGES` H2)

**Règle de dérivation (automatique, `teams_v3_gen.py`) :** chaque équipe Normale a un bloc Hard **sous le même ID** (aucun ID consommé). Le moteur retombe sur Normal si un bloc manque (`GetTrainerDifficultyLevel`).

| Élément | Normal | Difficile | Pourquoi |
|---|---|---|---|
| Niveaux, espèces, capacités, objets tenus | référence | **identiques** | pas d'abus de niveau ; la doc et les fiches restent vraies |
| IV | T1 15, T2 20, T3 25, T4–T5 31 | 31 | statistiques de « vrai » dresseur |
| EV (selon le rôle) | T1–T3 aucun, T4 128/128, T5 252/252/4 | T1 85/85, T2 128/128, T3+ 252/252/4 | la différence se sent sans changer de lecture |
| IA | §3.1 | + un cran : G1 + `HP Aware` ; G2/RV/V + `Smart Mon Choices` + `Predict Switch` ; B + `HP Aware`, `Predict Incoming Mon`, `Predict Move` ; E/Z + `Weigh Ability Prediction` | décisions plus fines, jamais d'omniscience ajoutée |
| Sac du joueur | libre | demande au brief C : `B_VAR_NO_BAG_USE` = 1 contre les combats majeurs (option du mode) | Run & Bun, Radical Red (`STRATEGY_RESEARCH` §9) |

Mode **Facile** : non produit (le moteur retombe sur Normal) ; si le GMD le veut, même dérivation inversée (IV −5, IA d'un cran en dessous).

---

## 10. Dresseurs de route et couches de faction

**Règle d'or :** un dresseur de route **montre** ce que le prochain combat majeur **exige** (`GM_METHOD` §4.9 : introduction sûre → essai → échec peu coûteux → renforcement → contrainte → combinaison). Aucun dresseur de route n'est rentable à farmer (plafond souple, pas de revanche : `gRematchTable` neutralisée, §12.3).

| Ch. | Zone | Niveaux (plafond en vigueur) | Ce qu'ils enseignent | Avant quel combat | IA | Taille |
|---|---|---|---|---|---|---|
| 0–1 | R101–R104, Bois Clémenti | plafond − 6 … − 4 | types de base ; une espèce de la table de la route dans chaque équipe (la route montre ses options) ; un Fermeté à l'École | Roxanne | AI-R0 | 1–2 |
| 2 | Myokara, Grotte Granite | − 5 … − 3 | un Gonflette, un Cran, un Psy | Bastien | AI-R0 | 2 |
| 3 | R107–R109, Poivressel | − 5 … − 3 | équipes à 2 types différents ; dresseurs de la Tente qui changent de tête | Blue 1 | AI-R1 | 2–3 |
| 4 | R110, R117, Tunnel | − 4 … − 2 | Paratonnerre, paralysie ; Pokémon immunisé au Sol ; sbires Poison (Toxik) | Voltère, raid | AI-R1 | 2–3 |
| 5 | R111–R114 | − 4 … − 2 | **doubles de route** (deux par route) ; Draby de route au Site | Amaryllis | AI-R1 | 2 (×2) |
| 6 | Chemin Ardent, Mont Chimnée | − 4 … − 2 | un Chartor (soleil) ; ouvriers Magma à Intimidation | Adriane, Max | AI-R1 | 2–3 |
| 7 | R117, Vergazon | − 3 … − 1 | un Monaflèmit (Absentéisme), un Encore | Norman | AI-R1 | 3 |
| 8 | R118–R120, Cimetronelle | − 3 … − 1 | pluie (un Bekipan) ; **un Picots** puis un Tentacool de pêcheur (Tour Rapide montré) ; un Pics Toxik | Brice 3, Alizée, Koga | AI-R2 | 3 |
| 9 | R121–R122, Nénucrique, Mont Mémoria | − 3 … − 1 | Spectres **la nuit** (variante E-TOD) ; un Voile/écran ; un Exuviation | Agatha, Olga, Blue 2 | AI-R2 | 3–4 |
| 10 | R124, Algatia | − 2 … 0 | doubles à Distorsion ; Provoc ; une Illusion (Zorua) | Lévy et Tatia, Lambda | AI-R2 | 3–4 |
| 11–12 | R125–R128, Caverne Fondmer, Atalanopolis | − 2 … 0 | Buée Noire, Relais, Inconscient | Juan | AI-R2 | 4 |
| 13–14 | Route Victoire | − 1 … + 1 | une Méga par **Topdresseur** au plus ; Vulné-Assurance ; Intimidation | Blue, Ligue | AI-R2 | 4–5 |

**Couches de faction (mêmes règles, identité visible) :**
- **Sbires Rocket** (ID `TRAINER_GRUNT_*`, 53 ID vanilla) : présents **avant** les anneaux (bible §7) ; espèces Poison/Ténèbres + **arrivants capturés** (Goupilou, Chacripan) quand `RK` ≥ seuil (deux tables de sbires : RK bas, RK haut ; même ID, `Difficulty` non utilisé pour ça : on duplique 6 ID de sbires de route sélectionnés par script). AI-R1, aucun objet.
- **Brigades du Rempart** (ID de route recyclés sur leurs cartes) : **natifs seulement** (Medhyèna, Zigzaton, Nirondelle, Mangriff) ; barrages sur les routes selon `rL` ; refusables (le refus coûte `rL`, brief C).
- **Ouvriers Magma / militants Aqua** : Magma = Sol/Feu + Frison (le troupeau) ; Aqua = Eau/Ténèbres + arrivants marins libérés. AI-R1.
- **Topdresseurs** : un satellite étranger cohérent avec la zone (`ENCOUNTERS_PLAN` §10.5) ; AI-R2.

---

## 11. Interface avec les briefs A, C, D

### 11.1 Demandes au brief C (noms logiques ; C alloue les ID)
| Nom logique | Type | Lu par | Écrit par |
|---|---|---|---|
| `STARTER_RED` | var vanilla du starter (recyclée) | Brice (×5 rencontres) | ch. 0 |
| `EADAPT_TYPE` | `VAR_RESULT` après le special E-ADAPT (aucun stockage) | Blue, Peter, Giovanni | script juste avant le combat |
| `BV`, `STANCE_BLUE`, `REL_KOGA_PETER`, `STANCE_ERIKA`, `STANCE_ARTHUR`, `STANCE_PR`, `REL_ONDINE_ARTHUR`, `REL_AUGUSTE_FUJI` | déjà demandés (A §1.2, bible §11) | §5.1 | C |
| `TIMMY_SAUVE`, `OLGA_LOKHLASS`, `ONDINE_MISSION` | flags (brouillon C : D038/D064, D082, D104) | Timmy, Olga, Ondine | C |
| `Z02_ETAT` ≠ ABATTU | flags de zone (D) | Pierre (Brock) | mission des mines |
| `RK` ≥ seuil, `PA` ≥ seuil P2 | vars existantes | Ariane, Amos, sbires ; Amaryllis ch. 13 | C |
| `FLAG_CF_REFUS_*` | un par Défi qui est une décision | §4 colonne « Décision » | C ; à créer : `REFUS_OLGA`, `REFUS_AGATHA` (lus au Sommet) ; Pierre, Auguste, Erika, Ondine 1, Morgane : Défis sans flag recommandés |
| `B_SLEEP_CLAUSE TRUE` | config moteur | toutes les équipes | programmeur moteur |
| `B_VAR_NO_BAG_USE` (mode Difficile) | var | §9 | C (option) |

### 11.2 Combats à deux issues et jalons (B → C)
| Combat | Victoire écrit | Défaite écrit | Jalon (toutes issues) |
|---|---|---|---|
| Raid du Tunnel (Lance) | cargaison saisie (+ `rL`, − `RK`, C) | cargaison perdue (+ `RK`) | raid → 27 |
| Amaryllis ch. 5 | `AM` + (respect) | `AM` − ; réplique « Pas encore. » | Site Météore → 29 |
| Max (D054 b/c) | démonstration interrompue | démonstration achevée | — (badge 4 inchangé) |
| Centre Spatial (Ariane, Lambda) | Lambda démasqué devant Giovanni | la Rocket atteint le relais, Ciléo ferme le cœur | → 49 |
| Climax (Ariane, Amaryllis) | temps gagné (bible §12.2) | Rayquaza plus tôt | → 56 |
| Brice 1–3, Flora 2, Koga piège | relations (`BR`, `FL`, garde de Hoopa par D075) | idem, autre réplique | — |
**Jalons :** aucun combat refusable ne pose seul un jalon ; Blue 1 refusé : le jalon 22 est posé à la **sortie de Poivressel** (bible §8.3).

### 11.3 Reçu du brief D
Options de joueur par combat : `ENCOUNTERS_PLAN` §10.4 et `encounter_roster_v1.csv` (chapitres d'accès cités dans §7–§8). Satellites : §10.5, suivis sauf écarts listés §14.

---

## 12. Allocation des ID de dresseurs

**Principe :** un ID n'est qu'un emplacement (portrait, classe, musique, équipe se changent dans `trainers.party`). On **garde** les ID vanilla dont le rôle survit (Champions `_1`, Conseil 4, `WALLACE`, `STEVEN`), on **recycle** les autres. Les 9 ID libres (855–863) restent **en réserve** (aucun utilisé). Liste exacte ID → équipe : `docs/hack/data/teams_v3_ids.csv` (générée ; contrôle de collision automatique).

| Pool (vérifié dans `opponents.h` et `gRematchTable`) | Disponible | Utilisé | Reste | Usage |
|---|---|---|---|---|
| ID vanilla conservés (8 Champions `_1`, 4 Conseil 4, `WALLACE`, `STEVEN`) | 14 | 14 | 0 | badges, Ligue, Maître (Marc, Pierre Rochard PROTÈGE) |
| Revanches des Champions (`<CHAMPION>_2`…`_5`) | 32 | 8 (`_2` = T5) | 24 | réserve postgame |
| Rivaux (`BRENDAN_*` 15, `MAY_*` 15, `WALLY_*` 6, 2 `PLACEHOLDER`) | 38 | 36 | 2 (`WALLY_MAUVILLE`, `WALLY_VR_5`) | Brice (32), Timmy (4) |
| Admins et chefs Magma/Aqua (`MAXIE_*` 3, `TABITHA_*` 3, `ARCHIE`, `MATT`, `SHELLY_*` 2) | 10 | 10 | 0 | Max (2), Kelvin, Courtney, Lambda, Arthur (2), Sarah (2), Matthieu |
| Revanches de dresseurs (`gRematchTable`, entrées 2–5, hors Champions et Conseil 4) | 259 | 107 | **152** | Blue, Flora, Mission Indigo, Peter, Giovanni, Amaryllis, Rocket, T5, Têtes, Chen |
| Sbires `GRUNT_*` | 53 | 0 (couche de faction, §10) | 53 | sbires Rocket, ouvriers Magma, militants Aqua |
| Libres (855–863) | 9 | 0 | 9 | réserve |

**Total :** 175 équipes sur 175 ID distincts ; **zéro collision** (contrôle du générateur). Restent 152 + 24 + 2 + 53 + 9 = **240 ID**.
**Écart avec la bible §10/§14 :** la bible annonce « 324 revanches » ; le décompte vérifié est 259 (dresseurs) + 32 (Champions) = 291, les entrées du Conseil 4 dans `gRematchTable` répétant le même ID. Sans effet sur le budget.

### 12.3 Conditions techniques du recyclage
1. **Revanches désactivées** (bible §10) : les ID `_2`…`_5` ne doivent plus être atteignables par Cherche VS / Match Call. Demande au programmeur moteur : neutraliser `UpdateRematch`/`ShouldTryRematchBattle` (ou vider `gRematchTable`) ; sinon un dresseur de route `ROSE_1` relancé déclencherait `ROSE_2` = Brice T5. **Bloquant avant intégration.**
2. Chaque ID recyclé garde son **flag de dresseur** (vaincu) : aucun script vanilla ne doit lire ces flags après la réécriture (grep demandé au brief C sur `FLAG_DEFEATED`/`trainerbattle` vanilla retirés).
3. Classes et noms : noms ≤ 10 caractères (`TRAINER_NAME_LENGTH`) : « PIERRE R. », « LEVY&TATIA », « PROF. CHEN » ; classes ≤ 12 (`ENGINE_CHANGES`).
4. Partenaires (`battle_partners.party`, budget séparé) : `PARTNER_STEVEN` (recyclé : Pierre Rochard), `PARTNER_PETER_CH5`, `PARTNER_OLGA_CH9` (nouveaux) : annexe `docs/hack/data/partners_v3.party`.
5. Le 2 contre 1 (Amaryllis ch. 5) utilise `BATTLE_TWO_VS_ONE_OPPONENT` (code présent, `battle_setup.c`) ; la macro de script est à confirmer par le programmeur moteur.

---

## 13. Validation (log) et tests d'acceptation

### 13.1 Commandes exécutées (2026-10-14)
```
python3 -I docs/hack/data/teams_v3_gen.py
  dresseurs/variantes : 175 ; blocs Hard : 175 ; partenaires : 3 ; ID distincts : 175 ; Pokémon : 902
  (aucune « ERREUR équité » : niveaux ≤ plafond + 2, As ≤ plafond + 3, T5 ≤ 78, ≤ 1 Méga, aucune Méga avant le plafond 40)
python3 -I tools/qa/validate_trainers.py -f docs/hack/data/teams_v3.party --learnsets --strict-levels
  Fichiers : 1 | dresseurs : 350 | Pokémon : 1804 | erreurs : 0 | avertissements : 20
python3 -I tools/qa/validate_trainers.py -f docs/hack/data/partners_v3.party --learnsets --strict-levels
  Fichiers : 1 | dresseurs : 3 | Pokémon : 9 | erreurs : 0 | avertissements : 0
```
**Les 20 avertissements restants** sont tous du type « talents non résolus (macro) » (limite connue du validateur) pour Morphéo (Météo), Mimiqui (Fantômasque), Haydaim (Herbivore), Superdofin (Supermutation) ; **vérifiés à la main** dans `src/data/pokemon/species_info/` (`gen_3_families.h:9128`, `gen_7_families.h:5160`, `gen_5_families.h:7911`, `gen_9_families.h:4183`) : talents légaux.
Corrections faites pendant la validation : Ectoplasma Corps Maudit → Lévitation (config du dépôt), Séléroc Vaste Pouvoir → Psyko, Draco (partenaire) Attention → Mue, Zéblitz Puissance Cachée → Coup d'Jus.

**Limites (à ne pas surinterpréter) :** le validateur lit le sur-ensemble `all_learnables.json` (une capacité de CT absente du jeu passe) ; il ne vérifie ni la cohérence Méga-Gemme/espèce (vérifiée à la main : chaque gemme correspond à son porteur) ni l'ordre des jalons. **Rien n'est compilé ni testé en ROM.**

### 13.2 Garde-fous automatiques du générateur
Niveaux contre plafond ; une Méga max ; Méga après le plafond 40 ; collisions d'ID ; ≤ 6 Pokémon. Interdits retirés à la main et vérifiés par `grep` (0 occurrence) : Reflet, Lilliput, Jet de Sable, Brouillard, Vantardise, Ultrason, Puissance Cachée, attaques OHKO, Hypnose, Grobisou, Roche Royale, Griffe Rasoir ; une seule dormeuse par équipe.

### 13.3 Socle de tests pour chaque combat majeur (`STRATEGY_RESEARCH` §10)
- [ ] `validate_trainers.py --trainer <ID> --learnsets` : 0 erreur (fait, §13.1).
- [ ] Combat au plafond avec une équipe « moyenne » : ≤ 3 essais en Normal.
- [ ] Combat avec une équipe « réponse » (§7) : nettement plus facile.
- [ ] Mode Difficile sans sac.
- [ ] `B_FLAG_AI_VS_AI_BATTLE` : l'IA suit le plan de la fiche (setup au tour 1, Méga au premier tour, Relais).
- [ ] Sélecteur : chaque état lu donne l'ID attendu (§5.1) ; état absent → variante par défaut.
- [ ] Refus : flag posé, aucune EXP, dresseur ne repère plus (D1).
- [ ] Jalon posé dans toutes les issues (§11.2).

---

## 14. Conflits avec la bible et les autres briefs (à arbitrer par le GMD)

> **Arbitré** (`reviews/ARBITRATION_V3.md` §3) : C1–C6, C8, C9 acceptés ; C7 modifié (4 Défis comptés, pas de flag pour Olga ni Agatha) ; 2 contre 1 sans nouvelle macro ; E-ADAPT accepté.

| # | Conflit | Cause | Ma proposition | Coût de l'alternative |
|---|---|---|---|---|
| C1 | Bible §9.3 : Timmy « H ch. 7 (refusable) » ; brouillon C : D064 (combat contre la **brigade** au ch. 7) et D124 (Timmy à la Route Victoire, ch. 14) | deux lectures du même arc | suivre C : ch. 7 = Flora 2 (brigade), Timmy = Route Victoire (canon Timmy/Wally), avec ou sans son arrivant | garder un combat Timmy au ch. 7 : deux combats contre des enfants/brigade dans la même scène, routine |
| C2 | Koga : brouillon C met le Défi au ch. 8 (D081) juste après le piège (D075, qui peut être un combat) ; A lit `REL_KOGA_PETER` au ch. 10 | deux combats Koga dans le même chapitre ; la variante PROPRE/PIÈGES ne peut pas lire un état écrit plus tard | Défi D081 au ch. 8 avec une équipe neutre (`T-KOGA-T2-DEFI`) **et** une revanche ch. 10 (après W10) avec PROPRE/PIÈGES | supprimer la revanche ch. 10 : la position de Koga ne se lit plus en combat |
| C3 | Giovanni : A dit « rien d'importé » ; D propose Mascaïman, Hippopotas, Dunaja | identité contre écologie | « rien d'**importé** » = rien acheté par Passerelle ; ses satellites E-ADAPT (Corboss, Hippodocus, Tyranocif) sont ses Pokémon d'avant le réseau | prendre ceux de D : contredit sa réplique centrale (D127) |
| C4 | Bible §10 : Méga « une par équipe désignée » sans liste ; A : Aragon et Amaryllis ont tous deux Méga-Drattak (canon ROSA) | deux Méga-Drattak à un chapitre d'écart | Amaryllis seule au ch. 10/13 ; Aragon en T5 ; Glacia en T5 | deux fois la même Méga au climax et à la Ligue : routine |
| C5 | Bible §10 et brief : « 324 revanches » | décompte | 291 vérifiés (§12) | aucun |
| C6 | Pseudo-légendaires de PNJ avant le ch. 8 | symétrie avec D §2.2 | exception : Drackhaus (Draby, natif du Site Météore) chez Amaryllis au ch. 5 | retirer : Amaryllis sans Dragon fort au ch. 5 |
| C7 | Défis refusables sans décision dans le brouillon C (Pierre, Auguste, Erika, Ondine 1, Olga, Morgane, Agatha-rite) | brief C en cours | flags pour Olga et Agatha seulement ; les autres non comptés | 7 flags de plus pour peu de lecteurs |
| C8 | Taille : brief B vise 60–100 Ko | 22 fiches avec équipes en clair | ≈ 120 Ko ; l'annexe porte le reste | retirer les blocs Showdown des fiches (−45 Ko) : moins lisible pour le scénariste |
| C9 | Fun « environnement » = non pour Roxanne, Bastien, Norman | combats d'arène sans règle de terrain | acceptés comme tutoriels (déclarés) | ajouter un effet de terrain : coût de script, peu de gain |

---

## 15. Checklists `GM_METHOD` §6.1 et §6.2 (dresseurs/combats)

- [x] Intention en une phrase (§0) ; comportement observable (changer 1–2 membres avant un combat majeur).
- [x] Décisions du joueur identifiées : préparation, tête (D2), refus (D1), dominante face à E-ADAPT.
- [x] Économie : sources (captures, CT), puits (séries sans soin), plafond (convertisseur) ; aucune EXP rentable.
- [x] Dominance cherchée et contre-pressions (§0, §1, fiches).
- [x] Arc d'apprentissage et réponse à la routine par palier (§1).
- [x] Sémiotique 4 couches (§0).
- [x] Fiches §5.4 pour les combats clés (22) ; ≥ 2 plans de victoire chacune ; hasard faible.
- [x] Niveaux cohérents avec le plafond (contrôle automatique).
- [x] Dresseurs de route qui enseignent le prochain examen (§10).
- [x] Format Showdown validé : 0 erreur (§13.1).
- [x] Flags d'IA justifiés, jamais l'omniscience sans raison de lore (§3).
- [x] Aucune espèce/donnée/animation modifiée ; aucun Mewtwo Rocket/Giovanni ; aucun légendaire de PNJ pendant l'histoire ; Téra absent.
- [ ] Textes FR des répliques : brief A (seuls des échantillons courts ici).
- [ ] Preuves ROM : aucune (rien compilé ni joué).
- [x] Changelog de la bible : à reporter par le GMD (ligne proposée ci-dessous).

---

## 16. Changelog

| Date | Version | Changement | Auteur |
|---|---|---|---|
| 2026-10-14 | 3.0 | Création (brief B) : paliers T1–T5, IA par palier, 51 rencontres, 175 équipes + 175 Hard + 3 partenaires (générateur `teams_v3_gen.py`, validées : 0 erreur), E-ADAPT (3 paquets), politique Méga, 22 fiches, allocation de 175 ID recyclés (240 restants), conflits C1–C9. Ligne proposée pour la bible §16 : « COMBAT_DESIGN v3 livré (proposé) ». | GMD secondaire combat |
| 2026-10-14 | 3.1 | Arbitrage du GMD (`reviews/ARBITRATION_V3.md`) : Caverne Fondmer (ch. 11) ; note d'arbitrage §14 et §4 (C7) ; 2 contre 1 par suiveur partenaire (§8.6) | GMD |
