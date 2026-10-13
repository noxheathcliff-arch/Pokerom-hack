# Inventaire des assets et contenus réutilisables

> Projet : `/home/user/Pokerom-hack` (pokeemeraude-expansion 1.16.4, décomp Émeraude FR + expansion, contenu RFVF inclus).
> Public : agents narration, level design, design de dresseurs.
> Légende : **[V]** = vérifié directement dans les sources (fichier cité) ; **[C]** = connaissance du jeu vanilla, non revérifiée ligne à ligne.
> Inventaire établi en lecture seule, sans `make`. Les chiffres viennent de scripts Python lancés sur les JSON et les headers.

---

## 0. Points clés

| Sujet | Constat |
|---|---|
| Maps RFVF dans la build Émeraude | **Non incluses.** Elles sont exclues par `tools/mapjson` (attribut `"region": "REGION_KANTO"`) et leurs tilesets, scripts et sprites OW sont sous `#if IS_FRLG`. Pour les avoir dans la build par défaut (`make`), il faut un portage manuel. Voir §1.6. **[V]** |
| Maps Hoenn | **518** maps `REGION_HOENN` sur 939 `map.json` (421 sont `REGION_KANTO`). **[V]** |
| Noms de lieux FR | `src/data/region_map/region_map_sections.json` (champ `name`). Le renommage est facile, mais les noms apparaissent aussi en dur dans les dialogues (par ex. MEROUVILLE : 37 occurrences dans 16 fichiers). **[V]** |
| Portraits de dresseurs (`TRAINER_PIC_*`) | **159** constantes. Toutes sont compilées dans les deux builds, y compris celles de RFVF : Giovanni, Chen, Blue, les champions et le Conseil 4 de Kanto, la Team Rocket. **24 PNG de style RFVF existent sans constante** (par ex. `wally_frlg`, `champion_steven_frlg`). **[V]** |
| Sprites OW | Environ 400 `OBJ_EVENT_GFX_*`. Ceux de RFVF (de `RED_NORMAL` à `BREAKABLE_ROCK_FRLG`) **ne sont pas compilés** dans la build Émeraude. Les PNJ Pokémon (`OBJ_EVENT_GFX_SPECIES(X)`) sont disponibles pour les Gen 1 à 9. **[V]** |
| Musique | Environ 200 `MUS_*`, dont **toutes les pistes RFVF (`MUS_RG_*`), compilées dans Émeraude** (`sound/song_table.inc` n'a aucun `#if`). **[V]** |
| Pokémon | `NUM_SPECIES` = 1573 IDs (formes comprises), dex national jusqu'à Pêchaminus (1025). **1299 `overworld.png` + 98 variantes femelles**, Gen 9 incluse. Followers désactivés par défaut. **[V]** |

---

## 1. Maps

### 1.1 Chiffres **[V]** (`data/maps/map_groups.json`, `data/layouts/layouts.json`)

- `data/maps/` contient 940 entrées, dont 939 `map.json` et `map_groups.json`.
- **518 maps Hoenn** et **421 maps Kanto/Sevii** (suffixe `_Frlg`, plus `Route23_UnusedHouse` et `SevenIsland_UnusedHouse`, qui sont KANTO sans suffixe).
- Layouts : 785 au total, dont **441 `layout_version: emerald`**.
- Groupes Hoenn (34) : TownsAndRoutes (57), Indoor* par ville, Dungeons (108), IndoorDynamic (61), SpecialArea (89), IndoorRoute104Prototype (2), etc.
- Groupes RFVF (42) : Link_Frlg, Dungeons_Frlg (123), SpecialArea_Frlg (60), TownsAndRoutes_Frlg (62), Indoor*_Frlg.

**Météo.** Dans les `map.json`, la météo est presque partout `SUNNY` ou `NONE`. La vraie météo vient des scripts et des coord events :

| Météo | Maps et mécanisme |
|---|---|
| Tempête de sable | Route 111 (`setweather WEATHER_SANDSTORM` dans `Route111/scripts.inc`) |
| Cendres | Route 113, Sentier Sinuroc (coord events `COORD_EVENT_WEATHER_VOLCANIC_ASH`), Mont Chimnée (`WEATHER_VOLCANIC_ASH`) |
| Pluie ou cycle | Routes 119, 120, 123 |
| Brouillard (`FOG_HORIZONTAL`) | Mont Mémoria sommet, Grotte Origine B1F, arène de Vermilava, Tunnel Mérazon, fins de Grotte Marine/Terra, Caverne Fondmer salle 9 |
| Ombre (`SHADE`) | Épave, Bois Clementi, intérieur de l'Île du Sud, Île Lointaine, sommet du Roc Nombri |
| Bulles (sous-marin) | Toutes les maps sous-marines |

### 1.2 Villes, routes et connexions de Hoenn **[V]** (connexions extraites des `map.json`)

Format des connexions : `direction:MAP`. `dive` et `emerge` relient la surface à une map sous-marine.

#### Villes et villages

| Constante | Nom FR | Connexions | Tilesets (prim/sec) | Musique | Rôle et terrain |
|---|---|---|---|---|---|
| `MAP_LITTLEROOT_TOWN` | BOURG-EN-VOL | up:ROUTE101 | General/Petalburg | MUS_LITTLEROOT | Village de départ, maisons du joueur et du rival, labo de Birch. |
| `MAP_OLDALE_TOWN` | ROSYERES | up:ROUTE103, down:ROUTE101, left:ROUTE102 | General/Petalburg | MUS_OLDALE | Premier Centre et Boutique, carrefour. |
| `MAP_PETALBURG_CITY` | CLEMENTI-VILLE | left:ROUTE104, right:ROUTE102 | General/Petalburg | MUS_PETALBURG | Arène de Norman (père), maison de Timmy (Wally). |
| `MAP_RUSTBORO_CITY` | MEROUVILLE | up:ROUTE115, down:ROUTE104, right:ROUTE116 | General/Rustboro | MUS_RUSTBORO | Ville industrielle (Devon SA), arène Roche, école Pokémon. |
| `MAP_DEWFORD_TOWN` | VILLAGE MYOKARA | up:ROUTE106, right:ROUTE107 | General/Dewford | MUS_DEWFORD | Île, arène Combat, accès à la Grotte Granite. |
| `MAP_SLATEPORT_CITY` | POIVRESSEL | up:ROUTE110, down:ROUTE109, right:ROUTE134 | General/Slateport | MUS_SLATEPORT | Port, marché, Musée Océanographique, chantier naval, Tente de combat. |
| `MAP_MAUVILLE_CITY` | LAVANDIA | up:ROUTE111, down:ROUTE110, left:ROUTE117, right:ROUTE118 | General/Mauville | MUS_RUSTBORO | Plaque tournante centrale, arène Électrik, Casino, magasin de vélos. |
| `MAP_VERDANTURF_TOWN` | VERGAZON | up:ROUTE116, right:ROUTE117 | General/Mauville | MUS_VERDANTURF | Village calme, Tunnel Mérazon, Tente de combat. |
| `MAP_FALLARBOR_TOWN` | AUTEQUIA | left:ROUTE114, right:ROUTE113 | General/Fallarbor | MUS_FALLARBOR | Village couvert de cendres, Professeur Cosmo, Tente de combat, Maître des capacités. |
| `MAP_LAVARIDGE_TOWN` | VERMILAVA | right:ROUTE112 | General/Lavaridge | MUS_OLDALE | Village thermal volcanique, arène Feu, herboriste. |
| `MAP_FORTREE_CITY` | CIMETRONELLE | left:ROUTE119, right:ROUTE120 | General/Fortree | MUS_FORTREE | Ville perchée dans les arbres, arène Vol, magasin de décoration. |
| `MAP_LILYCOVE_CITY` | NENUCRIQUE | left:ROUTE121, right:ROUTE124 | General/Lilycove | MUS_LILYCOVE | Grande ville côtière : Grand Magasin (5 étages et toit), Concours, musée, port, entrée de la Planque Aqua. |
| `MAP_MOSSDEEP_CITY` | ALGATIA | up:ROUTE125, down:ROUTE127, left:ROUTE124 | General/Mossdeep | MUS_RUSTBORO | Île, Centre Spatial, arène Psy (Lévy et Tatia), maison de Pierre. |
| `MAP_SOOTOPOLIS_CITY` | ATALANOPOLIS | **aucune** (accès par Plongée depuis le fond marin 126) | General/Sootopolis | MUS_SOOTOPOLIS | Ville dans un cratère, arène Eau, Grotte Origine. |
| `MAP_PACIFIDLOG_TOWN` | PACIFIVILLE | left:ROUTE132, right:ROUTE131 | General/Pacifidlog | MUS_LILYCOVE | Village sur radeaux en pleine mer. |
| `MAP_EVER_GRANDE_CITY` | ETERNARA | left:ROUTE128 | General/EverGrande | MUS_EVER_GRANDE | Ligue Pokémon, Route Victoire. |

#### Routes terrestres

| Constante | Nom FR | Connexions | Tileset sec. | Musique | Rôle et terrain (nombre de dresseurs sur la map) |
|---|---|---|---|---|---|
| `MAP_ROUTE101` | ROUTE 101 | up:OLDALE, down:LITTLEROOT | Petalburg | MUS_ROUTE101 | Hautes herbes, sauvetage de Birch (0) |
| `MAP_ROUTE102` | ROUTE 102 | left:PETALBURG, right:OLDALE | Petalburg | MUS_ROUTE101 | Herbes, petit étang (4) |
| `MAP_ROUTE103` | ROUTE 103 | down:OLDALE, right:ROUTE110 | Petalburg | MUS_ROUTE101 | Premier combat contre le rival, eau (Surf) vers la 110, Grotte Métamo (9) |
| `MAP_ROUTE104` | ROUTE 104 | up:RUSTBORO, down:ROUTE105, right:PETALBURG | Rustboro | MUS_ROUTE104 | Plage et Bois Clementi, maison de M. Marcel (Briney), fleuriste (8) |
| `MAP_ROUTE110` | ROUTE 110 | up:MAUVILLE, down:SLATEPORT, left:ROUTE103 | Mauville | MUS_ROUTE110 | Piste Cyclable (pont), Maison des Pièges, New Lavandia (14) |
| `MAP_ROUTE111` | ROUTE 111 | down:MAUVILLE, left:ROUTE113, left:ROUTE112 | Mauville | MUS_ROUTE110 | **Désert** (tempête de sable, Lunettes Sable), Tour Mirage, Ruines du Désert, Mont Dresseurs, famille Stratège (17). Layout alternatif sans la Tour Mirage. |
| `MAP_ROUTE112` | ROUTE 112 | up:ROUTE113, left:LAVARIDGE, right:ROUTE111 | Lavaridge | MUS_ROUTE110 | Pied du volcan, téléphérique, Chemin Ardent, Sentier Sinuroc (6) |
| `MAP_ROUTE113` | ROUTE 113 | down:ROUTE112, left:FALLARBOR, right:ROUTE111 | Fallarbor | MUS_ROUTE113 | **Pluie de cendres** (herbe grise), atelier de verre (11) |
| `MAP_ROUTE114` | ROUTE 114 | left:ROUTE115, right:FALLARBOR | Fallarbor | MUS_ROUTE110 | Rivière et collines, Site Météore, maniaque des fossiles, maison de Lanette (13) |
| `MAP_ROUTE115` | ROUTE 115 | down:RUSTBORO, right:ROUTE114 | Fallarbor | MUS_ROUTE104 | Côte, falaises, Site Météore (10) |
| `MAP_ROUTE116` | ROUTE 116 | down:VERDANTURF, left:RUSTBORO | Rustboro | MUS_ROUTE104 | Plaine, Tunnel Mérazon (10) |
| `MAP_ROUTE117` | ROUTE 117 | left:VERDANTURF, right:MAUVILLE | Mauville | MUS_ROUTE110 | Fleurs, Pension Pokémon (10) |
| `MAP_ROUTE118` | ROUTE 118 | up:ROUTE119, left:MAUVILLE, right:ROUTE123 | Mauville | MUS_ROUTE118 (2 sections) | Coupée par une rivière (Surf) (7) |
| `MAP_ROUTE119` | ROUTE 119 | down:ROUTE118, right:FORTREE | Fortree | MUS_ROUTE119 | **Jungle pluvieuse**, très hautes herbes, cascade, ponts, Institut Météo (17) |
| `MAP_ROUTE120` | ROUTE 120 | left:FORTREE, right:ROUTE121 | Fortree | MUS_ROUTE120 | Pluie et brouillard, Tombeau Antique, Grotte Zénith, Kecleon invisibles (13) |
| `MAP_ROUTE121` | ROUTE 121 | down:ROUTE122, left:ROUTE120, right:LILYCOVE | Lilycove | MUS_ROUTE120 | Entrée du Parc Safari (11) |
| `MAP_ROUTE123` | ROUTE 123 | up:ROUTE122, left:ROUTE118 | Lilycove | MUS_ROUTE122 | Rebords à sens unique, Maître des Baies (16) |

#### Chenaux maritimes (`MAP_TYPE_OCEAN_ROUTE` pour 124 à 134)

| Constante | Nom FR | Connexions | Rôle et terrain (nombre de dresseurs) |
|---|---|---|---|
| `MAP_ROUTE105` | CHENAL 105 | up:ROUTE104, down:ROUTE106, dive:UNDERWATER_ROUTE105 | Mer, Grotte Île (Régice) (7) |
| `MAP_ROUTE106` | CHENAL 106 | up:ROUTE105, down:DEWFORD | Mer et plage, Grotte Granite (4) |
| `MAP_ROUTE107` | CHENAL 107 | left:DEWFORD, right:ROUTE108 | Mer (7) |
| `MAP_ROUTE108` | CHENAL 108 | left:ROUTE107, right:ROUTE109 | Mer, Épave (Abandoned Ship) (6) |
| `MAP_ROUTE109` | CHENAL 109 | up:SLATEPORT, left:ROUTE108 | Plage, maison de bord de mer (14) |
| `MAP_ROUTE122` | CHENAL 122 | up:ROUTE121, down:ROUTE123 | Lac autour du Mont Mémoria (0) |
| `MAP_ROUTE124` | CHENAL 124 | down:ROUTE126, left:LILYCOVE, right:ROUTE125, right:MOSSDEEP, dive | Mer et zones de plongée, maison des chasseurs de trésor (9) |
| `MAP_ROUTE125` | CHENAL 125 | down:MOSSDEEP, left:ROUTE124, dive | Grotte Tréfonds (marées) (9) |
| `MAP_ROUTE126` | CHENAL 126 | up:ROUTE124, right:ROUTE127, dive | Anneau autour d'Atalanopolis (8) |
| `MAP_ROUTE127` | CHENAL 127 | up:MOSSDEEP, down:ROUTE128, left:ROUTE126, dive | Haute mer (8) |
| `MAP_ROUTE128` | CHENAL 128 | up:ROUTE127, down:ROUTE129, right:EVER_GRANDE, dive | Récifs, Caverne Fondmer (en plongée) (7) |
| `MAP_ROUTE129` | CHENAL 129 | up:ROUTE128, left:ROUTE130, dive | Haute mer, Wailord (5) |
| `MAP_ROUTE130` | CHENAL 130 | left:ROUTE131, right:ROUTE129 | Île Mirage (layout alternatif `ROUTE130_MIRAGE_ISLAND`) (3) |
| `MAP_ROUTE131` | CHENAL 131 | left:PACIFIDLOG, right:ROUTE130 | Entrée du Pilier Céleste (8) |
| `MAP_ROUTE132`, `MAP_ROUTE133` | CHENAL 132/133 | 132 : left:ROUTE133, right:PACIFIDLOG ; 133 : left:ROUTE134, right:ROUTE132 | Courants marins (8 et 7) |
| `MAP_ROUTE134` | CHENAL 134 | left:SLATEPORT, right:ROUTE133 | Courants, Sanctuaire sous-marin (9) |

**Fond marin** (`MAP_TYPE_UNDERWATER`, tileset Underwater, `MUS_UNDERWATER`) : `MAP_UNDERWATER_ROUTE105`, `_124`, `_125`, `_126` (warp vers `UNDERWATER_SOOTOPOLIS_CITY`), `_127` (vers la Grotte Marine), `_128` (vers la Caverne Fondmer), `_129` (Grotte Marine), `_134` (Sanctuaire, dans le groupe Dungeons).

### 1.3 Graphe des connexions de Hoenn **[V]**

```
Liste d'adjacence (connexions de bord vérifiées) :

LITTLEROOT ─N─ R101 ─N─ OLDALE ─W─ R102 ─W─ PETALBURG ─W─ R104 ─N─ RUSTBORO ─N─ R115 ─E─ R114 ─E─ FALLARBOR ─E─ R113 ─E─ R111
                          │                                  │                 │
                          N                                  S                 E
                        R103 ─E─ R110                      R105 (mer)        R116 ─S─ VERDANTURF ─E─ R117 ─E─ MAUVILLE
                                  │                          │                                                 │
           SLATEPORT ─N──────── R110 ─N─ MAUVILLE          R106 ─S─ DEWFORD ─E─ R107 ─E─ R108 ─E─ R109 ─N─ SLATEPORT

MAUVILLE ─N─ R111 ─W─ R112 ─W─ LAVARIDGE      (R111 ─W─ R113 aussi ; R112 ─N─ R113)
MAUVILLE ─E─ R118 ─N─ R119 ─E─ FORTREE ─E─ R120 ─E─ R121 ─E─ LILYCOVE ─E─ R124 ─E─ MOSSDEEP
             R118 ─E─ R123 ─N─ R122 ─N─ R121                               R124 ─E─ R125 ─S─ MOSSDEEP
                                                                           R124 ─S─ R126 ─E─ R127 ─N─ MOSSDEEP
                                                                                            R127 ─S─ R128 ─E─ EVER GRANDE
SLATEPORT ─E─ R134 ─E─ R133 ─E─ R132 ─E─ PACIFIDLOG ─E─ R131 ─E─ R130 ─E─ R129 ─N─ R128

Plongée (dive/emerge) : R105, R124–R129 ↔ UNDERWATER_*. SOOTOPOLIS : aucune connexion,
accès uniquement par UNDERWATER_ROUTE126 → UNDERWATER_SOOTOPOLIS_CITY (warp).
Ferry/Aqualine : ports Slateport/Lilycove → Zone de Combat, Île du Sud, îles d'événements.
```

Lecture simplifiée de la boucle principale :

`Littleroot → 101 → Oldale → 102 → Petalburg → 104 (Bois) → Rustboro → [bateau] Dewford → [bateau] Slateport → 110 → Mauville → 117 → Verdanturf / 111-112 → Lavaridge / 113 → Fallarbor → 114 → Site Météore → Mt Chimnée → 118 → 119 → Fortree → 120 → 121 → Lilycove → 124 → Mossdeep → 126/127 → Atalanopolis (plongée) → 128 → Ever Grande`.

- Sootopolis n'a **aucune connexion** : on y entre par warp sous-marin (`UNDERWATER_SOOTOPOLIS_CITY`).
- La Zone de Combat se rejoint par l'Aqualine (`SS_TIDAL_*`) depuis les ports de Slateport et de Lilycove.

### 1.4 Intérieurs par ville **[V]**

Le préfixe `MAP_<VILLE>_` est omis. Musique : `MUS_POKE_CENTER` et `MUS_POKE_MART` partout, `MUS_GYM` pour les arènes.

| Ville | Intérieurs |
|---|---|
| Littleroot | BRENDANS_HOUSE_1F/2F, MAYS_HOUSE_1F/2F, PROFESSOR_BIRCHS_LAB |
| Oldale | HOUSE1, HOUSE2, POKEMON_CENTER_1F/2F, MART |
| Dewford | HOUSE1, HOUSE2, POKEMON_CENTER_1F/2F, GYM (Bastien/Brawly, salle sombre, 6 dresseurs), HALL |
| Lavaridge | HERB_SHOP, GYM_1F/B1F (Adriane/Flannery, geysers, 4+4 dresseurs), HOUSE, MART, POKEMON_CENTER_1F/2F (bains de sable) |
| Fallarbor | MART, BATTLE_TENT_LOBBY/CORRIDOR/BATTLE_ROOM, POKEMON_CENTER_1F/2F, COZMOS_HOUSE, MOVE_RELEARNERS_HOUSE |
| Verdanturf | BATTLE_TENT_LOBBY/CORRIDOR/BATTLE_ROOM, MART, POKEMON_CENTER_1F/2F, WANDAS_HOUSE, FRIENDSHIP_RATERS_HOUSE, HOUSE |
| Pacifidlog | POKEMON_CENTER_1F/2F, HOUSE1 à HOUSE5 (pas de Boutique) |
| Petalburg | WALLYS_HOUSE, GYM (Norman, salles successives, 7), HOUSE1, HOUSE2, POKEMON_CENTER_1F/2F, MART |
| Slateport | STERNS_SHIPYARD_1F/2F, BATTLE_TENT_*(3), NAME_RATERS_HOUSE, POKEMON_FAN_CLUB, OCEANIC_MUSEUM_1F/2F, HARBOR, HOUSE, POKEMON_CENTER_1F/2F, MART (et marché extérieur avec `pokemart` sur la map de la ville) |
| Mauville | GYM (Voltère/Wattson, 5), BIKE_SHOP, HOUSE1, GAME_CORNER, HOUSE2, POKEMON_CENTER_1F/2F, MART |
| Rustboro | DEVON_CORP_1F/2F/3F, GYM (Roxanne, 3), POKEMON_SCHOOL, POKEMON_CENTER_1F/2F, MART, FLAT1_1F/2F, HOUSE1 à HOUSE3, CUTTERS_HOUSE, FLAT2_1F/2F/3F |
| Fortree | HOUSE1 à HOUSE5, GYM (Alizée/Winona, tourniquets, 6), POKEMON_CENTER_1F/2F, MART, DECORATION_SHOP |
| Lilycove | COVE_LILY_MOTEL_1F/2F, LILYCOVE_MUSEUM_1F/2F, CONTEST_LOBBY, CONTEST_HALL, POKEMON_CENTER_1F/2F, **UNUSED_MART** (inutilisée), POKEMON_TRAINER_FAN_CLUB, HARBOR, MOVE_DELETERS_HOUSE, HOUSE1 à HOUSE4, DEPARTMENT_STORE_1F à 5F, ROOFTOP, ELEVATOR |
| Mossdeep | GYM (Lévy et Tatia, téléporteurs, 12), HOUSE1 à HOUSE4, POKEMON_CENTER_1F/2F, MART, STEVENS_HOUSE, SPACE_CENTER_1F/2F (4 dresseurs Magma lors de l'invasion), GAME_CORNER_1F/B1F |
| Sootopolis | GYM_1F/B1F (Juan, sol de glace, 10), POKEMON_CENTER_1F/2F, MART, HOUSE1 à HOUSE7, LOTAD_AND_SEEDOT_HOUSE, MYSTERY_EVENTS_HOUSE_1F/B1F |
| Ever Grande | SIDNEYS_ROOM, PHOEBES_ROOM, GLACIAS_ROOM, DRAKES_ROOM, CHAMPIONS_ROOM, HALL1 à HALL5, POKEMON_LEAGUE_1F/2F, HALL_OF_FAME, POKEMON_CENTER_1F/2F |

Intérieurs de routes :

| Route | Intérieurs |
|---|---|
| 104 | `ROUTE104_MR_BRINEYS_HOUSE`, `ROUTE104_PRETTY_PETAL_FLOWER_SHOP` |
| 109 | `ROUTE109_SEASHORE_HOUSE` (3 dresseurs) |
| 110 | `ROUTE110_TRICK_HOUSE_ENTRANCE/END/CORRIDOR/PUZZLE1` à `PUZZLE8` (8 énigmes avec dresseurs), `SEASIDE_CYCLING_ROAD_NORTH/SOUTH_ENTRANCE` |
| 111 | `WINSTRATE_FAMILYS_HOUSE`, `OLD_LADYS_REST_STOP` |
| 112 | `ROUTE112_CABLE_CAR_STATION`, `MT_CHIMNEY_CABLE_CAR_STATION` |
| 113 | `GLASS_WORKSHOP` |
| 114 | `FOSSIL_MANIACS_HOUSE/TUNNEL`, `LANETTES_HOUSE` |
| 116 | `TUNNELERS_REST_HOUSE` |
| 117 | `POKEMON_DAY_CARE` |
| 119 | `WEATHER_INSTITUTE_1F/2F` (dresseurs Aqua), `HOUSE` |
| 121 | `SAFARI_ZONE_ENTRANCE` |
| 123 | `BERRY_MASTERS_HOUSE` |
| 124 | `DIVING_TREASURE_HUNTERS_HOUSE` |

Note : les Centres Pokémon partagent `LAYOUT_POKEMON_CENTER_1F/2F` (sauf Lavaridge et la Ligue) et les Boutiques partagent `LAYOUT_MART`.

### 1.5 Donjons et zones spéciales **[V]**

#### Donjons (groupe `gMapGroup_Dungeons`)

| Lieu | Maps (`MAP_` omis) | Tileset et ambiance |
|---|---|---|
| Site Météore | METEOR_FALLS_1F_1R, 1F_2R, B1F_1R, B1F_2R, STEVENS_CAVE | Tileset MeteorFalls, cascades |
| Tunnel Mérazon | RUSTURF_TUNNEL | Tileset RusturfTunnel |
| Ruines du Désert | DESERT_RUINS | Régirock, `MUS_SEALED_CHAMBER` |
| Grotte Granite | GRANITE_CAVE_1F, B1F, B2F, STEVENS_ROOM | Flash, sol fragile |
| Bois Clementi | PETALBURG_WOODS | Forêt, `WEATHER_SHADE` |
| Volcan | MT_CHIMNEY (cendres, Magma vs Aqua, 8 dresseurs), JAGGED_PASS, FIERY_PATH | Tileset Lavaridge, volcanique |
| Mont Mémoria | MT_PYRE_1F à 6F (cimetière intérieur), MT_PYRE_EXTERIOR, MT_PYRE_SUMMIT | Brouillard, `MUS_MT_PYRE` |
| Planque Aqua | AQUA_HIDEOUT_1F, B1F, B2F (+ UNUSED_RUBY_MAP1 à 3) | Tileset Facility |
| Planque Magma | MAGMA_HIDEOUT_1F, 2F_1R à 3R, 3F_1R à 3R, 4F | Tileset Lavaridge (lave), Groudon |
| Caverne Fondmer | UNDERWATER_SEAFLOOR_CAVERN, SEAFLOOR_CAVERN_ENTRANCE, ROOM1 à ROOM9 | Kyogre, rochers à pousser |
| Grotte Origine | CAVE_OF_ORIGIN_ENTRANCE, 1F, B1F (+ UNUSED_RUBY_SAPPHIRE_MAP1 à 3) | Brouillard |
| Route Victoire | VICTORY_ROAD_1F, B1F, B2F | `MUS_VICTORY_ROAD`, 16 dresseurs |
| Grotte Tréfonds | SHOAL_CAVE_LOW_TIDE_ENTRANCE/INNER/STAIRS/LOWER/ICE_ROOM, HIGH_TIDE_ENTRANCE/INNER | Marées ; ICE_ROOM = glace sur le tileset Cave, pas de tileset neige |
| New Lavandia | NEW_MAUVILLE_ENTRANCE, NEW_MAUVILLE_INSIDE | Centrale électrique souterraine |
| Épave | ABANDONED_SHIP_DECK, CORRIDORS_1F/B1F, ROOMS_1F/B1F, ROOMS2_1F/B1F, ROOM_B1F, CAPTAINS_OFFICE, UNDERWATER1/2, HIDDEN_FLOOR_CORRIDORS/ROOMS | Tileset InsideShip, `MUS_ABANDONED_SHIP` |
| Énigmes des Regi | ISLAND_CAVE (Régice), ANCIENT_TOMB (Registeel), SEALED_CHAMBER_OUTER/INNER_ROOM, UNDERWATER_SEALED_CHAMBER, UNDERWATER_ROUTE134 | Braille |
| Grotte Zénith | SCORCHED_SLAB | Grotte |
| Pilier Céleste | SKY_PILLAR_ENTRANCE, OUTSIDE, 1F à 5F, TOP | Tileset Pacifidlog ; layouts « _CLEAN » alternatifs ; Rayquaza |
| Tour Mirage | MIRAGE_TOWER_1F à 4F | Tileset MirageTower, sable, fossiles |
| Voie du Désert | DESERT_UNDERPASS | Grotte |
| Grotte Atelier | ARTISAN_CAVE_1F, B1F | Grotte |
| Légendaires errants (post-game) | MARINE_CAVE_ENTRANCE/END + UNDERWATER_MARINE_CAVE (Kyogre), TERRA_CAVE_ENTRANCE/END (Groudon) | Grotte |
| Grotte Métamo | ALTERING_CAVE | Musique `MUS_RG_SEVII_CAVE` |

#### Zones spéciales (groupe `gMapGroup_SpecialArea`)

| Lieu | Maps et remarques |
|---|---|
| Parc Safari | SAFARI_ZONE_NORTHWEST, NORTH, NORTHEAST, SOUTHWEST, SOUTH, SOUTHEAST (connectés entre eux), REST_HOUSE |
| Zone de Combat | BATTLE_FRONTIER_OUTSIDE_WEST/EAST (connectés, `MUS_B_FRONTIER`) ; Tour (LOBBY, ELEVATOR, CORRIDOR, BATTLE_ROOM, MULTI_*) ; Dôme ; Palace ; Pyramide (LOBBY, FLOOR, TOP + 16 `BATTLE_PYRAMID_SQUARE01` à `16` dans IndoorDynamic) ; Arène ; Usine ; Reptile (Pike) ; RANKING_HALL ; LOUNGE1 à 9 ; EXCHANGE_SERVICE_CORNER ; SCOTTS_HOUSE ; RECEPTION_GATE ; POKEMON_CENTER ; MART |
| Mont Dresseurs (Trainer Hill) | TRAINER_HILL_ENTRANCE, 1F à 4F, ROOF, ELEVATOR |
| Îles d'événement | SOUTHERN_ISLAND_EXTERIOR/INTERIOR (Latios/Latias), FARAWAY_ISLAND_ENTRANCE/INTERIOR (Mew), BIRTH_ISLAND_EXTERIOR/HARBOR (Deoxys), NAVEL_ROCK_EXTERIOR/HARBOR/ENTRANCE/B1F/FORK/UP1 à UP4/TOP/DOWN01 à DOWN11/BOTTOM (Ho-Oh et Lugia, `MUS_RG_SEVII_*`) |

#### Groupe dynamique (`gMapGroup_IndoorDynamic`)

- 24 Bases Secrètes : RED/BROWN/BLUE/YELLOW_CAVE1 à 4, TREE1 à 4, SHRUB1 à 4.
- Salles de câble : BATTLE_COLOSSEUM_2P/4P, TRADE_CENTER, RECORD_CORNER, UNION_ROOM.
- Salles de concours : CONTEST_HALL et ses variantes BEAUTY/TOUGH/COOL/SMART/CUTE.
- INSIDE_OF_TRUCK (intro).
- Aqualine : SS_TIDAL_CORRIDOR, LOWER_DECK, ROOMS (9 dresseurs).

### 1.6 Maps inutilisées ou prototypes **[V]**

| Élément | Statut |
|---|---|
| `MAP_ROUTE104_PROTOTYPE`, `MAP_ROUTE104_PROTOTYPE_PRETTY_PETAL_FLOWER_SHOP` | Aucun warp n'y mène. Vides (0 PNJ). Réutilisables comme coquilles. |
| `MAP_LILYCOVE_CITY_UNUSED_MART` | Boutique vide, non reliée. |
| `MAP_UNUSED_CONTEST_HALL1` à `6` | `MUS_GSC_PEWTER`, vides. |
| `MAP_AQUA_HIDEOUT_UNUSED_RUBY_MAP1` à `3`, `MAP_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1` à `3` | Restes de Rubis/Saphir, non reliés. |
| Layouts sans map (35) | `UNUSED_CAVE1` à `14`, `UNUSED_OUTDOOR_AREA`, `FALLARBOR_TOWN_LEFTOVER_RSCONTEST_LOBBY/HALL`, `UNUSED_CONTEST_ROOM1` à `3`, `BATTLE_FRONTIER_BATTLE_PIKE_ROOM_UNUSED`, `CAVE_OF_ORIGIN_UNUSED_B4F_LAVA`. |
| Layouts alternatifs (utilisés par script, `setmaplayoutindex`) | `ROUTE130_MIRAGE_ISLAND`, `ROUTE131_SKY_PILLAR`, `ROUTE111_NO_MIRAGE_TOWER`, `SKY_PILLAR_*_CLEAN`, `SOOTOPOLIS_CITY_LEGENDS_BATTLE`, `SEAFLOOR_CAVERN_ROOM9_LAVA`, `LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE`, `SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_STAIRS_UNBLOCKED` |
| Tilesets secondaires `unused_1`, `unused_2` | Présents dans `data/tilesets/secondary`. |

Le tutoriel `docs/tutorials/how_to_delete_vanilla_maps.md` décrit la suppression propre des maps vanilla.

### 1.7 Maps RFVF (Kanto et Sevii) : disponibles dans la build Émeraude ? **[V]**

**Réponse : non.** Elles ne sont ni compilées ni accessibles dans la build par défaut (`make`, c'est-à-dire `GAME_VERSION=EMERALD`, `MAP_VERSION=emerald`). Elles ne servent qu'à `make firered` et `make leafgreen`, qui produisent deux ROMs séparées.

Preuves :

1. **Makefile.** `MAP_VERSION ?= emerald` ; il passe à `firered` seulement avec `make firered` ou `make leafgreen`. `-D$(GAME_VERSION)` définit `IS_FRLG` (`include/constants/global.h`).
2. **`tools/mapjson/mapjson.cpp`, `process_groups`.** Toute map dont `region` ≠ `REGION_HOENN` est rangée dans `invalid_maps`, puis exclue de `groups.inc`, `headers.inc`, `connections.inc` et `events.inc`. Un groupe vide devient `.4byte NULL`. Les IDs `MAP_*_FRLG` restent donc définis, mais leur groupe est NULL. `clean_heal_locations` neutralise aussi les heal locations hors version.
3. **Layouts.** Ceux avec `layout_version: "frlg"` deviennent `NULL` dans `layouts_table.inc` en build Émeraude.
4. **`#if IS_FRLG`.** Ce garde entoure les tilesets RFVF (`src/data/tilesets/graphics.h`, `headers.h`, `metatiles.h`), les scripts des maps RFVF (`data/event_scripts.s` : `.if IS_FRLG` puis `@ FRLG scripts`), les sprites OW de RFVF (`src/data/object_events/*.h`) et les dresseurs (`src/data.c` inclut `trainers_frlg.h` **ou** `trainers.h`).
5. **Documentation du projet.** `docs/tutorials/how_to_frlg.md` le dit explicitement : une map d'un groupe RFVF ne peut ni être warpée ni connectée depuis une map Émeraude, et inversement.

Pour **porter** des maps de Kanto dans la build Émeraude, il faudrait :

- passer `region` à `REGION_HOENN` et `layout_version` à `emerald` (ou bien sortir la logique de version) ;
- retirer les gardes `IS_FRLG` autour des tilesets nécessaires (les formats de metatiles RFVF diffèrent : `NUM_METATILES_IN_PRIMARY_FRLG` et `METATILE_ATTR_*_FRLG`, voir `migration_scripts/frlg_metatile_behavior_converter.py`), ainsi qu'autour des scripts et des sprites OW ;
- vérifier l'espace ROM.

C'est un **chantier conséquent, déconseillé** pour un scénario Hoenn. En revanche, **les musiques `MUS_RG_*` et les portraits de dresseurs RFVF sont utilisables directement** dans Émeraude.

Pour référence, contenu RFVF (build FRLG uniquement) :

- **Villes et routes** : Bourg Palette, Jadielle, Argenta, Azuria, Lavanville, Carmin sur Mer, Céladopole, Parmanie, Cramois'Île, Plateau Indigo, Safrania, Routes 1 à 25, Îles 1 à 7 et leurs routes (Route Tison, Plage Trésor, Cap Falaise, Pont du Lien, Camp de Vacances, Labyrinthe d'O, Pré, Mémorial, Île du Lointain, Chemin Vert, Agualcanal, Vallée Ruine, Tour Dresseurs, Canyon Sésor, Ruines Tanoby).
- **Donjons** : Forêt de Jade, Mont Sélénite, L'Océane (S.S. Anne), Souterrain, Cave Taupiqueur, Route Victoire, Repaire Rocket, Sylphe SARL, Manoir, Safari, Caverne Azurée, Ligue, Grotte, Îles Écume (glace), Tour Pokémon, Centrale, Mont Braise, Bois Baies, Grotte de Glace, Entrepôt Rocket, Trou Percé, Forbuissons, Grotte Métamo, Grotte Perdue, Chambres Tanoby, Roc Nombri et Île Aurore version RFVF.

---

## 2. Sections de carte régionale et noms de lieux **[V]**

- **Source unique** : `src/data/region_map/region_map_sections.json` (209 entrées `id`, `name`, `x`, `y`, `width`, `height`).
- Fichiers générés par `json_data_rules.mk` avec les gabarits `*.json.txt` : `include/constants/region_map_sections.h` (enum `MAPSEC_*`) et `src/data/region_map/region_map_entries.h` (`gRegionMapEntries`, avec `COMPOUND_STRING(name)`).
- Chaque map référence sa section par `"region_map_section": "MAPSEC_..."` dans `map.json`. Ce nom sert au pop-up d'entrée, à la carte, au lieu de capture et à la Pokénav.

**Noms FR de Hoenn** (`MAPSEC_` omis) :

- **Villes** : LITTLEROOT_TOWN=BOURG-EN-VOL ; OLDALE_TOWN=ROSYERES ; DEWFORD_TOWN=VILLAGE MYOKARA ; LAVARIDGE_TOWN=VERMILAVA ; FALLARBOR_TOWN=AUTEQUIA ; VERDANTURF_TOWN=VERGAZON ; PACIFIDLOG_TOWN=PACIFIVILLE ; PETALBURG_CITY=CLEMENTI-VILLE ; SLATEPORT_CITY=POIVRESSEL ; MAUVILLE_CITY=LAVANDIA ; RUSTBORO_CITY=MEROUVILLE ; FORTREE_CITY=CIMETRONELLE ; LILYCOVE_CITY=NENUCRIQUE ; MOSSDEEP_CITY=ALGATIA ; SOOTOPOLIS_CITY=ATALANOPOLIS ; EVER_GRANDE_CITY=ETERNARA.
- **Routes** : ROUTE_101 à 104, 110 à 121 et 123 = « ROUTE n » ; 105 à 109, 122 et 124 à 134 = « CHENAL n » ; UNDERWATER_* = FOND MARIN.
- **Lieux** : GRANITE_CAVE=GROTTE GRANITE, MT_CHIMNEY=MONT CHIMNEE, SAFARI_ZONE=PARC SAFARI, BATTLE_FRONTIER=ZONE DE COMBAT, PETALBURG_WOODS=BOIS CLEMENTI, RUSTURF_TUNNEL=TUNNEL MERAZON, ABANDONED_SHIP=EPAVE, NEW_MAUVILLE=NEW LAVANDIA, METEOR_FALLS=SITE METEORE, MT_PYRE=MONT MEMORIA, AQUA_HIDEOUT(_OLD)=PLANQUE AQUA, MAGMA_HIDEOUT=PLANQUE MAGMA, SHOAL_CAVE=GROTTE TREFONDS, SEAFLOOR_CAVERN=CAVERNE FONDMER, VICTORY_ROAD=ROUTE VICTOIRE, MIRAGE_ISLAND=ILE MIRAGE, CAVE_OF_ORIGIN=GROTTE ORIGINE, SOUTHERN_ISLAND=ILE DU SUD, FIERY_PATH=CHEMIN ARDENT, JAGGED_PASS=SENTIER SINUROC, SEALED_CHAMBER=SANCTUAIRE, SCORCHED_SLAB=GROTTE ZENITH, ISLAND_CAVE=GROTTE ISLAND, DESERT_RUINS=RUINES DESERT, ANCIENT_TOMB=TOMBEAU ANTIQUE, INSIDE_OF_TRUCK=CAMIONNETTE, SKY_PILLAR=PILIER CELESTE, SECRET_BASE=BASE SECRETE, MIRAGE_TOWER=TOUR MIRAGE, BIRTH_ISLAND=ILE AURORE, FARAWAY_ISLAND=ILE LOINTAINE, ARTISAN_CAVE=GROTTE ATELIER, MARINE_CAVE=GROTTE MARINE, TERRA_CAVE=GROTTE TERRA, DESERT_UNDERPASS=VOIE DU DESERT, ALTERING_CAVE=GROTTE METAMO, NAVEL_ROCK=ROC NOMBRI, TRAINER_HILL=MONT DRESSEURS.
- Les sections Kanto et Sevii sont dans le même fichier (BOURG PALETTE, JADIELLE, etc.). Elles sont compilées dans Émeraude, car l'enum est commun.

**Difficulté de renommage : faible à moyenne.**

- Pop-up et carte : il suffit d'éditer `name` dans le JSON. Limite pratique d'environ 16 caractères, à cause de la largeur du pop-up et de la carte.
- Les noms sont aussi **écrits en dur dans les dialogues** (`data/maps/*/scripts.inc`, `data/text/*.inc`, `src/strings.c`, etc.). Mesuré : MEROUVILLE 37 occurrences dans 16 fichiers, POIVRESSEL 64 dans 34, LAVANDIA 36 dans 17, BOURG-EN-VOL 10 dans 8. Il faut faire un remplacement global par `grep`.
- Les identifiants techniques (`MAP_RUSTBORO_CITY`, `MAPSEC_RUSTBORO_CITY`) peuvent rester tels quels.
- Coordonnées sur la carte : `x`, `y`, `width`, `height` dans le JSON. Le **dessin** de la carte vient de `graphics/pokenav/region_map/` (tilemap) et de `src/data/region_map/region_map_layout*.h`. Changer la géographie demande donc de redessiner.
- `graphics/pokenav/region_map/city_zoom_text.png` ne contient que des libellés de bâtiments (CENTRE POKéMON, ARENE, ZONE DE COMBAT, CONCOURS), pas de noms de ville. Il ne bloque pas le renommage.
- Pour une nouvelle ville, il faut aussi une `city_maps/*` (zoom Pokénav) et une entrée dans `city_map_entries.h`.

---

## 3. Dresseurs : portraits, classes, musiques **[V]**

Sources :

- `include/constants/trainers.h` : enum `TrainerPicID`, `TRAINER_CLASS_*`, `TRAINER_ENCOUNTER_MUSIC_*`.
- `src/data/graphics/trainers.h` : 327 lignes `INCGFX`, sans aucun `#if`, donc toutes les images sont compilées dans les deux builds.
- `graphics/trainers/front_pics/` : 180 PNG.
- `graphics/trainers/back_pics/` : 11 PNG.

Les parties de dresseurs sont dans **`src/data/trainers.party`** (format Showdown, 855 entrées) pour la build Émeraude. `trainers_frlg.party` (624 entrées) ne sert qu'à la build FRLG.

### 3.1 Portraits de face (`TRAINER_PIC_*`, 159 valeurs avec `NONE`)

**Protagonistes et personnages nommés de Hoenn**

| Constantes | Notes |
|---|---|
| BRENDAN, MAY | Protagonistes Émeraude |
| RS_BRENDAN, RS_MAY | Version Rubis/Saphir : variante alternative pour un double ou un clone |
| WALLY | Timmy |
| STEVEN | Pierre |
| CHAMPION_WALLACE | Marc |
| AQUA_LEADER_ARCHIE | Arthur |
| MAGMA_LEADER_MAXIE | Max |
| AQUA_ADMIN_M, AQUA_ADMIN_F | Matt et Sarah (Shelly) |
| MAGMA_ADMIN | Un seul portrait pour Courtney et Tabitha |
| INTERVIEWER | Duo de reporters (Gabby et Ty) |

**Champions d'arène de Hoenn** : LEADER_ROXANNE, LEADER_BRAWLY, LEADER_WATTSON, LEADER_FLANNERY, LEADER_NORMAN, LEADER_WINONA, LEADER_TATE_AND_LIZA, LEADER_JUAN.

**Conseil 4 de Hoenn** : ELITE_FOUR_SIDNEY, ELITE_FOUR_PHOEBE, ELITE_FOUR_GLACIA, ELITE_FOUR_DRAKE.

**Sbires** : AQUA_GRUNT_M, AQUA_GRUNT_F, MAGMA_GRUNT_M, MAGMA_GRUNT_F.

**Têtes de la Zone de Combat** : SALON_MAIDEN_ANABEL, DOME_ACE_TUCKER, PALACE_MAVEN_SPENSER, ARENA_TYCOON_GRETA, FACTORY_HEAD_NOLAND, PIKE_QUEEN_LUCY, PYRAMID_KING_BRANDON.

**Classes génériques de Hoenn** : HIKER, POKEMON_BREEDER_F/M, COOLTRAINER_M/F, BIRD_KEEPER, COLLECTOR, SWIMMER_M/F, EXPERT_M/F, BLACK_BELT, HEX_MANIAC, AROMA_LADY, RUIN_MANIAC, TUBER_F/M, LADY, BEAUTY, RICH_BOY, POKEMANIAC, GUITARIST, KINDLER, CAMPER, PICNICKER, BUG_MANIAC, PSYCHIC_M/F, GENTLEMAN, SCHOOL_KID_M/F, SR_AND_JR, POKEFAN_M/F, YOUNGSTER, FISHERMAN, CYCLING_TRIATHLETE_M/F, RUNNING_TRIATHLETE_M/F, SWIMMING_TRIATHLETE_M/F, DRAGON_TAMER, NINJA_BOY, BATTLE_GIRL, PARASOL_LADY, TWINS, SAILOR, BUG_CATCHER, POKEMON_RANGER_M/F, LASS, YOUNG_COUPLE, OLD_COUPLE, SIS_AND_BRO.

**Kanto et divers, disponibles dans Émeraude** : RED, LEAF, POKEDUDE (Professeur Pokémon de la TV ABC), OLD_MAN.

**Personnages nommés RFVF**

| Constantes | Notes |
|---|---|
| PROFESSOR_OAK_FRLG | Chen |
| RIVAL_EARLY_FRLG, RIVAL_LATE_FRLG, CHAMPION_RIVAL_FRLG | Blue, en 3 tenues |
| LEADER_GIOVANNI_FRLG | Giovanni |
| LEADER_BROCK_FRLG, LEADER_MISTY_FRLG, LEADER_LT_SURGE_FRLG, LEADER_ERIKA_FRLG, LEADER_KOGA_FRLG, LEADER_BLAINE_FRLG, LEADER_SABRINA_FRLG | Champions de Kanto |
| ELITE_FOUR_LORELEI_FRLG, ELITE_FOUR_BRUNO_FRLG, ELITE_FOUR_AGATHA_FRLG, ELITE_FOUR_LANCE_FRLG | Conseil 4 de Kanto |
| ROCKET_GRUNT_M_FRLG, ROCKET_GRUNT_F_FRLG | Team Rocket |

**Classes génériques RFVF** : POKEMON_RANGER_M/F_FRLG, AROMA_LADY_FRLG, YOUNGSTER_FRLG, BUG_CATCHER_FRLG, LASS_FRLG, SAILOR_FRLG, CAMPER_FRLG, PICNICKER_FRLG, POKEMANIAC_FRLG, HIKER_FRLG, FISHERMAN_FRLG, SWIMMER_M/F_FRLG, BEAUTY_FRLG, PSYCHIC_M/F_FRLG, BIRD_KEEPER_FRLG, BLACK_BELT_FRLG, COOLTRAINER_M/F_FRLG, GENTLEMAN_FRLG, TWINS_FRLG, YOUNG_COUPLE_FRLG, SIS_AND_BRO_FRLG, TUBER_F_FRLG, RUIN_MANIAC_FRLG, LADY_FRLG, SUPER_NERD_FRLG, BIKER_FRLG, BURGLAR_FRLG, ENGINEER_FRLG, CUE_BALL_FRLG, GAMER_FRLG, ROCKER_FRLG, JUGGLER_FRLG, TAMER_FRLG, SCIENTIST_FRLG, CHANNELER_FRLG, COOL_COUPLE_FRLG, CRUSH_KIN_FRLG, CRUSH_GIRL_FRLG, POKEMON_BREEDER_FRLG, PAINTER_FRLG.

**PNG présents sans constante** (24, faciles à brancher en ajoutant une entrée à l'enum et à `src/data/graphics/trainers.h`) : `wally_frlg`, `champion_steven_frlg`, `collector_frlg`, `cycling_triathlete_f/m_frlg`, `dragon_tamer_frlg`, `expert_f/m_frlg`, `guitarist_frlg`, `hex_maniac_frlg`, `interviewer_frlg`, `kindler_frlg`, `parasol_lady_frlg`, `pokefan_f/m_frlg`, `rich_boy_frlg`, `running_triathlete_f/m_frlg`, `school_kid_f/m_frlg`, `sr_and_jr_frlg`, `swimming_triathlete_f/m_frlg`, `tuber_m_frlg`.

**Absents** :

- Aucun portrait de combat pour Birch, la Maman, Scott, Lanette, Cosmo ou les admins Magma distincts.
- Aucun portrait au-delà de la Gen 3. Tout nouveau personnage nommé exige un nouveau PNG 64×64 et sa palette.

**Portraits de dos (11)** : brendan, may, brendan_rs, may_rs, red, leaf, wally, steven, pokedude, old_man, none.

**Usage dans `trainers.party` (Émeraude)** : les plus utilisés sont Swimmer M (34), Swimmer F (30), Cooltrainer F (30), Cooltrainer M (26), Hiker et Bird Keeper (23), Fisherman (22), Magma Grunt M (21). **Aucun portrait `_FRLG` n'est utilisé** : ils sont tous libres pour de nouveaux PNJ.

### 3.2 Classes (`TRAINER_CLASS_*`) et noms FR (`src/battle_main.c`, `gTrainerClasses`)

**Classes de Hoenn**

PKMN_TRAINER_1/2=DRESSEUR ; HIKER=MONTAGNARD ; TEAM_AQUA=TEAM AQUA ; PKMN_BREEDER=ELEVEUR ; COOLTRAINER(_2)=TOPDRESSEUR ; BIRD_KEEPER=ORNITHOLOGUE ; COLLECTOR=COLLEC ; SWIMMER_M=NAGEUR ; TEAM_MAGMA=TEAM MAGMA ; EXPERT=EXPERT ; AQUA_ADMIN=ADMIN AQUA ; BLACK_BELT=KARATEKA ; AQUA_LEADER=LEADER AQUA ; HEX_MANIAC=MYSTIMANIAC ; AROMA_LADY=AROMA ; RUIN_MANIAC=RUINEMANIAC ; INTERVIEWER=JOURNALISTES ; TUBER_F/M=FLOTTEUR ; LADY=MADEMOISELLE ; BEAUTY=CANON ; RICH_BOY=RICHARD ; POKEMANIAC=POKéMANIAC ; GUITARIST=GUITARISTE ; KINDLER=SALTIMBANQUE ; CAMPER=CAMPEUR ; PICNICKER=PIQUE-NIQUE ; BUG_MANIAC=ENTOMOMANIAC ; PSYCHIC=KINESISTE ; GENTLEMAN=GENTLEMAN ; ELITE_FOUR=CONSEIL 4 ; LEADER=CHAMPION ; SCHOOL_KID=ELEVE ; SR_AND_JR=SR. ET JR. ; WINSTRATE=STRATEGE ; POKEFAN=POKéFAN ; YOUNGSTER=GAMIN ; CHAMPION=MAITRE ; FISHERMAN=PECHEUR ; TRIATHLETE=TRIATHLETE ; DRAGON_TAMER=DRACOLOGUE ; NINJA_BOY=NINJA FAN ; BATTLE_GIRL=COMBATTANTE ; PARASOL_LADY=SŒUR PARASOL ; SWIMMER_F=NAGEUSE ; TWINS=JUMELLES ; SAILOR=MARIN ; MAGMA_ADMIN=ADMIN MAGMA ; RIVAL=DRESSEUR ; BUG_CATCHER=SCOUT ; PKMN_RANGER={PKMN} RANGER ; MAGMA_LEADER=LEADER MAGMA ; LASS=FILLETTE ; YOUNG_COUPLE=JEUNE COUPLE ; OLD_COUPLE=VIEUX COUPLE ; SIS_AND_BRO=FRERE & SŒUR ; SALON_MAIDEN=AS DU SALON ; DOME_ACE=STAR DU DOME ; PALACE_MAVEN=CAPT. PALACE ; ARENA_TYCOON=PRO DU DOJO ; FACTORY_HEAD=CHEF D'USINE ; PIKE_QUEEN=REINE VENIN ; PYRAMID_KING=ROI PYRAMIDE ; RS_PROTAG=DRESSEUR.

**Classes RFVF** (compilées partout)

YOUNGSTER=GAMIN, BUG_CATCHER=SCOUT, LASS=FILLETTE, SAILOR=MARIN, CAMPER=CAMPEUR, PICNICKER=PIQUE-NIQUE, POKEMANIAC=POKéMANIAC, SUPER_NERD=INTELLO, HIKER=MONTAGNARD, BIKER=MOTARD, BURGLAR=PILLARD, ENGINEER=MECANO, FISHERMAN=PECHEUR, SWIMMER_M/F=NAGEUR/NAGEUSE, CUE_BALL=LOUBARD, GAMER=CROUPIER, BEAUTY=CANON, PSYCHIC=KINESISTE, ROCKER=ROCKER, JUGGLER=JONGLEUR, TAMER=DOMPTEUR, BIRD_KEEPER=ORNITHOLOGUE, BLACK_BELT=KARATEKA, RIVAL_EARLY/LATE=RIVAL, SCIENTIST=SCIENTIFIQUE, **BOSS=BOSS**, LEADER=CHAMPION, TEAM_ROCKET=TEAM ROCKET, COOLTRAINER=TOPDRESSEUR, ELITE_FOUR=CONSEIL 4, GENTLEMAN=GENTLEMAN, CHAMPION=MAITRE, CHANNELER=EXORCISTE, TWINS=JUMELLES, COOL_COUPLE=COUPLE COOL, YOUNG_COUPLE=JEUNE COUPLE, CRUSH_KIN=DUO BASTON, SIS_AND_BRO=FRERE & SŒUR, PKMN_PROF=PROF. {PKMN}, PLAYER=JOUEUR, CRUSH_GIRL=FILLE BASTON, TUBER=FLOTTEUR, PKMN_BREEDER=ELEVEUR, PKMN_RANGER={PKMN} RANGER, AROMA_LADY=AROMA, RUIN_MANIAC=RUINEMANIAC, LADY=MADEMOISELLE, PAINTER=PEINTRE. Toutes portent le suffixe `_FRLG`.

Les classes `BOSS_FRLG`, `PKMN_PROF_FRLG`, `SCIENTIST_FRLG`, `ENGINEER_FRLG`, `BURGLAR_FRLG`, `PAINTER_FRLG` et `CHANNELER_FRLG` sont **utilisables dans Émeraude** pour de nouveaux rôles narratifs (chef de faction, professeur adversaire, etc.).

### 3.3 Musique de combat selon la classe (`GetBattleBGM`, `src/pokemon.c`)

| Classe | Musique |
|---|---|
| AQUA_LEADER, MAGMA_LEADER | `MUS_VS_AQUA_MAGMA_LEADER` |
| TEAM_AQUA, TEAM_MAGMA, AQUA_ADMIN, MAGMA_ADMIN | `MUS_VS_AQUA_MAGMA` |
| LEADER | `MUS_VS_GYM_LEADER` |
| CHAMPION | `MUS_VS_CHAMPION` |
| RIVAL | `MUS_VS_RIVAL`, sauf si le nom est celui de Timmy (`MUS_VS_TRAINER`) |
| ELITE_FOUR | `MUS_VS_ELITE_FOUR` |
| CHAMPION_FRLG | `MUS_RG_VS_CHAMPION` |
| LEADER_FRLG, ELITE_FOUR_FRLG | `MUS_RG_VS_GYM_LEADER` |
| Têtes de la Zone de Combat | `MUS_VS_FRONTIER_BRAIN` |
| Autres classes | `MUS_VS_TRAINER`, ou `MUS_RG_VS_TRAINER` si la région courante est Kanto |
| Légendaires (`BATTLE_TYPE_LEGENDARY`) | `MUS_VS_RAYQUAZA`, `MUS_VS_KYOGRE_GROUDON`, `MUS_VS_REGI` (inclut Regigigas, Regieleki, Regidrago), sinon `MUS_RG_VS_LEGEND` |

À noter :

- `BOSS_FRLG` (Giovanni) n'a pas de cas dédié : il retombe sur `MUS_VS_TRAINER`.
- Pour donner un thème à un nouveau boss, il faut ajouter un `case` dans `GetBattleBGM`.

### 3.4 Musique de rencontre (champ `Music:` de `.party`)

| Valeur | Morceau | Classes vanilla typiques | Nb dans `trainers.party` |
|---|---|---|---|
| Male | `MUS_ENCOUNTER_MALE` | Gamin, Scout, Marin, Campeur, etc. | 145 |
| Female | `MUS_ENCOUNTER_FEMALE` | Fillette, Canon, Aroma, etc. | 118 |
| Girl | `MUS_ENCOUNTER_GIRL` | Flotteuse, Pique-nique, Élève F | 49 |
| Suspicious | `MUS_ENCOUNTER_SUSPICIOUS` | Ninja, Mystimaniac, Collec | 50 |
| Intense | `MUS_ENCOUNTER_INTENSE` | Karatéka, Kinésiste, Dracologue, Experts | 110 |
| Cool | `MUS_ENCOUNTER_COOL` | Topdresseur, Ranger, Ornithologue | 93 |
| Aqua | `MUS_ENCOUNTER_AQUA` | Team Aqua | 31 |
| Magma | `MUS_ENCOUNTER_MAGMA` | Team Magma | 32 |
| Swimmer | `MUS_ENCOUNTER_SWIMMER` | Nageurs | 94 |
| Twins | `MUS_ENCOUNTER_TWINS` | Jumelles, Pokéfans | 35 |
| Elite Four | `MUS_ENCOUNTER_ELITE_FOUR` | Conseil 4 | 4 |
| Hiker | `MUS_ENCOUNTER_HIKER` | Montagnards, Pêcheurs, Saltimbanques | 71 |
| Interviewer | `MUS_ENCOUNTER_INTERVIEWER` | Journalistes | 6 |
| Rich | `MUS_ENCOUNTER_RICH` | Richard, Gentleman | 17 |

Autres thèmes de rencontre disponibles via script (`playbgm`) : `MUS_ENCOUNTER_MAY`, `MUS_ENCOUNTER_BRENDAN`, `MUS_ENCOUNTER_CHAMPION`, `MUS_RG_ENCOUNTER_ROCKET`, `MUS_RG_ENCOUNTER_RIVAL`, `MUS_RG_ENCOUNTER_GYM_LEADER`, `MUS_RG_ENCOUNTER_GIRL`, `MUS_RG_ENCOUNTER_BOY`, `MUS_RG_ENCOUNTER_DEOXYS`.

Le format `.party` accepte aussi `Mugshot` (Purple/Green/Pink/Blue/Yellow), `Battle Type: Doubles`, `AI`, `Items`, `Tera Type`, `Dynamax Level` et `Gigantamax`, ainsi que les combats multi avec partenaire (`battle_partners.party`).

---

## 4. Sprites d'overworld (`OBJ_EVENT_GFX_*`) **[V]**

Source : `include/constants/event_objects.h` (enum terminé par `NUM_OBJ_EVENT_GFX`) et `src/data/object_events/object_event_graphics_info_pointers.h`.

**Disponibilité.**

- Tout ce qui précède `RED_NORMAL` dans l'enum est compilé dans Émeraude.
- Le bloc de `RED_NORMAL` à `BREAKABLE_ROCK_FRLG` est sous **`#if IS_FRLG`** : ces sprites n'existent pas dans la build Émeraude. Il faudrait retirer le garde, et prévoir leurs palettes.

**Joueur, rival et liens**

BRENDAN_ et MAY_ en variantes NORMAL, MACH_BIKE, ACRO_BIKE, SURFING, UNDERWATER, FIELD_MOVE, FISHING, WATERING et DECORATING ; RIVAL_BRENDAN_ et RIVAL_MAY_ en NORMAL, MACH_BIKE, ACRO_BIKE, SURFING et FIELD_MOVE ; LINK_BRENDAN, LINK_MAY, LINK_RS_BRENDAN, LINK_RS_MAY ; RED et LEAF (sprites simples, compilés dans Émeraude).

**PNJ génériques**

QUINTY_PLUMP, NINJA_BOY, TWIN, BOY_1/2/3, GIRL_1/2/3, LITTLE_BOY, LITTLE_GIRL, LITTLE_BOY_3, RICH_BOY, WOMAN_1 à 5, FAT_MAN, POKEFAN_F/M, MAN_1 à 5, EXPERT_M/F, COOK, OLD_MAN, OLD_WOMAN, HOT_SPRINGS_OLD_WOMAN, CAMPER, PICNICKER, YOUNGSTER, BUG_CATCHER, PSYCHIC_M, SCHOOL_KID_M, MANIAC, HEX_MANIAC, SWIMMER_M/F, BLACK_BELT, BEAUTY, SCIENTIST_1/2, LASS, GENTLEMAN, SAILOR, FISHERMAN, RUNNING_TRIATHLETE_M/F, CYCLING_TRIATHLETE_M/F, TUBER_F/M, TUBER_M_SWIMMING, HIKER, GAMEBOY_KID, ARTIST, CAMERAMAN, REPORTER_M/F, BARD (et, via la table Mauville Man, Hipster, Trader, Storyteller).

**Personnel**

NURSE, UNION_ROOM_NURSE, MART_EMPLOYEE, ROOFTOP_SALE_WOMAN, LINK_RECEPTIONIST, DEVON_EMPLOYEE, CONTEST_JUDGE, MYSTERY_GIFT_MAN, TEALA.

**Personnages nommés de Hoenn**

PROF_BIRCH, MOM, WALLY, STEVEN, SCOTT, ARCHIE, MAXIE, AQUA_MEMBER_M/F, MAGMA_MEMBER_M/F, ROXANNE, BRAWLY, WATTSON, FLANNERY, NORMAN, WINONA, LIZA, TATE, JUAN, SIDNEY, PHOEBE, GLACIA, DRAKE, WALLACE, ANABEL, TUCKER, GRETA, SPENSER, NOLAND, LUCY, BRANDON.

**Pokémon et légendaires (sprites dédiés)**

RAYQUAZA_STILL, RAYQUAZA, KYOGRE_FRONT/SIDE/ASLEEP, GROUDON_FRONT/SIDE/ASLEEP, REGIROCK, REGICE, REGISTEEL, LATIAS, LATIOS, MEW, DEOXYS, DEOXYS_TRIANGLE, LUGIA, HOOH, SKITTY, KECLEON, KECLEON_BRIDGE_SHADOW, ZIGZAGOON_1/2, PIKACHU, AZUMARILL, AZURILL, WINGULL, POOCHYENA, KIRLIA, DUSCLOPS, SUDOWOODO, VIGOROTH_CARRYING_BOX, VIGOROTH_FACING_AWAY.

**Objets et décors**

ITEM_BALL, POKE_BALL, BERRY_TREE (et stades EARLY/LATE), APRICORN_TREE, CUTTABLE_TREE, BREAKABLE_ROCK, PUSHABLE_BOULDER, FOSSIL, MR_BRINEYS_BOAT, SS_TIDAL, SUBMARINE_SHADOW, TRUCK, CABLE_CAR, MOVING_BOX, BIRCHS_BAG, TRICK_HOUSE_STATUE, LIGHT_SPRITE ; poupées et coussins de Base Secrète (environ 45 : PICHU_DOLL … BIG_REGISTEEL_DOLL, PIKA_CUSHION … WATER_CUSHION, UNUSED_*_DOLL).

**Pokémon génériques**

`OBJ_EVENT_GFX_SPECIES(NOM)` (et les variantes `_SHINY`, `_FEMALE`), activé par `OW_POKEMON_OBJECT_EVENTS TRUE` (`include/config/overworld.h`). Il permet de poser **n'importe quelle espèce Gen 1 à 9** comme PNJ. `OBJ_EVENT_GFX_OW_MON` sert au follower.

**Variables** : `OBJ_EVENT_GFX_VAR_0` à `VAR_F` (graphisme choisi par script).

**Bloc RFVF (build FRLG uniquement)**

| Catégorie | Constantes |
|---|---|
| Joueurs | RED_* et GREEN_* (NORMAL, BIKE, SURF, FIELD_MOVE, FISH, VS_SEEKER, VS_SEEKER_BIKE) |
| PNJ | BOY, CRUSH_GIRL, MAN, ROCKER, BALDING_MAN, OLD_MAN_1/2/LYING_DOWN, TUBER_M_WATER/LAND, COOLTRAINER_M/F, SWIMMER_*_WATER/LAND, WORKER_M/F, ROCKET_M/F, GBA_KID, POKE_MANIAC_FRLG, BIKER, BLACK_BELT_FRLG, SCIENTIST, FISHER, CHANNELER, CHEF, POLICEMAN, CAPTAIN, CABLE_CLUB_RECEPTIONIST, UNION_ROOM_RECEPTIONIST, CLERK, MG_DELIVERYMAN, TRAINER_TOWER_DUDE |
| Personnages nommés | PROF_OAK, BLUE, BILL, LANCE, AGATHA, DAISY, LORELEI, MR_FUJI, BRUNO, BROCK, MISTY, LT_SURGE, ERIKA, KOGA, SABRINA, BLAINE, GIOVANNI, CELIO, TEACHY_TV_HOST, GYM_GUY |
| Variantes `*_FRLG` | LITTLE_BOY, LITTLE_GIRL, YOUNGSTER, BUG_CATCHER, LASS, WOMAN_1/2/3, FAT_MAN, BEAUTY, OLD_WOMAN, CAMPER, PICNICKER, MOM, TUBER_F, HIKER, GENTLEMAN, SAILOR, NURSE, FOSSIL |
| Objets | TOWN_MAP, POKEDEX, RUBY, SAPPHIRE, OLD_AMBER, GYM_SIGN, SIGN, TRAINER_TIPS, CLIPBOARD, METEORITE, LAPRAS_DOLL, SEAGALLOP, SS_ANNE, PUSHABLE_BOULDER/CUTTABLE_TREE/BREAKABLE_ROCK_FRLG |
| Pokémon | SNORLAX, SPEAROW, CUBONE, POLIWRATH, CLEFAIRY, PIDGEOT, JIGGLYPUFF, PIDGEY, CHANSEY, OMANYTE, KANGASKHAN, PIKACHU_FRLG, PSYDUCK, NIDORAN_F/M, NIDORINO, MEOWTH, SEEL, VOLTORB, SLOWPOKE, SLOWBRO, MACHOP, WIGGLYTUFF, DODUO, FEAROW, MACHOKE, LAPRAS, ZAPDOS, MOLTRES, ARTICUNO, MEWTWO, ENTEI, SUICUNE, RAIKOU, CELEBI, KABUTO, DEOXYS_D/A/N |

Dans Émeraude, la plupart de ces Pokémon peuvent être remplacés par `OBJ_EVENT_GFX_SPECIES(...)`.

---

## 5. Musique et effets sonores **[V]**

Source : `include/constants/songs.h`. Tout est dans `sound/song_table.inc` sans condition de build, y compris les `MUS_RG_*`. On compte environ 270 constantes `SE_*`, dont environ 130 `SE_M_*` pour les attaques.

| Usage et ambiance | Morceaux |
|---|---|
| Villages paisibles | MUS_LITTLEROOT, MUS_OLDALE, MUS_PETALBURG, MUS_DEWFORD (îlien), MUS_VERDANTURF, MUS_FALLARBOR (mélancolique), MUS_PACIFIDLOG |
| Grandes villes | MUS_RUSTBORO (urbain, aussi Lavandia et Algatia), MUS_SLATEPORT (port), MUS_LILYCOVE, MUS_FORTREE (forestier), MUS_SOOTOPOLIS (mystique), MUS_EVER_GRANDE (solennel) |
| Routes | MUS_ROUTE101 (début), MUS_ROUTE104, MUS_ROUTE110, MUS_ROUTE113 (cendres), MUS_ROUTE118 (alias dynamique), MUS_ROUTE119 (épique), MUS_ROUTE120, MUS_ROUTE122 (mer mélancolique), MUS_SURF, MUS_CYCLING, MUS_SAILING (bateau), MUS_UNDERWATER, MUS_DESERT, MUS_SAFARI_ZONE |
| Donjons et lieux inquiétants | MUS_PETALBURG_WOODS (grottes génériques), MUS_MT_CHIMNEY (tension volcanique), MUS_MT_PYRE et MUS_MT_PYRE_EXTERIOR (deuil, fantômes), MUS_ABANDONED_SHIP, MUS_CAVE_OF_ORIGIN, MUS_SEALED_CHAMBER (ancien), MUS_VICTORY_ROAD, MUS_TRICK_HOUSE |
| Antagonistes | MUS_AQUA_MAGMA_HIDEOUT, MUS_ENCOUNTER_AQUA, MUS_ENCOUNTER_MAGMA, MUS_VS_AQUA_MAGMA, MUS_VS_AQUA_MAGMA_LEADER, MUS_VICTORY_AQUA_MAGMA, MUS_RG_ROCKET_HIDEOUT, MUS_RG_ENCOUNTER_ROCKET, MUS_RG_SILPH |
| Légendaires et cataclysme | MUS_AWAKEN_LEGEND, MUS_ABNORMAL_WEATHER, MUS_WEATHER_GROUDON, MUS_RAYQUAZA_APPEARS, MUS_VS_KYOGRE_GROUDON, MUS_VS_RAYQUAZA, MUS_VS_REGI, MUS_VS_MEW, MUS_RG_VS_LEGEND, MUS_RG_VS_DEOXYS, MUS_RG_VS_MEWTWO, MUS_RG_ENCOUNTER_DEOXYS, MUS_C_VS_LEGEND_BEAST |
| Combats | MUS_VS_WILD, MUS_VS_TRAINER, MUS_VS_GYM_LEADER, MUS_VS_RIVAL, MUS_VS_ELITE_FOUR, MUS_VS_CHAMPION, MUS_VS_FRONTIER_BRAIN, MUS_RG_VS_WILD, MUS_RG_VS_TRAINER, MUS_RG_VS_GYM_LEADER, MUS_RG_VS_CHAMPION, MUS_INTRO_BATTLE |
| Victoires et jingles | MUS_VICTORY_WILD, MUS_VICTORY_TRAINER, MUS_VICTORY_GYM_LEADER, MUS_VICTORY_LEAGUE, MUS_CAUGHT, MUS_LEVEL_UP, MUS_HEAL, MUS_OBTAIN_BADGE, MUS_OBTAIN_ITEM, MUS_OBTAIN_TMHM, MUS_OBTAIN_BERRY, MUS_OBTAIN_B_POINTS, MUS_OBTAIN_SYMBOL, MUS_EVOLVED, MUS_EVOLUTION(_INTRO), MUS_MOVE_DELETED, MUS_TOO_BAD, MUS_REGISTER_MATCH_CALL, MUS_SLOTS_JACKPOT, MUS_SLOTS_WIN |
| Rencontres de dresseurs | MUS_ENCOUNTER_MALE/FEMALE/GIRL/INTENSE/COOL/SUSPICIOUS/SWIMMER/TWINS/HIKER/RICH/INTERVIEWER/ELITE_FOUR/CHAMPION/MAY/BRENDAN, MUS_RG_ENCOUNTER_BOY/GIRL/RIVAL/GYM_LEADER |
| Personnages et scènes | MUS_HELP (danger), MUS_FOLLOW_ME, MUS_RG_FOLLOW_ME, MUS_BIRCH_LAB, MUS_RG_OAK, MUS_RG_OAK_LAB, MUS_RG_RIVAL_EXIT, MUS_SCHOOL, MUS_RG_JIGGLYPUFF, MUS_RG_POKE_FLUTE |
| Bâtiments | MUS_POKE_CENTER, MUS_POKE_MART, MUS_GYM, MUS_GAME_CORNER, MUS_LILYCOVE_MUSEUM, MUS_OCEANIC_MUSEUM, MUS_CONTEST, MUS_CONTEST_LOBBY, MUS_CONTEST_RESULTS, MUS_CONTEST_WINNER, MUS_LINK_CONTEST_P1 à P4, MUS_CABLE_CAR, MUS_ROULETTE, MUS_C_COMM_CENTER |
| Zone de Combat | MUS_B_FRONTIER, MUS_B_TOWER, MUS_B_TOWER_RS, MUS_B_DOME, MUS_B_DOME_LOBBY, MUS_B_PALACE, MUS_B_ARENA, MUS_B_FACTORY, MUS_B_PIKE, MUS_B_PYRAMID, MUS_B_PYRAMID_TOP |
| Finale | MUS_HALL_OF_FAME, MUS_HALL_OF_FAME_ROOM, MUS_CREDITS, MUS_END, MUS_TITLE, MUS_INTRO, MUS_RG_HALL_OF_FAME, MUS_RG_CREDITS, MUS_RG_TITLE |
| RFVF, villes et routes | MUS_RG_PALLET, MUS_RG_SLOW_PALLET, MUS_RG_PEWTER, (pas de MUS_RG_CERULEAN dans songs.h), MUS_RG_VERMILLION, MUS_RG_LAVENDER (lugubre), MUS_RG_CELADON, MUS_RG_FUCHSIA, MUS_RG_CINNABAR, MUS_RG_ROUTE1, MUS_RG_ROUTE3, MUS_RG_ROUTE11, MUS_RG_ROUTE24, MUS_RG_VIRIDIAN_FOREST, MUS_RG_MT_MOON, MUS_RG_POKE_MANSION, MUS_RG_POKE_TOWER (hanté), MUS_RG_SS_ANNE, MUS_RG_VICTORY_ROAD, MUS_RG_SURF, MUS_RG_CYCLING, MUS_RG_GYM, MUS_RG_POKE_CENTER, MUS_RG_GAME_CORNER |
| RFVF, Sevii | MUS_RG_SEVII_123, MUS_RG_SEVII_45, MUS_RG_SEVII_67, MUS_RG_SEVII_ROUTE, MUS_RG_SEVII_CAVE, MUS_RG_SEVII_DUNGEON, MUS_RG_TRAINER_TOWER, MUS_RG_BERRY_PICK, MUS_RG_POKE_JUMP |
| RFVF, divers | MUS_RG_HEAL, MUS_RG_VICTORY_TRAINER/WILD/GYM_LEADER, MUS_RG_CAUGHT(_INTRO), MUS_RG_OBTAIN_KEY_ITEM, MUS_RG_DEX_RATING, MUS_RG_PHOTO, MUS_RG_GAME_FREAK, MUS_RG_NEW_GAME_INTRO/INSTRUCT/EXIT, MUS_RG_INTRO_FIGHT, MUS_RG_UNION_ROOM, MUS_RG_NET_CENTER, MUS_RG_MYSTERY_GIFT, MUS_RG_TEACHY_TV_SHOW/MENU |
| Gen 2 et Colosseum (restes) | MUS_GSC_ROUTE38, MUS_GSC_PEWTER, MUS_C_COMM_CENTER, MUS_C_VS_LEGEND_BEAST, MUS_LITTLEROOT_TEST, MUS_DUMMY |

Note : `MUS_ROUTE118` vaut `0x7FFF`. C'est une valeur spéciale résolue par `GetCurrLocationDefaultMusic()`, qui donne deux musiques selon la position sur la route.

---

## 6. Tilesets **[V]** (`data/tilesets`, `data/layouts/layouts.json`)

**Primaires** : `general` (extérieurs Hoenn), `building` (intérieurs Hoenn), `secret_base`. Les primaires RFVF `general_frlg` et `building_frlg` existent sur disque mais ne sont compilés qu'en FRLG.

**Secondaires Hoenn et maps qui les utilisent** (primaire General, sauf mention Building)

| Tileset | Maps | Ambiance |
|---|---|---|
| Petalburg | Clementi, Bourg-en-Vol, Rosyères, Routes 101 à 103 | Prairie de départ |
| Rustboro | Mérouville, Routes 104 et 116, Bois Clementi, ROUTE104_PROTOTYPE, Île du Sud | Ville de pierre et forêt |
| Dewford | Myokara, Routes 105 à 107, extérieurs de l'Île Aurore et du Roc Nombri | Île, plage, mer |
| Slateport | Poivressel, Routes 108 et 109 | Port, plage |
| Mauville | Lavandia, Vergazon, Routes 110, 111 (**désert**), 117, 118 | Ville et désert |
| Lavaridge | Vermilava, Route 112, Mont Chimnée, Sentier Sinuroc, Chemin Ardent, **Planque Magma** | **Volcanique** et lave |
| Fallarbor | Autequia, Routes 113 (**cendres**), 114, 115, tunnel du maniaque des fossiles | Cendres, collines |
| Fortree | Cimetronelle, Routes 119 et 120, intérieur de l'Île Lointaine | **Jungle**, cabanes dans les arbres |
| Lilycove | Nénucrique, Routes 121 à 123, Parc Safari (6 zones) | Côte, safari |
| Mossdeep | Algatia, Routes 124 à 129 | Île, mer ouverte |
| Pacifidlog | Pacifiville, Routes 131 à 134, Caverne Fondmer salles 6 et 7, **Pilier Céleste** (toutes les salles et le sommet) | Mer, tour céleste en ruine |
| Sootopolis | Atalanopolis (et layout LEGENDS_BATTLE) | Cratère, cité ancienne |
| EverGrande | Éternara | Ligue |
| Underwater | Tous les fonds marins | **Sous-marin** |
| Cave | 61 layouts : Grotte Granite, Caverne Fondmer, Grotte Origine, Route Victoire, Grotte Tréfonds (avec la salle de **glace**), Ruines du Désert, Tombeau Antique, Sanctuaire, Grotte Zénith, Grotte Île, grottes Marine/Terra/Atelier/Métamo, Voie du Désert, Île Mirage, `UNUSED_CAVE*` | Grotte générique |
| MeteorFalls | Site Météore | Cascades |
| RusturfTunnel | Tunnel Mérazon | Tunnel |
| MirageTower | Tour Mirage | **Sable et ruines** |
| NavelRock | Roc Nombri (intérieurs) | Roche mystique |
| InsideShip | Épave, Aqualine | Navire |
| Facility | Chantier, Devon 2F, ports, téléphériques, **Mont Mémoria**, **Planque Aqua**, pont de l'Épave, New Lavandia (entrée) | Industriel et cimetière |
| BikeShop | Magasin de vélos, **New Lavandia** (intérieur) | Technique |
| IslandHarbor | Ports de l'Île Aurore et du Roc Nombri | Quai |
| BattleFrontierOutsideWest/East | Extérieurs de la Zone de Combat | Complexe |
| InsideOfTruck | Camion d'intro | — |
| Building + BrendansMaysHouse, Lab, GenericBuilding (38), Shop (10), PokemonCenter, PokemonSchool, PokemonFanClub, PokemonDayCare, PrettyPetalFlowerShop, SeashoreHouse, OceanicMuseum, LilycoveMuseum, Contest, CableClub, UnionRoom, MysteryEventsHouse, EliteFour, Facility (Devon 1F/3F), MauvilleGameCorner, MossdeepGameCorner, TrickHousePuzzle, TrainerHill, BattleTent | Intérieurs | — |
| Building + arènes : PetalburgGym, RustboroGym, DewfordGym, MauvilleGym, LavaridgeGym, FortreeGym, MossdeepGym, SootopolisGym | Chaque arène a son tileset | — |
| Building + Zone de Combat : BattleFrontier, BattleArena, BattleDome, BattleFactory, BattlePalace, BattlePike, BattlePyramid, BattleFrontierRankingHall | Intérieurs de la Zone de Combat | — |
| SecretBase + SecretBaseRed/Brown/Blue/YellowCave, Tree, Shrub | Bases Secrètes | — |

Tilesets marquants de Hoenn :

- volcanique (Lavaridge) ;
- désert (Route 111 avec Mauville, et Tour Mirage) ;
- cendres (Route 113 avec Fallarbor) ;
- jungle et cabanes (Fortree) ;
- sous-marin (Underwater) ;
- tour céleste (Pilier Céleste) ;
- cratère (Sootopolis) ;
- navire (InsideShip) ;
- cimetière (Mont Mémoria).

**Hoenn n'a pas de tileset neige ou glace dédié** : la glace de la Grotte Tréfonds et de l'arène de Juan est un comportement de metatile.

**Secondaires RFVF (non compilés dans Émeraude)** : pallet_town, viridian_city, pewter_city, cerulean_city, lavender_town, vermilion_city, celadon_city, fuchsia_city, cinnabar_island, saffron_city, indigo_plateau, viridian_forest, cerulean_cave, digletts_cave, rock_tunnel, **seafoam_islands** (glace), **mt_ember** (volcan), **tanoby_ruins** (ruines), **pokemon_tower** (hanté), pokemon_mansion, silph_co, ss_anne, power_plant, berry_forest, sevii_islands_123/45/67, trainer_tower, gyms (pewter, cerulean, vermilion, celadon, fuchsia, saffron, cinnabar, viridian), mart, pokemon_center, lab, school, museum, game_corner, department_store, condominiums, restaurant_hotel, sea_cottage, burgled_house, hall_of_fame, pokemon_league, underground_path, safari_zone_building, fan_club_daycare, generic_building_1/2, hoenn_building, cable_club, bike_shop, island_harbor, navel_rock, unused_gatehouse_1/2 (tous avec le suffixe `_frlg`).

---

## 7. Pokémon **[V]**

- **Espèces** : `NUM_SPECIES` = 1573 IDs (`include/constants/species.h`), toutes générations activées (`include/config/species_enabled.h` : `P_GEN_1` à `P_GEN_9 TRUE`). Dex national jusqu'à `NATIONAL_DEX_PECHARUNT` (1025).
- **Plage personnalisée** : `SPECIES_CUSTOM_START` à `SPECIES_CUSTOM_END` pour les fakémons.
- **Dossiers graphiques** : `graphics/pokemon/` contient 1029 dossiers d'espèces ; on compte 1390 sprites de face (`front.png` ou `anim_front.png`).
- **Style des sprites** : Gen 4/5 par défaut ; `P_GBA_STYLE_SPECIES_GFX FALSE` ; 394 variantes `*_gba` existent.
- **Formes activées** : Méga (`P_MEGA_EVOLUTIONS`, **98 Méga**, y compris celles de Z-A, par ex. MEGA de Clefable, Victreebel, Starmie, Dragonite, Meganium, Feraligatr, Absol Z, Garchomp Z, Lucario Z, Raichu X/Y, Chimecho, Glimmora, Baxcalibur, Scovillain), Primo (Kyogre et Groudon), Ultra-Necrozma, **37 Gigamax** (`P_GIGANTAMAX_FORMS`), formes Téracristal (Terapagos), fusions, et 63 constantes de formes régionales (Alola, Galar, Hisui, Paldea).
- **Sprites d'overworld** : **1299 `overworld.png` + 98 `overworldf.png`** (femelles) + 1 `overworld_neutral`. Toutes les espèces, Gen 9 comprise, ont un sprite OW (par ex. `pecharunt/overworld.png`, `terapagos/overworld.png`). Les seules exceptions sont `alcremie` (sprites rangés dans des sous-dossiers) et `egg`. Les Méga ont souvent un OW (`charizard/mega_x/overworld.png`), les Gigamax **non**. `OW_SUBSTITUTE_PLACEHOLDER TRUE` affiche un sprite de remplacement si l'un manque.
- **Configuration** (`include/config/overworld.h`) :
  - `OW_POKEMON_OBJECT_EVENTS TRUE` : Pokémon utilisables comme PNJ ;
  - **`OW_FOLLOWERS_ENABLED FALSE`** : les followers à la HGSS sont désactivés par défaut, il suffit de passer à TRUE ;
  - `OW_FOLLOWERS_POKEBALLS TRUE` ;
  - `OW_GFX_COMPRESS TRUE`.

---

## 8. Objets **[V]**

- `include/constants/items.h` : `ITEMS_COUNT`, environ 874 entrées dans `src/data/items.h`. `graphics/items/icons/` contient **619 PNG**, partagés entre objets (les CT/CS utilisent une icône générique colorée selon le type).
- **103 constantes `ITEM_TM*`**, **95 Méga-Gemmes** (`ITEM_*ITE`, `*ITE_X/Y/Z`), **35 Cristaux Z**, **19 Téra-Éclats**. On trouve aussi les Méga-Anneau, Super Bracelet Z, Poignet Dynamax, Orbe Téracristal, les baies Gen 1 à 9 et les objets compétitifs modernes.
- **79 objets rares** (`POCKET_KEY_ITEMS`, nom FR entre parenthèses) :
  - **Hoenn** : Passe Bateau (SS_TICKET), Passe Éon, Ticket Mystik, Ticket Aurora, Vieillecarte, Lettre à Pierre, Pack Devon, Lunettes Sable, Devon Scope, Clé Sous-Sol, Scanner, Clé Stockage, Clés Salle 1/2/4/6, Météorite, Sceau Magma, Passe Concours, Wailmerrosoir, Boîte Pokéblocs, Sac à Suie, Pot Poudre, Vélo de Course, Vélo Cross, Canne, Super Canne, Méga Canne, Boîte Jetons, Bon Commande.
  - **Kanto** : Colis, Clé Secrète, Dentier en Or, Carte Magnétique, Clé Ascenseur, Scope Sylphe, Tri-Passe, Passe Prisme, Thé, Rubis, Saphir, Poké Flûte, Memorydex, TV ABC, Boîte CT, Sac à Baies, Bicyclette, Vieil Ambre et les fossiles (Nautile, Dôme, Racine, Griffe).
  - **Modernes** : Multi Exp, Charmes (Ovale, Chroma, Stabilité, Exp, Éclatant), Moti-Catalogue, Gracidée, Miroir Sacré, Pointeau ADN, Boîte Zygarde, Vase Scellé, Necrosol, Necroluna, Rênes de l'Unité, Rouleaux Ténèbres et Eau, Cherch'Objet, Cherch'Combat, Poké Radar, Boîte Pokémon, Carte, Corde Sortie (en poche rare si config).

Pour une intrigue, les objets « MacGuffin » réutilisables sans nouvel asset sont : Météorite, Pack Devon, Devon Scope, Vieillecarte, Scanner, Sceau Magma, Rubis, Saphir, Thé, Colis, Clé Secrète, Rouleaux, Orbe Téracristal.

---

## 9. Scripts et textes réutilisables **[V]**

### Scripts standard (`data/event_scripts.s`, `gStdScripts`)

Messages : `MSGBOX_NPC`, `MSGBOX_SIGN`, `MSGBOX_DEFAULT`, `MSGBOX_YESNO`, `MSGBOX_AUTOCLOSE`, `MSGBOX_GETPOINTS`, `MSGBOX_POKENAV`.

Objets : `STD_OBTAIN_ITEM`, `STD_FIND_ITEM`, `STD_OBTAIN_DECORATION`, `STD_REGISTER_MATCH_CALL`, `STD_PUT_ITEM_AWAY`, `STD_RECEIVED_ITEM`.

### Scripts communs (`Common_EventScript_*`)

| Thème | Scripts |
|---|---|
| Soins et sauvegarde | PkmnCenterNurse, OutOfCenterPartyHeal, SaveGame |
| Objets | FindItem, ShowBagIsFull, BagIsFull, ShowNoRoomForDecor, NoRoomForDecor, PlayerHandedOverTheItem |
| Capacités | MoveRelearner, MoveRelearnerDynMultiChoice |
| Pokémon donnés | GetGiftMonPartySlot, NameReceivedBoxMon, NameReceivedPartyMon, TransferredToPC, NoMoreRoomForPokemon |
| Rival et arènes | SetupRivalGfxId, SetupRivalOnBikeGfxId, SetupRivalGfxIdSameGender, SetGymTrainers (et _Frlg), PlayGymBadgeFanfare, ReadyPetalburgGymForBattle |
| Panneaux | ShowPokemartSign, ShowPokemonCenterSign |
| Transport | FerryDepart, FerryDepartIsland, UpdateBrineyLocation, PlayBrineysBoatMusic, StopBrineysBoatMusic |
| Légendaires et météo | SetAbnormalWeather, RemoveStaticPokemon, LegendaryFlewAway |
| Câble et divers | UnionRoomAttendant, WirelessClubAttendant, DirectCornerAttendant, BufferTrendyPhrase |

### Modules dans `data/scripts/`

| Thème | Fichiers |
|---|---|
| Services | `pkmn_center_nurse.inc`, `mart_clerk.inc`, `pc.inc`, `pc_transfer.inc`, `obtain_item.inc`, `item_ball_scripts.inc` |
| Dresseurs | `trainer_battle.inc`, `trainer_script.inc`, `set_gym_trainers.inc`, `rival_graphics.inc` |
| Ligue | `elite_four.inc`, `pokemon_league.inc`, `hall_of_fame.inc` |
| Capacités | `move_tutors.inc`, `move_relearner.inc`, `field_move_scripts.inc`, `surf.inc`, `flash.inc`, `cave_hole.inc` |
| Rencontres et monde | `static_pokemon.inc`, `wild_encounter.inc`, `abnormal_weather.inc`, `cave_of_origin.inc`, `berry_tree.inc`, `apricorn_tree.inc`, `repel.inc`, `field_poison.inc` |
| Activités | `day_care.inc`, `safari_zone.inc`, `secret_base.inc`, `contest_hall.inc`, `trainer_hill.inc`, `battle_frontier.inc`, `battle_pike.inc` |
| PNJ récurrents | `tv.inc`, `gabby_and_ty.inc`, `interview.inc`, `mauville_man.inc`, `lilycove_lady.inc`, `kecleon.inc`, `prof_birch.inc`, `players_house.inc`, `new_game.inc`, `aide.inc`, `profile_man.inc`, `questionnaire.inc` |
| Cadeaux | `gift_pichu.inc`, `gift_altering_cave.inc`, tickets |
| Expansion | `dexnav.inc`, `follower.inc`, `debug.inc`, `config.inc` |
| Spécifiques RFVF | `*_frlg.inc`, `silphco_doors.inc`, `pokemon_mansion.inc`, `seagallop.inc`, `trainer_tower.inc` |

### Textes génériques (`data/text/*.inc`)

`pkmn_center_nurse.inc`, `obtain_item.inc`, `pc.inc`, `save.inc`, `surf.inc`, `move_tutors.inc`, `move_relearner.inc`, `berries.inc`, `braille.inc`, `match_call.inc`, `pokemon_news.inc`, `tv.inc`, `trainers.inc`, `birch_speech.inc` (texte d'intro du professeur), `abnormal_weather.inc`, `battle_tent.inc`, etc.

### Modèles concrets

- **Centre Pokémon** : `data/maps/OldaleTown_PokemonCenter_1F/scripts.inc` (`setrespawn HEAL_LOCATION_*` puis `call Common_EventScript_PkmnCenterNurse`). Il y a 42 heal locations (`src/data/heal_locations.json`).
- **Boutique** : `pokemart <liste>` suivi de `.2byte ITEM_*`, puis `pokemartlistend`. Voir `OldaleTown_Mart/scripts.inc`, qui a une liste de base et une liste étendue. 23 maps Hoenn utilisent `pokemart`. Shops dynamiques : `docs/tutorials/how_to_dynamic_shop.md`.

### Tutoriels internes (`docs/tutorials/`, en français)

`how_to_frlg.md`, `how_to_delete_vanilla_maps.md`, `how_to_dynamic_weather.md`, `how_to_follower_npc.md` (PNJ qui suit le joueur), `how_to_namebox.md`, `how_to_new_trainer_slide.md`, `how_to_map_preview_screen.md`, `how_to_overworld_wild_encounters.md`, `how_to_dynmultichoice.md`, `how_to_new_pokemon.md`, `how_to_apricorn_tree.md`, `how_to_spots.md`.

### Données de combat

`src/data/trainers.party` (Showdown, IA, objets, Téra, Dynamax, Mugshot), `battle_partners.party` (combats en duo avec un PNJ), `src/data/wild_encounters.json` (rencontres sauvages par map).
