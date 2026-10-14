# Bible — Scénario chapitre par chapitre (*Pokémon Heure Suspendue*)

> Partie de `GAME_DESIGN_BIBLE.md`. Toute modification passe par le GMD.
> Notation : cartes par constante `MAP_*` (préfixe parfois omis) ; **F#** = Figement n° ; **R#** = révélation (voir `WORLD.md` §3) ; **[V]** = événement vanilla conservé tel quel ou presque ; **[R]** = événement vanilla réécrit ; **[N]** = événement nouveau sur carte existante.
> Chaque chapitre donne : objectif, séquence (mission), espace (cartes), serrures/clés, combats, indices, ce que le joueur sait en sortant. Les dialogues ne sont pas écrits ici : intentions et contenus obligatoires seulement (rédaction : agents texte, ≤ 208 px/ligne).

---

## 0. Prologue — « L'horloge de Rosyères » (0:00–0:40)

**Objectif :** starter, Pokédex, choix du mode, première question.
**Cartes :** `INSIDE_OF_TRUCK`, `LITTLEROOT_TOWN` (+ maisons, `PROFESSOR_BIRCHS_LAB`), `ROUTE101`, `OLDALE_TOWN` (+ `POKEMON_CENTER_1F`), `ROUTE103`.

1. [V] Camion, maison, horloge de la chambre (le joueur règle l'heure : première image du thème).
2. [V] Route 101 : Seko attaqué par un Medhyèna ; choix du starter dans son sac.
3. [R] Labo : Pokédex ; Seko demande « Comment veux-tu voyager ? » → **mode Normal / Expert** (`B_VAR_DIFFICULTY`, H2). Seko : « Ma fille/mon fils est sur la Route 103. »
4. [N] Rosyères, Centre Pokémon : l'horloge murale est arrêtée à 4 h 12 depuis la nuit ; l'infirmière rit (« sûrement les piles »). Un vieux PNJ dehors : « Il paraît qu'un bois ne bouge plus, vers Clémenti. » (**Q1 posée**.)
5. [V] Route 103 : combat {RIVAL} 1 ; [R] {RIVAL} montre comment capturer et remet 5 Poké Balls (remplace le tutoriel de Timmy) ; il veut « tout photographier ».
**Sortie :** le joueur sait qu'il se passe quelque chose d'étrange avec le temps ; aucun nom.

## 1. Acte I — Ch. 1 « Le bois qui ne bouge plus » (0:40–1:40)

**Objectif :** apprendre la règle du Figement et le Diapason (tutoriel F1).
**Cartes :** `ROUTE102`, `PETALBURG_CITY` (+ `GYM`), `ROUTE104` (sud), `ROUTE104_MR_BRINEYS_HOUSE`, `PETALBURG_WOODS`, `ROUTE104` (nord).

1. [R] Clémenti : visite à Norman (vanilla : « reviens avec 4 badges ») ; la scène de Timmy est supprimée.
2. [N] Route 104 sud, sur un rebord : **Absol** observe le joueur puis s'enfuit (première apparition, « la veille »). Un pêcheur : « Un Absol ! Ça porte malheur. » Panneau neuf : **avis de recherche** des Veilleurs.
3. [R] Maison de M. Marcel : il est désespéré, Peeko est parti vers le bois et n'est pas revenu.
4. [N] Entrée du Bois Clémenti : **Gaspard** (ruinemaniaque). Combat d'entraînement facultatif. Il a vu l'intérieur : « Rien ne bouge, pas même les Chenipan. »
5. [N] **F1 — Bois Clémenti figé** (moitié nord de `PETALBURG_WOODS`, au-delà du tronc central) : brume/ombre, promeneurs immobiles (une famille en pique-nique, un Scout au filet levé), objet suspendu (Super Bonbon en l'air), Peeko figé en plein vol. **Aucune rencontre** dans la zone figée (N1). Un Carillonneur novice patrouille avec un grelot (combat ; il dit « On n'a rien fait de mal. On a juste… arrêté. »).
6. [N] Cœur : **cloche-pivot Archéomire** figé (combat Dominant, `settotemboost` +1 Déf). Gaspard rejoint le joueur et lui confie le **Diapason** (objet clé) : « Fais-le vibrer près de la cloche. » Délivrance : flash, la musique reprend, Peeko s'envole vers la Route 104, le Super Bonbon tombe. Gaspard remet le **Carnet de Gaspard** (premier fragment : un grelot gravé d'un motif de Braille qu'il ne sait pas encore lire).
7. [N] Sortie nord : deux **Veilleurs** cherchent Absol (combats ; Poursuite apparaît au 2ᵉ).
8. [R] M. Marcel, Peeko rentré : « Je te dois une traversée. » (Bateau disponible **après le badge 1**.)
**Serrures :** nord du bois figé (serrure vue) → Diapason + cloche-pivot (clé). Bateau de M. Marcel → Peeko libéré + badge 1.
**Sortie :** Q1 précisée (des lieux se figent ; il existe une cloche au cœur) ; Q2 posée (Absol ?).

## 2. Ch. 2 « La pierre qui sonne » (1:40–2:30)

**Cartes :** `RUSTBORO_CITY` (+ `GYM`, `DEVON_CORP_1F-3F`, `POKEMON_SCHOOL`), `ROUTE116`, `RUSTURF_TUNNEL` (entrée ouest seulement).

1. [V] École Pokémon, magasin ; [V] Roxanne → **badge 1 (Coupe)**.
2. [R] Devon SA (remplace le vol des Pièges Devon) : Gaspard a déposé le grelot pour analyse. M. Rochard : alliage inconnu ; il remet le **PokéNav** [V] et une **lettre pour son fils Pierre**, à la Grotte Granite, ainsi que le grelot à porter au **Conservateur Morel**, au Musée Océanographique de Poivressel (remplace les Pièges Devon).
3. [N] Route 116 → Tunnel Mérazon : l'entrée ouest est bloquée par des rochers (serrure vue : Éclate-Roc) ; un ouvrier : « Depuis hier, on n'entend plus les Chuchmur de l'autre côté. » (annonce F2).
4. [R] Retour Route 104 : M. Marcel → Myokara.
**Serrures :** bateau (Peeko + B1). Tunnel Mérazon (Éclate-Roc, badge 3) vu dès maintenant.

## 3. Ch. 3 « Le son arrête » (2:30–3:20)

**Cartes :** `DEWFORD_TOWN` (+ `GYM`, `HALL`), `ROUTE106`, `GRANITE_CAVE_1F/B1F/B2F/STEVENS_ROOM`.

1. [V] Bastien → **badge 2 (Flash)**.
2. [R] Grotte Granite, salle de Pierre : on lui remet la lettre ; il examine le grelot. [N] Sur le mur, une **inscription en Braille** jamais remarquée ; Pierre et le joueur la lisent avec la grille du Carnet : « LE SON ARRÊTE ». Pierre : « Les pierres gardent la mémoire du temps ; elles ne l'arrêtent pas. Celle-ci, si. » [V] CT (Aile d'Acier ◐).
3. [R] M. Marcel → Poivressel (Routes 107-109).
**Indice :** Braille n°1 (Carnet).

## 4. Ch. 4 « Les grelots du marché » (3:20–4:20)

**Cartes :** `SLATEPORT_CITY` (+ `OCEANIC_MUSEUM_1F/2F`, `HARBOR`, marché), `ROUTE109`, `ROUTE110`, (`TRICK_HOUSE` facultatif).

1. [R] Musée Océanographique (remplace l'invasion Aqua) : le **Conservateur Morel** analyse le grelot : il « sonne » sans être frappé, très faiblement, toujours sur la même note. Il compare avec un objet de la collection : une **cloche votive** repêchée près du Chenal 134 (Sanctuaire) — même alliage. (Indice R1/R4.)
2. [N] Marché : **rassemblement des Veilleurs** (Rocheval en tribune, PNJ ; pas de combat) : « Chaque fois qu'un Absol rôde, un malheur suit. » Avis de recherche.
3. [N] Au marché, une **vieille dame vend des grelots** : **Ysaline**. Elle se présente (« Ysaline, je sonne les cloches au Mont Mémoria »), demande au joueur : « Qu'est-ce que tu refuserais de perdre ? » (`multichoice` : mon Pokémon / ma famille / ce moment / rien) — la réponse est gardée en var et **reprise par elle au ch. 11**. Elle ne parle ni de Figements ni de cloches anciennes.
4. [V] Route 110 : {RIVAL} 2 ; [N] la nuit (ou à la sortie nord), Absol sur la piste cyclable, il regarde vers l'ouest (Vergazon).
**Sortie :** le joueur a vu Ysaline sans raison de la soupçonner ; Absol continue d'« annoncer ».

## 5. Ch. 5 « Le tunnel muet » — climax de l'acte I (4:20–6:00)

**Cartes :** `MAUVILLE_CITY` (+ `GYM`, maisons), `ROUTE117`, `VERDANTURF_TOWN`, `RUSTURF_TUNNEL`.

1. [R] Lavandia : la ville tourne sur générateurs de secours (dialogues ; la panne de New Lavandia est **mentionnée** : « La centrale ne répond plus », quête facultative ouverte au ch. 8). [V] Voltère → **badge 3** ; [V] CT Éclate-Roc (maison).
2. [N] Vergazon : une habitante a vu Absol la veille près du tunnel. Les Chuchmur du village sont agités.
3. [N] **F2 — Tunnel Mérazon figé** (depuis l'entrée est) : ouvriers immobiles, Chuchmur figés en plein cri (le cri est la « note » de la cloche), objets suspendus. Carillonneurs (Prescience introduite). **Tierce** (combat ; Requiem n'est **pas** encore utilisé ; elle a Abri).
4. [N] Cœur : **Ysaline**, la main sur une cloche ancienne enchâssée dans la roche. Elle ne fuit pas. « Ils ne souffrent pas. Ils attendent. » Elle explique peu : « Il me manque quelques cloches à accorder. » Elle sort par un passage (rochers déplacés). **Révélation R1** : les Figements sont sonnés par des humains, avec des cloches anciennes.
5. [N] Cloche-pivot **Korillon** Dominant ; délivrance ; les ouvriers reprennent leur phrase interrompue (« …et donc on arrête pour les Chuchmur ! »). Le passage vers Mérouville est dégagé (raccourci).
6. [N] Gaspard arrive par l'ouest : il relève l'inscription de la cloche (Braille n°2 : « CE QUE NOUS AIMONS NE PASSERA PAS »).
**Sortie :** Q3 posée (pourquoi Ysaline ?) ; Q2 reste ouverte (les Veilleurs insistent : « Absol était là la veille ! »).

---

## 6. Acte II — Ch. 6 « La traque » (6:00–7:40)

**Cartes :** `ROUTE111` (sud), `ROUTE112`, `ROUTE112_CABLE_CAR_STATION`, `FIERY_PATH` (facultatif), `ROUTE113`, `ROUTE113_GLASS_WORKSHOP`, `FALLARBOR_TOWN` (+ `COZMOS_HOUSE`), `ROUTE114`, `METEOR_FALLS_1F_1R/1F_2R/B1F_1R`.

1. [R] Route 112 : des **Veilleurs barrent le téléphérique** (remplace les sbires Magma) : « La bête est montée au volcan, personne ne passe. » Le désert (Route 111 nord) est bloqué par la tempête : serrure vue (Lunettes Sable).
2. [V] Route 113 (cendres : le volcan fume depuis des semaines — explication donnée à l'atelier de verre) ; Autéquia ; [N] **Prof. Cosmo** : « J'ai vu l'Absol avant-hier. Le lendemain, plus aucune secousse du volcan. Plus *rien*. » (indice R2).
3. [N] Route 114 : Veilleurs en battue.
4. [R] Site Météore (remplace le vol de la météorite par Magma) : Absol blessé, acculé par les Veilleurs. **Escorte** : Absol devient **PNJ suiveur** jusqu'à `METEOR_FALLS_B1F_1R` ; deux combats de Veilleurs ; **Rocheval 1** (cap 29, signature Poursuite). Rocheval cède : « Tu protèges ce qui nous tue. » Il retire le barrage.
5. [N] Absol se laisse approcher : **don facultatif** (`givemon`, oui/non). S'il est refusé, il reste aux étapes clés.
**Serrures :** téléphérique (barrage Veilleurs) → événement du Site Météore.
**Sortie :** le joueur a des doutes sur la culpabilité d'Absol (Cosmo, escorte).

## 7. Ch. 7 « L'éruption suspendue » (7:40–9:00)

**Cartes :** `ROUTE112_CABLE_CAR_STATION`, `MT_CHIMNEY_CABLE_CAR_STATION`, `MT_CHIMNEY`, `JAGGED_PASS`, `LAVARIDGE_TOWN` (+ `GYM_1F/B1F`, maisons).

1. [N] **F3 — Mont Chimnée figé** : au cratère, une **colonne de lave figée en plein jet** (re-habillage par objets/PNJ + `WEATHER_VOLCANIC_ASH` bloqué), randonneurs figés en pleine fuite. Carillonneurs (Distorsion **non** encore ; Prescience, Vœu).
2. [N] Ysaline, brièvement, sur le bord : « Sans moi, Vermilava serait déjà cendre. Délivre, et regarde. » Elle part par le Chemin Ardent. (Colère.)
3. [N] Mission de **préparation** : descendre par le Chemin Ardent à Vermilava, prévenir **Adriane**, faire évacuer 5 habitants (PNJ à convaincre, dont un herboriste qui demande un objet) — les PNJ disparaissent par flags et réapparaissent sur la Route 112.
4. [N] Retour au sommet (téléphérique), cloche-pivot **Archéodong** Dominant ; délivrance : l'éruption reprend, **pluie de cendres** (scène), Vermilava est vide et intacte. Adriane : « Elle avait raison sur un point. Elle avait tort sur tout le reste. »
5. [V] Adriane → **badge 4 (Force)**. [V] {RIVAL} remet les **Lunettes Sable** (ouvre Route 111 nord : Tour Mirage, Ruines Désert facultatifs).
**Sortie :** le joueur sait que figer peut *aussi* protéger ; nuance morale posée.

## 8. Ch. 8 « La cloche de grand-mère » (9:00–10:00)

**Cartes :** `PETALBURG_CITY` (+ `GYM`), `LITTLEROOT_TOWN` (maison), `ROUTE110` (Surf), `NEW_MAUVILLE_ENTRANCE/INSIDE` (facultatif), `ROUTE108` / `ABANDONED_SHIP_*` (début de quête).

1. [V] Norman → **badge 5** ; [R] Norman remet lui-même la **CS Surf**.
2. [N] Maman (si le joueur rentre) : la grand-mère du joueur a été accompagnée au Mont Mémoria par « la sonneuse » ; « Elle sonnait si doucement. Tout le monde pleurait, et pourtant on se sentait plus léger. » (humanise Ysaline ; indice R3/R5).
3. [N] **Facultatif — F-opt1 New Lavandia figée** (quête de Voltère, `NEW_MAUVILLE_*`) : centrale figée **sans Absol aperçu** (Absol ne peut entrer sous terre) → **preuve clé pour R2**. Cloche-pivot Archéomire. Récompense : courant rétabli à Lavandia (dialogues), CT.
4. [N] **Quête « Le Dernier Quart »** s'ouvre à l'Épave (`ABANDONED_SHIP_DECK`) : un fantôme de marin répète l'heure du naufrage ; la suite exige Plongée (ch. 12).

## 9. Ch. 9 « La pluie suspendue » (10:00–11:40)

**Cartes :** `ROUTE118`, `ROUTE119`, `ROUTE119_WEATHER_INSTITUTE_1F/2F`, `FORTREE_CITY` (+ `GYM`), `ROUTE120`.

1. [N] Route 119 : la veille, Absol sur le pont ; puis **F4 — l'averse figée** : un rideau de gouttes immobiles barre la route au nord de l'Institut (objets/PNJ « pluie » bloquants ; la zone d'herbes est sans rencontres).
2. [R] Institut Météo (remplace l'occupation Aqua) : chercheurs figés ; Carillonneurs (Abri, Vœu) ; **Bourdon** 1 (Distorsion **montrée** par lui, sans l'imposer : il l'utilise une fois). Cloche-pivot **Éoko** Dominant au 2F. Délivrance : le directeur reprend sa phrase ; il remet les **relevés** : avant chaque Figement, un « tintement » de 4 secondes est enregistré, et **Absol était déjà là avant le tintement** (indice R2). [V] Morphéo offert.
3. [V] {RIVAL} 3 → **CS Vol**. Il admire les Figements (« des photos en vrai »).
4. [V] Cimetronelle : Kecleon invisible bloque l'arène → [V] Route 120 : Pierre remet le **Scope Devon** ; [V] Alizée → **badge 6 (Vol)**.
5. [N] Route 120 : le Tombeau Antique (serrure vue pour le postgame) porte du Braille illisible sans le Sanctuaire.

## 10. Ch. 10 « Le repaire des Veilleurs » (11:40–12:50)

**Cartes :** `ROUTE121`, `LILYCOVE_CITY` (+ `LILYCOVE_MUSEUM_1F/2F`, `DEPARTMENT_STORE_*`, `ROOFTOP`, `HARBOR`), `AQUA_HIDEOUT_1F/B1F/B2F` (re-habillé en **repaire des Veilleurs**).

1. [N] Musée de Nénucrique : **exposition officielle** sur le peuple du Sanctuaire : « Ils scellèrent les Regis par peur de ces monstres. » (fausse lecture vue — serrure de la quête « L'Exposition »).
2. [V/R] Toit du Grand Magasin : {RIVAL} 4.
3. [N] Le joueur réunit **trois preuves** (vérifiées par flags) : témoignage de Cosmo (ch. 6), relevés de l'Institut (ch. 9), et au choix New Lavandia sans Absol (ch. 8) **ou** la page du Pokédex d'Absol (consultée devant le PNJ archiviste). Deux preuves suffisent ; trois débloquent un dialogue supplémentaire de Rocheval.
4. [R] **Repaire des Veilleurs** (Planque Aqua) : cages vides, cartes des « veilles » d'Absol annotées ; Veilleurs (pièges, Poursuite, Piège de Roc) ; **Rocheval 2** (cap 38). Après le combat, le joueur présente les preuves : **Révélation R2 — Absol prévient, il ne provoque pas.** Rocheval : « Mon frère… Absol était venu nous avertir. » Il dissout la traque ; les avis de recherche deviennent des avis d'**alerte** (« Si vous voyez un Absol, éloignez-vous : quelque chose va arriver »).
5. [N] Rocheval : « La vieille sonneuse est passée par ici. Elle allait au Mont Mémoria. »

## 11. Ch. 11 « Le sommet immobile » — climax de l'acte II (12:50–14:00)

**Cartes :** `ROUTE122`, `MT_PYRE_1F`–`6F`, `MT_PYRE_EXTERIOR`, `MT_PYRE_SUMMIT`.

1. [R] Intérieur du Mont Mémoria : tombes, Carillonneurs endeuillés (une phrase de perte chacun ; **Distorsion** utilisée systématiquement : l'examen arrive). Une **photo** dans une alcôve : une jeune Ysaline avec une fillette (Spectra — indice du coda).
2. [R] Extérieur : le **vieux couple** (remplace les Gemmes) : la **Cloche Mère**, qu'ils gardaient, a disparu ; Ysaline était leur élève : « Elle sonnait le glas mieux que nous. »
3. [N] Sommet : **brume immobile**, un Xatu très âgé figé face au soleil levant. Ysaline à ses côtés. **Révélation R3** : « Augure a soixante ans. Il voit l'avenir. Il a vu sa fin. Moi, je ne la verrai pas. » Le carillon de Hoenn, une fois accordé, figera ce sommet pour toujours. **Marchandage** : elle reprend la réponse du ch. 4 (« Tu m'as dit que tu refuserais de perdre… ») et propose de figer cela pour le joueur. Refus (le joueur choisit sa phrase ; pas d'acceptation possible).
4. [N] **Ysaline 1** (cap 38 ; Distorsion, Requiem, Prescience). Après le combat, elle sonne la Cloche Mère : le sommet reste figé, elle disparaît dans la brume. Le sommet **ne peut pas** être délivré (serrure finale vue).
5. [N] Au pied du Xatu : l'**Absolite** (objet suspendu qui, exceptionnellement, tombe quand le joueur s'approche — « comme si quelqu'un la lui tendait » : indice R5). **Vision** : « Un œil vers hier. Un œil vers demain. »
**Sortie :** Q3 résolue ; Q4 et Q5 au premier plan ; le joueur sait où tout finira.

---

## 12. Acte III — Ch. 12 « Le Centre Spatial » (14:00–15:20)

**Cartes :** `ROUTE124`, `MOSSDEEP_CITY` (+ `STEVENS_HOUSE`, `SPACE_CENTER_1F/2F`, `GYM`).

1. [R] Centre Spatial (remplace l'attaque Magma) : Pierre mesure les « ondes » du carillon avec les instruments du centre (Hoenn est presque accordé : 5 cloches sur 7). Bourdon et Tierce viennent voler les relevés. **Combat en duo** Pierre + joueur contre Bourdon + Tierce (vanilla : duo Pierre vs Max/Kelvin) ; **Pierre méga-évolue Métalosse** (introduction sûre du gimmick).
2. [N] Chez Pierre : **Méga-Bracelet** + leçon courte (une boîte : « Une seule par combat. Choisis le moment. »). Une Méga-Gemme au choix parmi deux (voir `WORLD.md` §5.3).
3. [N] Tierce, ébranlée : « Si elle refuse de perdre son Xatu… et moi, ma mère ? » (relance « Le Dernier Quart », complétable avec Plongée).
4. [V] Lévy & Tatia → **badge 7 (Plongée)**.

## 13. Ch. 13 « Ce que craignait le peuple » (15:20–17:00)

**Cartes :** `ROUTE125`, `SHOAL_CAVE_*` (marée basse), `ROUTE127`, `ROUTE128`, `UNDERWATER_ROUTE128`, `SEAFLOOR_CAVERN_ENTRANCE`, `SEAFLOOR_CAVERN_ROOM1`–`ROOM9`.

1. [N] **F5 — Grotte Tréfonds** : la marée est arrêtée à marée basse depuis trois jours (le vieil homme de l'entrée ne peut plus pêcher ; les cartes `HIGH_TIDE_*` ne sont plus accessibles). Puzzle : la salle de glace est atteignable seulement par le chemin de marée basse. Cloche-pivot **Archéodong**. Délivrance : les marées reprennent (accès normal aux deux états), Grelot Coque [V]. Carillonneurs (échec peu coûteux pour la Méga).
2. [R] **Caverne Fondmer** (remplace Aqua/Kyogre) : un **temple du peuple du Sanctuaire**. Carillonneurs (Requiem au complet). Murs en Braille (5 panneaux) : Gaspard attend à l'entrée ; le joueur relève les inscriptions et le Carnet les traduit.
3. [N] Salle 9 (ancien lieu de Kyogre) : la **fresque du peuple**. **Révélation R4** : après la colère des titans, le peuple a vu tout perdre en un jour. Il a construit des cloches pour arrêter le temps sur ce qu'il aimait : ses gardiens (les trois Regis, figés dans trois tombeaux), puis lui-même. « Nous devons tout aux Pokémon. Nous les avons figés. Nous en avions peur — peur de les perdre. » Le Braille donne la **première moitié du glas**, la mélodie inverse qui « laisse aller ». La seconde moitié « est gravée sur la cloche du clocher ».
4. [N] Sortie par plongée (Chenal 126) : en remontant vers le fond d'Atalanopolis, **Absol** attend sur un rocher. La ville est figée (on le voit en arrivant au ch. 14).

## 14. Ch. 14 « La ville dans le cratère » (17:00–18:20)

**Cartes :** `UNDERWATER_ROUTE126`, `UNDERWATER_SOOTOPOLIS_CITY`, `SOOTOPOLIS_CITY` (+ maisons), `CAVE_OF_ORIGIN_ENTRANCE`, `ROUTE131`, `PACIFIDLOG_TOWN`, `ROUTE131` (Pilier).

1. [R] **F6 — Atalanopolis entière figée** (remplace le combat des titans) : habitants immobiles au bord de l'eau, Juan figé devant l'arène, oiseaux suspendus. Pas de rencontres. Le joueur ne peut pas délivrer : la cloche n'est pas ici.
2. [R] Devant la Grotte Origine (zone préservée par les anciens), **Marc** : le peuple ancien protégeait cette grotte ; le **Pilier Céleste** n'est pas une tour mais leur **clocher**. Il ouvre l'accès (rôle vanilla). Les **Veilleurs de Rocheval** gardent Pacifiville et le Chenal 131 (dialogues ; soin offert à Pacifiville : point de repos avant la montée).
3. [R] Gaspard rejoint le joueur au Chenal 131 : **PNJ suiveur** dans le Pilier.

## 15. Ch. 15 « Le glas » — climax (18:20–20:00)

**Cartes :** `SKY_PILLAR_ENTRANCE`, `SKY_PILLAR_OUTSIDE`, `SKY_PILLAR_1F`–`5F`, `SKY_PILLAR_TOP`, puis `MT_PYRE_SUMMIT` (scène), `SOOTOPOLIS_CITY_GYM_1F`.

1. [R] Montée (sols fissurés : Vélo Cross, vanilla) ; Carillonneurs ; **Bourdon** 2 (dernier). Il s'efface : « Je n'ai plus d'heure à attendre. »
2. [N] Sommet : la **Cloche Mère** suspendue ; Ysaline épuisée (dépression) : « Encore deux cloches et ce sera fini. » **Ysaline 2** (cap 50 ; Distorsion, Requiem, Prescience, Abri ; IA `Prediction`).
3. [N] Après le combat : le joueur (et Gaspard) lisent la **seconde moitié du glas** gravée sur la Cloche Mère. Une **vision** plus longue : Augure, avant d'être figé, regardait le joueur à travers le temps ; c'est lui qui a envoyé Absol à chaque veille. **Révélation R5.** Absol paraît au bord du sommet.
4. [N] Choix scénarisé : le joueur **tend le Diapason** à Ysaline (seule action proposée ; le jeu attend que le joueur le fasse). Elle sonne **le glas**. Écran : chaque Figement restant se délivre (enchaînement court de fondus : Atalanopolis, Mont Mémoria). Gaspard renonce à prélever un éclat de la cloche.
5. [N] **Mont Mémoria, sommet, aube** : Augure respire ; il s'éteint au lever du soleil, Ysaline à ses côtés. Pas de combat. Ysaline : « Merci de ne pas m'avoir laissée arrêter le temps. » (Le joueur est ramené par fondu à Atalanopolis.)
6. [V] Atalanopolis délivrée ; Juan → **badge 8 (Cascade)**.

## 16. Finale — « Ce qui passe » (20:00–22:00)

**Cartes :** `ROUTE128`, `EVER_GRANDE_CITY`, `VICTORY_ROAD_1F/B1F/B2F`, `EVER_GRANDE_CITY_POKEMON_LEAGUE_1F`, salles du Conseil, `CHAMPIONS_ROOM`, `HALL_OF_FAME`.

1. [R] Route Victoire : **{RIVAL} final** (ID du dernier combat de Timmy) : « On ne garde pas un instant en l'arrêtant. On le garde en s'en souvenant. »
2. [V/R] Conseil 4 : Damien, **Spectra** (après le combat : « Grand-mère m'a écrit. Merci. »), Glacia, Aragon.
3. [R] **Maître Pierre** (Méga-Métalosse).
4. [V] Panthéon, crédits. [N] **Épilogue** : Mont Mémoria, Ysaline sonne un glas pour Augure ; un **œuf de Natu** près d'elle ; Absol sur le rebord, puis il s'en va.

## P. Postgame — « Les instants perdus »
Détail dans `WORLD.md` §6 : P1 Regis (Sanctuaire, `SEALED_CHAMBER_*`, `DESERT_RUINS`, `ISLAND_CAVE`, `ANCIENT_TOMB`) ; P2 Rayquaza (`SKY_PILLAR_TOP`) ; P3 Île du Sud ; P4 Île Aurore ; P5 Zone de Combat ; P6 revanches (Ysaline, Rocheval, Marc, champions) ; P7 Groudon/Kyogre (Grotte Terra/Marine, vanilla).

---

## 17. Table de remplacement des événements vanilla (obligatoire pour la production)

Règle : **aucune porte vanilla n'est supprimée sans remplaçante** ; la traversée reste possible à chaque étape.

| Événement vanilla | Cartes / scripts | Porte assurée | Remplacement |
|---|---|---|---|
| Tutoriel de capture avec Timmy | `PetalburgCity`, scripts de Timmy | aucune | supprimé ; {RIVAL} montre la capture (Route 103) |
| Sbire Aqua au Bois Clémenti | `PetalburgWoods` | aucune | F1 + Gaspard + Diapason |
| Vol des Pièges Devon, Tunnel Mérazon | `Route116`, `RusturfTunnel`, `RustboroCity_DevonCorp_*` | lettre + bateau | Devon : lettre pour Pierre + grelot pour Morel ; bateau = Peeko libéré + B1 |
| Peeko enlevé (Aqua) | `Route104_MrBrineysHouse`, `PetalburgWoods` | bateau | Peeko figé dans F1 |
| Lettre à Pierre | `GraniteCave_StevensRoom` | bateau vers Poivressel | idem + Braille n°1 |
| Pièges Devon au Capt. Marin, invasion Aqua au Musée | `SlateportCity_OceanicMuseum_*` | Route 110 libre | Conservateur Morel + grelot |
| Combats de Timmy (Lavandia, Route Victoire) | `MauvilleCity`, `VictoryRoad_1F` | aucune | supprimé (Lavandia) ; {RIVAL} final (Route Victoire) |
| Magma au Site Météore | `MeteorFalls_1F_1R` | téléphérique | traque d'Absol, Rocheval 1, escorte |
| Sbires Magma au téléphérique | `Route112` | Mont Chimnée | barrage des Veilleurs |
| Magma/Aqua au Mont Chimnée | `MtChimney` | Chemin Ardent / Vermilava | F3 éruption figée + évacuation |
| Planque Magma | `MagmaHideout_*`, `JaggedPass` | aucune | **fermée** (entrée non révélée ; flag d'ouverture jamais posé) |
| Père de Timmy → CS Surf | `PetalburgCity_WallysHouse` | Surf | Norman remet Surf |
| Aqua à l'Institut Météo | `Route119_WeatherInstitute_*` | (aucune stricte) | F4 + Bourdon 1 + relevés |
| {RIVAL} Route 119 → CS Vol | `Route119` | Vol | conservé |
| Kecleon / Scope Devon | `FortreeCity`, `Route120` | arène 6 | conservé |
| Gemmes volées au Mont Mémoria | `MtPyre_*` | (scénario) | Cloche Mère disparue, Ysaline 1, R3 |
| Planque Aqua | `AquaHideout_*` | (scénario) | repaire des Veilleurs, Rocheval 2, R2 |
| Magma au Centre Spatial | `MossdeepCity_SpaceCenter_*` | (scénario) | duo Pierre, Méga-Bracelet |
| Aqua/Kyogre Caverne Fondmer | `SeafloorCavern_*` | (scénario) | temple, R4, glas (moitié 1) |
| Crise des titans à Atalanopolis, Marc, Pilier | `SootopolisCity`, `SkyPillar_*` | arène 8, Pilier | F6 ville figée, Marc ouvre le Pilier, Ysaline 2, glas |
| Rayquaza éveillé (Émeraude) | `SkyPillar_Top` | arène 8 | **déplacé en postgame** ; l'arène 8 se débloque par la délivrance d'Atalanopolis |
| Groudon/Kyogre capturables (Grottes Terra/Marine) | vanilla postgame | — | conservé (postgame) |

ID de dresseurs : réaffecter les ID Magma/Aqua (sbires → Carillonneurs/Veilleurs ; admins → Bourdon, Tierce, Rocheval ; chefs → Ysaline 1/2) ; aucun nouvel ID requis pour l'aventure. Les 9 slots libres sont réservés au postgame.

## 18. Carte des serrures-clés (progression)

| # | Serrure (vue en) | Clé (obtenue en) | Type | Délai | Lien mécanique |
|---|---|---|---|---|---|
| 1 | Bois figé (ch. 1) | Diapason + cloche-pivot (ch. 1) | dynamique (combat) | < 10 min | combat Dominant |
| 2 | Bateau de M. Marcel (ch. 1) | Peeko libéré + B1 (ch. 1-2) | binaire | 30 min | — |
| 3 | Rochers du Tunnel Mérazon (ch. 2) | Éclate-Roc, B3 (ch. 5) | binaire | ~2 h | CS |
| 4 | Téléphérique (ch. 6) | traque résolue au Site Météore (ch. 6) | narrative | 30 min | combat Rocheval |
| 5 | Désert (ch. 6) | Lunettes Sable (ch. 7) | objet | 1 h | — |
| 6 | Éruption figée (ch. 7) | évacuation + cloche-pivot | mission | 30 min | préparation |
| 7 | Rideau de pluie, Route 119 (ch. 9) | cloche-pivot de l'Institut | combat | 20 min | — |
| 8 | Arène de Cimetronelle (ch. 9) | Scope Devon (ch. 9) | objet | 10 min | [V] |
| 9 | Exposition erronée (ch. 10) | lecture du Braille (ch. 13) | information | ~4 h | quête annexe |
| 10 | Culpabilité d'Absol (ch. 1) | preuves (ch. 6-10) | information | ~10 h | enquête |
| 11 | Sommet du Mont Mémoria figé (ch. 11) | glas complet (ch. 15) | information + combat | ~6 h | finale |
| 12 | Atalanopolis figée (ch. 13-14) | glas (ch. 15) | idem | 2 h | — |
| 13 | Tombeau Antique illisible (ch. 9) | Sanctuaire (postgame) | information | postgame | Braille |

Badges → capacités (vanilla, invariant) : B1 Coupe, B2 Flash, B3 Éclate-Roc, B4 Force, B5 Surf, B6 Vol, B7 Plongée, B8 Cascade.

## 19. Ce que sait le joueur à chaque étape

| Fin de | Il sait | Il soupçonne | Il ignore |
|---|---|---|---|
| Prologue | des choses s'arrêtent | — | tout |
| Ch. 1 | règle du Figement, cloche-pivot, Diapason | Absol porte malheur ? | qui sonne |
| Ch. 3 | « Le son arrête » ; alliage inconnu | lien avec le Sanctuaire | qui |
| Ch. 4 | Ysaline existe (sonneuse) | — | son rôle |
| Ch. 5 | **R1** : Ysaline accorde des cloches anciennes | pourquoi ? | son but |
| Ch. 7 | figer peut protéger | Absol innocent | le carillon complet |
| Ch. 10 | **R2** : Absol prévient | Ysaline veut figer quelque chose de précis | quoi |
| Ch. 11 | **R3** : Augure, le carillon, le sommet | les visions viennent d'Augure ? | ce que craignait le peuple |
| Ch. 13 | **R4** : peur de perdre ; moitié du glas | — | seconde moitié |
| Ch. 15 | **R5** : Augure guidait ; le glas complet | — | (rien de central) |
| Ligue | Spectra = petite-fille | — | — |

## 20. Budget flags / vars (histoire principale)

| Usage | Nb estimé |
|---|---|
| États de chapitre | 1 var `VAR_HS_CHAPITRE` (0-17) + 1 var par grand lieu à états (Lavandia, Atalanopolis, Mont Mémoria, Pilier) = 5 vars |
| Figements (actif / délivré) | 2 × 7 = 14 flags (+ `FLAG_FIGEMENT_ACTIF` global = 1) |
| Indices (Carnet) | 12 flags |
| Preuves R2 | 4 flags |
| Évacuation de Vermilava | 5 flags |
| Réponse d'Ysaline (ch. 4) | 1 var |
| PNJ masqués/affichés (Carillonneurs, Veilleurs, figés) | ~60 flags (recycler les flags `HIDE_*` Magma/Aqua) |
| Quêtes annexes | ~20 flags, 2 vars |
| Mode (H2) | 1 var (`B_VAR_DIFFICULTY`) |
| **Total** | **≈ 120 flags, ≈ 10 vars** (sur 372 / 55 libres, plus recyclage des flags vanilla supprimés) |
