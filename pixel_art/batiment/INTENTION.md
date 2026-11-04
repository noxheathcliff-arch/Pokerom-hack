# B0 — Intention : « L'échoppe de l'alchimiste » (64×64)

- **Quoi** : une petite boutique d'alchimiste à colombages, vue 3/4 de dessus (toit + façade, pas de côtés).
- **Histoire** : la boutique est ouverte en fin de journée — la vitrine est allumée, des fioles sur l'étagère,
  la cheminée fume (le labo tourne), une enseigne à fiole pend, de la mousse a gagné le vieux toit d'ardoise.
- **Idées hiérarchisées (3–4)** :
  1. La vitrine chaude allumée (accent, seul jaune vif de l'image).
  2. Le grand toit d'ardoise bleu-gris avec lucarne et cheminée (masse dominante, 45 % de la surface).
  3. La porte cintrée en pierre + enseigne (lecture « boutique »).
  4. Vie : fumée, mousse, herbe, fleurs, girouette.
- **Lumière** : haut-gauche. Le toit (dessus) est la face la plus claire, la façade plus sombre, ombre portée sous l'avant-toit.
- **Palette** : 24 couleurs max, rampes par matériau (ardoise 4, pierre 4, enduit 2, bois 3, verre 3, lumière 3, mousse 2, + O, e, i).
- **Silhouettes R7** : A = toit à pignon rectangulaire simple ; B = toit à croupe en trapèze + lucarne + cheminée décalée → B retenu (plus lisible, plus de caractère).

## Revue planche (étape 8) et corrections (étape 9)
- Défaut 1 corrigé : la fumée faisait 3 bouffées détachées + 1 pixel orphelin (57,0), ce qui donnait du bruit à x1. Elle est remplacée par une seule traînée en S, avec la lumière en haut à gauche et l'ombre en bas à droite.
- Défaut 2 corrigé : la lucarne n'avait pas de reflet, contrairement aux deux autres vitrages. Ajout d'un reflet 2x2 `z` et d'1 px opposé.
- Défaut restant : en niveaux de gris, la vitrine (`y`) et le plâtre (`p`) ont une valeur proche, donc l'accent lumineux tient surtout par la teinte. Piste : assombrir légèrement `p` ou ajouter une lueur `o` sur le plâtre autour de la vitrine.

## Leçons
- Une commande `rep` sur un rectangle déborde sur les zones voisines (pente de la lucarne). Il faut tracer des `line` à la place.
- Une bande d'ombre sur toute la largeur d'un mur doit exclure les ouvertures (porte), sinon elle recouvre le battant.
