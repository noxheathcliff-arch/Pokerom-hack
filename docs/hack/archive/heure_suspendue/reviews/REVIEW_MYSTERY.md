# REVIEW_MYSTERY — Critique indépendante de l'architecture du mystère

> Relecteur : critique narratif indépendant (spécialité : architecture du mystère, loyauté des indices, design des révélations, cohérence interne). Je n'ai pas écrit l'histoire.
> Corpus lu : `GAME_DESIGN_BIBLE.md` v1.0, `bible/CHAPTERS.md`, `bible/WORLD.md`, `bible/CHARACTERS.md`, `EXPERIENCE_INTENT.md` §9, `NARRATIVE_DIRECTIONS.md` (§2, §5, §6), `LORE_DOSSIER.md` §0.3 et §1.
> Date : 2026-10-13. Objet : défauts concrets uniquement. Les qualités (thème, antagoniste, sémiotique des Figements) sont réelles mais hors sujet ici.

Légende de sévérité :
- **BLOQUANT** : contradiction ou trou qui casse la logique du monde ou d'une révélation ; à corriger avant toute rédaction de script.
- **MAJEUR** : affaiblit nettement le mystère, la loyauté ou une révélation ; à corriger en préproduction.
- **MINEUR** : incohérence locale, oubli, finition.

---

## A. Règles du monde (les cloches) — le moteur du mystère ne tourne pas

### 1. BLOQUANT — La Cloche Mère est à trois endroits à la fois
- **Où :** `WORLD.md` §1.1.4 et §1.1.11 ; `CHAPTERS.md` ch. 11 étapes 2 et 4, ch. 15 étape 2 ; `GAME_DESIGN_BIBLE.md` §4 (Acte II).
- **Problème :** §1.1.4 dit que la Cloche Mère doit sonner le carillon **depuis le clocher (Pilier Céleste)**. Au ch. 11, le vieux couple annonce que la Cloche Mère **a disparu** (étape 2), puis Ysaline **sonne la Cloche Mère au sommet du Mont Mémoria** (étape 4). Au ch. 15, la Cloche Mère est **suspendue au sommet du Pilier**. Personne n'explique comment une femme de 80 ans transporte une cloche monumentale au Pilier (accès par Surf, sols fissurés franchis au Vélo Cross), ni pourquoi elle est « disparue » alors qu'elle est sur place.
- **Pourquoi c'est grave :** c'est l'objet central de R3 et du climax. Un joueur attentif (le public visé : « observer, formuler une hypothèse ») bute sur l'incohérence au moment même de la révélation.
- **Correctif :** fixer une seule vérité. Proposition : la Cloche Mère a été déplacée au Pilier il y a un mois (d'où la « disparition » constatée par le couple) ; au sommet du Mont Mémoria, Ysaline sonne un **grelot-relais** taillé dans le même alliage (un éclat de la Cloche Mère), qui maintient le Figement du sommet *à distance*. Le transport est fait par les Carillonneurs (et un Archéodong en Lévitation : `[CANON-JEU : DP]`, « aurait ouvert des passages »), ce qui en fait un indice. Réécrire ch. 11 étape 4 : « elle fait tinter le grelot-relais ».

### 2. BLOQUANT — Le glas n'est pas un secret : tout le monde le connaît déjà
- **Où :** `WORLD.md` §1.1.2 (« le glas = **même mélodie jouée à l'envers** ») et §1.1.11 (le Mont Mémoria sonne le glas à chaque funérailles, « transmis oralement ») ; `CHARACTERS.md` §7 (« elle a "oublié" volontairement la moitié ») ; `CHAPTERS.md` ch. 13 étape 3, ch. 15 étape 3 (quête des deux moitiés).
- **Problème :** (a) si le glas est le carillon à l'envers, quiconque connaît le carillon (Ysaline, Bourdon, Tierce, chaque Carillonneur) connaît le glas ; (b) le vieux couple et Ysaline le jouent depuis cinquante ans. Toute la quête de l'acte III (moitié 1 à Fondmer, moitié 2 sur la Cloche Mère) cherche donc une information déjà possédée par trois PNJ que le joueur a rencontrés. Et Ysaline ne peut pas avoir « oublié » ce qu'elle a joué mille fois.
- **Pourquoi c'est grave :** la serrure-clé n° 11 (« information + combat ») est vide. Un joueur qui pose la question « pourquoi ne pas demander au vieux couple ? » détruit l'acte III.
- **Correctif :** distinguer **glas des funérailles** (version populaire, tronquée, qui n'agit que sur les grelots et apaise les vivants : c'est pour cela qu'« on se sentait plus léger », ch. 8) et **glas véritable** (qui ne se joue que sur la Cloche Mère et contient une **coda** perdue). Supprimer « même mélodie jouée à l'envers » ou le restreindre aux cloches mineures. Faire dire au vieux couple au ch. 11 : « Le glas qu'on sonne ici n'a jamais délivré personne. Il console. » — ce qui **pose** la question (« alors qu'est-ce qui délivre une Cloche Mère ? ») au lieu de la laisser implicite.

### 3. BLOQUANT — La règle des « sept cloches » est inobservable et ses comptes sont faux
- **Où :** `WORLD.md` §1.1.4-5 ; `CHAPTERS.md` ch. 12 étape 1 (« 5 cloches sur 7 »), ch. 15 étape 2 (« Encore deux cloches ») ; `GAME_DESIGN_BIBLE.md` §12 invariant 7 (« chaque Figement : vu ou annoncé avant ») ; `CHAPTERS.md` §20 (budget « 2 × 7 Figements »).
- **Problème :** au ch. 12, le joueur a délivré F1-F4 (et peut-être F-opt1). Seul le sommet du Mont Mémoria est figé à sa connaissance. Si 5 cloches sur 7 sont accordées, **quatre Figements existent quelque part sans que le joueur les voie** — contraire à l'invariant 7 et à la loyauté. Au ch. 15, après la délivrance de F5, « encore deux cloches » ne se déduit d'aucun compte donné au joueur. Le budget de flags compte 7 Figements alors que la liste en contient 8 (F1-F6, F-opt1, sommet).
- **Pourquoi c'est grave :** c'est la seule règle quantitative du mystère ; un joueur qui tient les comptes (comportement que l'intention veut récompenser) constate qu'ils sont arbitraires.
- **Correctif :** rendre le carillon **visible et comptable** : (1) une carte murale au Centre Spatial (ch. 12) affiche les points accordés ; les points cachés sont des Figements **petits et nommés** (un phare, un puits, une cabane de la Route 123…) annoncés par PNJ et visitables en option ; (2) chaque délivrance fait reculer un compteur dans le Carnet de Gaspard (« cloches accordées : 4/7 ») ; (3) recompter les flags (8 + les cachés).

### 4. BLOQUANT — Absol arrive la veille de Figements déjà formés (la preuve R2 repose sur une chronologie fausse)
- **Où :** `CHAPTERS.md` ch. 0 étape 4 (rumeur du bois figé), ch. 1 étapes 2 et 4 (Absol vu « la veille » alors que Gaspard a déjà vu le bois figé et que Peeko a disparu), ch. 2 étape 3 (« Depuis hier, on n'entend plus les Chuchmur » : le tunnel est **déjà** figé), ch. 4 étape 4 et ch. 5 étapes 2 et 4 (Absol vu « la veille » et Ysaline **en train d'accorder** la cloche) ; `GAME_DESIGN_BIBLE.md` §12 invariant 3.
- **Problème :** pour F1 et F2, Absol est montré **après** la formation du Figement, et Ysaline accorde au ch. 5 une cloche dont le Figement existe depuis le ch. 2. Or R2 tout entière repose sur « Absol est toujours vu *avant* ».
- **Pourquoi c'est grave :** le joueur qui recoupe (exactement l'enquête demandée au ch. 10) trouve que les témoignages contredisent la thèse qu'on lui fait défendre. La fausse piste devient déloyale dans le mauvais sens : les faits donnent raison aux Veilleurs.
- **Correctif :** (a) ch. 2 : l'ouvrier dit « Les Chuchmur sont nerveux depuis hier » (annonce, pas Figement) ; le tunnel se fige **pendant** le ch. 5 ; (b) F1 : faire voir Absol dans le prologue (Route 103, de loin, la nuit), avant la rumeur ; (c) ajouter au Carnet une **chronologie** auto-remplie (« Absol vu : … / Figement constaté : … ») qui devient la pièce à conviction du ch. 10 — c'est la règle qui se joue au lieu de se dire.

### 5. MAJEUR — Le « tintement » et la « veille » sont deux causalités incompatibles, et R5 en ajoute une troisième
- **Où :** `WORLD.md` §1.1.6 (la cloche résonne **quelques secondes** avant le Figement, Absol le perçoit et arrive **la veille**) ; `CHAPTERS.md` ch. 9 étape 2 (« Absol était **déjà là avant** le tintement ») ; ch. 15 étape 3 (R5 : c'est Augure qui a **envoyé** Absol).
- **Problème :** un signal de 4 secondes ne peut pas être perçu la veille. L'indice I13 est présenté comme une preuve d'innocence, mais il réfute aussi l'explication officielle (§1.1.6). Puis R5 remplace tout par « Augure l'envoyait », sans mécanisme (comment un Xatu figé depuis un mois dirige-t-il un Absol libre ?).
- **Pourquoi c'est grave :** trois explications du même fait, dont aucune n'est cohérente avec les deux autres. R5 ressemble à une rustine plutôt qu'à une relecture.
- **Correctif :** une seule chaîne causale. Proposition : Absol perçoit les catastrophes **à venir** (canon pur, `[CANON-JEU : RSE Pokédex]`) — il n'a besoin d'aucun tintement ; le tintement sert seulement à prouver qu'un *son* précède le Figement (indice R1). Pour R5 : Augure, *avant* d'être figé, a vu les lieux à venir et a « montré » à Absol où attendre le joueur (télépathie de Xatu : canon d'espèce Psy) ; planter un indice : Absol est vu une fois au **sommet du Mont Mémoria** dans le prologue (vision du ch. 1 : un Absol aux côtés d'un oiseau vert). Supprimer de §1.1.6 « les êtres sensibles au malheur perçoivent [le tintement] ».

### 6. MAJEUR — Pourquoi des cloches anciennes dans des bâtiments modernes ?
- **Où :** `WORLD.md` §1.1.3-4 (cloches **enfouies** depuis l'Antiquité) ; `CHAPTERS.md` ch. 8 (centrale de New Lavandia), ch. 9 (Institut Météo, 2F), ch. 14 (Atalanopolis : « la cloche n'est pas ici »).
- **Problème :** une cloche du peuple ancien au 2ᵉ étage de l'Institut Météo ou dans une centrale électrique est anachronique ; et le Figement d'Atalanopolis n'a pas de cloche dans son rayon, contre la règle §1.1.3 (« maintient un Figement *autour d'elle* ») et contre l'invariant 7 (cloche-pivot dans chaque Figement).
- **Pourquoi c'est grave :** le joueur ne peut pas formuler d'hypothèse sur *où* le prochain Figement aura lieu, ce qui ruine la posture d'enquêteur et le potentiel de « relecture » (C2).
- **Correctif :** deux classes de cloches : **cloches fixes** (anciennes, dans les sites antiques : Bois, Tunnel, Tréfonds, Mont Chimnée) et **grelots plantés** par les Carillonneurs (éclats refondus, posables n'importe où : Institut, centrale). C'est déjà suggéré par les grelots du marché (ch. 4) : il suffit de l'assumer. Pour Atalanopolis : la cloche est **sous la ville**, dans la Grotte Origine (zone « préservée par les anciens », ch. 14) ; la délivrer exigerait d'entrer là où dort Groudon/Kyogre — d'où l'impossibilité, et le besoin du glas global.

### 7. MAJEUR — Le sommet est figé avant que le plan soit complet : la motivation d'Ysaline n'est pas lisible
- **Où :** `WORLD.md` §1.1.4 ; `CHAPTERS.md` ch. 11 étapes 3-4 ; `CHARACTERS.md` §7.
- **Problème :** au ch. 11, Augure est **déjà** figé. Le but d'Ysaline (« qu'il ne meure pas ») est donc atteint. Le besoin de permanence n'existe que si quelqu'un peut délivrer le sommet — or ni elle ni le jeu ne disent *qui* elle craint (le Diapason de Gaspard ? le vieux couple et son glas ?). Par ailleurs, figer Augure la sépare de lui pour toujours (elle reste dans le temps qui passe) : « Moi, je ne la verrai pas » est ambigu.
- **Pourquoi c'est grave :** C4/C3 reposent sur un plan « compréhensible, voire défendable ». Ici le joueur ne sait pas ce qu'elle gagnerait concrètement avec les cinq cloches suivantes.
- **Correctif :** expliciter deux choses, *en jeu* : (1) un Figement simple **s'use** (le brouillard du sommet s'éclaircit à chaque visite ; les objets suspendus du Bois avaient commencé à tomber) : il faut le carillon pour le rendre permanent ; (2) Ysaline compte **se figer elle-même** à ses côtés une fois le carillon complet — révélé au ch. 15 par une place vide marquée près d'Augure. Cela fait de R4 (« puis eux-mêmes ») un **miroir exact** de son plan : R4 ouvre enfin une vraie question (« va-t-elle faire comme eux ? »).

### 8. MAJEUR — Le Diapason est un deus ex machina
- **Où :** `CHAPTERS.md` ch. 1 étape 6 ; `WORLD.md` §1.1.8 (« trouvé par Gaspard ») ; `CHARACTERS.md` §6.
- **Problème :** l'unique contre-outil d'un art perdu depuis des millénaires se trouve, sans explication, dans la poche du premier PNJ rencontré à l'orée du premier Figement. Ni sa provenance ni pourquoi Ysaline ne s'en inquiète ne sont traitées. Au ch. 15, le lien entre un **diapason** (qui désaccorde) et une **mélodie** (le glas sonné sur une cloche) n'est pas défini : que fait Ysaline du Diapason qu'on lui tend ?
- **Pourquoi c'est grave :** c'est l'objet clé du jeu et l'objet de la scène finale.
- **Correctif :** (a) Gaspard l'a trouvé **parce qu'un Absol l'a mené** à une ruine de la Route 104 trois jours plus tôt (il le raconte au ch. 1 comme une anecdote ; payoff R5) ; (b) le Diapason donne la **note de départ** du glas véritable : sans lui, la Cloche Mère ne peut jouer que le carillon. Écrire cette règle au §1.1.8. Ysaline voudra le Diapason dès le ch. 5 (Tierce tente de le voler : scène jouée).

---

## B. Révélations — test « la question avant la réponse » (EXPERIENCE_INTENT §9.4)

| R | Question déjà posée par le joueur ? | Réponse déjà donnée avant ? | Ouvre une nouvelle question ? | Verdict |
|---|---|---|---|---|
| R1 (ch. 5) | Oui (Q1, ch. 0-1) | **Oui, en partie** : dès le ch. 1, un Carillonneur humain avec grelot dit « On a juste… arrêté » au cœur d'un Figement à cloche | Oui (Q3) | **Échoue sur la nouveauté** (voir n° 9) |
| R2 (ch. 10) | Oui (Q2, ch. 1) | **Oui** : R1 (ch. 5) innocente Absol logiquement ; Pokédex d'Absol (ch. 6 si capturé) | « Qui guide Absol ? » — non posée en jeu avant ch. 11 | **Échoue** (n° 10) |
| R3 (ch. 11) | Oui (Q3, ch. 5) | Fortement télégraphiée (grelots, « je sonne au Mont Mémoria », Maman, Rocheval) mais pas dite | Oui (permanence, carillon) | **Passe**, prévisible |
| R4 (ch. 13) | **Non** : Q4 n'est réellement posée qu'au ch. 10 (Musée), et I7 (ch. 5) y répond déjà | **Oui** (I7) | « Où est la seconde moitié ? » — répondu dans la même phrase | **Échoue** (n° 11) |
| R5 (ch. 15) | Oui (Q5), mais la table la pose au ch. 11 alors que les visions commencent au ch. 5 | **Oui de fait** : oiseau vert + « un œil vers hier, un œil vers demain » (Pokédex Xatu) devant le Xatu au ch. 11 ; `CHAPTERS` §19 l'admet (« soupçonne ») | Aucune (fin) | **Échoue sur la surprise** (n° 12) |

### 9. MAJEUR — R1 est éventée par le tutoriel
- **Où :** `CHAPTERS.md` ch. 1 étapes 5-6 (Carillonneur dans F1 ; cloche-pivot ; grelot) ; `GAME_DESIGN_BIBLE.md` §6.1 (« les Carillonneurs y circulent ») ; `WORLD.md` §3.4 R1.
- **Problème :** R1 = « les Figements viennent de cloches, sonnées par des humains ». Le joueur l'apprend à 0:50 : un humain organisé (classe CARILLONNEUR affichée en combat) patrouille dans le Figement et revendique l'acte, au pied d'une cloche. Au ch. 5, seule l'identité d'Ysaline est neuve — et c'est la seule personne nommée associée aux cloches depuis le ch. 4.
- **Pourquoi c'est grave :** la seule révélation de l'acte I n'apprend presque rien ; C9 exige « ≥ 1 révélation par acte ».
- **Correctif :** aucun Carillonneur avant F2. Dans F1, le combat secondaire est un **Pokémon sauvage figé à demi** (ou un Veilleur pris dans le Figement, ce qui sert la fausse piste Absol). Le grelot du bois est trouvé **dans la main d'un promeneur figé** (ambigu : victime ou coupable ?). Ainsi Q1 reste ouverte (« phénomène naturel ? malédiction d'Absol ? ») jusqu'à F2, où la vue d'Ysaline accordant la cloche **est** la révélation.

### 10. MAJEUR — R2 est résolue logiquement au ch. 5 et par le canon dès le ch. 1
- **Où :** `WORLD.md` §3.1 Q2, §3.3 (fausse piste « Absol cause »), §3.4 R2 ; `CHAPTERS.md` ch. 5, ch. 10 ; `GAME_DESIGN_BIBLE.md` §13 (« seuls des indices ») et §12 invariant 9 (Pokédex non modifié).
- **Problème :** dès R1, le joueur sait que des humains causent les Figements ; Q2 n'a plus d'objet pendant 6 heures. En outre, la fiche Pokédex d'Absol (non modifiable, invariant 9) dit qu'il prévoit les catastrophes ; tout joueur de Pokémon le sait. R2 n'est une révélation que pour Rocheval.
- **Pourquoi c'est grave :** le ch. 10, présenté comme révélation, est vécu comme une formalité ; la fausse piste n'est pas « loyale », elle est **transparente**.
- **Correctif :** muter Q2 après R1. Les Veilleurs passent à une **théorie de complicité** : « L'Absol est la bête de la sonneuse ; il repère les lieux pour elle. » La théorie s'appuie sur des faits vrais (Absol vu près d'Ysaline au Mont Chimnée, ch. 7 ; Absol présent à chaque cloche). La question devient : **pour qui travaille Absol ?** — et R2 (ch. 10) répond « pour personne d'humain : il avertit » tout en ouvrant explicitement Q5 (« alors qui l'envoie à *moi* ? »). R2 et R5 deviennent une chaîne.

### 11. MAJEUR — R4 : la réponse précède la question (I7)
- **Où :** `WORLD.md` §3.1 (Q4 « posée ch. 3 Granite, ch. 10 Musée »), §3.2 I4 et I7, §3.4 R4 ; `CHAPTERS.md` ch. 3, ch. 5 étape 6, ch. 13 étape 3.
- **Problème :** l'inscription du ch. 3 (« LE SON ARRÊTE ») ne pose pas la question « que craignait le peuple ? » ; la phrase canonique « nous en avions peur » n'est vue qu'au ch. 10. Mais au ch. 5, I7 « CE QUE NOUS AIMONS NE PASSERA PAS » donne déjà la clé (ils figeaient par amour). R4 arrive 8 heures après sa propre réponse. De plus, R4 prétend ouvrir « où est la seconde moitié ? », mais la même fresque répond (« gravée sur la cloche du clocher »).
- **Pourquoi c'est grave :** la révélation la plus thématique (la relecture du Braille canonique, greffe de la direction A) perd tout son effet.
- **Correctif :** inverser l'ordre. Ch. 3 (Granite) : inscription tronquée « … NOUS EN AVIONS PEUR » (pose Q4 tôt, avec la lecture « monstres » qui va de soi). Ch. 5 : I7 devient ambiguë, « NOUS AVONS ARRÊTÉ CE QUI … » (le reste brisé). Ch. 10 : le Musée cimente la fausse lecture. Ch. 13 : la fresque complète les deux fragments. Et la seconde moitié n'est **pas** localisée par la fresque : la fresque montre une tour au milieu de la mer **dont le joueur doit reconnaître la silhouette** (voir n° 13).

### 12. MAJEUR — R5 est devinable au ch. 11 et n'apporte plus que « il veut partir »
- **Où :** `GAME_DESIGN_BIBLE.md` §6.6 (« silhouette d'**oiseau vert** » + « Un œil vers hier. Un œil vers demain ») ; `CHAPTERS.md` ch. 11 étape 5, ch. 15 étape 3, §19 ; `WORLD.md` §3.1 Q5 ; `CHARACTERS.md` §12 (les Carillonneurs utilisent **Natu**).
- **Problème :** la vision décrit littéralement un Xatu (couleur + Pokédex canonique « voit le passé et l'avenir »), puis se répète au pied d'un Xatu au ch. 11. Le joueur qui a vu un Natu dans une équipe de Carillonneur fait le lien dès le ch. 5. Au ch. 15, R5 est livrée par **une vision plus longue** (exposition passive) et ne pose aucune question nouvelle. Par ailleurs, un trou de motivation reste ouvert : si Augure voyait tout, pourquoi s'est-il laissé conduire et figer au sommet ?
- **Pourquoi c'est grave :** la révélation finale est la plus faible des cinq, et elle est *regardée* (C3 ancre 1).
- **Correctif :** (a) visions sans couleur ni forme d'oiseau : un **œil** unique, puis deux, puis la phrase seulement au ch. 11 ; (b) donner une fausse piste loyale à Q5 : les visions semblent venir du **peuple ancien** (elles surviennent près des cloches ; Gaspard y croit) ; (c) faire de R5 une **action** : au ch. 15, le joueur doit retrouver dans le Carnet les dates des visions et les aligner sur la vie d'Augure (la première vision date du jour où Augure a été figé, 4 h 12 — voir n° 17) ; (d) répondre au « pourquoi s'est-il laissé figer » : Augure a vu que seule Ysaline sonnant elle-même le glas la guérirait ; s'enfuir l'aurait laissée seule avec son refus. C'est la vraie dernière révélation, et elle est émotionnelle.

---

## C. Expositions, deus ex machina, « dit au lieu de joué »

### 13. MAJEUR — Le Pilier Céleste-clocher est annoncé par Marc, pas découvert
- **Où :** `CHAPTERS.md` ch. 14 étape 2 ; `GAME_DESIGN_BIBLE.md` §13 (« Marc l'annonce seulement ») ; `WORLD.md` §1.1.10.
- **Problème :** le lieu final et le dernier secret topographique sont livrés par une réplique d'un personnage qui n'a jamais été relié aux cloches. Rien n'explique comment Marc le sait. Idem pour la règle des 7 cloches, donnée par les instruments de Pierre (ch. 12).
- **Pourquoi c'est grave :** C2 ancre 1 = « mystère résolu par un PNJ qui explique ». C'est exactement ce cas, au moment le plus important.
- **Correctif :** faire **déduire** le clocher : (1) la fresque de Fondmer montre une tour sur la mer ; (2) les relevés d'ondes de Pierre (ch. 12) convergent vers un point du Chenal 131, montré sur une carte ; (3) le panneau existant de Pacifiville / la vue du Pilier depuis la mer. Marc **confirme** (les sages d'Atalanopolis gardent une tradition, `[CANON-JEU : E]`, LORE §1.2) au lieu d'annoncer.

### 14. MAJEUR — Le Carnet traduit le Braille à la place du joueur
- **Où :** `CHAPTERS.md` ch. 3 étape 2, ch. 13 étape 2 (« le Carnet les traduit ») ; `GAME_DESIGN_BIBLE.md` §6.5.
- **Problème :** la greffe de la direction A (« lire le monde ») est neutralisée : le joueur relève, le jeu lit. Le « Test du joueur qui lit tout » n'est récompensé par rien.
- **Correctif :** le Carnet donne la **grille** (alphabet Braille) ; le joueur lit lui-même les inscriptions courtes (la police Braille existe dans le moteur, LORE §1.3) ; une réponse saisie (`multichoice` entre 3 lectures) valide le flag. Les inscriptions longues restent traduites. Corriger aussi l'incohérence : au ch. 1, Gaspard « ne sait pas encore lire » le motif, mais au ch. 3 le Carnet contient une grille de lecture — dire qui l'a ajoutée (Pierre ?).

### 15. MAJEUR — Le glas global du ch. 15 contredit le postgame des Regis et laisse le peuple ancien en suspens
- **Où :** `CHAPTERS.md` ch. 15 étape 4 (« chaque Figement restant se délivre ») ; `WORLD.md` §1.1.9 (le peuple s'est figé lui-même), §6 P1 (le joueur délivre les Regis ; « Merci d'avoir sonné ») ; §2 (« les tombeaux se réveillent »).
- **Problème :** si le glas délivre tout Figement, il délivre aussi les Regis — et **le peuple ancien figé** : où sont ces gens ? Reprennent-ils vie au XXIᵉ siècle ? Le jeu ne le dit pas ; le message « Merci d'avoir sonné » suppose qu'ils sont conscients. Le postgame P1 devient redondant.
- **Correctif :** restreindre le glas aux cloches **accordées par Ysaline** (règle : la Cloche Mère ne délivre que ce qu'elle a elle-même sonné) ; les Regis ont été figés par d'autres cloches, scellées dans les tombeaux. Donner au peuple une fin claire : la dernière salle du Sanctuaire contient **leur cloche, fêlée** ; ils se sont laissés partir longtemps après (la fresque finale est leur glas). Le message devient une inscription, pas des survivants.

### 16. MAJEUR — Atalanopolis : « figée » ou « évacuée » ?
- **Où :** `CHAPTERS.md` ch. 14 étape 1 (habitants immobiles) ; `CHARACTERS.md` §10 (« ses Veilleurs **évacuent** Atalanopolis ») ; `WORLD.md` §1.1.5 (« escalade quand elle manque de temps »).
- **Problème :** contradiction directe ; en outre, rien n'explique pourquoi figer une ville entière aide Ysaline (une cloche = un Figement, quelle que soit sa taille). L'escalade ressemble à un prétexte pour bloquer l'arène 8.
- **Correctif :** les Veilleurs **gardent les abords** (ch. 14) et évacuent Pacifiville, pas Atalanopolis. Motiver l'escalade : la cloche de la Grotte Origine (n° 6) est la **plus grande** cloche fixe — elle compte pour deux dans le carillon ; Ysaline la sacrifie parce que le joueur a délivré trop de cloches (lien causal joueur → escalade, qui rend le joueur responsable et le jeu plus fort).

---

## D. Fausses pistes et indices orphelins

### 17. MINEUR — L'horloge de Rosyères (4 h 12) n'a pas de résolution
- **Où :** `CHAPTERS.md` ch. 0 étape 4 ; `WORLD.md` §3.2 I1 (« effet parasite »), §2 (−1 mois).
- **Problème :** première image du jeu, jamais payée ; « effet parasite » n'est dit nulle part au joueur. Une heure précise appelle une explication.
- **Correctif :** 4 h 12 = l'heure à laquelle Ysaline a figé le sommet (le Carnet l'apprend au ch. 11 : la brume du sommet est « arrêtée à 4 h 12 », soleil levant). Payoff gratuit de relecture.

### 18. MINEUR — La fausse piste « Devon / projet Résonance » n'existe pas dans le scénario
- **Où :** `WORLD.md` §3.3 (ingénieur, « projet Résonance », démentie ch. 12) ; absente de `CHAPTERS.md` ch. 2 et ch. 12.
- **Correctif :** soit la planter (ch. 2, un ingénieur ; ch. 5, Lavandia : la panne serait due à « leurs essais »), soit la supprimer de §3.3. En l'état, c'est une fausse piste orpheline.

### 19. MINEUR — Indice I3 sans scène
- **Où :** `WORLD.md` §3.2 I3 (Seko : « plus aucune rencontre là-dedans », ch. 1) ; `CHARACTERS.md` §3 ; absent de `CHAPTERS.md` ch. 1.
- **Correctif :** ajouter un appel PokéNav de Seko à la sortie de F1 (ou retirer I3).

### 20. MAJEUR — La preuve New Lavandia (« Absol ne peut entrer sous terre ») est fausse dans le monde du jeu
- **Où :** `CHAPTERS.md` ch. 8 étape 3, ch. 10 étape 3 ; `WORLD.md` §3.2 I12.
- **Problème :** Absol est escorté *dans* le Site Météore (grotte, ch. 6) et rôde près du Tunnel Mérazon (souterrain). « Absol ne peut entrer sous terre » est contredit par le jeu lui-même.
- **Correctif :** la preuve devient : New Lavandia s'est figée **le jour où Absol était blessé et encerclé au Site Météore** (date attestée par les Veilleurs eux-mêmes). Preuve par alibi, que le joueur a vécu (escorte) — beaucoup plus forte et loyale.

### 21. MINEUR — Les grelots d'Ysaline au marché : indice énorme non exploité
- **Où :** `CHAPTERS.md` ch. 4 étapes 1 et 3 ; `GAME_DESIGN_BIBLE.md` §13.
- **Problème :** le joueur porte un grelot d'alliage inconnu que Morel vient d'analyser, et une vieille dame vend des grelots trois écrans plus loin. Soit ce sont les mêmes (alors le secret de §13 fuit de façon flagrante), soit non (alors pourquoi ?). Aucune interaction n'est prévue.
- **Correctif :** assumer l'indice comme **récompense du lecteur** : si le joueur examine l'étal, le texte note « Ces grelots ne sont pas du même métal que le tien. » (vrai : elle vend du laiton, elle garde l'alliage). Fausse piste loyale et caractérisation (elle ne ment pas, elle cache).

### 22. MINEUR — Spectra : collision avec le canon et coda devinable
- **Où :** `CHARACTERS.md` §7, §16 ; `GAME_DESIGN_BIBLE.md` §13 ; `LORE_DOSSIER.md` §1.7 (Spectra « a grandi au Mont Mémoria auprès de sa grand-mère »).
- **Problème :** le canon place déjà la grand-mère de Spectra au Mont Mémoria (dans ROSA, la vieille gardienne du sommet est présentée comme telle ◐ à vérifier). Le hack garde le vieux couple **et** fait d'Ysaline la grand-mère : soit contradiction pour le connaisseur, soit coda devinée dès le ch. 4. Q6 n'est par ailleurs jamais une vraie question pour le joueur (une photo).
- **Correctif :** vérifier le canon ROSA ; si confirmé, faire d'Ysaline la **sœur** de la gardienne (Spectra : « ma grand-tante ») ou fondre Ysaline avec la gardienne ; et ancrer Q6 par une seconde trace (le Conseil 4 a une lettre non ouverte en arrière-plan ?) ou la retirer de la table des questions.

### 23. MINEUR — Incohérences de chapitres et de personnages entre documents
- `CHARACTERS.md` §10 : Rocheval confronté aux preuves au **ch. 11** ; `CHAPTERS.md` : **ch. 10**.
- `CHARACTERS.md` §2 : le rival « doute devant le Xatu (ch. 11) » ; il n'apparaît pas au ch. 11 dans `CHAPTERS.md`. Ajouter la scène (sommet, après le combat) ou corriger l'arc.
- `CHARACTERS.md` §12.1 : Bourdon « s'efface à Atalanopolis » ; `CHAPTERS.md` ch. 15 : il s'efface au **Pilier Céleste**.
- `GAME_DESIGN_BIBLE.md` §4 : c'est **Gaspard** qui demande de porter le fragment à Pierre puis à Morel ; `CHAPTERS.md` ch. 2 : c'est **M. Rochard** (Devon).
- `GAME_DESIGN_BIBLE.md` §4 Acte II : la centrale de New Lavandia est citée parmi les preuves apportées, comme si elle était obligatoire ; elle est facultative (ch. 8, ch. 10 : « au choix »).
- `WORLD.md` §3.1 : Q5 posée au ch. 11 ; `WORLD.md` §3.2 I19 : visions dès le ch. 5. Q5 doit être posée au ch. 5.
- `WORLD.md` §1.1.6 : tag `[CANON-JEU : RSE Pokédex]` sur une règle (le tintement perçu) qui est une invention ; seul « Absol apparaît avant les catastrophes » est canon. `CHARACTERS.md` §8 : le pouvoir de Xatu est tagué `OAC` alors que l'entrée « voit passé et avenir » est déjà dans les Pokédex de 2ᵉ/3ᵉ génération (◐ à vérifier).

### 24. MINEUR — L'Épave et Tierce : Figement antérieur au plan
- **Où :** `CHAPTERS.md` ch. 8 étape 4 ; `CHARACTERS.md` §12.1 (Tierce « délivre elle-même l'Épave ») ; `WORLD.md` §2 (naufrage −20 ans, plan −1 an).
- **Problème :** le fantôme qui « répète l'heure du naufrage » est-il un Figement (une cloche) ou un fantôme vanilla ? Si c'est un Figement, qui l'a sonné et quand ? Si c'est Tierce, c'est un indice majeur sur les Carillonneurs non exploité.
- **Correctif :** l'Épave est le **premier essai** de Tierce (−1 an, avant Ysaline ou avec elle) : un grelot accordé dans la cabine de sa mère. C'est l'indice du « grelot planté » (n° 6) et la preuve que les Carillonneurs ont leurs propres motifs.

### 25. MINEUR — Rayquaza dort pendant un combat et un glas sous son nez
- **Où :** `CHAPTERS.md` ch. 15 ; `WORLD.md` §1.1.10, §6 P2.
- **Problème :** « il s'éveille après le glas » sans causalité ; le joueur se demandera pourquoi un combat de boss et une cloche géante ne le réveillent pas, mais le glas, si.
- **Correctif :** lui donner une cause dans les règles : le peuple ancien avait **figé Rayquaza lui aussi** (gardien du ciel) avec la Cloche Mère ; le glas véritable le délivre. Cela respecte l'invariant 5 (il n'agit pas dans le climax), relie postgame et mythe, et fait du Pilier un clocher *et* une prison — une relecture de plus.

---

## E. Notation (EXPERIENCE_INTENT §9.2) — contre-vérification de l'auto-évaluation (`NARRATIVE_DIRECTIONS.md` §5.2)

| Critère (poids) | Auto-éval. | **Ma note** | Justification |
|---|---|---|---|
| **C2 Potentiel de mystère** (12) | 4 | **3** | Questions bien emboîtées sur le papier (Q1 → Q6) et indices placés dans des lieux, mais trois des cinq révélations sont pré-répondues (R1 par le tutoriel, R2 par R1 et le canon, R4 par I7) et R5 se devine sur le Pokédex. Les deux plus grandes informations (le clocher, la règle des 7) sont **dites** par Marc et Pierre : ancre 1 « résolu par un PNJ qui explique ». Remonte à 4 si n° 9-14 sont appliqués. |
| **C9 Rythme des révélations** (10) | 4 | **3** | La répartition est bonne (R1 fin acte I, R2-R3 acte II, R4-R5 acte III) et les indices sont plantés tôt. Mais le test « chaque réponse ouvre une question » échoue pour R2 (Q5 pas posée), R4 (la question ouverte est fermée dans la même scène) et R5 (rien) ; et l'ordre indice/question est inversé pour R4. L'acte II enchaîne R2 et R3 à 1 h d'écart après 6 h sans révélation. |
| **C5 Cohérence du worldbuilding** (8) | 4 | **2** | Les lieux ont tous une raison d'être (point fort réel), mais la logique interne du système central est contradictoire : Cloche Mère à trois endroits (n° 1), glas connu de tous (n° 2), comptes de cloches faux (n° 3), chronologie Absol inversée (n° 4), causalité tintement/veille (n° 5), cloches anciennes dans des bâtiments modernes (n° 6), Atalanopolis figée/évacuée (n° 16). Un mystère sans règles stables n'est pas résoluble par le joueur. |
| **C6 Usage intelligent du lore** (10) | 4 | **3** | Excellentes trouvailles : relecture du Braille du Sanctuaire « nous en avions peur », Absol messager (canon Pokédex), Éoko au Mont Mémoria, Archéodong et ses « passages », Mont Mémoria comme lieu du deuil, Pilier sans bâtisseur. Mais le canon fragilise aussi le mystère (Pokédex d'Absol et de Xatu donnent R2 et R5), Spectra entre en collision avec la grand-mère canonique (◐), et Rayquaza endormi au milieu du climax n'est pas intégré aux règles. |

**Effet sur le total :** ces quatre critères passent de 32,0 à 22,4 points pondérés, soit **−9,6** : la direction B tomberait d'environ 87,6 à **≈ 78/100**. Elle reste au-dessus du seuil de 70 et sans note < 2 sur C2/C9, mais elle ne surclasse plus la direction A (78,4) sur le mystère. Les correctifs BLOQUANTS n° 1 à 4 sont des corrections de règles, peu coûteuses en production (texte et flags), et rendraient C5 à 4 ; les n° 9 à 13 rendraient C2 et C9 à 4.

### Ordre de traitement recommandé
1. Réécrire `WORLD.md` §1.1 en une page de règles fermées (n° 1, 2, 3, 5, 6, 8, 15) — avant tout script.
2. Refaire la chronologie « veille / Figement » chapitre par chapitre (n° 4, 20) et l'ajouter comme table à `CHAPTERS.md` §19.
3. Retravailler les révélations R1, R2, R4, R5 selon le tableau de la section B (n° 9-12).
4. Remplacer les expositions de Marc et de Pierre par des déductions (n° 13, 14).
5. Corriger les incohérences documentaires (n° 23) et tracer les décisions au changelog de la bible (§14).
