# DECISION_LEDGER — *Pokémon Confluence* (v3, brief C) — règles, synthèse, fins, audit

> Fichiers par acte (générés, une fiche complète par décision) : `DECISION_LEDGER_ACT0-1.md` (ch. 0–4), `DECISION_LEDGER_ACT2.md` (ch. 5–10), `DECISION_LEDGER_ACT3.md` (ch. 11–14), `DECISION_LEDGER_POST.md` (postgame).
> Source unique des données : `docs/hack/data/cf_decisions.py` ; modèle et rendu : `cf_model.py` (`--check`, `--sim`, `--golden`, `--render`). Systèmes, seuils, Sommet, climax, fins : `GAME_SYSTEMS.md`. IDs : `FLAGS_VARS_REGISTRY.md`.
> **Statut : toutes les décisions sont `proposé`. Rien n'est implémenté ni testé sur ROM.** Les vérifications citées sont celles du modèle papier (commande + sortie reproductibles), pas des tests de jeu.

## 1. Décompte
| Mesure | Valeur | Cible (brief C) |
|---|---|---|
| Décisions listées | **131** (budgets bible §8.3 respectés chapitre par chapitre) | 131 |
| **Robustes (VALIDE, lecture stricte de la grille REVIEW_V2_SYSTEMS §1)** | **124** | ≥ 115 |
| FAIBLE, listées non comptées | 7 : D004 (starter), D025, D042, D046, D085, D106, D130 | — |
| DOUBLON / NON-IMPL. comptées | 0 / 0 | 0 |
| Explicites / discrètes | 75 / **56 (42,7 %)** ; parmi les robustes : 70 / 54 | ≥ 30 % discrètes |
| Classes S / M / L | 90 (69 %) / 33 (25 %) / **8 (6,1 %)** : D001, D040, D054, D068, D075, D082 (bible) + D102, D116 | ≈ 70/25/5 |
| Délai principal immédiat / court / long | 54 (41 %) / 54 (41 %) / 23 (18 %) | ≈ 50/35/15 (écart : beaucoup de décisions préparent le Sommet ; assumé) |
| Combats refusables qui sont des décisions (macro D1) | 12 : D008, D022, D027, D043, D056, D081, D084, D100, D104, D111, D124, D127 | — |
| Vérification automatique | `cf_model.py --check` : 0 anomalie (gain **et** perte par option, deltas ≤ ±5 S / ±8 M / ±10 L, signal de mémoire pour toutes les M et L comptées, ≥ 1 lecteur par décision) | — |

Par chapitre (listées / robustes / discrètes) : 0 : 7/6/3 · 1 : 10/10/5 · 2 : 7/7/4 · 3 : 11/10/5 · 4 : 10/9/4 · 5 : 8/7/3 · 6 : 9/9/5 · 7 : 9/9/3 · 8 : 10/10/4 · 9 : 12/11/6 · 10 : 8/8/3 · 11 : 5/4/2 · 12 : 9/9/3 · 13 : 7/7/3 · 14 : 3/3/1 · P : 6/5/2.

## 2. Règles du registre (durcies après la revue v2)
1. **Champs obligatoires** (chaque fiche par acte) : ID · Type E/D · Classe S/M/L · nature (arbitrage, présence, don, aveu, combat, geste) · Unité (carte vanilla + label `CF_Dxxx`) · Déclencheur · Prérequis · Stockage · Options (deltas, immédiat, différé, gain/perte) · Lecteurs · Délai · signal de mémoire (M, L) · Fins · Test · Statut · Verdict.
2. **Gain et perte dans deux systèmes différents pour chaque option** (vérifié par script ; les objets, l'argent, l'équipe, le Dossier, la garde de Hoopa et les zones comptent comme systèmes).
3. **Garde à usage unique :** chaque décision a un slot de 2 bits (`VAR_CF_Dnn`) ; tous ses deltas sont appliqués par `CF_Dxxx` seulement si le slot vaut 0, puis le slot prend la valeur de l'option (exception : D117 → `VAR_CF_FIN` b5-7). Reparler ne rapporte rien (S17).
4. **Deltas :** S ≤ ±5, M ≤ ±8, L ≤ ±10, par `addaffinity`/`subaffinity` (bornes 0–100).
5. **Aucun état écrit sans lecteur** (table « lectures par carte », `GAME_SYSTEMS` §16 ; colonne Lecteurs de chaque fiche) ; lecteurs placés **après** l'écriture.
6. **Seuils** placés dans la plage atteignable au moment de la lecture (tableau de cumul, `GAME_SYSTEMS` §4) ; réputations lues **relativement** (`S(X)`).
7. **Refus :** uniquement par `trainerbattle_single_declinable` avec `FLAG_CF_REFUS_*` et script de refus qui écrit le slot (valeur 3). Aucun combat obligatoire n'est refusable.
8. **Jalons :** jamais posés dans une branche ; toujours dans le script de fin commun (`CF_Dxxx_End`) + plancher de chapitre.
9. **Présence exclusive** (≥ 3 paires) : D063 (filature / Vergazon), D082 (Olga / raid Aqua / libération), D116 (relais / Pilier / civils) ; plus D018 c (nuit en mer / Pierre Rochard) et D096 (jumeaux / quai).
10. **Équité après coup :** tout seuil lu au climax est annoncé à la veillée ; les gestes discrets ont un retour immédiat (Hoopa rend ou fuit, un PNJ se tait, le Carnet note).
11. **Test reproductible** par décision : état de départ, séquence, observation, vars/flags attendus (fiches). Harnais : saves forcées par le menu debug (`QA_TOOLING.md`).

## 3. Synthèse des 131 décisions
| ID | Ch. | Titre | Type | Classe | Nature | Délai | Systèmes touchés | Verdict |
|---|---|---|---|---|---|---|---|---|
| D001 | 0 | Qui Red rattrape dans l'anneau | E | L | presence | court | rC, rI, Dossier | VALIDE |
| D002 | 0 | Accreditation par telephone : nom ou anonymat | E | M | aveu | court | BR, RK, rL | VALIDE |
| D003 | 0 | Ronde nocturne de Brice encerclee (R101) | D | S | geste | court | BR, HO, BV | VALIDE |
| D004 | 0 | Starter de Seko (Arcko, Poussifeu, Gobou) | E | S | arbitrage | imm. |  | FAIBLE |
| D005 | 0 | Lettre de Chen : la montrer à Seko ou la garder | E | S | don | court | BR | VALIDE |
| D006 | 0 | Rester chez M. Marco ou suivre Ciléo | D | S | presence | court | rI, rL, Dossier | VALIDE |
| D007 | 0 | R103 : l'arrivant blessé | D | S | arbitrage | imm. | rL, BV | VALIDE |
| D008 | 1 | Bois Clémenti : Flora et la brigade (combat refusable) | E | M | combat | imm. | BR, FL, rL | VALIDE |
| D009 | 1 | L'affiche Passerelle (Red de dos) | D | S | presence | long | BR, RK, Dossier | VALIDE |
| D010 | 1 | Mission de zone Z-02 : les mines de Devon | E | M | arbitrage | imm. | TI, rA, rC, rI, rL, rP, ECO | VALIDE |
| D011 | 1 | Presentation de Passerelle : la photo publique | E | S | arbitrage | court | rC, rP | VALIDE |
| D012 | 1 | Petit voleur n 1 : le carnet de Brice | D | S | geste | court | BR, HO, BV | VALIDE |
| D013 | 1 | Devon 2F : l'ingenieur 'Ferrand' | D | S | geste | court | BR, RK | VALIDE |
| D014 | 1 | R116 : contrebandiers Rocket avant l'anneau | E | M | arbitrage | imm. | RK, TI, rA, rL, Dossier | VALIDE |
| D015 | 1 | Le sbire ruiné (ancien mineur) | D | S | don | court | RK, rP | VALIDE |
| D016 | 1 | Badge 1 : Roxanne demande les données de Red | E | S | arbitrage | court | BR, rL | VALIDE |
| D017 | 1 | QG de Clémenti : l'insigne de brigade | D | S | don | court | rA, rL | VALIDE |
| D018 | 2 | Mission de zone Z-01 : les pêcheries de Myokara | E | M | arbitrage | imm. | PR, rA, rP, BV, ECO | VALIDE |
| D019 | 2 | Petit voleur n 2 : le poisson du marché | D | S | geste | court | HO, rP | VALIDE |
| D020 | 2 | Grotte Granite : le secret des éclats | E | S | aveu | court | PR, BV, Dossier | VALIDE |
| D021 | 2 | Badge 2 : l'arrivant de Bastien | E | S | don | imm. | rA, rP | VALIDE |
| D022 | 2 | Aldo propose un duel (refusable) | D | S | combat | court | BR, rI, rP | VALIDE |
| D023 | 2 | R106 : le pêcheur qui vend un arrivant | D | S | don | imm. | RK, rL, rP | VALIDE |
| D024 | 2 | Emmener Brice à la Grotte Granite | D | S | presence | long | BR, PR, BV | VALIDE |
| D025 | 3 | Débarquement de la Mission : de quel côté du quai | D | S | presence | court | PE, rI, rP | FAIBLE |
| D026 | 3 | Kiosque Passerelle : première commande (loi H1) | E | M | arbitrage | imm. | PA, rC, rP | VALIDE |
| D027 | 3 | Blue 1 à la Tente de Scott (refusable) | E | M | combat | imm. | BL, PE, rC, rI | VALIDE |
| D028 | 3 | L'homme au Persian au marché | D | S | geste | court | GI, rI | VALIDE |
| D029 | 3 | Composant Devon pour le Capitaine Marin | E | S | arbitrage | long | rC, rI, Dossier | VALIDE |
| D030 | 3 | Chen demande les données de Red | E | S | don | imm. | BR | VALIDE |
| D031 | 3 | Petit voleur n 3 : l'objet du Kiosque | D | S | geste | court | HO, rI, Dossier | VALIDE |
| D032 | 3 | La pétition 'ports fermes à Kanto' | E | S | arbitrage | long | rI, rP | VALIDE |
| D033 | 3 | Rumeur de marché noir : payer l'informateur | D | S | don | court | RK | VALIDE |
| D034 | 3 | Le contrat de Scott | E | S | arbitrage | court | BL, rC | VALIDE |
| D035 | 3 | Maison de la plage (R109) : les arrivants caches | D | S | aveu | imm. | rA, rL | VALIDE |
| D036 | 4 | Lavandia : le quartier sud coupe | E | M | presence | imm. | rL, rP | VALIDE |
| D037 | 4 | Mission de zone Z-03 : les vergers de Vergazon | E | M | arbitrage | imm. | TI, rA, rC, rI, rL, rP, BV, ECO | VALIDE |
| D038 | 4 | Timmy et son arrivant condamne | D | S | don | court | TI, rL | VALIDE |
| D039 | 4 | Petit voleur n 4 : le piege du fermier | D | S | geste | court | HO, rP | VALIDE |
| D040 | 4 | Raid du Tunnel Merazon : l'approche | E | L | arbitrage | imm. | BR, RK, rA, rI, rL, BV, Dossier | VALIDE |
| D041 | 4 | Retour de Pikachu : le reprendre ou le laisser à Seko | E | S | arbitrage | imm. | BR, BV | VALIDE |
| D042 | 4 | Badge 3 : 'le courant d'abord' de Voltère | E | S | arbitrage | court | rA, rC | FAIBLE |
| D043 | 4 | L'exercice de Major Bob (refusable) | D | S | combat | long | BR, rI, rP | VALIDE |
| D044 | 4 | L'echantillon d'Erika | E | S | arbitrage | court | rA, rC | VALIDE |
| D045 | 4 | R117 : les œufs abandonnes | D | S | don | imm. | RK, rA, rL | VALIDE |
| D046 | 5 | R112 : le capteur de Kelvin | E | S | arbitrage | court | PA, rG, rM | FAIBLE |
| D047 | 5 | Petit voleur n 5 : les lunettes de Kosmo | D | S | geste | court | HO, Dossier | VALIDE |
| D048 | 5 | Quête de Bayar (désert, facultative) | E | M | arbitrage | long | rA, rG, Dossier, ECO | VALIDE |
| D049 | 5 | Les journaux de Lanette (W9 Léo/Lanette) | E | M | arbitrage | court | BR, rC, BV, Dossier | VALIDE |
| D050 | 5 | Site Météore : Peter contre Amaryllis (W1) | E | M | presence | court | AM, PE, rG, rI | VALIDE |
| D051 | 5 | Les données de Brice contredisent son père | D | S | don | long | BR, rL, BV | VALIDE |
| D052 | 5 | Le fragment de meteorite de Kosmo | E | S | arbitrage | long | rC, rG | VALIDE |
| D053 | 5 | Aster, la Chuchmur de la gardienne disparue | D | S | don | long | AM, PE, rG | VALIDE |
| D054 | 6 | Demonstration de Magma (W5) : soutenir, saboter, denoncer | E | L | arbitrage | imm. | PA, rA, rC, rL, rM, rP, ECO | VALIDE |
| D055 | 6 | Petit voleur n 6 : blessé par l'anneau | D | M | don | court | HO, rM | VALIDE |
| D056 | 6 | Giovanni incognito (refusable) | E | M | combat | long | BL, GI, RK | VALIDE |
| D057 | 6 | Ariane recrute a Vermilava | D | S | don | imm. | RK, rP | VALIDE |
| D058 | 6 | Erika et Adriane : les sources a vendre | D | S | presence | imm. | rC, rP | VALIDE |
| D059 | 6 | Planque Magma : l'horaire vendu par Lambda | E | S | arbitrage | court | BR, rM, Dossier | VALIDE |
| D060 | 6 | Attendre Brice au telepherique | D | S | presence | long | BR, rM, BV | VALIDE |
| D061 | 6 | Montrer à Max les sources vides | E | S | aveu | court | PA, rC, rM | VALIDE |
| D062 | 6 | Auguste et le petit voleur blessé | D | S | aveu | court | HO, rM | VALIDE |
| D063 | 7 | Filature de Lambda ou course à Vergazon (exclusif) | E | M | presence | imm. | RK, TI, Dossier | VALIDE |
| D064 | 7 | Vergazon : Timmy contre la brigade (W3) | E | M | arbitrage | imm. | FL, TI, rL | VALIDE |
| D065 | 7 | L'aveu de Léo : le protéger ou le nommer | E | S | aveu | long | rC, rL | VALIDE |
| D066 | 7 | Petit voleur n 7 : le carnet rendu | D | S | geste | court | BR, HO | VALIDE |
| D067 | 7 | Dîner chez les Seko : Chen contre Seko | D | S | presence | long | BR, rI, rL | VALIDE |
| D068 | 7 | Brice et la publication (R2) : la reaction de Red | E | L | aveu | imm. | BR, rC, rI, rL | VALIDE |
| D069 | 7 | Vote d'abattage du Rempart (W4) | E | M | arbitrage | imm. | BR, RK, rL, BV | VALIDE |
| D070 | 7 | Badge 5 : le message de Norman pour Flora | D | S | don | long | FL, rL | VALIDE |
| D071 | 7 | Devon 3F : Pierre Rochard et son père (W2) | E | S | aveu | long | PR, rC | VALIDE |
| D072 | 8 | Institut Meteo occupe par Sarah | E | M | arbitrage | imm. | rA, rL, Dossier | VALIDE |
| D073 | 8 | R120 : l'Absol 'porte-malheur' | D | S | arbitrage | imm. | rG, rL | VALIDE |
| D074 | 8 | Mission de zone Z-04 : la canopée de Cimetronelle | E | M | arbitrage | imm. | rA, rI, rL, rP, ECO | VALIDE |
| D075 | 8 | Le piege de Koga : la garde de Hoopa (R2b) | E | L | arbitrage | imm. | HO, RK, rI, rL, garde | VALIDE |
| D076 | 8 | La vision de Morgane (R120) | D | S | presence | court | PR, rG, Dossier | VALIDE |
| D077 | 8 | Embuscade de la R120 : le partenaire de duo | E | S | presence | imm. | BR, PR, BV | VALIDE |
| D078 | 8 | Jeannine suit Red en cachette | D | S | aveu | long | rI | VALIDE |
| D079 | 8 | Badge 6 : un Pokémon pour la canopée | E | M | don | imm. | rG, rP, ECO | VALIDE |
| D080 | 8 | Montrer à Sarah ses propres données | D | S | aveu | court | rA, rL | VALIDE |
| D081 | 8 | Défi Indigo de Koga (refusable) | E | S | combat | court | HO, PE, RK, rI | VALIDE |
| D082 | 9 | La nuit du marché : Olga, raid Aqua ou libération (exclusif) | E | L | presence | imm. | RK, rA, rI, rL, Dossier, ECO | VALIDE |
| D083 | 9 | Le toit du Grand Magasin (W6 Blue/Giovanni) | D | S | presence | court | BL, GI | VALIDE |
| D084 | 9 | Blue 2 sur le toit (refusable) | E | S | combat | court | BL, rC, rG, rI | VALIDE |
| D085 | 9 | Concours de Nénucrique : avec quel Pokémon | D | S | arbitrage | court | rA, rG | FAIBLE |
| D086 | 9 | Mont Mémoria : protéger le rite ou poursuivre Lance (Rocket) | E | M | arbitrage | imm. | RK, rG, Dossier | VALIDE |
| D087 | 9 | W7 : montrer l'article à Chen devant Agatha | D | S | aveu | court | rG, rI | VALIDE |
| D088 | 9 | Le plan de Fuji | E | M | arbitrage | long | HO, rI | VALIDE |
| D089 | 9 | Auguste rejoint-il Fuji ? | D | S | presence | long | rG, rM | VALIDE |
| D090 | 9 | W8 : Ondine et Aldo sur le port | E | S | presence | court | rA, rP | VALIDE |
| D091 | 9 | Damien : fermer les yeux sur les petits trafics | D | S | arbitrage | court | RK, rL | VALIDE |
| D092 | 9 | Montrer l'inscription à Marc | E | S | aveu | court | rC, rG | VALIDE |
| D093 | 9 | Safari : le garde qui revend la réserve | D | S | aveu | imm. | RK, rA, rL | VALIDE |
| D094 | 10 | Assaut du relais : le partenaire de duo | E | M | presence | long | BR, PE, PR, rC | VALIDE |
| D095 | 10 | Le faux Giovanni (Lambda) | E | M | aveu | imm. | GI, RK, rI, rL | VALIDE |
| D096 | 10 | Levy et Tatia entendent la 'voix' | D | S | presence | court | HO, rP, Dossier | VALIDE |
| D097 | 10 | Le registre du coffre (Ciléo) | E | S | aveu | court | PR, rC | VALIDE |
| D098 | 10 | La lettre d'Amos | D | S | don | court | GI, RK, rI | VALIDE |
| D099 | 10 | Levy et Tatia veulent sonder Hoopa | E | S | arbitrage | long | HO, rG | VALIDE |
| D100 | 10 | Défi Indigo de Peter (refusable) | D | S | combat | court | BR, PE, rG | VALIDE |
| D101 | 10 | Maison de Pierre Rochard : faut-il garder le relais ? | E | S | aveu | court | PR, rC, rG | VALIDE |
| D102 | 11 | Le câble de Passerelle : négocier, combattre, laisser couper | E | L | arbitrage | imm. | PA, rA, rC, rL, ECO | VALIDE |
| D103 | 11 | Une porte de sortie pour Sarah | D | S | don | court | BR, rA | VALIDE |
| D104 | 11 | Ondine, camp adverse (refusable) | E | S | combat | imm. | BR, rA, rI | VALIDE |
| D105 | 11 | Le soigneur de Fondmer : Aqua ou la brigade | D | S | presence | imm. | FL, rA | VALIDE |
| D106 | 11 | Le Capitaine Marin demande un témoignage | E | S | arbitrage | court | rA, rC, rP | FAIBLE |
| D107 | 12 | La phrase publique de Red : au Sommet ou jamais | E | M | aveu | court | BR | VALIDE |
| D108 | 12 | Sommet, motion 1 (le reseau) : l'option défendue | E | M | arbitrage | imm. | HO, rC, rG, rL, Sommet | VALIDE |
| D109 | 12 | Sommet, motion 2 (les arrivants) : l'option défendue | E | M | arbitrage | long | rA, rC, rL, rP, Sommet | VALIDE |
| D110 | 12 | Sommet, motion 3 (qui paie) : l'option défendue | E | M | aveu | long | rC, rG, rI, rL, Sommet | VALIDE |
| D111 | 12 | Brice veut un duel avant de voter (refusable) | E | S | combat | imm. | BR, rG, rI, rP | VALIDE |
| D112 | 12 | R4 en séance : designer Chen | D | S | presence | long | rG, rI | VALIDE |
| D113 | 12 | Le Président de Sylphe : confession privee ou chute publique | E | M | aveu | imm. | rC, rI, rP | VALIDE |
| D114 | 12 | Le témoignage de Giovanni | D | S | presence | imm. | GI, RK, rI | VALIDE |
| D115 | 12 | L'interruption : vers qui courir | D | S | presence | court | rG, rP | VALIDE |
| D116 | 13 | L'affectation : ou va Red, qui tient le reste | E | L | presence | imm. | RK, rC, rG, rP, Fiole | VALIDE |
| D117 | 13 | Au relais : le geste de Red avec la Fiole | E | M | arbitrage | imm. | HO, rA, rC, rG, Fiole | VALIDE |
| D118 | 13 | Veillee : le don de Red | D | S | don | imm. | BR, HO, rP | VALIDE |
| D119 | 13 | Pilier : Amaryllis | E | S | aveu | imm. | AM, RK, rG | VALIDE |
| D120 | 13 | Civils : le port des pêcheurs ou le Centre des arrivants | E | S | arbitrage | imm. | rA, rP | VALIDE |
| D121 | 13 | Rayquaza : combattre ou tenir le rite | D | S | arbitrage | imm. | rG, rL | VALIDE |
| D122 | 13 | Flora : obéir à Norman ou rejoindre les civils | D | S | presence | imm. | BR, FL, rL | VALIDE |
| D123 | 14 | Route Victoire : l'échange de Blue | E | S | don | imm. | BL, rG | VALIDE |
| D124 | 14 | Timmy à la Route Victoire (refusable) | D | S | combat | court | BR, TI, rL, rP | VALIDE |
| D125 | 14 | Pantheon : qui sur la photo | E | S | presence | court | BL, BR, GI | VALIDE |
| D126 | P | Fuji et Mewtwo | E | M | arbitrage | court | rG | VALIDE |
| D127 | P | Le dernier duel de Giovanni (refusable) | E | S | combat | imm. | GI, RK, rI | VALIDE |
| D128 | P | Financer une restauration (une seule zone) | E | M | arbitrage | imm. | rA, rC, rP, ECO | VALIDE |
| D129 | P | Le départ de Blue (Bourg-en-Vol) | D | S | presence | imm. | BL | VALIDE |
| D130 | P | Tournoi des Confluences : la finale | E | S | arbitrage | imm. | BL, BR | FAIBLE |
| D131 | P | Fin cachée : ouvrir la chambre scellee de Bayar | D | M | arbitrage | imm. | rG | VALIDE |
## 4. Contributions aux fins (ce qui pèse, par fin)
Formules : `GAME_SYSTEMS` §10.4 (ordre F2 → F1 → F3 → F5 → F4). Une fin n'est **jamais** décidée par une décision unique : il faut un état + un lieu + une intention.
| Fin | Conditions | Décisions qui y contribuent (principales) | Décisions qui l'éloignent |
|---|---|---|---|
| **F2 Pacte** | relais tenu, intention PACTE, Hoopa présent, `HO` ≥ 70 (Red) / ≥ 80 (allié) | gestes de Hoopa D012, D019, D031, D039, D047, D055, D066, D099 ; D075 a/c ; D088 a ; D108 c (LIBÉRER : `HO` +5, Hoopa vient) ; D116 a + D117 a, ou D118 a + Brice ACC / Fuji ; voie ACC de Brice (D007 a, D037 b, D077 b) | D031 c, D075 b, D117 b–d, `PA`/`RK` élevés qui font tomber le relais |
| **F1 Sceau** | relais tenu, intention SCEAU, rite, civils tenus, Pilier tenu | `S(rG)` : D048 a, D050 a, D052 a, D053 b, D086 a, D092 a, D115 b ; Doyenne alliée ; Peter/Koga/Brice PROT au relais ; D108 a (PR suit FERMER) ; D121 b | D046 a, D050 b, D086 b, pas de Doyenne ni de rite mené par Red |
| **F3 Passerelle** | relais tenu, intention PASSERELLE, `S(rC)` ≥ 0, `S(rL)` ≥ −5, `PA` < 50 | D011 a, D029 a, D049 b, D065 a (Léo), D097 a, D101 a, D102 a, D108 b, D113 a ; publication (D068) et FERMER/CHARTE pour baisser `PA` ; peu de Kiosque | Kiosque, D054 a, D102 c, D113 b (chute), D071 a |
| **F5 Ciel ouvert** | intention BRISER, ou relais perdu avec `HO` < 40 ou câble coupé | D088 b (Fuji brise), D102 c, D117 d, `RK` ≥ 70 sans allié fort au relais | `FUJI_ATTEND`, `HO` ≥ 40 |
| **F4 Rempart** | aucun des cas précédents (Rayquaza détruit le relais) | toute intention qui échoue (SCEAU sans rite, PASSERELLE avec `PA` ≥ 50, PACTE sans confiance) ; Red aux civils sans allié adapté | — |
| Variante sociale | résultat M2 corrigé par les zones | missions de zone D010, D018, D037, D048, D054, D074, D079, D082 c, D102 ; D109 ; votes (BV, `rC/rP`, `S(rG)`) | — |
| Fin cachée | Chen AVOUE ∧ ≥ 12 pièces facultatives sur 19 | D086 a + D087 a + D112 a ; pièces : D001 b, D006 a, D009 a, D014 b, D020 b, D029 b, D031 b, D040 a, D047 b, D048 a, D049 a, D059 a, D063 a, D072 b, D076 a, D082 a/b, D096 a | choix exclusifs (D040, D082, D086) : on ne peut pas tout avoir (max 17/19) |
Témoins complets (15 fins × variantes) : `GAME_SYSTEMS` §11.

## 5. Audit de robustesse (grille REVIEW_V2_SYSTEMS, lecture stricte)
**Grille :** VALIDE = état lu plus tard avec effet observable non cosmétique, **ou** effet immédiat substantiel (objet, combat, accès, PNJ). FAIBLE = une ligne, compteur sans lecteur, seuil franchi de toute façon. Méthode : `--check` (règles mécaniques) + revue manuelle des 19 décisions « à deltas purs » (liste produite par script) : 14 gardées VALIDE parce qu'elles touchent un seuil **pivot** prouvé par le cumul (ex. D053 : `AM` ≥ 55 exige D050 a **et** D053 a ; D083 : `BLUE_LIBRE` ; D028 : duel de Giovanni à `GI` ≥ 50 ; D016 : vote de Roxanne ; D105 : clé de négociation de D102), 5 déclassées FAIBLE (D025, D042, D046, D085, D106). Décisions fragiles (VALIDE mais à surveiller en prototype) : D039, D099 (Hoopa, effet seulement par cumul), D125, D131 (accès postgame), D077 (deltas + BV).
**Défauts S1–S20 de la revue v2 :**
| # | Défaut v2 | État v3 |
|---|---|---|
| S1 | plancher non atteint | 124 robustes / 115 exigés, décompte affiché, non-comptées listées ✔ |
| S2 | refus non enregistré | macro D1 avec flag et script de refus (ENGINE_CHANGES D1) ; 12 décisions de combat ✔ |
| S3 | blocage du téléphérique | fin d'événement du Site Météore pose `FLAG_HIDE_ROUTE_112_TEAM_MAGMA` dans les 2 issues de D050 ✔ |
| S4 | jalons de plafond | var monotone + script de fin commun + plancher par chapitre (`GAME_SYSTEMS` §7) ✔ |
| S5 | états écrits jamais lus | colonne Lecteurs + §16 ; états de climax lus par `VAR_CF_FIN` (épilogue, ch. 14, postgame) ✔ |
| S6 | seuils triviaux | seuils dans les plages du cumul ; réputations relatives ✔ |
| S7 | logique du Conseil | 9 votants, ≥ 4 votants potentiels par option, conditions coûteuses, défendue ≠ résultat (stockage séparé) ✔ |
| S8 | fins incohérentes, BR RUPTURE inatteignable | ordre unique F2→F1→F3→F5→F4 ; `BR` atteint 6–8 (sim) ✔ |
| S9 | chemin doré | impossible (preuve `AM`/`PE`, `GAME_SYSTEMS` §5) ; reste « F2 + intégration + démantelée » payé (K-C5) ⚠ |
| S10 | budget vars | 44 vars / 45 ; E-BITS ✔ (dépend d'E-BITS : **bloquant**) |
| S11 | budget flags | 227 / 260 + 40 HIDE recyclés ; quotidiens exclus ✔ |
| S12 | séquence ch. 11/12 | `FLAG_CF_M_FONDMER` exigé par le Sommet et l'arène ✔ |
| S13 | traversée | table par chapitre + soigneurs + cas de softlock (`GAME_SYSTEMS` §15) ✔ |
| S14 | aides manquantes | E-REMOVE, E-NATIVE, E-REPREL listées ; E-LVL résolu sans code ✔ |
| S15 | `FLAG_DELIVERED_DEVON_GOODS` | posé dans les 2 options de D029 ✔ |
| S16 | discrètes < 30 %, équité | 42,7 % ; seuils annoncés à la veillée ; gestes à retour immédiat ✔ |
| S17 | deltas répétables | slot à usage unique ✔ |
| S18 | crans saturés | plus de crans ; zones à 4 états bornés ✔ |
| S19 | états de Pikachu | `VAR_CF_WORLD` b14-15 : 0, 1 blessé, 2 équipe, 3 chez Brice ; D041 ✔ |
| S20 | conséquences absentes du déroulé | chaque lecteur nomme une carte (§16) ✔ |

## 6. Interfaces publiées (S2)
- **→ brief A :** positions demandées → stockage (`FLAGS_VARS_REGISTRY` §3) ; témoins W1–W10 câblés : W1 = D050, W2 = D071, W3 = D064, W4 = D069, W5 = D054, W6 = D083, W7 = D087, W8 = D090, W9 = D049, W10 = automatique au ch. 10 (page « K. » si possédée ; sinon D095 b).
- **→ brief B :** combats refusables-décisions (§1) avec leur flag ; combats à deux issues : D008, D022, D027, D043, D056, D081, D084, D100, D104, D111, D124, D127 (slot 1 = gagné, 2 = perdu, 3 = refusé) ; jalons de plafond (`GAME_SYSTEMS` §7) ; sélecteurs : Brice (BV, `PIKA_EQUIPE`), Blue (`BLUE_LIBRE`, D027/D034/D084, D123), Timmy (`TIMMY_SAUVE`), Olga (`OLGA_LOKHLASS`), Peter (`PETER_RESPECT`), Ariane (`RK` ≥ 40), Amaryllis (`PA` ≥ 50), Koga (`STANCE` b6-7), Ondine (`REL_ONDINE_ARTHUR`/`ONDINE_MISSION`), Auguste (`REL_AUGUSTE_FUJI`), Erika (`STANCE_ERIKA_INT`), Pierre (Brock) (`BROCK_PROTEGES`, D064), Maître (`VAR_CF_FIN` b14).
- **→ brief D :** `VAR_CF_ECO` (2 bits × 6, ABATTU adopté), missions = D010, D018, D037 (+ D048), D054, D074 (+ D079, D082 c), D102 ; glissement M2 ; `PA` pour les épidémies P2 ; canal des légendaires par `VAR_CF_FIN` b0-2 ; D126 (Mewtwo). *Placeholder :* espèces exactes et tables restent dans `ENCOUNTERS_PLAN.md`.

## 7. Changelog
| Date | Changement | Auteur |
|---|---|---|
| 2026-10-14 | v3 : 131 décisions (124 robustes), règles durcies, audit S1–S20, contributions aux fins ; données et modèle exécutable | GMD secondaire (brief C) |
