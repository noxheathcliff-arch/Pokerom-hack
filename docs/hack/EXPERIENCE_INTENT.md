# EXPERIENCE_INTENT — Intention d'expérience (couches 1 à 3)

> **Auteur :** Game Mechanics Director — v1.0, 2026-10-13
> **Statut :** fondation de conception. Écrit **avant** toute histoire. Les directions narratives de l'étape 2 seront évaluées contre ce document (§9).
> **Méthode :** `GM_METHOD.md` (pile de décision : intention → comportement → apprentissage/maîtrise). Tout ce qui suit est au niveau des couches 1-3 ; les couches techniques sont marquées `HYPOTHÈSE` tant que les audits (`TECHNICAL_AUDIT.md`, `FEATURE_INVENTORY.md`, `ASSET_INVENTORY.md`) ne sont pas disponibles.
> **Constat moteur vérifié à ce stade (lecture de `include/config/`) :** plafonds de niveau disponibles mais désactivés (`caps.h` : `B_EXP_CAP_TYPE = EXP_CAP_NONE`, modes dur/souple/par flags ou variable possibles) ; DexNav et suiveurs désactivés par défaut ; flags Dynamax/Tera/clause sommeil configurables. Rien n'est encore choisi.

---

## 1. La thèse en une phrase

> **Le joueur part comme quelqu'un qui *subit* les combats et le monde, et finit comme quelqu'un qui les *lit* : il anticipe un adversaire, construit une équipe comme une réponse à une question, et comprend ce qui s'est réellement passé dans cette région — parce que le jeu lui a appris à observer, pas parce qu'on le lui a raconté.**

Deux apprentissages parallèles, qui doivent se faire écho :
- **Lire le combat** (système) : passer de « j'attaque avec ce qui est super efficace » à « je sais ce que l'adversaire va faire et j'ai préparé de quoi y répondre ».
- **Lire le monde** (récit) : passer de « je suis les flèches de l'histoire » à « j'ai remarqué les indices, j'ai formé une hypothèse, la révélation m'a donné raison — ou m'a surpris d'une façon que je trouve juste ».

Le même verbe — **observer, formuler une hypothèse, préparer, vérifier** — doit être la compétence récompensée dans les deux couches. C'est le cœur de la cohérence sémiotique visée (GM_METHOD §4.11) : le jeu enseigne par ses règles ce que l'histoire affirme.

---

## 2. Ce que le joueur doit ressentir, apprendre, maîtriser

### 2.1 Ressentir
| Émotion visée | Où elle naît (systémiquement) | Anti-modèle à éviter |
|---|---|---|
| **Curiosité** | serrures vues avant les clés ; questions narratives ouvertes ; zones aperçues inaccessibles | le joueur suit un couloir sans rien à se demander |
| **Compétence croissante** | combats qui exigent de nouvelles lectures, et le joueur sent qu'il y répond mieux | victoire par le niveau seul (le joueur n'a rien appris) |
| **Tension maîtrisée** | attrition entre deux Centres ; boss préparables mais exigeants | tension par injustice (hasard qui tranche, info cachée impossible à deviner) |
| **Attachement** | l'équipe comme investissement (identité de jeu) ; personnages dont on revoit les conséquences | membres d'équipe interchangeables ; PNJ jetables |
| **Fierté (le poing levé)** | un boss vaincu avec un plan que le joueur a construit lui-même | victoire « donnée » par un script |
| **Émerveillement / révélation** | un indice longtemps ignoré qui se remet en place (reconnaître un motif avec une surprise) | révélation sans indices (arbitraire) ou trop télégraphiée (pas de surprise) |

### 2.2 Apprendre (patterns à transmettre)
1. **Le type n'est que la première couche** : talents, objets tenus, vitesse, priorité, statut et météo réécrivent le tableau des types.
2. **On gagne avant le combat** : la préparation (composition, objets, ordre) pèse plus que l'exécution.
3. **Un Pokémon a plusieurs usages** : attaquant, soutien, éclaireur, clé de terrain — l'équipe est un portefeuille, pas une hiérarchie.
4. **Les ressources s'usent** : une route se gère du début à la fin, pas combat par combat.
5. **L'adversaire a une logique** : les dresseurs (et l'antagoniste) ont des intentions lisibles qu'on peut anticiper.
6. **Le monde parle** : les lieux, les rencontres, les PNJ portent des indices ; l'attention est récompensée.

### 2.3 Maîtriser (le savoir-faire final)
Face à un adversaire inconnu mais annoncé, **construire une réponse** (équipe, objets, gimmick, ordre) avec des ressources contraintes (plafond de niveau, stock limité), puis **ajuster en cours de combat** quand l'IA déjoue le plan initial. La maîtrise n'est pas d'avoir « l'équipe ultime » mais de savoir **réorganiser** son équipe pour chaque question.

---

## 3. Le type de fun visé (Koster et grilles voisines)

- **Fun principal = maîtrise mentale d'un problème** (le sens strict de Koster). Siège : le combat et la construction d'équipe. C'est le fun dur (« hard fun ») : on le paie d'un effort, on en retire de la fierté.
- **Fun secondaire = découverte** (exploration, capture, zones cachées) et **plaisir de reconnaissance** (la révélation qui remet en ordre des indices). C'est le fun « facile » qui donne de la respiration entre deux pics.
- **Plaisirs non-fun mais assumés** : esthétique (musique, lieux), drame narratif, attachement, réconfort (rejouer une zone maîtrisée). Ils **soutiennent**, ils ne **remplacent** pas le fun d'apprentissage.
- **Écarté** : fun social/statut (solo), fantasme de puissance gratuite (domination sans apprentissage — c'est précisément ce que le plafond de niveau et l'IA combattent).

Règle de pondération : sur une heure de jeu, le joueur doit vivre **au moins un problème qu'il ne savait pas résoudre au début de l'heure**. Si une heure entière se passe sans apprentissage nouveau, le contenu est un remplissage (signal du détecteur de maîtrise).

---

## 4. Comportements cibles dans le temps

Les comportements ci-dessous sont **observables** sur une session (émulateur ou playtest). Ils servent de critères d'acceptation de haut niveau pour la tranche verticale et le jeu complet.

### Minute 20 (premières routes, avant ou autour du premier vrai combat exigeant)
- Le joueur **a capturé au moins un Pokémon par choix** (pas seulement le premier possible), parce qu'il a vu une raison de le vouloir (type, talent, indice d'un PNJ).
- Il **a changé de Pokémon au moins une fois en combat** de sa propre initiative.
- Il **a vu au moins une serrure** (obstacle, lieu inaccessible, question narrative) qu'il ne peut pas encore lever, et il s'en souvient.
- Il **a lu un indice environnemental** (un PNJ, un décor) qui lui a servi peu après.
- Il **a une question sur l'histoire** qu'il voudrait voir résolue.
- Il **n'a pas lu plus de quelques écrans de texte d'affilée** sans reprendre la main.

### Heure 5 (≈ 2-3 badges, milieu de l'acte 1)
- Il **prépare avant un combat majeur** : il modifie son équipe ou achète/équipe un objet en fonction de ce qu'il a appris de l'adversaire.
- Il **utilise au moins une mécanique au-delà du type** (statut, boost de stat, objet tenu, talent) de façon délibérée.
- Il **gère une route en attrition** : il décide quand rentrer au Centre et quand pousser.
- Il **revient vers une serrure vue plus tôt** dès qu'il a la clé, sans qu'on le lui dise.
- Il **formule une hypothèse** sur le mystère central (même fausse) — le jeu doit lui avoir donné de quoi.
- Il **a déjà perdu un combat** (ou failli) et compris pourquoi ; il a réessayé autrement.

### Heure 20 (fin d'acte 2 / approche de la Ligue)
- Il **change la composition** de son équipe selon l'adversaire (au moins un membre tourne entre deux combats majeurs).
- Il **anticipe l'IA** : il change de Pokémon en prévision d'un coup, il garde une réponse pour un Pokémon dangereux annoncé.
- Il **combine deux mécaniques** apprises (ex. météo + talent, statut + changement, gimmick + couverture).
- Il **explore l'optionnel** parce que l'optionnel rapporte des options (objets, Pokémon, indices), pas seulement des collectibles.
- Il **relit les événements passés à la lumière d'une révélation** (« c'est donc pour ça que… »).
- Il **ne peut plus gagner en appuyant sur un seul bouton** contre les adversaires majeurs — et ne le souhaite plus.

---

## 5. Modèle de variation des joueurs

### 5.1 Dimensions retenues
| Dimension | Casual / découvreur | Vétéran / optimiseur |
|---|---|---|
| Compétence préalable | connaît les types de base | connaît talents, EV/IV, IA, Showdown |
| Vitesse d'apprentissage | lente, a besoin de répétition | rapide, s'ennuie à la répétition |
| Tolérance au risque | faible : grinde, sur-prépare | élevée : cherche la limite |
| Préférence spatiale / verbale | suit les PNJ et le texte | lit les cartes, cherche les recoins |
| Logique / intuition | intuition (« ce Pokémon a l'air fort ») | calcul (dégâts, vitesses) |
| Social | — (solo) | — (peut venir du Nuzlocke/challenge communautaire) |

### 5.2 Principe : varier la distribution des défis, jamais le pattern
Les deux profils doivent apprendre **la même chose** (lire, préparer, ajuster). On change **la marge**, pas la leçon :

| Levier | Casual | Vétéran | Ce qui ne change pas |
|---|---|---|---|
| Marge de préparation | plus d'indices visibles avant un boss, plus d'objets trouvables | moins d'indices, stock plus serré | un boss se prépare ; l'info existe dans le monde |
| Plafond de niveau | souple (EXP réduite au-delà) `HYPOTHÈSE` | dur `HYPOTHÈSE` | le niveau ne remplace pas la compréhension |
| IA des boss | lisible, punit les erreurs grossières | anticipe, change, couvre ses faiblesses | les boss ont une logique cohérente avec leur personnage |
| Contenu optionnel | facultatif, récompense douce | défis exigeants (revanches, dresseurs d'élite, combats à contrainte) aux récompenses réelles | l'optionnel rapporte des **options**, jamais un « bouton gagner » |
| Rythme | Centres rapprochés | attrition plus longue | les routes restent des épreuves de gestion |

`HYPOTHÈSE` à valider : un choix de mode en début de partie (deux niveaux, nommés diégétiquement) qui règle **plafond, IA et objets en combat contre les boss** — sans jamais changer les cartes, l'histoire ni les équipes de base. Alternative si la faisabilité ou la lisibilité est mauvaise : un seul mode calibré « novice attentif », plus une couche optionnelle de défis pour vétérans. Décision à l'étape de préproduction mécaniques.

### 5.3 Le piège à éviter des deux côtés
- **Casual :** le jeu ne doit jamais lui permettre de *contourner* l'apprentissage (grinder 15 niveaux) — sinon il bute plus tard sur un mur incompréhensible. Le plafond est aussi une protection pour lui.
- **Vétéran :** il ne doit jamais gagner autant à écraser du facile qu'à affronter du difficile (problème de maîtrise : « se nourrir par le bas »). Les récompenses substantielles sont liées à la difficulté.

---

## 6. Structure cible — clause de contrat de design (niveau jeu entier)

**Structure dominante :** **hybride à deux échelles** — *progression* au niveau macro (voyage spatial + arc narratif + déblocage de capacités de terrain + plafonds par badge) ; *émergence* au niveau micro (chaque combat, chaque rencontre, chaque composition d'équipe). La progression fournit le cadre ; elle ne doit jamais annuler localement l'émergence (pas de combat où la décision ne compte pas).

**Famille mécanique dominante :** **manœuvre tactique** (combat au tour par tour), co-dominée par **l'économie interne** de l'équipe et des ressources. Progression en cadre ; physique (puzzles de terrain) en support ; social hors périmètre.

**Économie interne :**
- Ressources : PV/PP (attrition), objets de soin et de combat, argent, EXP/niveaux (plafonnés), membres d'équipe (ressource versatile), slots d'attaques (4), slot d'objet tenu (1), gimmick de combat (charge par combat), information (indices de combat et de récit), accès spatial (badges, capacités de terrain, flags), temps (jour/nuit).
- Patterns mis en œuvre :
  - *Playing Style Reinforcement* — l'équipe devient l'identité du joueur ; on veut cet attachement.
  - *Escalating Challenge* — chaque épreuve majeure exige une lecture de plus.
  - *Attrition* (contre l'environnement) — donne du sens aux routes et donjons.
  - *Stopping Mechanism* — plafond de niveau / EXP dégressive : empêche la puissance de remplacer la compréhension.
  - *Optionnels à valider* : *Slow Cycle* jour/nuit (phases de rencontres/événements), *Arms Race* asymétrique avec un rival qui adapte son équipe à celle du joueur.
- Structure de feedback : **mixte**. Positive lente (niveaux, équipe) **tempérée** par le plafond ; positive rapide descendante (attrition) **coupée** par les Centres et points de repos ; négative (IA adaptative, boss qui couvrent leurs faiblesses) pour empêcher la routine. Transparence : boucles de base visibles (PV, efficacité, badges/plafond annoncé) ; boucles fines cachées pour les experts (calculs, IA).

**Espace de possibilités :** **large et profond**. Large : centaines d'espèces, compositions et sets. Profond : séquences de combats où les ressources s'enchaînent, et trajectoires d'équipe sur 20+ heures. Cible : au moins **3 approches viables** par combat majeur à partir de l'acte 2, **2** en acte 1.

**Stratégies dominantes identifiées (a priori, à contrer) :**
1. Surentraîner le starter et dominer par le niveau.
2. Spammer l'attaque la plus forte / super efficace.
3. Empiler les soins pendant les boss (l'IA ne peut pas suivre).
4. Un « sweeper » boosté qui nettoie toute équipe de l'IA.
5. Le gimmick comme bouton « je gagne » (Méga/Tera/Dynamax/Z dès qu'il est disponible).
6. Fuir systématiquement les combats sauvages → sous-niveau puis grind brutal (le mur).
7. Exploiter une faiblesse d'IA connue (changements en boucle, pièges de priorité).

**Mécanismes de contrebalancement :** plafond de niveau lié aux badges ; équipes boss conçues avec couverture et plans B ; flags IA choisis par personnage (cohérents avec la fiction) ; limitation du nombre de gimmicks actifs et introduction séquencée (un seul gimmick central, cf. §7) ; contraintes de combat contextuelles (doubles, météo imposée, terrain) pour casser la routine ; récompenses liées à la difficulté ; tables de rencontres qui offrent des réponses aux défis à venir (le jeu fournit les clés à qui observe).

**Signification transmise :** *comprendre plutôt que dominer.* Le monde récompense celui qui observe, prépare et s'adapte ; la force brute (niveau, spam, gimmick) plafonne. Ce sens doit être compatible avec — idéalement porté par — le propos de l'histoire retenue (critère §9, « exploitation ludique »).

**Ce qu'il reste à apprendre après la première solution :** à chaque acte, une couche de lecture supplémentaire (§7) ; à la fin, la combinaison sous contrainte contre une IA qui s'adapte ; après la fin, des défis optionnels qui retirent une ressource (objets, niveaux, gimmick) pour forcer de nouvelles solutions.

---

## 7. L'arc d'apprentissage de la maîtrise du combat

Huit couches de lecture, alignées grossièrement sur les huit épreuves majeures (le nombre exact et l'ordre dépendront de la structure narrative retenue). Chaque couche suit la séquence d'enseignement en 6 temps (GM_METHOD §4.9) : **les dresseurs de route enseignent, le combat majeur vérifie.** Une seule nouveauté majeure par segment.

| Phase | Couche apprise | Introduction sûre | Combat qui l'exige | Ce que le joueur ne peut plus faire ensuite |
|---|---|---|---|---|
| 1 | **Types et PV** : efficacité, gérer les PV, changer quand on perd | dresseurs débutants mono-type | 1re épreuve : mono-type lisible mais avec une surprise de couverture | gagner sans jamais changer de Pokémon |
| 2 | **Statut et tempo** : poison, paralysie, sommeil ; qui agit en premier | dresseurs qui empoisonnent/paralysent | épreuve où le statut use l'équipe plus que les dégâts | ignorer le statut |
| 3 | **Modifs de stats et menace** : boosts, baisses, « reconnaître le Pokémon qui va tout balayer » | dresseurs qui boostent | boss avec un sweeper à neutraliser à temps | laisser un adversaire se booster |
| 4 | **Talents et objets tenus** : le type ne dit pas tout | dresseurs dont le talent annule une faiblesse | boss qui retourne la table des types | se fier au seul tableau des types |
| 5 | **Synergie d'équipe et changements préventifs** | dresseurs à paires complémentaires ; premiers combats doubles | boss qui punit l'équipe déséquilibrée / combat double | penser « mon meilleur Pokémon » au lieu de « mon équipe » |
| 6 | **Champ de bataille** : météo, terrains, pièges d'entrée | zone où la météo change les rencontres | boss qui impose une condition de champ | ignorer l'environnement du combat |
| 7 | **Le gimmick central** (un seul, à choisir) : quand l'activer, quand le garder | démonstration par un PNJ, puis usage libre | boss qui l'utilise aussi, au pire moment pour le joueur | l'activer réflexivement au tour 1 |
| 8 | **Adaptation à une IA qui s'adapte** | rival / antagoniste qui ajustent leur équipe | combats finaux : combinaison de tout sous plafond | gagner avec un plan unique non révisé |

**Choix du gimmick (décision différée, critère fixé) :** le moteur offre Méga, Z, Dynamax et Tera. Le filtre de complexité interdit de les empiler sans gain d'apprentissage. Règle provisoire : **un gimmick central** qui reçoit une vraie séquence d'enseignement et dont la **fiction est liée à l'histoire** ; un second éventuel seulement en post-game ou en défi optionnel. Le choix sera fait avec la direction narrative (§9, critère « exploitation ludique ») et la faisabilité.

**Vérification du détecteur de maîtrise par phase :** pour chaque phase, la fiche combat majeur (GM_METHOD §5.4) indique la stratégie dominante prévisible issue de la phase précédente et la façon dont la nouvelle couche la rend insuffisante **sans la rendre inutile** (la leçon précédente reste vraie, elle n'est plus suffisante).

---

## 8. Les boucles cœur et « l'envie de continuer »

### 8.1 Quatre boucles imbriquées
| Échelle | Boucle | Décision | Retour |
|---|---|---|---|
| **Tour** (secondes) | lire l'état → choisir action → résolution → retour | attaque/changement/objet/gimmick | dégâts, messages d'efficacité, K.O., réaction de l'IA |
| **Route / donjon** (10-40 min) | explorer → rencontrer → capturer/combattre → gérer les ressources → atteindre un Centre ou une sortie | pousser ou rentrer ; capturer ou non ; chemin long sûr ou court risqué | ressources restantes, nouvelles options d'équipe, serrures repérées |
| **Chapitre** (1-3 h) | voir une serrure → s'informer → préparer l'équipe → épreuve majeure → clé → nouvel espace + révélation | composition, objets, ordre des zones (si ouvert) | badge, plafond relevé, accès, morceau de vérité |
| **Récit** (jeu entier) | indice → hypothèse → vérification → révélation → nouvelle question | ce que le joueur croit et va chercher | confirmation ou surprise juste |

Pré-requis systémiques de chaque boucle : une décision précède l'action ; un retour lisible la suit ; la boucle supérieure donne un sens à l'inférieure (on gère une route *parce que* l'épreuve approche ; on prépare l'épreuve *parce qu'*on veut la clé ; on veut la clé *parce que* la question narrative est derrière).

### 8.2 « Un Pokémon qui donne envie de continuer », systémiquement
L'envie de continuer n'est pas une émotion qu'on scénarise ; c'est un **état du système** au moment où le joueur pourrait poser la console. On le conçoit ainsi :

1. **Toujours au moins une intention ouverte proche** : une serrure vue récemment, un Pokémon presque évolué, un plafond sur le point d'être relevé, une capture envisagée. (Serrures vues avant clés, à distance courte.)
2. **Des pistes de progression décalées** : badges, équipe (évolutions, nouvelles captures), mystère, zones optionnelles avancent à des rythmes différents et ne se ferment **jamais toutes en même temps**. Quand l'une se ferme, une autre est à mi-chemin. (Cycles lents désynchronisés.)
3. **Chaque fermeture ouvre** : chaque révélation pose une nouvelle question ; chaque badge ouvre un espace où l'on voit déjà la serrure suivante.
4. **Le prochain apprentissage est visible** : le joueur entrevoit un défi qu'il ne sait pas encore résoudre (un dresseur trop fort sur une route latérale, un Pokémon qu'il ne peut pas encore capturer) — la promesse d'une compétence à venir.
5. **La fin de session naturelle est un point de repos, pas un mur** : Centres et sauvegardes après une fermeture *et* une ouverture, jamais au milieu d'un pic frustrant.

Indicateur de test : à n'importe quel point de sauvegarde de la tranche verticale, un observateur doit pouvoir lister **au moins deux raisons concrètes** de continuer (une systémique, une narrative).

---

## 9. Critères d'évaluation des directions narratives (étape 2)

L'histoire n'est **pas** choisie ici. Voici la grille qui servira à comparer les candidates. Elle traduit les critères du brief en questions de design vérifiables.

### 9.1 Portes éliminatoires (une seule réponse « non » = candidate écartée ou à réviser)
- **E1 — Faisabilité GBA / moteur :** tout ce que l'histoire exige est réalisable avec le moteur (scripts, flags, combats, cartes) sans dépendre d'une technologie non confirmée.
- **E2 — Adéquation aux assets :** l'histoire se joue **principalement sur des cartes existantes** (Hoenn, éventuellement Kanto) re-habillées ; ≤ quelques nouvelles cartes, justifiées. Personnages incarnables par des sprites dresseurs/PNJ existants (ou un très petit nombre de nouveaux).
- **E3 — Intouchables respectés :** aucune nouvelle espèce, aucune modification d'espèce, de sprite de Pokémon, de données ou d'animation d'attaque.
- **E4 — Compatibilité avec l'intention :** l'histoire n'exige pas de retirer au joueur ses décisions de combat/équipe (pas de « tu perds forcément », pas de longues séquences sans contrôle).
- **E5 — Langue :** écrivable en français dans les limites de texte GBA (pas de dépendance à des pavés d'exposition).

### 9.2 Grille pondérée (note 0-5 par critère, total sur 100)

| # | Critère (brief) | Poids | Question de design | Ancre 1 (faible) | Ancre 5 (fort) |
|---|---|---|---|---|---|
| C1 | **Originalité** | 10 | Propose-t-elle une prémisse ou une structure qu'un joueur de Pokémon n'a pas déjà vue ? | « équipe maléfique veut un légendaire » sans variation | prémisse neuve **et** qui change la façon de jouer |
| C2 | **Potentiel de mystère** | 12 | Y a-t-il une question centrale qui tient tout le jeu, avec des indices observables dans le monde ? | mystère résolu par un PNJ qui explique | questions emboîtées, indices dans les lieux/rencontres/équipes, relecture possible |
| C3 | **Force émotionnelle** | 10 | Les moments forts sont-ils vécus par le joueur (décisions, conséquences) plutôt que regardés ? | émotion uniquement en cinématique | émotion produite par une situation de jeu (perte, choix, retrouvailles mécaniques) |
| C4 | **Profondeur de l'antagoniste** | 10 | Son projet est-il compréhensible, voire défendable ; a-t-il une **signature mécanique** ? | méchant par fonction | motivation cohérente, évolution, trace dans les règles (rencontres, accès, équipes, objets) |
| C5 | **Cohérence du worldbuilding** | 8 | Le monde a-t-il une logique interne stable (lieux, factions, histoire) ? | décor interchangeable | chaque lieu a une raison d'être et une place dans le récit |
| C6 | **Usage intelligent du lore Pokémon** | 10 | Exploite-t-elle mythes, espèces, mécaniques canoniques avec justesse, sans contradiction gratuite ? | name-dropping de légendaires | le lore existant devient indice, serrure ou propos ; écarts assumés |
| C7 | **Adéquation moteur / assets** | 10 | Au-delà de la porte E1-E2 : la direction **tire parti** de ce qui existe (cartes Hoenn, Frontier, jour/nuit, gimmicks, IA, éventuellement FRLG) ? | se bat contre les assets | les cartes existantes deviennent des lieux signifiants ; le gimmick a une raison fictionnelle |
| C8 | **Exploitation ludique de l'histoire** | 14 | L'histoire génère-t-elle des serrures-clés, des missions, des contraintes de combat et un sens mécanique (« comprendre plutôt que dominer ») ? | histoire plaquée entre des arènes | l'intrigue *est* la progression : elle change les rencontres, les accès, les équipes adverses, la façon de jouer |
| C9 | **Rythme des révélations** | 10 | Les révélations se répartissent-elles sur tout le jeu, chacune préparée par des indices et ouvrant une nouvelle question ? | tout au début ou tout à la fin | ≥ 1 révélation par acte, indices plantés ≥ 1 chapitre avant, chaque réponse ouvre une question |
| C10 | **Faisabilité GBA (coût réel)** | 6 | Au-delà de la porte E1 : volume de script, de texte, de cartes et de risques techniques raisonnable pour notre environnement sans éditeur graphique ? | nombreuses cartes neuves, scripts complexes | réutilisation massive, scripts simples, risques identifiés et bornés |

Score = Σ (note × poids) / 5. Seuil de candidature retenue : **≥ 70/100 et aucune note < 2** sur C2, C4, C8, C9.

### 9.3 Dossier exigé pour chaque direction candidate
1. Pitch (5 lignes) et **thème** en une phrase.
2. **Phrase de signification mécanique** : ce que les règles du jeu affirmeront de ce monde (GM_METHOD §4.11).
3. Question centrale du mystère + 3 révélations majeures, chacune avec ses indices (où, quand) et la nouvelle question qu'elle ouvre.
4. Antagoniste : motivation, évolution, **signature mécanique**.
5. Carte des serrures-clés narratives (≥ 6) avec leur lien aux mécaniques cœur.
6. Usage des cartes existantes (liste des lieux réutilisés et leur rôle) + nouvelles cartes éventuelles justifiées.
7. Gimmick central proposé et sa justification fictionnelle.
8. Comment l'histoire sert l'arc de maîtrise (§7) et les comportements cibles (§4).
9. Risques (narratifs, techniques, de rythme) et ce qui serait coupé en cas de dépassement.
10. Auto-évaluation sur la grille §9.2, à contre-vérifier par les critiques indépendants.

### 9.4 Tests transversaux appliqués à toute direction
- **Test de la question avant la réponse :** chaque révélation est-elle précédée d'une question que le joueur se pose déjà ?
- **Test sans texte :** si l'on retire 50 % des dialogues, le joueur comprend-il encore les enjeux par les lieux, les rencontres, les équipes adverses ?
- **Test d'ironie :** les mécaniques contredisent-elles le propos sans le vouloir (ex. une histoire sur le respect des Pokémon où l'on capture sans limite et où le grind est la solution) ?
- **Test du joueur qui saute l'histoire :** le jeu reste-t-il bon s'il fait défiler les textes ? Et le joueur qui lit tout est-il récompensé (indices utiles en combat/exploration) ?

---

## 10. Hypothèses ouvertes et dépendances

| ID | Hypothèse | Dépend de | Décision attendue |
|---|---|---|---|
| H1 | Plafond de niveau lié aux badges (souple ou dur selon mode) | `TECHNICAL_AUDIT.md`, prototype | préproduction mécaniques |
| H2 | Choix de mode en début de partie (2 niveaux) | faisabilité + lisibilité UX | préproduction mécaniques |
| H3 | Un seul gimmick central, choisi selon la direction narrative | étape 2 + `FEATURE_INVENTORY.md` | après choix de direction |
| H4 | Jour/nuit comme slow cycle (rencontres, PNJ, événements) | `FEATURE_INVENTORY.md` | préproduction rencontres |
| H5 | Rival à adaptation d'équipe (arms race asymétrique) | scripts de combat conditionnels | préproduction dresseurs |
| H6 | DexNav / suiveurs comme outils d'information (activables, désactivés par défaut) | audit + intention « lire le monde » | préproduction QoL |
| H7 | Cartes FRLG disponibles en complément de Hoenn | `ASSET_INVENTORY.md` | étape 2 (critère C7) |

Toute hypothèse reste marquée `HYPOTHÈSE` dans la bible jusqu'à franchissement de la porte prototype (GM_METHOD §4.12).
