# Asset UI — « Astrolabe du Cycle » (médaillon de menu pause)

## B0 — Intention

| | |
|---|---|
| Quoi | Médaillon central du menu pause : horloge-astrolabe ailée qui affiche le moment du cycle jour/nuit. L'aiguille pointe la phase du jour. |
| Format | 129×129, soit 128 + 1 colonne pour un axe impair (A5, élément central sur la colonne 64). Marge de 1 px (B1). |
| Projection | Vue de face, légère épaisseur (biseaux de 1 à 2 px sur chaque anneau, B2) |
| Fantasme | Une relique céleste : un astrolabe d'or tenu par des ailes de métal bleui, couronné de rayons, un cristal de lumière enchâssé au cœur |
| Accent saturé unique | Cristal cyan (`t u v w x y`), seule couleur saturée froide. Sa lueur (`z Y`) déborde sur l'émail. |
| Matières | Or (`a b c d e f g`, 7 tons), acier bleui (`h i j m n`, 5 tons), émail indigo (`p q r s`), cristal (`t…y`), contour vin `O` |
| Lumière | Haut-gauche. Le cristal est émissif : ombrage inversé, et il éclaire l'émail autour de lui. Le cadran est un creux, donc son ombre portée est en haut à gauche. |
| Point d'intérêt (B4) | Le cristal central : plus fort contraste, seul accent, au croisement des aiguilles |
| Formes (A4b) | Grande = le disque. Moyennes = les ailes, la couronne et le pendentif. Petites = graduations, étoiles, griffes. Les rimes : arcs des rémiges / arcs de l'anneau / volutes du pendentif / croissant de lune du contrepoids. |

## R7 — Deux silhouettes comparées

- **B — rose des vents** : un disque et 8 pointes. Elle se lit, mais c'est une boussole générique : rien ne dit « relique » ni « menu ».
- **A — astrolabe ailé** (retenu) : couronne de rayons (lance + courts + moyens), ailes à 6 rémiges pendantes séparées par des fentes de 1 px, pendentif goutte + volutes + perle. À la vignette noire, on lit « objet sacré ailé » avant toute couleur, sur fond clair comme sombre.

Corrections faites à l'étape 2 :
- Rémiges en éventail : elles se lisaient comme des pinces de crabe. Je les ai remplacées par des plumes pendantes, de la pointe vers le bas et l'extérieur.
- Plumes fondues en une masse : j'ai ajouté des fentes de 1 px le long de leur axe.

## Étape 4 (A5-6) — Contour sélectif

- **Selout avec `bord.py`** : chaque matière a un bord pris dans sa propre rampe, jamais du noir. Le pourtour extérieur de l'or prend le vin `O`, l'acier prend `h`, le cristal prend `t`. Entre l'or et l'acier de la lunette, j'ai mis une ligne intérieure `b` (le brun-rouge de l'or), un cran plus claire que `O`.
- **Hiérarchie** : `O` à l'extérieur, 2 px sur le haut (le trait le plus épais va en haut et dehors). Les lignes intérieures sont `b` ou `h`, en un ton plus clair que le contour.
- **Encoches** : les fentes entre les rémiges sont une ligne `h` de 1 px. Le pixel de départ est en `i` pour que la ligne s'éteigne au lieu de s'arrêter net.
- **Pointes** : j'ai retiré à la main les pixels doubles au bout des rayons et des plumes (A6-D, une pointe = un pixel qui dépasse, pas un « L »).
- **B1** : marge de 1 px rétablie là où les rayons touchaient le bord.
- **Miroir limité** (`miroir 64 0 128 100 128`) : je ne recopie la moitié gauche que là où aucune lumière asymétrique n'est prévue.

## Étape 5 (A5-7 / A6-A) — Palette

Planche : `v05_palette_vue.png`, et `v05_palette_gris.png` pour la version en gris. Les rampes sont posées côte à côte.

| Rampe | Teinte (clair → sombre) | Gris (sombre → clair) | Choix |
|---|---|---|---|
| Or `O a b c d e f g` | crème 45° → orange 29° → rouge-brun 10° → vin 324° | 23 / 37 / 67 / 103 / 141 / 182 / 219 / 245 | Marches régulières, de +30 à +41. Le ton moyen `d` est le plus saturé (S84). Les dernières marches vers le blanc sont plus courtes. |
| Acier `h i j k m n` | 238° → 216° | 29 / 57 / 93 / 127 / 164 / 218 | J'ai ajouté `k` pour pouvoir faire des bandes nettes de métal poli. `n` sert au reflet uniquement (+54). |
| Émail `p q r s` | 257° → 238° (de violet vers bleu) | 20 / 37 / 54 / 79 | La matière la plus sombre de l'objet, ce qui fait lire le cadran comme un creux. |
| Lueur `z Y` | 216° → 206° | 69 / 104 | Un bleu-vert intermédiaire, qui fait passer l'émail vers le cristal. |
| Cristal `t u v w x y` | 201° → 154° | 42 → 253 | Le seul accent saturé. `y` est le seul quasi-blanc, réservé à l'éclat. |

- Pas de noir ni de blanc purs. `O` est un vin très sombre, `y` un blanc teinté de vert.
- Valeurs proches entre matières : `j` (93) ≈ `c` (103) et `s` (79) ≈ `u` (81). Ces couples ne se touchent jamais : l'acier est séparé de l'or par la ligne `b`, et le cristal de l'émail par le chaton d'or. Ça reste donc lisible.
