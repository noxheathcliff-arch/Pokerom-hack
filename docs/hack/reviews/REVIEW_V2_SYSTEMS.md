# REVIEW V2 — Systèmes et faisabilité (critique indépendante)

> Périmètre : `DECISION_LEDGER.md` + `_ACT1/2/3`, `GAME_SYSTEMS.md`, `GAME_DESIGN_BIBLE.md` §6 et §10, `TECHNICAL_AUDIT.md` §7, `ENGINE_CHANGES.md`, `FLAGS_VARS_REGISTRY.md`. Vérifications ponctuelles dans le source (lecture seule, sans `make`).
> Grille : **VALIDE** (l'état est lu plus tard et produit un effet observable non cosmétique, ou l'effet immédiat est substantiel : objet, combat, accès, PNJ) · **FAIBLE** (effet limité à une ligne, à un compteur que rien ne lit, ou à un seuil franchi de toute façon) · **DOUBLON** (même effet qu'une autre décision) · **NON-IMPL.** (impossible tel que spécifié avec le moteur actuel) · **NON-TESTABLE**.
> Verdict global : **le plancher de 101 n'est pas atteint.** 80 décisions sont VALIDE telles qu'écrites (74 en lecture stricte). La marge annoncée (+19) n'existe pas. On peut atteindre environ 112 décisions robustes avec environ 10 jours-personne de câblage, sans nouvelle carte (§3).

---

## 1. Verdict par décision

| ID | Verdict | Raison / correctif |
|---|---|---|
| D001 | VALIDE | 3 états distincts (PNJ chez M. Marcel, Lilou au camp, Ernest informateur → D025 c). |
| D002 | VALIDE | Date de retour de Pikachu (ch. 4 ou 5) et accès à D038. Définir la valeur de `VAR_HS_PIKACHU` au retour du ch. 5 (voir S19). |
| D003 | VALIDE | Scène du ch. 13 et épilogue. Discrète : donner un indice (« Lilou grelotte ») pour qu'on pense à parler deux fois. Ajouter un garde « une seule fois » sur le delta. |
| D004 | VALIDE (fragile) | Scène immédiate distincte et B ±5. La suite (D045) n'est qu'une ligne. |
| D005 | VALIDE | `NOTORIETE` ouvre ou ferme des défis, le vote de Marc, le piège du ch. 10 et l'épilogue. |
| D006 | VALIDE (fragile) | Starter vanilla : réel en jeu, mais ce n'est pas une décision narrative. Le rR+2 de Poussifeu est décoratif. |
| D007 | VALIDE | Colis du ch. 2 et condition de D053. La conséquence aval (D053) est elle-même inopérante (voir D053). |
| D008 | FAIBLE | Point de réapparition et une ligne au ch. 7. Correctif : en faire la condition de D070 (dîner) ou de l'option b de D100. |
| D009 | FAIBLE | « D067 plus crédible » n'est défini nulle part ; le reste se limite à des lignes. Correctif : a → Marc vote sans condition de notoriété (motion 1). |
| D010 | VALIDE | Trois états de la propriétaire au ch. 3, CT, Pokémon dans l'Arche (motion 3). |
| D011 | FAIBLE | « Interrogatoire plus court » relève du rythme ; Rk ±5 n'est lu par rien de précis (S6). Correctif : badge gardé → l'option c de D092 (fuite) devient impossible, ou Rk lu au climax. |
| D012 | NON-IMPL. + FAIBLE | Refus de combat sans point d'accroche (S2) ; effet limité à une ligne. À retirer du décompte ou à fusionner. |
| D013 | VALIDE | CT et passage à N=2 (piège Rocket du ch. 10). |
| D014 | VALIDE | Affiche, hostilité d'Arthur, accès D055 (c), rM/rA ±10. |
| D015 | VALIDE | Débloque D026 b/c. Attention : `PREUVE_PLANS_PROFONDS` n'est dans aucune liste de preuves du §5 ; la lier à `PRESSION_DEVON`. |
| D016 | VALIDE | Ouvre D017. « D040 facilité » n'est pas défini. |
| D017 | DOUBLON | Même effet que D039 (« raid mieux préparé »). Correctif : les traces révèlent la sortie secrète → en D040 b, Rocket ne peut plus fuir avec la moitié des Pokémon. |
| D018 | FAIBLE | Seul effet : C+5 sur un compteur au seuil trivial (S6). |
| D019 | VALIDE | Méga-Gemme et enfants suiveurs. |
| D020 | VALIDE | Vote de Pierre sur la motion 2. |
| D021 | FAIBLE | −500 ₽ et une ligne au Conseil. Correctif : c → Brice peut négocier D081 c sans le seuil rR. |
| D022 | NON-IMPL. | Refus non stockable (S2). Une fois le crochet ajouté, devient VALIDE si Matthieu sert de contact pour D081. |
| D023 | VALIDE (fragile) | Débloque la lettre du postgame (D119). Le contenu est mince. |
| D024 | VALIDE | Échange d'objets (gemme maintenant ou objet rare au ch. 8). |
| D025 | VALIDE | Trois issues, C−10, vivres, Aqua amer. |
| D026 | VALIDE | Marin allié → D098. Option c : `FLAG_DELIVERED_DEVON_GOODS` a 6 lecteurs vanilla à auditer (S15). |
| D027 | FAIBLE | AU+5/C+2 et une ligne au ch. 6. Correctif : le Ponyta de Lilou aide à l'éboulement de D111. |
| D028 | VALIDE | Promesse vérifiée en D103 (AU−20 → EXODE possible). |
| D029 | VALIDE | AR ±, présence de la preuve. Même flag que D074 (`PREUVE_TEMPERATURE`) : choisir a ou b ne change que les deltas. |
| D030 | VALIDE | BL ±10, combat. **En cas de refus, poser aussi `FLAG_HS_BLUE1`**, sinon le plafond reste bloqué à 20 (S4). |
| D031 | VALIDE | Ticket au ch. 9, Zone de Combat ouverte plus tôt. |
| D032 | VALIDE | N+1, rR/C, Brice à l'écran. |
| D033 | VALIDE | Preuve `PLANS` (motion 1). Préciser l'interaction « l'en empêcher ». |
| D034 | VALIDE | Téo informateur ou guetteur, D039 c, épilogue. |
| D035 | NON-IMPL. + FAIBLE | Trois refus à compter sans crochet (S2) ; seul effet C+5. |
| D036 | FAIBLE | C+10 et Rk+5 : les deux compteurs sont mal lus (S6). Devient VALIDE si C et Rk sont lus au climax. |
| D037 | VALIDE | Méga-Gemme et affiche. Option dominante (le seul coût est rA−3). |
| D038 | VALIDE | Niveau, talent, disponibilité de D111. « Plafond − 2 » demande un special C (S14). |
| D039 | FAIBLE | Les 4 options mènent au même flag ; seuls le coût et le delta changent. Correctif : nombre de sbires → aucun blessé en D040 a. |
| D040 | VALIDE | Trois branches. Poser `FLAG_HS_RAID_MERAZON` dans les trois (S4). |
| D041 | DOUBLON | Même effet que D011 (D092 plus court). Correctif : le nom donne l'adjoint d'Ariane → raccourci de D116 ou piège de D093 b. |
| D042 | VALIDE | Preuve `RECENSEMENT`, PNJ au camp. |
| D043 | FAIBLE | Effet purement informatif (« D106 éclairé »). Correctif : lu → Rk−3 compté par un seuil Rk réel (S6). |
| D044 | VALIDE (fragile) | Don d'un Pokémon. En fait un oui/non, pas une décision discrète. |
| D045 | VALIDE | Débloque l'option c de D062. |
| D046 | NON-IMPL. | Crochet de refus (S2) ; rO ±2 seul : FAIBLE même réparé. |
| D047 | VALIDE | Objet contre soins gratuits au camp (ch. 13). |
| D048 | VALIDE | Ouvre D049 et la preuve `CAPTEUR`. **Le refus casse la chaîne vers le téléphérique (S3).** |
| D049 | VALIDE | Trois issues, informateur, V+5. |
| D050 | VALIDE | MX/AR +10 ou V−5. **Seul poseur de `FLAG_HS_DONNEES_COSMO` → blocage (S3).** |
| D051 | VALIDE | Site du postgame ouvert ou fermé, Peter. |
| D052 | VALIDE | Présence de PNJ selon la branche (Vermilava, Pacifiville). |
| D053 | FAIBLE | `AVIS_CHEN` n'est lu par aucun votant du §5 : état écrit jamais lu. Correctif : Juan vote l'intégration si `AVIS_CHEN`. |
| D054 | NON-IMPL. + FAIBLE | Crochet de refus ; rR+2 seul. |
| D055 | VALIDE | Deux chemins d'accès, MX ±5. |
| D056 | VALIDE | rA/rM ±8 et ligne d'Arthur. |
| D057 | FAIBLE | « C−15 au climax » : ETAT_CAMP n'est plus lu après le Conseil (S5). |
| D058 | VALIDE | Conditionne D060 b (sabotage 1). |
| D059 | VALIDE | AU/MX ±10, blessés visibles. |
| D060 | VALIDE | V−10, accusation des réfugiés. |
| D061 | VALIDE | Méga-Gemme, C+10. |
| D062 | VALIDE | Brice au Conseil ou au camp, Seko en motion 3. |
| D063 | NON-IMPL. + FAIBLE | Crochet de refus ; l'effet (accès à D065) double la lecture du dossier. |
| D064 | FAIBLE | « C−10 au climax » non lu (S5) ; le reste est rR/AU. |
| D065 | VALIDE | Preuve `PRESSION_DEVON`, vote de Max sur l'option 3. |
| D066 | FAIBLE | rR+3/C+3 et prix réduits ; en fait un achat oui/non. |
| D067 | FAIBLE | « Argument pour l'option 3 » est absent du §5. Correctif : a → Arthur vote l'option 2 sans condition ; b → Max vote l'option 2. |
| D068 | FAIBLE | Flora n'est pas votante ; présence décorative. Correctif : Flora sert de secouriste de repli à Fondmer si Sarah n'est pas alliée. |
| D069 | FAIBLE | rR/rO ±5 seulement. Correctif : pétition des réfugiés → condition de Juan en motion 2. |
| D070 | FAIBLE | « D100 facilité » n'est pas défini ; recoupe D008. Correctif : dîner → D100 b possible dès B ≥ 50. |
| D071 | VALIDE | b : pertes de l'Arche −1 cran. Voir S18 (crans saturés). |
| D072 | NON-IMPL. + FAIBLE | Crochet de refus ; rO+2 seul. |
| D073 | VALIDE | Sarah alliée ou arrestations. Contredit §10.3 (secouriste « toujours » à Fondmer). |
| D074 | VALIDE | « Compte double pour Juan » : à écrire dans le §5. |
| D075 | FAIBLE | Perdre est gratuit et rapporte B+5 : option dominante, introuvable sans aide. Exige `B_FLAG_NO_WHITEOUT` alloué. Correctif : gagner → CT. |
| D076 | VALIDE | Méga-Gemme, épilogue, −5 000 ₽. |
| D077 | VALIDE | Vote de Pierre. Le choix est trivial : on répond l'option qu'on défendra. |
| D078 | VALIDE | Sabotage 2 déjoué, Méga-Gemme. |
| D079 | FAIBLE | Seul effet : C ±. Prérequis incohérent (« ou après Pierre » alors que Vol exige le badge 6, `src/field_move.c`). |
| D080 | DOUBLON | Le filet de sécurité reproduit l'effet de D078. Crochet de refus manquant. Hors décompte. |
| D081 | VALIDE | Alliance (motion 2), D083. |
| D082 | VALIDE | AR+10 ou vote de Marc. **À ajouter au §5** : la condition de Marc ignore D082. |
| D083 | VALIDE | Débloque D097. |
| D084 | VALIDE | Aveu d'Auguste, AU+10. |
| D085 | VALIDE | Quatre détenteurs de l'Orbe, effets au climax. |
| D086 | VALIDE | Condition de D108. Discrète injuste : une 3e option de dialogue cachée commande −25 V (S16). |
| D087 | FAIBLE | C+10, oui/non d'achat. Devient VALIDE avec S6. |
| D088 | NON-IMPL. + FAIBLE | Crochet de refus ; l'« aide pour D081 » n'est pas définie. |
| D089 | VALIDE | BL ±, aide de Blue au climax. |
| D090 | VALIDE | Rk+15, crans de l'Arche, N+1, variante d'Ariane. |
| D091 | VALIDE | Partenaire de combat différent. |
| D092 | VALIDE | Lambda démasqué (V−10, RO). Poser `FLAG_HS_CENTRE_SPATIAL` aussi en c. |
| D093 | VALIDE | Pertes de l'Arche et piège. |
| D094 | VALIDE | P1 au postgame, Rk+5. |
| D095 | VALIDE | Méga de Brice dans les combats avec partenaire. |
| D096 | NON-IMPL. | Crochet de refus ; une fois réparé, la scène et B+3 suffisent tout juste. |
| D097 | FAIBLE | §5 compte `CORAIL` et `PHOTOS_FONDS` pareil (P+1) ; la différence est Rf, que rien ne lit. Correctif : le corail compte P+2. |
| D098 | FAIBLE | Marin n'est pas votant. Correctif : balise → M. Rochard vote l'option 2 sans condition de P. |
| D099 | FAIBLE | `PLAN_VERMILAVA` est informatif ; Rk−10 est peu lu. |
| D100 | VALIDE | Votes de Marc et d'Auguste. |
| D101 | VALIDE | VO. |
| D102 | VALIDE | SO. Mais l'option 3 ne peut jamais passer (S7). |
| D103 | VALIDE | Arche, contrôle de D028. |
| D104 | FAIBLE | Choix trivial : montrer 3 preuves de la motion 1 (seule motion qui lit P). Correctif : 3 preuves pour les 3 motions, et motions 2 et 3 lisent aussi P. |
| D105 | FAIBLE | rA/rM ne sont plus lus après le Conseil. Correctif : la faction saluée envoie des secouristes ou des médecins au climax. |
| D106 | VALIDE | Deux branches de climax. |
| D107 | VALIDE | V−20 ou dégazage. |
| D108 | VALIDE | V−25, Groudon endormi. |
| D109 | VALIDE | RO, otage. |
| D110 | VALIDE (fragile) | Interlocuteur de l'épilogue. Les deltas MX/AU après le climax ne sont pas lus. |
| D111 | VALIDE | Pikachu quitte l'équipe. Aucune commande de script pour retirer un Pokémon : special C nécessaire (S14). |
| D112 | VALIDE (fragile) | Sac interdit (`B_VAR_NO_BAG_USE` à allouer) et épilogue. |
| D113 | VALIDE | Titre et épilogue. |
| D114 | FAIBLE | Cosmétique (dernière image) : exclu par la règle §1.1. |
| D115 | VALIDE | Équipe classique (5 Pokémon donnés). |
| D116 | VALIDE | Combat final et épilogue Rocket. |
| D117 | VALIDE | Capture ou monde stabilisé. |
| D118 | VALIDE | Salle de la Zone de Combat, départ de Blue. |
| D119 | FAIBLE | Lire ou ignorer une lettre : cosmétique. |
| D120 | FAIBLE | Dernier plan : cosmétique. |

**Décompte :** VALIDE 80 (dont 6 fragiles : D004, D006, D023, D044, D110, D112) · FAIBLE 28 · DOUBLON 3 · NON-IMPL. 9 (dont 6 aussi FAIBLE) · NON-TESTABLE 0.
**Robustes stricts : 74.** Le plancher de 101 n'est pas atteint.

---

## 2. Constats systémiques

**S1 — BLOQUANT — Le plancher n'est pas atteint.** `DECISION_LEDGER.md` §2 annonce 120 décisions et une marge de +19. Avec le critère de l'exigence (« une variable qui n'influence rien ne compte pas »), on en compte 80, dont 74 robustes. 40 entrées sont écrites sans être lues, se limitent à une ligne, sont cosmétiques, doublonnent une autre ou ne sont pas implémentables. Correctif : §3.

**S2 — BLOQUANT — Combats déclinables : le refus ne peut pas être enregistré comme décision.** Preuve : `data/scripts/trainer_battle.inc:119-127` ; après NON, le script fait `RecordDeclinedTrainerBattle` / `releaseall` / `end`. Aucun script de l'appelant ne s'exécute, et `B_VAR_LAST_DECLINED_TRAINER` vaut 0 (`FLAGS_VARS_REGISTRY.md`). De plus, le dresseur repose la question (`ENGINE_CHANGES.md` D1) : on peut refuser, puis accepter, et cumuler les deux issues. Cela touche 10 décisions (D012, D022, D035, D046, D054, D063, D072, D080, D088, D096). Correctifs, au choix :
(a) sans moteur : PNJ « à parler » (sans repérage) → `msgbox` OUI/NON → `setflag FLAG_HS_D0xx` puis `trainerbattle_no_intro`, ou départ du PNJ dans les deux cas ;
(b) moteur : ajouter un paramètre `decline_script` à `trainerbattle_single_declinable` et poser le flag du dresseur au refus (environ 0,5 jour).

**S3 — BLOQUANT — Blocage au ch. 5 (téléphérique).** La sécurité Magma de la R112 (`FLAG_HIDE_ROUTE_112_TEAM_MAGMA`, G13) n'est levée que par `FLAG_HS_DONNEES_COSMO`, posé par D050. D050 exige des « données de Cosmo », qui n'existent pas si D048 est refusé ou si D049 = c (capteur détruit). De plus, aucun poseur de `FLAG_HS_SITE_METEORE` n'est spécifié : c'est le prérequis de D050 et un jalon du plafond (27). Correctif : un événement de fin du Site Météore pose `FLAG_HS_SITE_METEORE` **et** lève la sécurité dans tous les cas ; D050 n'a lieu que si les données existent. Sinon, Cosmo n'a « rien de fiable » (V+5), ce qui est déjà la conséquence de c.

**S4 — MAJEUR — Jalons du plafond de niveau à poser dans toutes les branches.** Règle du moteur : le plafond est celui du premier flag non posé (`ENGINE_CHANGES.md` H1). Un jalon absent d'une branche fige le plafond, et l'EXP au-delà est divisée par 64. Flags à risque :
- `FLAG_HS_BLUE1` : D030 b, refus ;
- `FLAG_HS_RAID_MERAZON` : D040 b et c ;
- `FLAG_HS_SITE_METEORE` : voir S3 ;
- `FLAG_HS_CENTRE_SPATIAL` : D092 c, fuite de Lambda.

Correctif : écrire « posé dans toutes les branches » dans la colonne Stockage, et ajouter un test du harnais par branche.

**S5 — MAJEUR — États écrits mais jamais lus.**
- `ETAT_RECIF` n'apparaît ni dans les votes (§5) ni dans les fins ou variantes (§8.4). D025, D029 a, D074 c et D097 a l'écrivent pour rien.
- `ETAT_CAMP` n'est lu qu'au Conseil (Auguste ≥ 60, Marc ≥ 50). Les malus de climax (D057 b, D064 a, D079 b, D111 non) tombent après sa dernière lecture.
- `AVIS_CHEN` (D053), `PLANS_PROFONDS` (D015) et `PLAN_VERMILAVA` (D099) ne figurent dans aucune liste de preuves.
- `rA`/`rM` après le Conseil (D105), et MX/AU après le climax (D110) : jamais lus.
- « Issue de l'évacuation (blessés, pertes de Pokémon) » (§2.3) : aucune règle n'est écrite.

Correctif : une table de lecture au climax.
- C ≥ 70 : aucun blessé ; 50–69 : blessés visibles ; < 50 : un Pokémon du camp perdu, et EXODE si VO ≠ MAÎTRISÉ et rR < 50.
- Rf ≥ 55 : Arthur vote l'option 2 de la motion 1 ; épilogue marin à 2 variantes.
- Rk ≥ 40 : Ariane a sa seconde équipe et un Pokémon de plus est volé.
- Ajouter les preuves orphelines au §5.

**S6 — MAJEUR — Seuils triviaux.**
- C : départ 40, environ +100 de gains possibles, aucune entrée négative avant le climax (sauf D025 b et D079 b). Les seuils de 50 et 60 sont atteints sans y penser.
- Rk : il n'a que deux usages (≥ 60 et « 2 variantes » sans seuil défini).
- Réputations et affinités : départ 50, seuils 55–60, gains libres nombreux (D003, D012, D019, D027, D047, D066, D087…). On peut tout tenir au-dessus de 60 à la fois.

Correctif : seuils de C à 70/85 ; vote d'Arthur lié à la comparaison rA > rM (et inversement pour Max) plutôt qu'à des seuils absolus ; deltas libres ramenés à ±1, ou supprimés.

**S7 — MAJEUR — Logique du Conseil (§5).**
- (a) Motion 2, option 3 : un seul votant possible (Auguste si AU ≤ 30). Le rapatriement ne peut jamais passer. Le chemin vers F5 « rapatriement voté (D102 = 3) » (`DECISION_LEDGER.md` §2) est donc inatteignable, et D102 c équivaut à b.
- (b) `VAR_HS_CONSEIL_*` mêle l'option défendue (lue par D028 : « si Red défend Devon ») et le résultat (lu par §8.2). Il faut 3 valeurs de plus, ou des flags temporaires pour l'option défendue.
- (c) « Auguste opt 2 si promesse tenue en partie » : état non défini.
- (d) D082 b (Marc), D074 (« compte double »), D067 et D098 sont annoncés dans le registre mais absents des conditions.
- (e) Victoires automatiques. Motion 1 option 2 : Auguste (AU ≥ 40), Marc et Juan (P ≥ 2), plus Pierre si D077 = 2 ; c'est quasi certain. Motion 2 option 1 : Auguste, Max (rM ≥ 50, valeur de départ), Marc (C ≥ 50, trivial), Juan (rR ≥ 55) ; 4 voix sans effort.
- (f) Marc vote « pour » toute option défendue. Sa condition ne dépend pas de l'option.

Correctif : donner à chaque option au moins 3 votants potentiels, avec au moins une condition coûteuse ailleurs ; documenter l'option défendue et le résultat séparément.

**S8 — MAJEUR — Cohérence formelle des fins.** Les fins F1–F5 sont exhaustives et exclusives grâce à l'ordre d'évaluation (§8.4). Les 5 sont atteignables (F5 par une défaite contre Groudon, ou par EXODE via AU ≤ 30). Mais :
- (a) §8.2 se chevauche. Avec CONSEIL = 1, VO = LIMITÉE et AU ≤ 30, INTÉGRATION et EXODE sont tous deux vrais, et l'ordre n'est pas écrit. Correctif : évaluer EXODE en premier.
- (b) Deux sources de vérité pour V. Le registre applique V+5 (D049 c), V−5 (D050 c), V−15 (D085 b), V+10 (D092 c) et V+15 (D107 b), absents de §8.1.
- (c) **BR RUPTURE est inatteignable.** Brice n'a que deux deltas négatifs (D004 b −5, D045 b −3), donc son minimum est 42. Il faut au moins 3 sources de −8 (exemples : D062 a imposé contre son gré, D075 gagné en l'humiliant, D095 gardé après une promesse).
- (d) Les crans de pertes de l'Arche saturent : D071 b, D090 a et D093 a font chacun −1 cran sur une échelle de 3 crans (S18).

**S9 — MAJEUR — Stratégie dominante : un « chemin doré » unique.** Il suffit de soutenir Soupape réduite (D077 = 2, D101 = 2), de déjouer les 2 sabotages, de démasquer Lambda et de tenir Brice ≥ 55 et Blue ≥ 60. On choisit ensuite le climax au camp avec D093 b, D109 b et l'intégration. Calcul de V : 30 + 10 − 10 − 10 − 10 − 10 = **0** → MAÎTRISÉ. On obtient en même temps F1, RO démantelée, BR alliance et 0 perte à l'Arche. Aucun de ces gains n'en exclut un autre. Facteurs aggravants :
- les puits d'argent cumulés (≈ 10 700 ₽) restent bien sous le revenu vanilla des dresseurs : « payer » est toujours dominant (D021, D034, D039, D076, D087) ;
- perdre en D075 et montrer 3 preuves de la motion 1 en D104 sont gratuits ;
- même la Soupape complète finit MAÎTRISÉE au chantier (30 + 30 − 30 − 20 = 10).

Correctif à coût nul :
- ramener sabotages et Lambda à −5 chacun, et Brice au chantier à −5 ;
- rendre mutuellement exclusives des paires clés : D058 (suivre Lambert) se fait au détriment de D059 (le sauvetage commence sans Red, et l'option c devient impossible) ; D093 b ne piège Ariane que si Rk < 40.

Avec ces chiffres, Soupape complète et climax au camp donnent 30 + 30 − 15 − 5 = 40, donc LIMITÉE : la motion 1 et le lieu du climax redeviennent de vrais arbitrages.

**S10 — MAJEUR — Budget des vars dépassé.** Le registre et GAME_SYSTEMS nomment environ 63 vars `VAR_HS_*`. Il faut y ajouter les vars moteur à allouer (`VAR_DIFFICULTY`, `B_VAR_NO_BAG_USE`, `B_VAR_LAST_DECLINED_TRAINER`, peut-être `B_LEVEL_CAP_VARIABLE`), soit environ 66. Il n'y en a que 54 de libres (55 − `VAR_DIFFICULTY`). §9 en annonce « ≈ 30 ». Le langage de script n'a aucune opération bit à bit (`asm/macros/event.inc` : seulement `setvar`/`addvar`/`subvar`/`copyvar`), donc `VAR_HS_PREUVES_MONTREES (bits)` n'est pas implémentable tel quel. Correctifs :
- 2 specials C, `GetVarBits`/`SetVarBits` (environ 40 lignes) : on range les choix à 3 options (`VAR_HS_D0xx`, environ 25) par 8 dans 4 vars ;
- D104 sur les flags temporaires 0x5–0xD ;
- supprimer les doublons var + flag (D030, D082, D092).

**S11 — MINEUR — Budget des flags.** Les « 372 libres » comprennent 52 flags quotidiens remis à zéro chaque jour (`TECHNICAL_AUDIT.md` §7). Il reste donc **319** flags persistants, moins 2 déjà alloués. Pour environ 265 flags estimés, la marge est d'environ 52, à condition que les flags de visibilité (estimés à 70) ne débordent pas. Les PNJ conditionnels au camp, à Vermilava et au Conseil sont nombreux. Correctif : recycler les `FLAG_HIDE_*` vanilla des objets Aqua, Magma et Timmy supprimés (environ 40), dont les lecteurs sont tous réécrits.

**S12 — MAJEUR — Rupture de séquence ch. 11/12.** Plongée ouvre à la fois Fondmer (R127/128) et Atalanopolis (R126). Si le Conseil se déclenche avant Fondmer, D083, D097, D098 et D099 sont perdus et la promesse faite à Arthur reste suspendue. Correctif : le Conseil n'a lieu que si `FLAG_HS_FONDMER` est posé ; sinon un garde dit « le Conseil attend la contre-expertise ». De son côté, la porte de l'arène reste verrouillée jusqu'au Conseil (G32).

**S13 — MINEUR — Table de traversée et prérequis.**
- D079 : « ou après Pierre » est incompatible avec l'option a (Vol exige le badge 6).
- D073 a contredit §10.3 (« plongeur-secouriste » garanti) : il faut un secouriste de repli à Fondmer (9 salles sans soin).
- Ch. 14 : Flash n'est pas requis (`requires_flash: false` dans tous les `data/maps/VictoryRoad_*/map.json`).
- D024 : Grotte Granite B2F est atteinte par chute (sol fragile), le retour se fait par l'échelle ; vérifier qu'on ne reste pas bloqué sans Vélo Cross.

**S14 — MINEUR — Aides moteur manquantes.**
- Aucune commande pour retirer un Pokémon de l'équipe (D111).
- Aucun special n'expose le plafond courant (D038 « plafond − 2 »).
- `B_FLAG_NO_WHITEOUT`, `B_VAR_NO_BAG_USE` et `B_VAR_LAST_DECLINED_TRAINER` valent 0. Ils sont requis par D030, D075, la défaite contre Groudon et D112. Rappel : `B_FLAG_NO_WHITEOUT` n'est remis à zéro qu'après un retour au Centre (`src/overworld.c:456`), et l'équipe n'est pas soignée (`include/config/battle.h:263`). Le script doit l'effacer lui-même.

Les specials existent (`dynmultichoice`, `setfollowernpc`, `GetBattleOutcome`), donc D040, D091, D104 et l'escorte du ch. 0 sont faisables.

**S15 — MINEUR — D026 c et `FLAG_DELIVERED_DEVON_GOODS`.** Ce flag a 6 lecteurs vanilla : Route109, DewfordTown, Route104_MrBrineysHouse, OceanicMuseum 1F/2F, SternsShipyard_1F, plus `src/pokenav_match_call_data.c`. Correctif : poser le flag dans tous les cas et stocker D026 à part.

**S16 — MINEUR — Discrètes et équité.**
- Les 37 discrètes annoncées comprennent des oui/non déguisés (D044, D053, D066, D087, D098, D119). Il en reste environ 31, soit **26 %**, sous la cible de 30 %.
- Équité après coup : D086 (une option de dialogue cachée commande −25 V), D075 (perte volontaire non signalée), D110 (« le premier visité compte ») et D003 (parler deux fois) ont besoin d'un indice dans le Carnet ou d'une ligne qui les annonce.

**S17 — MINEUR — Deltas répétables.** Chaque delta doit être gardé par un flag à usage unique (D003, D027, D066, déclinables reposés). Sinon on peut « farmer » les affinités en reparlant.

**S18 — MINEUR — Crans de l'Arche.** La formule §8.3 ne cite que D093. Elle doit intégrer D071 b et D090 a et borner la somme (−1 cran au maximum en tout), sinon deux de ces trois décisions ne servent à rien.

**S19 — MINEUR — États de Pikachu.** La valeur de `VAR_HS_PIKACHU` lors du retour au ch. 5 (D002 = a) n'est pas définie ; or D111 exige la valeur 3.

**S20 — MAJEUR — Conséquences absentes du déroulé §6 et coût de script.** Plusieurs lectures du registre n'apparaissent pas dans les chapitres de la bible : veste au ch. 13 (D003), Scott au ch. 9 (D031), Chen au ch. 9 (D053), ligne de Pierre au ch. 8 (D024), Téo au ch. 13 (D034). Il manque un index « lectures par carte ».

**Estimation de l'effort** (ordre de grandeur) :

| Poste | Volume | Jours-personne |
|---|---|---|
| Scripts déclencheurs | 120 × ~60 lignes | ≈ 60 |
| Branches de conséquence | ≈ 350 | ≈ 40 |
| Conseil | ≈ 600 lignes | ≈ 5 |
| Climax | ≈ 1 000 lignes, 2 branches | ≈ 10 |
| Épilogue | ≈ 25 variantes | ≈ 8 |
| États de test | 120 + états forcés | ≈ 25 |
| **Total** | | **≈ 150** |

Décisions qui touchent le plus de cartes :
- D001 (Lilou, Ernest : 5 cartes) et D005 (tous les défis, ch. 1/7/10, épilogue) ;
- D025 (quai, piquet de la R110, lignes Aqua jusqu'au ch. 9) et D034 (ch. 3/4/13, épilogue) ;
- D040 (donjon à 3 branches), D057 (camp de Vermilava en 2 dispositions), D085 (4 détenteurs × climax), D106 (2 climax complets) ;
- D014, D029, D032, D050 et D090 (affiches et JT à Poivressel, Lavandia, Nénucrique) : remplacer la « TV » par des affiches ou des PNJ, car le système TV vanilla ne sert pas de support scripté simple.

---

## 3. Décomptes et recommandation (≥ 101 robustes, ~10 % de marge, coût minimal)

**État actuel :** 80 VALIDE (74 strictes) sur 120. **Cible : ≥ 111.** Aucune nouvelle carte ni nouvelle décision : on câble des lectures sur des états déjà écrits.

| Lot | Contenu | Décisions remontées | Effort |
|---|---|---|---|
| A — Câblage du Conseil (un seul script) | D009 → Marc ; D053 → Juan (motion 2) ; D067 → Arthur ou Max ; D069 → Juan ; D070 → D100 b ; D097 → P+2 ; D098 → M. Rochard ; D104 → 3 preuves pour les 3 motions (vrai arbitrage). Réparer aussi S7 (option 3 de la motion 2 atteignable, option défendue ≠ résultat). | +8 | ≈ 2 j |
| B — Lecture des états au climax et à l'épilogue (S5/S6) | Table C/Rf/Rk au climax, avec des seuils relevés ; objets et PNJ visibles au camp de Vermilava par contributeur. Concerne D018, D036, D043, D057, D064, D066, D079, D087, D099, D011. | +10 | ≈ 3 j |
| C — Déclinables réparés (S2, option a sans moteur) | On garde D022 (Matthieu → contact Aqua en D081), D035 (aides visibles au camp), D046 (rO lu par M. Rochard), D063 (respect de Kelvin → seuil de Max −5), D096 (scène). D012, D054, D072, D088 et D080 restent du contenu, hors décompte. | +5 | ≈ 1,5 j |
| D — Correctifs unitaires | D017 ≠ D039 (sortie secrète / effectifs) ; D041 ≠ D011 (adjoint d'Ariane) ; D075 (gagner → CT) ; D105 (secouristes au climax). | +5 | ≈ 1 j |
| E — Petits crochets | D008 → D070 ; D021 c → D081 c ; D027 → aide en D111 ; D068 → secouriste de repli à Fondmer (règle aussi S13). | +4 | ≈ 1,5 j |
| **Total** | | **80 + 32 = 112** (≈ 106 si l'on écarte aussi les 6 fragiles) | **≈ 9-10 j** |

**Conditions pour valider ce décompte :**
1. Corriger d'abord les BLOQUANTS : S2 (déclinables), S3 (blocage du téléphérique), puis S4 (jalons du plafond) et S12 (ordre Fondmer → Conseil).
2. Retirer D114, D119 et D120 (cosmétiques) du décompte, ou leur donner une lecture réelle. Corriger le tableau §2 du registre : afficher 112 décisions « comptées » sur 120 « listées » et 26 % de discrètes. Pour remonter à 30 %, requalifier 4 des corrections des lots B et E en gestes sans menu.
3. Re-tarer les systèmes contre la stratégie dominante (S9) : sabotages, Lambda et Brice à −5 ; C à 70/85 ; votes d'Arthur et de Max relatifs (rA > rM) ; puits d'argent proportionnés au revenu du chapitre ; au moins 2 paires mutuellement exclusives (D058/D059, D093 b/Rk). Sans cela, la plupart des 112 décisions restent valides techniquement, mais deviennent **triviales** pour qui connaît le chemin doré.
4. Résoudre les vars (S10) avec les specials de bits avant toute allocation dans `FLAGS_VARS_REGISTRY.md`.
5. Unifier les deltas de V dans §8.1 (S8 b) et rendre BR RUPTURE atteignable (S8 c). Sinon, une variante d'épilogue est morte et l'affirmation « toutes les fins atteignables » n'est vraie que pour F1–F5.
