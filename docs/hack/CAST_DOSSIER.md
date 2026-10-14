# CAST DOSSIER — personnages de Kanto et de Hoenn

> **Destinataires :** Directeur Game Design / Mécaniques (histoire), designers de combat.
> **Rôle :** fiches de personnages compactes. Ce dossier ne fait que **compléter** `LORE_DOSSIER.md` (§1.7 Hoenn, §8 Kanto). Il ne répète pas la chronologie (§8.1), ni l'analyse de Red (§8.2), ni les ponts Kanto–Hoenn (§8.4). Il ne remplace pas les rôles déjà fixés dans `CHARACTER_AND_LORE.md` (*Pokémon Cendres*, cadre B, année 1). Les « accroches » ci-dessous sont un **réservoir** : elles restent compatibles avec ce cadre, sans le réécrire.
> **Date :** octobre 2026. Budget de recherche : 10 requêtes web (extraits de moteur uniquement). Tout le reste est donné de mémoire experte.

---

## 0. Conventions

### 0.1 Étiquettes

Ce sont les mêmes que dans `LORE_DOSSIER.md` §0.1.

| Étiquette | Sens |
|---|---|
| **✔** | Vérifié pendant cette recherche ou une précédente (Poképédia, Pokébip ou Bulbapedia, via extraits) |
| **◐** | De mémoire, très probable. À vérifier avant d'écrire les textes ou les `.party` |
| **?** | Incertain |
| **✘** | Absent (asset) ou faux |
| **[JEU : X]** | Canon des jeux. Codes : RBJ, RFVF, GSC, HGSS, RSE (E = Émeraude), ROSA, LGPE = Let's Go, SL/USUL, Stadium |
| **[ANIME]**, **[MANGA]** (*La Grande Aventure*), **[ORIGINS]** | Autres médias. Non contraignants |
| **[NON-CANON : Masters / PWT]** | *Pokémon Masters EX* et Tournoi Mondial Pokémon (N2B2). Équipes « fan-service » hors continuité |
| **HYPOTHÈSE** | Proposition pour le hack. Ce n'est **jamais** du canon |

### 0.2 Corrections et nouveautés trouvées pendant cette recherche

- **Daisy = Nina Chen** ✔ (Poképédia, *Nina_Chen*). Elle est la grande sœur de Blue et la petite-fille de Chen. **[JEU : RFVF]** C'est une coordinatrice reconnue ◐ (Poképédia indique qu'elle a gagné un concours avant le jeu). **[JEU : HGSS]** Elle toilette les Pokémon l'après-midi ◐.
- **Mr. Briney = M. Marco** ✔ (Poképédia, *M._Marco*). Son Goélise **Peeko = Piko** ◐ (nom employé par Poképédia).
- **Prof. Cozmo = Professeur Kosmo** ✔ (Poképédia ; il vit à **Autéquia** ✔). Cela corrige « Cosmo » dans `LORE_DOSSIER` §1.7 et dans `CHARACTER_AND_LORE`.
- **Mr. Stone = M. Rochard** ✔ (Joseph Stone en anglais). Poképédia écrit **Devon SARL** et non « Devon SA ». **Mérouville** = Rustboro ✔.
- **Présidence de Sylphe SARL** ✔ : un « Président de la Sylphe SARL » sans nom. Il remet la Master Ball après la défaite de Giovanni **[JEU : RBJ/RFVF]** ✔.
- **Têtes de la Zone de Combat** (mini-site FR d'Émeraude, via Pokébip ◐ ; correspondance faite par installation) :

  | Installation | Nom FR | Nom EN |
  |---|---|---|
  | Usine | **Sam** | Noland |
  | Dojo | **Carole** | Greta |
  | Pyramide | **Bayar** | Brandon |
  | Tour | **Capucine** | Anabel |
  | Dôme | **Takim** | Tucker |
  | Palace | **Esteban** | Spenser |
  | Reptile | **Charline** | Lucy |

  Ces noms datent du lancement. Il faut vérifier sur Poképédia qu'ils sont restés en jeu.
- **« Caroline »** est le prénom de la mère de Flora **dans l'anime anglais**. Dans les jeux, la mère du joueur n'a **pas de nom** (« Maman ») ✔ (Poképédia, *Brice_(Hoenn)* : mère sans nom).
- **Max, petit frère de Flora, n'existe que dans l'anime.** Il n'apparaît dans aucun jeu de Hoenn ◐. Cela corrige `LORE_DOSSIER` §1.7 et §8.6, qui le placent dans le jeu.
- **Lanette** : le nom FR reste ? (aucun extrait trouvé). Il n'existe **aucun** `OBJ_EVENT_GFX_LANETTE` : sa maison de la Route 114 utilise `WOMAN_2`. Cela corrige `CHARACTER_AND_LORE` §3.16.
- **Amaryllis** (Zinnia) à la Colonne Céleste **[JEU : ROSA]** ✔ : Muplodocus 60, Rexillius 60, Altaria 60, Bruyverne 60 et **Drattak 62** (Méga-Drattak). Elle voyage avec une Chuchmur femelle surnommée **Aster** (EN) ✔.
- **Sprites d'overworld RFVF** : `src/data/object_events/object_event_graphics_info_pointers.h` (ligne 648) porte le commentaire « *Hack: FRLG object events are also built in Emerald* ». Les OW de Kanto (BLUE, PROF_OAK, DAISY, BILL, CELIO, MR_FUJI, BROCK…GIOVANNI, LORELEI, BRUNO, AGATHA, LANCE, ROCKET_M/F, MEWTWO, oiseaux, etc.) sont donc **déjà compilés** dans la build Émeraude. `ASSET_INVENTORY` §4 (« sous `#if IS_FRLG` ») et les mentions « portage » de `CHARACTER_AND_LORE` sont **dépassés** sur ce point. Il reste à vérifier les palettes en jeu.

### 0.3 Lecture des fiches

Chaque fiche suit le même ordre :
- **Id** : nom FR / nom EN, statut du nom
- **Canon** : rôle et histoire, avec le jeu en étiquette
- **Perso** : personnalité dans les jeux, puis dans l'anime et le manga
- **Liens** : relations canoniques
- **Équipes** : versions clés
- **Identité stratégique**
- **Concepts adultes / adaptatifs** (HYPOTHÈSE, espèces Gen 1–9)
- **Accroches** : objectifs égoïstes ou altruistes « un an après RFVF », tensions
- **Assets** : `TRAINER_PIC_*` / `OBJ_EVENT_GFX_*`

Les niveaux d'équipe sont ◐ sauf mention contraire. Les noms de Pokémon sont les noms FR officiels.

**Principe des équipes adaptatives** (HYPOTHÈSE, pour les designers de combat) :
- Chaque personnage garde un **noyau canonique** de 2 ou 3 Pokémon.
- Il ajoute des **satellites** qui corrigent ses faiblesses connues, ou qui répondent à l'équipe du joueur. Exemple : un Champion Électrik prend un Pokémon Sol-proof si le joueur mise sur le Sol.
- On fait des variantes A, B et C selon le moment du récit, la difficulté ou le choix du joueur. Dans le moteur, ce sont des `trainers.party` distincts, sélectionnés par script.

---

## 1. KANTO

### 1.1 Red — Red / Red ✔
- **Canon.** Protagoniste de RBJ/RFVF. Il bat la Ligue et Giovanni, termine Sevii et la machine de Ciléo **[JEU : RFVF]**. Il s'isole ensuite au Mont Argenté **[JEU : GSC/HGSS]**, puis codirige l'Arbre de Combat avec Blue **[JEU : SL/USUL]**. Détails complets : `LORE_DOSSIER` §8.2. Dans LGPE, il est un PNJ aîné de la Ligue ◐.
- **Perso.** **[JEU]** Muet (« … »), il disparaît après sa défaite. **[ORIGINS]** Garçon ordinaire qui apprend de ses erreurs. **[MANGA]** Vantard au début, puis mûr et responsable. **[ANIME]** Sacha (Ash) en est l'analogue, mais ce n'est pas le même personnage.
- **Liens.**
  - Rival et ami d'enfance de Blue.
  - Le Prof. Chen lui confie le Pokédex.
  - Ennemi de Giovanni.
  - Il a sauvé le Président de Sylphe et M. Fuji (Tour Pokémon).
  - Il a aidé Léo et Ciléo.
  - Il est lié à Mewtwo (s'il l'a capturé, RFVF : Caverne Azurée).
  - Sa mère vit à Bourg Palette.
- **Équipes.**
  - GSC, HGSS (Pikachu 88), SL/USUL : voir `LORE_DOSSIER` §8.2.
  - **Stadium 2 ◐** : même noyau.
  - **[NON-CANON : Masters]** Red & Pikachu, puis Red & Dracaufeu ou Tortank, etc.
- **Identité stratégique.** Un **généraliste équilibré** : un trio de starters (couverture Plante, Feu et Eau, « noyau FWG »), un Pikachu offensif rapide et un pivot spécial défensif (Ronflex). Pas de gimmick : il joue « juste ». Le point de vue est celui de l'**endurance** : climat (Grêle au Mont Argenté), Repos et Ronflement.
- **Concepts adultes (HYPOTHÈSE).**
  - **A « Mont Argenté +1 an ».** Pikachu (Balle Lumière), Florizarre, Dracaufeu, Tortank, Ronflex, Lokhlass. Synergie : noyau FWG, plus Lokhlass pour la Grêle et Glace contre les dragons de Peter et d'Aragon.
  - **B « voyageur de Hoenn ».** Remplacer Lokhlass par **Absol** (présage du désastre, attrait du récit) ou par **Relicanth**. Méga-Dracaufeu X ou Y seulement si la Méga est introduite (cadre ROSA).
  - **C « miroir du joueur ».** La réserve des boîtes de Red alimente une équipe adaptative : contre un joueur à dominante Eau, Florizarre plus **Lucanon** ; contre le Feu, Tortank plus **Fort-Ivoire** ◐ (pas cohérent sans voyage). On préférera **Mammochon** (Glace/Sol, Sevii-friendly).
- **Accroches.**
  - *Altruiste* : réparer une dette (Cramois'Île), protéger un lieu.
  - *Égoïste* : fuir la célébrité ; se mesurer au seul adversaire qui l'inquiète (Pierre Rochard ? Rayquaza ?) ; comprendre Mewtwo.
  - *Tensions* : Blue (il est parti sans dire au revoir) ; Giovanni (le gamin qui l'a ruiné) ; Agatha (le gamin qui l'a battue, elle qui juge Chen).
- **Assets.** `TRAINER_PIC_RED` (face et dos) ✔. OW : `OBJ_EVENT_GFX_RED` (simple) et `RED_NORMAL/BIKE/SURF/FIELD_MOVE/FISH/VS_SEEKER` (avatar complet) ✔.

### 1.2 Blue — Blue / Blue (Green JP) ✔
- **Canon.**
  - Rival de RBJ/RFVF ; Maître quelques minutes.
  - **[JEU : RFVF]** Il réapparaît à Sevii (Île 7, Tour Dresseurs ◐ ; il cherche à compléter son Pokédex).
  - **[JEU : GSC/HGSS]** Champion de Jadielle, absent de son arène jusqu'à la fin ; donne le Badge Terre.
  - **[JEU : HGSS]** Combat de revanche le mercredi ◐ (Route 21, combat de Groupe).
  - **[JEU : SL/USUL]** Codirecteur de l'Arbre de Combat.
  - **[JEU : LGPE]** Il s'appelle « Green » ◐ (rôle de rival aîné).
- **Perso.** **[JEU]** Arrogant, sarcastique (« Smell ya later! »), compétitif. Au Hall de la Renommée, son grand-père le rabroue pour avoir négligé ses Pokémon (RFVF ✔ : « tu as oublié de traiter tes Pokémon avec amour »). Plus posé en GSC : il s'ennuie et cherche un bon adversaire. **[ANIME]** Régis (Gary) devient chercheur. **[MANGA]** Bleu (Green JP) est froid et talentueux ; c'est un ami.
- **Liens.** Petit-fils du Prof. Chen, petit frère de Nina (Daisy) ✔, rival de Red. Respect mutuel avec Peter, qui le félicite ◐.
- **Équipes.**
  - **RFVF Maître** ◐ (niveaux 59–65) : Roucarnage, Alakazam, Rhinoféros, puis deux parmi Léviator / Arcanin / Noadkoko selon le starter, plus le starter fort contre celui du joueur (Florizarre / Dracaufeu / Tortank).
  - **GSC Jadielle** : Roucarnage, Alakazam, Rhinoféros, Léviator, Arcanin, Noadkoko (56–58).
  - **HGSS** : même équipe, revanche aux niveaux 70+ ◐.
  - **SL** : starters et Méga-Roucarnage ? (à vérifier ◐).
  - **[NON-CANON : Masters]** Blue & Roucarnage.
- **Identité stratégique.** Un **généraliste offensif** : polyvalence de types, beaucoup de « hard-hitters ». Ses Pokémon sont choisis pour la **couverture** et non pour l'affection (c'est un thème : la scène du Hall de la Renommée). Tempo : il frappe d'abord. Ses outils : Alakazam (Psy rapide), Rhinoféros (Sol/Roche), Roucarnage (pivot).
- **Concepts adultes (HYPOTHÈSE).**
  - **A « Jadielle en devenir ».** Roucarnage, Alakazam, **Rhinastoc** (Protecteur), Léviator, Arcanin, Noadkoko. Synergie : Arcanin (Intimidation) avec Rhinastoc (Solide Roc).
  - **B « globe-trotter ».** Noyau Roucarnage + Alakazam + starter, plus **Corvaillus**, **Exagide** et **Tranchodon**. Il montre qu'il a voyagé ailleurs. Il ne faut pas en abuser à Hoenn : l'utiliser seulement si le récit lui fait traverser des régions.
  - **C « adaptatif anti-joueur ».** Il observe l'équipe du joueur au premier combat, puis compose des contre-équipes. C'est le rival « analytique ». Moteur : `trainers.party` A, B et C, choisis selon le type du starter et la variable du nombre de victoires.
- **Accroches.**
  - *Égoïste* : réhabiliter sa fierté (Maître pendant 3 minutes), forcer Red à un vrai combat, éclipser son grand-père.
  - *Altruiste* : protéger Nina et Chen ; découvrir qu'il aime ses Pokémon (arc canonique implicite).
  - *Tensions* : Red ; Chen (sentiment de ne pas être reconnu) ; Peter (honte de la défaite) ; Giovanni (il va hériter de son arène, et cela gêne).
- **Assets.** `TRAINER_PIC_RIVAL_EARLY_FRLG`, `RIVAL_LATE_FRLG`, `CHAMPION_RIVAL_FRLG` ✔. OW `OBJ_EVENT_GFX_BLUE` ✔.

### 1.3 Leaf — Leaf / Leaf ✔
- **Canon.**
  - Protagoniste féminine de RFVF (« la fille » au choix).
  - Nom officialisé tardivement (*Masters*, produits dérivés).
  - **[JEU : LGPE]** Les aînés « Green » sont un autre personnage, inspiré de Blue (Green JP). Ne pas confondre.
  - **[MANGA]** « Green / Verte » (Blue JP) est une voleuse de génie liée à Sevii, mais c'est un personnage distinct.
- **Perso.** Quasi aucune personnalité dans les jeux (avatar). **[NON-CANON : Masters]** Douce, déterminée, liée à Évoli ◐.
- **Liens.** Possibles (au choix du hack) : amie d'enfance de Red et de Blue ; élève de Chen.
- **Équipes.**
  - Aucune équipe canonique en jeu principal.
  - **[NON-CANON : Masters]** Leaf & Évoli.
  - Dans le moteur, elle peut tenir le rôle d'un « deuxième Red ».
- **Identité stratégique (HYPOTHÈSE).** Là où Red est un généraliste et Blue un offenseur, Leaf est une **tacticienne et éleveuse** : Évoli et ses évolutions, soutien, objets.
- **Concepts (HYPOTHÈSE).**
  - **A « Évoli-team ».** Aquali (Vœu et Protection), Noctali, Nymphali, Givrali, Phyllali, plus Florizarre ou Nidoqueen. Synergie : pivot Vœu, Nymphali Peau Féerique contre les dragons.
  - **B « Sevii ».** Lokhlass, Méganium (des espèces de Johto vivent à Sevii ✔ [JEU : RFVF]), Leveinard, Feunard, Florizarre.
  - **C « adaptatif ».** Elle change l'évolution d'Évoli pour contrer le joueur. Gimmick unique et lisible.
- **Accroches.** C'est l'autre championne du même voyage. Elle a battu Giovanni le même jour ? Pourquoi est-elle effacée de l'histoire ? *Égoïste* : sortir de l'ombre de Red. *Altruiste* : vivre la route et la recherche (Pokédex National complété avec Chen).
- **Assets.** `TRAINER_PIC_LEAF` (face et dos) ✔. OW `OBJ_EVENT_GFX_LEAF` (simple) et `GREEN_NORMAL/BIKE/SURF/…` (avatar complet) ✔.

### 1.4 Prof. Chen — Prof. Chen / Prof. Oak ✔
- **Canon.**
  - Chercheur de Bourg Palette, créateur du Pokédex.
  - **[JEU : RFVF]** Il donne le Pokédex National et les Ticketmystik / Ticketaurora ✔ (§8.3).
  - **[JEU : GSC/HGSS]** Il anime une émission de radio (*Pokémon Talk*, nom FR ◐). Il rencontre le joueur de Johto chez M. Pokémon (Route 30) et lui confie le Pokédex ◐.
  - **[JEU : HGSS]** Il compte le Pokédex du joueur de Johto.
- **Perso.** **[JEU]** Débonnaire, oublie le nom de son petit-fils (gag de l'intro), passionné. **Ancien grand dresseur** : Agatha dit qu'il était « dur et beau » autrefois ◐. **[ANIME]** Poète farfelu, mentor de Sacha. **[MANGA]** Ancien champion de la Ligue ; enlevé par la Rocket à Sevii (arc RFVF ✔).
- **Liens.**
  - Grand-père de Blue et de Nina.
  - **Rival d'Agatha** ✔ [JEU : RBJ/RFVF].
  - Collègue d'Orme (Elm, son ancien élève, **[JEU : GSC]** ◐).
  - Relation avec Seko seulement dans l'anime et le manga (§8.4).
  - Il connaît M. Fuji ? (non établi).
- **Équipes.**
  - Aucun combat en jeu principal.
  - **[NON-CANON : Stadium 2 ◐ ?]** Non confirmé.
  - **[NON-CANON : Masters]** Chen & Tauros ◐ (il combat).
  - Pokémon associés : les trois starters de Kanto ; **Tauros** (pré-Masters ◐), Dracolosse (Masters ◐).
- **Identité stratégique (HYPOTHÈSE, s'il combat).** Un **vétéran à l'ancienne** : espèces Gen 1 pures, attaques physiques fortes (Tauros Rage / Tête de Fer), Dracolosse. Gimmick : « les bonnes vieilles méthodes », sans objet ni climat, mais des niveaux très élevés.
- **Concepts (HYPOTHÈSE).**
  - **A** : Tauros, Dracolosse, Kangourex, Ectoplasma (souvenir d'Agatha), Lokhlass, Akwakwak.
  - **B « Professeur moderne »** : un spécimen de recherche par région (Tauros de Paldea, Ursaking, etc.), à éviter sauf cadre tardif.
- **Accroches.** *Altruiste* : le Pokédex comme bien commun ; correspondance avec Seko. *Égoïste* : la gloire scientifique (premier à cataloguer les espèces étrangères à Hoenn) ; vieille rivalité avec Agatha. *Tensions* : Blue (négligence affective), Agatha.
- **Assets.** `TRAINER_PIC_PROFESSOR_OAK_FRLG` ✔. OW `OBJ_EVENT_GFX_PROF_OAK` ✔.

### 1.5 Nina Chen — Nina / Daisy ✔
- **Canon.** **[JEU : RBJ/RFVF]** Elle donne la Carte de la Ville. **[JEU : RFVF]** Coordinatrice célèbre ◐. **[JEU : HGSS]** Elle masse les Pokémon (amitié) ◐. **[ANIME]** Les « Daisy » d'Azuria sont la sœur d'Ondine : homonyme sans lien.
- **Perso.** Douce, gentille, attentionnée, opposée à son frère ✔.
- **Liens.** Sœur aînée de Blue, petite-fille de Chen.
- **Équipes.** Aucune en jeu. **[NON-CANON : Masters]** non ◐.
- **Identité (HYPOTHÈSE).** Si elle combat : esthétique Concours (Beauté, Grâce), Grâce Céleste. Par exemple Leveinard / Leuphorie, Milobellus (lien avec Marc, maître des Concours), Nymphali.
- **Accroches.** Pont idéal vers les **Concours de Hoenn** (Marc, Lisia) : Nina vient concourir à Hoenn. *Égoïste* : un ruban de Hoenn. *Altruiste* : veiller sur Blue.
- **Assets.** **Pas de `TRAINER_PIC`** ✘. OW `OBJ_EVENT_GFX_DAISY` ✔.

### 1.6 Pierre — Pierre / Brock ✔
- **Canon.**
  - Champion d'Argenta, type Roche **[JEU : RBJ/RFVF]**.
  - Combat de revanche **[JEU : HGSS]** (Montagne de Kanto / Grotte Taupiqueur ◐, téléphone).
  - Son père (Flint, « Bajo » ?) et ses frères et sœurs nombreux : un détail de jeu RBJ ◐ ; l'anime développe beaucoup.
- **Perso.** **[JEU]** Sérieux, « dur comme la pierre » ✔. **[ANIME]** Éleveur, puis docteur Pokémon, dragueur, figure fraternelle. **[MANGA]** Mature, aide Red.
- **Liens.** Collègue d'Ondine ; ses frères et sœurs.
- **Équipes.**
  - **RFVF** : Racaillou 12, Onix 14 ✔.
  - **GSC** : Gravalanch, Rhinocorne, Amonistar, Onix, Kabutops (41–44).
  - **HGSS revanche** ◐ : Grolem, Rhinoféros, Amonistar, Kabutops, Ptéra, Steelix… (vers 71–72).
  - **[NON-CANON : PWT]** Champions de Kanto (Grolem, Ptéra, etc.).
- **Signature.** Onix, puis Steelix. Fossiles.
- **Identité stratégique.** Roche **défensive** : Fermeté, Tempête de Sable (bonus de Déf. Spé.), Piège de Roc, Explosion.
- **Concepts (HYPOTHÈSE).**
  - **A « Sable »** : Steelix (Méga ?), Tyranocif (Sable), Hippodocus, Bastiodon, **Minotaupe** (Baigne Sable). Synergie : Hippodocus pose le sable ; Minotaupe et Tyranocif balaient.
  - **B « Fossiles »** : Amonistar, Kabutops, Ptéra, Charkos, Rexillius, Aéroptéryx. Esthétique du musée d'Argenta.
  - **C « Éleveur »** : Leuphorie, Strassie, Monumontagne ◐ (nom FR à vérifier), Gigalithe, avec Danse Pluie retirée. Soins et soutien.
- **Accroches.** *Altruiste* : ses frères et sœurs, une école d'éleveurs. *Égoïste* : devenir éleveur reconnu en quittant son arène (tension avec son devoir). Un séjour à Hoenn, par exemple pour le Site Météore ou les fossiles de Vacilys et d'Armaldo, est plausible (Devon fait revivre les fossiles ✔ [JEU : RSE]).
- **Assets.** `TRAINER_PIC_LEADER_BROCK_FRLG` ✔. OW `OBJ_EVENT_GFX_BROCK` ✔.

### 1.7 Ondine — Ondine / Misty ✔
- **Canon.** Championne d'Azuria, type Eau **[JEU : RBJ/RFVF]**. **[JEU : GSC/HGSS]** Absente au début, en rendez-vous galant au Cap d'Azuria ◐.
- **Perso.** **[JEU]** « Ma politique est une offensive totale avec les Pokémon Eau ! » ✔. **[ANIME]** Compagne de route de Sacha, tempérament fougueux, trois sœurs aînées (« Daisy », Violette, Lily). **[MANGA]** Rivalité avec Red, puis amitié.
- **Liens.** Collègues champions ; sœurs dans l'anime.
- **Équipes.**
  - **RFVF** : Stari 18, Staross 21 ✔.
  - **GSC** : Akwakwak, Maraiste, Lokhlass, Staross (42–47).
  - **HGSS revanche** ◐ : Staross, Akwakwak, Lokhlass, Léviator, Maraiste, Tarpaud…
- **Signature.** Staross, Psykokwak (anime).
- **Identité stratégique.** Eau **offensive et rapide** : Staross (Rapide Turbo), Danse Pluie, Glissade.
- **Concepts (HYPOTHÈSE).**
  - **A « Pluie »** : Tarpaud (Crachin), Staross, Hastacuda (Glissade), Lanturn, Hyporoi, Prédastérie.
  - **B « Rivage »** : Staross, Oratoria, Superdauphin, Akwakwak, Lokhlass, Léviator.
- **Accroches.** Pont vers Marc et Atalanopolis (Eau). *Égoïste* : défier le meilleur dresseur Eau de Hoenn, obtenir un Barpau / Milobellus (espèce emblématique de Marc). *Altruiste* : la pollution des récifs (pont avec les Pêcheurs d'Aqua).
- **Assets.** `TRAINER_PIC_LEADER_MISTY_FRLG` ✔. OW `OBJ_EVENT_GFX_MISTY` ✔.

### 1.8 Major Bob — Major Bob / Lt. Surge ✔
- **Canon.**
  - Champion de Carmin sur Mer, type Électrik **[JEU : RBJ/RFVF]**.
  - « L'Éclair Américain » : vétéran de guerre ; ses Pokémon l'ont « sauvé à la guerre » ✔.
  - **[JEU : GSC/HGSS]** Toujours à Carmin.
- **Perso.** Bruyant, soldat, moqueur (« petit soldat »).
- **Liens.** Aucun lien canonique fort. Carmin sur Mer est le port de l'Océane, donc il connaît les marins.
- **Équipes.**
  - **RFVF** : Voltorbe 21, Pikachu 18, Raichu 24 ✔.
  - **GSC** : Raichu, Électrode ×2, Magnéton, Élektek (40–46).
  - **HGSS revanche** ◐ : Raichu, Élekable, Magnézone, Électrode, Élecsprint ?…
- **Signature.** Raichu.
- **Identité stratégique.** Électrik **vitesse et paralysie** : Électrode (Explosion, Écran), Raichu rapide, Cage-Éclair.
- **Concepts (HYPOTHÈSE).**
  - **A « Blitz »** : Raichu, Élekable (Motorisé), Magnézone, Électrode, Zéblitz, **Salarsen**.
  - **B « Champ Électrifié »** : Salarsen, Magnézone, Lucanon, **Rotom-Lavage**, Élekable. Synergie : terrain, anti-sommeil, Rotom contre le Sol. C'est l'adaptation anti-Sol.
- **Accroches.** Ancien militaire : il peut être le **logisticien** d'une évacuation (Océane, Carmin). *Égoïste* : nostalgie de la guerre ; méfiance envers les étrangers ? (à manier avec prudence). Rapprochement avec Voltère : la centrale de Lavandia, des « vieux soldats » de l'Électrik.
- **Assets.** `TRAINER_PIC_LEADER_LT_SURGE_FRLG` ✔. OW `OBJ_EVENT_GFX_LT_SURGE` ✔.

### 1.9 Erika — Erika / Erika ✔
- **Canon.** Championne de Céladopole, type Plante **[JEU : RBJ/RFVF]**. Elle fait des parfums et des arrangements floraux, et s'endort ✔. **[JEU : GSC/HGSS]** Idem.
- **Perso.** Polie, rêveuse, élégante. Elle déteste les parfums « vulgaires » (RBJ ◐). **[ANIME]** Elle tient une parfumerie ; épisode de Sacha et de l'Ortide.
- **Liens.** Collègues.
- **Équipes.**
  - **RFVF** : Empiflor 29, Saquedeneu 24, Rafflesia 29 ✔.
  - **GSC** : Saquedeneu, Cotovol, Empiflor, Joliflor (42–46).
  - **HGSS revanche** ◐ : Bouldeneu, Joliflor, Roserade, Cotovol, Empiflor, Rafflesia ?
- **Identité stratégique.** Plante **statut et soutien** : Poudre Dodo / Para-Spore, Méga-Sangsue, Zénith (Chlorophylle).
- **Concepts (HYPOTHÈSE).**
  - **A « Zénith »** : Joliflor, Fragilady, Feunard (Sécheresse), Bouldeneu, Roserade, Florizarre.
  - **B « Jardin »** : Guérilande (Aroma-Veil ◐), Gaulet (Spore Rage-Poudre), Farfaduvet, Florges, Roserade. Support en double.
- **Accroches.** Parfumerie et cosmétique : rivalité avec un concurrent de Devon ? Elle rencontre Adriane (sources chaudes) ou les jardiniers de Vergazon. *Égoïste* : un nouveau parfum de Hoenn (fleurs du Mont Chimnée ?).
- **Assets.** `TRAINER_PIC_LEADER_ERIKA_FRLG` ✔. OW `OBJ_EVENT_GFX_ERIKA` ✔.

### 1.10 Koga — Koga / Koga ✔
- **Canon.**
  - Champion de Parmanie, ninja, type Poison **[JEU : RBJ/RFVF]**.
  - **[JEU : GSC/HGSS]** Il passe au Conseil 4 ; sa fille Jeannine lui succède ✔.
  - **[MANGA]** Membre de la Team Rocket (3 Hommes-Rocket ◐). Les jeux ne l'affirment pas.
- **Perso.** Ninja secret, maître des illusions et du poison ; ses murs invisibles sont un piège.
- **Liens.** Père de Jeannine. Collègues de Conseil : Clément, Aldo, Marion, Peter.
- **Équipes.**
  - **RFVF** : Smogo 37, Tadmorv 39, Smogo 37, Smogogo 43 ✔.
  - **GSC/HGSS Conseil 4** : Migalos, Aéromite, Foretress, Grotadmorv, Nostenfer (40–44 GSC ; HGSS revanche ◐ ~ 60).
  - **[NON-CANON : PWT]**
- **Signature.** Smogogo, Nostenfer.
- **Identité stratégique.** **Poison, statut et attrition** : Toxik, Picots, Abri, Double Équipe (RBJ), Destruction, soins. Il « use » au lieu de frapper.
- **Concepts (HYPOTHÈSE).**
  - **A « Ninja »** : Nostenfer (Demi-Tour), Smogogo (Lévitation, Feu Follet), Prédastérie, Drascore, Foretress (Picots), Coatox.
  - **B « Ombres »** : **Ninjask** (Turbo + Relais, natif de Hoenn), **Malamandre** (Corrosion), **Scalproie**, Smogogo, Prédastérie. Amphinobi serait le thème ninja parfait, mais il est de Kalos : à réserver au cadre tardif.
- **Accroches.** C'est un ancien espion : il peut traquer la Rocket pour la Ligue, ou avoir été lui-même Rocket (lecture manga, HYPOTHÈSE). Il est l'agent double idéal. *Égoïste* : préparer sa promotion au Conseil 4. *Altruiste* : protéger Jeannine.
- **Assets.** `TRAINER_PIC_LEADER_KOGA_FRLG` ✔. OW `OBJ_EVENT_GFX_KOGA` ✔.

### 1.11 Jeannine — Jeannine / Janine ✔
- **Canon.** **[JEU : GSC/HGSS]** Championne de Parmanie, type Poison. Elle se déguise en sbire dans son arène ◐.
- **Perso.** Énergique, veut égaler son père.
- **Liens.** Fille de Koga.
- **Équipes.**
  - **GSC** : Nostenfer, Smogogo, Migalos ×2 ◐, Aéromite.
  - **HGSS** : Nostenfer 47, Smogogo 44, Migalos ◐ 47, Aéromite 50 ◐.
- **Identité.** Poison **rapide** (Aéromite, Nostenfer), plus offensive que Koga.
- **Concepts (HYPOTHÈSE).** **A** Malamandre, Aéromite, Brutapode (Turbo), Nostenfer, Coatox. **B** « déguisements » : Zoroark (Illusion) en tête ; c'est un écho de l'arène à leurres.
- **Accroches.** Un an après RFVF, elle n'est **pas encore championne** (avant GSC) : elle s'entraîne pour hériter de l'arène. *Égoïste* : prouver qu'elle vaut son père.
- **Assets.** **Aucun `TRAINER_PIC`** ✘, **aucun OW** ✘. Replis : `NINJA_BOY` (OW) et `TRAINER_PIC_BATTLE_GIRL` (repalettiser).

### 1.12 Morgane — Morgane / Sabrina ✔
- **Canon.**
  - Championne de Safrania, type Psy **[JEU : RBJ/RFVF]**.
  - Elle a éveillé ses pouvoirs psychiques après avoir tordu une cuillère ✔ ◐ (RBJ, dialogue).
  - Le Dojo voisin de Safrania a perdu son statut d'arène face à elle ✔.
  - **[JEU : GSC/HGSS]** Elle a prévu la venue du joueur.
- **Perso.** **[JEU]** Froide, télépathe, n'aime pas se battre ✔ ◐. **[ANIME]** Sinistre ; sa poupée et ses parents brisés ; elle est « guérie » par le rire.
- **Liens.** Le Karatéka du Dojo de Safrania, et Aldo par affinité ? La Sylphe est voisine (occupation Rocket).
- **Équipes.**
  - **RFVF** : Kadabra 38, M. Mime 37, Aéromite 38, Alakazam 43 ✔.
  - **GSC** : Mentali, M. Mime, Alakazam (46–48).
  - **HGSS revanche** ◐ : Alakazam, Mentali, M. Mime, Symbios ?, Roigada ?
- **Identité stratégique.** Psy avec **Distorsion, écrans (Mur Lumière, Protection) et Pré-Science**.
- **Concepts (HYPOTHÈSE).**
  - **A « Distorsion »** : Symbios (Distorsion), Sorcilence, Roigada, Archéodong, Alakazam. Cœur lent sous Distorsion, puis rapide quand elle se dissipe.
  - **B « Écrans »** : M. Mime (Mur Lumière + Protection), Mentali (Miroir Magik), Alakazam, Gardevoir, Wimessir (Terrain Psychique).
- **Accroches.** Elle **prévoit** l'avenir : elle a vu « quelque chose à Hoenn », que ce soit Groudon, Kyogre, Deoxys ou Mewtwo. *Égoïste* : comprendre l'origine de son pouvoir (lien avec Lévy et Tatia, jumeaux télépathes). C'est une sœur d'âme pour Anabel (« Capucine »), télépathe de la Zone de Combat.
- **Assets.** `TRAINER_PIC_LEADER_SABRINA_FRLG` ✔. OW `OBJ_EVENT_GFX_SABRINA` ✔.

### 1.13 Auguste — Auguste / Blaine ✔ ◐
- **Canon.**
  - Champion de Cramois'Île, type Feu, quizz, « chauve à lunettes » **[JEU : RBJ/RFVF]**.
  - Laboratoire et Manoir : journaux de Mewtwo.
  - **[JEU : GSC/HGSS]** L'île est détruite par le volcan ; il tient l'arène dans une grotte des Îles Écume.
  - **[JEU : LGPE ◐]** Il évoque un ami (M. Fuji ?) et Mewtwo.
  - **[MANGA]** Il a participé à la création de Mewtwo ; il a perdu un bras ? ◐.
- **Perso.** Excentrique, fan d'énigmes, chaleureux sous ses airs volcaniques.
- **Liens.** Ancien chercheur du Manoir (indices) ; lié à Fuji ◐.
- **Équipes.**
  - **RFVF** : Caninos 42, Ponyta 40, Galopa 42, Arcanin 47 ✔.
  - **GSC** : Volcaropod, Magmar, Galopa (45–50).
  - **HGSS revanche** ◐ : Arcanin, Maganon, Galopa, Volcaropod, Magmar ?, Feunard.
- **Identité.** Feu **offensif** ; climat Zénith ; Feu Follet.
- **Concepts (HYPOTHÈSE).**
  - **A « Après l'éruption »** : Chartor (Sécheresse), Arcanin, Maganon, Volcaropod (Corps Ardent), Pyrax, Monthracite.
  - **B « Laboratoire »** : Malvalame, Lugulabre, Démolosse, Feunard, Arcanin. Heatran est exclu (légendaire).
- **Accroches.** Déjà fixé dans `CHARACTER_AND_LORE` §3.4. En plus : sa culpabilité sur Mewtwo (le Manoir), et son lien avec Max (Maxie) par la géologie volcanique.
- **Assets.** `TRAINER_PIC_LEADER_BLAINE_FRLG` ✔. OW `OBJ_EVENT_GFX_BLAINE` ✔.

### 1.14 Giovanni — Giovanni / Giovanni ✔
- **Canon.**
  - Chef de la Team Rocket et Champion de Jadielle, type Sol **[JEU : RBJ/RFVF]**.
  - Il dissout la Team Rocket et disparaît ✔.
  - **[JEU : HGSS]** Événement Celebi : il abandonne Silver ◐, apprend la défaite de ses commandants, et part ✔.
  - **[JEU : USUL]** Un Giovanni alternatif dirige la Team Rainbow Rocket, avec Mewtwo (Méga-Y ?) ✔.
  - **[JEU : LGPE]** Persian ; il fait capturer Mewtwo ◐.
  - **[ORIGINS]** Il a financé la création de Mewtwo.
- **Perso.** Froid, charismatique, homme d'affaires, se veut « honnête dans la défaite ». Il dissout la Team Rocket par principe (vaincu par un enfant).
- **Liens.**
  - Père de **Silver** (Johto rival) ✔.
  - Patron d'Amos, Ariane, Lance et Lambda.
  - Ennemi de Red.
  - Lien de pouvoir avec la Sylphe (il la convoite) et avec Fuji ◐.
- **Équipes.**
  - **RFVF Repaire** : Onix 25, Rhinocorne 24, Kangourex 29.
  - **RFVF Sylphe** : Nidorino 37, Kangourex 35, Rhinocorne 37, Nidoqueen 41.
  - **RFVF Arène** : Rhinocorne 45, Triopikeur 42, Nidoqueen 44, Nidoking 45, Rhinoféros 50 ✔ ◐.
  - **HGSS Celebi** ◐ : Nidoking, Nidoqueen, Cornèbre ◐ (Murkrow), Kangourex ?
  - **USUL Rainbow** ◐ : Mewtwo, Nidoking ?, Rhinastoc, Démolosse ?
- **Signature.** Persian (anime, LGPE), Rhinoféros.
- **Identité stratégique.** Sol **brutal et contrôlé** : grands corps (Nidoking, Rhinastoc), Séisme, Piège de Roc. Le style « boss » repose sur l'investissement : il prépare (Danse Lames, Sable) puis frappe.
- **Concepts (HYPOTHÈSE).**
  - **A « Exil »** : Rhinastoc (Solide Roc), Nidoking (Sans Limite), Nidoqueen, Minotaupe, Persian, Kangourex.
  - **B « Empire »** : Scalpereur (Suprématie ◐), Carchacrok, Crocorible, Hippodocus, Démolosse, Persian. Synergie : sable, Ténèbres, intimidation.
  - **Jamais Mewtwo** (§8.5).
- **Accroches.** *Égoïste* : reconstruire en secret, « s'entraîner » (canon), racheter des parts de Devon ? *Ambivalent* : Silver, le fils qu'il néglige. *Tensions* : ses commandants veulent son retour, lui veut **mériter** ce retour. Hoenn est un exil plausible (plus de Rocket à Kanto, il est anonyme).
- **Assets.** `TRAINER_PIC_LEADER_GIOVANNI_FRLG` ✔. OW `OBJ_EVENT_GFX_GIOVANNI` ✔. Classe `BOSS_FRLG` sans musique dédiée (`ASSET_INVENTORY` §3.3).

### 1.15 Olga — Olga / Lorelei ✔
- **Canon.**
  - Conseil 4 de Kanto, type Glace (et Eau) **[JEU : RBJ/RFVF]**.
  - **[JEU : RFVF]** Elle est retournée sur l'Île 4 (Île Kin ◐), sa maison pleine de peluches ◐. Elle aide contre les vols de Lokhlass par la Rocket ◐.
  - **[JEU : GSC]** Remplacée par Clément.
  - **[MANGA]** Elle était l'antagoniste (Conseil 4 maléfique).
- **Perso.** Élégante, froide en combat, chaleureuse à la maison ; aime les poupées ◐.
- **Liens.** Collègues : Aldo, Agatha, Peter.
- **Équipes.**
  - **RFVF** : Lamantine 52, Crustabri 51, Flagadoss 52, Lippoutou 54, Lokhlass 54 ✔.
  - **Revanche RFVF** ◐ : 60+ (Kaimorse ?).
- **Identité stratégique.** Glace et Eau **bulky** : Lamantine (Isograisse), Lokhlass (Absorbe-Eau), Flagadoss (Lavabo / Repos), Crustabri (Exuviation, Gen 5). Grêle ou Neige (Gen 9). Entre attrition et une offensive surprise (Crustabri qui « exuvie »).
- **Concepts (HYPOTHÈSE).**
  - **A « Neige »** : **Blizzaroi** (Alerte Neige), **Glaivodo** ◐, Crustabri (Exuviation), Lokhlass, Kaimorse, Lippoutou.
  - **B « Île Kin »** : Lokhlass, Momartik, Dimoret, Séracrawl, Lamantine, Flagadoss.
  - **C « anti-dragon »** : quatre Glace plus Givrali, avec un Voile Aurore (Neige).
- **Accroches.** Elle **protège les Lokhlass** de Sevii, braconnés par la Rocket (canon). Elle peut suivre une piste de braconnage jusqu'à Hoenn (Lokhlass vendus au marché noir). Elle rencontre **Glacia** : deux spécialistes Glace, Glacia venue d'ailleurs (Hoenn est « trop chaud », RSE ✔ ◐).
- **Assets.** `TRAINER_PIC_ELITE_FOUR_LORELEI_FRLG` ✔. OW `OBJ_EVENT_GFX_LORELEI` ✔.

### 1.16 Aldo — Aldo / Bruno ✔
- **Canon.** Conseil 4 de RBJ/RFVF **et** de GSC/HGSS, type Combat. **[JEU : RFVF]** Après la Ligue, on le croise à Sevii (Île 1, Mont Braise ◐), où il s'entraîne.
- **Perso.** Ascète, honnête, « nos muscles… », fair-play.
- **Liens.** Collègues de Conseil.
- **Équipes.**
  - **RFVF** : Onix 51, Tygnon 53, Kicklee 53, Onix 54, Mackogneur 56 ✔.
  - **GSC** : Kapoera, Kicklee, Tygnon, Onix, Mackogneur (42–46).
  - **HGSS revanche** ◐ : Steelix, Kapoera, etc.
- **Identité stratégique.** Combat **bulky physique** : Mackogneur (Annule Garde : Dynamopoing toujours touchant), Onix (assez faible), Kapoera (Intimidation / Technicien).
- **Concepts (HYPOTHÈSE).**
  - **A « Dojo »** : Mackogneur (Annule Garde), Bétochef (Cran + Orbe Toxique), Kapoera (Intimidation, Bluff), Steelix, Hariyama (Isograisse), Lucario.
  - **B « Montagne »** : Courrousinge, Shifours, Ékaïser, Steelix. Synergie : Cran, Abri contre les pièges.
- **Accroches.** C'est l'**ascète voyageur** : il vient à Hoenn s'entraîner avec Bastien (Combat) ou au Pilier Céleste. Il est mentor naturel d'enfants (dojo). *Égoïste* : trouver un adversaire digne.
- **Assets.** `TRAINER_PIC_ELITE_FOUR_BRUNO_FRLG` ✔. OW `OBJ_EVENT_GFX_BRUNO` ✔.

### 1.17 Agatha — Agatha / Agatha ✔
- **Canon.**
  - Conseil 4 de RBJ/RFVF, type Spectre (et Poison).
  - Elle méprise Chen ✔ : « Oak was once tough and handsome… now just a wimp ».
  - **[JEU : GSC]** Retraitée, remplacée par Marion ✔ ◐.
- **Perso.** Vieille femme acerbe, canne, rancune envers Chen ; elle respecte la force.
- **Liens.** Rivale de Chen (et ancienne relation ? ◐ suggéré par l'anime et le fandom).
- **Équipes.** **RFVF** : Ectoplasma 54, Nosferalto 54, Spectrum 53, Arbok 56, Ectoplasma 58 ✔.
- **Identité stratégique.** Spectre et Poison **statut et piège** : Hypnose, Dévorêve, Malédiction, Regard Noir, Destiny Bond.
- **Concepts (HYPOTHÈSE).**
  - **A « Tour Pokémon »** : Ectoplasma, Spiritomb, Noctunoir, Momartik, Nostenfer, Arbok.
  - **B « Rituel »** : Lugulabre, Spiritomb, Magirêve, Tutankafer, Ectoplasma. Synergie : Destiny Bond, Malédiction, Pièges.
- **Accroches.** Déjà prévue au Mont Mémoria avec Spectra (`CHARACTER_AND_LORE` §3.15). *Égoïste* : régler ses comptes avec Chen ; recruter une héritière (Spectra ?). *Altruiste* : rites pour les âmes.
- **Assets.** `TRAINER_PIC_ELITE_FOUR_AGATHA_FRLG` ✔. OW `OBJ_EVENT_GFX_AGATHA` ✔.

### 1.18 Peter — Peter / Lance ✔
- **Canon.**
  - Maître du Conseil 4 de Kanto, type Dragon **[JEU : RBJ/RFVF]**.
  - **[JEU : GSC/HGSS]** Maître de la Ligue (Indigo). Il aide à démanteler la Rocket (Repaire d'Acajou, Tour Radio). Il est du **clan des dragons d'Ébènelle**, cousin de Sandra (Clair).
  - **[JEU : HGSS]** Il porte une cape ; il utilise Ultralaser.
  - **[MANGA]** Antagoniste qui hait les humains.
- **Perso.** Noble, droit, protecteur ; il utilise des Pokémon « dragons » et non-Dragons (Léviator, Ptéra, Dracaufeu GSC).
- **Liens.** Cousin de Sandra ✔. Son clan est mené par le Doyen d'Ébènelle (son grand-père ◐). Il fait figure d'aîné moral pour Blue.
- **Équipes.**
  - **RFVF** : Léviator 56, Draco 54, Draco 54, Ptéra 58, Dracolosse 60 ✔.
  - **GSC/HGSS** : Léviator, Dracolosse ×3, Dracaufeu, Ptéra (44–50 ; HGSS revanche 70+).
  - **[NON-CANON : Masters]**
- **Signature.** Dracolosse ; Léviator rouge ◐ (capturé au Lac Colère par le joueur, Peter y est présent ✔ GSC).
- **Identité stratégique.** **Dragons physiques et Danse Draco**, plus des « pseudo-dragons » (Léviator, Ptéra, Dracaufeu). Couverture élémentaire (Dracolosse apprend tout).
- **Concepts (HYPOTHÈSE).**
  - **A « Maître »** : Dracolosse (Multiécaille), Léviator, Ptéra, Dracaufeu, Carchacrok, Hyporoi.
  - **B « Site Météore »** : Drattak (natif de Hoenn), Libégon, Altaria, Dracolosse. C'est le pont avec Aragon et Amaryllis (Peuple du Météore : rivalité de clans dragons).
  - **C « anti-joueur »** : Méga-Drattak ou Ékaïser contre les Fée.
- **Accroches.** Déjà prévu au Site Météore (`CHARACTER_AND_LORE` §3.15). *Égoïste* : prestige du clan. *Altruiste* : chasser la Rocket (canon GSC). Tension avec **Amaryllis** : clan contre clan, gardiens du dragon.
- **Assets.** `TRAINER_PIC_ELITE_FOUR_LANCE_FRLG` ✔. OW `OBJ_EVENT_GFX_LANCE` ✔. **Ne pas confondre** avec le Commandant Rocket « Lance » (Proton).

### 1.19 Léo — Léo / Bill ✔
- **Canon.**
  - Concepteur du PC de Kanto.
  - Accident de téléporteur : il fusionne avec un Pokémon (Cottage de Léo, Cap d'Azuria ◐).
  - Il donne le ticket de l'Océane.
  - **[JEU : RFVF]** Il emmène le joueur à Sevii (Île 1) et présente Ciléo ✔.
  - **[JEU : GSC/HGSS]** Il est à Doublonville / Rosalia, et donne un Évoli ✔.
- **Perso.** Pokémaniaque, sympa, distrait. Il est fan d'Évoli ◐.
- **Liens.** Ami de Ciléo ✔. Sa famille vit à Doublonville (sœur, grand-père à Azuria ◐).
- **Équipes.** Aucune.
- **Identité (HYPOTHÈSE).** S'il combat : Évoli-line, Porygon-Z, Rotom (« le technicien »).
- **Accroches.** Réparation du réseau PC Kanto–Hoenn. Correspondance avec **Lanette** (créatrice des boîtes de Hoenn) : une rivalité de programmeurs.
- **Assets.** **Pas de `TRAINER_PIC`** ✘. OW `OBJ_EVENT_GFX_BILL` ✔.

### 1.20 M. Fuji — M. Fuji / Mr. Fuji ◐
- **Canon.**
  - **[JEU : RBJ/RFVF]** Il gère la Maison des Bénévoles de Lavanville. Il est captif de la Rocket à la Tour Pokémon, puis donne la Poké Flûte ✔.
  - **[JEU : LGPE]** Implicitement le créateur de Mewtwo ◐.
  - **[ORIGINS]** Créateur explicite.
  - **[ANIME : film 1]** Le Dr Fuji crée Mewtwo et essaie de cloner sa fille Ambre (Amber).
- **Perso.** Doux, pénitent, protecteur des orphelins.
- **Liens.** Lié au Manoir et à Auguste ◐. Il a été victime de la Rocket (et peut-être son ancien employeur).
- **Équipes.** Aucune.
- **Accroches.** *Pénitence* : retrouver Mewtwo pour se faire pardonner, ou empêcher qu'on recrée un clone (Deoxys → bio-ingénierie de Devon ?). Personnage de conscience. Il est âgé : faible mobilité.
- **Assets.** **Pas de `TRAINER_PIC`** ✘ (repli `OLD_MAN`). OW `OBJ_EVENT_GFX_MR_FUJI` ✔.

### 1.21 Ciléo — Ciléo / Celio ✔
- **Canon.** **[JEU : RFVF]** Ingénieur du Centre Réseau Pokémon (Île 1). Il complète la machine grâce au Rubis et au Saphir, qui relient Kanto, Hoenn et Rhode ✔. Famille : une sœur sur l'Île 1 ? (?).
- **Perso.** Discret, admiratif de Léo, honnête ; complexé par son génie modeste.
- **Liens.** Ami de Léo ✔.
- **Équipes.** Aucune.
- **Accroches.** C'est le pont le plus canonique (§8.4) : il vient à Hoenn examiner le relais. *Égoïste* : prouver qu'il vaut Léo. Rival naturel de **Lanette**.
- **Assets.** **Pas de `TRAINER_PIC`** ✘ (repli `SCIENTIST_FRLG`). OW `OBJ_EVENT_GFX_CELIO` ✔.

### 1.22 Commandants Rocket — Amos / Archer, Ariane / Ariana, Lance / Proton, Lambda / Petrel ✔
- **Canon.**
  - **[JEU : GSC]** Ce sont des « Caïds » sans nom.
  - **[JEU : HGSS]** Nommés. Ils prennent la Tour Radio de Doublonville pour rappeler Giovanni.
    - **Amos** : chef par intérim.
    - **Ariane** : seule femme.
    - **Lance** : « le plus cruel de la Team Rocket » ◐ (Puits Ramoloss).
    - **Lambda** : imitateur ; il se déguise en Giovanni et en directeur de la Tour Radio.
  - Un an après RFVF, ils sont en clandestinité (Repaire d'Acajou, ondes radio sur Magicarpe rouge en cadre GSC).
- **Équipes (HGSS ◐).**

  | Commandant | Équipe |
  |---|---|
  | Amos | Malosse ×2, Démolosse (Tour Radio) |
  | Ariane | Arbok, Mystherbe → Rafflesia ?, Cornèbre |
  | Lance | Nosferapti, Smogo (Puits Ramoloss) ; puis Nosferalto, Smogogo ◐ |
  | Lambda | Nosferalto / Smogo ×4–5 ?, Smogogo (Lac Colère) ◐ |

- **Identité.** Poison et Ténèbres, **sales** : Feu Follet, Toxik, Demi-Tour.
- **Concepts (HYPOTHÈSE).** Voir `LORE_DOSSIER` §8.5.
  - **Amos** : Démolosse, Corboss (Supersonic / Instinct ◐), Scalproie, Moufflair, Méga-Démolosse.
  - **Ariane** : Arbok, Vortente, Rafflesia, Corboss, Malamandre.
  - **Lance** : Nostenfer, Smogogo, Coatox, Drascore.
  - **Lambda** : Smogogo et **Zoroark** (Illusion : il se déguise !) ou **Métamorph** (Imposteur). C'est le gimmick idéal pour l'imitateur.
- **Accroches.** Rappeler Giovanni. Ariane et Lambda sont déjà fixés (`CHARACTER_AND_LORE` §3.14). Pour Amos (le stratège, qui reste à Kanto ?) et Lance (le cruel, homme de terrain) : une fracture interne entre ceux qui veulent un retour « digne » et ceux qui veulent un retour « à tout prix ».
- **Assets.**
  - **Aucun `TRAINER_PIC` dédié** ✘. Replis : `ROCKET_GRUNT_M/F_FRLG`, `SCIENTIST_FRLG` (Lambda déguisé), `GENTLEMAN_FRLG` (Amos ?).
  - **Aucun OW dédié** ✘. Replis : `ROCKET_M/F`.

### 1.23 Mewtwo (personnage)
- **Canon.**
  - **[JEU : RBJ/RFVF]** Journaux du Manoir : « Mew a donné naissance… nous l'avons nommé Mewtwo » ✔ ◐. « Mewtwo est trop puissant ; nous n'avons pas pu le contrôler. »
  - Caverne Azurée, niveau 70 ✔.
  - **[JEU : XY]** Méga X et Méga Y.
  - **[JEU : USUL]** Celui du Giovanni de Rainbow Rocket.
  - **[ANIME : films 1 et *Mewtwo Returns*]** Conscience, haine envers les humains, puis compassion ; quête du sens. Il protège les clones.
- **Perso (jeu).** Agressif, destructeur, « le plus sauvage ». **[ANIME]** Philosophe, blessé.
- **Liens.** « Fils » de Mew (génétiquement) ; créé par Fuji (Origins, LGPE) et Auguste ◐, financé par Giovanni (Origins).
- **Identité stratégique.** Psy **spécial**, de très haut niveau : Pression, Contre-Mesure. Méga Y (spécial) ou Méga X (Combat physique).
- **Accroches.** Un an après RFVF, il est soit capturé par Red, soit libre dans la Caverne Azurée (cadre A, §8.1). Il peut **chercher Mew** (Île Lointaine, à Hoenn !), ou fuir des chasseurs Rocket. Personnage muet (télépathe ?). Il doit **rester un mystère** : ne jamais le faire combattre pour la Rocket (§8.5).
- **Assets.** OW `OBJ_EVENT_GFX_MEWTWO` ✔. Sprite de combat : celui de l'espèce.

### 1.24 Président de Sylphe — « Président de la Sylphe SARL » / Silph President ✔
- **Canon.** **[JEU : RBJ/RFVF]** Otage de la Rocket au 11ᵉ étage ; il donne la Master Ball ✔. Il n'a pas de nom ✔.
- **Perso.** Bonhomme, reconnaissant, homme d'affaires.
- **Liens.** Ennemi de Giovanni, qui convoitait la Master Ball. Il héberge Pierre Rochard (HGSS ✔ : Pierre Rochard est à Sylphe).
- **Équipes.** Aucune.
- **Accroches.** Rivalité **industrielle** Sylphe contre Devon (Balls) : un contrat de PC, un espionnage industriel. Il pourrait financer des recherches sur Mewtwo (Master Ball oblige).
- **Assets.** **Aucun pic ni OW dédiés** ✘. Replis : `GENTLEMAN_FRLG` / `OBJ_EVENT_GFX_GENTLEMAN`.

---

## 2. HOENN

### 2.1 Brice — Brice / Brendan ✔ ◐
- **Canon.**
  - **[JEU : RSE/ROSA]** Protagoniste (fils de Norman) **ou** rival (fils de Seko) selon le choix du joueur. Détails : `LORE_DOSSIER` §8.6.
  - En rival, il aide son père et propose des combats amicaux.
  - **[JEU : E]** Combats supplémentaires, dont un post-Ligue optionnel à Bourg-en-Vol ◐.
  - **[JEU : ROSA]** Il est présent dans l'Épisode Delta et veut suivre la voie de son père ◐.
- **Perso.** **[JEU]** Amical, curieux, un peu compétitif, jamais méchant. **[ANIME]** Absent (seule Flora y apparaît). **[MANGA]** « Rubis » est un analogue : coordinateur esthète, fils de Norman.
- **Liens.** Fils de Seko (version rival) ou de Norman. Ami et rival de Flora. Il connaît Timmy (indirectement). Il connaît Pierre Rochard (ROSA ◐).
- **Équipes (rival).**
  - **RSE** : son starter (fort contre le vôtre). Il évolue en Massko / Galifeu / Flobio, puis en forme finale.
  - **E** : ses satellites dépendent du starter ◐ :
    - Jungko : Tropius, Bekipan, Volcaropod ;
    - Brasegali : Tropius, Bekipan, Lombre → Ludicolo ;
    - Laggron : Tropius, Volcaropod, Ludicolo / Tengalice.
  - Dernier combat en E à Nénucrique ◐, niveaux 31–36.
  - **ROSA** : starter, plus Bekipan, Massko… ◐.
- **Identité stratégique.** Un **naturaliste équilibré** : starter et espèces de Hoenn « de terrain », pas de cheese. Il a tendance au **pivot et au Demi-Tour** (Bekipan, Hélédelle).
- **Concepts (HYPOTHÈSE).**
  - **A « recenseur »** : starter, Tropius, Bekipan (Crachin), Ludicolo (Glissade), Volcaropod, et une espèce étrangère qu'il a « recensée » (par exemple Corvaillus).
  - **B « fils de professeur »** : espèces rares étudiées avec son père : **Relicanth**, **Absol**, **Kecleon** (Protéen), **Altaria**, Tropius.
- **Accroches.** Fixées dans `CHARACTER_AND_LORE` §3.2.
- **Assets.** `TRAINER_PIC_BRENDAN`, `RS_BRENDAN` (face) et dos `brendan` ✔. OW : `BRENDAN_*` (joueur), `RIVAL_BRENDAN_*` ✔.

### 2.2 Flora — Flora / May ✔ ◐
- **Canon.** Miroir de Brice (fille de Norman ou de Seko). **[ANIME]** Protagoniste de la saison Advanced, coordinatrice, frère **Max** (anime seulement). **[MANGA]** « Saphir » est une sauvageonne, fille de Seko.
- **Perso.** **[JEU]** Enjouée et serviable. **[ANIME]** Gourmande et coquette, elle devient une coordinatrice de talent (rival Drew).
- **Liens.** Brice ; Seko ou Norman ; Marc (Concours, anime ◐).
- **Équipes.** Les mêmes que Brice (miroir).
- **Identité (HYPOTHÈSE).** Le pendant **Concours** de Brice : esthétique et soutien. Exemples : Skitty / Delcatty, Azumarill, Milobellus, Altaria.
- **Accroches.** Fixées dans `CHARACTER_AND_LORE` (fille de Norman, attirée par les Pêcheurs d'Aqua).
- **Assets.** `TRAINER_PIC_MAY`, `RS_MAY` ✔. OW : `MAY_*`, `RIVAL_MAY_*` ✔.

### 2.3 Prof. Seko — Prof. Seko / Prof. Birch ✔
- **Canon.**
  - **[JEU : RSE/ROSA]** Professeur de Bourg-en-Vol, spécialiste de **l'habitat et de la répartition** des Pokémon. Il travaille sur le terrain.
  - Attaqué par un Medhyèna (Zigzaton en E) : c'est la scène du choix du starter ✔.
  - Il évalue le Pokédex.
  - **[JEU : ROSA]** Il a une émission de radio ? ◐.
- **Perso.** Jovial, débraillé, actif ; « préfère le terrain au labo ». **[ANIME]** Distrait et sympathique. **[MANGA]** Ami de Chen.
- **Liens.** Père de Brice ou de Flora ; son épouse n'a pas de nom ; voisin de Norman.
- **Équipes.** Aucune en jeu.
- **Identité (HYPOTHÈSE).** S'il combat : **terrain**. Zigzaton, Linéon, Grahyèna, Tropius, Relicanth ; Pokémon de la Route 101.
- **Accroches.** Fixées (`CHARACTER_AND_LORE` §3.11, la quarantaine). Ajout : il est le correspondant de Chen. *Égoïste* : publier la première étude sur les espèces étrangères, avant Chen.
- **Assets.** **Pas de `TRAINER_PIC`** ✘. OW `OBJ_EVENT_GFX_PROF_BIRCH` ✔.

### 2.4 Norman — Norman / Norman ✔
- **Canon.**
  - Champion de Clémenti-Ville, type Normal **[JEU : RSE/ROSA]**.
  - Père du protagoniste. La famille vient de Johto (ROSA ✔).
  - Il fait capturer un Pokémon à Timmy ✔ et donne Surf (via sa victoire ◐).
- **Perso.** Strict, juste, fier. Il refuse le combat tant que le joueur n'a pas quatre badges ✔.
- **Liens.** Époux de Maman ; père de Brice ou de Flora ; mentor de Timmy (capture). Il connaît Seko.
- **Équipes.**
  - **RS** : Monaflèmit 28, Vigoroth 30, Monaflèmit 31 ◐.
  - **E** : Spinda 27, Vigoroth 27, Linéon 29, Monaflèmit 31 ✔ ◐.
  - **E revanche** : Monaflèmit, Leuphorie, Kangourex, Ursaring ?, Tauros ◐.
  - **ROSA** : Monaflèmit, Vigoroth, Monaflèmit (Méga-Kangourex ? non ◐).
- **Signature.** Monaflèmit (Absentéisme : un tour sur deux).
- **Identité stratégique.** Normal **brut** : Façade, Repos et Ronflement, Monaflèmit (Absentéisme compensé par Abri, par Relais et par le pivot).
- **Concepts (HYPOTHÈSE).**
  - **A « père »** : Monaflèmit, Ursaking (forme normale), Kangourex, Leuphorie, Chelours, Étouraptor.
  - **B « Façade »** : Ursaring (Cran, Orbe Flamme), Linéon (Glissade), Tauros, Deusolourdo, Monaflèmit.
- **Accroches.** Fixées (registraire de la Ligue). *Égoïste* : préserver l'image de son arène face aux étrangers. *Tension* : Flora.
- **Assets.** `TRAINER_PIC_LEADER_NORMAN` ✔. OW `OBJ_EVENT_GFX_NORMAN` ✔.

### 2.5 Maman (« Caroline ») — Maman / Mom ; « Caroline » = anime ◐
- **Canon.** **[JEU : RSE/ROSA]** Elle donne les Chaussures de Course et parle de Norman. **[ANIME]** « Caroline », mère de Flora ✔ ◐.
- **Perso.** Chaleureuse et protectrice.
- **Liens.** Épouse de Norman (version protagoniste). Dans le hack, « Mme Seko » est un personnage distinct (`CHARACTER_AND_LORE` §3.11).
- **Accroches.** Une voix civile : elle accueille les réfugiés ?
- **Assets.** **Pas de `TRAINER_PIC`** ✘. OW `OBJ_EVENT_GFX_MOM` ✔.

### 2.6 Timmy — Timmy / Wally ✔ ◐
- **Canon.**
  - **[JEU : RSE]** Enfant malade. Il capture **Tarsal** avec l'aide du joueur (Pokémon de Norman) ✔. Il part à Vergazon (air pur, chez son oncle ◐ ; cousine Wanda ◐).
  - Il défie le joueur à Lavandia, puis à la Route Victoire.
  - **[JEU : E]** Revanche post-Ligue à Lavandia ◐.
  - **[JEU : ROSA]** Méga-Gallame à la Route Victoire ; Méga-Gardevoir à l'Île de Combat ◐.
- **Perso.** Timide, fragile, puis déterminé ; il a peur du conflit. Admire le joueur.
- **Liens.** Le joueur, Norman, son oncle et sa cousine, Tarsal.
- **Équipes.**
  - **RSE Route Victoire** : Altaria 44, Delcatty 43, Roselia 44, Magnéton 41, Gardevoir 45 ✔ ◐.
  - **ROSA Route Victoire** : Altaria, Delcatty, Roselia, Magnéton, Méga-Gallame ◐.
  - **ROSA Île de Combat** : Méga-Gardevoir ◐.
- **Identité stratégique.** Psy et Fée en **soutien et spécial** : Gardevoir ou Gallame, Altaria (Danse Draco), Roselia (Picots). Une équipe disparate, symbole d'un jeune dresseur.
- **Concepts (HYPOTHÈSE).**
  - **A « guéri »** : Gardevoir ou Gallame (Méga), Altaria, Roserade, Magnézone, Delcatty, Farfaduvet.
  - **B « soins »** : Gardevoir, Leuphorie, Altaria (Médic Nature), Roserade, Magnézone. Une équipe défensive qui raconte la guérison.
- **Accroches.** *Altruiste* : aider les enfants réfugiés malades de la cendre. *Égoïste* : prouver qu'il n'est plus fragile, battre Red (son idole ?).
- **Assets.** `TRAINER_PIC_WALLY` (face et dos) ✔, plus un PNG `wally_frlg` sans constante. OW `OBJ_EVENT_GFX_WALLY` ✔.

### 2.7 Pierre Rochard — Pierre Rochard / Steven Stone ✔
- **Canon.**
  - **[JEU : RS]** Maître de la Ligue de Hoenn.
  - **[JEU : E]** Il cède la place à Marc ; postgame au Site Météore. Il donne Terhal ✔. Combat en duo avec le joueur à Algatia (Centre Spatial).
  - **[JEU : ROSA]** Maître ; il donne le Méga-Bracelet et le Terhal ◐.
  - **[JEU : HGSS]** Il est à Kanto (Sylphe) ✔.
  - **[NON-CANON : PWT, Masters]**
- **Perso.** Calme, poli, curieux de géologie ; il se fait rare ; un peu solitaire. **[ROSA]** Plus présent, protecteur.
- **Liens.** Fils de M. Rochard ✔ ; ami de Marc ; mentor implicite du joueur ; rival de Max et d'Arthur (opposant).
- **Équipes.**
  - **RS Maître** : Airmure 57, Kaorine 55, Galeking 56, Vacilys 56, Armaldo 56, Métalosse 58 ✔ ◐.
  - **E postgame** : même équipe aux niveaux 76–78 ◐.
  - **ROSA** : Airmure, Kaorine, Galeking, Vacilys, Armaldo, Méga-Métalosse (57–59) ◐.
  - **E duo Algatia** : Métang, Airmure, Galeking ◐.
- **Signature.** Métalosse.
- **Identité stratégique.** Acier et Roche **défensif et technique** : Picots (Airmure), Piège de Roc. C'est un expert des **types résistants** : fossiles, Kaorine (Lévitation).
- **Concepts (HYPOTHÈSE).**
  - **A « Maître »** : Métalosse (Méga), Airmure, Galeking (Méga ?), Vacilys, Armaldo, Kaorine.
  - **B « collectionneur »** : Strassie, Gromago, Noacier, Duralugon, Métalosse, Archéodong. Des pierres et des métaux de partout.
- **Accroches.** Fixées (`CHARACTER_AND_LORE` §3.10). Ajouts : sa curiosité pour le Rubis et le Saphir de Ciléo (« pierres » !) ; il voyage à Kanto plus tard (HGSS) ; un dialogue avec Red, celui qui a quitté le titre (lui le perd en E !).
- **Assets.** `TRAINER_PIC_STEVEN` (face et dos) ✔, plus un PNG `champion_steven_frlg` sans constante. OW `OBJ_EVENT_GFX_STEVEN` ✔.

### 2.8 M. Rochard — M. Rochard / Mr. Stone (Joseph Stone) ✔
- **Canon.** Président de Devon SARL ✔ à Mérouville ✔. Il confie la lettre à Pierre et les Pièces Devon. Il donne le PokéNav et le Multi Exp. ◐.
- **Perso.** Jovial, reconnaissant, fier de son fils, homme d'affaires.
- **Liens.** Père de Pierre ✔ ; Capitaine Marin (Devon finance le sous-marin ◐).
- **Accroches.** Fixées (`CHARACTER_AND_LORE` §3.9). Rivalité Devon / Sylphe.
- **Assets.** **Aucun pic ni OW dédiés** ✘. En vanilla, Devon 3F utilise `OBJ_EVENT_GFX_GENTLEMAN` ✔.

### 2.9 Marc — Marc / Wallace ✔ ◐
- **Canon.**
  - **[JEU : RS/ROSA]** Champion d'Atalanopolis, type Eau.
  - **[JEU : E]** Maître de la Ligue ; élève de Juan.
  - Maître des Concours ✔.
  - **[JEU : ROSA]** Oncle de Lisia ◐ (Concours).
  - Gardien de la Grotte Origine (E/ROSA).
- **Perso.** Esthète, élégant, théâtral, sincère ; « le beau ».
- **Liens.** Juan (mentor), Pierre Rochard (ami), Lisia (nièce), Sages d'Atalanopolis.
- **Équipes.**
  - **RS Arène** : Lovdisc, Barbicha, Phogleur, Poissoroy, Milobellus ◐.
  - **E Maître** : Wailord 57, Tentacruel 55, Ludicolo 56, Barbicha 56, Léviator 56, Milobellus 58 ✔ ◐.
  - **ROSA Arène** : Lovdisc, Phogleur, Milobellus… ◐.
- **Signature.** Milobellus.
- **Identité stratégique.** Eau **beauté et durabilité** : Milobellus (Écaille Spéciale, Récupération), Wailord, Ludicolo (Pluie).
- **Concepts (HYPOTHÈSE).**
  - **A « Maître »** : Milobellus, Wailord, Ludicolo, Barbicha, Léviator (Méga), Tentacruel.
  - **B « Concours »** : Milobellus, Oratoria, Akwakwak, Hyporoi, Azumarill.
- **Accroches.** Gardien de la légende de Kyogre (Atalanopolis). *Égoïste* : le spectacle ; la peur du ridicule. Pont avec Nina (Concours) et Ondine (Eau).
- **Assets.** `TRAINER_PIC_CHAMPION_WALLACE` ✔ (pas de pic « Champion d'arène » séparé). OW `OBJ_EVENT_GFX_WALLACE` ✔.

### 2.10 Juan — Juan / Juan ✔ ◐
- **Canon.** **[JEU : E]** Champion d'Atalanopolis, type Eau ; maître de Marc ✔.
- **Perso.** Danseur raffiné, gentilhomme ; « l'art du combat ».
- **Liens.** Marc.
- **Équipes.**
  - **E** : Lovdisc 41, Barbicha 41, Phogleur 43, Colhomard 43, Hyporoi 46 ✔ ◐.
  - **E revanche** : Hyporoi, Milobellus, Kaimorse… ◐.
- **Signature.** Hyporoi.
- **Identité.** Eau **élégante et technique** : Hyporoi (Danse Pluie, Danse Draco), statut.
- **Concepts (HYPOTHÈSE).** Hyporoi, Colhomard, Kaimorse, Lanturn, Milobellus, Oratoria.
- **Accroches.** C'est l'arbitre (`CHARACTER_AND_LORE`) : il a de l'autorité morale.
- **Assets.** `TRAINER_PIC_LEADER_JUAN` ✔. OW `OBJ_EVENT_GFX_JUAN` ✔.

### 2.11 Les autres Champions de Hoenn

| FR / EN | Canon | Équipes canoniques ◐ | Identité stratégique | Concepts adultes (HYPOTHÈSE) | Assets |
|---|---|---|---|---|---|
| **Roxanne** / Roxanne ✔ | Championne de Mérouville, Roche. Elle sort de l'École des Dresseurs, étudiante et pédagogue (RSE) | RS : Racaillou, Tarinor. E : Racaillou ×2, Tarinor. ROSA : Racaillou, Tarinor ◐ | Roche, cours magistral : Fermeté, Piège de Roc | **A** Tarinorme (Magnépiège), Gigalithe, Amonistar, Bastiodon, Lougaroc. **B** sable « académique » : Hippodocus, Minotaupe | `LEADER_ROXANNE`, OW `ROXANNE` ✔ |
| **Bastien** / Brawly ✔ ◐ | Champion de Myokara, Combat, surfeur | RS : Machoc, Makuhita. E : Machoc, Méditikka, Makuhita ◐ | Combat, « grosse vague » : Hariyama (Isograisse), Réveil | **A** Hariyama, Charmina (Méga), Bétochef, Kapoera, Lucario. **B** « surf » : Hariyama plus Superdauphin et Hastacuda (Eau, hors type, pour le thème) | `LEADER_BRAWLY`, OW `BRAWLY` ✔ |
| **Voltère** / Wattson ✔ | Champion de Lavandia, Électrik. Il a bâti Lavandia et la Nouvelle Lavandia (RSE) | RS : Magnéti, Voltorbe, Magnéton. E : Voltorbe, Dynavolt, Magnéton, Élecsprint | Électrik, rire, Explosion, Magnépiège | **A** Magnézone, Élecsprint (Méga), Électrode, Élekable, Rotom-Chaleur. **B** « centrale » : Lucanon, Salarsen, Zéblitz | `LEADER_WATTSON`, OW `WATTSON` ✔ |
| **Adriane** / Flannery ✔ | Championne de Vermilava, Feu, débutante. Petite-fille de l'ancien Champion (ROSA ◐) | RS : Limagma ×2, Chartor. E : Chamallot, Limagma, Camérupt, Chartor | Feu « Sécheresse » : Chartor | **A** Chartor (Sécheresse), Camérupt (Méga), Pyrax, Volcaropod, Feunard, Monthracite | `LEADER_FLANNERY`, OW `FLANNERY` ✔ |
| **Alizée** / Winona ✔ | Championne de Cimetronelle, Vol | RS/E : Tylton, Tropius, Bekipan, Airmure, Altaria | Vol, soutien : Danse Draco (Altaria), Picots (Airmure) | **A** Altaria (Méga), Airmure, Bekipan, Corvaillus, Hélédelle (Cran). **B** Vent Arrière : Étouraptor, Fulgulairo ◐ | `LEADER_WINONA`, OW `WINONA` ✔ |
| **Lévy & Tatia** / Tate & Liza ✔ | Champions jumeaux d'Algatia, Psy. Ils combattent en **double** (E) | RS : Kaorine, Xatu, Séléroc, Solaroc ◐. E : Séléroc, Solaroc (double) | Psy en double, télépathie : Solaroc et Séléroc | **A** Solaroc, Séléroc, Symbios (Distorsion), Gardevoir, Archéodong. **B** double « Terrain Psy » : Wimessir ♂ et ♀, Sorcilence | `LEADER_TATE_AND_LIZA`, OW `TATE`, `LIZA` ✔ |

### 2.12 Conseil 4 de Hoenn

| FR / EN | Canon et personnalité | Équipes RSE ◐ (E / ROSA proches) | Identité | Concepts (HYPOTHÈSE) | Assets |
|---|---|---|---|---|---|
| **Damien** / Sidney ✔ | Voyou au grand cœur, Ténèbres ; « on va s'amuser » | Grahyèna 46, Tengalice 48, Cacturne 46, Colhomard 48, Absol 49 | Ténèbres, coups bas, Intimidation, pièges | **A** Absol (Méga), Scalpereur, Tengalice, Trioxhydre, Colhomard. **B** Farceur : Ténéfix, Angoliath | `ELITE_FOUR_SIDNEY`, OW `SIDNEY` ✔ |
| **Spectra** / Phoebe ✔ | Spectre ; elle a grandi au **Mont Mémoria** (grand-mère) ✔ ◐ ; lien avec les esprits | Teraclope 48, Branette 49, Ténéfix 50, Branette 49, Teraclope 51 | Spectre, attrition : Ombre Portée, Malédiction, Feu Follet | **A** Noctunoir, Branette (Méga), Ténéfix, Lugulabre, Mimiqui. **B** « ancêtres » : Spiritomb, Momartik | `ELITE_FOUR_PHOEBE`, OW `PHOEBE` ✔ |
| **Glacia** / Glacia ✔ | Glace ; venue d'ailleurs pour s'entraîner à Hoenn (« trop chaud ») ◐ | Phogleur ×2, Oniglali ×2, Kaimorse | Glace, Grêle ; Isograisse | **A** Kaimorse, Oniglali (Méga), Momartik, Séracrawl, Glaivodo. **B** « Neige » : Blizzaroi (Alerte Neige), Crustabri | `ELITE_FOUR_GLACIA`, OW `GLACIA` ✔ |
| **Aragon** / Drake ✔ | Dragon, ancien marin ◐ ; dur | Drackhaus 52, Altaria 54, Hyporoi 53, Libégon 53, Drattak 55 | Dragon, Danse Draco, Intimidation | **A** Drattak (Méga), Libégon, Hyporoi, Carchacrok, Altaria. **B** « Peuple du Météore » : Lanssorien, Muplodocus | `ELITE_FOUR_DRAKE`, OW `DRAKE` ✔ |

### 2.13 Max (Maxie) — Max (RSE VF) / Maxie (ROSA) ✔
- **Canon.**
  - Chef de la Team Magma. Il veut **étendre les terres** (Groudon) pour l'humanité ✔.
  - **[JEU : E]** Il éveille Groudon par erreur ; il est dépassé, puis aide à le calmer.
  - **[JEU : ROSA]** Il est ému, regrette ; Delta : il aide contre la météorite ◐. Ingénieur, lunettes.
  - **[JEU : USUL]** Version alternative dans Rainbow Rocket ✔.
- **Perso.** Intellectuel, rigide, rationaliste, plein de certitudes ; il finit par se rendre à l'évidence.
- **Liens.** Arthur (rival idéologique et ancien collègue : ROSA ◐ suggère des liens passés) ; Kelvin, Courtney.
- **Équipes.**
  - **RS / E** : Grahyèna, Nostenfer, Camérupt ◐.
  - **ROSA** : Grahyèna, Nostenfer, Méga-Camérupt ◐.
- **Identité.** Feu et Sol, **Sécheresse et Zénith** : Méga-Camérupt (Sans Limite).
- **Concepts (HYPOTHÈSE).** Camérupt (Méga), Chartor, Hippodocus, Nostenfer, Grahyèna, Monthracite.
- **Accroches.** Fixées (`CHARACTER_AND_LORE` §3.5).
- **Assets.** `TRAINER_PIC_MAGMA_LEADER_MAXIE` ✔. OW `OBJ_EVENT_GFX_MAXIE` ✔.

### 2.14 Arthur — Arthur / Archie ✔
- **Canon.** Chef de la Team Aqua ; veut **étendre les mers** (Kyogre). Il éveille Kyogre (RSE/E), puis regrette (ROSA). **[JEU : USUL]** Rainbow Rocket ✔.
- **Perso.** Pirate, fougueux, chaleureux avec ses hommes, impulsif.
- **Liens.** Max (rival), Matthieu, Sarah.
- **Équipes.** **RSE** : Grahyèna, Nostenfer, Sharpedo ◐. **ROSA** : Méga-Sharpedo ◐.
- **Identité.** Eau et Ténèbres, **Pluie et vitesse** : Sharpedo (Turbo), Crachin.
- **Concepts (HYPOTHÈSE).** Sharpedo (Méga), Bekipan (Crachin), Colhomard, Hastacuda, Léviator, Wailord.
- **Accroches.** Fixées (`CHARACTER_AND_LORE` §3.7).
- **Assets.** `TRAINER_PIC_AQUA_LEADER_ARCHIE` ✔. OW `OBJ_EVENT_GFX_ARCHIE` ✔.

### 2.15 Admins Magma et Aqua

| FR / EN | Canon | Équipes ◐ | Identité / concepts (HYPOTHÈSE) | Assets |
|---|---|---|---|---|
| **Kelvin** / Tabitha ✔ | Admin Magma, bras droit de Max (RSE/E). Dans ROSA, il veut être reconnu de Max | E : Chamallot, Grahyèna, Nosferapti, Camérupt | Feu / Poison ; **A** Camérupt, Malamandre, Nostenfer | `MAGMA_ADMIN` (partagé) ; OW `MAGMA_MEMBER_M` |
| **Courtney** / Courtney ✔ | Admin Magma (E, ROSA ; plus marquée dans ROSA : instable, obsédée par Max) | E : idem ? ROSA : Chamallot, Grahyèna ?, Camérupt ◐ | Feu « Brûlure » : Feu Follet, Malamandre, Pyrax | `MAGMA_ADMIN` (partagé, il manque un pic F distinct ✘) ; OW `MAGMA_MEMBER_F` |
| **Matthieu** / Matt ✔ | Admin Aqua, colosse jovial (RSE, ROSA) | Grahyèna, Sharpedo ◐ | Eau physique : Colhomard, Sharpedo, Hastacuda | `AQUA_ADMIN_M` ✔ ; OW `AQUA_MEMBER_M` |
| **Sarah** / Shelly ✔ | Admin Aqua, scientifique ; dans ROSA, elle doute de son chef (ROSA ◐) | Carvanha, Grahyèna, Sharpedo ◐ | Eau / statut : Prédastérie, Lanturn, Tentacruel | `AQUA_ADMIN_F` ✔ ; OW `AQUA_MEMBER_F` |

### 2.16 Scott — Scott / Scott ✔
- **Canon.** **[JEU : E]** Recruteur et fondateur de la Zone de Combat ; on le croise partout ✔. **[JEU : RS]** Simple dresseur flatteur à Lavandia ◐.
- **Perso.** Sympathique, mystérieux, toujours une longueur d'avance ; il ne se bat jamais.
- **Liens.** Il emploie les Têtes de la Zone ; il connaît Capucine (il l'a « découverte » ◐) ; il recrute Blue (`CHARACTER_AND_LORE`).
- **Accroches.** Il peut recruter Red, Blue, Aldo ou Peter. *Ambigu* : à quel point sa curiosité est-elle intéressée ?
- **Assets.** **Pas de `TRAINER_PIC`** ✘. OW `OBJ_EVENT_GFX_SCOTT` ✔.

### 2.17 Têtes de la Zone de Combat (« Meneurs ») [JEU : E]

| FR (◐) / EN | Installation | Canon et personnalité | Équipes Argent / Or ◐ | Identité / concept adulte (HYPOTHÈSE) | Assets |
|---|---|---|---|---|---|
| **Sam** / Noland | Usine | Joue avec les Pokémon de location, sympathique et nonchalant | Location (aléatoire) | Pas d'équipe fixe. Concept : « draft » Gen 1–9 adaptatif | `FACTORY_HEAD_NOLAND`, OW `NOLAND` ✔ |
| **Carole** / Greta | Dojo | Énergique, « pleine d'esprit » | Argent : Scarhino, Noctali, Munja. Or : Noctali, Ectoplasma, Chapignon | Arène : jugement de l'agressivité. **A** Bétochef, Noctali, Munja, Scarhino (Méga) | `ARENA_TYCOON_GRETA`, OW `GRETA` ✔ |
| **Bayar** / Brandon | Pyramide | Aventurier gaillard des ruines ; lié aux **Regis** | Argent : Regirock, Regice, Registeel. Or : Artikodin, Électhor, Sulfura | Le gardien des Regis. Concept : **Regigigas** en adaptatif | `PYRAMID_KING_BRANDON`, OW `BRANDON` ✔ |
| **Capucine** / Anabel | Tour | Calme, télépathe ? ◐ (elle « lit » les Pokémon) | Argent : Alakazam, Entei, Ronflex. Or : Raikou, Latios, Ronflex | Spéciale / légendaires. Pont avec Morgane | `SALON_MAIDEN_ANABEL`, OW `ANABEL` ✔ |
| **Takim** / Tucker | Dôme | Mégalo, star du spectacle | Argent : Laggron, Drattak, Dracaufeu. Or : Laggron, Métalosse, Latias | « Pseudo-légendaires » et starters | `DOME_ACE_TUCKER`, OW `TUCKER` ✔ |
| **Esteban** / Spenser | Palace | Vieux sage, « l'âme des Pokémon » (natures) | Argent : Nostenfer, Monaflèmit, Lokhlass. Or : Arcanin, Monaflèmit, Suicune | Pas de commandes : natures (IA « nature ») | `PALACE_MAVEN_SPENSER`, OW `SPENSER` ✔ |
| **Charline** / Lucy | Reptile | Taciturne, femme-serpent | Argent : Séviper, Caratroc, Milobellus. Or : Séviper, Steelix, Léviator | Statut et pièges : Séviper ; **A** Drascore, Noacier | `PIKE_QUEEN_LUCY`, OW `LUCY` ✔ |

### 2.18 Professeur Kosmo — Prof. Kosmo / Prof. Cozmo ✔
- **Canon.** **[JEU : RSE]** Chercheur en météorites à Autéquia ✔. La Team Magma lui vole la Météorite (Chutes Météore) pour le Mont Chimnée ✔. Il rend la CT Retour ◐.
- **Perso.** Pacifique, distrait, épouse inquiète.
- **Liens.** Victime de Max ; lien thématique avec Deoxys, le Peuple du Météore et Amaryllis.
- **Accroches.** Rôle de sismologue (`CHARACTER_AND_LORE`). En plus : la Météorite est-elle porteuse du « virus » de Deoxys ?
- **Assets.** **Aucun pic ni OW dédiés** ✘. En vanilla : `SCIENTIST_1` ✔.

### 2.19 Lanette — Lanette ? / Lanette
- **Canon.** **[JEU : RSE]** Créatrice du système de stockage de Hoenn (interface, 400+ Pokémon). Elle vit sur la Route 114 ✔ (Bulbapedia via extrait).
- **Perso.** Discrète, perfectionniste, un peu solitaire.
- **Liens.** Implicitement, l'homologue de Léo (Kanto) ; la machine de Ciléo connecte leurs réseaux.
- **Accroches.** Rivalité ou collaboration avec Léo et Ciléo ; réparation du lien (`CHARACTER_AND_LORE` §3.16).
- **Assets.** **Aucun pic ni OW dédiés** ✘. En vanilla : `WOMAN_2` ✔.

### 2.20 M. Marco — M. Marco / Mr. Briney ✔
- **Canon.**
  - **[JEU : RSE/ROSA]** Vieux marin à la retraite (Route 104). Son Goélise **Piko** (Peeko) est enlevé par la Team Magma ou Aqua dans le Tunnel Mérazon ✔.
  - Il transporte le joueur vers Myokara et Poivressel ✔.
- **Perso.** Bon vivant, gâteux avec Piko.
- **Liens.** Piko ; le Capitaine Marin (marins) ◐.
- **Accroches.** C'est le passeur maritime de toute l'intrigue des réfugiés (canots !).
- **Assets.** **Pas de `TRAINER_PIC`** ✘. OW vanilla `EXPERT_M` ✔, bateau `MR_BRINEYS_BOAT` ✔.

### 2.21 Amaryllis — Amaryllis / Zinnia ✔
- **Canon.**
  - **[JEU : ROSA, Épisode Delta]** Gardienne du Savoir du **Peuple du Météore** ✔. Elle veut que Rayquaza détruise la météorite qui menace la planète.
  - Elle vole la Gemme Sésame ou la Méga-Gemme ◐ et manipule pour invoquer Rayquaza.
  - Chuchmur **Aster** ✔ (souvenir d'une amie disparue ◐).
- **Perso.** Insolente, joueuse, tragique ; elle se sent investie d'un destin.
- **Liens.** Peuple du Météore ; la Doyenne du Peuple du Météore ◐ (lien de parenté ?) ; Pierre Rochard et Max/Arthur (opposants, puis alliés).
- **Équipes.** **ROSA Colonne Céleste** ✔ : Muplodocus 60, Rexillius 60, Altaria 60, Bruyverne 60, Drattak 62 (Méga).
- **Identité stratégique.** Dragons **variés et offensifs** ; Méga-Drattak (Peau Céleste).
- **Concepts (HYPOTHÈSE).** **A** son équipe ROSA, plus Lanssorien. **B** « Gardienne » : Drattak, Libégon, Altaria (Méga), Chuchmur → Ramboum, Rayquaza absent (on l'invoque, on ne le capture pas).
- **Accroches.** C'est une **anachronie** (ROSA) : utilisable si la Méga est introduite (règle du hack ✔). Rivalité de clans avec Peter. Elle sait que « le ciel » est en danger (Deoxys).
- **Assets.** **Aucun pic ni OW** ✘. Replis : `DRAGON_TAMER` repalettisé ; OW `HEX_MANIAC` ou `EXPERT_F`.

### 2.22 Sages d'Atalanopolis — « Doyen » / Sootopolis elder ◐
- **Canon.** **[JEU : RSE]** Les habitants d'Atalanopolis gardent la légende de Groudon, Kyogre et Rayquaza. Un vieil homme raconte la légende ◐. **[JEU : E]** Marc garde la Grotte Origine. **[JEU : ROSA]** Les gardiens du Mont Mémoria (le vieux couple) gardent les Gemmes.
- **Accroches.** Une figure d'autorité traditionnelle. Il sert à **refuser** l'usage des Gemmes (Orbes) par les autorités.
- **Assets.** OW `OLD_MAN` ou `EXPERT_M` ; `TRAINER_PIC_OLD_MAN` ✔ (portrait générique).

---

## 3. Légendaires et mythiques transrégionaux (Kanto ↔ Hoenn)

Résumé mythologique. Le détail du lore est dans `LORE_DOSSIER` §1.2–1.4 et §2. Les « Assets OW » sont des `OBJ_EVENT_GFX_*`. Toute espèce a de toute façon un OW générique via `OBJ_EVENT_GFX_SPECIES()`.

| Pokémon | Rôle mythologique (canon) | Lien Kanto–Hoenn | Usage narratif (HYPOTHÈSE) | OW dédié |
|---|---|---|---|---|
| **Mew** | Ancêtre de tous les Pokémon (son ADN contiendrait tous les autres) ◐ ; trouvé en Guyane (journaux du Manoir) ✔ | Île Lointaine à Hoenn (E, événement) ✔ ; Manoir de Cramois'Île | Chasse à « un second Mew » à Hoenn ; Mewtwo le cherche | `MEW` ✔ |
| **Mewtwo** | Clone modifié de Mew, créé par l'homme ✔ | Kanto (Caverne Azurée) | Thème : « la vie faite par l'homme » contre Deoxys | `MEWTWO` ✔ |
| **Deoxys** | Virus spatial muté par un rayon laser, arrivé sur une météorite ✔ ◐ | Île Aurore, accessible depuis les deux régions ✔ ; Centre Spatial d'Algatia ; Épisode Delta (ROSA) | Météorite de Kosmo ; menace venue du ciel | `DEOXYS` (+ `_A/_D/_N`, `DEOXYS_TRIANGLE`) ✔ |
| **Groudon** | Créateur des continents ; Primo-Résurgence (Gemme Rouge) ✔ | Hoenn (Grotte Origine / Mont Chimnée selon le hack) | Projet Soupape (fixé) | `GROUDON_FRONT/SIDE/ASLEEP` ✔ |
| **Kyogre** | Créateur des océans ; Gemme Bleue ✔ | Hoenn (Fondmer) | Tension latente | `KYOGRE_FRONT/SIDE/ASLEEP` ✔ |
| **Rayquaza** | Arbitre du ciel, il calme les titans ; Méga par la foi du Peuple du Météore (ROSA) ✔ | Pilier Céleste ; film *Destiny Deoxys* contre Deoxys | Amaryllis ; arbitre final | `RAYQUAZA`, `RAYQUAZA_STILL` ✔ |
| **Latias / Latios** | Éon, intelligents, rendent invisibles ; liés à l'Île du Sud (Rubis / Saphir) et à la Gemme Âme ◐ | Itinérants à Hoenn ; [ANIME : film 5] Alto Mare | Messagers, témoins | `LATIAS`, `LATIOS` ✔ |
| **Jirachi** | Exauce les vœux, s'éveille 7 jours tous les 1 000 ans ✔ | Hoenn (bonus GameCube ◐) ; « Étoile Vœu » ✔ | Le vœu égoïste ou altruiste (accroche 25 du `LORE_DOSSIER`) | ✘ (générique) |
| **Lugia / Ho-Oh** | Gardiens de la mer (les oiseaux) et de l'arc-en-ciel (Tour Cendrée) ✔ | Roc Nombri, accessible depuis Kanto (Ticketmystik) et Hoenn ✔ | Mythe de Johto qui « déborde » ; respect des morts | `LUGIA`, `HOOH` ✔ |
| **Regirock / Regice / Registeel** | Scellés par les anciens dans le Sanctuaire, en braille ✔ ; créés par Regigigas (Pt ◐) | Hoenn ; Bayar (Pyramide) | Ruines, « les hommes qui ont scellé la force » | `REGIROCK`, `REGICE`, `REGISTEEL` ✔ |
| **Artikodin / Électhor / Sulfura** | Oiseaux légendaires de Kanto ; [ANIME : film 2] les gardiens de l'équilibre (Lugia) | Kanto (Îles Écume, Centrale, Route Victoire ou Mont Braise en RFVF ✔) ; Or de Bayar | Perturbation climatique (Sulfura et l'éruption de Cramois'Île ?) | `ARTICUNO`, `ZAPDOS`, `MOLTRES` ✔ |
| **Arceus** | Créateur de l'univers (Sinnoh) ✔ | Aucun lien direct | À éviter (§2.1 du `LORE_DOSSIER`) | ✘ |
| **Celebi / Bêtes sacrées** | Voyage temporel (HGSS : retour à Giovanni) ✔ ; Entei, Raikou et Suicune, réincarnés par Ho-Oh | Celebi est le lien canonique avec Giovanni (HGSS) | Flash-back de la chute de Giovanni | `CELEBI`, `ENTEI`, `RAIKOU`, `SUICUNE` ✔ |

---

## 4. Matrice relationnelle

### 4.1 Liens canoniques (qui connaît qui)

Légende : **F** = famille · **R** = rival · **M** = mentor / élève · **A** = allié / collègue · **E** = ennemi · **C** = connaissance (vu ou évoqué en jeu). Toutes ces relations sont canon des jeux (avec l'étiquette), sauf « anime » ou « manga ».

| Personnage | Liens |
|---|---|
| **Red** | Blue (R, ami d'enfance) ; Chen (M) ; Giovanni (E) ; Peter, Olga, Aldo, Agatha (C : vaincus) ; Léo, Ciléo (A, RFVF) ; Fuji (C, sauvé) ; Président de Sylphe (C) ; Mewtwo (C) |
| **Blue** | Chen (F) ; Nina (F) ; Red (R) ; Peter (C) ; Giovanni (C : successeur à Jadielle, GSC) |
| **Chen** | Blue, Nina (F) ; Agatha (R) ; Orme (M, GSC ◐) ; Seko (A, **anime/manga seulement**) |
| **Giovanni** | Amos, Ariane, Lance, Lambda (A, subordonnés) ; Silver (F, HGSS) ; Red (E) ; Président de Sylphe (E) ; Fuji (C ◐ Origins/LGPE) |
| **Koga** | Jeannine (F) ; Conseil 4 de GSC (A) |
| **Peter** | Sandra (F) ; Conseil 4 (A) ; Blue (C) ; Rocket (E, GSC) |
| **Léo** | Ciléo (A) |
| **Auguste** | Fuji ◐, Manoir / Mewtwo (C ◐) |
| **Pierre Rochard** | M. Rochard (F) ; Marc (A) ; Max, Arthur (E) ; Sylphe / Kanto (C, HGSS) ; Amaryllis (E puis A, ROSA) |
| **Marc** | Juan (M) ; Lisia (F, ROSA) ; Pierre Rochard (A) |
| **Norman** | Brice / Flora (F) ; Timmy (M) ; Seko (C, voisins) |
| **Seko** | Brice / Flora (F) ; Norman (C) |
| **Timmy** | Joueur (A) ; Norman (M) ; son oncle et sa cousine (F) |
| **Max** | Kelvin, Courtney (A) ; Arthur (R) ; Kosmo (E : vol de la Météorite) |
| **Arthur** | Matthieu, Sarah (A) ; Max (R) ; M. Marco (C : Piko enlevé) |
| **Scott** | Les Têtes de la Zone (A, employeur) |
| **Amaryllis** | Peuple du Météore (F / communauté) ; Pierre Rochard, Max, Arthur (C, ROSA) |
| **Spectra** | Mont Mémoria / sa grand-mère (F ◐) |

**Aucun lien canonique Kanto ↔ Hoenn entre personnages**, à deux exceptions près :
- Pierre Rochard → Sylphe / Kanto (HGSS ✔) ;
- les leaders Max et Arthur alternatifs sous un Giovanni alternatif (USUL ✔, multivers).

Tout autre lien est **HYPOTHÈSE**.

### 4.2 Tensions et affinités exploitables (HYPOTHÈSE, fondées sur le canon)

| Paire | Nature | Pourquoi ça marche |
|---|---|---|
| Red ↔ Pierre Rochard | Affinité / miroir | Deux Maîtres qui « quittent » leur titre (Red de son plein gré ; Pierre en E) ; deux silencieux |
| Red ↔ Brice | Miroir de valeurs | `LORE_DOSSIER` §8.6 |
| Blue ↔ Brice / Flora | Agacement → respect | Rival « Blue » contre rival « collègue » |
| Blue ↔ Scott | Tentation | Scott offre à Blue la scène qu'il n'a pas eue |
| Chen ↔ Seko | Collégialité / compétition | Pokédex contre étude d'habitat |
| Chen ↔ Agatha | Rancune ancienne | Canon. Leur rencontre peut se faire à Hoenn (Mont Mémoria) |
| Agatha ↔ Spectra | Transmission | Spectre, deuil, Mont Mémoria |
| Olga ↔ Glacia | Affinité | Deux spécialistes Glace exilées du froid |
| Aldo ↔ Bastien | Mentorat | Combat, dojo, enfants |
| Peter ↔ Aragon / Amaryllis | Rivalité de clans dragons | Ébènelle contre le Peuple du Météore ; Drattak natif de Hoenn |
| Morgane ↔ Lévy & Tatia / Capucine | Affinité psychique | Prophétie, télépathie |
| Major Bob ↔ Voltère | Camaraderie | Électrik, « vieux bâtisseurs » |
| Erika ↔ Adriane | Affinité / contraste | Parfums contre sources chaudes ; deux héritières jeunes |
| Ondine / Nina ↔ Marc | Admiration | Eau / Concours |
| Auguste ↔ Max | Affinité dangereuse | Volcanologie ; le précédent de Cramois'Île |
| Koga ↔ Rocket | Ambiguïté | Ninja espion ; passé Rocket (manga) |
| Giovanni ↔ M. Rochard | Rivalité d'affaires | Devon contre l'empire Rocket ou Sylphe |
| Président de Sylphe ↔ M. Rochard | Concurrence | Balls, PC, brevets |
| Léo / Ciléo ↔ Lanette | Collaboration / rivalité technique | Réseau PC |
| Fuji / Auguste ↔ Mewtwo | Culpabilité | Créateurs face à leur créature |
| Lambda ↔ tous | Méfiance | Le déguiseur : n'importe quel PNJ peut être lui |
| Timmy ↔ Red | Idole | Le garçon fragile face à la légende |
| Kelvin / Courtney ↔ Ariane | Ressemblance | Admins loyaux jusqu'à l'aveuglement ; une alliance possible ou un piège |

---

## 5. Synthèse des assets manquants

Vérifié dans `include/constants/trainers.h` et `include/constants/event_objects.h`. Les OW de RFVF sont compilés dans Émeraude (`object_event_graphics_info_pointers.h`, ligne 648).

| Personnage | `TRAINER_PIC_*` | `OBJ_EVENT_GFX_*` | Repli proposé |
|---|---|---|---|
| Nina (Daisy) | ✘ | ✔ `DAISY` | pic : `LADY_FRLG` / `BEAUTY_FRLG` |
| Jeannine | ✘ | ✘ | OW `NINJA_BOY` ; pic `BATTLE_GIRL` |
| Léo (Bill) | ✘ | ✔ `BILL` | pic `POKEMANIAC_FRLG` / `SUPER_NERD_FRLG` |
| M. Fuji | ✘ | ✔ `MR_FUJI` | pic `OLD_MAN` |
| Ciléo | ✘ | ✔ `CELIO` | pic `SCIENTIST_FRLG` |
| Commandants Rocket (×4) | ✘ | ✘ | `ROCKET_GRUNT_M/F_FRLG` ; OW `ROCKET_M/F` |
| Président de Sylphe | ✘ | ✘ | `GENTLEMAN(_FRLG)` |
| Prof. Seko | ✘ | ✔ `PROF_BIRCH` | — |
| Maman | ✘ | ✔ `MOM` | — |
| M. Rochard | ✘ | ✘ | `GENTLEMAN` (vanilla) |
| Scott | ✘ | ✔ `SCOTT` | pic `EXPERT_M` |
| Kelvin / Courtney | un seul `MAGMA_ADMIN` | ✘ (sbires `MAGMA_MEMBER_M/F`) | — |
| Matthieu / Sarah | ✔ `AQUA_ADMIN_M/F` | ✘ (sbires `AQUA_MEMBER_M/F`) | — |
| Prof. Kosmo | ✘ | ✘ | `SCIENTIST_1` |
| Lanette | ✘ | ✘ | `WOMAN_2` |
| M. Marco | ✘ | ✘ | `EXPERT_M` (vanilla) |
| Amaryllis | ✘ | ✘ | `DRAGON_TAMER` ; `HEX_MANIAC` |
| Sage d'Atalanopolis | `OLD_MAN` (générique) | ✘ | `OLD_MAN` |
| Mewtwo et légendaires | pic d'espèce | ✔ (sauf Jirachi, Arceus : générique) | `OBJ_EVENT_GFX_SPECIES()` |

**Personnages complets** (pic et OW) : Red, Leaf, Blue, Chen, les 8 Champions de Kanto (sauf Jeannine), Giovanni, Olga, Aldo, Agatha, Peter, Brice, Flora, Timmy, Pierre Rochard, Norman, Marc, Juan, les 8 Champions de Hoenn, le Conseil 4 de Hoenn, Max, Arthur et les 7 Têtes de la Zone.

**PNG prêts à brancher** (sans constante) : `wally_frlg`, `champion_steven_frlg`.

---

## 6. Points à vérifier en priorité (Poképédia)

1. Les noms FR des Têtes de la Zone (Sam, Carole, Bayar, Capucine, Takim, Esteban, Charline), tirés du mini-site de lancement.
2. Lanette (nom FR) ; Doyen / Sages d'Atalanopolis.
3. Les équipes HGSS de revanche des Champions de Kanto et des Commandants Rocket (◐).
4. Les équipes de Courtney et de Matthieu dans ROSA.
5. Les équipes Or et Argent des Têtes de la Zone (◐ de mémoire).
6. Les noms FR des espèces Gen 8–9 cités sans ✔ (Glaivodo, Fulgulairo, Monumontagne : à vérifier, voire à retirer).
