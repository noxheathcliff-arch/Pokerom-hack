# GAME_SYSTEMS — *Pokémon Confluence* (v3, brief C)

> Propriétaire : GMD secondaire « Décisions et systèmes ». Source de vérité : `GAME_DESIGN_BIBLE.md` v3.0 (« bible »). Registre des décisions : `DECISION_LEDGER.md` (+ `_ACT0-1`, `_ACT2`, `_ACT3`, `_POST`). Allocation : `FLAGS_VARS_REGISTRY.md`.
> **Statut : conception. Rien n'est implémenté ni testé sur ROM.** Toutes les valeurs numériques sont des `HYPOTHÈSE` calibrées sur un **prototype papier exécutable** : `docs/hack/data/cf_model.py` (données : `cf_decisions.py`). Commandes reproductibles :
> `python3 -I docs/hack/data/cf_model.py --check` (règles du registre) · `--sim 18000` (cumul, Sommet, fins, témoins) · `--golden` (recherche locale du chemin doré) · `--render` (régénère les fichiers par acte).
> Les chiffres cités ci-dessous viennent de `--sim 18000` (graine 3 ; 9 « personas » de joueur : Hoopa, Consortium, Gardiens, Rempart, Aqua, Mission, Relations, Anti-Rocket, Aléa). Ce sont des preuves **de cohérence du modèle**, pas des tests de jeu.

## 0. Sommaire
1. Clause de contrat · 2. Inventaire et stockage · 3. Spécification par système · 4. Cumul et justification des seuils · 5. Dominance · 6. Économie et Kiosque · 7. Plafonds par jalons · 8. Événements systémiques (dérives, Hoopa, BV, vote d'abattage) · 9. Sommet · 10. Climax · 11. Fins formelles et chemins témoins · 12. Postgame · 13. Quêtes et QoL · 14. Allocation (résumé) · 15. Traversée par branche et softlocks · 16. Lectures par carte · 17. Aides moteur · 18. Checklists · 19. Conflits avec la bible et les autres briefs · 20. Changelog

---

## 1. Clause de contrat (niveau systèmes cachés)
- **Structure dominante :** progression (goulots de chapitre) colorée par un **état accumulé** (qualités à la Short) ; émergence locale limitée et voulue (vote du Sommet, affectation du climax, écosystèmes).
- **Famille dominante :** sociale simulée lisible par réactions ; co-dominée par une économie de **ressources rares** (argent, objets, pièces du Dossier, confiance de Hoopa, présence de Red).
- **Économie interne :** sources = décisions et événements ; convertisseurs = Sommet (relations/réputations/pièces → votes → `PA`, `FK`, zones), climax (alliés + intentions → résultat de la Fiole) ; puits = choix exclusifs (présence), argent, `PA` et `RK` (ressources communes négatives).
- **Feedback :** négatif sur la puissance (plafond) ; positif lent sur la confiance (alliés disponibles) ; **somme nulle** sur l'influence des factions (lecture relative `S(X)`, §3.2) ; dérive positive de `RK` (recrutement des ruinés) et de `PA` (surcharge d'Amaryllis), contrée par des actes coûteux.
- **Espace de possibilités :** 5 fins × 3 variantes sociales, toutes atteintes par le modèle (15/15, §11) ; 4 variantes Rocket × 3 issues d'Amaryllis × 3 bilans civils × Maître ×2.
- **Stratégies dominantes cherchées :** chemin doré, payer toujours, plaire à tous, tout capturer, farmer, Kiosque sans limite (§5). Aucune ne donne tout ; le reste-à-payer de chacune est chiffré.
- **Signification :** effet = des chiffres invisibles ; fiction = des gens qui se souviennent ; appris = « on ne peut pas être partout ni plaire à tous » ; thème = **tout échange a un prix** (l'influence gagnée ici est perdue là, par construction).
- **Après la première solution :** la 2e partie montre d'autres témoins (présence exclusive : 3 paires), d'autres votes (option défendue ≠ résultat), une fin cachée (Dossier ≥ 12 pièces + Chen avoue : 2,3 % des parties simulées).

## 2. Inventaire et stockage (définitif ; IDs : `FLAGS_VARS_REGISTRY.md`)
| Système | Stockage | Bornes / départ | Écrivains | Lecteurs (≥ 2, avant la dernière écriture) | Perception |
|---|---|---|---|---|---|
| Relations ×9 `BR BL FL PR PE AM TI GI HO` | 9 vars `VAR_CF_BR`…`VAR_CF_HO` | 0–100 ; 50 (HO 20) ; `addaffinity` borné | décisions (guard = slot de décision ≠ 0) | §3.1 | répliques de saillance, présence, Carnet |
| Réputations ×7 `rL rC rM rA rI rG rP` | 7 vars `VAR_CF_REP_*` | 0–100 ; 50 | décisions, Kiosque | **lecture relative** `S(X) = rX − moyenne(7)` (special `CF_RepStanding`) §3.2 | PNJ, affiches, votes |
| Pression des anneaux `PA` | `VAR_CF_PA` | 0–100 ; 20 | Kiosque, décisions, surcharges auto ch. 5/8/10, Sommet M1 | §3.3 | bulletins de l'Institut, épidémies P2, ciel |
| Emprise Rocket `RK` | `VAR_CF_RK` | 0–100 ; 20 | décisions, dérive ch. impairs | §3.4 | sbires sur les routes, assaut ch. 10 |
| Écosystèmes Z-01…Z-06 | `VAR_CF_ECO` 6×2 bits (0 ENVAHI, 1 MIXTE, 2 RESTAURÉ, 3 ABATTU — état ABATTU = proposition brief D) | départ ENVAHI | missions de zone, D048, D079, D082 c, glissement M2 au ch. 13, D128 | E-ECO, PNJ, prix, M2, variante sociale, diaporama | ce qu'on rencontre |
| Monde `VAR_CF_WORLD` | N (0–3) b0-1 · FK (0 fermée, 1 Mission, 2 ouverte) b2-3 · BV (0, 1 PROT, 2 ACC, 3 COMP) b4-5 · garde de Hoopa (0, 1 RED, 2 MISSION, 3 LIBRE) b6-7 · Kiosque commandes du chapitre b8-9 · chapitre de la dernière commande b10-13 · Pikachu (0, 1 blessé, 2 équipe, 3 Brice) b14-15 | — | D002, D009, D011, D027, D075, D107, Kiosque, M3 | Défis, Sommet, climax, épilogue | regards, ports |
| Compteurs de Brice `VAR_CF_BVCOUNT` | PROT b0-3, ACC b4-7, COMP b8-11 | 0–15 | 13 décisions avec Brice présent | D068 (publication), BV final ch. 12 | répliques |
| Positions `VAR_CF_STANCE` | PR axe B b0-1 (CTL/SCE/LIB) · Chen b2-3 (—/AVOUE/NIE) · Sylphe b4-5 (—/CONF/CHUTE) · Koga–Peter b6-7 (IGNORÉ/COUVERT/DÉMASQUÉ) · Arthur b8-9 (—/NÉGOCIE/COUPE) · photo du Panthéon b10-11 | — | D040, D095, D101, D102, D112, D113, D125 | Sommet, climax, épilogue | — |
| Positions 1 bit (brief A §1.2) | flags (`FLAG_CF_BLUE_LIBRE`, `PETER_ASSUME`, `PR_ACCUSE`, `STANCE_ERIKA_INT`, `STANCE_MAX_ECOUTE`, `REL_CHEN_SEKO`, `REL_ONDINE_ARTHUR`, `SARAH_DOUTE`, `REL_AMA_ARAGON`, `REL_AUGUSTE_FUJI`) | — | voir §3.6 | — | — |
| Dossier | 19 flags facultatifs + 5 obligatoires `FLAG_CF_DOS_*` | — | enquête | Sommet (montrer), R4, fin cachée (≥ 12 facultatives) | Carnet |
| Sommet `VAR_CF_SUMMIT` | défendue M1/M2/M3 b0-5 · résultat b6-11 · sources R4 b12-13 · phrase b14 | — | ch. 12 | ch. 13, fins | place d'Atalanopolis |
| Climax `VAR_CF_CLIMAX` | lieu de Red b0-1 · allié relais b2-5 · allié Pilier b6-9 · allié civils b10-13 | — | veillée | résultat | — |
| Fin `VAR_CF_FIN` | Fiole b0-2 (1 F1…5 F5) · variante sociale b3-4 · intention au relais b5-7 · civils b8-9 · Amaryllis b10-11 · Rocket b12-13 · Maître b14 · cachée b15 | — | fin du ch. 13 | ch. 14, épilogue, postgame | — |
| Décisions `VAR_CF_D00`…`D16` | 2 bits par décision (D001 = D00 b0-1 … D131 = D16 b4-5) ; 0 = non prise | — | chaque décision (une fois) | **garde à usage unique** de tous les deltas ; tests | — |
| Plafond `VAR_CF_CAP` | `B_LEVEL_CAP_VARIABLE` | 14 → 100, monotone | `CF_RaiseCap` | moteur (EXP souple) | EXP réduite |

## 3. Spécification par système

### 3.1 Relations (vars 0–100)
| Var | Départ | Seuils lus (lecteur) | Plage atteinte au moment de la lecture (sim) |
|---|---|---|---|
| `BR` Brice | 50 | ≥ 50 : traduction fidèle au Sommet (sinon la bascule de Red échoue si `N` < 2) ; ≥ 55 : D069 c, Brice retourne Roxanne ; ≥ 50 : D122 a (Flora) ; ≥ 30 : compétent au relais ; ≥ 60 : départage d'égalité au Sommet ; saillance ≥ 70 / ≤ 30 | ch. 12 : 10–100 |
| `BL` Blue | 50 | ≥ 55 : vient à la veillée (allié R/P) ; ≥ 60 + D083 a : `BLUE_LIBRE` (équipe ch. 14, épilogue) | ch. 13 : 40–65 |
| `FL` Flora | 50 | ≥ 55 (+ `BR` ≥ 50, D122 a) ou ≥ 60 / `FLORA_DOUTE` (D122 b) : `FLORA_DESOBEIT` ; ≥ 60 + doute : Norman s'abstient en M2 ; ≥ 55 (+ `TI` ≥ 55) : Timmy sauvé sans Red | ch. 13 : 40–65 |
| `PR` Pierre Rochard | 50 | ≥ 50 : allié (R/P/C) et duo ch. 10 ; ≥ 55 + `PR_PREUVE` : `PR_ACCUSE` ; ≥ 60 + `DOS_VOIX_RELAIS` : axe B LIB | ch. 12 : 38–74 |
| `PE` Peter | 50 | ≥ 50 : allié (R/P) ; ≥ 55 + Hoopa à la Mission : vote LIBÉRER ; ≥ 60 : `PETER_ASSUME` (alternative au respect du Site) | ch. 12 : 38–66 |
| `AM` Amaryllis | 50 | ≥ 55 + Red au Pilier + preuve : RENONCE ; < 50 + Red absent + pas de rite + `PA` ≥ 45 : SACRIFICE | ch. 13 : 38–63 ; **max 58 avant le climax** |
| `TI` Timmy | 50 | ≥ 55 (+ `FL` ≥ 55) : arrivant sauvé sans Red (D063 a) ; équipe et épilogue | ch. 7 : 33–62 |
| `GI` Giovanni | 50 | ≥ 50 : duel incognito (D056) ; ≥ 55 + `LAMBDA_DEMASQUE` : témoignage (D114, source R4) | ch. 12 : 35–69 |
| `HO` Hoopa | **20** | bandes de saillance ≤ 20 / 40 / 60 (brief A) ; ≥ 40 : rend le carnet (D066), Lévy-Tatia (D099), Fuji vise le PACTE ; ≥ 60 : vote DOY LIBÉRER, vient si M1 = LIBÉRER ; ≥ 70 : vient seul (garde LIBRE), **PACTE donné par Red** ; ≥ 80 : PACTE donné par un allié ; < 40 + relais perdu : F5 | ch. 12 : 0–87 ; borne analytique 87 |

### 3.2 Réputations (lecture relative)
**Règle (cause des défauts S6/S9 v2 corrigée à la source) :** l'influence des factions est **relative**. Tout lecteur compare `S(X) = rX − moyenne(rL, rC, rM, rA, rI, rG, rP)` (special `CF_RepStanding X` → `VAR_RESULT = S + 100`). Somme des `S` = 0 : « plaire à tous » est impossible par construction ; une option à +3/−2 ne fait plus monter tout le monde.
| Lecteur | Condition |
|---|---|
| Doyenne alliée (Pilier) | `S(rG)` ≥ +3 |
| Rite mené par Red | `S(rG)` ≥ −5 (−10 avec `RITE_PREPARE`, −15 avec `FRAGMENT_DOYENNE` en plus) |
| DOY vote REMPART (M2) / PARTAGÉE (M3) | `S(rG)` ≥ +10 / ≥ 0 |
| MAX vote MARCHÉ (M2) ; pièce « MARCHÉ » de Red | `S(rC)` ≥ +5 |
| Léo allié (relais) | `LEO_INSIDER` et `S(rC)` ≥ −5 |
| F3 PASSERELLE | `S(rC)` ≥ 0 et `S(rL)` ≥ −5 |
| Rocket DÉMANTELÉE | une autorité : `S(rL)` ≥ 0 ou `S(rI)` ≥ 0 |
| Major Bob allié (civils) | ou `S(rI)` ≥ +5 |
| COM vote KANTO (M3) ; FK après PARTAGÉE | `S(rI)` < −5 ; FK = 2 si `S(rI)` ≥ 0 sinon 1 |
| Aqua alliée (civils) / Magma allié (civils) | `ARTHUR=NÉGOCIE` et `S(rA)` ≥ 0 / `STANCE_MAX_ECOUTE` et `S(rM)` ≥ 0 |
| Dérive `RK` | +3 si `S(rP)` < −5 ; −2 si `S(rP)` ≥ +10 |
| Comparaisons directes | NOR M1 : `rL ≥ rC` ; COM M1 : `rP ≥ rC+5` ; COM M2 : `rC > rP` ; ART M1 : `rA ≥ rM` ; MAX M1 : `rM ≥ rA` |

### 3.3 Pression des anneaux `PA`
- **Sources :** Kiosque +2 par commande (≤ 2 par chapitre, ch. 3–12) ; D026 a +2 ; D054 a +5 / b +2 ; D061 b +2 ; D102 b +3 / c +8 ; D042 a +1 ; **surcharges d'Amaryllis automatiques +5 aux fins des ch. 5, 8 et 10**.
- **Puits :** publication de Brice −5 (D068) ; D061 a −2 ; D102 a −3 ; Sommet M1 : FERMER −15, CHARTE −8, LIBÉRER −3.
- **Seuils :** dès le ch. 8, `PA` ≥ 45 : une épidémie P2 par chapitre (E-OUT, brief D), ≥ 60 : deux ; au climax : ≥ 50 → anomalie P2 dans l'équipe d'Amaryllis ; < 50 requis pour F3 ; ≥ 40 → civils mal tenus = PERTES ; ≥ 45 → SACRIFICE possible. **Y1 :** Rayquaza descend dans toutes les parties (tempête + Fiole loin du Pilier) ; `PA` décide s'il **repart** (F3) ou détruit (F4).
- Plage au climax (sim) : 14–74. Perception : bulletin de l'Institut affiché au Centre Pokémon (« indice de déchirure » en mots : calme / tendu / déchiré), jamais un chiffre.

### 3.4 Emprise Rocket `RK`
- **Dérive :** +4 aux ch. 1, 3, 5, 7, 9, 11 (recrutement des ruinés), modulée par `S(rP)` (§3.2) ; +3 au ch. 8 si `VOTE_ABATTAGE` (primes).
- **Puits :** D014 a, D015 a, D040 (−3 à −8), D056 c, D057 a, D063 a, D082 a (−8), D086 b, D091 a, D093 a, D095, D098 a, D114 a, D127 a ; **sources** : D002 a, D009 a, D013 a, D045 b, D057 b, D075 a (+5), D082 b (+5)…
- **Seuils :** ≥ 40 : Ariane a sa seconde équipe au ch. 10 (brief B) ; ≥ 50 : +2 sbires de route par chapitre ; relais tenu par un allié faible seulement si `RK` < 70 (< 80 avec `COPIE_REPRISE`) ; ≥ 60 : FORTE (Giovanni intervient contre ses commandants si ≥ 70) ; DÉMANTELÉE : `RK` ≤ 35 avec Red au relais, ou ≤ 20, **et** une autorité (§3.2). Canon : arrestation puis évasion dans toutes les variantes.
- Plage au climax : 0–93.

### 3.5 Écosystèmes (interface brief D, `ENCOUNTERS_PLAN` §4)
- Missions (une issue = un état) : Z-02 D010, Z-01 D018, Z-03 D037 (+ D048 b un cran), Z-04 D074 (+ D079 a un cran ; D082 c → ENVAHI), Z-06 D054, Z-05 D102. **Mission non faite au jalon de fin de chapitre → MIXTE** (aucun état orphelin).
- Glissement au ch. 13 (M2) : REMPART : MIXTE → ABATTU ; INTÉGRATION : ENVAHI/ABATTU → MIXTE ; MARCHÉ : rien. Postgame : D128 (+1 cran, une zone).
- **Jamais de compteur de captures.** Lecteurs : E-ECO, boutiques (rupture d'objets en ENVAHI, brief D §6.2 : on remplace la hausse de prix par une **absence** pour éviter une aide moteur), M2 (BRI, COM, pièce INTÉGRATION si ≥ 2 RESTAURÉ), variante sociale, diaporama.
- *Placeholder brief D :* les tables par état et les espèces exactes restent la propriété d'`ENCOUNTERS_PLAN.md` ; le registre ne fixe que l'état.

### 3.6 Autres états
- **N** (0–3) : D002 (0 ou 2), D009 a / D011 a / D027 a (+1), D027 b (−1), D107 a (= 3). Lecteurs : Défis Indigo dès le ch. 3 si `N` ≥ 1 (sinon après le ch. 10) ; piège nominatif de Lambda (`N` ≥ 2) ; traduction au Sommet ; départage ; presse de l'épilogue.
- **FK** : 1 au débarquement (ch. 3) ; Sommet M3 : KANTO → 0, HOENN → 2, PARTAGÉE → 2 ou 1. Lecteurs : présence de la Mission au postgame, boutiques d'import, canal de retour F4 (bateau d'Olga : FK ≥ 1 **ou** `OLGA_LOKHLASS`), épilogue.
- **BV** : calculé au ch. 12 = compteur dominant de `VAR_CF_BVCOUNT` (égalité : COMP > ACC > PROT). Au ch. 7, D068 lit le dominant **courant**. Lecteurs : publication (ch. 7), vote de Brice (M1/M2/M3), intention de Brice au relais, équipe (brief B), voix de l'épilogue. `BR` ne le modifie jamais (brief A, N10).
- **Garde de Hoopa** (D075) : RED (suiveur `setfollowernpc`, masqué sur l'eau et en Plongée), MISSION (cage au camp de Nénucrique), LIBRE.
- **Positions dérivées** au début du ch. 12 : `PETER_ASSUME` = (≥ 2 pièces Kanto parmi article, registre, journal du nœud, affiche) ∧ (`PETER_RESPECT` ∨ `PE` ≥ 60) ; `PR_ACCUSE` = `PR` ≥ 55 ∧ `PR_PREUVE` ; `BLUE_LIBRE` = `BL` ≥ 60 ∧ D083 a ; Koga DÉMASQUÉ au ch. 10 si D095 b, `KOGA_AVEU`, `JEANNINE_ALLIEE` ou `DOS_CARNET_PRIMES` (W10) ; `REL_CHEN_SEKO` (fin) = Chen AVOUE ∧ (`CREDIT_PARTAGE` ∨ (`DINER_APAISE` ∧ ¬`CHEN_LETTRE_MONTREE`)).

## 4. Tableau de cumul (plages atteintes en fin de chapitre, 18 000 parties à personas)
| Fin ch. | BR | BL | FL | PR | PE | AM | TI | GI | HO | PA | RK |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 1 | 37–63 | 50–50 | 47–53 | 50–50 | 50–50 | 50–50 | 47–50 | 50–50 | 16–25 | 20–20 | 19–40 |
| 3 | 32–68 | 46–56 | 47–53 | 45–57 | 47–55 | 50–50 | 47–50 | 45–53 | 8–35 | 20–26 | 22–49 |
| 4 | 25–77 | 46–56 | 47–53 | 45–57 | 47–55 | 50–50 | 41–55 | 45–53 | 6–40 | 20–30 | 14–46 |
| 5 | 21–82 | 46–56 | 47–53 | 45–57 | 43–60 | 43–58 | 41–55 | 45–53 | 3–45 | 25–40 | 16–53 |
| 7 | 14–96 | 45–56 | 41–61 | 43–60 | 43–60 | 43–58 | 33–62 | 45–58 | 5–59 | 20–54 | 6–66 |
| 8 | 12–100 | 45–56 | 41–61 | 39–66 | 42–60 | 43–58 | 33–62 | 45–58 | 0–70 | 25–59 | 5–72 |
| 9 | 12–100 | 40–65 | 41–61 | 39–66 | 42–60 | 43–58 | 33–62 | 43–61 | 0–73 | 25–62 | 2–89 |
| 10 | 11–100 | 40–65 | 41–61 | 38–74 | 38–66 | 43–58 | 33–62 | 35–69 | 0–79 | 30–70 | 0–86 |
| 12 | 10–100 | 40–65 | 40–63 | 38–74 | 38–66 | 43–58 | 33–62 | 35–69 | 0–87 | 14–74 | 0–93 |
| 13 | 8–100 | 40–65 | 40–65 | 38–74 | 38–66 | 38–63 | 33–62 | 35–69 | 0–92 | 14–74 | 0–93 |

**Justification des seuils.** Chaque seuil est placé **à l'intérieur** de la plage atteignable au moment de sa lecture et au-dessus de la valeur de départ : aucun n'est « franchi de toute façon » (défaut S6) ni inatteignable. Exemples : `BL` ≥ 55/60 sur une plage 40–65 (il faut D083 a, D084, D123…) ; `AM` ≥ 55 sur 43–58 (exige D050 a **et** D053 a) ; `HO` ≥ 70/80 sur 0–87 (exige 6 à 8 gestes positifs sur 10, payés en objets, `BR`, `rP`, `rI`) ; `GI` ≥ 55 sur 35–69 ; `PA` < 50 sur 14–74 (Sommet FERMER ou CHARTE + publication + peu de Kiosque). Réputations : relatives (§3.2) ; plages absolues 0–100 sans signification isolée.

## 5. Dominance (GM_METHOD §6.1)
| Raccourci | Résultat dans le modèle | Contre-pression (structurelle) |
|---|---|---|
| **Chemin doré** (Pacte + intégration + Rocket démantelée + toutes les relations ≥ 60) | **impossible.** Preuve : `AM` ≥ 60 exige D119 a (Red au Pilier ; max 58 avant) **et** D050 a + D053 a, qui plafonnent `PE` à 57. Meilleur résultat de `--golden` (24 000 essais) : F2 + INTÉGRATION + DÉMANTELÉE, **mais** civils BLESSÉS, Amaryllis PERSISTE, pas de fin cachée, 7–8 relations ≥ 60 sur 9, `rC` ≈ 13 (Devon et Sylphe ruinées deux fois), `S(rA)`, `S(rI)` négatifs | présence de Red exclusive : RENONCE d'Amaryllis exige Red au Pilier, AUCUN blessé exige Red aux civils, PACTE donné par Red exige Red au relais (sinon `HO` ≥ 80 + Hoopa confié) ; DÉMANTELÉE exige une autorité (`S(rL)` ou `S(rI)` ≥ 0) que le chemin pro-Hoopa a dépensée |
| **Plaire à tous** | impossible par construction (Σ `S` = 0) ; relations : max 8/9 ≥ 60 (`--golden` variante) | positions contradictoires (bible §7) ; votes relatifs |
| **Payer toujours** (toutes les options payantes + 2 Kiosques/chapitre) | argent négatif **au ch. 3 dans 300/300 parties** ; `PA` moyen 65 au climax (F3 fermé, P2 doublées) ; `S(rP)` +4 contre +23 pour la politique économe | prix du Kiosque = 1 000 + 500 × chapitre ; plafond 2/chapitre ; Kiosque −1 `rP` ; tout paiement est un **don à un camp** (gain d'un côté) |
| **Tout capturer** | aucun lecteur de compte de captures (vérifiable : grep `VAR_CF_` ne contient aucun compteur de Pokédex) | états de zone = missions et M2 |
| **Farmer** | EXP divisée au-delà du plafond (÷4 à ÷64), revanches Cherche VS désactivées, sauvages 2–4 niveaux sous le plafond (brief D), aucune récompense d'argent répétable (Tournoi : primes plafonnées par chapitre) | plafond par jalons §7 |
| **Kiosque sans limite** | 2 commandes/chapitre au plus (`VAR_CF_WORLD` b8-13) ; chaque commande : `PA` +2 et un anneau prend un objet non-clé ou le Pokémon d'un PNJ voisin | H1 vécue (bible §11.4) |
| **Option défendue = toujours gagnante** | défendue ≠ résultat dans 48 % (M1), 47 % (M2), 27 % (M3) des parties | 1 seule bascule par motion, verrous de votants, traduction (`BR`/`N`) |
| **Refuser tous les combats** | chaque refus a un coût lu (`FL`, `BL`, `PE`, `GI`, `rI`…) ; aucun jalon ne dépend d'une victoire | invariant 4 |

**Distribution des fins (personas, non représentative d'un joueur réel) :** F1 15 %, F2 11 %, F3 11 %, F4 46 %, F5 16 %. F4 est le repli de la bible (§12.2 « REMPART sinon ») ; aucune fin n'est classée.

## 6. Économie, Kiosque, puits
**Carte des flux (HYPOTHÈSE de calibrage ; revenus = estimation des dresseurs de route, à mesurer sur ROM).**
| Ch. | Revenu dresseurs (≈) | Puits obligatoires (soins, Balles, ≈ 40 %) | Puits de décision (max) | Kiosque (prix / commande, ≤ 2) |
|---|---|---|---|---|
| 1 | 2 500 | 1 000 | D015 500 | — |
| 2 | 3 000 | 1 200 | D019 200, D023 300 | — |
| 3 | 4 500 | 1 800 | D026 3 000, D033 500, D034 (gain), D035 (gain) | 2 500 |
| 4 | 5 500 | 2 200 | — | 3 000 |
| 5 | 5 000 | 2 000 | D052 b (+500) | 3 500 |
| 6 | 6 500 | 2 600 | D057 1 000 | 4 000 |
| 7–8 | 4 000 / 7 500 | 1 600 / 3 000 | — | 4 500 / 5 000 |
| 9 | 8 500 | 3 400 | D093 b 1 000 | 5 500 |
| 10–12 | 8 000 / 5 000 / 7 000 | ≈ 40 % | — | 6 000 / 6 500 / 7 000 |
| Post | 15 000 | — | D128 10 000 | fermé (F1, F4, F5) ou ouvert (F3) |
- **Règles :** (1) aucun paiement n'est neutre : chaque option payante donne à un camp et retire à un autre (vérifié par `--check`) ; (2) les pertes de combat facultatif coûtent de l'argent (300 → 2 000) ; (3) le Kiosque est le seul convertisseur argent → objet rare et il alimente `PA` ; (4) le Tournoi (D034 a) est la seule source répétable, **plafonnée** à 3 victoires primées par chapitre.
- **Kiosque :** ouvert au ch. 3 (`FLAG_CF_KIOSK_OUVERT`). Une commande : objet de la liste du chapitre (Restes, Pierres d'évolution, Méga-gemmes après ch. 8) ; `PA` +2, `rC` +1, `rP` −1 ; l'anneau retour prend, par ordre, un objet non-clé du sac (liste fixe : Baies, Potions, Balles — jamais un objet clé), sinon le Pokémon d'un PNJ voisin (scène). Compteur `VAR_CF_WORLD` b8-9, remis à 0 quand b10-13 ≠ `VAR_CF_CHAPTER`. Pas d'aléatoire (anti save-scumming).
- **Boutiques selon l'état** : rupture (et non prix) — Mérouville sans Corde Sortie si Z-02 ENVAHI ; Myokara sans Baies Oran si Z-01 ENVAHI ; R117 : arbres à baies vides si Z-03 ENVAHI ; Nénucrique : imports si FK = 2 (postgame). Aucune aide moteur.

## 7. Plafonds par jalons (E-CAP)
`include/config/caps.h` : `B_LEVEL_CAP_TYPE LEVEL_CAP_VARIABLE`, `B_LEVEL_CAP_VARIABLE VAR_CF_CAP` (la table de flags de `src/caps.c` devient inutilisée). Script commun (monotone) :
```
CF_RaiseCap:: @ VAR_0x8004 = nouveau plafond
	goto_if_le VAR_0x8004, VAR_CF_CAP, CF_RaiseCap_End   @ comparaison var/var (macro goto_if_le accepte une var)
	copyvar VAR_CF_CAP, VAR_0x8004
CF_RaiseCap_End::
	return
```
**Filet de sécurité :** `CF_SetChapter n` (appelé à l'ouverture de chaque chapitre) pose aussi le plafond plancher du chapitre (colonne « plancher »). Un jalon oublié ne peut donc jamais figer le plafond plus d'un chapitre (défaut S4).
| Jalon (bible §8.3) | Plafond | Script (carte) | Posé dans toutes les branches parce que… | Plancher ch. |
|---|---|---|---|---|
| Nouvelle partie | 14 | `CF_Init` (new_game) | unique | ch. 0 : 14 |
| Badge 1 | 18 | `RustboroCity_Gym` après Roxanne | combat obligatoire | ch. 1 : 14 |
| Badge 2 | 20 | `DewfordTown_Gym` | idem | ch. 2 : 18 |
| Blue 1 réglé **ou** sortie de Poivressel | 22 | `CF_D027` (fin commune des 3 issues) + `Route110` trigger sud | refus, victoire, défaite ou départ convergent | ch. 3 : 20 |
| Badge 3 | 25 | `MauvilleCity_Gym` | — | ch. 4 : 22 |
| Raid du Tunnel | 27 | `CF_D040_End` (sortie est, 3 approches) | les 3 approches finissent sur le même script | — |
| Site Météore | 29 | `CF_D050_End` + `setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA` | fin d'événement commune (défaut S3 v2) | ch. 5 : 27 |
| Badge 4 | 32 | `LavaridgeTown_Gym_1F` | — | ch. 6 : 29 |
| R2 | 33 | `CF_D068_End` (chambre de Brice) | réaction de Red a/b/c puis fin commune | ch. 7 : 32 |
| Badge 5 | 35 | `PetalburgCity_Gym` | — | — |
| Institut | 37 | `CF_D072_End` | forcer ou négocier | ch. 8 : 35 |
| Badge 6 | 40 | `FortreeCity_Gym` | — | — |
| Nuit du marché (planque résolue) | 42 | `CF_D082_Aube` (pose `FLAG_CF_M_PLANQUE`) | l'aube arrive dans les 3 présences | ch. 9 : 40 |
| Mont Mémoria | 44 | `CF_D086_End` | rite protégé ou poursuite | — |
| Badge 7 | 47 | `MossdeepCity_Gym` | — | ch. 10 : 44 |
| Centre Spatial | 49 | `CF_D094_End` (après assaut, même si Lambda fuit) | toutes issues de D094/D095 | — |
| Caverne Fondmer | 51 | `CF_D102_End` (pose `FLAG_CF_M_FONDMER`, prérequis du Sommet) | négocier, combattre, laisser couper | ch. 11 : 49 |
| Badge 8 | 53 | `SootopolisCity_Gym_1F` (porte ouverte seulement après `FLAG_CF_M_FONDMER`) | — | ch. 12 : 51 |
| Climax | 56 | `CF_Climax_End` | toutes fins | ch. 13 : 53 |
| Conseil 4 battu (salle du Maître) | 60 | `EverGrandeCity_ChampionsRoom` (entrée) | combats obligatoires | ch. 14 : 56 |
| Maître battu (Panthéon) | 75 | `EverGrandeCity_HallOfFame` | — | — |
| Retour de l'équipe de Red (P4) | 100 | script du canal de la fin | 5 canaux, un par fin | — |
Défaite dans un combat d'histoire à deux issues : `FLAG_CF_NO_WHITEOUT` posé avant, effacé et soin scripté après (`B_FLAG_NO_WHITEOUT` ne soigne pas, revue S14) ; le jalon est posé par le script de fin commun. Combats obligatoires (arènes) : défaite = retour au Centre vanilla, aucun jalon perdu.

## 8. Événements systémiques
### 8.1 Dérives automatiques
| Quand | Effet |
|---|---|
| fin ch. 1, 3, 5, 7, 9, 11 | `RK` +4 (+3 si `S(rP)` < −5 ; −2 si `S(rP)` ≥ +10) |
| fin ch. 5, 8, 10 | `PA` +5 (surcharge d'Amaryllis ; bulletins, ciel) |
| fin ch. 8 | `RK` +3 si `VOTE_ABATTAGE` |
| ch. 3 | FK = 1 ; si D023 a : `RK` +1 |
| ch. 4 / 7 / 9 / 10 / 12 | pièces obligatoires : prédicteur, battement, inscription, registre, gardienne |
| ch. 7 | si D063 a : Vergazon résolu sans Red (sauvé si `TI` ≥ 55 et `FL` ≥ 55, sinon `TI` −5) ; si D054 c : Max ÉCOUTE |
### 8.2 Hoopa (10 gestes, `HO` 20 → 0–92)
D012, D019, D031, D039, D047, D055, D066, D075 (garde), D088, D099, puis Sommet (M1 LIBÉRER +5) et D117. Retour **immédiat** à chaque geste (il rend un objet / une baie ; ou il ne revient plus que de loin si `HO` ≤ 20) : défaut « gestes invisibles » (bible §11.4) traité. Le mot « Hoopa » n'apparaît qu'au ch. 8.
### 8.3 Voie de Brice
13 scènes incrémentent un compteur (`bv`) : D003, D007, D012 b, D018 c, D024 a, D037 b, D040 a, D041 b, D049 a, D051, D060 a (selon D054), D068 c (dominant), D069 c, D077 b. D068 : Brice **publie** si ACC ou COMP domine (`PA` −5, `rC` −3, `BRICE_PUBLIE`), sinon remet à son père (`rL` +5). La réaction de Red (D068) ne change pas sa décision.
### 8.4 Vote d'abattage (ch. 7, D069)
Votants : Norman (toujours POUR), Major Bob (POUR sauf `BOB_QUARTIER`), Roxanne (POUR si D016 a, sinon abstention). Red : **montrer** → Roxanne CONTRE ; passe ssi Bob POUR. **Rester** → passe ssi Bob POUR ou Roxanne POUR. **Partir** → Brice parle : si `BR` ≥ 55, Roxanne CONTRE ; passe ssi Bob POUR ou Roxanne POUR. Résultat : `FLAG_CF_VOTE_ABATTAGE` (option D074 b, primes `RK` +3).

## 9. Sommet des Confluences (ch. 12)
### 9.1 Accès
Exige `FLAG_CF_M_FONDMER` (sinon le garde : “Le Sommet attend la contre-expertise de Fondmer.”) : défaut S12 v2 réglé. Soin forcé avant la séance.
### 9.2 Votants (9) et présidence
NOR Norman (Rempart), PRO Pierre Rochard (Ligue), PET Peter (Mission), ROC M. Rochard (Consortium), MAX Max (Magma), ART Arthur (Aqua ; absent si `CABLE_COUPE`), DOY Doyenne (Gardiens), COM porte-parole des Communautés, BRI Brice (vote **à lui**). Juan préside : il ne vote que sur M3, pour PARTAGÉE, si les **3 sources R4** concordent (inscription, toujours ; registre présenté : D097 a ou `PR_ACCUSE` ; Giovanni témoigne ou le Président confesse).
### 9.3 Votes de base (première condition vraie)
| Votant | M1 réseau : 1 FERMER · 2 CHARTE · 3 LIBÉRER | M2 arrivants : 1 REMPART · 2 INTÉGRATION · 3 MARCHÉ | M3 qui paie : 1 KANTO · 2 HOENN · 3 PARTAGÉE |
|---|---|---|---|
| NOR | 1 si `rL ≥ rC`, sinon 2 | abstention si `FLORA_DOUTE` et `FL` ≥ 60, sinon 1 | 1 |
| PRO | axe B : SCE 1, LIB 3, CTL 2 | 2 | 2 si `PR_ACCUSE`, sinon 1 |
| PET | 3 si Hoopa à la Mission et `PE` ≥ 55, sinon 1 | 2 si `PETER_ASSUME`, sinon 1 | 3 si `PETER_ASSUME`, sinon 2 |
| ROC | 1 si `PR_ACCUSE`, sinon 2 | 3 | 3 si Sylphe CONF, sinon 1 |
| MAX | 1 si Max ÉCOUTE ou Auguste parti ; sinon 2 si `rM ≥ rA`, sinon 1 | 3 si `S(rC)` ≥ +5, sinon 1 | 2 |
| ART | 3 si `rA ≥ rM`, sinon 2 | 2 | 3 |
| DOY | 3 si Hoopa (RED ou LIBRE) et `HO` ≥ 60, sinon 1 | 1 si `S(rG)` ≥ +10, sinon abstention | 3 si `S(rG)` ≥ 0, sinon abstention |
| COM | 1 si `rP ≥ rC + 5`, sinon 2 | 3 si `rC > rP` ; 1 si ≥ 4 zones ENVAHI/ABATTU ; sinon 2 (copie BRI si `BRICE_PARLE`) | 1 si `PETITION` ou `S(rI)` < −5, sinon 3 |
| BRI | BV : PROT 1, ACC 3, COMP 2 | PROT 1, ACC 2, COMP 2 si ≥ 3 zones MIXTE/RESTAURÉ sinon 1 | 3 si ≥ 8 pièces facultatives, sinon 2 ; option défendue par Red si `BRICE_DEFERE` |
Votants potentiels par option (≥ 3 exigés) : M1 FERMER 8, CHARTE 6, **LIBÉRER 5** (PRO, PET, ART, DOY, BRI) ; M2 REMPART 6, INTÉGRATION 6, **MARCHÉ 4** (ROC, MAX, COM, BRI non) ; M3 KANTO 4, HOENN 4, PARTAGÉE 7 (+ Juan). Chaque option minoritaire a au moins une condition **coûteuse ailleurs** : LIBÉRER (Hoopa confié à la Mission = `HO` −8 ; `HO` ≥ 60 = objets et `rI`/`rL`), MARCHÉ (`S(rC)` ≥ +5 = `rP`/`rA` bas), HOENN (`PR_ACCUSE` = `rC` −5 à −8).
### 9.4 Gestes de Red (option défendue ≠ résultat)
Pour chaque motion, Red **défend** une option (D108–D110, stockée b0-5) : il **montre** une pièce pertinente et **désigne** un votant non verrouillé ; ce votant bascule si la traduction passe (`BR` ≥ 50 ou `N` ≥ 2). Une bascule par motion ; +1 sur M3 si la phrase publique est écrite (D107 a). Pièces pertinentes : M1 FERMER vision ou Institut ; CHARTE journaux ou schéma du câble ; LIBÉRER voix du relais ou Hoopa présent · M2 REMPART carte publiée et ≥ 2 zones ENVAHI ; INTÉGRATION Timmy sauvé, Lokhlass, ou ≥ 2 RESTAURÉ ; MARCHÉ schéma ou `S(rC)` ≥ +5 · M3 KANTO article ou journal du nœud ; HOENN éclats ; PARTAGÉE affiche Sylphe. Verrous : NOR (M1 : 3 ; M2 : 2, 3), ART (M1 : 1 ; M2 : 1), ROC (M2 : 1 ; M3 : 2), DOY (M2 : 3), MAX (M1 : 3), BRI (tout, sauf `BRICE_DEFERE` en M3). Égalité : l'option défendue gagne si elle est à égalité et `N` ≥ 2 ou `BR` ≥ 60, sinon l'option de plus petit numéro (statu quo).
### 9.5 Conséquences et matrice de test
Conséquences : M1 → `PA` −15 / −8 / −3 (LIBÉRER : `HO` +5) et intention de Pierre Rochard au relais ; M2 → glissement des zones (§3.5) et variante sociale ; M3 → FK, `rI` −5 (KANTO) ou `rC` −3 (HOENN), `PETER_ASSUME` lu au climax, Maître.
Fréquences (sim) : M1 FERMER 72 % · CHARTE 25 % · LIBÉRER 3 % ; M2 REMPART 36 % · INTÉGRATION 54 % · MARCHÉ 10 % ; M3 KANTO 38 % · HOENN 17 % · PARTAGÉE 45 %.
**Matrice témoin (une partie réelle du modèle par issue ; à rejouer en harnais avec états forcés) :**
| Motion → issue | Votes (après bascule) | Bascule par Red | Défendue |
|---|---|---|---|
| M1 → FERMER | NOR 2, PRO 3, PET 1, ROC 2, MAX 1, ART —, DOY 3, COM 2, BRI 1 (égalité FERMER–CHARTE 3-3 ; défendue hors égalité → statu quo) | PRO | LIBÉRER |
| M1 → CHARTE | NOR 1, PRO 2, PET 1, ROC 2, MAX 1, ART 2, DOY 1, COM 2, BRI 2 | — | CHARTE |
| M1 → LIBÉRER | NOR 2, PRO 3, PET 1, ROC 1, MAX 1, ART —, DOY 3, COM 2, BRI 3 (égalité 3-3, `N`/`BR`) | PRO | LIBÉRER |
| M2 → REMPART | NOR 1, PRO 3, PET 2, ROC 3, MAX 1, DOY 1, BRI 1, COM 1 | PRO | MARCHÉ |
| M2 → INTÉGRATION | NOR 1, PRO 2, PET 2, ROC 3, MAX 1, DOY 1, BRI 2, COM 2 | — | REMPART |
| M2 → MARCHÉ | NOR 1, PRO 3, PET 1, ROC 3, MAX 3, ART 2, BRI 2, COM 3 | PRO | MARCHÉ |
| M3 → KANTO | NOR 1, PRO 1, PET 1, ROC 3, MAX 2, DOY 3, COM 1, BRI 3, Juan 3 | PET | KANTO |
| M3 → HOENN | NOR 1, PRO 2, PET 3, ROC 1, MAX 2, DOY 3, COM 3, BRI 2 (égalité HOENN–PARTAGÉE 3-3 ; défendue gagne car `N` ≥ 2 ou `BR` ≥ 60) | — | HOENN |
| M3 → PARTAGÉE | NOR 3, PET 3, ROC 3, ART —, DOY 3, COM 3, BRI 3, Juan 3 | NOR | PARTAGÉE |
Test harnais : pour chaque ligne, forcer les vars/flags de la partie témoin (`--sim` les imprime : `MWIT`), jouer D108–D110, lire `VAR_CF_SUMMIT` b6-11.

## 10. Climax (ch. 13)
### 10.1 Veillée (soin forcé)
Chaque allié disponible **dit** où il peut tenir et ce qu'il fera de la Fiole (aucun seuil caché) : exemples — Fuji “Il ne la prendra que de quelqu'un qu'il croit.” ; Lanette “La charte tient si Devon et la Ligue tiennent, et si le ciel se calme.” ; la Doyenne “Sans moi au Pilier, pas de rite.” ; Peter “Je porte la Fiole au Pilier. C'est tout.” Le bulletin de l'Institut annonce `PA` en mots.
### 10.2 Alliés (disponibilité → lieux compétents → intention au relais)
| Allié | Disponible si | R | P | C | Intention s'il tient le relais |
|---|---|---|---|---|---|
| Brice | toujours | si `DUO_BRICE` ou BV COMP, et `BR` ≥ 30 | — | ✓ | PROT → SCEAU, ACC → PACTE, COMP → PASSERELLE |
| Peter | `PE` ≥ 50 ou `PETER_ASSUME` | ✓ (résiste à `RK`) | ✓ | — | SCEAU |
| Pierre Rochard | `PR` ≥ 50 | ✓ (résiste) | ✓ | ✓ | suit le résultat de M1 (SCEAU / PASSERELLE / PACTE) |
| Blue | `BL` ≥ 55 | ✓ (résiste) | ✓ | — | l'option que Red a défendue en M1 |
| Doyenne | `S(rG)` ≥ +3 | — | ✓ (rite) | — | — |
| Fuji | `REL_AUGUSTE_FUJI` ou `LEO_INSIDER` | ✓ | — | — | PACTE si `FUJI_ATTEND` et `HO` ≥ 40, sinon BRISER |
| Koga / Jeannine | `JEANNINE_ALLIEE` ou Koga DÉMASQUÉ | ✓ | — | — | SCEAU |
| Léo | `LEO_INSIDER` et `S(rC)` ≥ −5 | ✓ | — | — | PASSERELLE |
| Flora | `FLORA_DESOBEIT` | — | — | ✓ | — |
| Major Bob | `BOB_QUARTIER`, `BOB_RESPECT` ou `S(rI)` ≥ +5 | — | — | ✓ |  — |
| Morgane | `MORGANE_ALLIEE` | — | — | ✓ | — |
| Aqua / Magma | §3.2 | — | — | ✓ | — |
### 10.3 Lieux
Red choisit un lieu (D116) et désigne un allié compétent pour chacun des deux autres. Définitions :
- `PILIER_TENU` = Red au Pilier ∨ allié au Pilier. Sinon Rayquaza atteint le relais tôt : `RT` faux sauf Red au relais.
- `RT` (relais tenu) = Red au relais ∨ (allié au relais ∧ (`RK` < 70 [80 avec `COPIE_REPRISE`] ∨ allié ∈ {Peter, Pierre Rochard, Blue})), et `PILIER_TENU` ou Red au relais.
- `RITE` = Doyenne au Pilier ∨ (Red au Pilier ∧ D121 b ∧ `S(rG)` ≥ seuil §3.2).
- `TC` (tempête contenue) = Red aux civils ∨ allié aux civils.
- `HOOPA_PRÉSENT` = (garde RED ∧ (Red au relais ∨ D118 a)) ∨ (garde MISSION ∧ Peter/Koga au relais) ∨ (garde LIBRE ∧ `HO` ≥ 70) ∨ (M1 = LIBÉRER ∧ `HO` ≥ 60).
- `INTENTION` = D117 si Red au relais ; sinon intention de l'allié du relais (§10.2) ; sinon AUCUNE.
### 10.4 Résultat de la Fiole (ordre d'évaluation : exhaustif et exclusif par construction)
1. **F2 PACTE** : `RT` ∧ INTENTION = PACTE ∧ `HOOPA_PRÉSENT` ∧ `HO` ≥ 70 (donneur Red) ou ≥ 80 (donneur allié).
2. **F1 SCEAU** : sinon, `RT` ∧ INTENTION = SCEAU ∧ `RITE` ∧ `TC` ∧ `PILIER_TENU`.
3. **F3 PASSERELLE** : sinon, `RT` ∧ INTENTION = PASSERELLE ∧ `S(rC)` ≥ 0 ∧ `S(rL)` ≥ −5 ∧ `PA` < 50.
4. **F5 CIEL OUVERT** : sinon, INTENTION = BRISER ∨ (¬`RT` ∧ (`HO` < 40 ∨ `CABLE_COUPE`)).
5. **F4 REMPART** : sinon.
Invariants : la Rocket n'obtient jamais la Fiole (¬`RT` ⇒ la Fiole se brise (F5) ou Rayquaza la détruit avec le relais (F4)) ; combattre Rayquaza (D121 a) ne fait que tenir le Pilier ; aucune fin n'est décidée par une victoire seule (toutes exigent un état social : `HO`, `S(rG)`, `S(rC)`, `PA`, alliés).
### 10.5 Variantes calculées en même temps (`VAR_CF_FIN`)
- **Civils :** AUCUN si Red aux civils ; BLESSÉS si allié aux civils avec `CIVILS_PREPARES`, D118 b, Pierre Rochard ou Major Bob, ou si `PA` < 40 ; PERTES sinon.
- **Amaryllis :** RENONCE si Red au Pilier, D119 a et `AM` ≥ 55 ; SACRIFICE si Red absent du Pilier, `AM` < 50, pas de rite et `PA` ≥ 45 ; PERSISTE sinon. (Sim : 12 % / 7 % / 81 %.)
- **Rocket :** FORTE si `RK` ≥ 60 ; DÉMANTELÉE si (`RK` ≤ 35 avec Red au relais ou `RK` ≤ 20) et une autorité ; AFFAIBLIE sinon. Toujours évasion des commandants avant l'année 3.
- **Maître (ch. 14) :** Marc si F2 ou (`PR_ACCUSE` ∧ M3 = HOENN), sinon Pierre Rochard.
- **Variante sociale :** résultat de M2, corrigé par la moyenne des zones après glissement : INTÉGRATION avec ≥ 3 zones ABATTU → REMPART ; REMPART avec ≥ 3 zones RESTAURÉ → INTÉGRATION.
### 10.6 Table d'affectation (aucune affectation dominante)
| Red au… | Ce qu'il gagne seul | Ce qu'il abandonne à un allié |
|---|---|---|
| Relais | `RT` garanti ; seul donneur PACTE à 70 ; Rocket démantelable à `RK` ≤ 35 | Amaryllis ne peut pas renoncer ; civils au mieux BLESSÉS ; rite seulement si la Doyenne vient |
| Pilier | RENONCE d'Amaryllis ; rite sans la Doyenne | le relais à un allié (intention de l'allié, `RK` < 70) ; PACTE exige `HO` ≥ 80 + Hoopa confié |
| Civils | AUCUN blessé | relais et Pilier aux alliés : la fin dépend entièrement des intentions annoncées à la veillée |

## 11. Fins formelles et chemins témoins
Ordre : §10.4 (Fiole) puis §10.5 (variantes). Fin cachée (couche supplémentaire, compatible avec toutes) : `CHEN = AVOUE` ∧ ≥ 12 pièces facultatives sur 19 (`FLAG_CF_HIDDEN_ENDING`). **Aucune fin ni variante n'est atteinte par une victoire de combat seule** (invariant 4).
**Témoins (15/15 atteints par le modèle ; décisions clés, extrait de `--sim 18000`) :**
| Fin × variante | Persona | Clés | État décisif |
|---|---|---|---|
| F1 × INTÉGRATION | Anti-Rocket | D075 b, D082 a, D116 a, D117 b ; Doyenne au Pilier, PR aux civils | M 1-2-1 ; `S(rG)` +10 ; `PA` 51 |
| F1 × MARCHÉ | Gardiens | D116 b (Red au Pilier, rite D121 b), PR au relais (M1 = FERMER → SCEAU), Morgane aux civils | M 1-3-3 ; `S(rG)` +45 |
| F1 × REMPART | Anti-Rocket | D116 a, D117 b, Doyenne au Pilier, Brice aux civils | M 1-1-1 ; `RK` 0 |
| F2 × INTÉGRATION | Hoopa | D075 a, D116 a, D117 a ; Doyenne P, PR C | `HO` 92 ; M 3-2-3 |
| F2 × MARCHÉ | Hoopa | idem, Blue P, Flora C | `HO` 91 ; M 3-3-1 |
| F2 × REMPART | Hoopa | idem, PR P, Morgane C | `HO` 86 ; M 1-1-1 |
| F3 × INTÉGRATION | Consortium | D040 c, D054 c, D102 a, D116 a, D117 c ; Peter P, Bob C | `S(rC)` +37 ; `PA` 41 |
| F3 × MARCHÉ | Consortium | idem, D102 b | `S(rC)` +43 ; `PA` 43 |
| F3 × REMPART | Consortium | idem, M2 REMPART | `S(rC)` +38 ; `PA` 33 |
| F4 × INTÉGRATION | Mission | D116 a, D117 b sans rite (PR au Pilier, pas de Doyenne) | SCEAU échoue → F4 |
| F4 × MARCHÉ | Relations | D116 c ; Koga au relais (SCEAU) sans rite | — |
| F4 × REMPART | Rempart | D116 c ; Blue au relais (SCEAU défendu) sans rite | — |
| F5 × INTÉGRATION | Gardiens | D116 b ; Fuji au relais sans `FUJI_ATTEND` → BRISER | `HO` 30 |
| F5 × MARCHÉ | Aléa | D116 a, D117 d | — |
| F5 × REMPART | Aléa | D116 c ; Fuji au relais → BRISER | `HO` 29 |
Chaque témoin est une partie complète du modèle : les 131 choix sont imprimables (`path_of`). À convertir en saves forcées pour le harnais QA (`tools/qa/`), une par ligne.

## 12. Postgame (lecteurs)
Retour de l'équipe de Red par le canal de la fin (F1 PC de Ciléo, F2 anneau, F3 Passerelle, F4 bateau d'Olga : `OLGA_LOKHLASS` ou FK ≥ 1, sinon pêcheur de Myokara ; F5 anneau sauvage) → plafond 100. D125 ordonne les premiers accès ; D126–D131 ; Rocket : D127 a retire les sbires (`FLAG_CF_GIO_DISSOUT`) ; F3 garde le Kiosque ouvert (incidents résiduels : épidémies P2 rares) ; F5 : épidémies sauvages tournantes (E-OUT). Légendaires : canal par fin (brief D), **tous obtenables dans toutes les fins** (invariant 9 ; Mewtwo : D126 b retarde, ne retire pas).

## 13. Quêtes et QoL
**Quêtes :** fil de Hoopa (10 gestes) ; Piko (D006 → F2 ou lettre) ; missions de zone ×6 ; quête de Bayar (D048, facultative, Éclate-Roc) ; Ferrand (D033 → D082 a) ; Défis Indigo (8 combats refusables, 4 sont des décisions) ; Tournoi (D034) ; Auguste–Fuji (D062 → D089) ; Timmy (D038 → D064 → D124) ; restauration (D128) ; fin cachée (D131).
**QoL :** Multi Exp (`I_EXP_SHARE_FLAG FLAG_CF_EXP_SHARE`, ch. 3 par Chen ou ch. 4 par Seko : D030 ; **arbitrage v3.1 : posé dans toutes les branches avant la fin du ch. 4** — si D030 ≠ a, Seko le remet au ch. 4 même si Pikachu est laissé, D041) — demandé par le brief D pour que le plafond n'empêche pas de diversifier ; choix du Pokémon de tête (`FLAG_CHOOSE_BATTLE_LEAD`) via un PNJ « coach » à Clémenti (ch. 1) ; difficulté (`VAR_DIFFICULTY`) proposée par Seko au ch. 0 (Normal/Difficile) ; `FLAG_NO_WILD_ENCOUNTERS` pendant les scènes et escortes ; soin ≤ 2 cartes (§15) ; le Carnet (objet clé) affiche les pièces du Dossier et les phrases de Red (lecture seule, aucune jauge).

## 14. Allocation (résumé ; table définitive : `FLAGS_VARS_REGISTRY.md`)
| Catégorie | Utilisé | Budget | Marge |
|---|---|---|---|
| Vars libres (`VAR_UNUSED_*` + vars d'état « Unused Var », 54 vérifiées par grep sans référence hors `vars.h`) | **44** (9 relations, 7 réputations, `PA`, `RK`, CHAPTER, ECO, WORLD, BVCOUNT, SUMMIT, CLIMAX, FIN, STANCE, 17 vars de décisions, CAP) | ≤ 45 | 10 libres (0x40DB, 0x40DC, 0x40E5, 0x40F9–0x40FF) |
| Vars vanilla recyclées | **0** (inutile ; `VAR_SOOTOPOLIS_CITY_STATE` et `VAR_MOSSDEEP_CITY_STATE` sont lues par `src/overworld.c` : **interdites**) | — | — |
| Flags persistants libres | **227** (0x22–0x4F : 46 ; 0x264–0x2BB : 88 ; 0x493–0x4EF : 93, dont 93 de visibilité par chapitre) | ≤ 260 | 59 (0x8E5–0x91F) + 32 isolés |
| `FLAG_HIDE_*` vanilla recyclés | **40** (lecteurs = cartes réécrites + `new_game.inc`, aucun lecteur C ; liste et preuve grep au registre) | ~40 | 10 candidats prouvés non utilisés |
| Flags temporaires | 0x5–0xD : bascules du Sommet (une seule carte) | — | — |
| Quotidiens | **0** (0x920–0x95F remis à zéro chaque jour : exclus) | — | — |

## 15. Traversée par branche et softlocks
### 15.1 Capacités, donneurs, soins
| Ch. | Trajet obligatoire | Capacités requises | Donneurs (vanilla conservé) | Soin ≤ 2 cartes |
|---|---|---|---|---|
| 0 | R104 plage → maison Marco → Clémenti → R102 → Rosyères → R101 → Bourg-en-Vol → R103 | aucune | — | Mme Seko (lit) ; Centre de Rosyères |
| 1 | Bourg-en-Vol → Clémenti → R104 → Bois → Mérouville → R116 | aucune | Coupe (Roxanne, B1) | Centres de Clémenti, Mérouville |
| 2 | R104 (bateau, `FLAG_DELIVERED_STEVEN_LETTER` posé à la remise) → Myokara → Grotte Granite | Flash facultatif | Flash (Bastien, B2) | Centre de Myokara (1 carte) |
| 3 | Myokara → R107–109 → Poivressel → R110 sud | aucune | — | Centre de Poivressel |
| 4 | R110 → Lavandia → R117 → Vergazon → Tunnel Mérazon | Éclate-Roc **au milieu du tunnel : non** — le raid ouvre le passage (`VAR_RUSTURF_TUNNEL_STATE` réécrit, lu aussi par `src/field_specials.c` : garder les valeurs vanilla 4–6) | Éclate-Roc (maison de Lavandia, après B3) | Brice soigne avant le raid ; Centre de Vergazon |
| 5 | Lavandia → R111 sud → R112 → Chemin Ardent → R113 → Autéquia → R114 → Chutes Météore 1F_1R | Éclate-Roc (R111) | — | Centre d'Autéquia |
| 6 | R112 (téléphérique ouvert par `FLAG_HIDE_ROUTE_112_TEAM_MAGMA`, posé en fin d'événement du ch. 5) → Mont Chimnée → Vermilava → Planque Magma 1F/2F_1R | aucune | Force (Adriane, B4) ; Lunettes Sable (Brice) | médecin du chantier (sommet + entrée de planque) |
| 7 | Vermilava → R112 → Lavandia → R117 → Vergazon → Tunnel → R116 → Mérouville → R104 → Clémenti → Bourg-en-Vol | aucune | Surf (Norman, B5 ; `FLAG_RECEIVED_HM_SURF` lu par `PetalburgCity_WallysHouse` : remis par Norman, script réécrit) | Centres sur le trajet |
| 8 | R118 (Surf) → R119 → Institut → Cimetronelle → R120 | Surf | Vol (Brice, R119, `VAR_ROUTE119_STATE` conservé) ; Scope + Méga-Anneau (D077, deux cas) | lit de l'Institut |
| 9 | R120 → R121 → Nénucrique ; R122 (Surf) → Mont Mémoria | Surf | — | Centre de Nénucrique ; Spectra soigne au Mont Mémoria |
| 10 | Nénucrique → R124 (ouverte par `FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS` quand `FLAG_CF_M_PLANQUE` ∧ `FLAG_CF_M_MEMORIA`) → Algatia | Surf | Plongée (Pierre Rochard, D101, deux cas : `FLAG_RECEIVED_HM_DIVE`) | Centre d'Algatia |
| 11 | R127/128 → plongée → Caverne Fondmer | Surf, Plongée, Force, Éclate-Roc | — | infirmière d'Aqua **ou** Flora à l'entrée (D105, les deux soignent) ; Aldo en plus si `ALDO_RESPECT` |
| 12 | R126 → plongée → Atalanopolis | Plongée | Cascade (Juan, B8) | Centre d'Atalanopolis ; soin forcé avant le Sommet |
| 13 | veillée → lieu choisi (warps scriptés : relais, Pilier sommet, civils) | aucune (warps) | — | soin forcé à la veillée ; Doyenne avant le Pilier |
| 14 | R128 → Éternara → Route Victoire | Surf, Cascade, Force, Éclate-Roc (Flash non requis : `requires_flash: false`) | — | Centre d'Éternara |
### 15.2 Portes vanilla touchées (preuve grep, `data/maps/*/scripts.inc`, hors `map.json`)
| Drapeau / var | Lecteurs vanilla | Traitement |
|---|---|---|
| `FLAG_DELIVERED_DEVON_GOODS` | Route109, DewfordTown, Route104_MrBrineysHouse, OceanicMuseum 1F/2F, SternsShipyard_1F, `src/pokenav_match_call_data.c` | posé dans les 2 options de D029 (sens vanilla gardé) |
| `FLAG_DELIVERED_STEVEN_LETTER` | DevonCorp_3F, GraniteCave_StevensRoom, Route104, MrBrineysHouse, DewfordTown, pokenav | posé à la remise (ch. 2), même si D018 c (Pierre Rochard absent : la lettre est laissée sur son bureau) |
| `FLAG_HIDE_ROUTE_112_TEAM_MAGMA` | Route112, MeteorFalls_1F_1R | posé par la fin d'événement commune du Site Météore (D050) |
| `FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS` | LilycoveCity, AquaHideout_B2F | posé quand planque résolue ∧ Mont Mémoria |
| `FLAG_HIDE_ROUTE_119_TEAM_AQUA` | Route119, WeatherInstitute 1F/2F | occupation de l'Institut par Sarah ; levé par D072 (2 issues) |
| `VAR_ROUTE119_STATE`, `FLAG_RECEIVED_HM_FLY` | Route119 | Brice 3 et Vol conservés |
| `FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE` | SootopolisCity, MtPyre_Summit | posé à la nouvelle partie (état normal) ; portes de l'arène pilotées par `FLAG_CF_M_FONDMER` |
| `VAR_SOOTOPOLIS_CITY_STATE`, `VAR_MOSSDEEP_CITY_STATE` | + `src/overworld.c` | **non recyclées** ; valeurs vanilla de repos |
| `VAR_PETALBURG_GYM_STATE` | 7 scripts dont `prof_birch.inc` | réécrit : Norman accepte le défi à 4 badges (sens vanilla) |
| `VAR_RUSTURF_TUNNEL_STATE` | RustboroCity, RusturfTunnel, `event_scripts.s`, `src/field_specials.c` | posé à la valeur « tunnel ouvert » par la fin du raid (D040, 3 issues) |
| `FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN` | 6 cartes + pokenav | **jamais posé** (Kyogre dort, bible §6) |
### 15.3 Cas de softlock examinés
| Cas | Risque | Parade |
|---|---|---|
| Plongée ouvre Fondmer **et** Atalanopolis | Sommet avant Fondmer (S12 v2) | Sommet et arène exigent `FLAG_CF_M_FONDMER` ; garde explicite |
| Refus d'un combat refusable | décision perdue / question reposée (S2 v2) | `trainerbattle_single_declinable` + script de refus (D1) qui écrit le slot (valeur 3) ; refus définitif |
| Défaite dans un combat d'histoire | voile blanc, jalon non posé | `FLAG_CF_NO_WHITEOUT` + soin scripté + script de fin commun |
| Mission de zone ignorée | état orphelin | MIXTE posé au jalon de fin de chapitre |
| Hoopa suiveur sur l'eau / en Plongée | blocage du suiveur | `FLAG_CF_HOOPA_SUIVEUR` effacé sur les cartes d'eau (ON_TRANSITION), rétabli à terre |
| Retour arrière du ch. 7 (trajet long) | ennui, pas de blocage | contenu sur le trajet (D063–D071) |
| D063 a (filature) | Vergazon sans Red | script automatique (§8.1), aucun PNJ bloquant |
| D079 / D123 (donner un Pokémon) | équipe vide | option masquée si l'équipe a < 2 Pokémon |
| Kiosque prend un objet | objet clé perdu | liste fixe sans objets clés |
| Vélo Cross | sprites manquants (ENGINE_CHANGES §B) | jamais requis ; Pilier par warp scripté |
| Climax sans allié compétent pour un lieu | lieu vide | Brice toujours disponible (C) ; un lieu vide est **légal** et lisible (veillée : “Personne ne tient le Pilier.”) |

## 16. Lectures par carte (états lus → ce qui change)
| Carte (dossier vanilla) | États lus | Effet observable |
|---|---|---|
| PetalburgCity_Gym (QG) | N, D017, D016, `VOTE_ABATTAGE`, `BOB_QUARTIER`, `BR` | barrage, insigne, vote du ch. 7 |
| PetalburgWoods | D008, `FL` | brigade présente / arrivants enfuis |
| RustboroCity + DevonCorp 2F/3F | Z-02, D009, D011, D013, D071, D015 | boutique (Corde Sortie), affiche, Ferrand, mineur revenu, scène W2 |
| Route116 | Z-02, D012, D014, `HO` ≥ 40 (D066) | tables E-ECO, sbires, carnet rendu |
| RusturfTunnel | D014 b, D015, D040 | effectifs, approche du raid |
| DewfordTown (+ Gym) | Z-01, D006 (Marco), D019, D021, D022 | boutique (Baies Oran), passage gratuit, Aldo |
| GraniteCave_StevensRoom | D018 | Pierre Rochard présent ou lettre sur le bureau |
| SlateportCity (port, marché, Tente, chantier, musée) | D025, D026, D027, D030, D031, D032, D034, `FK`, `N`, Kiosque | foule, fillette sans Goélise, Blue/Scott, Chen/Seko, pétition, Défis |
| Route109_SeashoreHouse | D035 | couple présent / amendé |
| MauvilleCity / NewMauville | D036, D041, D042, D043, `BOB_*` | quartier éclairé ou sombre, Pikachu |
| VerdanturfTown / Route117 | Z-03, D037, D038, D063, D064 | baies, Timmy et son arrivant, brigade |
| Route111 (désert) | D048, Z-03 | ruines scellées / Kraknoix |
| Route112 / MeteorFalls_1F_1R | D046, D050, `FLAG_HIDE_ROUTE_112_TEAM_MAGMA` | capteur, clans, téléphérique |
| FallarborTown / Route113–114 | D047, D049, D052, D053 | Kosmo (lunettes), Lanette, fragment, Aster |
| MtChimney / LavaridgeTown / MagmaHideout | Z-06, D054–D062 | troupeau, sources vides, Ariane, Erika/Adriane, Auguste |
| LittlerootTown (maisons, labo) | D005, D030, D041, D067, D068, BV | dîner, publication, Pikachu chez Brice |
| Route119 + Institut | D072, D080, D077 | occupation, Sarah sur le pont |
| FortreeCity / Route120 | Z-04, D074, D075, D076, D078, D079, D081 | nids, piège, suiveur, Morgane, Jeannine |
| LilycoveCity (port, toit, Concours, Safari) | D082, D083, D084, D085, D090, D091, D093, garde MISSION | nuit du marché, Blue/Giovanni, Ondine/Aldo, cage de Hoopa |
| MtPyre (extérieur, sommet) | D086–D089 | rite, Agatha, article, Fuji/Auguste |
| MossdeepCity (+ Gym, Centre Spatial, maison de Pierre Rochard) | D094–D101, `N` ≥ 2, `RK` ≥ 40 | piège nominatif, seconde équipe d'Ariane, faux Giovanni, Plongée |
| SeafloorCavern_* | D102–D105, `REL_ONDINE_ARTHUR`, `ALDO_RESPECT` | camp d'Ondine, soigneurs, câble |
| SootopolisCity (+ Gym) | `FLAG_CF_M_FONDMER`, Sommet (tout §9), D107–D115 | séance, votes, R4 |
| Veillée, MossdeepCity_SpaceCenter_2F, SkyPillar_Top, civils | §10 | lieux, alliés, Fiole |
| VictoryRoad_1F, EverGrandeCity_* | Blue (`BL`, `BLUE_LIBRE`, D123), D124, `VAR_CF_FIN` | équipes et répliques du Conseil 4 (écho de la fin), Maître |
| Cartes du postgame | `VAR_CF_FIN`, D125–D131, `FK`, ECO | canal de retour, Kiosque, sbires, Mewtwo, Regis |

## 17. Aides moteur requises (code en ROM ; IWRAM interdite)
| Code | Aide | Exigée par | État |
|---|---|---|---|
| E-CAP | config `LEVEL_CAP_VARIABLE` + `VAR_CF_CAP` + `CF_RaiseCap` (script) | §7 | config seule |
| E-BITS | specials `CF_GetBits` / `CF_SetBits` (var, décalage, largeur → `VAR_RESULT`) | toutes les décisions (slots), WORLD, ECO, SUMMIT, CLIMAX, FIN, STANCE | **bloquant** (~40 lignes C) |
| E-REPREL | special `CF_RepStanding` (`VAR_RESULT = rX − moyenne + 100`) | §3.2 (tous les lecteurs de réputation) | **nouveau, bloquant** (~20 lignes) |
| E-ECO | table {carte, zone} → en-tête alternatif selon `VAR_CF_ECO` | §3.5, D010, D018, D037, D054, D074, D102, D128 | brief D |
| E-OUT | poser / effacer une épidémie (espèce, carte, niveau) ; couper le tirage TV | §3.3 (P2), F5 postgame | brief D |
| E-ADAPT | type dominant de l'équipe → `VAR_RESULT` | brief B (Blue, Giovanni, Peter), D123 | brief B |
| E-REMOVE | `removepartymon SLOT` | prologue (D001), D079, D123 | ~10 lignes |
| E-NATIVE | espèce du dex de Hoenn ? → `VAR_RESULT` | D085, D123 (natif) | ~10 lignes |
| E-LVL | **aucun code** : `givemon` lit le niveau par `VarGet` (`src/script_pokemon_util.c:506`) → `copyvar VAR_0x8001, VAR_CF_CAP ; subvar 2` | D041 | vérifié par lecture |
| Existants | D1 refusables, D2 tête, E affinités, N1 sans rencontres, `setfollowernpc`, `dynmultichoice`, `ChoosePartyMon` | partout | `ENGINE_CHANGES.md` |
| E-LEDGER | 128 bits dans SB3 (16 o) pour les statiques (brief D) | sites légendaires, orphelins | accepté (seul usage de SB3) |
| Non requis | E-SB3 général, E-PRICE (remplacé par ruptures de stock), E-LEND (D118 b donne des objets) | — | rejetés (arbitrage v3.1) |

## 18. Checklists
**GM_METHOD §6.1 :** intention (thèse bible §2 : lire ce que ses choix prennent aux autres) ✔ ; comportement observable (choisir, montrer, désigner, se placer) ✔ ; économie : sources/puits par système §3, §6 ✔ ; dominance : §5 chiffré ✔ ; progression : chaque chapitre ouvre des options (alliés, pièces, votes) ✔ ; sens : §1 ✔ ; UX : aucune jauge, perception par réactions, bulletin en mots ✔ ; faisabilité : budgets §14, aides §17 ✔ ; **aucune affirmation « testé » : le modèle papier est une preuve de cohérence, pas un test ROM** ✔.
**§6.2 Technique :** fiches 15 champs → le registre (champs du brief C) en tient lieu par décision ; flags/vars recensés sans collision (registre) ✔ ; build/tests : **non exécutés** (aucun code écrit) ✘ (attendu : porte prototype) ; dépendances : E-BITS et E-REPREL sur le chemin critique.

## 19. Conflits et écarts (à arbitrer par le GMD)

> **Arbitré** (`reviews/ARBITRATION_V3.md` §4) : K-C1 à K-C10 acceptés. Motion 3 « qui paie » retenue contre la bible v3.0 (la garde de la Fiole se joue au climax). Les « appels » sont des scènes scriptées (Match Call coupé). Multi Exp : voir §13 (règle ajoutée).
| # | Conflit | Cause | Choix fait ici | Alternative / coût |
|---|---|---|---|---|
| K-C1 | Bible ch. 11 « Grotte Tréfonds » = en FR vanilla **Caverne Fondmer** (`SeafloorCavern`, R128 sous-marin) ; « Grotte Tréfonds » = `ShoalCave` (`region_map_sections.json`) | erreur de nom | on écrit Caverne Fondmer | renommer la carte : risque de confusion avec Shoal Cave |
| K-C2 | Réputations lues **relativement** (`S(X)`) au lieu de seuils absolus (bible §11.1 « vars 0–100 ») | sans cela, « plaire à tous » marche (7/7 ≥ 55 trouvé par recherche) | lecture relative + E-REPREL | seuils absolus relevés : fragile, à retarer à chaque ajout |
| K-C3 | Seuil du PACTE : brief A « `HO` ≥ 80 au relais » ; ici 70 (Red donneur), 80 (allié) | borne analytique de `HO` = 87 : 80 exigerait 9 gestes sur 10 | 70 / 80 | 80 partout : F2 devient quasi introuvable |
| K-C4 | Amaryllis ne renonce **que** si Red est au Pilier (brief A : renonce/persiste/sacrifice selon `AM` et preuves) | chemin doré (F2 + RENONCE + civils sains) trouvé sinon | renonciation exclusive par présence | autoriser Aragon : rouvre le chemin doré |
| K-C5 | « Pacte + intégration + Rocket démantelée » reste atteignable (sans « toutes relations ≥ 60 ») | chemin libéral cohérent | gardé, au prix chiffré §5 | l'interdire = punir une cohérence thématique |
| K-C6 | Plafond « Maître → 60 » interprété : 60 à l'entrée de la salle du Maître, 75 au Panthéon, 100 au retour de l'équipe | ligne bible ambiguë | §7 | — |
| K-C7 | Défis Indigo : 8 refusables, seuls 4 sont des décisions comptées (Koga, Peter, Major Bob, Aldo) ; les autres sont du contenu | bible §10.1 (décision seulement si état lu) | conforme | — |
| K-C8 | Brief D : état ABATTU (2 bits) adopté ; prix → ruptures de stock | évite une aide moteur | adopté | E-PRICE si le GMD veut des prix |
| K-C9 | Mewtwo « laisser » (brief D §9.4) : D126 b **retarde** la capture (lettre de Fuji), ne la supprime pas | invariant 9 | adopté | — |
| K-C10 | Brief A demande `STANCE_ERIKA`, `STANCE_MAX`, `REL_*` : fusionnés en flags ou en bits de `VAR_CF_STANCE` ; `REL_CHEN_SEKO` **dérivé** à la fin | budget | voir registre | — |

## 20. Changelog
| Date | Version | Changement | Auteur |
|---|---|---|---|
| 2026-10-14 | 3.0 | Réécriture complète pour *Confluence* : systèmes, lecture relative des réputations, Sommet à 9 votants, climax à 3 lieux, fins ordonnées, plafonds par var, allocation, traversée, lectures par carte ; modèle `cf_model.py` | GMD secondaire (brief C) |
| 2026-10-14 | 3.1 | Arbitrage du GMD (`reviews/ARBITRATION_V3.md`) : note §19 ; E-LEDGER ajoutée en §17 ; règle du Multi Exp en §13 | GMD |
