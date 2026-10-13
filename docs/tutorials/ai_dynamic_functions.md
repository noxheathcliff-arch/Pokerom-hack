# Que sont les fonctions d'IA dynamiques ?
Les fonctions d'IA dynamiques permettent de controller le comportement de l'IA pour chaque combat en étant définie avant un combat particulier dans un script. Elles permettent un scoring unique des capacités, ou des décisions d'échanges qui ne sont pas appliquées à multiples dresseurs ou à toute l'IA.

De ce font, elles sont particulièrement utiles pour les combats uniques comme les combats de boss, ou les Pokémon dominant, ou juste des ajouts narratifs qui s'aideront bien d'une IA spécialisée qui n'agit que durant ces combats spécifiques.

Il y a actuellement deux différents types de fonctions d'IA dynamiques, une qui afffecte le scoring des capacités, et une qui affecte les échanges.

# Comment utiliser la fonction de scoring dynamique des capacités ?
Il y a une poignée d'étapes à suivre:
- Assurez-vous d'avoir activé le flag `AI_FLAG_DYNAMIC_FUNC` pour le dresseur concerné.
- Ecrivez votre logique d'IA personnalisée. Notre modèle est `AI_TagBattlePreferFoe`, et vous devrez faire correspondre la structure des arguments et du renvoi de résultat dans votre propre fonction.
Dans le script qui déclenche le combat, ajoutez un appel à `setdynamicaifunc` en spécifiant votre fonction, comme ceci:
```
setdynamicaifunc AI_TagBattlePreferFoe
multi_2_vs_2 TRAINER_SIRIUS_NOVA_HYPERION_TAG, Text_NovaInsurgence_Arrival_Hyperion_Loss, TRAINER_SIRIUS_NOVA_DEIMOS_RECRUIT_TAG, Text_NovaInsurgence_Arrival_DeimosRecruit_Loss, TRAINER_SIRIUS_WHARF_TRITON_PARTNER, TRAINER_PIC_BACK_TRITON
```
C'est tout! La fonction de scoring sera utilisée dans le combat suivant, et automatiquement effacée à la fin du combat. Vous pouvez ensuite utiliser `setdynamicaifunc` avec la même ou une autre fonction de scoring d'IA selon vos besoins.

# Comment utiliser la fonction d'échange dynamique ?
Il y a une poignée d'étapes à suivre:
- Ecrivez votre logique d'IA personnalisée. Notre modèle est `ShouldSwitchDynFuncExample`, et vous devrez faire correspondre la structure des arguments et du renvoi de résultat dans votre propre fonction.
- Dans le script qui déclenche le combat, ajoutez un appel à `setdynamicswitchaifunc` en spécifiant votre fonction, comme ceci:
```
setdynamicswitchaifunc ShouldSwitchDynFuncExample
trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
```
C'est tout! La fonction d'échange sera utilisée dans le combat suivant, et automatiquement effacée à la fin du combat. Vous pouvez ensuite utiliser `setdynamicswitchaifunc` avec la même ou une autre fonction de scoring d'IA selon vos besoins.
