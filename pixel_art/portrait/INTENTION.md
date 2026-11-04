# Portrait buste — personnage au manteau blanc (256x320)

## Intention
Portrait de dialogue en grand format, cadré jusqu'au buste. L'image doit reproduire l'illustration webtoon de référence au plus près, comme un calque.

## Pourquoi 256x320
- En 192x256, l'œil fait 3 à 4 px de haut, les boutons 7 px, et le 卍 des boucles d'oreilles devient illisible.
- En 256x320, l'œil a la place pour une iris et un reflet. Les boucles d'oreilles sont des plaques 7x7 qui portent le motif, et les grains du chapelet restent séparés.
- Le ratio 4:5 reprend le cadrage de la référence : main levée aux lunettes en haut, chapelet en bas.

## Méthode (E6, table lumineuse)
1. `etape01_construction` : volumes et placement.
2. `etape02_decalque` : décalque guidé par zones.
   - `zones.txt` découpe les matières : peau, cheveux, manteau, gant, or, perles, serpent, fond.
   - `decalque.py` choisit, dans chaque zone, la lettre autorisée la plus proche en espace Lab.
   - La référence sert de calque lumineux et n'est jamais exportée.
3. Passes à la main, une commande `cXX.txt` par étape (R3, R4) :
   - c03 : visage (yeux, iris, nez, bouche).
   - c04 : nettoyage du bruit, et boutons redessinés en pièces 12x12.
   - c05 : boucles d'oreilles 卍 dessinées à la main (plaque claire côté lumière, plaque ombrée côté ombre).
   - c06 : reflets des verres durcis.
   - c07 : contour des boutons adouci (N/M au lieu de O/o, comme sur la référence).
   - c08 : chasse aux orphelins, ton dominant si au moins 5 voisins sur 8 le partagent. Visage et lignes exclus.

## Palette et rampes
- Rampes décalées en teinte :
  - Rouge du rideau : 0→X.
  - Manteau : W/w/v/V/u/U, ombres blanches tirées vers le rose sous le reflet du rideau.
  - Gant : G/g/f/F, froid bleuté.
  - Peau : K/k/j/J/L.
  - Cheveux : H/h/d/D.
  - Verres : e/c/C/Z.
  - Or : Y/y/z.
  - Perles : R/r/q/Q.
  - Serpent translucide : m/M/N.
  - Iris : i/I.
- Lumière en haut à gauche. Le rideau rouge renvoie une lumière réfléchie sur les bords droits du manteau et sur le liseré rouge qui entoure la figure.

## Défauts connus
- Le manteau garde un léger grain de décalque dans les plis doux (les orphelins à moins de 5 voisins identiques ont été conservés).
- La case silhouette de la planche est sans objet : le portrait est plein cadre, sans transparence.
