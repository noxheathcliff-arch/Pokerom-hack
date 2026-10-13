# GAME_DESIGN_BIBLE — *Pokémon Heure Suspendue*

> **Source unique de vérité du design.** Version **1.0** — 2026-10-13 — propriétaire : Game Mechanics Director.
> Toute décision de design, de scénario ou de progression vit ici ou dans un document lié ci-dessous. Toute modification passe par le GMD et est consignée au **changelog** (§14).
> Méthode : `GM_METHOD.md`. Intention : `EXPERIENCE_INTENT.md`. Choix de direction : `NARRATIVE_DIRECTIONS.md`.

## Documents liés (font partie de la bible)
| Document | Contenu |
|---|---|
| [`bible/CHARACTERS.md`](bible/CHARACTERS.md) | Distribution complète : objectifs, conflits, croyances, arcs, équipes-types, assets (portrait, sprite, classe, musique), relations |
| [`bible/CHAPTERS.md`](bible/CHAPTERS.md) | Scénario complet chapitre par chapitre, mappé sur les cartes (`MAP_*`), table de remplacement des événements vanilla, carte des serrures-clés, ce que sait le joueur à chaque étape |
| [`bible/WORLD.md`](bible/WORLD.md) | Règles du monde (Figements, cloches), chronologie, lieux, architecture du mystère (questions, indices, fausses pistes, révélations), quêtes principales et annexes, postgame |

---

## 1. Concept

**Une phrase :** *un Pokémon où le temps s'arrête par endroits, et où l'on doit comprendre pourquoi avant de le laisser repartir.*

**Prémisse.** Hoenn, de nos jours. Des lieux se **figent** : tout ce qui s'y trouve reste suspendu au dernier instant — un bois au crépuscule, une centrale en pleine panne, une éruption en plein jet, une ville entière. Les habitants accusent Absol, aperçu chaque fois la veille ; une milice, les **Veilleurs**, le traque. La cause est humaine et ancienne : **Ysaline**, la vieille sonneuse de glas du Mont Mémoria, a retrouvé l'art des **cloches** du peuple ancien du Sanctuaire. Son Xatu, compagnon de soixante ans, se meurt ; elle accorde à travers Hoenn un carillon de cloches anciennes pour figer le sommet du Mont Mémoria à jamais, et chaque cloche accordée fige ce qui l'entoure. Le joueur, aidé d'un ruinemaniaque qui lit le Braille, apprend à délivrer les lieux figés, comprend ce que le peuple ancien redoutait vraiment, et finit par sonner le **glas** — la mélodie inverse, celle qui laisse partir.

## 2. Thèmes et propos

- **Thème central :** *Ce qu'on refuse de perdre, on finit par l'empêcher de vivre.*
- **Thèmes secondaires :** le deuil et ses étapes ; accuser le messager au lieu de lire les signes ; le savoir qui se perd ou se réécrit ; grandir = accepter de changer.
- **Propos mécanique (sémiotique, GM_METHOD §4.11) :** *ce qui est figé n'enseigne plus rien.* Les Figements sont des zones sans rencontres, sans heure, sans changement — des mondes « maîtrisés » et morts. Le joueur progresse par le changement (évolution, Méga-Évolution, rotation d'équipe) ; l'antagoniste combat avec le temps tordu (Distorsion, Requiem, Prescience) et ne méga-évolue jamais.
- **Ton :** aventure lumineuse traversée de mélancolie. Jamais gore, jamais cynique. La mort est présente (Mont Mémoria, Xatu) et traitée avec douceur. Humour par les PNJ ordinaires.
- **Cohérence avec l'intention :** la compétence récompensée — *observer, formuler une hypothèse, préparer, vérifier* — est la même dans l'enquête et dans les combats (EXPERIENCE_INTENT §1).

## 3. Identité

| Élément | Décision |
|---|---|
| Titre | **Pokémon Heure Suspendue** |
| Titre en-tête ROM (≤ 12 car.) | `HEURESUSPEND` |
| Région | **Hoenn**, noms FR vanilla conservés (aucun renommage global) |
| Langue | Français |
| Signature visuelle | lieux figés : brume/ombre (`WEATHER_FOG_HORIZONTAL` / `WEATHER_SHADE`), PNJ immobiles en pleine action, objets suspendus ; musique du Figement : `MUS_SEALED_CHAMBER` |
| Signature sonore du climax | `MUS_MT_PYRE`, `MUS_ABNORMAL_WEATHER`, silence avant le glas |
| Pokémon emblèmes | **Absol** (le messager), **Xatu** (celui qui voit), **Archéomire/Archéodong** et **Éoko** (les cloches) |
| Gimmick | **Méga-Évolution** (§7) |
| Accroche de jaquette | « Le temps s'est arrêté. Quelqu'un l'a voulu. » |

## 4. Synopsis complet

**Prologue (Bourg-en-Vol → Route 103).** Le joueur emménage à Bourg-en-Vol. Sur la Route 101, il sauve le Prof. Seko et choisit son starter. À Rosyères, l'horloge du Centre Pokémon s'est arrêtée pendant la nuit ; une rumeur parle d'un « bois qui ne bouge plus ». Premier combat contre {RIVAL}, l'enfant de Seko, qui veut *tout consigner* dans son Pokédex.

**Acte I — Les premiers silences (badges 1 à 3).** Le Bois Clémenti est figé au crépuscule ; des promeneurs y sont pris en plein geste, et Peeko, le Goélise de M. Marcel, y est suspendu en vol. À l'orée, le joueur rencontre **Gaspard**, ruinemaniaque, qui lui confie un **Diapason** ancien et lui montre comment faire vibrer la **cloche-pivot** au cœur du Figement : un Archéomire figé qui se défend (combat Dominant). Le bois repart ; Peeko est libre. Des **Veilleurs** surgissent, à la poursuite d'un Absol aperçu la veille. À Mérouville, Roxanne ; Gaspard demande de porter un fragment de cloche à Pierre Rochard, à la Grotte Granite, puis au conservateur du Musée de Poivressel. M. Marcel, reconnaissant, fait la traversée. À Myokara, Bastien ; à la Grotte Granite, Pierre lit avec le joueur une première **inscription en Braille** (« LE SON ARRÊTE »). À Poivressel, rassemblement des Veilleurs contre Absol ; une vieille dame vend des grelots au marché et demande au joueur ce qu'il refuserait de perdre — c'est Ysaline, qui ne cache pas son nom. À Lavandia, Voltère : la centrale de New Lavandia est figée en pleine panne, la ville est privée de courant. Au cœur du Figement, le joueur trouve **Ysaline en train d'accorder la cloche**. Elle ne fuit pas : « Ils ne souffrent pas. Ils attendent. » Elle part par un passage ; ses **Carillonneurs** couvrent sa retraite. **Révélation R1 : les Figements sont l'œuvre de cloches sonnées par des humains.**

**Acte II — Le carillon (badges 4 à 6).** Les Veilleurs bloquent le téléphérique de la Route 112 : ils traquent Absol vers le Site Météore. Le joueur le suit par les cendres (Routes 111, 113, Autéquia, Route 114) et protège Absol blessé dans le Site Météore (escorte, combat contre le capitaine **Rocheval**). Absol, sauvé, reste près du joueur (il peut le recevoir dans l'équipe). Au sommet du Mont Chimnée, l'**éruption est figée** en plein jet : la cloche d'Ysaline a, de fait, sauvé Vermilava. Le joueur et Adriane doivent **évacuer Vermilava** avant de délivrer le volcan : les cendres retombent sur la Route 113. Adriane, badge 4. Norman, badge 5 (Surf). Route 119 : une averse figée en rideau barre la route, l'Institut Météo est pris dans l'instant ; on délivre. {RIVAL} remet Vol après un combat ; il trouve les Figements « beaux, comme des photos ». Cimetronelle, Alizée, badge 6. À Nénucrique, les Veilleurs ont leur repaire sous la crique ; le joueur y apporte les preuves (témoignages « vu la veille », un Figement sans Absol possible à New Lavandia, le Pokédex) et bat Rocheval. **Révélation R2 : Absol prévient, il ne provoque pas.** Rocheval dissout la traque. Au Mont Mémoria, le vieux couple de gardiens révèle que la **Cloche Mère** a disparu. Au sommet, figé dans une brume immobile, un Xatu très âgé fixe le soleil. Ysaline est là. **Révélation R3 : elle accorde un carillon de cloches à travers Hoenn pour figer ce sommet à jamais et que son Xatu ne meure pas.** Elle propose au joueur de figer, lui aussi, ce qu'il aime. Refus ; combat ; elle sonne et disparaît dans la brume.

**Acte III — Le glas (badges 7 et 8, climax).** À Algatia, Pierre attend le joueur au Centre Spatial, où ses instruments mesurent les « ondes » du carillon ; les Carillonneurs attaquent pour voler les relevés : combat en duo avec Pierre, qui **méga-évolue son Métalosse** sous les yeux du joueur. Pierre remet le **Méga-Bracelet**. Lévy et Tatia, badge 7 (Plongée). La Grotte Tréfonds a cessé d'avoir des marées ; on y délivre une cloche. Sous le Chenal 128, la **Caverne Fondmer** est un ancien temple du peuple du Sanctuaire ; ses murs racontent la fin de ce peuple. **Révélation R4 : ils ont figé leurs gardiens (les Regis) puis eux-mêmes, par peur de perdre — « Nous en avions peur. »** Le Braille donne la première moitié de la **mélodie inverse**, le glas. À la sortie, **Atalanopolis entière est figée**. Marc (Wallace), resté hors du cratère, indique le **Pilier Céleste** : ce n'est pas une tour, c'est le clocher du peuple ancien. Ascension. Au sommet, Ysaline et la Cloche Mère. Combat final contre elle. Le joueur lit la seconde moitié du glas sur la cloche elle-même ; les visions qui le guidaient depuis le début prennent sens. **Révélation R5 : c'est le Xatu qui, voyant l'avenir, a envoyé Absol et les visions — il demande à partir.** Le choix final de sonner revient à Ysaline ; le joueur lui tend le Diapason. Elle sonne le glas. Hoenn repart. Au Mont Mémoria, le Xatu s'éteint au lever du soleil, Ysaline à ses côtés. Juan, badge 8 (Cascade).

**Finale — Ligue (Éternara).** Route Victoire : dernier combat contre {RIVAL}, qui a compris qu'on ne garde pas un instant en l'arrêtant. Conseil 4 (Damien, Spectra — qui évoque sa grand-mère, Ysaline —, Glacia, Aragon) puis le Maître **Pierre Rochard**. Panthéon. Épilogue : Ysaline sonne elle-même un glas au Mont Mémoria ; un œuf de Natu repose près d'elle.

**Postgame — Les instants perdus.** Les trois tombeaux du peuple ancien (Regis figés) se délivrent par le Sanctuaire ; Rayquaza s'est éveillé au sommet du Pilier Céleste ; l'Île du Sud et l'Île Aurore gardent des « instants perdus » ; la Zone de Combat ouvre ; revanches. Détail : `bible/WORLD.md` §6.

## 5. Structure en actes

| Acte | Chapitres | Badges | Durée cible | Révélations | Pic |
|---|---|---|---|---|---|
| Prologue | 0 | — | 0:00–0:40 | (questions posées) | Rival 1 |
| I — Les premiers silences | 1–5 | 1, 2, 3 | 0:40–6:00 | R1 | New Lavandia : Ysaline accorde la cloche |
| II — Le carillon | 6–11 | 4, 5, 6 | 6:00–14:00 | R2, R3 | Mont Mémoria : le Xatu figé |
| III — Le glas | 12–15 | 7, 8 | 14:00–20:00 | R4, R5 | Pilier Céleste : le glas |
| Finale | 16 | — | 20:00–22:00 | coda (Spectra) | Maître Pierre |
| Postgame | P1–P6 | — | 22:00+ | (instants perdus) | Regis, Rayquaza, Zone de Combat |

Scénario détaillé : `bible/CHAPTERS.md`.

## 6. Règles de jeu propres à l'histoire (résumé ; détail `bible/WORLD.md` §1)

1. **Figement** : zone où le temps est arrêté. Dedans : **aucune rencontre sauvage**, horloge suspendue, PNJ immobiles qui répètent leur dernière phrase, objets suspendus non ramassables, brume ou ombre, musique `MUS_SEALED_CHAMBER`. Les Carillonneurs y circulent (ils portent des grelots accordés).
2. **Cloche-pivot** : au cœur de chaque Figement, un Pokémon-cloche figé (Archéomire, Archéodong, Éoko, Korillon) se défend en **combat Dominant** (`settotemboost`), non capturable pendant le combat (`WE_FLAG_NO_CATCHING`).
3. **Diapason** (objet clé, chap. 1) : nécessaire pour faire vibrer la cloche-pivot. Après victoire, utiliser le Diapason délivre la zone : flash, la musique reprend, les PNJ bougent, les objets tombent et deviennent ramassables, les rencontres reviennent.
4. **Absol** apparaît **la veille** d'un Figement près du lieu (scripté par chapitre) : il annonce le chapitre suivant (affordance narrative).
5. **Carnet de Gaspard** (objet clé) : liste les fragments de Braille et témoignages recueillis (script de `msgbox` conditionné par flags).
6. **Visions** : en entrant dans certains Figements, un bref flash montre une silhouette d'oiseau vert et une phrase (« Un œil vers hier. Un œil vers demain. ») — indices de R5.

## 7. Décision gimmick (H3) — **Méga-Évolution**, seul gimmick de l'aventure

- **Pourquoi :** canon hoennien (la première Méga est née d'une prière et d'une météorite, LORE_DOSSIER §1.6 `[CANON-JEU : ROSA]`) ; lisible sur GBA (88 formes, sprites présents) ; sémiotique opposée aux Figements (*changer pour dépasser*) ; l'IA méga-évolue au premier tour (« tell » loyal, AI_AUDIT §6).
- **Obtention :** **Méga-Bracelet** (`ITEM_MEGA_RING`, nom FR à vérifier) remis par Pierre à Algatia, chap. 12, *après* une démonstration en duo (introduction sûre, GM_METHOD §4.9).
- **Séquence d'enseignement :** démonstration (duo avec Pierre, Méga-Métalosse) → libre usage (Absolite et 2 autres gemmes à portée) → échec peu coûteux (Carillonneurs du Tréfonds) → renforcement (Lévy & Tatia : un Méga adverse) → contrainte (Juan : Méga adverse + pluie) → combinaison (Conseil 4, Maître).
- **Antagoniste :** Ysaline et les Carillonneurs **n'utilisent jamais** la Méga (refus du changement). Les Veilleurs non plus (ils n'en ont pas les moyens).
- **Z, Dynamax, Téra :** **désactivés pendant l'aventure** (aucun objet clé distribué). Postgame : différé ; au plus un second gimmick en défi optionnel (H3-bis, §11).
- **Méga-Gemmes** : ressource **tangible et rare**, une par lieu notable, jamais en boutique avant le postgame. Liste et emplacements : `bible/WORLD.md` §5.3.

## 8. Arc de maîtrise appliqué (EXPERIENCE_INTENT §7 → épreuves concrètes)

| Phase | Couche | Enseignée par (combats mineurs) | Vérifiée par | Plafond (souple) |
|---|---|---|---|---|
| 1 | Types et PV | dresseurs Routes 102-104, Bois Clémenti | **Roxanne** (Roche) | 15 |
| 2 | Menace et boosts (Gonflette, reconnaître le balayeur) | Grotte Granite, dresseurs Myokara | **Bastien** (Combat) | 19 |
| 3 | Statut et tempo (paralysie, vitesse) | Routes 109-110, **Carillonneurs** de New Lavandia | **Voltère** (Électrik) | 24 |
| — | Changements sous pression (Poursuite, pièges) | **Veilleurs** (Routes 104, 110, 112, 114) | **Rocheval** 1 (Site Météore) | — |
| 4 | Champ de bataille : soleil, Sécheresse | Mont Chimnée, Chemin Ardent | **Adriane** (Feu) | 29 |
| 5 | Talents et objets tenus | Routes 117-118 | **Norman** (Normal) | 33 |
| 6 | Synergie et changements préventifs (immunités, pivots) | Route 119, Institut Météo | **Alizée** (Vol) ; **Rocheval** 2 (repaire) | 38 |
| — | Tempo inversé (Distorsion) | **Carillonneurs** (Mont Mémoria) | **Ysaline** 1 (sommet du Mont Mémoria) | — |
| 7 | Méga + double combat | duo avec Pierre, Grotte Tréfonds | **Lévy & Tatia** | 44 |
| 8 | Adaptation à une IA qui s'adapte | Caverne Fondmer, Pilier Céleste | **Ysaline** 2 (Pilier) ; **Juan** | 50 |
| Synthèse | Combinaison sous plafond | Route Victoire, {RIVAL} final | Conseil 4, **Pierre** | 58 |

Les plafonds sont des **valeurs initiales** (paramètres réglables, propriétaire : superviseur dresseurs). Équipes : `bible/CHARACTERS.md` (équipes-types) ; fiches combat majeur à produire au format GM_METHOD §5.4 / STRATEGY_RESEARCH §10.

## 9. Économie (résumé)

- **Attrition** : chaque Figement est un donjon *sans rencontres* mais avec Carillonneurs, sans soin intérieur : on y entre préparé ; un point de soin (PNJ ou Centre) est toujours à ≤ 1 carte de l'entrée.
- **Récompense de la délivrance** : les objets suspendus (vus avant, donc serrure vue avant clé) deviennent ramassables ; les rencontres reviennent avec **1-2 espèces nouvelles** utiles au défi suivant.
- **Méga-Gemmes** : rares, tangibles, liées aux lieux ; Absolite au sommet du Mont Mémoria (après R3).
- **Argent** : puits multiples (Boutiques, Grand Magasin, tuteurs, Baies) ; aucune vente de Méga-Gemme pendant l'aventure.
- **Information** : le Carnet de Gaspard ; les équipes des Carillonneurs suivent un thème annoncé (indices utiles en combat).

## 10. Contraintes techniques de conception (contraignantes)

| Domaine | Contrainte | Conséquence de design |
|---|---|---|
| Cartes | 518 cartes Hoenn ; pas de cartes Kanto/Sevii (D4) ; aucune carte neuve prévue | toute l'histoire se joue sur cartes existantes re-scriptées ; une carte neuve = copie de layout, sur dérogation |
| Dresseurs | ~855 ID, **9 slots libres** | **réutiliser les ID vanilla** : les ~70 ID Magma/Aqua (sbires, admins, chefs) deviennent Carillonneurs, Veilleurs, Rocheval, Ysaline ; les ID de Timmy (Wally) servent au {RIVAL} final/Rocheval selon besoin |
| Flags / vars | 372 flags, 55 vars libres | budget histoire ≈ 120 flags, 12 vars (détail `bible/CHAPTERS.md` §4) ; recycler `VAR_*_STATE` des événements vanilla supprimés |
| Sauvegarde | SB1 376 o libres | aucune structure persistante nouvelle (journal = flags) |
| Code | IWRAM 4,3 Ko libres | pas de système C lourd ; seuls crochets autorisés : (a) suppression des rencontres sous `FLAG_FIGEMENT_ACTIF` (quelques lignes, ROM) ; (b) cas `GetBattleBGM` pour les nouvelles classes ; (c) éventuel nom de classe |
| ROM | 6,7 Mio libres | ample |
| Texte | ≤ 208 px/ligne, 2 lignes/boîte ; `{PLAYER}` = 42 px ; pas de « » | une idée par boîte ; dialogues longs découpés ; noms ≤ 10 car. pour les dresseurs |
| Gimmicks | aucun obtenable par défaut | seul `ITEM_MEGA_RING` est câblé (script de don) ; Z/Dynamax/Téra non câblés |
| Titre | en-tête ≤ 12 car. | `HEURESUSPEND` |
| Portraits | pas de portrait pour Seko, Maman, Scott ; FRLG libres | nouveaux personnages = portraits réutilisés (voir `bible/CHARACTERS.md`) ; 0 PNG neuf obligatoire |

## 11. Hypothèses H1–H7 : résolution

| ID | Décision | Statut |
|---|---|---|
| H1 Plafond de niveau | **Souple** (`EXP_CAP_SOFT`), table par badge (`LEVEL_CAP_FLAG_LIST`), `B_LEVEL_CAP_EXP_UP TRUE` ; valeurs initiales §8 | **Résolu** (valeurs à régler au prototype) |
| H2 Modes | Deux modes via `B_VAR_DIFFICULTY` : **Normal** et **Expert** (équipes boss `Difficulty: Hard`, IA renforcée). Choix diégétique au chap. 0 (Seko : « Comment veux-tu voyager ? »). Les cartes, l'histoire et le plafond ne changent pas. | **Résolu** (contenu Expert produit après Normal) |
| H3 Gimmick | Méga-Évolution seule (§7). H3-bis : second gimmick en postgame **différé** | **Résolu** |
| H4 Jour/nuit | Rencontres par moment **activées** (`OW_TIME_OF_DAY_ENCOUNTERS TRUE`) ; Figements = heure suspendue. Arrêt réel de l'horloge (`OW_USE_FAKE_RTC` + `OW_FLAG_PAUSE_TIME`) **à prototyper** ; repli : effet cosmétique seul | **Résolu sur le principe**, prototype requis |
| H5 Rival adaptatif | {RIVAL} : équipe selon le starter (vanilla) + IA `Know Opponent Party` aux 2 derniers combats | **Résolu** |
| H6 DexNav / suiveurs | DexNav **différé** (coût SB3) ; Pokémon suiveurs **désactivés** ; **PNJ suiveur** activé pour deux escortes (Absol au Site Météore, Gaspard au Pilier Céleste) | **Résolu** |
| H7 Cartes FRLG | Non (D4). Musiques `MUS_RG_*` et portraits FRLG utilisés | **Résolu** |

Hypothèses nouvelles : **N1** suppression des rencontres en Figement (crochet C minime ; repli : Figements placés sur cartes/zones sans herbe ou eau à rencontres, ou `Repousse` scriptée) — prototype en tranche verticale ; **N2** nom de classe « CARILLONNEUR » (12 car.) tient dans le buffer de classe — à vérifier, repli « SONNEUR ».

## 12. Invariants (ne changent pas sans arbitrage du GMD)

1. Le thème central (§2) et la phrase de signification mécanique.
2. Ysaline est identifiée comme cause **à la fin de l'acte I** (New Lavandia), jamais en retournement tardif.
3. Absol n'est **jamais** la cause ; il est toujours vu *avant*.
4. Ysaline et ses Carillonneurs ne méga-évoluent jamais ; le joueur obtient la Méga après une démonstration.
5. Aucun légendaire ne résout une crise à la place du joueur. Rayquaza n'intervient pas dans le climax.
6. Le glas final est **sonné par Ysaline** ; le joueur rend cela possible (combat + lecture), il ne le lui impose pas.
7. Chaque Figement : vu (ou annoncé) avant d'être délivré ; contient une cloche-pivot, un fragment d'indice, au moins un objet suspendu.
8. Ordre des badges et correspondance badges → capacités de terrain vanilla conservés (B1 Coupe … B8 Cascade).
9. Aucune espèce, sprite, donnée ou animation d'attaque modifiés.
10. Pas de carte neuve sans dérogation écrite.

## 13. Secrets à garder (ne pas divulguer avant leur moment ; pas de texte « spoiler » dans les panneaux, descriptions d'objets ou Pokédex)

| Secret | Révélé à | Ne pas laisser fuiter via |
|---|---|---|
| Ysaline est la cause | ch. 5 (New Lavandia) | dialogues de Poivressel (elle y parle de perte, pas de cloches) |
| Absol prévient | ch. 11 (repaire des Veilleurs) | aucune ligne d'allié ne doit l'affirmer avant ; seuls des indices |
| Le Xatu figé au sommet | ch. 11 (Mont Mémoria) | Ysaline parle d'« un ami », jamais de Xatu, avant |
| « Nous en avions peur » = peur de perdre | ch. 13 (Caverne Fondmer) | Musée : version officielle erronée (« peur des monstres ») |
| Le Pilier Céleste est un clocher | ch. 14 | Marc l'annonce seulement ; aucun panneau avant |
| Le Xatu guidait le joueur | ch. 15 | visions toujours cryptiques |
| Spectra est la petite-fille d'Ysaline | Conseil 4 | indice discret au Mont Mémoria (photo) |

## 14. Changelog

| Date | Version | Changement | Raison | Auteur |
|---|---|---|---|---|
| 2026-10-13 | 1.0 | Création de la bible : direction B « L'Heure suspendue » (greffes A, C, D), titre, synopsis, structure, gimmick Méga, H1–H7 résolues, invariants, contraintes techniques | Étape 2 de la mission GMD | GMD |
