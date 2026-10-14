# NARRATIVE_DIRECTIONS (brief v2) — Exploration et choix

> **Auteur :** Game Mechanics Director — 2026-10-14. Remplace la version « Heure suspendue » (archivée dans `archive/heure_suspendue/`).
> **Entrées :** brief v2 (définition d'agent, section « Project constraints »), `LORE_DOSSIER.md` §8 (étiquettes respectées), `TECHNICAL_AUDIT.md`, `ASSET_INVENTORY.md`, `AI_AUDIT.md`, leçons des revues archivées (chaîne de portes vanilla, donneurs de CS, plafonds sur jalons d'histoire, soins, budget d'ID dresseurs).
> **Résultat :** direction **A « Cendres »** retenue (greffes de B et C). Titre : ***Pokémon Cendres***.

---

## 0. Ce que le brief v2 change et comment on évalue

Le brief v2 change quatre choses par rapport à l'intention initiale (`EXPERIENCE_INTENT.md` §0, mis à jour) :
1. **Le joueur incarne Red**, ancien Maître de Kanto, en terre étrangère. Il est expérimenté, et le design doit pourtant garder des combats qui comptent. Le thème qui en découle naturellement : **les limites de la force**.
2. **Brice** (fils du Prof. Seko) et la distribution de Hoenn sont des **acteurs**, pas des figurants.
3. **≥ 101 décisions significatives**, observables, consignées (`DECISION_LEDGER.md`), avec des systèmes cachés sélectifs et **plusieurs fins**.
4. **Maturité** : des intérêts légitimes en conflit, des compromis, des conséquences ; pas de morale assénée.

### Grille v2 (EXPERIENCE_INTENT §9.2 mise à jour)

Deux critères s'ajoutent : **C11 Profondeur des décisions et des conséquences** et **C12 Justification de Kanto à Hoenn**. Les poids sont rééquilibrés (total 100). La note va de 0 à 5 ; score = Σ(note × poids) / 5.

| # | Critère | Poids |
|---|---|---|
| C1 | Originalité | 8 |
| C2 | Potentiel de mystère / d'enquête | 8 |
| C3 | Force émotionnelle (vécue en jeu) | 9 |
| C4 | Profondeur des antagonistes / intérêts opposés | 9 |
| C5 | Cohérence du monde | 7 |
| C6 | Usage intelligent du lore | 8 |
| C7 | Adéquation moteur / assets / chaîne de portes | 8 |
| C8 | Exploitation ludique de l'histoire | 12 |
| C9 | Rythme des révélations | 7 |
| C10 | Faisabilité réelle (budget Claude Pro, petite équipe d'agents) | 8 |
| **C11** | **Profondeur des décisions / conséquences (≥ 101, systèmes cachés, fins)** | **10** |
| **C12** | **Justification de Kanto à Hoenn (canon, cadre temporel)** | **6** |

Portes éliminatoires (inchangées + une nouvelle) : E1 faisabilité moteur ; E2 cartes Hoenn seulement ; E3 intouchables ; E4 décisions joueur préservées ; E5 texte FR GBA ; **E6 l'avenir canonique de Red, Blue et Giovanni reste possible** (Red au Mont Argenté en année 3, Blue Champion de Jadielle, Giovanni vivant et sans Mewtwo).

---

## 1. Direction A — « Cendres » (les réfugiés de Cramois'Île)

**Cadre temporel :** **B, « année 1 »** `[INTERPRÉTATION]` : un an après RBJ/RFVF. Red a quitté son titre ; Blue l'a détenu quelques minutes ; la Team Rocket est décapitée mais active (§8.3) ; l'éruption de **Cramois'Île** `[CANON-JEU : GSC, placée entre l'année 0 et l'année 3 ◐]` vient d'avoir lieu.

**Pourquoi Red est à Hoenn :** Red était à Cramois'Île quand le volcan s'est réveillé. Il a aidé à l'évacuation et il a embarqué sur l'**Océane** `[CANON-JEU : RFVF ◐, croisière internationale]`, réquisitionnée pour transporter 300 réfugiés vers Hoenn, seule région à avoir accepté de les accueillir (Devon SA y voit de la main-d'œuvre pour un chantier). Le jeu **commence en pleine nuit, dans un canot de sauvetage**, au large de la Route 104.

**Conflit central :** le **Mont Chimnée** montre des signes de réveil. Après Cramois'Île, personne ne veut attendre. La **Coopérative Magma** (Max, géologue, vulcanologues de Vermilava) propose le **Projet Soupape** : forer pour « dégazer » le volcan, financé par Devon, avec la main-d'œuvre réfugiée. Les **pêcheurs d'Aqua** (Arthur) s'y opposent : l'eau chaude rejetée au fond marin tue les récifs dont ils vivent, et les réfugiés pêchent sur leurs zones. Les **réfugiés** (menés par Auguste) veulent du travail, un toit, et récupérer leurs Pokémon placés en quarantaine dans l'**Arche** de Devon. Les **autorités** (Ligue de Hoenn, Devon) veulent l'ordre et le chantier. La **Team Rocket** (Ariane, Lambda) infiltre le chantier : elle veut voler l'Arche — des centaines de Pokémon rares de Kanto — en provoquant une évacuation. Personne n'a entièrement tort.

**Factions :** Réfugiés de Cramois'Île · Coopérative Magma · Pêcheurs d'Aqua · Autorités (Ligue + Devon) · Team Rocket (cachée jusqu'à l'acte I).

**Rôle de Brice :** fils de Seko, chargé par son père de **recenser les Pokémon étrangers** arrivés avec les réfugiés (ce qui justifie les espèces de toutes générations, LORE §8.7 rang 2). Il est la **voix** de Red (Red est muet `[CANON-JEU]`) et le lien de Hoenn : beaucoup de négociations passent par lui, et il peut agir seul, dans un sens ou dans l'autre, selon la confiance qu'il accorde à Red.

**Limites de la force :** l'équipe légendaire de Red est restée dans les PC de Kanto (le lien PC Kanto–Hoenn est coupé depuis l'éruption, qui a endommagé un relais) ; son Pikachu est blessé dans le naufrage. Red repart d'un starter de Hoenn. Surtout, les problèmes centraux (volcan, accueil, mer) **ne se règlent pas en combat**.

**Architecture des décisions :** ~110 décisions réparties en enquêtes (qui vole les Pokémon ?), arbitrages (quai, données, témoignages), négociations (Conseil d'Atalanopolis : trois motions votées selon les alliances et les preuves), choix de présence (le climax oblige à choisir **où** être), choix discrets (soigner, décliner un combat, lire une lettre). Systèmes : affinité avec 5 personnages, réputation de 4 factions, 4 états du monde.

**Fins :** cinq fins selon l'issue du volcan (maîtrisé / éruption limitée / éruption majeure) et le sort des réfugiés (intégration / relogement / exode), avec des variantes Rocket, Brice et notoriété. Red part toujours vers le nord à la fin (Mont Argenté, E6).

**Points forts :** pertinence adulte (catastrophe, accueil, ressources) sans villain caricatural ; justification canonique très solide (Cramois'Île, Océane, Rocket, lien PC) ; utilise les cartes « Magma/Aqua » existantes pour des factions réinventées ; chaque grande décision s'exprime en flags/vars/branches.
**Risques :** mystère moins fort qu'un thriller ; thème politique à doser pour un public Pokémon ; volume de dialogues de PNJ.

## 2. Direction B — « La Machine qui écoute » (le réseau)

**Cadre temporel :** **A, « année 0+ »** : la machine de Ciléo vient de relier Kanto, Hoenn et Rhode `[CANON-JEU : RFVF ✔]`.
**Pourquoi Red est à Hoenn :** Ciléo l'envoie accompagner l'installation du **relais hoennien** (Centre Spatial d'Algatia, avec Lanette). Le Rubis et le Saphir résonnent avec les Gemmes Rouge et Bleue du Mont Mémoria `[HYPOTHÈSE, LORE §8.4.1]`.
**Conflit :** le relais provoque des anomalies (séismes, marées) ; Devon et Sylphe se disputent le monopole des transferts ; la Team Rocket veut détourner le réseau pour **siphonner les PC** de deux régions.
**Factions :** Devon · Sylphe SARL · Ligue · Rocket · Gardiens du Mont Mémoria.
**Brice :** technicien de terrain du relais pour Lanette.
**Décisions :** ouvrir/fermer/contrôler le réseau, qui détient les Gemmes, vie privée des dresseurs.
**Fins :** réseau ouvert, coupé, monopolisé ou piraté.
**Points forts :** pont Kanto–Hoenn le plus canonique ; thème contemporain (infrastructure, données).
**Risques :** abstrait (on « voit » mal un réseau sur GBA), climax technologique peu jouable, Red en âge de 11 ans (cadre A) ; émotion faible.

## 3. Direction C — « Les Héritiers » (Giovanni en exil)

**Cadre temporel :** **B, « année 2 »**.
**Pourquoi Red est à Hoenn :** il traque **Giovanni**, qui s'entraîne incognito à Hoenn `[CANON-JEU : RFVF, « s'entraîner » ✔]` pendant que ses commandants préparent son retour.
**Conflit :** Lambda (maître du déguisement `[CANON-JEU : HGSS]`) infiltre Magma et Aqua pour attiser leur rivalité et voler un « cadeau » pour Giovanni ; Red découvre que Giovanni, ici, est un homme fatigué qui hésite à revenir.
**Factions :** Rocket (deux lignes : retour du chef / dissolution) · Magma · Aqua · Ligue.
**Brice :** l'enquêteur local, qui doute de la croisade de Red.
**Décisions :** démasquer ou utiliser les infiltrés, livrer ou laisser partir Giovanni.
**Fins :** Giovanni revient (prépare GSC), Giovanni disparaît, Rocket scindée.
**Points forts :** excellent mystère (qui est déguisé ?), face-à-face Red–Giovanni mémorable.
**Risques :** histoire centrée sur Kanto (Hoenn devient décor), « équipe maléfique veut un cadeau légendaire » proche du cliché, Giovanni contraint par le canon (E6).

## 4. Portes et notation

| Porte | A | B | C |
|---|---|---|---|
| E1 moteur | ✔ | ✔ | ✔ |
| E2 cartes Hoenn | ✔ | ✔ | ✔ |
| E3 intouchables | ✔ | ✔ | ✔ |
| E4 décisions préservées | ✔ | ◐ (climax technique) | ✔ |
| E5 texte | ✔ | ✔ | ✔ |
| E6 avenir canonique | ✔ | ✔ | ◐ (Giovanni contraint) |

| Critère (poids) | A | B | C |
|---|---|---|---|
| C1 Originalité (8) | 4 | 4 | 3 |
| C2 Mystère (8) | 3 | 4 | 5 |
| C3 Émotion (9) | 5 | 3 | 3 |
| C4 Intérêts opposés (9) | 4 | 3 | 4 |
| C5 Monde (7) | 5 | 4 | 4 |
| C6 Lore (8) | 4 | 5 | 4 |
| C7 Moteur/assets (8) | 5 | 3 | 4 |
| C8 Exploitation ludique (12) | 5 | 4 | 3 |
| C9 Rythme (7) | 4 | 4 | 4 |
| C10 Faisabilité (8) | 4 | 3 | 4 |
| C11 Décisions (10) | 5 | 4 | 3 |
| C12 Kanto (6) | 5 | 5 | 4 |
| **Total /100** | **88,8** | **76,0** | **73,8** |

Tests transversaux (§9.4) : A passe « sans texte » (camp, cendres, quai bloqué, chantier visibles), « joueur qui saute l'histoire » (les décisions restent des actions de jeu : présence, combat décliné, objet donné) et « ironie » (le joueur le plus fort du monde ne peut pas tout régler : c'est voulu et lisible). B échoue partiellement au test « sans texte ». C échoue au test « Hoenn n'est pas un décor ».

## 5. Choix : A « Cendres », avec greffes

| Greffe | Origine | Intégration |
|---|---|---|
| Lien PC Kanto–Hoenn coupé ; Lanette et Ciléo ; équipe de Red bloquée à Kanto | B | enjeu personnel de Red ; décision « réseau » en acte III ; conséquence différée au postgame (l'équipe classique de Red revient ou non) |
| Lambda déguisé, fuite chez Devon, enquête « qui vole les Pokémon ? » | C | colonne vertébrale du mystère (acte I à III) ; Lambda se fait passer pour un ingénieur de Devon |
| Giovanni | C | **absent physiquement** ; une lettre d'Ariane le mentionne ; un épilogue Rocket varie selon les choix (E6 respecté) |

**Pourquoi A :** c'est la seule direction où la thèse « les limites de la force » est **mécanique** (l'équipe ne peut pas résoudre le volcan ni l'accueil) et où chaque grande décision a un effet visible sur des **lieux** de Hoenn (Vermilava, Poivressel, Pacifiville, récifs). Les factions Magma/Aqua, réinventées en mouvements légitimes, réutilisent toutes les cartes et tous les sprites existants.

**Titre : *Pokémon Cendres*** (en-tête ROM : `CENDRES`).
**Identité :** *L'ancien Maître de Kanto arrive à Hoenn dans un canot de sauvetage. Ici, sa force ne suffit pas.*

La suite est dans `GAME_DESIGN_BIBLE.md`.
