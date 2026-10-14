# DECISION_LEDGER_ACT3 - Acte III et Écho (ch. 11-14) (*Pokémon Confluence*, brief C)

> Généré par `docs/hack/data/cf_model.py --render` a partir de `docs/hack/data/cf_decisions.py` (source unique). Ne pas éditer à la main : éditer les données puis régénérer.
> Règles, légende, décomptes et audit : `DECISION_LEDGER.md`. Systèmes, seuils et allocation : `GAME_SYSTEMS.md`. **Statut de toutes les entrées : propose (rien n est implémenté ni teste).**
> Accents restaurés au rendu (`cf_accents.py`) : les données sont saisies sans accents. Les répliques en jeu seront écrites par les scénaristes (<= 208 px, 2 lignes, guillemets “ ”).

**Décisions : 24** (E 15 / D 9 ; S 16 / M 6 / L 2 ; comptées 23)

## Ch. 11

### D102 - Le câble de Passerelle : négocier, combattre, laisser couper
`E` · `L` · arbitrage · Ch. 11 · statut **proposé** · verdict **VALIDE**

- **Unité :** SeafloorCavern_Room4-9 (Caverne Fondmer ; bible : "Grotte Tréfonds") - CF_D102 (jalon plafond 51, toutes issues ; FLAG_CF_FONDMER_DONE)
- **Déclencheur :** Arthur et Sarah vont couper le câble sous la mer ; Marin et Ondine (ou pas) defendent.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D12 bits 10-11 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Négocier (Sarah doute, plan du câble, ou message de l infirmière)** - deltas : rA+3, rC+2, PA-3, rL-2, Z05=RESTAURE, ARTHUR=NEGOCIE · *si* SARAH_DOUTE, DOS_PLAN_CABLE ou D105 a · immédiat : Arthur pose son couteau : 'On le déroute. Loin des Wailmer.' · différé : Z-05 RESTAURE ; ART vote LIBERER ; Aqua aux civils. · [gain : Écosystème, PA, rA, rC / perte : rL]
  - **b) Combattre Arthur** - deltas : rA-5, rL+3, PA+3, Z05=MIXTE · immédiat : Arthur tombe ; une équipe dissidente coupe une ligne secondaire. · différé : Z-05 MIXTE ; Aqua discreditee. · [gain : Écosystème, rL / perte : PA, rA]
  - **c) Laisser couper** - deltas : rA+5, rC-8, PA+8, Z05=ENVAHI, CABLE_COUPE, ARTHUR=COUPE · immédiat : Le noir à Algatia ; la mer s'ouvre d'anneaux. · différé : Z-05 ENVAHI ; F5 possible même sans Fuji ; F3 compromise. · [gain : rA / perte : Écosystème, PA, rC]
- **Lecteurs (contenu affecté) :** Sommet ART; PA; climax (F5 si relais perdu); E-ECO Z-05
- **Délai principal :** immédiat · signal de mémoire : Carnet : 'Le noir. Puis des anneaux partout.' (c)
- **Fins :** F5 / F3.
- **Test :** Save avant. Chaque issue : FLAG_CF_FONDMER_DONE (prérequis du Sommet), VAR_CF_CAP>=51. c : CABLE_COUPE, PA+8.

### D103 - Une porte de sortie pour Sarah
`D` · `S` · don · Ch. 11 · statut **proposé** · verdict **VALIDE**

- **Unité :** SeafloorCavern_Room9 - CF_D103
- **Déclencheur :** Sarah, après le câble, ne sait plus ou aller.
- **Prérequis :** SARAH_DOUTE
- **Stockage :** VAR_CF_D12 bits 12-13 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Lui donner la carte de recensement de Brice (un travail)** - deltas : rA-2, BR+2, SARAH_TEMOIN · immédiat : 'Compter. Ça, je sais faire.' · différé : Sommet M1 : Sarah temoigne (ART ne peut pas voter BRISER). · [gain : BR / perte : rA]
  - **b) Rester** - deltas : rA+2 · immédiat : Elle rejoint Arthur. · différé : rien. · [gain : rA / perte : -témoin]
- **Lecteurs (contenu affecté) :** Sommet
- **Délai principal :** différé court
- **Fins :** indirect.
- **Test :** Prérequis SARAH_DOUTE. a : SARAH_TEMOIN.

### D104 - Ondine, camp adverse (refusable)
`E` · `S` · combat · Ch. 11 · statut **proposé** · verdict **VALIDE**

- **Unité :** SeafloorCavern_Room1 - CF_D104 (FLAG_CF_REFUS_ONDINE)
- **Déclencheur :** Si Ondine est du côté Aqua, elle barre la route ; sinon elle escorte.
- **Prérequis :** Ondine côté Aqua
- **Stockage :** VAR_CF_D12 bits 14-15 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Accepter et gagner** - deltas : rI+2, rA-3, ONDINE_MISSION · immédiat : Ondine : 'Bon. Je reviens.' · différé : alliance rompue. · [gain : rI / perte : rA]
  - **b) Accepter et perdre** - deltas : rA+1, BR-1, -800 P · immédiat : Elle passe devant. · différé : alliance tient. · [gain : rA / perte : Argent, BR]
  - **c) Refuser (passer à côté)** - deltas : rA+2, rI-2 · immédiat : Elle laisse passer. · différé : alliance tient ; refus definitif. · [gain : rA / perte : rI]
- **Lecteurs (contenu affecté) :** brief B (Ondine Aqua/Mission); Sommet (Mission)
- **Délai principal :** immédiat
- **Fins :** indirect.
- **Test :** Prérequis REL_ONDINE_ARTHUR sans ONDINE_MISSION.

### D105 - Le soigneur de Fondmer : Aqua ou la brigade
`D` · `S` · présence · Ch. 11 · statut **proposé** · verdict **VALIDE**

- **Unité :** SeafloorCavern_Entrance - CF_D105
- **Déclencheur :** Une infirmière d'Aqua soigne à l'entree ; Flora arrive une salle plus tard.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D13 bits 0-1 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Accepter l'infirmière (elle confie un message pour Arthur)** - deltas : rA+2, FL-1 · immédiat : 'Dites-lui que Sarah vit.' · différé : D102 a disponible. · [gain : rA / perte : FL]
  - **b) Attendre Flora** - deltas : FL+2, rA-1 · immédiat : Flora soigne en silence. · différé : FL (ch. 13). · [gain : FL / perte : rA]
- **Lecteurs (contenu affecté) :** D102; FL
- **Délai principal :** immédiat
- **Fins :** indirect.
- **Test :** Les deux soignent (soin à <=2 cartes). a : clé de négociation.

### D106 - Le Capitaine Marin demande un témoignage
`E` · `S` · arbitrage · Ch. 11 · statut **proposé** · verdict **FAIBLE (liste, non comptée)** (delta rC marginal, doublon fonctionnel de D011/D029 (revue stricte))

- **Unité :** SlateportCity_SternsShipyard_1F (retour) / Route128 - CF_D106
- **Déclencheur :** Marin veut que Red defende les droits du Consortium sur le câble au Sommet.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D13 bits 2-3 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Promettre** - deltas : rC+3, rA-2 · immédiat : Marin : 'Je compte sur vous.' · différé : Sommet : COM lit rC plus haut. · [gain : rC / perte : rA]
  - **b) Refuser** - deltas : rC-2, rP+2 · immédiat : Marin soupire. · différé : rien. · [gain : rP / perte : rC]
- **Lecteurs (contenu affecté) :** Sommet (rC)
- **Délai principal :** différé court
- **Fins :** F3.
- **Test :** a : rC+3.

## Ch. 12

### D107 - La phrase publique de Red : au Sommet ou jamais
`E` · `M` · aveu · Ch. 12 · statut **proposé** · verdict **VALIDE**

- **Unité :** SootopolisCity_Gym_1F (après badge 8) - CF_D107
- **Déclencheur :** Juan : 'Au Sommet, voulez-vous parler ? Une fois. Ecrit.'
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D13 bits 4-5 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Écrire au Sommet** - deltas : BR-3, N=3 · immédiat : La phrase s'adapte : Dossier complet, Hoopa, ou 'Je pars apprendre a perdre'. · différé : Sommet : +1 voix basculee sur la motion 3 ; épilogue sans phrase (Carnet). · [gain : +une voix basculee (M3) / perte : BR]
  - **b) Garder la phrase pour l'épilogue** - deltas : BR+2 · immédiat : Juan hoche la tête. · différé : épilogue : 'Je pars apprendre a perdre.' · [gain : BR / perte : -voix supplémentaire]
- **Lecteurs (contenu affecté) :** Sommet M3; épilogue
- **Délai principal :** différé court · signal de mémoire : Juan : 'Une fois. Choisissez bien.'
- **Fins :** épilogue (phrase).
- **Test :** a : N=3, bascule M3 ; b : BR+2.

### D108 - Sommet, motion 1 (le reseau) : l'option défendue
`E` · `M` · arbitrage · Ch. 12 · statut **proposé** · verdict **VALIDE**

- **Unité :** SootopolisCity (place) - CF_D108 (gestes : montrer 1 pièce + designer 1 votant)
- **Déclencheur :** FERMER (sceller) / CHARTE (controle) / LIBERER (Hoopa réuni).
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D13 bits 6-7 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Défendre FERMER** - deltas : rG+2, rC-2 · différé : voir GAME_SYSTEMS 9 · [gain : rG / perte : rC]
  - **b) Défendre CHARTE** - deltas : rC+2, rG-2 · [gain : rC / perte : rG]
  - **c) Défendre LIBERER** - deltas : HO+3, rL-3 · [gain : HO / perte : rL]
- **Lecteurs (contenu affecté) :** résultat M1 (PA a ch. 13, intentions au climax); épilogue
- **Délai principal :** immédiat · signal de mémoire : Brice traduit : 'Red defend ceci. Moi, je vote a moi.'
- **Fins :** F1/F2/F3 (PA).
- **Test :** Matrice de vote (GAME_SYSTEMS 9.5) ; VAR_CF_SUMMIT : défendue M1 bits 0-1, résultat bits 6-7.

### D109 - Sommet, motion 2 (les arrivants) : l'option défendue
`E` · `M` · arbitrage · Ch. 12 · statut **proposé** · verdict **VALIDE**

- **Unité :** SootopolisCity (place) - CF_D109
- **Déclencheur :** REMPART (renvoyer) / INTEGRATION (sanctuaires) / MARCHE (exploiter).
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D13 bits 8-9 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Défendre REMPART** - deltas : rL+2, rA-2 · [gain : rL / perte : rA]
  - **b) Défendre INTEGRATION** - deltas : rA+2, rL-2 · [gain : rA / perte : rL]
  - **c) Défendre MARCHE** - deltas : rC+2, rP-2 · [gain : rC / perte : rP]
- **Lecteurs (contenu affecté) :** variante sociale; glissement des zones ch. 13
- **Délai principal :** différé long · signal de mémoire : idem D108 (le registre du Sommet est relu à la veillée).
- **Fins :** variante sociale.
- **Test :** VAR_CF_SUMMIT bits 2-3 / 8-9.

### D110 - Sommet, motion 3 (qui paie) : l'option défendue
`E` · `M` · aveu · Ch. 12 · statut **proposé** · verdict **VALIDE**

- **Unité :** SootopolisCity (place) - CF_D110
- **Déclencheur :** KANTO et Sylphe / HOENN et Devon / PARTAGEE (la chaine, Red compris).
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D13 bits 10-11 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Défendre KANTO** - deltas : rL+2, rI-3 · [gain : rL / perte : rI]
  - **b) Défendre HOENN** - deltas : rI+2, rC-3 · [gain : rI / perte : rC]
  - **c) Défendre PARTAGEE** - deltas : rG+2, rC-2 · [gain : rG / perte : rC]
- **Lecteurs (contenu affecté) :** FK; STANCE_PETER (ASSUME); Maitre ch. 14; épilogue
- **Délai principal :** différé long · signal de mémoire : idem D108 ; le résultat est affiche sur la place jusqu'au ch. 14.
- **Fins :** FK, variantes de personnages.
- **Test :** VAR_CF_SUMMIT bits 4-5 / 10-11.

### D111 - Brice veut un duel avant de voter (refusable)
`E` · `S` · combat · Ch. 12 · statut **proposé** · verdict **VALIDE**

- **Unité :** SootopolisCity - CF_D111 (FLAG_CF_REFUS_BRICE4)
- **Déclencheur :** 'Je vote a moi. Mais je veux savoir si tu m'entends.'
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D13 bits 12-13 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Accepter et gagner** - deltas : BR+2, rP-1, BRICE_DEFERE · immédiat : Brice : 'D'accord. Sur la motion 3, je te suis.' · différé : BRI vote l'option défendue de M3. · [gain : BR / perte : rP]
  - **b) Accepter et perdre** - deltas : BR+3, rI-1, BRICE_PARLE · immédiat : Brice parlera le premier. · différé : COM suit le vote de Brice sur M2. · [gain : BR / perte : rI]
  - **c) Refuser** - deltas : BR-3, rG+1 · immédiat : 'Alors je vote sans ton avis.' · différé : traduction seche (comme BR<50). · [gain : rG / perte : BR]
- **Lecteurs (contenu affecté) :** Sommet (BRI, COM)
- **Délai principal :** immédiat
- **Fins :** variante sociale.
- **Test :** slot 1/2/3 ; tester M2/M3 avec et sans.

### D112 - R4 en séance : designer Chen
`D` · `S` · présence · Ch. 12 · statut **proposé** · verdict **VALIDE**

- **Unité :** SootopolisCity (place) - CF_D112
- **Déclencheur :** Agatha leve la photocopie ; tous regardent Chen.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D13 bits 14-15 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Designer Chen (il parle)** - deltas : rI-3, rG+2 · immédiat : AVOUE s'il a été confronte (D087 a), sinon il nie mal. · différé : STANCE_CHEN ; fin cachée ; REL_CHEN_SEKO. · [gain : rG / perte : rI]
  - **b) Rester (le protéger)** - deltas : rI+2, rG-2, CHEN=NIE · immédiat : Agatha lit l'article elle-même. · différé : Chen NIE. · [gain : rI / perte : rG]
- **Lecteurs (contenu affecté) :** fin cachée; épilogue Chen-Seko
- **Délai principal :** différé long
- **Fins :** fin cachée.
- **Test :** a : CHEN=AVOUE si CHEN_CONFRONTE, sinon NIE.

### D113 - Le Président de Sylphe : confession privee ou chute publique
`E` · `M` · aveu · Ch. 12 · statut **proposé** · verdict **VALIDE**

- **Unité :** SootopolisCity (place) - CF_D113
- **Déclencheur :** Le registre prouve que la Fiole a dormi dans le coffre de Sylphe.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D14 bits 0-1 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Lui montrer en prive (il confesse)** - deltas : rC-3, rI+2, SYLPHE=CONF · immédiat : Il parle lui-même : 'Je l'ai cachée. J'ai cru la vendre.' · différé : R4 source 2 ; F3 garde un partenaire credible. · [gain : rI / perte : rC]
  - **b) Le montrer en séance (chute)** - deltas : rC-8, rI+3, rP+2, SYLPHE=CHUTE · immédiat : Le Président quitte la salle sous les huees. · différé : R4 source 2 ; F3 très difficile (rC). · [gain : rI, rP / perte : rC]
- **Lecteurs (contenu affecté) :** R4 (sources); Sommet ROC/M3; F3
- **Délai principal :** immédiat · signal de mémoire : Le Président, au ch. 14 (lettre) : 'Vous m'avez laisse parler.' / 'Vous m'avez juge.'
- **Fins :** F3.
- **Test :** Les deux comptent comme source 2. a/b : STANCE_SYLPHE.

### D114 - Le témoignage de Giovanni
`D` · `S` · présence · Ch. 12 · statut **proposé** · verdict **VALIDE**

- **Unité :** SootopolisCity (place) - CF_D114
- **Déclencheur :** Giovanni est dans le public, sans Persian.
- **Prérequis :** GI>=55 et LAMBDA_DEMASQUE
- **Stockage :** VAR_CF_D14 bits 2-3 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Le designer** - deltas : RK-5, rI-3, GIO_TEMOIN · immédiat : 'J'ai ordonne le vol. Pas ce qu'ils en ont fait.' Il part. · différé : R4 source 2 bis ; dernier duel (postgame) d'office. · [gain : RK / perte : rI]
  - **b) Rester** - deltas : GI-2, rI+1 · immédiat : Il part sans un mot. · différé : rien. · [gain : rI / perte : GI]
- **Lecteurs (contenu affecté) :** R4; D127
- **Délai principal :** immédiat
- **Fins :** variante Rocket.
- **Test :** Prérequis GI>=55 et LAMBDA_DEMASQUE.

### D115 - L'interruption : vers qui courir
`D` · `S` · présence · Ch. 12 · statut **proposé** · verdict **VALIDE**

- **Unité :** SootopolisCity - CF_D115
- **Déclencheur :** La tempête d'anneaux eclate ; la Rocket attaque Algatia ; le ciel gronde.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D14 bits 4-5 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Vers les civils de la place** - deltas : rP+3, rG-1, CIVILS_PREPARES · immédiat : Red ouvre un passage. · différé : climax : civils +1 competence (n'importe quel allié). · [gain : rP / perte : rG]
  - **b) Vers la Doyenne et les Sages** - deltas : rG+3, rP-1, RITE_PREPARE · immédiat : La Doyenne : 'Le rite. Maintenant.' · différé : climax : RITE avec rG>=40 au lieu de 45. · [gain : rG / perte : rP]
- **Lecteurs (contenu affecté) :** climax
- **Délai principal :** différé court
- **Fins :** F1 / casualties.
- **Test :** a : CIVILS_PREPARES ; b : RITE_PREPARE.

## Ch. 13

### D116 - L'affectation : ou va Red, qui tient le reste
`E` · `L` · présence · Ch. 13 · statut **proposé** · verdict **VALIDE**

- **Unité :** MossdeepCity / SkyPillar / SootopolisCity - CF_D116 (veillée ; soin force)
- **Déclencheur :** Chaque allié dit ce qu'il tient ; Red va en un lieu et designe un allié pour chacun des deux autres.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D14 bits 6-7 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Red au relais** - deltas : rC+2, rG-2 · [gain : rC / perte : rG]
  - **b) Red au Pilier** - deltas : rG+3, rC-2 · [gain : rG / perte : rC]
  - **c) Red aux civils** - deltas : rP+3, RK+3 · [gain : rP / perte : RK]
- **Lecteurs (contenu affecté) :** résultat de la Fiole (GAME_SYSTEMS 10); variante Rocket; casualties
- **Délai principal :** immédiat · signal de mémoire : Brice : 'Tu choisis. Nous, on tient.'
- **Fins :** toutes les fins.
- **Test :** Table d'affectation x etats (GAME_SYSTEMS 10.6). VAR_CF_CLIMAX.

### D117 - Au relais : le geste de Red avec la Fiole
`E` · `M` · arbitrage · Ch. 13 · statut **proposé** · verdict **VALIDE**

- **Unité :** MossdeepCity_SpaceCenter_2F (coeur) - CF_D117
- **Déclencheur :** La Fiole entre les mains de Red.
- **Prérequis :** D116 = a
- **Stockage :** VAR_CF_FIN bits 5-7 (intention : 1 PACTE, 2 SCEAU, 3 PASSERELLE, 4 BRISER) ; garde = FLAG_CF_M_CLIMAX non pose
- **Options :**
  - **a) La donner à Hoopa** - deltas : HO+5, rC-5 · [gain : HO / perte : rC]
  - **b) La confier au courrier du Pilier (rite)** - deltas : rG+5, HO-5 · [gain : rG / perte : HO]
  - **c) La laisser à la charte (Consortium et Ligue)** - deltas : rC+5, HO-8 · [gain : rC / perte : HO]
  - **d) La briser** - deltas : HO-8, rA+3 · [gain : rA / perte : HO]
- **Lecteurs (contenu affecté) :** résultat de la Fiole
- **Délai principal :** immédiat · signal de mémoire : Hoopa, la Doyenne ou Lanette regardent Red ; la scène de fin le rappelle.
- **Fins :** F1-F5.
- **Test :** Prérequis Red au relais.

### D118 - Veillee : le don de Red
`D` · `S` · don · Ch. 13 · statut **proposé** · verdict **VALIDE**

- **Unité :** veillée (carte selon D116) - CF_D118
- **Déclencheur :** Red peut donner quelque chose à un allié avant de partir.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D14 bits 10-11 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Confier Hoopa à l'allié du relais** - deltas : HO-3, BR+1 · immédiat : Hoopa se cache derriere l'allié. · différé : Hoopa present au relais. · [gain : BR / perte : HO]
  - **b) Donner ses objets de soin à l'allié des civils** - deltas : rP+2 · immédiat : L'allié remplit ses poches. · différé : civils : BLESSES au lieu de PERTES avec un allié faible ; Red arrive au combat sans soins. · [gain : rP / perte : -objets de soin (Hyper Potions x3), Objets]
  - **c) Ne rien donner** - deltas : BR-1 · [gain : +équipe complete / perte : BR]
- **Lecteurs (contenu affecté) :** résultat de la Fiole (présence de Hoopa); casualties
- **Délai principal :** immédiat
- **Fins :** F2.
- **Test :** a : prérequis garde RED et Red pas au relais.

### D119 - Pilier : Amaryllis
`E` · `S` · aveu · Ch. 13 · statut **proposé** · verdict **VALIDE**

- **Unité :** SkyPillar_Top - CF_D119
- **Déclencheur :** Amaryllis attend Rayquaza ; Aster tremble.
- **Prérequis :** D116 = b
- **Stockage :** VAR_CF_D14 bits 12-13 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Montrer la preuve de la mort de la gardienne** - deltas : AM+5, RK+1 · différé : RENONCE si AM>=55, sinon PERSISTE. · [gain : AM / perte : RK]
  - **b) La combattre (gagner du temps, Y3)** - deltas : AM-5, rG+1 · différé : PERSISTE ; temps gagne. · [gain : rG / perte : AM]
- **Lecteurs (contenu affecté) :** AM_ISSUE (épilogue, P2 dans son équipe)
- **Délai principal :** immédiat
- **Fins :** variante Amaryllis.
- **Test :** Prérequis Red au Pilier. Si Red absent : AM>=60 et REL_AMA_ARAGON -> RENONCE ; AM<30 -> SACRIFICE ; sinon PERSISTE.

### D120 - Civils : le port des pêcheurs ou le Centre des arrivants
`E` · `S` · arbitrage · Ch. 13 · statut **proposé** · verdict **VALIDE**

- **Unité :** SootopolisCity / LilycoveCity (civils) - CF_D120
- **Déclencheur :** Deux quartiers sous les anneaux ; on n'en vide qu'un a temps.
- **Prérequis :** D116 = c
- **Stockage :** VAR_CF_D14 bits 14-15 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Le port des pêcheurs** - deltas : rP+5, rA-3, CIVILS_PORT · différé : casualties côté arrivants ; postgame : le Centre des arrivants ferme (PNJ absents). · [gain : rP / perte : rA]
  - **b) Le Centre des arrivants** - deltas : rA+5, rP-3, CIVILS_CENTRE · différé : casualties côté pêcheurs ; postgame : le port de Nénucrique à moitié vide. · [gain : rA / perte : rP]
- **Lecteurs (contenu affecté) :** épilogue (casualties); variante sociale (rP)
- **Délai principal :** immédiat
- **Fins :** variante sociale.
- **Test :** Prérequis Red aux civils.

### D121 - Rayquaza : combattre ou tenir le rite
`D` · `S` · arbitrage · Ch. 13 · statut **proposé** · verdict **VALIDE**

- **Unité :** SkyPillar_Top - CF_D121
- **Déclencheur :** Rayquaza descend. Le combattre fait gagner du temps ; le rite le retient.
- **Prérequis :** D116 = b
- **Stockage :** VAR_CF_D15 bits 0-1 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Combattre (Y3)** - deltas : rG-2, rL+2 · différé : temps gagne (civils), pas de rite. · [gain : rL / perte : rG]
  - **b) Tenir le rite avec la Doyenne** - deltas : rG+2, rL-2 · différé : RITE si rG>=45 (40 avec RITE_PREPARE). · [gain : rG / perte : rL]
- **Lecteurs (contenu affecté) :** RITE (F1)
- **Délai principal :** immédiat
- **Fins :** F1.
- **Test :** Prérequis Red au Pilier.

### D122 - Flora : obéir à Norman ou rejoindre les civils
`D` · `S` · présence · Ch. 13 · statut **proposé** · verdict **VALIDE**

- **Unité :** veillée - CF_D122
- **Déclencheur :** Norman ordonne à Flora de rejoindre la brigade au Pilier.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D15 bits 2-3 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Designer Brice (il lui parle)** - deltas : BR+1, rL-2 · différé : FLORA_DESOBEIT si FL>=55 et BR>=50. · [gain : BR / perte : rL]
  - **b) Rester (la laisser choisir)** - deltas : FL+2, BR-1 · différé : FLORA_DESOBEIT si FL>=60 ou FLORA_DOUTE. · [gain : FL / perte : BR]
- **Lecteurs (contenu affecté) :** climax (Flora allié civils); épilogue Flora; vote NOR (abstention)
- **Délai principal :** immédiat
- **Fins :** casualties.
- **Test :** slot ; FLORA_DESOBEIT selon seuils.

## Ch. 14

### D123 - Route Victoire : l'échange de Blue
`E` · `S` · don · Ch. 14 · statut **proposé** · verdict **VALIDE**

- **Unité :** VictoryRoad_1F - CF_D123 (E-REMOVE + E-NATIVE)
- **Déclencheur :** Blue : 'Donne-moi un de tes natifs. Je te donne un import. Pour voir.'
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D15 bits 4-5 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Accepter** - deltas : BL+3, rG-1 · immédiat : Blue aligne ton natif au combat final. · différé : Blue final : variante 'natif' ; épilogue Blue (Jadielle) chaleureux. · [gain : +import de Blue, BL / perte : Équipe, rG]
  - **b) Refuser** - deltas : BL-1, rG+1 · immédiat : 'Comme tu veux.' · différé : Blue final : E-ADAPT pur. · [gain : rG / perte : BL]
- **Lecteurs (contenu affecté) :** brief B (Blue final); épilogue Blue
- **Délai principal :** immédiat
- **Fins :** variante Blue.
- **Test :** a : échange effectue (vérifier especes).

### D124 - Timmy à la Route Victoire (refusable)
`D` · `S` · combat · Ch. 14 · statut **proposé** · verdict **VALIDE**

- **Unité :** VictoryRoad_1F - CF_D124 (FLAG_CF_REFUS_TIMMY)
- **Déclencheur :** Timmy, avec ou sans son arrivant : 'Je veux savoir si je peux.'
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D15 bits 6-7 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Accepter et gagner** - deltas : TI+2, BR-1 · différé : Timmy rentre fier (épilogue). · [gain : TI / perte : BR]
  - **b) Accepter et perdre** - deltas : TI+4, rL-1, -1000 P · différé : Timmy part pour la Zone de Combat (postgame). · [gain : TI / perte : Argent, rL]
  - **c) Refuser** - deltas : TI-3, rP+1 · différé : épilogue Timmy triste ; refus definitif. · [gain : rP / perte : TI]
- **Lecteurs (contenu affecté) :** épilogue Timmy; postgame Zone
- **Délai principal :** différé court
- **Fins :** variante Timmy.
- **Test :** slot 1/2/3.

### D125 - Pantheon : qui sur la photo
`E` · `S` · présence · Ch. 14 · statut **proposé** · verdict **VALIDE**

- **Unité :** HallOfFame - CF_D125
- **Déclencheur :** Le photographe attend ; Brice et Blue sont la.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D15 bits 8-9 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Avec Brice** - deltas : BR+3, BL-2 · différé : postgame : Brice partenaire de duo au Tournoi. · [gain : BR / perte : BL]
  - **b) Avec Blue** - deltas : BL+3, BR-2 · différé : postgame : duel de Blue a Bourg-en-Vol des P1. · [gain : BL / perte : BR]
  - **c) Seul** - deltas : GI+2, BR-1 · différé : postgame : dernier duel de Giovanni des P1. · [gain : GI / perte : BR]
- **Lecteurs (contenu affecté) :** postgame (ordre des acces)
- **Délai principal :** différé court
- **Fins :** aucune.
- **Test :** slot ; PNJ postgame selon slot.
