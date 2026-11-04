# Revue — potion 32x32 (étape 11)

## Les 7 questions
1. **Lisible en x1 ?** Oui : fiole ronde + bouchon + liquide rouge reconnaissables à 32 px.
2. **Silhouette seule identifiable ?** Oui : boule + col + bouchon, pas de confusion avec un vase (variante B écartée).
3. **Valeurs en gris séparées ?** Oui : verre clair / liquide moyen / bouchon et contour sombres.
4. **Lumière cohérente ?** Haut-gauche partout : reflet 2x2 verre, terminateur à droite, occlusion en bas, liseré rebond à droite.
5. **Fond clair ET sombre ?** Oui ; sur sombre le contour se fond un peu côté ombre (acceptable, selout côté lumière).
6. **Pixels orphelins / bruit ?** Retirés à l'étape 10 (petite bulle 1x2).
7. **Palette ≤16 ?** 15 couleurs utiles (contour + 4 verre + 4 liquide + 4 bouchon + W).

## 3 réussites
- La lentille de surface du liquide (bande claire effilée) donne le volume rond.
- Le reflet 2x2 + reflet opposé 1 px fait lire « verre » immédiatement.
- Le selout côté lumière adoucit sans perdre la découpe.

## 3 à améliorer (appliqués au 64)
- Le rebord (lèvre) lit comme une barre noire : lui donner des tons de verre.
- Le bouchon manque de texture (liège) — impossible à 32, prévu au 64.
- Le contour côté ombre se fond sur fond sombre : au 64, contour cassé + liseré de rebond plus net.
