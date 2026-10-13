# Comment utiliser Rouge Feu/Vert Feuille

## Comment compiler
```make firered -j<résultat de nproc>```<br>
ou<br>
```make leafgreen -j<résultat de nproc>```

Note: Si vous sautez de compilation en compilation entre Emeraude et RFVF, vous devrez exécuter un `make clean` au préalable.

## Ajustements sur Porymap
Pour que Porymap fonctionne avec les maps de RFVF, certains paramètres doivent être ajustés (`Options > Project Settings`):
- Dans l'onglet `General`, changez la version de base en `pokefirered`

![porymap_general](./img/frlg/porymap_general.png)

- Dans l'onglet `Identifiers`, changez les attributs suivants:
  - define_tiles_primary: `NUM_TILES_IN_PRIMARY_FRLG`
  - define_metatiles_primary: `NUM_METATILES_IN_PRIMARY_FRLG`
  - define_pals_primary: `NUM_PALS_IN_PRIMARY_FRLG`
  - define_mask_behavior: `METATILE_ATTR_BEHAVIOR_MASK_FRLG`
  - define_mask_layer: `METATILE_ATTR_LAYER_MASK_FRLG`

![porymap_identifier](./img/frlg/porymap_identifier.png)

## Comment ajouter des maps
Pour que les maps soient inclues dans le processus de compilation, elles doivent avoir un attribut personnalisé de `region` avec la valeur `REGION_KANTO` ou `REGION_HOENN` pour leurs jeux respectifs.

Si vous créez une nouvelle map, l'attribut `region` ne sera pas présent par défaut, et doit être ajouté manuellement dans le fichier `map.json` correspondant ou à travers Porymap.

**Exemples:**

map.json:
```
{
  "id": "MAP_PALLET_TOWN",
  "name": "PalletTown_Frlg",
  "layout": "LAYOUT_PALLET_TOWN",
  "music": "MUS_RG_PALLET",
  "region": "REGION_KANTO",
  ...
```
Porymap:

![porymap_region_attribute](./img/frlg/porymap_region_attribute.png)

Si une map ne possède pas l'attribut `region`, le compilateur va utiliser comme valeur par défaut la région associée à la version que vous compilez, et la map que vous avez créé sera inclue dans le jeu.

Additionnellement, les maps doivent avoir un attribut `layout_version` que vous ajouterez manuellement dans `layouts.json`.
```
    {
      "id": "LAYOUT_ONE_ISLAND_KINDLE_ROAD_EMBER_SPA",
      "name": "OneIsland_KindleRoad_EmberSpa_Layout",
      "width": 27,
      "height": 39,
      "primary_tileset": "gTileset_General_Frlg",
      "secondary_tileset": "gTileset_MtEmber",
      "border_filepath": "data/layouts/OneIsland_KindleRoad_EmberSpa_Frlg/border.bin",
      "blockdata_filepath": "data/layouts/OneIsland_KindleRoad_EmberSpa_Frlg/map.bin",
      "border_height": 2,
      "border_width": 2,
      "layout_version": "frlg"
    },
```

Comme l'attribut `region`, si une map dans `layouts.json` n'a pas d'attribut `layout_version`, le compilateur utilisera la valeur par défaut de la version que vous compilez.

Enfin, vous ne pouvez pas accéder *normalement* à une map dans un groupe de maps (une bank) vanilla depuis une autre version. Si vous créez une map dans un groupe de maps appartenant à Rouge Feu (ex: `gMapGroup_TownsAndRoutes_Frlg`), vous ne pourrez pas warp ou connecter cette map à une map sur Emeraude, et vice-versa. Il est recommandé de mettre vos maps dans des groupes de maps existants et appropriés, ou de créer de nouveaux groupes de maps.

## Migrer les tilesets de RFVF
Pour migrer les tilesets qui ont précédemment été créés pour `pokerougefeu`, vous pouvez utiliser [ce script](/migration_scripts/frlg_metatile_behavior_converter.py).<br>
Les instructions sont dans le script.

## Avertissement: Les changements qui suivent ne sont pas des solutions permanentes aux problèmes énoncés, un meilleur système de compilation est en développement, et par conséquent, ces changements pourraient causer des merge conflicts dans le futur

## Compiler RFVF par défaut
Si vous voulez que `make -j<résultat de nproc>` compile directement Rouge Feu ou Vert Feuille au lieu d'Emeraude, effectuez les changements suivants dans le fichier `Makefile`:

(Ici, la version par défaut est Vert Feuille. Vous pouvez quand-même compiler Emeraude ou Rouge Feu en utilisant `make emerald` ou `make firered`).

```diff
-GAME_VERSION ?= EMERALD
-TITLE        ?= POKEMON EMER
-GAME_CODE    ?= BPEF
-BUILD_NAME   ?= emeraude
-MAP_VERSION  ?= emerald
+GAME_VERSION ?= LEAFGREEN
+TITLE        ?= POKEMON LEAF
+GAME_CODE    ?= BPGF
+BUILD_NAME   ?= vertfeuille
+MAP_VERSION  ?= firered

ifeq (firered,$(MAKECMDGOALS))
  	GAME_VERSION 	:= FIRERED
	TITLE       	:= POKEMON FIRE
	GAME_CODE   	:= BPRF
	BUILD_NAME  	:= rougefeu
	MAP_VERSION 	:= firered
else

-ifeq (leafgreen,$(MAKECMDGOALS))
-	GAME_VERSION 	:= LEAFGREEN
-	TITLE       	:= POKEMON LEAF
-	GAME_CODE   	:= BPGE
-	BUILD_NAME  	:= vertfeuille
-	MAP_VERSION 	:= firered
+ifeq (emerald,$(MAKECMDGOALS))
+	GAME_VERSION 	:= EMERALD
+	TITLE       	:= POKEMON EMER
+	GAME_CODE   	:= BPEF
+	BUILD_NAME  	:= emeraude
+	MAP_VERSION 	:= emerald
endif
endif
```

## Faire en sorte que les attributs `region` vides correspondent à `REGION_KANTO` par défaut
Un autre problème est que vous devez ajouter l'attribut `region`, et le définir en `REGION_KANTO` pour chaque map que vous créerez.

Effectuez les changements suivants dans `tools/mapjson/mapjson.cpp` pour que les nouvelles maps sans `REGION_KANTO` fonctionnent correctement

```diff
string region = json_to_string(map_data, "region", true);

        if (region.empty()) {
-            region = "REGION_HOENN";
+            region = "REGION_KANTO";
        }
        string map_name = json_to_string(map_data, "name");

        if ((version == "emerald" && region != "REGION_HOENN")
         || (version == "firered" && region != "REGION_KANTO")) {
            invalid_maps.push_back(map_name);
        }
```

Ensuite, exécutez ce script pour que les attributs `region` de toutes les maps d'Hoenn soient définies en `REGION_KANTO`.
**Assurez-vous d'exécuter ce script à partir du [dossier racine](../..) de votre projet!**

```
python3 migration_scripts/add_region_hoenn_attribute_to_hoenn_maps.py
```

Assurez-vous aussi d'exécuter un `make clean` après ce script.

## Fix CI if you are building FRLG by default
## Corriger la CI si vous compilez RFVF par défaut
Si vous effectuez ces changements ci-dessus, il est recommandé de corriger votre CI pour qu'elle corresponde à vos changements.

Effectuez les changements suivants dans le fichier `.github/workflows/build.yml`

```diff
# build-essential and git are already installed

-      - name: ROM (Emerald)
+      - name: ROM (Leafgreen)
        env:
          COMPARE: 0
-          GAME_VERSION: EMERALD
+          GAME_VERSION: LEAFGREEN
        run: make -j${nproc} -O all

      - name: Release
        env:
-          GAME_VERSION: EMERALD
+          GAME_VERSION: LEAFGREEN
        run: |
          make tidy
          make -j${nproc} release
        # make tidy to purge previous build

      - name: Test
        env:
-          GAME_VERSION: EMERALD
+          GAME_VERSION: LEAFGREEN
          TEST: 1
        run: |
          make -j${nproc} check

      - name: ROM (Firered)
        env:
          COMPARE: 0
        run: |
          make clean
          make firered -j${nproc} -O

-      - name: ROM (Leafgreen)
+      - name: ROM (Emerald)
        env:
          COMPARE: 0
        run: |
-          make leafgreen -j${nproc} -O
+          make emerald -j${nproc} -O
```
