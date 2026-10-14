# REVIEW_V3_NARRATIVE — revue critique indépendante de la narration (*Pokémon Confluence* v3.1)

> Critique externe, non-auteur. Objet : défauts concrets, pas éloges. Documents lus : `GAME_DESIGN_BIBLE.md` v3.1 (intégral), `CHARACTER_AND_LORE.md` (§1, rang A complet, échantillons B/C, §8–§12), `reviews/ARBITRATION_V3.md` §6, `DECISION_LEDGER.md` (synthèse), `GAME_SYSTEMS.md` §4–§5 et §8–§11, `STORYCRAFT_RESEARCH.md` §7, `LORE_DOSSIER.md` §8, `CAST_DOSSIER.md` (contrôles canon).
> Barème : **BLOQUANT** = à corriger avant la tranche ch. 0–2 ou avant de scripter le climax ; **MAJEUR** = dégrade nettement l'expérience ou une exigence utilisateur ; **MINEUR** = cohérence, polish.
> Références : `Bible §x`, `SYS §x` (GAME_SYSTEMS), `CL §x` (CHARACTER_AND_LORE), `ARB §x`.

## A. Constats

### A1. Lois du mythe et mécanisme (ce que le joueur apprend doit tenir)

**N01 — BLOQUANT — F4 contredit la loi H3.** `SYS §10.4` (invariant : « Rayquaza la détruit avec le relais (F4) ») ; `Bible §5.2` H3 ; `CL §8.2` ligne 5.
- Problème : la loi enseignée au ch. 9 dit « Brisée sans lui, la fiole lâche une force sans maître ». Or en F4 la Fiole est détruite par Rayquaza, sans Hoopa, et le monde se **referme** proprement (« les anneaux se referment violemment »). Selon les règles du jeu, F4 devrait produire F5. Aucune règle Y ne dit ce que Rayquaza fait du pouvoir libéré.
- Impact : le joueur attentif, celui que le design récompense (« observer → hypothèse → vérifier »), constate que la loi gravée est fausse dans la fin la plus fréquente (46 %). La crédibilité du mythe s'effondre à l'endroit exact où elle doit payer.
- Correctif : ajouter **Y4** (ligne 11 de l'inscription, et une phrase du conte) : « Ce que le gardien détruit, il l'emporte au ciel ; rien ne revient, rien ne passe, et la tour reste vide. » F4 devient « le pouvoir est emporté par Rayquaza » : Hoopa est privé de sa force **pour toujours**. Cette perte claire et exclusive (Hoopa ne pourra jamais redevenir entier, même au postgame) le distingue de F1. Il faut l'énoncer **avant** le ch. 13 (Doyenne, ch. 12).

**N02 — BLOQUANT — Le Kiosque du ch. 3 révèle R2 quatre chapitres trop tôt.** `Bible §2.2`, `§11.4` (Kiosque), `§4.1` (R2 au ch. 7) ; `SYS §5` (« chaque commande : un anneau prend un objet »).
- Problème : le tutoriel de H1 montre en direct qu'**une commande Passerelle ouvre un anneau**. C'est exactement la conclusion R2, dont le mi-parcours (ch. 7) fait sa révélation, avec la carte de Brice, les journaux de Lanette et le battement. De plus, la croyance « de surface » listée en `§4.1` est déjà « le réseau kantonais […] ouvre les anneaux ». Le premier suspect est donc le coupable : R2 confirme au lieu de retourner.
- Impact : le mi-parcours tombe à plat. Le joueur sait depuis la ch. 3 ce que Brice « découvre » au ch. 7, et la scène qui définit Brice (la carte superposée) devient une formalité.
- Correctif (au choix) :
  - (a) **Délocaliser la perte.** Au ch. 3, la commande donne l'objet sans contrepartie visible ; ce qui est pris disparaît **ailleurs** (un PNJ du quai perd son Pokémon « à 14 h 10 »), et le joueur ne relie les deux faits que s'il note l'heure. La pièce « Reçu horodaté » rejoint le Dossier et devient l'indice 1 de R2.
  - (b) **Recadrer R2.** Assumer que « le réseau » est connu au ch. 3, et déplacer le retournement du mi-parcours sur ce qui est vraiment caché : « le réseau est alimenté par **quelqu'un** » (le battement). Q1 doit alors devenir « Qui ou quoi alimente Passerelle ? », et R1 doit innocenter **le réseau** (la Rocket prédit, Magma déclenche, donc « ce sont des humains ») pour que R2 retourne quelque chose.
  - Je recommande (a) + (b) : la fausse piste R1 devient « des humains ouvrent les anneaux », R2 répond « une machine, et une créature dedans ».

**N03 — MAJEUR — Le vol de l'an −2 est impossible selon les propres règles du jeu.** `Bible §3.1`, `§5.2` Y1 ; `CL §8.1` lignes 8–9 (« le dragon veilla sur la fiole, sans dormir » ; « si la fiole s'éloigne du ciel, le dragon descend la chercher »).
- Problème : la Fiole a quitté le Pilier il y a deux ans, et rien ne s'est produit. Le conte affirme pourtant que Rayquaza ne dort jamais et qu'il descend si la Fiole s'éloigne. Lance (Rocket), un commandant de terrain, l'a volée au sommet du Pilier, sous le gardien, puis a échappé à la gardienne du Peuple du Météore. Canon : Rayquaza **dort** au sommet du Pilier, et vit dans la couche d'ozone en ROSA.
- Impact : c'est la première question qu'un joueur pose au ch. 9 (« alors pourquoi il n'est pas venu ? »), et rien n'y répond.
- Correctif : en faire un indice au lieu d'un trou. Le conte est **faux sur un point**, et c'est voulu : Rayquaza ne garde pas la Fiole, il garde **le ciel**. Il ne descend que si le ciel se déchire (Y1, pression). Le vol a eu lieu **pendant la saison où Rayquaza est dans la couche d'ozone** (ancrage ROSA). La Doyenne le sait et l'a caché, par honte. Le joueur peut contredire le conte avec l'inscription (`montrer`) : c'est une micro-révélation au ch. 9, et elle nourrit le thème « sceller par peur » (les anciens ont menti aux enfants pour qu'ils gardent la tour).

**N04 — MAJEUR — Comment Sylphe a-t-elle su que la Fiole était une source d'énergie ?** `Bible §3.1` (An 0 : « le Président trouve la Fiole et la cache ») ; `CL §9` (« An −2 à 0 : la Fiole est étudiée en secret »).
- Problème : un artefact inconnu, trouvé dans un coffre à An 0 + 1 mois, devient en trois mois la source d'un réseau de transfert de matière entre six régions (signature à + 4 mois). Personne ne dit qui l'a étudiée, ni comment on a compris qu'elle ouvre des anneaux. Les deux chronologies divergent d'ailleurs : la bible place la découverte « An 0 », CL « An 0 + 1 mois », et la campagne d'affiches (+ 2 mois) vante « Sylphe relie le monde » **avant** la signature de Passerelle (+ 4 mois).
- Impact : le maillon central de la chaîne R4 repose sur un saut technique. Le joueur adulte le remarque au Sommet, et la question « qui savait ? » perd son tranchant.
- Correctif : la Rocket a fait étudier la Fiole **par des chercheurs de Sylphe** pendant l'occupation (c'était le but de l'occupation, avec la Master Ball). Les notes de recherche sont restées dans le coffre. Le Président a **hérité d'un dossier**, pas d'un caillou. Cela lie Sylphe à la Rocket sans en faire des complices, rend Léo plus coupable (il a lu les notes) et fournit la pièce « Notes de l'occupation ». Il faut aussi aligner les dates et placer l'affiche **après** la signature (+ 5 mois).

**N05 — MAJEUR — L'autre rive des anneaux n'existe pas.** `Bible §5.1` (« ils emportent ce qui se trouve de ce côté-ci »), `§5.2` H1.
- Problème : la loi d'échange implique que des natifs de Hoenn tombent **à Kanto, à Kalos, à Paldea** depuis trois mois. Personne n'en parle. Kanto devrait vivre la crise symétrique : des Zigzaton dans la Forêt de Jade, des Pokémon de Kanto disparus. Hoenn accuse pourtant Kanto, et la Mission arrive pour « laver son nom », comme si Kanto ne souffrait pas.
- Impact : c'est un trou de cohérence du monde. Surtout, c'est l'**occasion manquée** la plus coûteuse du document, car la symétrie est le cœur du thème « tout échange a un prix ».
- Correctif : la Mission Indigo arrive **avec des preuves de l'autre rive** : des photos de natifs de Hoenn à Kanto, et la liste des Lokhlass d'Olga apparus près d'Algatia. C'est le vrai motif de Peter (« vos anneaux nous volent aussi »), et cela rend son SE DÉFEND crédible. Au ch. 3, cette pièce devient l'indice 2 de R3 (H1), donc **avant** le Mont Mémoria. En épilogue, chaque fin a une ligne sur Kanto.

**N06 — MAJEUR — Les espèces de Hisui supposent un voyage dans le temps qu'aucune règle n'énonce.** `Bible §5.2` P2 (« espèces et formes de Hisui (Sinnoh ancien) »).
- Problème : les anneaux de Hoopa sont **spatiaux** (canon). Les Paradoxes de la Zone Zéro et les Ultra-Chimères existent **dans le présent** ; les formes de Hisui, non. P2 introduit un franchissement du temps sans loi (contre la 1re loi de Sanderson, que la bible invoque).
- Correctif : soit retirer Hisui de P2 et le faire obtenir par d'autres canaux (cadeaux, échanges, postgame avec un anneau « au-delà du temps » qui s'annonce comme une anomalie), soit poser une loi **H5** dans la vision de Morgane au ch. 8 (« là où le ciel est mince, l'anneau traverse aussi les années »). Il faut alors en faire un signe d'escalade explicite.

**N07 — MINEUR — Hoopa arrive « attiré par son pouvoir » seulement deux semaines avant le jeu.** `Bible §3.1`.
- Problème : où était Hoopa Confiné pendant des siècles, et pourquoi le pouvoir ne l'attirait-il pas au Pilier ?
- Correctif : une phrase de la Doyenne (le sceau « cache » la force ; c'est le réseau qui la fait « chanter »). Lévy et Tatia entendent ce chant au ch. 10. Ce motif existe déjà, il suffit de le brancher.

