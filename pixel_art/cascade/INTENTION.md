# B0 — Intention : La cascade d'étoiles

- **Usage** : sprite décoratif animé pour le hack GBA (objet de décor « lieu mystique », écran
  de titre ou carte du monde). Taille **64×64** = taille d'objet GBA autorisée (E8-B),
  **15 couleurs + transparence** (C15). Fond transparent.
- **Idée unique (fantaisie)** : une petite **île de pierre qui flotte** dans le ciel. Une
  source turquoise lumineuse jaillit sur son plateau, déborde par le bord droit et tombe dans
  le vide… mais l'eau ne touche jamais le sol : en bas de sa chute, elle **se défait en
  gouttes qui deviennent des étoiles**, puis s'éteignent.
- **Projection** : 3/4 vu d'un peu au-dessus (le plateau est une ellipse), lumière
  **en haut à gauche**.
- **Volumes** : plateau (ellipse plate) + dessous en **cône renversé** taillé en facettes ;
  un petit arbre rond à gauche (repère d'échelle, équilibre la chute à droite) ; la colonne
  d'eau (cylindre étroit qui s'élargit un peu en tombant) ; un petit éclat de roche flottant.
- **Matières** (tableau 8b) : pierre (facettes, un ton par face, fissures cassées, mousse
  sur le dessus et dans les fentes) ; mousse/herbe (organique, volumes ronds) ; eau
  lumineuse = **émissive** (ombrage inversé : cœur clair) avec une surface en **lentille de
  2 px** dans le bassin ; étoiles (éclats en escalier).
- **Accent** : le **turquoise lumineux** est la seule couleur saturée froide ; la seule
  touche chaude est l'**or pâle des étoiles** (complémentaire, rare). La pierre reste en
  violets gris désaturés pour porter la lumière de l'eau.
- **Marqueurs d'identité** (à garder à toutes les tailles) : île en toupie + colonne d'eau
  claire + étoiles sous la chute.
- **Animation** : boucle d'attente (idle). La pierre ne bouge pas ; **l'eau tombe** (bandes
  d'écume qui accélèrent), les gouttes du bas se fragmentent, rapetissent, s'assombrissent et
  s'effacent (E7-G), et **une seule étoile** scintille en escalier (E2-H). Détail dans
  `ANIM_PLAN.md`.
