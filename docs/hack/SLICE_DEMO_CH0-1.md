# SLICE_DEMO_CH0-1 — spécification d'implémentation de la démo (prologue + chapitre 1)

> Auteur : Game Mechanics Director. Date : 2026-10-14. Périmètre fixé par l'utilisateur : **démo jouable = prologue (ch. 0) + chapitre 1**. Le reste du jeu est conçu mais mis de côté.
> Références :
> - `reviews/ARBITRATION_V3_2.md` (règles de la démo) ;
> - `DECISION_LEDGER_ACT0-1.md` (D001–D017) ;
> - `GAME_SYSTEMS.md` §2 (stockage) ;
> - `FLAGS_VARS_REGISTRY.md` (ID) ;
> - `ENGINE_CHANGES.md` §CF (macros) ;
> - `COMBAT_DESIGN.md` et `data/teams_v3.party` (équipes) ;
> - `data/encounter_roster_v1.csv` (espèces).
>
> Statut : **spécification. Rien n'est implémenté ni testé.**
>
> **Conventions :**
> - Les dialogues sont écrits “ligne 1 / ligne 2” : une paire de guillemets = **une boîte**, et « / » = le saut de ligne.
> - Toutes les boîtes ont été vérifiées à ≤ 208 px avec la police du jeu (§13).
> - Dans les scripts, utiliser ’ pour l'apostrophe et “ ” pour les guillemets, jamais « ».
> - Red ne parle jamais. Ses choix sont des **gestes**, présentés par un menu (`dynmultichoice`), avec des libellés courts.
> - **Narr.** = boîte sans locuteur (narration).

---

## 0. Prérequis moteur

| Code | Besoin | État |
|---|---|---|
| **E-CLEARPARTY** | `clearparty` : vider l'équipe, sans garde « dernier Pokémon ». Nécessaire parce que l'anneau du prologue emporte **toute** l'équipe (`removepartymon` refuse de retirer le dernier Pokémon) | **à faire** : quelques lignes, ROM seulement (`ZeroPlayerPartyMons` + recompte) |
| **SPAWN** | La nouvelle partie démarre sur la plage de la Route 104, sans camion ni Maman. Modifier la destination de départ dans `src/new_game.c` (aujourd'hui le camion de Bourg-en-Vol) | **à faire** |
| Décisions, bits, plafond | `setdecision_once`, `checkdecision`, `getbits` / `setbits`, `raisecap` | fait (CF-2, CF-3) |
| Relations, réputations | `addaffinity` / `subaffinity` sur `VAR_CF_*` | fait (E) |
| Combats refusables | `trainerbattle_single_declinable` | fait (D1) |
| Pokémon de tête | `FLAG_CHOOSE_BATTLE_LEAD` | fait (D2) |
| Écosystèmes, nuit | E-ECO, E-TOD | faits (CF-6) |
| Suiveur | `setfollowernpc` (Brice) | vanilla de l'expansion |
| Défaite sans K.O. | `FLAG_CF_NO_WHITEOUT` | branché |

---

## 1. Ordre des scènes (chemin critique)

| # | Scène | Carte | Décisions | Plafond |
|---|---|---|---|---|
| P1 | La plage : force, puis perte | `MAP_ROUTE104` (sud) | D001 | 14 |
| P2 | Chez M. Marco | `MAP_ROUTE104_MR_BRINEYS_HOUSE` (+ `MAP_PETALBURG_CITY` si D006 b) | D006 | 14 |
| P3 | Le labo de Seko, la nuit | `MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB` | D004 (non comptée), D002, D005 | 14 |
| P4 | La ronde de Brice | `MAP_ROUTE101` | D003 | 14 |
| P5 | Matin chez les Seko | `MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F` | — | 14 |
| P6 | Duel et Zigzaton de Galar | `MAP_ROUTE103` | D007 | 14 |
| C1 | QG du Rempart | `MAP_PETALBURG_CITY_GYM` (salle d'entrée) | D017 | 14 |
| C2 | Barrage du Bois | `MAP_ROUTE104` (entrées sud du Bois) | — (lit D002, D005, D017, D003) | 14 |
| C3 | Flora au Bois | `MAP_PETALBURG_WOODS` | D008 | 14 |
| C4 | L'affiche | `MAP_RUSTBORO_CITY` (entrée sud) | D009 | 14 |
| C5 | « Ferrand » | `MAP_RUSTBORO_CITY_DEVON_CORP_2F` | D013 | 14 |
| C6 | Présentation de Passerelle | `MAP_RUSTBORO_CITY_DEVON_CORP_3F` | D011 | 14 |
| C7 | Le petit voleur | `MAP_RUSTBORO_CITY` (sortie de Devon) | D012 | 14 |
| C8 | Les mines | `MAP_RUSTURF_TUNNEL` (partie ouest) | D010 | 14 |
| C9 | Roxanne | `MAP_RUSTBORO_CITY_GYM` | D016 | 14 → **18** |
| C10 | Contrebandiers de la R116 | `MAP_ROUTE116` | D014, D015 | 18 |
| C11 | Fin de la démo | `MAP_RUSTBORO_CITY_POKEMON_CENTER_1F` | — (lit tout) | 18 |

**Portes d'ordre :**
- l'arène de Mérouville est fermée tant que D010 n'est pas prise (Roxanne est aux mines) ;
- la scène C10 exige `FLAG_BADGE01_GET` ;
- C11 exige D014 prise ;
- les étapes C4 → C7 se suivent dans l'ordre indiqué, par des déclencheurs à état.

`VAR_CF_CHAPTER` : 0 au départ ; **1** à la fin de P6 ; **2** à la fin de C11, ce qui marque la fin de la démo.

---

## 2. État initial (nouvelle partie de démo)

À appeler en plus de `CF_InitNewGameVars()`, dans un script `CF_Demo_NewGame` lancé au premier chargement de la plage :

- **Position :** `MAP_ROUTE104`, plage sud près du ponton de M. Marco. Le joueur est en (13, 57), tourné vers le haut. Coordonnée **à valider dans Porymap** : une tuile de sable libre au sud du ponton (12, 51–54).
- `setflag FLAG_NO_WILD_ENCOUNTERS` (levé à la fin de P4).
- Équipe du prologue (`givemon` ; dresseur Red ; aucune Ball dans le sac). Les niveaux restent sous le canon HGSS (88), qui serait illisible ici :

| Pokémon | Niv. | Attaques |
|---|---|---|
| Pikachu (Balle Lumière) | 62 | Tonnerre, Vive-Attaque, Queue de Fer, Fatal-Foudre |
| Dracaufeu | 64 | Lance-Flammes, Lame d'Air, Dracochoc, Exploforce |
| Florizarre | 64 | Tempête Verte, Bomb-Beurk, Poudre Dodo, Synthèse |
| Tortank | 64 | Hydrocanon, Blizzard, Luminocanon, Exploforce |
| Ronflex | 63 | Plaquage, Repos, Ronflement, Mâchouille |
| Lokhlass | 62 | Surf, Laser Glace, Psyko, Chant |

- Argent : 3 000 ₽. Plafond : `VAR_CF_CAP` = 14 (déjà posé par `CF_InitNewGameVars`).
- Visibilité au départ :
  - masqués : tous les PNJ nouveaux de la démo (§6) ; les dresseurs des Routes 102, 103 et 104 jusqu'à `VAR_CF_CHAPTER` ≥ 1 (aucun combat sans Pokémon) ;
  - visible : M. Marco (Briney) **dans sa maison**.

---

## 3. Acteurs de la démo (graphismes et positions)

Les positions sont celles des objets vanilla réutilisés quand ils existent. Une position marquée ◐ est **à valider dans Porymap** (tuile libre, chemin praticable).

| Acteur | `OBJ_EVENT_GFX_*` | Où (carte : x, y) | Visibilité |
|---|---|---|---|
| M. Marco | `EXPERT_M` | plage R104 (12, 55) ◐ ; maison (5, 3) (objet vanilla) | `FLAG_CF_VIS_00` (plage) ; maison : vanilla, flag effacé |
| Ciléo | `CELIO` | plage (14, 56) ◐ ; maison (4, 5) ◐ ; QG (6, 103) ◐ ; Devon 3F (13, 7) ◐ | `VIS_01` à `VIS_04` |
| Seko | `PROF_BIRCH` | labo (6, 4) (vanilla) | vanilla |
| Pikachu blessé | `SPECIES(PIKACHU)` | labo (9, 4) ◐ | `VIS_05`, si `VAR_CF_WORLD` b14-15 = 1 |
| Brice | `RIVAL_BRENDAN_NORMAL` | R101 (10, 13) ; R103 (10, 3) (vanilla rival) ; suiveur au ch. 1 | `VIS_06`, `VIS_07` ; suiveur |
| Arrivants de la R101 | `SPECIES(SPEAROW)`, `SPECIES(NIDORAN_M)`, `SPECIES(DIGLETT)` | (9, 12), (11, 12), (10, 14) ◐ | `VIS_08` |
| Mme Seko | `WOMAN_4` | maison 1F (2, 7) (objet vanilla « mère du rival ») | vanilla, réécrit |
| Brigadier (R103, barrages, QG, R116) | `POLICEMAN` | R103 (12, 5) ◐ ; R104 aux entrées du Bois ◐ ; QG (5, 106) ◐ ; R116 (38, 10) ◐ ; murs §7 | `VIS_09` à `VIS_15` |
| Zigzaton de Galar | `SPECIES(ZIGZAGOON_GALAR)` | R103 (11, 4) ◐ | `VIS_16` |
| Norman | `NORMAN` | QG (4, 103) ◐ | `VIS_17` |
| Flora | `RIVAL_MAY_NORMAL` | QG (3, 104) ◐ ; Bois (26, 17) (place de l'Aqua vanilla) ; R116 (scène) | `VIS_18` à `VIS_20` |
| Coach | `YOUNGSTER` | Centre de Clémenti (9, 6) (objet vanilla réécrit) | toujours |
| Brigade du Bois ×2 | `POLICEMAN` | (25, 18), (27, 18) ◐ | `VIS_21` |
| Arrivants du Bois | `SPECIES(WOOLOO)`, `SPECIES(YAMPER)`, `SPECIES(APPLIN)` | (26, 20), (27, 20), (25, 20) ◐ ; s'ils sont sauvés : (33, 6), (34, 6), (32, 6) ◐ | `VIS_22` (scène), `VIS_23` (sauvés) |
| Passante (affiche) | `WOMAN_5` | Mérouville (17, 52) ◐ | `VIS_24` |
| « Ferrand » | `SCIENTIST_1` | Devon 2F (10, 5) (objet vanilla réécrit) ; R116 (43, 8) ◐ | toujours (2F) ; `VIS_25` (R116) |
| M. Rochard | `GENTLEMAN` | Devon 3F (17, 5) (vanilla) | vanilla |
| Président de Sylphe | `GENTLEMAN` | Devon 3F (15, 5) (2e objet vanilla) | vanilla |
| Léo | `BILL` | Devon 3F (12, 6) ◐ | `VIS_26` |
| Lanette | `WOMAN_2` | Devon 3F (10, 6) ◐ | `VIS_27` |
| Petit voleur (Hoopa) | `SPECIES(HOOPA)` | Mérouville (14, 18) ◐ ; Centre de Mérouville, fenêtre (2, 2) ◐ ; R116 (48, 7) ◐ | `VIS_28` à `VIS_30` |
| Roxanne | `ROXANNE` | mines (10, 5) ◐ ; arène (5, 2) (vanilla) | `VIS_31` (mines) |
| Pierre (Brock) | `BROCK` | mines (12, 4) ◐, reste après D010 | `VIS_32` |
| Mineurs ×2 | `HIKER` | mines (8, 6), (9, 4) ◐ | `VIS_33` |
| Charbi et Strassie | `SPECIES(ROLYCOLY)`, `SPECIES(CARBINK)` | mines (14, 5), (15, 4) ◐ | `VIS_34` |
| Lance (Rocket) | `ROCKET_M` | R116 (44, 10) ◐ | `VIS_35` |
| Sbire A | `ROCKET_M` | R116 (45, 9) ◐ | `VIS_36` |
| Sbire B (ex-mineur) | `ROCKET_F` (repli `ROCKET_M`) | R116 (45, 11) ◐ | `VIS_37` |
| Ex-mineur rentré | `HIKER` | Mérouville (13, 33) ◐ | `VIS_38`, si D015 a |

Les flags de visibilité `FLAG_CF_VIS_00`…`VIS_38` sont pris dans la plage réservée (`FLAGS_VARS_REGISTRY` : `VIS_00..92`) et sont à inscrire au registre.

---

## 4. Scènes et dialogues

### P1 — La plage (D001)
**Déclencheur :** script de chargement de `MAP_ROUTE104` si `VAR_CF_CHAPTER` = 0 et D001 non prise (`checkdecision 1` = 0). Joueur bloqué. M. Marco (12, 55) et Ciléo (14, 56) visibles.

- Narr. “Nuit. Route 104, côte sud / de Hoenn. Les ports sont fermés.”
- **Marco** “On y est. Pas de lumière, / pas de bruit, d’accord ?”
- **Marco** “Si la brigade vous trouve, moi, / je vous ai jamais vus.”
- **Ciléo** “Merci, monsieur Marco. Red, / tu as tout ? Tes six Balls ?”
- **Ciléo** “Les gemmes que tu m’as rapportées / stabilisent mon nœud. Tu te rappelles ?”
- **Ciléo** “Ma machine relie Kanto et Hoenn. / Elle n’ouvre rien du tout.”
- **Ciléo** “Je dois le prouver à leur Ligue. / Avant qu’ils nous accusent de tout.”
- **Marco** “Chut ! Regardez la mer…”
- Narr. “Un cercle d’or s’ouvre au-dessus / de l’eau. Il en tombe des formes.”
- Narr. “Des Pokémon. Affolés, ils / chargent la plage.”
- **Ciléo** “Des Pokémon de chez nous ! / Red, protège-nous !”

Combats sauvages scriptés (`setwildbattle` + `dowildbattle`, `FLAG_CF_NO_WHITEOUT` posé ; aucune Ball, donc aucune capture possible) : **Tauros 42**, puis **Ursaring 43**, puis **Léviator 45**.
- Entre le 1er et le 2e : Narr. “D’autres arrivent. L’anneau ne / se referme pas.”
- Après le 3e : **Marco** “Ils fuient… Petit, t’as une / sacrée équipe.”

Puis :
- Narr. “Le sable s’illumine sous les pieds / de Red. Un second cercle.”
- Narr. “Les Balls glissent de sa ceinture. / Il ne peut rattraper qu’une chose.”
- **Ciléo** “Mon sac ! Le disque du nœud ! / Red !”

**D001** — menu (geste « tendre la main vers… ») : “Pikachu” · “Le sac de Ciléo”

- **a**
  - Narr. “Pikachu saute. Red le saisit / au vol. L’anneau avale le reste.”
  - Narr. “Pikachu a heurté les rochers. / Il respire, mais ne bouge plus.”
  - **Ciléo** “Mon disque… Tant pis. Il est / vivant, c’est le principal.”
  - États : `setdecision_once 1, DEC_A` ; `setbits VAR_CF_WORLD, 14, 2, 1` (Pikachu blessé) ; `subaffinity VAR_CF_REP_I, 3`.
- **b**
  - Narr. “Red attrape le sac. Pikachu / bondit vers lui, trop tard.”
  - Narr. “Le cercle se ferme. Il ne reste / qu’une plage vide.”
  - **Ciléo** “Red… Je suis désolé. Ton / équipe… Pikachu…”
  - États : `setdecision_once 1, DEC_B` ; `setflag FLAG_CF_DOS_JOURNAL_NOEUD` ; `addaffinity VAR_CF_REP_I, 5` ; `subaffinity VAR_CF_REP_C, 3`.
- **Commun**
  - `clearparty` (E-CLEARPARTY) ; `clearflag FLAG_CF_NO_WHITEOUT`.
  - **Marco** “Venez chez moi, vite. La brigade / fait sa ronde à l’aube.”
  - Fondu, puis warp vers la maison de M. Marco (5, 7).

### P2 — Chez M. Marco (D006)
**Déclencheur :** script de chargement si D006 non prise. Marco (5, 3), Ciléo (4, 5) ◐. Piko masqué (`FLAG_HIDE_BRINEYS_HOUSE_PEEKO` posé).

- **Marco** “Asseyez-vous. Y a du thé, / et y a pas de questions.”
- **Marco** “Moi aussi, un anneau m’a pris / quelqu’un. Piko, ma Goélise.”
- **Marco** “C’était il y a huit jours, sur le / ponton. Un cercle d’or, et plus rien.”
- **Ciléo** “Je dois aller à Clémenti cette / nuit. Me déclarer à leur QG.”
- **Ciléo** “Si j’attends, ils diront que les / Kantonais se cachent.”
- **Marco** “Et toi, petit ? Tu restes ici, / ou tu suis ton ami ?”

**D006** — menu : “Rester” · “Suivre Ciléo”

- **a**
  - **Marco** “Bon choix. Tiens, la clochette / de Piko. Garde-la pour moi.”
  - **Marco** “Si tu croises un cercle d’or, / écoute bien. Elle tintait toujours.”
  - **Ciléo** “Alors j’y vais seul. On se / retrouve à Clémenti.”
  - États : `setdecision_once 6, DEC_A` ; `setflag FLAG_CF_DOS_CLOCHETTE_PIKO` ; `setflag FLAG_CF_MARCO_ALLIE` ; `subaffinity VAR_CF_REP_L, 2`.
- **b**
  - **Ciléo** “Merci. À deux, on aura l’air / moins louches. Enfin, j’espère.”
  - Mini-scène sur `MAP_PETALBURG_CITY`, entrée ouest (2, 11) ◐ : fondu, le joueur, Ciléo et un brigadier.
  - **Brigadier** “Halte. Couvre-feu. Vos noms, / et ce que vous faites dehors.”
  - **Ciléo** “Ciléo, ingénieur de Kanto. / Je viens me déclarer.”
  - **Brigadier** “Un Kantonais qui vient tout seul ? / Ça, c’est nouveau. Passez.”
  - États : `setdecision_once 6, DEC_B` ; `addaffinity VAR_CF_REP_I, 2`.
- **Commun**
  - **Marco** “Le professeur Seko, à Bourg-en-Vol, / soigne les blessés.”
  - **Marco** “Bêtes ou gens. Dis-lui que tu / viens de ma part.”
  - Narr. “Une heure de marche plus tard, / Bourg-en-Vol dort encore.”
  - Warp vers le labo (6, 11). Le trajet n'est pas joué : aucun dresseur, aucun sauvage.

### P3 — Le labo de Seko (D004, difficulté, D002, D005)
**Déclencheur :** script de chargement du labo si D002 non prise. Seko (6, 4). L'assistant (9, 8). Pikachu blessé visible si Pikachu = 1.

- **Seko** “Un visiteur à cette heure ? / Marco t’envoie, c’est ça ?”
- **Seko** “Je suis Seko. J’étudie où vivent / les Pokémon. Où ils vivaient.”
- Si Pikachu = 1 :
  - **Seko** “Ton Pikachu… Pose-le là. Côtes / fêlées. Il lui faut du repos.”
  - **Seko** “Plusieurs semaines. Il reste / ici, je m’en occupe.”
- Si Pikachu = 0 : **Seko** “Ton équipe entière, aspirée ? / Je suis désolé, petit.”
- **Seko** “Sans Pokémon, tu ne passeras / pas la nuit. Pas avec ce qui rôde.”
- **Seko** “Ces trois-là sont nés à Hoenn. / Choisis celui qui te ressemble.”

**D004** (non comptée) — menu : “Arcko” · “Poussifeu” · “Gobou”
- `givemon SPECIES_TREECKO|TORCHIC|MUDKIP, 5` ; `setdecision_once 4, DEC_A|B|C`.

Suite :
- **Seko** “Prends aussi ça. Et mon Pokédex : / note tout. Surtout ce qui vient d’ailleurs.”
- Objets : Pokédex (`setflag FLAG_SYS_POKEDEX_GET`), 5 Poké Balls, 1 Baie Oran.
- **Seko** “Une question de méthode. Tu veux / des combats durs, ou normaux ?”
- Menu (non compté) : “Normaux” · “Durs” → `setdifficulty DIFFICULTY_NORMAL|HARD`.
- **Assistant** “Professeur ! Le QG du Rempart, / au téléphone. C’est Norman.”
- **Seko** “Norman dirige le Rempart. Il veut / savoir qui débarque la nuit.”
- Narr. “Seko tend le combiné à Red.” (Scène scriptée au téléphone du labo, sans Match Call.)
- **Norman** “Un étranger sans papiers sur ma / côte. Votre nom.”

**D002** — menu : “Donner son nom” · “Rester anonyme”

- **a**
  - Narr. “Red écrit son nom sur le registre. / Seko le lit au téléphone.”
  - **Norman** “Red. Le champion de Kanto. / Bien.”
  - **Norman** “Accréditation de crise, niveau un. / Vous combattrez les hordes.”
  - **Norman** “Un faux pas, et vous repartez / en cale. Avec votre nom dessus.”
  - États : `setdecision_once 2, DEC_A` ; `setbits VAR_CF_WORLD, 0, 2, 2` (N = 2) ; `addaffinity VAR_CF_REP_L, 3` ; `addaffinity VAR_CF_RK, 3`.
- **b**
  - **Seko** “Il ne dira rien. Mon fils l’appellera / le Passeur, je parie.”
  - **Norman** “Anonyme ? Alors accréditation / provisoire. Sous garant.”
  - **Norman** “Mon QG, demain matin. Sinon, / la cale.”
  - États : `setdecision_once 2, DEC_B` ; N = 0 ; `subaffinity VAR_CF_REP_L, 3` ; `addaffinity VAR_CF_BR, 2`.

Puis :
- **Seko** “Ceci est arrivé pour toi par / Passerelle. Ça vient de Kanto.”
- Narr. “Une lettre du Prof. Chen : / ‘Envoie-moi tout. Avant Seko.’”

**D005** — menu : “Montrer la lettre” · “La garder”

- **a**
  - **Seko** “‘Avant Seko’… Ce vieux renard / de Chen.”
  - **Seko** “Tant pis pour lui. Mon registre / est à toi. Mon fils aussi.”
  - **Seko** “Demain, Brice t’accompagne. Il / connaît chaque barrage.”
  - États : `setdecision_once 5, DEC_A` ; `setflag FLAG_CF_CHEN_LETTRE_MONTREE` ; `addaffinity VAR_CF_BR, 2`. **Effet dans la démo : Brice devient suiveur dès P6.**
- **b**
  - Narr. “Red range la lettre. Seko fait / semblant de ne rien voir.”
  - **Seko** “Brice finira son recensement ici / demain. Il te rejoindra plus tard.”
  - États : `setdecision_once 5, DEC_B` ; `subaffinity VAR_CF_BR, 2`. **Effet dans la démo : Brice absent de C1 à C5 ; il rejoint en C6.**
- **Commun**
  - **Seko** “Mon fils est encore dehors, sur / la Route 101. Tu me le ramènes ?”
  - Seko soigne l'équipe (`special HealPlayerParty`) à chaque fois qu'on lui parle, pendant toute la démo.

### P4 — La ronde de Brice (D003)
**Déclencheur :** tuiles (10, 18) et (11, 18) de `MAP_ROUTE101`. Ce sont les tuiles vanilla « PreventExitSouth », dont le script vanilla est neutralisé. Brice (10, 13). Trois arrivants autour de lui.

- **Brice** “Six… sept… Et un Piafabec. / Non, deux !”
- **Brice** “Hé, vous trois ! Je vous recense, / je vous mange pas !”
- Narr. “Les arrivants grognent. Ils / encerclent Brice.”

**D003** — menu : “Intervenir” · “Rester et observer”

- **a**
  - Combat sauvage scripté : Piafabec niv. 5.
  - **Brice** “Merci ! Tu es tombé du ciel ? / Je suis Brice. Le fils de Seko.”
  - États : `setdecision_once 3, DEC_A` ; `addaffinity VAR_CF_BR, 3` ; `subaffinity VAR_CF_HO, 1` ; `VAR_CF_BVCOUNT` PROT + 1 (`getbits` puis `setbits` b0-3).
- **b**
  - Narr. “Red ne bouge pas. Les arrivants / fuient tous vers le même point.”
  - Narr. “Vers la plage, là où le ciel / brillait une heure plus tôt.”
  - **Brice** “Aïe ! Il m’a griffé… Tu aurais / pu m’aider, toi !”
  - **Brice** “…Attends. Ils fuient tous vers / la mer. Je le note.”
  - États : `setdecision_once 3, DEC_B` ; `subaffinity VAR_CF_BR, 3` ; BVCOUNT COMP + 1 (b8-11).
- **Commun**
  - **Brice** “Tu dors chez nous ce soir. / Maman a toujours un lit en trop.”
  - `clearflag FLAG_NO_WILD_ENCOUNTERS`. Fondu, puis warp vers la maison des Seko, 2F (lit).

### P5 — Matin chez les Seko
Mme Seko (2, 7) :
- “Bonjour ! Brice m’a tout raconté. / Enfin, sa version.”
- “Tiens, des Chaussures de Course. / Par ici, on court beaucoup.”

Effets : Chaussures de Course (vanilla `FLAG_RECEIVED_RUNNING_SHOES`). Le lit des Seko soigne (comme le lit vanilla de la maison du joueur).

**Brice** (sortie de la maison) “Je pars devant, Route 103. / Un duel d’essai, ça te dit ?”

### P6 — Route 103 : duel et Zigzaton de Galar (D007)
**Duel.** Brice (10, 3). Combat à deux issues : `FLAG_CF_NO_WHITEOUT` posé avant, effacé après, puis soin scripté.

Avant le combat, selon D003 :
- a : “Le héros d’hier soir ! Voyons / si tu es aussi bon de jour.”
- b : “Celui qui regarde sans bouger ! / Voyons si tu sais te battre.”

Équipe selon le starter :

| Starter de Red | Équipe de Brice |
|---|---|
| Arcko | `TRAINER_BRENDAN_ROUTE_103_TORCHIC` (`T-BRICE-T1-R103-T`) |
| Poussifeu | `TRAINER_BRENDAN_ROUTE_103_MUDKIP` |
| Gobou | `TRAINER_BRENDAN_ROUTE_103_TREECKO` |

Après le combat :
- victoire : “Joli ! Je note : Red, très fort, / ne parle pas.”
- défaite : “Ha ! Pas mal quand même. Je note : / Red, à entraîner.”

**Zigzaton de Galar.** Un Zigzaton de Galar (11, 4) sort des herbes, puis un brigadier arrive (12, 5).
- Narr. “Un Zigzaton pas comme les autres / sort des herbes. Il boite.”
- **Brice** “Noir et blanc… Un Zigzaton de / Galar ! Il n’a rien à faire ici.”
- **Brigadier** “Brigade du Rempart. On ramasse / les arrivants blessés. Écartez-vous.”

**D007** — menu : “Le capturer” · “Le laisser”

- **a**
  - `givemon SPECIES_ZIGZAGOON_GALAR, 5`.
  - **Brigadier** “Hé ! C’est un arrivant. Vous devrez / le déclarer au QG.”
  - **Brice** “On le déclare ou pas ? …Moi, / je n’ai rien vu.”
  - États : `setdecision_once 7, DEC_A` ; `subaffinity VAR_CF_REP_L, 2` ; BVCOUNT ACC + 1 (b4-7).
- **b**
  - **Brigadier** “Merci. Il sera soigné. Enfin… / on verra.”
  - **Brice** “Je note son numéro. Je veux savoir / ce qu’il devient.”
  - États : `setdecision_once 7, DEC_B` ; `addaffinity VAR_CF_REP_L, 2` ; BVCOUNT PROT + 1.

**Fin du prologue :**
- `setvar VAR_CF_CHAPTER, 1` ; afficher les dresseurs des Routes 102–104 ; `setvar VAR_OLDALE_TOWN_STATE, 1` (le chemin ouest d'Rosyères s'ouvre).
- Si D005 a : **Brice** “Direction Clémenti. Le QG de Norman, / c’est l’ancienne arène.” Puis `setfollowernpc` Brice.
- Si D005 b : **Brice** “Mon père veut que je finisse ici. / Je te rejoins à Mérouville !”

### C1 — QG du Rempart (D017)
**Déclencheur :** entrée dans `MAP_PETALBURG_CITY_GYM` avec D017 non prise. Salle d'entrée : Norman (4, 103), Flora (3, 104), brigadier (5, 106). Ciléo (6, 103), seulement si D006 a.

- **Norman** “Red. Le Rempart a une règle : / ici, rien ne passe sans contrôle.”
- Selon D002 :
  - a : **Norman** “Votre nom est sur ma liste. Ne / me faites pas regretter de l’y avoir.”
  - b : **Norman** “Le Passeur, hein ? Mon registre / déteste les surnoms.”
- Si D006 a :
  - **Norman** “Votre ingénieur a dormi ici. / Il réclamait un avocat.”
  - **Ciléo** “Red ! Dis-leur que je suis venu / de moi-même !”
  - **Norman** “Il peut partir. Sous votre / responsabilité.”
  - Ciléo, selon D001 : a “Sans mon disque, je n’ai que ma / parole. Ici, ça ne vaut rien.” ; b “Mon disque prouve l’heure de chaque / transfert. Ils vont voir.”
- **Flora** “Flora, cadette de la brigade. / Et la fille de ce monsieur.”
- Flora, selon D007 :
  - a : **Flora** “Il paraît que tu as gardé un / arrivant. Déclaré, j’espère ?”
  - b : **Flora** “Merci pour le Zigzaton d’hier. / Il est au chaud.”
- **Norman** “Nos barrages ferment les routes. / Ceci vous les ouvre.”
- Narr. “Norman tend un insigne du / Rempart.”

**D017** — menu : “Accepter l’insigne” · “Refuser”

- **a**
  - **Norman** “Portez-le bien en vue. Les gens / sauront de quel côté vous êtes.”
  - États : `setdecision_once 17, DEC_A` ; `setflag FLAG_CF_INSIGNE` ; `addaffinity VAR_CF_REP_L, 3` ; `subaffinity VAR_CF_REP_A, 3`.
- **b**
  - **Norman** “À votre guise. Chaque barrage / vous demandera un garant.”
  - États : `setdecision_once 17, DEC_B` ; `subaffinity VAR_CF_REP_L, 2` ; `addaffinity VAR_CF_REP_A, 1`.
- **Commun**
  - **Norman** “Flora part au Bois Clémenti. Une / horde y niche. Allez voir.”
  - Les portes intérieures de la salle d'entrée sont gardées par deux brigadiers (mur §7).

**Coach** (Centre de Clémenti, (9, 6)) :
- “Moi, j’entraîne. Tu veux choisir ton / Pokémon de tête avant un duel ?”
- Menu Oui / Non → `setflag` / `clearflag FLAG_CHOOSE_BATTLE_LEAD`.
- “C’est noté. Reviens me voir pour / changer d’avis.”

### C2 — Barrage du Bois (lit D002, D017, D005, D003)
**Déclencheur :** tuiles devant les deux entrées sud du Bois sur `MAP_ROUTE104`, soit (10–11, 39) et (32–33, 43) ◐. Un brigadier se place devant le joueur. Le barrage disparaît après le premier passage (`VIS_10` posé).

- **Brigadier** “Barrage du Rempart. Le Bois est / fermé aux civils.”

Puis, la **première** condition vraie :
1. `FLAG_CF_INSIGNE` → **Brigadier** “L’insigne. Passez, monsieur.”
2. N ≥ 1 (D002 a) → **Brigadier** “Red, de Kanto ? Le chef vous a / inscrit. Passez.”
3. Brice suiveur et `VAR_CF_BR` ≥ 50 :
   - **Brice** “Il est avec moi. Mon père s’en / porte garant.”
   - **Brigadier** “Le fils de Seko… Bon. Passez.”
4. Sinon (repli, aucun blocage définitif) :
   - **Brigadier** “Pas d’insigne, pas de garant ? / Alors vous attendez.”
   - **Flora** “Laisse, je l’emmène. Sous escorte. / Tu me suis, Red.”
   - Flora entre la première dans le Bois.

### C3 — Flora au Bois (D008)
**Déclencheur :** tuiles (26–27, 23) de `MAP_PETALBURG_WOODS`. Ce sont les tuiles vanilla du chercheur de Devon, neutralisées. Flora (26, 17), deux brigadiers, trois arrivants.

- **Flora** “Trois arrivants de Galar. Ils / pillent les nids des Nirondelle.”
- **Flora** “Ordre du Rempart : on les abat. / Rien de personnel.”
- Si Brice est présent : **Brice** “Les abattre ? Ils sont juste / perdus, Flora !”
- Narr. “Red s’avance entre la brigade et / les arrivants.”
- **Flora** “Tu veux les protéger ? Alors / prouve-le. En duel.”

**D008** — combat refusable :
```
trainerbattle_single_declinable TRAINER_BROOKE_4, Text_FloraIntro, Text_FloraDefaite, FLAG_CF_REFUS_FLORA1, CF_D008_Refus
```
- Équipe `T-FLORA-T1` : Zigzaton 11, Medhyèna 12, Nirondelle 14.
- `FLAG_CF_NO_WHITEOUT` posé avant le combat.
- Texte de défaite de Flora : “D’accord, d’accord ! Tu as gagné.”

Issues :
- **a, victoire**
  - **Flora** “Ils filent. Mon père va adorer / mon rapport.”
  - **Brice**, ou Narr. s'il est absent : “Flora s’en souviendra. Moi aussi.”
  - États : `setdecision_once 8, DEC_A` ; `subaffinity VAR_CF_FL, 3` ; `subaffinity VAR_CF_REP_L, 3` ; `setflag FLAG_CF_BOIS_SAUVES`.
  - Les arrivants réapparaissent en (32–34, 6) : Moumouton, au contact : “Moumouton bêle doucement.”
- **b, défaite**
  - **Flora** “Au moins, tu t’es battu. Frais de / brigade : 300 Pokédollars.”
  - États : `setdecision_once 8, DEC_B` ; `addaffinity VAR_CF_FL, 2` ; `addaffinity VAR_CF_REP_L, 1` ; argent − 300 (ou tout l'argent si moins de 300). Arrivants emmenés (masqués).
- **c, refus** (`CF_D008_Refus`)
  - **Brice**, ou Narr. : “On les laisse faire ?”
  - **Flora** “Sage décision. Je te salue, Red.”
  - États : `setdecision_once 8, DEC_C` ; `addaffinity VAR_CF_FL, 3` ; `subaffinity VAR_CF_BR, 2`. Arrivants emmenés.

### C4 — L'affiche (D009)
**Déclencheur :** rangée (12–19, 53) de `MAP_RUSTBORO_CITY`. Ce sont les tuiles vanilla du rival, neutralisées. Condition : D009 non prise. Affiche = événement de décor en (16, 52) ◐.

- Narr. “Une affiche : ‘Il a sauvé Sylphe. / Sylphe relie le monde.’”
- Narr. “‘Passerelle, depuis cinq mois.’ / Un garçon de dos, casquette rouge.”
- Si Brice est présent : **Brice** “…C’est toi. Sur l’affiche, / c’est toi.”
- Sinon : **Passante** “Vous ressemblez au garçon de / l’affiche. Celui de Kanto.”

**D009** — menu : “Rester devant” · “Partir”

- **a**
  - Narr. “Un passant prend une photo. Red / ne bouge pas.”
  - Si Brice est présent : **Brice** “Un contrat, je parie. Signé contre / la Master Ball, à onze ans.”
  - États : `setdecision_once 9, DEC_A` ; `setflag FLAG_CF_DOS_AFFICHE_SYLPHE` ; `addaffinity VAR_CF_BR, 2` ; `addaffinity VAR_CF_RK, 2` ; N + 1 (borné à 3).
- **b**
  - **Brice**, ou Narr. : “C’était toi ? …Pas de réponse. / D’accord.”
  - États : `setdecision_once 9, DEC_B` ; `subaffinity VAR_CF_BR, 1`.

### C5 — « Ferrand » (D013)
**Déclencheur :** parler à l'ingénieur de Devon 2F, en (10, 5).

- **Ferrand** “Le célèbre Red ! Ferrand, ingénieur / Passerelle. Enchanté.”
- **Ferrand** “Le Rubis et le Saphir… Vous les / avez tenus longtemps ?”

**D013** — menu : “Le laisser parler” · “Partir”

- **a**
  - **Ferrand** “Fascinant. Et vous logez où, / ces jours-ci ? Pure curiosité.”
  - Narr. “Ferrand note quelque chose, puis / fredonne un air léger.”
  - Si Brice est présent : **Brice** “Il parle comme un vendeur, ton / ingénieur.”
  - États : `setdecision_once 13, DEC_A` ; `setflag FLAG_CF_LAMBDA_REMARQUE` ; `addaffinity VAR_CF_RK, 3`.
- **b**
  - Narr. “Ferrand vous regarde partir.”
  - États : `setdecision_once 13, DEC_B` ; `subaffinity VAR_CF_BR, 1`.

### C6 — Présentation de Passerelle (D011)
**Déclencheur :** entrée à Devon 3F avec D011 non prise. M. Rochard (17, 5), le Président (15, 5), Léo (12, 6), Lanette (10, 6), Ciléo (13, 7).

- **M. Rochard** “Bienvenue chez Devon ! Voici / Passerelle : le monde en une seconde.”
- **Président** “Sylphe fournit le Cœur, Devon le / réseau. Une belle alliance.”
- **Léo** “J’ai écrit la couche de transfert. / Elle marche. Trop bien, même.”
- **Lanette** “Mes boîtes stockent tout. Et je / tiens des journaux. De tout.”
- **Ciléo**, selon D001 :
  - a : “J’avais un disque. Un anneau / l’a pris. Comme par hasard.”
  - b : “Mon disque dit que mon nœud est / propre. Je le prouverai.”
- **Président**, selon D009 :
  - a : “Red ! Vous avez vu l’affiche ? / Vous étiez si… vendeur.”
  - b : “Vous ne vous êtes pas reconnu ? / Sur l’affiche, en bas ?”
- **Président** “Une photo avec moi, près du / Kiosque ? Pour la presse.”

**D011** — menu : “Poser” · “Partir”

- **a**
  - Narr. “Flash. Le Président serre la main / de Red. Longtemps.”
  - États : `setdecision_once 11, DEC_A` ; `addaffinity VAR_CF_REP_C, 5` ; `subaffinity VAR_CF_REP_P, 3` ; N + 1 (borné à 3).
- **b**
  - **Président** “Ha. Ha. Une autre fois, / peut-être.”
  - États : `setdecision_once 11, DEC_B` ; `subaffinity VAR_CF_REP_C, 3` ; `addaffinity VAR_CF_REP_P, 2`.
- **Commun**
  - **M. Rochard** “Un service ? Une lettre pour mon / fils, Pierre Rochard. Il est à Myokara.”
  - Objet : `ITEM_LETTER`. Elle n'est **pas** livrée dans la démo, et `FLAG_DELIVERED_STEVEN_LETTER` n'est pas posé.
  - **M. Rochard** “Les traversées reprendront bientôt. / Enfin, j’espère.”
  - Si D005 b, Brice entre :
    - **Brice** “Red ! Mon père a fini, me voilà. / J’ai raté quoi ?”
    - Puis `setfollowernpc` Brice.

### C7 — Le petit voleur (D012)
**Déclencheur :** tuiles (11–12, 16) de `MAP_RUSTBORO_CITY` (sortie de Devon), après D011. Brice est toujours présent à ce stade.

- Narr. “Un petit cercle d’or s’ouvre près / de Brice. Une main violette en sort.”
- **Brice** “Mon carnet ! Rends-moi ça, espèce / de… de quoi, d’ailleurs ?”
- Narr. “Une silhouette violette, à peine / plus grande qu’un Skitty.”

**D012** — menu : “Lancer une baie” (si `checkitem ITEM_ORAN_BERRY`) · “Le poursuivre” · “Ne rien faire”

- **a**
  - `removeitem ITEM_ORAN_BERRY`.
  - Narr. “Il attrape la baie au vol, sourit, / et disparaît. Avec le carnet.”
  - **Brice** “Super. Il a mon carnet ET ta / baie.”
  - États : `setdecision_once 12, DEC_A` ; `addaffinity VAR_CF_HO, 5` ; `subaffinity VAR_CF_BR, 2`.
- **b**
  - Narr. “Red court. Quatre pages tombent. / Le voleur file vers l’est.”
  - **Brice** “Quatre pages… Il est parti vers / l’est. Je note.”
  - États : `setdecision_once 12, DEC_B` ; `subaffinity VAR_CF_HO, 3` ; `addaffinity VAR_CF_BR, 2` ; BVCOUNT COMP + 1.
- **c**
  - **Brice** “Tu ne fais rien ?! C’était tout / mon recensement !”
  - États : `setdecision_once 12, DEC_C` ; `addaffinity VAR_CF_HO, 1` ; `subaffinity VAR_CF_BR, 1`.

### C8 — Les mines (D010)
**Déclencheur :** tuile (8, 5) ◐ de `MAP_RUSTURF_TUNNEL`, à l'entrée ouest, depuis la R116 (47, 8). Roxanne, Pierre (Brock), deux mineurs, Charbi, Strassie.

- **Mineur** “Ils mangent le charbon. Les galeries / s’effondrent. On est tous virés.”
- **Roxanne** “Roxanne, championne. Et prof. Il / me faut des données, pas des cris.”
- **Pierre** “Pierre, d’Argenta. Je suis coincé / ici depuis que les ports ont fermé.”
- **Pierre** “Je peux les emmener. J’élève des / Pokémon. Chez moi, c’est pareil.”
- **Mineur** “Les emmener ? Ou on les abat, et / on rouvre demain !”
- **Roxanne** “Red. Tu as vu ces anneaux de près. / Que fait-on ?”

**D010** — menu : “Déplacer avec Pierre” · “Relevés pour Roxanne” · “Laisser les mineurs”

- **a**
  - **Pierre** “Merci. Galerie fermée une semaine, / et ils partent avec moi.”
  - États : `setdecision_once 10, DEC_A` ; `setbits VAR_CF_ECO, 2, 2, ECO_RESTAURE` ; `addaffinity VAR_CF_REP_I, 3` ; `subaffinity VAR_CF_REP_P, 3` ; `setflag FLAG_CF_BROCK_PROTEGES`. Charbi et Strassie masqués.
- **b**
  - **Roxanne** “Un protocole : on balise, on rouvre, / on compte. Je te citerai.”
  - États : `setdecision_once 10, DEC_B` ; `setbits VAR_CF_ECO, 2, 2, ECO_MIXTE` ; `addaffinity VAR_CF_REP_C, 3` ; `addaffinity VAR_CF_REP_P, 2` ; `subaffinity VAR_CF_REP_A, 2`.
- **c**
  - Narr. “La galerie se vide. Un mineur / pleure son Charbi apprivoisé.”
  - États : `setdecision_once 10, DEC_C` ; `setbits VAR_CF_ECO, 2, 2, ECO_ABATTU` ; `addaffinity VAR_CF_REP_L, 4` ; `addaffinity VAR_CF_REP_P, 3` ; `subaffinity VAR_CF_REP_I, 3` ; `subaffinity VAR_CF_TI, 2`. Charbi et Strassie masqués.
- **Commun**
  - **Brice** “Je note l’état de la galerie. / On verra ce qui revient.”
  - **Roxanne** “Je t’attends à l’arène. Tu as gagné / le droit d’essayer.”
  - Le panneau « Roxanne est aux mines », devant l'arène, est retiré.

**Défi de Pierre** (contenu, non compté ; aux mines, seulement après `FLAG_BADGE01_GET`) :
```
trainerbattle_single_declinable TRAINER_VALERIE_5 (si Z-02 = RESTAURÉ) sinon TRAINER_VALERIE_4, ..., 0
```
- Flag de refus 0 : le Défi reste proposé.
- Intro : “Un duel entre bloqués ? / Sans rancune.” Défaite : “Solide. Tu as de la roche dans / le cœur.”

### C9 — Roxanne (D016)
- L'arène est ouverte après D010. Ses dresseurs sont vanilla, avec leurs niveaux ramenés au plafond (§9).
- Combat : `TRAINER_ROXANNE_1` (`T-ROXANNE-T1` : Racaillou 12, Galekid 13, Tarinor 15 @ Baie Oran).
- Après la victoire : badge 1, CT39 (Tomberoche, vanilla), puis `raisecap 18`.

- **Roxanne** “Joli combat. Une dernière chose : / tes observations sur les anneaux.”
- **Roxanne** “Le Rempart me les demande. Je / peux les transmettre ?”

**D016** — menu : “Donner” · “Refuser”

- **a**
  - **Roxanne** “Des données, pas des cris. Merci.”
  - États : `setdecision_once 16, DEC_A` ; `addaffinity VAR_CF_REP_L, 3` ; `subaffinity VAR_CF_BR, 2`. **Effet dans la démo :** des filets du Rempart sont posés sur la R116 (brigadier en (38, 10) visible en C10).
- **b**
  - **Brice** “Nos chiffres restent à nous.”
  - **Roxanne** “Je respecte. Le Rempart, moins.”
  - États : `setdecision_once 16, DEC_B` ; `subaffinity VAR_CF_REP_L, 2` ; `addaffinity VAR_CF_BR, 2`. Pas de filets.

### C10 — Contrebandiers de la R116 (D014, D015)
**Déclencheur :** colonne (40, 9–12) ◐ de `MAP_ROUTE116`, si `FLAG_BADGE01_GET` et D014 non prise. Lance (Rocket) et deux sbires. « Ferrand » (43, 8). Le petit voleur (48, 7), visible si `VAR_CF_HO` ≥ 25.

- Si D016 a, avant la scène, le **brigadier** (38, 10) : “Nos filets sont posés là-bas. / Grâce à vos chiffres. Merci.”
- **Brice** “Chut. Des hommes en noir, près / des rochers. Ils attendent.”
- **Lance** “Quatre minutes. Préparez les cages. / Le cercle sera gros, ce soir.”
- **Sbire A** “Et si la brigade débarque ?”
- **Lance** “Le Rempart paie les arrivants / abattus. Nous, on les revend.”
- Si D013 a :
  - **Brice** “Attends… Le type avec eux. C’est / Ferrand, l’ingénieur de Devon !”
  - Narr. “Ferrand s’éloigne en fredonnant.”
- Si D009 a : **Sbire A** “Hé, le gamin de l’affiche ! Le / champion de Kanto !”

**D014** — menu : “Les affronter” · “Observer, caché” · “Prévenir la brigade”

- **a**
  - Combat contre `TRAINER_GRUNT_PETALBURG_WOODS` (sbire A), puis contre `TRAINER_GRUNT_RUSTURF_TUNNEL` (sbire B). `FLAG_CF_NO_WHITEOUT` posé.
  - Narr. “Le cercle s’ouvre quand même. Il / prend quelque chose dans le sac.”
  - Script : retire 1 exemplaire du **premier** objet possédé de cette liste : Super Potion, Potion, Antidote, Poké Ball. Puis la ligne : “[objet] a disparu dans l’anneau.”
  - **Lance** “Tu me coûtes une nuit, champion. / On se reverra.”
  - États : `setdecision_once 14, DEC_A` ; `subaffinity VAR_CF_RK, 3` ; `addaffinity VAR_CF_REP_L, 1` ; argent − 200 (borné à 0).
- **b**
  - Narr. “Lance regarde sa montre. Une / minute pile avant le cercle.”
  - Narr. “Le cercle s’ouvre. Les sbires mettent / trois arrivants en cage.”
  - **Brice** “Il savait l’heure. À la minute / près. Comment ?”
  - États : `setdecision_once 14, DEC_B` ; `setflag FLAG_CF_DOS_HORAIRE_R116` ; `addaffinity VAR_CF_RK, 3`.
- **c**
  - Narr. “Brice siffle. La brigade arrive / en courant, Flora en tête.”
  - **Flora**, selon D008 :
    - a : “Encore toi. Cette fois, on est / du même côté.”
    - b ou c : “Merci, Red. On s’en occupe.”
  - Narr. “Un sbire est arrêté. Les arrivants / saisis partent… vers l’abattage.”
  - États : `setdecision_once 14, DEC_C` ; `addaffinity VAR_CF_REP_L, 3` ; `subaffinity VAR_CF_REP_A, 2` ; `subaffinity VAR_CF_TI, 1`.

**Le sbire ruiné (D015).** Dans les trois issues, le sbire B reste seul, assis.
- **Sbire B** “Je suis pas un voleur. J’étais / mineur, avant les anneaux.”
- **Sbire B** “Ils paient 200 P la nuit. Ma fille / mange, comme ça.”
- Selon D011 :
  - a : **Sbire B** “Et toi, tu poses en photo avec / ceux qui nous ont virés.”
  - b : **Sbire B** “T’as pas souri sur leur photo, / toi. Je l’ai vu dans le journal.”

**D015** — menu : “Donner 500 P” (masqué si l'argent < 500) · “Partir”

- **a**
  - **Sbire B** “…Pour rentrer. D’accord. Je jette / cette casquette. Merci.”
  - États : `setdecision_once 15, DEC_A` ; `subaffinity VAR_CF_RK, 2` ; `addaffinity VAR_CF_REP_P, 2` ; argent − 500 ; `VIS_38` affiché (il reparaît en mineur à Mérouville).
- **b**
  - Narr. “Il remet sa casquette et suit / les autres dans le noir.”
  - États : `setdecision_once 15, DEC_B` ; `addaffinity VAR_CF_RK, 2`.

**Ex-mineur à Mérouville** (13, 33), si D015 a : “Je reprends lundi. Merci, Red.”

### C11 — Fin de la démo
**Déclencheur :** entrée au Centre de Mérouville avec `FLAG_BADGE01_GET` et D014 prise, alors que `VAR_CF_CHAPTER` = 1. Brice s'assoit en (3, 4). Le panneau « Bulletin des anneaux » est un événement de décor.

- Narr. “Le soir tombe sur Mérouville.”
- **Bulletin**, selon Z-02 :
  - RESTAURÉ : “Bulletin : galeries fermées. Les / Skitty reviennent sur la R116.”
  - MIXTE : “Bulletin : galeries balisées. / Devon rouvre sous protocole.”
  - ABATTU : “Bulletin : galeries rouvertes. Plus / un arrivant. Plus grand-chose.”
- **Brice**, bilan : une boîte par état, dans cet ordre, au plus 4 boîtes au total.
  - D001 a : “Pikachu guérit chez Papa. Il / t’attend.”
  - D001 b : “Ton équipe est quelque part. / On la retrouvera.”
  - D006 a : “M. Marco attend toujours Piko. / Garde bien sa clochette.”
  - D008 a : “Les trois de Galar dorment au Bois. / Grâce à toi.”
  - D015 a : “Ton mineur est rentré. Il t’a / salué, tu l’as vu ?”
- **Le petit voleur à la fenêtre**, selon D012 et `VAR_CF_HO` :
  - HO ≥ 25 : Narr. “Contre la vitre, une ombre violette. / Elle pose une baie, et des pages.” Puis +1 Baie Oran. **Brice** “Il rend mes pages ! Drôle de / voleur.”
  - HO ≤ 18 : Narr. “Contre la vitre, une ombre violette. / Une Poké Ball disparaît du sac.” Puis − 1 Poké Ball, si possédée.
  - Sinon : Narr. “Contre la vitre, une ombre violette. / Elle observe, puis s’en va.”
- **Brice** “Des gens arrivent, d’autres partent. / Et personne ne demande pourquoi.” (C'est la seule phrase-thèse de la démo.)
- **Brice** “Les traversées reprennent bientôt, / paraît-il. Moi, j’y crois moyen.”
- Narr. “Fin de la démo de Pokémon / Confluence. Merci d’avoir joué !”
- Narr. “La suite arrive bientôt. Votre / partie va être sauvegardée.”
- Puis : `setvar VAR_CF_CHAPTER, 2` ; sauvegarde (`special SaveGame` ou équivalent vanilla, à vérifier). Le jeu continue en **libre circulation** dans la zone de démo, murs maintenus.

---

## 5. Décisions de la démo (comptage, règle `ARBITRATION_V3_2` §2)

| ID | Effet observable **dans la démo** (chaque option différente) | Compté |
|---|---|---|
| D001 | Pikachu au labo (P3) ou absent ; réplique de Ciléo (C1, C6) ; bilan C11 | oui |
| D002 | Répliques de Norman (P3, C1) ; passage au barrage C2 (N ≥ 1) | oui |
| D003 | Combat ou non (P4) ; réplique d'avant-duel (P6) ; garant au barrage C2 (`BR` ≥ 50) | oui |
| D004 | Starter (choix de combat) | **non** (règle) |
| D005 | Brice suiveur dès P6, ou absent de C1 à C5 : barrage C2, répliques C3, C4, C5 | oui |
| D006 | Ciléo retenu au QG (C1) ou libre ; clochette ; mini-scène du barrage nocturne ; bilan C11 | oui |
| D007 | Zigzaton de Galar dans l'équipe ou non ; réplique de Flora (C1) | oui |
| D008 | Arrivants sauvés visibles au Bois, ou −300 P, ou refus ; réplique de Flora en C10 c ; bilan C11 | oui |
| D009 | Réplique du Président (C6) ; réplique du sbire A (C10) ; pièce | oui |
| D010 | Tables de la R116 (E-ECO) ; équipe de Pierre ; Bulletin (C11) ; Corde Sortie en vente | oui |
| D011 | Réplique du sbire B (D015) ; N | oui |
| D012 | Objet perdu ou pages récupérées ; scène de la fenêtre (C11, seuils de `HO`) | oui |
| D013 | Ferrand reconnu ou non à la R116 (C10) | oui |
| D014 | Combat, pièce `DOS_HORAIRE_R116` ou arrestation par la brigade (immédiat) | oui |
| D015 | Ex-mineur visible à Mérouville ; bilan C11 | oui |
| D016 | Filets et brigadier sur la R116 (C10) ; répliques | oui |
| D017 | Passage du barrage C2 (insigne) | oui |

**Total : 16 décisions comptées, avec leur effet dans la démo, et 1 décision non comptée.**
- Discrètes (sans menu présenté comme un choix, ou par présence) : D003, D006, D012, D013, D015 = 5 sur 16.
- Les **effets différés au-delà de la démo** (Sommet, ch. 3–7) restent valables pour le jeu complet, mais ils ne sont pas comptés ici.

**Bornes et gardes :**
- tout delta passe par `setdecision_once`, donc il n'est appliqué qu'une fois ;
- une option payante est masquée si l'argent manque (D015) ;
- une perte d'argent imposée par une issue (D008 b, D014 a) est bornée à l'argent disponible.

---

## 6. Chaîne de M. Marco (Briney) et flags vanilla fixés

| Élément vanilla | Valeur dans la démo | Pourquoi |
|---|---|---|
| `FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY` | **effacé** à la nouvelle partie (vanilla : posé par `new_game.inc`) | Marco est chez lui dès le prologue |
| `FLAG_HIDE_BRINEYS_HOUSE_PEEKO` | posé | Piko a disparu |
| `FLAG_HIDE_ROUTE_104_MR_BRINEY`, `FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT` | posés pendant toute la démo | aucune traversée |
| `VAR_BRINEY_HOUSE_STATE` | fixé à une valeur sans départ (« à la maison ») ; le script de Marco est réécrit | le script vanilla de départ vers Myokara n'est jamais atteint |
| `FLAG_DEVON_GOODS_STOLEN`, `FLAG_RECOVERED_DEVON_GOODS`, `FLAG_DELIVERED_DEVON_GOODS`, `FLAG_DELIVERED_STEVEN_LETTER` | jamais posés | il n'y a pas de vol des Pièces Devon ; la lettre n'est pas livrée |
| Script de Marco (maison) après P2 | “Pas de traversée cette semaine. / La brigade surveille la mer.” | mur |

---

## 7. Murs de fin de démo (zone jouable fermée)

**Zone jouable :** Routes 101–104, Bourg-en-Vol, Rosyères, Clémenti, Bois Clémenti, Mérouville, R116 jusqu'à l'entrée du tunnel, Tunnel Mérazon (partie ouest).

| Mur | Moyen | Réplique |
|---|---|---|
| Nord de Mérouville (R115) | brigadier sur la tuile de sortie nord ◐, qui tourne le joueur | “Route 115 fermée : hordes. / Revenez plus tard.” |
| R116 à l'est de l'entrée du tunnel | brigadier en (49, 9) et un second sur la tuile voisine praticable ◐ | “Au-delà, c’est la zone des anneaux. / Interdit.” |
| Tunnel Mérazon, vers l'est | rochers vanilla : pas d'Éclate-Roc dans la démo, donc infranchissables | — |
| Bateau de M. Marco | §6 | — |
| CS Coupe | la maison du Coupeur ne la donne pas (aucune CS dans la démo) | “La Coupe ? Quand les traversées / reprendront, petit.” |
| Portes intérieures du QG (arène de Clémenti) | deux brigadiers devant les portes de la salle d'entrée (vanilla (1, 105) et (7, 105)) | “Bureaux du Rempart. Défense / d’entrer.” |
| Route 110 / Grotte Altérée (R103) | eau : pas de Surf. Vérifier que la Grotte Altérée (45, 6) n'est pas accessible à pied, sinon ajouter un brigadier ◐ | — |
| Mer (R104 vers R105) | pas de Surf | — |

---

## 8. Scripts et événements vanilla à neutraliser dans la zone de démo
**21 éléments.** Un script neutralisé ne doit plus s'exécuter. On le remplace par un script vide, ou on masque l'objet ou le déclencheur. Chaque flag vanilla touché est d'abord vérifié par grep (lecteurs et écrivains).

| # | Carte / système | Élément vanilla | Traitement |
|---|---|---|---|
| 1 | nouvelle partie | camion, intro de Maman, `VAR_LITTLEROOT_INTRO_STATE` | SPAWN sur la R104 ; état d'intro mis à la valeur finale |
| 2 | Bourg-en-Vol | déclencheurs « NeedPokemon », « GoSaveBirch », Chaussures de Course de Maman (`VAR_LITTLEROOT_TOWN_STATE` 0–3), Maman dehors | état mis à la valeur finale ; Chaussures données par Mme Seko |
| 3 | Maison de Brendan 1F/2F | rencontre du rival, Vigoroth, papa, intro (`VAR_LITTLEROOT_RIVAL_STATE`) | masqués ; Mme Seko réécrite |
| 4 | Maison de May | toute la séquence | porte fermée (« Personne ») ◐ |
| 5 | Route 101 | sauvetage de Seko, sac, Zigzaton, triggers PreventExit (`VAR_ROUTE101_STATE`) | `FLAG_RESCUED_BIRCH` posé ; triggers remplacés par P4 |
| 6 | Labo | séquence vanilla Pokédex et rival ; Balls de Johto (postgame) | réécrit (P3) ; Balls masquées |
| 7 | Rosyères | homme aux empreintes (`VAR_OLDALE_TOWN_STATE`), rival | état = 1 à la fin de P6 ; rival masqué |
| 8 | Route 103 | combat de rival vanilla, Seko (évaluation du Pokédex) | remplacés par P6 ; Seko masqué |
| 9 | Clémenti | Timmy et sa capture, son père, déclencheurs « ShowGym », Scott | masqués ; états mis à la valeur finale |
| 10 | Arène de Clémenti | Norman champion, porte « 4 badges », Timmy | QG (C1) ; dresseurs d'arène masqués |
| 11 | Route 104 | rival, Marco et bateau sur la route (`VAR_ROUTE104_STATE`) | masqués |
| 12 | Maison de Marco | départ vers Myokara, Piko | §6 |
| 13 | Bois Clémenti | sbire Aqua et chercheur Devon (`VAR_PETALBURG_WOODS_STATE`), cadeau de la Super Ball | masqués ; triggers remplacés par C3 |
| 14 | Mérouville | Pièces Devon volées, poursuite, retour (`VAR_RUSTBORO_CITY_STATE` 1–7), sbire Aqua, scientifique, rival | état mis à une valeur neutre ; triggers remplacés (C4, C7) |
| 15 | Devon 1F/2F/3F | M. Rochard vanilla (PokéNav, Pièces), garde d'escalier, scientifiques du Match Call et du PokéNav | réécrits (C5, C6) ; PokéNav non donné |
| 16 | Maison du Coupeur | CS Coupe | mur §7 |
| 17 | Route 116 | sbire Aqua, employé Devon, Marco, petit ami de Wanda (`VAR_ROUTE116_STATE`), homme aux lunettes | masqués |
| 18 | Tunnel Mérazon | Wanda, son petit ami, Marco, sbire, Piko, blocages (`TRIGGER_RUN_IMMEDIATELY`) | masqués ; triggers de blocage neutralisés ; scène C8 |
| 19 | Télé | épidémies aléatoires | coupées (E-OUT) |
| 20 | Match Call | inscriptions | sans objet (`FREE_MATCH_CALL TRUE`) |
| 21 | Arène de Mérouville | rien à neutraliser (porte gérée par C8) | panneau « Roxanne est aux mines » |

---

## 9. Dresseurs et équipes

| Combat | ID | Équipe | IA | Niv. (plafond) |
|---|---|---|---|---|
| Brice, R103 | `TRAINER_BRENDAN_ROUTE_103_{TORCHIC,MUDKIP,TREECKO}` | `T-BRICE-T1-R103-*` (`teams_v3.party`) | Basic / Sequence / Ace | 4–6 (14) |
| Flora, Bois | `TRAINER_BROOKE_4` | `T-FLORA-T1` | Basic / Sequence / Ace | 11–14 (14) |
| Roxanne | `TRAINER_ROXANNE_1` | `T-ROXANNE-T1` | + Conservative | 12–15 (14) |
| Pierre, Défi | `TRAINER_VALERIE_4` / `_5` | `T-PIERRE-T1-SANS` / `-AVEC` | Basic / Smart Switching / Ace / HP Aware | 16–18 (18) |
| Sbire A (R116) | `TRAINER_GRUNT_PETALBURG_WOODS` (recyclé) | **nouvelle équipe de démo** ci-dessous | Basic Trainer | 15–16 (18) |
| Sbire B, ex-mineur (R116) | `TRAINER_GRUNT_RUSTURF_TUNNEL` (recyclé) | **nouvelle équipe de démo** ci-dessous | Basic Trainer | 15–16 (18) |
| Dresseurs vanilla des Routes 102–104, du Bois, de la R116 et de l'arène | ID vanilla | équipes vanilla, **niveaux ramenés à ≤ plafond − 2** (14 → 12 avant le badge ; 16 après, sur la R116) | vanilla | — |

Les dresseurs vanilla gardent leur texte, sauf ceux qui citent Aqua, Magma ou l'intrigue vanilla : réécrits en 1 boîte. Une liste par grep est à produire.

```
=== TRAINER_GRUNT_PETALBURG_WOODS ===
Name: SBIRE
Class: Team Rocket Frlg
Pic: Rocket Grunt M Frlg
Gender: Male
Music: Male
Battle Type: Singles
AI: Basic Trainer

Koffing
Level: 15
Ability: Levitate
- Tackle
- Smog
- Poison Gas
- Smokescreen

Zubat
Level: 15
Ability: Inner Focus
- Leech Life
- Supersonic
- Astonish
- Bite

=== TRAINER_GRUNT_RUSTURF_TUNNEL ===
Name: SBIRE
Class: Team Rocket Frlg
Pic: Rocket Grunt F Frlg
Gender: Female
Music: Female
Battle Type: Singles
AI: Basic Trainer

Rattata
Level: 15
Ability: Guts
- Tackle
- Quick Attack
- Bite
- Tail Whip

Rolycoly
Level: 16
Ability: Steam Engine
- Tackle
- Smokescreen
- Rapid Spin
- Rock Polish
```
Le sbire B aligne **son propre Charbi** de mineur. À valider avec `tools/qa/validate_trainers.py --learnsets` avant intégration (attaques par niveau à vérifier : Charbi niv. 16).

---

## 10. Rencontres sauvages de la démo (`src/data/wild_encounters.json`)

**Emplacements d'herbe :** 12 emplacements, taux 20 · 20 · 10 · 10 · 10 · 10 · 5 · 5 · 4 · 4 · 1 · 1 (ordre ci-dessous).
- **Niveaux :** prologue (R101–R103) 3–6 ; ch. 1 (R104, Bois, R116, tunnel) 7–12.
- **Nuit** (E-TOD, variante `_Night`) : remplace seulement les emplacements indiqués.
- **Autres méthodes :** aucune pêche (Vieille Canne au ch. 2) et aucun surf dans la démo.

| Carte (zone) | Emplacements 0 → 11 (jour) | `_Night` |
|---|---|---|
| R101 (Z-01) | Piafabec, Taupiqueur, Chenipan, Nidoran♂, Zigzaton, Medhyèna, Chétiflor, Fouinette, Pomdepik, Chenipotte, Chenipotte, **Goélise** | 0 Fantominus, 1 Mimitoss, 6 Hoothoot, 7 Hoothoot |
| R102 (Z-01) | Abo, Aspicot, Osselait, Paras, Zigzaton, Nénupiot, Coxy, Snubbull, Noeunoeuf, Tarsal, Arakdo, **Goélise** | 0 Rattata, 1 Miaouss, 6 Mimigal, 7 Mimigal |
| R103 (Z-01) | Roucool, Férosinge, Nidoran♀, Marcacrin, Zigzaton, Medhyèna, Granivol, Medhyèna, Zigzaton, Roucool, Évoli, **Goélise** | 0 Mélofée, 1 Soporifik, 6 Mélofée, 7 Soporifik |
| R104 (Z-01) | Caninos, Ponyta, Canarticho, Saquedeneu, Medhyèna, Chenipotte, Excelangue, Simularbre, Onix, Nirondelle, Porygon, **Goélise** | 0 Cornèbre, 1 Farfuret, 6 Feuforêve, 7 Feuforêve |
| Bois Clémenti (Z-02, table unique) | Moumouton, Voltoutou, Tournicoton, Verpom, Chenipotte, Balignon, Grillepattes, Bibichut, Nirondelle, Parecool, Crèmy, Medhyèna | — |
| Tunnel Mérazon ouest (Z-02, table unique) | Charbi, Chuchmur, Racaillou, Charbi, Chuchmur, Racaillou, Charbi, Chuchmur, Strassie, Racaillou, Strassie, Chuchmur | — |
| **R116 ENVAHI** (`gRoute116`) | Minisange, Sapereau, Hélionceau, Psystigri, Medhyèna, Nirondelle, Cabriolaine, Sucroquin, Galvaran, Ningale, Chuchmur, **Skitty** | 8 Morpeko, 9 Goupilou |
| **R116 MIXTE** (`gRoute116_Mixte`) | Medhyèna, Minisange, Nirondelle, Ningale, Sapereau, Psystigri, **Skitty**, Chuchmur, Hélionceau, Cabriolaine, Sucroquin, Galvaran | 8 Morpeko, 9 Goupilou |
| **R116 RESTAURÉ** (`gRoute116_Restaure`) | **Skitty**, Medhyèna, Nirondelle, Ningale, Chuchmur, Minisange, Sapereau, Psystigri, Hélionceau, Galvaran, Cabriolaine, Sucroquin | 8 Morpeko, 9 Goupilou |
| **R116 ABATTU** (`gRoute116_Abattu`, `encounter_rate` × 0,5) | Medhyèna, Nirondelle, Ningale, Chuchmur, **Skitty**, Minisange, Sapereau, Psystigri, Hélionceau, Galvaran, Cabriolaine, Sucroquin | 8 Morpeko, 9 Goupilou |

**Règles respectées :**
- l'ensemble des espèces est constant entre les états (aucune espèce ne disparaît) ;
- le natif emblématique **Skitty** passe de 1 % (ENVAHI) à 5 % (MIXTE), 20 % (RESTAURÉ) et 10 % (ABATTU) ;
- les 4 tables de la R116 sont **consécutives** dans le JSON (contrainte d'E-ECO), chacune suivie de sa `_Night`. La table provisoire `gRoute116_Mixte` déjà livrée est remplacée ;
- arrivants de Z-01 : Kanto et Johto ; de Z-02 : Kalos et Galar.

---

## 11. Objets, plafonds, Multi Exp, coach, difficulté, soins

- **Objets donnés :** Pokédex, 5 Poké Balls, 1 Baie Oran (Seko, P3) ; Chaussures de Course (Mme Seko, P5) ; Lettre (M. Rochard, C6) ; CT39 (Roxanne). Les objets vanilla au sol de la zone sont conservés.
- **Boutiques :** stock vanilla à Rosyères, Clémenti et Mérouville. La **Corde Sortie** est absente à Mérouville tant que Z-02 = ENVAHI (avant D010).
- **Plafond :** 14 du début jusqu'à Roxanne, puis 18 (`raisecap 18`). L'EXP de l'équipe du prologue est sans effet, puisque l'équipe est retirée.
- **Multi Exp :** **non donné dans la démo**. Il arrive au ch. 3 (D030) ou au ch. 4, hors démo. Le rattrapage d'EXP sous le plafond (`B_LEVEL_CAP_EXP_UP`) suffit pour une recrue tardive.
- **Coach :** Centre de Clémenti (C1).
- **Difficulté :** Seko (P3).
- **Soins :** labo (Seko, illimité), lit des Seko, Centres de Rosyères, Clémenti et Mérouville. Le Bois est encadré par deux Centres à deux cartes ; les mines et la R116 sont voisines de Mérouville. Au prologue, aucun soin n'est nécessaire (équipe niv. 60+).

---

## 12. Budget de texte (cible ≤ 400 boîtes)

| Bloc | Boîtes |
|---|---|
| Prologue P1–P6 (avec variantes) | ≈ 120 |
| Ch. 1 C1–C10 (avec variantes) | ≈ 150 |
| Fin C11 | ≈ 18 |
| Murs, coach, panneaux, bulletin, ex-mineur, Défi de Pierre | ≈ 22 |
| Dresseurs vanilla réécrits (citant Aqua, Magma ou l'intrigue vanilla) | ≈ 20 (estimation, à mesurer par grep) |
| **Total** | **≈ 330** (marge ≈ 70) |

Le décompte exact des boîtes écrites ici est donné par le vérificateur (§13).

---

## 13. Tests d'acceptation (vérifiables sur émulateur)

Harnais : `QA_TOOLING.md`. Une sauvegarde d'état avant chaque décision. Vars et flags lus en mémoire.

1. **Nouvelle partie :** spawn sur la plage de la R104 ; 6 Pokémon niv. 60+ ; `VAR_CF_CAP` = 14 ; aucune rencontre sauvage tant que P4 n'est pas finie.
2. **P1 :** les 3 combats sauvages s'enchaînent ; après D001, l'équipe est **vide** (E-CLEARPARTY) ; `VAR_CF_D00` b0-1 = 1 ou 2 ; en b, `FLAG_CF_DOS_JOURNAL_NOEUD` posé ; Pikachu = 1 dans `VAR_CF_WORLD` b14-15 en a.
3. **P2 → P3 :** pas de softlock sans Pokémon ; en D006 b, la mini-scène de Clémenti est jouée ; warp vers le labo.
4. **P3 :** le starter est reçu ; `VAR_DIFFICULTY` suit le choix ; D002 et D005 sont écrits une seule fois (un 2e passage ne change aucun delta).
5. **P4 :** en a, combat contre un Piafabec ; BVCOUNT correct ; `FLAG_NO_WILD_ENCOUNTERS` effacé ensuite.
6. **P6 :** l'équipe de Brice correspond au starter (3 cas) ; la défaite ne renvoie pas au Centre et l'histoire continue ; en D007 a, Zigzaton de Galar dans l'équipe.
7. **C1 :** Ciléo n'est au QG que si D006 a ; réplique de Flora selon D007 ; `FLAG_CF_INSIGNE` selon D017.
8. **C2 :** tester les 4 branches du barrage, y compris le repli de Flora (D002 b + D017 b + D005 b) : **aucun blocage**.
9. **C3 :** victoire, défaite (−300 P borné) et refus (`FLAG_CF_REFUS_FLORA1` posé, Flora ne repère plus le joueur).
10. **C4–C7 :** ordre forcé ; répliques conditionnelles (Brice présent ou absent selon D005) ; en D012 a, l'option est cachée sans Baie Oran.
11. **C8 :** pour chaque issue de D010, `VAR_CF_ECO` b2-3 = 2 / 1 / 3. Puis **50 rencontres sur la R116** : Skitty ≈ 0–1 (ENVAHI, avant D010), ≈ 2–3 (MIXTE), ≈ 10 (RESTAURÉ), ≈ 5 (ABATTU, avec une densité réduite). La Corde Sortie est en vente seulement après D010.
12. **C9 :** l'arène est fermée avant D010 ; après Roxanne, `VAR_CF_CAP` = 18 ; D016 écrit.
13. **C10 :** inaccessible avant le badge 1. En a, 2 combats, 1 objet de la liste retiré, −200 P borné ; en b, `FLAG_CF_DOS_HORAIRE_R116` ; en c, Flora apparaît. Les filets sont visibles seulement si D016 a ; Ferrand est reconnu seulement si D013 a.
14. **D015 :** l'option a est cachée si l'argent < 500 ; en a, l'ex-mineur est visible à Mérouville.
15. **C11 :** se déclenche une seule fois ; bulletin selon Z-02 ; bilan de Brice ≤ 4 boîtes ; scène du voleur selon `HO` (≥ 25 → +1 Baie Oran ; ≤ 18 → −1 Poké Ball) ; `VAR_CF_CHAPTER` = 2 ; sauvegarde effectuée ; au rechargement, la partie reprend au Centre.
16. **Murs :** R115, R116 est, bateau de Marco, Coupeur, portes du QG ; Grotte Altérée inaccessible.
17. **Neutralisations (§8) :** aucun script vanilla Aqua, Magma ou Timmy ne s'exécute. Trace : `grep` des flags vanilla touchés + parcours complet.
18. **Texte :** toutes les boîtes ≤ 208 px et 2 lignes. Commande : `python3 -I <scratchpad>/pxw.py <racine> docs/hack/SLICE_DEMO_CH0-1.md` (contrôle de ce document), puis le même contrôle sur les `.inc`.
19. **Parcours complet :** de la nouvelle partie à la fin de la démo, sans softlock, en Normal **et** en Difficile.
20. **Équipes de démo :** `validate_trainers.py --learnsets` : 0 erreur.

---

## 14. Changelog
| Date | Changement | Auteur |
|---|---|---|
| 2026-10-14 | Création : spécification complète de la démo (prologue + ch. 1) après le changement de périmètre | GMD |
