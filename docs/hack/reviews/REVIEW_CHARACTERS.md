# Revue critique — Personnages, antagoniste, arcs, ton (*Pokémon Heure Suspendue*)

> Critique indépendant (spécialité : personnages, antagonistes, arcs émotionnels, ton, attentes des fans). Date : 2026-10-13.
> Documents lus : `GAME_DESIGN_BIBLE.md` v1.0, `bible/CHARACTERS.md`, `bible/CHAPTERS.md`, `bible/WORLD.md`, `EXPERIENCE_INTENT.md` (§9), `LORE_DOSSIER.md` §6.
> Mandat : trouver des défauts concrets, pas faire l'éloge. Les points forts réels ne sont cités que lorsqu'ils servent de levier à une correction.
> Gravité : **BLOQUANT** (casse la cohérence ou l'intention ; à corriger avant l'écriture des dialogues) ; **MAJEUR** (dégrade nettement l'expérience ; à corriger avant la tranche verticale) ; **MINEUR** (polissage, incohérence locale).

---

## A. L'antagoniste et sa faction

### 1. BLOQUANT — Le glas n'est pas un secret pour Ysaline, et toute la quête de l'acte III repose sur ce secret
- **Où :** `WORLD.md` §1.1.11 (« on y sonnait le glas des funérailles (la moitié "délivrance", transmise oralement) ») ; `CHARACTERS.md` §7 (« sonneuse de glas depuis cinquante ans », « elle a "oublié" volontairement la moitié de la mélodie ») ; `CHAPTERS.md` ch. 13.3 (Fondmer donne la « première moitié du glas ») et ch. 15.3 (« seconde moitié » sur la Cloche Mère).
- **Problème :** trois versions incompatibles. (a) Le glas est le métier quotidien d'Ysaline, transmis oralement au Mont Mémoria. (b) Elle en a « oublié » la moitié. (c) Le joueur doit en reconstituer deux moitiés gravées à Fondmer et sur la Cloche Mère. Et le Diapason, depuis le ch. 1, fait déjà ce que fait le glas (il désaccorde et délivre). R4 annonce donc au joueur l'existence d'un objet qu'il utilise depuis 15 heures, et que l'antagoniste pratique depuis 50 ans.
- **Impact joueur :** un fan attentif voit le trou à la Caverne Fondmer. La quête du glas, censée porter l'acte III, devient une chasse au MacGuffin. Et le choix final d'Ysaline perd son sens : elle a toujours su comment arrêter.
- **Correction :** une seule règle, écrite noir sur blanc. Proposition : le glas des funérailles est **un glas de personne**. Il « laisse partir » un mort et non un lieu, et Ysaline le connaît. Le **Diapason** désaccorde **une** cloche ordinaire. La **Cloche Mère accordée en carillon** ne peut être désaccordée que par le **grand glas**, celui du peuple ancien (moitiés à Fondmer et sur la Cloche Mère), que personne ne connaît. Le conflit d'Ysaline devient alors net : elle *sait* laisser partir les autres et refuse de le faire pour Augure. C'est déjà la meilleure ligne du personnage (« J'ai aidé mille personnes à laisser partir »). Supprimer « oublié volontairement ».

### 2. BLOQUANT — Les Carillonneurs n'ont aucune raison de suivre Ysaline
- **Où :** `CHARACTERS.md` §12 (« des endeuillés qu'Ysaline a accompagnés ») ; `WORLD.md` §2 (−1 an : « rassemble des endeuillés »).
- **Problème :** le projet d'Ysaline est strictement personnel : figer *son* sommet pour *son* Xatu. On ne dit pas ce qu'y gagne un veuf, un orphelin ou Tierce. Pourtant ils figent des ouvriers, des randonneurs, une ville entière, attaquent un enfant et cambriolent le Centre Spatial (ch. 12). Les croyances de Bourdon et de Tierce (« si le bateau ne coule jamais… ») réclament *leur propre* Figement, que le plan ne leur offre pas. Une vieille dame de 80 ans à la tête d'une milice militante n'est crédible que si la milice y trouve son compte.
- **Impact joueur :** on retombe sur la critique n°1 des fans (LORE §6.2, « Teams génériques, motivations absurdes, admins interchangeables »). Les sbires ne sont que des Aqua/Magma renommés qui disent une phrase triste avant de combattre.
- **Correction :** lier le carillon aux pertes des fidèles. Les **sept cloches** ne sont pas placées au hasard : chacune est accordée **sur le lieu d'une perte** d'un Carillonneur, et le carillon permanent les fige **toutes** pour toujours, pas seulement le sommet. Ysaline n'a pas recruté des soldats. Elle a fait une promesse à sept personnes : « vous ne perdrez plus rien ». Effets : (a) chaque Figement a un propriétaire nommé, présent sur place, qui défend *son* instant (variété, voir n°14) ; (b) quand Tierce renonce, une cloche tombe du carillon, ce qui donne enfin un poids mécanique aux arcs des lieutenants ; (c) le vol des relevés au ch. 12 se justifie (savoir combien de cloches tiennent encore). Préciser dans le même mouvement qui porte physiquement la Cloche Mère jusqu'au Pilier (voir n°5).

### 3. MAJEUR — L'acceptation d'Ysaline est provoquée par une révélation extérieure juste après une défaite : le schéma « vaincu donc converti »
- **Où :** `CHAPTERS.md` ch. 15.2-15.4.
- **Problème :** juste avant le combat, elle dit « Encore deux cloches et ce sera fini ». Elle perd. Une vision révèle qu'Augure voulait partir (R5). Le joueur lui tend le Diapason, elle sonne. Le basculement tient en une scène et c'est *l'information* qui le produit, pas un cheminement. Les « cinq étapes du deuil » de `CHARACTERS.md` §7 sont plaquées une par apparition : le déni tient en une phrase au ch. 5, la colère en une phrase au ch. 7, la dépression en un adjectif (« épuisée »). C'est un schéma Kübler-Ross sur rails, nommé dans la bible mais jamais *joué*.
- **Impact joueur :** la fin semble rapide et cousue de fil blanc. Les fans de N ou d'AZ attendent un doute visible *avant* la défaite.
- **Correction :** semer **trois fissures observables** avant le ch. 15. (1) Au ch. 7, elle s'arrête devant un randonneur figé en pleine fuite et dit « Celui-là avait peur. Je n'avais pas prévu ça. » (2) Au ch. 11, elle ne regarde jamais Augure en face : le texte la place dos au Xatu, et le joueur peut le remarquer en lui parlant deux fois. (3) Au ch. 12-14, les Carillonneurs la quittent un à un (voir n°2), et chaque départ est annoncé par un PNJ. Au ch. 15, le déclencheur doit venir **du joueur** et non d'une vision seule : il lui rend la réponse donnée au ch. 4, ou lui remet la lettre de Spectra (voir n°9). R5 devient la confirmation, pas la cause.

### 4. MAJEUR — Ysaline n'a jamais à répondre de ce qu'elle a fait aux innocents
- **Où :** ch. 5 (ouvriers), ch. 7 (randonneurs), ch. 14 (Atalanopolis entière, Juan compris) ; ch. 15.5 et épilogue (glas pour Augure, œuf de Natu offert).
- **Problème :** elle a figé une ville entière avec ses habitants. Pourtant l'épilogue lui donne le dernier mot (« Merci de ne pas m'avoir laissée… »), puis un œuf de Natu en récompense. Personne ne lui demande de comptes : ni Juan, ni Marc, ni les ouvriers, ni Adriane. La douceur est voulue (bible §2), mais l'absence complète de conséquences fait de l'antagoniste une victime pure et annule l'enjeu rétroactivement.
- **Impact joueur :** une dissonance morale. Un enfant de 10 ans comme un adulte se demande : « Et les gens d'Atalanopolis ? ». La fin passe pour complaisante.
- **Correction :** une scène courte de **réparation**, sans punition. Au postgame (P6) ou dans l'épilogue, Ysaline sonne un glas *pour chaque lieu figé* et va demander pardon à Atalanopolis. Juan accepte ou refuse, au choix du joueur ou sans choix, mais la scène existe. Autre option : l'œuf de Natu n'est pas un cadeau, il est confié par le vieux couple « pour qu'elle apprenne à voir grandir ».

### 5. MAJEUR — Les règles du carillon ne tiennent pas d'un chapitre à l'autre ; les enjeux deviennent illisibles
- **Où :** `WORLD.md` §1.1.4-5 ; `CHAPTERS.md` ch. 11.4, 12.1, 15.2.
- **Problèmes relevés :**
  - Au ch. 11, Ysaline « sonne la Cloche Mère » **au sommet du Mont Mémoria**. Au ch. 15, la Cloche Mère est « suspendue » **au sommet du Pilier Céleste**, et la règle 1.1.4 exige qu'elle sonne *depuis le clocher*. On ne dit nulle part comment ni quand elle a été déplacée, ni qui l'a hissée au sommet d'une tour qui exige le Vélo Cross.
  - Au ch. 12, il y a « 5 cloches sur 7 ». Le joueur a pourtant désaccordé F1, F2, F3, F4 (et New Lavandia s'il l'a faite). Les 5 cloches accordées sont donc des cloches **que le joueur ne voit jamais**, et ses délivrances ne font pas reculer la menace de manière visible.
  - Au ch. 15, « encore deux cloches » alors que F5 vient d'être délivrée et que F6 est active : le compte n'est pas suivi.
  - Au ch. 11, le sommet « ne peut pas être délivré » sans règle qui l'explique, alors que le joueur a le Diapason en main.
  - Absol arrive « la veille » parce qu'il sent le tintement (`WORLD` 1.1.6), mais R5 dit qu'**Augure l'a envoyé**. Deux causes pour le même fait : R5 affaiblit R2 au lieu de l'approfondir.
- **Impact joueur :** l'antagoniste paraît incohérent (C4), et le joueur ne sent pas qu'il gagne ou perd du terrain. Ses actions ne pèsent rien.
- **Correction :** (a) le **compteur de cloches** devient un état visible : le Carnet affiche « Cloches accordées : n/7 » d'après les relevés de Pierre, chaque délivrance le fait baisser, chaque nouveau Figement le fait monter. (b) La Cloche Mère est déplacée au ch. 11 *sous les yeux du joueur* : après le combat Ysaline 1, des Carillonneurs l'emportent par la brume. Elle ne « disparaît » pas, elle part vers le clocher, ce qui donne au ch. 14-15 sa destination. (c) Une règle : un Figement de Cloche Mère ne se défait que par le grand glas (voir n°1). (d) Absol perçoit le tintement de lui-même, et Augure ne fait que **mettre le joueur sur sa route** (les visions) : deux mécanismes distincts.

### 6. MINEUR — Le choix d'Ysaline pour le Mont Chimnée n'est pas tranché
- **Où :** ch. 7.2.
- **Problème :** « Sans moi, Vermilava serait déjà cendre » laisse penser qu'elle a figé l'éruption *exprès*. Or le plan (règle 1.1.5) consiste à accorder des cloches pour tenir le compte. On ne sait pas s'il s'agit d'un acte de bonté ou d'un effet secondaire revendiqué après coup. Les deux lectures sont intéressantes, mais il faut en choisir une.
- **Correction :** effet secondaire revendiqué. Elle a accordé la cloche du volcan parce qu'elle était là ; l'éruption s'est figée par hasard. Elle s'en sert comme argument, et Adriane le lui fait remarquer : « Tu ne savais même pas. » Cela renforce le thème du déni.

---

## B. Lieutenants, rival, alliés

### 7. MAJEUR — Bourdon est un mannequin ; Tierce n'a d'arc que dans une quête facultative
- **Où :** `CHARACTERS.md` §12.1 ; `CHAPTERS.md` ch. 9, 12, 15 ; `WORLD.md` A2.
- **Problème :** l'arc de Bourdon est « fidèle jusqu'au bout ; s'efface », avec trois combats et une phrase de sortie. Son métier (horloger de Poivressel) n'est exploité nulle part, alors que le joueur traverse Poivressel au ch. 4. Il y a une contradiction de plus : il « s'efface à Atalanopolis » (CHARACTERS) mais au Pilier Céleste (CHAPTERS 15.1). L'arc de Tierce (doute, puis délivrance de l'Épave, puis départ) vit entièrement dans A2, qui est **facultative** : le joueur qui la saute ne voit jamais Tierce changer.
- **Impact joueur :** on retombe dans les « admins interchangeables » (LORE §6.2). Les deux lieutenants sont distingués par leurs attaques, pas par leur personnalité.
- **Correction :** (a) relier l'**horloge de Rosyères arrêtée à 4 h 12** (I1, aujourd'hui « effet parasite » sans propriétaire) à Bourdon. 4 h 12 est l'heure de la mort de sa femme, et il a réglé cette horloge lui-même, des années plus tôt, pour l'arrêter. Au ch. 4, sa boutique fermée à Poivressel porte la même heure. Au ch. 15, il remonte enfin l'horloge, par un PNJ de Rosyères au postgame, et le premier indice du jeu devient le dernier geste d'un lieutenant. (b) Rendre obligatoire le **cœur** de l'arc de Tierce : la scène où elle quitte Ysaline se joue dans le chemin principal (ch. 14, Pacifiville ou Chenal 131), et A2 n'en est que l'approfondissement.

### 8. MAJEUR — Le rival n'a pas d'arc jouable : quatre combats et une morale prononcée
- **Où :** `CHARACTERS.md` §2 ; `CHAPTERS.md` ch. 0, 4, 9, 10, 16.
- **Problème :** l'arc annoncé (admiration, puis doute devant le Xatu au ch. 11, puis compréhension) n'apparaît pas dans les chapitres : le rival est **absent** du ch. 11, et son « on préserve, c'est bien, non ? » n'est mis en scène nulle part. Sa compréhension finale arrive dans une réplique qui énonce le thème mot pour mot à la Route Victoire. Son axe thématique (« ce qui est enregistré ne disparaît jamais ») recouvre celui de Gaspard (« une ruine qu'on ne lit pas est une ruine qu'on perd ») et celui de Pierre (« les pierres gardent la mémoire ») : **trois personnages pour la même idée**.
- **Impact joueur :** le rival d'Émeraude, déjà réputé le plus plat de la série, le reste. La réplique de la Route Victoire sonne comme une morale de fin d'épisode.
- **Correction :** **figer le rival dans Atalanopolis (F6)**, appareil photo levé. Le joueur voit son ami pris dans l'instant qu'il admirait. Une fois délivré, il a « perdu » trois jours et ses photos de la ville figée sont floues ou vides. Sa réplique finale devient alors une expérience vécue par les deux personnages. Différencier les trois axes : le rival = **enregistrer** (et découvrir qu'une photo n'est pas l'instant) ; Gaspard = **comprendre** (et accepter de ne pas tout garder) ; Pierre = **mesurer**, le scientifique qui n'a pas besoin d'arc.

### 9. MAJEUR — La révélation « Spectra petite-fille d'Ysaline » est un gadget qui crée un trou
- **Où :** `CHARACTERS.md` §7, §16 ; `CHAPTERS.md` ch. 11.1 (photo), ch. 16.2 ; `GAME_DESIGN_BIBLE.md` §13.
- **Problème :** un seul indice (une photo dans une alcôve), une seule réplique en retour (« Grand-mère m'a écrit. Merci. »), aucune conséquence. Pire, la révélation **ouvre une question** que le jeu ne traite pas : pourquoi une membre du Conseil 4, formée au Mont Mémoria dans le canon, n'a-t-elle rien fait pendant que sa grand-mère figeait une ville ? Le fan qui connaît Spectra se la posera aussitôt.
- **Impact joueur :** un clin d'œil, pas une émotion. On a coché la case « lien familial » sans l'exploiter.
- **Correction :** donner un **rôle actif** à Spectra. Au ch. 11, elle est au pied du Mont Mémoria et ne peut pas monter : la brume repousse ceux qu'Ysaline connaît. Elle confie au joueur une lettre pour sa grand-mère, sans dire son lien. Au ch. 15, c'est cette lettre que le joueur peut remettre avant ou après le Diapason, et elle fait partie du déclencheur (voir n°3). Au Conseil 4, la réplique paie un geste que le joueur a fait lui-même. Si le budget ne le permet pas, **supprimer** le lien familial plutôt que le garder décoratif.

### 10. MAJEUR — Gaspard tient le rôle d'allié-explicateur ; son défaut ne vit que dans une quête annexe
- **Où :** `CHARACTERS.md` §6 ; ch. 1, 5, 13, 14-15 ; `WORLD.md` A4.
- **Problème :** il donne le Diapason et le Carnet, lit le Braille, attend à l'entrée de Fondmer, suit le joueur au Pilier. Son défaut (sacrifier un site pour un savoir) n'apparaît que dans A4, qui est facultative, et son renoncement final tient en une ligne au ch. 15. Il y a aussi deux incohérences : on présente Gaspard comme le lecteur de Braille, mais au ch. 1 il « ne sait pas encore lire » le motif, et c'est Pierre qui lit le premier au ch. 3. Et pourquoi Gaspard, qui détient le Diapason et sait se battre (combat au ch. 1), ne délivre-t-il pas lui-même le bois ?
- **Impact joueur :** un distributeur d'objets clés et de traductions, la définition même de « l'allié qui n'existe que pour expliquer ».
- **Correction :** (a) une raison de jeu au ch. 1 : il a tenté le combat et perdu, et son équipe est K.O. à l'entrée. Le joueur le remplace, et Gaspard le reconnaît. (b) Mettre son défaut **dans le chemin principal** : à Fondmer (ch. 13), il veut détacher un panneau de Braille pour le Musée, et le joueur choisit de le laisser faire ou non. Le choix a un effet sur A1 (l'exposition corrigée cite la fresque *in situ* ou la plaque arrachée). (c) Son renoncement au ch. 15 répond alors à ce choix.

### 11. MAJEUR — Marc (Wallace) est réduit à un panneau indicateur ; Norman et Maman sont absents de la crise
- **Où :** `CHARACTERS.md` §4, §5, §14 ; ch. 8.2 (« si le joueur rentre ») ; ch. 14.2.
- **Problème :** les fans aiment Marc, et il n'a ici qu'une fonction : dire « le Pilier est un clocher » et ouvrir la porte. Son mentor Juan est figé, sa ville aussi, et il ne réagit pas. Norman, père du joueur, ne commente jamais les Figements. La scène de Maman sur la grand-mère, le seul lien personnel entre le joueur et Ysaline, est **facultative**.
- **Impact joueur :** le monde ne réagit pas à la crise (critique LORE §6.2). Le « mystère personnel lié au mystère régional » (leçon 3) est disponible mais caché derrière un détour.
- **Correction :** (a) la scène de Maman devient **obligatoire** : Norman remet Surf *à la maison* au ch. 8 et Maman raconte. (b) Marc a une scène d'impuissance (il ne peut pas entrer dans sa propre ville) et un **combat en duo** au Chenal 131 contre Carillonneurs ou Bourdon, en écho au duo avec Pierre. Cela réutilise le dispositif du ch. 12 sans coût de script nouveau. (c) Norman, au ch. 8 : une réplique sur Ysaline (« Elle a sonné pour ta grand-mère. Je n'ai jamais su la remercier. »).

### 12. MINEUR — Rocheval : arc correct mais convenu ; deux incohérences ; le mot « éliminer »
- **Où :** `CHARACTERS.md` §10 ; ch. 6, 10, 14.
- **Problèmes :** l'arc annonce la « confrontation aux preuves (ch. 11) », alors qu'elle a lieu au ch. 10. Il dit que ses Veilleurs « évacuent Atalanopolis », impossible puisque la ville est figée (ch. 14 : ils gardent Pacifiville). « Éliminer les Absol de Hoenn » est trop sombre pour le registre fixé (« jamais gore ») et contredit les **cages** du repaire. Enfin, frère mort, catastrophe, honte, rédemption : l'arc est solide mais attendu, et son revirement passe seulement par les preuves que le joueur apporte.
- **Correction :** corriger les deux références. Remplacer « éliminer » par « capturer et chasser hors de Hoenn ». Ajouter une nuance non convenue : Rocheval *avait raison* sur un point, Absol porte bien des nouvelles terribles, et il en garde un comme sentinelle au postgame.

### 13. MINEUR — Pierre et le Prof. Seko : incohérences de rôle
- Le Prof. Seko est censé formuler la règle « plus aucune rencontre » au ch. 1 (`CHARACTERS.md` §3, indice I3), mais aucune scène de Seko n'existe au ch. 1 de `CHAPTERS.md`.
- La fausse piste « Devon / projet Résonance » (`WORLD.md` §3.3) n'existe pas dans `CHAPTERS.md` : c'est une piste orpheline.
- Le synopsis (bible §4) dit que *Gaspard* demande de porter le fragment à Pierre ; `CHAPTERS.md` ch. 2 dit que c'est *M. Rochard*. Même écart pour les « Carillonneurs qui couvrent la retraite » au ch. 5.
- **Correction :** harmoniser les quatre documents. Une passe de cohérence entre bible, personnages et chapitres est nécessaire avant la rédaction des dialogues.

---

## C. Structure, rôle du joueur, ton

### 14. MAJEUR — La boucle « Absol la veille, zone figée, Carillonneurs, Dominant, Diapason, phrase reprise » se répète six fois
- **Où :** F1, F2, F3, New Lavandia, F4, F5 (`CHAPTERS.md` ; `WORLD.md` §1.2).
- **Problème :** les variations portent sur la **contrainte d'accès** (évacuation, rideau de pluie, marée), pas sur la **forme de l'expérience**. Les cloches-pivots se répètent : Archéomire ×2, Archéodong ×2 (×3 en comptant Ysaline). La fin est toujours la même : flash, musique, PNJ qui finit sa phrase, gag charmant la première fois et prévisible la quatrième. Absol « la veille » devient une case à cocher. Les deux Figements qui changent la règle (le sommet, Atalanopolis) sont des Figements que le joueur **ne peut pas** délivrer : la variation passe par le retrait d'agentivité.
- **Impact joueur :** une lassitude probable au milieu de l'acte II (F4). L'émerveillement du ch. 1 s'use.
- **Correction (au moins trois des quatre) :**
  - **Un Figement vécu de l'intérieur pendant sa formation** : au ch. 9, le joueur entend le tintement de 4 secondes *en direct*, voit le monde se figer autour de lui et doit atteindre l'Institut avant d'être pris (sortie forcée sinon, sans game over).
  - **Un Figement qu'on peut choisir de ne pas délivrer** : à New Lavandia, un vieil Électrode en fin de vie s'est blotti contre la cloche, et le délivrer, c'est le laisser mourir. Délivrer ou non, le choix change la récompense et une ligne du rival ou d'Ysaline (voir n°15).
  - **Un propriétaire humain par Figement** (voir n°2) : le combat final n'est pas toujours le Dominant, parfois le Carillonneur qui « possède » l'instant, ou les deux en combat double.
  - **Varier la conclusion** : une fois sur deux, pas de phrase reprise mais une conséquence (la lave tombe, la marée submerge un objet, la pluie inonde la route).

### 15. MAJEUR — Le joueur est un témoin : ses rares choix sont factices ou facultatifs
- **Où :** `CHARACTERS.md` §1 ; ch. 4.3 (multichoice), ch. 11.3 (« pas d'acceptation possible »), ch. 15.4 (« seule action proposée ; le jeu attend »).
- **Problème :** l'inventaire des choix réels est court. Accueillir Absol ou non. Deux preuves ou trois. A4 (fossile). L'ordre de quelques délivrances. La réponse du ch. 4 n'est que **cosmétique** (elle change une réplique). Le refus du ch. 11 est imposé. Le geste final (tendre le Diapason) est le seul possible. La bible l'assume (« le refus est l'unique issue, mais il est dit par le joueur »), mais un refus sans alternative n'est pas une décision, c'est une réplique. L'invariant 6 (Ysaline sonne elle-même) est juste, mais rien n'empêche que le *chemin* pour y arriver dépende du joueur.
- **Impact joueur :** C3 plafonne. Le joueur « lit » (rôle annoncé) mais ne pèse pas. Les moments forts sont regardés.
- **Correction :** introduire **deux ou trois choix à conséquence persistante**, sans mauvaise fin :
  - au ch. 11, autoriser **l'acceptation** : le joueur dit oui, Ysaline sonne, son Pokémon de tête (ou « ce moment ») est figé pendant le combat Ysaline 1, et il combat sans lui. Le refus reste la voie normale, mais l'acceptation devient une vraie tentation punie mécaniquement, ce qui vaut mieux qu'un faux choix ;
  - le choix de New Lavandia (voir n°14) et celui de Gaspard à Fondmer (voir n°10) ;
  - au ch. 15, le déclencheur de l'acceptation d'Ysaline puise dans ce que le joueur a fait : la réponse du ch. 4, la lettre de Spectra, le nombre de Carillonneurs convaincus, et chaque élément ajoute une réplique. Le résultat reste le même, mais il est construit par le joueur.

### 16. MAJEUR — Le moment le plus fort (la mort d'Augure) est une cinématique où le joueur n'est même pas présent
- **Où :** ch. 15.4-15.5 (« enchaînement court de fondus », « Le joueur est ramené par fondu »).
- **Problème :** sonner le glas, voir Hoenn repartir, la mort d'Augure à l'aube : tout passe par des fondus. Le joueur ne marche jamais dans le sommet du Mont Mémoria qui se délivre. Le transport d'Ysaline et du joueur du Pilier au Mont Mémoria n'est pas expliqué. EXPERIENCE_INTENT §9.2 C3 nomme exactement ce défaut comme ancre basse (« émotion uniquement en cinématique »).
- **Impact joueur :** l'émotion est montrée, pas produite.
- **Correction :** (a) **le glas se joue** : le joueur reconstitue la mélodie dans un `multichoice` de notes, à partir des fragments réunis dans le Carnet (Braille de Fondmer et de la Cloche Mère). L'enquête de 15 heures devient la clé du dénouement, et une erreur fait juste rejouer (pas d'échec). (b) Le joueur **marche** dans le sommet qui se délivre (Vol vers le Mont Mémoria, montée dans la brume qui se lève carte par carte). (c) Si Absol est dans l'équipe, il sort de sa Poké Ball et se couche près d'Augure : le choix du ch. 6 paie au ch. 15. (d) Augure regarde le joueur une dernière fois, et le joueur choisit de rester jusqu'au lever du soleil ou de partir. Dans les deux cas Augure s'éteint, mais le joueur aura décidé où il se tient.

### 17. MAJEUR — Saturation du deuil ; l'humour est promis mais pas écrit
- **Où :** bible §2 (« Humour par les PNJ ordinaires ») ; `CHARACTERS.md` §10-12, §16 ; `WORLD.md` §4 (Lavandia, « humour sur le Casino éteint »).
- **Problème :** l'inventaire des personnages endeuillés est le suivant : Ysaline (Xatu), chaque Carillonneur (une ligne de perte **chacun**, soit plusieurs dizaines), Bourdon (veuf), Tierce (mère), Rocheval (frère), le joueur (grand-mère), Aragon (naufrage), le fantôme de l'Épave, Spectra, le vieux couple. Pour l'humour, on compte deux occurrences planifiées (l'infirmière et ses piles, les ouvriers qui finissent leur phrase) plus une mention (le Casino). Pour un public Pokémon, dont une partie a 10-14 ans, trente phrases de deuil en combat finissent par sonner comme une routine, ce qui dilue le vrai deuil d'Ysaline.
- **Impact joueur :** monotonie de ton et anesthésie émotionnelle avant le climax. Le « lumineux » de « aventure lumineuse traversée de mélancolie » n'existe pas dans le texte prévu.
- **Correction :** (a) limiter les lignes de perte aux **Carillonneurs nommés** (un par Figement, voir n°2). Les autres parlent d'**attente**, de **routine**, voire d'absurde (« J'ai figé mon thé à la bonne température. Ne me jugez pas. »). (b) Prévoir un **personnage comique récurrent** : le rival photographe (ses ratés, ses photos floues des Figements), ou un Veilleur maladroit qui devient fan d'Absol après R2. (c) Prévoir **des chapitres-respirations sans Figement** : ch. 8 (retour à la maison) et ch. 10 (Nénucrique : Concours, Grand Magasin) doivent contenir au moins une scène légère scriptée chacun. (d) Les Figements eux-mêmes peuvent être drôles : un Ronflex figé en plein bâillement, un dresseur figé en pleine pose de victoire.

### 18. MAJEUR — La fausse piste « Absol coupable » est connue des fans et dure 10 heures
- **Où :** `WORLD.md` §3.3 ; ch. 1 à 10.
- **Problème :** le Pokédex de Rubis/Saphir dit déjà qu'Absol *prévient* les catastrophes, et tout fan le sait. Le jeu fait jouer au joueur une enquête dont il connaît la réponse depuis le ch. 1, puis lui fait réunir des preuves pour convaincre des PNJ. LORE §6.2 avertit justement contre les retournements prévisibles.
- **Impact joueur :** R2 n'est pas une révélation, c'est une formalité. Le « Mon frère… » de Rocheval porte, mais seulement pour Rocheval.
- **Correction :** assumer que le joueur sait, et retourner la question. Le vrai mystère d'Absol devient « **pourquoi suit-il le joueur ?** » (R5, posée dès le ch. 1 au lieu du ch. 11). Réduire R2 à un enjeu de *conviction des autres* (gameplay de preuves, déjà bon) et avancer sa résolution au ch. 8-9. Le ch. 10 libère alors de la place pour une scène Spectra ou une scène de respiration.

### 19. MINEUR — Quêtes annexes : A5 est du remplissage ; A1 et A2 portent un contenu qui devrait être principal
- **A5 « Avis d'alerte »** : « convaincre 6 PNJ » = 6 dialogues de livraison sans mécanique. **Correction :** la fusionner avec A2 ou la supprimer, ou en faire une chasse où l'on retrouve 6 Absol sauvages relâchés des cages du repaire, ce qui donne un usage concret aux cages.
- **A1 « L'Exposition »** : retour au musée pour voir un texte modifié. C'est un bon payoff de Q4, mais il ne déclenche ni combat, ni choix, ni personnage. **Correction :** la Directrice défend sa lecture, et le joueur la contredit avec les fragments du Carnet (un `multichoice` de citations) ; brancher le choix de Gaspard (n°10).
- **A2 et A4** portent les arcs de Tierce et de Gaspard (voir n°7 et n°10) : les remonter dans le chemin principal.

### 20. MINEUR — Occasions de rappels non exploitées
- La **réponse du ch. 4** (mon Pokémon / ma famille / ce moment / rien) ne sert qu'au ch. 11. Elle pourrait aussi colorer une ligne du rival à la Route Victoire, la dernière réplique d'Ysaline et l'épilogue (« rien » : Ysaline rit pour la première fois, « Menteur. »).
- **Peeko** (premier être délivré) : il pourrait survoler le Chenal 131 au ch. 14, et M. Marcel offrir la traversée symbolique vers le Pilier.
- **L'horloge de la chambre** du joueur (« première image du thème ») n'est jamais reprise : à l'épilogue, elle pourrait avoir pris du retard, et le joueur la remet ou non à l'heure. C'est la dernière action du jeu, un geste d'acceptation.
- **Aragon** « a connu le naufrage » : aucune scène ne paie ce lien. Une ligne post-combat liée à Tierce si A2 est faite.
- **Ressemblances que les fans repéreront :** les zones où le temps s'arrête rappellent fortement les **Engrenages du Temps** de *Donjon Mystère : Explorateurs du Temps*, et le combo Regis + civilisation ancienne rappelle *Pokémon Gaia* (LORE §6.3). Ce n'est pas rédhibitoire, mais un PNJ conteur peut évoquer « d'autres régions où le temps s'est arrêté » pour assumer l'écho plutôt que de le subir.

---

## D. Synthèse des priorités
1. **Avant tout dialogue :** n°1 (règle du glas), n°2 (motivation des Carillonneurs), n°5 (compteur de cloches et trajet de la Cloche Mère), n°13 (passe d'harmonisation des documents).
2. **Avant la tranche verticale :** n°15 et n°16 (agentivité, glas joué), n°14 (variation des Figements), n°3 (fissures d'Ysaline), n°8 (rival figé).
3. **Pendant la rédaction :** n°17 (humour), n°7, n°9, n°10, n°11 (seconds rôles), n°19-20.

---

## E. Notes sur la grille EXPERIENCE_INTENT §9.2

| Critère | Note | Justification |
|---|---|---|
| **C3 — Force émotionnelle** | **2 / 5** | Quelques beaux moments *vécus* : délivrer Peeko, l'escorte d'Absol blessé, l'évacuation de Vermilava puis la pluie de cendres sur un village intact. Mais les trois sommets émotionnels sont regardés. La mort d'Augure passe par fondus, sans le joueur sur place. Le glas consiste à tendre un objet, avec une seule action possible. La révélation Spectra tient en une réplique. Les choix sont factices (refus imposé au ch. 11) ou cosmétiques (réponse du ch. 4). La saturation du deuil (des dizaines de lignes de perte) émousse le vrai deuil. C'est l'ancre basse de §9.2 (« émotion uniquement en cinématique ») légèrement dépassée. Avec les n°15-16 appliqués (glas joué depuis le Carnet, acceptation possible au ch. 11, Absol près d'Augure), la note passe à 4. |
| **C4 — Profondeur de l'antagoniste** | **3 / 5** | Les points forts sont réels. La motivation est intime et défendable (un Xatu de 60 ans qui meurt). L'ironie du métier (celle qui aide à laisser partir ne peut pas laisser partir) est excellente. La signature mécanique est exemplaire : Distorsion, Requiem et Prescience comme « temps tordu », jamais de Méga, et des zones sans rencontres comme trace dans les règles. Mais la cohérence est fragile. Le glas que joue son métier contredit l'intrigue (n°1). Sa faction n'a pas de raison de la suivre (n°2). Les règles du carillon ne tiennent pas (n°5). Le basculement est déclenché par une vision après défaite (n°3). Les crimes envers des innocents restent sans conséquence (n°4). Ses lieutenants sont minces (n°7). Une seule de ces failles suffit à faire dire « méchant par fonction » à un joueur exigeant. Avec n°1, n°2 et n°3 corrigés : 4,5. |
| **C1 — Originalité** | **3 / 5** | La prémisse « des lieux figés à délivrer, une antagoniste en deuil qui veut arrêter le temps pour un Pokémon » est fraîche dans le corpus des ROM hacks. Elle change vraiment la façon de jouer : donjons d'attrition sans rencontres, et la délivrance qui rend les rencontres. Mais (a) la structure calque un à un les événements d'Émeraude (table §17 : chaque intervention Aqua/Magma est remplacée à la même place, sur la même carte) ; (b) le « temps arrêté par endroits » rappelle les Engrenages du Temps de Donjon Mystère, et Regis + peuple ancien rappelle Pokémon Gaia ; (c) l'innocence d'Absol est un fait canonique connu de tous ; (d) le Dominant reprend les Totems de Soleil/Lune. Les ingrédients sont originaux pour un ROM hack, mais leur agencement est prévisible pour un fan. Une variation réelle de la boucle des Figements (n°14) et un rival figé (n°8) feraient passer la note à 4. |
