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

### A2. Motifs, logique des acteurs, canon

**N08 — BLOQUANT (canon) — Giovanni avoue publiquement le vol au Sommet.** `CL C-06` (« Sommet, `GI` haut : “Oui, j'ai ordonné ce vol.” ») ; `SYS §9.2` (3e source de R4) ; `Bible §3` (« Giovanni reste caché, n'obtient rien »).
- Problème : Giovanni avouerait un crime devant le Maître de Hoenn, Peter (qui traque la Rocket [c GSC]), la Ligue et le Rempart. Ensuite, il repart libre et caché. C'est incompatible avec son caractère (orgueil, contrôle, « je n'ordonne plus ») et avec l'avenir canonique.
- Impact : la scène la plus forte du noyau devient invraisemblable, et c'est elle qui débloque le vote de Juan.
- Correctif : Giovanni **ne vient pas**. Si `GI` est haut, il remet à Red, sur le toit (ch. 9) ou au Centre Spatial (ch. 10), une **pièce** : l'ordre de mission signé, ou le reçu du coffre. Red la **montre** au Sommet. Giovanni témoigne par un objet, Red porte la parole : c'est plus fort pour le thème « parler pour quelqu'un », cohérent avec le canon, et cela donne à Red un acte décisif (voir N13).

**N09 — MAJEUR — La part de Red dans la chaîne est artificielle.** `Bible §4.1` (Noyau : « les victoires de Red ont livré la Fiole à Sylphe ») ; `CL P06` ; `ARB §6` Q7.
- Problème : Red a **empêché** la Rocket de garder la Fiole en libérant Sylphe, et il a branché les gemmes à la demande de Ciléo. Ce sont des liens de causalité sans choix moral. Quant à l'affiche, Sylphe l'a faite **à sa place**. La phrase-concept « il découvre qui a payé pour ses victoires » promet une compromission que le texte ne montre pas.
- Impact : R4 dit au joueur « tu en fais partie », mais il ne peut pas le ressentir : rien de ce que Red a choisi n'y conduit. C'est le piège STORYCRAFT §7 n° 8 (le moralisme) déguisé en culpabilité.
- Correctif : donner à Red **une vraie contrepartie acceptée**, ancrée dans le canon. Le Président de Sylphe lui a remis la **Master Ball** [c RBJ/RFVF], sortie **du même coffre**, le jour où il a gardé la Fiole. L'image de l'affiche a été cédée contre ce cadeau, par un contrat que Red a signé sans lire, à 11 ans. Le Carnet : “Une Ball pour mon visage. / Il a gardé le reste.” Option discrète : Red peut **donner** la Master Ball au Sommet (D107 bis), un geste coûteux et lisible.

**N10 — MAJEUR — Amaryllis sait tout et se tait, sans raison écrite ; ses moyens ne sont pas expliqués.** `CL C-05` (« elle sent la Fiole tirer le ciel depuis Algatia ») ; `Bible §3.1` (« achats massifs par prête-noms »).
- Problème 1 : si elle sait que la Fiole est au relais, il suffit de le dire à la Doyenne et aux Sages, qui la réclament, pour faire tomber le noyau du mystère. Problème 2 : une nomade du Site Météore n'a pas les moyens d'acheter des transferts en masse depuis six semaines.
- Impact : c'est un trou de motif chez l'antagoniste « croyante » qui doit porter la maturité du récit.
- Correctif : elle **l'a dit**. La Doyenne a choisi d'attendre, parce que M. Rochard finance discrètement le Peuple du Météore (bourses, réfection du Site) et a promis de « rendre le Cœur à la fin du contrat ». Les Gardiens deviennent un maillon de la chaîne, ce qui donne à R4 un sixième maillon que le joueur n'attend pas. Les prête-noms d'Amaryllis sont **les fidèles du Peuple**, qui vendent leurs Méga-Gemmes pour payer : la pièce « Gemme vendue » se trouve au marché de Nénucrique au ch. 9.

**N11 — MAJEUR — Accréditer Red au ch. 0 n'a aucun sens pour Norman.** `Bible §8.3` ch. 0 (« accréditation par téléphone avec Norman »).
- Problème : le chef du Rempart, hostile à Kanto, accrédite par téléphone, la nuit même, un clandestin kantonais.
- Correctif : en faire une **laisse** : « Tu travailles sous accréditation, ou tu repars en cale. » Norman veut un dresseur fort contre les hordes, et un Kantonais qu'il peut expulser à tout moment. Cela donne une raison au plafond par jalons (bible §2.2) et une menace réelle pendant tout l'acte I.

**N12 — MAJEUR — La Rocket reste un méchant de service, sans point de vue défendable.** `Bible §7` (« aucun diagnostic juste : c'est la faction égoïste lisible ») ; `§13` invariant 3.
- Problème : l'utilisateur exige « aucun méchant auto-déclaré » et des motifs crédibles. Lance (Rocket) est défini comme « cruel » ; Amos est un rang C sans scène propre ; Ariane a une seule « réplique juste ». La faction qui attaque deux fois le relais est la moins écrite du jeu.
- Correctif : incarner le recrutement des ruinés (`RK`) dans **un** visage récurrent. Un pêcheur de Myokara (ch. 2, filets crevés) réapparaît en sbire au Tunnel (ch. 4), puis à l'assaut du ch. 10. Selon `rP`, il reste ou repart. Donner à Ariane un diagnostic juste (« la Ligue abat, Devon licencie, nous on paie ») et à Lance (Rocket) un motif concret (il garde l'argent des primes pour lui : c'est le coin que Lambda enfonce). Ne plus écrire « cruel » comme fonction.

**N13 — MAJEUR — L'agence de Red est sous-traitée au climax politique.** `SYS §9.4` (une bascule par motion, soumise à `BR` ≥ 50 ou `N` ≥ 2), `§5` (« défendue ≠ résultat dans 48 % / 47 % / 27 % ») ; `CL C-01` (la phrase publique est choisie **selon l'état**).
- Problème : au moment fort de la négociation, Red montre une pièce et désigne un votant, trois fois. Son seul acte expressif, la phrase écrite, est **choisi par le système**. Brice publie seul, vote seul, et Flora désobéit seule. Ces choix sont tous bons isolément, mais leur cumul fait de Red un spectateur du Sommet.
- Impact : avec F4 en repli dans 46 % des cas, le joueur conclut que ses actes ne changent rien. C'est l'inverse de la thèse.
- Correctif :
  - (1) **La veille du Sommet, les couloirs** : Red rend visite à 3 délégués sur 9 (choix exclusifs). Il y **donne**, **montre** ou **reste**, et verrouille ou déverrouille un vote. C'est de la négociation réelle, par gestes, sans menu.
  - (2) La phrase publique est **choisie par le joueur** parmi 2 ou 3 phrases débloquées, ou tue (le silence est une option enregistrée).
  - (3) Une pièce « décisive » (l'ordre de Giovanni, N08) donne une bascule supplémentaire.

**N14 — MINEUR — Pourquoi Brice vote-t-il au Sommet ?** `SYS §9.2` (BRI).
- Problème : un adolescent recenseur siège parmi neuf chefs de faction.
- Correctif : Seko lui **cède son siège** s'il est ÉCOUTE (l'arc de Seko gagne un acte). Sinon, Seko vote, et Brice ne peut que parler (copie COM). L'émergence `BV` est conservée.

**N15 — MINEUR — Faute de Chen trop légère, âge discutable.** `CL C-09`.
- Problème : un article de jeunesse qui mentionne un artefact au sommet d'une tour connue n'est pas une faute assez lourde pour porter la fin cachée. De plus, « j'avais vingt ans » il y a 50 ans donne à Chen 70 ans.
- Correctif : Chen a **publié le relevé du sceau** (la méthode pour l'ouvrir), qu'il avait recopié malgré Agatha. Il faut ramener l'épisode à environ 35–40 ans.

**N16 — MINEUR — Possible théorie de fans.** `CL C-55` (« Capucine liée à Morgane »).
- Problème : aucun lien canon n'existe entre les deux. La règle de la bible (§3, « aucune théorie de fans ») s'applique.
- Correctif : étiqueter le lien `HYPOTHÈSE` (deux psychiques qui correspondent), sans parenté.

### A3. Distribution chorale : figurants déguisés et surcharge

**N17 — MAJEUR — Une douzaine de « rangs B » sont des figurants selon la définition même de la bible.** `Bible §9` (rang B = ≥ 4 pulsations) et `§9.3` ; `CL C-37…C-46` ; `SYS §9.2`.
- Problème : les quatre pulsations de Bastien, Voltère, Adriane, Alizée et Roxanne sont regroupées dans **le chapitre de leur ville** : P, É et B le même jour. La quatrième est « ch. 12 vote ». Or **aucun** d'eux ne vote au Sommet (`SYS §9.2` : 9 votants, aucun Champion de Hoenn). Cette pulsation est fantôme. Juan a 2 scènes dans la bible et préside pourtant le Sommet. Le Conseil 4 de Hoenn n'a qu'une scène avant la Ligue, sauf Aragon. Aldo (« un adversaire digne ») et Jeannine n'ont aucun enjeu qui se déplace.
- Impact : cela viole l'invariant 13 et l'exigence explicite de l'utilisateur (« none as extras »). En jeu, le joueur les quitte en partant de leur ville, et ne les revoit qu'en diaporama.
- Correctif : brancher chaque Champion de Hoenn sur une **fonction de fin de partie** existante.
  - **Voltère** devient le porte-parole COM : le votant anonyme « Communautés » prend un visage, et il porte sa trahison (son second contrat Passerelle).
  - **Bastien** devient le secouriste de Fondmer au ch. 11, à la place du soigneur de repli.
  - **Adriane** est l'alliée « Civils » à Vermilava, qui est un lieu de civils possible.
  - **Alizée** vole la Fiole jusqu'au Pilier si la Doyenne n'a pas d'oiseau. Cela répare aussi N19 (rite impossible).
  - **Roxanne** devient l'experte assermentée de M3, et lit la carte de Brice au Sommet.
  - **Juan** obtient une scène au ch. 9 (jury du Concours, où il refuse le cadeau du Président). Cette scène existe dans CL, mais la bible l'ignore.
  - Mettre à jour `Bible §9.3`, qui dit encore « ch. 12, E ».

**N18 — MAJEUR — 64 entrées pour 3 500–4 500 boîtes : le compte ne tient pas.** `ARB §6` Q6 ; `Bible §14` (texte).
- Estimation : rang A, 11 × 6 scènes × 10 boîtes ≈ 660 ; rang B, 37 × 4 × 9 ≈ 1 330 ; rang C, 16 × 3 × 7 ≈ 340 ; crises de ville et scènes de témoin ≈ 600 ; Sommet, veillée et climax (3 lieux × 5 issues) ≈ 450 ; épilogue (10 plans × 3 variantes, plus 5 scènes jouables) ≈ 400 ; saillance (≈ 5 répliques × 48) ≈ 500 ; dresseurs-témoins, panneaux, Carnet ≈ 600. Total : **≈ 4 900 boîtes**, au-dessus du plafond avant même les combats, les tutoriels et le postgame.
- Coupes et fusions proposées, sans perdre de personnage exigé par l'utilisateur :

  | Action | Personnages | Gain estimé |
  |---|---|---|
  | **Fusion** | Kelvin + Courtney en un seul admin Magma (Courtney garde l'excès) ; Matthieu absorbé dans Sarah | ≈ 60 boîtes |
  | **Fusion** | Ciléo + Lanette pour la fonction « témoin technique » : Lanette porte les journaux **et** la vision du cœur au ch. 10 ; Ciléo garde le prologue et le registre | ≈ 50 |
  | **Réduction** | Amos à des lettres seulement ; Nina à une seule scène (ch. 9) et une lettre ; Capucine et les Têtes de la Zone sortent du décompte (postgame pur) | ≈ 90 |
  | **Fusion** | Sages d'Atalanopolis + Marc : Marc parle pour les Sages | ≈ 40 |
  | **Gel** | aucun nouveau nom propre de PNJ (Ferrand reste, et c'est le dernier) | — |
  | **Règle** | rang C = 2 scènes **ou** 1 scène + 1 écho, pas les deux | ≈ 100 |

  Cible : ≈ 4 300 boîtes, avec une marge pour la tranche ch. 0–2. Si cette tranche dépasse son budget de plus de 15 %, couper d'abord les scènes de témoin facultatives de l'acte I, jamais les crises de ville.

**N19 — MAJEUR — Les personnages qui décident la fin sont au rang C.** `CL §6` (Doyenne C-61, Lanette C-57) ; `SYS §10.2–10.4`.
- Problème : la Doyenne conditionne le rite, donc F1. Elle vote au Sommet et raconte le conte, et elle n'a que 2 scènes et un écho. Sa disponibilité (`S(rG)` ≥ +3) dépend d'une faction marginale que la plupart des joueurs ne travaillent pas. C'est la cause principale de « SCEAU échoue → F4 » (témoins F4 × INTÉGRATION, MARCHÉ et REMPART dans `SYS §11`). Lanette fournit l'indice 2 de R2 et une réplique de veillée décisive, mais reste au rang C.
- Correctif : la Doyenne passe au rang B, avec une scène au ch. 9 au Mont Mémoria (elle lit l'inscription et ment sur la ligne « veilla sans dormir », voir N03) et une au ch. 12. Lanette passe au rang B, à la place de Ciléo (N18).

### A4. Révélations, rythme, équité

**N20 — MAJEUR — R4 est une révélation-exposé, pas un retournement.** `Bible §4.1` (« recontextualise au moins cinq scènes ») ; `§4.3` R4.
- Problème : sur les cinq scènes listées, « Cimetronelle : Hoopa fuit vers l'est » est recontextualisé par R2b, pas par R4. « L'homme au Persian » est un Giovanni que tout joueur reconnaît dès le ch. 3, donc de l'ironie dramatique, pas une révélation. « Les étoiles d'Amaryllis » relève de R2. R4 recontextualise réellement **deux** scènes (le prologue de Ciléo et le « Cœur breveté »). De plus, R4 se livre **en séance**, par des documents montrés, puis on vote aussitôt : c'est le piège STORYCRAFT §7 n° 1 (pavé d'exposition) au pire moment.
- Correctif :
  - (1) Ajouter au noyau un maillon que le joueur **n'a pas soupçonné** et qui retourne au moins trois scènes : les Gardiens et l'argent de Devon (N10) retournent le conte du ch. 5, la patience de la Doyenne et la colère d'Amaryllis ; la Master Ball (N09) retourne le prologue, l'affiche et la remise de la Ball, en flash-back au Carnet.
  - (2) Livrer R4 **avant** la séance, la nuit des couloirs (N13), en trois scènes courtes (Président, Doyenne, Ciléo). Le Sommet devient le lieu où l'on **agit** sur ce qu'on sait.

**N21 — MINEUR — Le ch. 12 ferme tout d'un coup.** `Bible §4.2` (« 12 : tout est fermé ») contre STORYCRAFT §7 n° 18 (« 1 ouverte, 1 fermée »).
- Problème : le ch. 12 ferme Q4 et Q5, livre R4, contient le badge 8, trois motions, l'interruption et le réveil de Rayquaza. Aucune respiration n'est prévue avant la veillée, ce qui viole aussi `Bible §2` (« une respiration après chaque scène forte »).
- Correctif : fermer Q4 dès le ch. 11. La Caverne Fondmer montre la règle Y1 sur une fresque (lieu canon ROSA ◐), et Sarah lit les relevés. Le ch. 12 ne garde que Q5 et R4.

**N22 — MINEUR — L'indice « impossible à rater » de R4 est conditionnel.** `Bible §4.3` (3e source : « témoignage de Giovanni **ou** confession du Président »), `SYS §9.2`.
- Problème : si `GI` est bas et que le Président ne confesse pas, la source « impossible à rater » manque, et Juan ne bascule pas.
- Correctif : rendre obligatoire une pièce de secours (le registre du coffre, posé au ch. 10 dans **toutes** les branches) et réserver les deux autres sources à l'intensité de la scène, pas à son existence.

**N23 — MINEUR — Le Pacte dépend de gestes faits avant que le joueur sache qu'ils comptent.** `SYS §8.2` (`HO` de 20 à ≥ 70 ; 8 des 10 gestes avant le ch. 8) ; `GAME_SYSTEMS §4` (`HO` de 0 à 70 en fin de ch. 8).
- Problème : le petit voleur est présenté comme un gag jusqu'au ch. 8. Un joueur qui l'a ignoré est exclu de F2 sans l'avoir su. C'est le défaut « seuil caché » que la bible proscrit, appliqué à la fin la plus altruiste. Cela explique en partie F2 à 11 % et LIBÉRER à 3 %.
- Correctif : ajouter une **voie de réparation** après R2b (ch. 8–12, 3 gestes de rattrapage coûteux : rendre les objets volés à leurs propriétaires, soigner Hoopa après le ch. 10, le confier à Lévy et Tatia). Elle doit permettre d'atteindre 70 depuis 30, au prix de `rC` et `rL`. Les gestes précoces restent un avantage, pas une condition.

### A5. Fins

**N24 — BLOQUANT — F4 est une fin d'échec maquillée, et son nom ment.** `SYS §10.4` (« F4 REMPART : sinon »), `§11` (les témoins F4 sont tous des SCEAU ratés faute de rite) ; `Bible §12.3`.
- Problème 1 : F4 n'est **jamais choisie**. Elle sanctionne l'échec d'une autre intention, celle d'un joueur qui voulait sceller et à qui il manquait la Doyenne.
- Problème 2 : elle porte le nom d'une faction (le Rempart de Norman) dont la politique n'a rien à voir avec ce qui se produit (Rayquaza détruit le relais). Un joueur qui a **défendu le Rempart** au Sommet n'obtient pas F4 par ce chemin.
- Problème 3 : son « gain exclusif » (« l'arc d'Amaryllis s'accomplit ») est un gain **pour l'antagoniste** ; il contredit d'ailleurs la variante RENONCE, qui reste possible en F4.
- Problème 4 : F4 × INTÉGRATION contredit le texte de F4 (« frontières fermées ; abattages »).
- Impact : près d'un joueur sur deux (46 %) voit Rayquaza raser le Centre Spatial et la Mission partir en disgrâce, après avoir voulu autre chose. Ce n'est pas « une fin à part entière ».
- Correctif :
  - (1) **Chaque intention a une version payée.** Un SCEAU sans rite devient « **Sceau brisé** » (F1-b) : la Fiole atteint le Pilier, mais Rayquaza a déjà frappé Algatia. On obtient la perte de F4 et le résultat de F1. Une PASSERELLE avec `PA` trop haut devient « Passerelle amputée » (F3-b) : le relais saute, mais la charte survit pour les données.
  - (2) **F4 devient un choix.** On crée l'intention **LAISSER LE CIEL JUGER** (D117 e), que portent Amaryllis, Norman et Major Bob s'ils tiennent le relais. Red peut la choisir : « on évacue, on laisse tomber le relais ». On la renomme « **Le Jugement** » ; Rempart reste le nom d'une variante sociale, pas d'une fin.
  - (3) Gain exclusif de F4 : **la seule fin où aucun anneau ne reste et où Hoopa n'est enchaîné par personne** (avec Y4, voir N01). C'est un monde purgé, un vrai gain pour les natifs ; sa perte est que Hoopa reste petit pour toujours.
  - (4) Fallback : si **aucune** intention n'est portée au relais (relais non tenu), la fin dépend du lieu de Red, et ne tombe jamais par défaut sur la même fin.
  - Cible de distribution : aucune fin au-dessus de 30 %.

**N25 — MAJEUR — Gains « exclusifs » qui ne le sont pas.** `Bible §12.3` contre `§12.4`.
- Problème : F2 donne pour gain exclusif « l'équipe de Red revient par un anneau », mais l'équipe revient dans **toutes** les fins (§12.4). F1 promet une « restauration des natifs la plus rapide », alors que l'état des zones dépend de M2 et des missions (`Bible §5.4`). Les deux gains se recoupent donc.
- Correctif : formuler chaque gain comme un contenu ou un état **qu'aucune autre fin n'a** :
  - F2 : des Pokémon disparus nommés (Piko, les Lokhlass) reviennent ;
  - F1 : les épreuves du Pilier ;
  - F3 : des boutiques mondiales ;
  - F4 : Hoopa n'est enchaîné par personne, et aucun anneau ne reste (N24) ;
  - F5 : des sites légendaires sauvages.

**N26 — MAJEUR — Amaryllis : l'arc de la croyante est invisible dans 81 % des parties.** `SYS §10.5` (RENONCE 12 %, SACRIFICE 7 %, PERSISTE 81 %).
- Problème : la bascule du personnage antagoniste de rang A dépend d'un choix de présence exclusif (Red au Pilier) **et** de `AM` ≥ 55, qui exige deux décisions précises au ch. 5. PERSISTE n'a qu'une réplique.
- Correctif :
  - (1) Ajouter une bascule **non exclusive** au ch. 10 : la surcharge cause une anomalie P2 qui blesse Aster (ou un enfant d'Algatia), et Amaryllis voit le prix sans que Red ait à choisir.
  - (2) Rendre RENONCE accessible par un **porteur** au Pilier (Aragon, ou Peter si le Site a été respecté) à qui Red a **donné** l'objet de la gardienne (récupéré par l'aveu de Lance (Rocket)).
  - (3) Donner à PERSISTE une vraie scène d'épilogue : elle voit les ruines (ou le Sceau) et se tait. Une conséquence, pas une réplique.
  - Cible : RENONCE 25–35 %, PERSISTE ≤ 55 %.

**N27 — MAJEUR — M1 « LIBÉRER » est un faux choix (3 %), et Peter le vote contre son propre caractère.** `SYS §9.3` (PET : 3 si Hoopa à la Mission et `PE` ≥ 55) ; `CL C-07` (position SCEAU ; intention au relais : SCEAU).
- Problème : le chef dont toute la position est le rapatriement et le sceau vote la libération de Hoopa sous une condition technique. L'option elle-même ne passe presque jamais, et ses effets (`PA` −3, `HO` +5) sont marginaux.
- Correctif : voir la réponse Q2 (§B).

**N28 — MINEUR — F2 est un châtiment divin moralisateur.** `Bible §12.3` (« Hoopa prend le trésor de qui l'a enchaîné : Devon et Sylphe ruinées »).
- Problème : la seule fin « libératrice » punit les coupables par un dieu. C'est le moralisme proscrit par la bible (§2), et Pierre Rochard démissionne en plus.
- Correctif : Hoopa prend le trésor **sans viser personne** (H1 : poids égal), et c'est Mérouville (des emplois) qui paie, pas seulement les actionnaires. Pierre Rochard reste libre de choisir.

### A6. Ton, Kanto, occasions manquées

**N29 — MAJEUR — Kanto vidé : la Ligue Indigo envoie tout son effectif.** `Bible §8.3` ch. 3 (Peter, Major Bob, Ondine, Olga, Erika, Morgane, Koga et Jeannine) ; plus Aldo, Agatha, Pierre (Brock), Auguste, Giovanni, Blue, Chen, Léo, Fuji, Ciléo.
- Problème : 6 Champions, 3 membres du Conseil 4 et le Maître par intérim quittent Kanto en même temps qu'une crise des anneaux qui, par H1, frappe aussi Kanto (N05). Personne ne garde les arènes.
- Correctif : une ligne diégétique, plus un coût. La Ligue a **gelé les badges** tant que les ports sont fermés (cela justifie la venue des Champions, désœuvrés), et Kanto est géré par Sandra et Mortimer [c GSC] (un nom dans une lettre). Pour réduire la charge, faire voyager Morgane hors Mission (sa vision l'y pousse) et Erika pour son contrat : deux motifs privés plutôt qu'institutionnels.

**N30 — MINEUR — Les éclats rouges et bleus sont une promesse ambiguë.** `CL P15` (« le relais résonne »).
- Problème : le Rubis et le Saphir évoquent Groudon et Kyogre (`LORE_DOSSIER` : ROSA, Gemmes). Le joueur en attend un réveil des titans que la règle 0 interdit.
- Correctif : soit Ciléo dit au ch. 3 que les gemmes **stabilisent** le nœud (cela renforce la part de Red, N09), soit les éclats sont remplacés par des « éclats dorés » de Hoopa. Il ne faut pas laisser un fusil de Tchekhov chargé.

**N31 — MINEUR — Le Mont Mémoria est rangé dans une zone d'influence Sinnoh/Alola, alors que les spectres viennent de Lavanville.** `CL §12.5` K-04.
- Constat : c'est déjà arbitré, mais c'est une **occasion** : les spectres « pris » par l'anneau prouvent que la loi d'échange touche aussi les morts, ce qui fait d'eux l'indice le plus fort de l'autre rive (N05).

**N32 — MINEUR — Le Match Call coupé prive le monde d'une mémoire bon marché.** `Bible §10`.
- Constat : la mémoire du monde repose sur les panneaux, la saillance et le diaporama. C'est suffisant, mais il faut alors **un bulletin TV** par chapitre selon les réputations (technique n° 15), aujourd'hui non budgété.

**N33 — MINEUR — Le ton est tenu, mais les échos risquent de surligner.** `CL` (échos par fin).
- Constat : les répliques sont de bonne facture (voix distinctes, interdits de voix, aucune maxime). Quelques échos frôlent la phrase-thèse (Peter : « Kanto a volé, caché, publié » ; Lévy et Tatia : « Il pleure quand même »). Règle à ajouter : **au plus une phrase-thèse par chapitre**, toutes voix confondues.

## B. Réponses aux questions résiduelles (`ARBITRATION_V3` §6)

1. **F4 à 46 % : échec ou fin ?** C'est un **échec**, pour quatre raisons : F4 est atteinte par défaut, son nom ne correspond à aucun choix, son image finale est une ruine, et son gain revient à l'antagoniste. Rendre F4 « plus souvent choisie » au Sommet ne suffit pas : le Sommet ne décide pas de la Fiole (bible §12.1). Il faut, comme en N24 : (a) des versions « payées » de chaque intention (F1-b, F3-b) en guise de repli ; (b) une intention LAISSER LE CIEL JUGER, portée par des alliés identifiables ; (c) la règle Y4 et un gain exclusif réel. Cible : aucune fin au-dessus de 30 %, et F4 ≤ 20 % hors parties où elle a été voulue.

2. **M1 LIBÉRER à 3 % : option morte ?** Oui, c'est un faux choix, et l'excuse « la libération se joue au climax » ne tient pas, car LIBÉRER ne prépare presque rien pour F2 (`HO` +5). Je propose de **retirer LIBÉRER de M1** (M1 = FERMER ou CHARTE) et de la remplacer par un **acte de Red hors vote** : Red **montre** Hoopa à l'assemblée. L'appel nominal est enregistré : chaque délégué qui se lève pour Hoopa (conditions actuelles de LIBÉRER) prend l'intention PACTE s'il tient ensuite le relais, et `HO` gagne +3 par délégué levé. L'option ne « perd » plus jamais : elle mesure qui suivra Hoopa. Peter ne se lève que si `PETER_ASSUME`, ce qui est cohérent avec son arc ; la condition « Hoopa à la Mission » est à retirer.

3. **Amaryllis RENONCE à 12 % : arc visible ?** Non. Les 81 % qui la voient PERSISTER n'ont qu'une réplique. Il faut une bascule non exclusive au ch. 10, RENONCE par un porteur et une scène PERSISTE (N26).

4. **Lisibilité du mythe avant le Mont Mémoria ?** H1, oui, et même trop tôt (N02). H2 est lisible par le petit voleur. **H3 n'est jamais enseignée avant le ch. 9** (le conte ne la contient pas, `CL §8.3`), alors qu'elle règle F2 et F5. Y1 est **contredite** par le conte (N03), et F4 contredit H3 (N01). Test de compréhension proposé, après le ch. 9, sur 5 joueurs novices, sans aide. Il faut qu'au moins 4 joueurs sur 5 répondent juste aux quatre questions :
   - (a) « Si on commande au Kiosque, que se passe-t-il ailleurs ? »
   - (b) « Que faut-il pour fermer les anneaux ? »
   - (c) « Que se passe-t-il si on casse la Fiole ? »
   - (d) « Pourquoi le dragon n'est-il pas venu quand on l'a volée ? »

   La question (d) n'a aujourd'hui aucune réponse.

5. **Coût du chemin libéral ressenti ?** Seulement s'il **change une carte**. Les réputations relatives `S(X)` sont invisibles par nature. Exiger que chaque franchissement de seuil lu au climax ait **un effet physique** antérieur : une rupture de stock (`rC`), une brigade sur une route (`rL`), une affiche arrachée (`rI`), ou un PNJ de Mérouville au chômage qui réapparaît chez la Rocket (N12). Sinon, le coût n'existe que dans `cf_model.py`.

6. **Charge de texte : 64 entrées dans 3 500–4 500 boîtes ?** Non : l'estimation donne environ 4 900 boîtes (N18). Les coupes et fusions de N18 ramènent la charge à environ 4 300. Si la tranche ch. 0–2 dépasse son budget, couper dans l'ordre : les scènes de témoin facultatives, puis la saillance au-delà de 3 répliques, puis les rangs C (règle « 2 scènes **ou** scène + écho »). Ne jamais couper les crises de ville ni les gestes de Hoopa.

7. **Red, un maillon parmi d'autres ?** Oui en poids, mais c'est un maillon **sans choix**, et c'est le problème (N09). Il faut lui donner une contrepartie acceptée (la Master Ball du coffre) et un acte réparateur possible (la **donner**).

8. **Hypothèses empilées lues comme canon ?** Les étiquettes n'existent pas en jeu : elles ne protègent rien. Le vrai risque n'est pas qu'un fan croie à l'article de Chen. C'est que les hypothèses **contredisent** un canon que le fan connaît : Rayquaza qui dort au Pilier (N03), Amaryllis qui est elle-même la Gardienne en ROSA, Giovanni qui ne se montre jamais (N08). Règle : une hypothèse peut **ajouter** au canon, jamais le contredire sans qu'un personnage le relève. Limiter aussi à **une** hypothèse nouvelle par révélation.

9. **E-TOD de nuit seule, injuste ?** Oui, si rien ne l'explique. On peut en faire de la fiction à coût nul : les transferts Passerelle se font **la nuit**, aux heures creuses (c'est l'horaire volé de R1). Les anneaux fuient donc la nuit, Brice recense la nuit, et le prologue est nocturne. Le joueur apprend une règle au lieu de subir une contrainte. Un PNJ du labo le dit au ch. 1.

10. **Climax : le joueur comprend-il avant de choisir ?** Pas avec les répliques actuelles. « Il ne la prendra que de quelqu'un qu'il croit » ne dit pas au novice que `HO` ≥ 80 est requis. Ajouter au Carnet une page **« Plan de la nuit »**, générée à la veillée : pour chaque allié, le lieu possible et ce qu'il fera de la Fiole, en une ligne (« Peter : Pilier ou relais. Au relais, il scelle. »), plus un signe de confiance de Hoopa envers chacun (il se cache derrière lui, ou non). Test sur 5 novices : prédire la fin avant de valider l'affectation, avec au moins 4 joueurs sur 5 qui ont juste.

## C. Notes (0–5)

| Critère | Note | Justification |
|---|---|---|
| Originalité | **4** | Hoopa en batterie d'un réseau commercial, la loi d'échange comme écologie et le Sommet par gestes sont neufs pour un hack. Ils restent adossés à des archétypes connus (« le réseau qui enchaîne un dieu »). |
| Mystère | **2,5** | Les couches sont bien tracées sur le papier, mais R2 est éventée par le Kiosque (N02), R4 est un exposé (N20), Q4 se résout dès le conte, et l'identité de Giovanni n'est pas un mystère. |
| Émotion | **3** | Il y a de bons noyaux (Brice et son père, Pikachu blessé, Hoopa qui rend un objet, Blue qui ne connaît pas le nom de ses Pokémon). Ils sont dilués par la taille de la distribution, et la fin la plus fréquente est vécue comme un échec. |
| Antagonistes | **2,5** | Amaryllis, Max et Arthur sont crédibles. Giovanni est juste jusqu'à son aveu public (N08). La Rocket est plate (N12), et la bascule d'Amaryllis est invisible pour la majorité (N26). |
| Cohérence du monde | **2,5** | L'autre rive manque (N05), le vol de l'an −2 est impossible (N03), la R&D de la Fiole est absente (N04), et Kanto est vidé (N29). La chronologie est globalement soignée, mais deux tables divergent. |
| Usage du lore | **3,5** | La triade conte → loi → choix est un excellent outil, et le parallèle des Regis est intelligent. Mais les lois se contredisent au climax (N01), et Hisui n'est couvert par aucune règle (N06). |
| Justification de Kanto | **3,5** | Chaque Kantonais a une raison (`CL §12.2`), avec deux vagues. Il manque la souffrance de Kanto (N05), et la « faute de Kanto » repose sur des maillons fragiles (Chen N15, Red N09). |
| Ensemble choral | **2,5** | Les rangs A et une partie des rangs B de Kanto sont solides. Les Champions et le Conseil 4 de Hoenn restent des figurants selon la définition même de la bible (N17), les décideurs de fin sont au rang C (N19), et 64 entrées dépassent le budget (N18). |
| Maturité | **3,5** | Il y a des compromis réels (Seko qui livre ses chiffres au Rempart, Erika et son contrat, Voltère, Brice qui vote contre Red), aucun narrateur moralisateur, et des voix tenues. Restent F2 en châtiment divin (N28), une Rocket « égoïsme lisible » et une culpabilité de Red plaquée (N09). |

## D. Priorités (ordre conseillé avant la tranche ch. 0–2)
1. N01 et N24 (loi Y4, refonte de F4 et des replis) : elles conditionnent le climax, donc le registre (D116–D121).
2. N02 (Kiosque contre R2) : le ch. 3 fait partie de la tranche.
3. N03, N04, N05 (vol de l'an −2, R&D, autre rive) : à corriger dans la chronologie avant toute écriture de scène.
4. N08, N09, N13 (Giovanni, part de Red, agence au Sommet) : ce sont des réécritures de fiches, peu coûteuses maintenant.
5. N17, N18, N19 (distribution) : à décider avant de budgéter la tranche.
6. Le reste au fil de l'écriture.
