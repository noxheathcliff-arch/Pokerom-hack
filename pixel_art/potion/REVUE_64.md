# Revue — potion 64x64 (étape 11), redessinée de zéro (pas d'agrandissement du 32)

## Défaut corrigé à chaque étape
| Étape | Défaut vu sur l'image | Correction |
|---|---|---|
| 01 construction | ressemblait à un chapeau haut-de-forme | bouchon rétréci, lèvre 3 lignes, col 5 lignes, sphère r=19 |
| 02 silhouettes | variante B = banjo | A gardée ; courbe redessinée en escalier à la main (disc() faisait des picots) |
| 02b | marches de l'épaule non monotones (2,3,2) | ligne 23 ramenée à demi-largeur 7 |
| 03 contour | lèvre avec 1 seule ligne intérieure | bouchon remonté d'une ligne |
| 04 palette | brun sombre du bouchon = même gris que le contour | `i` éclairci (#4a2a2c) |
| 05 aplats | surface du liquide = bande plate | lentille elliptique (lignes 36–40) |
| 06 terminateur | bas du terminateur en diagonale droite | marches croissantes 1,1,1,2,2,2,3,3,3 |
| 07 ombres | arrière de la surface en barre rouge flottante | supprimé |
| 08 lumière | caustique rose = trou gris | halo ton 3 + cœur ton 4 |
| 09 détails | pores du liège formant une « lettre » | pores dispersés par groupes de 1–2 |
| 10 nettoyage | bord ombre fondu sur fond sombre (hérité du 32) | liseré de rebond `5` + selout côté lumière + contour cassé au reflet |

## Les 7 questions
1. **Lisible en x1 ?** Oui, fiole, bouchon et liquide rouge immédiatement.
2. **Silhouette seule ?** Oui, même identité que le 32 (boule, col, lèvre, bouchon).
3. **Valeurs en gris ?** Verre clair / liquide moyen / bouchon et contour sombres : trois masses distinctes.
4. **Lumière cohérente ?** Haut-gauche : reflet 2x2 + traînée courbe, terminateur courbe, occlusion en croissant, caustique à l'opposé.
5. **Fond clair et sombre ?** Oui ; le liseré de rebond détache maintenant le bas-droit sur fond sombre.
6. **Orphelins / bruit ?** Les bulles sont volontaires (hiérarchie : 2x2 > 1 px > 1 px plus bas), pas de pixel isolé hors détail.
7. **Palette ≤24 ?** 17 couleurs utilisées.

## 3 réussites
- La lentille de surface + le reflet du verre qui traverse le liquide donnent un vrai volume sphérique.
- Le liège se lit comme matière (dessus clair, pores, colonne d'ombre).
- La lèvre n'est plus une barre noire : verre clair éclairé à gauche, ombre portée du bouchon.

## 3 à améliorer
- La traînée de reflet `d` sur le verre est peu contrastée sur `c` en grand.
- Le bas (lignes 58–60) garde des marches de 2–3 px un peu dures : un AA intérieur aiderait.
- Les bulles pourraient suivre une trajectoire plus nette vers la surface.
