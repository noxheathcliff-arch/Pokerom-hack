# GAME_SYSTEMS — *Pokémon Cendres*

> Partie de la bible. Toute modification passe par le GMD.
> Principe de conception (GM_METHOD §1) : chaque système existe pour une **décision** du joueur et produit un **effet observable**. Pas de jauge de morale unique. Tout est stocké en vars/flags et lu par des branches de script ; aucune structure de sauvegarde nouvelle.
> Noms de vars/flags : `VAR_HS_*` / `FLAG_HS_*` (neufs, pris dans les plages libres de `TECHNICAL_AUDIT.md` §7). Les aides moteur (ajout/borne d'affinité, niveau relatif au plafond) sont décrites dans `ENGINE_CHANGES.md` ; à défaut, `addvar`/`subvar` + bornes en script.

---

## 1. Vue d'ensemble
| Famille | Variables | Pourquoi |
|---|---|---|
| Affinités (5 personnages) | `VAR_HS_AFF_BRICE`, `_BLUE`, `_AUGUSTE`, `_MAXIE`, `_ARCHIE` | qui suit Red, qui parle pour lui, qui agit seul |
| Réputations (4 factions) | `VAR_HS_REP_REFUGIES`, `_MAGMA`, `_AQUA`, `_AUTORITES` | qui écoute Red, qui vote quoi au Conseil |
| États du monde (4) | `VAR_HS_ETAT_VOLCAN`, `_CAMP`, `_RECIF`, `_ROCKET` | ce qui arrive aux lieux ; issues du climax |
| Notoriété de Red | `VAR_HS_NOTORIETE` (0 anonyme / 1 connu / 2 légende) | portes ouvertes ou fermées, cibles de Rocket |
| Décisions structurantes | `VAR_HS_RESEAU`, `_ORBE`, `_PIKACHU`, `_BRICE_VOIE`, `_PIERRE_POS`, `_TEMOIGNAGE`, `_CONSEIL_SOUPAPE`, `_CONSEIL_REFUGIES`, `_CONSEIL_ARCHE`, `_CLIMAX_LIEU`, `_CHAPITRE` | branches majeures |
| Preuves | `FLAG_HS_PREUVE_*` (14) | enquête ; poids au Conseil |
| Promesses | `FLAG_HS_PROMESSE_*` (4) | vérifiées plus tard ; promesse rompue = conséquence |

Règle anti-jauge : aucune décision ne monte « tout » ; la plupart des choix forts **monte une valeur et en baisse une autre** (intérêts en tension).

## 2. Systèmes cachés — spécifications

### 2.1 Affinités (0–100, départ 50 ; bornées)
| Seuil | Nom | Effet générique |
|---|---|---|
| ≤ 30 | Rupture | le personnage refuse d'aider ; dialogues froids ; ne viendra pas au climax |
| 31–59 | Réserve | aide quand on le lui demande ; pas d'initiative |
| ≥ 60 | Allié | initiative, parole au Conseil, aide au climax |
| ≥ 80 | Confiance | scène personnelle (aveu), objet unique |

| Personnage | Monte avec (exemples) | Baisse avec | Effets spécifiques observables |
|---|---|---|---|
| **Brice** | le suivre, l'écouter, lui laisser la parole, partager les preuves, l'aider face à son père | l'ignorer, décider à sa place quand il s'est engagé, mentir par omission (D015) | ≥ 50 : peut négocier à la place de Red (D025/D049/D081) ; ≥ 55 : tient l'autre lieu au climax ; ≥ 60 : parle au Conseil (D100) ; ≤ 30 : quitte l'équipe au ch. 12 (épilogue « rupture ») ; surnom de Red (« Red » / « le Maître » / « toi ») |
| **Blue** | accepter ses défis, l'écouter (toit), le respecter | refuser ses défis, le provoquer | ≥ 60 : vient au climax défendre l'Arche ; équipe de la Route Victoire « digne » (variante 2) ; épilogue Jadielle avec message |
| **Auguste** | tenir ses promesses, protéger les ouvriers, rite (D084) | promesse rompue, soutien du forage complet, Arche à Devon | ≥ 60 : aveu (ch. 9) et vote « intégration » plus facile ; ≤ 30 : il organise seul le départ des réfugiés (pousse vers EXODE) |
| **Max** | le confronter avec des preuves sans l'humilier, comprendre la pression de Devon (D065) | humiliation publique, sabotage du capteur toléré | ≥ 55 : arrête lui-même la foreuse au climax ; vote « réduit » |
| **Arthur** | lever le blocus par l'échange, données publiques, alliance des pêcheurs | violence contre ses militants, données données à Devon | ≥ 60 : alliance pêcheurs/réfugiés ; plongeur-secouriste à Fondmer garanti |

Perception : ligne d'accueil différente à chaque rencontre (3 variantes par seuil), position du personnage (à côté de Red ou à l'écart), objets offerts, et le **Carnet de Red** (§10) qui note « Brice semble… » sans chiffre.

### 2.2 Réputations de faction (0–100, départ : Réfugiés 50, Magma 50, Aqua 40, Autorités 50)
| Faction | Monte | Baisse | Effets observables |
|---|---|---|---|
| Réfugiés | aide au camp, Pokémon rendus, soutien à l'intégration | soutien à l'Arche-Devon, dénonciation de Téo, embauche risquée qui tourne mal | prix réduits au marché du camp ; enfants qui suivent Red ; vote d'Auguste ; ≥ 60 empêche l'EXODE après une éruption |
| Magma | soutien de la Soupape, données remises, sauvetage du blessé Magma | sabotage toléré, données publiées contre eux | accès au chantier sans détour (D055) ; médecin du chantier ; vote de Max |
| Aqua | données publiques, défense des récifs, alliance des pêcheurs | violence, données à Devon, soutien du forage complet | blocus levé sans combat (D081) ; plongeur-secouriste ; vote d'Arthur |
| Autorités (Ligue + Devon) | coopération avec Norman/Devon, respect des procédures, notoriété assumée | contester Devon, relâcher un sbire, ouvrir le manifeste | portes officielles (Centre Spatial, archives) ; votes de M. Rochard et de Marc |

Perception : affiches et journaux télévisés (Gabby & Ty) à Poivressel, Lavandia, Nénucrique ; attitude des gardes ; PNJ de faction sur les routes.

### 2.3 États du monde
| Var | Départ | Sens | Entrées principales | Effets |
|---|---|---|---|---|
| `ETAT_VOLCAN` | 30 | risque (0 sûr – 100 catastrophe) | Soupape (complet +30, réduit +10, arrêt −10), sabotages déjoués (−10 chacun), Lambda démasqué (−10), décisions du climax | issue du climax (§8) ; ≥ 70 : Groudon s'éveille (4F accessible) |
| `ETAT_CAMP` | 40 | préparation et moral du camp (0–100) | dons, tentes, soins, hébergement, jour supplémentaire (D036) | issue de l'évacuation (blessés, pertes de Pokémon) ; visuel du camp (PNJ/objets) |
| `ETAT_RECIF` | 60 | santé marine (0–100) | Soupape, prélèvement de corail (D097), alliance pêcheurs | épilogue marin ; PNJ pêcheurs ; objet Coquillage ; vote d'Arthur |
| `ETAT_ROCKET` | 20 | avance de Rocket (0–100) | indices manqués, sbires relâchés, codes non changés, notoriété publique trop tôt (D090) | force de l'équipe d'Ariane (2 variantes) ; nombre de Pokémon volés ; fuite d'Ariane |

### 2.4 Notoriété de Red
`0` anonyme (D005 « R. »), `1` connu, `2` légende (conférences, interview). Effets : `1+` dresseurs qui défient Red (combats déclinables) ; `2` Rocket tend un piège supplémentaire au ch. 10 ; `0` certains PNJ officiels refusent de le croire sans Brice ; épilogue.

## 3. Progression et plafonds de niveau
- **Plafond souple** (`B_EXP_CAP_TYPE EXP_CAP_SOFT`, `B_LEVEL_CAP_TYPE LEVEL_CAP_FLAG_LIST`, `B_LEVEL_CAP_EXP_UP TRUE`) ; table `sLevelCapFlagMap` (`src/caps.c`) réécrite avec **jalons d'histoire** (leçon des revues) :

| Tant que ce drapeau n'est pas posé | Plafond | Combat qui le clôt |
|---|---|---|
| `FLAG_BADGE01_GET` | 14 | Roxanne |
| `FLAG_BADGE02_GET` | 18 | Bastien |
| `FLAG_HS_BLUE1` | 20 | Blue à Poivressel (perdre ou gagner pose le drapeau) |
| `FLAG_BADGE03_GET` | 23 | Voltère |
| `FLAG_HS_RAID_MERAZON` | 25 | raid du tunnel |
| `FLAG_HS_SITE_METEORE` | 27 | Site Météore |
| `FLAG_BADGE04_GET` | 30 | Adriane |
| `FLAG_BADGE05_GET` | 33 | Norman |
| `FLAG_HS_INSTITUT` | 35 | Institut (Sarah) |
| `FLAG_BADGE06_GET` | 38 | Alizée |
| `FLAG_HS_PLANQUE_AQUA` | 40 | Planque Aqua |
| `FLAG_HS_MONT_MEMORIA` | 42 | Mont Mémoria |
| `FLAG_BADGE07_GET` | 45 | Lévy & Tatia |
| `FLAG_HS_CENTRE_SPATIAL` | 47 | Lambda |
| `FLAG_BADGE08_GET` | 50 | Juan |
| `FLAG_HS_BRAISE` | 53 | climax |
| `FLAG_IS_CHAMPION` | 60 | Ligue |
| (postgame) | 75 | — |
Propriété : le plafond est celui de la **première** entrée non validée ; un joueur qui saute un jalon reste au plafond le plus bas, jamais plus haut.
- **Combats majeurs** : niveau ≤ plafond + 2 (As + 3).
- **Progression non réduite aux badges** : les jalons d'histoire ouvrent des lieux (téléphérique, Route 124, Atalanopolis), des personnages (Brice autonome, Blue allié), des objets (Méga) et des issues (fins).

## 4. Rencontres sauvages (principes et intentions)
- **Principes** : chaque route propose 1-2 espèces **utiles au prochain défi** (options d'équipe) ; niveaux 2-4 sous le plafond (pas de farming rentable : EXP réduite au-delà du plafond) ; espèces étrangères seulement près des camps (Pokémon relâchés, LORE §8.7 rang 2) et au Parc Safari ; pas de Pokémon des générations 4-9 « au hasard ».
- **Fichier** : `src/data/wild_encounters.json` ; `OW_TIME_OF_DAY_ENCOUNTERS` reste à `FALSE` (pas de dépendance à l'heure, coût réduit).

| Zone | Intention | Exemples (indicatifs, à équilibrer par le superviseur rencontres) |
|---|---|---|
| Routes 101-104, Bois | équipe de base, contre Roche | Zigzaton, Nirondelle, Chenipotte, Lotad, Grenousse (Gen 6, relâché près de la plage) |
| Routes 106-109 (mer), plage du camp | Pokémon de Cramois'Île relâchés | Ponyta, Caninos, Magmar (rare), Tentacool, Machoc |
| Route 110, 117 | contre Électrik/Combat | Rototaupe, Wattouat, Marcacrin |
| Tunnel Mérazon | contre Rocket (Poison) | Chuchmur, Sabelette, Grotichon |
| Routes 111-114, cendres | contre Feu/soleil | Hippopotas, Cacnea, Spinda, Groret |
| Mont Chimnée, Chemin Ardent | contre Feu, Sol | Chartor, Limagma, Grolem |
| Routes 118-120 | contre Vol, synergies | Kecleon, Tropius, Absol (rare), Hélédelle |
| Routes 121-124, Mont Mémoria | contre Spectre/Ténèbres | Polichombr, Skelénox, Morphéo (Institut, don) |
| Mers 124-128, Fondmer | contre Eau/pluie | Wailmer, Lanturn, Relicanth (rare) |
| Route Victoire | synthèse | vanilla relevé de niveau |

## 5. Le Conseil d'Atalanopolis (mécanique de vote)
Sept votants : **Marc** (président), **Juan**, **Pierre**, **M. Rochard**, **Max**, **Arthur**, **Auguste**. Pour chaque motion, Red (ou Brice, D100) défend **une option** (D101–D103) ; chaque votant vote « pour » si sa condition est vraie ; la motion passe à **4 voix**. Si elle échoue, l'**option par défaut** s'applique. Implémentation : un compteur `VAR_TEMP` incrémenté par une suite de `goto_if` (aucun code C).

`P` = nombre de preuves présentées (D104, max 3) pertinentes pour la motion (voir colonne « preuves »).

**Motion 1 — Soupape** (options : 1 complet / 2 réduit et surveillé / 3 arrêt et plan d'évacuation ; défaut : 1)
| Votant | Vote « pour » l'option défendue si… |
|---|---|
| Max | opt 1 ; ou opt 2 et (`AFF_MAXIE` ≥ 55 ou `PREUVE_SABOTAGE`) ; ou opt 3 et `AFF_MAXIE` ≥ 75 et `PREUVE_PRESSION_DEVON` |
| Arthur | opt 3 ; ou opt 2 et (`REP_AQUA` ≥ 55 ou `PREUVE_TEMPERATURE`) |
| Auguste | opt 2 et `AFF_AUGUSTE` ≥ 40 ; ou opt 1 et `REP_REFUGIES` ≥ 60 ; ou opt 3 et `ETAT_CAMP` ≥ 60 |
| M. Rochard | opt 1 ; ou opt 2 et `REP_AUTORITES` ≥ 55 et P ≥ 2 |
| Pierre | opt = `VAR_HS_PIERRE_POS` (D077) ; sinon P ≥ 3 |
| Juan | P ≥ 2 et opt ≠ 1 ; ou opt 1 et `PREUVE_CAPTEUR` |
| Marc | `REP_AUTORITES` ≥ 40 et (Brice a parlé ou `NOTORIETE` ≥ 1) |
Preuves pertinentes : `SABOTAGE`, `TEMPERATURE`, `CORAIL`/`PHOTOS_FONDS`, `CAPTEUR`, `PLANS`, `PRESSION_DEVON`.

**Motion 2 — Réfugiés** (1 intégration / 2 relogement à Pacifiville / 3 rapatriement ; défaut : 2)
| Votant | « pour » si… |
|---|---|
| Auguste | opt 1 ; opt 3 seulement si `AFF_AUGUSTE` ≤ 30 |
| Arthur | opt 2 ; ou opt 1 et (`FLAG_HS_ALLIANCE_PECHEURS` ou `AFF_ARCHIE` ≥ 60) |
| Max | opt 1 et `REP_MAGMA` ≥ 50 (main-d'œuvre) ; ou opt 2 |
| M. Rochard | opt 2 ; ou opt 1 et `REP_AUTORITES` ≥ 60 |
| Pierre | opt 1 et `PREUVE_TEMOIGNAGE_STEVEN` ; sinon opt 2 |
| Juan | opt 1 et `REP_REFUGIES` ≥ 55 ; sinon opt 2 |
| Marc | opt 1 et `ETAT_CAMP` ≥ 50 ; sinon opt 2 |

**Motion 3 — Arche** (1 garde Devon / 2 garde Ligue / 3 restitution aux familles ; défaut : 1)
| Votant | « pour » si… |
|---|---|
| Auguste | opt 3 ; opt 2 si `PROMESSE_ARCHE` tenue en partie |
| M. Rochard | opt 1 ; opt 2 si `LAMBDA_DEMASQUE` (taupe chez Devon) |
| Pierre | opt 2 ; opt 3 si `PREUVE_RECENSEMENT` (Brice/Seko) |
| Seko (remplace Max sur cette motion) | opt 1 ; opt 3 si `BRICE_VOIE` = 3 (confrontation) |
| Arthur | opt 3 si `AFF_ARCHIE` ≥ 50 ; sinon s'abstient (= contre) |
| Juan | opt 2 |
| Marc | opt 2 ; opt 3 si `REP_REFUGIES` ≥ 60 |

Feedback : chaque vote est **dit** à voix haute avec sa raison (une boîte) ; le Carnet note le résultat. Le joueur comprend a posteriori ce qui a pesé.

## 6. Objets et économie
- **Argent** : sources = dresseurs (barème vanilla), objets ; **puits** = dons au camp (D027, D087), tentes, cabanes de Cimetronelle (5 000 ₽, D076), informations (D039), Flûtes (D047). Les combats déclinés ne rapportent rien : décliner a un coût.
- **Soins** : boutiques plafonnées en début de jeu (Potion, Super Potion jusqu'au ch. 6) ; pas de Rappel Max en boutique avant le ch. 10.
- **Méga-Gemmes** (rares, une par lieu ou décision) : gemme du starter (Pierre, ch. 8) ; Absolite (D078, Route 120) ; Élecsprintite (Voltère après D037) ; Camérupite (Adriane si D061) ; Méditikkanite (Bastien si D019) ; Altarite (Alizée si D076) ; Pikachu n'a pas de Méga ; Florizarrite/Dracaufite X/Tortankite (postgame, équipe classique si D115).
- **CT** : récompenses de décisions (indiquées dans le registre), jamais en double.
- **Objets clés** : Carnet de Red, Manifeste de l'Arche, Lettre pour Pierre, Lunettes Sable, Scope Devon, Méga-Bracelet, Orbe Rouge (si D085 = Red).

## 7. Quêtes
| ID | Quête | Ouverture → fin | But | Conséquence |
|---|---|---|---|---|
| Q0 | Principale (ch. 0-14) | — | — | fins |
| S1 | Le Galopa du bois | D010 → ch. 3 (propriétaire au camp) | rendre un Pokémon = politique | `REP_REFUGIES`, Méga ? non ; CT Lance-Flammes ◐ |
| S2 | Lilou et Téo | ch. 0 → ch. 13 | ce qu'on doit à ceux qu'on sauve | Téo guetteur Rocket ou informateur (D034) |
| S3 | Peter au Site Météore | ch. 5 (facultatif) | respect d'un lieu sacré | Peter au postgame ; Draby |
| S4 | Le rite des morts | ch. 9 | deuil partagé | aveu d'Auguste |
| S5 | Flora | ch. 7 → ch. 12 | jeunesse et engagement | Flora au Conseil (voix Aqua) |
| S6 | Les cabanes | ch. 8 | coût de l'accueil | `ETAT_CAMP`, Altarite |
| S7 | Lettres à la mère | ch. 2 → postgame | qui attend Red | réponse au postgame |
| P1 | Le lien PC | postgame (si `RESEAU` ≥ 1) | ce que Red a laissé | équipe classique (D115) |
| P2 | Ariane | postgame (si en fuite) | Rocket hors de Hoenn | épilogue Rocket |
| P3 | Groudon | postgame (si éveillé) | apaiser ou capturer | monde |
| P4 | Zone de Combat | postgame | Blue, Scott | statut de Blue |
| P5 | Revanches | postgame | rejouabilité | dresseurs revanchables |

## 8. Climax et fins — conditions formelles

### 8.1 Calcul de l'issue du volcan (au moment de `FLAG_HS_BRAISE`)
`V = VAR_HS_ETAT_VOLCAN` après application, dans l'ordre :
1. Motion 1 : complet +30 ; réduit +10 ; arrêt −10.
2. Chaque sabotage déjoué (`FLAG_HS_SABOTAGE1_DEJOUE` ch. 6, `_2_` ch. 8) : −10.
3. `FLAG_HS_LAMBDA_DEMASQUE` : −10.
4. Climax au chantier (`CLIMAX_LIEU` = 1) : D107 arrêt d'urgence −20 (si motion 1 ≠ 3) ; D108 Orbe utilisée −25 (si `ORBE` = 2 et `FLAG_HS_SAIT_ORBE`) ; sinon si `AFF_MAXIE` ≥ 55 : Max arrête lui-même −15.
5. Climax au camp (`CLIMAX_LIEU` = 2) : Brice au chantier si `AFF_BRICE` ≥ 55 → −10 ; Max seul si `AFF_MAXIE` ≥ 55 → −15 ; sinon +10.
6. Si `V` ≥ 70 : Groudon s'éveille (`MAGMA_HIDEOUT_4F`). Si `ORBE` = 2 et `FLAG_HS_SAIT_ORBE` : Red l'apaise sans combat → `V` = 69. Sinon combat (Groudon niveau 60, au-dessus du plafond : la force seule est risquée), avec `B_FLAG_NO_WHITEOUT` posé : victoire → `V` = 69 ; défaite → `V` reste ≥ 70 (pas de retour au Centre, la scène continue).

**Issue du volcan `VO`** : `V` ≤ 39 → **MAÎTRISÉ** ; 40-69 → **LIMITÉE** ; ≥ 70 → **MAJEURE**.

### 8.2 Issue sociale `SO`
- **INTÉGRATION** si `CONSEIL_REFUGIES` = 1 et (`VO` ≠ MAJEURE ou `REP_REFUGIES` ≥ 60).
- **EXODE** si `CONSEIL_REFUGIES` = 3, ou (`VO` = MAJEURE et `REP_REFUGIES` < 40), ou `AFF_AUGUSTE` ≤ 30 et `VO` ≠ MAÎTRISÉ.
- **RELOGEMENT** sinon.

### 8.3 Rocket `RO`, Arche, Brice `BR`
- `RO` = **DÉMANTELÉE** si `FLAG_HS_LAMBDA_DEMASQUE` et `FLAG_HS_ARIANE_ARRETEE` ; sinon **EN FUITE**.
- Pertes de l'Arche : 0 si Red au camp et D109 ≠ fuite ; sinon 0 si (Brice ≥ 55 et Blue ≥ 60) ; faible si un seul des deux ; forte sinon (+ `ETAT_ROCKET` ≥ 60 → forte). Codes changés (D093 = 1) → un cran de moins.
- `BR` = **ALLIANCE** si `AFF_BRICE` ≥ 60 ; **RUPTURE** si ≤ 30 ; **DISTANCE** sinon.

### 8.4 Fins (ordre d'évaluation, exhaustif et exclusif)
1. **F5 « Ce qui reste »** : `VO` = MAJEURE **ou** `SO` = EXODE.
2. **F1 « Terre d'accueil »** : `VO` = MAÎTRISÉ **et** `SO` = INTÉGRATION.
3. **F2 « La paix armée »** : `VO` = MAÎTRISÉ **et** `SO` = RELOGEMENT.
4. **F3 « Cendres partagées »** : `VO` = LIMITÉE **et** `SO` = INTÉGRATION.
5. **F4 « La digue »** : `VO` = LIMITÉE **et** `SO` = RELOGEMENT.
Variantes d'épilogue (indépendantes) : `RO` (2), `BR` (3), Arche (`CONSEIL_ARCHE` × pertes), `NOTORIETE` (3), Lilou/Téo (2), Pikachu (2).

## 9. Budget flags / vars
| Usage | Estimation |
|---|---|
| Vars (systèmes, décisions structurantes, chapitre, mode) | **≈ 30** (55 libres + vars vanilla d'histoire libérées) |
| Flags de décisions (≈ 1,3 par décision) | ≈ 155 |
| Preuves, promesses | ≈ 20 |
| Visibilité PNJ/objets (camp, chantier, factions) | ≈ 70 |
| Quêtes | ≈ 20 |
| **Total flags** | **≈ 265** (372 libres) |

## 10. Qualité de vie
- **Combats déclinables** (fonction moteur, `ENGINE_CHANGES.md`) : certains dresseurs (marqués « déclinable » dans le registre) proposent un combat ; décliner a des effets (réputation, argent perdu).
- **Choix du Pokémon de tête** avant un combat (fonction moteur) : sert aussi des décisions discrètes (montrer un Pokémon de Kanto au camp, etc.).
- **Carnet de Red** (objet clé) : liste preuves, promesses et dernière piste (script `msgbox` selon flags) ; pas de chiffres.
- Chaussures de course dès le départ ; texte rapide par défaut ; `B_SPLIT_EXP` ; réapprentissage des capacités au labo ; VS Seeker et revanches **désactivés** avant le postgame (pas de farming) ; DexNav et Pokémon suiveurs désactivés ; PNJ suiveur activé (escorte Brice ch. 0) avec aperçu d'équipe désactivé.
