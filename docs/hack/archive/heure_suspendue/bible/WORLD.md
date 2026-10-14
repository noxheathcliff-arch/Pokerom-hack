# Bible — Monde, mystère et quêtes (*Pokémon Heure Suspendue*)

> Partie de `GAME_DESIGN_BIBLE.md`. Toute modification passe par le GMD.
> Étiquettes : ce qui relève du canon est marqué `[CANON-JEU : X]` (cf. LORE_DOSSIER) ; tout le reste est **invention du hack** (canon interne du jeu, contraignant pour la production).

---

## 1. Règles du monde

### 1.1 Les cloches anciennes (canon interne)
1. Le **peuple du Sanctuaire** (`[CANON-JEU : RSE]` : un peuple ancien a « tout dû aux Pokémon » puis les a « scellés » par « peur ») a fondu des **cloches** dans un alliage inconnu (le « métal qui sonne seul »).
2. Une cloche peut jouer deux mélodies :
   - le **carillon** (mélodie montante) : *fige* le temps autour d'elle — rien n'y change plus, rien n'y meurt, rien n'y naît ;
   - le **glas** (même mélodie jouée à l'envers) : *délivre* — il laisse aller ce qui était retenu.
3. Une cloche **accordée** (sur laquelle on a joué le carillon) maintient un **Figement** dans un rayon d'un lieu (une carte, parfois quelques cartes).
4. Il existe des dizaines de cloches enfouies dans Hoenn. Si **sept** cloches sont accordées *en même temps* et que la **Cloche Mère** sonne le carillon depuis le **clocher** (le Pilier Céleste), le Figement de la Cloche Mère devient **permanent** et ne peut plus être délivré. C'est le but d'Ysaline : figer pour toujours le sommet du Mont Mémoria.
5. Délivrer un Figement **désaccorde** sa cloche ; Ysaline doit en accorder une autre ailleurs. D'où une suite de Figements malgré les délivrances du joueur, et l'escalade (Atalanopolis entière, ch. 13-14) quand elle manque de temps.
6. Avant qu'un Figement ne se forme, la cloche « résonne » pendant quelques secondes (le **tintement**, enregistré par l'Institut Météo) et les êtres sensibles au malheur le perçoivent : **Absol** arrive *la veille* `[CANON-JEU : RSE Pokédex — Absol apparaît avant les catastrophes]`.
7. Les **Pokémon-cloches** (Archéomire, Archéodong `[CANON-JEU : DP — vénéré comme dieu de la pluie, aurait ouvert des passages]`, Éoko `[CANON-JEU : RSE — vit au sommet du Mont Mémoria]`, Korillon) sont attirés par les cloches anciennes et se figent en se blottissant contre elles : ce sont les **cloches-pivots** que le joueur doit affronter.
8. Le **Diapason** du peuple ancien (trouvé par Gaspard) fait vibrer une cloche hors de son accord : utilisé après avoir calmé la cloche-pivot, il la désaccorde (délivrance).
9. Les **Regis** sont les gardiens que le peuple a figés en premier `[INTERPRÉTATION fondée sur les Pokédex RSE : roches de plusieurs époques, glace d'une ère glaciaire, métal durci pendant des dizaines de milliers d'années]`. Le peuple s'est ensuite figé lui-même.
10. Le **Pilier Céleste** est le **clocher** du peuple ancien (le canon laisse son bâtisseur inconnu `[CANON-JEU : RSE/ROSA]` ; c'est notre réponse). Rayquaza y dort au sommet `[CANON-JEU]` ; il s'éveille *après* le glas (postgame).
11. Le Mont Mémoria a gardé la **Cloche Mère** depuis des siècles, sans savoir ce qu'elle était : on y sonnait le glas des funérailles (la moitié « délivrance », transmise oralement). Ysaline, en étudiant les vieux registres des gardiens, a retrouvé le carillon.

### 1.2 Le Figement — règles jouables (contrat pour la production)
| Élément | Règle | Implémentation (spéc. initiale) |
|---|---|---|
| Visuel | brume (`WEATHER_FOG_HORIZONTAL`) en extérieur, ombre (`WEATHER_SHADE`) en intérieur/forêt | `setweather` + `doweather` dans `ON_TRANSITION` si `FLAG_FIG_n_ACTIF` |
| Son | `MUS_SEALED_CHAMBER` | `playbgm` / musique de carte conditionnelle |
| PNJ figés | immobiles (`MOVEMENT_TYPE_FACE_*`), répètent leur dernière phrase en gris | objets dédiés, visibles seulement si Figement actif (flags `HIDE`) ; texte `{COLOR}` gris |
| Objets suspendus | visibles, non ramassables (« L'objet flotte, immobile. ») ; ramassables après délivrance | deux objets superposés, échangés par flag |
| Rencontres | **aucune** | **N1** : flag temporaire `FLAG_TEMP_FIGEMENT` (plage 0x05-0x0D, remis à zéro à chaque changement de carte) posé en `ON_TRANSITION` ; crochet de quelques lignes dans la tentative de rencontre (code ROM, pas IWRAM). Repli sans C : Figements placés sur zones sans herbe, ou `Repousse` scriptée |
| Heure | suspendue | **H4 à prototyper** : `OW_USE_FAKE_RTC` + `OW_FLAG_PAUSE_TIME` ; repli : cosmétique seul |
| Dresseurs | Carillonneurs actifs (ils portent des grelots accordés) | dresseurs normaux |
| Soin | aucun dans la zone ; point de soin ≤ 1 carte de l'entrée | placement |
| Cœur | cloche-pivot Dominant, non capturable | `setwildbattle` + `settotemboost` + `WE_FLAG_NO_CATCHING` (flag à assigner) |
| Délivrance | après victoire : « Utiliser le Diapason ? » → flash, `FLAG_FIG_n_ACTIF` effacé, rafraîchissement de la carte | script commun `Common_EventScript_Delivrance` |
| Indice | 1 fragment (Braille ou témoignage) par Figement | flag d'indice → Carnet |

### 1.3 Clause de contrat de design — système « Figement »
- **Structure dominante :** progression (chaque Figement est une porte pré-dessinée) avec émergence locale (combats dans un donjon d'attrition).
- **Famille dominante :** économie interne (attrition sans rencontres ni soins) + tactique (combat Dominant).
- **Économie interne :** ressources PV/PP/objets ; pas de source dans la zone (ni rencontres ni soins), puits = Carillonneurs + Dominant ; récompense = objets suspendus + retour des rencontres (1-2 espèces nouvelles). Feedback : négatif local (on s'use) coupé par la sortie proche.
- **Espace de possibilités :** profond (séquence de combats sans soin) plus que large.
- **Stratégie dominante prévisible :** foncer au cœur avec le Pokémon le plus fort. **Contrebalancement :** Dominant boosté sur la stat qui punit cette approche (Déf/Déf Spé), Carillonneurs à Distorsion/Requiem qui punissent le « tout-en-un ».
- **Signification :** un lieu figé ne produit plus rien (ni rencontres, ni heure) ; le délivrer *redonne* de la vie (rencontres, objets) — « ce qui est figé n'enseigne plus rien ».
- **Ce qu'il reste à apprendre :** chaque Figement ajoute une contrainte (mission d'évacuation, marées, ville sans Centre, montée sans soin).

## 2. Chronologie (canon interne)

| Époque | Événement |
|---|---|
| Temps mythiques | Groudon et Kyogre s'affrontent ; Rayquaza les apaise `[CANON-JEU : RSE/E]` |
| Après la colère des titans | Le peuple du Sanctuaire, qui a vu tout perdre en un jour, fond les cloches, bâtit le clocher (Pilier Céleste), fige ses trois gardiens (Regis) puis lui-même. Inscriptions du Sanctuaire `[CANON-JEU : RSE]`, réinterprétées |
| Il y a plusieurs siècles | Le Mont Mémoria devient cimetière ; la Cloche Mère y est trouvée et sert au glas des funérailles ; le carillon est oublié |
| −60 ans | Naissance d'Augure (Natu) ; Ysaline, enfant, le reçoit |
| −50 ans | Ysaline devient sonneuse de glas, formée par le vieux couple gardien |
| −20 ans | Naufrage du paquebot (l'Épave, `[CANON-JEU : RSE]` ; cause jamais donnée par le canon) ; la mère de Tierce disparaît. Aragon (Conseil 4), alors marin, participe aux secours |
| −15 ans | Catastrophe au village de Rocheval ; un Absol avait été vu la veille ; son frère meurt. Naissance des Veilleurs, plus tard |
| −1 an | Augure faiblit. Ysaline étudie les registres des gardiens, retrouve le carillon, rassemble des endeuillés (les Carillonneurs) |
| −1 mois | Ysaline prend la Cloche Mère ; premières cloches accordées. Effets parasites (horloge de Rosyères arrêtée) |
| Jour 0 | Le joueur arrive à Bourg-en-Vol |
| Climax | Le glas est sonné au clocher ; Augure s'éteint à l'aube |
| Après | Rayquaza s'éveille au sommet du clocher ; les tombeaux des Regis se « réveillent » (postgame) |

## 3. Architecture du mystère

### 3.1 Questions
| Q | Question du joueur | Posée (où) | Résolue (où) |
|---|---|---|---|
| Q1 | Qu'est-ce qui fige les lieux ? | ch. 0 Rosyères, ch. 1 Bois | **R1** ch. 5 Tunnel Mérazon |
| Q2 | Absol en est-il la cause ? | ch. 1 Route 104 | **R2** ch. 10 repaire des Veilleurs |
| Q3 | Pourquoi Ysaline fait-elle cela ? | ch. 5 | **R3** ch. 11 sommet du Mont Mémoria |
| Q4 | Que craignait le peuple ancien ? | ch. 3 Grotte Granite (Braille), ch. 10 Musée | **R4** ch. 13 Caverne Fondmer |
| Q5 | Qui guide le joueur (Absol, visions) ? | ch. 11 (Absolite tendue, vision) | **R5** ch. 15 Pilier Céleste |
| Q6 (coda) | Qui est la fillette de la photo ? | ch. 11 | Conseil 4 (Spectra) |

### 3.2 Indices (où / quand / vers quoi)
| # | Indice | Où | Ch. | Vers |
|---|---|---|---|---|
| I1 | Horloge de Rosyères arrêtée à 4 h 12 | `OLDALE_TOWN_POKEMON_CENTER_1F` | 0 | Q1 (effet parasite) |
| I2 | Grelot gravé de Braille dans le bois | `PETALBURG_WOODS` | 1 | R1 |
| I3 | Seko : « plus aucune rencontre là-dedans » | Labo / Route 104 | 1 | règle |
| I4 | Braille n°1 « LE SON ARRÊTE » | `GRANITE_CAVE_STEVENS_ROOM` | 3 | R1 |
| I5 | Cloche votive du Chenal 134, même alliage | `SLATEPORT_CITY_OCEANIC_MUSEUM_2F` | 4 | R1, R4 |
| I6 | Ysaline : « Qu'est-ce que tu refuserais de perdre ? » | marché de Poivressel | 4 | R3 |
| I7 | Braille n°2 « CE QUE NOUS AIMONS NE PASSERA PAS » | `RUSTURF_TUNNEL` | 5 | R4 |
| I8 | Cosmo : Absol vu *avant* l'arrêt du volcan | `FALLARBOR_TOWN_COZMOS_HOUSE` | 6 | R2 |
| I9 | Absol blessé qui ne fuit pas le joueur | `METEOR_FALLS_*` | 6 | R2, R5 |
| I10 | « Sans moi, Vermilava serait cendre » | `MT_CHIMNEY` | 7 | R3 (elle protège ce qu'elle aime) |
| I11 | Maman : la sonneuse aux funérailles de grand-mère | maison du joueur | 8 | R3 (le métier du glas) |
| I12 | New Lavandia figée sans Absol possible | `NEW_MAUVILLE_INSIDE` | 8 (fac.) | R2 |
| I13 | Relevés : tintement, Absol présent avant | `ROUTE119_WEATHER_INSTITUTE_2F` | 9 | R2, R1 |
| I14 | Exposition officielle « peur des monstres » | `LILYCOVE_CITY_LILYCOVE_MUSEUM_1F` | 10 | Q4 (fausse lecture) |
| I15 | Photo d'Ysaline jeune et d'une fillette | `MT_PYRE_6F` | 11 | Q6 |
| I16 | Absolite qui « tombe » vers le joueur ; vision | `MT_PYRE_SUMMIT` | 11 | R5 |
| I17 | Pierre : 5 cloches sur 7 accordées | `MOSSDEEP_CITY_SPACE_CENTER_2F` | 12 | règle 1.1.4 |
| I18 | Fresque et Braille du temple | `SEAFLOOR_CAVERN_ROOM9` | 13 | R4 |
| I19 | Visions répétées (« Un œil vers hier… ») à F2, F4, F5 | divers | 5-13 | R5 |

### 3.3 Fausses pistes (loyales)
| Fausse piste | Pourquoi on y croit | Pourquoi elle est loyale (indices contraires disponibles) | Démentie |
|---|---|---|---|
| **Absol cause les Figements** | il est vu près de chaque Figement ; les Veilleurs le disent ; mythe local | I8, I9, I12, I13 ; Pokédex `[CANON-JEU]` : « apparaît *avant* » | ch. 10 |
| **Les Figements sont bienveillants** | l'éruption figée protège Vermilava ; {RIVAL} les trouve beaux | personnes prises au piège, ville sans courant ; Adriane | ch. 7 (nuance), ch. 11 (but réel) |
| **Devon est impliqué** | le grelot est analysé chez Devon ; un ingénieur parle d'un « projet Résonance » | M. Rochard dit ne pas connaître l'alliage ; le projet est une étude acoustique | ch. 12 (Centre Spatial : instruments de mesure seulement) |
| **Le peuple ancien était un peuple de geôliers** | Braille canonique « nous les avons scellés » + exposition du Musée | I7 : « ce que nous aimons » | ch. 13 |

### 3.4 Révélations
- **R1 (ch. 5)** — Les Figements viennent de cloches anciennes, accordées par une personne : Ysaline.
- **R2 (ch. 10)** — Absol prévient ; il ne provoque rien.
- **R3 (ch. 11)** — Ysaline veut figer pour toujours le sommet où meurt son Xatu, Augure ; il faut sept cloches et la Cloche Mère.
- **R4 (ch. 13)** — Le peuple ancien a figé ce qu'il aimait (Regis, puis lui-même) par peur de le perdre ; le glas existe.
- **R5 (ch. 15)** — Augure, qui voit l'avenir, a guidé Absol et le joueur ; il veut partir.
- **Résolution** — Ysaline sonne le glas ; Augure s'éteint à l'aube ; le monde reprend.

Chaque révélation répond à une question déjà posée et en ouvre une autre (R1 → Q3 ; R2 → « alors qui guide Absol ? » ; R3 → Q4/Q5 ; R4 → « où est la seconde moitié ? »).

## 4. Lieux (rôle et description)

| Lieu | Carte(s) | Rôle | Description / ambiance |
|---|---|---|---|
| Bourg-en-Vol | `LITTLEROOT_TOWN` | départ | vanilla ; l'horloge de la chambre comme motif |
| Rosyères | `OLDALE_TOWN` | premier signe | l'horloge du Centre arrêtée |
| Bois Clémenti | `PETALBURG_WOODS` | F1 tutoriel | crépuscule figé ; pique-nique interrompu ; Peeko suspendu |
| Mérouville / Devon | `RUSTBORO_CITY`, `DEVON_CORP_*` | analyse du grelot | ville de pierre et d'ingénieurs |
| Grotte Granite | `GRANITE_CAVE_*` | Braille n°1, Pierre | obscurité, Flash |
| Poivressel | `SLATEPORT_CITY`, musée | Veilleurs, Ysaline | marché animé ; tribune des Veilleurs ; étal de grelots |
| Lavandia | `MAUVILLE_CITY` | ville en panne | générateurs de secours ; humour sur le Casino éteint |
| Tunnel Mérazon | `RUSTURF_TUNNEL` | F2, R1 | Chuchmur figés en plein cri |
| Site Météore | `METEOR_FALLS_*` | traque d'Absol | cascades ; escorte |
| Mont Chimnée | `MT_CHIMNEY` | F3 | éruption figée en colonne ; cendres immobiles |
| Vermilava | `LAVARIDGE_TOWN` | évacuation | village vidé puis intact |
| Route 119 / Institut | `ROUTE119`, `WEATHER_INSTITUTE_*` | F4 | rideau de pluie suspendue |
| Nénucrique | `LILYCOVE_CITY`, musée, `AQUA_HIDEOUT_*` | R2 | musée (fausse lecture), repaire des Veilleurs sous la crique |
| Mont Mémoria | `MT_PYRE_*` | R3 | deuil, brume immobile au sommet, Xatu face au soleil |
| Algatia / Centre Spatial | `MOSSDEEP_CITY_*` | Méga | instruments, duo avec Pierre |
| Grotte Tréfonds | `SHOAL_CAVE_*` | F5 | marée arrêtée |
| Caverne Fondmer | `SEAFLOOR_CAVERN_*` | R4 | temple englouti, fresque |
| Atalanopolis | `SOOTOPOLIS_CITY` | F6 | ville entière figée ; Marc devant la Grotte Origine |
| Pilier Céleste | `SKY_PILLAR_*` | finale | clocher du peuple ancien, Cloche Mère au sommet |
| Épave | `ABANDONED_SHIP_*` | quête A2 | naufrage « rejoué » par des fantômes |

## 5. Quêtes

### 5.1 Quête principale
Chapitres 0-16 (`CHAPTERS.md`). Objectif lisible à tout moment : par PNJ de ville (« On dit que… ») et par le **Carnet de Gaspard** (dernière entrée = prochaine piste).

### 5.2 Quêtes annexes (chacune a un but au-delà du remplissage)
| ID | Titre | Ouverture → fin | But de design | Récompense |
|---|---|---|---|---|
| A1 | **L'Exposition** | Musée de Nénucrique ch. 10 → après R4 | « Lire le monde » récompensé ; état persistant (le texte du musée change) ; payoff de Q4 | CT + plaque de Braille lisible (indice postgame) |
| A2 | **Le Dernier Quart** | Épave ch. 8 → Plongée (ch. 12+) | miroir du thème à échelle humaine ; arc de Tierce ; enseigne Requiem avant Fondmer | Rune Sort ◐ ; Branettite ◐ en postgame |
| A3 | **Les lumières de Lavandia** | ch. 8 (Surf) | Figement facultatif = preuve I12 pour R2 ; récompense le joueur curieux | CT Change Éclair ◐ |
| A4 | **La Tour Mirage** | Route 111 nord (après Lunettes) | coût irréversible du savoir ; Gaspard veut les deux fossiles, le joueur choisit (vanilla : la tour s'effondre) | fossile ; ligne d'arc de Gaspard |
| A5 | **Avis d'alerte** | après R2 | le monde réagit ; anciens chasseurs à convaincre (6 PNJ) | objets, Baies |
| A6 | Maison des Pièges [V] | Route 110 | énigmes | vanilla |
| A7 | Revanches de dresseurs [V] | Match Call | rejouabilité | vanilla |

### 5.3 Méga-Gemmes (emplacements ; noms FR ◐ à vérifier)
| Gemme | Où | Quand |
|---|---|---|
| Absolite | sommet du Mont Mémoria | ch. 11 |
| Gemme du starter (Jungkonite / Braségalite / Laggronite) | Pierre, avec le Méga-Bracelet | ch. 12 |
| Sablaineite ou Mysdibulite (choix) | Pierre (choix entre deux) | ch. 12 |
| Méditikkanite | Lévy & Tatia, après le badge | ch. 12 |
| Oniglalite | Grotte Tréfonds, salle de glace | ch. 13 |
| Sharpedite | Caverne Fondmer | ch. 13 |
| Élecsprintite | Rocheval, Pacifiville | ch. 14 |
| Camérupite | Adriane (retour à Vermilava après ch. 12) | facultatif |
| Altarite | Alizée (retour à Cimetronelle après ch. 12) | facultatif |
| Gardevoirite / Gallamite, Métalossite, Drattakite, Latiasite / Latiosite, Branettite | postgame | P3-P6 |

## 6. Postgame — « Les instants perdus »
| ID | Contenu | Cartes | Clé |
|---|---|---|---|
| P1 | **Le peuple qui attendait** : les trois tombeaux s'ouvrent avec le Braille du Sanctuaire (énigmes Émeraude [V], textes réécrits : le joueur *délivre* les gardiens) ; dernière salle : un message du peuple (« Merci d'avoir sonné. ») | `SEALED_CHAMBER_*`, `DESERT_RUINS`, `ISLAND_CAVE`, `ANCIENT_TOMB` | Wailord + Relicanth [V] |
| P2 | **Le gardien du clocher** : Rayquaza éveillé au sommet du Pilier ; capture ; Méga-Rayquaza via Draco Ascension (tuteur : vieux couple du Mont Mémoria) | `SKY_PILLAR_TOP` | Pilier |
| P3 | **L'île des images** : Latios/Latias (porteurs d'images, écho des visions) | `SOUTHERN_ISLAND_*` | Passe offert par Gaspard |
| P4 | **L'instant tombé du ciel** : Deoxys (météorite) | `BIRTH_ISLAND_*` | Passe offert par Pierre |
| P5 | **Zone de Combat** | `BATTLE_FRONTIER_*` | Scott, Aqualine [V] |
| P6 | **Revanches** : Ysaline (Mont Mémoria, équipe pacifiée + Natu), Rocheval, Marc, champions | divers | VS/Match Call |
| P7 | Groudon / Kyogre | Grottes Terra / Marine [V] | vanilla |
| Différé | Roc Nombri, Île Lointaine, second gimmick (H3-bis) | — | décision ultérieure |
