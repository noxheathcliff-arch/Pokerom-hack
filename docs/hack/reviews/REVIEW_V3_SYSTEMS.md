# REVIEW V3 — Systèmes et faisabilité (critique indépendante, design v3.1)

> Périmètre : `DECISION_LEDGER.md` + `_ACT0-1/_ACT2/_ACT3/_POST`, données `data/cf_decisions.py`, modèle `data/cf_model.py`, `GAME_SYSTEMS.md` (tout), `GAME_DESIGN_BIBLE.md` §6–§12, `reviews/ARBITRATION_V3.md`, grille `REVIEW_V2_SYSTEMS.md` §1, `ENGINE_CHANGES.md`, `TECHNICAL_AUDIT.md`, `COMBAT_DESIGN.md` §5 et §12, `ENCOUNTERS_PLAN.md` §13–14. Source lu en lecture seule (aucun `make`).
> Date : 2026-10-14. Toutes les mesures ci-dessous sont **reproductibles** (commandes et script en annexe A). Ce sont des mesures du **modèle papier**, pas des tests sur ROM.

## 0. Verdict global

| Question | Réponse |
|---|---|
| Le plancher de 101 décisions à impact réel tient-il ? | **Oui, de justesse : 109 VALIDE** (registre : 124). Dont **11 fragiles** ; **98 robustes** sans réserve. |
| Avec ≥ 10 % de marge (≥ 112) ? | **Non.** Marge réelle : +8 (7,9 %). Sans les fragiles : −3. Écart avec le registre : −15. |
| Non-comptables | 20 FAIBLE, 1 DOUBLON (D039), 1 NON-IMPLÉMENTABLE tel que spécifié (D048 : désert sans Lunettes Sable). |
| Chemin doré / « plaire à tous » | **Plus fort qu'annoncé.** `--golden` obtient F2 + INTÉGRATION + Rocket DÉMANTELÉE + **civils AUCUN** + 8/9 relations ≥ 60. `GAME_SYSTEMS` §5 affirme « civils BLESSÉS » : faux (constat S3). |
| Fins exhaustives et exclusives | **Oui** par construction (§10.4 = chaîne `if/elif/else` du modèle, vérifiée ligne à ligne). Mais 4 styles de jeu cohérents sur 9 tombent à 73–95 % dans F4 (constat S4). |
| Budget vars/flags | **Vérifié par grep** : 54 vars libres (44 utilisées), plages de flags revendiquées toutes `FLAG_UNUSED_*` sans référence de code. Deux trous de stockage (S11). |
| Moteur | Toutes les aides sont faisables ; E-ECO et E-OUT sont les deux seules non triviales (S13). ≈ 450–700 lignes C. |
| Effort | Jeu complet ≈ **330–420 jours-personne** ; ch. 0–4 ≈ **95–115 j-p** (§4). |

---

## 1. Verdict par décision

### 1.1 Méthode (plus stricte que le registre)
1. **Grille** `REVIEW_V2_SYSTEMS` §1, appliquée sans indulgence : VALIDE = un état lu plus tard produit un effet observable non cosmétique, **ou** l'effet immédiat est substantiel (Pokémon gagné/perdu, combat, accès, objet unique/CT, PNJ d'état). FAIBLE = deltas seuls dont le seuil est « franchi de toute façon », objet courant, ligne d'épilogue, ordre d'accès seulement.
2. **Test contrefactuel (nouveau).** Pour chaque décision, 120 parties à personas sont rejouées en forçant tour à tour chaque option, **toutes les autres choses égales** (bruit des personas indexé par (partie, décision, option) ; affectation du climax figée) : on mesure le **taux de pivot** = part des parties où le résultat change sur au moins une sortie lisible (fin, variante sociale, Rocket, civils, Amaryllis, M1–M3, fin cachée, Maître, FK, alliés réellement affectés au climax, `REL_CHEN_SEKO`, `BLUE_LIBRE`, `PETER_ASSUME`, `PR_ACCUSE`, `TIMMY_SAUVE`, `FLORA_DESOBEIT`, Koga). Colonne « Fin » = part où la **fin de la Fiole** change. Colonne « Chemin » (dans le texte) = part où les **options proposées plus tard** changent.
3. Règle de décision : décision à deltas purs **et** pivot < 10 % → FAIBLE ; 10–15 % → VALIDE (fragile) si un lecteur nommé existe ; ≥ 15 % → VALIDE. Les décisions des ch. 14 et postgame sont hors modèle : jugées sur leur effet de contenu.
4. Le registre a raison sur 117 verdicts, tort sur 14 (13 VALIDE → non comptables, 1 FAIBLE → VALIDE fragile : D025).

> **Note de méthode :** une première passe naïve (flux aléatoire partagé) donnait des pivots de 90–99 % pour des gestes mineurs (D028) : c'était une désynchronisation du générateur, pas un effet. Les chiffres ci-dessous sont ceux de la passe corrigée.

### 1.2 Table (131 lignes)
Colonnes : ID · Ch. · Type (E explicite / D discrète) · verdict du registre · **verdict de cette revue** · pivot · fin changée · raison.

| ID | Ch. | T | Registre | **Revue v3** | Pivot | Fin | Raison |
|---|---|---|---|---|---|---|---|
| D001 | 0 | E | VALIDE | VALIDE | 53% | 8% | pivote : FK×28 PET×24 held×22 M3×13 |
| D002 | 0 | E | VALIDE | VALIDE | 18% | 1% | N : Défis Indigo dès le ch. 3 ou après le ch. 10 |
| D003 | 0 | D | VALIDE | VALIDE | 32% | 6% | BV |
| D004 | 0 | E | FAIBLE | FAIBLE | 0% | 0% | starter vanilla ; lu seulement par l'équipe de Brice (sélecteur B), aucune conséquence narrative |
| D005 | 0 | E | VALIDE | FAIBLE | 9% | 2% | Multi Exp désormais remis dans toutes les branches (arbitrage §13.3-7) : reste « Chen froid » + `REL_CHEN_SEKO` d'épilogue ; pivot 9 % |
| D006 | 0 | D | VALIDE | VALIDE | 11% | 0% | pièce `DOS_CLOCHETTE_PIKO` + passage gratuit |
| D007 | 0 | D | VALIDE | VALIDE | 26% | 2% | BV |
| D008 | 1 | E | VALIDE | VALIDE | 32% | 2% | pivote : held×24 FLO×22 M2×5 RK×4 |
| D009 | 1 | D | VALIDE | VALIDE | 37% | 5% | pivote : PET×30 M3×17 held×17 FK×14 |
| D010 | 1 | E | VALIDE | VALIDE | 49% | 1% | pivote : VS×36 M2×25 RK×17 FK×15 |
| D011 | 1 | E | VALIDE | VALIDE | 31% | 0% | Kiosque −10 %, N |
| D012 | 1 | D | VALIDE | VALIDE | 17% | 4% | BV, HO, objet |
| D013 | 1 | D | VALIDE | FAIBLE | 3% | 0% | `LAMBDA_REMARQUE` n'ouvre rien : l'autre condition de D063 a (Lambda vu au ch. 4) est toujours vraie → chemins identiques (pathdiv 0 %) |
| D014 | 1 | E | VALIDE | VALIDE | 21% | 0% | pivote : RK×17 FK×4 M3×3 hid×2 |
| D015 | 1 | D | VALIDE | VALIDE | 17% | 0% | pivote : RK×17 FK×2 held×1 M2×1 |
| D016 | 1 | E | VALIDE | VALIDE (fragile) | 11% | 2% | lu par le vote d'abattage (Roxanne) mais seulement si D036 a ; pivot 11 % |
| D017 | 1 | D | VALIDE | VALIDE | 26% | 0% | pivote : M1×13 held×8 RK×5 VS×5 |
| D018 | 2 | E | VALIDE | VALIDE | 69% | 8% | pivote : VS×35 held×32 M2×25 PRA×20 |
| D019 | 2 | D | VALIDE | VALIDE (fragile) | 13% | 1% | geste Hoopa + 200 ₽ ; `HO` ≥ 25 au ch. 3 (rendu partiel) |
| D020 | 2 | E | VALIDE | VALIDE | 74% | 16% | pivote : held×35 PRA×32 F×13 M1×13 |
| D021 | 2 | E | VALIDE | VALIDE | 7% | 0% | Pokémon (Demanta) contre Super Canne |
| D022 | 2 | D | VALIDE | VALIDE | 16% | 0% | pivote : FK×12 RK×6 held×2 M3×2 |
| D023 | 2 | D | VALIDE | VALIDE | 4% | 0% | Pokémon acheté |
| D024 | 2 | D | VALIDE | VALIDE | 41% | 11% | pivote : held×15 PRA×13 F×9 M1×6 |
| D025 | 3 | D | FAIBLE | VALIDE (fragile) | 43% | 2% | déclassée FAIBLE par le registre, mais pivote `PETER_ASSUME` (43 %) : effet réel **illisible** ; ajouter un signal ou laisser FAIBLE |
| D026 | 3 | E | VALIDE | VALIDE | 12% | 0% | Restes, H1 vécue, PA |
| D027 | 3 | E | VALIDE | VALIDE | 69% | 18% | pivote : BLUE×46 held×39 F×22 PET×8 |
| D028 | 3 | D | VALIDE | VALIDE | 19% | 0% | pivote : FK×11 RK×9 M3×2 held×2 |
| D029 | 3 | E | VALIDE | VALIDE | 25% | 1% | pivote : M1×9 FK×7 M2×5 M3×5 |
| D030 | 3 | E | VALIDE | FAIBLE | 2% | 1% | seule différence restante = Multi Exp un chapitre plus tôt (arbitrage) + `BR` ±3 ; pivot 2 % |
| D031 | 3 | D | VALIDE | VALIDE | 16% | 3% | pivote : FK×9 M3×6 F×4 Maitre×4 |
| D032 | 3 | E | VALIDE | VALIDE | 32% | 0% | pivote : FK×22 RK×17 M3×17 Maitre×4 |
| D033 | 3 | D | VALIDE | FAIBLE | 1% | 0% | `INFO_ENTREPOT` ne change la pièce Ferrand que si `S(rI)` < 5 ∧ D082 a : pivot 1 % |
| D034 | 3 | E | VALIDE | VALIDE | 69% | 12% | pivote : BLUE×31 held×20 F×9 FK×3 |
| D035 | 3 | D | VALIDE | VALIDE (fragile) | 8% | 0% | 3 Potions vs barrage R110 « ouvert » : vérifier que l'option b ne ferme pas R110 (sinon softlock) ; pivot 8 % |
| D036 | 4 | E | VALIDE | VALIDE | 48% | 1% | pivote : held×42 RK×16 FK×6 cas×6 |
| D037 | 4 | E | VALIDE | VALIDE | 32% | 2% | pivote : VS×19 held×10 M2×10 FK×9 |
| D038 | 4 | D | VALIDE | VALIDE (fragile) | 7% | 0% | objet + équipe de Timmy (sélecteur B) ; aucun flag : le slot `D038` doit être lu par D064/D124 |
| D039 | 4 | D | VALIDE | DOUBLON | 14% | 2% | même effet que D019 (HO +5 / −2, même lecteur, aucun état propre) ; à fusionner ou différencier (ex. le fermier devient témoin de D064) |
| D040 | 4 | E | VALIDE | VALIDE | 62% | 4% | pivote : FK×25 KOGA×22 RK×18 held×15 |
| D041 | 4 | E | VALIDE | VALIDE | 17% | 3% | pivote : held×7 M1×5 VS×5 M2×5 |
| D042 | 4 | E | FAIBLE | FAIBLE | 7% | 1% | PA +1 au ch. 7 seulement ; pivot 7 % (accord avec le registre) |
| D043 | 4 | D | VALIDE | VALIDE | 37% | 0% | pivote : held×31 FK×15 RK×8 cas×3 |
| D044 | 4 | E | VALIDE | VALIDE (fragile) | 3% | 0% | CT immédiate ; « D058 plus dur » non stocké ; pivot 3 % |
| D045 | 4 | D | VALIDE | VALIDE | 10% | 0% | œuf |
| D046 | 5 | E | FAIBLE | FAIBLE | 9% | 2% | accord registre ; pivot 9 % |
| D047 | 5 | D | VALIDE | VALIDE | 8% | 1% | pièce `DOS_ETOILES` → ouvre D080 (pathdiv 52 %) |
| D048 | 5 | E | VALIDE | NON-IMPL. | 31% | 4% | **ruines du désert de la R111 au ch. 5, mais Lunettes Sable données au ch. 6** (`Route111_EventScript_ViciousSandstormTrigger` : `checkitem ITEM_GO_GOGGLES`) : inaccessible au moment prévu. Correctif : Bayar remet les Lunettes ou déplacer D048 au ch. 6 |
| D049 | 5 | E | VALIDE | VALIDE | 50% | 12% | pivote : held×26 M2×26 VS×17 M1×17 |
| D050 | 5 | E | VALIDE | VALIDE | 78% | 14% | pivote : PET×69 held×27 AMA×25 FK×21 |
| D051 | 5 | D | VALIDE | VALIDE | 38% | 11% | pivote : held×13 M2×9 F×7 VS×7 |
| D052 | 5 | E | VALIDE | VALIDE | 30% | 8% | pivote : held×16 F×10 FK×7 VS×6 |
| D053 | 5 | D | VALIDE | VALIDE | 33% | 2% | pivote : AMA×21 PET×8 held×7 FK×6 |
| D054 | 6 | E | VALIDE | VALIDE | 66% | 7% | pivote : held×38 M2×33 VS×30 M1×18 |
| D055 | 6 | D | VALIDE | FAIBLE | 9% | 2% | Potion + `HO` +8 ; `HOOPA_SOIGNE` sans lecteur, la dépendance D062 annoncée n'est pas câblée (D062 sans `when`) ; pivot 9 % |
| D056 | 6 | E | VALIDE | VALIDE | 18% | 2% | pivote : RK×5 BLUE×3 held×2 F×1 |
| D057 | 6 | D | VALIDE | VALIDE (fragile) | 14% | 0% | un sbire de moins au ch. 10 / aide aux civils (slot) ; pivot 14 % |
| D058 | 6 | D | VALIDE | VALIDE | 11% | 1% | équipe d'Erika (sélecteur) |
| D059 | 6 | E | VALIDE | VALIDE | 14% | 0% | pièce, ouvre l'option D095 a |
| D060 | 6 | D | VALIDE | VALIDE (fragile) | 14% | 3% | Brice témoin de D054 (BV) ; pivot 14 % |
| D061 | 6 | E | VALIDE | VALIDE | 52% | 0% | pivote : held×13 M1×5 cas×3 AMA×1 |
| D062 | 6 | D | VALIDE | VALIDE | 22% | 11% | pivote : held×18 F×13 FK×3 RK×3 |
| D063 | 7 | E | VALIDE | VALIDE | 72% | 0% | pivote : TIM×72 FLO×37 held×30 RK×12 |
| D064 | 7 | E | VALIDE | VALIDE | 100% | 0% | pivote : TIM×68 FLO×66 held×44 M2×4 |
| D065 | 7 | E | VALIDE | VALIDE | 32% | 16% | pivote : held×25 F×19 M1×8 FK×4 |
| D066 | 7 | D | VALIDE | FAIBLE | 5% | 0% | option b = +1 au compteur BV **déjà dominant** (ne change jamais le dominant) ; a/c = `HO` ; pivot 5 % |
| D067 | 7 | D | VALIDE | FAIBLE | 13% | 0% | seul lecteur : `REL_CHEN_SEKO` = ligne d'épilogue ; pivot 13 % (porté par `CS` seulement) |
| D068 | 7 | E | VALIDE | VALIDE | 41% | 2% | pivote : CS×21 FK×11 M1×10 held×9 |
| D069 | 7 | E | VALIDE | VALIDE | 28% | 3% | mais le vote ne dépend de D069 que si D036 a (si Bob POUR, le vote passe quoi que fasse Red) ; pivot 28 % via deltas |
| D070 | 7 | D | VALIDE | VALIDE | 31% | 0% | pivote : FLO×28 held×19 M2×4 VS×3 |
| D071 | 7 | E | VALIDE | VALIDE | 73% | 8% | pivote : PRA×50 held×33 M1×17 FK×11 |
| D072 | 8 | E | VALIDE | VALIDE | 18% | 0% | pivote : M1×8 M3×5 FK×5 held×4 |
| D073 | 8 | D | VALIDE | VALIDE | 10% | 2% | Absol dans l'équipe |
| D074 | 8 | E | VALIDE | VALIDE | 26% | 0% | pivote : FK×16 VS×8 RK×7 M1×4 |
| D075 | 8 | E | VALIDE | VALIDE | 52% | 14% | pivote : FK×25 RK×23 F×17 Maitre×16 |
| D076 | 8 | D | VALIDE | VALIDE | 70% | 9% | pivote : held×71 PRA×17 F×11 Maitre×7 |
| D077 | 8 | E | VALIDE | VALIDE | 60% | 12% | pivote : held×48 PRA×32 F×15 M1×12 |
| D078 | 8 | D | VALIDE | VALIDE | 32% | 2% | pivote : KOGA×30 FK×6 held×5 F×3 |
| D079 | 8 | E | VALIDE | VALIDE | 20% | 0% | don d'un Pokémon → Z-04 |
| D080 | 8 | D | VALIDE | VALIDE | 22% | 0% | pivote : M1×7 held×5 VS×4 M2×3 |
| D081 | 8 | E | VALIDE | VALIDE | 38% | 1% | pivote : KOGA×26 FK×9 held×7 RK×5 |
| D082 | 9 | E | VALIDE | VALIDE | 72% | 0% | pivote : RK×43 VS×38 M2×28 FK×20 |
| D083 | 9 | D | VALIDE | VALIDE | 58% | 18% | pivote : held×44 BLUE×34 F×22 AMA×3 |
| D084 | 9 | E | VALIDE | VALIDE | 60% | 12% | pivote : held×40 BLUE×37 F×15 FK×4 |
| D085 | 9 | D | FAIBLE | FAIBLE | 7% | 2% | accord registre |
| D086 | 9 | E | VALIDE | VALIDE | 57% | 10% | pivote : held×25 PET×25 FK×19 RK×16 |
| D087 | 9 | D | VALIDE | VALIDE | 35% | 0% | pivote : CS×13 FK×6 hid×3 held×2 |
| D088 | 9 | E | VALIDE | VALIDE | 16% | 4% | intention de Fuji au relais |
| D089 | 9 | D | VALIDE | VALIDE | 29% | 14% | pivote : held×14 F×9 FK×2 M1×2 |
| D090 | 9 | E | VALIDE | VALIDE | 8% | 1% | ouvre D104 (pathdiv 100 %) |
| D091 | 9 | D | VALIDE | FAIBLE | 14% | 0% | « l'assaut a moins de soutien local » non défini, aucun état ; RK/rL purs ; pivot 14 % |
| D092 | 9 | E | VALIDE | VALIDE | 25% | 3% | pivote : M1×16 held×6 FK×4 VS×4 |
| D093 | 9 | D | VALIDE | VALIDE | 13% | 0% | achat d'un arrivant |
| D094 | 10 | E | VALIDE | VALIDE | 45% | 14% | pivote : held×28 PET×18 F×17 M3×7 |
| D095 | 10 | E | VALIDE | VALIDE | 36% | 0% | pivote : KOGA×19 RK×17 FK×12 M3×7 |
| D096 | 10 | D | VALIDE | VALIDE | 20% | 1% | pivote : M1×6 M3×5 FK×5 hid×4 |
| D097 | 10 | E | VALIDE | VALIDE | 63% | 10% | pivote : PRA×37 held×30 M3×13 M1×13 |
| D098 | 10 | D | VALIDE | VALIDE | 21% | 0% | seconde équipe Rocket au ch. 13 (slot) |
| D099 | 10 | E | VALIDE | FAIBLE | 10% | 0% | `HO` ±5 seul, effet immédiat cosmétique ; pivot 10 % |
| D100 | 10 | D | VALIDE | VALIDE | 39% | 6% | pivote : PET×23 held×18 F×7 M3×6 |
| D101 | 10 | E | VALIDE | VALIDE | 34% | 8% | pivote : held×16 M1×15 F×10 PRA×5 |
| D102 | 11 | E | VALIDE | VALIDE | 64% | 3% | pivote : VS×38 M2×36 M1×21 held×16 |
| D103 | 11 | D | VALIDE | FAIBLE | 4% | 0% | `SARAH_TEMOIN` **écrit, jamais lu** par le modèle ; l'effet annoncé (« ART ne peut pas voter BRISER ») vise une option qui n'existe pas en M1 ; pivot 4 % |
| D104 | 11 | E | VALIDE | VALIDE | 15% | 0% | combat ; alliance Ondine |
| D105 | 11 | D | VALIDE | VALIDE | 20% | 1% | pivote : held×13 FLO×13 M2×5 VS×4 |
| D106 | 11 | E | FAIBLE | FAIBLE | 8% | 0% | accord registre |
| D107 | 12 | E | VALIDE | VALIDE | 21% | 0% | +1 bascule M3, N=3 |
| D108 | 12 | E | VALIDE | VALIDE | 57% | 6% | pivote : M1×57 F×7 held×6 M2×5 |
| D109 | 12 | E | VALIDE | VALIDE | 45% | 0% | pivote : M2×54 VS×46 M1×3 FK×1 |
| D110 | 12 | E | VALIDE | VALIDE | 82% | 1% | pivote : FK×96 M3×93 Maitre×26 RK×8 |
| D111 | 12 | E | VALIDE | VALIDE | 36% | 2% | pivote : M3×22 FK×17 M2×15 VS×12 |
| D112 | 12 | D | VALIDE | VALIDE | 28% | 4% | pivote : FK×14 CS×10 held×9 M3×6 |
| D113 | 12 | E | VALIDE | VALIDE | 32% | 1% | pivote : M3×29 FK×22 Maitre×9 M1×6 |
| D114 | 12 | D | VALIDE | VALIDE | 18% | 0% | R4 + accès D127 |
| D115 | 12 | D | VALIDE | VALIDE | 20% | 2% | seuil du rite / bilan civils |
| D116 | 13 | E | VALIDE | VALIDE | 100% | 79% | pivote : cas×120 held×120 F×95 AMA×68 |
| D117 | 13 | E | VALIDE | VALIDE | 100% | 100% | pivote : F×69 Maitre×24 held×7 RK×3 |
| D118 | 13 | D | VALIDE | VALIDE (fragile) | 12% | 0% | bilan civils (`PRET_CIVILS`) et présence de Hoopa ; pivot 12 % |
| D119 | 13 | E | VALIDE | VALIDE | 95% | 0% | pivote : AMA×20 |
| D120 | 13 | E | VALIDE | FAIBLE | 0% | 0% | aucun état lu avant l'épilogue/postgame (PNJ absents) ; pivot 0 % |
| D121 | 13 | D | VALIDE | VALIDE | 38% | 38% | pivote : F×8 |
| D122 | 13 | D | VALIDE | FAIBLE | 10% | 1% | ne fait que choisir entre deux seuils de `FLORA_DESOBEIT` ; pivot 10 % |
| D123 | 14 | E | VALIDE | VALIDE | 0% | 0% | variante du combat final de Blue |
| D124 | 14 | D | VALIDE | VALIDE | 0% | 0% | combat + Timmy (Zone) |
| D125 | 14 | E | VALIDE | FAIBLE | 0% | 0% | ne change que l'**ordre** des accès du postgame ; rien n'est perdu |
| D126 | 15 | E | VALIDE | VALIDE (fragile) | 0% | 0% | Mewtwo tout de suite ou plus tard (K1) : effet immédiat substantiel, mais ordre seulement à long terme |
| D127 | 15 | E | VALIDE | VALIDE | 0% | 0% | combat ; sbires retirés (`FLAG_CF_GIO_DISSOUT`) |
| D128 | 15 | E | VALIDE | VALIDE | 0% | 0% | zone restaurée (E-ECO), 10 000 ₽ |
| D129 | 15 | D | VALIDE | FAIBLE | 0% | 0% | `BL` ±3 après la fin (aucun lecteur de `BL` ensuite) ; coût « Tournoi fermé ce jour » trivial |
| D130 | 15 | E | FAIBLE | FAIBLE | 0% | 0% | accord registre |
| D131 | 15 | D | VALIDE | VALIDE (fragile) | 0% | 0% | Regis immédiats vs canal de fin ; n'existe que dans 2,6 % des parties (fin cachée) : à tester par save forcée |

Abréviations de la colonne Raison (sorties qui changent, en nombre de parties sur 120) : `held` alliés affectés au climax · `F` fin · `VS` variante sociale · `RK` Rocket · `cas` civils · `AMA` Amaryllis · `M1–M3` motions · `hid` fin cachée · `FK` ports · `CS` `REL_CHEN_SEKO` · `BLUE/PET/PRA/TIM/FLO/KOGA` positions de Blue, Peter, Pierre Rochard, Timmy, Flora, Koga.

---

## 2. Constats systémiques

Sévérité : **B** bloquant (le livrable ne tient pas sans correction) · **M** majeur (exigence du brief en danger) · **m** mineur.

### S1 — Le plancher tient, la marge de 10 % non (M)
- **Preuve :** table §1.2 → 109 VALIDE dont 11 fragiles (D016, D019, D025, D035, D038, D044, D057, D060, D118, D126, D131). 101 × 1,1 = 111,1 → il faut **112**. Le registre en annonce 124 : son `--check` ne calcule pas la robustesse, il **compte le champ déclaratif** `verdict` de `cf_decisions.py` (`if d['verdict'][0] == 'V': c['robust'] += 1`). Les « 0 anomalie » de `--check` portent sur gain/perte et bornes de deltas, pas sur la lecture effective.
- **Correctif (≈ 6 j-p, aucune carte neuve) :** remonter 8 décisions par un lecteur concret (§3.2) → ≈ 117–120 VALIDE ; remplacer le compteur déclaratif par le test contrefactuel de l'annexe A (seuil : pivot ≥ 15 % ou effet immédiat substantiel listé).

### S2 — D048 inaccessible au chapitre prévu (M, correctif trivial)
- **Preuve :** D048 se joue « Route111 (désert, ruines) » au ch. 5. Le désert est fermé par `Route111_EventScript_ViciousSandstormTrigger` (`checkitem ITEM_GO_GOGGLES`, `data/maps/Route111/scripts.inc` l. 188–191, 10 déclencheurs dans `map.json`). Les Lunettes Sable sont données par Brice au **ch. 6** (`GAME_SYSTEMS` §15.1 ; `LavaridgeTown/scripts.inc` l. 62). La pièce `DOS_SCEAUX_ANCIENS` et le cran Z-03 de D048 b sont donc hors d'atteinte au ch. 5.
- **Correctif :** Bayar remet les Lunettes Sable en ouvrant sa quête (et le don de Brice au ch. 6 devient un objet de remplacement), ou D048 passe au ch. 6. Ajouter la ligne à §15.2.

### S3 — Le chemin doré existe : Pacte, intégration, Rocket démantelée **et** aucun blessé (M)
- **Preuve :** `python3 -I docs/hack/data/cf_model.py --golden` → score 125 : `F2 INTEGRATION DEMANTELEE`, civils **AUCUN**, relations BR 60, BL 68, FL 60, PR 60, PE 64, TI 61, GI 66, HO 80 (8/9 ≥ 60). Détail de la partie : Red **aux civils** (D116 c), Pierre Rochard au relais, Peter au Pilier, M1 = LIBÉRER (D108 c), garde RED (D075 a), D102 c (câble coupé !). Mécanisme : `ally_intent(PR)` = PACTE quand M1 = 3, et `HOOPA_PRÉSENT` est vrai par la clause « M1 = LIBÉRER ∧ `HO` ≥ 60 » sans que Red confie Hoopa ; `HO` = 80 suffit au seuil allié.
- `GAME_SYSTEMS` §5 affirme le contraire (« civils BLESSÉS, Amaryllis PERSISTE… ») : la première moitié est **fausse**. Le reste à payer réel : Amaryllis PERSISTE, pas de fin cachée, `S(rC)` −24, `S(rA)` −12 — des chiffres invisibles, pas des pertes vécues. Cela contredit la table §10.6 (« Civils : AUCUN blessé ; la fin dépend des intentions ») qui présentait l'absence de Red au relais comme un vrai pari.
- **Correctif (un seul suffit) :** (a) la clause M1 = LIBÉRER ne rend Hoopa présent que si Red est au relais **ou** D118 a ; (b) un Pacte donné par un allié en l'absence de Red ouvre un anneau sur la place → civils au mieux BLESSÉS ; (c) PR ne porte PACTE que si `PR` ≥ 65 ∧ `DOS_VOIX_RELAIS`. Puis relancer `--golden` et corriger §5.

### S4 — F4 est un puits d'échec pour 4 styles cohérents sur 9 ; 3 fins sont « mono-jauge » (M)
- **Preuve (300 parties par persona, `persona_chooser`) :** HOOPA → F2 100 % ; AQUA → F5 100 % ; CONSORTIUM → F3 95 % ; GARDIENS → F1 65 % ; mais **MISSION → F4 95 %**, RELATIONS → F4 82 %, ANTI-ROCKET → F4 79 %, REMPART → F4 73 %, ALÉA → F4 63 %.
- Lecture : (1) un joueur qui sert une seule cause **et** choisit l'intention assortie obtient sa fin à coup sûr : pas de morale unique, mais une **jauge par fin** (HO pour F2, `S(rC)` pour F3) — le cumul des autres systèmes ne joue presque plus ; (2) un joueur pro-Mission ou « gentil avec tout le monde » échoue presque toujours au SCEAU (pas de rite sans Doyenne, `S(rG)` relatif bas) et reçoit F4, que la bible décrit comme « Rayquaza détruit le relais ». Réponse à la question résiduelle 1 de l'arbitrage : **oui**, F4 sera vécue comme un échec par la majorité.
- **Correctif :** (a) créer une intention **REMPART** explicite (Red aux civils avec Flora ou Bob, ou Rempart défendu en M2) qui mène à F4 comme fin **choisie** ; (b) SCEAU sans rite → F1 dégradée (Pilier tenu, relais perdu) plutôt que F4 ; (c) pour F2/F3, exiger un second système non corrélé (ex. F3 : `S(rL)` ≥ −5 **et** ≥ 2 zones non ENVAHI).

### S5 — La lecture relative rend des gestes discrets décisifs et illisibles (M)
- **Preuve :** D025 (présence discrète au quai, deltas ±2/±3, classée FAIBLE par le registre) fait basculer `PETER_ASSUME` dans 43 % des parties ; D028 (homme au Persian) change les options proposées plus tard dans 100 % des parties (accès au duel de Giovanni, `GI` ≥ 50). Avec `S(X) = rX − moyenne(7)`, **chaque** delta de réputation déplace les 6 autres positions : un +3 au port peut fermer la Doyenne (`S(rG)` ≥ +3) au climax.
- La règle 10 (« tout seuil lu au climax est annoncé à la veillée ») ne couvre pas les positions relatives, que rien n'affiche : l'équité après coup des décisions discrètes n'est pas tenue pour celles qui n'agissent que par `S()`.
- **Correctif :** (a) un rapport de rang des factions à chaque fin de chapitre (Carnet : « Le port vous fait plus confiance que la Mission ») ; (b) réserver la lecture relative au Sommet et au climax, lire les seuils intermédiaires en absolu ; (c) spécifier l'arrondi d'E-REPREL : comparer `7·rX − Σr` à `7·seuil` (entiers), sinon le modèle (flottant) et la ROM divergent d'un point.

### S6 — États écrits sans lecteur vérifiable (m → M si non corrigé avant la tranche)
- **Preuve (`grep` des noms de flags dans `cf_model.py` et dans les `req`/`when` de `cf_decisions.py`) :** sans aucun lecteur modélisé : `PIKA_BLESSE`, `MARCO_ALLIE`, `BOIS_SAUVES`, `BROCK_PROTEGES`, `ALDO_RESPECT`, `ERIKA_CONTRAT`, `PIKA_EQUIPE`, `HOOPA_SOIGNE`, `STANCE_ERIKA_INT`, `RITE_PROTEGE`, `SARAH_TEMOIN`, `CIVILS_PORT`, `CIVILS_CENTRE`, `DUO_PETER`, `DUO_PR`, `MEWTWO_*`. Beaucoup ont un lecteur **hors modèle** (sélecteurs du brief B, soins de Fondmer, épilogue) : acceptable, mais aujourd'hui invérifiable.
- **Vrais orphelins :** `SARAH_TEMOIN` (effet annoncé « ART ne peut pas voter BRISER » : BRISER n'est pas une option de M1, et `base_votes` ne lit pas le flag) ; `HOOPA_SOIGNE` (D062 « Red peut montrer à Auguste » n'a pas de `when`) ; `BROCK_PROTEGES` (le registre §6 le donne comme sélecteur de Pierre (Brock), `COMBAT_DESIGN` §5.1 lit **l'état de Z-02**).
- **Correctif :** chaque flag sans lecteur modélisé reçoit soit une ligne dans le modèle, soit une référence de lecteur (carte + label) dans `GAME_SYSTEMS` §16 ; aligner le sélecteur de Pierre (Brock).

### S7 — Seuil inatteignable : `PA` ≥ 80 (m)
- **Preuve :** `--sim 3000` : `PA` max = 76 aux ch. 12 et 13 (60 au plus avant le ch. 9). `ENCOUNTERS_PLAN` §13.1 lit `PA` ≥ 80 (épidémie P2 à Bourg-en-Vol, O17, et « 4 anomalies par chapitre ») : jamais vrai.
- **Correctif :** seuil à 70 ou retirer O17 de la liste des lecteurs.

### S8 — Sommet : départage par défaut vers le statu quo ; LIBÉRER presque mort (m)
- **Preuve :** `summit()` : égalité → option défendue si `N` ≥ 2 ou `BR` ≥ 60, **sinon la plus petite** (statu quo). Résultat `--sim 3000` : M1 FERMER 71 %, CHARTE 26 %, **LIBÉRER 2,9 %** (question résiduelle 2). LIBÉRER sert surtout… le chemin doré de S3.
- **Correctif :** départage par Juan selon les sources R4 (déjà calculées), ou par l'option qui a reçu la bascule de Red ; puis revérifier S3.

### S9 — Fins : exhaustivité, exclusivité, cohérence documentaire (m)
- `climax()` reproduit exactement §10.4 (F2 → F1 → F3 → F5 → `else` F4) : **exhaustif et exclusif** ; la fin cachée est une couche orthogonale (2,6 % des parties, `CACHEE 78/3000`). 15/15 combinaisons fin × variante sociale atteintes.
- Incohérences : §1 annonce « 4 variantes Rocket », le modèle et §10.5 en ont 3 ; `GAME_SYSTEMS` §1 donne la fin cachée à 2,3 %, le `--sim 3000` à 2,6 % (graines différentes, sans gravité).
- **Correctif :** aligner les textes.

### S10 — Économie : le modèle ne borne pas les achats par l'argent (m)
- **Preuve :** `--sim 3000` affiche `ARGENT<0 1745` (58 %). Mesure séparée : sans Kiosque, **0** option payante choisie hors de portée ; avec le Kiosque aléatoire (0–2 commandes/chapitre), 53 % des parties « paient » une option qu'elles n'ont pas (D128 dans 45 % des parties, D093, D124, D084…). Le modèle compte donc des `PA` de Kiosque impossibles, ce qui biaise F3 (`PA` < 50) et les anomalies.
- Pas de farming possible (revanches coupées : `FREE_MATCH_CALL TRUE`, `include/config/save.h:12`) : c'est voulu, mais D128 (10 000 ₽, postgame) devient inaccessible pour qui a commandé au Kiosque ; c'est une conséquence lisible, pas un blocage.
- **Correctif :** dans `kiosk()` et `apply()`, refuser l'achat si `money` < prix ; recalibrer les distributions.

### S11 — Budget d'IDs : vérifié, deux trous de stockage (m)
- **Vars :** `include/constants/vars.h` contient 61 vars « unused » en 0x40xx ; 7 `VAR_GIFT_UNUSED_*` sont écrites par `src/event_data.c:154` (exclues à raison) → **54 libres**, aucune référence hors commentaires (`include/config/battle.h:267` cite `VAR_UNUSED_0x404E` en exemple). 44 utilisées → 10 libres : **conforme** à §14. `VAR_DIFFICULTY` occupe déjà 0x40F7.
- **Flags :** 0x22–0x4F (46), 0x264–0x2BB (88), 0x493–0x4EF (93), 0x8E5–0x91F (59) : tous `FLAG_UNUSED_*` ; références trouvées uniquement dans des commentaires d'exemple (`include/config/*.h`) et dans `flags_frlg.h` (autre jeu) : **conforme**.
- **Contrôle de l'allocation en cours** (non commitée au moment de la revue : `include/constants/vars.h`, `flags.h`, `include/constants/confluence.h`) : 44 `VAR_CF_*` remplacent 44 anciennes définitions ; aucun des 44 anciens noms (ex. `VAR_DEWFORD_TOWN_STATE`, `VAR_UNUSED_0x404E`) n'est encore référencé dans `src/`, `data/` ou `include/` hors `vars.h`, `vars_frlg.h` et commentaires de `include/config/`. `VAR_SOOTOPOLIS_CITY_STATE` et `VAR_MOSSDEEP_CITY_STATE` sont bien conservées. Conforme.
- **Trous :** (a) le plafond « 3 victoires primées par chapitre » du Tournoi (D034) n'a **aucun stockage** (`VAR_CF_WORLD` est plein, b0–b15) ; (b) l'état « anomalie active » d'E-OUT et le compteur d'anomalies par chapitre ne sont pas alloués. Deux vars (ou 6 bits) à prendre dans la marge.

### S12 — Traversée : la chaîne de M. Marco (Briney) n'est pas traitée (M pour la tranche ch. 0–2)
- **Preuve :** M. Marco = Briney, présent dès le ch. 0 (D006) et passeur au ch. 2. En vanilla, il est caché par `new_game.inc:132` (`setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY`) et réapparaît seulement par `RustboroCity_DevonCorp_3F/scripts.inc:65` (retour des Marchandises Devon, après Peeko au Tunnel Mérazon) ; `VAR_BRINEY_HOUSE_STATE` pilote sa position. Ici, le Tunnel n'est résolu qu'au ch. 4 (D040). `GAME_SYSTEMS` §15.2 ne liste ni ces flags, ni `FLAG_HIDE_ROUTE_104_MR_BRINEY`, ni `FLAG_DEVON_GOODS_STOLEN`.
- Autres points vérifiés : badges → CS (`src/field_move.c`) cohérents avec §15.1 (Éclate-Roc B3 au ch. 4, Plongée B7 au ch. 10, Cascade B8 au ch. 12) ; D079/D123 « option masquée si < 2 Pokémon » doit aussi exclure œufs et Pokémon K.O. (les CS restent réapprenables : pas de blocage) ; D035 « barrage R110 ouvert » en option a : vérifier que b ne ferme pas R110 (sinon softlock au ch. 4).
- **Correctif :** ajouter la chaîne Briney à §15.2 avec traitement explicite (Marco visible dès `CF_Init`, `VAR_BRINEY_HOUSE_STATE` fixé), et un test de traversée ch. 0 → ch. 3 dans le harnais.

### S13 — Aides moteur : faisabilité et taille
| Aide | Faisabilité constatée dans le source | Taille estimée | Risque |
|---|---|---|---|
| E-CAP | `LEVEL_CAP_VARIABLE` existe (`src/caps.c:38–40`) ; `caps.h` est encore sur `LEVEL_CAP_FLAG_LIST` / variable 0 ; `goto_if_le VAR, VAR` fonctionne (`compare` choisit var/var, `event.inc:261`) | config + 6 lignes de script | nul |
| E-BITS | trivial (`VarGet`/`VarSet` + masques) | ~40 lignes C, 2 specials | **chemin critique** : 17 vars de slots, WORLD, ECO, SUMMIT, CLIMAX, FIN, STANCE en dépendent |
| E-REPREL | trivial ; spécifier l'arrondi (S5) | ~20 lignes | divergence modèle/ROM |
| E-REMOVE | briques `ZeroMonData` + `CompactPartySlots` (`ENGINE_CHANGES` « Retirer un Pokémon ») | ~15 lignes + gardes (dernier apte, objet tenu, suiveur) | D001 retire **toute** l'équipe : prévoir un mode « vider » |
| E-NATIVE | table Hoenn existante (numéros régionaux) | ~10 lignes | nul |
| E-ADAPT | boucle sur l'équipe, scores de types | ~30 lignes | nul |
| E-LEDGER | `SaveBlock3` a un `STATIC_ASSERT` de taille (`src/save.c:80`) ; 16 o tiennent | ~40 lignes | compatibilité des saves de test à figer avant |
| E-OUT | les champs d'épidémie existent en **un seul exemplaire** (`include/global.h:1150–1154`) : une anomalie active à la fois | 100–200 lignes (poser, effacer, couper le tirage TV) | « 2–4 anomalies par chapitre » et « épidémies tournantes » F5 doivent être **séquentielles** |
| E-ECO | crochet sur la sélection d'en-tête sauvage (lookup {carte → zone} puis décalage d'en-tête) + générateur JSON des 4 états × jour/nuit | 150–300 lignes C + générateur ; ROM +40–80 Kio (79,85 % utilisés : OK) | plus gros poste ; test « 4 en-têtes consécutifs » exigé par D §14 |
| D1, E affinités | **déjà faits et testés** (`ENGINE_CHANGES` tableau d'état) | — | UI OUI/NON non testée en émulateur |
Total ≈ 450–700 lignes C, **8–12 j-p** avec tests unitaires. IWRAM à 86,6 % : tout en ROM/EWRAM (respecté par toutes les aides).

### S14 — Plafonds de niveau : posés dans toutes les branches (conforme, m)
Les 22 jalons de §7 sont posés dans des scripts de fin communs ou des combats obligatoires, avec un plancher par chapitre ; aucun jalon n'est dans une branche. Seul point : le Tournoi (D034 a) et D063 a (Vergazon sans Red) ne posent pas de jalon, ce qui est correct. Rien à corriger hors S12.

### S15 — Cohérence registre ↔ combat ↔ rencontres (m)
- Timmy : `COMBAT_DESIGN` §5.1 écrit « `TIMMY_SAUVE` (D038, D064) » ; D038 ne pose aucun flag (le slot `VAR_CF_D04` doit être lu explicitement).
- Les 8 décisions d'orphelins transmises par `ENCOUNTERS_PLAN` §13.1 au brief C ne sont pas numérotées : c'est une **réserve** de décisions discrètes (choix d'adoption, PNJ receveur) déjà spécifiée, utile pour S1.

---

## 3. Décomptes et recommandations

### 3.1 Décomptes
| Mesure | Registre | **Cette revue** |
|---|---|---|
| Listées | 131 | 131 |
| VALIDE (comptables) | 124 | **109** (dont 11 fragiles) |
| VALIDE robustes sans réserve | — | **98** |
| FAIBLE | 7 | **20** (D004, D005, D013, D030, D033, D042, D046, D055, D066, D067, D085, D091, D099, D103, D106, D120, D122, D125, D129, D130) |
| DOUBLON | 0 | **1** (D039 ≈ D019) |
| NON-IMPLÉMENTABLE (tel que spécifié) | 0 | **1** (D048) |
| NON-TESTABLE | 0 | 0 (D131 n'apparaît que dans 2,6 % des parties : testable par save forcée) |
| Discrètes parmi les VALIDE | 54 / 124 | 45 / 109 = **41 %** (≥ 30 % : tenu) |
| Marge sur 101 | +23 | **+8 (7,9 %)** — exigence ≥ 10 % **non tenue** |
| Ch. 0–4 (tranche) | 42 / 45 | **38 / 45** |

### 3.2 Remontées à coût faible (chaque ≈ 0,5 j-p, aucune carte neuve)
| Décision | Lecteur à créer | Effet |
|---|---|---|
| D048 | Lunettes Sable données par Bayar | redevient VALIDE (pivot 31 %) |
| D013 | D063 a (filature) **exige** `LAMBDA_REMARQUE` ; sinon la filature passe par D059 a | ouvre/ferme une option exclusive |
| D033 | la lettre de Ferrand (D082 a) exige `INFO_ENTREPOT` ou Olga suivie, sans la clause `S(rI)` | pièce de la fin cachée |
| D055 | D062 a n'existe que si `HOOPA_SOIGNE` | accès |
| D103 | `SARAH_TEMOIN` : Arthur s'abstient en M1 **et** M2 (un votant en moins) | Sommet |
| D066 | option b ajoute à **COMPRENDRE** (le recensement) au lieu du dominant | voie de Brice |
| D120 | port → Z-01 +1 cran au glissement M2 ; Centre → `TIMMY_SAUVE`/arrivants protégés comptent pour INTÉGRATION | variante sociale |
| D039 | le fermier devient témoin à charge au vote d'abattage (D069) si piège laissé | différencie de D019 |
→ **≈ 117 VALIDE** (marge 16 %). Ajouter si besoin 2–4 décisions d'orphelins (S15) déjà spécifiées par le brief D.

### 3.3 Recommandations (ordre)
1. **Avant la tranche ch. 0–2 :** S12 (Briney), S2 (D048), E-BITS + E-REPREL + E-CAP, remontées D013/D033.
2. **Avant le gel définitif :** S3 (chemin doré) puis S8 (départage), S4 (F4 choisie), S5 (lisibilité de `S()`), S6 (orphelins), S10 (modèle borné par l'argent), relancer `--sim 18000` et `--golden`, mettre à jour `GAME_SYSTEMS` §5.
3. **Outillage :** remplacer le champ déclaratif `verdict` par le test contrefactuel (annexe A) dans `--check` ; seuil d'alerte pivot < 10 %.

---

## 4. Estimation d'effort

Hypothèses (à mesurer sur la tranche) : script de décision S ≈ 80 lignes et 12 boîtes, M ≈ 200 lignes et 30 boîtes, L ≈ 400 lignes et 75 boîtes ; lecteur ≈ 10 lignes et 2 boîtes (297 lecteurs déclarés) ; productivité ≈ 200 lignes de script testées/jour, ≈ 100 boîtes écrites et relues/jour.

| Poste | Jeu complet (131 déc. : 90 S, 33 M, 8 L ; 108 unités de carte) | Ch. 0–4 (45 déc. : 34 S, 9 M, 2 L ; 41 unités) |
|---|---|---|
| Scripts de décision + lecteurs | ≈ 20 000 lignes → 100 j-p | ≈ 6 500 lignes → 33 j-p |
| Scènes d'histoire hors décisions, arènes réécrites | 60–90 j-p | 15–20 j-p |
| Texte (boîtes) | décisions ≈ 3 400 + histoire ≈ 2 000–3 000 = **5 400–6 400** (la bible prévoit 3 500–4 500 : **sous-estimé**) → 55–65 j-p | ≈ 1 800–2 000 → 18–20 j-p |
| Cartes (PNJ, objets, déclencheurs, `FLAG_HIDE_*`) | ≈ 30 j-p | ≈ 12 j-p |
| Moteur (S13) | 8–12 j-p | 6–8 j-p (E-BITS, E-REPREL, E-CAP, E-REMOVE, E-ECO pour Z-01–Z-03) |
| Équipes (175 générées) et rencontres (JSON E-ECO, E-TOD) | 25–35 j-p | 6–8 j-p |
| QA (une save forcée par décision et par témoin, régressions, traversée) | 45–65 j-p | 15–20 j-p |
| **Total** | **≈ 330–420 j-p** (16–20 mois à une personne) | **≈ 95–115 j-p** |

Les ch. 0–4 portent 34 % des décisions mais aussi toute l'infrastructure (E-BITS, slots, Carnet, macro de fin commune, harnais) : c'est la bonne tranche pour mesurer les productivités ci-dessus avant d'engager la suite.

---

## Annexe A — Reproduire les mesures
- `python3 -I docs/hack/data/cf_model.py --check` → `robust 124` (champ déclaratif) ; `--sim 3000` → `FINS {'F1': 466, 'F2': 336, 'F3': 330, 'F4': 1393, 'F5': 475}`, `MOTIONS {1: {1: 2137, 2: 775, 3: 88}, …}`, `CACHEE 78`, `ARGENT<0 1745`, `PA` max 76 ; `--golden` → `GOLD score 125 F2 INTEGRATION DEMANTELEE AUCUN PERSISTE`.
- Test contrefactuel (script utilisé pour la colonne Pivot ; Python 3, à lancer depuis n'importe quel dossier) :
```python
import sys, random, collections
sys.path.insert(0, 'docs/hack/data'); import cf_model as M
orig = M.climax
def det(s, rng, assign=None):            # affectation du climax figée
    r = orig(s, random.Random(99), assign); s['val']['HELD'] = tuple(sorted(s['val']['held'].items())); return r
M.climax = det
names = list(M.PERSONAS)
def mk(pn, k, did, force, ok):           # bruit indexé (partie, décision, option) : pas de désynchronisation
    w, pref = M.PERSONAS[pn], M.CLIMAX_PREF[pn]
    def ch(s, d, opts, rng):
        if d['id'] == did:
            if force in opts: return force
            ok[0] = False
        best, bi = None, opts[0]
        for i in opts:
            o = d['opts'][i]; r = random.Random('%d-%s-%d' % (k, d['id'], i)).uniform(-1.5, 1.5) * 3
            sc = sum(w.get(x, 0) * dv for x, dv in o['d'].items()) + (r if w else r * 10)
            if pref[0] and o['fx'].get('loc') == pref[0]: sc += 50
            if pref[1] and o['fx'].get('intent') == pref[1]: sc += 50
            if best is None or sc > best: best, bi = sc, i
        return bi
    return ch
def out(s):
    v = s['val']; f = s['flags']
    return (v['F'], v['VS'], v['rocket'], v['cas'], v['ama_issue'], v['M1'], v['M2'], v['M3'], s['hidden'], v.get('MAITRE'),
            v.get('FK'), v['HELD'], 'REL_CHEN_SEKO' in f, 'BLUE_LIBRE' in f, 'PETER_ASSUME' in f, 'PR_ACCUSE' in f,
            'TIMMY_SAUVE' in f, 'FLORA_DESOBEIT' in f, v.get('KOGA'))
for d in M.DECISIONS:
    tot = piv = 0
    for k in range(120):
        res = []
        for force in range(len(d['opts'])):
            ok = [True]; s = M.play(random.Random(1000 + k), mk(names[k % len(names)], k, d['id'], force, ok))
            if ok[0] and d['id'] in s['choice']: res.append(out(s))
        if len(res) >= 2: tot += 1; piv += len(set(res)) > 1
    print(d['id'], '%.0f%%' % (100 * piv / max(tot, 1)))
```
- Greps de budget : `grep -niE unused include/constants/vars.h` puis, par nom, `grep -rlw NOM src data include` hors `vars.h` ; idem pour les plages de flags (`flags.h`).

## Changelog
| Date | Changement | Auteur |
|---|---|---|
| 2026-10-14 | Création : revue indépendante systèmes/faisabilité de la v3.1 (131 verdicts, 15 constats, effort) | critique systèmes |
