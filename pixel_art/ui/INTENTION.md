# UI fantaisie — Text field « parchemin » & Barre de vie « orbe-lance »

## B0 — Intention

| | Text field | Barre de vie |
|---|---|---|
| Format | 127×40 (9-slice possible : rouleaux fixes, feuille étirable) | 112×33 |
| Fantasme | Un parchemin déroulé, scellé par une gemme d'apothicaire | Un cœur prisonnier d'un orbe de verre, dont la vie coule dans une lance d'or |
| Accent saturé unique | Gemme sarcelle (`b c C z`) | Liquide rouge (`R e r h`) — le cœur est taillé *dans* le liquide |
| Matières | Parchemin (rampe chaude `p P q l`), or (`k n g y w`) | Or, verre, liquide émissif |
| Lumière | Haut-gauche | Haut-gauche ; liquide = ombrage inversé (émissif) + lentille |
| États | normal / focus (cadre doré `y`, gemme qui s'allume, curseur d'encre) | plein / moitié / critique (ménisque `h`) |

## R7 — Deux silhouettes comparées

**Text field**
- **A — plaque droite** : rectangle à coins biseautés. Lisible, mais c'est l'UI de n'importe quel jeu.
- **B — parchemin** (retenu) : deux rouleaux + médaillon central + pendentif en losange. La silhouette seule (planche, case noire) dit « fantasy » avant toute couleur.

**Barre de vie**
- **A — barre droite + cœur à gauche** : le cœur et la jauge sont deux objets posés côte à côte.
- **B — orbe + lance effilée** (retenu) : un seul objet, la jauge *sort* de l'orbe et se rétrécit en pointe ; la diminution de largeur crée le mouvement vers la droite et sert de lecture « niveau » même en silhouette.

## Revue de planche — défaut relevé et corrigé

- **Barre de vie** : les 4 rivets de l'anneau (1 px clair + 1 px sombre en diagonale) disparaissaient dans le jaune de l'anneau à ×1. → Rivets passés en **plots 2×2** (`w|y` clair, `n` ×2, `k` sombre) : on les voit à ×1 sur fond clair comme sombre. Appliqué aux 3 états.
- **Text field** : les pommeaux des rouleaux étaient des **pavés 3×3** — à ×1 ils lisaient comme des carrés collés au rouleau. → Col étranglé de 1 px (`OnO` / `OgO`) + reflet `w` : ils deviennent des **perles sur un col**, comme des embouts de bâton tournés.

## Leçons

1. Sur un anneau de 4 px, un détail de 1 px de la même famille de teinte n'existe pas : il faut un contraste de **valeur** (clair + `k`) sur au moins 2×2.
2. Un pommeau se lit par son **étranglement**, pas par sa taille : retirer 2 px vaut mieux qu'en ajouter.
3. Les disques d'ombrage concentriques mangent le contour si `décalage + rayon` dépasse le rayon du contour − 1.
4. Une ligne de lumière (`hline w`) tracée en une fois écrase tout ce qu'elle traverse : la couper autour des ornements.
5. États de jauge générés par script, mais le ménisque (`h`) reste un choix à la main : sans lui, la coupe du liquide paraît plate.
