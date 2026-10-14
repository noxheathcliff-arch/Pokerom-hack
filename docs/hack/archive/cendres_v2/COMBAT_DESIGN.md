# COMBAT_DESIGN — *Pokémon Cendres* (squelette v2.0)

> Partie de la bible. Les **fiches détaillées** (format `GM_METHOD.md` §5.4 / `STRATEGY_RESEARCH.md` §10, sets Showdown, IA, tells, deux plans de victoire) seront produites par le superviseur dresseurs à partir de ce squelette, validées par `tools/qa/validate_trainers.py` et revues par le GMD.
> Règles d'équité (`STRATEGY_RESEARCH.md` §8) : boss ≤ plafond + 2 (As + 3) ; ≥ 2 réponses obtenables avant chaque boss ; hasard faible dans le verdict ; omniscience réservée aux sommets.

## 1. Principes propres à *Cendres*
1. **Red est fort, son équipe ne l'est pas d'office** : starter de Hoenn, Pikachu plafonné, équipe classique absente (`GAME_DESIGN_BIBLE.md` §7). Le joueur expert (le « vrai » Red) gagne par la lecture, pas par le niveau.
2. **Les combats ne règlent que les combats.** Aucun combat ne résout une question politique ; un combat peut **ouvrir** une scène (respect gagné, preuve obtenue) ou **échouer sans game over** (Blue 1, Peter, Groudon : défaite = scène).
3. **Combats déclinables** (fonction moteur) : 10 dresseurs « de rancune » ; décliner coûte de l'argent et de l'EXP mais peut gagner de la réputation (registre).
4. **Signatures de faction** (une couche de maîtrise chacune) :
   - **Rocket** : Poison, statuts, objets volés (Larcin, Implore), pièges (Toile, Piège de Roc) → apprendre à protéger son équipe et à purger les statuts.
   - **Coopérative Magma** : Feu/Sol sous **soleil**, Pokémon lents et massifs → météo et vitesse.
   - **Pêcheurs d'Aqua** : Eau sous **pluie**, Pokémon défensifs, Vampigraine/Toxik → usure et contre-usure.
   - **Blue** : équipe équilibrée qui **s'adapte** à celle de Red (`Know Opponent Party` aux 2 derniers combats).
5. **Une mécanique signature sur trois dresseurs au plus** (leçon des revues : éviter la monotonie).

## 2. Arc de maîtrise appliqué
| Phase | Couche | Enseignée par | Vérifiée par | Plafond |
|---|---|---|---|---|
| 1 | types et PV | Brice (R103), Routes 102-104 | **Roxanne** | 14 |
| 2 | menace et boosts | dojo, Grotte Granite | **Bastien** | 18 |
| — | adversaire qui s'adapte (avant-goût) | — | **Blue 1** (défaite autorisée) | 20 |
| 3 | statut et tempo | Routes 109-110, sbires Rocket (Tunnel) | **Voltère** ; raid (double avec Brice) | 23 → 25 |
| 4 | champ de bataille : soleil | Mont Chimnée (Magma), Chemin Ardent | **Adriane** | 30 |
| 5 | talents et objets tenus | Routes 117-118 | **Norman** | 33 |
| 6 | synergie, pivots, pluie | Institut (Aqua) | **Sarah** ; **Alizée** | 35 → 38 |
| 7 | Méga + double | duo avec Pierre (R120), Planque Aqua | **Lévy & Tatia** (Méga adverse) | 45 |
| 8 | adaptation à une IA qui lit | Centre Spatial (Lambda), Fondmer | **Juan** (pluie + Méga) | 47 → 50 |
| Climax | combinaison sous contrainte | — | **Ariane** ou **Groudon** | 53 |
| Synthèse | tout | Route Victoire (**Blue final**) | Conseil 4, **Pierre** | 60 |

## 3. Combats majeurs (roster)
| # | Qui | Où (`MAP_*`) | Ch. | Rôle | Intention d'équipe | IA (`AI:`) | Fiche |
|---|---|---|---|---|---|---|---|
| 1 | Brice 1 | `ROUTE103` | 0 | tutoriel | starter + Zigzaton | `Check Bad Move` | à faire |
| 2 | Roxanne | `RUSTBORO_CITY_GYM` | 1 | phase 1 | Racaillou, Tarinor, As Kranidos | `Basic Trainer / Sequence Switching / Ace Pokemon` | à faire |
| 3 | Bastien | `DEWFORD_TOWN_GYM` | 2 | phase 2 | Machoc, Méditikka, As Makuhita (Gonflette tell) | idem + `HP Aware` | à faire |
| 4 | Blue 1 | `SLATEPORT_CITY_BATTLE_TENT_LOBBY` | 3 | avant-goût (défaite OK) | Roucoups, Kadabra, Rhinocorne, starter de Kanto contre celui de Red ; 2 niveaux au-dessus | `Basic Trainer / Smart Switching` | à faire |
| 5 | Voltère | `MAUVILLE_CITY_GYM` | 4 | phase 3 | Magnéti, Dynavolt, Voltorbe, As Élecsprint | `Basic Trainer / Smart Switching / Ace Pokemon` | à faire |
| 6 | Raid Rocket (double, Brice partenaire) | `RUSTURF_TUNNEL` | 4 | phase 3 | Abo, Smogo, Nosferapti, Mysdibule | `Basic Trainer` | à faire |
| 7 | **Militants Aqua** (D049 = a) | `METEOR_FALLS_1F_1R` | 5 | pluie (avant-goût) | Tentacool, Lotad, Barloche | `Basic Trainer` | à faire |
| 8 | Kelvin (déclinable) | `MT_CHIMNEY` | 6 | soleil | Chartor (Sécheresse), Limagma, Grolem | `Basic Trainer / HP Aware` | à faire |
| 9 | Adriane | `LAVARIDGE_TOWN_GYM_1F` | 6 | phase 4 | Chartor, Malosse, Galopa, As Camérupt | idem + `Assume Stab` | à faire |
| 10 | Norman | `PETALBURG_CITY_GYM` | 7 | phase 5 | Ronflex @ Restes, Ursaring @ Orbe Flamme, Porygon2 @ Évoluroc, As Monaflèmit | `Basic Trainer / Smart Switching / Ace Pokemon / HP Aware` | à faire |
| 11 | Sarah | `ROUTE119_WEATHER_INSTITUTE_2F` | 8 | phase 6 | Bekipan (Crachin), Lanturn, Barbicha, Corayon | `Basic Trainer / Smart Switching` | à faire |
| 12 | Brice 3 | `ROUTE119` | 8 | lien (D075 : perdre possible) | starter évolué + recensés | `Basic Trainer` | à faire |
| 13 | Pierre + Red vs éclaireurs Rocket (double) | `ROUTE120` | 8 | démonstration Méga | sbires ordinaires | `Basic Trainer` | à faire |
| 14 | Alizée | `FORTREE_CITY_GYM` | 8 | phase 6 | Altaria, Hélédelle, Airmure, As Corvaillus | `... / HP Aware` | à faire |
| 15 | Arthur (facultatif) | `AQUA_HIDEOUT_B1F` | 9 | pluie | Sharpedo, Wailord, Pingoléon | `Smart Switching / Ace Pokemon` | à faire |
| 16 | Voleurs Rocket de l'Orbe | `MT_PYRE_SUMMIT` | 9 | statuts | Arbok, Smogogo, Grotadmorv | `Basic Trainer / Smart Switching` | à faire |
| 17 | Blue 2 (si D089 = b) | `LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP` | 9 | adaptation | 5 Pokémon, une Méga (Méga-Roucarnage ◐) | `+ Know Opponent Party` | à faire |
| 18 | Lévy & Tatia | `MOSSDEEP_CITY_GYM` | 10 | phase 7 | Solaroc, Séléroc, Méditikka @ Méditikkanite, Gardevoir | `... / Double Ace Pokemon` | à faire |
| 19 | Lambda (+ sbires) | `MOSSDEEP_CITY_SPACE_CENTER_2F` | 10 | phase 8 | Smogogo, Moufouette, Cradopaud, Mysdibule ; As Smogogo de Galar ◐ | `Smart Trainer / Ace Pokemon` (tells : déguisement) | à faire |
| 20 | Juan | `SOOTOPOLIS_CITY_GYM_1F` | 12 | phase 8 | Bekipan (Crachin), Milobellus, Kingdra, Lanturn, As Léviator @ Léviatorite | `Basic Trainer / Smart Switching / Ace Pokemon / HP Aware / Prediction` | à faire |
| 21 | Ariane (camp) | `LAVARIDGE_TOWN` | 13 | climax | Démolosse, Grotadmorv, Vortente, Arbok, Corboss ; 2 variantes selon `ETAT_ROCKET` | `Smart Trainer / Ace Pokemon / HP Aware` | à faire |
| 22 | Groudon (chantier, si V ≥ 70) | `MAGMA_HIDEOUT_4F` | 13 | climax (défaite = scène) | Groudon niv. 60, soleil | — (sauvage, `B_FLAG_NO_WHITEOUT`) | à faire |
| 23 | Blue final | `VICTORY_ROAD_1F` | 14 | synthèse | 6 Pokémon, Méga, adaptatif ; 6 variantes (3 starters × 2 seuils `AFF_BLUE`) | `Smart Trainer / Know Opponent Party / Ace Pokemon` | à faire |
| 24 | Conseil 4 de Hoenn (Damien, Spectra, Glacia, Aragon) | Ligue | 14 | synthèse | thèmes vanilla, une mécanique chacun | `Smart Trainer / Ace Pokemon / HP Aware / Prediction` | à faire |
| 25 | Pierre Rochard (Maître) | `EVER_GRANDE_CITY_CHAMPIONS_ROOM` | 14 | final | Méga-Métalosse, Armaldo, Kaorine, Galeking, Carchacrok, Corvaillus | `Smart Trainer / Prediction / Weigh Ability Prediction / Ace Pokemon / HP Aware` | à faire |
| P | Peter, Auguste, Agatha, Ariane (postgame), revanches | divers | post | rejouabilité | — | `Smart Trainer / Prediction / Randomize Party Indices` | à faire |


## 4. Affectation des ID de dresseurs (9 slots libres seulement)
Principe : **réaffecter les ID vanilla** dont l'événement disparaît ; le portrait, la classe et la musique se changent dans `trainers.party` (un ID n'est qu'un emplacement). Aucun nouvel ID pour l'aventure ; les 9 slots libres sont réservés au postgame.

| Usage *Cendres* | ID vanilla réutilisés | Nb | Combats |
|---|---|---|---|
| Brice | `BRENDAN_ROUTE_103_*`, `_RUSTBORO_*`, `_ROUTE_110_*`, `_ROUTE_119_*`, `_LILYCOVE_*` | 15 | 3 variantes (starter de Red) × jusqu'à 5 combats/scènes |
| Blue (1 et 2) | `MAY_RUSTBORO_*` (Blue 1), `MAY_LILYCOVE_*` (Blue 2) | 6 | variantes par starter |
| Blue final | `WALLY_VR_1..5` + `WALLY_MAUVILLE` | 6 | 3 starters × 2 seuils d'affinité |
| Ariane | `MAXIE_MAGMA_HIDEOUT` (+ `MAXIE_MT_CHIMNEY` pour la variante forte) | 2 | climax |
| Lambda | `MAXIE_MOSSDEEP` | 1 | Centre Spatial |
| Kelvin | `TABITHA_MT_CHIMNEY` | 1 | déclinable |
| Kelvin / ingénieurs (réserve) | `TABITHA_MAGMA_HIDEOUT`, `TABITHA_MOSSDEEP` | 2 | galeries, Centre Spatial |
| Arthur | `ARCHIE` | 1 | facultatif |
| Matthieu | `MATT` | 1 | déclinable |
| Sarah | `SHELLY_WEATHER_INSTITUTE` (+ `SHELLY_SEAFLOOR_CAVERN` réserve) | 2 | Institut |
| Sbires Rocket | `GRUNT_*` (Planque Magma ×16, Planque Aqua ×8, Centre Spatial ×7…) | ≈ 22 | Route 116, Tunnel, R120, Mont Mémoria, Centre Spatial, Fondmer, climax |
| Ouvriers Magma | `GRUNT_*` restants | ≈ 12 | chantier, galeries |
| Militants/pêcheurs Aqua | `GRUNT_*` restants + dresseurs vanilla Aqua | ≈ 15 | Site Météore, Institut, planque, port |
| Dresseurs « de rancune » (déclinables) | dresseurs vanilla de route réaffectés (même carte) | 10 | D012, D022… |
| Postgame (slots libres) | 9 libres | 9 | Peter, Auguste, Agatha, Ariane (postgame), Flora, Lilou ?, 3 réserves |

Contrôle : les 53 `GRUNT_*` couvrent ≈ 49 besoins (sbires + ouvriers + militants) ; si le compte dépasse, réaffecter des dresseurs vanilla de la Planque Magma 3F-4F (cartes fermées). Le mode **Expert** utilise les blocs `Difficulty: Hard` des **mêmes ID** (boss uniquement : 8 champions, Conseil 4, Pierre, Blue final, Ariane, Lambda), produit après le mode Normal.

## 5. Musiques et classes (à câbler)
| Classe | Portrait | Musique de combat | Rencontre |
|---|---|---|---|
| Rocket (`TEAM_ROCKET_FRLG` réutilisée) | `ROCKET_GRUNT_M/F_FRLG` | `MUS_RG_VS_TRAINER` ◐ (case `GetBattleBGM`) | `MUS_RG_ENCOUNTER_ROCKET` |
| Commandante / Lambda (`BOSS_FRLG` renommée « COMMANDANT ») | `ROCKET_GRUNT_F_FRLG`, `SCIENTIST_FRLG` | `MUS_VS_AQUA_MAGMA_LEADER` (case) | `MUS_RG_ENCOUNTER_ROCKET` |
| Magma (`TEAM_MAGMA` renommée « OUVRIER MAGMA ») | vanilla | `MUS_VS_AQUA_MAGMA` | `MUS_ENCOUNTER_MAGMA` |
| Aqua (`TEAM_AQUA` renommée « PECHEUR AQUA ») | vanilla | `MUS_VS_AQUA_MAGMA` | `MUS_ENCOUNTER_AQUA` |
| Blue (`RIVAL_LATE_FRLG`) | `RIVAL_LATE_FRLG` / `CHAMPION_RIVAL_FRLG` | `MUS_RG_VS_TRAINER` ◐ | `MUS_RG_ENCOUNTER_RIVAL` |
| Brice (`RIVAL`) | `BRENDAN` | `MUS_VS_RIVAL` | `MUS_ENCOUNTER_BRENDAN` |
Noms de classe ≤ 12 caractères ; vérifier le buffer (`TRAINER_CLASS` name length) avant « OUVRIER MAGMA » (13) → repli « OUVRIER ».

## 6. Prochaines fiches (ordre de production)
Tranche verticale d'abord : Brice 1, Roxanne, Blue 1, Voltère, raid du Tunnel. Puis acte II, puis acte III.
