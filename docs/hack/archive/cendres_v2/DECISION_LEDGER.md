# DECISION_LEDGER — *Pokémon Cendres*

> Registre des décisions du joueur. Partie de la bible. Toute décision ajoutée, retirée ou modifiée passe par le GMD et entre au changelog de la bible.
> **Fichiers détaillés :** [`DECISION_LEDGER_ACT1.md`](DECISION_LEDGER_ACT1.md) (prologue + acte I, D001–D046) · [`DECISION_LEDGER_ACT2.md`](DECISION_LEDGER_ACT2.md) (acte II, D047–D080) · [`DECISION_LEDGER_ACT3.md`](DECISION_LEDGER_ACT3.md) (acte III, finale, postgame, D081–D120).
> **Statut de toutes les entrées : `proposé`** (aucune n'est implémentée ni testée).

---

## 1. Règles

### 1.1 Ce qui compte comme décision
Une entrée compte si et seulement si :
1. le joueur a **au moins deux options réelles** (dont « ne rien faire » quand c'est un acte visible : partir, ne pas parler, ne pas donner) ;
2. le choix modifie un **état stocké** (flag/var) ;
3. l'effet est **observable en jeu** (dialogue, PNJ présent/absent, objet, combat, accès, issue, épilogue) — immédiatement ou plus tard, et **intelligible après coup** ;
4. un **test** reproductible existe (sauvegarde d'état + séquence + observation attendue).

Ne comptent pas : choix du mode de difficulté, choix de nom, réponses purement cosmétiques.

### 1.2 Types
- **E (explicite)** : `multichoice` / oui-non présenté comme un choix.
- **D (discret)** : acte sans menu de choix — donner un objet, parler deux fois, suivre quelqu'un, décliner un combat, choisir son Pokémon de tête, perdre volontairement, lire ou non un document, rester ou partir.
Cible : ≥ 30 % de discrètes (atteint : voir §2).

### 1.3 Champs (dans les fichiers par acte)
`ID` · `Type` (E/D) · `Déclencheur` (carte, moment) · `Options` · `Prérequis` · `Stockage` (flags/vars, **coût** en flags neufs) · `Immédiat` · `Différé / contenu affecté` · `Systèmes` (deltas) · `Fins` (variables de fin influencées) · `Test` · `Statut`.

Abréviations des deltas : **B** `AFF_BRICE`, **BL** `AFF_BLUE`, **AU** `AFF_AUGUSTE`, **MX** `AFF_MAXIE`, **AR** `AFF_ARCHIE` ; **rR** `REP_REFUGIES`, **rM** `REP_MAGMA`, **rA** `REP_AQUA`, **rO** `REP_AUTORITES` ; **V** `ETAT_VOLCAN`, **C** `ETAT_CAMP`, **Rf** `ETAT_RECIF`, **Rk** `ETAT_ROCKET` ; **N** `NOTORIETE`. Variables de fin : **VO**, **SO**, **RO**, **BR**, **Arche**, **épi.** (variante d'épilogue) — `GAME_SYSTEMS.md` §8.

### 1.4 Méthode de test (commune)
1. Sauvegarde d'état juste avant le déclencheur (fichiers `tests/states/D###.ss`, à créer par le QA).
2. Script mGBA (harnais `QA_TOOLING.md`) : jouer chaque option ; lire les flags/vars en mémoire (adresses exportées par la build) ; vérifier l'observation attendue (texte affiché, objet présent, combat lancé).
3. Pour les effets différés : sauvegarde au point de conséquence, avec les flags forcés, et vérification de la branche.

### 1.5 Cycle de statut
`proposé` → `implémenté` (script fusionné, référence de commit) → `testé` (preuve : log du harnais) → `validé` (revue GMD).

## 2. Synthèse
| Acte | IDs | Nombre | Explicites | Discrètes | Combats déclinables | Flags neufs (est.) |
|---|---|---|---|---|---|---|
| Prologue | D001–D008 | 8 | 6 | 2 | 0 | 8 |
| Acte I | D009–D046 | 38 | 24 | 14 | 4 | 48 |
| Acte II | D047–D080 | 34 | 23 | 11 | 4 | 42 |
| Acte III | D081–D111 | 31 | 24 | 7 | 2 | 36 |
| Finale + postgame | D112–D120 | 9 | 6 | 3 | 0 | 9 |
| **Total** | **D001–D120** | **120** | **83** | **37 (31 %)** | **10** | **≈ 143** (+ vars partagées : ≈ 30) |

Marge sur l'exigence (≥ 101) : **19 décisions**, pour absorber les coupes de production sans repasser sous le seuil.

## 3. Contributions aux fins

| Variable de fin | Décisions qui y contribuent (principales) |
|---|---|
| **VO** (volcan) | D020, D033, D048, D049, D050, D055, D058, D059, D060, D061, D065, D073, D077, D079, D092, D101, D104, D106, D107, D108, D110, D111 |
| **SO** (réfugiés) | D001, D009, D010, D014, D019, D025, D027, D028, D032, D034, D036, D042, D052, D057, D064, D066, D069, D076, D081, D084, D087, D100, D102, D105 |
| **RO** (Rocket) | D011, D016, D017, D039, D040, D041, D043, D058, D071, D078, D082, D090, D092, D093, D099, D106, D109, D116 |
| **Arche** | D015, D026, D028, D042, D093, D095, D103, D106, D109 |
| **BR** (Brice) | D003, D004, D008, D015, D025, D045, D049, D062, D070, D075, D081, D091, D095, D100, D106 |
| **Blue** (épi.) | D030, D031, D089, D112, D118 |
| **Notoriété** (épi.) | D005, D013, D032, D090, D113 |
| **Lilou / Téo** (épi.) | D001, D003, D034, D110 |
| **Pikachu** (épi.) | D002, D038, D111 |
| **Réseau / équipe classique** (postgame) | D007, D094, D115 |
| **Monde postgame** | D051, D085, D097, D117, D118, D119, D120 |

Toutes les fins F1–F5 sont atteignables ; chacune a été vérifiée sur les conditions de `GAME_SYSTEMS.md` §8 avec au moins un chemin :
- **F1** : Soupape réduite (D101), ≥ 2 preuves, Lambda démasqué, climax au chantier avec arrêt d'urgence ; intégration votée (D102) avec `REP_REFUGIES` ≥ 55.
- **F2** : idem pour le volcan ; relogement voté ou motion 2 échouée.
- **F3** : Soupape complète, sabotages non déjoués, climax au camp avec Brice au chantier ; intégration.
- **F4** : comme F3 avec relogement.
- **F5** : Soupape complète, aucun sabotage déjoué, `AFF_MAXIE` < 55, climax au camp sans Brice (V ≥ 70), Orbe non détenue, défaite contre Groudon ; ou rapatriement voté (D102 = 3).
