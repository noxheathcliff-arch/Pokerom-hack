# CHARACTER_AND_LORE — *Pokémon Confluence* (v3.0, brief A)

> **Rôle.** Document lié à la bible (`GAME_DESIGN_BIBLE.md` v3.0, §9 et §3–§4). Il donne la distribution, la toile relationnelle, les voix, le lore, la mythologie et la chronologie. Auteur : GM spécialiste « distribution et relations », sous l'autorité du GMD. Date : 2026-10-14.
> **Statut : `proposé`.** Rien n'est implémenté ni testé. Toute invention porte `HYPOTHÈSE` ; tout fait de jeu porte `CANON (code)`. Les autres médias sont signalés `[ANIME]`/`[MANGA]` et ne contraignent rien.
> **Ce document ne fait pas :** les équipes (brief B), les ID de flags et vars ni la logique des décisions (brief C), les espèces (brief D). Il **demande** des états par nom logique (`STANCE_*`, `REL_*`) ; seul le brief C les alloue.
> **Méthode appliquée.** Chaque personnage passe le **test du figurant** (« sans Red, demain il… »). Une position ne bouge **que** par une **preuve** (P), une **relation** (R) ou un **événement** (É), jamais par une option de menu (leçon N12). Chaque mécanique de personnage est lue sur 4 couches (effet, fiction, sens appris, thème) quand elle porte du sens.
> **Lignes de texte.** Chaque échantillon s'écrit “ligne 1 / ligne 2” (le ` / ` sépare les deux lignes d'une boîte). Toutes ont été mesurées avec la table `gFontNormalLatinGlyphWidths` (`src/fonts.c`) et `charmap.txt`, guillemets compris : **toutes ≤ 208 px** (journal en §12.3).

## Sommaire
- §0 Conventions et règles de voix transversales
- **§1 Tables d'interface (A → C, A → B)** : liste `C-xx`, positions, pulsations, scènes de témoin, relations déplaçables, états demandés, identités de combat
- §2 Toile relationnelle (matrice + liste)
- §3 Rang A (11 fiches)
- §4 Mission Indigo, Kanto, Rocket (rang B)
- §5 Hoenn (rang B)
- §6 Rang C et personnages muets
- §7 Brice parle pour Red (les 5 gestes)
- §8 Lore et mythologie
- §9 Chronologie détaillée
- §10 Registre des promesses (plants et récoltes)
- §11 Qui gagne si X échoue (complet)
- §12 Contrôles : canon année 3, raison d'être à Hoenn, N1–N23, checklists, conflits avec la bible
- §13 Changelog

---

## 0. Conventions

**Axes (bible §7).** Axe A : `REM` Rempart · `INT` Intégration · `MAR` Marché · `RAP` Rapatriement. Axe B : `SCE` Sceau · `CTL` Contrôle · `LIB` Libération · `BRI` Briser · `CIE` le Ciel juge · `VOL` (Rocket). `—` = indifférent. **Précision :** la bible écrit « COMPRENDRE » en axe B pour Chen et Pierre (Brock). Ce n'est pas une valeur de l'axe ; on la lit `CTL` (« garder le réseau assez longtemps pour étudier ») — voir conflit K-03 (§12.5).
**Pulsations :** P présentation · É épreuve · B bascule · E écho. **Rangs :** A ≥ 6 scènes ; B ≥ 4 pulsations ; C ≥ 2 scènes + un écho.
**Agenda :** É égoïste · A altruiste · M mixte. **Fins :** F1 Sceau · F2 Pacte · F3 Passerelle · F4 Rempart · F5 Ciel ouvert.
**Saillance :** la ligne la plus spécifique gagne (ordre : état de fin > décision du chapitre > relation ≥ seuil > défaut).

### 0.1 Règles de voix transversales (HYPOTHÈSE de style)
| Règle | Contenu |
|---|---|
| Tutoiement | Kanto tutoie Red (on l'a connu enfant). Hoenn officiel le **vouvoie** (Champion étranger) jusqu'à la confiance. **Giovanni et Peter vouvoient** Red : respect froid pour l'un, protocole pour l'autre. Amaryllis tutoie tout le monde, dieux compris |
| Une idée par boîte | Jamais de tirade : 3 boîtes de suite maximum sans geste, combat ou mouvement |
| Le silence de Red | Les PNJ **réagissent** à son silence (gêne, respect, colère). Personne ne parle à sa place sauf Brice, et Brice le dit (§7) |
| Humour | Il vient des personnages (Brice, Blue, Major Bob, Bastien, le petit voleur). Une respiration après chaque scène forte (bible §2) |
| Jargon | Les mots du monde sont fixes : **anneau**, **arrivant**, **natif**, **Passerelle**, **Kiosque**, **Rempart**, **Fiole**, **le Pilier**, **le Sommet**. Le mot « Hoopa » n'apparaît pas avant R2b (ch. 8) |
| Interdits globaux | Pas de « méchant » autoproclamé ; pas de morale adressée au joueur ; pas de chiffres de morts ; aucun personnage ne dit « tu avais raison » à Red sans preuve montrée |

---

## 1. Tables d'interface (publiées pour S1 ; noms logiques gelés après S1)

### 1.1 Liste des personnages (`C-xx`)
| ID | Personnage (FR / EN) | Rang | Groupe | Var / état lié (bible §11) |
|---|---|---|---|---|
| C-01 | Red | A | joueur | Carnet, `N` |
| C-02 | Brice / Brendan | A | Bourg-en-Vol | `BR`, `BV` |
| C-03 | Blue | A | Kanto (Scott) | `BL` |
| C-04 | Hoopa Confiné (« le petit voleur ») | A (muet) | mythe | `HO` |
| C-05 | Amaryllis / Zinnia | A | dissidente | `AM` |
| C-06 | Giovanni | A | indépendant | `GI` |
| C-07 | Peter / Lance | A | Mission Indigo | `PE`, `rI` |
| C-08 | Pierre Rochard / Steven | A | Ligue de Hoenn | `PR` |
| C-09 | Prof. Chen / Oak | A | Kanto | — |
| C-10 | Prof. Seko / Birch | A | Bourg-en-Vol | — |
| C-11 | Flora / May | A | Rempart | `FL` |
| C-12 | Pierre / Brock | B | Mission | — |
| C-13 | Ondine / Misty | B | Mission | — |
| C-14 | Major Bob / Lt. Surge | B | Mission | — |
| C-15 | Erika | B | Mission | — |
| C-16 | Koga | B | Mission | — |
| C-17 | Jeannine / Janine | C | Mission | — |
| C-18 | Morgane / Sabrina | B | Mission | — |
| C-19 | Auguste / Blaine | B | Magma (consultant) | — |
| C-20 | Olga / Lorelei | B | Mission | — |
| C-21 | Aldo / Bruno | B | Mission (escorte) | — |
| C-22 | Agatha | B | indépendante | — |
| C-23 | Léo / Bill | B | Consortium | — |
| C-24 | Ciléo / Celio | B | nœud Kanto | — |
| C-25 | M. Fuji | B | indépendant | — |
| C-26 | Président de Sylphe | B | Consortium | `rC` |
| C-27 | Nina / Daisy | C | Kanto | — |
| C-28 | Ariane / Ariana | B | Rocket | `RK` |
| C-29 | Lambda / Petrel | B | Rocket | `RK` |
| C-30 | Lance (Rocket) / Proton | B | Rocket | `RK` |
| C-31 | Amos / Archer | C | Rocket | `RK` |
| C-32 | Norman | B | Rempart | `rL` |
| C-33 | Timmy / Wally | B | Vergazon | `TI` |
| C-34 | M. Rochard / Mr. Stone | B | Consortium | `rC` |
| C-35 | Marc / Wallace | B | Gardiens | `rG` |
| C-36 | Juan | B | Atalanopolis | — |
| C-37 | Roxanne | B | Ligue | — |
| C-38 | Bastien / Brawly | B | Ligue | — |
| C-39 | Voltère / Wattson | B | Ligue | — |
| C-40 | Adriane / Flannery | B | Ligue | — |
| C-41 | Alizée / Winona | B | Ligue | — |
| C-42 | Lévy et Tatia / Tate & Liza | B | Ligue | — |
| C-43 | Damien / Sidney | B | Conseil 4 | — |
| C-44 | Spectra / Phoebe | B | Conseil 4 | — |
| C-45 | Glacia | B | Conseil 4 | — |
| C-46 | Aragon / Drake | B | Conseil 4 / Gardiens | `rG` |
| C-47 | Max / Maxie | B | Magma | `rM` |
| C-48 | Arthur / Archie | B | Aqua | `rA` |
| C-49 | Kelvin / Tabitha | C | Magma | `rM` |
| C-50 | Courtney | C | Magma | `rM` |
| C-51 | Matthieu / Matt | C | Aqua | `rA` |
| C-52 | Sarah / Shelly | C | Aqua | `rA` |
| C-53 | Scott | C | indépendant | — |
| C-54 | Bayar / Brandon | C | Zone de Combat | — |
| C-55 | Capucine / Anabel | C | Zone de Combat | — |
| C-56 | Prof. Kosmo / Cozmo | C | Autéquia | — |
| C-57 | Lanette | C | Consortium | — |
| C-58 | M. Marco / Mr. Briney | C | Route 104 | — |
| C-59 | Capitaine Marin / Capt. Stern | C | Poivressel | — |
| C-60 | Mme Seko | C | Bourg-en-Vol | — |
| C-61 | La Doyenne du Peuple du Météore | C | Gardiens | `rG` |
| C-62 | Les Sages d'Atalanopolis (porte-parole : le Sage aîné) | C | Gardiens | `rG` |
| C-63 | Rayquaza | C (muet) | mythe | `PA` |
| C-64 | Autres Têtes de la Zone (Sam, Carole, Takim, Esteban, Charline) | C (groupe) | postgame | — |

### 1.2 Positions par personnage (A → C)
Lecture : *défaut* = position au premier contact. *Atteignable* = ce que le personnage peut devenir. *Moteur* = ce qui le déplace (P preuve, R relation, É événement). *Nom logique* = état demandé au brief C ; « dérivé » = calculable à partir d'états déjà prévus (pas de nouveau stockage).

| ID | Perso | Défaut A / B | Atteignable | Moteur (jamais un menu) | Nom logique demandé | Stockage suggéré |
|---|---|---|---|---|---|---|
| C-02 | Brice | — / — | `BV` : PROTÉGER = REM/SCE · ACCUEILLIR = INT/LIB · COMPRENDRE = RAP/CTL | É : scènes où Red l'a emmené (calcul brief C) ; son vote ch. 12 suit `BV`, **pas** `BR` | `BV` (bible) | existant |
| C-03 | Blue | MAR / — | LIBRE / — (quitte Scott) | É toit ch. 9 + R `BL` ≥ seuil | `STANCE_BLUE` {SCOTT, LIBRE} | 1 bit |
| C-05 | Amaryllis | — / CIE | ch. 13 : PERSISTE · RENONCE · SACRIFICE | P : preuve de la mort de la gardienne (Lance, ch. 12) ; P : bulletin des civils d'Algatia ; R `AM` | `AM_ISSUE` (temporaire climax) | dérivé au climax |
| C-06 | Giovanni | MAR / refuse VOL | témoigne au Sommet ou non | É : Lambda démasqué ch. 10 ; R `GI` ≥ seuil | dérivé (`GI` + flag ch. 10) | dérivé |
| C-07 | Peter | RAP / SCE | ch. 12 : KANTO ASSUME · KANTO SE DÉFEND | P : ≥ 2 pièces Kanto (article annoté, registre du coffre) ; É ch. 5 (Site respecté) ; R `PE` | `STANCE_PETER` | 1 bit |
| C-08 | Pierre Rochard | INT prudente / CTL | B : CTL → SCE ; père : PROTÈGE → ACCUSE | É : inscription lue (ch. 9) + R Marc → SCE ; P : registre du coffre **ou** enregistrement de Léo, + R `PR` → ACCUSE | `STANCE_PR` (axe B, père) | 2 bits |
| C-09 | Chen | INT / CTL | ch. 12 : AVOUE · NIE | P : article annoté saisi sur Lance (ch. 9) ; É : accusation d'Agatha ; R : réconciliation avec Seko | `STANCE_CHEN` | 1 bit |
| C-10 | Seko | REM doux / SCE | ÉCOUTE (son fils) · FERMÉ | É : publication de Brice (ch. 7) + geste de Red | `REL_CHEN_SEKO` (voir 1.5) | dérivé + 1 bit |
| C-11 | Flora | REM / SCE | ch. 13 : OBÉIT · DÉSOBÉIT | R `FL` ; É : témoin de Vergazon (ch. 7) ; R : Brice | `FL` + flag climax | existant |
| C-12 | Pierre (Brock) | INT / CTL | vote ch. 12 : INT ferme · retrait (amer) | É : ses protégés de Vergazon sauvés ou abattus (ch. 7) | dérivé (issue ch. 7) | dérivé |
| C-13 | Ondine | INT / LIB | ch. 11 : camp AQUA · camp MISSION | R : alliance Arthur (ch. 9) ; P : pêcheurs ruinés montrés (Aldo) | `REL_ONDINE_ARTHUR` | 1 bit |
| C-14 | Major Bob | REM / SCE | vote d'abattage ch. 7 : POUR · CONTRE | É : quartier coupé de Lavandia (ch. 4) rétabli ou non par Red | dérivé (issue ch. 4) | dérivé |
| C-15 | Erika | MAR / CTL | INT / CTL | É : vergers et arrivant de Timmy (ch. 4–7) ; P : relevé de Roxanne | `STANCE_ERIKA` | 1 bit |
| C-16 | Koga | — / CTL | DÉMASQUÉ · COUVERT · IGNORÉ | P : page du carnet de primes (ch. 4) ; geste de Red (**montrer** à Peter ou non) | `REL_KOGA_PETER` | 2 bits |
| C-18 | Morgane | — / SCE | — / LIB (ou abstention) | É : vision (ch. 8) ; R : Lévy et Tatia entendent la « voix » (ch. 10) | dérivé (présence ch. 10) | dérivé |
| C-19 | Auguste | REM géré / CTL | INT / LIB (rejoint Fuji) | É : Hoopa blessé à la démonstration (ch. 6) ; R : Fuji (ch. 9) | `REL_AUGUSTE_FUJI` | 1 bit |
| C-20 | Olga | RAP / SCE | accepte l'aide de Hoenn ou non | É : la nuit du marché (ch. 9, présence exclusive) | dérivé (L ch. 9) | dérivé |
| C-21 | Aldo | REM / — | s'engage (REM) · reste neutre | É : Myokara ruinée ou non (ch. 2 et 9) | dérivé | dérivé |
| C-22 | Agatha | — / SCE | pardonne (transmet à Spectra) · rancune | É : rite protégé ou profané (ch. 9) ; É : Chen avoue | dérivé | dérivé |
| C-24 | Ciléo | — / CTL | — / LIB | É : il voit la Fiole (ch. 10), automatique | dérivé | aucun |
| C-25 | Fuji | INT / LIB | BRI (ch. 13) | É : garde de Hoopa (ch. 8) ; `HO` bas ; affectation au relais | dérivé au climax | dérivé |
| C-26 | Président de Sylphe | MAR / CTL | CONFESSION · CHUTE | P : registre du coffre ; P : témoignage de Giovanni ; R : M. Rochard se retourne | `STANCE_SYLPHE` | 1 bit |
| C-32 | Norman | REM / SCE | REM ferme · abstention (sa fille) | É : bascule de Flora (ch. 7, ch. 13) | dérivé (Flora) | dérivé |
| C-34 | M. Rochard | MAR / CTL | VÉRITÉ · SILENCE | R : son fils ACCUSE (`STANCE_PR`) ; P : battement du Cœur | dérivé | dérivé |
| C-35 | Marc | INT / SCE | vote avec les Sages · avec son ami | R : position de Pierre Rochard | dérivé | dérivé |
| C-36 | Juan | — / — | impartial · prend parti (pour la vérité établie) | P : trois sources concordantes au Sommet (R4) | dérivé (Dossier) | dérivé |
| C-37 | Roxanne | REM prudent / — | RAP / — | P : carte de Brice publiée (ch. 7) | dérivé | dérivé |
| C-46 | Aragon | — / SCE | réconcilié avec Amaryllis · rompu | É : ch. 5 (Peter respecte le Site) ; R : Doyenne | `REL_AMARYLLIS_ARAGON` | 1 bit |
| C-47 | Max | REM géré / CTL | ÉCOUTE · PERSISTE | P : disparition des Pokémon des sources (ch. 6) ; R : départ d'Auguste | `STANCE_MAX` | 1 bit |
| C-48 | Arthur | INT / LIB | NÉGOCIE · COUPE (→ BRI) | R : Sarah ; P : données de l'Institut (ch. 8, règle H3) | `STANCE_ARTHUR` (si le câble n'a pas déjà son flag) | 1 bit |
| C-52 | Sarah | INT / LIB | DOUTE PUBLIC · RESTE | P : Red **montre** ses propres données (ch. 8) ; É : ch. 11 | `REL_SARAH_ARTHUR` | 1 bit |
| autres | Hoopa, Ariane, Lambda, Lance (Rocket), Amos, Voltère, Adriane, Alizée, Bastien, Lévy et Tatia, Damien, Spectra, Glacia, Timmy, Léo | positions **fixes** (fiches) | — | — | — | — |

**Coût total demandé :** environ 17 bits nouveaux (2 vars en E-BITS, ou des flags), le reste dérivé. Le brief C peut fusionner un `STANCE_*` avec un flag de décision existant s'il porte la même information.

### 1.3 Pulsations (A → C) — vue compacte
Format : `ch. carte` ; le déclencheur, ce qu'on voit et l'action du joueur sont dans chaque fiche.

| ID | P | É | B | E (et autres scènes) |
|---|---|---|---|---|
| C-02 Brice | 0 R101 (nuit, sauvetage) | 5 Chutes Météore (ses données contredisent son père) | 7 Bourg-en-Vol (publie seul) ; 12 Atalanopolis (vote à lui) | 0 R103, 4 R110, 8 R119 (combats) ; épilogue (voix) |
| C-03 Blue | 3 Poivressel, Tente de Scott | 9 Nénucrique, toit | 13 veillée (vient ou non) | 14 Route Victoire ; P Bourg-en-Vol (départ) |
| C-04 Hoopa | 1 Mérouville (vole le carnet) | 6 Mont Chimnée (blessé par l'anneau) | 8 Cimetronelle (piège de Koga) | 2, 3, 4, 5, 7 (vols) ; 13 relais ; fin |
| C-05 Amaryllis | 5 Chutes Météore | 8 R119 (tempête) ; 10 Centre Spatial (surcharge) | 13 Pilier Céleste | 12 Sommet ; épilogue ; postgame |
| C-06 Giovanni | 3 Poivressel (homme au Persian) | 6 Chemin Ardent (corrige des sbires) | 10 Centre Spatial (désavoue Lambda) | 9 toit ; 12 témoignage ; P Zone (dernier duel) |
| C-07 Peter | 3 Poivressel (débarquement) | 5 Site Météore | 12 Sommet | 10 Défi ; 13 allié ; épilogue |
| C-08 Pierre Rochard | 2 Grotte Granite | 8 R120 (Méga-Bracelet, doute) | 12 Sommet (père) | 7 Devon (témoin) ; 10 duo ; 14 Maître ou démission |
| C-09 Chen | 3 Poivressel (rejoint Seko) | 7 Bourg-en-Vol (clash) | 9 Mont Mémoria ; 12 Sommet | épilogue ; postgame (duel) |
| C-10 Seko | 0 Bourg-en-Vol, labo | 4 Lavandia (ramène Pikachu) | 7 Bourg-en-Vol (dîner, publication) | 3 ; épilogue |
| C-11 Flora | 1 Bois Clémenti | 7 Vergazon | 13 Civils (désobéit ou non) | 7 Clémenti (vote) ; épilogue |
| C-12 Pierre (Brock) | 1 Mérouville (mines) | 7 Vergazon (protégés condamnés) | 12 Sommet (vote) | épilogue (élevage) |
| C-13 Ondine | 3 Poivressel | 9 Nénucrique, port | 11 Tréfonds (camp) | épilogue |
| C-14 Major Bob | 3 Poivressel | 4 Lavandia (coupe un quartier) | 7 Clémenti (vote) | 13 Civils (évacuation) |
| C-15 Erika | 4 Vergazon | 6 Vermilava (avec Adriane) | 7 Vergazon (contrat) | épilogue |
| C-16 Koga | 3 Poivressel | 8 Cimetronelle (piège) | 10 Algatia (double jeu) | épilogue (Conseil 4) |
| C-18 Morgane | 3 Poivressel | 8 R120 (vision) | 10 Algatia (avec Lévy et Tatia) | 13 veillée |
| C-19 Auguste | 6 Mont Chimnée | 6 Vermilava (sources vides) | 9 Mont Mémoria (rejoint Fuji ou non) | 12 Sommet ; épilogue |
| C-20 Olga | 3 Poivressel | 9 Nénucrique (coup de filet) | 12 Sommet | épilogue (Île 4) |
| C-21 Aldo | 2 Myokara | 9 Nénucrique, port (contre Ondine) | 11 Tréfonds ou Tournoi | épilogue |
| C-22 Agatha | 9 Mont Mémoria | 9 Mont Mémoria (accuse Chen) | 12 Sommet (l'article) | 13 Pilier ; épilogue (retraite) |
| C-23 Léo | 1 Devon 2F | 5 R114 (chez Lanette) | 7 Lavandia (aveu) | 10 Centre Spatial |
| C-24 Ciléo | 0 R104 plage | 3 Poivressel (entrepôt) | 10 Centre Spatial (voit la Fiole) | 12 Sommet (registre) |
| C-25 Fuji | 9 Mont Mémoria | 12 Sommet | 13 relais (brise ou non) | postgame (Mewtwo) |
| C-26 Président | 1 Devon 3F | 3 Poivressel (Kiosque) | 12 Sommet (confession ou chute) | 10 Centre Spatial |
| C-28 Ariane | 1 R116 (lettre) | 6 Vermilava (recrute) | 10 Centre Spatial (assaut) | 13 relais |
| C-29 Lambda | 1 Devon 2F (« Ferrand ») | 6 Planque Magma (horaire) ; 7 filature | 10 Centre Spatial (faux Giovanni) | 4 Lavandia (indice) |
| C-30 Lance (Rocket) | 1 R116 | 4 Tunnel Mérazon (raid) | 9 Mont Mémoria (profanation) | 12 interrogatoire ; 13 |
| C-32 Norman | 0 téléphone | 1 Clémenti (QG) | 7 Clémenti (vote, badge 5) | 12 Sommet ; 13 |
| C-33 Timmy | 4 Vergazon | 7 Vergazon (contre la brigade) | 13 Civils (son arrivant) | 14 Route Victoire ou postgame |
| C-34 M. Rochard | 1 Devon 3F | 7 Devon (son fils) | 12 Sommet | 10 (appel au relais) |
| C-35 Marc | 9 Nénucrique (Concours) | 12 Atalanopolis (Sages contre ami) | 14 (Maître si démission) | 13 Civils |
| C-36 Juan | 9 Nénucrique (jury) | 12 arène (badge 8) | 12 Sommet (prend parti) | épilogue |
| C-37 à C-46 | voir fiches §5 (crise de ville = P/É, badge = B, Sommet ou Ligue = E) | | | |
| C-47 Max | 5 R112 (relevés) | 6 Mont Chimnée (démonstration) | 12 Sommet | épilogue |
| C-48 Arthur | 6 Mont Chimnée (manifestation) | 9 Planque Aqua | 11 Tréfonds | épilogue |

### 1.4 Scènes de témoin (Red arrive pendant ; il ne fait que regarder, puis peut faire un geste)
| W | Paire | Carte, ch. | Ce qui se dit sans Red | Geste possible ensuite (décision ou non : brief C) |
|---|---|---|---|---|
| W1 | Peter / Amaryllis (arbitre Aragon) | Chutes Météore 1F, ch. 5 | clan contre clan ; elle l'accuse d'être « de la région du voleur » ; il la traite de fanatique | **désigner** Aragon (respect du Site) ou **partir** avec Peter |
| W2 | Pierre Rochard / M. Rochard | Devon 3F, ch. 7 | « Qu'y a-t-il dans le Cœur ? » — « Des emplois. » | **montrer** l'enregistrement de Léo (si obtenu) ou **rester** |
| W3 | Brice / Flora | Vergazon, ch. 7 | elle exécute l'ordre d'abattage ; il récite ses chiffres ; ils se blessent | aucun geste : Brice décide seul plus tard |
| W4 | Norman / Major Bob | Clémenti (QG), ch. 7 | vote d'abattage : deux soldats, deux gestions du chiffre | **montrer** une pièce du Dossier au vote |
| W5 | Max / Arthur | Mont Chimnée, ch. 6 | « Tu joues aux dieux. » — « Toi, tu les nourris. » | décision L ch. 6 (soutenir, saboter, dénoncer) |
| W6 | Blue / Giovanni | toit du Grand Magasin, Nénucrique, ch. 9 | Jadielle, l'héritage, la défaite contre un gamin | **rester** (Blue parle ensuite à Red) ou **partir** |
| W7 | Chen / Agatha | Mont Mémoria (sommet), ch. 9 | « Ton article, Chen. Il y a cinquante ans. » | **montrer** l'article annoté (si saisi) |
| W8 | Ondine / Aldo | port de Nénucrique, ch. 9 | elle a ouvert un filet ; il porte les caisses vides des pêcheurs | **désigner** l'un ou l'autre (déplace `REL_ONDINE_ARTHUR`) |
| W9 | Léo / Lanette | maison de Lanette, R114, ch. 5 | qui a signé la couche de transfert ; ses journaux horodatés | **rester** : Lanette donne les journaux |
| W10 | Koga / Peter | Algatia, ch. 10 | « Tu as payé la Rocket pour un nom. » — « J'ai payé pour Hoenn. » | **montrer** la page du carnet (`REL_KOGA_PETER`) |

### 1.5 Relations PNJ–PNJ déplaçables (≥ 5 exigées ; 9 fournies)
| M | Relation | Défaut | État atteignable | Ce qui la déplace (P/R/É) | Ce qui la lit (lecteurs) | Nom logique |
|---|---|---|---|---|---|---|
| M1 | Ondine ↔ Arthur | aucune | alliance (ch. 9 → ch. 11) | É : Red n'empêche pas la libération du banc (W8) ; R : Sarah | camp d'Ondine au ch. 11 (son équipe), vote ch. 12, épilogue Myokara | `REL_ONDINE_ARTHUR` |
| M2 | Chen ↔ Seko | rivalité | réconciliation | É : publication de Brice (ch. 7, crédit partagé) **et** Chen avoue (ch. 12) | dîner du ch. 7 (variante), épilogue Chen–Seko (bible §12.2), fin cachée | `REL_CHEN_SEKO` |
| M3 | Flora ↔ Norman | obéissance | Flora bascule | R `FL` ≥ seuil ; É : W3 ; R : Brice | ch. 13 (Civils), équipe de Flora (mixte), vote de Norman | `FL` + flag |
| M4 | Auguste ↔ Max (→ Fuji) | loyauté | Auguste rejoint Fuji | É : Hoopa blessé (ch. 6) vu par Red **et** Red n'a pas soutenu la démonstration ; R : Fuji | ch. 12 (Magma perd son géologue), ch. 13 (Fuji au relais), épilogue Cramois'Île | `REL_AUGUSTE_FUJI` |
| M5 | Koga ↔ Peter | méfiance | démasqué · couvert · ignoré | P : page du carnet (ch. 4) ; geste **montrer** à W10 | ch. 10, combat de Koga (variante), Conseil 4 de Kanto en épilogue | `REL_KOGA_PETER` |
| M6 | Pierre Rochard ↔ M. Rochard | loyauté filiale | accusation publique | P + R `PR` (voir 1.2) | ch. 12, F2, Maître au ch. 14 | `STANCE_PR` |
| M7 | Blue ↔ Giovanni (héritage de Jadielle) | rejet | Blue accepte Jadielle comme la sienne | É : W6 ; R `BL` | épilogue Blue (variante), départ postgame | `STANCE_BLUE` |
| M8 | Sarah ↔ Arthur | loyauté | doute public | P : données de l'Institut (ch. 8) montrées par Red | ch. 11 (négociation), sort du câble | `REL_SARAH_ARTHUR` |
| M9 | Amaryllis ↔ Aragon | respect inquiet | réconciliés · rompus | É : W1 ; R : Doyenne ; R `AM` | ch. 13 (qui tient le rite), épilogue Site Météore | `REL_AMARYLLIS_ARAGON` |

### 1.6 Identités de combat (A → B) — ce que l'équipe raconte
Les satellites et les niveaux sont du ressort du brief B. Ici : noyau canonique (◐ = de mémoire, à vérifier), **récit de l'équipe**, variantes de position.

| ID | Noyau canonique | Ce que l'équipe raconte | Variantes de position (sélecteur) |
|---|---|---|---|
| C-02 Brice | starter fort contre le vôtre ; Tropius, Bekipan [CANON E ◐] | un recenseur : il combat avec ce qu'il a compté | `BV` : PROTÉGER = natifs de Hoenn ; ACCUEILLIR = arrivants qu'il a protégés ; COMPRENDRE = espèces rares étudiées (Relicanth, Absol) |
| C-03 Blue | Roucarnage, Alakazam, Rhinoféros [CANON RFVF ◐] | **un champion qui achète** : satellites importés par le Kiosque de Scott, choisis pour la couverture | E-ADAPT (contre-type) ; `STANCE_BLUE` LIBRE au ch. 14 : il retire un import et remet un Pokémon de Bourg Palette |
| C-05 Amaryllis | Drattak (Méga après ch. 8), Altaria, Muplodocus [CANON ROSA] | des dragons du ciel ; elle ne capture pas, elle **accompagne** | `PA` haut au climax : une anomalie P2 (bible §9) |
| C-06 Giovanni | Rhinoféros, Nidoking, Nidoqueen, Persian [CANON RFVF] | un empire réduit à ce qu'il peut porter seul | ch. 6 incognito : 3 Pokémon ; postgame : 6, sans aucun arrivant (orgueil : « rien d'importé ») ; jamais Mewtwo |
| C-07 Peter | Dracolosse, Léviator, Ptéra [CANON RFVF] | l'autorité de Kanto, vieille et lourde | Drattak si `ch. 5 respect` ; E-ADAPT |
| C-08 Pierre Rochard | Métalosse (Méga), Airmure, Galeking [CANON RS/E ◐] | les pierres de Hoenn, les fossiles de Devon | ACCUSE : il retire le fossile ranimé par Devon (Armaldo ou Vacilys) au ch. 14 |
| C-11 Flora | — (pas de canon d'équipe propre) | une brigade : natifs disciplinés | bascule : moitié arrivants sauvés à Vergazon |
| C-12 Pierre (Brock) | Onix ou Steelix, Racaillou [CANON RFVF] | un éleveur de roche, défensif | + arrivants adoptés aux mines s'ils ont été sauvés (ch. 1) |
| C-13 Ondine | Staross, Stari [CANON RFVF] | offensive Eau | AQUA : arrivants marins libérés ; MISSION : Eau de Kanto |
| C-14 Major Bob | Raichu, Voltorbe [CANON RFVF] | un logisticien : paralysie, vitesse | exercice refusable ch. 4 |
| C-15 Erika | Rafflesia, Empiflor [CANON RFVF] | statut, parfum | MAR : la fleur arrivante sous contrat ; INT : plantes de Vergazon |
| C-16 Koga | Smogogo, Nostenfer ◐ | attrition, illusions | DÉMASQUÉ : il joue « propre » (sans piège) ; COUVERT : pièges complets |
| C-17 Jeannine | Nostenfer, Aéromite ◐ [CANON GSC] | la fille qui imite trop bien | — |
| C-18 Morgane | Alakazam, M. Mime [CANON RFVF] | elle **prévoit** : écrans, Pré-Science | — |
| C-19 Auguste | Arcanin, Galopa [CANON RFVF] | feu de laboratoire, chaleur contenue | rejoint Fuji : il retire le Pokémon prêté par Magma |
| C-20 Olga | Lokhlass, Lippoutou, Crustabri [CANON RFVF] | une île froide qui protège | avec ou sans ses Lokhlass (bible §B) |
| C-21 Aldo | Mackogneur, Onix [CANON RFVF] | le corps, l'honnêteté | — |
| C-22 Agatha | Ectoplasma, Arbok [CANON RFVF] | le deuil qui mord | rite profané : combat d'histoire ch. 9 |
| C-28 Ariane | Arbok, Rafflesia ◐ [CANON HGSS] | ce qu'on achète aux ruinés | `RK` haut : arrivants « rachetés » en satellites |
| C-29 Lambda | Smogogo ◐ [CANON HGSS] + Zoroark ou Métamorph (HYPOTHÈSE) | l'imposture lisible | — |
| C-30 Lance (Rocket) | Smogogo, Nosferalto ◐ [CANON HGSS] | les primes : il aligne ce qu'il chasse | — |
| C-32 Norman | Monaflèmit, Vigoroth [CANON RSE] | l'ordre qui tient un tour sur deux | — |
| C-33 Timmy | Tarsal → Kirlia [CANON RSE] | un enfant et son ami condamné | avec ou sans l'arrivant sauvé (bible §B) |
| C-35 Marc | Milobellus [CANON RSE] | la beauté qui dure | Maître (ch. 14) si Pierre Rochard démissionne |
| C-46 Aragon | Drattak, Altaria, Libégon [CANON RSE ◐] | le vieux marin des dragons | — |
| C-47 Max | Camérupt (Méga), Grahyèna [CANON ROSA] | la gestion par la force tellurique | — |
| C-48 Arthur | Sharpedo (Méga), Grahyèna [CANON ROSA] | la mer libre et vorace | COUPE : arrivants marins libérés ; NÉGOCIE : natifs |
| Champions et Conseil 4 de Hoenn | noyaux `CAST_DOSSIER` §2.11–2.12 | chacun aligne la réponse de sa ville à la crise (fiches §5) | — |

**Règle pour le brief B (HYPOTHÈSE de sens) :** quatre personnages refusent tout arrivant par principe (Giovanni, Norman, Flora non basculée, Aldo) ; quatre en alignent par conviction (Ondine côté Aqua, Glacia, Timmy, Bastien) ; deux en **achètent** (Blue, Ariane). Le joueur lit la position dans l'équipe avant de l'entendre.

### 1.7 Pièces du Dossier et objets demandés par la distribution (A → C)
Le brief C les intègre ou les fusionne. Chacune a un plant et une récolte (§10).
| Pièce (nom logique) | Où et comment | Qui la reconnaît | Sert à |
|---|---|---|---|
| `DOS_AFFICHE_SYLPHE` | Mérouville, ch. 1 : affiche Passerelle (« Il a sauvé Sylphe. Sylphe relie le monde. ») avec Red de dos | Brice (ch. 1), Président (ch. 12) | R4 : la part de Red |
| `DOS_CARNET_PRIMES` | Tunnel Mérazon, ch. 4 (raid) ; une page porte un paiement à « K. » | Peter, Koga (W10) | R1 ; M5 (Koga) |
| `DOS_BATTEMENT` | Lavandia, ch. 7 : enregistrement remis par Léo | Pierre Rochard, Lévy et Tatia | R2 ; M6 |
| `DOS_ARTICLE_CHEN` | Mont Mémoria, ch. 9 : photocopie annotée, perdue par Lance (Rocket) | Agatha, Chen | R4 ; `STANCE_CHEN` ; fin cachée |
| `DOS_REGISTRE_COFFRE` | Centre Spatial, ch. 10 : Ciléo le copie dans le cœur du relais | Président, Pierre Rochard, Juan | R4 (source 1) |
| `DOS_DONNEES_INSTITUT` | Institut Météo, ch. 8 : relevés de tempête de Sarah | Sarah, Arthur, Morgane | Q4 ; M8 ; H3 |
| `OBJ_LETTRE_FERRAND` | Nénucrique, ch. 9 : le vrai ingénieur Ferrand, séquestré dans l'entrepôt du marché (coup de filet d'Olga) | Lanette, Léo | démasquer Lambda **avant** le ch. 10 (facultatif ; change la scène du faux Giovanni) |

---

## 2. Toile relationnelle

Codes : **F** famille · **R** rival · **M** mentor/élève · **A** allié · **E** ennemi · **C** connaissance. `[c]` = canon de jeu ; sans marque = HYPOTHÈSE du hack. Chaque majeur a au moins un **A** et un **R/E** avec un PNJ (invariant 13) : vérifié ligne par ligne.

### 2.1 Matrice du noyau (lecture ligne → colonne)
| | Brice | Blue | Amar. | Giov. | Peter | P. Roch. | Chen | Seko | Flora | Norman |
|---|---|---|---|---|---|---|---|---|---|---|
| **Brice** | — | R (agacement→respect) | C | — | C | A | M (admire) | F, R (positions) | A, R (positions) | C |
| **Blue** | R | — | — | R (héritage) [c : Jadielle] | R (honte) | C | F [c], R (reconnaissance) | — | C | — |
| **Amaryllis** | C | — | — | E (Rocket : vengeance) | R (clans) | R (respect) | — | — | — | E (Rempart) |
| **Giovanni** | — | C (successeur) | — | — | E [c GSC] | C | E (l'article l'a guidé) | — | — | — |
| **Peter** | C | R (honte, attente) | R | E [c] | — | A | A (Kanto) | C | C | R (rapatrier ≠ abattre) |
| **P. Rochard** | A | C | R | C | A | — | C | C | — | A (Ligue) |
| **Chen** | M | F [c] | — | E | A | C | — | R | — | R |
| **Seko** | F | — | — | — | C | C | R | — | C | A (voisin [c]) |
| **Flora** | A, R | C | — | — | C | — | — | C | — | F, M |
| **Norman** | C | — | E | — | R | A | R | A | F | — |

### 2.2 Liste d'adjacence (tous les majeurs)
- **Red** : Brice (A) ; Ciléo (A [c RFVF]) ; Blue (R [c]) ; Giovanni (E [c]) ; Chen (M [c]) ; Fuji, Président (C [c] : sauvés) ; Peter, Olga, Aldo, Agatha (C [c] : vaincus) ; M. Marco (A : passeur).
- **Hoopa** : Fuji (A, tardif) ; Aqua (A, idéologique) ; Koga (E : piège) ; Rocket, Consortium (E) ; Lévy et Tatia (C : ils « l'entendent »).
- **Pierre (Brock)** : Roxanne (A, collègues Roche) ; Timmy (A, ch. 7) ; mineurs de Mérouville (R) ; Major Bob (R : déplacer ≠ contenir).
- **Ondine** : Marc (A, admiration) ; Arthur (A temporaire, M1) ; Aldo (R) ; Major Bob (R).
- **Major Bob** : Voltère (A : vieux bâtisseurs) ; Norman (A) ; Flora (M, elle l'admire) ; Ondine, Erika (R).
- **Erika** : Adriane (A) ; Timmy (A) ; Major Bob (R) ; Président de Sylphe (R : négociation du contrat) ; Flora (R : abattage des vergers).
- **Koga** : Jeannine (F [c]) ; Lance (Rocket) (A secret, informations) ; Peter (R : méfiance) ; Hoopa (E).
- **Jeannine** : Koga (F, R : elle veut le dépasser) ; Alizée (A : canopée).
- **Morgane** : Lévy et Tatia (A) ; Capucine (A) ; Amaryllis (R : deux prophéties) .
- **Auguste** : Max (A, volcanologie) ; Fuji (A [c ◐ : Manoir]) ; Adriane (R : sources vidées) .
- **Olga** : Glacia (A) ; Damien (A : indic) ; Lance et Ariane (E : braconnage [c RFVF ◐]) ; marchands de Nénucrique (R).
- **Aldo** : Bastien (M) ; pêcheurs de Myokara (A) ; Ondine (R).
- **Agatha** : Spectra (M) ; Fuji (A : Lavanville) ; Chen (R [c]) ; Lance (Rocket) (E : profanation).
- **Léo** : Ciléo (A [c]) ; Lanette (R technique, puis A) ; Président de Sylphe (R : il dénonce).
- **Ciléo** : Red (A) ; Léo (A [c]) ; Lanette (R : nœud contre stockage) ; Président (R : exclu du relais).
- **Fuji** : Auguste, Agatha (A) ; Président de Sylphe (R : le coffre) ; Ariane (E : la Rocket l'a séquestré [c RFVF]).
- **Président de Sylphe** : M. Rochard (A et R) ; Giovanni (E [c]) ; Fuji (R) ; Ciléo, Léo (R).
- **Nina** : Blue (F [c]) ; Marc (A : Concours) ; Chen (F [c]) .
- **Ariane** : Lance (Rocket) (A) ; Amos (R : méthode) ; Giovanni (loyauté non payée de retour) ; Olga (E).
- **Lambda** : Ariane (A) ; Max (A d'affaires : il lui vend l'horaire) ; Giovanni (E après ch. 10) ; Lanette (E : elle a connu le vrai Ferrand).
- **Lance (Rocket)** : Ariane (A) ; Koga (A d'intérêt) ; Peter (E) ; Agatha, Spectra (E) ; Amaryllis (E : la nuit du vol).
- **Amos** : Giovanni (loyauté) ; Ariane (R).
- **Norman** : Major Bob, Seko (A) ; Chen, Peter (R) ; Erika (R : ruines des vergers) ; Flora (F) ; Timmy (M [c]).
- **Timmy** : Erika, Pierre (Brock) (A) ; Flora (R) ; Norman (M [c]) .
- **M. Rochard** : Président de Sylphe (A et R) ; Capitaine Marin (A [c ◐]) ; Pierre Rochard (F [c], R) ; Giovanni (R : rachats d'actions).
- **Marc** : Juan (M [c]) ; Pierre Rochard (A [c]) ; Nina, Ondine (A) ; Sages et Doyenne (R : tradition contre ouverture).
- **Juan** : Marc (M [c]) ; Sages (A) ; Max et Arthur (R : il les a vus grandir et se haïr).
- **Roxanne** : Pierre (Brock) (A) ; Brice (A : données) ; mineurs (R).
- **Bastien** : Aldo (M) ; Ondine (A) ; pêcheurs (R).
- **Voltère** : Major Bob (A) ; Aqua (R : sabotages) ; habitants du quartier coupé (R).
- **Adriane** : Erika (A) ; Max et Auguste (R).
- **Alizée** : Koga, Jeannine (A) ; Amaryllis (R : le ciel) .
- **Lévy et Tatia** : Morgane (A) ; Consortium (R : ils entendent la voix).
- **Damien** : Olga (A) ; Rocket (R : territoire) ; Rempart (R : primes).
- **Spectra** : Agatha (M) ; Lance (Rocket) (E).
- **Glacia** : Olga (A) ; Rempart (R : elle est arrivante elle-même).
- **Aragon** : Doyenne (A) ; Amaryllis (A inquiet, M9) ; Peter (R).
- **Max** : Auguste, Kelvin (A) ; Arthur (R [c]) ; Pierre Rochard (R [c]) ; Kosmo (E [c] : la Météorite).
- **Arthur** : Sarah, Matthieu (A [c]) ; Ondine (A temporaire) ; Max (R [c]) ; Norman (E : Rempart).

---

## 3. Rang A (noyau)

### C-01 Red — Red / Red · rang A · `CANON RFVF` (passé), `HYPOTHÈSE` (année 1)
- **Fonction.** Joueur, témoin et acteur par 5 gestes (bible §4.4). Il ne commente pas : il choisit où il est, ce qu'il montre, à qui il donne.
- **Veut → besoin.** Retrouver son équipe, réparer → accepter qu'on ne répare pas seul. **Faiblesse :** il croit que gagner suffit ; à Kanto, cela a suffi.
- **Pourquoi muet (HYPOTHÈSE).** Après le Panthéon, la Ligue Indigo et Sylphe ont parlé **à sa place** : interviews jamais données, slogans, et une affiche Passerelle où on le voit de dos (`DOS_AFFICHE_SYLPHE`). Depuis, il se tait : « quand il parle, on le cite ». Ironie voulue : à Hoenn, Brice parle pour lui (thème « parler pour quelqu'un »).
- **Pourquoi à Hoenn.** Ciléo lui demande de l'accompagner : il a aidé à brancher le Rubis et le Saphir [c RFVF], le nœud Kanto est accusé, et les ports sont fermés. M. Marco les passe de nuit (il cherche Piko).
- **Agenda.** M : récupérer son équipe (égoïste et légitime) ; savoir si ses victoires ont causé ceci.
- **Carnet (voix intime, débloqué par les relations).** Phrases sans sujet, présent, une image. Exemples :
  - “Pikachu a sauté. Pas moi.”
  - “Brice a dit ‘nous’. / Je n’ai pas corrigé.”
  - “Sylphe. Mon visage. Leur Cœur.”
- **La phrase écrite publique (une seule ; choix de la scène : brief C).** Trois candidates selon l'état :
  - Dossier complet au Sommet : “J’ai gagné à Kanto. / C’est Hoenn qui a payé.”
  - Hoopa confié, `HO` haut : “Rendez-lui ce qu’on lui a pris.”
  - Épilogue, toutes fins : “Je pars apprendre à perdre.” (annonce le Mont Argenté)
- **Pulsations.** P ch. 0 plage R104 (3 combats à pleine force, puis l'anneau prend l'équipe) ; É ch. 7 Bourg-en-Vol (R2 : sa part du réseau) ; B ch. 12 Sommet (la chaîne, R4) ; E départ vers le nord (épilogue).
- **Sémiotique.** Effet : aucun texte, 5 verbes. Fiction : un champion qui refuse d'être cité. Appris : « mes actes parlent ; les autres traduisent ». Thème : parler pour quelqu'un a un prix, même par amitié.
- **Contrainte canon.** Année 3 : Mont Argenté [c GSC/HGSS]. Pas de mort, pas de défaite humiliante permanente. Il ne devient jamais Maître de Hoenn.
- **Asset.** `TRAINER_PIC_RED`, avatar `RED_*` ✔ (`ENGINE_CHANGES` §B).

### C-02 Brice — Brice / Brendan · rang A · `CANON RSE` (fils de Seko, rival), `HYPOTHÈSE` (recenseur)
- **Fonction.** Second protagoniste, voix de Red, recenseur des arrivants.
- **Veut → besoin.** Être utile à son père → avoir son propre avis. **Faiblesse :** il remplit les silences ; il suit celui qui parle le plus fort, et Red ne parle pas.
- **Agenda.** A (le recensement comme bien commun), avec un fond égoïste : être cité avant Chen.
- **Test du figurant.** Sans Red, demain, il continue sa ronde nocturne de la R101, remet ses chiffres à son père, qui les transmet au Rempart. Il découvrirait seul, plus tard, que ses comptes servent aux listes d'abattage.
- **Positions.** Émergent de `BV` (§1.2). Son vote ch. 12 suit `BV`, même contre Red et même avec `BR` à 90 : la loyauté n'est pas l'accord (N10).
- **Alliances / rivalités PNJ.** Chen (admiration ; Chen lui demande ses données avant publication : tentation) ; Flora (amitié tendue, positions opposées) ; Seko (père, puis rival de méthode) ; Roxanne (données) ; Timmy (protecteur).
- **Pulsations (≥ 6 scènes).**
  | Ch. | Carte | Déclencheur | Ce qu'on voit | Action du joueur |
  |---|---|---|---|---|
  | 0 | R101 nuit | Red sort de chez Seko | Brice compte les arrivants, il est encerclé | combattre (starter de Seko) |
  | 0 | R103 | après le starter | premier duel ; il parle pour deux | combat |
  | 1 | Mérouville | affiche Passerelle | il reconnaît Red de dos et se tait (pour une fois) | **rester** ou **partir** |
  | 4 | R110 | carte des anneaux | il montre la carte ; il veut le raid avec Red | combat ; venir au raid ou non (`BV`) |
  | 5 | Chutes Météore | relevés de Kosmo | ses données contredisent son père : les arrivants suivent les contrats | **montrer** les journaux de Lanette |
  | 7 | Bourg-en-Vol | R2 | il décide **seul** de publier ; Red réagit par un geste | geste (décision L, brief C) |
  | 8 | R119 | après l'Institut | troisième combat ; il donne Vol | combat |
  | 12 | Atalanopolis | Sommet | il vote **à lui** | voir ; combat refusable |
- **Scène qui définit (12 boîtes, ch. 7, Bourg-en-Vol, chambre de Brice).** Brice étale la carte sur le lit ; Red pose les journaux de Lanette dessus ; les points coïncident. Brice parle de son père, de Chen, des listes d'abattage. Il se tait trois boîtes (« … »). Il prend le stylo : il publiera ou non, selon **ce qu'il a vu** (`BV`). Red n'a qu'une réaction : approuver, tourner le dos, ou lui donner sa casquette (geste du don).
- **Voix.** Traits : bavard, précis, honnête. Tics : il corrige ses chiffres ; « enfin, je veux dire » ; il dit « nous » pour Red. Interdits : jamais cynique ; jamais de mensonge sur un chiffre. Exemples :
  - “Douze arrivants sur la R101. / Enfin, treize. Il y a un œuf.”
  - “Tu ne dis rien, hein ? / Bon. Je parle pour deux.”
  - “Papa dit que compter, c’est / protéger. Je n’en suis plus sûr.”
- **Saillance.**
  | État | Réplique |
  |---|---|
  | ch. 12, `BV` PROTÉGER | “Les natifs d’abord. Désolé, Red. / Je l’ai vu de mes yeux.” |
  | ch. 12, `BV` ACCUEILLIR | “Ils n’ont pas demandé à venir. / On ne les renvoie pas comme ça.” |
  | ch. 12, `BV` COMPRENDRE | “On ne tranche pas sans les / chiffres. Même toi, Red.” |
  | `BR` ≥ 70 | “Tu as hoché la tête, là ? / Je le note. Comme un vote.” |
  | `BR` ≤ 30 | “Je vais recenser seul, cette fois. / Tu n’as pas besoin de moi.” |
- **Équipe.** §1.6.
- **Échos.** F1 : il signe le recensement final, natifs en tête. F2 : il compte ceux qui reviennent, avec M. Marco. F3 : il devient le premier contrôleur de la charte. F4 : il compte ce qui a été abattu, et le publie. F5 : il cartographie les anneaux sauvages, seul sur la R101.
- **Contrainte canon.** Aucune après RSE (rôle remplacé). Il reste fils de Seko.
- **Asset.** `TRAINER_PIC_BRENDAN` ; OW `RIVAL_BRENDAN_*` ✔.

### C-03 Blue — Blue / Blue · rang A · `CANON RFVF/GSC`
- **Fonction.** Rival miroir ; comédie et blessure.
- **Veut → besoin.** Battre Red → valoir sans être premier ; aimer ses Pokémon (le reproche de Chen au Panthéon [c RFVF]). **Faiblesse :** il achète ce qu'il n'arrive pas à gagner.
- **Pourquoi à Hoenn (HYPOTHÈSE).** Après ses trois minutes de Maître, la Ligue Indigo lui offre l'arène vide de Jadielle. Il refuse « l'arène d'un fuyard » (Giovanni). Scott lui offre la vedette du Tournoi des Confluences et des imports par Passerelle. Il est arrivé **avant** la fermeture des ports.
- **Agenda.** É. **Test du figurant :** sans Red, il gagne le Tournoi de Scott, signe un contrat de vedette, et ne rentre jamais à Jadielle (contre le canon : il faut donc la scène du toit).
- **Positions.** MAR (Scott) → LIBRE ; moteur : W6 + `BL`.
- **Alliances / rivalités PNJ.** Scott (tentation), Nina (sœur qui veille) · Peter (honte ; Peter le voulait dans la Mission), Chen (reconnaissance), Giovanni (héritage).
- **Pulsations.**
  | Ch. | Carte | Déclencheur | Ce qu'on voit | Action |
  |---|---|---|---|---|
  | 3 | Poivressel, Tente | entrée de la Tente | Blue en vedette ; Scott sourit | combat refusable (Blue 1) |
  | 3 | quai | débarquement | il évite Peter et Chen | — |
  | 9 | Nénucrique, toit | après la planque | W6 : Giovanni lui parle de Jadielle | combat refusable ; **rester** |
  | 13 | veillée | `BL` | il dit ce qu'il tient (les quais) ou il n'est pas là | affectation |
  | 14 | Route Victoire | obligatoire | combat final, contre-équipe | combat |
  | P | Bourg-en-Vol, port | postgame | départ pour Jadielle | **donner** (optionnel) |
- **Scène qui définit (10 boîtes, ch. 9, toit).** Red arrive sur W6. Giovanni : « Une arène est une porte. Vous la gardez ou vous la vendez. » Blue rit trop fort. Giovanni part. Blue avoue à Red qu'il a acheté deux de ses Pokémon au Kiosque et qu'il ne connaît pas leur nom. Il propose un combat « pour voir si ça compte ».
- **Voix.** Traits : fanfaron, rapide, blessé. Tics : « le Muet » ; il compte ses victoires ; il finit sur une pique. Interdits : jamais cruel envers un Pokémon à l'écran ; jamais « merci » avant le ch. 13. Exemples :
  - “Toujours muet ? Parfait. / Comme ça, tu ne me coupes pas.”
  - “Scott paie bien. Et ici, on / m’applaudit avant le combat.”
  - “Trois minutes de Maître, Red. / Je les compte encore.”
- **Saillance.**
  | État | Réplique |
  |---|---|
  | veillée, `BL` haut | “Je tiens les quais. Pas pour toi. / Pour eux. Bon… un peu pour toi.” |
  | Blue 1 refusé | “Tu refuses ? Tu as peur, ou / tu me trouves trop petit ?” |
  | battu (tout combat) | “J’ai étudié ton équipe. / La prochaine fois, je l’ai.” |
  | `STANCE_BLUE` LIBRE | “Ce Ptiravi, je l’ai attrapé hier. / Moi-même. C’est bête, hein ?” |
- **Échos.** F1 : il rentre à Jadielle par le dernier bateau. F2 : un anneau dépose une lettre de Nina ; il part le lendemain. F3 : il garde une licence Passerelle et la brûle sur le quai. F4 : il part en disgrâce avec la Mission, tête haute. F5 : il part sans prévenir, comme Red autrefois.
- **Contrainte canon.** Champion de Jadielle en année 3, souvent absent [c GSC]. Pas de Méga hors politique du brief B.
- **Asset.** `TRAINER_PIC_RIVAL_LATE_FRLG` / `CHAMPION_RIVAL_FRLG` ; OW `BLUE` ✔.

### C-04 Hoopa Confiné — « le petit voleur » · rang A muet · `CANON ROSA/XY` (espèce, Fiole, avarice, anneaux) ; `HYPOTHÈSE` (rôle)
- **Fonction.** Cœur mythique : victime et cause.
- **Veut → besoin.** Retrouver son pouvoir → un échange juste. **Faiblesse :** il prend avant de demander.
- **Test du figurant.** Sans Red, il continue de voler pour manger en remontant vers Algatia, attiré par son pouvoir dans le relais ; Koga ou la Rocket le capturent au ch. 8.
- **Vocabulaire de comportement (texte : aucun).**
  | Geste de Hoopa | Sens appris |
  |---|---|
  | petit anneau qui prend un objet visible | « il a faim, pas d'intention » |
  | il rend l'objet, plus une baie | « il a reconnu un geste » (`HO` monte) |
  | il fuit toujours vers l'est | « quelque chose l'attire » (indice R2b, R4) |
  | il se cache derrière Brice | « il a choisi quelqu'un » (`HO` ≥ 60) |
  | il regarde le ciel et tremble | Rayquaza approche (ch. 8+) |
- **Pulsations (7 rencontres + révélation).** ch. 1 Mérouville (carnet de Brice) ; ch. 2 Myokara (poisson) ; ch. 3 Poivressel (objet du Kiosque) ; ch. 4 Vergazon (baies) ; ch. 5 R113 (lunettes de Kosmo) ; ch. 6 Mont Chimnée (**blessé** par l'anneau de Magma) ; ch. 7 R116 (il rend le carnet si `HO` ≥ 40) ; ch. 8 Cimetronelle (piège de Koga, révélation) ; ch. 13 relais.
- **Scène qui définit (9 boîtes, ch. 6).** L'anneau de Magma s'ouvre ; le petit voleur est aspiré à moitié ; il retient un Chamallot natif par la patte ; Red peut **donner** une Potion ou **rester**. Personne ne voit sauf Red (et Brice s'il est là).
- **Saillance (comportements).** `HO` ≤ 20 : il n'apparaît plus qu'à distance. `HO` 40–59 : il rend la moitié. `HO` ≥ 60 : il dépose un objet aux pieds de Red. `HO` ≥ 80 au relais : il tend son anneau à Red (Pacte possible).
- **Échos.** F1 : seul au sommet du Pilier. F2 : il rend Piko à M. Marco. F3 : au fond du relais, il dort, rationné. F4 : on ne le revoit pas ; un anneau minuscule reste dans le Carnet. F5 : il s'enfuit ; on le voit voler des pommes à Bourg-en-Vol.
- **Contrainte.** Aucun combat dans l'histoire ; obtenable au postgame dans toutes les fins (brief D). Le mot « Hoopa » est interdit avant R2b.
- **Asset.** `OBJ_EVENT_GFX_SPECIES(HOOPA)` (bible §14).

### C-05 Amaryllis — Amaryllis / Zinnia · rang A · `CANON ROSA` (gardienne du Peuple du Météore, Aster, équipe) ; `HYPOTHÈSE` (année 1)
- **Fonction.** Antagoniste croyante : raison sur le diagnostic, tort sur le traitement (le traitement fait payer Algatia).
- **Veut → besoin.** Faire descendre Rayquaza, venger la gardienne → admettre que la colère d'un dieu n'est pas une justice. **Faiblesse :** elle sait avant tout le monde, et personne ne l'a crue ; elle a cessé de convaincre.
- **Histoire (HYPOTHÈSE).** An −2, la gardienne (son amie, propriétaire d'Aster) poursuit les voleurs de la Fiole jusqu'à la mer et disparaît dans la tempête. Amaryllis hérite d'Aster et du rôle. Elle sent la Fiole « tirer » le ciel depuis Algatia. Depuis six semaines, elle **surcharge** le réseau par prête-noms (bible §3.1).
- **Agenda.** M. **Test du figurant :** sans Red, elle continue d'acheter des transferts par prête-noms jusqu'à ce que Rayquaza descende. Algatia paie.
- **Positions.** — / CIE ; issue PERSISTE · RENONCE · SACRIFICE (§1.2). Le sacrifice n'est **pas** une mort : elle retient Rayquaza par le rite et son Drattak ; Drattak suit le dragon dans le ciel et ne revient pas.
- **Alliances / rivalités PNJ.** Aster, Aragon (respect), quelques fidèles · Doyenne (patience contre jugement), Peter (clans), Lance (Rocket) (vengeance), Pierre Rochard (il veut la raisonner), Morgane (prophétie rivale).
- **Pulsations.**
  | Ch. | Carte | Déclencheur | Ce qu'on voit | Action |
  |---|---|---|---|---|
  | 5 | Chutes Météore 1F | arrivée | W1 : contre Peter, Aragon arbitre | combat d'histoire (ou duo avec Peter) |
  | 5 | Autéquia | maison de Kosmo | elle appelle les éclairs « des étoiles » | — |
  | 8 | R119 | après l'Institut | elle danse sous la tempête, Aster crie | **rester** (`AM`) |
  | 10 | Centre Spatial | après l'assaut | on la surprend à acheter des transferts | combat d'histoire |
  | 12 | Sommet | R4 | elle entre sans être invitée | — |
  | 13 | Pilier Céleste | climax | elle accueille Rayquaza | combat ; issue |
- **Scène qui définit (11 boîtes, ch. 8, R119, pluie).** Elle tourne sous la tempête. « Tu entends ? Il compte. » Elle montre à Red l'anneau qui s'ouvre au-dessus de la forêt : un Pokémon de Paldea tombe, un Tropius disparaît. « Ils appellent ça un réseau. » Elle offre à Red de la rejoindre, sans attendre de réponse, et s'en va en sifflant.
- **Voix.** Traits : insolente, joueuse, tragique. Tics : tutoie tout le monde ; « champion » ironique ; parle du ciel comme d'une personne. Interdits : jamais de plan expliqué en entier ; jamais de pitié pour elle-même à voix haute. Exemples :
  - “Tu as vu les étoiles, champion ? / Ce ne sont pas des étoiles.”
  - “Le ciel a une mémoire. / Il va s’en servir.”
  - “Je ne prie pas Rayquaza. / Je lui montre la plaie.”
- **Saillance.**
  | État | Réplique |
  |---|---|
  | ch. 13, RENONCE | “Aster tremble. Elle n’a jamais / tremblé. … Bon. J’arrête.” |
  | ch. 13, PERSISTE | “Tu veux que j’aie tort ? Alors / ferme la plaie avant lui.” |
  | aveu de Lance entendu | “Elle les a suivis jusqu’à la mer. / Et moi, je l’ai suivie trop tard.” |
  | défaut, ch. 10 | “Une créature dans une boîte. / Et vous appelez ça du réseau.” |
- **Échos.** F1 : elle garde le Pilier avec la Doyenne. F2 : elle rit, pour la première fois, devant Hoopa. F3 : elle surveille le relais, prête à recommencer. F4 : son arc s'accomplit ; elle pleure dans les ruines. F5 : elle suit les anneaux sauvages pour les compter, comme Brice.
- **Contrainte canon.** ROSA est hors chronologie (bible §3) ; elle reste vivante et libre.
- **Asset.** Aucun pic ni OW : `DRAGON_TAMER` repalettisé ; OW `HEX_MANIAC` (bible §14).

### C-06 Giovanni — Giovanni / Giovanni · rang A · `CANON RFVF/HGSS`
- **Fonction.** Ombre, clé du noyau. Il a ordonné le vol (An −2), caché la Fiole chez Sylphe (An 0).
- **Veut → besoin.** Mériter son retour seul → (il ne change pas : il renonce, canon HGSS).
- **Pourquoi à Hoenn (HYPOTHÈSE).** Exil anonyme ; il « s'entraîne » [c HGSS : « je vais m'entraîner »]. Il rachète en secret des actions de Devon, au plus bas depuis la fermeture des ports : s'il revient, ce sera avec de l'argent, pas avec un dieu.
- **Agenda.** É (orgueil). **Test du figurant :** sans Red, il achète 9 % de Devon et regarde ses anciens commandants échouer.
- **Positions.** MAR / refuse VOL : « un dieu volé est une dette ». Il désavoue Lambda (ch. 10) ; il témoigne au Sommet si `GI` le permet.
- **Alliances / rivalités PNJ.** Persian ; Amos (loyauté qu'il respecte) · Ariane et Lambda (mépris), Président de Sylphe (vieil ennemi), M. Rochard (rival d'affaires), Peter (ennemi [c GSC]).
- **Pulsations.**
  | Ch. | Carte | Déclencheur | Ce qu'on voit | Action |
  |---|---|---|---|---|
  | 3 | Poivressel, marché | Kiosque | l'homme au Persian lit les cours | **rester** : il vous vouvoie |
  | 6 | Chemin Ardent | sbires Rocket | il les corrige sans se nommer | combat incognito refusable |
  | 9 | Nénucrique, toit | W6 | il parle à Blue de Jadielle | — |
  | 10 | Centre Spatial | faux Giovanni | il entre et désavoue Lambda | — |
  | 12 | Sommet | R4 (si `GI`) | il témoigne : « j'ai ordonné ce vol » | **désigner** |
  | P | Zone de Combat | postgame | dernier duel, puis départ « s'entraîner » | combat |
- **Scène qui définit (9 boîtes, ch. 10).** Lambda, déguisé, harangue les sbires. La porte s'ouvre. Persian entre le premier. Giovanni regarde son double, longtemps. « Ôtez ce visage. » Les sbires reculent. Il ne combat pas : il sort, et c'est pire.
- **Voix.** Traits : froid, précis, patient. Tics : vouvoie ; parle de prix et de mérite ; dit « mes anciens employés », jamais « la Rocket ». Interdits : ne hausse jamais le ton ; ne supplie jamais. Exemples :
  - “Vous m’avez battu, jeune homme. / Je ne l’oublie pas. C’est utile.”
  - “Un dieu volé n’est pas une victoire. / C’est une dette.”
  - “Je n’achète pas Hoenn. / J’achète du temps.”
- **Saillance.**
  | État | Réplique |
  |---|---|
  | après le ch. 10 | “Cet homme porte mon visage. / Il n’a jamais su porter mon nom.” |
  | Sommet, `GI` haut | “Oui, j’ai ordonné ce vol. / Je n’ordonne plus. Voilà tout.” |
  | Sommet, `GI` bas | “Témoigner pour vous ? Non. / Gagnez votre propre vérité.” |
  | combat du ch. 6 refusé | “Vous refusez. Sage, ou lâche. / Je trancherai plus tard.” |
- **Échos.** Toutes fins : il repart seul. F3 : il vend ses actions Devon avec profit (il gagne de l'argent, pas son retour). `RK` haut : il intervient lui-même contre ses commandants (bible §12.2).
- **Contrainte canon.** Il reste caché, n'obtient rien, ne revient pas avant l'année 3 [c HGSS] ; jamais Mewtwo.
- **Asset.** `TRAINER_PIC_LEADER_GIOVANNI_FRLG` ; OW `GIOVANNI` ✔.

### C-07 Peter — Peter / Lance · rang A · `CANON RFVF/GSC`
- **Fonction.** Chef de la Mission Indigo ; Maître par intérim depuis le départ de Red (HYPOTHÈSE cohérente avec GSC).
- **Veut → besoin.** Laver Kanto, abattre la Rocket → écouter les gens du lieu. **Faiblesse :** il confond l'honneur de Kanto et la vérité.
- **Pourquoi à Hoenn.** Kanto est accusé ; les ports de Kanto sont fermés ; la Ligue Indigo l'envoie négocier le rapatriement des Pokémon de Kanto et la réouverture des ports. Motif privé : il traque la Rocket [c GSC].
- **Agenda.** M. **Test du figurant :** sans Red, il obtient la réouverture des ports en livrant un coupable kantonais commode (un contrebandier), et il repart.
- **Positions.** RAP / SCE ; ch. 12 : KANTO ASSUME · SE DÉFEND (§1.2).
- **Alliances / rivalités PNJ.** Pierre Rochard, Major Bob, Olga · Amaryllis et Aragon (clans), Koga (méfiance), Blue (attente déçue), Norman (« on rapatrie, on n'abat pas »).
- **Pulsations.**
  | Ch. | Carte | Déclencheur | Ce qu'on voit | Action |
  |---|---|---|---|---|
  | 3 | Poivressel, quai | débarquement | la Mission entre sous les huées | — |
  | 5 | Chutes Météore | W1 | il veut fouiller les chutes | **désigner** Aragon ou **partir** avec lui (décision) |
  | 7 | Clémenti | vote d'abattage | il proteste contre l'abattage des espèces de Kanto | — |
  | 10 | Algatia | W10 | Koga démasqué ou non | Défi Indigo |
  | 12 | Sommet | R4 | Kanto assume ou se défend | — |
  | 13 | lieu affecté | climax | allié | affectation |
- **Scène qui définit (10 boîtes, ch. 3, quai).** Les pêcheurs crient « Kanto dehors ! ». Peter s'arrête, lit le chiffre des natifs disparus sur une ardoise, et répond par un discours sur l'honneur de Kanto. Personne n'applaudit. Il demande à Red, à voix basse : « Qu'aurait dit un Maître ? » Red se tait.
- **Voix.** Traits : noble, protocolaire, droit. Tics : vouvoie ; « au nom de la Ligue Indigo » ; tout argument passe par Kanto. Interdits : jamais d'insulte aux gens de Hoenn ; jamais de rire. Exemples :
  - “Au nom de la Ligue Indigo, / nous venons reprendre les nôtres.”
  - “Les Pokémon de Kanto rentrent. / On ne les abat pas comme des rats.”
  - “Vous avez quitté le titre, Red. / Moi, je l’ai ramassé.”
- **Saillance.**
  | État | Réplique |
  |---|---|
  | KANTO ASSUME | “Kanto a volé, caché, publié. / Kanto paiera sa part.” |
  | SE DÉFEND | “Un savant, un bandit, un marchand. / Ce n’est pas Kanto.” |
  | ch. 5 respecté | “Votre doyenne m’a appris / à me taire. Ce n’est pas rien.” |
  | ch. 5 piétiné | “Ces gens gardent des cailloux. / Nous gardons des vies.” |
- **Échos.** F1 : il rentre avec les ports rouverts. F2 : il rentre avec les Pokémon de Kanto rendus par les anneaux. F3 : il signe la charte au nom de Kanto. F4 : il repart en disgrâce (bible §12.3). F5 : il laisse deux dragons à Hoenn pour surveiller les anneaux.
- **Contrainte canon.** Maître en année 3 [c GSC]. Cousin de Sandra [c].
- **Asset.** `TRAINER_PIC_ELITE_FOUR_LANCE_FRLG` ; OW `LANCE` ✔.

### C-08 Pierre Rochard — Pierre Rochard / Steven · rang A · `CANON RS/E/HGSS`
- **Fonction.** Maître de Hoenn, fils de Devon ; le miroir de Red (deux Maîtres qui pensent à partir).
- **Veut → besoin.** Protéger Hoenn et son père → affronter son père. **Faiblesse :** il cherche dans les pierres ce qu'il refuse de chercher chez lui.
- **Agenda.** M. **Test du figurant :** sans Red, il remonte les traces minérales jusqu'au relais vers le ch. 10, comprend, et protège son père en silence.
- **Positions.** INT prudente / CTL → SCE ; père PROTÈGE → ACCUSE (§1.2).
- **Alliances / rivalités PNJ.** Marc (ami [c]), Peter (collègue), Brice (il l'encourage) · M. Rochard (père), Max (il lui vole ses données), Arthur, Amaryllis (respect).
- **Pulsations.**
  | Ch. | Carte | Déclencheur | Ce qu'on voit | Action |
  |---|---|---|---|---|
  | 1 | Mérouville | lettre de M. Rochard | (lettre seulement) | livrer la lettre |
  | 2 | Grotte Granite | lettre livrée | éclats rouges et bleus des anneaux | **montrer** un éclat |
  | 7 | Devon 3F | W2 | il interroge son père | **montrer** l'enregistrement ou **rester** |
  | 8 | R120 | après Cimetronelle | Méga-Bracelet, Scope ; il doute | duo |
  | 10 | Centre Spatial | assaut | duo [c E : duo à Algatia] | combat ; Plongée |
  | 12 | Sommet | R4 | il accuse ou protège son père | — |
  | 14 | Ligue | Maître ou démission | | combat |
- **Scène qui définit (12 boîtes, ch. 2, Grotte Granite).** Il gratte un éclat rouge et un bleu au fond de la grotte. « Rubis et Saphir. Vous les connaissez, je crois. » Il comprend que Red a aidé Ciléo [c RFVF] et ne l'accuse pas : il note. Il parle de son père qui « bâtit », de lui qui « creuse ».
- **Voix.** Traits : calme, poli, curieux. Tics : ramasse des pierres ; « Intéressant. » ; métaphores minérales. Interdits : ne critique pas son père en public avant le ch. 12 ; ne se vante jamais du titre. Exemples :
  - “Ces éclats sont rouges et bleus. / Comme deux pierres connues.”
  - “Mon père bâtit. Moi, je creuse. / Parfois, on trouve la même chose.”
  - “Un Maître qui part… J’y pense / plus souvent que je ne le dis.”
- **Saillance.**
  | État | Réplique |
  |---|---|
  | ACCUSE | “Mon père savait. Il a choisi / de ne pas savoir. C’est pire.” |
  | PROTÈGE | “Devon répondra. Pas ici. / Pas devant tout Hoenn.” |
  | `PR` bas, ch. 10 | “Je ferai le duo, Red. / Rien de plus.” |
  | F2 (démission) | “Je rends le titre à Marc. / Il saura mieux sourire que moi.” |
- **Échos.** F1 : Maître, il paie la crise de Devon. F2 : démission ; départ pour Kanto [c HGSS]. F3 : Maître et garant de la charte. F4 : Maître d'une région blessée. F5 : il part chercher les anneaux sauvages ; Marc assure l'intérim. Dans F1, F3, F4 : s'il a ACCUSÉ, il démissionne aussi (Marc Maître).
- **Contrainte canon.** Libre de voyager vers Kanto (HGSS, Sylphe).
- **Asset.** `TRAINER_PIC_STEVEN` ; OW `STEVEN` ✔.

### C-09 Prof. Chen — Prof. Chen / Oak · rang A · `CANON RBJ/RFVF` (rival d'Agatha) ; `HYPOTHÈSE` (article)
- **Fonction.** Science de Kanto ; faute ancienne. Il y a 50 ans, avec Agatha, il a publié « un artefact scellé au sommet du Pilier Céleste ». Giovanni l'a lu.
- **Veut → besoin.** Être le premier à cataloguer → reconnaître Seko et Blue ; avouer.
- **Pourquoi à Hoenn.** Attaché scientifique de la Mission : nommer les espèces inconnues avant Seko.
- **Agenda.** É. **Test du figurant :** sans Red, il publie le premier catalogue avec les données de Brice, sous son nom.
- **Positions.** INT / CTL ; ch. 12 AVOUE · NIE.
- **Alliances / rivalités PNJ.** Nina, Brice (il le courtise) · Seko (rival), Agatha (rival [c]), Blue (négligence).
- **Pulsations.** ch. 0 (lettre) ; ch. 3 Poivressel (rejoint Seko) ; ch. 7 Bourg-en-Vol (clash au dîner) ; ch. 9 Mont Mémoria (W7) ; ch. 12 Sommet (aveu ou déni) ; épilogue ; postgame (duel de vétéran, HYPOTHÈSE non canon).
- **Scène qui définit (10 boîtes, ch. 7, dîner chez Seko).** Chen demande à Brice « juste un tableau » ; Seko pose sa fourchette. Les deux professeurs se disputent sur le droit de nommer. Mme Seko ressert tout le monde. Brice regarde Red.
- **Voix.** Traits : débonnaire, distrait, avide. Tics : oublie les prénoms [c] ; « Fascinant ! » ; tutoie Red. Interdits : ne parle jamais d'Agatha le premier ; pas de « je me suis trompé » avant le ch. 12. Exemples :
  - “Une espèce inconnue ! Note, / Brice… C’est bien Brice ?”
  - “Seko compte les habitats. Moi, / je nomme. Le nom reste.”
  - “Agatha ? Une vieille amie. / Vieille, surtout.”
- **Saillance.**
  | État | Réplique |
  |---|---|
  | AVOUE | “J’ai écrit où elle dormait. / J’avais vingt ans. Ça ne suffit pas.” |
  | NIE | “Un article de jeunesse ! / On ne vole pas avec un article.” |
  | `REL_CHEN_SEKO` réconciliés | “Seko, ton nom d’abord. / Le mien attendra, pour une fois.” |
- **Échos.** F1–F5 : il co-signe ou non avec Seko (M2). AVOUE : fin cachée possible (bible §12.3).
- **Contrainte canon.** Vivant, actif, radio en année 3 [c GSC].
- **Asset.** `TRAINER_PIC_PROFESSOR_OAK_FRLG` ; OW `PROF_OAK` ✔.

### C-10 Prof. Seko — Prof. Seko / Birch · rang A · `CANON RSE`
- **Fonction.** Science de Hoenn, père. Il fournit les chiffres du recensement au Rempart : c'est son compromis.
- **Veut → besoin.** Publier avant Chen, protéger les natifs → écouter son fils.
- **Agenda.** É/A. **Test du figurant :** sans Red, il publie avant Chen une étude « habitats menacés » qui sert d'annexe aux listes d'abattage de Norman.
- **Positions.** REM doux / SCE ; ÉCOUTE · FERMÉ.
- **Alliances / rivalités PNJ.** Norman (voisin [c], Rempart), Mme Seko · Chen, Brice (méthode).
- **Pulsations.** ch. 0 labo (starter ; Red dort dans la remise) ; ch. 3 Poivressel (Chen débarque) ; ch. 4 Lavandia (ramène Pikachu) ; ch. 7 Bourg-en-Vol (dîner, publication) ; ch. 12 Sommet (il présente les chiffres des natifs, avec ou sans Brice) ; épilogue (labo, nouvelle carte au mur).
- **Scène qui définit (9 boîtes, ch. 4, Lavandia).** Il rend Pikachu à Red, couvert de pansements, et avoue en riant qu'il a envoyé les chiffres de la R101 au Rempart « parce qu'il faut bien que quelqu'un agisse ». Brice entend. Seko ne voit pas le visage de son fils.
- **Voix.** Traits : jovial, de terrain, anxieux. Tics : « Ha ha ! » ; « sur le terrain » ; essuie ses lunettes. Interdits : pas de jargon ; jamais méchant avec Brice. Exemples :
  - “Ha ha ! Un ancien Maître dans / ma remise. Ça, c’est du terrain !”
  - “Les natifs disparaissent, Red. / Je dois les compter avant.”
  - “Chen nomme. Moi, je cherche / où ils vivent. Où ils vivaient.”
- **Saillance.**
  | État | Réplique |
  |---|---|
  | ÉCOUTE | “Ton recensement vaut mieux / que le mien. Signe-le seul.” |
  | FERMÉ | “Tu publieras quand tu sauras / ce que coûte une erreur.” |
  | ch. 4, Pikachu | “Ton Pikachu a mordu trois / infirmiers. Il va très bien.” |
- **Échos.** M2 décide : co-signature avec Chen, ou deux catalogues rivaux.
- **Asset.** OW `PROF_BIRCH` ✔ ; aucun pic (non combattant).

### C-11 Flora — Flora / May · rang A · `CANON RSE` (fille de Norman) ; `HYPOTHÈSE` (cadette du Rempart)
- **Fonction.** L'héroïne qui aurait pu l'être.
- **Veut → besoin.** Prouver qu'elle sert → son propre jugement. **Faiblesse :** l'ordre la rassure plus que les gens.
- **Agenda.** M. **Test du figurant :** sans Red, elle mène l'abattage de Vergazon et est promue.
- **Positions.** REM / SCE ; OBÉIT · DÉSOBÉIT au ch. 13.
- **Alliances / rivalités PNJ.** Norman, Brice (amitié), Major Bob (elle l'admire) · Brice (positions), Timmy (abattage), Erika.
- **Pulsations.**
  | Ch. | Carte | Déclencheur | Ce qu'on voit | Action |
  |---|---|---|---|---|
  | 1 | Bois Clémenti | brigade | contrôle de Red, arrivants en cage | combat refusable |
  | 1 | Clémenti | QG | elle reçoit son grade | — |
  | 7 | Vergazon | ordre d'abattage | W3 : Timmy devant elle | combat d'histoire |
  | 7 | Clémenti | vote | elle vote comme son père, ou s'abstient | — |
  | 13 | Civils | tempête | elle tient la place ou va aux gens | affectation |
  | E | Clémenti | épilogue | | — |
- **Scène qui définit (12 boîtes, ch. 7, Vergazon, W3).** Le verger est rongé. Flora lit l'ordre à voix haute. Timmy serre son arrivant. Brice récite le chiffre des baies perdues, puis celui des arrivants abattus la veille. Flora : « Tu comptes. Moi, je réponds. » Elle hésite une boîte (« … »), puis lance son Pokémon : le combat contre Timmy (ou contre Red, s'il s'interpose) décide du sort de l'arrivant.
- **Voix.** Traits : vive, disciplinée, droite. Tics : salue ; « Brigade trois » ; vocabulaire d'ordre. Interdits : jamais « je ne sais pas » avant le ch. 13 ; jamais cruelle sans ordre. Exemples :
  - “Brigade du Rempart. Papiers, / Pokémon, pas de geste brusque.”
  - “Un ordre, c’est une promesse / faite pour tout le monde.”
  - “Brice compte. Moi, j’agis. / On verra qui a sauvé quoi.”
- **Saillance.**
  | État | Réplique |
  |---|---|
  | DÉSOBÉIT | “L’ordre dit de tenir la place. / Les gens sont dans la rue. J’y vais.” |
  | OBÉIT | “On m’a dit de tenir la place. / … Je la tiens.” |
  | `FL` haut après Vergazon | “Timmy m’a regardée comme si / j’étais le Rempart. Je le suis ?” |
- **Échos.** F4 : capitaine du Rempart, sans joie. Ailleurs : elle quitte la brigade (DÉSOBÉIT) ou la commande (OBÉIT).
- **Asset.** `TRAINER_PIC_MAY` ; OW `RIVAL_MAY_*` ✔.

---

## 4. Mission Indigo, Kanto, Rocket (rang B)

**Deux vagues de Kantonais (HYPOTHÈSE structurante).** Les **bloqués** sont arrivés avant la fermeture des ports, il y a trois mois : Pierre (Brock), Aldo, Blue, Léo, le Président de Sylphe, Giovanni (incognito), les commandants Rocket. La **Mission** arrive officiellement au ch. 3 : Peter, Major Bob, Ondine, Erika, Koga et Jeannine, Morgane, Olga, Chen ; elle annexe Pierre (Brock) et Aldo. Agatha et Fuji viennent seuls au ch. 9. Cela explique la xénophobie : à Hoenn, tout Kantonais bloqué est un suspect.

Format des fiches B : fonction · veut → besoin (faiblesse) · raison d'être à Hoenn et désaccord · agenda et test du figurant · PNJ (A · R) · pulsations · scène qui définit · voix (traits ; tics et interdits ; 3 exemples) · saillance (3) · échos F1–F5 · canon année 3 · asset. L'équipe est en §1.6, la position en §1.2.

### C-12 Pierre — Pierre / Brock · `CANON RFVF/GSC`
- **Fonction.** L'éleveur qui veut soigner, pas trancher. **Veut → besoin :** quitter l'arène pour soigner → accepter qu'on ne sauve pas tout. Faiblesse : il promet trop.
- **À Hoenn :** invité par Devon il y a quatre mois pour les fossiles ranimés [c RSE : Devon ranime les fossiles] et pour les mines ; bloqué par la fermeture. **Désaccord :** Major Bob (contenir) et les mineurs (abattre).
- **Agenda** É/A. **Sans Red, demain**, il déplace en secret les arrivants des mines vers les vergers de Vergazon, chez l'oncle de Timmy ; la brigade l'arrête au ch. 7.
- **PNJ.** A : Roxanne, Timmy. R : mineurs, Major Bob.
- **Pulsations.** P ch. 1 mines de Mérouville (galeries envahies ; duo possible) · ch. 3 Poivressel (annexé par la Mission, il proteste) · É ch. 7 Vergazon (ses protégés sont sur la liste d'abattage) · B ch. 12 Sommet (vote) · E épilogue (refuge d'élevage).
- **Scène qui définit (10 boîtes, ch. 1, mines).** Un arrivant mangeur de sel est coincé sous un étai. Les mineurs veulent l'achever. Pierre se glisse dessous, lui parle, le sort. Le contremaître : « Et nos salaires ? » Pierre n'a pas de réponse.
- **Voix.** Traits : sérieux, doux, têtu. Tics : décrit des soins ; « doucement » ; ne s'assoit jamais. Interdits : aucune blague sur l'abattage ; pas de drague (trait de l'anime, non canon des jeux).
  - “Ils mangent le sel parce qu’ils / ont faim. Pas pour ruiner Devon.”
  - “Un Onix ne se presse pas. / Les mineurs, si. Je comprends.”
  - “J’ai quitté mon arène pour soigner. / Pas pour signer des listes.”
- **Saillance.**
  - protégés sauvés : “Ils dorment dans le verger. / Toute la nuit. Ça suffit, ce soir.”
  - protégés abattus : “Je n’en ai sauvé aucun. / Je recommence demain.”
  - mines réglées : “Les galeries tiennent. Merci. / Les mineurs, eux, pas encore.”
- **Échos.** F1 refuge à Vergazon, arrivants installés · F2 il rend les siens aux anneaux, en pleurant · F3 refuge financé par Devon · F4 il rentre à Argenta, refuge fermé · F5 refuge débordé, il reste un mois de plus.
- **Canon année 3 :** Champion d'Argenta [c GSC] : il rentre dans toutes les fins (le refuge passe à d'autres). **Asset :** `LEADER_BROCK_FRLG`, OW `BROCK` ✔.

### C-13 Ondine — Ondine / Misty · `CANON RFVF/GSC`
- **Fonction.** L'action directe. **Veut → besoin :** libérer les Pokémon Eau des filets (A), défier Marc (É) → mesurer les conséquences. Faiblesse : elle confond libérer et sauver.
- **À Hoenn :** experte marine de la Mission (des Stari de Kanto finissent dans les filets de Myokara). **Désaccord :** Aldo (pêcheurs), Major Bob.
- **Agenda** M. **Sans Red**, elle ouvre un filet par nuit et ruine les pêcheurs de Nénucrique.
- **PNJ.** A : Marc (admiration), Arthur (M1). R : Aldo, Major Bob.
- **Pulsations.** P ch. 3 quai · É ch. 9 port de Nénucrique (W8) · B ch. 11 Tréfonds (camp Aqua ou Mission) · E épilogue.
- **Scène qui définit (9 boîtes, ch. 9, W8).** Elle coupe un filet ; un banc d'arrivants file. Aldo arrive avec les caisses vides. Elle ne baisse pas les yeux, lui non plus. Red **désigne** l'un ou l'autre.
- **Voix.** Traits : fougueuse, franche, fière. Tics : « Allez ! » ; parle d'offensive [c RFVF : « offensive totale »]. Interdits : jamais cynique ; jamais froide avec un Pokémon.
  - “Ma politique ? L’offensive / totale. Avec ou sans permis.”
  - “Un filet, ça se coupe. / Un pêcheur, ça se relève.”
  - “Marc ? Je veux le battre. Et voir / son Milobellus. Dans cet ordre.”
- **Saillance.**
  - camp AQUA : “Arthur a tort sur tout. / Sauf sur la mer.”
  - camp MISSION : “J’ai vu les caisses vides d’Aldo. / Je reste avec la Mission.”
  - W8, Red a désigné Aldo : “Il a raison, ton gros bras. / Ça ne me plaît pas du tout.”
- **Échos.** F1 elle rentre sans Barpau · F2 les Stari reviennent, elle danse sur le quai · F3 elle siège au comité marin de la charte · F4 elle rentre en disgrâce, furieuse · F5 elle reste un été pour surveiller les anneaux marins.
- **Canon année 3 :** Championne d'Azuria [c GSC]. **Asset :** `LEADER_MISTY_FRLG`, OW `MISTY` ✔.

### C-14 Major Bob — Major Bob / Lt. Surge · `CANON RFVF`
- **Fonction.** Le logisticien militaire. **Veut → besoin :** contenir par la force → voir les gens derrière les chiffres.
- **À Hoenn :** logistique de la Mission ; Carmin sur Mer vit du port, et les dockers sont au chômage depuis la fermeture (motif concret). **Désaccord :** Ondine, Erika.
- **Agenda** A (l'ordre). **Sans Red**, il coupe la Nouvelle Lavandia un mois et appelle cela un succès.
- **PNJ.** A : Voltère, Norman ; Flora l'admire. R : Ondine, Erika.
- **Pulsations.** P ch. 3 quai · É ch. 4 Lavandia (il coupe un quartier pour sauver la centrale) · B ch. 7 Clémenti (vote d'abattage, W4) · E ch. 13 Civils (évacuation).
- **Scène qui définit (10 boîtes, ch. 4).** Devant un tableau de courant, il coupe un quartier d'un geste. Une enfant frappe à la vitre. Il ne la regarde pas, puis si. Red peut **rester** ou aller rétablir la ligne (décision, brief C).
- **Voix.** Traits : bruyant, moqueur, loyal. Tics : « petit soldat » [c] ; des pourcentages. Interdits : ne se moque jamais de la peur des civils.
  - “Petit soldat ! Le muet de Kanto ! / On m’avait dit que tu parlais peu.”
  - “Quatre-vingt-dix pour cent du / courant sauvé. Bon chiffre.”
  - “À la guerre, mes Pokémon m’ont / sauvé. Ici, je sauve la centrale.”
- **Saillance.**
  - quartier rétabli : “Les gens du quartier m’ont offert / du café. Froid. Mais offert.”
  - quartier coupé : “Dix pour cent dans le noir. / Des gens, ça ? … Des gens.”
  - ch. 13 : “Évacuation ! En rang ! / Les enfants d’abord, petit soldat.”
- **Échos.** F1–F3 il rentre avec les ports rouverts · F4 il évacue Algatia, médaillé et muet · F5 il reste former des brigades d'évacuation.
- **Canon :** Champion de Carmin. **Asset :** `LEADER_LT_SURGE_FRLG`, OW `LT_SURGE` ✔.

### C-15 Erika — Erika / Erika · `CANON RFVF`
- **Fonction.** La parfumeuse d'affaires. **Veut → besoin :** un contrat de parfum avec une fleur arrivante → choisir entre profit et vergers.
- **À Hoenn :** botaniste de la Mission pour Vergazon ; en secret, elle négocie avec le Consortium une licence d'import exclusive (l'espèce : brief D, nœud de Lavandia). **Désaccord :** Major Bob, Flora (abattage), le Président (prix).
- **Agenda** É. **Sans Red**, elle signe ; la fleur s'étend ; les vergers meurent.
- **PNJ.** A : Adriane, Timmy. R : Major Bob, Président de Sylphe, Flora.
- **Pulsations.** P ch. 4 Vergazon · É ch. 6 Vermilava (avec Adriane : un parfum des sources) · B ch. 7 Vergazon (le contrat) · E épilogue.
- **Scène qui définit (9 boîtes, ch. 7).** Dans le verger rongé, elle respire la fleur, puis regarde Timmy. Elle tient le contrat. Elle s'endort une boîte [c : elle somnole]. À son réveil, elle déchire ou signe (`STANCE_ERIKA` selon É et P).
- **Voix.** Traits : polie, rêveuse, tranchante. Tics : somnole ; métaphores de parfum. Interdits : jamais vulgaire.
  - “Pardon… je somnolais. / Vous disiez ? Ah, le contrat.”
  - “Cette fleur vient d’ailleurs. Son / parfum sera de Céladopole.”
  - “Le Rempart brûle des vergers / pour sauver des baies. Charmant.”
- **Saillance.**
  - INT : “J’ai déchiré le contrat. / Le parfum attendra. Les vergers, non.”
  - MAR : “Le contrat est signé. Les fermiers / seront… dédommagés.”
  - arrivant de Timmy sauvé : “Timmy dort près de son ami. / Voilà un parfum qui me plaît.”
- **Échos.** F1 parfum interdit, vergers sauvés · F2 la fleur repart, le flacon reste unique · F3 parfum vendu dans tous les Kiosques · F4 contrat annulé, elle rentre fâchée · F5 la fleur pousse partout ; elle en rit.
- **Canon :** Championne de Céladopole. **Asset :** `LEADER_ERIKA_FRLG`, OW `ERIKA` ✔.

### C-16 Koga — Koga / Koga · `CANON RFVF/GSC` ; passé Rocket : `[MANGA]`, jamais affirmé
- **Fonction.** L'espion ambigu. **Veut → besoin :** un siège au Conseil 4, la tête de la Rocket → (ambiguïté assumée).
- **À Hoenn :** sécurité de la Mission ; il chasse la Rocket. Il veut la recommandation de Peter pour le Conseil 4 (HYPOTHÈSE). Pour trouver la Rocket, il **achète** des informations à Lance (Rocket) : c'est le paiement à « K. » du carnet de primes. **Désaccord :** Peter.
- **Agenda** É. **Sans Red**, il piège le petit voleur au ch. 8, le livre à Peter comme « arme de la Rocket » et obtient son siège.
- **PNJ.** A : Jeannine, Lance (Rocket, d'intérêt), Alizée. R : Peter, Hoopa.
- **Pulsations.** P ch. 3 quai · É ch. 8 Cimetronelle (piège ; combat si Red lui dispute Hoopa) · B ch. 10 Algatia (W10) · E épilogue (Conseil 4).
- **Scène qui définit (10 boîtes, ch. 8).** Un filet invisible dans la canopée [écho des murs invisibles de Parmanie, c RFVF]. Le petit voleur tombe dedans. Koga : « Voilà ton voleur, Peter. Un dieu de poche. » Hoopa regarde Red.
- **Voix.** Traits : laconique, patient, ironique. Tics : proverbes de chasse ; parle de poison. Interdits : n'explique jamais un plan en entier ; ne confirme jamais un passé Rocket.
  - “Le poison est patient. / Le voleur, non. Il reviendra.”
  - “Un piège n’est pas une ruse. / C’est une promesse au gibier.”
  - “Peter veut des héros. / Moi, je lui livre des noms.”
- **Saillance.**
  - DÉMASQUÉ : “Oui, j’ai payé Lance. Pour un nom. / Peter jugera. Ça me va.”
  - COUVERT : “Tu as gardé la page. / Je te dois une ombre, Red.”
  - garde de Hoopa confiée à Koga : “Il dort. Les ninjas aussi / savent garder quelqu’un.”
- **Échos.** Toutes fins : il entre au Conseil 4 (canon) ; DÉMASQUÉ, Peter le nomme quand même, « sous surveillance ».
- **Canon :** Conseil 4 en année 3 ; Jeannine reprend Parmanie. **Asset :** `LEADER_KOGA_FRLG`, OW `KOGA` ✔.

### C-18 Morgane — Morgane / Sabrina · `CANON RFVF`
- **Fonction.** La voyante. **Veut → besoin :** comprendre sa vision → une prophétie n'est pas un ordre.
- **À Hoenn :** la Ligue Indigo lui demande de « sentir » les anneaux (ils plient l'espace). Elle a vu « un dragon dans un ciel déchiré ». **Désaccord :** Amaryllis (deux prophètes, deux lectures).
- **Agenda** M. **Sans Red**, elle pousse Peter à enterrer la Fiole à tout prix.
- **PNJ.** A : Lévy et Tatia, Capucine. R : Amaryllis.
- **Pulsations.** P ch. 3 quai · É ch. 8 R120 (vision) · B ch. 10 Algatia (avec les jumeaux, elle entend la voix) · E ch. 13 veillée.
- **Scène qui définit (8 boîtes, ch. 8, R120).** Absol passe. Morgane s'arrête, les yeux blancs. Elle décrit le Pilier, le dragon, et « une petite main dans une bouteille ». Elle ne comprend pas la dernière image.
- **Voix.** Traits : froide, précise, lasse. Tics : répond avant la question ; « je vois », jamais « je pense ». Interdits : ne rit pas avant l'épilogue.
  - “Vous alliez me demander mon nom. / Morgane. Asseyez-vous.”
  - “Je vois un dragon, un ciel / déchiré. Pas qui le recoud.”
  - “Vos pensées sont bruyantes, Red. / Pour quelqu’un qui se tait.”
- **Saillance.**
  - après le ch. 10 : “Ce n’est pas un dragon qui crie. / C’est une créature enfermée.”
  - bascule : “Une vision n’est pas un ordre. / Je l’apprends. Lentement.”
  - veillée : “Je tiens le Pilier. Je l’ai vu. / Cette fois, je choisis de le voir.”
- **Échos.** Toutes fins : elle rit une fois, en épilogue (seule fois du jeu).
- **Canon :** Championne de Safrania. **Asset :** `LEADER_SABRINA_FRLG`, OW `SABRINA` ✔.

### C-19 Auguste — Auguste / Blaine · `CANON RFVF` ; lien Fuji–Mewtwo ◐ (journaux du Manoir)
- **Fonction.** Conscience de Magma. **Veut → besoin :** financer la surveillance et l'évacuation de Cramois'Île (le volcan gronde : présage, bible §3) → refuser de refaire Mewtwo.
- **À Hoenn :** géologue consultant de Magma (volcanologie partagée avec Max). **Désaccord :** Adriane (sources vidées), puis Max.
- **Agenda** M. **Sans Red**, il signe les relevés de la démonstration, encaisse, et écrit à Fuji une lettre qu'il n'envoie pas.
- **PNJ.** A : Max, Fuji. R : Adriane.
- **Pulsations.** P ch. 6 Mont Chimnée · É ch. 6 Vermilava (les sources sont vides) · B ch. 9 Mont Mémoria (rejoint Fuji ou non, M4) · E ch. 12 Sommet et épilogue.
- **Scène qui définit (10 boîtes, ch. 6).** Après l'anneau, il voit le petit voleur blessé. Il s'agenouille. « Question ! Qu'est-ce qui respire dans une machine ? » Personne ne répond. Il écrit à Fuji (la lettre qui fait venir Fuji au ch. 9).
- **Voix.** Traits : excentrique, chaleureux, coupable. Tics : « Question ! » [c : les quiz]. Interdits : jamais de blague sur Mewtwo ; ne nomme pas Mewtwo avant le postgame.
  - “Question ! Qu’est-ce qui brûle / sans flamme ? … La culpabilité.”
  - “Magma paie bien. Mon île aura / des sirènes et des bateaux.”
  - “J’ai aidé à créer ce qu’on ne / contrôle pas. Une fois suffit.”
- **Saillance.**
  - rejoint Fuji : “Fuji, on a fabriqué un monstre. / Libérons-en un, pour changer.”
  - reste : “Max a besoin d’un géologue. / Mon île a besoin de son argent.”
  - sources vides : “Les sources sont vides. Je n’ai / rien demandé. C’est ça, le crime.”
- **Échos.** Toutes fins : il rentre ; « le volcan gronde » (bible §12.4). F2 Hoopa lui laisse un sac de pièces (l'île aura ses sirènes).
- **Canon :** l'éruption est future (GSC) : présage seulement. **Asset :** `LEADER_BLAINE_FRLG`, OW `BLAINE` ✔.

### C-20 Olga — Olga / Lorelei · `CANON RFVF` (Lokhlass de l'Île 4 ◐)
- **Fonction.** La traqueuse froide. **Veut → besoin :** récupérer ses Lokhlass → accepter l'aide de Hoenn.
- **À Hoenn :** des Lokhlass de Sevii braconnés [c RFVF ◐ : vols de Lokhlass par la Rocket] sont vendus à Nénucrique ; ses propres Lokhlass ont disparu un jour d'anneau (Q3). **Désaccord :** marchands, Rocket ; Peter (qui la veut au quai, pas au marché).
- **Agenda** A/É. **Sans Red**, elle force l'entrepôt seule ; la Rocket embarque les Lokhlass pendant la confusion.
- **PNJ.** A : Glacia, Damien. R : Lance et Ariane, marchands.
- **Pulsations.** P ch. 3 quai · É/B ch. 9 Nénucrique (coup de filet, présence exclusive) · ch. 12 Sommet · E épilogue (Île 4).
- **Scène qui définit (12 boîtes, ch. 9).** L'entrepôt la nuit. Elle entend un Lokhlass chanter derrière une cloison. Elle prend la main de Glacia sans la regarder. Le vrai Ferrand est dans la pièce voisine (`OBJ_LETTRE_FERRAND`).
- **Voix.** Traits : élégante, froide, tendre en privé. Tics : images de froid ; phrases courtes. Interdits : ne supplie jamais.
  - “Mes Lokhlass chantaient le soir. / Depuis l’anneau, l’île se tait.”
  - “Je n’ai pas besoin d’aide. J’ai / besoin de vitesse. Et de vous.”
  - “Le froid conserve. La colère, / non. Je reste froide.”
- **Saillance.**
  - Red avec elle : “Glacia m’a prêté sa neige. / Hoenn n’est pas si chaude.”
  - Red avec Aqua : “Vous étiez ailleurs, cette nuit. / Deux Lokhlass sont partis.”
  - F2 : “Ils chantent. Je rentre à l’Île 4. / Merci. Le mot est difficile.”
- **Échos.** F4 : ses Lokhlass ramènent l'équipe de Red par la mer (bible §12.4). Autres fins : elle rentre à l'Île 4.
- **Canon :** retour à l'Île 4 (bible §3). **Asset :** `ELITE_FOUR_LORELEI_FRLG`, OW `LORELEI` ✔.

### C-21 Aldo — Aldo / Bruno · `CANON RFVF/GSC`
- **Fonction.** L'ascète. **Veut → besoin :** un adversaire digne → s'engager.
- **À Hoenn :** venu s'entraîner à Myokara avec Bastien avant la fermeture [c RFVF : il s'entraîne en voyage] ; les pêcheurs l'ont nourri ; la Mission en fait son escorte. **Désaccord :** Ondine.
- **Agenda** É. **Sans Red**, il s'entraîne sur les falaises de la Grotte Granite et ignore la crise, jusqu'au naufrage d'un bateau.
- **PNJ.** A : Bastien (élève), pêcheurs de Myokara. R : Ondine.
- **Pulsations.** P ch. 2 Myokara · ch. 3 (escorte de la Mission) · É ch. 9 port (W8) · B ch. 11 Tréfonds ou Tournoi · E épilogue.
- **Scène qui définit (8 boîtes, ch. 2).** Il porte seul un bateau échoué. Bastien le regarde. « Tu ne te bats pas pour eux ? » Aldo pose le bateau. « Je porte. C'est déjà ça. »
- **Voix.** Traits : bref, honnête, physique. Tics : « Hmph. » Interdits : jamais d'insulte ; jamais de mensonge.
  - “Les pêcheurs m’ont nourri tout / l’hiver. Je porte leurs caisses.”
  - “Un adversaire digne. C’est tout / ce que je demande à Hoenn.”
  - “Hmph. Ta force ne parle pas. / La mienne non plus.”
- **Saillance.**
  - engagé : “Je me bats pour Myokara. / Pas pour la Ligue. Pour Myokara.”
  - neutre : “Je m’entraîne. Le reste ne / se règle pas à coups de poing.”
  - W8, désigné : “Ondine a ouvert le filet. / J’aurais fermé les yeux. Pas toi.”
- **Échos.** F4 il reste un mois à Myokara · autres : il rentre au Conseil 4.
- **Canon :** Conseil 4 en GSC. **Asset :** `ELITE_FOUR_BRUNO_FRLG`, OW `BRUNO` ✔.

### C-22 Agatha — Agatha / Agatha · `CANON RFVF` (rivale de Chen ; « autrefois dur et beau », paraphrase ◐)
- **Fonction.** Deuil et rancune. **Veut → besoin :** ramener les spectres de Lavanville, régler ses comptes avec Chen → transmettre, pardonner.
- **À Hoenn :** les spectres de la Tour Pokémon ont été « pris » par des anneaux et sont apparus au Mont Mémoria ; elle vient avec Fuji (Lavanville). Il y a 50 ans, elle était à Hoenn avec Chen (bible §3.1). **Désaccord :** Chen.
- **Agenda** M. **Sans Red**, elle fait le rite seule et accuse Chen au Sommet, sans preuve, donc sans effet.
- **PNJ.** A : Spectra (élève), Fuji. R : Chen. E : Lance (Rocket).
- **Pulsations.** P ch. 9 Mont Mémoria (rite) · É ch. 9 (W7) · B ch. 12 Sommet (l'article) · ch. 13 Pilier (rite avec la Doyenne) · E retraite.
- **Scène qui définit (11 boîtes, ch. 9, W7).** Sommet du mont, cierges. Chen arrive essoufflé. Agatha ne se retourne pas. « Tu as écrit où elle dormait, Chen. Un vase. Un pilier. » Chen rit trop vite. Agatha frappe le sol de sa canne. Les spectres se taisent.
- **Voix.** Traits : acerbe, lucide, fatiguée. Tics : « Hé hé. » ; « petit ». Interdits : jamais sentimentale à voix haute.
  - “Chen était dur et beau, jadis. / Maintenant, il est vieux.”
  - “Mes spectres sont venus ici / par vos anneaux. Je les ramène.”
  - “Tu m’as battue, petit. Bien. / Ça ne te donne pas raison.”
- **Saillance.**
  - Chen avoue : “Il l’a dit. Cinquante ans. / Spectra, prends ma place.”
  - rite profané : “Ils ont piétiné mes morts. / La Rocket apprendra à prier.”
  - ch. 12, défaut : “Lis l’article, Chen. À voix haute. / Tout Hoenn écoute.”
- **Échos.** Toutes fins : retraite (canon) ; F2 les spectres rentrent par un anneau, elle les compte.
- **Canon :** retraitée en année 3 [c GSC]. **Asset :** `ELITE_FOUR_AGATHA_FRLG`, OW `AGATHA` ✔.

### C-23 Léo — Léo / Bill · `CANON RFVF/GSC`
- **Fonction.** Concepteur de la couche de transfert. **Veut → besoin :** sauver son invention → dire la vérité à ses dépens.
- **À Hoenn :** ingénieur du Consortium depuis la signature. **Désaccord :** le Président (il dénonce) ; rivalité technique avec Lanette.
- **Agenda** M. **Sans Red**, il « corrige les fuites » en silence et espère.
- **PNJ.** A : Ciléo, puis Lanette. R : Président de Sylphe.
- **Pulsations.** P ch. 1 Devon 2F · É ch. 5 R114 (W9, chez Lanette) · B ch. 7 Lavandia (aveu et enregistrement du battement) · E ch. 10 Centre Spatial.
- **Scène qui définit (10 boîtes, ch. 7, centrale).** Il branche un haut-parleur. Boum. Boum. Voltère cesse de rire. Léo : « J'ai conçu le passage. Pas ce qui le nourrit. » Il tend l'enregistrement à Red.
- **Voix.** Traits : enthousiaste, distrait, honnête. Tics : « Génial ! » ; parle d'Évoli. Interdits : pas plus d'un mot technique par boîte.
  - “Génial, hein ? Un Pokémon part / d’ici, il arrive là-bas. Pouf !”
  - “J’ai conçu la couche de transfert. / Pas ce qui la nourrit.”
  - “Écoute ça. Boum… boum… / Les machines n’ont pas de cœur.”
- **Saillance.**
  - après l'aveu : “J’ai signé. Je témoignerai. / Même si on me reprend tout.”
  - allié de Lanette : “Lanette avait vu avant moi. / Je déteste quand elle a raison.”
  - F3 : “On le rationne, comme un / moteur. J’ai honte. Je signe.”
- **Échos.** F3 il écrit la charte · F4 il ramasse les débris du relais · autres : il rentre à Johto.
- **Canon :** à Doublonville en GSC. **Asset :** OW `BILL` ✔ (non combattant).

### C-24 Ciléo — Ciléo / Celio · `CANON RFVF`
- **Fonction.** Opérateur du nœud Kanto. **Veut → besoin :** prouver que sa machine est saine → admettre.
- **À Hoenn :** clandestin avec Red ; le Consortium l'a exclu du relais. **Désaccord :** Lanette (nœud contre stockage), le Président.
- **Agenda** É. **Sans Red**, il reste caché chez M. Marco, analyse les journaux du nœud de Poivressel, et finit arrêté comme « saboteur de Kanto ».
- **PNJ.** A : Red, Léo. R : Lanette, Président.
- **Pulsations.** P ch. 0 plage · É ch. 3 Poivressel, entrepôt (son nœud est propre, mais le trafic est énorme) · B ch. 10 (il voit la Fiole) · E ch. 12 (registre du coffre).
- **Voix.** Traits : timide, honnête, complexé. Tics : « Euh… » ; se compare à Léo. Interdits : jamais de vantardise.
  - “Euh… Ma machine relie des / données. Pas des Pokémon.”
  - “Léo aurait trouvé en une nuit. / Moi, en trois. Mais je trouve.”
  - “Tu as porté le Rubis jusqu’à moi. / On a relié le monde. Et voilà.”
- **Saillance.**
  - ch. 10 : “Il y a une fiole dans le relais. / Et quelque chose respire dedans.”
  - ch. 12 : “Registre du coffre de Sylphe. / ‘Cœur, origine : Pilier’.”
  - F1–F5 : “Je retourne au nœud de Kanto. / Je le couperai s’il le faut.”
- **Canon :** Centre Réseau de l'Île 1. **Asset :** OW `CELIO` ✔.

### C-25 M. Fuji — M. Fuji / Mr. Fuji · `CANON RFVF` (Lavanville) ; créateur de Mewtwo : `[ORIGINS]`/LGPE, non contraignant
- **Fonction.** La conscience extrême. **Veut → besoin :** libérer la créature à tout prix → sa pénitence ne justifie pas un désastre.
- **À Hoenn :** la lettre d'Auguste (ch. 6) ; il reconnaît « le bruit d'une cage ». **Désaccord :** le Président (le coffre), Ariane.
- **Agenda** A. **Sans Red**, il entre au Centre Spatial au ch. 13 et brise la Fiole (F5).
- **PNJ.** A : Auguste, Agatha. R : Président. E : Ariane [c RFVF : la Rocket l'a séquestré].
- **Pulsations.** P ch. 9 Mont Mémoria · É ch. 12 Sommet · B ch. 13 relais (il brise ou non) · E postgame (Mewtwo).
- **Voix.** Traits : doux, pénitent, têtu. Tics : « ceux qu'on fabrique ». Interdits : ne nomme pas Mewtwo avant le postgame ; ne hausse jamais la voix.
  - “J’ai fabriqué une créature, jadis. / Je connais le bruit d’une cage.”
  - “Les orphelins de Lavanville / m’attendent. Celui-ci d’abord.”
  - “Si personne ne l’ouvre, / je briserai la fiole moi-même.”
- **Saillance.**
  - il brise (F5) : “Pardon. Je n’ai pas su attendre. / Je n’ai jamais su.”
  - Hoopa avec quelqu'un (`HO` haut) : “Il a choisi quelqu’un. / Ce n’est pas moi. C’est bien.”
  - après l'inscription : “Briser sans lui, c’est lâcher / la tempête. Je sais. Et alors ?”
- **Canon :** vivant, Lavanville. **Asset :** OW `MR_FUJI` ✔.

### C-26 Président de Sylphe — sans nom [c] · `CANON RBJ/RFVF`
- **Fonction.** L'homme d'affaires coupable. **Veut → besoin :** sauver Sylphe → assumer.
- **À Hoenn :** coprésident du Consortium. Après l'occupation, il a trouvé la Fiole dans le coffre, l'a cachée à la police, puis l'a fournie comme « Cœur breveté » (bible §3.1). **Désaccord :** M. Rochard (partenaire et rival), Fuji, Giovanni.
- **Agenda** É. **Sans Red**, il vend la part de Sylphe à « un acheteur anonyme de Johto » au sommet des cours (c'est une société de Giovanni : ironie révélée au ch. 12).
- **PNJ.** A et R : M. Rochard. E : Giovanni. R : Fuji, Ciléo, Léo, Juan.
- **Pulsations.** P ch. 1 Devon 3F (présentation de Passerelle) · É ch. 3 Poivressel (Kiosque) · ch. 10 Centre Spatial (il se cache pendant l'assaut) · B ch. 12 (confession ou chute).
- **Voix.** Traits : bonhomme, vendeur, fuyant. Tics : « Formidable ! » ; change de sujet. Interdits : ne dit jamais « fiole ».
  - “Formidable ! Le monde entier, / livré en une seconde !”
  - “Le Cœur ? Un brevet de Sylphe. / Parlons plutôt des prix !”
  - “Vous avez sauvé Sylphe, Red. / Laissez-moi sauver le reste.”
- **Saillance.**
  - CONFESSION : “Je l’ai trouvée dans le coffre. / J’ai eu peur. Puis une idée.”
  - CHUTE : “Je n’ai rien à déclarer. / Mes avocats, si.”
  - ch. 12, affiche montrée : “Cette affiche ? Le marketing. / Vous étiez si… vendeur.”
- **Échos.** F2 Sylphe ruinée (elle se relève avant l'année 3 : voir K-05) · F3 il préside la charte · autres : démission ou procès selon la branche.
- **Asset :** repli `GENTLEMAN(_FRLG)`.

### C-28 Ariane — Ariane / Ariana · `CANON HGSS`
- **Fonction.** Cheffe des opérations à Hoenn ; l'égoïsme lisible. **Veut :** prouver sa valeur, ramener Giovanni avec la Fiole. Elle ne change pas.
- **Ce qu'elle voit juste (N13).** La Ligue parque les arrivants ; elle, elle **paie** les ruinés pour les leurs, puis les revend, et les recrute.
- **Agenda** É. **Sans Red**, elle achète les arrivants des pêcheurs ruinés, les revend à Nénucrique, et attaque le relais au ch. 10 de toute façon.
- **PNJ.** A : Lance (Rocket). R : Amos (méthode), Giovanni (qui méprise son plan). E : Olga.
- **Pulsations.** P ch. 1 R116 (sa lettre sur les contrebandiers) · É ch. 6 Vermilava (elle recrute les gardiens des sources ruinés) · B ch. 10 assaut · E ch. 13 relais (arrêtée puis évadée, ou en fuite).
- **Scène qui définit (9 boîtes, ch. 6).** Un gardien des sources ruiné, un arrivant au bout d'une corde. Ariane compte des billets. « Votre Ligue les parque. Nous, on les paie. » L'homme prend l'argent. Red peut **donner** (argent ou objet) pour que l'homme refuse (`RK`, brief C).
- **Voix.** Traits : froide, efficace, méprisante. Tics : désigne les gens par leur prix ; « Affaire conclue. » Interdits : ne crie jamais ; ne parle jamais de sentiments pour Giovanni.
  - “Votre Ligue les parque. / Nous, on les paie.”
  - “Affaire conclue. Le Rempart paie / la prime, nous, la recette.”
  - “Giovanni reviendra. Avec ou / sans sa permission.”
- **Saillance.**
  - `RK` haut : “Regarde les quais, champion. / La moitié porte déjà notre R.”
  - `RK` bas : “Tes amis ont nourri les ruinés. / Mauvais pour les affaires.”
  - arrêtée : “Une cellule ? Je compte les / jours. Ils seront courts.”
- **Canon :** libre en année 3 (Tour Radio). **Asset :** repli `ROCKET_GRUNT_F_FRLG`, OW `ROCKET_F`.

### C-29 Lambda — Lambda / Petrel · `CANON HGSS` (imitateur)
- **Fonction.** L'imposteur. **Veut :** réussir le coup du siècle et qu'on le sache.
- **Infiltration (correctif N5).** Depuis An 0 + 5 mois (huit mois avant le jeu), il a **remplacé** un vrai ingénieur, **Ferrand**, séquestré dans un entrepôt de Nénucrique. L'alias n'évoque pas « Lambda ». Il vend l'horaire volé à la Rocket **et** à Magma : affaire privée qu'Ariane ignore.
- **Agenda** É. **Sans Red**, il revend l'horaire une troisième fois (à Aqua) et disparaît avant l'assaut.
- **PNJ.** A : Ariane ; Max (client). E : Giovanni (après ch. 10), Lanette (elle a connu Ferrand).
- **Pulsations.** P ch. 1 Devon 2F (« Ferrand ») · ch. 4 Lavandia (présent avant la panne) · É ch. 6 Planque Magma (horaire signé « F. ») ; ch. 7 filature · B ch. 10 faux Giovanni, démasqué.
- **Indice récurrent (plant).** « Ferrand » fredonne toujours le même air ; le faux Giovanni du ch. 10 le fredonne aussi.
- **Voix.** Traits : théâtral, vaniteux, rapide. Tics : en Ferrand, « procédure » ; en lui-même, il se félicite. Interdit : en Ferrand, aucun tic de Lambda sauf l'air fredonné.
  - “Procédure sept, alinéa deux. / Merci de ne pas toucher.”
  - “Un visage, c’est un costume. / Le mien est au vestiaire.”
  - “J’ai vendu le même horaire / deux fois. Ça, c’est du talent.”
- **Saillance.**
  - vrai Ferrand libéré : “Le vrai Ferrand ? Libéré ? / Il n’avait aucun style.”
  - démasqué par Giovanni : “Patron… c’était un hommage. / … Patron ?”
  - filature repérée : “Tu me suis depuis Lavandia ? / Moi aussi, je sais être discret.”
- **Canon :** libre en année 3. **Asset :** replis `ROCKET_GRUNT_M_FRLG`, `SCIENTIST_FRLG` (Ferrand), `GIOVANNI` (déguisement).

### C-30 Lance (Rocket) — Lance / Proton · `CANON HGSS` (« le plus cruel » ◐)
- **Fonction.** L'homme de terrain. **Veut :** encaisser les primes du Rempart ; reprendre la Fiole qu'il a déjà volée une fois (An −2).
- **Agenda** É. **Sans Red**, il chasse les arrivants pour la prime et revend les mêmes au marché noir.
- **PNJ.** A : Ariane, Koga (d'intérêt). E : Peter, Agatha, Spectra, Amaryllis.
- **Pulsations.** P ch. 1 R116 (contrebandiers postés avant l'anneau) · É ch. 4 Tunnel (raid) · B ch. 9 Mont Mémoria (profanation ; il perd l'article annoté) · E ch. 12 interrogatoire (aveu sur la gardienne), ch. 13.
- **Voix.** Traits : souriant, cruel, pratique. Tics : « Rien de personnel. » ; compte les têtes. Interdits : aucune cruauté montrée (N15) ; tout reste hors champ.
  - “Le Rempart paie à la tête. / Moi, je sais compter les têtes.”
  - “Rien de personnel. Une prime, / c’est une prime.”
  - “Ce mont ? J’en ai grimpé de plus / hauts. Un pilier, par exemple.”
- **Saillance.**
  - interrogatoire ch. 12 : “Elle nous a suivis jusqu’au bateau. / La tempête a fait le reste.”
  - raid perdu : “Le prédicteur ? Gardez-le. / Il ne prédit pas vos ennuis.”
  - arrêté : “Arrêté ? Pour combien de / temps, à votre avis ?”
- **Canon :** libre en année 3 (Puits Ramoloss). **Asset :** replis `ROCKET_GRUNT_M_FRLG`, OW `ROCKET_M`.

---

## 5. Hoenn (rang B)

Format resserré (même champs que §4). Pour les Champions : la **crise de ville** est P/É, le **badge** (remis quelle que soit l'issue, bible §8.1) est B, le **Sommet** ou la **Ligue** est E.

### C-32 Norman · `CANON RSE`
- **Veut → besoin :** l'ordre → voir sa fille. Chef du Rempart, registraire de l'accréditation. **Sans Red**, il signe l'abattage de Vergazon et ferme les ports pour de bon. **PNJ** A : Major Bob, Seko · R : Peter (rapatrier ≠ abattre), Chen, Erika.
- **Pulsations.** P ch. 0 (téléphone : nom ou anonymat) · ch. 1 Clémenti (QG du Rempart) · É/B ch. 7 (vote d'abattage W4, badge 5, Surf) · ch. 12 Sommet · E ch. 13 (sa fille).
- **Scène (10 boîtes, ch. 7).** Il ouvre le vote, compte les mains, regarde Flora en dernier.
- **Voix.** strict, juste, fier ; vouvoie, « la règle est la règle » ; ne hausse jamais le ton contre Flora en public.
  - “Nom, ou anonymat ? / La loi d’urgence accepte les deux.”
  - “Un dresseur étranger est accrédité / niveau par niveau. C’est la règle.”
  - “Je ne hais pas les arrivants. / Je compte ceux qu’ils remplacent.”
- **Saillance.** Flora désobéit : “Ma fille a désobéi. … Elle / avait raison. Ne le répétez pas.” · vote passé : “Le vote est passé. Voici le badge. / Et Surf. Ne me remerciez pas.” · vote rejeté : “Le vote a échoué. Hoenn / choisira plus tard. Plus cher.”
- **Échos.** F4 il commande le Rempart victorieux, seul · autres : il rend l'accréditation et rentre à l'arène. **Asset :** `LEADER_NORMAN`, OW ✔.

### C-33 Timmy · `CANON RSE` (Vergazon, fragile)
- **Veut → besoin :** garder son ami → se battre pour lui ou le laisser partir. Son arrivant (espèce : brief D ; surnom « Petit-Pois ») est condamné. **Sans Red**, il le cache dans la remise jusqu'à la brigade. **PNJ** A : Erika, Pierre (Brock) · R : Flora.
- **Pulsations.** P ch. 4 Vergazon · É ch. 7 (contre la brigade, combat refusable) · B ch. 13 Civils (son arrivant aide à l'évacuation) · E ch. 14 Route Victoire ou postgame.
- **Voix.** timide puis décidé ; « Je… je peux ? » ; ne se plaint plus après le ch. 7.
  - “Il s’appelle Petit-Pois. / Il a mangé toutes les baies.”
  - “Mon oncle dit qu’il faut le / rendre. Le rendre à qui ?”
  - “Je tousse moins, depuis lui. / C’est bête, non ?”
- **Saillance.** sauvé : “Petit-Pois a grandi. Moi aussi. / Tu veux voir ? On se bat ?” · abattu : “Ils l’ont emmené. Flora a dit / pardon. Ça ne sert à rien.” · F2 : “Un anneau l’a ramené chez lui. / Il m’a regardé. Il savait.”
- **Asset :** `TRAINER_PIC_WALLY`, OW ✔.

### C-34 M. Rochard · `CANON RSE`
- **Veut → besoin :** sauver Devon et les emplois de Mérouville → dire la vérité à son fils. A choisi de ne pas demander ce qu'était le Cœur. **Sans Red**, il signe l'extension de Passerelle vers Johto et réembauche les mineurs. **PNJ** A/R : Président de Sylphe ; A : Capitaine Marin · R : Pierre Rochard, Giovanni (rachats d'actions).
- **Pulsations.** P ch. 1 Devon 3F (lettre, Passerelle) · É ch. 7 (W2) · ch. 10 (appel : « protégez le Cœur ») · B ch. 12.
- **Voix.** jovial, fier, comptable ; chiffres d'emplois ; ne dit jamais « je savais » hors VÉRITÉ.
  - “Mille deux cents emplois, Red. / Voilà ce que relie Passerelle.”
  - “Mon fils creuse des cailloux. / Moi, je creuse des salaires.”
  - “Le Cœur ? Je n’ai pas demandé. / On ne questionne pas un cadeau.”
- **Saillance.** VÉRITÉ : “J’ai choisi de ne pas savoir. / Pierre, c’était un choix.” · SILENCE : “Devon n’a rien à déclarer. / Devon a des employés.” · F2 : “Hoopa a vidé le coffre et laissé / les mineurs. Étrange voleur.”
- **Asset :** repli `GENTLEMAN`.

### C-35 Marc · `CANON RSE/E`
- **Veut → besoin :** préserver la tradition et le spectacle → choisir entre les Sages et son ami. A laissé l'arène à Juan, garde la Grotte Originelle, préside les Concours (bible §3). **Sans Red**, il maintient le Concours de Nénucrique malgré le marché noir et ferme la Grotte. **PNJ** A : Juan, Pierre Rochard, Nina · R : Doyenne et Sages.
- **Pulsations.** P ch. 9 Concours · É ch. 12 Atalanopolis · ch. 13 Civils · B/E ch. 14 (Maître si Pierre Rochard démissionne).
- **Voix.** théâtral, sincère ; « Magnifique. » ; jamais de moquerie.
  - “Un Concours pendant la crise ? / Justement. Il faut de la beauté.”
  - “La Grotte dort. Les Sages aussi. / Moi, je veille. Avec style.”
  - “Pierre est mon ami. Les Sages, / ma famille. Ne me forcez pas.”
- **Saillance.** avec son ami : “Je vote avec Pierre. Les Sages / me pardonneront. Un jour.” · avec les Sages : “La tradition n’est pas belle. / Elle est solide. Je la choisis.” · Maître : “Maître ? Moi ? … Bien. Alors / faisons-le magnifiquement.”
- **Asset :** `CHAMPION_WALLACE`, OW ✔.

### C-36 Juan · `CANON E`
- **Veut → besoin :** l'impartialité → prendre parti. Arbitre du Sommet. **Sans Red**, il préside un Sommet qui vote sans preuve. **PNJ** A : Marc, Sages · R : Président de Sylphe (qui tente d'acheter l'ordre du jour).
- **Pulsations.** P ch. 9 jury du Concours · É ch. 12 arène (badge 8) · B ch. 12 Sommet · E épilogue.
- **Voix.** gentilhomme danseur ; « Bravo. » ; neutre jusqu'à R4.
  - “Un combat est une danse. / On ne danse pas en criant.”
  - “Je préside. Je ne vote pas. / Du moins, pas encore.”
  - “Votre cadeau est charmant, / Président. Reprenez-le.”
- **Saillance.** R4 établi : “Trois sources concordent. Je ne / suis plus neutre. Je suis juste.” · R4 incomplet : “Je ne vois que des rumeurs. / Le Sommet ne juge pas cela.” · badge : “Voici le badge. Montez, Red. / Le Sommet vous attend.”
- **Asset :** `LEADER_JUAN`, OW ✔.

### C-37 Roxanne · C-38 Bastien · C-39 Voltère · C-40 Adriane · C-41 Alizée · C-42 Lévy et Tatia (Champions)
| ID | Veut → besoin · sans Red demain | PNJ A · R | Pulsations (P, É, B, E) | Voix (traits ; tic) |
|---|---|---|---|---|
| C-37 Roxanne | des données, pas des cris → agir sans données complètes · elle publie un relevé que personne ne lit | Pierre (Brock), Brice · mineurs | ch. 1 mines ; ch. 1 badge 1 ; ch. 7 relevés (retour) ; ch. 12 vote | pédagogue ; « Notez bien. » |
| C-38 Bastien | défendre les arrivants des vagues → partager la baie · il sauve des arrivants et perd ses amis pêcheurs | Aldo, Ondine · pêcheurs | ch. 2 Myokara ; ch. 2 badge 2 ; ch. 11 surveille le câble ; ch. 12 vote | surfeur ; « Grosse vague ! » |
| C-39 Voltère | le courant de Lavandia → voir ce qui le produit · il signe un second contrat Passerelle | Major Bob · Aqua, le quartier coupé | ch. 4 centrale ; ch. 4 badge 3 ; ch. 7 aveu de Léo dans sa centrale ; ch. 12 | bâtisseur rieur ; « Ouahaha ! » |
| C-40 Adriane | sauver les sources → régner sans grand-père · elle ferme Vermilava aux touristes et s'endette | Erika · Max, Auguste | ch. 6 troupeau ; ch. 6 sources vides ; ch. 6 badge 4 ; ch. 12 | jeune, nerveuse ; « Je suis la Championne ! » |
| C-41 Alizée | sauver les nids → accepter un ciel partagé · elle chasse les corvidés jusqu'au dernier | Koga, Jeannine · Amaryllis | ch. 8 canopée ; ch. 8 piège ; ch. 8 badge 6 ; ch. 12 | sereine ; images de vent |
| C-42 Lévy et Tatia | comprendre la « voix » du relais → la faire entendre · ils signalent la voix ; le Consortium les fait taire | Morgane · Consortium | ch. 10 arène ; ch. 10 badge 7 (double) ; ch. 13 relais ; E | répliques alternées, phrases finies par l'autre |

Répliques (3 par Champion) :
- Roxanne : “Notez bien : on ne panique pas. / On mesure. Ensuite, on panique.” · “Vous êtes un ancien Maître. Ici, / vous êtes élève. Asseyez-vous.” · carte publiée : “La carte de Brice est formelle. / Ces arrivants viennent de Kalos.”
- Bastien : “Grosse vague ! Euh… Monsieur / le Maître. Grosse vague.” · “Ils ont nagé jusqu’ici. On ne / renvoie pas un nageur.” · Myokara ruinée : “Les bateaux restent au port. / Même moi, je ne surfe plus.”
- Voltère : “Ouahaha ! J’ai bâti cette ville. / Je ne la laisserai pas s’éteindre.” · “Le Major coupe un quartier. / Moi, j’aurais coupé l’autre.” · après Léo : “Une créature dans mes câbles ? / … Je ne ris plus, Red.”
- Adriane : “Je suis la Championne ! Depuis / trois mois. Mais je le suis.” · “Les sources se sont vidées en / une nuit. Leurs Pokémon aussi.” · démonstration dénoncée : “Vous avez dénoncé Magma. / Ça ne remplit rien. Mais merci.”
- Alizée : “Le vent apporte tout. Même / ce qu’on ne veut pas.” · “Votre petit voleur vole mieux / que mes Tylton. C’est vexant.” · Hoopa chez Koga : “Koga garde la créature. Moi, / mes nids. Chacun sa cage.”
- Lévy et Tatia : “Lévy : On entend quelque chose… / Tatia : …qui pleure.” · “Tatia : Le relais a une voix. / Lévy : Elle dit ‘rends’.” · F3 : “Tatia : Il pleure moins fort. / Lévy : Il pleure quand même.”
**Assets :** pics et OW ✔ pour tous (`CAST_DOSSIER` §2.11).

### C-43 Damien · C-44 Spectra · C-45 Glacia · C-46 Aragon (Conseil 4 de Hoenn)
| ID | Veut → besoin · sans Red demain | PNJ A · R | Pulsations | Voix |
|---|---|---|---|---|
| C-43 Damien | protéger les petits trafics des siens → choisir un camp · il vend à tout le monde et perd sa rue au profit de la Rocket | Olga · Rocket, Rempart | ch. 3 Poivressel (rumeur) ; ch. 9 nuit du marché ; ch. 13 Civils (cache des familles) ; ch. 14 | voyou au grand cœur ; « frangin » |
| C-44 Spectra | être reconnue par Agatha → garder le mont seule · elle fait le rite, qui échoue sans Agatha | Agatha · Lance (Rocket) | ch. 9 mont ; ch. 9 rite ; ch. 13 Mont Mémoria (civils) ; ch. 14 | joyeuse et spectrale ; « Hi hi. » |
| C-45 Glacia | aider les arrivants (elle en est une) → se dire d'ici · elle loge des arrivants chez elle, hors la loi | Olga · Rempart | ch. 9 avec Olga ; ch. 9 nuit du marché ; ch. 13 Civils ; ch. 14 | froide, ironique ; « Quelle chaleur. » |
| C-46 Aragon | apaiser les clans → choisir entre la Doyenne et Amaryllis · il arbitre jusqu'à ce que personne ne l'écoute | Doyenne, Amaryllis · Peter | ch. 5 arbitre (W1) ; ch. 12 voix des Gardiens ; ch. 13 Pilier (rite) ; ch. 14 | vieux marin ; images de mer |

Répliques :
- Damien : “On va s’amuser, frangin. Enfin, / toi. Moi, je travaille.” · “Le marché noir, c’est le marché / de ceux que l’autre a oubliés.” · Olga avec Red : “Olga a tenu parole. Mes gars / sont libres. Les Rocket, non.”
- Spectra : “Hi hi ! Les esprits disent que / vous êtes très vivant.” · “Ces spectres viennent de / Lavanville. Ils ont froid ici.” · transmission : “Agatha m’a donné sa canne ! / Enfin, une canne. C’est pareil.”
- Glacia : “Je suis une arrivante, moi aussi. / Le Rempart m’a donné un titre.” · “Olga ! Enfin quelqu’un qui / comprend le froid.” · variante REM : “Le Rempart a gagné. On m’a / demandé mes papiers. À moi.”
- Aragon : “J’ai navigué quarante ans. / Le ciel décide. Toujours.” · “Peter, ici, tu ôtes tes bottes. / Le Site n’est pas ta caserne.” · “Amaryllis a raison sur le mal. / Elle se trompe de remède.”
**Échos (Ligue = écho de la fin, bible §12.3) :** chacun ouvre son combat par une réplique de fin (brief C fournit le sélecteur ; 1 réplique × 5 fins × 4 membres = 20 boîtes). **Assets :** ✔.

### C-47 Max · `CANON RSE/ROSA`
- **Veut → besoin :** répartir les espèces par anneaux déclenchés → écouter ceux qui paient. Il a acheté l'horaire à Lambda (« F. »). **Ce qu'il voit juste :** le phénomène doit être géré. **Sans Red**, il fait sa démonstration, vide les sources de Vermilava, et appelle cela un « transfert réussi ». **PNJ** A : Auguste, Kelvin · R : Arthur [c], Pierre Rochard [c] ; E : Kosmo [c].
- **Pulsations.** P ch. 5 R112 (relevés ; sécurité levée en fin d'événement) · É ch. 6 démonstration (W5) · B ch. 12 · E épilogue.
- **Voix.** rationaliste, rigide ; « Calculé. » ; ne s'excuse pas avant B.
  - “Le chaos se gère. Il suffit / d’un horaire et d’un plan.”
  - “Un anneau qu’on déclenche est / un anneau qu’on comprend.”
  - “Arthur libère. Moi, je range. / Lequel de nous noie les gens ?”
- **Saillance.** ÉCOUTE : “Les sources de Vermilava… / Je n’avais pas calculé ça.” · PERSISTE : “Une erreur de mesure. / La méthode reste juste.” · sabotée : “Vous avez coupé ma démonstration. / Vous avez coupé une solution.”
- **Asset :** `MAGMA_LEADER_MAXIE`, OW ✔.

### C-48 Arthur · `CANON RSE/ROSA`
- **Veut → besoin :** libérer la créature, accueillir tous → mesurer. **Ce qu'il voit juste :** enchaîner une créature est un crime. **Sans Red**, il coupe le câble au ch. 11 : tempête d'anneaux sur Pacifiville. **PNJ** A : Sarah, Matthieu, Ondine (M1) · R : Max [c] ; E : Norman (Rempart).
- **Pulsations.** P ch. 6 manifestation (W5) · É ch. 9 Planque Aqua (plan du câble) · B ch. 11 Tréfonds · E épilogue.
- **Voix.** pirate, chaleureux, impulsif ; « Les gars ! » ; jamais cruel envers un Pokémon.
  - “Une créature enchaînée sous / nos mers ! Et ça s’appelle Hoenn ?”
  - “Les gars ! Tout ce qui nage / a le droit de nager.”
  - “Max range le monde en boîtes. / Moi, j’ouvre les boîtes.”
- **Saillance.** NÉGOCIE : “Sarah a raison. Si je coupe, / la tempête mange Pacifiville.” · COUPE : “Je coupe ! Que le ciel / s’arrange avec le reste !” · Red avec Olga au ch. 9 : “Tu étais avec Kanto cette nuit. / Je m’en souviendrai.”
- **Asset :** `AQUA_LEADER_ARCHIE`, OW ✔.

**Échos F1–F5 des Hoenn rang B (une case = un plan de diaporama ou une réplique de PNJ) :**
| Perso | F1 Sceau | F2 Pacte | F3 Passerelle | F4 Rempart | F5 Ciel ouvert |
|---|---|---|---|---|---|
| Max | dissout Magma | aide à recompter les sources revenues | conseiller de la charte | félicité par le Rempart, honteux | traque les anneaux sauvages |
| Arthur | manifeste au Pilier | fête au port | câble surveillé par Aqua | arrêté, relâché | « la mer est libre », et inquiète |
| Roxanne à Glacia | crise de ville réglée, natifs en hausse | disparus revenus, emplois perdus | prix bas, petits anneaux | natifs protégés, arrivants partis | épidémies d'anneaux sur leur route |

---

## 6. Rang C et personnages muets (≥ 2 scènes + un écho, un agenda, une relation)

| ID | Fonction · agenda · sans Red demain | PNJ A · R | Scènes + écho | Réplique | Asset |
|---|---|---|---|---|---|
| C-17 Jeannine | égaler son père (É) · elle pose ses propres pièges et rate le voleur | Koga (F, R), Alizée | ch. 3 ; ch. 8 (déguisée en sbire [c GSC]) ; E Parmanie | “Père a piégé un dieu. Moi, / je piégerai mieux. Un jour.” | OW `NINJA_BOY`, pic `BATTLE_GIRL` |
| C-27 Nina | un ruban de Hoenn ; veiller sur Blue (A) · elle concourt et écrit à Chen | Blue, Marc | ch. 3 ; ch. 9 Concours ; E (lettre à Blue) | “Blue fait le fier. Il m’écrit / chaque soir. Ne lui dites pas.” | OW `DAISY` |
| C-31 Amos | un retour « digne » de Giovanni (É) · il prépare Johto [c HGSS] et désavoue Ariane par lettre | Giovanni · Ariane | ch. 6 (lettres interceptées) ; ch. 10 ; ch. 13 selon `RK` ; E fuite | “Le patron reviendra debout, / ou il ne reviendra pas.” | repli `GENTLEMAN_FRLG` |
| C-49 Kelvin | être reconnu par Max · il exécute la démonstration sans poser de question | Max · Courtney | ch. 5 R112 ; ch. 6 ; E | “Max l’a calculé. Donc / c’est juste. Donc on y va.” | `MAGMA_ADMIN` |
| C-50 Courtney | loyauté instable · elle pousse la démonstration plus loin que prévu | Max · Kelvin | ch. 6 Planque ; ch. 12 ; E | “Plus grand. L’anneau. / Max a dit grand, non ?” | `MAGMA_ADMIN` (pic partagé) |
| C-51 Matthieu | protéger les siens · il évacue les sbires avant le câble | Arthur · Max | ch. 9 ; ch. 11 ; E | “Le chef coupe ? Je porte / les gars. Chacun son travail.” | `AQUA_ADMIN_M` |
| C-52 Sarah | la vérité des données (M) · elle occupe l'Institut et cache ses doutes | Arthur (M8) · Max | ch. 8 Institut ; ch. 11 Tréfonds ; E | “Mes relevés disent : tempête. / Arthur dit : liberté. Les deux ?” | `AQUA_ADMIN_F` |
| C-53 Scott | profiter des imports, recruter des stars (É) · il signe Blue à vie | Blue · Peter (refuse ses imports) | ch. 3 Tente ; ch. 9 ; P Zone | “Une star, des imports, un public. / Il ne manque que vous, Red.” | OW `SCOTT`, pic `EXPERT_M` |
| C-54 Bayar | les sceaux anciens (A) · il fouille seul les ruines du désert | Capucine · Magma (relevés) | ch. 5 quête ; P Pyramide ; fin cachée | “Les anciens ont scellé ce / qu’ils craignaient. Toujours.” | ✔ |
| C-55 Capucine | « lire » les Pokémon ; liée à Morgane | Morgane · Scott | P Tour ; lettre de Morgane (ch. 10) ; E | “Votre équipe vous manque. / Elle le sait, où qu’elle soit.” | ✔ |
| C-56 Kosmo | comprendre les « étoiles filantes » (A) · il publie que ce sont des éclairs d'anneaux, personne n'y croit | Brice · Max [c : la Météorite] | ch. 5 Autéquia ; ch. 8 lettre à l'Institut ; E | “Mes étoiles filantes tombent / à l’heure. Les étoiles, non.” | `SCIENTIST_1` |
| C-57 Lanette | ses journaux, son honneur (É) · elle dépose plainte contre Léo, qui a signé « sa » couche | Léo (R puis A) · Ciléo ; elle a connu Ferrand | ch. 5 R114 (W9) ; ch. 9 (le vrai Ferrand) ; E | “Mes journaux sont horodatés. / Les anneaux aussi. Même heure.” | `WOMAN_2` |
| C-58 M. Marco | retrouver Piko (A/É) · il passe des clandestins pour payer l'essence des recherches | Red · Capitaine Marin | ch. 0 passeur ; ch. 2 bateau ; ch. 3 ; F2 (Piko rendu) | “Piko est parti un jour d’anneau. / Je cherche le jour suivant.” | `EXPERT_M` |
| C-59 Capitaine Marin | relever le câble (A) · il relève le câble et découvre qu'il « chauffe » | M. Rochard · Arthur | ch. 3 (composant Devon) ; ch. 11 sous-marin ; E | “Ce câble est tiède. Un câble / n’a pas de raison d’être tiède.” | OW vanilla |
| C-60 Mme Seko | le foyer, les deux enfants de la maison (A) · elle nourrit Red sans poser de question | Seko · Chen (elle le remet à sa place) | ch. 0 ; ch. 7 dîner ; E | “Ici, on mange d’abord. / On sauve le monde après.” | OW `MOM` |
| C-61 Doyenne | rendre la Fiole au Pilier, par le rite (A) · elle prépare le rite et attend | Aragon · Amaryllis | ch. 5 (conte) ; ch. 12 (rite) ; ch. 13 Pilier (soin) ; E | “Le dragon ne juge pas. / Il nettoie. Nous, nous jugeons.” | repli `OLD_WOMAN` / `EXPERT_F` |
| C-62 Sages | la tradition (eaux sacrées) contre l'ouverture · ils refusent l'accès à la Grotte | Juan · Marc | ch. 12 ×2 ; E | “On n’ouvre pas une grotte / parce qu’une foule le demande.” | `OLD_MAN` |
| C-64 Têtes de la Zone | Sam, Carole, Takim, Esteban, Charline : chacun teste une forme de force achetée ou gagnée (postgame) | Scott | P ×2 (ouverture, revanche) ; E lettres | — | ✔ |

**C-63 Rayquaza (muet) · `CANON RSE/ROSA` (gardien du ciel) ; règles Y1–Y3 `HYPOTHÈSE`.** Il ne parle pas, ne choisit pas, ne punit pas : il **nettoie ce qui déchire**. Scènes : ch. 8 signes (tempêtes, Absol, vision de Morgane) ; ch. 12 éveil ; ch. 13 descente ; E remontée (F4) ou ciel calme. Sens : le monde a des règles que la force ne négocie pas (invariant 4). Asset : `RAYQUAZA`, `RAYQUAZA_STILL` ✔.

---

## 7. Brice parle pour Red (les 5 gestes)

Principe : Brice **traduit** ; il le dit ; il se trompe parfois ; à partir du ch. 7, il peut ajouter **son** avis, signalé (« moi, je… »). Le Sommet (brief C) peut lire `BR` pour la fidélité de la traduction et `BV` pour l'ajout.

| Geste | Ce que Brice dit | Maladresse typique (comique ou coûteuse) |
|---|---|---|
| **montrer** | “Red vous montre ceci. Il pense / que ça répond à votre question.” | il explique trop la pièce et en révèle la source |
| **désigner** | “Red veut que vous parliez, vous. / Oui, vous. Allez-y.” | il présente la personne avec un titre faux |
| **rester** | “Red attend. Il attend très bien. / Moi, beaucoup moins.” | il lit un accord là où Red attend seulement |
| **partir** | “Red s’en va. Ce n’est pas contre / vous. Enfin… un peu, si.” | il adoucit la rupture et la rend ambiguë |
| **donner** | “C’est pour vous. Red ne le dit pas, / mais il le pense fort.” | il commente la valeur du don, gêne |
| ajout (`BV` posé) | “Je traduis Red. Et moi, je ne / suis pas d’accord. Voilà.” | — (ce n'est pas une erreur : c'est sa voix) |

Si `BR` est bas, il traduit sèchement (“Il montre ça. C’est tout.”) ; les votants en tirent moins (brief C).

---

## 8. Lore et mythologie

### 8.1 La légende du Voleur d'Anneaux (le **conte**, ch. 5, la Doyenne à Autéquia)
Ancres : Hoopa, la Fiole (Vase Prison), le Pokédex « avarice » et « un château entier emporté » `CANON ROSA/XY ◐`. Le reste est `HYPOTHÈSE`.
1. “Il était une fois un génie / aux bras de fumée et d’or.”
2. “Il ouvrait des cercles dans l’air. / Ce qu’il voulait passait.”
3. “Il prit des fruits, puis des / maisons, puis un château entier.”
4. “Mais pour chaque chose venue, / une autre s’en allait.” (H1)
5. “Nos ancêtres eurent peur. / Ils enfermèrent sa force.”
6. “Dans une fiole, au sommet / de la tour du ciel.”
7. “Le génie redevint petit. / Il vola encore. Mais peu.” (H2)
8. “Et le dragon du ciel veilla / sur la fiole, sans dormir.” (Y1)
9. “Si la fiole s’éloigne du ciel, / le dragon descend la chercher.” (Y1)
10. “Et le dragon ne regarde pas / à qui sont les mains.” (Y1)

### 8.2 L'inscription du Sceau (la **loi**, ch. 9, sommet du Mont Mémoria ; copiée par Lance (Rocket))
1. “ICI REPOSE CE QUI FUT PRIS. / ICI ATTEND CE QUI FUT DONNÉ.”
2. “Le cercle relie deux rives. / Ce qui passe est rendu.” (H1)
3. “Le petit génie ouvre de petits / cercles. Sa force, les grands.” (H2)
4. “Seul le génie entier referme / le cercle, en rendant juste.” (H3)
5. “Brisée sans lui, la fiole lâche / une force sans maître.” (H3)
6. “Rendue au pilier, la fiole dort. / Rien ne passe. Rien ne revient.” (H4)
7. “Quand le ciel se déchire, / le gardien descend.” (Y1)
8. “Il n’écoute pas. Le chant des / gardiens le retient un temps.” (Y2)
9. “Le combattre gagne une heure. / Pas une réponse.” (Y3)
10. “Nous l’avons scellé par peur. / Que nos enfants fassent mieux.”

### 8.3 Les règles racontées trois fois (conte → loi → choix)
| Règle | Conte (ch. 5) | Loi (ch. 9) | Choix (ch. 13) |
|---|---|---|---|
| H1 échange | « une autre s'en allait » | « ce qui passe est rendu » | qui accepte de perdre quoi |
| H2 deux tailles | « il redevint petit » | « sa force, les grands » | rendre la force ou la garder captive |
| H3 fermer | — (les enfants ne l'apprennent pas) | « seul le génie entier » | Pacte ou Ciel ouvert |
| H4 dormir | « au sommet de la tour du ciel » | « la fiole dort » | Sceau |
| Y1 descente | « ne regarde pas à qui sont les mains » | « le gardien descend » | tenir le relais ou le Pilier |
| Y2 retard | — | « le chant le retient » | affecter la Doyenne et le rite |
| Y3 combat | — | « une heure, pas une réponse » | combattre pour évacuer |

### 8.4 Le parallèle des sceaux anciens (Bayar, ch. 5 ; fin cachée)
`CANON RSE ◐` : dans le Sanctuaire, le braille dit que les anciens ont vécu grâce aux Pokémon, puis les ont scellés **parce qu'ils les craignaient**. `HYPOTHÈSE` : les ancêtres du Peuple du Météore sont les mêmes « scelleurs ». Ils ont enfermé les Regis, puis, plus tard, la force du génie. **Le jeu montre un réflexe, pas un complot** : le Rempart d'aujourd'hui recommence. La fin cachée (Dossier complet + Chen avoue) révèle une tablette de Bayar : le premier sceau fut celui « des porteurs du monde » (ouverture vers Regigigas au postgame, `HYPOTHÈSE`).

### 8.5 Le Peuple du Météore (`CANON ROSA` : gardienne du savoir, Doyenne, lien avec Rayquaza et la Méga-Évolution ◐ ; le reste `HYPOTHÈSE`)
- **Mémoire orale.** On apprend le conte avant de lire ; la gardienne est celle qui sait le dire en entier.
- **Le ciel comme personne.** On ne prie pas Rayquaza : on lui « montre » (Amaryllis reprend le mot).
- **Le rite.** Un chant à plusieurs voix au Pilier ; il retarde, il ne commande pas (Y2).
- **La dette.** Chaque génération doit « faire mieux » que le sceau (inscription, ligne 10). La Doyenne lit cette ligne comme « garder mieux » ; Amaryllis comme « juger mieux ». C'est leur désaccord.
- **Deux clans de dragons.** Ébènelle (Peter, `CANON GSC`) garde les dragons comme une lignée ; le Peuple du Météore les garde comme un ciel. W1 met les deux face à face.

### 8.6 Passerelle (histoire, nœuds, contrats) — bible §3.1 et §5.3
- **Origine.** Le réseau PC Kanto–Hoenn–Rhode existe par la machine de Ciléo, le Rubis et le Saphir (`CANON RFVF`). Passerelle (`HYPOTHÈSE`) ajoute le transfert de matière, signé par Sylphe et Devon quatre mois après l'occupation.
- **Qui a fait quoi.** Léo : couche de transfert. Lanette : stockage. Ciléo : nœud Kanto (exclu ensuite du relais). Relais : Centre Spatial d'Algatia. Énergie : le « Cœur » de Sylphe (la Fiole). M. Rochard ne demande pas.
- **Nœuds et contrats.** Poivressel : Kanto, Johto · Mérouville : Kalos, Galar · Lavandia : Unys · Nénucrique : Sinnoh, Alola · Algatia : Paldea, plus la surcharge. Chaque contrat est un accord commercial avec une compagnie de la région (noms : brief C ou D, facultatif).
- **Ce que le monde en dit.** Affiches (« Le monde en une seconde »), Kiosque, prix bas à Poivressel, emplois à Mérouville. Personne ne parle d'énergie.

### 8.7 Règles de lore (contrôles pour tous les scénaristes)
| # | Règle |
|---|---|
| L1 | Toujours écrire « Pierre Rochard » en entier ; « Lance (Rocket) » pour Proton ; « Peter » pour le Maître dragon |
| L2 | Les noms d'anime ne sont pas utilisés (« Caroline », « Samuel », Max frère de Flora) |
| L3 | La Fiole n'est nommée « Fiole » qu'à partir du ch. 10 ; avant, c'est « le Cœur » |
| L4 | Personne ne connaît les espèces étrangères : on les décrit, Chen et Seko les nomment |
| L5 | Aucun personnage ne cite un événement de RSE comme passé (Groudon et Kyogre dorment) |
| L6 | Le passé Rocket de Koga reste une rumeur ; la création de Mewtwo par Fuji reste une allusion |
| L7 | La gardienne disparue est « disparue en mer », jamais un cadavre ; aucun chiffre de morts |
| L8 | Cramois'Île gronde ; elle n'entre pas en éruption |

---

## 9. Chronologie détaillée (cohérente avec bible §3.1)
| Date | Événement | Étiquette | Révélé |
|---|---|---|---|
| −50 ans | Chen et Agatha à Hoenn ; article de Chen sur « l'artefact du Pilier » | HYPOTHÈSE | ch. 9, 12 |
| −50 à −3 ans | le Peuple du Météore garde la Fiole ; une gardienne par génération | HYPOTHÈSE | ch. 5 |
| An −2 | Giovanni, lecteur de l'article, envoie Lance (Rocket) ; vol ; la gardienne disparaît en mer ; Amaryllis hérite d'Aster | HYPOTHÈSE | ch. 9 (lieu), 12 (auteur) |
| An −2 à 0 | la Fiole est étudiée en secret, puis cachée dans le coffre de Sylphe pendant l'occupation | HYPOTHÈSE | ch. 12 |
| An 0 | Red bat Giovanni, libère Sylphe (`CANON RFVF`), finit Sevii, relie les gemmes pour Ciléo | CANON | prologue |
| An 0 | Giovanni dissout la Rocket et disparaît (`CANON`) ; il passe à Hoenn incognito | CANON / HYPOTHÈSE | ch. 3 |
| An 0 + 1 mois | le Président trouve la Fiole, la cache à la police | HYPOTHÈSE | ch. 12 |
| An 0 + 2 mois | campagne Sylphe avec l'image de Red (affiche) ; Red cesse de parler | HYPOTHÈSE | ch. 1, 12 |
| An 0 + 4 mois | signature de Passerelle | HYPOTHÈSE | ch. 7 |
| An 0 + 5 mois | Lambda remplace l'ingénieur Ferrand | HYPOTHÈSE | ch. 10 (ch. 9 si libéré) |
| An 1 − 4 mois | Pierre (Brock) invité par Devon ; Aldo à Myokara ; Blue signé par Scott | HYPOTHÈSE | ch. 1–3 |
| An 1 − 3 mois | mise en service ; premiers anneaux à Poivressel ; ports fermés à Kanto ; Piko disparaît | HYPOTHÈSE | prologue |
| An 1 − 2 mois | Rocket achète l'horaire volé à Lambda ; primes du Rempart instituées par Norman | HYPOTHÈSE | ch. 4 |
| An 1 − 6 semaines | Amaryllis commence la surcharge ; Lambda vend l'horaire à Magma | HYPOTHÈSE | ch. 6, 12 |
| An 1 − 2 semaines | Hoopa Confiné arrive par un anneau | HYPOTHÈSE | ch. 8 |
| Jeu, ch. 0–14 | ≈ 6 à 8 semaines de jeu ; la Mission arrive au ch. 3 ; Fuji et Agatha au ch. 9 | HYPOTHÈSE | — |
| Après le jeu | départs canoniques (bible §12.4) | CANON (avenir) | postgame |
| An 3 | Red au Mont Argenté, Blue à Jadielle, Koga au Conseil 4, commandants libres à la Tour Radio | CANON GSC/HGSS | hors jeu |

---

## 10. Registre des promesses (plants et récoltes)
| ID | Promesse | Plant (ch., carte) | Rappel | Récolte |
|---|---|---|---|---|
| P01 | R1 la Rocket prédit | sbires avant l'anneau (1, R116) | carnet de primes (4) | prédicteur saisi (4, Tunnel) |
| P02 | R2 le réseau ouvre | carte de Brice (1–6) | journaux de Lanette (5, W9) | battement de Léo (7) + carte superposée (7) |
| P03 | R2b le voleur est Hoopa | petits anneaux (1) | fuite vers l'est (3–7) | piège de Koga (8) |
| P04 | R3 la loi d'échange | Piko (0), Lokhlass (3) | sources vides (6) | inscription (9) |
| P05 | R4 la chaîne | le Président esquive (1, 3) | homme au Persian (3, 6, 9) ; W7 | trois sources au Sommet (12) |
| P06 | la part de Red | affiche Sylphe (1) | Ciléo : « tu as porté le Rubis » (0, 10) | le Président et l'affiche (12) |
| P07 | Q2 l'avarice | conte : « un château entier » (5) | Hoopa vide une caisse (4) | F2 : il prend « le trésor de qui l'a enchaîné » |
| P08 | Q4 le ciel gronde | tempêtes de l'Institut (8) | vision de Morgane (8) | règle Y1 au Sommet (12) |
| P09 | Q5 le Cœur | « Cœur breveté » (1) | battement (7) | registre du coffre (10, 12) |
| P10 | Lambda | « Ferrand » fredonne (1, 4) | horaire signé « F. » (6) | même air chez le faux Giovanni (10) |
| P11 | Koga | paiement à « K. » (4) | Koga sait où frappera la Rocket (8) | W10 (10) |
| P12 | Chen | lettre de Chen (0) ; Agatha l'évite (3) | W7 (9) | aveu ou déni (12) |
| P13 | Lance au Pilier | « un pilier, par exemple » (4) | il copie l'inscription (9) | aveu sur la gardienne (12) |
| P14 | Giovanni rachète Devon | M. Rochard : « un acheteur anonyme » (1) | homme au Persian lit les cours (3) | le Président a vendu à Giovanni (12) |
| P15 | éclats rouges et bleus | Pierre Rochard (2) | Ciléo et le Rubis (3) | le relais résonne (10) |
| P16 | sceller par peur | braille de Bayar (5) | inscription ligne 10 (9) | fin cachée (P) |
| P17 | Petit-Pois | Timmy (4) | Vergazon (7) | Civils (13), Route Victoire (14) |
| P18 | Morgane ne rit pas | (3, 8) | (10) | elle rit à l'épilogue |
| P19 | les Lokhlass d'Olga | (3) | marché (9) | F4 : ils ramènent l'équipe de Red |
| P20 | Auguste et Mewtwo | « une fois suffit » (6) | Fuji (9) | postgame : Mewtwo et Fuji |

---

## 11. Qui gagne si X échoue (complété)
| Si … échoue | Qui gagne | Qui perd aussi |
|---|---|---|
| Rempart | Consortium et Rocket (marché) ; Mission (rapatrier) | Communautés natives |
| Consortium | Magma, Aqua, Gardiens (la Fiole peut partir) ; Rocket (recrute les ruinés) | Communautés (emplois), Ligue |
| Magma | Aqua (morale), Rempart (« la gestion a échoué, on abat ») | Auguste (son île) |
| Aqua | Rempart, Consortium (câble intact) | Hoopa |
| Mission Indigo | Rempart (Kanto coupable), Rocket (Kantonais bloqués à recruter) | Blue, Pierre (Brock) |
| Gardiens | Consortium (la Fiole reste) ou Amaryllis (le ciel juge) | Hoopa (F1 impossible) |
| Amaryllis | Consortium respire ; Gardiens perdent leur levier | Algatia y gagne aussi |
| Rocket | tout le monde ; Giovanni y gagne en dignité | — |
| Communautés | Rocket (`RK`), Rempart (vote xénophobe) | tout le monde à terme |
Aucune paire ne gagne dans toutes les lignes (vérifié : Consortium et Rocket gagnent ensemble sur « Rempart » mais s'opposent sur « Consortium »).

---

## 12. Contrôles

### 12.1 Avenir canonique (année 3) — respecté
Red Mont Argenté · Blue Jadielle · Giovanni caché, sans rien · 4 commandants libres (arrestation → évasion) · Koga Conseil 4, Jeannine Parmanie · Peter Maître · Agatha retraitée · Olga Île 4 · Pierre (Brock), Ondine, Major Bob, Erika, Morgane, Auguste : Champions (retour dans toutes les fins) · Pierre Rochard libre de partir à Kanto · Cramois'Île : présage seulement · Léo à Johto · Ciléo Île 1.

### 12.2 Kantonais : raison d'être à Hoenn et désaccord (critère d'acceptation)
| Perso | Raison concrète | Désaccord avec |
|---|---|---|
| Pierre (Brock) | invité par Devon, bloqué | Major Bob |
| Ondine | experte marine de la Mission | Aldo |
| Major Bob | logistique ; port de Carmin ruiné | Ondine, Erika |
| Erika | botaniste ; contrat secret | Flora, Major Bob |
| Koga | sécurité ; siège au Conseil 4 | Peter |
| Morgane | sentir les anneaux ; sa vision | Amaryllis |
| Auguste | consultant payé de Magma | Adriane, puis Max |
| Giovanni | exil ; rachats de Devon | ses commandants |
| Olga | Lokhlass braconnés et disparus | marchands, Peter |
| Aldo | entraînement, puis escorte | Ondine |
| Agatha | spectres de Lavanville | Chen |
| Peter | chef de la Mission ; la Rocket | Norman, Amaryllis |
| Chen | attaché scientifique ; être premier | Seko, Agatha |
| Blue | Scott, fuir Jadielle | Peter, Chen |
| Léo | ingénieur du Consortium | Président |
| Fuji | lettre d'Auguste ; la cage | Président |
| Ciléo | prouver son nœud | Lanette, Président |
| Président de Sylphe | coprésident du Consortium | M. Rochard |
| Ariane, Lambda, Lance, Amos | Fiole, primes, horaire, retour | entre eux (Amos ↔ Ariane ; Lambda trahit Ariane) et Giovanni |

### 12.3 Largeur du texte (preuve)
Méthode : script `pxw.py` (bac à sable, non suivi) : `charmap.txt` → octet → `gFontNormalLatinGlyphWidths` (`src/fonts.c`), apostrophe droite comptée comme ’, guillemets “ ” comptés. Toutes les répliques entre “ ” de ce document ont été extraites et mesurées. Résultat (2026-10-14) : **288 boîtes mesurées, 288 OK, 0 échec ; ligne la plus large : 200 px.** Trois boîtes utilisaient « » (absents de `charmap.txt`) : remplacés par ‘ ’. Règle : pas de « » dans les textes du jeu.

### 12.4 Défauts N1–N23 (revue narrative v2)
| N | Statut ici |
|---|---|
| N1 pourquoi Hoenn | ✔ crise transrégionale ; chaque Kantonais a sa raison (§12.2) |
| N2 rapport à RSE | ✔ règle 0 de la bible, L5 |
| N3–N4 cible Rocket | ✔ Fiole fixe au relais ; motif de Giovanni et d'Ariane |
| N5 Lambda | ✔ remplacement de Ferrand à An 0 + 5 mois ; alias neutre ; libération possible |
| N6 force de Red | ✔ prologue à pleine force (bible) ; Red « vendeur » malgré lui |
| N7 écarts canon | ✔ L1–L8 ; Peter Maître par intérim ; Amos prépare Johto |
| N8 révélations éventées | ✔ fausses pistes vraies (Magma déclenche, Koga paie la Rocket) |
| N9 moment unique | ✔ Sommet interrompu (bible) |
| N10 arc de Brice | ✔ vote selon `BV`, pas `BR` ; publication seule |
| N11 mutisme | ✔ choisi ; 5 gestes ; une phrase |
| N12 opinions dictées | ✔ tous les moteurs sont P, R ou É (§1.2) |
| N13 Rocket plate | ✔ Ariane a raison sur un point ; fractures internes |
| N14 option cachée | ✔ aucune position n'a d'issue gratuite (brief C vérifie) |
| N15 trop dur | ✔ L7 ; cruauté hors champ |
| N16 badges | ✔ accréditation (bible) ; répliques de Norman et Roxanne |
| N17 ch. 7 | ✔ W2, W3, W4, filature, aveu de Léo sur le trajet |
| N18 trop de texte | ✔ scènes de 8–15 boîtes ; saillance |
| N19 combat qui règle | ✔ Y3 ; personne ne résout le conflit |
| N20 bon chemin | ✔ échos : chaque fin coûte à chacun |
| N21 Red à un seul endroit | ✔ affectation annoncée par les répliques de veillée |
| N22 fins à deux variables | ✔ variantes par personnage (§3–5) |
| N23 données | ✔ IDs `C-xx` uniques ; noms à vérifier ◐ signalés |

### 12.5 Conflits et écarts avec la bible (à arbitrer par le GMD)
- **K-01 Auguste.** Bible §9.2 : « payer la reconstruction de Cramois'Île ». Or l'éruption est future (bible §3). Lecture adoptée : financer la **surveillance et l'évacuation**. Coût : aucun. Alternative : « reconstruire le Manoir », plus faible.
- **K-02 Bloqués avant la Mission.** Pierre (Brock) au ch. 1 et Aldo au ch. 2 précèdent le débarquement du ch. 3. Résolu (§4, deux vagues) sans changer la bible ; à inscrire au changelog.
- **K-03 « COMPRENDRE » en axe B** (Chen, Pierre (Brock)) : lu `CTL`. À confirmer.
- **K-04 Spectres de Lavanville au Mont Mémoria** : origine Kanto dans une zone Sinnoh/Alola (§5.3). Ce sont des esprits scénarisés, hors des tables de rencontre (brief D : à compter dans les 20 % de bruit ou à exclure).
- **K-05 F2 « Sylphe ruinée »** : Sylphe fonctionne en HGSS. Lecture : ruinée puis relevée avant l'année 3 ; une ligne d'épilogue le dit.
- **Ajouts proposés (non contradictoires, à valider) :** l'affiche Sylphe et la raison du silence de Red ; Ferrand ; Giovanni actionnaire de Devon ; Koga qui paie Lance ; la lettre d'Auguste à Fuji ; Erika et son contrat.

### 12.6 Checklists `GM_METHOD` §6.1 et §6.2 (narration)
- Intention et comportement : ✔ (lire les gens comme on lit un combat : observer → preuve → geste).
- Décisions identifiées : positions et relations déplaçables (§1.2, §1.5) ; aucune par menu.
- Économie : la confiance est une ressource en tension (plaire à l'un coûte ailleurs) ; puits = positions contradictoires (§7 de la bible, §11).
- Dominance : « plaire à tous » échoue (désaccords §12.2) ; « tout montrer à tous » coûte (Koga couvert ou démasqué, M5).
- Sens : 4 couches pour Red, Hoopa, Rayquaza, Brice-traducteur.
- Serrures narratives : questions avant réponses (§10).
- Texte : ✔ (§12.3). Faisabilité : assets vérifiés dans `CAST_DOSSIER` §5 ; états demandés ≈ 17 bits.
- Aucune affirmation « implémenté » ou « testé » : rien ne l'est.

---

## 13. Changelog
| Date | Version | Changement | Auteur |
|---|---|---|---|
| 2026-10-14 | 3.0 | Création (brief A) : 64 entrées `C-xx`, tables d'interface A→B/C, toile, voix, lore, chronologie, promesses, contrôles | GM spécialiste distribution |
