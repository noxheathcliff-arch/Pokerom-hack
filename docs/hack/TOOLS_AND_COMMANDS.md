# TOOLS_AND_COMMANDS.md — Outils, commandes, validation headless

> Conteneur : Linux x86-64, 4 cœurs, `arm-none-eabi-gcc 13.2.1` (apt, pas devkitPro), make, python3.13 (+Pillow 12.3), gcc/g++, cmake, go, node22, cargo, Xvfb, ImageMagick `convert`, libpng 1.6.43.
> Règle d'équipe : **seul l'orchestrateur lance `make` dans `/home/user/Pokerom-hack`** ; `/home/user/upstream` = copie de référence en lecture seule.

## 1. Inventaire `tools/` (compilés automatiquement au premier `make`, via `make_tools.mk`) [V]

| Outil | Rôle | Entrée → sortie |
|---|---|---|
| `preproc` | Encode les chaînes avec `charmap.txt`, gère `INCBIN` | `.s/.inc/.c` → flux pour `as`/`cc1` |
| `scaninc` | Dépendances `#include`/`.include` | — |
| `mapjson` | Cartes/layouts JSON → assembleur + constantes | `map.json`, `map_groups.json`, `layouts.json` → `*.inc`, `map_groups.h`, `layouts.h`, `map_event_ids.h` |
| `jsonproc` | JSON + template Inja → C | `wild_encounters.json`, `heal_locations.json`, `region_map_sections.json` |
| `trainerproc` | Format `.party` (Showdown) → `trainers.h` | `src/data/*.party` |
| `gbagfx` | PNG/PAL ↔ `.4bpp/.8bpp/.gbapal/.lz` | `graphics/**` |
| `compresSmol` | Compression « smol » (tilesets, tilemaps) | `.4bpp` → `.smol/.fastSmol` |
| `rsfont` | Polices | `graphics/fonts` |
| `mid2agb` / `wav2agb` | Musique/échantillons | `sound/` |
| `bin2c`, `ramscrgen` | Utilitaires (binaire→C, scripts de RAM) | — |
| `gbafix` | En-tête ROM (titre, code, maker, checksum, padding) | `.elf/.gba` |
| `patchelf`, `mgba-rom-test-hydra` | Outils de `make check` (`check-tools`) | test ELF |
| `tools/mgba/mgba-rom-test` | mGBA headless préconstruit (Linux/Mac/Win), fonctionne ici | — |
| `tools/wild_encounters/wild_encounters_to_header.py` | `wild_encounters.json` → `src/data/wild_encounters.h` | Python |
| `tools/learnset_helpers/*.py` | CT/tuteurs → `teachable_learnsets.h`, `tutor_moves.h` | Python |
| `tools/misc/make_scr_cmd_constants.py` | `script_cmd_table.inc` → `script_commands.h` | Python |
| `tools/find_func/find_func.py` | Recherche de fonctions | Python |
| `tools/qa/` | Ajouté par l'équipe QA (`validate_trainers.py`, `gbaplay/`, `scripts/`) — voir `QA_TOOLING.md` | — |
| `dev_scripts/delete_frlg_maps.py` | Supprime les cartes/layouts `_Frlg` | Python (destructif) |

Aussi installés hors dépôt par l'agent QA : `/opt/mgba-tools/bin/{mgba-rom-test, mgba-rom-test-hydra, gbaplay}`.
**Absents** : Porymap (GUI Qt — inutilisable sans écran ; Xvfb existe mais aucun binaire Qt/qmake), poryscript (non installé ; installable via `go install` si besoin, mais les scripts actuels sont en `.inc` brut — **non recommandé** d'introduire poryscript), devkitPro, arm-none-eabi-gdb, mGBA GUI (gbaplay le remplace pour captures).

## 2. Commandes de build [V : Makefile]

```bash
make -j4                    # ROM de dev : pokeemeraude.gba (+ .elf/.map), menu debug ACTIF, ~4 min à froid
make release -j4            # pokeemeraude-release.gba : -DRELEASE, NDEBUG, LTO, debug/quickstart OFF  ← LIVRAISON
make debug -j4              # -Og -g (build/emeraude-debug)
make check -j4              # compile pokeemeraude-test.elf et exécute ~6000 tests headless
make check TESTS="Spikes"   # filtre par nom de test (préfixe)
make pokeemeraude-test.elf TESTS="X"   # ROM de test ouvrable dans un émulateur
make syms                   # pokeemeraude.sym (table des symboles)
make generated              # régénère seulement les fichiers auto (maps, trainers, wild…) — rapide
make tools                  # compile les outils hôtes
make tidy                   # supprime ROM/ELF/objets (garde assets convertis)
make clean                  # tidy + outils + fichiers générés + assets convertis (long rebuild)
make TITLE="MON HACK" GAME_CODE=BPEF   # surcharger l'en-tête (12 / 4 car.)
make firered / leafgreen    # builds FRLG (hors périmètre)
```
Options : `NODEP=1` (saute le scan de dépendances), `LTO=1`, `DINFO=1` (-g), `ANALYZE=1` (-fanalyzer), `KEEP_TEMPS=1`. Logs utiles : `--print-memory-usage` affiche EWRAM/IWRAM/ROM à la fin du link.
Référence actuelle (upstream) : EWRAM 86.43 %, IWRAM 86.60 %, ROM 79.12 % ; SHA1 `ff2de54c…` (build dev).

## 3. Validation headless des cartes et scripts (sans Porymap)

1. **JSON** : `python3 -c "import json,glob;[json.load(open(f)) for f in glob.glob('data/maps/*/map.json')+['data/layouts/layouts.json','data/maps/map_groups.json']]"`.
2. **Génération cartes** (après `make tools`) — n'écrit que des fichiers générés :
   `tools/mapjson/mapjson map emerald data/maps/<Nom>/map.json data/layouts/layouts.json data/maps/<Nom>` ; `make generated` pour tout. Erreurs typiques détectées : layout inconnu, warp vers carte inexistante, constante manquante.
3. **Assemblage ciblé** (orchestrateur) : `make -j4 build/emeraude/data/event_scripts.o build/emeraude/data/maps.o build/emeraude/data/map_events.o` → vérifie macros, labels, constantes FLAG/VAR, caractères hors charmap (preproc échoue sur un caractère inconnu, ex. « »).
4. **Cohérence** (scripts Python à écrire/étendre dans `tools/qa/`) : chaque `dest_map`/`dest_warp_id` existe ; chaque `script` d'event est défini dans un `scripts.inc` inclus par `data/event_scripts.s` ; carte nouvelle présente dans `map_groups.json`, `region: REGION_HOENN` ; `.bin` de layout de taille `width*height*2` ; flags utilisés ≠ flags déjà pris ; textes ≤ 208 px (§5).
5. **Dresseurs** : `tools/trainerproc/trainerproc` échoue avec ligne/colonne sur un `.party` invalide ; `tools/qa/validate_trainers.py` (équipe stratégie).
6. **Exécution** : `make check` (moteur) ; `/opt/mgba-tools/bin/gbaplay` (QA) pour boot/captures/inputs scriptés. Éditer visuellement les blocs `.bin` sans Porymap : script Python (u16 = metatile id 10 bits | collision 2 bits | élévation 4 bits) + rendu PNG via Pillow à partir des tilesets — à outiller si création de cartes.

## 4. Où modifier quoi (aide-mémoire)

| Besoin | Fichier |
|---|---|
| Config fonctionnalités | `include/config/*.h` |
| Nouveau flag/var | renommer un `FLAG_UNUSED_*` (`include/constants/flags.h`) / `VAR_UNUSED_*` (`include/constants/vars.h`) |
| Carte / PNJ / warps | `data/maps/<Nom>/map.json` ; scripts+textes `data/maps/<Nom>/scripts.inc` ; inclusion `data/event_scripts.s` |
| Layout | `data/layouts/layouts.json` + `data/layouts/<Nom>/{map,border}.bin` |
| Dresseurs | `src/data/trainers.party` (+ constantes `include/constants/opponents.h`) |
| Rencontres sauvages | `src/data/wild_encounters.json` |
| Objets au sol / cachés | `object_events` (`OBJ_EVENT_GFX_ITEM_BALL`) + `FLAG_ITEM_*` / `bg_events` hidden_item |
| CS / badges | `src/field_move.c`, `src/battle_util.c:5645` (obéissance), `src/caps.c` |
| Début de partie | `src/new_game.c` |
| Textes communs | `data/text/*.inc`, `src/strings.c` |
| Titre/code ROM | `Makefile` l.2-3 |

## 5. Vérificateur de largeur de texte (prototype, résultats : p99 vanilla 208 px)

Mesure chaque segment `.string` (séparé par `\n \l \p`) avec la table `gFontNormalLatinGlyphWidths` ; placeholders comptés au pire. À intégrer dans `tools/qa/` si adopté.
```python
import re,sys,glob
root=sys.argv[1]; cm={}
for l in open(root+'/charmap.txt',encoding='utf-8'):
    m=re.match(r"^'(.)'\s*=\s*([0-9A-Fa-f]{2})\s*$",l.split('@')[0].rstrip())
    if m: cm.setdefault(m.group(1),int(m.group(2),16))
src=open(root+'/src/fonts.c').read()
W=[int(x) for x in re.findall(r'\d+',re.search(r'gFontNormalLatinGlyphWidths\[\]\s*=\s*\{(.*?)\};',src,re.S).group(1))]
PH={'PLAYER':42,'RIVAL':42,'STR_VAR_1':60,'STR_VAR_2':60,'STR_VAR_3':60}
def width(s):
    w=i=0
    while i<len(s):
        if s[i]=='{': j=s.index('}',i); w+=PH.get(s[i+1:j],0); i=j+1; continue
        if s[i]=='\\': i+=2; continue
        if s[i]=='$': i+=1; continue
        c=cm.get(s[i]); w+=W[c] if c is not None else 6; i+=1   # inconnu = erreur preproc probable
    return w
LIMIT=208
for f in sorted(glob.glob(root+'/data/maps/*/scripts.inc')+glob.glob(root+'/data/text/*.inc')):
    if '_Frlg' in f: continue
    for n,l in enumerate(open(f,encoding='utf-8'),1):
        m=re.match(r'\s*\.string "(.*)"',l)
        if m:
            for seg in re.split(r'\\[nlp]',m.group(1)):
                if width(seg)>LIMIT: print(f"{f}:{n}: {width(seg)}px: {seg}")
```
Usage : `python3 -I check_text_width.py /home/user/Pokerom-hack`.
