# GAME_DESIGN_BIBLE — *Pokémon Confluence* (v3.0, colonne vertébrale)

> **Source unique de vérité du design.** Propriétaire : Game Mechanics Director (GMD). Toute modification passe par le GMD et entre au changelog (§16).
> Méthode obligatoire : `GM_METHOD.md`. Intention : `EXPERIENCE_INTENT.md` (son addendum v2 reste valable, sauf là où ce document le contredit ; la thèse est reformulée en §2).
> Statut : **v3.0 — colonne vertébrale (conception). Rien n'est implémenté ni testé.** Toute mécanique nouvelle est une `HYPOTHÈSE` jusqu'à la porte prototype.
> Briefs des spécialistes : `SPEC_BRIEFS.md`. Archives v2 (*Cendres*) : `archive/cendres_v2/`. Les revues v2 (`reviews/REVIEW_V2_*.md`) restent des **listes de défauts à ne pas reproduire**.

## Documents liés (font partie de la bible)
| Document | Contenu | État |
|---|---|---|
| `CHARACTER_AND_LORE.md` v3 | fiches complètes, toile relationnelle, guides de voix, lore/mythologie, chronologie détaillée | à produire (brief A) |
| `COMBAT_DESIGN.md` v3 | équipes de tous les dresseurs majeurs par rencontre, paliers, IA, ID | à produire (brief B) |
| `DECISION_LEDGER.md` (+ fichiers par acte) et `GAME_SYSTEMS.md` v3 | ≥ 131 décisions listées / ≥ 115 robustes, systèmes, budget flags/vars, logique des fins | à produire (brief C) |
| `ENCOUNTERS_PLAN.md` | les 1 025 espèces Gen 1–9, répartition, rareté, écologie, événements | à produire (brief D) |

---

## 0. Décision v2 → v3 : remplacer la prémisse, garder le châssis

**Diagnostic.** *Cendres* (v2) reposait sur un volcan et 300 réfugiés de Cramois'Île. L'addendum v2.1 exige **toutes les espèces Gen 1–9 expliquées par l'intrigue**, une **intervention légendaire**, une **intrigue en couches** et **tout le casting majeur de Kanto** (Chen, Blue, les 8 Champions, le Conseil 4, Giovanni, Léo, Fuji…). Un camp de réfugiés ne justifie ni la venue de huit Champions et du Conseil 4, ni l'arrivée de Pokémon de Paldea. Les revues v2 avaient en plus touché la prémisse elle-même : motif de l'exil (N1), plan Rocket absurde (N3), combat qui sauve le volcan (N19), bon chemin unique (N20, S9).

**Cause.** Le conflit central de v2 était **local** (un volcan, un camp). Or l'addendum demande un conflit **systémique et transrégional**.

**Décision.** On remplace la prémisse et le titre. On garde le châssis validé :
- Red joueur muet, qui agit par gestes ; Brice voix et second protagoniste ; cadre « année 1 » ;
- le Carnet de Red ; Méga seule ;
- les commandants Rocket et le déguisement de Lambda ; Agatha et Spectra au Mont Mémoria ; Peter au Site Météore ; Ciléo et Lanette sur le réseau ; l'arc de Blue vers Jadielle ;
- le Conseil (devenu le **Sommet**), avec négociation par gestes ;
- les leçons techniques : portes vanilla, plafonds par jalons, accès aux soins, budget d'ID, combats refusables enregistrés.

**Ce qui disparaît :** le Projet Soupape, l'Arche, le camp de Cramois'Île, Groudon au climax.

---

## 1. Concept et identité

**Une phrase :** *Red a tout gagné à Kanto. Un an plus tard, à Hoenn, il découvre qui a payé pour ses victoires.*

**Accroche :** « Tout ce qui arrive vient d'ailleurs. »

**Le pitch.** Depuis trois mois, des **anneaux dorés** s'ouvrent dans le ciel et sur la mer de Hoenn. Il en sort des Pokémon que personne ici n'a jamais vus : ils viennent de Kanto et de Johto, puis de Sinnoh, Unys, Kalos, Alola, Galar et Paldea. Les bancs de poissons s'effondrent à Myokara, des Pokémon mangent le sel des mines de Mérouville et les vergers de Vergazon dépérissent. Hoenn a fermé ses ports aux navires de Kanto : les premiers anneaux ont craché des Pokémon de Kanto, et le réseau qui relie les PC des deux régions est kantonais.

Red arrive de nuit, en clandestin, avec **Ciléo**, venu prouver que sa machine est innocente. Sur la plage, Red se bat avec toute sa force et gagne. Puis un anneau s'ouvre sous lui et **emporte son équipe**.

Avec **Brice**, qui recense les « arrivants » pour son père, il traverse une région où chacun a une réponse à la crise :
- la Ligue veut abattre les intrus ;
- le consortium Devon–Sylphe vend le réseau qui relie le monde ;
- Magma veut déplacer les espèces par anneaux contrôlés, Aqua veut libérer tout ce qui est enfermé ;
- la Mission Indigo, envoyée par Kanto, veut laver son nom ;
- la Team Rocket veut l'arme qui vole n'importe quoi, n'importe où ;
- une gardienne du Peuple du Météore veut que **le ciel juge**.

| Élément | Décision |
|---|---|
| Titre | **Pokémon Confluence** |
| En-tête ROM (≤ 12) | `CONFLUENCE` |
| Joueur | **Red** (nom fixe, muet par choix ; avatar Red, `ENGINE_CHANGES.md` §B) |
| Second protagoniste | **Brice**, fils du Prof. Seko, chargé du recensement des arrivants |
| Région / cartes | Hoenn, 518 cartes vanilla, noms FR vanilla ; aucune carte neuve |
| Cadre temporel | **Année 1** après RFVF (cadre B du `LORE_DOSSIER` §8.1) |
| Gimmick | **Méga-Évolution** seule (Méga-Bracelet au ch. 8). Téra, Dynamax et Z existent ailleurs, pas à Hoenn |
| Durée cible | 22–26 h d'aventure principale, plus 6–10 h de postgame |
| Préfixes techniques | flags `FLAG_CF_*`, vars `VAR_CF_*`, décisions `D###`, personnages `C-xx`, zones `Z-xx`, équipes `T-<perso>-<palier><variante>` |

---

## 2. Thèmes, propos, contrat de design

**Thèse d'expérience (remplace EXPERIENCE_INTENT §1) :** *le joueur le plus fort du monde découvre que chaque gain vient de quelque part, et apprend à lire ce que ses choix prennent aux autres.* La compétence récompensée reste **observer → formuler une hypothèse → préparer → vérifier**. Elle s'applique aux combats, aux gens et aux écosystèmes.

- **Thème central : tout échange a un prix.** La loi des anneaux, le réseau Passerelle, le marché, la capture et les victoires de Red relèvent tous de l'échange. La question n'est jamais « gagner ou perdre ». C'est « qui paie, et le sait-il ? ».
- **Thèmes secondaires :**
  - **appartenir** : qui est chez lui ? les espèces natives, les arrivants, la Mission de Kanto, Red l'étranger ;
  - **la responsabilité diffuse** : aucun coupable unique, une chaîne de décisions défendables ;
  - **sceller par peur** : les anciens ont enfermé ce qu'ils craignaient, et le Rempart recommence ;
  - **parler pour quelqu'un** : Brice parle pour Red, mais pas toujours comme Red le voudrait.
- **Ton :** aventure sérieuse et chaleureuse, jamais cynique ni moralisatrice. L'humour vient des personnages : Brice bavard, Blue fanfaron, Major Bob, Bastien, et le « petit voleur » (§6). Les Pokémon eux-mêmes allègent les scènes. Règle : une respiration après chaque scène forte.
- **Maturité :** des motifs crédibles (emplois, deuil, orgueil, peur, foi, dette). Les compromis ont un coût visible. Aucune fin n'est punitive, aucune n'est parfaite.

### 2.1 Clause de contrat (niveau jeu)
**Structure dominante :** hybride. Au niveau micro, **émergence** : combat, composition d'équipe, rencontres, écosystèmes par zone. Au niveau macro, **progression** : ordre des zones, révélations, portes. Les **états cachés** colorent les goulots (branch-and-bottleneck, avec des scènes qui testent des seuils).
**Famille dominante :** manœuvre tactique (combat), co-dominée par l'économie interne (équipe comme portefeuille, PV/PP/objets, plafond). La **sociale simulée** (relations, réputations) est un cadre lisible par réactions, sans jauge visible.
**Économie interne :**
- ressources : PV/PP, objets, argent, EXP plafonnée, membres d'équipe, information (pièces du Dossier), confiance (relations), réputation, **pression des anneaux** (ressource commune et négative) ;
- patterns : Playing Style Reinforcement (l'équipe comme identité), Escalating Challenge (paliers d'adversaires), Stopping Mechanism (plafond souple par jalons), Attrition (zones sans soin courtes), et un **Slow Cycle** narratif (ouvertures d'anneaux qui changent les rencontres) ;
- feedback : négatif fort pour la puissance (plafond) ; positif lent pour la confiance (les alliés de confiance ouvrent des options), tempéré par des **intérêts en tension** (plaire à l'un coûte ailleurs) ;
- **dynamic friction** sur la pression des anneaux : plus on utilise le réseau, plus il prend.

**Espace de possibilités :** large (≥ 2 plans de victoire par combat majeur ; ≥ 2 approches par crise de ville) et profond (les états cumulés produisent 5 fins × 3 variantes sociales, plus des variantes de personnages).
**Stratégies dominantes recherchées et contre-pressions :** voir §11.3 (« chemin doré », « payer toujours », « tout capturer », « farmer », « plaire à tous »).
**Ce qu'il reste à apprendre après la première solution :** la deuxième partie révèle d'autres couches (scènes de témoin selon la présence, fins à couches, Dossier complet) ; en combat, les équipes adaptatives changent de contre-stratégie.

### 2.2 Sémiotique des mécaniques clés (4 couches)
| Mécanique | Effet mécanique | Sens fictionnel | Sens appris | Sens thématique |
|---|---|---|---|---|
| **Anneau** (événement d'ouverture) | change la table de rencontre d'une carte ; prend un objet ou un Pokémon visible | portail de Hoopa alimenté par le réseau | « quelque chose arrive, quelque chose part » | l'échange a toujours deux côtés |
| **Kiosque Passerelle** (commande d'import) | objet rare contre argent ; **+ pression des anneaux** ; un anneau prend quelque chose ailleurs | commerce instantané mondial | « mon confort se paie ailleurs » | le joueur participe au système qu'il juge (ironie voulue, dosée : facultatif, plafonné) |
| **Capture** | ajoute un membre | lien consenti, gagné par l'épreuve | « on se gagne » | s'oppose à la **saisie** (réseau, Rocket) : la différence est le consentement |
| **Recensement** (Pokédex de Brice) | compteur d'espèces + carte des anneaux | cartographier le phénomène | « les arrivants suivent un motif » | compléter n'est pas innocent : on mesure aussi ce qui manque |
| **Plafond par jalons** | EXP réduite au-delà | l'accréditation de crise limite les combattants étrangers | « la force se mérite et se borne » | même Red ne peut pas forcer le monde |
| **Refuser un combat** | flag de refus, définitif | geste de Red (dignité, mépris, paix) | « ne pas se battre est un acte » | la force n'est pas toujours la réponse |
| **États d'écosystème** | tables de rencontre alternatives par zone | une route envahie, mixte ou restaurée | « mes actes changent ce qui vit ici » | appartenir se négocie |
| **La Fiole** | objet-clé de fin | pouvoir scellé de Hoopa | « celui qui la tient décide pour tous » | la peur qui scelle, l'avarice qui exploite, la confiance qui libère |

---

## 3. Cadre et règles de lore

**Règle 0.** *Confluence* **est** la crise de Hoenn de cette chronologie. RSE n'a pas eu lieu sous sa forme connue :
- Groudon et Kyogre dorment ;
- Magma et Aqua sont des mouvements idéologiques organisés et militants, pas encore des criminels de masse ;
- **Pierre Rochard est Maître** (RS) ; **Juan tient l'arène d'Atalanopolis** (E) ;
- **Marc** a quitté l'arène pour garder la Grotte Originelle et présider les Concours. Juan, son maître, l'a reprise. Une réplique le dit au ch. 9.

**Étiquettes.** Tout fait de lore porte une étiquette : `CANON` (jeu, avec le code du jeu) ou `HYPOTHÈSE` (invention du hack). Les autres médias sont non contraignants. Aucune théorie de fans n'est présentée comme canon.

**Futur canonique à préserver (année 3, GSC/HGSS) :**
- Red repart vers le nord (Mont Argenté) ;
- Blue devient Champion de Jadielle ;
- Giovanni reste caché, n'obtient rien et ne revient pas ;
- les quatre commandants Rocket sont **libres** en année 3 : une arrestation est suivie d'une évasion, jamais d'une peine définitive ;
- Koga entre au Conseil 4 et Jeannine reprend Parmanie ;
- Peter est Maître ; Agatha prend sa retraite ; Olga rentre à l'Île 4 ;
- Pierre Rochard peut partir pour Kanto (HGSS) ;
- Cramois'Île entrera en éruption (GSC) : on peut le présager, pas le montrer.

**Espèces.** Toutes les espèces existent déjà dans leurs régions en année 1. Hoenn et Kanto ne les connaissent simplement pas : leurs entrées sont inconnues du Pokédex, et Chen et Seko font la course pour les nommer.

**Pièges de noms.** Pierre = Brock ; **Pierre Rochard** = Steven (toujours en entier). **Peter** = Lance (le Maître dragon) ; **Lance** = le commandant Rocket (Proton), toujours écrit « Lance (Rocket) ».

### 3.1 Chronologie (cachée au joueur jusqu'au noyau)
| Date | Événement | Étiquette | Révélé |
|---|---|---|---|
| Il y a ~50 ans | Le jeune Chen et Agatha voyagent à Hoenn. Chen publie un article sur « un artefact scellé au sommet du Pilier Céleste ». Agatha le lui reproche depuis | HYPOTHÈSE (rivalité CANON RBJ, cause inventée) | ch. 12 |
| An −2 | Sur ordre de Giovanni, Lance (Rocket) vole **la Fiole** (Vase Prison) au Pilier Céleste. La gardienne du Peuple du Météore, amie d'Amaryllis, disparaît cette nuit-là (Aster est sa Chuchmur) | HYPOTHÈSE | ch. 9 (lieu), ch. 12 (auteur) |
| An 0 | Giovanni cache la Fiole dans le coffre de Sylphe pendant l'occupation : il voulait la Master Ball **et** la Fiole. Red libère Sylphe. Le Président trouve la Fiole et la cache à la police | occupation CANON RBJ/RFVF ; Fiole HYPOTHÈSE | ch. 12 |
| An 0 | Red apporte le Rubis et le Saphir à Ciléo : le réseau Kanto–Hoenn–Rhode est relié | CANON RFVF | prologue (indice) |
| An 0 + 4 mois | Sylphe (ruinée) et Devon signent **Passerelle** : transfert instantané de Pokémon et de biens entre les régions. Léo conçoit la couche de transfert, Lanette le stockage, Ciléo le nœud Kanto. Le relais est au Centre Spatial d'Algatia. Sa source d'énergie est un « Cœur » scellé fourni par Sylphe. M. Rochard ne demande pas ce que c'est | HYPOTHÈSE | ch. 7 (Cœur vivant), ch. 10 (Fiole), ch. 12 (qui savait) |
| An 1 − 3 mois | Mise en service commerciale. Premiers anneaux près de Poivressel, avec des Pokémon de Kanto. Hoenn ferme ses ports aux navires de Kanto | HYPOTHÈSE | prologue |
| An 1 − 6 semaines | Amaryllis comprend et commence à **surcharger** le réseau (achats massifs par prête-noms, résonance de la météorite) pour forcer Rayquaza à descendre | HYPOTHÈSE | ch. 12 |
| An 1 − 2 semaines | **Hoopa Confiné**, attiré par son pouvoir enfermé, arrive à Hoenn par un anneau. Il vole pour manger et se cache | HYPOTHÈSE (Hoopa et Fiole CANON ROSA/XY ; Pokédex : avarice, anneaux CANON) | ch. 8 |
| An 1 | Le jeu commence | — | — |

---

## 4. L'oignon : couches, ce que croit le joueur, révélations

### 4.1 Les couches
| Couche | Contenu vrai | Ce que le joueur croit à ce stade | Fermée par | Action de jeu induite |
|---|---|---|---|---|
| **Surface** (prologue–ch. 4) | Des anneaux s'ouvrent ; des espèces arrivent, des choses disparaissent ; la Rocket fait de la contrebande d'arrivants | « Le réseau kantonais ou des contrebandiers ouvrent les anneaux » | **R1** (ch. 4, raid du Tunnel Mérazon) : la Rocket **prédit** les anneaux avec un horaire volé ; elle ne les ouvre pas | enquête, combats contre la Rocket, premiers états d'écosystème |
| **Milieu** (ch. 5–10) | Chaque transfert Passerelle ouvre des anneaux. Le relais est alimenté par une **créature** (le pouvoir de Hoopa dans la Fiole). Les anneaux **prennent autant qu'ils donnent**. La Fiole vient du **Pilier Céleste**, où Rayquaza la surveillait | ch. 5–6 : « Magma ou le consortium contrôlent les anneaux » (fausse piste vraie à un autre niveau : Magma **sait** déclencher un anneau avec les données volées) ; ch. 7 : « le réseau est la cause » ; ch. 8–10 : « une créature est enchaînée, le ciel va répondre » | **R2** (ch. 7, mi-parcours), **R2b** (ch. 8), **R3** (ch. 9–10) | choix de garde de Hoopa, marché noir, rite, défense du relais |
| **Noyau** (ch. 11–12) | Une **chaîne de responsabilités**. Chen a révélé le lieu. Giovanni a ordonné le vol. Le Président de Sylphe a caché la Fiole. Les victoires de Red ont livré la Fiole à Sylphe et le lien à Ciléo. Devon a choisi de ne pas savoir. Amaryllis surcharge le réseau. Le Rempart nourrit le marché des primes que la Rocket exploite | « Personne n'est le coupable unique, et j'en fais partie » | **R4** (ch. 12, pendant le Sommet) | vote du Sommet, affectation au climax, sort de la Fiole |
| **Mythe** (en filigrane, fermé au ch. 9 et au ch. 13) | La légende du **Voleur d'Anneaux**. Les ancêtres du Peuple du Météore ont scellé son pouvoir **par peur**, sous la garde de Rayquaza. Bayar et le Sanctuaire montrent le même réflexe des anciens (Regis scellés) | ch. 5 : un conte ; ch. 9 : une loi ; ch. 13 : un choix | inscription du Mont Mémoria (ch. 9) ; descente de Rayquaza (ch. 13) | Sceau, Pacte, Passerelle, Rempart ou Ciel ouvert (§12) |

**Mi-parcours (R2, ch. 7).** La question change. Avant : « Qui ouvre les anneaux ? ». Après : « Que faire d'une infrastructure dont toute la région dépend, et qui fonctionne en enchaînant une créature ? ». Le joueur passe de l'enquête à l'arbitrage.

**Retournement final (R4).** Il recontextualise au moins cinq scènes antérieures :
- le prologue : la culpabilité de Ciléo, le silence de Red ;
- Mérouville : le « Cœur breveté » vanté par le Président de Sylphe ;
- Poivressel : l'homme au Persian qui regarde le marché ;
- le Site Météore : les « étoiles » d'Amaryllis ;
- Cimetronelle : Hoopa qui fuit toujours vers l'est, vers Algatia.

### 4.2 Économie de l'information : questions ouvertes (jamais plus de 3 majeures)
| Q | Question active | Ouverte | Hypothèse que le jeu laisse former | Fermée |
|---|---|---|---|---|
| Q1 | Qui ouvre les anneaux ? | prologue | Kanto, puis la Rocket | partiellement en R1 (ch. 4), totalement en R2 (ch. 7) |
| Q2 | Qui est le petit voleur aux anneaux ? | ch. 1 | un Pokémon d'ailleurs, une mascotte de la Rocket | **R2b** (ch. 8, Cimetronelle) : Hoopa Confiné |
| Q3 | Où vont ceux qui disparaissent ? (Piko, les Lokhlass d'Olga, les Pokémon des sources de Vermilava, les natifs) | ch. 5–6 (germe au prologue avec Piko) | volés par les arrivants, ou par la Rocket | **R3** (ch. 9, Mont Mémoria) : la loi d'échange |
| Q4 | Pourquoi le ciel gronde-t-il ? | ch. 8 (Route 120, vision de Morgane) | un dragon ennemi arrive | **R4** (ch. 12) : la règle de Rayquaza et la surcharge d'Amaryllis |
| Q5 | D'où vient le Cœur, et qui est responsable ? | ch. 7 | le consortium seul | **R4** (ch. 12) |

Questions ouvertes par chapitre :
| Chapitres | Questions ouvertes |
|---|---|
| 1–4 | Q1, Q2 |
| 5–6 | Q1, Q2, Q3 |
| 7 | Q2, Q3, Q5 |
| 8 (après Cimetronelle) | Q3, Q5, Q4 |
| 9–11 | Q4, Q5 |
| 12 | tout est fermé |

**Micro-révélations** (une par chapitre au moins) : un nom, un lieu, une contradiction.

### 4.3 Trois indices par conclusion (dont un impossible à rater)
| Conclusion | Indice 1 | Indice 2 | Indice 3 (impossible à rater) |
|---|---|---|---|
| R1 : la Rocket prédit, elle n'ouvre pas | sbires présents **avant** chaque anneau (R116, ch. 1) | carnet de primes avec des heures (Tunnel, ch. 4) | le prédicteur saisi au raid, avec un horaire signé « Passerelle » |
| R2 : le réseau ouvre les anneaux | la carte du recensement de Brice : l'origine des espèces suit les contrats de chaque nœud (§5.3) | les journaux de Lanette (ch. 5) : heures des transferts = heures des anneaux | l'aveu de Léo et l'enregistrement du « battement » du Cœur (ch. 7) |
| R2b : le voleur est Hoopa | il vole avec de petits anneaux (dès le ch. 1) | il fuit toujours vers Algatia | il est capturé par le piège de Koga (ch. 8) |
| R3 : la loi d'échange | Piko et les Lokhlass disparus le jour d'un anneau | après la démonstration de Magma (ch. 6), les Pokémon des sources disparaissent | les spectres du Mont Mémoria « montrent » ce qui est parti, et l'inscription du Sceau le dit (ch. 9) |
| R4 : la chaîne de responsabilités | le Président de Sylphe évite toute question sur le Cœur (ch. 1, 3) ; l'homme au Persian (ch. 3, 6, 9) | Agatha accuse Chen (ch. 9) ; Lambda se déguise en Giovanni (ch. 10) | au Sommet, trois sources concordent : registre du coffre de Sylphe (Ciléo), témoignage de Giovanni **ou** confession du Président, inscription |

### 4.4 Le silence de Red
Red **choisit** de se taire depuis la Ligue. Ce n'est ni un handicap ni une coquetterie. Le Carnet est sa seule voix intime (des phrases courtes, débloquées par les relations). **Une seule phrase écrite publique**, au moment fort du Sommet ou de l'épilogue, selon l'état (brief C).

Pour agir, Red dispose de **cinq verbes de geste**, valables dans tout le jeu, de la négociation au Sommet : **montrer** (une pièce, un objet), **désigner** (une personne, qui parle alors), **rester** (attendre), **partir** (rompre), **donner**.

---

## 5. Toutes les espèces Gen 1–9 : mécanisme, conséquences, réactions

### 5.1 Le mécanisme
**Passerelle** est le réseau Devon–Sylphe construit sur la machine de Ciléo. Il promet le transfert instantané de Pokémon et de biens entre les régions sous contrat. Il devait transporter des **données**, comme les PC (CANON). Mais son relais d'Algatia est alimenté par **le pouvoir de Hoopa scellé dans la Fiole** (HYPOTHÈSE). Chaque transfert emprunte donc **une paire d'anneaux réels**. Ces anneaux « fuient » : des anneaux secondaires, non programmés, s'ouvrent près des nœuds. Ils amènent des Pokémon sauvages des campagnes de la région partenaire et emportent ce qui se trouve de ce côté-ci.

Ancres canon :
- les anneaux de Hoopa amènent à Hoenn des Pokémon d'autres régions (lieux Mirages et anneaux, ROSA) ;
- la Fiole contient la forme Déchaînée (XY/ROSA) ;
- le Pokédex parle d'avarice et de vol par anneaux ;
- le réseau Rubis/Saphir relie Kanto, Hoenn et Rhode (RFVF).

### 5.2 Règles (lois de Sanderson ; le joueur les apprend avant qu'elles servent)
| # | Règle | Où le joueur l'apprend |
|---|---|---|
| H1 | Un anneau relie deux lieux. **Ce qui passe dans un sens est compensé dans l'autre** (poids de vie à peu près égal, pas la même espèce) | Kiosque Passerelle (ch. 3, échec peu coûteux), démonstration de Magma (ch. 6), Mont Mémoria (ch. 9, énoncé) |
| H2 | Hoopa Confiné n'ouvre que de petits anneaux (objets, petits Pokémon). Le **pouvoir déchaîné**, dans la Fiole, ouvre les grands | le petit voleur (ch. 1–7) ; le relais (ch. 10) |
| H3 | Seul Hoopa réuni à son pouvoir peut **fermer** les anneaux en équilibrant l'échange. Briser la Fiole sans lui libère le pouvoir sans maître (tempête d'anneaux) | Fuji et Léo (ch. 9–10), inscription (ch. 9) |
| H4 | Une Fiole rescellée au Pilier Céleste rend le pouvoir **dormant** : les anneaux cessent, rien ne revient | Doyenne du Peuple du Météore (ch. 5 conte, ch. 12 rite) |
| Y1 | **Rayquaza** garde le ciel et la Fiole. Quand le ciel est « déchiré » (la pression des anneaux dépasse un seuil, ou la Fiole est loin du Pilier pendant une tempête d'anneaux), il descend et **détruit ce qui déchire**, sans distinguer | conte (ch. 5), signes (ch. 8 : tempêtes de l'Institut, Absol, vision de Morgane), inscription (ch. 9) |
| Y2 | Rayquaza ne négocie pas. Le rite des gardiens peut le **retarder**. Il **repart** si la déchirure est fermée avant son arrivée. Il ne peut pas être capturé pendant l'histoire | Doyenne (ch. 12) |
| Y3 | Le combattre ne **décide** rien : cela fait gagner du temps (évacuer, atteindre le relais) | règle de climax (§12) |

**Paliers d'arrivée** (ils expliquent toutes les espèces ; détail dans le brief D) :
- **P1, arrivants régionaux.** Anneaux fuyants des nœuds sous contrat. Populations sauvages, dynamique invasive. C'est l'essentiel des espèces Gen 1–9 non légendaires, et des formes régionales cohérentes avec leur région d'origine.
- **P2, anomalies.** Anneaux de **surcharge** déclenchés par Amaryllis : ils percent là où l'espace ou le temps sont « minces ». Ultra-Chimères (Ultra-Dimension), Paradoxes (Zone Zéro), espèces et formes de Hisui (Sinnoh ancien). Ils sont rares et localisés, apparaissent seulement à partir du ch. 8, et augmentent avec la pression des anneaux. Leur présence est **le signal visible** de l'escalade.
- **P3, légendaires et fabuleux.** Au postgame, par anneaux, sur le modèle des anneaux de Hoopa dans les lieux Mirages (CANON ROSA). Le **canal dépend de la fin** (§12.4), mais **chaque espèce est obtenable dans chaque fin**. Exceptions scénarisées : Hoopa et Rayquaza (histoire), Latios et Latias (témoins, Île du Sud).
- **Autres sources :** cadeaux (starters des autres régions remis par des personnages), fossiles (Devon et Pierre), échanges en jeu, œufs, évolutions.
- **Natifs de Hoenn :** ils restent présents, mais **raréfiés** dans les zones envahies. Une partie a été **emportée ailleurs** (loi H1).

### 5.3 Nœuds et origines : l'indice systémique
Chaque nœud de Passerelle a des contrats avec certaines régions. Les anneaux fuyants autour d'un nœud amènent donc **surtout** des espèces de ces régions : au moins 80 % des espèces étrangères sauvages d'une zone, le reste étant du bruit. Le joueur peut **cartographier** le phénomène, et la carte de Brice devient la preuve de R2.

| Nœud (carte) | Contrats | Zones d'effet (ordre indicatif) |
|---|---|---|
| Poivressel (port, entrepôt Passerelle) | Kanto, Johto | Routes 104–110, 134 ; Myokara |
| Mérouville (siège Devon) | Kalos, Galar | Bois Clémenti, Routes 115–116, Tunnel Mérazon, Grotte Granite |
| Lavandia (centrale, Nouvelle Lavandia) | Unys | Routes 110–111, 117–118, Vergazon |
| Nénucrique (marché) | Sinnoh, Alola | Routes 119–123, Parc Safari, Mont Mémoria |
| Algatia (relais central) | Paldea, plus la **surcharge** (P2) | Routes 124–131, Grotte Tréfonds, Pilier Céleste |
| Autéquia, Site Météore (aucun nœud) | anneaux de surcharge seulement | Routes 113–114, Chutes Météore (P2 tardif) |

### 5.4 Perturbations écologiques et sociales
Les exemples d'espèces sont **indicatifs** : le brief D les choisit selon §5.3, et l'origine doit rester cohérente avec le nœud.

| Zone | Perturbation | Effet social | Qui réagit et comment | Mission du joueur (état d'écosystème) |
|---|---|---|---|---|
| Mines de Mérouville | arrivants mangeurs de sel ou de roche dans les galeries de Devon | mineurs mis à pied, Devon accusée | mineurs : abattage ; Pierre (Brock) : déplacer ; Roxanne : données | ch. 1 |
| Pêcheries de Myokara | bancs et prédateurs étrangers qui crèvent les filets | pêcheurs ruinés, prix du poisson | Aldo avec les pêcheurs ; Bastien avec les arrivants | ch. 2 |
| Marché de Poivressel | imports Passerelle bon marché | commerçants locaux ruinés ; xénophobie anti-Kanto | Consortium : expansion ; Communautés : ports fermés | ch. 3 |
| Lavandia | arrivants Électrik qui vident les lignes | coupures, quartiers sacrifiés | Major Bob : périmètre ; Voltère : courant d'abord | ch. 4 |
| Vergers de Vergazon | arrivants qui dévorent les baies | fermiers ; Timmy adopte un arrivant condamné | Rempart (Flora) : abattage ; Erika : parfum ; Timmy | ch. 4, 7 |
| Routes 111–113 (cendres, désert) | arrivants fouisseurs contre Kraknoix et les natifs du sable | Bayar et les ruines menacés | Magma : relevés ; Bayar : sceaux anciens | ch. 5 (quête) |
| Vermilava | troupeau étranger dans les champs ; puis **les Pokémon des sources disparaissent** (échange, démonstration Magma) | tourisme des sources ruiné | Max : déplacer ; Adriane, Auguste ; Aqua : manifestation | ch. 6 |
| Canopée de Cimetronelle | corvidés étrangers contre Hélédelle et Tropius | nids détruits, ponts suspendus | Alizée ; Koga traque le voleur | ch. 8 |
| Nénucrique | **marché noir** d'arrivants et de Pokémon volés (Lokhlass de Sevii) | primes, abandons, chasseurs | Olga, Damien ; Rocket ; Aqua | ch. 9 |
| Mont Mémoria | spectres de Lavanville « pris » par les anneaux | deuil, profanation | Agatha, Spectra, Fuji ; Lance (Rocket) | ch. 9 |
| Mers 124–131 | grands arrivants marins ; Wailmer déplacés ; câble Passerelle | Pacifiville menacé | Aqua (couper) ; Marin (câble) | ch. 10–11 |
| Atalanopolis | eaux sacrées | tradition contre ouverture | Sages, Marc, Juan | ch. 12 |

**Tendances sociales transversales :**
- primes du Rempart (des chasseurs, la Rocket qui encaisse) ;
- abandons d'arrivants achetés puis trop chers ;
- enfants qui adoptent des arrivants ;
- course scientifique Chen contre Seko ;
- lecture religieuse (Peuple du Météore, Mont Mémoria) ;
- recrutement de la Rocket parmi les ruinés : il est mesuré par `RK` (§11).

**Anti-farming et anti-dominance.** L'état d'une zone dépend des **issues de missions et de la politique votée**, jamais du nombre de captures.

---

## 6. L'intervention légendaire

**Hoopa : la créature au centre, victime et cause.**
- Le **petit voleur** vole de la nourriture, le carnet de Brice ou un objet de la boutique, puis rend parfois. C'est un fil comique **récurrent du ch. 1 au ch. 7** ; ses apparitions sont « drôles » jusqu'à ce qu'elles ne le soient plus (la technique Volo).
- Chaque rencontre offre des **gestes discrets** (nourrir, poursuivre, ignorer, signaler, piéger). Ils alimentent la **confiance de Hoopa** (`HO`).
- Révélé au ch. 8 (piège de Koga). Il devient alors un **suiveur non combattant** (PNJ suiveur) ou il est confié à quelqu'un (§9, décision de garde).
- Hoopa ne parle pas. Il agit, il regarde, il prend et il rend.

**Rayquaza : l'arbitre indifférent.** Il n'est ni sauveur ni ennemi : c'est la **règle Y1** incarnée. Ses signes s'installent dès le ch. 8 (tempêtes mesurées à l'Institut Météo, Absol, vision de Morgane). Il descend au ch. 13 si la condition est remplie, ce qui est le cas dans presque toutes les parties, car la surcharge d'Amaryllis y pousse. Ce qu'il détruit dépend de **ce que les humains ont fait de la Fiole avant son arrivée** (§12).

**Hors champ, volontairement :**
- Groudon et Kyogre (une descente de Rayquaza les menace : on en parle, on ne les montre pas) ;
- Mewtwo (le passé de Fuji ; anneau au postgame) ;
- Deoxys (météorite de Kosmo ; postgame).

Règle : **on développe Hoopa et Rayquaza avant d'en ajouter** (3e loi de Sanderson).

**Contre le deus ex machina.** Aucun légendaire ne résout le problème. L'issue est fixée par l'état accumulé : confiance de Hoopa, détenteur de la Fiole, réputation des gardiens, pression des anneaux, affectations au climax.

---

## 7. Les factions

Deux axes de désaccord. Les positions sont **contradictoires deux à deux**, et personne ne peut plaire à tous.
- **Axe A, les arrivants :** REMPART (expulser, abattre) / INTÉGRATION (sanctuaires, accueil) / MARCHÉ (exploiter, vendre) / RAPATRIEMENT (rendre aux régions d'origine).
- **Axe B, la Fiole et le réseau :** SCEAU (rescellement) / CONTRÔLE (Passerelle régulée) / LIBÉRATION (Hoopa réuni) / BRISER (sans Hoopa) / LE CIEL JUGE (Rayquaza).

| Faction | Chef(s) | Membres clés | A raison sur… | A tort sur… | Axe A / Axe B | Ce qu'elle attend de Red | Signature mécanique | Var |
|---|---|---|---|---|---|---|---|---|
| **Ligue de Hoenn / Plan Rempart** | Norman (chef du Rempart), Pierre Rochard (Maître, réticent) | Flora, Seko (en partie), brigades | les natifs disparaissent : il faut agir vite | abattre par peur et fermer les ports nourrit le marché noir | REMPART / SCEAU puis CONTRÔLE | obéir à l'accréditation, témoigner | barrages de brigade sur des routes ; tables « abattues » (moins d'arrivants **et** de natifs) | `rL` |
| **Consortium Passerelle** | M. Rochard, Président de Sylphe | Lanette, Léo (au début), Ciléo (au début) | Hoenn vit du commerce : couper, c'est la ruine | ils exploitent une créature et refusent de savoir | MARCHÉ / CONTRÔLE | soutien public, silence | Kiosque, prix des boutiques, emplois à Mérouville | `rC` |
| **Team Magma** | Max | Kelvin, Courtney, Auguste (consultant) | le phénomène doit être **géré**, pas subi | jouer aux dieux avec des anneaux déclenchés | REMPART géré (redistribuer) / CONTRÔLE (par eux) | données, protection de la démonstration | anneaux déclenchés (ch. 6) qui vident un lieu pour en remplir un autre | `rM` |
| **Team Aqua** | Arthur | Sarah (doute), Matthieu | enchaîner une créature est un crime ; tout Pokémon a le droit de vivre | sabotages qui ruinent les pêcheurs ; couper le câble = tempête | INTÉGRATION / LIBÉRATION puis BRISER | complicité, données de Sarah | libérations de bancs ; câble (ch. 11) | `rA` |
| **Mission Indigo** | Peter | Major Bob, Ondine, Erika, Pierre (Brock), Koga et Jeannine, Morgane, Olga, Aldo (escorte) | Kanto n'est pas seul coupable ; les Pokémon de Kanto doivent rentrer | elle protège l'image de Kanto avant la vérité | RAPATRIEMENT / SCEAU (divisée : voir §9) | réhabiliter Kanto | Défis Indigo ; présence par ville | `rI` |
| **Gardiens** (Peuple du Météore, Sages d'Atalanopolis) | Doyenne du Peuple du Météore ; Marc (gardien) | Aragon (sympathisant) | la Fiole doit revenir au Pilier | le sceau est né de la peur ; il condamne Hoopa | indifférents / SCEAU | rendre la Fiole | rite, retardement de Rayquaza | `rG` |
| **Amaryllis** (dissidente) | Amaryllis | Aster ; quelques fidèles | le réseau déchire le ciel ; il faut l'arrêter | appeler un dieu qui ne distingue pas | — / LE CIEL JUGE | rien : elle le teste | **surcharge** : `PA` monte après ses actes, anomalies P2 | relation `AM` |
| **Team Rocket** | Ariane (opérations à Hoenn), Amos (stratège, arrive tard) | Lance (Rocket), Lambda | — (aucun diagnostic juste : c'est la faction égoïste lisible) | tout | MARCHÉ / VOLER la Fiole (arme pour voler n'importe quoi, n'importe où : le retour de Giovanni) | rien ; l'éliminer | sbires présents **avant** les anneaux ; recrutement des ruinés | état `RK` |
| **Communautés** (pêcheurs, fermiers, mineurs, commerçants) | porte-paroles locaux | — | leurs vies s'effondrent | xénophobie, primes | REMPART ou MARCHÉ / SCEAU | du concret | PNJ, prix, recrutement Rocket si abandonnées | `rP` |
| *Indépendants influents* | Giovanni, Fuji, Chen, Seko, Scott | — | voir §9 | — | — | — | — | relations |

**Qui gagne si X échoue (anti-fusion des antagonistes) :**
- si le Rempart échoue : le marché (Consortium, Rocket) gagne ;
- si le Consortium échoue : Magma et Aqua gagnent en influence, et les Communautés perdent leurs emplois ;
- si Aqua échoue : le Rempart gagne ;
- si Amaryllis échoue : le Consortium respire, les Gardiens perdent leur levier ;
- si la Rocket échoue : tout le monde, mais Giovanni y gagne en dignité.

Aucune paire ne gagne toujours ensemble.

---

## 8. Structure : actes, chapitres, pistes, plafonds

### 8.1 Pistes parallèles (la progression n'est pas réduite aux badges)
| Piste | Matérialisation | Lecture |
|---|---|---|
| **Accréditation** (badges) | Loi d'urgence de la Ligue : un dresseur étranger doit être accrédité, niveau par niveau, pour utiliser des capacités de terrain en zone de crise et pour entrer dans un périmètre d'anneau. Chaque Champion accorde son badge **après la crise de sa ville (quelle qu'en soit l'issue) et un combat**. Sa réplique change selon l'issue | portes vanilla, capacités de terrain |
| **Enquête** (Dossier) | pièces (flags) rangées dans le Carnet ; montrées au Sommet | R1–R4 ; motions ; options de fin |
| **Factions** | réputations | barrages, aides, votes, fins |
| **Défis** | Défis Indigo, Tournoi des Confluences, duels d'histoire (§10) | objets, relations, scènes |
| **Recensement** | Pokédex, carte des anneaux de Brice, états d'écosystème | R2, tables de rencontre, épilogue |
| **Relations** | relations cachées | qui vient au climax ; voix de Brice ; fins |

### 8.2 Actes
| Acte | Ch. | Badges | Durée cible | Révélation | Morceau de bravoure | Respiration |
|---|---|---|---|---|---|---|
| Prologue « La Passe » | 0 | — | 0:00–0:50 | — | plage : force puis perte | maison de M. Marco, labo de Seko |
| I « Les Arrivants » | 1–4 | 1–3 | 0:50–7:00 | **R1** | débarquement de la Mission Indigo (ch. 3) ; raid du Tunnel (ch. 4) | Myokara, Tente de Combat |
| IIa « Le Réseau » | 5–7 | 4–5 | 7:00–12:30 | **R2** (mi-parcours) | démonstration de Magma (ch. 6) | dîner chez les Seko (ch. 7) |
| IIb « L'Échange » | 8–10 | 6–7 | 12:30–18:30 | **R2b**, **R3** | piège de Cimetronelle ; rite du Mont Mémoria ; assaut du Centre Spatial | Concours de Nénucrique, toit avec Blue |
| III « Le Ciel » | 11–13 | 8 | 18:30–23:30 | **R4** | Sommet interrompu ; Nuit des Anneaux | veillée avant le climax |
| Écho | 14 | — | 23:30–25:30 | — | Route Victoire, Ligue (configurée par la fin) | épilogue en diaporama |
| Postgame | P1–P8 | — | +6–10 h | couches cachées (fin cachée du Dossier complet) | retours, départs canoniques | — |

### 8.3 Chapitres (cartes, paires, crises, révélations, jalons)
Notation : `Dx–Dy` = budget de décisions (le brief C les numérote) ; **L** = décision de classe L (scène ou carte qui change).

| Ch. | Cartes (vanilla) | Paire Kanto / Hoenn | Crise et événements clés | Révél. | Décisions | Jalon de plafond (posé dans **toutes** les branches) |
|---|---|---|---|---|---|---|
| 0 | R104 plage (nuit), maison de M. Marco, Clémenti, R102, Rosyères, R101, Bourg-en-Vol (labo, maison Seko), R103 | Ciléo / M. Marco | débarquement clandestin ; **3 combats avec l'équipe complète de Red (niv. 60–65)** contre une horde d'arrivants ; l'anneau emporte l'équipe ; Pikachu blessé ; Brice (ronde de recensement nocturne) ; starter de Seko ; accréditation par téléphone avec Norman (nom ou anonymat) ; lettre de Chen ; Brice à la R103 | — | 7 (**L** : qui Red rattrape dans l'anneau) | départ : plafond 14 |
| 1 | Clémenti (arène = QG du Rempart), R104, Bois Clémenti, Mérouville (arène, Devon 1F–3F, École), R116 (entrée ouest du tunnel) | Pierre (Brock) / Roxanne ; Président de Sylphe / M. Rochard ; Léo, Lanette | Flora et la brigade au Bois ; mines envahies ; **présentation de Passerelle** ; lettre pour Pierre Rochard ; 1er vol du petit voleur (carnet de Brice) ; R116 : contrebandiers Rocket postés **avant** un anneau (serrure vue : rochers du tunnel) | Q2 ouverte | 10 | badge 1 → 18 |
| 2 | R104 (bateau), Myokara (arène, salle), R106, Grotte Granite | Aldo / Bastien | pêcheries ; Pierre Rochard étudie les traces minérales des anneaux (éclats rouges et bleus) ; petit voleur n° 2 | — | 7 | badge 2 → 20 |
| 3 | R107–109, maison de la plage, Poivressel (port, chantier naval, musée, marché, Tente de Combat), R110 sud | **Débarquement de la Mission Indigo** : Peter, Major Bob, Ondine, Olga, Erika, Morgane, Koga et Jeannine ; Chen rejoint Seko | ports rouverts à la seule Mission ; Kiosque Passerelle (apprentissage de H1) ; **Blue 1** (Tente de Scott, refusable) ; l'homme au Persian (Giovanni) ; composant Devon remis au Capitaine Marin (relevé du câble) ; rumeur de marché noir | — | 11 | Blue 1 réglé (gagné, perdu ou refusé) **ou** sortie de Poivressel → 22 |
| 4 | R110, Lavandia (arène, Nouvelle Lavandia en extérieur), R117, Vergazon, Tunnel Mérazon | Major Bob / Voltère ; Erika / Timmy | anneaux groupés autour de la centrale ; périmètre militaire ; vergers ; Timmy et son arrivant condamné ; **raid du Tunnel** avec Brice (prédicteur, Lance (Rocket)) ; retour de Pikachu (Seko) | **R1** | 10 (**L** : approche du raid) | badge 3 → 25 ; raid (toutes issues) → 27 |
| 5 | R111 sud, R112, Chemin Ardent, R113, atelier du verrier, Autéquia (maison de Kosmo), R114 (maison de Lanette), Chutes Météore 1F_1R | Peter / Amaryllis (arbitre : Aragon) ; Léo / Lanette ; quête facultative de Bayar (ruines du désert, par Éclate-Roc) | journaux de Lanette ; les « étoiles filantes » de Kosmo sont des éclairs d'anneaux ; conte du Voleur d'Anneaux ; affrontement de clans au Site Météore ; relevés de Magma ; **la sécurité Magma de la R112 est levée à la fin de l'événement, quelle que soit l'issue** | Q3 ouverte | 8 | Site Météore → 29 |
| 6 | téléphérique, Mont Chimnée, Chemin Ardent, Vermilava (arène), Planque Magma 1F et 2F_1R | Auguste / Max ; Erika / Adriane | troupeau étranger dans les champs ; **démonstration de Magma** (anneau déclenché qui déplace le troupeau, puis les Pokémon des sources disparaissent) ; Aqua manifeste ; la planque Magma montre l'horaire volé (vendu par Lambda aux deux camps) ; Lunettes Sable (Brice) | fausse piste | 9 (**L** : soutenir, saboter ou dénoncer la démonstration) | badge 4 → 32 |
| 7 | R112 → Lavandia → R117 → Vergazon → Tunnel → R116 → Mérouville → R104 → Clémenti → Bourg-en-Vol | Chen / Seko ; Norman / Major Bob ; Flora / Timmy | **trajet avec du contenu** (contre la critique N17) : filature de Lambda déguisé (à remarquer) ; Timmy contre la brigade à Vergazon ; Léo remet l'enregistrement du « battement » ; à Bourg-en-Vol, la carte de Brice superposée aux journaux donne **R2** ; Brice décide seul s'il publie ; vote d'abattage du Rempart ; Norman (badge 5) remet Surf | **R2** | 9 (**L** : Brice et la publication, réaction de Red) | R2 → 33 ; badge 5 → 35 |
| 8 | R118, R119, Institut Météo, Cimetronelle (arène), R120 | Koga et Jeannine / Alizée ; Morgane / Pierre Rochard ; Sarah (Aqua) | Institut occupé par Sarah (données de tempête : les signes de Rayquaza) ; Brice 3 → Vol ; canopée ; **piège de Koga : le voleur est Hoopa Confiné** ; R120 : Méga-Bracelet et Scope ; vision de Morgane ; Absol | **R2b**, Q4 ouverte | 10 (**L** : garde de Hoopa) | Institut → 37 ; badge 6 → 40 |
| 9 | R121, entrée du Parc Safari, Nénucrique (toit du Grand Magasin, salle des Concours, port), Planque Aqua 1F/B1F, R122, Mont Mémoria | Olga / Glacia ; Agatha et Fuji / Spectra ; Ondine / Arthur ; Nina / Marc ; Blue et Giovanni (toit) ; Damien | marché noir : **coup de filet avec Olga ou raid Aqua la même nuit (présence exclusive)** ; plan d'Arthur (couper le câble) ; rite du Mont Mémoria ; les spectres montrent ce qui est parti ; **inscription du Sceau** ; Lance (Rocket) la copie ; plan de Fuji ; **la R124 s'ouvre quand planque et Mont Mémoria sont faits** | **R3** | 12 (**L** : la nuit du marché) | planque → 42 ; Mont Mémoria → 44 |
| 10 | R124, Algatia (arène, Centre Spatial 1F/2F, maison de Pierre Rochard), R125 | Morgane / Lévy et Tatia ; Ciléo ; Amos | badge 7 ; **assaut Rocket du relais** (Ariane, plus Lambda déguisé en Giovanni) ; duo (partenaire selon les relations) ; **le vrai Giovanni désavoue** ; Ciléo voit la Fiole dans le cœur du relais ; Plongée (Pierre Rochard) | Fiole vue | 8 | badge 7 → 47 ; Centre Spatial (toutes issues) → 49 |
| 11 | R127/128, sous-marin 128, Grotte Tréfonds | Arthur et Sarah / Capitaine Marin et Ondine | opération Aqua pour couper le câble ; Sarah doute ; négocier, combattre, laisser faire | — | 5 | Grotte Tréfonds → 51 (**prérequis du Sommet**) |
| 12 | sous-marin 126, Atalanopolis (arène, place), Grotte Originelle fermée | Juan et Marc / Peter et Pierre Rochard ; Doyenne ; tous les chefs | Juan → badge 8 (Cascade) ; puis **Sommet des Confluences** (3 motions, négociation par gestes) ; **R4 pendant la séance** ; interruption : tempête d'anneaux, assaut Rocket, Rayquaza s'éveille | **R4** | 9 | badge 8 → 53 |
| 13 | Atalanopolis ou Nénucrique (civils), Centre Spatial (relais, Fiole), Pilier Céleste (warp vers le sommet ; aucun Vélo Cross requis) | tous | veillée : chaque allié **dit** ce qu'il peut tenir ; affectation ; résolution de la Fiole ; Rayquaza | — | 7 | climax (toutes issues) → 56 |
| 14 | R128, Éternara, Route Victoire, Ligue, Panthéon | Blue ; Conseil 4 de Hoenn ; Maître (Pierre Rochard **ou** Marc) | Blue final ; Ligue = **écho** de la fin (équipes et répliques selon l'état) ; épilogue en diaporama | — | 3 | Maître → 60 ; postgame 75, puis 100 |
| P | Zone de Combat, Pilier, lieux d'anneaux, Bourg-en-Vol… | départs canoniques | retour de l'équipe de Red ; anneaux légendaires ; dernier duel de Giovanni ; Mewtwo et Fuji ; Tournoi | couches cachées | 6 | — |

**Budget :** 131 décisions listées, cible ≥ 115 robustes (brief C).

**Règles de portes et d'accès** (leçons v2 ; table vanilla de référence : `archive/cendres_v2/GAME_DESIGN_BIBLE.md` §10, à **re-vérifier** pour chaque changement) :
- ordre des badges et correspondance badges → capacités vanilla conservés ;
- les drapeaux de livraison vanilla gardent leur sens. Lettre pour Pierre Rochard. Composant Devon pour le Capitaine Marin : poser `FLAG_DELIVERED_DEVON_GOODS` dans **tous** les cas (ce drapeau a 6 lecteurs vanilla) ;
- chaque barrage vanilla Magma ou Aqua réutilisé est levé par un événement qui se termine dans **toutes** les branches ;
- le Sommet exige la Grotte Tréfonds ; l'arène d'Atalanopolis se déverrouille à la fin de Tréfonds ;
- au Pilier Céleste, warp scripté vers le sommet (le Vélo Cross n'est pas requis).

**Soins :** aucune zone exigeante à plus de 2 cartes d'un soin. On ajoute des soigneurs PNJ :
- médecin du chantier au Mont Chimnée ;
- secouriste d'Aqua **ou** de repli (Flora / Ondine) à Tréfonds ;
- la Doyenne avant le Pilier Céleste ;
- un soin forcé avant la veillée.

---

## 9. La distribution chorale (aucun figurant)

Lecture :
- **Veut → Besoin** (Truby).
- **Agenda** : É = égoïste, A = altruiste, M = mixte.
- **Position** : axe A / axe B (§7).
- **Pulsations** : P = présentation, É = épreuve, B = bascule, E = écho.
- **Combats** : H = d'histoire, L = libre (Défi Indigo, Tournoi, duel refusable) ; T1–T5 = paliers (§10).
- **Test du figurant :** chacun a un projet qui avancerait **sans Red**.

Rangs :
- **Rang A** (≥ 6 scènes, arc complet) ;
- **Rang B** (≥ 4 pulsations) ;
- **Rang C** (≥ 2 scènes + un écho), avec une relation et un agenda : ce ne sont **pas** des figurants.

### 9.1 Noyau (rang A)
| Perso | Fonction | Veut → Besoin | Agenda | Position | Alliés · Rivaux (PNJ) | Pulsations | Combats et adaptation |
|---|---|---|---|---|---|---|---|
| **Red** (joueur) | témoin et acteur par gestes | retrouver son équipe, réparer → accepter qu'on ne répare pas seul | M | choisie | Brice, Ciléo · Blue, Giovanni | P ch. 0 (force puis perte) ; É ch. 7 (sa part du réseau) ; B ch. 12 (la chaîne) ; E départ vers le nord | — |
| **Brice** | second protagoniste, voix, recenseur | être utile à son père → avoir son propre avis | A | **émerge de ce qu'il a vu** (`BV` : PROTÉGER, ACCUEILLIR ou COMPRENDRE) | Red, Flora (amitié tendue), Chen (admiration) · Seko, Flora (positions) | P ch. 0 sauvetage ; É ch. 5 (ses données contredisent son père) ; B ch. 7 (publie ou se tait, **seul**) ; B2 ch. 12 (vote **à lui**, même contre Red) ; E voix de l'épilogue | H : R103, R110, R119 ; ch. 12 refusable ; L : postgame. Son équipe contient les arrivants protégés ou des natifs selon `BV`, plus le starter fort contre le vôtre |
| **Blue** | rival miroir, comédie et blessure | battre Red → valoir sans être premier, aimer ses Pokémon | É | MARCHÉ (Scott) → libre / indifférent | Scott (tentation), Nina · Red, Peter (honte), Giovanni (héritage de Jadielle) | P ch. 3 défi ; É ch. 9 (aveu sur le toit, rencontre Giovanni) ; B ch. 13 (vient ou non) ; E Route Victoire et départ pour Jadielle | H ch. 3, ch. 9 (refusables), ch. 14 (obligatoire) ; L : Tournoi. **Adaptatif** : contre le type dominant de l'équipe du joueur (aide moteur E-ADAPT), plus une variante selon `BL` |
| **Hoopa** (Confiné) | cœur mythique muet | retrouver son pouvoir → un échange juste (confiance) | É puis ? | LIBÉRATION | Fuji, Aqua · Koga (piège), Rocket, Consortium | P ch. 1 vol ; É ch. 6 (blessé par l'anneau de Magma) ; B ch. 8 révélé ; E fin (§12) | aucun combat pendant l'histoire (suiveur PNJ) ; postgame : obtenable dans toutes les fins (canal par fin) |
| **Amaryllis** | antagoniste croyante | faire descendre Rayquaza, venger la gardienne → admettre que la colère d'un dieu n'est pas une justice | M | — / LE CIEL JUGE | Aster, Aragon (respect), Doyenne (tension) · Peter (clans), Rocket (vengeance), Pierre Rochard | P ch. 5 ; É ch. 8 (tempête) et ch. 10 (surcharge entrevue) ; B ch. 13 (renonce, persiste ou se sacrifie, selon `AM` et les preuves) ; E épilogue | H ch. 5, ch. 10, ch. 13 ; L postgame. Dragons et Méga-Drattak après le ch. 8 ; au climax, **une anomalie P2** dans l'équipe si `PA` est haut |
| **Giovanni** | ombre, clé du noyau | mériter son retour seul → (il ne change pas : il renonce, canon) | É (orgueil) | MARCHÉ / « pas comme ça » (refuse le dieu volé) | Persian · Red, Ariane et Lambda (mépris), Président de Sylphe, M. Rochard | P ch. 3 (l'homme au Persian) ; É ch. 6 (corrige des sbires négligents) ; B ch. 10 (désavoue Lambda) ; E ch. 12 témoignage (si `GI` le permet), postgame dernier duel et départ (« s'entraîner », canon) | L ch. 6 incognito (refusable) ; L postgame (T5). Noyau Sol, satellites Ténèbres ; jamais Mewtwo |
| **Peter** | chef de la Mission Indigo | laver Kanto, abattre la Rocket → écouter les gens du lieu | M | RAPATRIEMENT / SCEAU | Pierre Rochard, Major Bob, Olga · Amaryllis et Aragon (clans), Koga (méfiance), Blue | P ch. 3 débarquement ; É ch. 5 (piétine ou respecte le Site Météore) ; B ch. 12 (Kanto assume sa part ou non) ; E rentre Maître (canon) | H ch. 5 (duo ou contre Amaryllis), ch. 13 allié ; L Défi Indigo dès le ch. 10. Dragons ; Drattak s'il respecte les gardiens |
| **Pierre Rochard** | Maître de Hoenn, fils de Devon | protéger Hoenn et son père → affronter son père | M | INTÉGRATION prudente / SCEAU ou CONTRÔLE (déchiré) | Marc, Peter, Red · M. Rochard, Max, Arthur | P ch. 2 ; É ch. 8 (Méga-Bracelet, doute) ; B ch. 12 (accuse ou protège son père) ; E Maître, **ou** démission (Marc devient Maître) et départ pour Kanto (canon HGSS) | H ch. 8 duo, ch. 10 duo, ch. 14 Maître ; L postgame. Méga-Métalosse |
| **Prof. Chen** | science de Kanto, faute ancienne | être le premier à cataloguer → reconnaître Seko et Blue, avouer | É | INTÉGRATION / COMPRENDRE | Nina, Brice · Seko, Agatha | P ch. 3 ; É ch. 7 (clash avec Seko) ; B ch. 9 et 12 (Agatha révèle l'article ; il avoue ou nie) ; E épilogue | L postgame (vétéran ; HYPOTHÈSE non canon) |
| **Prof. Seko** | science de Hoenn, père | publier avant Chen, protéger les natifs → écouter son fils | É/A | REMPART doux / SCEAU | Norman, Mme Seko · Chen, Brice | P ch. 0 ; É ch. 4 (ramène Pikachu) ; B ch. 7 ; E épilogue | aucun |
| **Flora** | héroïne qui aurait pu l'être, cadette du Rempart | prouver qu'elle sert → son propre jugement | M | REMPART / SCEAU | Norman, Brice · Brice (positions), Timmy (abattage) | P ch. 1 Bois ; É ch. 7 Vergazon ; B ch. 13 (désobéit ou non) ; E épilogue | H ch. 1 (refusable), ch. 7 ; L. Équipe de brigade (natifs) ou mixte si elle bascule |

### 9.2 Mission Indigo et Kanto (rang B sauf mention)
| Perso | Fonction | Veut → Besoin | Agenda | Position | Alliés · Rivaux | Présence et pulsations | Combats |
|---|---|---|---|---|---|---|---|
| **Pierre** (Brock) | éleveur | quitter l'arène pour soigner → assumer qu'on ne sauve pas tout | É/A | INTÉGRATION / COMPRENDRE | Roxanne, Timmy · mineurs, Major Bob | ch. 1 mines (P), ch. 7 (É : ses protégés condamnés), ch. 12 vote (B), épilogue élevage (E) | H ch. 1 (duo possible) ; L. Roche défensive, plus les arrivants adoptés s'ils ont été sauvés |
| **Ondine** | action directe | libérer les Eau des filets (A), défier Marc (É) → mesurer les conséquences | M | INTÉGRATION / LIBÉRATION | Arthur (temporaire), Marc · Major Bob, Aldo | ch. 3, ch. 9 (libère un banc : pêcheurs ruinés), ch. 11 (Aqua ou Mission), E | L ; H ch. 11 selon le camp choisi |
| **Major Bob** | logisticien militaire | contenir par la force → voir les gens derrière les chiffres | A (ordre) | REMPART / SCEAU | Voltère, Norman · Ondine, Erika | ch. 3, ch. 4 (coupe un quartier), ch. 7 (vote), ch. 13 évacuation | L ; H ch. 4 (exercice refusable) |
| **Erika** | parfumeuse d'affaires | contrat de parfum avec une fleur arrivante → choisir entre profit et vergers | É | MARCHÉ → INTÉGRATION / CONTRÔLE | Adriane, Timmy · Major Bob, Consortium (négociation) | ch. 4, ch. 6, ch. 7 ou 9, E | L |
| **Koga** | espion ambigu | un siège au Conseil 4, la tête de la Rocket → (ambiguïté : ancien de la Rocket ? HYPOTHÈSE inspirée du manga) | É | — / CONTRÔLE (pour Indigo) | Jeannine, Peter (méfiant) · Rocket, Hoopa | ch. 3, ch. 8 (piège), ch. 10 (révèle son double jeu), E (Conseil 4) | H ch. 8 si Red lui dispute Hoopa ; L |
| **Jeannine** (rang C) | héritière | égaler son père | É | — | Koga · Koga | ch. 3, ch. 8, E | L (sprite de repli) |
| **Morgane** | voyante | comprendre sa vision → une prophétie n'est pas un ordre | M | — / SCEAU (elle craint le dragon) | Lévy et Tatia, Capucine · Amaryllis | ch. 3, ch. 8 (vision), ch. 10, ch. 13 | L |
| **Auguste** | consultant de Magma, conscience | payer la reconstruction de Cramois'Île → refuser de refaire Mewtwo | M | REMPART géré → LIBÉRATION | Max, Fuji · Adriane | ch. 6 (démonstration, sources), ch. 9 (rejoint Fuji ou reste), ch. 12, E (rentre : le volcan gronde) | L |
| **Olga** | traque les Lokhlass de Sevii | récupérer ses Lokhlass → accepter l'aide de Hoenn | A/É | RAPATRIEMENT / SCEAU | Glacia, Damien · Rocket, marchands | ch. 3, ch. 9 coup de filet, ch. 12, E (Île 4) | H ch. 9 duo ; L |
| **Aldo** | ascète | un adversaire digne → s'engager | É | REMPART (avec les pêcheurs) / — | Bastien · Ondine | ch. 2, ch. 11 ou Tournoi, E | L |
| **Agatha** | deuil et rancune | ramener les spectres de Lavanville, régler ses comptes avec Chen → transmettre, pardonner | M | — / SCEAU | Spectra, Fuji · Chen | ch. 9 (P/É), ch. 12 (B : révèle l'article), E retraite (canon) | L ; H ch. 9 si le rite est profané |
| **Léo** (Bill) | concepteur de la couche de transfert | sauver son invention → dire la vérité à ses dépens | M | INTÉGRATION / LIBÉRATION | Lanette (rivale), Ciléo · Président de Sylphe | ch. 1, ch. 5, ch. 7 (aveu), ch. 10 | aucun |
| **Ciléo** | opérateur du nœud Kanto | prouver que sa machine est saine → admettre | É | — / CONTRÔLE → LIBÉRATION | Red, Léo · Lanette | ch. 0, ch. 3, ch. 10 (voit le cœur), ch. 12 (registre du coffre) | aucun |
| **M. Fuji** | conscience extrême | libérer Hoopa à tout prix → sa pénitence ne justifie pas un désastre | A | INTÉGRATION / LIBÉRATION ou BRISER | Auguste, Agatha · Président de Sylphe | ch. 9, ch. 12, ch. 13 (peut briser la Fiole), postgame (Mewtwo) | aucun |
| **Président de Sylphe** | homme d'affaires coupable | sauver Sylphe → assumer | É | MARCHÉ / CONTRÔLE | M. Rochard (partenaire et rival) · Giovanni, Fuji | ch. 1, ch. 3, ch. 10, ch. 12 (confession ou chute) | aucun |
| **Nina** (rang C) | médiatrice des Concours | un ruban de Hoenn ; veiller sur Blue | A | INTÉGRATION / — | Marc, Blue | ch. 3, ch. 9, E | aucun (pas de portrait) |
| **Ariane** (Rocket) | cheffe des opérations | prouver sa valeur, ramener Giovanni → (ne change pas) | É | MARCHÉ / VOLER | Lance (Rocket) · Amos (méthode), Giovanni | ch. 1 (indirect), ch. 6, ch. 10 (assaut), ch. 13 ; réplique juste : « Votre Ligue les parque, nous on les paie » | H ch. 10, ch. 13 |
| **Lambda** (Rocket) | imitateur | réussir le coup du siècle | É | — / VOLER | Ariane · tous | infiltré en ingénieur de Passerelle (ch. 1–7, indices), faux Giovanni (ch. 10), démasqué | H ch. 10 ; Zoroark ou Métamorph (gimmick lisible) |
| **Lance** (Rocket) | cruel, homme de terrain | encaisser les primes du Rempart | É | REMPART cynique / VOLER | Ariane · Peter | ch. 1 (R116), ch. 4 (Tunnel), ch. 9 (profane le Mont Mémoria) | H ch. 4, ch. 9 |
| **Amos** (Rocket, rang C) | stratège | un retour « digne » | É | — | Giovanni (loyauté) · Ariane | lettres (ch. 6), ch. 10 et ch. 12 | H ch. 13 selon `RK` |

### 9.3 Hoenn (rang B sauf mention)
| Perso | Fonction | Veut → Besoin | Agenda | Position | Alliés · Rivaux | Présence et pulsations | Combats |
|---|---|---|---|---|---|---|---|
| **Norman** | chef du Rempart, registraire | l'ordre → voir sa fille | A | REMPART / SCEAU | Major Bob, Seko · Chen, Erika | ch. 0 (téléphone), ch. 1, ch. 7, ch. 12 | badge 5 ; L postgame |
| **Timmy** | enfant qui adopte un arrivant | garder son ami → se battre pour lui ou le laisser partir | M | INTÉGRATION | Erika, Pierre (Brock) · Flora | ch. 4, ch. 7, ch. 14 ou postgame | H ch. 7 (refusable) ; L. Son arrivant est dans l'équipe s'il a été sauvé |
| **M. Rochard** | Devon | sauver Devon et les emplois de Mérouville → dire la vérité à son fils | É | MARCHÉ / CONTRÔLE | Président de Sylphe · Pierre Rochard, Giovanni | ch. 1, ch. 7, ch. 12 | aucun |
| **Marc** | gardien d'Atalanopolis, Concours | préserver la tradition et le spectacle → choisir entre les sages et son ami | M | INTÉGRATION / SCEAU | Juan, Pierre Rochard, Nina · Doyenne | ch. 9, ch. 12, ch. 14 (Maître si Pierre Rochard démissionne) | H ch. 14 (conditionnel) ; L |
| **Juan** | arbitre moral du Sommet | l'impartialité → prendre parti | A | — | Marc · — | ch. 12, E | badge 8 ; L |
| **Roxanne** | pédagogue | des données, pas des cris | A | REMPART prudent | Pierre (Brock) · mineurs | ch. 1 (P/É), ch. 7 (relevés), E | badge 1 ; L |
| **Bastien** | surfeur | défendre les arrivants des vagues | A | INTÉGRATION | Aldo · pêcheurs | ch. 2, E | badge 2 ; L |
| **Voltère** | bâtisseur | garder le courant de Lavandia | É civique | MARCHÉ / CONTRÔLE | Major Bob · Aqua | ch. 4, E | badge 3 ; L |
| **Adriane** | jeune héritière | sauver les sources | A | — / SCEAU | Erika · Max, Auguste | ch. 6, E | badge 4 ; L |
| **Alizée** | gardienne de la canopée | sauver les nids | A | REMPART | Koga · Amaryllis (ciel) | ch. 8, E | badge 6 ; L |
| **Lévy et Tatia** | télépathes | comprendre la « voix » du relais (Hoopa) | A | — / LIBÉRATION | Morgane · Consortium | ch. 10, E | badge 7 (double) ; L |
| **Damien** | indic de la rue | protéger les petits trafics des siens | É | MARCHÉ | Olga (marché) · Rocket | ch. 9, ch. 14 | Conseil 4 ; L |
| **Spectra** | Mont Mémoria | être reconnue par Agatha | A | — / SCEAU | Agatha · Lance (Rocket) | ch. 9, ch. 14 | Conseil 4 ; L |
| **Glacia** | arrivante elle-même | empathie pour les arrivants | A | INTÉGRATION | Olga · Rempart | ch. 9, ch. 14 | Conseil 4 ; L |
| **Aragon** | ancien marin lié au Peuple du Météore | apaiser les clans | A | — / SCEAU | Amaryllis, Doyenne · Peter | ch. 5 (arbitre), ch. 14 | Conseil 4 ; L |
| **Max** | Magma, technocrate | répartir les espèces par anneaux contrôlés → écouter ceux qui paient | M | REMPART géré / CONTRÔLE | Auguste, Kelvin · Arthur, Pierre Rochard | ch. 5, ch. 6 (P/É), ch. 12 (B), E | H ch. 6 ; L |
| **Arthur** | Aqua | libérer Hoopa, accueillir tous → mesurer | M | INTÉGRATION / LIBÉRATION puis BRISER | Ondine, Sarah · Max, Rempart | ch. 6 (manifestation), ch. 9, ch. 11 (B), E | H ch. 9 ou ch. 11 ; L |
| **Kelvin, Courtney, Matthieu, Sarah** (rang C) | admins | Kelvin : reconnaissance de Max ; Courtney : loyauté instable ; Matthieu : protéger les siens ; **Sarah : la vérité des données** (doute) | — | camp | camp · camp adverse | ch. 6, 8, 9, 11 | H |
| **Scott** (rang C) | impresario | profiter des imports (Usine de Combat), recruter des stars | É | MARCHÉ | Blue · — | ch. 3, ch. 9, postgame | — (Tournoi) |
| **Têtes de la Zone** (rang C) | postgame ; **Bayar** au ch. 5 (sceaux anciens), **Capucine** liée à Morgane | variés | — | — | — | ch. 5 (Bayar), postgame | L postgame |
| **Kosmo, Lanette, M. Marco, Capitaine Marin, Mme Seko, Doyenne du Peuple du Météore, Sages** (rang C) | savoir, logs, passeur (Piko disparu), câble, foyer, rite, tradition | chacun un projet propre (brief A) | — | — | — | 2–3 scènes + écho | — |

**Règles de la toile relationnelle** (brief A) :
- chaque majeur a au moins **une alliance et une rivalité avec un PNJ** ;
- au moins 6 scènes où **Red n'est que témoin** (exemples : Chen/Agatha, Blue/Giovanni, Peter/Amaryllis, Pierre Rochard/M. Rochard, Brice/Flora, Ondine/Aldo) ;
- au moins 5 relations entre PNJ que le joueur **déplace** (alliance Ondine–Arthur, réconciliation Chen–Seko, Flora qui bascule, Auguste qui rejoint Fuji, Koga démasqué ou couvert).

---

## 10. Combats hors badges et équipes adaptatives

**Formats :**
1. **Défis Indigo.** Chaque membre de la Mission propose un duel quand la crise de sa ville est close. Le duel est refusable avec `trainerbattle_single_declinable`, et le refus est définitif. Il n'est une **décision** que si le refus ou la victoire change un état lu plus tard.
2. **Tournoi des Confluences** (Scott). Tente de Poivressel dès le ch. 3, puis Zone de Combat au postgame. Paliers par plafond. Récompenses : objets, jamais de l'EXP rentable (plafond).
3. **Duels d'histoire.** Soit obligatoires, soit **à deux issues racontées** : jamais de défaite imposée gratuite.
4. **Rivaux.** Brice, Blue, Flora, Timmy.
5. **Postgame.** Équipes T5 complètes, Méga, revanches à la Zone.

**Paliers :**
| Palier | Plafonds | Niveaux des As |
|---|---|---|
| T1 | ≤ 25 | plafond + 2 (As + 3) |
| T2 | 26–38 | idem |
| T3 | 39–53 | idem |
| T4 (climax, Ligue) | 54–60 | idem |
| T5 (postgame) | 70–80 | idem |

**Sélecteurs de variante**, dans cet ordre :
1. palier (plafond courant) ;
2. **position** du personnage (var de relation ou de faction) : l'équipe **raconte** sa position. Les pro-intégration alignent des arrivants qu'ils ont rencontrés à Hoenn ; le Rempart aligne des natifs ;
3. **décisions** (l'arrivant de Timmy, les Lokhlass d'Olga, le Drattak de Peter) ;
4. pour Blue, Giovanni et Peter seulement : **type dominant de l'équipe du joueur** (aide moteur E-ADAPT).

**Construction.** Un noyau canonique de 2 ou 3 Pokémon, puis des satellites Gen 1–9 **justifiés par l'intrigue** : origine cohérente avec §5.3, ou avec le passé du personnage. Validateur `tools/qa/validate_trainers.py --learnsets` : 0 erreur exigée.

**Méga :** une seule par équipe désignée, après l'introduction au ch. 8.

**IA :** flags par palier, justifiés (brief B).

**ID de dresseurs :** recyclés. 324 ID de revanche vanilla, 64 ID de sbires et admins Magma/Aqua, 38 ID de rivaux, plus 9 libres. Les revanches par Cherche VS sont **désactivées** (cohérent avec « pas de farm »).

---

## 11. Systèmes cachés (aperçu ; spécification : brief C)

### 11.1 Inventaire
| Système | Stockage | Échelle | Écrit par | Lecteurs (≥ 2, avant la dernière écriture) | Lisible comment |
|---|---|---|---|---|---|
| Relations (9) : Brice `BR`, Blue `BL`, Flora `FL`, Pierre Rochard `PR`, Peter `PE`, Amaryllis `AM`, Timmy `TI`, Giovanni `GI` (respect), **Hoopa `HO`** (confiance) | vars 0–100, départ 50 (`HO` part de 20) | bornée (`addaffinity`) | décisions, gestes discrets | répliques de saillance, options déverrouillées, qui vient au climax, voix de l'épilogue, fins | réactions, présence, Carnet |
| Réputations (7) : `rL`, `rC`, `rM`, `rA`, `rI`, `rG`, `rP` | vars 0–100 | bornée | décisions | barrages, prix, aides, votes du Sommet (**comparaisons relatives**, ex. `rA > rM`), fins | PNJ, affiches, prix |
| **Pression des anneaux** `PA` | var 0–100 | monte par le Kiosque, la surcharge, les transferts du Consortium soutenus ; baisse par les fermetures de nœuds et les preuves publiées | décisions et événements | fréquence des anneaux (épidémies scriptées), anomalies P2, descente de Rayquaza, options de fin | météo, PNJ, bulletins |
| Emprise Rocket `RK` | var 0–100 | recrutement des ruinés, primes | décisions | sbires sur les routes, assaut du ch. 10, climax, variante Rocket de l'épilogue | sbires locaux reconnus |
| Écosystèmes × 6 zones (`Z-01`–`Z-06`) | 2 flags par zone (ENVAHI / MIXTE / RESTAURÉ) | discret | missions de zone, motion 2 du Sommet | **tables de rencontre alternatives** (aide moteur E-ECO), PNJ, diaporama | ce qu'on rencontre |
| Frontière `FK` | flag ou var (fermée / Mission / ouverte) | discret | ch. 3, ch. 12 | présence de la Mission, postgame | ports |
| Notoriété `N` | var 0–3 | — | ch. 0 (nom ou anonymat), actes publics | portes, Défis, Sommet (qui parle), épilogue | regards, presse |
| Dossier | flags de pièces | — | enquête | Sommet (montrer), R4, options de fin, fin cachée | Carnet |
| Voie de Brice `BV` | var 0–3 | — | **calculée** à partir des scènes où Red a emmené Brice | vote de Brice, équipe de Brice, épilogue | répliques |
| Sommet | option défendue **et** résultat séparés (vars ou bits) | — | ch. 12 | ch. 13, fins | — |
| Climax | flags temporaires + 1 var de résultat de la Fiole | — | ch. 13 | fins, postgame | — |

### 11.2 Règles anti-défauts (issues des revues v2)
1. **Aucun état écrit sans lecteur.** Le brief C fournit une table « lectures par carte ».
2. **Deltas** : ±1 à ±5 pour les décisions courantes, ±8 à ±10 pour les décisions L. Chaque delta est **gardé par un flag à usage unique**.
3. **Seuils calibrés contre le maximum atteignable** : tableau de cumul. Votes par **comparaisons relatives** autant que possible.
4. **Toute option a un gain et une perte, dans deux systèmes différents.** Si une option gagne partout, on la supprime.
5. Au moins **3 paires mutuellement exclusives** par présence et temps : la nuit du marché (ch. 9), le sauvetage ou la filature (ch. 6–7), l'affectation au climax.
6. **Puits d'argent proportionnés** au revenu du chapitre ; « payer » a toujours un coût social (`rP` ou `RK`).
7. **≥ 30 % de décisions discrètes** : gestes envers le petit voleur, refus de combat, présence, don, filature.
8. Les combats refusables passent par la macro D1 : un flag de refus par décision.

### 11.3 Stratégies dominantes cherchées et contre-pressions
| Raccourci du joueur | Jusqu'où il marche | Contre-pression |
|---|---|---|
| « Plaire à tous » | il échoue | les positions sont contradictoires (§7) ; votes relatifs |
| « Payer toujours » | jusqu'au ch. 3 | les prix suivent le revenu ; payer nourrit le marché (`RK`, `rP`) |
| « Tout capturer pour restaurer » | il ne marche jamais | l'état des zones dépend des missions et de la politique, pas des captures |
| « Chemin doré » (Pacte + intégration + Rocket démantelée + toutes les relations ≥ 60) | il ne doit pas exister | le Pacte exige un `HO` haut, ce qui coûte `rC`, `rL` et des objets ; l'affectation au climax empêche d'être partout ; chaque fin a un gain exclusif |
| « Farmer » | il ne marche jamais | plafond souple, pas de revanches, EXP réduite |
| « Utiliser le Kiosque sans limite » | il est plafonné | nombre de commandes plafonné par chapitre ; `PA` et ce que l'anneau prend |

### 11.4 Hypothèses à prototyper en premier (gabarit `GM_METHOD` §3.2, abrégé)
- **Kiosque Passerelle.**
  - Problème : le joueur doit **sentir** la loi H1 avant qu'on la lui dise.
  - Mécanisme : une commande donne un objet rare, `PA` +1, et un anneau prend un élément visible dans une liste définie (objet du sac non-clé, Pokémon d'un PNJ voisin). Pas d'aléatoire sur les objets clés.
  - Prédiction : le joueur hésite à la deuxième commande.
  - Échec : le prix est perçu comme arbitraire ; ou le joueur sauvegarde et recharge.
  - Test : Poivressel, 3 commandes, observation de l'hésitation.
- **États d'écosystème.**
  - Problème : les actes doivent changer ce qui vit ici.
  - Mécanisme : une table alternative par état (E-ECO).
  - Prédiction : le joueur revient voir la route.
  - Échec : différence invisible ; il faut au moins 3 emplacements changés, dont un natif emblématique.
  - Test : R116, avant et après.
- **Confiance de Hoopa.**
  - Problème : de petits gestes doivent compter.
  - Mécanisme : 7 rencontres, gestes discrets, `HO`.
  - Prédiction : à la révélation, le joueur relit ses gestes.
  - Échec : gestes trop rares ou invisibles. Il faut un retour immédiat (Hoopa rend un objet, ou ne revient pas).
  - Test : parcours ch. 1–8 avec deux profils.
- **Affectation au climax.**
  - Problème : un choix de présence éclairé, sans seuil caché.
  - Mécanisme : chaque allié dit ce qu'il tient ; 3 lieux ; résultat déterministe.
  - Prédiction : il n'y a pas d'affectation dominante.
  - Échec : un allié couvre tout.
  - Test : tableau d'affectation × états, avant le script.

---

## 12. Climax, fins, postgame

### 12.1 La Nuit des Anneaux (ch. 13)
La surcharge d'Amaryllis déclenche une **tempête d'anneaux** sur Atalanopolis ou Nénucrique (civils). La Rocket attaque le relais pour prendre la Fiole : c'est leur fenêtre, tous les chefs étant au Sommet. Rayquaza s'éveille au Pilier Céleste.

**Veillée** (soin forcé). Chaque allié disponible, selon ses relations et réputations, **dit** ce qu'il peut tenir (« Je tiens le relais si tu me laisses la Fiole »).

**Trois lieux :**
- **Relais** : la Fiole, la Rocket ;
- **Pilier** : Rayquaza, Amaryllis, le rite ;
- **Civils** : évacuation, Major Bob, Flora.

Red va en un lieu ; 2 ou 3 alliés sont affectés aux autres.

**Invariants :**
- la Rocket **n'obtient jamais** la Fiole ;
- combattre Rayquaza ne fait que **gagner du temps** ;
- aucun seuil caché n'est lu sans avoir été **annoncé** par une réplique de veillée.

### 12.2 Résultat de la Fiole (évaluation ordonnée ; formalisation : brief C)
1. **PACTE** si Hoopa est présent et réuni à la Fiole par quelqu'un en qui il a confiance (`HO` ≥ seuil), **et** si le relais est tenu.
2. **SCEAU** si la Fiole atteint le Pilier avec le rite (`rG` ≥ seuil ou Doyenne présente), **et** si la tempête est contenue.
3. **PASSERELLE** si le relais est tenu par le Consortium et la Ligue (`rC` et `rL`), **et** si `PA` est ramené sous le seuil de Y1 avant l'arrivée de Rayquaza (fermeture des nœuds de surcharge).
4. **CIEL OUVERT** si la Fiole est brisée sans Hoopa (Fuji ou Aqua ; câble coupé au ch. 11 ; `HO` bas).
5. **REMPART** sinon : Rayquaza détruit le relais, les anneaux se referment violemment et Algatia est endommagée.

**Variante sociale (motion 2 du Sommet, plus moyenne des zones) :** REMPART, INTÉGRATION ou MARCHÉ.
**Variantes de personnages :** voix de Brice, Blue (comment il part pour Jadielle), Maître (Pierre Rochard ou Marc), Rocket (`RK` : effectifs, arrestation puis évasion ou fuite ; Giovanni intervient lui-même contre ses commandants si `RK` est haut), Amaryllis, Timmy, Flora, Chen–Seko.

### 12.3 Fins (aucun classement ; chacune a un gain exclusif et une perte)
| Fin | Ce qui arrive | Gain exclusif | Perte | Dernière image |
|---|---|---|---|---|
| **F1 Le Sceau** | Fiole au Pilier ; les anneaux cessent ; les arrivants restent | restauration des natifs la plus rapide ; épreuves du Pilier au postgame | Hoopa exilé, impuissant ; réseau mort, crise économique à Mérouville | Hoopa seul au sommet, qui regarde le ciel |
| **F2 Le Pacte** | Hoopa réuni et libre ; il **équilibre** l'échange : une part des disparus revient, une part des arrivants rentre | l'équipe de Red revient par un anneau ; sites d'anneaux de Hoopa | Hoopa prend « le trésor de qui l'a enchaîné » : Devon et Sylphe ruinées ; Pierre Rochard démissionne (Marc Maître) | un anneau qui rend Piko à M. Marco |
| **F3 La Passerelle** | réseau régulé par une charte ; Hoopa toujours captif mais « rationné » | lien fort Kanto–Hoenn ; boutiques mondiales ; imports pour la Zone de Combat | Hoopa enchaîné (coût moral visible) ; incidents résiduels au postgame | une file au Kiosque ; un anneau minuscule au loin |
| **F4 Le Rempart** | Rayquaza détruit le relais ; fermeture violente ; frontières fermées ; abattages | les natifs protégés ; l'arc d'Amaryllis s'accomplit | Algatia blessée ; la Mission repart en disgrâce ; arrivants abattus ou bloqués | Rayquaza qui remonte ; ruines du Centre Spatial |
| **F5 Le Ciel ouvert** | Fiole brisée ; le pouvoir est sans maître ; Hoopa s'enfuit ; anneaux sauvages imprévisibles | le plus de sites légendaires ; monde le plus mêlé | instabilité (épidémies d'anneaux sur les routes) | un anneau qui s'ouvre au-dessus de Bourg-en-Vol |

**Épilogue :**
- un diaporama de 8–10 plans (Mérouville, Myokara, Vergazon, Vermilava, Nénucrique, Algatia, Pilier, Bourg-en-Vol, Brice, Blue), chacun en 2 ou 3 variantes ;
- une **scène jouable propre** à chaque fin ;
- la **Ligue est l'écho** : répliques du Conseil 4 selon l'état, Maître Pierre Rochard ou Marc ;
- Red part toujours vers le nord.

**Fin cachée** (couche supplémentaire) : Dossier complet **et** Chen a avoué. On apprend ce que les anciens ont scellé **avant** Hoopa (le lien avec les Regis de Bayar), comme ouverture au postgame.

### 12.4 Postgame « Ce que les anneaux ont laissé »
- **Retour de l'équipe de Red dans toutes les fins**, par un canal propre à chaque fin : anneau (F2), Passerelle (F3), PC de Ciléo après des mois (F1), arrivée par la mer avec les Lokhlass d'Olga (F4), anneau sauvage (F5).
- **Toutes les espèces légendaires et fabuleuses** obtenables, par le canal de la fin : anneaux de Hoopa, expéditions Passerelle, anneaux résiduels ouverts par la Doyenne, anneaux sauvages. Conditions par espèce : brief D.
- **Départs canoniques** : Blue vers Jadielle, Koga au Conseil 4, Olga à l'Île 4, Agatha à la retraite, Auguste vers Cramois'Île, Pierre Rochard possiblement vers Kanto.
- **Dernier duel de Giovanni**, puis son départ.
- **Fuji et Mewtwo** : un anneau amène Mewtwo ; capturer ou laisser est une décision.
- Zone de Combat et Tournoi ; Défis T5.
- Restauration écologique continuée ; lettres.

---

## 13. Invariants (arbitrage du GMD obligatoire pour les changer)
1. Le joueur est Red, muet **par choix**. Il agit par 5 gestes (montrer, désigner, rester, partir, donner) et par une seule phrase écrite publique.
2. Brice a une voix décisive **qui peut contredire Red** : son vote et sa voie émergent de ce qu'il a vu. Il agit seul au moins deux fois.
3. Aucune faction n'a entièrement tort, sauf la Rocket, qui est l'égoïsme lisible. Aucun texte ne désigne « le bon camp ».
4. Les problèmes non combattus (écosystèmes, Sommet, Fiole, Rayquaza) ne se règlent **jamais** par une victoire de combat seule.
5. Futur canonique préservé (§3). La Rocket n'obtient jamais la Fiole. Giovanni n'obtient rien.
6. Pas de farming : plafond souple par jalons (`LEVEL_CAP_VARIABLE`, jalon posé dans **toutes** les branches), pas de revanches avant le postgame, argent et soins rationnés.
7. Ordre des badges et correspondance badges → capacités vanilla conservés. Aucune carte neuve.
8. Aucune espèce, sprite, donnée ou animation d'attaque modifiée.
9. **Toutes les espèces Gen 1–9 sont obtenables dans toutes les fins.**
10. Toute décision du registre a un effet **observable**, intelligible après coup, et un **test**.
11. Aucune zone exigeante à plus de 2 cartes d'un soin. Aucun softlock (tableau de traversée par branche : brief C).
12. Aucune fin n'est classée « meilleure ». Chacune a un gain exclusif et une perte.
13. Chaque personnage majeur de Kanto et de Hoenn a un agenda propre, au moins une alliance et une rivalité entre PNJ, et ses pulsations de rang. Aucun figurant.
14. Texte FR : ≤ 208 px par ligne, 2 lignes par boîte, une idée par boîte, guillemets “ ”.

---

## 14. Contraintes techniques (contraignantes)
| Domaine | Contrainte | Conséquence |
|---|---|---|
| ID de dresseurs | 9 libres ; recyclables : 324 revanches, 64 Magma/Aqua, 38 rivaux | revanches Cherche VS désactivées ; allocation par le brief B, sans collision |
| Flags | 319 persistants libres + ~40 `FLAG_HIDE_*` vanilla recyclables (lecteurs réécrits) | budget ~260 ; option E-SB3 |
| Vars | 54 libres + vars d'état vanilla recyclables une fois l'histoire vanilla retirée (liste vérifiée par grep) | budget ≤ 45 ; choix à 3 options en bits (E-BITS) ; aucune var sans lecteur |
| Sauvegarde | SB1 376 o, SB2 120 o, **SB3 1 623 o libres** | aucune structure nouvelle sauf E-SB3 (flags étendus), à valider par le programmeur moteur |
| IWRAM | 86,6 % | **aucune** aide en IWRAM : code en ROM seulement |
| Rencontres | `wild_encounters.json` ; `OW_TIME_OF_DAY_ENCOUNTERS` (capacité ×4 si activé) ; épidémies vanilla en SaveBlock1 (`outbreakPokemonSpecies`…) | brief D : analyse de capacité ; épidémies = anneaux scriptés |
| Texte | ~3 500–4 500 boîtes estimées | scènes de 8–15 boîtes ; saillance plutôt que branches |
| Assets | sprites OW de RFVF compilés ; replis : Jeannine (`NINJA_BOY` / `BATTLE_GIRL`), commandants Rocket (sbires RFVF), Président de Sylphe (`GENTLEMAN`), Amaryllis (`DRAGON_TAMER` / `HEX_MANIAC`), Hoopa (`OBJ_EVENT_GFX_SPECIES`) | `CAST_DOSSIER` §5 |

**Aides moteur à demander** (code en ROM uniquement ; chacune passe la porte prototype) :
| Code | Aide | Pour |
|---|---|---|
| E-CAP | `B_LEVEL_CAP_TYPE LEVEL_CAP_VARIABLE` + var, montée monotone par un script commun | jalons dans toutes les branches |
| E-ECO | table alternative de rencontres par zone selon un état (petite table {carte, flag → en-tête alternatif}) | écosystèmes |
| E-OUT | special qui pose ou efface une épidémie (espèce, carte, niveau) | anneaux sur les routes |
| E-TOD | activer les tables par moment de la journée (si le brief D le justifie) | capacité pour 1 025 espèces |
| E-ADAPT | special « type dominant de l'équipe » → `VAR_RESULT` | Blue, Giovanni, Peter |
| E-REMOVE | `removepartymon` (vider l'équipe du prologue) ; donner une équipe temporaire | prologue |
| E-LVL | donner un Pokémon au « plafond − 2 » | retour de Pikachu |
| E-BITS | `GetVarBits` / `SetVarBits` | budget vars |
| E-SB3 | bloc de flags étendus dans SB3 (optionnel) | marge |
| Déjà faits | combats refusables enregistrés (D1), choix du Pokémon de tête (D2), affinités (E), aucun sauvage (N1) | `ENGINE_CHANGES.md` |

---

## 15. Risques principaux
| # | Risque | Gravité | Mitigation |
|---|---|---|---|
| R1 | **Périmètre** (≈ 46 personnages, 1 025 espèces, 131 décisions, 5 fins) contre le budget Claude Pro | critique | tranche représentative d'abord (ch. 0–2) ; scènes par paires ; saillance plutôt que branches ; rang C borné |
| R2 | Capacité des tables de rencontre pour toutes les espèces | haut | analyse du brief D ; évolutions, cadeaux, épidémies, E-TOD |
| R3 | Lisibilité du mythe (Hoopa, Fiole, Rayquaza) | haut | les règles sont apprises avant d'être utilisées (§5.2) ; Kiosque ; test de compréhension |
| R4 | Le chemin doré réapparaît (Pacte + tout) | haut | coûts croisés (§11.3) ; analyse de cumul par le brief C |
| R5 | « Le monde tourne autour de Red » (R4 lui donne une part) | moyen | Red n'est qu'**un maillon** : Chen, Giovanni, Sylphe, Devon et Amaryllis portent des parts plus lourdes ; personnages à agenda propre |
| R6 | Canon : commandants libres en année 3, avenir des personnages | moyen | §3, invariant 5 ; relecture canon par le brief A |
| R7 | Budget ID, flags, vars | moyen | recyclage, E-BITS, E-SB3 |
| R8 | Climax trop complexe à scripter | moyen | 3 lieux, résultat déterministe, flags temporaires ; prototype papier d'abord |
| R9 | Retour arrière du ch. 7 | moyen | contenu sur le trajet (filature, Timmy, Léo) |
| R10 | Une hypothèse de lore lue comme du canon (Fiole au Pilier, article de Chen) | faible | étiquettes HYPOTHÈSE dans `CHARACTER_AND_LORE` |

---

## 16. Changelog
| Date | Version | Changement | Raison | Auteur |
|---|---|---|---|---|
| 2026-10-13 | 1.0 | « Heure suspendue » (archivée) | brief v1 | GMD |
| 2026-10-14 | 2.0 | *Pokémon Cendres* (archivé dans `archive/cendres_v2/`) | brief v2 | GMD |
| 2026-10-14 | 3.0 | **Nouvelle colonne vertébrale : *Pokémon Confluence*.** Prémisse remplacée (anneaux de Hoopa et réseau Passerelle à la place du volcan et du camp) ; oignon à 4 couches et R1–R4 ; mécanisme des espèces Gen 1–9 (nœuds, paliers P1–P3, loi d'échange) ; Hoopa et Rayquaza avec leurs règles ; 10 factions sur 2 axes ; distribution chorale complète (Kanto et Hoenn, rangs A/B/C) ; Mission Indigo en paires par ville ; Défis Indigo et Tournoi ; 5 fins × 3 variantes ; plafond par var ; aides moteur E-* ; v2 archivée. Briefs des spécialistes dans `SPEC_BRIEFS.md` | addendum utilisateur v2.1 ; revues v2 | GMD |
