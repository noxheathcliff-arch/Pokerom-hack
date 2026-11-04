# ANIM_PLAN — Ouverture du parchemin (méthode Partie E)

## Intention (B0)
Un parchemin roulé s'**ouvre d'un coup sec** après un petit ramassement, ses rouleaux
dépassent et rebondissent, le cadre doré s'**encre** depuis le centre, puis le joyau
**surgit** en haut (pop + rampe de lumière) et lance **un seul éclat**. Émotion :
**solennel mais vif** (récompense, ouverture d'objet rare). Durée totale : **~3,0 s**
(2,0 s de mouvement + 1 s de tenue finale), jouée une seule fois (E2-A, « cérémoniel »).

## Pose de départ / pose d'arrivée
- **Départ (F01)** : parchemin fermé, les deux rouleaux serrés au centre (axes x=56 et 70),
  seule une bande de papier de 4 px visible, pendentif accroché dessous.
- **Arrivée (F21)** : le dessin statique déjà validé `etape_final_tf` (axes x=7 et 119),
  reconstruit **pixel pour pixel** à chaque étape par `build.py` (contrôle automatique).

## Calques (E2-E : une pièce = un calque)
Ordre de profondeur : feuille → décor (cadre + coulure) → pendentif → médaillon → traînée
(smear) → rouleau gauche → rouleau droit → éclat. Les pièces sont **copiées** du dessin
validé (`extraire.py`, pas de redessin), les pièces qui n'existent pas dans le dessin
statique (pop du médaillon, traînée, éclat, pointe du trait) sont dessinées pour chaque
image dans `build.py`, en passant par les 5 étapes.

## Espacement (E2-B) — axe du rouleau gauche / droit
| Image | cxL | Δ | cxR | Δ | Commentaire |
|---|---|---|---|---|---|
| 01 | 56 | – | 70 | – | clé de départ, tenue |
| 02 | 57 | +1 | 69 | −1 | anticipation : ramassement vers le centre |
| 03 | 58 | +1 | 68 | −1 | anticipation tenue (plus longue que l'action) |
| 04 | 38 | −20 | 90 | +22 | **smear** : vitesse max, traînée 1 image |
| 05 | 16 | −22 | 108 | +18 | ouverture (le droit a 1 image de retard d'amplitude) |
| 06 | 4 | −12 | 120 | +12 | **dépassement** gauche 3 px |
| 07 | 9 | +5 | 122 | +2 | rebond 1 gauche (−2 au-delà) ; droit dépasse 3 px (décalé : pas de jumeaux) |
| 08 | 7 | −2 | 118 | −4 | gauche posé ; droit rebond 1 px au-delà |
| 09 | 7 | 0 | 119 | +1 | droit posé, pendentif revient : fin de l'élan |
Ralenti : espacements 22 → 12 → 5 → 2 → 0 (serré près de la clé d'arrivée).

## Feuille de timing (12 i/s, multiples de 16,7 ms)
| Image | Rôle | Ce qui change | Principe | Durée |
|---|---|---|---|---|
| 01 | clé | parchemin fermé | mise en scène, tenue | 300 ms |
| 02 | anticipation | rouleaux se serrent 1 px | anticipation | 133 ms |
| 03 | anticipation (extrême) | serrés 2 px | anticipation > action | 167 ms |
| 04 | smear | traînées papier + poignées | image étirée | 50 ms |
| 05 | passage | rouleaux presque ouverts | ralenti au départ (inversé) | 67 ms |
| 06 | extrême | dépassement gauche | exagération | 83 ms |
| 07 | intervalle | rebond gauche, dépassement droit ; pendentif −1 | chevauchement, pas de jumeaux | 83 ms |
| 08 | intervalle | gauche posé, rebond droit ; pendentif +1 | continuité | 100 ms |
| 09 | clé | rouleaux posés, pendentif posé | ralenti à l'arrivée | 117 ms |
| 10 | passage | cadre doré à moitié (pointe claire) | action secondaire après la principale | 67 ms |
| 11 | clé | cadre complet + coulure | – | 83 ms |
| 12 | pop 1 | médaillon 45 % éteint | pop, rampe émissive (éteint) | 67 ms |
| 13 | pop 2 | médaillon 115 % éteint | pop trop grand | 67 ms |
| 14 | pop 3 | médaillon écrasé, première lueur | écrasement, rampe | 67 ms |
| 15 | pic | médaillon final, pic lumineux | « pop » de lumière | 83 ms |
| 16 | éclat 1 | point | éclat en escalier | 67 ms |
| 17 | éclat 2 | croix 3 | | 67 ms |
| 18 | éclat 3 | croix 5 (pic) | | 100 ms |
| 19 | éclat 4 | croix 3 | | 67 ms |
| 20 | éclat 5 | point | | 67 ms |
| 21 | clé | pose finale = dessin validé | tenue | 1000 ms |
Total : 3 015 ms.

## Validation image par image (E5-A)
- **F01 validée** : 5 étapes regardées (bande_etapes.png), contour fermé, rouleaux 307 px chacun, lumière haut-gauche sur chaque pièce, silhouette = « fermé » conforme au rôle de clé.
- **F02 validée** : anticipation 1 (rouleaux −1 px vers le centre), 5 étapes regardées, contour fermé, 307 px/rouleau, lumière OK.
- **F03 validée** : anticipation max (rouleaux jointifs, feuille cachée), contour fermé, 307 px/rouleau.
- **F04 validée** : smear unique (traînée P sans détail derrière chaque rouleau, pommeaux g), contour fermé autour de la traînée, rouleaux 307 px (zone 318 avec traînée, voulu).
- **F05 validée** : passage (espacement 22 px), sans traînée, feuille + bords nets, lumière OK, 307 px/rouleau.
- **F06 validée** : dépassement (G −4 px de plus que la pose, D −2 px : pas de jumeaux), rouleaux entiers dans le cadre, contour fermé.
- **F07 validée (après correction)** : 1er rendu refusé : le décalage des seules lignes ≥34 cassait le triangle du pendentif (bord gauche vertical, aplat coupé). Corrigé à l'étape 01 : pièce rigide redessinée entière décalée de −1 px (pendentif_*_m1), bélière fermée par un O côté vide. Rouleaux rebond vers l'intérieur, 307 px.
- **F08 validée** : contre-rebond (G −2 / D −4, amplitudes différentes = pas de jumeaux), pendentif +1 px (pièce rigide _p1, triangle intact, retard d'1 image sur les rouleaux = chevauchement), contour OK, 307 px par rouleau.
- **F09 validée** : pose posée (G 7 / D 119), pendentif revenu au centre (chevauchement terminé), tenue 117 ms avant l'apparition du décor ; contour OK, 307 px.
- **F10 validée** : demi-décor (filets dessinés à moitié de leur longueur depuis le centre, couleur moyenne = encre qui « monte »), pendentif fixe ; rouleaux inchangés (aucun bruit), contour OK.
- **F11 validée** : décor complet (filets pleine longueur, encre passée à la couleur finale), aucun autre changement = une seule action ; contour OK.
- **F12 validée** : pop 1/4, médaillon petit (~45 %, redessiné et non réduit), gemme éteinte (b sombre), reflet or en haut à gauche ; contour fermé autour du médaillon, silhouette 01 = rôle prévu.
- **F13 validée** : pop 2/4, dépassement ~115 % (anneau touche le haut du cadre sans être coupé), gemme en première lueur (teinte moyenne), lumière haut-gauche sur l'or et la gemme ; contour fermé.
- **F14 validée** : pop 3/4, médaillon écrasé (plus large, moins haut, volume ≈ conservé), 1er pixel de reflet sur la gemme en haut-gauche ; ombre bas-droite, contour fermé.
- **F15 validée (image seule)** : pop 4/4, taille finale, gemme au pic (plus claire que la pose finale, 1 image), ailettes latérales posées, lumière haut-gauche ; contour fermé. À surveiller en E5-B : les ailettes apparaissent d'un coup.
- **F16 validée** : gemme retombée aux couleurs finales (fin de la rampe émissive), éclat état 1 = point sur l'or haut-gauche (zone la plus claire) ; un seul éclat à l'écran ; contour OK.
- **F17 validée** : éclat état 2 = croix 3 px centrée (59,4) ; les bras gauche/haut mordent le contour (lisible) mais contraste faible w/y sur l'or → à juger dans le GIF (E5-B).
- **F18 validée** : éclat au pic = croix 5 px, centre z, bras w ; le bras haut sort du contour sur le fond (lisible à ×1), durée allongée 100 ms (tenue du pic).
- **F19 validée** : éclat redescend à la croix 3 px (même dessin que F17 : escalier ; ≠ F18 donc pas d'image doublée) ; contour OK.
- **F20 validée** : éclat retombé au point (z en (59,4)), même dessin que F16 sur la zone éclat (escalier) ; ≠ F19 ; contour OK.
- **F21 validée** : tenue finale, identique au dessin fini à chacune des 5 étapes et au final (contrôle automatique « = dessin fini »).

## Contrôle de séquence (E5-B)

Fichiers : `bande.png` (×3, durées), `bande_x1.png`, `oignon.png` (image précédente en rouge à 40 %), `anim.gif` (×4, vraies durées, en boucle). Version avant correction gardée : `*_v1`.

| Contrôle | Résultat |
|---|---|
| Clés lisibles seules (F01, F05, F09, F15, F21) | oui |
| Espacement serré aux clés | oui (F06-F09 : 3, 2, 1, 0 px ; durées allongées 83 → 117 ms) |
| Anticipation | F02-F03 (rouleaux se resserrent avant de s'ouvrir) |
| Image étirée (smear) | F04 seule, jamais deux de suite |
| Dépassement et retour | F07 (trop loin) → F08 (retour) → F09 (posé) |
| Chevauchement | pendentif en retard de 1-2 images sur les rouleaux |
| Pop du médaillon | F12 petit → F13 trop grand → F14 écrasé → F15 taille finale + pic de lumière |
| Éclat en escalier | F16 point → F17 croix 3 → F18 croix 5 → F19 croix 3 → F20 point → F21 rien |
| Une action principale à la fois | ouverture (F01-F09), cadre (F10-F11), médaillon (F12-F15), éclat (F16-F20) |
| Pas de jumeaux | rouleau droit décalé d'1 px d'amplitude sur le gauche |

**Défauts relevés et corrigés**
1. **F07 (pendentif cassé)** : la pièce avait été décalée ligne par ligne. Corrigé à l'étape 01 : pièce rigide redessinée entière.
2. **F15 (ailettes qui apparaissent d'un coup)**, vu à la pelure d'oignon F14 → F15. Corrigé à l'étape 01 de F14 : ailettes en bourgeon 2×3 (x53-54 / x72-73), séparées du corps par le contour ; F14 ≠ F15 vérifié ; bande refaite.
3. **F17 / F18 peu distinctes à ×3** (éclat clair sur l'or) : acceptable, car la différence se lit dans le GIF (100 ms de tenue au pic). Non modifié.

**Durée** : 1,9 s de mouvement + 1 s de tenue = 2,9 s. C'est plus long que la règle UI (200-500 ms), mais c'est une ouverture cérémonielle jouée une seule fois (E2-A).
