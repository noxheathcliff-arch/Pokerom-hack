# Écrire pour un jeu Pokémon sur GBA

## 1. Ce que le joueur attend d'un jeu Pokémon

Ces éléments forment un contrat. On peut en rompre un, mais exprès, et en en faisant un moment de l'histoire.

| Élément | Ce qu'il apporte | Comment s'en servir |
|---|---|---|
| Le départ de la maison, le premier Pokémon | Le lien fondateur | Le starter peut compter dans l'histoire : d'où il vient, qui d'autre le voulait |
| Le professeur | La porte d'entrée dans le monde | Il peut avoir un passé, une faute, un lien avec l'antagoniste |
| Le rival | La mesure des progrès du joueur | Lui donner un désir à lui et un arc visible dans son équipe |
| Les arènes et les badges | Le rythme | Chaque champion incarne une facette du thème ou de sa ville |
| L'équipe adverse | La menace | Une idée, un chef, des cadres distincts |
| Le légendaire | Le mythe | Un seul au centre, avec un sens |
| La Ligue | Le sommet attendu | L'endroit idéal pour un retournement, puisque le joueur croit savoir ce qui l'attend |

## 2. Le protagoniste muet

Le joueur ne parle pas et n'a pas de passé imposé. Conséquences :

- **Son arc est plat** (voir `artisanat.md`) : il ne change pas, il change les autres. Les arcs forts appartiennent au rival, aux alliés, à l'antagoniste.
- **Les autres le définissent** par leurs réactions : ce qu'on lui confie, ce qu'on lui reproche, ce qu'on attend de lui.
- **Ses actes parlent** : qui il affronte, qui il aide, ce qu'il rapporte.
- **Les choix oui / non** existent, mais restent rares pour garder leur poids.
- **Pourquoi lui ?** La réponse doit être concrète (il était là, il possède tel Pokémon, il est le seul à avoir vu) et non « il est l'élu ».

## 3. Ancrer le thème dans l'univers

L'histoire doit avoir besoin des Pokémon. Thèmes que l'univers porte naturellement :

- le lien entre humains et Pokémon : amitié, dépendance, exploitation ;
- la capture et la liberté ;
- l'évolution : grandir, changer, refuser de changer ;
- la nature et la technique ;
- les mythes fondateurs et ce que les humains en ont fait ;
- grandir, quitter la maison, y revenir.

Le test : si l'on remplace les Pokémon par des épées, l'histoire tient-elle encore ? Si oui, le thème n'est pas ancré.

## 4. Le ton

- Le monde de Pokémon est lumineux. C'est une force : l'ombre y porte plus loin.
- La mort existe dans la série (Lavande, A.Z., le professeur de la Zone Zéro), toujours traitée avec retenue.
- Avant d'ajouter un élément sombre, demander : à quoi sert-il dans le thème ? Peut-il être suggéré plutôt que montré ?
- L'humour des dresseurs et des passants fait partie du contrat. Un jeu sans respiration fatigue.

## 5. Aligner l'histoire sur la progression

L'histoire avance à la vitesse du jeu. Pour chaque étape, on fixe ensemble l'avancée du jeu et l'avancée du récit.

| Avancée du jeu | Rôle habituel dans le récit |
|---|---|
| Départ, première route | Monde ordinaire, manque, premier signe de la menace |
| Badges 1 et 2 | Rencontres : rival, alliés, première vue de l'antagoniste |
| Badges 3 et 4 | Montée, premiers succès, les enjeux se précisent |
| Milieu du jeu | Basculement : une vérité apparaît, l'enjeu change |
| Badges 5 et 6 | Conséquences, pertes, les alliés se divisent |
| Badge 7 | Point le plus bas |
| Badge 8 et après | Dernier affrontement, résolution |
| Ligue | Épilogue, ou vrai sommet si l'histoire y mène |

Ce tableau se réduit pour un jeu plus court. Avec quatre badges, on garde les cinq points d'appui et on resserre.

Règles pratiques :

- **Chaque zone fait avancer l'histoire d'un pas**, même petit. Une zone sans rien est une zone où le joueur décroche.
- **Les verrous de progression ont une raison dans l'histoire.** Un pont cassé, une route gardée, un champion absent : autant d'occasions de récit.
- **Alterner** tension et détente : après un donjon, une ville.
- **L'antagoniste apparaît régulièrement.** S'il disparaît pendant trois badges, il n'existe plus.
- **Le joueur peut se perdre, faire une pause d'une semaine, revenir.** Un personnage ou un lieu doit pouvoir lui rappeler où il en est, en une phrase.

## 6. Ce que le jeu permet de raconter, et à quel prix

Le jeu est une décompilation d'Émeraude étendue (voir `PROCESSUS_ROMHACK.md`). Chaque scène a un coût de fabrication. L'agent indique ce coût pour chaque scène proposée.

| Moyen | Coût | Remarques |
|---|---|---|
| Dialogue d'un personnage | Faible | Boîtes de deux lignes courtes. Viser peu de boîtes par réplique |
| Personnage qui apparaît ou disparaît selon l'avancée | Faible | Par un indicateur de progression |
| Combat scénarisé (équipe, répliques avant et après) | Faible | Le meilleur rapport entre effort et émotion |
| Objet ou lieu qui raconte (panneau, journal, pièce vide) | Faible | Récit par l'environnement |
| Scène scriptée avec déplacements, émoticônes, fondu | Moyen | Chaque déplacement s'écrit à la main |
| Choix oui / non qui change la suite | Moyen | Multiplie les cas à tester |
| Changement d'une carte après un événement | Moyen | Variante de carte ou modification de tuiles |
| Musique dédiée | Moyen à élevé | Très rentable pour un moment clé |
| Illustration plein écran | Élevé | Pixel art sur mesure, limites de palettes |
| Nouvelle mécanique liée à l'histoire | Élevé | Code C, à réserver à un élément central |
| Embranchements d'histoire, fins multiples | Très élevé | À éviter pour un premier projet, ou limiter à une variation finale |

Ce que le support ne sait pas faire : pas de voix, pas de jeu d'acteur, des personnages de 16 × 32 pixels. L'émotion passe par **le geste du joueur, la musique, le silence et le texte court**.

Moyens d'expression peu coûteux et efficaces :

- l'équipe d'un personnage raconte son état (un Pokémon manquant, un Pokémon qui a évolué, une équipe épuisée) ;
- un combat qu'on ne peut pas gagner, ou qu'on ne veut pas gagner ;
- un lieu où l'on revient et qui a changé ;
- un personnage absent là où il était toujours ;
- un passant dont la phrase change après un événement.

## 7. Le texte

- Deux lignes par boîte, phrases courtes.
- Une idée par boîte.
- Chaque personnage a un vocabulaire et un rythme reconnaissables.
- Aucun personnage n'explique ce que le joueur vient de voir.
- Les passants disent le monde : rumeurs, peurs, blagues. C'est là que se glisse l'exposition, par petites doses.
- Les noms français officiels des Pokémon, capacités, objets et lieux sont utilisés (le jeu est en français).

## 8. Protocole de recherche sur le lore

À suivre **chaque fois** que l'histoire utilise un élément de l'univers.

### Ce qu'il faut vérifier

- **Chaque Pokémon cité** : ses entrées de Pokédex dans plusieurs jeux, son type, son habitat, ses évolutions, ce qu'il peut apprendre.
- **Chaque légendaire ou fabuleux** : son rôle dans les mythes, ses pouvoirs, ses limites, les jeux où il apparaît, ce qui lui est arrivé.
- **Chaque lieu, personnage ou organisation repris** de la série : son histoire, sa place dans la chronologie.
- **Les mécaniques utilisées par le récit** (Méga-Évolution, formes régionales, Pokémon Obscurs…) : leur origine et leurs règles dans l'univers.
- **La disponibilité dans le jeu** : l'espèce, la capacité ou l'objet existe-t-il dans cette base ? Chercher dans `include/constants/species.h`, `include/constants/moves.h`, `include/constants/items.h`, et vérifier les réglages dans `include/config/`.

### Où chercher

1. Poképédia (en français, pour les noms officiels) et Bulbapedia (en anglais, plus détaillé).
2. Les textes des jeux eux-mêmes, quand ils sont cités par ces encyclopédies.
3. Le dépôt, pour ce qui est disponible techniquement.

Si une page ne peut pas être ouverte, le dire et ne pas remplacer par un souvenir présenté comme vérifié.

### Comment étiqueter

Chaque fait de lore utilisé dans un document porte une étiquette :

- `[CANON]` : affirmé par un jeu de la série principale. Indiquer lequel.
- `[CANON SECONDAIRE]` : vient de l'anime, d'un manga, d'un jeu dérivé. Les jeux principaux priment en cas de conflit.
- `[INTERPRÉTATION]` : déduction raisonnable à partir du canon.
- `[PROJET]` : invention propre à ce jeu.

### Règles de cohérence

- Les entrées de Pokédex se contredisent souvent et exagèrent. On peut choisir celle qui sert l'histoire, en le notant.
- S'écarter du canon est permis si c'est **voulu, signalé et expliqué dans l'histoire**. Ce qui est interdit, c'est l'écart par ignorance.
- Un Pokémon agit selon sa nature. Si un Pokémon craintif fait preuve de courage, c'est un événement, et il faut qu'il le soit dans le récit.
- Une région nouvelle peut exister à côté des régions connues. Préciser ses liens avec elles, ou assumer qu'elle en est isolée.
- Les pouvoirs des légendaires suivent les lois de Sanderson (voir `artisanat.md`) : limites et coût connus avant de servir à résoudre quoi que ce soit.
- Tenir une **chronologie** du monde du projet dès qu'il y a un passé : dates relatives, qui savait quoi.

### La fiche de vérification

Pour chaque élément vérifié, noter dans le document de travail :

```
Élément : <nom français officiel>
Usage dans l'histoire : <ce qu'on lui fait faire>
Ce que dit le canon : <faits, avec le jeu d'origine>
Écart éventuel : <aucun / lequel, et pourquoi il est voulu>
Disponible dans le jeu : <oui / non / à ajouter>
Source : <lien>
```
