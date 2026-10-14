# ARBITRATION_V3 — gel du design, étape 1 (arbitrage des conflits des spécialistes)

> Arbitre : Game Mechanics Director (GMD). Date : 2026-10-14. Résultat : `GAME_DESIGN_BIBLE.md` **v3.1**.
> Périmètre :
> - conflits signalés par les quatre spécialistes : `CHARACTER_AND_LORE.md` §12.5, `ENCOUNTERS_PLAN.md` §13, `COMBAT_DESIGN.md` §14, `GAME_SYSTEMS.md` §19 ;
> - demandes moteur ;
> - contrôle de cohérence aux interfaces.
> Faits d'intégration pris en compte : `FREE_MATCH_CALL TRUE` (revanches, Cherche VS et Match Call coupés ; **Match Call n'est pas un canal narratif**) ; `B_SLEEP_CLAUSE TRUE`.
> Verdicts :
> - **A** = accepté tel quel ;
> - **M** = accepté modifié ;
> - **R** = rejeté.
> Règle : les décisions ci-dessous **font foi** sur les documents des spécialistes jusqu'à leur mise à jour. Les modifications minimales sont faites et marquées dans leurs changelogs.

## 1. Distribution et lore (`CHARACTER_AND_LORE` §12.5 et ajouts)
| # | Sujet | Verdict | Raison (une ligne) | Documents mis à jour |
|---|---|---|---|---|
| K-01 | Auguste « paie la reconstruction » alors que l'éruption de Cramois'Île est future | A | Financer la **surveillance et l'évacuation** de Cramois'Île garde le présage canon sans anachronisme | bible §9.2 |
| K-02 | Pierre (Brock) au ch. 1 et Aldo au ch. 2 avant le débarquement de la Mission (ch. 3) | A | Deux vagues : les **bloqués** (arrivés avant la fermeture des ports) et la **Mission** (ch. 3). Cela explique aussi la xénophobie | bible §3.1, §9 |
| K-03 | « COMPRENDRE » en axe B (Chen, Pierre (Brock)) | A | Ce n'était pas une valeur de l'axe : erreur de la bible ; lue `CTL` | bible §9 |
| K-04 | Spectres de Lavanville (Kanto) dans une zone Sinnoh/Alola | A | Ce sont des esprits scénarisés, **hors tables de rencontre**, donc hors du calcul des 80 % | bible §5.3 |
| K-05 | F2 « Sylphe ruinée » alors que Sylphe fonctionne en HGSS | A | Ruinée puis relevée avant l'année 3 ; une ligne d'épilogue le dit | bible §12.3 |
| A1 | Deux vagues de Kantonais | A | voir K-02 | bible §3.1 |
| A2 | Affiche Sylphe (Red de dos) et raison du silence de Red | A | Donne au mutisme une cause **sociale** (« quand il parle, on le cite ») et plante R4. On ne la sur-explique pas en jeu : elle n'est explicite qu'au Carnet et au ch. 12 | bible §3.1, §4.4 |
| A3 | Lambda remplace l'ingénieur **Ferrand** (An 0 + 5 mois) ; Ferrand libérable au ch. 9 | A | Corrige N5 (calendrier, alias) ; une libération facultative ne casse pas R4 | bible §3.1, §9.2 |
| A4 | Giovanni rachète des actions de Devon | A | Sert son orgueil (« revenir avec de l'argent, pas avec un dieu ») ; HYPOTHÈSE sans conflit canon. Garde-fou : il n'obtient **rien** à la fin (toutes les fins : parts revendues ou gelées, au choix du brief A pour l'épilogue) | bible §9.1 |
| A5 | Koga paie Lance (Rocket) pour des informations (« K. » du carnet de primes) | A | Fausse piste vraie à un autre niveau ; ne confirme jamais un passé Rocket (canon respecté) | bible §9.2 |
| A6 | Erika et son contrat de parfum (déchire ou signe) | A | Agenda égoïste lisible ; écho par fin déjà écrit | bible §9.2 (inchangé sur le fond) |
| A7 | Lettre d'Auguste → venue de Fuji au ch. 9 | A | Donne à Fuji une raison concrète d'être à Hoenn | bible §9.2 |
| A8 | Amaryllis : SACRIFICE ≠ mort (elle retient Rayquaza ; son Drattak suit le dragon) | A | Pas de noirceur gratuite ; la perte reste réelle | bible §9.1, §12.2 |
| A9 | Brice vote selon `BV`, pas selon `BR` | A | C'était déjà l'invariant 2 ; confirmé | — |

## 2. Espèces et écologie (`ENCOUNTERS_PLAN` §13.2 et §13.3)
| # | Sujet | Verdict | Raison | Documents |
|---|---|---|---|---|
| K1 | Mewtwo « laisser » contre l'invariant 9 | A | « Laisser » **retarde** l'obtention (don de Fuji à P8, D126 b). L'espèce reste obtenable dans toutes les fins | bible §12.4 |
| K2 | R110 dans deux nœuds ; R101–R103 sans nœud | A | R110 → Z-03 (anneaux autour de la centrale) ; R101–R103 → Z-01 | bible §5.3 |
| K3 | 4e état d'écosystème ABATTU | A | Donne enfin une règle à la signature du Rempart ; même coût en stockage (2 bits) | bible §5.4, §11.1 |
| K4 | Stockage des zones : 1 var en bits plutôt que 12 flags | A | Budget ; dépend d'E-BITS (déjà requis) | bible §11.1 |
| K5 | P3 « canal par fin » | A | Même site, même espèce, **ouverture** différente selon la fin ; F5 garde son gain (tous les sites à la fois) | bible §5.2 |
| K6 | Parc Safari = réserve d'arrivants saisis, exclu de la règle des 80 % | A | Résout Kanto–Johto et les espèces de palier C précoces ; sens : « prison douce » portée par des PNJ opposés | bible §5.3 ; `CHARACTER_AND_LORE` (une ligne de lore) |
| K7 | Ursaking (évolution `IF_REGION HISUI`) | A | Rencontre directe en P2 ; aucune donnée d'espèce modifiée | — |
| K8 | Dates des cannes | A | Vieille canne ch. 2 (Myokara), Super canne ch. 8 (R118), Méga canne ch. 10 (Algatia) : ce sont les **donneurs vanilla**, conservés | bible §8.3 |
| §13.3-1 | Une table alternative ne retire jamais une espèce, elle change sa rareté | A | L'invariant 9 tient par construction | bible §5.4 |
| §13.3-2 | ABATTU | A | voir K3 | — |
| §13.3-3 | Safari exclu des 80 % | A | voir K6 | — |
| §13.3-4 | Mewtwo | A | voir K1 | — |
| §13.3-5 | R110 en Z-03 | A | voir K2 | — |
| §13.3-6 | E-TOD « nuit seule » (`OW_TIME_OF_DAY_ENCOUNTERS TRUE`, variantes `_Night` seulement) | A | Capacité suffisante, coût minimal. Chaque espèce nocturne a un canal de jour ailleurs ou au postgame. Test RTC sur mGBA exigé (code jeu `BPEF` avec RTC conservé) | bible §14 |
| §13.3-7 | Paliers de puissance et niveaux sauvages (plafond − 2), avec le Multi Exp | **M** | Accepté, à une condition : le Multi Exp est remis **dans toutes les branches avant la fin du ch. 4**. D030 a → Chen au ch. 3 ; sinon (b **ou** non prise) → Seko au ch. 4, **indépendamment de D041** (reprendre ou laisser Pikachu) | bible §8.3 ; `DECISION_LEDGER_ACT0-1` (note D030) |
| E-LEDGER | 128 bits dans SB3 (16 o) pour les statiques | A | Seul usage de SB3 retenu. **E-SB3 général abandonné**. Validation par le programmeur moteur | bible §14 ; `GAME_SYSTEMS` §17 |
| E-OUT | Special « épidémie d'anneau » ; couper le tirage télé vanilla | A | Requis par les anneaux de l'histoire | bible §14 |

## 3. Combat (`COMBAT_DESIGN` §14 et demandes moteur)
| # | Sujet | Verdict | Raison | Documents |
|---|---|---|---|---|
| C1 | Timmy au ch. 7 ou à la Route Victoire | A | Ch. 7 = **Flora 2** (brigade), que Red affronte pour défendre Timmy (D064 a). Timmy combat à la **Route Victoire** (D124, refusable), avec ou sans son arrivant. On évite deux combats d'enfants dans une même scène | bible §9.3, §8.3 ; `CHARACTER_AND_LORE` C-33 |
| C2 | Koga : deux combats au ch. 8 ; la variante liée à W10 lit un état du ch. 10 | A | Défi D081 au ch. 8 avec une équipe neutre, **plus** une revanche de **contenu** au ch. 10 (après W10) qui lit `REL_KOGA_PETER` (PROPRE / PIÈGES). La revanche n'est pas une décision comptée | bible §9.2, §10 |
| C3 | Giovanni : « rien d'importé » contre les satellites proposés par D | A | Satellites d'avant le réseau (Corboss, Hippodocus, Tyranocif) ; la réplique centrale tient | bible §9.1 |
| C4 | Deux Méga-Drattak (Amaryllis, Aragon) | A | Pendant l'histoire, Méga-Drattak pour Amaryllis seulement ; Aragon et Glacia : Méga en T5 seulement | bible §10 |
| C5 | Compte des ID de revanche | A | **291 vérifiés** (et non 324) ; la marge reste large | bible §10, §14 |
| C6 | Drackhaus d'Amaryllis au ch. 5 (pseudo-légendaire de PNJ avant le ch. 8) | A | La règle du ch. 8 vise les **sauvages**. Drackhaus est natif du Site Météore et c'est l'identité d'Amaryllis. Exception unique, déclarée | bible §10 |
| C7 | Défis refusables sans décision (Pierre, Auguste, Erika, Ondine 1, Olga, Morgane, Agatha-rite) | **M** | On suit le brief C : seuls Aldo (D022), Major Bob (D043), Koga (D081) et Peter (D100) sont des décisions. La recommandation de B (flags pour Olga et Agatha) est **rejetée** : leurs refus n'ont pas de lecteur. Les autres Défis sont du **contenu** : macro avec flag de refus 0, le Défi reste proposé, aucun état. Le combat « rite profané » d'Agatha est un combat d'histoire, pas un Défi | bible §10 ; `COMBAT_DESIGN` §4 (note) |
| C8 | Taille ≈ 120 Ko au lieu de 60–100 | A | La lisibilité pour les scénaristes prime | — |
| C9 | Arènes de Roxanne, Bastien et Norman sans effet de terrain | A | Ce sont des tutoriels déclarés ; ajouter du terrain coûte du script sans nouvelle décision | — |
| E-2v1 | Macro « 2 contre 1 » (Amaryllis contre Red et Peter, ch. 5) | **M** | **Pas de nouvelle macro.** Le moteur sait déjà le faire : un PNJ suiveur partenaire (`setfollowernpc … battlePartner`) suivi d'un `trainerbattle` simple fixe `opponentB = 0xFFFF` (`src/battle_setup.c` l. 1419–1423 ; `BATTLE_TWO_VS_ONE_OPPONENT`). **À vérifier en émulateur** par le programmeur moteur | bible §14 ; `COMBAT_DESIGN` §8.6 et §12.3 |
| E-ADAPT | Type dominant de l'équipe | A | Spécification du brief B §5.3 retenue (+2 au type 1, +1 au type 2 ; égalité → Pokémon de tête), code en ROM | bible §14 |

## 4. Systèmes (`GAME_SYSTEMS` §19)
| # | Sujet | Verdict | Raison | Documents |
|---|---|---|---|---|
| K-C1 | « Grotte Tréfonds » (ch. 11) = en réalité **Caverne Fondmer** (`SeafloorCavern`) | A | Erreur de la bible, vérifiée : `region_map_sections.json` donne `MAPSEC_SEAFLOOR_CAVERN` = CAVERNE FONDMER et `MAPSEC_SHOAL_CAVE` = GROTTE TREFONDS. Renommé partout où il s'agit du ch. 11 ; « Tréfonds » reste juste pour Shoal Cave (Z-05, sites légendaires) | bible ; `CHARACTER_AND_LORE` ; `COMBAT_DESIGN` ; `SPEC_BRIEFS` ; `DECISION_LEDGER_ACT3` |
| K-C2 | Réputations lues relativement (`S(X)` = écart à la moyenne) ; aide E-REPREL | A | Sans cela, « plaire à tous » marche (constat du modèle) | bible §11.1, §14 |
| K-C3 | Seuil du PACTE : `HO` ≥ 70 si Red donne la Fiole, ≥ 80 si c'est un allié | A | 80 partout rendrait F2 introuvable (borne de `HO` = 87–92) | bible §12.2 |
| K-C4 | Amaryllis ne renonce que si Red est au Pilier | A | Ferme le chemin doré ; c'est un vrai coût de présence | bible §12.2 |
| K-C5 | Le chemin libéral « Pacte + intégration + Rocket démantelée » reste atteignable, à un coût chiffré | A | L'interdire punirait une cohérence thématique. **Question aux critiques** (§6) | — |
| K-C6 | Plafonds de fin de partie : 60 à l'entrée de la salle du Maître, 75 au Panthéon, 100 au retour de l'équipe de Red | A | Lève une ambiguïté de la bible | bible §8.3 |
| K-C7 | Défis Indigo : 8 refusables, 4 comptés | A | Conforme à la bible §10 | — |
| K-C8 | ABATTU adopté ; prix remplacés par des ruptures de stock | A | Évite E-PRICE (rejeté) | bible §14 |
| K-C9 | Mewtwo : D126 b retarde l'obtention | A | voir K1 | — |
| K-C10 | Positions et relations demandées par A fusionnées en bits ; `REL_CHEN_SEKO` dérivé | A | Budget | — |
| X1 | Motion 3 du Sommet : bible « garde de la Fiole » ; C « qui paie » (KANTO / HOENN / PARTAGÉE) | **M (C retenu)** | La garde de la Fiole se règle **au climax** (affectation et intention au relais). Si M3 la tranchait aussi, le vote pré-empterait le climax. M3 devient la **responsabilité** (thème de R4) et pèse sur FK, `rI`/`rC`, le Maître et Peter | bible §8.3, §12.1 |
| X2 | « Appels » (Norman au ch. 0, M. Rochard au ch. 10) alors que Match Call est coupé | M | Ce sont des **scènes scriptées** (téléphone du labo, interphone du Centre Spatial, PNJ présent), jamais Match Call ou PokéNav | bible §14 ; `CHARACTER_AND_LORE` (note) |
| X3 | Nouvelles aides moteur : E-REPREL, E-NATIVE (espèce du dex de Hoenn ?), E-LVL sans code (`givemon` lit le niveau dans une var) | A | Petites, en ROM, chacune avec un lecteur | bible §14 |
| X4 | E-PRICE, E-LEND, E-SB3 général | R | Remplacés : ruptures de stock, don d'objets, E-LEDGER | bible §14 |

## 5. Cohérence entre documents (contrôles faits pendant cet arbitrage)
| Point | Constat | Statut |
|---|---|---|
| ID de décisions cités par B et D | Échantillon de B §4 (D008, D022, D027, D043, D050, D054, D056, D059, D064, D075, D081, D082, D084, D095, D100, D102, D104, D111, D121, D124, D127, D130) : tous existent dans `DECISION_LEDGER` §3 **avec le même sens**. Ceux de D (missions de zone D010, D018, D037, D054, D074, D102 ; D126 Mewtwo ; D128) concordent avec `GAME_SYSTEMS` §3.5 | conforme |
| États de zone | Z-01–Z-06 identiques dans D §3.1, C §3.5 et §16 ; départ ENVAHI ; mission non faite → MIXTE au jalon ; glissement M2 au ch. 13 | conforme |
| Jalons de plafond et niveaux de combat | B §4 utilise le plafond courant de C §7 à chaque rencontre (ex. Blue 1 : 20, Koga ch. 8 : 37, Peter ch. 10 : 47, Juan : 51, Conseil 4 : 56, Maître ≤ 60) ; les niveaux sauvages de D §2.3 suivent les mêmes plafonds | conforme |
| Timmy et Flora au ch. 7 | B (Flora 2, D064 a) = C (D064, D063 exclusif) ; A disait « Timmy combat au ch. 7 » | **corrigé** dans A (C-33) |
| Chapitre du Défi de Koga | B et C : ch. 8 (D081). A : W10 au ch. 10 = révélation et revanche de contenu | aligné par la décision C2 |
| Défis Indigo comme décisions | 4 comptés (D022, D043, D081, D100), les autres sont du contenu | aligné par la décision C7 |
| Nom « Grotte Tréfonds » | erreur de la bible propagée dans A et B | **corrigé** (K-C1) |
| Multi Exp | donné dans toutes les branches ? D030 « non prise » n'était pas couverte | **règle ajoutée** (§13.3-7) |
| Match Call et revanches | personne ne s'appuie sur Match Call ; B §12.3 demande déjà la neutralisation (faite : `FREE_MATCH_CALL`) | conforme |

## 6. Questions résiduelles pour les critiques indépendants
1. **Distribution des fins** (modèle à personas) : F4 REMPART 46 %, puis F5 16 %, F1 15 %, F2 11 %, F3 11 %. Le repli sur F4 donne-t-il au joueur moyen le sentiment d'un **échec** plutôt que d'une fin à part entière ? Faut-il un repli sur une autre fin, ou rendre F4 plus souvent **choisie** (Rempart défendu au Sommet) ?
2. **M1 LIBÉRER ne passe que dans 3 % des parties** (FERMER 72 %). Est-ce une option morte (« faux choix ») ? Est-ce acceptable parce que la libération se joue au climax (F2), sans passer par le vote ?
3. **Amaryllis RENONCE dans 12 % des parties seulement** (présence exclusive au Pilier). L'arc de la croyante est-il assez visible pour la majorité, qui la voit PERSISTER ?
4. **Lisibilité du mythe** (H1–H4, Y1–Y3) : le Kiosque (ch. 3) et la démonstration de Magma (ch. 6) suffisent-ils pour que la loi d'échange soit comprise **avant** le Mont Mémoria ? Un test de compréhension est demandé.
5. **Chemin libéral (K-C5)** : son coût chiffré est-il ressenti en jeu, ou seulement visible dans le modèle ?
6. **Charge de texte et de personnages** : A compte 64 entrées. La règle « rang C ≥ 2 scènes + écho » tient-elle dans le budget de production (~3 500–4 500 boîtes) ? Quelles coupes, si la tranche ch. 0–2 dépasse son budget ?
7. **« Le monde tourne autour de Red »** (affiche Sylphe, Rubis porté, Sylphe libérée) : la part de Red reste-t-elle **un maillon** parmi d'autres ?
8. **Hypothèses de lore empilées** (article de Chen, Fiole au Pilier, vol de l'an −2, actions de Giovanni, Ferrand) : risque d'être lues comme du canon. Les étiquettes suffisent-elles en jeu ?
9. **E-TOD** : un joueur qui ne joue que de jour perçoit-il la variante nocturne comme une contrainte injuste ?
10. **Climax** : la table d'affectation est déterministe. Le joueur comprend-il **avant** de choisir ce que chaque allié fera de la Fiole ? Les répliques de veillée doivent être testées sur un joueur novice.

## 7. Étapes suivantes du gel
1. Revues critiques indépendantes (narration, systèmes) sur la v3.1 et les cinq documents.
2. Programmeur moteur, dans l'ordre du chemin critique : E-BITS, E-REPREL, E-CAP, E-ECO, E-OUT ; puis E-ADAPT, E-REMOVE, E-NATIVE, E-LEDGER, E-TOD ; vérification du 2 contre 1.
3. Tranche représentative (ch. 0–2) en production.
