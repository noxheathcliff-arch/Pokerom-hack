# Audit de l'IA de combat — pokeemeraude-expansion 1.16.4

> Rôle : Competitive Strategy & Battle AI. Audit **lu dans le code** (pas seulement dans la doc).
> Fichiers étudiés : `include/constants/battle_ai.h`, `include/config/ai.h`, `src/battle_ai_main.c`,
> `src/battle_ai_util.c`, `src/battle_ai_switch.c`, `src/battle_ai_items.c`, `src/battle_ai_field_statuses.c`,
> `src/battle_controllers.c`, `src/battle_gimmick.c`, `src/battle_terastal.c`, `src/battle_dynamax.c`,
> `src/battle_util.c`, `src/difficulty.c`, `include/config/{battle,caps,item}.h`, `tools/trainerproc/main.c`,
> `docs/tutorials/{ai_flags,ai_logic,ai_dynamic_functions,how_to_trainer_party_pool}.md`.
> Les numéros de ligne renvoient à l'état du dépôt au commit `f06a884`.

---

## 0. Synthèse (TL;DR)

| Constat | Conséquence pour le design |
|---|---|
| Toute l'IA est un **système de score** : chaque capacité part à 100 (`AI_SCORE_DEFAULT`), chaque flag actif ajoute/retire des points, la meilleure note gagne, **égalité = tirage aléatoire** (`ChooseMoveOrAction_Singles`, `RandomUniform(RNG_AI_SCORE_TIE_SINGLES…)`). | Un dresseur sans `CHECK_VIABILITY` joue quasiment au hasard parmi ses capacités « non mauvaises ». |
| **640 / 855** dresseurs vanilla n'ont que `AI: Check Bad Move`, 173 ont `Basic Trainer`, **aucun** n'a `Smart Trainer` (seul `DEBUG_TRAINER_AI` l'a). | La base actuelle est très facile ; tout boss doit être retouché. |
| Sans `OMNISCIENT`, l'IA **ne connaît que ce qu'elle a vu** (capacités utilisées, talent/objet révélés) via `gBattleHistory` / `gAiPartyData`. Avec `OMNISCIENT`, elle lit moves/talent/objet de **toute** l'équipe du joueur dès le début (`Ai_InitPartyStruct`, `battle_ai_main.c:575`). | Omniscient = « IA qui triche » perçue. À réserver aux combats où l'équipe du joueur est connue du lore (Rival, Champion) ou compensée par des indices. |
| L'IA calcule les dégâts réels (même moteur que le combat) avec des « rolls » configurables : en attaque elle suppose le **roll max** (`AI_ROLL_ATTACKING = AI_ROLL_MAX`), en défense le roll médian. | Elle sur-estime légèrement ses KO → peut tenter un KO raté de justesse : c'est une fenêtre de jeu pour le joueur. |
| Les gimmicks (Méga, Z, Dynamax, Téra) sont **utilisés dès que possible** : `BattleAI_ChooseMoveIndex` met toujours `USE_GIMMICK`, seuls Z (pas si l'attaque normale KO) et Téra (pas avec Abri, ou logique `SMART_TERA`) sont reconsidérés. | La Méga du boss arrive au tour 1 de sa sortie : prévisible → bon « tell ». |
| Les objets de dresseur (`Items:` max 4) sont utilisés via `ShouldUseItem` : soin si PV < 25 % et que le soin évite le KO (ou soin > 2× dégâts reçus, ou dernier Pokémon), statut, X-objets, Rappel. Désactivé si l'IA pense pouvoir KO ce tour. | Les potions boss sont « intelligentes » : ne pas en donner 4 à un boss early. |
| `SMART_SWITCHING` active ~14 heuristiques de switch avec des **taux d'échec volontaires** (50 % sur « mauvais matchup ») réglables dans `include/config/ai.h`. | Le switch IA n'est jamais 100 % prédictible → conforme au « fair play » si l'équipe est lisible. |
| Système de **difficulté** natif présent (`Difficulty: Easy/Normal/Hard` par dresseur dans `trainers.party`) mais **désactivé** (`B_VAR_DIFFICULTY 0`). | Exploitable pour un mode « Difficile » à faible coût. |
| Caps de niveau natifs présents mais **désactivés** (`B_EXP_CAP_TYPE EXP_CAP_NONE`, `B_LEVEL_CAP_TYPE LEVEL_CAP_NONE`). | À décider au niveau design (voir §9). |

---

## 1. Architecture de la décision IA

1. **Initialisation** (`BattleAI_SetupFlags`, `battle_ai_main.c:303`) : flags lus via `GetTrainerAIFlagsFromId(trainerId)`.
   - Ajouts automatiques (`GetAiFlags`, l.254) : `DOUBLE_BATTLE` si combat double ; `SMART_MON_CHOICES` si `SMART_SWITCHING` ; `PREDICT_SWITCH` si `PREDICT_INCOMING_MON` ; `DYNAMIC_FUNC` si une fonction dynamique a été posée par script.
   - Cas spéciaux : Safari, Roaming, `FIRST_BATTLE` (combat contre Zigzagoon), Frontier/e-Reader/Trainer Hill/base secrète = `BASIC` codé en dur.
   - Les **flags de l'adversaire sont aussi copiés sur les battlers du joueur** (l.351-356) : c'est ce qui permet la prédiction (l'IA simule « ce que je ferais à la place du joueur »).
   - IA sauvage : `GetWildAiFlags` (l.224) — `CHECK_BAD_MOVE`, + `CHECK_VIABILITY` dès N.20, + `TRY_TO_2HKO` dès N.60, + `HP_AWARE` dès N.80 ; seulement si `WE_SMART_WILD_AI_FLAG` est défini et levé.
2. **Chaque tour** (`ComputeAiBattlerDecisions`, l.402) :
   - tirage de prédiction (switch : 50 % `PREDICT_SWITCH_CHANCE` ; move : 100 % `PREDICT_MOVE_CHANCE`) ;
   - calcul du meilleur remplaçant (`GetMostSuitableMonToSwitchInto`) puis `ShouldSwitch` ;
   - scoring des 4 capacités : boucle sur chaque bit de flag → `sBattleAiFuncTable[bit]` (l.78) ;
   - `AI_CompareDamagingMoves` si `CHECK_VIABILITY` : départage des attaques (KO garanti, vitesse, précision, baies de résistance, auto-KO, attaques en 2 tours).
3. **Action** (`AI_TrySwitchOrUseItem`, l.460) : priorité **switch > objet > attaque**. Un switch ou un objet annule le gimmick du tour.

Fonctions de score réellement branchées (table `sBattleAiFuncTable`) : `CHECK_BAD_MOVE`, `TRY_TO_FAINT`, `CHECK_VIABILITY`, `FORCE_SETUP_FIRST_TURN`, `RISKY`, `TRY_TO_2HKO`, `PREFER_BATON_PASS`, `DOUBLE_BATTLE`, `HP_AWARE`, `POWERFUL_STATUS`, `PREDICT_SWITCH`, `PP_STALL_PREVENTION`, `ATTACKS_PARTNER` (+ `DYNAMIC_FUNC`, `ROAMING`, `SAFARI`, `FIRST_BATTLE`). Les autres flags n'ont **pas** de fonction propre : ce sont des conditions lues ailleurs (switch, calcs, connaissance).

---

## 2. Référence de tous les flags (vérifiés dans le code)

Légende colonne « Type » : **S** = fonction de score, **C** = condition lue ailleurs, **K** = connaissance (information), **H** = handicap.

| Flag (bit) | Type | Effet réel vérifié | Où |
|---|---|---|---|
| `CHECK_BAD_MOVE` (0) | S | Pénalise les capacités qui échouent : immunités (type/talent), cible invulnérable, statut déjà présent, météo déjà active, Sleep Clause (`B_FLAG_SLEEP_CLAUSE`), etc. **Indispensable** à tout dresseur (sinon spam d'attaques inutiles). | `AI_CheckBadMove` main.c:1237 (≈1800 lignes) |
| `TRY_TO_FAINT` (1) | S | Gros bonus à la capacité qui **OHKO** ; si l'IA est plus lente et va mourir, bonus aux attaques prioritaires. Ne gère pas le 2HKO. | main.c:3039 |
| `CHECK_VIABILITY` (2) | S | Le « cerveau » : `AI_CalcMoveEffectScore` (score de chaque effet : boosts, hazards, statut, soin, pivot, météo…) + `AI_CompareDamagingMoves` (meilleure attaque). Déclenche aussi le setup **quand c'est pertinent** (`ShouldSetup…` avec roll `AI_ROLL_SHOULD_SETUP_DEFENDING`). | main.c:5925, 4205, 4002 |
| `FORCE_SETUP_FIRST_TURN` (3) | S | Bonus fixe aux capacités de setup/statut au **premier tour**, sans réflexion. Aussi : utilise les X-objets dès le tour 1 (`battle_ai_items.c:82`). | main.c:5959 |
| `RISKY` (4) | S+C | Suppose roll **max** en attaque et **min** en défense, ignore la précision pour les KO, préfère coups critiques/effets aléatoires, Explosion, Counter/Mirror Coat « à l'aveugle », switch offensif après KO. | main.c:6020, util.c:111-160 |
| `TRY_TO_2HKO` (5) | S | Bonus à toute capacité qui OHKO ou 2HKO (sans tenir compte de qui frappe en premier). | main.c:6100 |
| `PREFER_BATON_PASS` (6) | S | Favorise boosts (si PV ≥ 60 %), Racines/Anneau Hydro/Abri, puis Relais. | main.c:6139 |
| `DOUBLE_BATTLE` (7) | S (auto) | Logique de duo : ne pas gêner le partenaire, Coup d'Main, déclenchement de talents alliés (Motorisé, Lavabo…), Skill Swap, Fake Out pour sauver l'allié (`FAKE_OUT_SAVE_ALLY_CHANCE` 50 %), Trick Room/Tailwind « double » en fin de Distorsion (35 %). Ajouté automatiquement. | main.c:3095 |
| `HP_AWARE` (8) | S | Modulation selon les PV : pas d'auto-KO/soin à ≥ 70 % PV, pas de setup à ≤ 30 %, moins de statut si la cible est basse. | main.c:6191 |
| `POWERFUL_STATUS` (9) | S | Favorise météo, terrains, Distorsion, hazards, Vent Arrière… même si un KO est possible. | main.c:6354 |
| `NEGATE_UNAWARE` (10) | H | L'IA **ignore** Brise Moule, Ciel Gris/Air Lock, Zone Magique, Embargo… (handicap). | util.c:1830+ |
| `WILL_SUICIDE` (11) | C | Autorise/favorise Explosion, Souvenir, Tout ou Rien (Final Gambit). | main.c:3288, 4265 |
| `PREFER_STATUS_MOVES` (12) | S | +10 à toute capacité de statut qui n'est pas immunisée. À combiner avec `CHECK_BAD_MOVE`. | main.c:4233 |
| `STALL` (13) | C | Préférences « stall » (piégeage, boosts défensifs, Toxik + Abri). **Marqué TODO non fini** dans le header. | util.c:3743, 4762… |
| `SMART_SWITCHING` (14) | C | Active la majorité des heuristiques de switch (§4). Ajoute `SMART_MON_CHOICES`. | switch.c |
| `ACE_POKEMON` (15) | C | Le **dernier** slot n'est envoyé qu'en dernier (sauf Hurlement/U-turn forcé). | switch.c:243 |
| `OMNISCIENT` (16) | K | Connaît moves, talent, objet de tous les Pokémon du joueur (§5). | main.c:577, util.c:202 |
| `SMART_MON_CHOICES` (17) | C | Choix du remplaçant après KO : piégeur gagnant le 1v1 > **revenge killer** > bon matchup + SE > bon matchup > Relais > plus gros dégâts. Après switch volontaire : piégeur > matchup > « pas 3HKO ». | switch.c:2613+ |
| `CONSERVATIVE` (18) | C | Suppose roll **min** en attaque, max en défense ; KO seulement si précision 100. | util.c:111-160, 5258 |
| `SEQUENCE_SWITCHING` (19) | C | Envoie strictement dans l'ordre de l'équipe, **ne switche jamais** volontairement. Idéal tutoriel. | switch.c:1416 |
| `DOUBLE_ACE_POKEMON` (20) | C | Les 2 derniers slots sont des As. | switch.c:249 |
| `WEIGH_ABILITY_PREDICTION` (21) | K | Devine le talent du joueur selon `aiRating` (au lieu d'un tirage uniforme). | util.c:226 |
| `PREFER_HIGHEST_DAMAGE_MOVE` (22) | S | Bonus à l'attaque qui fait le plus de dégâts, sans regarder précision/effets. | main.c:3997, 5939 |
| `PREDICT_SWITCH` (23) | S | Simule si le joueur devrait switcher (50 % de chance de « lire ») → favorise Poursuite, hazards, setup, Coup Bas sur le switch, etc. | main.c:6466 |
| `PREDICT_INCOMING_MON` (24) | C | Si switch prédit, score les capacités contre le Pokémon **entrant** prédit. Ajoute `PREDICT_SWITCH`. | main.c:1124 |
| `PP_STALL_PREVENTION` (25) | S | Détecte le joueur qui switche en boucle sur des immunités ; décote progressivement la capacité absorbée (-20, 50 %/roll). | main.c:6620, 849 |
| `PREDICT_MOVE` (26) | C | Prédit l'attaque du joueur en simulant son propre choix (100 % du temps). Utilisé par switch/absorbeur, Coup Bas, etc. Recommandé avec `OMNISCIENT`. | main.c:392, switch.c:574 |
| `SMART_TERA` (27) | C | Décide intelligemment de Téracristalliser (KO permis, survie, nb de Téra restants). **Singles uniquement** (`IsBattle1v1`). Sans ce flag : Téra **dès le 1er tour**. | util.c:5286 |
| `ASSUME_STAB` (28) | K | Connaît les capacités STAB du joueur (omniscience restreinte). | util.c:210 |
| `ASSUME_STATUS_MOVES` (29) | K | Probabilité de « deviner » les capacités de statut (90/70/40/25 %), + Bluff (Fake Out) et Croc Fatal. | util.c:218 |
| `ATTACKS_PARTNER` (30) | S | Duo : attaque délibérément son partenaire (rivaux qui se détestent, ennemis naturels sauvages). | main.c:6114 |
| `KNOW_OPPONENT_PARTY` (31) | K | Connaît les **espèces** du joueur (team preview), pas leurs sets. | main.c:578 |
| `RANDOMIZE_SWITCHIN` (32) | C | Choisit au hasard parmi les remplaçants éligibles (au lieu du dernier en ordre). | switch.c:2015 |
| `RANDOMIZE_PARTY_INDICES` (33) | C | Mélange l'ordre de l'équipe avant combat (lead aléatoire, **déplace aussi l'As !**). | trainer_pools.c:375 |
| `DYNAMIC_FUNC` (60) | S (auto) | Fonction de score custom posée par `setdynamicaifunc` (voir §8). | main.c:6703 |
| `ROAMING`/`SAFARI`/`FIRST_BATTLE` (61-63) | interne | Fuite des légendaires errants, Safari, combat d'intro. Ne pas mettre à la main. | |

Composites (`battle_ai.h`) :
- `AI_FLAG_BASIC_TRAINER` = `CHECK_BAD_MOVE | TRY_TO_FAINT | CHECK_VIABILITY`
- `AI_FLAG_SMART_TRAINER` = BASIC + `OMNISCIENT | SMART_SWITCHING | SMART_MON_CHOICES | PP_STALL_PREVENTION | SMART_TERA | RANDOMIZE_SWITCHIN`
- `AI_FLAG_PREDICTION` = `PREDICT_SWITCH | PREDICT_INCOMING_MON | PREDICT_MOVE`
- `AI_FLAG_ASSUMPTIONS` = `ASSUME_STAB | ASSUME_STATUS_MOVES | WEIGH_ABILITY_PREDICTION`

> ⚠️ `SMART_TRAINER` **inclut `OMNISCIENT`**. Pour une IA « intelligente mais honnête », écrire les flags à la main (voir §3) en remplaçant `OMNISCIENT` par `Assumptions`.
> ⚠️ La doc `ai_flags.md` mentionne `AI_FLAG_STRONGEST_MOVE` : ce flag **n'existe pas** (remplacé par `PREFER_HIGHEST_DAMAGE_MOVE`).
> ⚠️ `IsAiFlagPresent()` teste **tous** les battlers : en combat tag/multi, un seul dresseur omniscient rend la connaissance globale (`IsAiBattlerAware`).

---

## 3. Combinaisons recommandées par palier d'adversaire

Principe : la difficulté doit venir **d'abord de l'équipe** (synergie, objets, sets), **ensuite** de l'IA ; l'omniscience et la prédiction se gardent pour les sommets. Syntaxe `trainers.party` (cf. §7).

| Palier | Ligne `AI:` recommandée | Intention |
|---|---|---|
| Dresseur de route (early) | `AI: Check Bad Move / Try To Faint` | Pas d'erreurs grossières, joue l'attaque qui tue ; pas de setup « intelligent ». (Le vanilla `Check Bad Move` seul est quasi aléatoire.) |
| Dresseur de route (mid/late) | `AI: Basic Trainer` | Choix de capacité cohérent ; pas de switch. |
| Ace Trainer / Topdresseur, mini-boss | `AI: Basic Trainer / Smart Mon Choices / HP Aware` | Remplaçants pertinents après KO (revenge-kill), ne switche pas volontairement → lisible. |
| Champion d'arène 1-2 (tutoriel) | `AI: Basic Trainer / Sequence Switching / Ace Pokemon` | Ordre fixe, As en dernier : le joueur apprend les types sans surprise. |
| Champion d'arène 3-8 | `AI: Basic Trainer / Smart Switching / Ace Pokemon / HP Aware / Assume Stab` (+ `Smart Tera` si Téra) | Switch raisonné, connaissance « plausible » (STAB) mais pas totale. |
| Rival (combats successifs) | `AI: Basic Trainer / Smart Switching / Ace Pokemon / Know Opponent Party / Assumptions / Smart Tera` | Le rival « connaît » votre équipe (lore) mais pas vos sets. |
| Admin d'organisation | `AI: Basic Trainer / Smart Switching / Powerful Status / Ace Pokemon / Assumptions` (+ `Risky` pour un admin brutal, `Will Suicide` pour un kamikaze) | Personnalité : terrain/météo/hazards appuyés. |
| Chef d'organisation | `AI: Smart Trainer / Ace Pokemon / Predict Switch` | Premier contact avec l'omniscience : compenser par des tells (dialogues). |
| Conseil 4 | `AI: Smart Trainer / Ace Pokemon / HP Aware / Prediction` | IA maximale, équipes compétitives. |
| Maître | `AI: Smart Trainer / Prediction / Weigh Ability Prediction / Ace Pokemon / HP Aware` | Plafond de l'IA. |
| Post-game / revanches | `AI: Smart Trainer / Prediction / Assumptions / Randomize Party Indices` (sans `Ace` si on randomise) | Rejouabilité (lead variable) + pools (`Party Size`). |
| Combat « gimmick » | ajouter `Force Setup First Turn`, `Prefer Baton Pass`, `Stall`, `Prefer Status Moves`, `Attacks Partner` selon le thème | Toujours garder `Check Bad Move`. |

Réglages fins : `Conservative` pour une IA prudente (Pokémon « sage »), `Risky` pour un personnage téméraire ; ne pas cumuler les deux (ils s'annulent dans `AI_GetDamage`). Éviter `Negate Unaware` (handicap) sauf personnage volontairement naïf.

---

## 4. Logique de switch (vérifiée dans `ShouldSwitch`, `battle_ai_switch.c:1396`)

Pré-conditions : pas piégé (Étreinte, Regard Noir, Racines, talents piégeurs, Commandant), pas `SEQUENCE_SWITCHING`, au moins un remplaçant éligible (les As sont exclus).
Ordre d'évaluation (le premier vrai gagne) — **(SS)** = nécessite `SMART_SWITCHING` :

1. Fonction dynamique (`setdynamicswitchaifunc`) — 50 % (`SHOULD_SWITCH_DYN_FUNC_PERCENTAGE`).
2. `ShouldSwitchIfWonderGuard` — **sans SS** : ne peut pas toucher Garde Mystik → 100 %.
3. (SS) Ne switche pas si le Pokémon mourrait aux hazards en revenant et qu'aucun anti-hazard n'est dans l'équipe.
4. (SS) Piégeur dans l'équipe qui gagne le 1v1 → 100 %.
5. (SS) Absorbeur de l'attaque attendue (Absorb Eau, Paratonnerre…) → 100 % (66 % de rester si on a un SE).
6. (SS) Adversaire en charge/invulnérable (Vol, Tunnel) → switch gratuit (singles).
7. `Truant` (Absentéisme) → 100 %.
8. `AllMovesBad` : aucune capacité n'affecte la cible → 100 %.
9. Mauvais statuts : Requiem (100 %), Bâillement (100 %), Toxik (50 %), Malédiction (50 %), Cauchemar (33 %), Vampigraine (25 %), Attraction (100 %) — taux réduits si boosts.
10. (SS) Talents bénéfiques : Médic Nature, Régé-Force (50 %), Intimidation (25 %).
11. (SS) Passer un Vœu.
12. (SS) **Mauvaises chances** (`HasBadOdds`, 50 %) : mauvais matchup sans SE et PV ≥ 50 %, ou perd le 1v1 vite.
13. (SS) Encore sur statut (100 %) / attaque (50 %).
14. (SS) Verrouillé Choix sur une capacité de statut (100 %).
15. (SS) Stat offensive à -2 (50 %) / -3 ou pire (100 %).
16. (SS) Perd le 1v1 — **0 % par défaut** (`SHOULD_SWITCH_LOSES_1V1_PERCENTAGE`).

Après KO : `GetMostSuitableMonToSwitchInto` (`SMART_MON_CHOICES`) ; sinon le dernier Pokémon valide en ordre inverse (comportement vanilla « mon suivant »). `RISKY` traite les switches mid-battle comme des switches après KO (offensifs).
Tous les pourcentages sont dans `include/config/ai.h` — **levier de difficulté sans toucher au code**.

## 5. Connaissance du joueur (omniscience) et prédiction

- **Par défaut** : l'IA lit `gBattleHistory` — capacités déjà utilisées par chaque Pokémon, talent et objet une fois révélés ; le talent non révélé est deviné (uniforme, ou pondéré avec `WEIGH_ABILITY_PREDICTION`). Les espèces non encore vues sont inconnues.
- `OMNISCIENT` : `Ai_InitPartyStruct` copie au début du combat moves/talent/objet/espèce de toute l'équipe du joueur. `SMART_SWITCHING_OMNISCIENT` (FALSE) peut donner l'omniscience aux seuls calculs de switch.
- `KNOW_OPPONENT_PARTY` : espèces + état KO seulement (≈ team preview).
- `ASSUME_STAB` / `ASSUME_STATUS_MOVES` : omniscience partielle probabiliste (réglages `ASSUME_*` dans ai.h).
- **Prédiction** : l'IA rejoue *sa propre* logique pour le joueur (`SetupAIPredictionData`). Switch prédit 50 % du temps, attaque prédite 100 % du temps si le flag est présent. Qualité dépendante de l'information disponible → prédiction sans omniscience = devinettes sur les capacités vues.
- Coup Bas : 50 % de ne pas l'utiliser si le joueur a un statut (`SUCKER_PUNCH_CHANCE`).

## 6. Objets, gimmicks, combats doubles

### Objets de dresseur (`src/battle_ai_items.c`)
- Jusqu'à **4** objets (`MAX_TRAINER_ITEMS`), champ `Items:`. Uniquement en combat dresseur (pas Frontier/link/partenaire).
- Utilisation : soin PV (si PV < 25 % ou manque > soin, et que le soin évite le KO ; ou soin > 2× dégâts max ; ou dernier Pokémon), soin statut, X-objets (tour 1 si `FORCE_SETUP_FIRST_TURN`), Muscle +/Focus, Brume (Garde Spéciale), **Rappel** (ranime le premier KO), Poké Flûte. Jamais si l'IA prévoit de KO ce tour. Un objet consomme l'action.
- Objets **tenus** : effets gérés par le moteur ; l'IA les prend en compte dans les calcs (Choix → `AI_DoesChoiceEffectBlockMove`, baies de résistance `AI_DAMAGES_THROUGH_BERRIES`, Ceinture Force/Multiécaille → pivot 50 %). `B_TRAINERS_KNOCK_OFF_ITEMS TRUE` : les dresseurs peuvent voler/échanger les objets du joueur (restitués après combat sauf baies).

### Gimmicks
| Gimmick | Comment l'activer pour un dresseur | Comportement IA |
|---|---|---|
| Méga | Tenir la Méga-Gemme (`@ Gardevoirite`). Pas de Méga-Anneau requis côté IA (`CanMegaEvolve`, battle_util.c:8471). 1 par dresseur. | **Dès le premier tour** où le Pokémon agit (pas de reconsidération). |
| Z-Move | Tenir le Cristal Z + capacité du bon type. | Uniquement si viable et si l'attaque normale ne KO pas (`ShouldUseZMove`, util.c:5088). |
| Dynamax | `Dynamax Level: N` ou `Gigantamax: Yes` dans le set (positionne `shouldDynamax`). `B_FLAG_DYNAMAX_BATTLE` ne conditionne **que le joueur**. | Dès que possible. |
| Téra | `Tera Type: X` (positionne `shouldTerastal`). | Sans `SMART_TERA` : Téra au **premier tour**, sauf si l'action choisie est Abri. Avec `SMART_TERA` : calcul offensif/défensif, 10 %×(n-1) de garder la Téra, singles uniquement. |

### Double combat
- `DOUBLE_BATTLE` auto. `ChooseMoveOrAction_Doubles` score chaque cible séparément, tient compte du coup de l'allié (`partnerMove`), du friendly fire (seuils 2/3/4 coups selon Risky/normal/Conservative), redirection, Fake Out, Protect + Trick Room/Tailwind en fin de Distorsion (35 %).
- `SMART_TERA` **inactif en double**. `AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE` 50 % pour éviter un biais de slot.
- Multi (2 dresseurs) : `Multi Party: Half` → 3 Pokémon chacun ; `DOUBLE_ACE_POKEMON` pour les duos (Jumelles, Lévy & Tatia).

## 7. Syntaxe des flags et des équipes (`src/data/trainers.party`)

```
=== TRAINER_EXEMPLE_BOSS ===
Name: NOM
Class: Leader
Pic: Leader Roxanne
Gender: Female
Music: Female
Items: Hyper Potion / Hyper Potion
Battle Type: Singles            (ou Doubles ; ancien alias "Double Battle: No/Yes")
Difficulty: Hard                (optionnel, voir §9.4 ; défaut Normal)
AI: Basic Trainer / Smart Switching / Ace Pokemon / Assume Stab
Mugshot: Purple                 (optionnel)
Party Size: 4                   (optionnel : active les pools si < nb de Pokémon)

Nickname (Tyranitar) (M) @ Leftovers
Level: 42
Ability: Sand Stream
IVs: 31 HP / 31 Atk / 31 Def / 31 SpA / 31 SpD / 31 Spe     (défaut : 31 partout)
EVs: 252 HP / 252 Atk / 4 SpD                              (défaut : 0)
Adamant Nature                                            (ou "Nature: Adamant")
Tera Type: Rock                                           (active la Téra pour ce Pokémon)
Tags: Lead / Weather Setter                               (pools)
- Stone Edge
- Crunch
- Stealth Rock
- Earthquake
```
- Flags : nom sans `AI_FLAG_`, séparés par `/`, casse et espaces libres (`Smart Switching` = `SMART_SWITCHING`). Conversion : `tools/trainerproc/main.c`, `fprint_constant` (non-alphanum → `_`, apostrophe supprimée).
- Sans ligne de capacités → les 4 dernières apprises par niveau.
- **Talent illégal pour l'espèce = `assertf` au runtime** (`battle_main.c:1941`) → à valider (outil `tools/qa/validate_trainers.py`).
- Pas de champ « Mega » : la Méga passe par l'objet tenu.

## 8. Fonctions IA dynamiques (boss sur mesure)
- `setdynamicaifunc <Fonction>` avant le `trainerbattle` → ajoute `AI_FLAG_DYNAMIC_FUNC` pour **ce combat** (effacé après). Modèle : `AI_TagBattlePreferFoe` (main.c:6682).
- `setdynamicswitchaifunc <Fonction>` → logique de switch custom (modèle `ShouldSwitchDynFuncExample`, switch.c:1279), appliquée à 50 %.
- Idéal pour des « patterns de boss » scénarisés (ex. le boss utilise Danse Pluie tous les 5 tours, ou garde son As derrière un Pokémon précis) **sans** toucher l'IA globale. Nécessite du C → passage par l'agent Engine/Code.

## 9. Configuration affectant la difficulté

### 9.1 Caps de niveau (`include/config/caps.h`) — **désactivés**
- `B_EXP_CAP_TYPE` : `EXP_CAP_NONE` (actuel) / `EXP_CAP_HARD` (0 XP au-delà du cap) / `EXP_CAP_SOFT` (XP réduite).
- `B_LEVEL_CAP_TYPE` : `LEVEL_CAP_NONE` (actuel) / `LEVEL_CAP_FLAG_LIST` (table `sLevelCapFlagMap` dans `src/caps.c` : 15/19/24/29/31/33/42/46/58 par badge) / `LEVEL_CAP_VARIABLE` (var `B_LEVEL_CAP_VARIABLE`).
- `B_RARE_CANDY_CAP`, `B_LEVEL_CAP_EXP_UP` (rattrapage sous le cap) : FALSE.
- EV caps : `B_EV_CAP_TYPE EV_CAP_NONE` (`EV_CAP_NO_GAIN` possible, à la Run & Bun).

### 9.2 Expérience
- `B_SPLIT_EXP` Gen6+ (chaque participant reçoit l'XP complète), `B_SCALED_EXP` Gen5/7+ (pondérée par l'écart de niveau — freine naturellement le sur-niveau), `B_EXP_CATCH` Gen6+, `B_TRAINER_EXP_MULTIPLIER` Gen7+ (pas de ×1,5).
- `I_EXP_SHARE_FLAG 0` / `I_EXP_SHARE_ITEM GEN_5` : Multi Exp. **objet tenu** façon Gen5 ; pour un Multi Exp. global (Gen6+), définir un flag.

### 9.3 Style de combat, sac, divers
- Style par défaut : **Shift** (`src/new_game.c:105`, `OPTIONS_BATTLE_STYLE_SHIFT`) modifiable dans les Options. Pas de config pour **forcer** Set : il faut soit changer le défaut, soit verrouiller l'option (code). Les hacks difficiles imposent Set.
- `B_VAR_NO_BAG_USE 0` : à pointer vers une var (1 = pas de sac contre dresseurs, 2 = jamais) — équivalent « pas d'objets en combat ».
- `B_FLAG_NO_WHITEOUT`, `B_RUN_TRAINER_BATTLE TRUE` (fuir un dresseur = défaite), `B_FLAG_SLEEP_CLAUSE`/`B_SLEEP_CLAUSE` (l'IA la respecte avec `CHECK_BAD_MOVE`), `B_FLAG_INVERSE_BATTLE`, `B_FLAG_SKY_BATTLE`, `B_FLAG_DYNAMAX_BATTLE`, `B_FLAG_TERA_ORB_*`, `B_FLAG_AI_VS_AI_BATTLE` (utile pour tester un boss en auto !).
- Badges : `B_BADGE_BOOST GEN_LATEST` → aucun bonus de stats (les `B_FLAG_BADGE_BOOST_*` n'agissent qu'en `GEN_3`).
- `B_SHOW_EFFECTIVENESS SHOW_EFFECTIVENESS_SEEN`, `B_SHOW_TYPES SHOW_TYPES_NEVER`, `B_SHOW_MOVE_DESCRIPTION TRUE` : aides à la lisibilité (fair-play).
- `B_TRAINER_MON_RANDOM_ABILITY FALSE` : sans `Ability:`, le talent est le slot 0 → **toujours préciser le talent des boss**.

### 9.4 Système de difficulté natif
- `include/constants/difficulty.h` : `DIFFICULTY_EASY`, `DIFFICULTY_NORMAL`, `DIFFICULTY_HARD`.
- Activation : `B_VAR_DIFFICULTY` → une var libre (actuellement 0 = toujours Normal). Macros de script : `setdifficulty`, `getdifficulty`, `increasedifficulty`, `decreasedifficulty` (`asm/macros/event.inc:2595+`), à appeler **après** `NewGameInitData`.
- Données : on déclare plusieurs fois le même `=== TRAINER_X ===` avec `Difficulty: Easy` / `Hard`. `GetTrainerDifficultyLevel` retombe sur Normal si la version demandée n'existe pas → on n'écrit que les boss concernés. Fonctionne aussi pour les partenaires.
- Chaque variante peut avoir **ses propres flags IA, objets, niveaux et sets** → base idéale pour un mode Facile/Normal/Difficile.

### 9.5 Pools d'équipe
- `Party Size: N` < nb de Pokémon → tirage parmi un pool, règles `Pool Rules` (`POOL_RULESET_BASIC`, `_DOUBLES`, `_WEATHER_SINGLES`…), tags `Lead`/`Ace`/`Weather Setter`/`Weather Abuser`/`Support`. Utile pour revanches/post-game.

## 10. Faiblesses connues / exploitables de l'IA

1. **Dresseurs `Check Bad Move` seul** : choix aléatoire entre attaques « non mauvaises » → trivial.
2. **Pas de vision multi-tours** : l'IA optimise le tour courant (sauf heuristiques de setup) ; pas de planification de sweep sur plusieurs Pokémon.
3. **Roll max en attaque** : tente des KO « limites » qui ratent ; le joueur peut tanker avec un Pokémon à PV justes.
4. **Sans omniscience** : se fait piéger par des capacités jamais montrées (Coup Bas, Abri, Vampigraine, Focus Sash du joueur).
5. **Switch volontairement imparfait** (50 % sur mauvais matchup) ; « perd le 1v1 » désactivé → un boss peut rester face à un counter.
6. **Gimmicks immédiats** : Méga/Dynamax tour 1, Téra tour 1 sans `SMART_TERA` → le joueur peut anticiper (et c'est souhaitable pour le fair-play).
7. **`SMART_TERA` absent en double**.
8. **`STALL` inachevé**.
9. **As + `RANDOMIZE_PARTY_INDICES`** : l'As change de slot → incompatible.
10. **Prédiction = miroir de sa propre logique** : un joueur qui fait le coup « sous-optimal » attendu par aucun calcul (double switch, sacrifice) déjoue la prédiction.
11. **PP stall** : contourné sans `PP_STALL_PREVENTION`.
12. **Objets** : un boss avec 4 Potions et un joueur qui chip-damage proprement → combat long et frustrant (le soin est fait quand il évite le KO).
13. **Tag/multi** : la connaissance (omniscience) est partagée entre tous les battlers IA.

## 11. Recommandations immédiates
- Créer un tableau `docs/hack/trainer_ai_matrix` (palier → flags) et l'appliquer à tous les dresseurs du hack.
- Activer `B_VAR_DIFFICULTY` (var dédiée) dès maintenant, même si seul Normal est rempli.
- Décider caps (soft cap + `B_LEVEL_CAP_EXP_UP` recommandé) et Multi Exp. global.
- Exiger `Ability:` et `Nature`/`EVs` explicites pour tout boss ; passer `tools/qa/validate_trainers.py --learnsets` en CI locale avant chaque PR.
- Tester chaque boss en `B_FLAG_AI_VS_AI_BATTLE` + debug menu (`DEBUG_TRAINER_AI` a déjà `Smart Trainer`) et via le système de tests (`docs/tutorials/how_to_testing_system.md`, `AI_SINGLE_BATTLE_TEST`).
