# STORYCRAFT_RESEARCH — Techniques d'écriture pour *Pokémon Cendres*

> **Rôle :** recherche en narrative design pour le Game Mechanics Director. **Public :** scénaristes, scripteurs (`.inc` / Poryscript), level designers.
> **Ce document n'est pas académique.** Chaque section finit par des règles applicables. La §8 donne 25 techniques traduites en outils GBA (msgbox, flags, vars, PNJ, dresseurs, objets, décor).
> **Méthode et sources :** aucune recherche web n'a été faite (budget Claude Pro). Le contenu vient de l'analyse des œuvres citées et de textes de référence bien connus du métier, cités de mémoire : J. Truby, *The Anatomy of Story* (2007) ; R. McKee, *Story* (1997) ; B. Snyder, *Save the Cat!* (2005) ; B. Sanderson, cours d'écriture BYU (promesses / progression / résolution, lois de la magie) ; J.J. Abrams, conférence TED « The Mystery Box » (2007) ; Hitchcock sur la bombe sous la table (entretiens avec Truffaut, 1966) ; S. Kabo Ashwell, « Standard Patterns in Choice-Based Games » (blog *Heterogenous Tasks*, 2015) ; E. Short, « Beyond Branching: Quality-Based, Salience-Based, and Waypoint Narrative Structures » (emshort.blog, 2016) ; J. Ingold (inkle), GDC 2017 « Narrative Sorcery » ; analyses de Game Maker's Toolkit (M. Brown). Les détails d'intrigue des œuvres sont de connaissance générale ; à revérifier avant toute citation publique.
> **Rapport à la bible :** les exemples s'appuient sur *Cendres* (`NARRATIVE_DIRECTIONS.md`, `CHARACTER_AND_LORE.md`, `DECISION_LEDGER*.md`) : réfugiés de Cramois'Île, Projet Soupape, Arche, Opération Braise, Groudon. Ils restent valables si le cadre change.

---

## 0. Les cinq idées à retenir

1. **Un mystère est une économie.** On gère ce que le joueur sait, croit et soupçonne. Chaque révélation doit coûter quelque chose (un effort, un choix, un combat) et rapporter plus qu'elle ne coûte.
2. **Chaque personnage veut quelque chose sans Red.** Si un PNJ n'a pas de projet qui avancerait sans le joueur, c'est un figurant.
3. **Un choix compte quand le jeu s'en souvient de façon visible**, pas quand il ouvre une branche. La mémoire coûte peu (un flag, une ligne). Une branche coûte cher (une carte, une scène).
4. **L'antagoniste a raison sur le problème.** Le désaccord porte sur la solution, le prix, et qui le paie.
5. **Le légendaire répond à ce que les humains ont fait.** Il ne vient jamais sauver la mise ; il juge, il réagit, il amplifie.

---

## 1. Architecture du mystère en couches

### 1.1 L'oignon : surface / milieu / noyau

Les grandes œuvres de mystère superposent trois vérités. Chacune explique la précédente et la rend insuffisante.

| Œuvre | Surface (crise visible) | Milieu (cause apparente) | Noyau (vraie cause) |
|---|---|---|---|
| *Chinatown* | Une affaire d'adultère | Un détournement d'eau pour spéculer | L'inceste et l'impunité des puissants (« Forget it, Jake ») |
| *Twin Peaks* (S1-2) | Le meurtre de Laura Palmer | Drogue, prostitution, double vie de la ville | Bob / Leland : le mal est dans la famille et dans la Loge |
| *Dark* | Un enfant disparaît | Des voyages dans le temps via la grotte | Une boucle causale entretenue par deux camps et un monde-origine |
| *Mass Effect* | Saren attaque | Les Geth, puis un vaisseau ancien | Les Moissonneurs, cycle d'extinction de 50 000 ans ; la Citadelle est leur piège |
| *Outer Wilds* | Le soleil explose, tu revis 22 minutes | Les Nomaï cherchaient l'Œil de l'univers | Leur projet a causé la boucle ; la supernova est naturelle, l'univers meurt de vieillesse |
| *Majora's Mask* | La lune va tomber | Skull Kid l'y pousse | Le masque possède Skull Kid ; le cœur du jeu est le deuil (les quatre géants, les amis perdus) |
| *Bloodborne* | Une chasse nocturne à la bête | Le Sang Ancien guérit et transforme | L'Église a bu le sang des Grands Anciens ; la « peste » est le prix de la connaissance |
| *Pokémon N/B* | La Team Plasma veut libérer les Pokémon | N croit sincèrement à ce combat | Ghetsis manipule N pour être le seul à garder des Pokémon |
| *Légendes Arceus* | Les seigneurs deviennent frénétiques | La faille dans le ciel | Volo veut recréer le monde ; Arceus teste le joueur |
| *Metal Gear Solid* | Des terroristes prennent une base | Liquid veut Metal Gear et les restes de Big Boss | Snake est l'arme (FoxDie) ; le gouvernement l'a envoyé pour tuer |

**La règle :** la surface se résout dans l'acte I, le milieu dans l'acte II, le noyau dans l'acte III (ou dans une fin cachée). **Chaque couche doit mener à une action en jeu**, pas seulement à une scène qui l'explique.

**Pour *Cendres* (exemple à valider par le GMD) :**
- *Surface* : des Pokémon de toutes générations apparaissent près des camps ; des vols ; le volcan gronde.
- *Milieu* : Rocket vole et relâche ; Devon cache des données ; le forage d'essai perturbe la faune.
- *Noyau* : l'Arche n'est pas une quarantaine, c'est une monnaie d'échange (Devon/Ligue) ; le phénomène est **la conséquence cumulée de décisions humaines** (accueil négocié contre main-d'œuvre, forage, relâchers), et Groudon réagit à ce que Hoenn devient. Personne n'est le grand coupable unique.

### 1.2 L'économie de l'information

Trois quantités à suivre dans un tableur (une ligne par révélation) :
- **Ce que le joueur sait** (vérifié en jeu).
- **Ce qu'il croit** (ce que le jeu lui laisse supposer, y compris à tort).
- **Ce qu'il soupçonne** (indices plantés mais pas reliés).

*Return of the Obra Dinn* est le modèle : le jeu donne des outils (montre, carnet), les faits arrivent en fragments, et le joueur **déduit** ; le jeu ne valide les déductions que par paquets de trois, ce qui empêche le hasard. *Pentiment* va plus loin : l'enquête ne sera **jamais** résolue officiellement ; le joueur accuse sans certitude et vit avec.

**Règles :**
- Une révélation majeure tous les 2-3 h de jeu. Entre deux, des micro-révélations (un nom, un lieu, une contradiction).
- Ne jamais révéler deux couches dans la même scène. Laisser le joueur digérer.
- Le joueur doit toujours avoir **une question active** (« qui a ouvert la cage ? ») et **une hypothèse** (« Rocket ? »). Si les deux manquent, il décroche.
- **Suspense > surprise** (Hitchcock) : souvent, mieux vaut que le joueur sache que la bombe est là et que les personnages l'ignorent. Exemple : le joueur voit Lambda parler à un sbire au port, Devon continue de lui faire confiance.

### 1.3 Indices honnêtes et fausses pistes

- **Règle des trois indices** (variante de la « Three Clue Rule » des meneurs de JdR, J. Alexander) : chaque conclusion obligatoire doit être accessible par au moins trois indices, dont un impossible à rater.
- **Indice honnête** = vrai, visible, interprétable autrement au premier regard. Dans *Zero Escape: 999*, la narration à la troisième personne et le « Ennéa » cachent le twist sans jamais mentir ; à la relecture, tout était là.
- **Fausse piste honnête** = elle doit être *vraie à un autre niveau*. Rocket n'est pas la cause du phénomène, mais Rocket est vraiment coupable de quelque chose. Une fausse piste qui ne mène nulle part est une trahison ; une fausse piste qui mène à un autre secret est un cadeau.
- **Indices par le système, pas seulement par le texte** : une espèce qui n'apparaît que sur un itinéraire de camion (table de rencontres), une baie étrangère dans un nid, un dresseur avec un Pokémon de Galar qui dit l'avoir « trouvé à Vermilava ».

### 1.4 Le retournement du milieu (midpoint reversal)

Vers 50 % du récit, une révélation change **la nature du but** (Snyder, McKee). Le héros passe de la réaction à l'action, ou découvre qu'il servait le mauvais camp.
- *Mass Effect* : Sovereign révèle sur Virmire que Saren n'est qu'un instrument.
- *Xenoblade Chronicles* : on découvre que les Mechon ont des pilotes humains (Fiora), puis que Bionis lui-même n'est pas bienveillant. Ennemi et allié s'inversent.
- *NieR: Automata* : la route B montre les machines comme des êtres qui imitent la culture humaine ; la route C révèle que l'humanité est morte et que YoRHa ment.
- *N/B* : la Ligue envahie par N et le château qui surgit du sol.

**Pour un jeu Pokémon** : le midpoint tombe naturellement autour du badge 4-5. Il doit transformer la question « qui vole les Pokémon ? » en « à quoi sert vraiment l'Arche ? ». Le joueur doit **rejouer mentalement** les scènes précédentes.

### 1.5 Twists qui recontextualisent

Un bon twist ne surprend pas seulement : il **change le sens de ce qu'on a déjà vu**. Test : après le twist, au moins trois scènes antérieures prennent un nouveau sens.
- *Bioshock* : « Would you kindly » transforme chaque ordre reçu en contrôle mental, y compris les ordres que le joueur a suivis volontairement. Le twist parle du médium.
- *Metal Gear Solid 2* : le Colonel n'existe pas ; tout le jeu était une simulation sur le contrôle de l'information.
- *Outer Wilds* : la boucle n'est pas l'ennemi, c'est l'outil.
- *Légendes Arceus* : Volo, marchand amical et serviable, présent partout dès le début. Son omniprésence était l'indice.

**Erreur fréquente** : le twist qui annule (« tout était un rêve »). Un twist doit *ajouter* une couche, pas en retirer une.

### 1.6 Planter / récolter : le registre

Tenir un **registre des promesses** (inspiré de Sanderson : chaque promesse faite au lecteur doit être tenue ou consciemment détournée).

| ID | Plant (où, quand) | Forme | Rappel(s) | Récolte | Flag lié |
|---|---|---|---|---|---|
| P07 | Ch. 2, Poivressel : Lambda refuse de serrer la main d'un pêcheur | Animation + 1 ligne | Ch. 5 : il porte des gants au labo | Ch. 10 : démasqué, cicatrice de brûlure (Cramois'Île) | `FLAG_SAW_LAMBDA_GLOVES` |

Règle : **un plant = au moins un rappel avant la récolte**, sinon le joueur l'a oublié. Et tout objet nommé (Orbe, carnet, clé) doit servir.

### 1.7 Les boîtes à mystère qui paient (et l'inflation)

La « mystery box » d'Abrams a deux faces : *Lost* ouvrait des boîtes plus vite qu'il ne les refermait ; *Dark* et *Outer Wilds* ont tenu parce que leurs auteurs connaissaient la fin dès le début.

**Inflation du mystère** = chaque réponse ouvre deux questions. C'est grisant 10 heures, épuisant 30. Antidotes :
- **Règle du « 1 ouverte, 1 fermée »** : à chaque chapitre, on ferme au moins une question ouverte avant d'en ouvrir une nouvelle.
- **Pas plus de trois questions majeures ouvertes à la fois.**
- **La réponse doit être plus intéressante que la question.** Si la réponse est « c'était une machine », la question ne valait pas 20 heures.
- **Écrire la fin d'abord.** Le noyau, la réponse à chaque question, et quand elle tombe.

---

## 2. Distributions chorales où personne n'est un figurant

### 2.1 Envie et besoin

Truby : chaque personnage a un **désir** (ce qu'il poursuit, conscient) et un **besoin** (ce qui lui manque, souvent inconscient). L'arc = le chemin du désir vers le besoin, ou l'échec à le faire.

| Personnage | Désir | Besoin | Faiblesse qui crée le conflit |
|---|---|---|---|
| Blue | Retrouver un sens après avoir perdu le titre | Accepter qu'on peut valoir sans être le meilleur | Il provoque Red pour se prouver quelque chose |
| Auguste | Un toit et du travail pour ses gens | Admettre qu'il ne peut pas tout porter seul | Il accepte des risques inacceptables (le forage) |
| Max | Empêcher un second Cramois'Île | Écouter ceux qui paient le prix | Il croit que la science justifie l'urgence |
| Brice | Prouver à son père qu'il est utile | Avoir son propre avis | Il suit Red ou Seko au lieu de choisir |

### 2.2 Des agendas personnels, égoïstes ou non

- ***The Wire*** : chaque institution (police, port, mairie, école) a sa logique, et chaque personnage sert sa carrière ou sa survie autant que sa cause. Aucun personnage n'est là *pour* McNulty.
- ***Le Trône de fer*** : chaque chapitre est du point de vue d'un personnage qui pense être le héros. Même Cersei a des raisons cohérentes (ses enfants).
- ***Yakuza*** : les sous-histoires montrent les gens ordinaires de Kamurocho avec leurs petits drames ; Kiryu est le témoin. Le ton passe du burlesque au tragique sans honte.

**Test du figurant :** si on retirait Red du jeu, que ferait ce PNJ demain ? S'il n'y a pas de réponse, il faut lui en donner une.

### 2.3 Relations entre PNJ (pas seulement avec le joueur)

*Mass Effect 2* l'a montré avec les disputes Jack/Miranda et Tali/Legion : le joueur arbitre un conflit **qui existe sans lui**. *Dragon Age: Origins* fait réagir les compagnons entre eux (dialogues de groupe en marchant). *Baldur's Gate 3* : les compagnons se jugent les uns les autres et parfois partent ensemble. *Fire Emblem* : les supports entre unités forment un réseau, pas une étoile autour de l'avatar. *Suikoden II* : l'amitié Riou/Jowy, devenue guerre, est le centre du jeu, et les 108 étoiles ont des liens entre elles (familles, rivalités, ex-ennemis).

**Règles :**
- Dessiner le **graphe** : chaque personnage majeur a au moins **une alliance** et **une rivalité** avec un autre PNJ.
- Écrire au moins une scène **où Red n'est que témoin** (il arrive pendant la dispute).
- Le joueur influence les relations entre PNJ (ex. D081 : alliance Arthur/Auguste).

### 2.4 La scène qui définit

Chaque personnage majeur a droit à **une scène où on voit qui il est**, de préférence en action et pas en exposition.
- *Final Fantasy VI* : l'opéra de Celes, le dernier train de Cyan, le suicide évité de Celes sur l'île. FFVI n'a pas de protagoniste fixe : chaque personnage a son chapitre (scénarios divisés en deuxième partie).
- *Persona* : chaque social link a un point de crise (rang 5-7) où le personnage montre sa faiblesse.
- *Three Houses* : les supports de rang A révèlent le traumatisme ou le rêve de chacun.

**Format économique (pas de gonflement)** : une scène = 1 carte existante, 2 PNJ, 8-15 msgbox, une action du joueur (un choix, un combat, un objet donné). Pas plus.

### 2.5 Une pulsation par personnage, sans gonfler

Schéma simple : **présentation → épreuve → bascule → écho**.
- Présentation (acte I) : on voit son désir.
- Épreuve (acte II) : son désir entre en conflit avec celui d'un autre.
- Bascule (acte II-III) : il choisit (selon le joueur ou non).
- Écho (fin/épilogue) : on voit le résultat.

Quatre scènes par personnage majeur, pour ~12 personnages majeurs = ~48 scènes. C'est réaliste. Les personnages secondaires ont 2 scènes (présentation + écho).

### 2.6 Rappels

Une phrase, un objet, un geste qui revient. *Persona 4* : le « Everyday's great at your Junes » devient affectueux. *Mass Effect 2 → 3* : les morts de la mission suicide sont absents, et le jeu le dit. Dans un jeu Pokémon : le dresseur de la Route 104 qui reparaît au postgame et parle de ce qu'il a vu.

### 2.7 Les crossovers : justifier la rencontre des icônes

| Œuvre | Justification | Ce qui marche | Ce qui échoue |
|---|---|---|---|
| *Kingdom Hearts* | Les mondes sont séparés ; les Sans-cœur brisent les murs | Chaque monde Disney est une boucle courte cohérente | Les persos Disney ne changent pas ; mythologie maison devenue illisible |
| *Smash Bros.* | Jouets animés (Melee), puis Tabuu / Galeem (Subspace, Ultimate) | Subspace : les persos ont des rencontres qui jouent sur leurs traits (Ike et Marth) | Aucun arc ; prétexte assumé |
| *Dissidia* | Un dieu convoque des guerriers pour une guerre cyclique | Les héros et méchants de chaque FF se parlent selon leur caractère | Amnésie générique ; dialogues abstraits |
| *Pokémon Masters* | Île artificielle de tournois (Pasio) | Paires dresseur/Pokémon iconiques ; contexte léger et logique | Pas d'enjeux ; tout le monde est gentil ; personnages réduits à une phrase-clé |
| *Avengers* (MCU) | Une menace trop grande pour un seul héros ; une organisation (SHIELD) les réunit | Les héros **ne sont pas d'accord** (Stark/Rogers) ; chacun garde son arc | Plus tard : surabondance de caméos sans enjeu |

**Leçon pour *Cendres*** : la justification « réfugiés de Cramois'Île + Océane » est **meilleure** que les prétextes ci-dessus parce qu'elle est **la crise elle-même**. Kanto rencontre Hoenn *parce que* c'est le sujet. Garder deux règles :
1. **Chaque personnage de Kanto doit avoir une raison concrète d'être là** (Auguste : ses habitants ; Blue : il fuit ; Agatha : le rite pour les morts ; Ariane : l'Arche). Pas de caméo gratuit.
2. **Les icônes doivent être en désaccord** entre elles et avec les gens de Hoenn. Une rencontre où tout le monde se respecte n'est qu'une photo.

---

## 3. Choix et conséquences

### 3.1 Ce que font bien (ou mal) les références

| Œuvre | Technique | Leçon |
|---|---|---|
| *The Witcher 2* | Acte II entièrement différent selon Roche ou Iorveth | Une grosse branche bien placée vaut mieux que dix petites. Coûteux : une seule fois |
| *The Witcher 3* | Conséquences différées (le Baron, Ciri) ; quêtes « sans bonne réponse » | Montrer le prix des heures plus tard ; le choix de Ciri dépend de petits gestes cumulés (bataille de boules de neige, laisser Ciri casser le labo) |
| *Mass Effect* | Parangon/Pégase | Deux jauges qui récompensent la constance poussent à « jouer une couleur » ; le joueur ne choisit plus, il optimise. À éviter tel quel |
| *Telltale* (TWD S1) | « Clementine s'en souviendra » | Le signal de mémoire crée l'émotion, même quand les branches reconvergent. La critique d'« illusion du choix » vient quand le joueur *voit* que rien ne change. L'émotion compte, mais il faut quelques vraies divergences |
| *Disco Elysium* | Compétences qui parlent, Cabinet de pensées | Les choix expriment **qui est le personnage**, pas seulement ce qui arrive. Les échecs sont intéressants |
| *Fallout: New Vegas* | Réputation par faction, à deux axes (estime/infamie) | On peut être aimé et craint ; les factions ont des intérêts opposés, on ne peut pas plaire à tous |
| *Undertale* | Moralité systémique (tuer / épargner dans le combat) | Le système de jeu lui-même est le choix ; le jeu se souvient même après un reset |
| *Baldur's Gate 3* | Approbation par compagnon, états cachés énormes | La réactivité fine (un compagnon commente un détail) donne l'impression d'un monde vivant. Très coûteux ; retenir le principe, pas le volume |
| *Fire Emblem* | Supports | Relations construites par la répétition de petits gestes (combattre côte à côte) |
| *Persona* | Liens sociaux + calendrier | Le temps limité force des choix de présence : on ne peut pas tout voir |
| *Pentiment* | Choix sur la vérité | Accuser sans preuve, vivre avec ; le jeu ne dit jamais qui était coupable |
| *Frostpunk*, *This War of Mine* | Pression morale par la survie | Les choix moraux sont meilleurs quand ils sont **forcés par une ressource** (nourriture, chaleur, temps) |

### 3.2 Les structures à connaître (Ashwell, Short)

- **Branch-and-bottleneck** (*Ashwell*) : le récit se divise, puis reconverge sur des goulots (jalons obligatoires). Entre deux goulots, les choix modifient l'**état**, et l'état colore les goulots. C'est la structure naturelle d'un jeu Pokémon (badges = goulots).
- **Quality-based narrative** (*Short*, *Fallen London*) : les scènes se débloquent selon des valeurs (qualités) et pas selon un arbre. Idéal pour 110 décisions : chaque décision modifie une ou deux vars, et des scènes testent des seuils.
- **Salience-based** (*Short*, *Firewatch*, *Left 4 Dead* via Valve) : le système choisit la réplique **la plus spécifique** disponible selon l'état. Ex. : si `FLAG_TEO_ROCKET` et `VAR_AFF_BRICE ≥ 60`, réplique A ; sinon si `FLAG_TEO_ROCKET`, réplique B ; sinon réplique par défaut.
- **Waypoint / Ingold (*Sorcery!*, *80 Days*)** : beaucoup de petits choix qui s'accumulent en « faits » de monde, testés plus tard. inkle insiste : **le joueur doit voir le jeu se souvenir**.

### 3.3 Règles pratiques pour 110+ décisions avec une petite production

1. **Typologie fixe.** Chaque décision a un type : *arbitrage* (A contre B), *présence* (où être), *don* (objet, Pokémon, info), *aveu* (dire ou taire), *combat* (affronter, épargner, refuser), *discret* (geste non annoncé). Varier les types évite la lassitude.
2. **Le coût est fixé à l'avance.** Classes de coût : **S** = 1 ligne de réaction (70 % des décisions), **M** = un PNJ change de place ou de dialogue + un rappel plus tard (25 %), **L** = scène ou carte qui change (5 %, soit ~5-6 décisions). Le registre `DECISION_LEDGER` doit porter cette colonne.
3. **Accumuler, ne pas brancher.** La plupart des décisions incrémentent une variable (affinité, réputation, état du monde). Les fins testent des seuils. 110 décisions × 2 vars chacune = un espace d'états riche avec peu de contenu.
4. **Dialogues réactifs.** Pour chaque PNJ majeur, prévoir un « tableau de saillance » : 3-5 répliques selon l'état, la plus spécifique gagne. C'est la meilleure dépense par octet.
5. **Le moment de la conséquence.** Trois délais : **immédiat** (le PNJ réagit), **différé court** (chapitre suivant), **différé long** (acte III ou épilogue). Viser ~50/35/15 %. Une décision sans conséquence immédiate doit avoir un **signal de mémoire** (« Brice note quelque chose dans son carnet »).
6. **Signaux de mémoire, avec parcimonie.** Le « X s'en souviendra » de Telltale crée l'attente. Le réserver aux décisions de classe M et L, sinon il devient du bruit. Variante diégétique : un carnet d'enquête (objet clé) qui s'enrichit.
7. **Pas de bonne voie dominante.** Chaque option doit avoir un gain **et** une perte, dans **deux systèmes différents**. Ex. : livrer Téo à la police = +Autorités, −Réfugiés, −Lilou. Le protéger = l'inverse, et Rocket garde un guetteur. Si une option gagne partout, la supprimer.
8. **Pas de jauge morale visible.** Les jauges visibles poussent à optimiser (*Mass Effect*). Garder les systèmes **cachés** et les rendre lisibles par les réactions des gens (*New Vegas*, *Witcher 3*).
9. **Les petits gestes comptent en cumul.** Le modèle Ciri (*Witcher 3*) : la fin dépend de 5 moments discrets, non signalés. Faire de même pour une fin émotionnelle (Lilou, Brice).
10. **Le choix par l'action de jeu.** Pas tout en msgbox : capturer ou laisser un Pokémon, refuser un combat (`trainerbattle` évitable), donner un objet, aller ou non dans une zone. *Undertale* montre que le système est le meilleur porteur de sens.
11. **La pression vient d'une ressource.** Temps (le Conseil a lieu à date fixe : les quêtes non faites sont perdues), place (on ne peut sauver que 3 Pokémon de l'Arche), confiance (on ne peut pas mentir à tout le monde).
12. **Bilan explicite à la fin.** Les épilogues (*Fallout*, *Witcher 3*) disent ce que les choix ont produit. C'est le moment où le joueur comprend l'ampleur de ce qu'il a fait ; ne pas le rater.

---

## 4. Antagonistes et complexité morale

### 4.1 Le méchant a raison sur le problème

| Antagoniste | Ce qu'il voit juste | Où il a tort |
|---|---|---|
| Killmonger (*Black Panther*) | Le Wakanda a laissé souffrir les opprimés | La conquête violente reproduit l'oppression |
| Thanos (*Infinity War*) | Les ressources sont finies | Le génocide arbitraire ; il refuse toute autre solution |
| N (*N/B*) | Certains dresseurs maltraitent leurs Pokémon | Séparer tous les Pokémon des humains |
| Ghetsis | Rien de juste : c'est le **manipulateur** qui se sert de la cause de N | — (contraste voulu : le vrai méchant n'a pas de cause) |
| Lusamine (*SL*) | Les Ultra-Chimères doivent être étudiées et protégées | Obsession, abandon de ses enfants |
| Rose (*ÉB*) | Galar manquera d'énergie dans 1000 ans | Il réveille Éthernatos *maintenant* sans consentement |
| Volo (*Légendes Arceus*) | Le monde est imparfait | Il veut le détruire pour le refaire à son goût |
| Andrew Ryan (*Bioshock*) | Les États étouffent l'individu | Son utopie sans règles produit la tyrannie qu'il fuyait |
| Handsome Jack (*Borderlands 2*) | Pandora est un enfer de bandits | Il se croit le héros et massacre pour « l'ordre » |
| GLaDOS (*Portal*) | La science demande des tests | Elle a tué tout le monde ; humour froid qui rend la menace sympathique |

**Formule :** l'antagoniste a raison sur **le diagnostic**, tort sur **le traitement**, et le traitement fait payer **quelqu'un d'autre**. Le joueur doit pouvoir dire : « Je comprends, mais pas comme ça. »

**Pour *Cendres*** : Max a raison (le volcan est dangereux), Arthur a raison (le forage tue la mer), Devon a raison (il faut de l'argent et des bras), Ariane a raison sur un point (la Ligue a parqué des Pokémon d'étrangers comme des marchandises : c'est presque une injustice que Rocket « répare » en volant). C'est la bonne structure. Le danger serait d'en faire *trop* : il faut au moins une figure dont la logique est égoïste et lisible (Ariane, qui veut faire revenir Giovanni) pour que le joueur ait un adversaire clair à frapper.

### 4.2 Plusieurs antagonistes aux agendas concurrents

Modèle *Le Trône de fer* / *The Wire* : les antagonistes **se gênent entre eux**. Chacun profite des erreurs des autres.
- Rocket se sert du conflit Magma/Aqua comme couverture.
- Devon tolère Rocket sans le savoir (Lambda) et se sert des réfugiés.
- Magma et Aqua se haïssent et ne voient pas qui les monte l'un contre l'autre.

**Règle :** faire un tableau « qui gagne si X échoue ». Si deux antagonistes gagnent toujours ensemble, fusionner ou différencier.

### 4.3 Le manipulateur derrière le croyant

Le duo N/Ghetsis est le meilleur outil de Pokémon pour la maturité : **un croyant sincère et un cynique qui l'exploite**. Le joueur respecte l'un, méprise l'autre, et doit séparer les deux. *Metal Gear* le fait aussi (Liquid sincère / Ocelot double jeu). Dans *Cendres*, on peut avoir ce duo dans plusieurs camps : Max (croyant) / M. Rochard (calculateur) ; Téo (enfant utilisé) / Lambda.

### 4.4 Rédemption : réussie ou ratée

**Réussie** quand :
- elle **coûte** quelque chose au personnage (Zuko dans *Avatar* : il perd sa place, son père) ;
- elle est **préparée** par des failles visibles plus tôt (Jaime Lannister, la main coupée, puis Brienne) ;
- elle **ne lave pas tout** : les victimes n'ont pas à pardonner. *Witcher 3*, le Baron : rédemption incomplète et peut-être impossible.
- elle dépend en partie du joueur (*Mass Effect 3*, Tali/Legion ; *Suikoden II*, Jowy).

**Ratée** quand : le méchant devient gentil parce que le scénario a besoin d'un allié pour la fin ; les remords tombent en une scène ; ses crimes sont oubliés par les autres personnages. (Reproche fait à plusieurs « gentils méchants » de Pokémon : Lysandre/Lusamine ne sont jamais vraiment jugés.)

**Règle pour *Cendres*** : prévoir **deux** arcs de rédemption conditionnels (Téo, Lambda ou Kelvin) que le joueur peut ouvrir ou fermer, et **un** antagoniste qui ne change pas (Ariane). La rédemption doit laisser une trace concrète (une victime qui refuse de pardonner).

---

## 5. Mythologie et intervention légendaire

### 5.1 Éviter le deus ex machina

Le deus ex machina résout un problème que les personnages n'ont pas su résoudre. Les bonnes histoires inversent : **le dieu crée ou aggrave le problème, et les humains doivent le gérer**, ou **le dieu répond à ce que les humains ont fait**.

| Œuvre | Usage du divin | Leçon |
|---|---|---|
| *Princesse Mononoké* | Le Dieu-Cerf donne et prend la vie ; décapité, il détruit tout | Le divin est une **force de nature indifférente**, ni bon ni mauvais. Les humains en paient le prix ; la fin ne résout pas, elle permet de recommencer |
| *Shadow of the Colossus* | Dormin promet de ressusciter Mono si Wander tue 16 colosses | Le joueur sert un dieu sans le comprendre ; chaque victoire coûte (les colosses sont tristes). La quête **est** la faute |
| *Okami* | Amaterasu est un dieu affaibli qui a besoin de la foi des gens | Le dieu est le joueur ; sa force dépend de ce que les humains croient. Le divin est relationnel |
| *God of War* (2018) | Kratos dieu tente de ne pas transmettre sa violence à Atreus | Les enjeux cosmiques (Ragnarök) sont vécus comme une histoire de père et de fils |
| *Légendes Arceus* | Arceus confie une mission, la faille vient de Volo, les seigneurs sont frénétiques | Les légendaires ont des **réactions** et des **règles** ; le dieu suprême observe et teste |
| *Xenoblade Chronicles 2* | Le Créateur (Klaus) a fait un monde par culpabilité ; Pneuma (Mythra) est une arme | Le dieu est un homme brisé. Le cosmique devient intime |

### 5.2 Les règles de Sanderson appliquées aux légendaires

- **1re loi** : la capacité d'une magie à *résoudre* un problème est proportionnelle à la compréhension qu'en a le lecteur. Donc : si l'Orbe Rouge calme Groudon au climax, le joueur doit **avoir appris les règles** avant (l'Orbe calme, ne commande pas ; il faut un porteur reconnu ; il faut du temps).
- **2e loi** : les limites sont plus intéressantes que les pouvoirs. Groudon ne peut pas être capturé au climax ; l'Orbe ne marche que si quelqu'un renonce à quelque chose.
- **3e loi** : développer ce qu'on a avant d'ajouter. Groudon et Kyogre suffisent ; Rayquaza reste un horizon (postgame).

### 5.3 Le cosmique ancré dans le personnel

Le réveil de Groudon n'est grave que s'il menace **quelque chose qu'on aime** : le camp où dort Lilou, la maison de Brice, les récifs d'Arthur. Règles :
- Avant le climax, montrer la petite chose menacée (un dessin de Lilou affiché au camp, un lieu de pause).
- La réaction du légendaire dépend des **choix humains cumulés** (`VAR_ETAT_VOLCAN`). Groudon ne vient pas du ciel : il répond au forage, au rite du Mont Mémoria, à la garde de l'Orbe.
- **Le légendaire ne parle pas.** Il agit, il regarde, il part. Ses « messages » passent par le monde (séismes, sol brûlant, Pokémon qui fuient). Les PNJ l'interprètent et **se trompent** parfois.
- **La fin ne dépend pas d'un combat contre le dieu.** Un combat peut avoir lieu, mais la résolution passe par une décision (qui porte l'Orbe, arrêter ou non le forage, rester au camp ou à l'Arche).

### 5.4 Pour le phénomène « toutes générations »

Si le brief garde l'idée d'un phénomène mystérieux (espèces de Gen 1-9 dans Hoenn), il faut **une règle de cause** cohérente et découverte progressivement. Les meilleures causes sont **humaines d'abord, mythiques ensuite** : relâchers de réfugiés et trafic Rocket (cause sociale, acte I-II), puis perturbation de l'écosystème qui fait fuir les espèces locales et attire les étrangères (cause écologique, acte II), puis réaction de Groudon/Kyogre à un équilibre rompu (cause mythique, acte III). Le joueur ne doit jamais entendre « c'est la magie » ; il doit pouvoir **cartographier** le phénomène (où, quand, quelles espèces) et y voir un motif.

---

## 6. Rythme pour une aventure de 20-30 h, semi-ouverte

### 6.1 Structure d'actes

Pour 25 h, une base en 4 parties (acte II coupé en deux par le midpoint) :

| Bloc | Durée | Badges | Fonction | Révélation |
|---|---|---|---|---|
| Acte I | 5-6 h | 1-2 | Situation, personnages, première crise | Surface : des Pokémon disparaissent, Rocket est là |
| Acte IIa | 6-7 h | 3-4 | Exploration, alliances, les camps se forment | Milieu : Devon ment sur l'Arche |
| Midpoint | 1 h | — | Retournement | La question change |
| Acte IIb | 6-7 h | 5-6 | Les conséquences arrivent, les alliances se brisent | Le noyau se laisse deviner |
| Acte III | 4-5 h | 7-8 + climax | Conseil, nuit de la Braise, choix de présence | Noyau révélé |
| Épilogue / postgame | 1-3 h | — | Échos, bilan | Fin cachée possible |

### 6.2 Ouvert, mais rythmé

Les jeux semi-ouverts perdent le rythme quand le joueur peut faire les révélations dans le désordre. Solutions :
- **Révélations attachées aux goulots** (badges, Conseil), indices libres entre les goulots.
- **Contenu ouvert = personnages et monde**, pas noyau du mystère. Les quêtes annexes enrichissent les factions et les relations.
- **Escalade par état du monde** : une même ville change entre deux passages (camp plus grand, tension, barricades). Le monde avance même si le joueur traîne (*Majora's Mask*, *Persona*).

### 6.3 Morceaux de bravoure et moments de respiration

- **Set pieces** (scènes fortes) : 1 par acte au minimum. Ex. : naufrage du canot (ouverture), incendie au camp (acte I), Conseil (acte III), nuit de la Braise (climax). Les annoncer et les préparer.
- **Respiration** : après chaque set piece, une séquence calme (ville, quête légère, dialogue intime). *Persona* alterne donjon et vie quotidienne ; *FFVI* place l'opéra entre deux crises.
- **Courbe en dents de scie** : tension qui monte, baisse partielle, remonte plus haut. Jamais de plateau de 3 h.

### 6.4 L'humour dans les histoires sérieuses

- *Yakuza*, *Undertale*, *Persona*, *Majora's Mask* : l'humour **rend la tragédie supportable** et fait aimer les personnages qu'on risque de perdre.
- L'humour doit venir **des personnages** (Brice qui parle trop pour compenser le silence de Red, Blue qui fanfaronne), pas de clins d'œil au joueur.
- Règle : **une blague par scène sérieuse au maximum, jamais au moment le plus douloureux**, mais souvent juste avant (le contraste rend le coup plus fort).
- Pokémon a un atout : les Pokémon eux-mêmes. Un Psykokwak qui ne comprend rien au drame peut alléger une scène sans la casser.

### 6.5 Des fins qui portent

| Œuvre | Technique | Leçon |
|---|---|---|
| *Chrono Trigger* | 13 fins selon le moment où l'on bat Lavos | Les fins récompensent la curiosité et le replay ; certaines sont des blagues assumées |
| *NieR* / *Automata* | Fins A-E : chaque partie révèle une couche ; la fin E demande un sacrifice (sa sauvegarde) | Les fins sont des **couches du mystère**, pas des variantes |
| *Undertale* | Neutre / Pacifiste / Génocide | La fin reflète **comment** on a joué, pas un choix final |
| *Witcher 3* | Épilogue de Ciri + diaporama des régions | Les petits gestes se paient ; montrer chaque région touchée |
| *Mass Effect 3* (contre-exemple) | Trois couleurs au dernier moment | Une fin qui ignore les choix cumulés trahit le joueur |

**Règles pour *Cendres* :**
- La fin = **combinaison d'états** (volcan × réfugiés × relations), pas un choix final unique.
- **Épilogue en diaporama** : 6-10 cartes/plans (Vermilava, Poivressel, l'Arche, les récifs, Lilou, Brice, Blue...), chacun avec 2-3 variantes. Peu cher et très puissant.
- **Une fin cachée** qui révèle une couche du noyau (ex. ce que Devon savait vraiment), accessible par l'enquête la plus complète.
- **Aucune fin parfaite.** Chaque fin garde une perte. La meilleure fin doit être méritée, pas gratuite.
- Red part toujours vers le nord (E6) : cette constante est une force (on sait comment il finit ; la question est ce qu'il laisse).

---

## 7. Liste des pièges (défauts « slop »)

À relire avant chaque passe d'écriture et chaque relecture.

| # | Piège | Symptôme | Correction |
|---|---|---|---|
| 1 | **Pavé d'exposition** | Un PNJ explique l'histoire de Hoenn sur 12 boîtes | Max 4 msgbox d'exposition d'affilée ; le reste dans le décor, les objets, les livres optionnels |
| 2 | **Personnages-explicateurs** | Le PNJ n'existe que pour donner une info | Lui donner un désir et une raison de *ne pas* tout dire |
| 3 | **Tout le monde est d'accord avec le héros** | Chacun félicite Red | Au moins un personnage majeur critique chaque grande décision du joueur |
| 4 | **Twist sans préparation** | « En fait, c'était lui ! » sans indice | Registre des plants (§1.6) : 3 indices minimum |
| 5 | **Grimdark = maturité** | Morts gratuites, cruauté, cynisme généralisé | La maturité = intérêts légitimes en conflit et conséquences. Garder chaleur et humour |
| 6 | **Caméos de fan-service** | Personnage culte qui apparaît, dit sa réplique, part | Chaque perso de Kanto/Hoenn a un désir, un conflit et une scène, ou n'apparaît pas |
| 7 | **Lore trop compliqué** | Noms propres en cascade, chronologies | 1 nouveau nom propre par scène au maximum ; un glossaire implicite |
| 8 | **Moralisme** | Le jeu dit au joueur ce qu'il faut penser | Pas de narrateur qui juge ; les conséquences parlent |
| 9 | **Dialogues symétriques** | Les personnages parlent tous pareil, phrases complètes, polies | Une voix par personnage (tics, longueur de phrase, vocabulaire) ; voir `CHARACTER_AND_LORE` §6 |
| 10 | **Émotion annoncée** | « Je suis très triste. » | Montrer par un geste (il range une photo, il refuse le combat) |
| 11 | **Méchant qui explique son plan** | Monologue du boss | Le plan se découvre par l'enquête ; le boss parle de lui, pas du plan |
| 12 | **Choix sans perte** | Option évidemment gentille qui gagne partout | Règle des deux systèmes (§3.3, n° 7) |
| 13 | **Héros qui sait tout** | Red « devine » | Le joueur déduit ; Red agit |
| 14 | **Symboles martelés** | Le titre dit trois fois par scène (« cendres ») | Une image forte, rarement nommée |
| 15 | **Listes de trois et formules creuses** | « Courage, espoir et amitié » | Dire une chose précise |
| 16 | **Résolutions par discours** | Un beau speech convainc le méchant | Les gens changent par conséquences, pas par arguments |
| 17 | **Tout se règle en combat** | Le combat résout un problème politique | Le combat ouvre une porte ; la décision règle le problème |
| 18 | **Questions sans réponse empilées** | Inflation du mystère | Règle « 1 ouverte, 1 fermée » |

---

## 8. Boîte à outils : 25 techniques pour un script GBA Pokémon

Rappels d'implémentation (pokeemeraude-expansion) : `msgbox` (2 lignes ~36 caractères en FR, pages avec `\p`), `setflag/checkflag`, `setvar/addvar/compare` (`VAR_AFF_*`, `VAR_REP_*`, `VAR_ETAT_*`), drapeaux de visibilité d'objets (`FLAG_HIDE_*` dans `map.json`), `applymovement`, `trainerbattle_*`, panneaux (`bg_event`), objets cachés, descriptions d'objets (`src/data/items.h`), entrées de Pokédex, tables de rencontres (`wild_encounters.json`), PokéNav / Appel Match, TV. Enregistrer tout nouveau flag/var dans `FLAGS_VARS_REGISTRY.md`.

| # | Technique | Ce que ça apporte | Application GBA |
|---|---|---|---|
| 1 | **Tableau de saillance** | Réactivité forte à faible coût | Pour chaque PNJ majeur, script en cascade : `goto_if_set` du cas le plus spécifique au plus général ; 3-5 répliques. Ex. Brice : Téo chez Rocket + confiance haute → réplique A ; Téo chez Rocket → B ; défaut → C |
| 2 | **Le PNJ qui se déplace** | Montrer une conséquence sans scène | Deux objets pour le même PNJ, à deux endroits, contrôlés par un flag de visibilité. Ex. Auguste au chantier ou au camp selon D059 |
| 3 | **Le décor qui change** | Escalade visible | Variantes de tuiles avec `setmetatile` + `special DrawWholeMapView` au chargement (`MAP_SCRIPT_ON_LOAD`), ou objets de décor (tentes, barricades) via flags |
| 4 | **Le panneau qui se souvient** | Mémoire du monde à 1 ligne | Panneaux et affiches (`bg_event`) dont le texte dépend d'un flag : « Projet Soupape : chantier suspendu » |
| 5 | **Descriptions d'objets comme indices** | Lore non intrusif | Objets clés au texte précis (Carnet de Lambda, Badge d'employé Devon). Les infos clés sont lisibles dans le Sac. Un objet clé peut avoir 2 versions (échange d'ID) quand l'enquête avance |
| 6 | **Rencontres sauvages comme indices** | Le phénomène devient système | Tables de rencontres modifiées par état (via `VAR` + scripts de couche ou tables alternatives) : espèces étrangères sur les itinéraires des camions Rocket ; le joueur peut cartographier |
| 7 | **Entrées de Pokédex détournées** | Écologie crédible | Pour les espèces étrangères notables, une note de Brice (texte de recensement) à la place ou en plus de l'entrée Pokédex, lisible dans un PC du labo |
| 8 | **Le dresseur-témoin** | Personne n'est un figurant | Les dresseurs génériques ont un avant/après combat qui parle de la crise selon leur métier (pêcheur, randonneur, ouvrier) ; 1 ligne qui change après un jalon via `trainerbattle` + script post-défaite |
| 9 | **Le combat évitable** | Choix par l'action | `trainerbattle` déclenché seulement si le joueur accepte (`yesnobox`) ; refuser pose un flag qui compte (Blue, Arthur). Refuser un combat = décision |
| 10 | **Les équipes qui racontent** | Narration par le jeu | L'équipe d'un PNJ change selon l'état (deux IDs de dresseur) : les Pokémon de Kanto d'Auguste blessés, ou rendus par l'Arche ; une Rocket qui utilise un Pokémon volé reconnaissable |
| 11 | **Le carnet d'enquête** | Économie d'info visible | Objet clé « Carnet » dont l'utilisation lance un script qui liste les questions ouvertes selon les flags (3 max, règle §1.7). Sert aussi de signal de mémoire |
| 12 | **Signal de mémoire diégétique** | Le joueur sait que ça compte | Après une décision M/L : petit son (`playse`) + « Brice griffonne quelque chose. » Rare, pour garder sa valeur |
| 13 | **Le rappel de PNJ secondaire** | Callbacks peu coûteux | Le PNJ d'une décision de l'acte I réapparaît (flag de visibilité) en acte III ou postgame avec 2-3 lignes |
| 14 | **Appel Match / PokéNav** | Conséquences différées à distance | Messages de PNJ via l'Appel Match (rematchs, nouvelles) conditionnés par flags : Lilou raconte sa journée, Blue envoie un défi. Peu de cartes, beaucoup de réactivité |
| 15 | **Journaux télévisés et rumeurs** | Opinion publique et factions | TV des maisons et bulletins de Gabby & Ty : texte selon `VAR_REP_*`. Les PNJ de Centre Pokémon répètent les rumeurs (vraies ou fausses : fausses pistes) |
| 16 | **Lettres et documents** | Exposition optionnelle | Lettres dans les tiroirs, mails sur les PC (`bg_event` sur un PC) ; lecture facultative = décision « discrète » (lire ou non la lettre d'Auguste). L'exposition lourde vit ici, pas dans les dialogues obligatoires |
| 17 | **La scène de témoin** | Relations entre PNJ | Red arrive pendant une dispute : `applymovement` des deux PNJ, Red bloqué par `lockall`, 6-10 msgbox, choix final facultatif d'intervenir |
| 18 | **Choix de présence** | Pression et coût réel | Au climax, deux warps menant à deux scènes exclusives ; le premier franchi pose un flag qui ferme l'autre. Le joueur l'apprend avant (sauvegarde honnête) |
| 19 | **La date limite douce** | Pression de ressource | Un jalon (Conseil) ferme des quêtes : drapeaux « quête expirée » posés à l'entrée d'Atalanopolis ; un PNJ le rappelle avant. Les quêtes perdues ont un écho dans l'épilogue |
| 20 | **Fausse piste honnête dans le décor** | Mystère juste | Un indice matériel (empreinte, débris, objet caché `hidden_item`) attribuable à deux coupables ; un second indice ailleurs tranche |
| 21 | **Le légendaire comme climat** | Pas de deus ex machina | Séismes scriptés (`special ShakeCamera`/`setweather`) dont la fréquence suit `VAR_ETAT_VOLCAN` ; PNJ qui interprètent. Groudon ne parle jamais |
| 22 | **Règles du mythe posées tôt** | Résolution crédible | Inscriptions et livres (Mont Mémoria, Musée) qui énoncent les limites de l'Orbe ; le climax les respecte. Indices de règle au moins 3 fois avant le climax |
| 23 | **L'antagoniste visible avant d'être révélé** | Twist recontextualisant | Placer Lambda (sous l'identité « Lambert ») dans 3-4 scènes anodines (Devon, port, labo). Le joueur peut lui parler ; ses répliques ont un double sens à la relecture |
| 24 | **Épilogue en diaporama** | Bilan des choix | Après le générique, une suite de cartes (warp + `fadescreen`) avec un PNJ et 2-3 msgbox par lieu selon les vars. 8 lieux × 3 variantes ≈ 24 petits scripts |
| 25 | **Le monde ouvert par les gens, pas par le noyau** | Rythme en semi-ouvert | Les quêtes libres entre badges servent les factions et relations (`VAR_REP_*`, `VAR_AFF_*`) ; les révélations du noyau restent attachées aux goulots (badges, Conseil) |

### 8.1 Gabarit d'une scène (pour tous les scénaristes)

```
SCÈNE : [ID] — [carte] — [acte/chapitre]
But du personnage dans la scène : (ce qu'il veut maintenant)
Ce que le joueur apprend : (1 info, au maximum 2)
Ce que le joueur peut faire : (choix / combat / objet / rien)
Conséquence : immédiate / différée (flag, var, classe S/M/L)
Plant ou récolte : (ID du registre §1.6)
Ligne de respiration : (humour ou chaleur, oui/non)
Budget : ≤ 15 msgbox, ≤ 2 nouveaux noms propres
```

### 8.2 Contrôle qualité d'une décision (à joindre au DECISION_LEDGER)

1. Quel type (arbitrage, présence, don, aveu, combat, discret) ?
2. Quels deux systèmes bougent, dans des sens opposés ?
3. Quelle réaction immédiate (au moins 1 ligne) ?
4. Quel écho plus tard (où, quand) ?
5. Un joueur raisonnable pourrait-il choisir chaque option ? Si non, réécrire.
6. Classe de coût S/M/L, et le budget global (≈ 70/25/5 %) tient-il ?

---

## Annexe — Références rapides par besoin

- **Concevoir l'oignon du mystère** : *Outer Wilds*, *Obra Dinn*, *Chinatown*, *Légendes Arceus* (Volo).
- **Écrire une distribution chorale** : *The Wire*, *Mass Effect 2*, *Suikoden II*, *FFVI*.
- **Faire peser les choix** : *Witcher 3* (différé), *New Vegas* (factions), *Pentiment* (vérité incertaine), Ashwell/Short (structures).
- **Écrire un antagoniste** : N/Ghetsis, Killmonger, Rose ; règle du diagnostic juste / traitement faux.
- **Utiliser un dieu** : *Princesse Mononoké*, *Shadow of the Colossus*, lois de Sanderson.
- **Finir** : épilogues de *Witcher 3*, couches de fins de *NieR*, système d'*Undertale* ; contre-exemple *Mass Effect 3*.
