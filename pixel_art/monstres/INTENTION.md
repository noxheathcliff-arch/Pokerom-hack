# Monstres — intention (test 11, méthode v10.2, section C15)

Trois créatures originales en 64×64, une par langage de formes. Lumière haut-gauche,
contour `O` #2a1a2e, ≤ 15 couleurs + transparent par créature.

| Dossier | Créature | Langage | Ce qu'on doit ressentir | Marqueurs | Accent |
|---|---|---|---|---|---|
| `mousseron/` | esprit-champignon de sous-bois | rond | doux, compagnon de début d'aventure | chapeau tacheté, pousse sur la tête, queue-feuille | joues roses |
| `tisonard/` | renard-lézard d'obsidienne | triangle | vif, hargneux, dangereux | museau en coin, 3 épines dorsales, flamme de queue | flamme (émissive) |
| `moellon/` | tortue de pierre à cristaux | carré | lourd, lent, inébranlable | carapace en dalles, arcade lourde, pattes-piliers | cristaux turquoise |

## Créatures complexes (test 12, méthode v10.3, section C16)

| Dossier | Créature | Genre | Ce qu'on doit ressentir | Marqueurs | Accent |
|---|---|---|---|---|---|
| `ossard/` | squelette guerrier | mort-vivant | menace sèche, soldat oublié | orbites vertes, cœur nécrotique dans la cage, épaulière et épée rouillées | vert nécrotique |
| `blemoire/` | liche en robe | mort-vivant mage | puissance froide, rituel | flamme verte derrière la capuche, bras levés en V, orbes flottants | vert nécrotique |
| `magmorne/` | golem de magma | élémentaire | masse brute, chaleur | rochers liés par des joints de lave, cœur de lave, poings flottants | lave (émissive) |

Outils (à lancer depuis le dossier d'une créature) :
`python3 ../trace.py in.txt|NEW:64x64 out.txt cXX.txt` · `python3 ../px.py etape.txt 10` ·
`python3 ../contour.py in.txt out.txt` · `python3 ../planche.py etape_final.png planche_finale.png`
