# Manuel de design des combats majeurs — recherche stratégique

> Rôle : Competitive Strategy & Battle AI. Public : designers de dresseurs/boss du hack.
> Complément de `docs/hack/AI_AUDIT.md` (ce que l'IA sait faire) : ici, **quoi lui donner à jouer**.
> Sources : concepts du jeu compétitif (Smogon Strategy Dex, guides de teambuilding Showdown, ressources VGC),
> retours de communautés de hacks de difficulté (liste en fin de document). Note méthodo : smogon.com,
> pokecommunity.com et le wiki Radical Red étaient injoignables en fetch direct depuis l'environnement ;
> les points sur les hacks viennent de résultats de recherche et de synthèses secondaires (fiabilité moyenne, à
> recouper par playtest). Les concepts compétitifs sont des savoirs stables de la scène (Gen 4-9).

---

## 1. Rôles stratégiques (vocabulaire commun de l'équipe)

| Rôle | Définition | Exemples (expansion) | Ce que le rôle enseigne au joueur | Flags IA utiles |
|---|---|---|---|---|
| **Wallbreaker** | Puissance brute pour percer les Pokémon défensifs ; souvent Choix/Orbe Vie, couverture large. | Mackogneur (Cran), Dracolosse Lunettes Choix, Hydragla, Grodrake | Ne pas compter sur un seul mur ; gérer la menace par vitesse/KO. | `Try To Faint`, `Prefer Highest Damage Move` |
| **Sweeper (setup)** | Se boost (Danse Lames, Danse Draco, Plénitude, Machination) puis balaie. | Dracolosse (Danse Draco), Léviator, Tyranocif, Mélofée | Punir le setup : statut, phazing, priorité, Coup Critique, Hâte. | `Check Viability` (setup intelligent) ; `Force Setup First Turn` pour un boss « signalé » |
| **Pivot** | Entre, encaisse, ressort avec Demi-Tour/Change Éclair/Volte-Face/Téléport/Queue Ardente en gardant l'élan. | Corvaillus, Amphinobi, Motisma, Tauros-Paldea | Le momentum ; anticiper l'entrée suivante. | `Smart Switching`, `Smart Mon Choices` |
| **Hazard setter** | Pose Piège de Roc, Picots, Pics Toxik, Toile Gluante dès le début. | Airmure, Grodoudou, Forteresse, Ferrothorn (Noacier), Hippodocus | Coût des switches, Grosse Bottes, Tour Rapide/Anti-Brume. | `Powerful Status` |
| **Hazard control** | Tour Rapide / Anti-Brume / Ravage Rapide / Magie Miroir. | Corvaillus (Anti-Brume), Mélodelfe (Magic Guard), Cizayox | Gérer l'usure de son équipe. | — |
| **Cleric / support** | Glas de Soin, Aromathérapie, Vœu, écrans, Soin Mouluvant. | Leuphorie, Lanssorien, Florges, Akwakwak | Gestion du statut/temps. | `HP Aware` |
| **Wall** (physique/spécial) | Encaisse un type d'attaque, récupère (Soin, Repos, Restes), use (Toxik, Feu Follet). | Airmure, Leuphorie, Ecremeuh, Toxiquak, Clefable/Mélodelfe | Wallbreaking, Provoc, Toxik/Brûlure, couverture. | `Stall` (inachevé) + `Check Bad Move` |
| **Revenge killer** | Rapide (Mouchoir Choix) ou priorité ; arrive après un KO pour achever. | Dracaufeu Mouchoir, Lucario (Vitesse Extrême), Tranchodon, Hydragla | Garder des PV/de la vitesse ; ne pas surboosser imprudemment. | `Smart Mon Choices` (choisit explicitement le revenge killer) |
| **Weather setter / abuser** | Talent ou capacité de météo + bénéficiaires (Chlorophylle, Glissade, Baigne Sable, Synthèse Énergétique). | Tyranocif/Hippodocus + Carchacrok/Dracolosse ; Kyogre-like : Pélipper + Dracolosse Glissade | Contrôle météo, déclencheurs, contre-météo. | `Powerful Status`, pools `Weather Setter/Abuser` |
| **Terrain setter** | Créa-Électrique/Psychique/Herbu/Brumeux (Tapu-like, Pachirisu…). | Tokorico, Plumeline (rare), Rillaboom (Herbe) | Les terrains changent priorités/types. | idem |
| **Trick Room** | Distorsion + Pokémon lents et forts. | Mucuscule/Golemastoc + Rhinastoc, Granivol, Mysdibule, Ursaking-Lune | Gérer l'inversion de vitesse (attendre 5 tours, Provoc, KO du setter). | `Powerful Status`, `Double Battle` (Trick Room recast 35 %) |
| **Lead / suicide lead** | Ouvre le combat : Bluff, hazards + Ceinture Force, Explosion. | Forteresse, Galekid Ceinture Force, Zoroark Illusion | Lead adapté, Provoc. | `Will Suicide`, ordre de party fixe |
| **Trapper** | Piège (Marque Ombre, Piège Sable, Prise Ferraille) pour éliminer une cible clé. | Gothitelle, Triopikeur, Magnézone | Garder un échappatoire (U-turn, Ghost). | `Smart Switching` choisit le piégeur gagnant le 1v1 |

**Check vs Counter** : un *counter* entre sans crainte et gagne le 1v1 ; un *check* gagne s'il est déjà sur le terrain. Un boss juste offre au joueur au moins **2 checks accessibles** par menace majeure.

## 2. Cores (synergies défensives/offensives)

| Core | Pourquoi ça marche | Usage boss conseillé |
|---|---|---|
| **Feu / Eau / Plante** | Chaque type couvre les faiblesses d'un autre ; première leçon de complémentarité. | Arène 1-2 du rival, équipe « équilibrée » du rival. |
| **Dragon / Acier / Fée** | Acier encaisse Fée/Dragon, Fée bloque Dragon, Dragon résiste Eau/Feu/Plante/Élec. | Conseil 4 / Maître. |
| **Combat / Spectre** (« coverage core ») | Couverture neutre quasi parfaite (seuls quelques Pokémon résistent). | Wallbreaker de boss : Lucario + Ectoplasma, Mackogneur + Pharamp. |
| **Sol / Vol** (Earthquake/Air) | Immunités mutuelles Sol↔Électrique/Vol. | Duo de double combat (Séisme sans toucher l'allié Vol). |
| **Eau / Sol** (« Swampert core ») + Acier | Une seule faiblesse (Plante) ; avec Acier, ensemble très solide. | Admin d'organisation aquatique. |
| **Fantôme / Normal** (immunités croisées) | Bloque Combat et Spectre. | Combat « gimmick » défensif. |
| **Régé-Force pivot core** (Amphinobi, Ecremeuh, Corvaillus) | Usure du joueur via switches gratuits. | Post-game ; nécessite `Smart Switching`. |
| **Volt-Turn** (Change Éclair + Demi-Tour) | Momentum continu, punit les switches. | Chef d'organisation ; avec `Predict Switch`. |

## 3. Météo, terrains, hazards, priorité, pivots, setup

### Météo
- **Soleil** (Sécheresse) : Chlorophylle, Synthèse Énergétique Proto, Lance-Soleil sans charge, Feu ×1,5, Eau ×0,5. Contre : Roc, Eau puissante, changer la météo.
- **Pluie** (Crachin) : Glissade, Fatal-Foudre/Vent Violent 100 %, Eau ×1,5. Contre : Plante, Élec résistants, Absorb Eau.
- **Sable** (Sable Volant) : +50 % Déf. Spé. Roche, Baigne Sable, Force Sable, dégâts résiduels. Contre : Eau/Plante/Combat, Lunettes Filtre.
- **Neige** (Alerte Neige, Gen 9) : +50 % Déf. Glace, Blizzard 100 %, Voile Aurore. Contre : Feu/Combat/Acier/Roche.
- Règle de design : 1 setter + 2 abusers ; le setter doit pouvoir revenir (pivot) ou l'équipe doit avoir un plan B. Expansion gère les durées Gen 6+ (5 tours, 8 avec roche) : **le joueur peut attendre** → contre-jeu naturel.

### Terrains
Électrique (pas de Sommeil, Élec ×1,3), Psychique (bloque la priorité sur les Pokémon au sol), Herbu (soins, Séisme réduit), Brumeux (pas de statut, Dragon ×0,5). Très forts en double.

### Hazards
Piège de Roc (1/8 neutre → 1/2 pour ×4 Roche), Picots (3 couches), Pics Toxik, Toile Gluante. Contre-jeu : Tour Rapide, Anti-Brume, Grosses Bottes, Magie Miroir. **Ne pas introduire les hazards avant que le joueur puisse obtenir un outil de contrôle** (CT Anti-Brume / Tour Rapide ou un Pokémon qui l'apprend).

### Priorité
Vitesse Extrême, Pisto-Poing, Aqua-Jet, Coup Bas, Éclats Glace, Ombre Portée, Poing Ombre, Bluff (Fake Out tour 1), Prankster sur statut, Gale Wings. L'IA (`Try To Faint`) utilise la priorité quand elle est plus lente et va mourir — c'est le principal outil de « revenge kill » IA.

### Pivots
Demi-Tour, Change Éclair, Volte-Face, Queue Ardente (Gen 9 « Chilly Reception »), Téléport (Gen 8+), Relais, Rafale Psy… Avec `Smart Mon Choices`, l'IA choisit le meilleur entrant après pivot.

### Setup
Danse Lames, Danse Draco, Plénitude, Machination, Gonflette, Exuviation, Ceinture Ventre, Coquilame, Victory Dance… L'IA avec `Check Viability` setup « quand c'est sûr » (ne pas mourir au roll max défensif). Un boss setup **doit** laisser un tell : 1er tour visible, objet visible (Herbe Blanche), message d'avant-combat.

### Speed control
Vent Arrière, Distorsion, Cage-Éclair/Paralysie, Toile, Icy Wind/Electroweb (double), Mouchoir Choix. À enseigner au milieu du jeu.

## 4. Téracristal (si activé)
- Téra **défensive** (retourner un matchup : Dracolosse Téra Normal + Multiécaille) ou **offensive** (Téra STAB : Téra Feu sur un Pokémon Feu → ×2).
- Téra Blast pour couverture surprise (universal move, cf. `special_movesets.json`).
- Design : **un seul Téra par dresseur** (règle moteur) et rendre le type Téra **visible** (dialogue, design du personnage, objet thématique). Sans `Smart Tera`, l'IA Téra au tour 1 : excellent pour les boss early-Téra (lisible) ; avec `Smart Tera`, réservé aux sommets (singles).

## 5. Objets — quand et pourquoi

| Objet | Rôle | Remarque design |
|---|---|---|
| **Bandeau / Lunettes / Mouchoir Choix** | Puissance ou vitesse ×1,5 verrouillée | L'IA gère le verrouillage (switch si bloquée sur statut). Le joueur exploite le lock → leçon. |
| **Orbe Vie** | ×1,3, -10 % PV par attaque | Bon pour wallbreakers ; usure visible. |
| **Restes / Boue Noire** | 1/16 PV/tour | Murs, Abri+Toxik. |
| **Ceinture Force (Focus Sash)** | Survit à 1 PV depuis full | Leads ; frustrant si cumulé avec Fermeté → max 1 par équipe. L'IA pivote 50 % pour casser une Sash du joueur. |
| **Baies** : Sitrus, baies de résistance (Chiaz…), Prine (statut), baies « pinch » (Lansat/Salac/Liechi) | Survie, contre-mesure ciblée | `AI_DAMAGES_THROUGH_BERRIES` : l'IA voit à travers les baies de résistance pour un 2HKO. |
| **Veste de Combat (Assault Vest)** | Déf. Spé. ×1,5, pas de statut | Murs spéciaux offensifs. |
| **Évoluroc (Eviolite)** | Déf/Déf. Spé. ×1,5 pour non évolués | Boss early très crédibles (Ponchiot/Cradopaud/Porygon2). |
| **Vulné-Assurance (Weakness Policy)** | +2/+2 si touché super efficace | Excellent « piège pédagogique » : enseigne à ne pas taper SE à l'aveugle. Le signaler. |
| **Énergie Booster** | Active Paléo-/Neurocharge | Pokémon Paradoxe post-game. |
| **Herbe Blanche / Mental** | Annule baisses / bloque Provoc-Encore | Setups (Coquilame). |
| **Grosses Bottes** | Immunité hazards | Late game, quand le joueur a des hazards. |
| **Casque Brut / Roche Royale / Griffe Rasoir** | Dégâts de contact / flinch | Éviter les sources de RNG pure (Roche Royale) en boss → frustration. |
| **Méga-Gemmes / Cristaux Z** | Gimmicks | 1 par dresseur ; la Méga arrive au premier tour → tell gratuit. |

Objets **de dresseur** (sac) : jusqu'à 4 ; règle maison proposée : 0 en route, 1-2 Potions early, 2 Super/Hyper Potions arène, 2 Guérison/Rappel au Conseil 4 ; **0 en mode « Set + sans objets »** si on reprend les règles hardcore.

## 6. Talents structurants
Intimidation (pivot anti-physique ; l'IA switche pour la réutiliser 25 %), Régé-Force (pivot ; 50 %), Sécheresse/Crachin/Sable Volant/Alerte Neige (météo), Créa-* (terrains), Multiécaille/Fermeté (survie garantie), Magie Miroir (anti-hazards/statut), Garde Magik, Moiteur, Brise Moule (ignore talents ; l'IA le comprend sauf `Negate Unaware`), Absentéisme, Pression, Lévitation, Absorb Eau/Volt/Paratonnerre/Lavabo (l'IA switche dessus avec `Smart Switching`), Technicien, Adaptabilité, Prankster, Cuvette, Phobique. Rappel moteur : **le talent doit appartenir à l'espèce** sinon `assertf`.

## 7. Courbe d'apprentissage : une compétence par boss

| Étape | Combat | Leçon visée | Outils adverses | Outils fournis au joueur avant |
|---|---|---|---|---|
| 1 | Arène 1 | Types / STAB | 3 Pokémon mono-type, `Sequence Switching` | Starter + 2 captures complémentaires |
| 2 | Rival 1-2 | Équipe équilibrée, choix de lead | Feu/Eau/Plante | Objets de soin, PC |
| 3 | Arène 2 | Statut & baisses de stats | Toxik, Cage-Éclair, Rugissement | Baies anti-statut, Total Soin |
| 4 | Admin 1 | Setup adverse + punition | 1 sweeper avec tell (Danse Lames tour 1) | Hurlement/Dévorêve/Provoc, Pokémon rapide |
| 5 | Arène 3-4 | Météo (setter + abuser) | Sable ou Pluie | Pokémon qui change la météo ou résiste |
| 6 | Arène 5 | Hazards & switching | Piège de Roc + phazing | Anti-Brume/Tour Rapide accessible juste avant |
| 7 | Rival 3 | Pivot / momentum, connaissance de votre équipe | `Know Opponent Party`, Demi-Tour | CT Demi-Tour/Change Éclair |
| 8 | Arène 6-7 | Speed control (Vent Arrière / Distorsion) | Trick Room team | Pokémon lents, Provoc |
| 9 | Chef d'organisation | Gimmick (Méga/Téra) + ancienne leçon combinée | `Smart Trainer` | Méga-Anneau/Orbe Téra obtenu avant |
| 10 | Arène 8 | Double combat | Synergie duo (Bluff, redirection) | Double combats de route préalables |
| 11 | Conseil 4 | Synthèse : 1 thème + 1 mécanique chacun | IA max, équipes compétitives | Tuteurs, Mentali (Nature), EV reset |
| 12 | Maître | Toutes leçons, plusieurs plans de victoire | `Smart Trainer / Prediction` | — |
| Post | Revanches | Optimisation, variance | Pools + `Randomize Party Indices` | Accès complet aux sets |

Règle d'or : **introduire une mécanique dans un combat mineur (route/mini-boss) avant de la poser en examen** sur un boss.

## 8. Équité (fair-play) — garde-fous

1. **Pas d'abus de niveau** : écart boss / cap ≤ +2 niveaux (ace +3 max). La difficulté vient des sets, pas de +10 niveaux. Les hacks critiqués pour leurs pics de niveau (« level spikes ») sont perçus comme « fake difficulty ».
2. **Tells visibles** : dialogue avant combat qui annonce le thème ; objet ou talent visible (`B_SHOW_EFFECTIVENESS`) ; Méga/Téra au tour 1 ; panneaux/PNJ indiquant l'équipe (Run & Bun et Radical Red publient des docs complètes des équipes ; joueurs Nuzlocke s'en servent).
3. **Contre-jeu garanti** : pour chaque menace, ≥ 2 réponses obtenables avant le combat (captures, CT, tuteurs) ; vérifier dans `wild_encounters.json`/CT.
4. **RNG limitée** : éviter combos Lilliput/Reflet + Ordre de précision faible, Roche Royale + Sérénité, OHKO moves, Hypnose spam sur un boss ; respecter Sleep Clause (`B_FLAG_SLEEP_CLAUSE`) en boss.
5. **Omniscience mesurée** : réservée aux sommets ou justifiée par le lore ; sinon `Assumptions`.
6. **Soins du joueur** : soigner l'équipe avant les boss (Run & Bun soigne avant chaque champion) ou point de soin proche.
7. **Pas de « double gimmick »** (Téra + Méga + météo + Sash) avant le Conseil.
8. **Tester sans connaissance préalable** puis avec ; viser ≤ 3 tentatives pour un joueur moyen en Normal.

## 9. Ce que font les hacks de difficulté (retours communautaires)

| Hack | Approche boss / caps | Ce qui est loué | Ce qui est critiqué |
|---|---|---|---|
| **Radical Red** (FRLG, CFRU) | Mode Hardcore : style Set forcé, pas d'objets en combat, caps de niveau stricts, équipes de boss plus fortes ; caps ≈ niveau max du prochain boss (ex. 16/23/28/36 en Hardcore vs 15/22/27/34 en Normal) ; météo/terrain IA permanents en Hardcore. | Échecs perçus comme « les vôtres » : corrigeables en changeant d'équipe ou de sets ; nombreux outils (tuteurs, EV, natures). | Style « VGC » qui exige une équipe différente par boss ; impression d'une IA qui « sait ce que vous faites » ; nécessité de lire la doc/calculer. |
| **Run & Bun** (Emerald) | Caps codés par boss, **aucun EV** (ni joueur ni IA), soin avant champions, Set forcé et sac interdit en dresseur ; IA custom **documentée** (document de scoring public), calculateur dédié. | Transparence (doc IA + calc) ; switch-in IA qui privilégie vitesse et dégâts. | Caps jugés trop durs tôt (« Lv 12 comme premier cap ») ; bugs IA corrigés au fil des patchs (boost de vitesse inutile, Distorsion mal utilisée). |
| **Emerald Kaizo** | Courbe de niveaux très raide (Tate & Liza ~70, Ligue 100), équipes optimisées avec objets. | Défi extrême, maîtrise du jeu. | Grind et niveaux démesurés → « fake difficulty » pour beaucoup. |
| **Elite Redux** (Emerald) | Jusqu'à 3 talents innés + talents changeables, chaque équipe refaite à la main ; volonté « difficile sans trop d'avantages injustes » ; mode Facile. | Renouvelle des Pokémon délaissés. | Lisibilité : beaucoup d'informations cachées (innés). |
| **Inclement Emerald** (decomp) | Hack « Hard » à IA améliorée, patchs IA réguliers (talents Voile, Dazzling en double). | Défi équilibré, modernité. | Bugs IA en double au lancement. |
| **Unbound** (FR, CFRU) | Modes (Vanilla/Difficult/Expert/Insane) ; niveaux **dynamiques** : boss alignés sur votre Pokémon le plus haut, dresseurs sur le plus bas ; Insane : pas d'objets en combat, boss EV-trained compétitifs ; caps par mode. | Une bonne équipe peut porter toute l'aventure (moins de « team rebuild »). | Scaling dynamique = moins de sentiment de progression. |

**Leçons pour notre hack** :
1. Offrir des **modes** (le moteur a `Difficulty:`) plutôt qu'une difficulté unique ; le mode Difficile = Set forcé (option), sac interdit en boss (`B_VAR_NO_BAG_USE`), caps durs.
2. **Caps souples** en Normal (`EXP_CAP_SOFT` + `B_LEVEL_CAP_EXP_UP`) ; caps durs en Difficile ; cap = niveau de l'As du prochain boss.
3. **Publier** (in-game ou doc) les équipes des boss majeurs → l'IA forte devient un puzzle, pas une injustice.
4. Donner **les outils** (Multi Exp. global, Mentali/Menthes, reset EV, tuteurs, accès aux natures) avant d'exiger l'optimisation.
5. Limiter le besoin de reconstruire toute l'équipe à chaque boss : au plus 1-2 slots « counter » à changer.

## 10. Modèle — « Fiche de combat majeur »

```markdown
### Fiche : <TRAINER_ID> — <Nom> (<Palier>, <lieu>, cap joueur N.<X>)

**Rôle stratégique dans la progression** : quelle leçon ? (ex. « enseigne la gestion des hazards »)
**Thème / identité** : type(s), personnalité → choix de flags (Risky/Conservative…)
**Format** : Singles/Doubles · Style Set/Shift · Objets de sac : … · Difficulté : Easy/Normal/Hard

| Slot | Pokémon @ Objet | Talent | Nature / EV | Capacités | Rôle | Tera/Méga |
|---|---|---|---|---|---|---|
| 1 (lead) | | | | | | |
| … | | | | | | |
| 6 (As) | | | | | | |

**Ligne IA** : `AI: …` (justifier chaque flag)

**Risques pour le joueur** (menaces) :
- M1 : … (ex. Tyranocif sous sable 2HKO l'équipe-type)
- M2 : …

**Réponses du joueur** (≥ 2 par menace, toutes obtenables avant ce combat) :
- M1 → captures/CT/tuteurs : … (lieu d'obtention)
- M2 → …

**Plan de jeu IA attendu** (tour par tour, avec les flags) :
1. Lead pose X… 2. Si le joueur Y, l'IA switch vers Z (Smart Switching, 50 %)… 3. As entre en dernier…

**Tells** (indices donnés au joueur) : dialogue, PNJ, décor, objet visible…

**Conditions de victoire** : joueur (ex. retirer le setter météo avant tour 3) ; IA (ex. Danse Draco non punie).

**Tests** :
- [ ] `validate_trainers.py --trainer <ID> --learnsets` sans erreur
- [ ] Combat test équipe « moyenne » au cap (3 essais max en Normal)
- [ ] Combat test équipe « counter » (doit être clairement plus facile)
- [ ] Combat test sans objets (mode Difficile)
- [ ] Debug AI vs AI (`B_FLAG_AI_VS_AI_BATTLE`) : l'IA suit le plan de jeu
- [ ] Test automatisé (`AI_SINGLE_BATTLE_TEST` dans `test/`) pour 1-2 comportements clés
- [ ] Vérif écart de niveau ≤ +2 (As +3)
```

## 11. Checklist de validation d'une équipe contre le moteur

**Existence (obligatoire)** — chaque nom doit correspondre à une constante :
- Espèce → `include/constants/species.h` (`SPECIES_*`). Conversion trainerproc : `Mr. Mime` → `SPECIES_MR_MIME`, `Nidoran♂` → `SPECIES_NIDORAN_M`, `Persian-Alola` → `SPECIES_PERSIAN_ALOLA`, `Farfetch’d` → `SPECIES_FARFETCHD`.
- Objet → `include/constants/items.h` (`ITEM_*`) ; `grep -n "ITEM_CHOICE_SCARF" include/constants/items.h`.
- Capacité → `include/constants/moves.h` (`MOVE_*`).
- Talent → `include/constants/abilities.h` (`ABILITY_*`).
- Nature `include/constants/pokemon.h` (`NATURE_*`), Type Téra (`TYPE_*`), Ball `include/constants/pokeball.h`, Classe/Pic/Musique `include/constants/trainers.h`, flags IA `include/constants/battle_ai.h`.

**Légalité** :
- Talent ∈ `.abilities` de l'espèce : `src/data/pokemon/species_info/gen_N_families.h`, bloc `[SPECIES_X] = { … .abilities = { A, B, HIDDEN } }` (attention aux macros `*_ABILITIES` / `*_SPECIES_INFO`). **Sinon crash/assert.**
- Capacités :
  - level-up : `.levelUpLearnset = sXLevelUpLearnset` → `src/data/pokemon/level_up_learnsets/gen_N.h` (`LEVEL_UP_MOVE(niv, MOVE_…)`) ;
  - œufs : `.eggMoveLearnset` → `src/data/pokemon/egg_moves.h` (souvent sur la forme de base → remonter les pré-évolutions via `.evolutions`) ;
  - CT/tuteurs : `src/data/pokemon/all_learnables.json` (clé = nom snake-case du symbole `sXTeachableLearnset`) + `special_movesets.json` (`universalMoves`) ; le fichier final `src/data/pokemon/teachable_learnsets.h` est **généré au build** et filtré par les CT/tuteurs réellement présents (`include/constants/tms_hms.h`, scripts `setvar VAR_0x8005, MOVE_*`) — voir `docs/tutorials/teachable_learnsets.md`.
  - cas spéciaux : Smeargle (Gribouille), formes Motisma (capacité de forme), capacités d'événement.
- Niveau : capacité level-up apprise ≤ niveau du Pokémon (ou via CT disponible à ce stade du jeu).
- ≤ 4 capacités, ≤ 6 Pokémon (sauf pool `Party Size`), ≤ 4 objets de sac, IV ≤ 31, EV ≤ 252/stat et ≤ 510 (non bloquant moteur mais à respecter pour l'équité).
- Gimmick : 1 Méga-Gemme / 1 Cristal Z utile par dresseur ; la Méga-Gemme correspond à l'espèce ; `Tera Type` sur au plus les Pokémon voulus (1 seul Téra effectif par combat).
- Configs : feature activée ? (`P_FAMILY_*`/`P_GEN_*` dans `include/config/species_enabled.h`, `B_FLAG_DYNAMAX_BATTLE` pour le joueur, Orbe Téra…)

Commandes utiles :
```sh
grep -n "\[SPECIES_GARCHOMP\]" -A80 src/data/pokemon/species_info/gen_4_families.h | grep -E "abilities|Learnset"
grep -n "sGarchompLevelUpLearnset" -A40 src/data/pokemon/level_up_learnsets/gen_4.h
python3 -c "import json;print('MOVE_SWORDS_DANCE' in json.load(open('src/data/pokemon/all_learnables.json'))['GARCHOMP'])"
grep -n "ABILITY_ROUGH_SKIN\b" include/constants/abilities.h
```

## 12. Outil de validation statique — `tools/qa/validate_trainers.py`

### Conception
- **Python 3 stdlib**, lecture seule, aucun `make`. Rapide (< 1 s pour 855 dresseurs).
- **Parsing `.party`** : blocs séparés par lignes vides après `=== TRAINER_X ===` ; en-tête `Clé: valeur` ; Pokémon au format Showdown (`Surnom (Espèce) (M) @ Objet`, champs, `X Nature`, `- Capacité`) ; commentaires `/* */` retirés en conservant les numéros de ligne.
- **Conversion des noms** : réplique exacte de `fprint_constant` / `fprint_species` de `tools/trainerproc/main.c` (gestion ♂/♀/é/’).
- **Référentiels** : constantes collectées dans les headers (`enum` et `#define`) ; données d'espèce parsées dans `species_info/*.h` avec expansion des macros (2 niveaux) ; learnsets level-up, œufs, `all_learnables.json`, `universalMoves` ; graphe des pré-évolutions depuis `.evolutions`.
- **Niveaux de sévérité** :
  - ERREUR (bloquant, code retour 1) : constante inexistante (espèce, objet, capacité, talent, nature, ball, type, flag IA, classe, pic, musique, mugshot), talent hors espèce, > 4 capacités, > 6 Pokémon hors pool, > 4 objets de sac, IV > 31, niveau hors 1-100, champ/ligne inconnus de trainerproc.
  - AVERTISSEMENT : doublon de capacité, EV hors normes, surnom > 12, talents non résolus, `--learnsets` (capacité inapprenable), `--strict-levels` (capacité level-up au-dessus du niveau sans autre source).
- Options : `-f FICHIER` (répétable), `--learnsets`, `--strict-levels`, `--trainer TRAINER_X`, `--summary`, `--werror`, `--json rapport.json`.
- Limites connues : learnset « superset » (all_learnables non filtré par les CT réellement présents) ; capacités d'événement non connues ; formes à learnset spécial (liste blanche Motisma + Smeargle) ; ne vérifie pas la cohérence Méga-Gemme/espèce ni les `Tags`/`Pool Rules` (amélioration future) ; 10 espèces à talents non résolus (Ogerpon, NONE, EGG) → avertissement.

### Résultats sur l'état actuel du dépôt (commit `f06a884`)
| Fichier | Dresseurs | Pokémon | Erreurs | Avertissements (`--learnsets`) |
|---|---|---|---|---|
| `src/data/trainers.party` | 855 | 1825 | **0** | 2 (+1 avec `--strict-levels`) |
| `src/data/trainers_frlg.party` | 624 | 1619 | 0 | 4 (Nidorino/Nidorina d'OWEN, sets hérités) |
| `src/data/debug_trainers.party` | 2 | 4 | 0 | 5 (Wobbuffet de debug volontairement illégal) |

Avertissements `trainers.party` (tous hérités du vanilla, non bloquants) :
- l.7628 `TRAINER_DIANNE` : Lanturn — Séisme (absent de ses learnsets expansion).
- l.14181 `TRAINER_ROXANNE_2` : Kabuto — Danse Lames.
- (`--strict-levels`) l.5559 `TRAINER_COLTON` : Skitty N.12 avec Feinte (apprise N.22).

Auto-test : un fichier factice avec talent illégal, objet mal orthographié, flag IA inconnu, 5 capacités, champ mal écrit (`Abilty`) et capacités illégales a bien produit 6 erreurs + 5 avertissements.

### Intégration proposée
- Hook pre-commit / CI locale : `python3 tools/qa/validate_trainers.py -f src/data/trainers.party --learnsets` (échec si erreur).
- Avant chaque PR de boss : `--trainer <ID> --learnsets --strict-levels`.
- Évolutions : vérifier Méga-Gemme ↔ espèce (`form_change_tables.h`), Cristal Z ↔ type de capacité, tags de pool, écart de niveau vs cap (`src/caps.c`), disponibilité des CT au moment du combat (table progression).

---

## Sources
- Définitions de rôles (Smogon, PokéBase) : https://www.smogon.com/forums/threads/sv-anything-goes-role-compendium.3754344 · https://pokemondb.net/pokebase/209800/im-confused-with-pokemon-roles · https://www.smogon.com/forums/threads/braviary.3746819
- Radical Red Hardcore : https://radicalred.miraheze.org/wiki/Hardcore_Mode · https://nuzlocketracker.org/guides/radical-red-hardcore · https://pokefirered.com/pokemon-radical-red-walkthrough/ · https://retrododo.com/pokemon-radical-red/
- Critiques communautaires (r/PokemonROMhacks, fils hebdo) : https://reddit.fabiomanganiello.com/r/PokemonROMhacks/comments/1f1hwqi/weekly_questions_thread_pokérom_codex
- Run & Bun : https://www.pokecommunity.com/threads/pok%C3%A9mon-run-bun-v1-07.493223/ · https://www.runlocke.com/docs/run-bun · https://pokepatched.com/hacks/pokemon-run-bun/
- Emerald Kaizo : https://www.pokecommunity.com/threads/pokemon-emerald-kaizo.395830/
- Elite Redux : https://pokeromcodex.notion.site/Elite-Redux-26e2dde171f240fba5e231e9d31cfd7d · https://lutris.net/games/pokemon-elite-redux/
- Inclement Emerald : https://www.pokecommunity.com/threads/pok%C3%A9mon-inclement-emerald-a-decomp-difficulty-hack-version-1-13.457039/
- Unbound : https://pokemonunbound.fandom.com/wiki/ · https://www.pokemoncoders.com/level-caps-in-pokemon-unbound/
- Code et docs du dépôt : voir `docs/hack/AI_AUDIT.md`.
