# Asset UI — « Orbe de vie » (jauge de PV du HUD)

## B0 — Intention

| | |
|---|---|
| Quoi | Jauge de vie du HUD : une fiole sphérique remplie de sang lumineux. Le niveau du liquide montre les PV, et le nombre (`65/99`) s'affiche sur la plaque de fer en dessous. |
| Format | 64×64. Axe vertical sur la colonne 32 : je dessine la moitié gauche, puis `miroir` la recopie. Marge de 1 px (B1). |
| Projection | Vue de face. La sphère de verre est un volume ; l'anneau, les ailes et la plaque sont des reliefs avec des biseaux de 1 px (B2). |
| Fantasme | Un reliquaire : une fiole de vie sertie d'or, couronnée d'un rubis, portée par deux ailes. On la sent précieuse : la perdre, c'est mourir. |
| Accent saturé unique | Le liquide rouge (`1…6`). Le rubis de la couronne lui répond avec les mêmes teintes, il n'apporte pas de nouvelle couleur. |
| Matières | Or poli (`a…f`), verre (`p q r s k x w`, froid), liquide (`1…6`), fer (`h i j m`), contour vin `O` |
| Lumière | Vient d'en haut à gauche. Le verre reçoit une fenêtre de reflet en haut à gauche et un liseré froid en bas à droite (rim). Le liquide est translucide : il est plus clair sous le ménisque et s'assombrit vers le fond. |
| Point d'intérêt (B4) | La surface du liquide (ménisque) et l'éclat du verre juste au-dessus. C'est là que le joueur regarde : c'est l'information de jeu. |
| Formes (A4b) | Grande forme : le disque. Moyennes : les ailes, la couronne et la plaque. Petites : rivets, bulles, chiffres. Les rimes : les pointes des plumes répondent aux pointes de la couronne, l'arc de l'anneau à celui du ménisque, et l'hexagone de la plaque aux facettes du rubis. |
| Lisibilité gameplay | Le niveau du liquide doit se lire en x1 (sur 64 px) en moins d'une seconde. Le contraste maximal est donc entre le liquide et le vide de verre. |

## R7 — Deux silhouettes comparées

- **A — orbe ailé** (retenu) : un disque, une couronne à 5 pointes, des ailes levées dans les coins du haut et une plaque hexagonale. En silhouette noire, sur fond clair comme sombre, on lit « relique ailée » avant toute couleur.
- **B — globe sur pied** : un disque, un socle et de petites oreilles. Ça se lit comme un trophée ou une boule à neige générique, sans rien de « vie ».

Révisions de l'étape 1 :
1. Des ailes en masse molle et une plaque qui flottait.
2. Des rémiges horizontales : la silhouette lisait « soleil ».
3. Ailes levées en éventail, avec les pointes vers l'extérieur et le haut. C'est cette version que je garde.
4. B1 : les pointes en colonne 1 se recopiaient en colonne 63, donc elles touchaient le bord. Je les ai reculées d'1 px dans `c01` (R3).

## Étape 3 (A5-6) — Contour sélectif

- **Selout avec `bord.py`** (`c03.sh`) : tout ce qui touche le vide prend le vin `O`, jamais du noir. À l'intérieur, chaque matière garde un bord tiré de sa propre rampe :
  - l'or qui touche le verre ou le liquide devient `a` (le chaton, la sertissure qui tient la fiole) ;
  - le fer de la plaque qui touche l'or prend `h` : c'est l'arête où la plaque passe sous l'anneau.
- **Anneau** : une ligne `a` le sépare des plumes et de la couronne (`c03_lignes.txt`). Elle fait lire l'anneau comme une pièce à part, posée par-dessus les ailes.
- **Fentes des plumes** : un trait `a` de 1 px le long de chaque rémige. Le pixel de départ est en `b`, pour que la fente s'allume doucement au lieu de commencer net.
- **Pointes** : une pointe = un pixel qui dépasse (A6-D). Il n'y a plus de « L » au bout des rémiges ni de la couronne.

## Étape 4 (A5-7 / A6-A) — Palette

Planches : `v04_palette_vue.png`, et `v04_palette_gris_vue.png` pour la version en gris. `v04_contour_gris_vue.png` montre l'étape 3 en gris.

| Rampe | Teinte (sombre → clair) | Gris (sombre → clair) | Choix |
|---|---|---|---|
| Contour `O` | vin 320° | 23 | Le plus sombre de l'image, sans être noir. |
| Or `a b c d e f` | 2° → 46° (vin → crème) | 47 / 79 / 119 / 162 / 205 / 240 | Marches régulières de +32 à +43. Le ton moyen `d` est le plus saturé. Les clairs glissent vers le jaune, les sombres vers le rouge. |
| Liquide `1 2 3 4 5 6` | 328° → 29° (pourpre → orange) | 23 / 43 / 64 / 92 / 137 / 189 | L'accent unique. Les sombres sont serrés (+20) parce que le fond de la fiole doit rester une masse profonde. Les clairs s'écartent (+45/+52) pour le ménisque lumineux. |
| Verre `p q r s k x w` | 246° → 196° (indigo → ciel) | 22 / 38 / 61 / 99 / 162 / 218 / 248 | Froid, opposé au liquide. Le saut `s → k` (+63) est voulu : un reflet sur du verre est une arête nette, pas un dégradé. `w` est le seul quasi-blanc, réservé à l'éclat. |
| Fer `h i j m` | 244° → 224° | 28 / 48 / 77 / 120 | Bleu-gris sourd. Il reste sous l'or et ne lui vole jamais la vedette. |

- **Budget** (A6-B) : 30 couleurs en tout, 5 matières. Seul le liquide est saturé ; le rubis réutilise ses teintes (`4 5 6`).
- **Test du gris** : les rampes montent bien et ne se recouvrent pas. L'or lit clair, le verre et le fer lisent sombre, donc l'anneau se détache.
- **Point de vigilance** : le verre vide `q` (38) et le liquide `3` (64) sont proches en gris. Or c'est justement la frontière qu'il faut lire en moins d'une seconde. Je le règle à l'ombrage, pas en changeant la palette :
  - le liquide s'éclaircit sous le ménisque (`4`, `5`) ;
  - le vide de verre reste sombre (`p`, `q`) ;
  - une ligne de ménisque claire marque le niveau.

## Étape 5 (A5-8) — Terminateur et ombres

Lumière en haut à gauche (R23). Fichiers : `c05.sh`, `c05_isole.txt`, `c05_ombres.txt`, `c05b_menisque.txt` → `v05_ombres_vue.png`.

- **Anneau d'or** : le terminateur passe sur la diagonale haut-droite / bas-gauche. La moitié haut-gauche monte en `d`, la moitié bas-droite descend en `b`. Le miroir de l'étape 1 est cassé ici : la lumière n'est pas symétrique.
- **Plumes et couronne** : arête haute éclairée (`d`), arête basse dans l'ombre (`b`). L'aile droite ne reçoit que l'ombre (`bd`) : elle est du côté opposé à la lumière.
- **Liquide** : la profondeur va de `3` à `2` puis `1` vers le fond et le bord bas-droit. Le fond reste une masse sombre, sans bandes.
- **Ménisque** (`c05b`) : la surface n'est plus une règle plate.
  - Elle est concave : le liquide remonte d'1 px contre le verre aux deux bords.
  - La ligne de surface s'éteint de gauche à droite (`5 → 4 → 3`), et la lumière qui la traverse éclaire les deux rangs dessous (`4`).
  - Correction après vue : un pixel `4` posé en x15 y24 faisait une marche isolée contre l'or. Je l'ai retiré : une seule marche suffit.
- **Verre vide** : `q` en masse, `p` en croissant d'ombre en haut à droite, `r` sur l'épaisseur éclairée du bord haut-gauche.
- **Rubis** : facette claire en haut à gauche, sombre en bas à droite, avec les teintes du liquide.
- **Plaque** : biseau `j` en haut à gauche, `h` en bas à droite (B2).

Encore à régler : le verre du haut est mort et plat (ce sera l'étape 8, avec le reflet), et les ailes comme la plaque restent plates.

## Étape 7 (A5-9) — Occlusion ambiante

Fichier : `c07_ao.txt` → `v07_ao_vue.png`. Chaque pixel a été vérifié avant d'être posé.

- **Ailes contre l'anneau** : là où une plume passe sous l'anneau, la lumière rasante n'arrive pas.
  - Aile gauche, côté lumière : 1 px descend d'un cran (`d → c`, `c → b`).
  - Aile droite, côté ombre : 2 px (`a` puis `b`), parce que l'anneau projette aussi son ombre vers la droite.
- **Couronne** : la pointe droite pose une petite ombre (`b`) sur l'anneau, du côté opposé à la lumière.
- **Plaque** : sous l'anneau, le biseau clair `j` s'éteint en `i`. La plaque passe *sous* l'or au lieu d'être collée à côté.
- Le fond du liquide était déjà en `1` contre le verre : rien à ajouter.

## Étape 8 (A5-10/11) — Lumière et matières

Fichier : `c08_lumiere.txt` → `v08_lumiere_vue.png`.

- **Verre** : une fenêtre de reflet courbe en haut à gauche, qui épouse l'arc de la sphère (`k`, `x`, avec un seul pixel `w` pour l'éclat). Elle s'éteint en `s` puis `r` en descendant. Une petite vitre secondaire (`k`, `s`) la double : c'est le reflet d'un deuxième carreau, et c'est ce qui fait lire le verre et non un trou.
- **Liseré froid** (rim) : le bord bas-droit du liquide reçoit `r` puis `s`. C'est la lumière qui revient à travers le verre. Il ne touche pas le ménisque, donc le niveau reste net.
- **Ménisque** : un éclat spéculaire `6` sur 3 px à gauche, prolongé par `5`. C'est le point le plus lumineux du liquide, et donc le point d'intérêt (B4).
- **Liquide** : 4 bulles (`4`, `5`) qui montent en diagonale, et une caustique `3` au fond. Le liquide devient une matière vivante, plus un aplat.
- **Or poli** : une bande `d` suit l'arc haut-gauche de l'anneau, avec un cœur `e` et un seul `f`. Le métal poli se lit comme une bande nette, pas comme un dégradé.
- **Plumes et couronne** : quelques points `e` sur les arêtes éclairées.
- **Fer** : un reflet `m` sur l'arête haute de la plaque, et un biseau `j` à gauche. Le fer reste mat face à l'or.

## Étape 9 (A5-12) — Détails

Fichiers : `c09_details.txt` et `c09_chiffres.txt` → `v09_details_vue.png`.

- **Cartouche en creux** : un rectangle `h` creusé dans la plaque. Ses parois haute et gauche sont dans l'ombre, ses lèvres basse et droite sont éclairées (`j`). Comme la lumière vient d'en haut à gauche, on lit un creux et non une bosse.
- **Chiffres « 65/99 »** : une police 3×5 dessinée pixel par pixel. Le corps est en crème `e`, le rang du haut en `f` pour l'arête éclairée. La barre est en `d` : elle est secondaire. Correction après vue : en `c`, elle se perdait sur le fer.
- **Rivets** : deux têtes de 2×2 qui encadrent le cartouche (`m` en haut à gauche, `j` sur les flancs, `h` en bas à droite). Ils répondent aux bulles du liquide par leur petite taille (A4b).

## Étape 10 (A5-13) — Nettoyage

Fichier : `c10_nettoyage.txt` → `v10_nettoyage_vue.png`. Chaque pixel retouché est choisi à la main.

- **Pointe de la rémige haute** (y8-9) : le bloc `OO` / `OOO` faisait un « L » épais (R21). La pointe redevient un seul pixel qui dépasse, suivi d'une diagonale propre.
- **Pointe de la rémige basse** (y17-19) : il y avait un coin en « L » en x3. Le contour glisse d'1 px vers l'intérieur.
- **Côté droit** : je recopie chaque retouche à la main avec x → 64 − x. Correction après vue : j'avais d'abord pris x → 63 − x, et ça laissait un trou `O.O` dans le contour.
- **Pixels orphelins** (A6-C) :
  - un `2` isolé au fond du liquide (x30 y47) devient `1` ;
  - un `c` perdu sous l'anneau (x29 y49) devient `b`.
- **Caustique** : un `3` isolé en x30 y43, détaché de la tache x34-38, faisait du bruit. Il devient `2`. La tache principale reste.
- **Vérifié et gardé** :
  - l'arc de l'anneau en y13-14 : ses marches sont régulières ;
  - les bulles du liquide : elles sont isolées exprès.
