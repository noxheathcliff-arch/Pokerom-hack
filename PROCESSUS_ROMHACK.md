# Créer un ROM hack Pokémon : le processus complet

Ce guide explique comment travaillent les créateurs de ROM hacks qui finissent leurs projets. On y voit les grandes étapes, leur ordre et la raison de cet ordre. Il est adapté à **ce dépôt** (`pokeemeraude-expansion` 1.16.4, construit sur la décompilation de Pokémon Émeraude) et à notre façon de travailler : **toi tu décides, on avance par petits blocs, et moi je comble les manques techniques**.

---

## 0. Ce que les créateurs expérimentés savent et que les débutants ignorent

1. **La plupart des ROM hacks ne sortent jamais.** La cause n'est presque jamais technique. C'est l'**ambition qui déborde** : 8 arènes, 150 fakémon, une région entière et 4 mécaniques inédites, tout ça avant d'avoir une seule route jouable. Les projets qui aboutissent commencent petit, sortent une démo, puis grandissent.
2. **Le contenu passe avant le code.** Un hack réussi, c'est avant tout une carte bien construite, une histoire, des combats bien dosés et une progression agréable. Les mécaniques inédites viennent ensuite, et seulement si elles servent le jeu.
3. **On décide sur papier avant de toucher à l'outil.** Les cartes, les équipes des dresseurs et la courbe de niveaux se préparent dans un document ou un tableur. On ne les invente pas en ouvrant Porymap.
4. **On construit par zones jouables complètes.** Une ville, plus sa route, plus ses dresseurs, plus son événement, le tout testé de bout en bout. On évite de faire toutes les cartes, puis tous les dialogues, puis tous les dresseurs : rien ne fonctionnerait avant la toute fin.
5. **On joue à son propre jeu en permanence.** Chaque bloc terminé se teste en émulateur, et le jeu doit toujours se compiler et se lancer.
6. **On ne distribue jamais la ROM.** On distribue un **patch** (`.bps`), et on crédite la base utilisée (ici RHH et Qigast, voir `README.md`).

> **Décompilation ou hack binaire ?** Il existe deux familles de hacks. Les anciens (« binary hacking » avec AdvanceMap, XSE…) modifient directement le fichier `.gba`. La méthode moderne, celle de ce dépôt, part du **code source C reconstitué** du jeu, qu'on modifie puis qu'on recompile. Elle est plus propre, versionnable avec Git, et c'est là que je t'aide le plus.

---

## Vue d'ensemble des phases

| Phase | Nom | Question à laquelle elle répond | Ce qu'on obtient à la fin |
|---|---|---|---|
| 1 | Vision | *Quel jeu, pour qui, de quelle taille ?* | Une fiche projet d'une page |
| 2 | Base technique | *Est-ce que je sais compiler et tester ?* | Une ROM vanilla compilée, la configuration choisie |
| 3 | Pré-production | *Qu'est-ce qu'il y a dans le jeu, dans quel ordre ?* | Carte de la région, scénario, progression, Pokédex régional |
| 4 | Tranche verticale | *Est-ce que ça marche en vrai ?* | 20 à 40 min jouables : une ville, une route, une arène |
| 5 | Production | *On fabrique le reste, zone après zone* | Le jeu complet, couche par couche |
| 6 | Test et équilibrage | *Est-ce que c'est agréable et sans bug ?* | Un jeu qui se termine sans blocage |
| 7 | Finitions | *Est-ce que ça a l'air fini ?* | Écran titre, crédits, petits détails |
| 8 | Sortie | *Comment les gens y jouent ?* | Un patch `.bps`, une page de présentation |

Les phases 4 à 6 forment une **boucle** : chaque nouvelle zone est produite, testée et équilibrée avant de passer à la suivante.

---

## Phase 1 — Vision et cadrage

C'est la phase la plus importante, et c'est **la tienne**. Je peux t'aider à formuler, mais les choix doivent venir de toi. Sinon on obtient un jeu générique.

### À écrire (une page suffit)

- **Le pitch en une phrase.** Exemple : « Un hack court et difficile dans une région volcanique, où le joueur enquête sur la disparition de son frère. »
- **Les 3 piliers.** Ce sont les trois choses qui rendent le jeu unique, et chaque décision future doit en servir au moins un. Exemples : « difficulté type Run & Bun », « ambiance sombre », « exploration non linéaire ».
- **Le public visé** : joueurs nostalgiques, joueurs de Nuzlocke, joueurs occasionnels ?
- **L'ampleur, en chiffres** :
  - nombre de badges (8, ou 4 pour un premier projet ?) ;
  - nombre de villes et de routes ;
  - durée de jeu visée ;
  - Pokémon officiels seulement, ou fakémon en plus ? Combien ?
- **Les mécaniques** : quelle génération de combat (Méga-Évolution, Dynamax, Téracristal… que l'expansion fournit déjà), courant d'expérience partagé, plafond de niveau, rencontres visibles ou non…
- **Les références** : 2 ou 3 jeux ou hacks dont tu veux t'inspirer, et ce que tu leur prends exactement.
- **Ce que le jeu ne fera PAS.** Cette liste protège le projet contre l'ajout sans fin.

### Règle d'or des créateurs : le « MVP »

Définis la **plus petite version du jeu qui serait déjà un vrai jeu**. Par exemple : 3 villes, 2 arènes, un méchant, une fin. C'est la cible n°1. Tout le reste est du bonus pour les versions suivantes.

---

## Phase 2 — Base technique et outils

Le choix de la base est déjà fait : **`pokeemeraude-expansion` 1.16.4**. C'est Émeraude en français, avec les mécaniques modernes jusqu'à la 9ᵉ génération, un menu de debug et un système de tests.

### Outils standard de la communauté

| Outil | Rôle |
|---|---|
| **mGBA** | Émulateur de référence pour tester (précis, avec débogueur) |
| **Porymap** | Éditeur de cartes pour la décompilation : cartes, événements, personnages, warps, connexions |
| **Porytiles** | Convertit des tilesets dessinés en PNG au format du jeu (palettes, métatiles) |
| **Poryscript** *(facultatif)* | Langage de script plus lisible que l'assembleur des scripts d'événement |
| **Git** | Historique, retour en arrière, branches pour expérimenter |
| **Un tableur** | Courbe de niveaux, équipes, répartition des Pokémon |
| **Flips** | Crée le patch `.bps` pour la sortie |
| **Aseprite / LibreSprite** | Pixel art (sprites, tiles, interfaces) en respectant les contraintes GBA |

### Étapes

1. Compiler la ROM **sans rien modifier** (`make`) et la lancer dans mGBA. Si ça ne marche pas, rien d'autre ne marchera.
2. Parcourir les fichiers de configuration `include/config/*.h` (`battle.h`, `pokemon.h`, `overworld.h`, `item.h`, `general.h`…). Ce sont des centaines d'interrupteurs pour les mécaniques. **On les règle maintenant, d'après les choix de la phase 1.**
3. Essayer le **menu de debug** (`include/config/debug.h`) : téléportation, objets, combats de test. Tu l'utiliseras tout le temps.
4. Savoir lancer les tests automatiques (`make check`, voir `docs/tutorials/how_to_testing_system.md`).

---

## Phase 3 — Pré-production : tout planifier sur papier

C'est l'équivalent du plan d'architecte. Ici, aucun code et aucune carte dans l'outil : seulement des documents.

### 3.1 La région

- Un **plan global** dessiné grossièrement : villes, routes, grottes, eau, zones secrètes.
- Pour chaque lieu : son **nom**, son **ambiance**, son **rôle** (arène, scénario, objet clé, simple passage).
- Les **verrous de progression** : qu'est-ce qui empêche le joueur d'aller trop loin trop tôt ? CS (Coupe, Surf…), objets clés, personnages qui bloquent, événements. C'est la colonne vertébrale du level design.
- **Décision importante :** garder Hoenn et la modifier, ou repartir d'une région vide ? Une nouvelle région demande beaucoup plus de travail, voir `docs/tutorials/how_to_delete_vanilla_maps.md`.

### 3.2 Le scénario

- Un synopsis en 5 à 10 lignes.
- Un découpage en **actes**, alignés sur les badges.
- Les personnages principaux : rival, méchants, professeur, figures marquantes. Pour chacun, sa motivation et son évolution.
- Une liste des **événements scénarisés**, dans l'ordre, avec le lieu où chacun se passe.

### 3.3 La progression (le tableur des créateurs)

Pour chaque étape du jeu, une ligne :

| Zone | Badge précédent | Niveau des sauvages | As du dresseur fort | Niveau du champion | Objets obtenus | Ce que ça débloque |
|---|---|---|---|---|---|---|

Ce tableau évite les deux défauts classiques : une difficulté en dents de scie, et un joueur obligé de passer du temps à monter ses Pokémon en niveau.

### 3.4 Le Pokédex régional et les rencontres

- La liste des Pokémon disponibles et **l'endroit où on les trouve**.
- On vérifie que chaque **type** est accessible tôt, qu'il y a une bonne réponse contre chaque champion, et pas trois insectes faibles en début de jeu.
- On choisit les starters et leur rapport avec la première arène.

### 3.5 La direction artistique

- Une palette générale et un style (Émeraude classique, style 4ᵉ génération, style personnel).
- Une liste de ce qu'il faut **créer** et de ce qu'on **réutilise** : tilesets, sprites de dresseurs, personnages sur la carte, interface, fakémon.
- La méthode de `pixel_art/METHODE_PIXEL_ART.md` s'applique à toute cette production.

---

## Phase 4 — La tranche verticale (la démo interne)

Avant de produire tout le jeu, les créateurs font **un petit morceau complet et soigné**. Par exemple : la ville de départ, la route 1, la ville 2 et la première arène. Ce morceau a **tous** les ingrédients finaux : vraies cartes, vrais dialogues, vrais dresseurs, musique, événements, interface.

**Pourquoi :**
- on découvre tous les problèmes techniques d'un coup, sur un petit périmètre ;
- on mesure le **temps réel** que prend une zone, ce qui permet d'estimer tout le projet (et souvent de réduire l'ampleur) ;
- on a quelque chose à montrer et à faire tester tôt ;
- c'est motivant : on joue enfin à SON jeu.

Si la tranche verticale n'est pas agréable à jouer, on corrige **ici**, pas après avoir fait 8 arènes.

---

## Phase 5 — Production, zone par zone

### 5.1 La boucle de production d'une zone

Voici l'ordre que suivent la plupart des créateurs pour **chaque** zone :

1. **Tileset** (si la zone a besoin de nouveaux graphismes) : dessin, puis conversion avec Porytiles.
2. **Carte** dans Porymap : forme générale, puis détails, collisions et hauteurs.
3. **Connexions et warps** : relier la zone au reste (routes, portes, grottes).
4. **Personnages et objets posés** : PNJ, objets au sol, panneaux, objets cachés.
5. **Scripts et événements** : dialogues, cinématiques, conditions (flags et variables).
6. **Dresseurs** : équipes, IA, récompenses, dialogues d'avant et d'après combat.
7. **Rencontres sauvages** : espèces, niveaux, taux.
8. **Musique et sons** de la zone.
9. **Test complet** : arriver dans la zone, tout faire, en repartir, sauvegarder et recharger.
10. **Commit Git.**

### 5.2 Où se trouve chaque chose dans ce dépôt

| Domaine | Fichiers / dossiers | Outil |
|---|---|---|
| Cartes et événements posés | `data/maps/<Carte>/map.json`, `data/layouts/` | Porymap |
| Scripts d'une carte | `data/maps/<Carte>/scripts.inc` | Porymap + éditeur de texte (ou Poryscript) |
| Scripts communs | `data/scripts/` | Éditeur de texte |
| Tilesets | `data/tilesets/` | Porytiles + logiciel de pixel art |
| Dresseurs | `src/data/trainers.party` | Éditeur de texte (format lisible, type Showdown) |
| Rencontres sauvages | `src/data/wild_encounters.json` | Porymap (onglet Wild Pokémon) ou éditeur |
| Espèces, stats, attaques apprises | `src/data/pokemon/` | Éditeur (voir `docs/tutorials/how_to_new_pokemon.md`) |
| Attaques | `src/data/moves_info.h` | Voir `docs/tutorials/how_to_new_move.md` |
| Objets | `src/data/items.h` | Éditeur |
| Graphismes (sprites, interface) | `graphics/` | Logiciel de pixel art (PNG indexés, 16 couleurs) |
| Musique | `sound/` | Séquenceur MIDI, puis `mid2agb` |
| Mécaniques, menus, interface | `src/*.c`, `include/*.h` | Code C (c'est là que je suis le plus utile) |
| Réglages globaux | `include/config/*.h` | Éditeur |
| Flags et variables du scénario | `include/constants/flags.h`, `include/constants/vars.h` | Éditeur |

### 5.3 Les couches transversales (à faire en parallèle, pas en premier)

- **Mécaniques inédites** (nouvel objet, système de quêtes, nouveau menu) : **une à la fois**, chacune comme un bloc isolé, testée et commitée seule.
- **Fakémon** : sprite de face, de dos, icône, cri, données, Pokédex, évolutions. Comptez une bonne journée de travail par fakémon soigné. C'est pour ça que les projets réalistes en ont peu.
- **Interface** (écrans de menu, HUD) : par exemple l'Orbe de vie qu'on vient de faire. Elle doit respecter les contraintes de la GBA (palettes de 16 couleurs, tuiles de 8×8, mémoire vidéo limitée).

### 5.4 Les contraintes de la GBA à garder en tête

- **Palettes** : 16 couleurs par palette, dont une transparente. Un nombre limité de palettes à l'écran.
- **Tuiles** de 8×8 pixels. Le décor est fait de **métatiles** de 16×16.
- **Écran** de 240×160 pixels.
- **Mémoire de sauvegarde limitée** : ajouter des données à la sauvegarde se planifie. **Changer la structure de sauvegarde casse les sauvegardes existantes**, ce qui compte pour les testeurs.
- **Taille de la ROM** : 32 Mo maximum, ce qui est large en pratique.

---

## Phase 6 — Test et équilibrage

- **Toi, à chaque bloc** : test immédiat en émulateur.
- **Une partie complète** du début jusqu'au point le plus avancé, régulièrement, **sans le menu de debug**. C'est là qu'on repère les blocages et les trous de progression.
- **Les testeurs externes** : 2 à 5 personnes de confiance. On regarde où ils bloquent, s'ennuient ou meurent. On ne leur explique rien avant.
- **Un suivi des bugs** : une simple liste (ou les issues GitHub) avec la description, comment reproduire et la priorité.
- **L'équilibrage** : confronter le tableur de progression (3.3) au ressenti réel. Le calculateur de dégâts de Showdown aide à vérifier les champions.
- **Les tests automatiques** (`make check`) pour les mécaniques de combat qu'on modifie.

**Bugs classiques des hacks :**
- un flag jamais activé, qui laisse un PNJ bloquer le passage pour toujours ;
- un warp qui mène au mauvais endroit ;
- un joueur coincé sans pouvoir revenir en arrière (Surf ou Coupe manquant) ;
- un événement rejouable à l'infini ;
- un problème de palette qui fait passer un sprite à la mauvaise couleur ;
- une sauvegarde corrompue après une modification de structure.

---

## Phase 7 — Finitions

- Écran titre, introduction, crédits de fin.
- Relecture **de tous les textes** : orthographe, ton, longueur des boîtes de dialogue.
- Des petits détails qui donnent de la vie : PNJ qui commentent les événements, objets cachés, zones optionnelles.
- Une cohérence visuelle générale.
- Des options de confort pour le joueur (vitesse du texte, objets à la place des CS…). L'expansion en fournit beaucoup dans `include/config/`.

---

## Phase 8 — Sortie

1. Compiler la version finale et vérifier qu'elle se lance sur une sauvegarde neuve.
2. Créer un **patch `.bps`** avec Flips, à partir de la ROM Émeraude d'origine. **Ne jamais distribuer la ROM elle-même.**
3. Rédiger une page de présentation : pitch, captures d'écran, fonctionnalités, durée, **crédits** (RHH, Qigast, auteurs des ressources utilisées, testeurs).
4. Numéroter les versions : `v0.1` (démo), `v0.5` (bêta), `v1.0`.
5. Publier là où la communauté se trouve : forums et Discord de hacking Pokémon, et la page GitHub du projet.
6. Prévoir une **version corrective** rapide : il y a toujours des bugs que personne n'a vus.

**Rappel :** les hacks sont des projets de fans, **non commerciaux**. Ne jamais vendre le jeu ni accepter d'argent contre lui.

---

## Comment on travaille ensemble, toi et moi

### La répartition des rôles

| Toi (le directeur du projet) | Moi (l'assistant technique) | Ensemble |
|---|---|---|
| Vision, piliers, ampleur | Code C, scripts, formats de données | Découpage en blocs |
| Histoire, personnages, dialogues | Explication de chaque modification | Revue du résultat |
| Choix des Pokémon, équipes, difficulté | Recherche dans le code de l'expansion | Résolution des bugs |
| Direction artistique, validation des visuels | Production de pixel art selon la méthode | Décisions sur les mécaniques |
| **Tests en émulateur** | Compilation, tests automatiques | Bilan après chaque phase |

Ce partage évite le « AI slop » : **toutes les décisions créatives viennent de toi**, et j'exécute en te montrant ce que je fais.

### Qu'est-ce qu'un bon bloc ?

Un bloc, c'est **une seule chose, terminée et testable en moins d'une session**. Exemples :

- ✅ « Ajoute le dresseur Gamin Théo sur la route 101, avec cette équipe et ces dialogues. »
- ✅ « Crée le script de la scène où le rival nous attend à la sortie de la ville. »
- ✅ « Active la Méga-Évolution et désactive le Dynamax dans la configuration. »
- ✅ « Fais l'icône 32×32 de l'objet Clé Volcan. »
- ❌ « Fais la région. » (trop gros, et rien ne serait de toi)
- ❌ « Améliore les combats. » (aucun critère pour savoir quand c'est fini)

### Le modèle de demande d'un bloc

Copie-colle ce modèle et remplis-le à chaque demande. C'est ce qui économise le plus ton quota : je n'ai pas à deviner, donc pas à explorer.

```
BLOC : <nom court>
OBJECTIF : <ce que le joueur doit voir ou vivre>
DÉTAILS : <noms, dialogues, Pokémon, niveaux, positions… tout ce que tu as décidé>
FICHIERS CONCERNÉS (si tu sais) : <ex. data/maps/Route101/>
C'EST FINI QUAND : <le critère de test, ex. « je parle au PNJ, il me donne la Potion une seule fois »>
À NE PAS FAIRE : <ce qu'il ne faut pas toucher>
```

### Le cycle d'un bloc

1. **Toi** : tu remplis la demande.
2. **Moi** : je pose des questions si une décision manque. Je ne l'invente pas.
3. **Moi** : je fais la modification et je compile.
4. **Moi** : je t'explique en quelques lignes ce que j'ai changé et où.
5. **Toi** : tu testes dans mGBA.
6. **Ensemble** : on corrige si besoin.
7. **Moi** : je commite avec un message clair.

### Conseils pour économiser ton quota

- **Une conversation = un bloc, ou une petite série de blocs liés.** Les longues conversations coûtent plus cher à chaque message.
- **Donne les décisions d'avance.** « Équipe : Medhyèna niv. 5, Zigzaton niv. 4 » coûte moins cher que « fais une équipe sympa », suivi de deux allers-retours.
- **Indique le fichier** quand tu le connais.
- **Garde les documents de pré-production** (phase 3) dans le dépôt, par exemple dans un dossier `projet/`. Je peux les lire au lieu de te reposer les questions.
- **Fais toi-même ce qui est visuel et rapide dans Porymap** (déplacer un PNJ, peindre une carte). Garde-moi pour le code, les scripts, la logique et les recherches.
- **Teste avant d'enchaîner.** Un bug repéré tout de suite coûte un message ; repéré dix blocs plus tard, il en coûte vingt.

---

## Feuille de route proposée pour ton projet

Coche au fur et à mesure.

**Phase 1 — Vision**
- [ ] Bloc 1 : écrire la fiche projet (pitch, piliers, public, ampleur, références, ce qu'on ne fera pas)
- [ ] Bloc 2 : définir le MVP

**Phase 2 — Base technique**
- [ ] Bloc 3 : compiler la ROM vanilla et la lancer dans mGBA
- [ ] Bloc 4 : installer Porymap, ouvrir le projet, se balader dans les cartes
- [ ] Bloc 5 : régler `include/config/*.h` selon la fiche projet (je t'explique chaque option importante)

**Phase 3 — Pré-production**
- [ ] Bloc 6 : plan de la région (dessin, même grossier) et liste des lieux
- [ ] Bloc 7 : synopsis et découpage en actes
- [ ] Bloc 8 : tableur de progression (niveaux, badges, verrous)
- [ ] Bloc 9 : Pokédex régional et répartition des rencontres
- [ ] Bloc 10 : direction artistique et liste des ressources à créer

**Phase 4 — Tranche verticale**
- [ ] Bloc 11 : ville de départ (carte, PNJ, maison du joueur)
- [ ] Bloc 12 : introduction et choix du starter
- [ ] Bloc 13 : route 1 (carte, dresseurs, rencontres)
- [ ] Bloc 14 : ville 2 et Centre Pokémon
- [ ] Bloc 15 : première arène (puzzle, dresseurs, champion, badge)
- [ ] Bloc 16 : partie complète de la tranche, bilan et ajustements

**Phase 5 et suivantes** : on répète la boucle de la section 5.1 pour chaque zone du plan, puis on passe aux phases 6, 7 et 8.

---

## Les pièges qui tuent les projets (à relire de temps en temps)

1. **Une ampleur trop grande.** Le remède : le MVP, et une liste « pas dans cette version ».
2. **Commencer par le code compliqué.** Un nouveau système de combat avant la moindre route jouable, c'est le meilleur moyen d'abandonner.
3. **Tout refaire graphiquement dès le départ.** On réutilise les ressources d'Émeraude pour les premières zones, et on les remplace plus tard.
4. **Ne jamais jouer à son jeu.** Les problèmes de rythme et de difficulté ne se voient qu'en jouant.
5. **Pas de sauvegarde du travail.** Git, et un commit par bloc.
6. **Mettre à jour la base en plein projet sans précaution.** Une mise à jour de l'expansion se fait sur une branche à part, puis on teste.
7. **Tout déléguer à l'IA.** Le jeu perd son âme. C'est exactement ce que cette méthode évite.
8. **Le perfectionnisme sur un détail.** On avance, puis on revient faire les finitions en phase 7.
