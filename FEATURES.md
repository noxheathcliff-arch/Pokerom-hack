# Quelles fonctionnalités sont incluses ?
## Sommaire
- [Quelles fonctionnalités sont incluses ?](#quelles-fonctionnalités-sont-incluses)
  - [Sommaire](#sommaire)
  - [Ajout de RFVF](#ajout-de-rfvf)
  - [Fichiers de configuration](#fichiers-de-configuration)
  - [Moteur de combat mis à jour](#moteur-de-combat-mis-à-jour)
  - [Personnalisation complète des dresseurs](#personnalisation-complète-des-dresseurs)
  - [Données des Pokémon](#données-des-pokémon)
  - [Améliorations de l'interface](#améliorations-de-linterface)
  - [Améliorations du moteur](#améliorations-du-moteur)
  - [Améliorations de l'overworld](#améliorations-de-loverworld)
  - [Outils pour développeurs](#outils-pour-développeurs)

## Ajout de RFVF
pokeemeraude-expansion possède *l'intégralité* du contenu de Rouge Feu et Vert Feuille (en Français), c'est-à-dire les maps, les scripts, les sprites, etc. Afin de compiler Rouge Feu ou Vert Feuille, consultez le [tutoriel dédié](docs/tutorials/how_to_frlg.md). Cette portion de pokeemeraude-expansion est jouable, mais n'est pas encore entièrement testée, et doit donc être utilisée avec précaution.

## Fichiers de configuration
Une liste de nombreuses fonctionnalités ci-dessous peut être désactivée selon vos besoins. Vérifiez lesquelles dans ces fichiers :
- [Configuration de l'IA de combat](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/config/ai.h)
- [Configuration de combat](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/config/battle.h)
- [Configuration des "limites" (caps)](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/config/caps.h)
- [Configuration de débogage](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/config/debug.h)
- [Configuration du NaviDex](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/config/dexnav.h)
- [Configuration générale](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/config/general.h)
- [Configuration du Pokédex Plus HGSS](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/config/pokedex_plus_hgss.h)
- [Configuration des objets](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/config/item.h)
- [Configuration des PNJ followers](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/config/follower_npc.h)
- [Configuration de l'overworld](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/config/overworld.h)
- [Configuration des Pokémon](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/config/pokemon.h)
- [Configuration de sauvegarde](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/config/save.h)
- [Configuration des Pokémon activés](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/config/species_enabled.h)
- [Configuration de l'écran de résumé](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/config/summary_screen.h)

## Moteur de combat mis à jour
- ***Mécanismes de combat:*** Méga-Evolution, Primo-Résurgence, Ultra-Explosion, Capacités Z, Dynamax, Gigamax and Téracristallisation.
- ***Nouveaux types de combat:*** Combats sauvages doubles, Combats multi personnalisés, Combats Inversés, Combats 1v2/2v1, Combats Aériens.
- ***Mises à jour des mécaniques de combat:*** Capture critique, Gelure, Menu rapide de Poké Ball, Menu de description de capacité, pas de boost de badge, brouillard 4G, obéissance, Affection, Echange après capture, efficacité d'une capacité en combat, calcul d'argent perdu à la défaite à la RFVF/Gen4+, ombres du style 4G.
- ***Mises à jour des données des capacités:***: Type Fée/Stellaire, split Physique/Spécial/Statut, flags.
- ***Mises à jour des calculs:*** Dégats, expérience, vitesse mi-tour, stats et EVs post-combat, EVs au niveau 100.
- ***Tous les objets, talents, et effets de capacités jusqu'à la 9G:*** Inclut les données de concours jusqu'à la 8G (Epée/Bouclier) ([source](https://pokemonurpg.com/info/contests/rse-move-list/)).
- ***Conditions initiales de combat:*** Niveaux de stats, champs de combat, flags pour l'IA sauvage.
- ***Combats plus rapides:*** Réduction simultanée de PV, raccourci vers l'option "Fuir", introduction de combat plus rapide, réduction de PV plus rapide, calculs d'IA plus rapides.
- ***Personnalisation plus facile:*** Base de code plus propre pour implémenter des capacités et des effets personnalisés.
- ***IA améliorée:*** Plus rapide et prend en compte les nouveaux effets ajoutés par l'Expansion.
- ***Fonctionnalités populaires:*** Limites de niveau/EV, Clause de sommeil, Indicateurs de type.

## Personnalisation complète des dresseurs
- ***Compatible avec la syntaxe des équipes de Pokémon Showdown:*** Créez vos équipes avec le [teambuilder](https://play.pokemonshowdown.com/teambuilder) et collez les résultats!
- ***Données de Pokémon personnalisées:*** Surnoms, EVs, IVs, Capacités, Talents, Poké Balls, Amitié, Nature, Sexe, Chromatisme, niveau de Dynamax, Facteur Gigamax et type Téra.
  - ***"As":*** Gardera un Pokémon "As" pour la fin du combat.
  - ***Pools de dresseurs:*** Un dresseur peut avoir un pool de Pokémon aléatoires au lieu d'équipes fixes.
- ***Messages de dresseur personnalisés mi-combat:*** Au premier tour, après un coup critique, avant la Méga-Evolution, etc.
- ***Nouveaux flags pour l'IA:*** Personnaliser l'intelligence de vos dresseurs.
- ***Poké Balls attachées aux classes de dresseurs:*** Les éleveurs utilisent des Faiblo Balls, etc.

## Données des Pokémon
- ***Structure des données des Pokémon améliorée:*** Optimisation de l'espace pour permettre d'ajouter plus d'informations, telles que le type Téra, les noms en 12 caractères, les statistiques d'Entraînement Ultime, les conditions d'évolution, les PV/effets de statut sauvegardés.
- ***Mise à jour des données de reproduction:*** Héritage de la Poké Ball, des capacités d'œuf, des talents et de la nature, bébés d'encens automatiques au niveau 1.
- ***Mise à jour des données des Pokémon:*** Stats, Types, Talents, Talents Cachés, Groupes d'œufs, Rendements EV, liste de capacités, interdictions dans les zones de combat, nombres garantis de IV parfaits, numéros du Pokédex ORAS.
- ***Manipulation plus simple des données des Pokémon:***: Plus que ~5 fichiers à éditer pour ajouter un nouveau Pokémon, au lieu de 20+ dans pokeemeraude vanilla.
- ***Sprites mis à jour:*** Style DS pour les sprites avec support des animations en 2 images d'Emeraude et de la différence de sexe.
- ***Basculement des Pokémon:*** Vous pouvez désactiver des groupes spécifiques de Pokémon pour économiser de l'espace, y compris les familles, les évolutions intergénérationnelles, les Méga-Évolutions, les formes régionales, etc.
- ***Système d'évolution revu:*** Plusieurs conditions d'évolution peuvent être empilées afin de créer des méthodes complexes sans codage supplémentaire. Toutes les conditions sauf l'affection et le gyroscope de la console sont prises en charge.
- ***Système de changement de forme:*** La plupart des changements de forme peuvent être ajoutés sans codage supplémentaire. Cela inclut le support pour: Tenir/utiliser un objet, atteindre des seuils d'HP, changer le temps météorologique en combat ou non, les Fusions, et plus encore.

## Améliorations de l'interface
- ***Résumé d'un Pokémon:*** Maître des capacités, vue des EVs/IVs, couleurs de nature ([branche](https://github.com/DizzyEggg/pokeemerald/tree/nature_color) par @DizzyEggg).
- ***Menu des Pokémon:*** Option "Déplacer" pour un objet.
- ***Système de stockage des Pokémon:*** Option "Déplacer" par défaut, accès via l'objet Boîte Pokémon.
- ***PokéDex du style HGSS*** ([branche originale](https://github.com/TheXaman/pokeemerald/tree/tx_pokedexPlus_hgss) par @TheXaman): Informations détaillées en jeu accessibles aux joueurs.

## Améliorations du moteur
- ***Tous les correctifs de base de pokeemeraude implémentés par défaut:*** Tout ce qui se trouve sous la définition `BUGFIX`.
- ***Compression améliorée des sprites et palettes:*** Les ressources utilisent moins d'espace que la compression vanilla.
- ***Prise en charge du compilateur moderne:*** Détection plus facile des erreurs potentielles dans votre code.
- ***Choix multiples dynamiques*** ([branche originale](https://github.com/SBird1337/pokeemerald/tree/feature/dynmulti) par @SBird1337): Moyen plus simple d'ajouter des menus de choix multiples pour le scripting.
- ***Générateur de nombres aléatoires de haute qualité:*** Plus de générateur de nombres aléatoires défectueux.

## Améliorations de l'overworld
- ***Mécaniques modernes***: Anti-Brume comme capacité utilisable dans l'overworld, système de repousse du style N2B2+, courir dans les maps intérieures, pas de poison dans l'overworld, pêche à la chaîne, Cherche VS, message de défaite RFVF+.
- ***Followers PNJ et Pokémon***: ([branche](https://github.com/aarant/pokeemerald/tree/followers-expanded-id) par @aarant)
    - *Inclut le support pour les palettes dynamiques dans l'overworld et l'expansion des IDs d'overworld au-delà de 255*
    - *Inclut les sprites de Pokémon jusqu'à la 9G.*
- ***Système Nuit/Jour:*** ([branche](https://github.com/aarant/pokeemerald/tree/lighting-expanded-id) par @aarant)
    - *Inclut le support pour l'horloge simulée (pas en temps réel)*.
- ***Followers PNJ***: ([branche](https://github.com/ghoulslash/pokeemerald/tree/follow_me) par @ghoulslash)
- ***Pop-up de map du style N/B*** ([branche](https://github.com/ravepossum/pokeemerald/tree/bsbob_map_popups) par @BSBob)
- ***Mécanisme de baies du style X/Y:*** Mutations, humidité, mauvaises herbes, nuisibles.
- ***Description des objets à l'obtention*** (branche par @ghoulslash).

## Outils pour développeurs
- ***Système de test intégré:*** Identifiez si vos mécaniques personnalisées ont cassé quelque chose d'autre dans le jeu ou non.
- ***Visualiseur de sprites de Pokémon:*** Testez tous les sprites et animations de Pokémon.
- ***Menu de débogage dans l'overworld*** ([branche originale](https://github.com/TheXaman/pokeemerald/tree/tx_debug_system) par @TheXaman)*: Support d'un menu avec un assortiment de fonctionnalités pour faciliter le débogage, y compris le téléportation, le basculement des flags et des variables, la génération de Pokémon et d'objets et plus encore.
- ***Menu de débogage en combat***: Modifiez des données en direct au milieu d'un combat.
- ***Helper de learnsets:*** Génerez des listes de capacités pour vos CT et maîtres de capacités personnalisés grâce aux données officielles de compatibilité.
- ***Flags de scripts configurables:*** Désactivation des rencontres sauvages, désactivation des combats de dresseurs, forcer/désactiver les Pokémon chromatiques.
- ***Nettoyage du SaveBlock*** ([branche](https://github.com/ghoulslash/pokeemerald/tree/saveblock) par @ghoulslash)
