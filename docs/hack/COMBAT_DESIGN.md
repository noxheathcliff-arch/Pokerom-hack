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
| Centre Spatial | 49 | Tréfonds : Sarah, Arthur, Ondine (camp Aqua), Aldo |
| Tréfonds | 51 | Juan |
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
| 41 | 11 | Grotte Tréfonds | Sarah 2 (si elle reste) ; Ondine (camp Aqua) ; Arthur | T3 (49) | 2I / R (Ondine) | D102, D104 | Tréfonds → 51 | `T-SARAH-T3`, `T-ONDINE-T3-AQUA`, `T-ARTHUR-T3-{COUPE,NEGOCIE}` |
| 42 | 11 | Grotte Tréfonds ou Tente | Aldo (escorte) ou finale du Tournoi T3 | T3 (49) | R | — | — | `T-ALDO-T3` |
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

**C-21 Aldo** (plafond 20 ; 49 ; T5). *Identité :* le corps et l'honnêteté ; **aucun arrivant** : ses Pokémon sont venus avec lui par bateau. T1 : Onix 18, Tygnon 19, Kicklee 19, Machopeur 21. T3 (escorte de Tréfonds ou finale du Tournoi T3) : Kapoera, Kicklee (Téméraire), Tygnon (Veste de Combat), Steelix, Mackogneur 51. T5 : + Courrousinge (son Colossinge, évolué). AI-G2. *Plan :* coups physiques directs, aucune ruse. *Menaces → réponses :* Psy (Tarsal, Abra), Vol, Fée ; Intimidation (Medhyèna) ; T3 Mackogneur Cran : ne pas le brûler. *Victoire :* (1) Psy rapide ; (2) murs physiques (Galekid, Airmure).

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

**C-52 Sarah** (plafond 35 ; 49). Institut : Wailmer 33, Grahyèna 34, Sharpedo 36. Tréfonds (si elle reste) : Prédastérie (Alola), Grahyèna, Wailord, Sharpedo 50. AI-V. *Menaces → réponses :* Électrik (Dynavolt, Zéblitz), Plante.

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
