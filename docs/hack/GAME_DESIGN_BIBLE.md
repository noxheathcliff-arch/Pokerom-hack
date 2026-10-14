# GAME_DESIGN_BIBLE — *Pokémon Cendres* (v2.0)

> **Source unique de vérité du design.** Propriétaire : Game Mechanics Director. Toute modification passe par le GMD et entre au changelog (§13).
> Méthode : `GM_METHOD.md`. Intention : `EXPERIENCE_INTENT.md` (avec l'addendum v2). Choix de direction : `NARRATIVE_DIRECTIONS.md`.
> Statut : **v2.0 — conception. Rien n'est encore implémenté ni testé.**

## Documents liés (font partie de la bible)
| Document | Contenu |
|---|---|
| [`CHARACTER_AND_LORE.md`](CHARACTER_AND_LORE.md) | Distribution (Kanto, Hoenn, nouveaux), objectifs, conflits, croyances, arcs, relations, assets ; chronologie ; règles de lore |
| [`GAME_SYSTEMS.md`](GAME_SYSTEMS.md) | Systèmes cachés (stockage, seuils, effets), progression, plafonds par jalon, rencontres, objets/économie, quêtes, QoL, **conditions formelles des fins** |
| [`DECISION_LEDGER.md`](DECISION_LEDGER.md) | Registre des décisions (règles, synthèse, contributions aux fins) + fichiers par acte |
| [`COMBAT_DESIGN.md`](COMBAT_DESIGN.md) | Combats majeurs, arc de maîtrise, IA, affectation des ID de dresseurs |

---

## 1. Concept
**Une phrase :** *l'ancien Maître de Kanto arrive à Hoenn dans un canot de sauvetage ; ici, sa force ne suffit pas.*

Un an après sa victoire à la Ligue de Kanto, **Red** a quitté son titre sans un mot. Il était à **Cramois'Île** quand le volcan s'est réveillé. Il a aidé à l'évacuation, puis il a embarqué sur l'**Océane**, réquisitionnée pour emmener 300 réfugiés vers la seule région qui a accepté de les accueillir : **Hoenn**. Le jeu commence la nuit où l'Océane, prise dans une tempête, met ses canots à la mer au large de la Route 104.

À Hoenn, le **Mont Chimnée** gronde. Après Cramois'Île, personne ne veut attendre. La **Coopérative Magma** propose de forer pour « dégazer » le volcan (**Projet Soupape**), avec l'argent de Devon et la main-d'œuvre des réfugiés. Les **pêcheurs d'Aqua** s'y opposent : l'eau brûlante rejetée tue les récifs dont ils vivent, et les réfugiés pêchent dans leurs zones. Les **réfugiés** veulent du travail, un toit et leurs Pokémon, que Devon garde en quarantaine dans l'**Arche**. Les **autorités** (Ligue, Devon) veulent l'ordre et le chantier. Dans l'ombre, la **Team Rocket**, orpheline de Giovanni, prépare un coup : provoquer une évacuation pour vider l'Arche.

Red ne parle pas. **Brice**, fils du Prof. Seko, chargé de recenser les Pokémon étrangers, devient sa voix, son guide et parfois sa conscience. Ensemble, ils traversent Hoenn, enquêtent, choisissent, négocient — et découvrent que l'équipe la plus forte du monde ne fait pas reculer un volcan, ne loge personne et ne convainc aucun conseil.

## 2. Thèmes et propos
- **Thème central : les limites de la force.** La puissance règle les combats ; elle ne règle ni la peur, ni l'accueil, ni les intérêts qui s'opposent.
- **Thèmes secondaires :** l'accueil et ce qu'il coûte ; prévenir une catastrophe sans en provoquer une autre ; parler pour quelqu'un (Brice parle pour Red) ; ce qu'on doit à ceux qu'on a sauvés.
- **Propos mécanique (sémiotique) :** les combats résolvent les **combats** ; les **problèmes** se résolvent par l'enquête (preuves), la confiance (affinités) et la réputation (factions). L'équipe de Red est forte mais plafonnée (§7) ; sa vraie ressource est ce qu'il sait et ceux qui le suivent.
- **Ton :** aventure sérieuse et chaleureuse, jamais cynique, jamais moralisatrice. Chaque faction a raison sur quelque chose. Humour par Brice, les enfants du camp, Blue, et les petites gens de Hoenn (exemples écrits en `CHARACTER_AND_LORE.md` §6).
- **Fins :** cinq fins (§9), du meilleur compromis à l'exode ; aucune n'est une punition, toutes gardent un espoir.

## 3. Identité
| Élément | Décision |
|---|---|
| Titre | **Pokémon Cendres** |
| En-tête ROM (≤ 12) | `CENDRES` |
| Joueur | **Red** (nom fixe, muet ; avatar Red — `ENGINE_CHANGES.md`) |
| Second protagoniste | **Brice** (Brendan), fils du Prof. Seko |
| Région / cartes | Hoenn, 518 cartes vanilla, noms FR vanilla |
| Cadre temporel | **Année 1** après RBJ/RFVF (`CHARACTER_AND_LORE.md` §2) |
| Gimmick | **Méga-Évolution** seule (Méga-Bracelet au ch. 8) |
| Signature sonore | `MUS_RG_CINNABAR` au camp ; `MUS_RG_ROCKET_HIDEOUT` pour Rocket ; `MUS_MT_CHIMNEY` au chantier |
| Accroche | « Il a battu la Ligue. Il ne peut pas battre un volcan. » |

## 4. Synopsis complet

**Prologue — « Naufrage » (ch. 0).** Nuit de tempête. Dans un canot, Red, Pikachu, une fillette réfugiée (Lilou) et un vieux marin. Le canot se brise sur les rochers de la Route 104. Pikachu se jette à l'eau pour le retenir et se blesse. **Brice**, en relevés de terrain avec M. Marcel, les hisse à bord. Brice escorte Red à Bourg-en-Vol, chez son père. Le Prof. Seko soigne Pikachu (convalescence longue), confie à Red un starter de Hoenn, et téléphone à **Norman**, registraire de la Ligue à Clémenti-Ville, pour enregistrer « le dresseur étranger ». Red peut s'inscrire sous son nom ou rester anonyme. Premier combat d'entraînement avec Brice (Route 103).

**Acte I — « Les débarqués » (ch. 1-4, badges 1-3).** À Clémenti, Norman enregistre Red et lui explique la loi de quarantaine : les Pokémon étrangers des réfugiés sont placés dans l'**Arche** de Devon le temps d'un recensement. Au Bois Clémenti, un Galopa réfugié affolé, des employés de Devon qui veulent le capturer : premier arbitrage. À Mérouville, Roxanne (badge 1). Chez Devon, M. Rochard présente le **Projet Soupape** et demande à Red de le soutenir publiquement ; il lui confie une lettre pour son fils Pierre et le manifeste de l'Arche pour le capitaine Marin à Poivressel. Sur la Route 116, une réfugiée a été volée : premiers indices d'une organisation — Red reconnaît des méthodes de la **Team Rocket**. M. Marcel, en dette envers Red depuis la nuit du naufrage, fait la traversée. À Myokara, Bastien (badge 2) ; à la Grotte Granite, Pierre Rochard étudie les secousses et demande ce que Red a vu à Cramois'Île. À **Poivressel**, le camp de réfugiés sur la plage, Auguste (ex-Champion de Cramois'Île) qui le dirige, les pêcheurs d'Aqua qui bloquent la Route 110 pour protester contre l'attribution des quais, et **Blue**, invité par Scott, qui veut enfin affronter Red. Red tranche le conflit du quai (ou laisse Brice le faire). À Lavandia, Voltère (badge 3) soutient le projet, qui promet de l'électricité. Seko ramène Pikachu. À Vergazon, les ouvriers ont vu « des hommes en noir » dans le Tunnel Mérazon : raid avec Brice, Pokémon volés retrouvés, un sbire capturé. **Révélation R1 : la Team Rocket vole les Pokémon des réfugiés, et quelqu'un chez Devon la renseigne.**

**Acte II — « La Soupape » (ch. 5-8, badges 4-6).** La Coopérative Magma ferme le téléphérique (« zone de chantier ») : Red passe par le Chemin Ardent, les cendres de la Route 113, Autéquia où le Prof. Cosmo installe des sismographes. Au Site Météore, des militants d'Aqua sabotent un capteur ; les données de Cosmo deviennent un enjeu. Max lève le barrage. Au Mont Chimnée, le chantier : Max, sa cheffe ingénieure Kelvin (Tabitha), des ouvriers réfugiés, des manifestants d'Aqua. À Vermilava, Adriane héberge les réfugiés aux sources chaudes ; les villageois grondent. Dans les galeries (Planque Magma), une secousse provoque un **accident** : des ouvriers coincés, un choix de sauvetage. Red trouve une vanne **sabotée**. L'ingénieur de Devon « Lambert » est introuvable au moment de l'accident. Adriane (badge 4). À Clémenti, Norman demande à Red de témoigner sur Cramois'Île devant le registre ; Norman (badge 5, Surf). Route 119 : les pêcheurs d'Aqua occupent l'Institut Météo pour obtenir les relevés de température de la mer ; négocier avec Sarah. Brice remet Vol. Route 120 : Pierre Rochard combat aux côtés de Red contre des éclaireurs Rocket, méga-évolue Métalosse, puis remet le **Méga-Bracelet** et le Scope Devon. Alizée (badge 6). Une alerte tombe : **une mini-éruption** au Mont Chimnée, causée par un second sabotage. **Révélation R2 : les sabotages ne viennent pas d'Aqua, mais de Rocket, qui veut une évacuation.**

**Acte III — « Avant la braise » (ch. 9-13, badges 7-8, climax).** À Nénucrique, Aqua bloque le port (Route 124) ; dans leur planque, Arthur montre que Rocket leur a volé du matériel de plongée pour les faire accuser. Au Mont Mémoria, Agatha (venue de Lavanville) et Spectra célèbrent un rite pour les morts de Cramois'Île ; Rocket tente de voler l'**Orbe Rouge**, qui peut apaiser Groudon, endormi sous le Mont Chimnée. Red décide qui garde l'Orbe. Blue, sur le toit du Grand Magasin, avoue qu'il a perdu son titre en quelques minutes et qu'il ne sait plus pourquoi il se bat. À Algatia, Lévy & Tatia (badge 7, Plongée) ; Rocket attaque le Centre Spatial pour voler les relevés sismiques et les codes de l'Arche ; **Lambda**, alias « Lambert », est démasqué. **Révélation R3 : l'Opération Braise — saboter la Soupape pendant le vote, pour vider l'Arche pendant l'évacuation.** Lanette propose de réparer le lien PC avec Kanto. Sous le Chenal 128, la **Caverne Fondmer** : les rejets du forage d'essai ont blanchi les fonds ; Kyogre s'agite. À **Atalanopolis**, Marc et Juan réunissent le **Conseil de Hoenn** : Ligue, Devon, Coopérative Magma, Aqua, réfugiés. Red (ou Brice) défend trois motions avec les preuves et les alliés réunis : le sort du forage, le sort des réfugiés, la garde de l'Arche. Juan (badge 8, Cascade). La nuit même, **l'Opération Braise** commence : sabotage au forage, attaque de l'Arche à Vermilava. Red ne peut être qu'à un endroit. **Climax : Ariane, Groudon qui s'éveille ou non, le volcan.**

**Finale (ch. 14).** Route Victoire : Blue. Conseil 4 de Hoenn puis **Pierre Rochard**, Maître. Épilogue selon l'état du monde (§9). Red repart toujours vers le nord, sur l'Océane réparée.

**Postgame — « Ce qui reste ».** Les conséquences mûrissent : Vermilava reconstruite ou déserte, colonie de Pacifiville, récifs, Rocket en fuite ou démantelée, lien PC rétabli (l'équipe classique de Red peut revenir), Groudon à apaiser, Zone de Combat avec Blue et Scott, lettres de la mère de Red.

## 5. Structure en actes
| Acte | Chapitres | Badges | Durée cible | Révélations | Pic |
|---|---|---|---|---|---|
| Prologue | 0 | — | 0:00–0:45 | — | Naufrage |
| I — Les débarqués | 1–4 | 1–3 | 0:45–5:30 | R1 | Raid du Tunnel Mérazon |
| II — La Soupape | 5–8 | 4–6 | 5:30–11:00 | R2 | Accident des galeries / mini-éruption |
| III — Avant la braise | 9–13 | 7–8 | 11:00–17:00 | R3 | Conseil puis Braise |
| Finale | 14 | — | 17:00–18:30 | — | Maître |
| Postgame | P1–P8 | — | 18:30+ | — | conséquences différées |

## 6. Déroulé chapitre par chapitre (cartes, événements, décisions)

Notation : **[V]** vanilla conservé, **[R]** vanilla réécrit, **[N]** nouveau sur carte existante. `D###` = décision (`DECISION_LEDGER*.md`). `FLAG_HS_*` = drapeaux neufs (aucun recyclage de drapeau vanilla sauf mention explicite, leçon des revues).

### Ch. 0 — Naufrage (D001–D008)
Cartes : `MAP_ROUTE104` (plage sud, nuit), `MAP_ROUTE104_MR_BRINEYS_HOUSE`, `MAP_PETALBURG_CITY`, `MAP_ROUTE102`, `MAP_OLDALE_TOWN`, `MAP_ROUTE101`, `MAP_LITTLEROOT_TOWN`, `MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F/2F` (maison des Seko), `MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB`, `MAP_ROUTE103`.
1. [N] Début de partie sur la plage de la Route 104 (nouvelle position de départ ; intro du camion supprimée). Scène du canot (D001, D002, D003). Rencontres sauvages coupées (`WE_FLAG_NO_ENCOUNTER` assigné à `FLAG_HS_NO_ENCOUNTER`) jusqu'au labo.
2. [N] Maison de M. Marcel : on sèche les naufragés. Brice : « Mon père saura quoi faire pour ton Pikachu. » (D004 : suivre Brice ou partir seul).
3. [N] Escorte de Brice (PNJ suiveur) par Clémenti, Route 102, Rosyères, Route 101.
4. [R] Labo de Seko : Pikachu en convalescence ; choix du starter (D006) ; choix du mode (Normal/Expert, `B_VAR_DIFFICULTY` ; non compté comme décision) ; inscription au registre par téléphone avec Norman : nom ou anonymat (D005) ; lettre du Prof. Chen (D007) ; chambre chez les Seko ou au camp (D008). `FLAG_HS_NO_ENCOUNTER` levé.
5. [R] Route 103 : combat d'entraînement contre Brice (ID `BRENDAN_ROUTE_103_*`).

### Ch. 1 — Clémenti, le Bois, Mérouville (D009–D018)
Cartes : `PETALBURG_CITY` (+ `_GYM` : Norman registraire), `ROUTE104`, `PETALBURG_WOODS`, `RUSTBORO_CITY` (+ `_GYM`, `_DEVON_CORP_1F-3F`, `_POKEMON_SCHOOL`), `ROUTE116`, `RUSTURF_TUNNEL` (entrée ouest).
- [R] Norman enregistre Red (D009).
- [R] Bois Clémenti : le Galopa réfugié (D010) ; portefeuille d'un employé Devon (D011, indice « Lambert »).
- [V] Roxanne → badge 1 (Coupe) ; conférence à l'École (D013) ; gamin hostile, combat déclinable (D012).
- [R] Devon : Projet Soupape et Arche ; soutien public (D014) ; lettre pour Pierre + manifeste scellé (D015). **Remplace le vol des Pièges Devon** : les drapeaux vanilla de livraison `FLAG_DELIVERED_STEVEN_LETTER` / `FLAG_DELIVERED_DEVON_GOODS` sont **conservés** avec le même sens (livraisons).
- [N] Route 116 : réfugiée volée (D016) ; traces à l'entrée ouest du Tunnel (D017, serrure vue : rochers, Éclate-Roc).
- [R] M. Marcel : traversée (D018) ; `VAR_BRINEY_HOUSE_STATE` posé par notre script après le badge 1.

### Ch. 2 — Myokara (D019–D024)
Cartes : `DEWFORD_TOWN` (+ `_GYM`, `_HALL`, `_POKEMON_CENTER_1F`), `ROUTE106`, `GRANITE_CAVE_1F/B1F/B2F/STEVENS_ROOM`.
- [V] Bastien → badge 2 (Flash) ; enfants réfugiés au dojo (D019).
- [R] Pierre Rochard : lettre livrée (`FLAG_DELIVERED_STEVEN_LETTER`) ; témoignage (D020) ; gemme du Ténéfix (D024).
- [N] Pêcheur qui refuse de vendre (D021) ; Matthieu, combat déclinable (D022) ; lettre à la mère (D023).

### Ch. 3 — Poivressel (D025–D036)
Cartes : `ROUTE107-109`, `ROUTE109_SEASHORE_HOUSE`, `SLATEPORT_CITY` (+ `_HARBOR`, `_STERNS_SHIPYARD_1F`, `_OCEANIC_MUSEUM_1F/2F`, `_BATTLE_TENT_LOBBY`), `ROUTE110` (sud).
- [N] Camp de réfugiés (plage Route 109 + esplanade de Poivressel) : Auguste (D027, D028), Lilou, enfant voleur (D034), dresseurs hostiles déclinables (D035).
- [R] Quai : conflit pêcheurs/réfugiés (D025). Les objets Aqua de `SLATEPORT_CITY` (`FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA`) deviennent la manifestation ; ceux de la Route 110 (`FLAG_HIDE_ROUTE_110_TEAM_AQUA`) deviennent le **piquet des pêcheurs** qui bloque la Route 110 → masqués par notre script de fin du conflit (`FLAG_HS_QUAI_REGLE`).
- [R] Capitaine Marin (chantier naval) reçoit le manifeste (D026) ; plans du forage sous-marin (D033).
- [N] Arthur et ses mesures (D029) ; Journalistes (D032).
- [N] **Blue** (invité de Scott, Tente de Combat) : défi (D030), offre de Scott (D031).
- [N] Rester un jour au camp ou partir (D036).
- [V] Route 110 : Brice 2 (ID `BRENDAN_ROUTE_110_*`).

### Ch. 4 — Lavandia, Vergazon, le Tunnel (D037–D046)
Cartes : `MAUVILLE_CITY` (+ `_GYM`), `ROUTE117`, `VERDANTURF_TOWN`, `RUSTURF_TUNNEL`.
- [R] Lavandia : **supprimer Timmy et son oncle** (`FLAG_HIDE_MAUVILLE_CITY_WALLY`, `..._WALLYS_UNCLE` posés à la nouvelle partie) ; Voltère → badge 3 (CT Éclate-Roc dans la maison vanilla) ; soutien énergétique (D037) ; retour de Pikachu (D038).
- [N] Vergazon : informateurs (D039) ; question de Brice sur le silence de Red (D045).
- [R] **Raid du Tunnel Mérazon** (entrée est ; Éclate-Roc requis au milieu, vanilla) : choix d'approche (D040), sbire (D041), Pokémon libérés (D042), carnet (D043), Chuchmur (D044). Fin : `VAR_RUSTURF_TUNNEL_STATE` posé à l'état « dégagé » par notre script (raccourci Mérouville). **R1.**
- [N] Combat déclinable (D046).

### Ch. 5 — Cendres (D047–D054)
Cartes : `ROUTE111` (sud ; rochers Éclate-Roc vanilla), `ROUTE112`, `FIERY_PATH` (**obligatoire** tant que le téléphérique est fermé), `ROUTE113`, `ROUTE113_GLASS_WORKSHOP`, `FALLARBOR_TOWN` (+ `_COZMOS_HOUSE`), `ROUTE114`, `METEOR_FALLS_1F_1R` **uniquement** (leçon : 1F_2R et B1F exigent Surf).
- [R] Route 112 : les objets Magma (`FLAG_HIDE_ROUTE_112_TEAM_MAGMA`) deviennent la **sécurité du chantier** ; masqués par notre événement du Site Météore (`FLAG_HS_DONNEES_COSMO`).
- [N] Souffleur de verre (D047) ; Cosmo (D048, D053) ; famille campant Route 114 (D052) ; combat déclinable (D054).
- [R] Site Météore 1F_1R : militants Aqua et capteur (D049), données (D050) ; Peter, quête facultative (D051).

### Ch. 6 — Le chantier (D055–D066)
Cartes : `MT_CHIMNEY_CABLE_CAR_STATION`, `MT_CHIMNEY`, `JAGGED_PASS`, `LAVARIDGE_TOWN` (+ `_GYM_1F/B1F`, `_HERB_SHOP`, `_POKEMON_CENTER_1F`), `MAGMA_HIDEOUT_1F`, `_2F_1R` (seules ces deux cartes sont réécrites ; le reste est fermé par rochers/PNJ).
- [R] Sommet : chantier Magma, manifestants Aqua (D055, D056, D063). Les objets Magma/Aqua vanilla du Mont Chimnée sont masqués à la nouvelle partie ; nouveaux objets sur `FLAG_HS_*`.
- [R] Chemin Ardent : l'entrée de la Planque Magma (`VAR_JAGGED_PASS_STATE`, garde `FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD`) est ouverte par **notre** script (`FLAG_HS_VISITE_CHANTIER`), plus par le Mont Mémoria.
- [N] Vermilava : hébergement (D057), herboriste (D066), embauches (D064).
- [N] Galeries : suivre « Lambert » (D058), accident et sauvetage (D059), rapport (D060), dossier de Max (D065).
- [V] Adriane → badge 4 (Force) ; preuve confiée (D061) ; [R] Brice remet les Lunettes Sable (`FLAG_RECEIVED_GO_GOGGLES`, script vanilla réutilisé) et parle de son père (D062).

### Ch. 7 — Le registre (D067–D072)
Cartes : `PETALBURG_CITY_GYM`, `PETALBURG_CITY`, maison des Seko (retour), `ROUTE116`→`RUSTBORO`→`ROUTE104` (trajet via le tunnel dégagé).
- [R] Norman : témoignage (D067) ; pétitions (D069) ; [V] Norman → badge 5 ; [R] **Norman remet la CS Surf** (remplace le père de Timmy ; `FLAG_RECEIVED_HM_SURF`).
- [N] Flora (D068) ; dîner chez les Seko (D070) ; lettre d'Ariane (D071) ; combat déclinable (D072).

### Ch. 8 — La mer chaude (D073–D080)
Cartes : `ROUTE118`, `ROUTE119`, `ROUTE119_WEATHER_INSTITUTE_1F/2F`, `FORTREE_CITY` (+ `_GYM`), `ROUTE120`.
- [R] Institut Météo : occupé par Aqua (Sarah) ; les sbires du pont de la Route 119 (`FLAG_HIDE_ROUTE_119_TEAM_AQUA`) bloquent la route de Cimetronelle → masqués par notre fin d'événement (`FLAG_HS_INSTITUT`) ; données (D073, D074). Lit de l'Institut : soin conservé (hors zone de conflit).
- [R] Route 119 : Brice 3, combat (D075) → **CS Vol** (`BRENDAN_ROUTE_119_*`).
- [N] Cimetronelle : réfugiés dans les cabanes (D076).
- [R] Route 120 : Pierre Rochard ; duo contre deux éclaireurs Rocket (Pierre partenaire, `battle_partners`) ; Méga-Bracelet + Scope Devon (vanilla `FLAG_HIDE_ROUTE_120_STEVEN` logique conservée) ; son avis sur la Soupape (D077) ; Absol (D078).
- [V] Kecleon / Alizée → badge 6.
- [N] Alerte : mini-éruption (D079). **R2.** Combat déclinable (D080).

### Ch. 9 — Nénucrique et le Mont Mémoria (D081–D090)
Cartes : `ROUTE121`, `LILYCOVE_CITY` (+ `_DEPARTMENT_STORE_*`, `_ROOFTOP`, `_HARBOR`), `AQUA_HIDEOUT_1F/B1F` (B2F fermé), `ROUTE122`, `MT_PYRE_1F`, `MT_PYRE_EXTERIOR`, `MT_PYRE_SUMMIT`.
- [R] Route 121 : supprimer la scène Aqua (`FLAG_HIDE_ROUTE_121_TEAM_AQUA_GRUNTS` posé ; `VAR_ROUTE121_STATE` mis à l'état final à la nouvelle partie).
- [R] Port : blocus Aqua — les 5 sbires de `LILYCOVE_CITY` (`FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS`) bloquent la Route 124 ; négociation (D081). Les gardes de l'entrée de la planque (`FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1/2_BLOCKING_ENTRANCE`) sont masqués **par D081** (et non plus par le port de Poivressel).
- [R] Planque Aqua : preuve du matériel volé (D082), Arthur (D083). Combat Arthur facultatif.
- [N] Toit du Grand Magasin : Blue 2 (D089) ; achats pour le camp (D087) ; journalistes (D090) ; combat déclinable (D088).
- [R] Mont Mémoria (**remplace le vol des Orbes** ; le script vanilla qui pose `FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD` est neutralisé) : rite (D084), légende (D086), Rocket et Orbe Rouge (D085). Fin du chapitre : quand `FLAG_HS_PLANQUE_AQUA` **et** `FLAG_HS_MONT_MEMORIA` sont posés, notre script pose `FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS` (Route 124 ouverte). Le script vanilla de `AQUA_HIDEOUT_B2F` est neutralisé.

### Ch. 10 — Algatia (D091–D096)
Cartes : `ROUTE124`, `MOSSDEEP_CITY` (+ `_GYM`, `_SPACE_CENTER_1F/2F`, `_STEVENS_HOUSE`), `ROUTE125`.
- [V] Lévy & Tatia → badge 7 (Plongée **non** remise par l'arène en vanilla : c'est Pierre qui la remet ; ordre vanilla conservé). Le script d'arène arme `VAR_MOSSDEEP_CITY_STATE` (conservé) ; il **ne pose plus** `FLAG_HIDE_AQUA_HIDEOUT_GRUNTS` (neutralisé).
- [R] Centre Spatial : attaque Rocket (remplace Magma) ; partenaire Pierre ou Brice (D091) ; Lambda démasqué (D092) ; codes de l'Arche (D093). **R3.**
- [R] Maison de Pierre : **CS Plongée** (`FLAG_RECEIVED_HM_DIVE`, script vanilla) + masque le garde de Fondmer (`FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT`, conservé) ; Méga-Gemme (D095).
- [N] Lanette (venue au Centre Spatial) : lien PC Kanto (D094). Combat déclinable (D096).

### Ch. 11 — Fondmer (D097–D099)
Cartes : `ROUTE128`, `UNDERWATER_ROUTE128`, `SEAFLOOR_CAVERN_ENTRANCE`, `_ROOM1`, `_ROOM9` (réécrites) ; salles 2-8 : texte vanilla vidé d'Aqua, énigmes Force/Éclate-Roc vanilla.
- [R] Contre-expertise (D097), balise (D098), plongeurs Rocket (D099). Le script de la salle 9 ne pose plus `FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN` (Atalanopolis reste dans son état normal). La scène vanilla de la Route 128 (Pierre/Max/Arthur) est supprimée (drapeaux `HIDE_ROUTE_128_*` posés à la nouvelle partie).

### Ch. 12 — Le Conseil d'Atalanopolis (D100–D105)
Cartes : `UNDERWATER_ROUTE126` → `UNDERWATER_SOOTOPOLIS_CITY` → `SOOTOPOLIS_CITY` (place, extérieur), `SOOTOPOLIS_CITY_GYM_1F/B1F`.
- [N] Conseil en extérieur (pas de nouvelle carte). Intervenants : Marc (président), Pierre, M. Rochard, Max, Arthur, Auguste, Norman. Mécanique : `GAME_SYSTEMS.md` §5 (votes). D100–D105.
- [R] Atalanopolis garde son état vanilla « normal » (`VAR_SOOTOPOLIS_CITY_STATE` = 0 ; `VAR_SKY_PILLAR_STATE` inchangé). La porte de l'arène, verrouillée tant que `FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE` est vide, est déverrouillée **par la fin du Conseil** (notre script pose ce drapeau vanilla).
- [V] Juan → badge 8 (Cascade).

### Ch. 13 — La Braise (climax) (D106–D111)
Cartes : `LAVARIDGE_TOWN` (camp et Arche mobile), `JAGGED_PASS`, `MAGMA_HIDEOUT_1F/2F_1R` (+ salle de Groudon `MAGMA_HIDEOUT_4F` atteinte par warp scripté **uniquement** si `VAR_ETAT_VOLCAN` ≥ 70), `MT_CHIMNEY`.
- [N] Soin complet garanti au Centre de Vermilava avant le choix. Choix du lieu (D106). Branches : chantier (D107, D108) ; camp (D109) ; puis D110, D111. Résolution des états (`GAME_SYSTEMS.md` §8).

### Ch. 14 — Finale (D112–D114)
Cartes : `ROUTE128` → `EVER_GRANDE_CITY` → `VICTORY_ROAD_1F/B1F/B2F` → Ligue (salles vanilla) → `HALL_OF_FAME`.
- [R] Route Victoire : Blue final (ID `WALLY_VR_1..5` + `WALLY_MAUVILLE` = 6 variantes) (D112). [V/R] Conseil 4, Pierre Rochard (D113, D114). Épilogue variable.

### Postgame (D115–D120)
`GAME_SYSTEMS.md` §7 : lien PC, Ariane, Groudon, Zone de Combat, lettres, départ.

## 7. Red, sa force et la difficulté
- **Équipe de départ :** aucune. Pikachu (son partenaire) est blessé au prologue et reste au labo ; Seko confie un **starter de Hoenn** niveau 5. Pikachu revient au ch. 4 (ou ch. 5 selon D002/D038) au niveau **plafond − 2** (fonction d'aide moteur), avec un set « rééducation » ; il ne dépasse jamais le plafond.
- **Équipe légendaire** (Florizarre, Dracaufeu, Tortank, Ronflex, Lokhlass) : bloquée dans les PC de Kanto (lien coupé). Elle peut revenir **au postgame** (D094, D115), sous le plafond postgame.
- **Plafonds souples par jalon d'histoire** (`GAME_SYSTEMS.md` §3) : EXP réduite au-delà ; les combats majeurs sont calés à plafond + 2 au plus.
- **Ce que Red apporte :** son savoir (option « lire l'adversaire » dans certaines scènes : Red identifie un Pokémon Kanto ou une méthode Rocket), sa notoriété (des portes s'ouvrent ou se ferment, D005), et sa présence (choisir où il est, D106). **Sa force ne suffit jamais à résoudre un problème non combattu.**

## 8. Gimmick (Méga) — décision
Méga-Évolution seule pendant l'aventure (Z, Dynamax, Téra non câblés). Démonstration sûre : duo avec Pierre Rochard à la Route 120 (ch. 8), puis Méga-Bracelet. Premières Méga adverses : Lévy & Tatia (ch. 10), Juan (ch. 12). La Team Rocket n'en a pas ; Blue en a une à partir de Nénucrique. Méga-Gemmes : rares, liées à des décisions et des lieux (`GAME_SYSTEMS.md` §6).

## 9. Fins (résumé ; conditions formelles en `GAME_SYSTEMS.md` §8)
| Fin | Volcan | Réfugiés | Ton |
|---|---|---|---|
| F1 « Terre d'accueil » | maîtrisé | intégration | compromis réussi, cicatrices |
| F2 « La paix armée » | maîtrisé | relogés ou rapatriés | sécurité au prix de l'accueil |
| F3 « Cendres partagées » | éruption limitée | intégration | perte matérielle, solidarité |
| F4 « La digue » | éruption limitée | relogés ou rapatriés | séparation, colère, reconstruction |
| F5 « Ce qui reste » | éruption majeure, ou exode | — | deuil, espoir porté par Brice et les enfants |
Variantes d'épilogue indépendantes : Rocket (démantelée / en fuite), Brice (alliance / distance / rupture), notoriété de Red (anonyme / connu / légende), Arche (Devon / Ligue / restituée).

## 10. Table des portes et traversée (vérifiée sur les scripts vanilla)

### 10.1 Bloqueurs vanilla et leur sort
| # | Bloqueur vanilla (carte : mécanisme) | Sort | Remplacement / note |
|---|---|---|---|
| G1 | `LittlerootTown` : jumelle qui garde la Route 101 (`VAR_LITTLEROOT_TOWN_STATE` 0) | modifié | état mis à jour par notre script de départ (le joueur arrive par le nord) |
| G2 | `Route101` : sauvetage de Seko (`FLAG_RESCUED_BIRCH`) | supprimé | posé à la nouvelle partie ; scène remplacée par le labo |
| G3 | `OldaleTown` : homme aux empreintes (`FLAG_ADVENTURE_STARTED`) | conservé | posé au labo |
| G4 | `PetalburgCity` : Timmy, sa mère, déclencheurs de visite d'arène (`VAR_PETALBURG_CITY_STATE`) | supprimé/modifié | Timmy masqué ; état mis à 1 ; Norman registraire |
| G5 | `PetalburgWoods` : sbire Aqua + chercheur Devon (`VAR_PETALBURG_WOODS_STATE`) | remplacé | Galopa (D010) ; Aqua masqué |
| G6 | `RustboroCity` → vol des Pièges Devon → `Route116`/`RusturfTunnel` (Peeko, sbire ; `FLAG_DEVON_GOODS_STOLEN`, `FLAG_RECOVERED_DEVON_GOODS`, `VAR_BRINEY_HOUSE_STATE`) | remplacé | aucun vol ; `VAR_BRINEY_HOUSE_STATE` = 1 et `FLAG_RECOVERED_DEVON_GOODS` posés par le script Devon après badge 1 ; Peeko chez M. Marcel |
| G7 | `Route104_MrBrineysHouse` : départs selon `FLAG_DELIVERED_STEVEN_LETTER` / `FLAG_DELIVERED_DEVON_GOODS` | conservé | sens identique (livraisons) |
| G8 | `DewfordTown` : départ vers Poivressel si lettre livrée | conservé | — |
| G9 | `SlateportCity` : file Aqua au musée (`FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA`) ; `Route110` : 5 sbires (`FLAG_HIDE_ROUTE_110_TEAM_AQUA`, posé au musée) | remplacé | manifestation ; piquet des pêcheurs levé par `FLAG_HS_QUAI_REGLE` (D025) |
| G10 | `Route110` : rival (`VAR_ROUTE110_STATE`) | conservé | Brice 2 |
| G11 | `MauvilleCity` : Timmy et son oncle devant l'arène ; libération du tunnel (`VAR_RUSTURF_TUNNEL_STATE`) | supprimé/remplacé | masqués ; tunnel dégagé par notre raid |
| G12 | `Route111` sud : rochers (Éclate-Roc) | conservé | badge 3 |
| G13 | `Route112` : sbires Magma au téléphérique (`FLAG_HIDE_ROUTE_112_TEAM_MAGMA`, posé au Site Météore) | remplacé | sécurité du chantier ; même drapeau, posé par notre événement |
| G14 | `MeteorFalls_1F_1R` : vol de la météorite (`VAR_METEOR_FALLS_STATE`) | remplacé | capteur de Cosmo (1F_1R seulement) |
| G15 | `MtChimney` : Max/Kelvin/sbires ; `VAR_JAGGED_PASS_ASH_WEATHER` | remplacé | chantier ; nos objets ; la descente vers le Chemin Ardent est libre |
| G16 | `LavaridgeTown` : rival → Lunettes Sable (`FLAG_RECEIVED_GO_GOGGLES`) | conservé | Brice |
| G17 | `JaggedPass` : entrée de la Planque Magma (garde, `VAR_JAGGED_PASS_STATE`), ouverte via le Mont Mémoria | remplacé | ouverte par `FLAG_HS_VISITE_CHANTIER` (ch. 6) |
| G18 | `PetalburgCity_Gym` : 4 badges (`VAR_PETALBURG_GYM_STATE`) ; CS Surf par le père de Timmy | conservé/remplacé | Norman remet Surf |
| G19 | `Route118` : Pierre (`VAR_ROUTE118_STATE`) | conservé | caméo réécrit |
| G20 | `Route119` : sbires Aqua du pont (`FLAG_HIDE_ROUTE_119_TEAM_AQUA`, posé par l'Institut 2F) ; rival → Vol (`VAR_ROUTE119_STATE`) | remplacé/conservé | occupation de l'Institut par Aqua ; Brice remet Vol |
| G21 | `FortreeCity` / `Route120` : Kecleon + Scope Devon | conservé | + Méga-Bracelet |
| G22 | `Route121` : scène Aqua (`VAR_ROUTE121_STATE`) | supprimé | état final à la nouvelle partie |
| G23 | `LilycoveCity` : 5 sbires bloquant la Route 124 (`FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS`, posé par `AquaHideout_B2F`) | remplacé | blocus Aqua ; posé quand planque **et** Mont Mémoria sont faits |
| G24 | `AquaHideout_1F` : gardes d'entrée (masqués par `SlateportCity_Harbor`) | remplacé | masqués par D081 ; script du port neutralisé |
| G25 | `MtPyre_Summit` : Orbes, pose `FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD` | remplacé | rite, Orbe Rouge (D085) ; ne touche plus le Chemin Ardent |
| G26 | `MagmaHideout_4F` : Groudon (`FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT`) → port de Poivressel | remplacé | chaîne coupée ; 4F seulement au climax si volcan ≥ 70 |
| G27 | `MossdeepCity_Gym` : arme le Centre Spatial (`VAR_MOSSDEEP_CITY_STATE`), pose `FLAG_HIDE_AQUA_HIDEOUT_GRUNTS` | conservé/modifié | armement conservé ; pose Aqua neutralisée |
| G28 | `MossdeepCity` : sbires Magma devant le Centre Spatial | remplacé | sbires Rocket (objets réhabillés) |
| G29 | `MossdeepCity_StevensHouse` : CS Plongée, garde de Fondmer | conservé | + Méga-Gemme |
| G30 | `SeafloorCavern_Room9` : Kyogre, `FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN` | remplacé | contre-expertise ; drapeau jamais posé |
| G31 | `Route128` : scène Pierre/Max/Arthur | supprimé | drapeaux de masquage posés à la nouvelle partie |
| G32 | `SootopolisCity` : portes verrouillées (`FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE`), états légendaires | remplacé | état normal ; fin du Conseil pose le drapeau |
| G33 | `SkyPillar_*` : ouvert par Marc après la crise | différé | postgame (Rayquaza) ; layouts `_CLEAN` jusqu'au postgame |
| G34 | `Route128` → `EverGrandeCity` : Cascade | conservé | badge 8 |
| G35 | `VictoryRoad_1F` : Timmy | remplacé | Blue final |
| G36 | Ligue, Panthéon, `FLAG_SYS_GAME_CLEAR`, ferry de la Zone de Combat | conservé | — |

Règle de production : chaque script vanilla qui touche Magma/Aqua/Timmy est audité (grep) et listé dans un fichier de suivi avant modification ; les objets vanilla réutilisés gardent leur drapeau seulement si **tous** ses lecteurs/écrivains sont réécrits (sinon nouveau drapeau `FLAG_HS_*`).

### 10.2 Traversée par chapitre (capacités requises)
| Ch. | Trajet obligatoire | Capacités requises | Donneurs |
|---|---|---|---|
| 0 | R104 plage → Clémenti → R102 → Rosyères → R101 → Bourg-en-Vol → R103 | aucune | — |
| 1 | Bourg-en-Vol → Clémenti → R104 → Bois → Mérouville → R116 | aucune | Coupe (Roxanne, B1) |
| 2 | R104 (bateau) → Myokara → Grotte Granite | Flash facultatif (B2F sombre) | Flash (Bastien, B2) |
| 3 | Myokara (bateau) → R107-109 → Poivressel → R110 sud | aucune | — |
| 4 | R110 → Lavandia → R117 → Vergazon → Tunnel (est) | Éclate-Roc (milieu du tunnel) | Éclate-Roc (maison de Lavandia, après B3) |
| 5 | Lavandia → R111 sud → R112 → Chemin Ardent → R113 → Autéquia → R114 → Site Météore 1F_1R | Éclate-Roc (R111) | — |
| 6 | R112 (téléphérique) → Mont Chimnée → Chemin Ardent → Vermilava → Planque Magma 1F/2F | aucune | Force (Adriane, B4) ; Lunettes (Brice) |
| 7 | Vermilava → R112 → R111 → Lavandia → R117 → Vergazon → Tunnel → R116 → Mérouville → R104 → Clémenti | aucune | Surf (Norman, B5) |
| 8 | Lavandia → R118 (Surf) → R119 → Institut → Cimetronelle → R120 | Surf | Vol (Brice, R119) ; Scope + Méga-Bracelet (Pierre, R120) |
| 9 | R120 → R121 → Nénucrique ; R122 (Surf) → Mont Mémoria | Surf | — |
| 10 | Nénucrique → R124 (Surf) → Algatia | Surf | Plongée (Pierre, maison, après B7 et Centre Spatial) |
| 11 | R127/R128 → plongée → Fondmer | Surf, Plongée, Force, Éclate-Roc | — |
| 12 | R126 → plongée → Atalanopolis | Plongée | Cascade (Juan, B8) |
| 13 | Vol → Vermilava → Chemin Ardent → Planque Magma | Vol | — |
| 14 | R128 → Éternara → Route Victoire | Surf, Cascade, Force, Éclate-Roc, Flash | — |

### 10.3 Soins accessibles
| Zone exigeante | Soin le plus proche | Ajout |
|---|---|---|
| Bois Clémenti | Centre de Clémenti (1 carte) | — |
| Tunnel Mérazon (raid) | Centre de Vergazon (1 carte) | Brice soigne avant l'assaut |
| Site Météore 1F_1R | Centre d'Autéquia (1 carte) | — |
| Mont Chimnée / galeries | Centre de Vermilava (2 cartes) | **médecin du chantier** au sommet et à l'entrée de la planque (soin complet) |
| Institut Météo | lit de l'Institut (vanilla) | — |
| Planque Aqua | Centre de Nénucrique (1 carte) | — |
| Mont Mémoria | Centre de Nénucrique (2 cartes) | Spectra soigne à l'extérieur |
| Centre Spatial | Centre d'Algatia (1 carte) | — |
| Fondmer | aucun (9 salles) | **plongeur-secouriste d'Aqua** à l'entrée (soin complet) |
| Climax | Centre de Vermilava | soin forcé avant D106 |

## 11. Secrets (ne pas révéler avant leur moment)
| Secret | Révélé | Ne pas laisser fuiter via |
|---|---|---|
| Rocket vole les Pokémon des réfugiés | ch. 4 (R1) | Red reconnaît « des méthodes » au ch. 1, sans nom |
| « Lambert » est Lambda | ch. 10 | indices : portefeuille (D011), absence (D058), voix radio (D040) |
| Les sabotages sont de Rocket, pas d'Aqua | ch. 8 (R2) | Aqua est soupçonné par Devon et Magma jusque-là |
| Opération Braise (date, cible : l'Arche) | ch. 10 (R3) | lettre d'Ariane (D071) en donne la moitié |
| Groudon dort sous le chantier | ch. 9 (légende) | Cosmo parle seulement d'« une masse chaude » |
| L'équipe de Red est intacte à Kanto | ch. 10 (Lanette) | Red ne le sait pas ; Chen l'évoque (D007) |

## 12. Invariants (arbitrage du GMD obligatoire pour les changer)
1. Le joueur est Red, muet ; ses choix sont des **gestes et des actes** (montrer, désigner, rester, partir, donner).
2. Brice a une **voix décisive** : au moins 15 décisions dépendent de sa confiance ; il peut agir seul.
3. Aucune faction n'a entièrement tort ; aucun texte ne désigne « le bon camp ».
4. Les problèmes non combattus (volcan, accueil, mer, Conseil) ne se règlent **jamais** par une victoire de combat seule.
5. Avenir canonique préservé : Red part vers le nord ; Blue est en route vers Jadielle ; Giovanni n'apparaît pas et n'obtient rien.
6. Pas de farming comme solution : plafonds souples, dresseurs non revanchables avant le postgame, argent et soins rationnés.
7. Ordre des badges et correspondance badges → capacités vanilla conservés.
8. Aucune espèce, sprite, donnée ou animation d'attaque modifiés ; pas de carte neuve sans dérogation.
9. Toute décision du registre a un effet **observable** et un **test**.

## 13. Contraintes techniques (contraignantes)
| Domaine | Contrainte | Conséquence |
|---|---|---|
| Dresseurs | ~855 ID, **9 libres** | réaffectation des ID vanilla (`COMBAT_DESIGN.md` §4) |
| Flags / vars | 372 / 55 libres | budget : ~260 flags, ~30 vars (`GAME_SYSTEMS.md` §9) ; drapeaux neufs `FLAG_HS_*` |
| Sauvegarde | SB1 376 o | aucune structure nouvelle ; tout en flags/vars |
| Code | IWRAM quasi plein | uniquement des aides légères (affinités, niveau de Pikachu, cases musicales, classes) via `ENGINE_CHANGES.md` |
| Texte | ≤ 208 px/ligne, 2 lignes/boîte | une idée par boîte ; options de `multichoice` courtes |
| Assets Kanto | portraits RFVF compilés ; sprites OW RFVF à porter | dépendance `ENGINE_CHANGES.md` ; repli : OW génériques |
| Fonctions moteur | combats déclinables, choix du Pokémon de tête, avatar Red, aides d'affinité | `ENGINE_CHANGES.md` (en cours) |
| Volume | cible 15-20 h | ~1 500 boîtes de texte, ~45 cartes réécrites, ~150 équipes |

## 14. Changelog
| Date | Version | Changement | Raison | Auteur |
|---|---|---|---|---|
| 2026-10-13 | 1.0 | « Heure suspendue » (archivée) | brief v1 | GMD |
| 2026-10-14 | 2.0 | Nouvelle bible : *Pokémon Cendres* ; Red joueur, Brice second protagoniste, cadre année 1, factions réinventées, 5 fins, table des portes vérifiée sur scripts, plafonds par jalons, Méga au ch. 8 | brief v2 | GMD |
