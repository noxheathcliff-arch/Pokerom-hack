# Revue critique — Gameplay, rythme, cohérence ludonarrative et faisabilité technique

> Objet : `GAME_DESIGN_BIBLE.md` v1.0, `bible/CHAPTERS.md`, `bible/WORLD.md`, `bible/CHARACTERS.md`.
> Critique indépendant. Spécialité : expérience joueur, rythme, cohérence histoire/mécanique, progression, faisabilité dans pokeemerald-expansion.
> Méthode : lecture complète de la bible, puis vérification des affirmations dans le code source (lecture seule, sans compiler). Pour la connexité de Site Météore, un parcours en largeur (BFS) des tuiles praticables à pied a été lancé sur `map.bin` + attributs de metatiles. Il ne gère qu'approximativement les rebords et les niveaux d'élévation.
> Sévérités : **BLOQUANT** = blocage de progression (softlock) ou contournement de séquence qui casse l'histoire si rien ne change ; **MAJEUR** = défaut de jeu ou de production qui dégrade nettement l'expérience ou le coût ; **MINEUR** = à corriger, sans risque structurel.

---

## Synthèse

Le squelette tient. Les cartes Hoenn reçoivent un vrai sens (planque Aqua → repaire des Veilleurs, Pilier Céleste → clocher), les serrures découlent de l'intrigue, et la plupart des affirmations sur le moteur sont exactes (`settotemboost`, `WE_FLAG_NO_CATCHING`, `OW_FLAG_PAUSE_TIME`, `B_VAR_DIFFICULTY`, PNJ suiveur, drapeaux d'IA). Il y a même mieux que prévu : le crochet C « N1 » est inutile, car `WE_FLAG_NO_ENCOUNTER` existe déjà.

En revanche, **la table de remplacement des événements vanilla (§17) est incomplète sur la seconde moitié du jeu**. Elle ignore la chaîne de portes Mt Mémoria → Planque Magma → port de Poivressel → Planque Aqua → Route 124. Elle omet aussi la CS Plongée. Elle place une escorte dans une salle inaccessible sans Surf. Enfin, les plafonds de niveau sont indexés sur les badges alors que trois boss majeurs se jouent entre deux badges. S'y ajoutent des problèmes de rythme : Méga trop tardive, combat de Juan après le climax, et six combats Dominants sur quatre espèces seulement.

---

## Constats

### 1. BLOQUANT — L'escorte d'Absol vise une salle inaccessible sans Surf
- **Lieu :** CHAPTERS ch. 6 §4 (« Absol devient PNJ suiveur jusqu'à `METEOR_FALLS_B1F_1R` »).
- **Problème :** au ch. 6, le joueur a 3 badges et pas de Surf (la CS Surf arrive au ch. 8).
- **Preuve :** `data/maps/MeteorFalls_1F_1R/map.json` contient les warps (27,18)→Route 114, (6,39)→Route 115, (10,3)→1F_2R, (5,4) et (26,28)→B1F_1R. Le BFS à pied lancé depuis l'entrée de la Route 114 atteint la Route 115, mais **aucun** warp vers B1F_1R ou 1F_2R. Ces accès passent par l'eau, comme dans le vanilla.
- **Impact joueur :** l'escorte est impossible à terminer (softlock), ou bien la production « triche » avec un warp scripté qui contredit l'espace du jeu.
- **Correctif :** faire toute l'escorte dans `METEOR_FALLS_1F_1R` (de l'entrée Route 114 au pont, puis vers la sortie Route 115), avec Rocheval 1 sur le pont. Réserver B1F au postgame (Cascade).

### 2. BLOQUANT — La chaîne de portes vanilla de l'acte III n'est pas remplacée : on peut sauter le climax de l'acte II
- **Lieu :** CHAPTERS §17, lignes « Planque Magma : aucune porte », « Planque Aqua : (scénario) », « Gemmes volées au Mont Mémoria : (scénario) ».
- **Problème :** en vanilla, ces événements **sont** des portes, enchaînées les unes aux autres :
  1. Sommet du Mt Mémoria → `FLAG_RECEIVED_RED_OR_BLUE_ORB` (`data/maps/MtPyre_Summit/scripts.inc:61`) → Emblème Magma → Planque Magma.
  2. Planque Magma → `FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT` (`MagmaHideout_4F/scripts.inc:62`) → vol du sous-marin au port de Poivressel, qui retire le garde de la Planque Aqua (`SlateportCity_Harbor/scripts.inc:73`, `setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE`).
  3. Planque Aqua → `FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS` (`AquaHideout_B2F/scripts.inc:50`). Ce drapeau retire les 5 sbires de Nénucrique (`LilycoveCity/map.json`, dont `WailmerTrainerGrunt` sur le rivage) qui bloquent le Surf vers la **Route 124 / Algatia**.
- La bible inverse l'ordre (repaire au ch. 10, Mont Mémoria au ch. 11, Algatia au ch. 12). Elle ferme la Planque Magma et ne mentionne ni le port de Poivressel ni les sbires de Nénucrique.
- **Impact joueur :** deux issues possibles. Soit le repaire n'ouvre jamais (garde de l'entrée jamais retiré : **softlock**). Soit, si la production branche le drapeau sur le repaire, la Route 124 s'ouvre au ch. 10 et le joueur va à Algatia **sans passer par le Mont Mémoria**. Il manque alors R3, Ysaline 1 et l'Absolite, et Pierre parle d'un carillon que le joueur ne comprend pas.
- **Correctif :** ajouter au §17 trois lignes explicites :
  - (a) entrée du repaire : garde retiré par `FLAG_HS_PREUVES_OK` (≥ 2 preuves) ;
  - (b) barrage de la Route 124 : réécrire les 5 objets de Nénucrique en Veilleurs (ou en marins « mer dangereuse ») et les retirer **au sommet du Mont Mémoria** (après Ysaline 1), pas à la fin du repaire ;
  - (c) neutraliser les scripts du port de Poivressel et de l'Emblème Magma.
- Problème de cohérence au passage : si ce sont des Veilleurs qui bloquent la Route 124, ils ne peuvent pas avoir été dissous au ch. 10. Il faut un autre bloqueur, par exemple un courant ou une brume figée devant la Route 124, ce qui donne une serrure vue de plus.

### 3. MAJEUR (risque de BLOQUANT) — CS Plongée : aucun personnage ne la remet
- **Lieu :** CHAPTERS ch. 12 §2 (« Chez Pierre : Méga-Bracelet… ») ; §17 sans ligne « Pierre → CS Plongée ».
- **Preuve :** en vanilla, Pierre remet `ITEM_HM_DIVE` chez lui (`MossdeepCity_StevensHouse/scripts.inc:40`), déclenché par l'événement du Centre Spatial, lui-même armé **après** le badge 7 (`MossdeepCity_Gym/scripts.inc:78-82` efface les drapeaux `HIDE_..._SPACE_CENTER_*`). La bible place le Centre Spatial **avant** l'arène 7.
- **Impact :** si l'on réécrit le script de la maison de Pierre pour le Méga-Bracelet sans reporter la CS Plongée, il n'y a plus de Plongée, donc ni Fondmer, ni Atalanopolis : softlock. Il faut aussi déplacer le déclencheur du Centre Spatial, aujourd'hui posé dans le script de l'arène.
- **Correctif :** ligne §17 « Pierre (maison) → CS Plongée + Méga-Bracelet, après le duo » ; armer le Centre Spatial à l'arrivée à Algatia (`VAR_MOSSDEEP_CITY_STATE`) et verrouiller l'arène tant que le duo n'est pas joué.

### 4. MAJEUR — Plafonds de niveau incohérents avec le moteur : le climax de l'acte II est trivialisé
- **Lieu :** BIBLE §8 et §11 H1 ; CHARACTERS (Rocheval 2 « cap 38 », Ysaline 1 « cap 38 »).
- **Preuve :** `src/caps.c:10-21` : `GetCurrentLevelCap()` renvoie le plafond de la **première entrée dont le drapeau n'est pas posé**, et la table vanilla ne contient que des badges. Après le badge 6 (Alizée, 38), le plafond devient donc celui de Lévy & Tatia (44). Rocheval 2 et Ysaline 1, prévus à 38, se jouent pendant que le joueur peut monter à 44, d'autant plus vite que la bible active `B_LEVEL_CAP_EXP_UP` (qui augmente l'expérience sous le plafond). Même chose pour Tierce (ch. 5, après le badge 3 : plafond 29, pas 24).
- Par ailleurs, la table du code (15/19/24/29/**31/33/42/46**/58) ne correspond pas à celle de la bible (15/19/24/29/33/38/44/50/58), et `B_EXP_CAP_TYPE` / `B_LEVEL_CAP_TYPE` valent `NONE` (`include/config/caps.h:14-15`).
- **Impact :** le duel avec Ysaline au sommet du Mont Mémoria, pic émotionnel de l'acte II, se joue avec 6 niveaux d'avance. L'antagoniste paraît faible au moment où elle doit inquiéter.
- **Correctif :** `sLevelCapFlagMap` accepte n'importe quel drapeau. Insérer des paliers d'histoire : `{FLAG_BADGE06_GET,38}, {FLAG_HS_ROCHEVAL2,40}, {FLAG_HS_YSALINE1,42}, {FLAG_BADGE07_GET,44}…`. Recalculer les boss hors badge avec la règle « écart ≤ +2 » sur le palier **réellement actif** à ce moment-là.

### 5. MAJEUR — Séquence ouverte : F2 et R1 jouables dès le badge 2
- **Lieu :** CHAPTERS ch. 4-5 ; §18 serrure n°3.
- **Problème :** F2 s'aborde par l'**entrée est** du Tunnel Mérazon, accessible à pied depuis Lavandia → Route 117 → Vergazon, sans Éclate-Roc. Le joueur qui sort de Poivressel (badge 2) peut aller à Vergazon avant Voltère. La clé « Éclate-Roc » de la serrure n°3 n'ouvre donc rien d'indispensable, puisque c'est Ysaline qui dégage le passage. De plus, §8 fait enseigner « statut et tempo » par les Carillonneurs du tunnel **avant** Voltère, alors que le ch. 5 place Voltère d'abord.
- **Impact :** R1 et Tierce (pensée pour le plafond 29) affrontés au plafond 24 ; ordre pédagogique incohérent.
- **Correctif :** soit verrouiller F2 jusqu'à `FLAG_BADGE03_GET` (ouvrier de Vergazon : « Personne n'entre tant que le champion n'a pas donné son accord »), soit assumer l'ordre libre et calibrer Tierce sur le plafond 24. Remplacer la serrure n°3 par une vraie serrure ou la supprimer de la table.

### 6. MAJEUR — Méga-Évolution trop tardive pour porter la thèse mécanique
- **Lieu :** BIBLE §2 (« le joueur progresse par le changement… Méga ») et §7 ; Méga-Bracelet au ch. 12 (14:00 sur 20:00).
- **Problème :** l'unique gimmick, présenté comme l'antithèse sémiotique des Figements, n'est disponible qu'à 70 % de l'aventure. Pendant 14 heures, rien dans les mécaniques ne dit « changer pour dépasser », hormis l'évolution ordinaire. L'Absolite (ch. 11) reste inutilisable un chapitre. Sept des neuf gemmes de l'aventure arrivent entre les ch. 12 et 14, en rafale, juste avant une suite de boss à Méga (Lévy & Tatia, Juan, rival, Conseil 4, Maître).
- **Impact :** la phase 7 de l'arc de maîtrise est comprimée ; le joueur apprend la Méga sous pression, en 2 heures, et n'a pas le temps de construire une équipe autour.
- **Correctif :** déplacer la démonstration et le Méga-Bracelet au **ch. 9, Route 120** (Pierre y est déjà en vanilla pour le Scope Devon), par exemple avec un duo contre Bourdon. Garder la montée en puissance (gemmes rares) mais l'étaler : Absolite au ch. 10 ou 11, gemme du starter au ch. 9. Alizée et Ysaline 1 deviennent les premiers tests « Méga contre un adversaire qui refuse de changer ».

### 7. MAJEUR — Juan (badge 8) arrive après la catharsis, et son IA est plus faible que celle d'Ysaline 2
- **Lieu :** CHAPTERS ch. 15 §6 ; BIBLE §8 phase 8 (« adaptation à une IA qui s'adapte », vérifiée par Ysaline 2 **et** Juan) ; CHARACTERS §15 (Juan : `Smart Switching / Ace Pokemon / HP Aware / Assume Stab`).
- **Problème :** juste après la mort d'Augure à l'aube, le joueur enchaîne un combat d'arène sans enjeu narratif. Le profil d'IA de Juan n'a ni `Basic Trainer` (`CHECK_BAD_MOVE`, `TRY_TO_FAINT`, `CHECK_VIABILITY` : `include/constants/battle_ai.h:46`) ni `Prediction`, alors qu'Ysaline 2 a `Smart Trainer` (omniscient) et `Prediction`. Le « vérificateur » de la phase 8 est donc plus facile que le combat qui le précède.
- **Impact :** courbe de difficulté inversée et retombée émotionnelle (dissonance entre l'histoire et le jeu).
- **Correctif :** faire de Juan l'épreuve d'**avant** le Pilier : Atalanopolis ne se fige qu'à demi, Juan se bat dans son arène isolée et remet la CS Cascade nécessaire pour monter au clocher. Une variante : il exige le badge avant d'ouvrir l'accès. Ysaline 2 devient le dernier boss de l'aventure avant la Ligue. Ajouter au minimum `Basic Trainer` à Juan.

### 8. MAJEUR — Six combats Dominants sur quatre espèces : structure répétitive
- **Lieu :** WORLD §1.1.7, §1.2 ; F1 Archéomire, F2 Korillon, F3 Archéodong, F4 Éoko, F-opt1 Archéomire, F5 Archéodong.
- **Problème :** chaque Figement suit le même enchaînement : Carillonneurs → Dominant +1 Déf/DéfSpé → Diapason. Archéomire et Archéodong (Acier/Psy, Lévitation/Ignifu-Voile) reviennent chacun deux fois. Augmenter les défenses ne « punit » pas le joueur qui fonce : cela allonge seulement le combat (WORLD §1.3 prétend le contraire). Contre un Archéodong à Ignifu-Voile, au Mont Chimnée, la lignée de Poussifeu est neutralisée dans la zone même où elle devrait briller.
- **Impact :** lassitude dès F3, sentiment de « donjon tamponné ». La promesse « chaque Figement ajoute une contrainte » est tenue pour F3 (évacuation) et F5 (marées), mais pas pour F1, F2, F4 et F-opt1.
- **Correctif :** un pivot différent par Figement, avec une règle propre :
  - F1 Archéomire seul (tutoriel) ;
  - F2 Korillon + 2 Chuchmur figés qui se « réveillent » (Dominant en double) ;
  - F3 Archéodong sous soleil forcé (`settotemboost` Vitesse) ;
  - F4 Éoko qui lance Requiem au tour 1 (compte à rebours = le temps) ;
  - F5 sans Dominant : un puzzle de marées.
- Supprimer F-opt1 ou en faire un Figement **sans** combat, où l'indice vient de l'absence d'Absol.

### 9. MAJEUR — Absol en double : membre de l'équipe et messager sur la carte
- **Lieu :** CHARACTERS §9 (`givemon` au ch. 6) ; CHAPTERS ch. 9 §1 (Absol sur le pont), ch. 13 §4, ch. 15 §3, épilogue.
- **Problème :** si le joueur a accepté Absol, un Absol continue d'apparaître sur la carte « la veille » des Figements suivants et au sommet du Pilier. Rien ne dit s'il s'agit du même. Si c'est le même, il est à la fois dans la Poké Ball et sur un rocher.
- **Impact :** dissonance ludonarrative sur la créature emblème. Le joueur qui l'a dans son équipe se demande pourquoi « son » Absol ne réagit pas.
- **Correctif :** au choix :
  - (a) le don est un **jeune Absol** (« il a laissé son petit avec toi »), tandis que l'adulte reste messager ;
  - (b) si Absol est dans l'équipe (`checkpartymon`/`getpartysize` via `special`), les apparitions de veille deviennent des réactions du Pokémon de l'équipe (cri, message « Absol fixe l'ouest »), ce qui renforce le lien.

### 10. MAJEUR — Règle « soin à une carte au plus de l'entrée » violée presque partout
- **Lieu :** BIBLE §9 ; WORLD §1.2 (« Soin : aucun dans la zone ; point de soin ≤ 1 carte »).
- **Preuves :**
  - Bois Clémenti : il faut traverser 2 cartes (Route 104 puis Clémenti) pour rejoindre le Centre de Clémenti, idem vers Mérouville.
  - Mont Chimnée : le Centre le plus proche est à 2 cartes ou plus (Chemin Ardent puis Vermilava, ou téléphérique puis Route 112).
  - Fondmer : 9 salles, sans soin.
  - Pilier Céleste : Pacifiville → Route 131 → entrée → extérieur → 1F-5F → sommet, soit au moins 8 cartes. Bourdon 2 et Ysaline 2 s'y enchaînent sans soin.
  - À l'inverse, l'Institut Météo a un **lit qui soigne** à l'intérieur même du Figement (`Route119_WeatherInstitute_1F/scripts.inc:53-57`, `Common_EventScript_OutOfCenterPartyHeal`).
- **Impact :** la boucle « entrer préparé » devient « recommencer depuis le Centre ». La défaite contre Ysaline 2 renvoie au pied d'une tour de 8 cartes, ce qui dissuade d'expérimenter, à l'opposé de l'intention « observer, tester ».
- **Correctif :** un **PNJ soigneur aux abords de chaque Figement** (Gaspard, ou les Veilleurs repentis après R2, ce que CHARACTERS §10 annonce déjà). Soin complet avant Ysaline 2 (Gaspard, PNJ suiveur, soigne en haut de l'escalier). Neutraliser le lit de l'Institut tant que `FLAG_FIG_4_ACTIF` est posé.

### 11. MAJEUR — Atalanopolis figée : Centre Pokémon, point de réapparition, Vol et absence de cloche-pivot
- **Lieu :** CHAPTERS ch. 14 §1 ; invariant 7 (BIBLE §12).
- **Problèmes :**
  - (a) Un joueur passé à Atalanopolis avant Fondmer (Plongée dès le ch. 12) a pu enregistrer `HEAL_LOCATION_SOOTOPOLIS_CITY` (`SootopolisCity_PokemonCenter_1F/scripts.inc:7`). Une défaite ou un Vol le renvoie alors dans un Centre figé, avec une infirmière immobile.
  - (b) La porte d'arène reste fermée par `FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE` (`SootopolisCity/scripts.inc:10`, `LockGymDoor`), un drapeau que seul le script vanilla des titans pose. Le glas doit le poser explicitement.
  - (c) F6 ne contient pas de cloche-pivot, ce qui contredit l'invariant 7 (« chaque Figement contient une cloche-pivot »).
  - (d) Incohérence d'espace : Marc est dit « hors du cratère » (synopsis), alors que l'entrée de la Grotte Origine est **dans** le cratère.
- **Correctif :** Centre d'Atalanopolis exclu du Figement (« zone préservée », comme la Grotte Origine), ce qui donne un point de soin ; `setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE` dans le script du glas ; amender l'invariant 7 (« sauf Figement-conséquence ») ; Marc placé devant la Grotte Origine, dans le cratère.

### 12. MAJEUR — Pilier Céleste : « sols fissurés, Vélo Cross » est faux, et dangereux avec un PNJ suiveur
- **Lieu :** CHAPTERS ch. 15 §1 ; ch. 14 §3 (Gaspard en PNJ suiveur).
- **Preuves :**
  - En vanilla, les sols ne sont fissurés **qu'après** la crise. `SkyPillar_2F/scripts.inc:8` charge `LAYOUT_SKY_PILLAR_2F_CLEAN` tant que `VAR_SKY_PILLAR_STATE < 2`, et la valeur 2 est posée par Atalanopolis (`SootopolisCity/scripts.inc:560`). Le vélo requis est d'ailleurs le **Vélo Course** (Mach Bike), pas le Vélo Cross.
  - Surtout, le PNJ suiveur force le joueur à descendre de vélo si l'option `FNPC_BIKE` n'est pas posée (`src/follower_npc.c:233-236`), et `OBJ_EVENT_GFX_MANIAC` n'a pas de sprite à vélo dans `gFollowerNPCAlternateSprites`.
- **Impact :** si la production applique la lettre de la bible (sols fissurés + Gaspard qui suit), il devient impossible de franchir les fissures : softlock.
- **Correctif :** garder les layouts `_CLEAN` pendant l'ascension (`VAR_SKY_PILLAR_STATE` < 2) et poser l'état 2 seulement après le glas, pour la capture postgame de Rayquaza au Vélo Course. Corriger le texte.

### 13. MAJEUR — Heure suspendue (H4) : `OW_FLAG_PAUSE_TIME` impose une horloge factice globale
- **Lieu :** BIBLE §11 H4 ; WORLD §1.2 (« Heure »).
- **Preuve :** `include/config/overworld.h:93-94,110`. `OW_FLAG_PAUSE_TIME` n'a d'effet que si `OW_USE_FAKE_RTC` vaut TRUE, et l'horloge factice avance alors selon `OW_ALTERED_TIME_RATIO` (`GEN_LATEST`, soit 20 s de jeu par seconde réelle : une journée dure environ 72 min). Ce choix change **tout le jeu** : baies, drapeaux quotidiens, marées de la Grotte Tréfonds (`src/time_events.c:54`, `UpdateShoalTideFlag`), rencontres par moment de la journée (H4 activé), apparition nocturne d'Absol (ch. 4). Par ailleurs, `OW_ENABLE_DNS TRUE` (FEATURE_INVENTORY) teinte l'écran selon l'heure : le « bois figé au crépuscule » sera éclairé comme à midi si l'on y joue à midi.
- **Impact :** soit l'horloge accélérée bouleverse l'économie et les cycles du jeu, soit le « temps suspendu » n'est qu'un mot.
- **Correctif :** décider tôt. Option A : fake RTC au ratio `TIME_DEBUG` (1:1), pause dans les Figements, et accepter que l'horloge ne tourne pas console éteinte. Option B : pas de fake RTC ; on « suspend » seulement la teinte DNS, en forçant une palette fixe sur les cartes figées (à vérifier dans `src/dns.c`, exclusions par carte). Dans les deux cas, pour F5, forcer la marée basse par script et non par l'horloge.

### 14. MAJEUR — Recyclage des drapeaux et variables vanilla : risque d'effets fantômes
- **Lieu :** CHAPTERS §20 (« ~60 flags, recycler les `HIDE_*` Magma/Aqua » ; « recycler `VAR_*_STATE` »).
- **Preuve :** ces drapeaux et variables sont posés ou effacés **ailleurs** que sur leur carte : par exemple `MossdeepCity_Gym/scripts.inc:78-82` efface les `HIDE_*_SPACE_CENTER_*`, et `SlateportCity_Harbor` pose un drapeau de la Planque Aqua. Au total, 73 `scripts.inc` mentionnent Magma, Aqua ou leurs admins.
- **Impact :** des PNJ apparaissent ou disparaissent hors contexte ; les bogues sont difficiles à reproduire.
- **Correctif :** n'utiliser **que des drapeaux neufs** (372 libres, le budget de 120 tient largement). Partager un même drapeau de masquage entre tous les PNJ figés d'un Figement (2 drapeaux par Figement suffisent : actif / délivré). Une variable vanilla n'est recyclée que si **tous** ses lecteurs et écrivains sont réécrits (audit par grep obligatoire, consigné).

### 15. MAJEUR — Le budget d'ID de dresseurs est faux pour les lieutenants et le rival final
- **Lieu :** CHAPTERS §17 (« aucun nouvel ID requis ») ; CHARACTERS §12.1, §2.
- **Preuves** (`include/constants/opponents.h`) :
  - Matthieu (`TRAINER_MATT`, l.37) n'a **qu'un** ID, alors que Bourdon combat 3 fois (Institut, Centre Spatial, Pilier).
  - Sarah (Shelly) a 2 ID ; Tierce en demande 3 (Tunnel, Centre Spatial, Épave).
  - Le stock d'ID nommés est de 10 (Max ×3, Arthur ×1, Matthieu ×1, Sarah ×2, Kelvin ×3) pour au moins 10 combats d'histoire (Ysaline 2, Rocheval 2, Bourdon 3, Tierce 3), plus les revanches postgame.
  - Le rival final exige **6** ID (2 genres × 3 starters, comme le vanilla : 32 ID `BRENDAN/MAY`). « L'ID du dernier combat de Timmy » ne suffit pas ; il faut les 6 ID de Timmy (`WALLY_MAUVILLE`, `VR_1..5`).
  - Les 53 ID `GRUNT` couvrent mal les besoins estimés de 65 à 75 Carillonneurs et Veilleurs (Bois, sortie du Bois, Routes 104/110/112/114, Site Météore, Tunnel, Chimnée, Institut, repaire, Mont Mémoria, Tréfonds, Fondmer, Pilier, F-opt1).
- **Correctif :** tableau d'affectation ID par ID dans la bible, avec décompte. Récupérer les dresseurs vanilla supprimés (Timmy, ID Aqua/Magma de la Planque Magma fermée) et, au besoin, monter `MAX_TRAINERS_COUNT` : c'est un jeu neuf, la compatibilité de sauvegarde ne compte pas (TECHNICAL_AUDIT, risque 5).

### 16. MAJEUR — Le Centre Spatial, « introduction sûre » de la Méga, est en réalité un combat piégeux
- **Lieu :** CHAPTERS ch. 12 §1 ; BIBLE §7 (« introduction sûre, GM_METHOD §4.9 »).
- **Problème :** le combat en duo oppose Bourdon (Distorsion, lents puissants) et Tierce (Requiem + Abri). Distorsion et Requiem en double, plus un partenaire IA, forment l'une des configurations les plus confuses du jeu. Ce n'est pas le cadre où l'on découvre une mécanique.
- **Correctif :** le combat de démonstration se joue contre des Carillonneurs ordinaires ; Bourdon et Tierce interviennent ensuite, en simple, après l'obtention du bracelet. Ou bien Pierre joue seul la Méga sous les yeux du joueur, sans enjeu.

### 17. MAJEUR — Décor impossible sans art neuf : colonne de lave figée et rideau de pluie
- **Lieu :** CHAPTERS ch. 7 §1 (« colonne de lave figée en plein jet : re-habillage par objets/PNJ ») et ch. 9 §1 (« objets/PNJ "pluie" bloquants ») ; BIBLE §10 (« 0 PNG neuf obligatoire »).
- **Preuve :** aucun graphisme d'objet de lave, de pluie ou de gouttes dans `include/constants/event_objects.h` (le grep ne renvoie que `FIRE_CUSHION`, les nageurs, etc.). Il n'y a pas d'éditeur graphique dans l'environnement (TECHNICAL_AUDIT).
- **Impact :** les deux images-signatures de l'acte II tombent, ou bien elles exigent des metatiles et des sprites neufs, ce qui contredit la contrainte.
- **Correctif :** lister ces deux éléments comme **dérogation art** chiffrée, ou les remplacer par des solutions déjà disponibles : `WEATHER_VOLCANIC_ASH` figé + `WEATHER_FOG` + PNJ figés « bras levés », et pour la pluie `WEATHER_RAIN` (ou `DOWNPOUR`) bloquée + rochers ou arbres « non franchissables », plus un message.

### 18. MINEUR — N1 : le crochet C est inutile, le moteur l'offre déjà
- **Lieu :** BIBLE §10 et §11 N1 ; WORLD §1.2.
- **Preuve :** `include/config/wild_encounter.h:6` `WE_FLAG_NO_ENCOUNTER` (« wild encounters will be disabled ») ; aussi `WE_FLAG_NO_CATCHING` (l.16) et `WE_FLAG_NO_RUNNING` (l.17). FEATURE_INVENTORY le documente pourtant (l.46).
- **Correctif :** assigner `WE_FLAG_NO_ENCOUNTER` à un drapeau temporaire posé en `ON_TRANSITION`. Ajouter `WE_FLAG_NO_RUNNING` pendant le combat contre la cloche-pivot : sinon le joueur fuit le Dominant puis utilise le Diapason, à moins que le script ne vérifie `B_OUTCOME_WON`. Vérifier que la pêche, Éclate-Roc et Doux Parfum respectent aussi ce drapeau. Effacer `WE_FLAG_NO_CATCHING` après le combat. Retirer le « crochet (a) » des contraintes de code.

### 19. MINEUR — Fausses notes factuelles sur le vanilla
- Chemin Ardent noté « facultatif » au ch. 6, alors qu'il est **obligatoire** pour passer de la Route 112 sud à la Route 113 tant que le téléphérique est barré.
- « Sortie par plongée (Chenal 126) » au ch. 13 : l'entrée et la sortie de Fondmer sont sous la Route 128.
- La CS Surf était remise par le père de Timmy (correct), mais Timmy à Lavandia bloque aussi l'arène 3 (`MauvilleCity/scripts.inc:86+`) et déclenche la libération du Tunnel Mérazon (`VAR_RUSTURF_TUNNEL_STATE` 4-5, `ClearTunnelScene`). À ajouter au §17.
- R2 placée au « ch. 11 » dans BIBLE §13 et CHARACTERS §10, au ch. 10 dans CHAPTERS.
- Vœu introduit au Mont Chimnée (ch. 7), alors que CHARACTERS §12 dit « Institut : Abri/Vœu ».
- CHARACTERS §10 : les Veilleurs « évacuent Atalanopolis », alors que la ville est figée avec ses habitants.

### 20. MINEUR — Enquête R2 sans vraie décision
- **Lieu :** CHAPTERS ch. 10 §3.
- **Problème :** deux preuves suffisent, et les deux preuves obligatoires (Cosmo au ch. 6, relevés de l'Institut au ch. 9) se trouvent sur le chemin principal. Le joueur réussit l'« enquête » sans rien chercher ; New Lavandia et la page du Pokédex ne servent qu'au dialogue bonus.
- **Correctif :** rendre le témoignage de Cosmo **facultatif** (il faut lui parler) et exiger 3 preuves sur 4. Ou bien faire choisir au joueur, devant Rocheval, la preuve qui réfute **sa** croyance (`multichoice`, mauvaise preuve = réplique de Rocheval et nouvel essai). C'est le geste « observer, formuler une hypothèse » de l'intention.

### 21. MINEUR — Le combat contre le pivot F1 pénalise le starter Arcko
- **Lieu :** CHAPTERS ch. 1 §6 (Archéomire Dominant +1 Déf, avant le badge 1).
- **Problème :** l'Acier résiste à Plante et à Normal. Arcko, vers le niveau 12 (Écras'Face, Groz'Yeux, Vol-Vie, Vive-Attaque), n'a presque rien d'efficace contre le pivot ; les rencontres possibles avant ce combat (Zigzaton, Medhyèna, Chenipotte…) aident peu. Le premier combat obligatoire « de règle » devient une affaire de PP.
- **Correctif :** pivot F1 = Korillon (Psy pur, battable par Morsure et par tout le monde), ou Archéomire boosté en Vitesse plutôt qu'en Défense, avec un niveau de 2 sous le plafond. Archéomire et Archéodong passent plus tard.

### 22. MINEUR — Monotonie des dresseurs à mécanique « temps »
- **Problème :** CHARACTERS §12 prévoit la Distorsion « utilisée systématiquement » au Mont Mémoria (environ 8 combats) et « Requiem au complet » dans Fondmer (9 salles sans soin). Chaque combat sous Distorsion ou Requiem dure plus longtemps et se ressemble.
- **Correctif :** au plus 1 dresseur sur 3 porte la mécanique signature ; les autres préparent la contre-mesure (Pokémon lents, Changement…). C'est la logique « enseigner → vérifier » de §8.

### 23. MINEUR — Points techniques à préciser
- `givemon` Absol au « niveau = plafond − 2 » : il n'existe pas de commande de script qui lise le plafond ; il faut un `callnative` ou un `special` sur `GetCurrentLevelCap()` (`src/caps.c:8`).
- PNJ suiveur : `FNPC_ENABLE_NPC_FOLLOWERS FALSE` (`include/config/follower_npc.h:5`) ; il coûte un peu de SaveBlock3 (`include/global.h:262`). Compatible avec le budget (SB3 : 1 623 o libres), mais `FNPC_NPC_FOLLOWER_PARTY_PREVIEW TRUE` affichera un aperçu d'équipe avant chaque combat de dresseur pendant l'escorte : à désactiver.
- Expert (`B_VAR_DIFFICULTY`, `include/config/battle.h:272`) : chaque boss existe en double dans `.party`, et il faut appeler `Script_SetDifficulty` **après** `NewGameInitData`, puisque le choix se fait au labo.
- `settotemboost` existe (`asm/macros/event.inc:2221`) et `ITEM_MEGA_RING` est bien vérifié par le moteur (`src/battle_util.c:8479`) : rien à signaler.
- Graphismes : le portrait `TRAINER_PIC_ELITE_FOUR_AGATHA_FRLG` existe (`include/constants/trainers.h:161`), de même que `OW_POKEMON_OBJECT_EVENTS TRUE` (Xatu, Absol, Goélise utilisables comme PNJ).

---

## Rythme global

| Segment | Durée cible | Constat |
|---|---|---|
| Prologue + acte I | 0:00–6:00 | Bon : F1 apprend la règle, R1 tombe au ch. 5. Risque : F2 accessible trop tôt (n°5). |
| Acte II | 6:00–14:00 (8 h, 6 chapitres) | Trop long, et le ch. 8 est un creux (Norman, puis uniquement du facultatif). Trois Figements de même structure (n°8). Méga absente (n°6). Recommandation : passer le Méga-Bracelet au ch. 9 et fusionner les ch. 8 et 9. |
| Acte III | 14:00–20:00 | Dense : Méga, Tréfonds, Fondmer, Atalanopolis et Pilier en 6 h, avec trois chapitres sans soin (n°10). Juan arrive après la catharsis (n°7). |
| Finale | 20:00–22:00 | Correct ; le dernier combat contre le rival, avec Méga, rend la thèse sur le changement lisible. |

Estimation réaliste : 25 à 30 h pour un joueur moyen, compte tenu des évacuations, des allers-retours en téléphérique et des donjons sans soin. La cible de 22 h est optimiste.

---

## Notes sur la grille EXPERIENCE_INTENT §9.2

| Critère | Note /5 | Justification |
|---|---|---|
| **C7 Adéquation moteur / assets** (poids 10) | **3** | Points forts : les cartes existantes prennent un sens (repaire, clocher, Mont Mémoria), les fonctions du moteur sont réelles et vérifiées (totem, drapeaux de rencontre et de capture, PNJ suiveur, difficulté, IA), et la Méga a une raison dans la fiction. Points faibles : deux images-signatures demandent de l'art inexistant (n°17), le « temps suspendu » se heurte à l'horloge et au DNS (n°13), et la chaîne de portes vanilla est mal comprise (n°2, 3, 12). |
| **C8 Exploitation ludique de l'histoire** (poids 14) | **3** | L'intrigue est bien la progression : Figements comme portes, escorte, évacuation, preuves, marées, plafonds associés aux combats. Mais l'enquête se résout sans décision (n°20), cinq Figements sur sept ont la même structure (n°8), la mécanique centrale du « changement » arrive à 70 % du jeu (n°6), et Absol en double fausse le symbole (n°9). Avec les corrections n°6, 8 et 20, le critère vaut 4. |
| **C10 Faisabilité GBA (coût réel)** (poids 6) | **2** | Aucune carte neuve et peu de C, ce qui est bien. Mais le volume de script et de texte est celui d'un remake complet de l'histoire d'Émeraude (voir ci-dessous) ; les ID de dresseurs sont sous-estimés (n°15) ; le recyclage des drapeaux est risqué (n°14) ; et le mode Expert double le travail d'équilibrage. Sans éditeur de cartes, chaque PNJ figé est une modification de `map.json` faite à la main. |

---

## Estimation du volume de production

| Poste | Volume estimé | Base |
|---|---|---|
| `scripts.inc` à réécrire en profondeur (remplacement d'événement) | **45 à 55 cartes** | §17 + chapitres (Bois, Devon ×3, Grotte Granite, Musée ×2, Lavandia, Tunnel, Route 112 + gares, Site Météore ×2, Chimnée, Chemin Ardent, Vermilava, Clémenti/Timmy, Institut ×2, Route 119, Nénucrique + musée, repaire ×3, Mont Mémoria ×8, Algatia + Centre Spatial ×2 + Pierre, Tréfonds ×4, Fondmer ×10, Atalanopolis, Pilier ×8) |
| `scripts.inc` à purger (références Magma/Aqua/Timmy/Pierre) | **73 + 7 + 15** fichiers (en partie communs) | grep `MAXIE|ARCHIE|TABITHA|SHELLY|MATT|GRUNT|AQUA|MAGMA`, `WALLY`, `STEVEN` |
| `map.json` modifiés (PNJ figés en doublon, Carillonneurs, Veilleurs, objets suspendus) | **60 à 80** | 7 à 9 zones figées × 8-15 objets + routes des Veilleurs |
| Équipes de dresseurs (`.party`) écrites ou réécrites | **≈ 130 en Normal + ≈ 35 boss en Expert ≈ 165 blocs** | 53 sbires + 10 admins/chefs + 30 rival + 6 Timmy + 8 champions + 5 Ligue + ~10 ID supplémentaires pour Carillonneurs/Veilleurs |
| Textes | **≈ 1 800 à 2 500 boîtes** (≤ 208 px, 2 lignes) | ~100 dresseurs × 3 répliques + scènes (environ 40 scènes de 15 à 40 boîtes) + PNJ de ville réécrits + Carnet |
| Code C / config | **≈ 150 à 300 lignes** | table des plafonds, cases `GetBattleBGM`, 2-3 classes, `special` niveau d'Absol, configs (`WE_FLAG_*`, `FNPC`, caps, difficulté, éventuellement fake RTC) |
| Art | **0 obligatoire selon la bible, en réalité 2 dérogations** (lave figée, rideau de pluie) ou repli météo | n°17 |

**Postes trop coûteux pour leur rendement (à couper ou réduire) :**
1. **F-opt1 New Lavandia** : un Figement complet pour une preuve facultative. À remplacer par une scène de constat sans combat.
2. **Mode Expert** : à limiter aux 8 champions, au Conseil 4, au Maître et à Ysaline, et à produire après le jeu Normal (c'est déjà prévu ; à graver dans la bible).
3. **Atalanopolis entière figée** (56 `msgbox` vanilla, 9 maisons, tous les PNJ en double) : figer seulement l'anneau extérieur et fermer les maisons (les métatiles de portes fermées existent déjà, `SootopolisCity/scripts.inc:17-27`).
4. **Quêtes A4 et A5** (Tour Mirage avec choix, 6 anciens chasseurs) : à remettre après la tranche verticale.
5. **Fondmer** : 5 panneaux de Braille sur 10 salles réécrites. À recentrer sur 3 salles signifiantes ; les autres gardent leur texte vanilla et se vident d'Aqua.

**Tranche verticale recommandée avant tout volume :** ch. 0-1 (F1 complet : `WE_FLAG_NO_ENCOUNTER`, Dominant, Diapason, PNJ figés, objet suspendu, délivrance) + ch. 6 (escorte avec PNJ suiveur, corrigée selon le n°1) + le tableau des plafonds avec paliers d'histoire (n°4). Ces trois éléments tranchent les risques n°1, 4, 13, 14 et 18.
