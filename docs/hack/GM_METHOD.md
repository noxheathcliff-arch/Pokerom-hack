# GM_METHOD — Méthode de design opérationnelle du projet

> **Auteur :** Game Mechanics Director (persona « Milo Hartmann », architecte des systèmes ludiques)
> **Statut :** v1.0 — standard de travail **obligatoire** pour tout agent (superviseurs de domaine, critiques, producteurs, QA).
> **Portée :** toute décision de design du ROM hack (base pokeemeraude-expansion 1.16.4, build Émeraude FR).
> **Source de vérité du design :** `docs/hack/GAME_DESIGN_BIBLE.md` (à venir) et les documents qu'elle lie. Ce document-ci définit **comment** on décide ; la bible dit **ce qui** est décidé.
> **Confidentialité :** la méthode s'appuie sur un corpus privé (Adams & Dormans, *Game Mechanics: Advanced Game Design* ; Koster, *A Theory of Fun* ; corpus UX/game feel). Ce document en est une **reformulation appliquée** ; aucun extrait du corpus ne doit être recopié dans un fichier suivi par git.

---

## 0. Comment utiliser ce document

- **Avant de produire** quoi que ce soit (histoire, carte, dresseur, objet, texte, script) : lire §1 à §3, puis le moteur concerné en §4.
- **Pendant** : remplir le gabarit adapté en §5 (clause de contrat, fiche feature, fiche zone, fiche combat majeur, fiche serrure-clé).
- **Avant de livrer** : passer **sa propre** production à la checklist universelle (§6.1) + la checklist de domaine (§6.2). Un livrable sans checklist remplie est renvoyé sans lecture.
- **En revue** (critiques, superviseurs, GMD) : appliquer le protocole §6.3 et rendre un verdict sur l'échelle §6.4.

Vocabulaire : un mot de ce document a toujours le même sens partout (cf. glossaire §8). Si un agent a besoin d'un terme nouveau, il le propose au GMD au lieu de l'inventer en silence.

---

## 1. La question qui gouverne tout

Chaque décision commence par une seule question :

> **Quelle conduite du joueur voulons-nous rendre passionnante, et quelles règles l'empêchent de se réduire à une solution évidente ?**

Corollaires que tout agent doit appliquer :

1. **Une mécanique ne vaut que par les décisions qu'elle crée.** « On ajoute la Dynamax » n'est pas un argument. « On veut que le joueur arbitre entre puissance immédiate et réserve pour plus tard, et la Dynamax limitée à un usage par combat crée cet arbitrage » en est un.
2. **Un pattern est un outil, pas une recette.** Citer un pattern sans dire quelle décision il produit, quels risques il porte et comment on le contre est refusé.
3. **Complexité ≠ profondeur.** Mega + Z + Dynamax + Tera dans le même combat, c'est de la complexité ; la profondeur, c'est un petit nombre de règles qui interagissent pour produire beaucoup de situations distinctes.
4. **On ne cache pas un core loop faible sous du contenu ou du lore.** Si le combat est ennuyeux, une meilleure cinématique ne le répare pas.
5. **Une idée non testée est une hypothèse.** On la formule comme telle (gabarit §3.2) et on la prouve sur ROM, au moindre coût.

---

## 2. L'ordre de raisonnement (pile de décision à 12 couches)

Toute décision significative descend cette pile **dans l'ordre**. Une couche basse ne peut **jamais** écraser silencieusement une couche haute : si un conflit apparaît (ex. « la carte n'a pas la place pour ce détour »), on le **signale explicitement** et soit on justifie le compromis, soit on retravaille la couche basse.

| # | Couche | Question appliquée à notre jeu | Exemple Pokémon |
|---|---|---|---|
| 1 | Intention / expérience | Que doit ressentir le joueur ici ? | « Inquiétude croissante dans une grotte où les dresseurs disparaissent » |
| 2 | Comportement cible | Que doit-il *faire* ? | Gérer ses PV/PP sans pouvoir revenir au Centre, choisir quand fuir |
| 3 | Pattern / apprentissage / maîtrise | Quel pattern découvre-t-il, que reste-t-il à apprendre après ? | « L'attrition se gère avant le combat, pas pendant » |
| 4 | Mécaniques cœur | Quelle règle minimale rend le pattern manipulable ? | Pas de soin dans la zone, objets rares, rencontres plus denses la nuit |
| 5 | Économie / feedback / progression / émergence | Quels flux, boucles, serrures ? | Source = objets trouvés ; puits = combats ; boucle négative : moins de PV → fuite → moins d'EXP |
| 6 | Level design & enseignement | Comment l'espace enseigne-t-il sans texte ? | Première salle : un objet de soin bien visible + un PNJ épuisé qui « montre » la règle |
| 7 | UX / interface | Quelle info au moment de décider ? | Le joueur voit-il combien de rencontres il reste avant la sortie ? (repères visuels) |
| 8 | Faisabilité technique | Le moteur le permet-il ? | Script de zone, flag, encounter table jour/nuit — vérifier `TECHNICAL_AUDIT.md` |
| 9 | Assets & implémentation | Quels fichiers, quelle réutilisation ? | Carte existante (ex. Grotte Granite) re-habillée, PNJ existants |
| 10 | Polish & présentation | Qu'est-ce qui amplifie la sensation ? | Musique, rythme des textes, `!` d'alerte |
| 11 | Test & comportement observé | Que montre la ROM ? | Traversée sur mGBA, nombre de soins utilisés, taux de K.O. |
| 12 | Itération | Quelle variable unique change-t-on ? | Densité de rencontres −20 %, puis on re-teste |

**Règle de transition vers la production :** une fois une décision validée (gate §4.12), on **arrête de débattre au niveau concept** et on descend : spécification → dépendances → tâches → assets → critères d'acceptation.

---

## 3. La boucle de décision et le gabarit d'hypothèse

### 3.1 La boucle (10 étapes) appliquée

1. **Définir le comportement désiré** — en verbe observable (« le joueur change de Pokémon avant que le sien tombe », pas « le joueur s'amuse »).
2. **Identifier la décision du joueur** — quel choix, entre quelles options, avec quelle information.
3. **Identifier ressources et contraintes** — PV, PP, objets, argent, niveaux plafonnés, membres d'équipe, temps (jour/nuit), information, accès spatial.
4. **Choisir ou construire le mécanisme** — de préférence avec ce que le moteur offre déjà (expansion 1.16.4).
5. **Prédire le feedback** — quelles boucles positives/négatives naissent ?
6. **Prédire la stratégie dominante** — que fera le joueur paresseux et malin ? (voir §4.10, compression)
7. **Identifier la contre-pression** — quelle règle rend cette stratégie non dominante sans la tuer ?
8. **Prototyper** — la plus petite tranche jouable (une route, un combat) dans la ROM.
9. **Observer** — sur émulateur (harnais QA), avec des mesures, pas des impressions.
10. **Réviser** — une variable à la fois.

### 3.2 Gabarit d'hypothèse (à joindre à toute mécanique proposée)

```markdown
**Problème :** quel comportement ou défaut observons-nous / voulons-nous ?
**Hypothèse :** quelle structure l'expliquerait / le produirait ?
**Mécanisme :** quelle règle concrète (et où dans le moteur) ?
**Prédiction :** quel comportement observable cette règle devrait-elle produire ?
**Cas d'échec :** comment un joueur pourrait-il la casser / la contourner ?
**Test :** quel prototype minimal le vérifie (map, script, save d'état, mesure) ?
```

**Exemple court (plafond de niveau) :**
- Problème : le joueur surentraîne son starter et écrase chaque champion sans réfléchir (dominance par niveau).
- Hypothèse : le feedback positif EXP→puissance→EXP n'est pas tempéré.
- Mécanisme : plafond de niveau lié aux badges (option `caps.h` du moteur), type souple ou dur à décider.
- Prédiction : le joueur ne peut plus « acheter » la victoire par le grind ; il doit diversifier l'équipe et préparer.
- Cas d'échec : le plafond est vécu comme un mur arbitraire ; ou le joueur atteint le plafond si tôt que les combats intermédiaires ne rapportent plus rien.
- Test : save avant champion 3, équipe au plafond vs équipe −3 niveaux ; mesurer le nombre de tours et d'objets utilisés.

---

## 4. Les moteurs, appliqués à un jeu d'aventure Pokémon

### 4.1 Familles de mécaniques — qui pilote ?

Un Pokémon solo mobilise cinq familles, mais **pas à égalité** :

| Famille | Rôle dans notre jeu | Rang |
|---|---|---|
| **Manœuvre tactique** | le combat au tour par tour (choix d'attaque, changement, objets, gimmick) | **Dominante** |
| **Économie interne** | l'équipe comme portefeuille, PV/PP/objets/argent, EXP plafonnée | **Co-dominante** |
| **Progression** | badges, CS/clés, arc narratif, ouverture de la carte | Cadre (structure macro) |
| Physique | déplacement case par case, surf, vélo, puzzles de rochers/glace | Support |
| Sociale | quasi absente (solo) ; on ne la simule pas artificiellement | Hors périmètre |

Conséquence d'arbitrage : en cas de conflit, **la tactique et l'économie d'équipe priment** sur un effet de mise en scène. Une scène narrative ne peut pas imposer un combat injouable (ex. combat « perdu d'avance » sans enjeu de décision) sans dérogation explicite.

Toutes nos mécaniques sont **discrètes** (cases, tours, entiers) : elles se prototypent sur papier/tableur **avant** d'être scriptées. Un calcul de courbe de niveaux, une table de rencontres ou une équipe de champion se valident d'abord en feuille, puis sur ROM.

### 4.2 Émergence vs progression — l'architecture à deux échelles

- **Micro = émergence.** Chaque combat, chaque rencontre sauvage, chaque composition d'équipe est un espace de possibilités produit par les règles (types, talents, objets, IA). Le designer ne scénarise pas l'issue ; il façonne le terrain.
- **Macro = progression.** L'ordre des zones, les révélations, les serrures-clés et la courbe de difficulté sont pré-dessinés.
- **Règle d'isolation :** la progression ne doit pas annuler l'émergence localement. Interdits sauf dérogation : combat scripté où le choix du joueur ne change rien ; « défaite obligatoire » qui punit un joueur qui a bien joué. Si l'histoire exige une défaite, elle doit soit être un vrai combat dont on raconte les *deux* issues, soit ne pas être un combat.
- **Trajectoires attendues :** pour chaque segment, nommer au moins deux façons distinctes de réussir (deux équipes / deux approches). Si une seule passe, c'est un puzzle (acceptable ponctuellement, à déclarer comme tel).

### 4.3 Économie interne — dessiner les flux avant les chiffres

Carte économique de référence (à tenir à jour dans la bible ; toute nouvelle ressource s'y ajoute avec source **et** puits) :

| Ressource | Sources | Convertisseurs | Puits (drains) | Échanges | Remarques de design |
|---|---|---|---|---|---|
| PV / PP | Centre Pokémon, objets, talents/attaques de soin | — | combats, statut, météo | — | Ressource d'**attrition** entre deux Centres : c'est elle qui donne du sens à une route |
| Objets de soin / combat | sol, PNJ, Poké Balls cachées, boutiques | argent → objets | usage | vente (ratio non neutre) | Ne jamais rendre le stock illimité-gratuit ; sinon l'attrition disparaît |
| Argent | victoires dresseurs, ventes, objets de valeur | — | boutiques, (perte au K.O.) | vente | Doit avoir **plusieurs usages** concurrents sinon il s'accumule sans valeur |
| EXP / niveaux | combats | — | **plafond** (stopping mechanism) | — | Boucle positive à tempérer (cf. §4.4) |
| Membres d'équipe | captures, dons, échanges PNJ, œufs | évolution (niveau/objet/condition) | boîte (inactivité) | échanges PNJ | **Ressource versatile** : un même Pokémon sert en combat, en clé de terrain, en identité |
| Attaques (CT/maître des capacités) | CT trouvées/achetées, tuteurs | ressources → attaque | slot limité à 4 | — | Les 4 slots sont une contrainte productive : chaque ajout coûte une option |
| Objets tenus / gimmicks (Méga-gemme, Cristal Z, Tera) | quêtes, récompenses | — | slot unique d'objet tenu | — | Un seul objet tenu = arbitrage permanent ; à préserver |
| Information | PNJ, panneaux, Pokédex, indices narratifs | exploration → connaissance | — | — | Ressource **abstraite** mais réelle : la préparation dépend d'elle |
| Accès spatial | badges, CS/outils, flags d'histoire | — | — | — | voir §4.8 |
| Temps (jour/nuit) | horloge | — | — | — | Slow cycle possible : change les rencontres, les PNJ, les événements |

Questions systématiques pour chaque ressource : où naît-elle, comment se transforme-t-elle, où meurt-elle, quelle boucle crée-t-elle, quelle stratégie favorise-t-elle, quel **coût d'opportunité** impose-t-elle ? Une ressource sans puits s'accumule : c'est un défaut de design, pas de code.

### 4.4 Feedback — les boucles qu'on surveille

Boucles natives d'un Pokémon et leur traitement :

1. **Spirale de puissance (positive, lente) :** niveaux → victoires faciles → EXP → niveaux. *Risque :* snowball, ennui. *Tempérer :* plafond de niveau, EXP réduite contre les faibles, adversaires qui escaladent.
2. **Spirale d'attrition (positive, rapide, descendante) :** Pokémon K.O. → moins d'options → plus de K.O. *Risque :* sentiment d'injustice en milieu de donjon. *Tempérer :* points de repos, PNJ soigneurs placés, sorties visibles.
3. **Rééquilibrage par le Centre (négative, forte) :** remet à zéro l'attrition. *Placement des Centres = réglage du rythme.*
4. **Adaptation de l'IA (négative, si conçue) :** les dresseurs avancés punissent la stratégie répétée (changement, couverture de type).
5. **Économie monétaire (positive faible) :** plus d'argent → plus d'objets → victoires plus sûres → plus d'argent. *Tempérer :* puits attractifs (objets rares, services), prix des objets en phase avec la progression.

Pour chaque boucle : **signe, vitesse, intensité, transparence**. La transparence est un choix : on montre au novice les boucles de base (barres de PV, efficacité de type), on laisse aux experts les boucles cachées (calculs de dégâts, ordre de priorité, IA).

### 4.5 Aléatoire — où il est autorisé

- **Aléatoire de condition/input (encouragé) :** quelle espèce apparaît, quel moment de la journée, quel PNJ est présent, quel objet est caché. Il force l'adaptation sans voler l'agence.
- **Aléatoire d'output (toléré, borné) :** coups critiques, précision, plage de dégâts, effets secondaires. Sur les **combats clés**, on ne laisse jamais la victoire dépendre d'un seul jet (ex. une attaque OHKO, un sommeil de 5 tours) : on conçoit les équipes boss pour que le hasard crée du drame mais pas le verdict.
- **Drame utile :** un événement aléatoire est bon s'il ouvre une situation à laquelle le joueur peut répondre ; mauvais s'il tranche sans recours.

### 4.6 Patterns — la combinaison visée (2 à 4, pas plus)

Combinaison de référence d'un RPG de collection (à confirmer en bible) :
- **Playing Style Reinforcement** — l'équipe devient l'identité du joueur (on investit dans « ses » Pokémon).
- **Escalating Challenge** — chaque arène/boss exige plus de préparation.
- **Attrition** (contre l'environnement) — routes et donjons usent les ressources entre deux Centres.
- **Stopping Mechanism** — plafond de niveau / EXP dégressive, pour que la puissance ne remplace pas la compréhension.
- *Optionnel :* **Slow Cycle** (jour/nuit) ; **Arms Race** asymétrique avec un rival qui s'adapte à l'équipe du joueur.

Toute proposition d'un nouveau pattern doit expliciter : intention, conditions, structure, conséquences, risques, combinaisons compatibles, et **ce qu'il remplace ou contredit** dans la combinaison existante (ex. un rubberbanding fort contredit l'Escalating Challenge).

### 4.7 Mission et espace — deux plans, puis un seul niveau

Pour **chaque zone** (route, ville, grotte, bâtiment de l'antagoniste), on produit deux schémas séparés, puis on les intègre :

- **Mission** (temps) : objectif → séquence de défis (types, difficulté relative) → contraintes → ressources disponibles → courbe locale (pic/vallée) → ce qui est enseigné.
- **Espace** (lieu) : disposition → chemins (principal, optionnels, raccourcis) → portes/serrures → repères visuels (landmarks) → zones sûres → zones de risque (herbes hautes, dresseurs aveugles) → emplacements de ressources.
- **Intégration :** la mission exploite les affordances de la carte (une impasse visible avec un objet derrière un arbre coupable = serrure vue) et l'espace crée des décisions pour la mission (deux chemins : l'un long et sûr, l'autre court mais gardé par un dresseur fort).

Contrainte projet : nous **réutilisons** des cartes existantes (Hoenn, éventuellement Kanto FRLG). La fiche zone indique donc aussi : carte source, modifications légères (PNJ, warps, objets, tuiles), et ce que la carte **ne permet pas** (pour ne pas promettre une mission que l'espace ne peut pas porter). Une nouvelle carte n'est demandée que si aucune carte existante ne porte l'intention ; justification obligatoire.

### 4.8 Serrures et clés — les badges, les CS et la connaissance

Inventaire des serrures-clés d'un Pokémon : badges (accès + obéissance + ouverture d'arène suivante), capacités de terrain (Coupe, Surf, Force, Éclate-Roc, Cascade, Plongée, Vol…), objets-clés (Vélo, Scope, Itinéraire), flags d'histoire (barrages de PNJ), plafond de niveau (serrure **dynamique** sur la puissance), et **la compétence du joueur** (une équipe capable de battre un boss *est* une clé).

Règles :
1. **La serrure se voit avant la clé.** Le joueur doit croiser l'arbre à couper, le courant à remonter, la porte scellée **avant** d'obtenir la clé, et suffisamment récemment pour faire le lien lui-même.
2. **La clé répond à un obstacle compréhensible** dans la fiction ET dans les règles. Un barrage de PNJ « parce que » est la serrure la plus faible : à n'utiliser qu'avec une raison diégétique forte et brève.
3. **Préférer les clés intégrées aux mécaniques centrales :** une capacité de terrain qui est aussi une attaque utile ; une connaissance (indice narratif) qui est aussi une préparation de combat.
4. **Les serrures dynamiques** (plafond de niveau, quantité d'objets, équipe capable) se règlent finement ; les serrures binaires (badge) se lisent facilement. On combine les deux.
5. **Les meilleures serrures narratives sont des questions :** un mystère posé tôt est une serrure ; sa révélation est la clé. On applique « question avant réponse » comme « serrure avant clé » (cf. §4.10 et EXPERIENCE_INTENT §8).
6. Documenter pour chaque paire : serrure, clé, ordre de rencontre, distance (temps de jeu) entre les deux, lien avec les mécaniques cœur, revisite prévue.

### 4.9 Séquence d'enseignement — montrer, faire essayer, exiger

Toute mécanique nouvelle pour le joueur (type, statut, météo, talent clé, gimmick, puzzle de terrain) suit six temps :

1. **Introduction sûre** — on la *montre* dans un contexte sans enjeu (un dresseur faible qui l'utilise, un PNJ qui la démontre en combat simulé).
2. **Expérimentation** — le joueur peut l'utiliser librement (objet/Pokémon disponible près de là).
3. **Échec peu coûteux** — un combat où mal la gérer coûte un peu (un objet, un retour au Centre proche), pas une heure de jeu.
4. **Renforcement** — elle revient plusieurs fois, sous des formes légèrement différentes.
5. **Nouvelle contrainte** — on la rend nécessaire, ou on la retourne contre le joueur.
6. **Combinaison** — on la combine avec une mécanique déjà maîtrisée (ex. météo + talent qui en dépend).

Règle : **ne jamais expliquer par texte ce qu'une carte ou un combat peut démontrer.** Le texte n'est admis que pour ce qui ne se devine pas par essai (ex. l'activation d'un gimmick, une commande de menu) — et alors il est court, au moment du besoin.

Limite de charge : **une seule mécanique nouvelle par segment de mission.** Deux nouveautés simultanées = la seconde est reportée.

### 4.10 Apprentissage et maîtrise (couche Koster)

**Cycle d'apprentissage visé à chaque nouveau pattern :** rencontre → hypothèse → action → retour → mise à jour du modèle mental → répétition → maîtrise → recherche d'un nouveau pattern.

**Courbe de maîtrise attendue :** nouveauté → confusion → découverte du pattern → expérimentation → compétence → maîtrise → routine. Notre travail : **changer le contexte juste avant la routine.**

**La question d'or (à poser sur chaque système) :** quelle compréhension visons-nous, par quel chemin le joueur y arrive-t-il, et **quelle part du système reste à découvrir une fois sa première solution trouvée ?**

**Détecteur de problème de maîtrise — signaux en Pokémon :**
| Signal | Manifestation typique | Réponse type |
|---|---|---|
| Routine | « J'appuie sur la même attaque super efficace depuis 3 arènes » | nouveau contexte (équipe boss qui couvre sa faiblesse) |
| Solution dominante | « Mon starter surentraîné bat tout » | nouvelle contrainte (plafond), nouvelle interaction (talents qui punissent) |
| Absence de variation | dresseurs de route tous identiques | variabilité significative (doubles, météo, objets tenus, IA différente) |
| L'expert gagne autant sur du facile | farmer des dresseurs faibles rapporte | EXP plafonnée/dégressive ; récompenses liées à la difficulté (revanches) |

Réponses autorisées : nouveau contexte, nouvelle interaction, variabilité significative, nouvelle contrainte, nouvel espace de décision. **Jamais** « plus de PV aux ennemis » seul.

**Modèle de compression de solution :** le joueur cherchera toujours la règle mémorisable qui résout tout. Pour chaque système, on écrit : *le raccourci naturel* (ex. « tout soigner au Centre et rouler sur la route »), *jusqu'où il marche*, *le moment où le joueur cesse d'expérimenter*. Réponse : garder plusieurs voies viables ou déplacer le contexte avant que la découverte devienne routine.

**Filtre de complexité :** une règle nouvelle doit payer son coût cognitif par un nouveau pattern, une nouvelle décision ou une nouvelle forme de maîtrise. Questions : qu'apprend-on grâce à elle ? quelle possibilité ouvre-t-elle ? quel comportement nouveau produit-elle ? Sinon, elle sort.

**Checklist « présence du fun » d'un défi (à appliquer à chaque combat majeur) :** peut-on s'y préparer ? de plusieurs façons ? l'environnement change-t-il le défi ? les règles sont-elles claires ? le joueur peut-il mobiliser plusieurs capacités, et doit-il le faire en difficulté haute ? y a-t-il du skill dans l'usage ? plusieurs issues de victoire ? l'expert ne gagne-t-il rien à écraser du facile ? l'échec coûte-t-il au moins une nouvelle tentative ? — un « non » = à retravailler.

**Avertissement « designeritis » :** nous sommes des experts du genre ; nous ne voyons plus la courbe d'apprentissage. Les tests de compréhension se font en se plaçant explicitement en joueur novice (profil §EXPERIENCE_INTENT §5) et, quand c'est possible, avec des observations de parties réelles.

### 4.11 Sémiotique — ce que nos règles disent du monde

Chaque mécanique et chaque dispositif narratif est lu sur quatre couches :

| Couche | Question |
|---|---|
| Effet mécanique | Que fait la règle ? |
| Sens fictionnel | Que représente-t-elle dans le monde ? |
| Sens appris | Qu'est-ce que le joueur finit par croire sur ce monde à force de la pratiquer ? |
| Sens thématique | Est-ce cohérent avec le thème de l'histoire (ou volontairement en tension) ? |

Exemples à garder en tête :
- *Capturer* : mécaniquement, ajouter une ressource ; fictionnellement, créer un lien ; appris, « les êtres de ce monde se gagnent par l'épreuve » ; thématiquement, à aligner avec le propos de l'histoire (si l'antagoniste « possède » les Pokémon, la capture du joueur doit pouvoir être relue).
- *Plafond de niveau* : mécaniquement, un stop ; fictionnellement, l'obéissance liée au badge ; appris, « la confiance se mérite » — cohérent si on l'habille ainsi.
- *K.O. / retour au Centre* : échec temporaire ; le monde est clément ; l'histoire ne doit pas prétendre l'inverse sans mécanique qui le porte.

**L'ironie (contradiction volontaire entre mécanique et propos) est un outil avancé** : autorisée seulement si elle est voulue, lisible, et dosée. Une contradiction involontaire est un défaut à corriger.

### 4.12 Du concept à la production — étapes et portes

**Règle d'or : on n'industrialise jamais une hypothèse non validée.** Plus l'incertitude est forte, plus le livrable reste petit et réversible.

Étapes (adaptées à notre chaîne agents + décompilation) :

1. Intention & comportement (GMD)
2. Définition de la mécanique (GMD + superviseur de domaine)
3. Prototype minimal (une zone / un combat / un script, sur branche)
4. Validation (harnais mGBA, mesures)
5. **Fiche feature** (15 champs, §5.2)
6. Spéc UX (flux, textes, menus)
7. Spéc technique (fichiers, flags, vars, scripts, constantes)
8. Décomposition contenu/assets (réutilisation d'abord)
9. Graphe de dépendances (chemin critique, placeholders possibles, tâche la plus invalidante)
10. Tâches d'implémentation
11. Intégration (build `make`)
12. QA (`make check`, tests émulateur, validateurs statiques)
13. Playtest (parcours complet du segment)
14. Polish
15. Prêt à livrer

**Portes (gates) — on ne passe pas sans réponse « oui » prouvée :**
| Porte | Question | Preuve attendue |
|---|---|---|
| Prototype | Le comportement cœur est-il observable ? | capture/sauvegarde d'état + note d'observation |
| Feature | Le bénéfice joueur est-il démontré ? | comparaison avant/après sur le prototype |
| Production | Est-ce assez stable pour investir ? | spéc figée, dépendances listées, aucun TBD bloquant |
| QA | Les critères observables sont-ils satisfaits ? | rapport de test reproductible |
| Polish | Le polish améliore-t-il compréhension/sensation/identité **sans masquer un problème de fond** ? | justification par critère |

**Dépendances, questions systématiques :** qu'est-ce qui doit exister avant quoi ? qu'est-ce qui bloque ? que peut-on remplacer par un placeholder ? quelle tâche, si elle change, invalide le plus de travail (en général : l'ordre des zones et la courbe de niveaux → à figer tôt) ? quel est le chemin critique ?

**Traduction par rôle :** chaque livrable doit être compréhensible par son destinataire sans deviner l'intention : designer → règles et intention ; UX/texte → flux, info, interaction ; programmeur/scripteur → états, événements, flags ; artiste/intégrateur maps → assets ; QA → critères et cas limites ; producteur → séquence, dépendances, périmètre, risques.

### 4.13 UI/UX — l'interface comme dialogue intention → information → action → réponse

Contexte GBA : écran 240×160, boîtes de texte courtes, menus fixes, pas de HUD en exploration. L'UX passe donc **surtout par le monde et le texte**. Règles :

- **Architecture d'information :** classer chaque info selon la décision qu'elle sert : critique maintenant / importante bientôt / contextuelle / optionnelle / historique. Exemple : avant un champion, la « critique maintenant » est le type dominant de l'arène — elle doit être perceptible (décor, PNJ à l'entrée, dresseurs de l'arène) sans fiche à mémoriser.
- **Reconnaissance plutôt que rappel :** ne pas obliger le joueur à se souvenir d'un indice donné 3 heures plus tôt sans le lui remontrer (journal, PNJ récapitulatif, panneau, nom de lieu).
- **Affordances (4 types : physique, cognitive, sensorielle, fonctionnelle) :** arbre coupable reconnaissable, rocher fissuré, eau surfable, PNJ placé face à un chemin = « ici il se passe quelque chose ». Quand un joueur ne sait pas quoi faire, diagnostiquer d'abord : problème d'information, d'affordance, de motivation ou de mécanique ? **Ajouter du texte est la dernière option.**
- **Attention :** une seule chose saillante à la fois (position, mouvement d'un PNJ, emote `!`, musique, son). Si tout clignote, rien ne compte.
- **Modes :** limiter les changements de mode ; signaler clairement chaque mode (combat spécial, puzzle, séquence scénarisée). Le même bouton ne doit pas faire deux choses opposées sans signal.
- **Diégèse :** choisir le canal le plus lisible ; le diégétique n'est pas meilleur par principe. Le joueur doit comprendre un état sans connaître le lore.
- **Charge cognitive :** pendant un apprentissage, pas plus d'une nouveauté d'interface à la fois ; divulgation progressive ; réutiliser les conventions Pokémon que le joueur connaît déjà.
- **Texte FR :** respecter les limites de la boîte (largeur de ligne, 2 lignes visibles, pagination), phrases courtes, une idée par boîte, jamais d'info critique noyée dans une tirade.
- **Ordre de production UI :** décisions & info → flux → prototype → test de compréhension → langage visuel → feedback/motion → accessibilité → implémentation → observation → polish. **On ne commence jamais par le style.**
- **Tests UX :** temps pour comprendre, première action, complétion, erreurs, mauvais chemin, rappel, coût de recherche, erreurs de mode. Une difficulté d'usage n'est pas une difficulté de jeu : diagnostiquer avant de corriger.

### 4.14 Game feel — la sensation de contrôle et de réponse

Sur GBA, le feel tient à : latence input→réponse (déplacement, menus), vitesse du texte, durée des animations de combat, rythme des sons de confirmation, poids des moments clés (secousse d'écran, flash, silence musical avant un boss), inertie des transitions (fondus, warps).

Questions : combien de temps entre l'appui et la réponse ? la causalité est-elle claire ? quel son confirme l'impact ? quel mouvement donne du poids ? quel polish **amplifie réellement** la sensation ?

Règle : **le polish ne corrige pas un système défaillant.** Un boss ennuyeux avec un meilleur thème musical reste ennuyeux. Le feel sert à faire *sentir* une décision déjà intéressante (ex. le silence avant la révélation, le jingle quand une serrure s'ouvre).

QoL connues à évaluer en priorité (faible coût, gain de feel) : vitesse du texte, chaussures de course, réduction des allers-retours, confirmation des choix irréversibles.

---

## 5. Gabarits de livrables

### 5.1 Clause de contrat de design (pour chaque système)

```markdown
**Système :** …
**Structure dominante :** émergence / progression / hybride (préciser l'échelle de chacune)
**Famille mécanique dominante :** tactique / économie interne / progression / physique / sociale
**Économie interne :**
  - Ressources : …
  - Patterns mis en œuvre : … (rôle de chacun)
  - Structure de feedback : positif / négatif / mixte — vitesse, intensité, transparence
**Espace de possibilités :** large / profond / les deux — estimation (nb d'approches viables)
**Stratégies dominantes identifiées :** … (ou « aucune identifiée » + comment on l'a cherchée)
**Mécanismes de contrebalancement :** …
**Signification transmise :** effet mécanique / sens fictionnel / sens appris / sens thématique
**Ce qu'il reste à apprendre après la première solution :** …
```

### 5.2 Fiche feature (15 champs obligatoires)

```markdown
1. Intention de design
2. Problème du joueur (ce qu'il cherche à résoudre)
3. Comportement joueur visé (observable)
4. Règles
5. États (et transitions ; flags/vars associés)
6. Entrées (actions joueur, déclencheurs)
7. Sorties (effets, récompenses)
8. Ressources (consommées / produites)
9. Feedback (canaux : texte, son, visuel, état du monde)
10. Cas limites (séquence rompue, retour arrière, sauvegarde au mauvais moment, équipe vide, boîte pleine…)
11. Paramètres réglables (et valeurs initiales)
12. Dépendances (autres features, cartes, scripts, assets)
13. Risques (design, technique, narratif)
14. Périmètre du prototype
15. Critères d'acceptation (vérifiables sur ROM)
```

### 5.3 Fiche zone (mission + espace)

```markdown
**Zone / carte source :** (ex. Route 113 réutilisée) — modifications prévues — limites de la carte
**Rôle dans l'arc :** (acte, révélation éventuelle, pic/vallée)
**MISSION :** objectif · séquence de défis (type, difficulté relative 1-5) · contraintes · ressources dispo · ce qui est enseigné (étape 1-6 de §4.9)
**ESPACE :** chemins · serrures vues / clés trouvées · landmarks · zones sûres · zones de risque · ressources placées
**INTÉGRATION :** quelles décisions l'espace crée-t-il pour la mission ?
**Rencontres :** table (jour/nuit), rôle de chaque espèce (option d'équipe ? menace ? indice narratif ?)
**Sémiotique :** que dit ce lieu du monde ?
**Critères d'acceptation :** …
```

### 5.4 Fiche combat majeur (champion, rival, antagoniste, boss)

```markdown
**Intention :** ce que le joueur doit ressentir / prouver
**Pattern testé :** quelle compétence de l'arc de maîtrise (EXPERIENCE_INTENT §7)
**Préparation possible :** indices disponibles avant, et où
**Équipe (format Showdown) :** + rôle de chaque membre + couverture
**IA :** flags et justification
**Gimmick éventuel :** lequel, pourquoi ici, comment il est annoncé
**Stratégie dominante prévisible du joueur :** … et contre-pression
**Au moins 2 plans de victoire viables :** …
**Part de hasard dans le verdict :** (doit rester faible)
**Plafond de niveau en vigueur :** …
**Checklist « présence du fun » (§4.10) :** oui/non par item
```

### 5.5 Fiche serrure-clé

```markdown
Serrure · Clé · Ordre de rencontre · Délai entre les deux · Lien aux mécaniques cœur · Sens fictionnel · Revisite prévue · Flag(s)
```

---

## 6. Revue — checklists et protocole

### 6.1 Checklist universelle (tout livrable, tout agent)

**Intention et comportement**
- [ ] L'intention d'expérience est écrite en une phrase et rattachée à `EXPERIENCE_INTENT.md`.
- [ ] Le comportement visé est observable (verbe d'action).
- [ ] La décision du joueur est identifiée (options, information disponible).

**Boucle cœur**
- [ ] Au bout de 20 minutes dans ce contenu, quelle action le joueur répète-t-il encore ?
- [ ] Qu'est-ce qui rend cette action digne d'intérêt ? Quel choix la précède, quel retour la suit ?

**Économie**
- [ ] Sources, convertisseurs, puits identifiés. Aucune ressource sans puits.
- [ ] Quelle boucle se renforce ? Où est la friction ?

**Émergence et dominance**
- [ ] Quelles combinaisons de règles produisent des situations imprévues ? Le joueur comprend-il encore ce qui se passe ?
- [ ] Stratégie dominante cherchée (réponse optimale, stratégie sûre, exploit qui passe à l'échelle, non-choix) ; contre-pression proposée.
- [ ] « Que se passe-t-il si le joueur optimise parfaitement ? » / « … s'il exploite la marge ? »

**Progression**
- [ ] Après cette étape, qu'est-ce que le joueur peut faire qu'il ne pouvait pas faire avant ? Ce gain ouvre-t-il des choix nouveaux (et pas seulement des chiffres plus grands) ?

**Niveau**
- [ ] Mission et espace pensés séparément puis intégrés.
- [ ] Le niveau enseigne par l'usage ; aucune explication textuelle de ce qui peut être montré.
- [ ] Les obstacles révèlent les clés (serrure avant clé).

**Apprentissage et maîtrise**
- [ ] Quel motif le joueur doit-il découvrir ? Quel retour lui montre qu'il s'est trompé ?
- [ ] Vers quelle stratégie converge-t-il au bout d'une demi-heure, et que lui propose-t-on une fois qu'elle est acquise ?
- [ ] La complexité ajoutée ouvre-t-elle un nouveau champ de maîtrise (filtre de complexité) ?

**Sens**
- [ ] Que signifie chaque mécanique (4 couches) ? Incohérence mécanique/fiction ? Ironie voulue ou accidentelle ?

**UX / feel**
- [ ] L'info critique est perceptible au moment de décider ; reconnaissance > rappel.
- [ ] Textes FR dans les limites des boîtes ; une idée par boîte.
- [ ] Le polish proposé ne masque pas un défaut de fond.

**Production**
- [ ] Faisabilité vérifiée contre `TECHNICAL_AUDIT.md` / `FEATURE_INVENTORY.md` / `ASSET_INVENTORY.md` (citer la ligne/section).
- [ ] Réutilisation d'assets d'abord ; toute création justifiée.
- [ ] Aucune modification d'espèce, sprite, données ou animation d'attaque.
- [ ] Critères d'acceptation vérifiables sur ROM.
- [ ] Aucune affirmation « testé » / « implémenté » sans preuve (commande, log, capture).
- [ ] Changement reporté dans le changelog de la bible.

**Interdits de communication (rejet immédiat)**
- [ ] Pas de pattern présenté comme solution automatique.
- [ ] Pas de liste de mécaniques sans les décisions qu'elles créent.
- [ ] Pas de confusion complexité / profondeur.
- [ ] Pas de mécanique ajoutée pour masquer une boucle cœur faible.

### 6.2 Checklists de domaine

**Narration / histoire / dialogues**
- [ ] Chaque révélation a des indices plantés avant (question avant réponse) ; distance indice→révélation documentée.
- [ ] L'histoire crée des serrures et des clés jouables (pas seulement des cinématiques).
- [ ] L'antagoniste a une **signature mécanique** (ce que son projet fait au monde se voit dans les règles : rencontres, accès, équipes, objets).
- [ ] Aucune scène ne retire au joueur une décision qu'il aurait légitimement (pas de défaite imposée gratuite).
- [ ] Le propos est porté par au moins une mécanique, pas uniquement par le texte.
- [ ] Cohérence lore Pokémon (pas de contradiction gratuite avec le canon ; écarts assumés et justifiés).
- [ ] Rythme : alternance tension / respiration ; pas plus de N boîtes de texte d'affilée sans action (N fixé en bible).

**Cartes / level design**
- [ ] Fiche zone (§5.3) remplie ; carte source identifiée ; limites de la carte déclarées.
- [ ] Au moins un landmark par zone ; chemins optionnels qui récompensent l'exploration.
- [ ] Serrures visibles avant les clés ; revisites prévues après obtention des clés.
- [ ] Centres/points de repos placés selon le rythme d'attrition voulu.
- [ ] Warps et connexions vérifiés (aucun cul-de-sac non voulu, aucun softlock).

**Dresseurs / combats / IA**
- [ ] Fiche combat majeur (§5.4) pour chaque combat clé.
- [ ] Courbe de niveaux cohérente avec le plafond en vigueur.
- [ ] Au moins deux plans de victoire viables ; hasard faible dans le verdict.
- [ ] Les dresseurs de route enseignent ce que le combat majeur va tester (§4.9).
- [ ] Format Showdown valide (validateur `tools/qa/validate_trainers.py` quand disponible).
- [ ] Flags IA justifiés par l'intention (pas « le max partout »).

**Économie / objets / rencontres**
- [ ] Carte économique à jour (§4.3).
- [ ] Chaque objet placé a une raison (préparer un défi à venir, récompenser l'exploration, enseigner).
- [ ] Les tables de rencontres offrent des **options d'équipe** pertinentes pour le défi suivant (le joueur peut construire une réponse).
- [ ] Prix et récompenses en phase avec la progression ; pas d'accumulation sans usage.

**UX / texte / menus**
- [ ] Info critique classée et rendue perceptible ; pas de texte là où une affordance suffit.
- [ ] Limites de caractères respectées ; accents/charmap vérifiés.
- [ ] Choix irréversibles confirmés.

**Technique / production**
- [ ] Fiche feature 15 champs complète.
- [ ] Flags/vars nouveaux recensés (pas de collision).
- [ ] Build OK + tests exécutés, preuves jointes.
- [ ] Dépendances et chemin critique à jour.

### 6.3 Protocole de revue (critiques, superviseurs, GMD)

1. **Lire l'intention d'abord**, puis vérifier que le livrable la sert. Un livrable brillant qui sert une autre intention est hors sujet.
2. **Appliquer §6.1 + §6.2** ; noter chaque « non » avec sa cause.
3. **Séparer symptôme et cause** : remonter du défaut à la structure qui le produit (mode diagnostic). Proposer de corriger la cause, pas d'empiler des rustines.
4. **Chercher activement la stratégie dominante et le contournement** : jouer le joueur paresseux et malin.
5. **Structure de retour imposée :** diagnostic → cause → intention → mécanisme proposé → compromis → modes d'échec → prototype de vérification.
6. **En cas de désaccord :** dire clairement ce qui ne va pas **et** proposer au moins une architecture alternative avec son coût.
7. **Conflit de couches :** si une contrainte basse (technique, asset) heurte une couche haute (intention), l'écrire explicitement et escalader au GMD.

### 6.4 Échelle de verdict

| Verdict | Signification | Suite |
|---|---|---|
| **Accepté** | Passe toutes les checklists ; preuves fournies | Intégration / porte suivante |
| **Accepté avec réserves** | Défauts mineurs listés, non bloquants | Corrections tracées, pas de nouvelle revue complète |
| **À reprendre** | Un ou plusieurs « non » sur intention, boucle cœur, dominance, serrure-clé, faisabilité | Nouvelle version + nouvelle revue |
| **Rejeté** | Interdit de communication enfreint, ou contradiction avec la bible, ou contrainte projet violée (espèces/sprites/données) | Retour au concept |

---

## 7. Gouvernance

- **Le GMD arbitre** toute question de design, de cohérence narrative/ludique et de progression. Les superviseurs arbitrent dans leur domaine **sous** les décisions de la bible.
- **La bible est la seule source de vérité.** Toute décision validée y entre avec une ligne de changelog (date, décision, raison, auteur).
- **Preuves obligatoires :** « compilé », « testé », « fonctionne » s'accompagnent de la commande, du résultat et, pour l'émulateur, d'une trace reproductible.
- **Hypothèses ouvertes :** tant qu'une décision n'a pas passé la porte prototype, elle est marquée `HYPOTHÈSE` dans les documents.
- **Garder des alternatives :** on ne verrouille pas trop tôt ; les options écartées restent consignées avec la raison.

---

## 8. Glossaire minimal

- **Boucle cœur** : la séquence d'actions que le joueur répète le plus (ici : lire → choisir → résoudre → recevoir le retour).
- **Attrition** : usure de ressources (PV, PP, objets) entre deux points de restauration.
- **Serrure / clé** : obstacle d'accès / ce qui le lève (objet, capacité, information, compétence).
- **Plafond de niveau** : limite de niveau/EXP liée à la progression ; serrure dynamique sur la puissance.
- **Stratégie dominante** : approche qui bat (presque) tout et rend les autres choix inutiles.
- **Compression de solution** : réduction, par le joueur, du système à une règle mémorisable.
- **Problème de maîtrise** : moment où le système est maîtrisé et ne produit plus d'apprentissage.
- **Signature mécanique** (d'un personnage, d'un lieu) : la trace de sa fiction dans les règles du jeu.
- **Porte (gate)** : point de contrôle où une preuve est exigée avant d'investir davantage.
