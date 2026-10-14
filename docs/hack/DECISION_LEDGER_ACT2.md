# DECISION_LEDGER_ACT2 - Acte II (ch. 5-10) (*Pokémon Confluence*, brief C)

> Généré par `docs/hack/data/cf_model.py --render` a partir de `docs/hack/data/cf_decisions.py` (source unique). Ne pas éditer à la main : éditer les données puis régénérer.
> Règles, légende, décomptes et audit : `DECISION_LEDGER.md`. Systèmes, seuils et allocation : `GAME_SYSTEMS.md`. **Statut de toutes les entrées : propose (rien n est implémenté ni teste).**
> Accents restaurés au rendu (`cf_accents.py`) : les données sont saisies sans accents. Les répliques en jeu seront écrites par les scénaristes (<= 208 px, 2 lignes, guillemets “ ”).

**Décisions : 56** (E 32 / D 24 ; S 37 / M 15 / L 4 ; comptées 54)

## Ch. 5

### D046 - R112 : le capteur de Kelvin
`E` · `S` · arbitrage · Ch. 5 · statut **proposé** · verdict **FAIBLE (liste, non comptée)** (PA+1 et deltas marginaux ; la precision de la démonstration est du texte (revue stricte))

- **Unité :** Route112 - CF_D046
- **Déclencheur :** Kelvin (Magma) demande à Red de poser un capteur au Site Météore.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D05 bits 10-11 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Accepter** - deltas : rM+3, rG-2, PA+1 · immédiat : Kelvin : 'Max saura que tu es raisonnable.' · différé : ch. 6 : la démonstration est plus précise (troupeau mieux deplace, PA +1). · [gain : rM / perte : PA, rG]
  - **b) Refuser** - deltas : rM-2, rG+1 · immédiat : Kelvin range le capteur. · différé : rien. · [gain : rG / perte : rM]
- **Lecteurs (contenu affecté) :** ch. 6 démonstration; rM/rG (Sommet)
- **Délai principal :** différé court
- **Fins :** indirect.
- **Test :** a : rM=53, PA+1 ; b : rM=48.

### D047 - Petit voleur n 5 : les lunettes de Kosmo
`D` · `S` · geste · Ch. 5 · statut **proposé** · verdict **VALIDE**

- **Unité :** Route113 - CF_D047
- **Déclencheur :** Le voleur emporte les lunettes de Kosmo dans la cendre.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D05 bits 12-13 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Le laisser les garder** - deltas : HO+5 · immédiat : Il les porte de travers. · différé : Kosmo n'a pas ses relevés (DOS_ETOILES indisponible). · [gain : HO / perte : -Kosmo sans données]
  - **b) Les reprendre** - deltas : HO-3, DOS_ETOILES · immédiat : Kosmo : 'Mes étoiles filantes... ce ne sont pas des étoiles.' · différé : pièce : eclairs d'anneaux (Q4, H3) ; ch. 8 : négociation avec Sarah. · [gain : Dossier / perte : HO]
- **Lecteurs (contenu affecté) :** HO; D080 (ch. 8); Sommet M1
- **Délai principal :** différé court
- **Fins :** F2.
- **Test :** a : HO+5 ; b : DOS_ETOILES.

### D048 - Quête de Bayar (désert, facultative)
`E` · `M` · arbitrage · Ch. 5 · statut **proposé** · verdict **VALIDE**

- **Unité :** Route111 (désert, ruinés) - CF_D048 (Éclate-Roc)
- **Déclencheur :** Des fouisseurs d'Unys menacent les ruinés ; Bayar veut sceller la galerie.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D05 bits 14-15 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Sceller avec Bayar** - deltas : rG+3, rA-2, DOS_SCEAUX_ANCIENS · immédiat : Bayar : 'Les anciens ont fait pareil. Pour pire que ça.' · différé : fin cachée : pièce des sceaux (Regis). · [gain : Dossier, rG / perte : rA]
  - **b) Ouvrir et déplacer les fouisseurs** - deltas : rA+2, rG-2, Z03 +1 cran · immédiat : Les Kraknoix reviennent. · différé : Z-03 : +1 cran vers RESTAURE (MIXTE -> RESTAURE ; ABATTU -> MIXTE). · [gain : Écosystème, rA / perte : rG]
- **Lecteurs (contenu affecté) :** fin cachée; E-ECO Z-03
- **Délai principal :** différé long · signal de mémoire : Bayar : 'Tu reviendras quand tu sauras ce qu'ils ont enferme.'
- **Fins :** fin cachée.
- **Test :** a : DOS_SCEAUX_ANCIENS ; b : VAR_CF_ECO Z03 +1 cran.

### D049 - Les journaux de Lanette (W9 Léo/Lanette)
`E` · `M` · arbitrage · Ch. 5 · statut **proposé** · verdict **VALIDE**

- **Unité :** Route114_LanettesHouse - CF_D049
- **Déclencheur :** Lanette remet ses journaux horodates ; Léo demande de ne rien dire au Consortium.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D06 bits 0-1 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Les garder pour Brice** - deltas : BR+3, rC-2, BV.COMP+1, DOS_JOURNAUX · immédiat : Brice les serre contre lui. · différé : ch. 7 : R2 complete (carte + journaux) ; Sommet M1 (CHARTE/FERMER). · [gain : BR, Dossier / perte : rC]
  - **b) Les rendre au Consortium** - deltas : rC+4, BR-3 · immédiat : Le Président remercie par lettre. · différé : ch. 7 : R2 tient par l'aveu de Léo seul (indice 3). · [gain : rC / perte : -pièce, BR]
- **Lecteurs (contenu affecté) :** ch. 7 R2; D051; Sommet
- **Délai principal :** différé court · signal de mémoire : Brice : 'Je les recopie ce soir.'
- **Fins :** indirect.
- **Test :** a : DOS_JOURNAUX, BVCOUNT.C+1 ; b : rC=54.

### D050 - Site Météore : Peter contre Amaryllis (W1)
`E` · `M` · présence · Ch. 5 · statut **proposé** · verdict **VALIDE**

- **Unité :** MeteorFalls_1F_1R - CF_D050 (fin d événement : FLAG_HIDE_ROUTE_112_TEAM_MAGMA pose, plafond 29, toutes issues)
- **Déclencheur :** Clan contre clan ; Aragon arbitre ; Amaryllis accuse Peter 'd'être de la region du voleur'.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D06 bits 2-3 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Designer Aragon (respect du Site)** - deltas : rG+5, AM+3, PE-2, PETER_RESPECT, REL_AMA_ARAGON · immédiat : Aragon parle ; Peter se retire, Drattak à son côté. · différé : Peter aligne Drattak (brief B) ; Amaryllis et Aragon reconcilies. · [gain : AM, rG / perte : PE]
  - **b) Partir avec Peter** - deltas : PE+5, rI+3, rG-5, AM-5 · immédiat : Peter pietine la mousse sacree. · différé : Amaryllis : 'Le voleur et ses amis.' ; rite du ch. 12 plus fragile. · [gain : PE, rI / perte : AM, rG]
- **Lecteurs (contenu affecté) :** brief B (Peter Drattak); AM (climax); rG (rite); REL_AMA_ARAGON
- **Délai principal :** différé court · signal de mémoire : Carnet : 'Elle a dit voleur. Elle me regardait.'
- **Fins :** climax Pilier (AM, rG).
- **Test :** Les deux issues : FLAG_HIDE_ROUTE_112_TEAM_MAGMA pose (lecteurs : Route112, MeteorFalls_1F_1R), VAR_CF_CAP>=29. a : rG=55, AM=53 ; b : PE=55, AM=45.

### D051 - Les données de Brice contredisent son père
`D` · `S` · don · Ch. 5 · statut **proposé** · verdict **VALIDE**

- **Unité :** MeteorFalls_1F_1R (sortie) - CF_D051
- **Déclencheur :** Brice relit ses comptes : les arrivants suivent les contrats des nœuds.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D06 bits 4-5 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Montrer les journaux de Lanette** - deltas : BR+2, rL-1, BV.COMP+1 · immédiat : Brice : 'Papa se trompe. Ou on lui ment.' · différé : BV COMPRENDRE +1. · [gain : BR / perte : rL]
  - **b) Rester (le laisser croire son père)** - deltas : BR-1, rL+1, BV.PROT+1 · immédiat : Brice : 'Papa doit avoir une raison.' · différé : BV PROTEGER +1. · [gain : rL / perte : BR]
- **Lecteurs (contenu affecté) :** BV
- **Délai principal :** différé long
- **Fins :** BV.
- **Test :** Prérequis DOS_JOURNAUX pour a. a : BVCOUNT.C+1 ; b : BVCOUNT.P+1.

### D052 - Le fragment de meteorite de Kosmo
`E` · `S` · arbitrage · Ch. 5 · statut **proposé** · verdict **VALIDE**

- **Unité :** FallarborTown_CozmosHouse - CF_D052
- **Déclencheur :** Kosmo hésite : rendre le fragment au Peuple du Météore ou le vendre à Devon.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D06 bits 6-7 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) À la Doyenne** - deltas : rG+3, rC-2, FRAGMENT_DOYENNE · immédiat : La Doyenne : 'Il servira au rite.' · différé : ch. 13 : le rite retarde Rayquaza plus longtemps (RITE possible avec rG>=45). · [gain : rG / perte : rC]
  - **b) A Devon (1 500 P pour Kosmo, 500 P pour Red)** - deltas : rC+2, rG-3, +500 P · immédiat : Kosmo paie sa toiture. · différé : rien. · [gain : Argent, rC / perte : rG]
- **Lecteurs (contenu affecté) :** climax RITE (seuil rG)
- **Délai principal :** différé long
- **Fins :** F1.
- **Test :** a : FRAGMENT_DOYENNE ; b : +500 P.

### D053 - Aster, la Chuchmur de la gardienne disparue
`D` · `S` · don · Ch. 5 · statut **proposé** · verdict **VALIDE**

- **Unité :** Route113 / MeteorFalls - CF_D053
- **Déclencheur :** Une Chuchmur suit Red dans la cendre ; elle porte un ruban du Peuple du Météore.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D06 bits 8-9 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) La ramener à Amaryllis** - deltas : AM+5, PE-2 · immédiat : Amaryllis se fige ; 'Aster...' · différé : ch. 13 : Amaryllis renonce plus facilement (AM). · [gain : AM / perte : PE]
  - **b) La confier à la Doyenne** - deltas : rG+3, AM-2 · immédiat : La Doyenne la garde au chaud. · différé : ch. 12 : Aster au rite. · [gain : rG / perte : AM]
- **Lecteurs (contenu affecté) :** AM (climax); rG
- **Délai principal :** différé long
- **Fins :** climax Pilier.
- **Test :** a : AM+5 ; b : rG+3.

## Ch. 6

### D054 - Demonstration de Magma (W5) : soutenir, saboter, denoncer
`E` · `L` · arbitrage · Ch. 6 · statut **proposé** · verdict **VALIDE**

- **Unité :** MtChimney - CF_D054
- **Déclencheur :** Max ouvre un anneau declenche pour déplacer le troupeau d'Unys des champs ; Arthur manifeste.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D06 bits 10-11 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Soutenir (protéger la démonstration)** - deltas : rM+8, PA+5, rA-8, Z06=MIXTE · immédiat : Le troupeau disparaît des champs ; une heure plus tard, les Pokémon des sources aussi. · différé : Z-06 MIXTE ; Max PERSISTE par defaut ; Auguste reste. · [gain : Écosystème, rM / perte : PA, rA]
  - **b) Saboter avec Aqua** - deltas : rA+8, rM-8, PA+2, rP-3, Z06=ENVAHI · *si* sans l insigne de brigade (D017 b) · immédiat : L'anneau rate à moitié ; le troupeau reste, les sources tiennent. · différé : Z-06 ENVAHI ; fermiers ruinés ; Aqua fait confiance à Red. · [gain : rA / perte : Écosystème, PA, rM, rP]
  - **c) Denoncer (montrer l'horaire vole à Adriane)** - deltas : rL+5, rM-5, rC-3, Z06=ABATTU · immédiat : La Ligue arrête la démonstration ; la brigade abat le troupeau. · différé : Z-06 ABATTU ; le Consortium accuse d'avoir vendu l'horaire. · [gain : rL / perte : Écosystème, rC, rM]
- **Lecteurs (contenu affecté) :** E-ECO Z-06; D061 (Max); D062/D089 (Auguste); PA; Sommet
- **Délai principal :** immédiat · signal de mémoire : Brice (s'il est la) : 'Ça prend autant que ça donne.'
- **Fins :** PA (F3), variante sociale.
- **Test :** Save avant. a : PA+5, Z06=1, Chamallot 20 % -> 1 % sur R112 ; b : Z06=0 ; c : Z06=3. Hoopa blessé dans les 3 issues (D055).

### D055 - Petit voleur n 6 : blessé par l'anneau
`D` · `M` · don · Ch. 6 · statut **proposé** · verdict **VALIDE**

- **Unité :** MtChimney (bord du cratere) - CF_D055
- **Déclencheur :** Le voleur, à moitié aspire, retient un Chamallot par la patte. Personne ne voit sauf Red.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D06 bits 12-13 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Donner une Potion** - deltas : HO+8, HOOPA_SOIGNE · immédiat : Il la boit, regarde Red longtemps. · différé : D062 : Red peut montrer à Auguste ; HO. · [gain : HO / perte : Objets]
  - **b) Rester** - deltas : rM+2, HO-1 · immédiat : Il se libere seul et fuit vers l'est. · différé : indice R2b. · [gain : rM / perte : HO]
- **Lecteurs (contenu affecté) :** HO; D062
- **Délai principal :** différé court · signal de mémoire : Carnet : 'Il m'a regarde boire la Potion. Lui.'
- **Fins :** F2.
- **Test :** a : HO+8, HOOPA_SOIGNE ; b : rM+2.

### D056 - Giovanni incognito (refusable)
`E` · `M` · combat · Ch. 6 · statut **proposé** · verdict **VALIDE**

- **Unité :** FieryPath (Chemin Ardent) - CF_D056 (FLAG_CF_REFUS_GIO1)
- **Déclencheur :** L'homme au Persian corrige des sbires negligents, puis propose un combat a 3 Pokémon.
- **Prérequis :** GI >= 50 (D028 a ou neutre)
- **Stockage :** VAR_CF_D06 bits 14-15 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Accepter et gagner** - deltas : GI+5, RK+2 · immédiat : 'Tu es devenu... interessant.' · différé : D114 : témoignage possible (GI>=55). · [gain : GI / perte : RK]
  - **b) Accepter et perdre** - deltas : GI+2, BL-1, -500 P · immédiat : 'Tu n'es plus le même.' · différé : rien d'autre. · [gain : GI / perte : Argent, BL]
  - **c) Refuser** - deltas : GI-3, RK-3 · immédiat : Il congedie lui-même ses sbires : 'Vous m'avez fait honte.' · différé : moins de sbires au ch. 7. · [gain : RK / perte : GI]
- **Lecteurs (contenu affecté) :** GI (D114); RK
- **Délai principal :** différé long · signal de mémoire : Giovanni : 'On se reverra. Ailleurs.'
- **Fins :** R4 source 2.
- **Test :** Prérequis GI>=50. a : GI+5 ; c : GI-3, RK-3, refus pose.

### D057 - Ariane recrute a Vermilava
`D` · `S` · don · Ch. 6 · statut **proposé** · verdict **VALIDE**

- **Unité :** LavaridgeTown - CF_D057
- **Déclencheur :** Un gardien des sources ruiné ; Ariane compte des billets : 'Votre Ligue les parque. Nous, on les paie.'
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D07 bits 0-1 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Donner 1 000 P au gardien** - deltas : RK-4, rP+2, -1000 P · immédiat : Il rend les billets a Ariane. · différé : ch. 10 : Ariane à un sbire de moins ; il aide à l'évacuation (ch. 13). · [gain : RK, rP / perte : Argent]
  - **b) Rester** - deltas : RK+3 · immédiat : Il prend l'argent. · différé : ch. 10 : il est au relais, en noir. · [gain : +argent / perte : RK]
- **Lecteurs (contenu affecté) :** RK; climax civils
- **Délai principal :** immédiat
- **Fins :** variante Rocket.
- **Test :** a : -1000 P, RK-4 ; b : RK+3.

### D058 - Erika et Adriane : les sources a vendre
`D` · `S` · présence · Ch. 6 · statut **proposé** · verdict **VALIDE**

- **Unité :** LavaridgeTown (sources) - CF_D058
- **Déclencheur :** Erika veut acheter les sources taries pour un parfum ; Adriane refuse.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D07 bits 2-3 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Designer Adriane (elle parle)** - deltas : rP+3, rC-2, STANCE_ERIKA_INT · immédiat : Erika écoute, puis dechire son contrat. · différé : Erika passe INTEGRATION (équipe, vote via Mission). · [gain : rP / perte : rC]
  - **b) Rester** - deltas : rC+3, rP-3 · immédiat : Erika signe ; Adriane pleure de rage. · différé : Erika reste MARCHE. · [gain : rC / perte : rP]
- **Lecteurs (contenu affecté) :** STANCE_ERIKA (brief B); épilogue Vermilava
- **Délai principal :** immédiat
- **Fins :** diaporama Vermilava.
- **Test :** a : STANCE_ERIKA_INT ; b : rC+3.

### D059 - Planque Magma : l'horaire vendu par Lambda
`E` · `S` · arbitrage · Ch. 6 · statut **proposé** · verdict **VALIDE**

- **Unité :** MagmaHideout_2F_1R - CF_D059
- **Déclencheur :** Un horaire signe 'Passerelle', vendu aux deux camps par 'Ferrand'.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D07 bits 4-5 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Le copier pour Brice** - deltas : rM-2, BR+1, DOS_HORAIRE_VENDU · immédiat : Brice : 'Le même papier que chez Aqua ?' · différé : ch. 10 : preuve pour demasquer Lambda (D095). · [gain : BR, Dossier / perte : rM]
  - **b) Le rendre à Max** - deltas : rM+4, BR-1 · immédiat : Max : 'Merci. On nous a vole.' · différé : D061 : Max écoute plus volontiers. · [gain : rM / perte : -pièce, BR]
- **Lecteurs (contenu affecté) :** D095; D061
- **Délai principal :** différé court
- **Fins :** indirect.
- **Test :** a : DOS_HORAIRE_VENDU ; b : rM+4.

### D060 - Attendre Brice au telepherique
`D` · `S` · présence · Ch. 6 · statut **proposé** · verdict **VALIDE**

- **Unité :** Route112_CableCarStation - CF_D060
- **Déclencheur :** Brice est en retard ; la démonstration commence dans dix minutes.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D07 bits 6-7 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Attendre** - deltas : BR+2, rM-2 · immédiat : Ils arrivent pendant la manifestation. · différé : Brice témoin de D054 : BV +1 (a : PROTEGER, b : ACCUEILLIR, c : COMPRENDRE). · [gain : BR / perte : rM]
  - **b) Monter seul** - deltas : BR-2, rM+1 · immédiat : Max accueille Red en personne. · différé : Brice absent de la démonstration. · [gain : rM / perte : BR]
- **Lecteurs (contenu affecté) :** BV
- **Délai principal :** différé long
- **Fins :** BV.
- **Test :** a : BVCOUNT +1 selon D054 ; b : BR-2.

### D061 - Montrer à Max les sources vides
`E` · `S` · aveu · Ch. 6 · statut **proposé** · verdict **VALIDE**

- **Unité :** LavaridgeTown -> MagmaHideout_1F - CF_D061
- **Déclencheur :** Après la démonstration, les natifs des sources ont disparu (loi H1 visible).
- **Prérequis :** D054 = a
- **Stockage :** VAR_CF_D07 bits 8-9 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Montrer (Chamallot absent, relevé de Brice)** - deltas : rM+2, PA-2, rC-2, STANCE_MAX_ECOUTE · immédiat : Max se tait longtemps ; 'Alors, on prend ailleurs.' · différé : Max ECOUTE : il arrête les anneaux declenches ; Sommet : MAX vote FERMER. · [gain : PA, rM / perte : rC]
  - **b) Partir** - deltas : PA+2, rC+1 · immédiat : Max relance les calculs. · différé : ch. 8-9 : Magma declenche deux anneaux de plus (P2 plus tôt). · [gain : rC / perte : PA]
- **Lecteurs (contenu affecté) :** Sommet MAX; PA; E-OUT ch. 8
- **Délai principal :** différé court
- **Fins :** PA.
- **Test :** Prérequis D054 = a (sinon Max écoute d'office si c). a : STANCE_MAX_ECOUTE ; b : PA+2.

### D062 - Auguste et le petit voleur blessé
`D` · `S` · aveu · Ch. 6 · statut **proposé** · verdict **VALIDE**

- **Unité :** LavaridgeTown (Centre) - CF_D062
- **Déclencheur :** Auguste boit seul ; il parle de Cramois'Ile et d'une 'creature qu'on a déjà fabriquee'.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D07 bits 10-11 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Lui montrer la trace du voleur blessé** - deltas : rM-3, HO+1, AUGUSTE_DOUTE · immédiat : Auguste : 'Encore une fois, on enchaine quelque chose.' · différé : ch. 9 : Auguste peut rejoindre Fuji (D089). · [gain : HO / perte : rM]
  - **b) Rester** - deltas : rM+1 · immédiat : Auguste retourne à ses cartes. · différé : ch. 9 : Auguste reste avec Max. · [gain : rM / perte : -Auguste reste loyal]
- **Lecteurs (contenu affecté) :** D089 (ch. 9); Sommet (Magma)
- **Délai principal :** différé court
- **Fins :** climax relais (Fuji competent).
- **Test :** Prérequis HOOPA_SOIGNE ou D055 vue. a : AUGUSTE_DOUTE ; b : rM+1.

## Ch. 7

### D063 - Filature de Lambda ou course à Vergazon (exclusif)
`E` · `M` · présence · Ch. 7 · statut **proposé** · verdict **VALIDE**

- **Unité :** MauvilleCity -> VerdanturfTown - CF_D063
- **Déclencheur :** 'Ferrand' quitte Lavandia en hate ; au même moment, la brigade marche sur Vergazon.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D07 bits 12-13 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Suivre Lambda** - deltas : RK-3, TI-3, DOS_LAMBDA · immédiat : Photo du déguisement retire dans une ruelle. · différé : ch. 10 : demasquage immédiat (D095) ; Vergazon se joue sans Red (D064 decidee par FL et D038). · [gain : Dossier, RK / perte : TI]
  - **b) Courir à Vergazon** - deltas : TI+2, RK+1 · immédiat : Red arrive avant la brigade. · différé : D064 jouee par Red ; Lambda disparaît. · [gain : TI / perte : RK]
- **Lecteurs (contenu affecté) :** D064; D095
- **Délai principal :** immédiat · signal de mémoire : Carnet : 'Un choix. L'autre continue sans moi.'
- **Fins :** variante Timmy ; RK.
- **Test :** a : DOS_LAMBDA, D064 résolue automatiquement ; b : D064 disponible.

### D064 - Vergazon : Timmy contre la brigade (W3)
`E` · `M` · arbitrage · Ch. 7 · statut **proposé** · verdict **VALIDE**

- **Unité :** VerdanturfTown - CF_D064
- **Déclencheur :** Flora execute l'ordre ; Brice recite ses chiffres ; Timmy serre son arrivant.
- **Prérequis :** D063 = b
- **Stockage :** VAR_CF_D07 bits 14-15 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Défendre Timmy (combat contre la brigade)** - deltas : TI+5, FL-3, rL-4, TIMMY_SAUVE · immédiat : La brigade recule ; Flora part sans un mot. · différé : Timmy aligne son arrivant ; Flora ne bascule que si FL>=60. · [gain : TI / perte : FL, rL]
  - **b) Convaincre Flora (montrer relevés ou Z-03)** - deltas : FL+5, rL-2, TI+3, TIMMY_SAUVE, FLORA_DOUTE · *si* Z-02 MIXTE, Z-03 MIXTE/RESTAURE ou journaux · immédiat : Flora baisse son arme : 'Je n'ai rien vu.' · différé : Flora DOUTE (bascule au ch. 13 si FL>=55). · [gain : +sauvetage sans combat, FL, TI / perte : rL]
  - **c) Laisser faire l'ordre** - deltas : TI-5, rL+3, FL+2 · immédiat : Timmy ne pleure pas ; c'est pire. · différé : Pierre (Brock) : ses protégés abattus aussi (vote ch. 12 : retrait amer). · [gain : FL, rL / perte : -arrivant de Timmy abattu, TI]
- **Lecteurs (contenu affecté) :** équipe Timmy (brief B); D122 (Flora); Pierre (Brock) vote; D123; épilogue Timmy
- **Délai principal :** immédiat · signal de mémoire : Brice : 'Flora. Tu m'avais dit que tu choisirais.'
- **Fins :** variante Timmy, Flora.
- **Test :** Prérequis D063 = b. a : TIMMY_SAUVE, FL-3 ; b : TIMMY_SAUVE+FLORA_DOUTE ; c : TI-5. Si D063 = a : script auto (sauvé si TI>=55 et FL>=55, sinon c).

### D065 - L'aveu de Léo : le protéger ou le nommer
`E` · `S` · aveu · Ch. 7 · statut **proposé** · verdict **VALIDE**

- **Unité :** MauvilleCity (Centre) - CF_D065
- **Déclencheur :** Léo remet l'enregistrement du 'battement' du Coeur (DOS_BATTEMENT, toujours) et demande l'anonymat.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D08 bits 0-1 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Le protéger** - deltas : rC+2, rL-1, LEO_INSIDER · immédiat : Léo retourne au relais. · différé : ch. 10 et 13 : Léo ouvre le relais (allié Consortium competent). · [gain : rC / perte : rL]
  - **b) Le nommer publiquement** - deltas : rC-4, rL+2 · immédiat : Léo est renvoye ; il rejoint Lanette. · différé : Sommet : COM et NOR lisent rC plus bas. · [gain : rL / perte : rC]
- **Lecteurs (contenu affecté) :** climax (Léo/Lanette); rC
- **Délai principal :** différé long
- **Fins :** F3 (allié relais).
- **Test :** Les deux : DOS_BATTEMENT pose. a : LEO_INSIDER.

### D066 - Petit voleur n 7 : le carnet rendu
`D` · `S` · geste · Ch. 7 · statut **proposé** · verdict **VALIDE**

- **Unité :** Route116 - CF_D066
- **Déclencheur :** Si HO>=40, le voleur dépose le carnet de Brice ; sinon, rien, sauf un anneau éteint.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D08 bits 2-3 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Donner quelque chose en échange** - deltas : HO+5, BR+1 · immédiat : Il prend la baie et reste a regarder. · différé : HO. · [gain : BR, HO / perte : Objets]
  - **b) Reprendre le carnet sans rien donner** - deltas : HO-2, BR+3 · immédiat : Il part, vexe. · différé : Brice retrouve son recensement (BV +1 à son compteur dominant). · [gain : BR / perte : HO]
  - **c) Laisser de la nourriture à l'anneau éteint** - deltas : HO+3 · immédiat : Le lendemain, la nourriture a disparu. · différé : HO. · [gain : HO / perte : -carnet perdu, Objets]
- **Lecteurs (contenu affecté) :** HO; BV
- **Délai principal :** différé court
- **Fins :** F2.
- **Test :** Si HO>=40 : options a/b ; sinon c seule. Valeurs HO attendues +5/-2/+3.

### D067 - Dîner chez les Seko : Chen contre Seko
`D` · `S` · présence · Ch. 7 · statut **proposé** · verdict **VALIDE**

- **Unité :** LittlerootTown_BrendansHouse_1F - CF_D067
- **Déclencheur :** Chen et Seko se disputent la paternite des noms d'especes.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D08 bits 4-5 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Designer Seko** - deltas : BR+2, rI-1 · immédiat : Seko parle de Hoenn qui perd ses natifs. · différé : REL_CHEN_SEKO : rivalite maintenue. · [gain : BR / perte : rI]
  - **b) Rester (Mme Seko intervient)** - deltas : BR+1, rL-1, DINER_APAISE · immédiat : Mme Seko sert le dessert ; Chen rit le premier. · différé : REL_CHEN_SEKO possible (si Chen avoue au ch. 12). · [gain : BR / perte : rL]
- **Lecteurs (contenu affecté) :** REL_CHEN_SEKO (épilogue, fin cachée)
- **Délai principal :** différé long
- **Fins :** fin cachée.
- **Test :** b : DINER_APAISE.

### D068 - Brice et la publication (R2) : la reaction de Red
`E` · `L` · aveu · Ch. 7 · statut **proposé** · verdict **VALIDE**

- **Unité :** LittlerootTown_BrendansHouse_2F - CF_D068 (jalon plafond 33 après la scène, toutes issues)
- **Déclencheur :** Brice superpose sa carte et les journaux : R2. Il décide seul (selon BV) de publier ou de remettre à son père.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D08 bits 6-7 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Approuver (hocher la tête)** - deltas : BR+8, rC-5 · immédiat : Brice publie (ou remet) en disant 'nous'. · différé : si publie : PA -5 (un nœud de surcharge ferme à Poivressel), rC -3 de plus. · [gain : BR / perte : rC]
  - **b) Tourner le dos** - deltas : BR-10, rL+2 · immédiat : Brice publie quand même, seul ; il ne dit plus 'nous'. · différé : BR bas : traduction seche au Sommet. · [gain : rL / perte : BR]
  - **c) Lui donner sa casquette** - deltas : BR+5, rI-2, CREDIT_PARTAGE · immédiat : Brice rit, puis pleure un peu. · différé : Credit partage Chen-Seko (REL_CHEN_SEKO possible) ; BV +1 au compteur dominant. · [gain : BR / perte : rI]
- **Lecteurs (contenu affecté) :** BRICE_PUBLIE (PA, rC, Sommet BRI); BR (traduction, veillée); REL_CHEN_SEKO
- **Délai principal :** immédiat · signal de mémoire : Brice : 'Je l'ai fait. Toi, tu as fait ça.'
- **Fins :** F3 (PA), fin cachée.
- **Test :** État BV force (PROT dominant / COMP dominant). Attendu : publie si COMP ou ACC domine (PA-5), sinon remise à Seko (rL+5). VAR_CF_CAP>=33 dans les 3 issues.

### D069 - Vote d'abattage du Rempart (W4)
`E` · `M` · arbitrage · Ch. 7 · statut **proposé** · verdict **VALIDE**

- **Unité :** PetalburgCity_Gym (QG) - CF_D069
- **Déclencheur :** Norman et Major Bob votent l'abattage général ; Roxanne apporte ses chiffres.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D08 bits 8-9 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Montrer une pièce (battement, prédicteur, journaux)** - deltas : rL-5, RK-2 · immédiat : Le vote échoue si Major Bob est CONTRE (D036 a) ou si Roxanne s'abstient. · différé : VOTE_ABATTAGE non : aucune brigade au ch. 8. · [gain : RK / perte : rL]
  - **b) Rester** - deltas : rL+3, RK+2 · immédiat : Le vote passe sauf si Major Bob CONTRE et Roxanne abstention. · différé : VOTE_ABATTAGE oui : brigade a Cimetronelle (D074 b), primes (RK +3 au ch. 8). · [gain : rL / perte : RK]
  - **c) Partir (Brice parle a ta place)** - deltas : rL-2, BR-1, BV.COMP+1 · immédiat : Norman : 'Le champion s'abstient.' · différé : issue selon Major Bob seul. · [gain : +Brice parle (BV COMP +1) / perte : BR, rL]
- **Lecteurs (contenu affecté) :** VOTE_ABATTAGE (D074, RK ch. 8, glissement ch. 13)
- **Délai principal :** immédiat · signal de mémoire : Norman note le vote de Red dans le registre (réplique au ch. 12).
- **Fins :** variante sociale (zones).
- **Test :** Matrice : D036 x D016 x option. Attendu : VOTE_ABATTAGE selon GAME_SYSTEMS 8.4.

### D070 - Badge 5 : le message de Norman pour Flora
`D` · `S` · don · Ch. 7 · statut **proposé** · verdict **VALIDE**

- **Unité :** PetalburgCity_Gym - CF_D070
- **Déclencheur :** Norman, après le combat : 'Dites a ma fille d'obéir. Moi, elle ne m'écoute plus.'
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D08 bits 10-11 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Porter le message** - deltas : FL-3, rL+3 · immédiat : Flora : 'Il t'envoie, maintenant ?' · différé : ch. 13 : Flora obéit plus facilement. · [gain : rL / perte : FL]
  - **b) Le garder pour soi** - deltas : FL+3, rL-2 · immédiat : Flora ne saura jamais. · différé : ch. 13 : bascule plus facile. · [gain : FL / perte : rL]
- **Lecteurs (contenu affecté) :** FL (ch. 13)
- **Délai principal :** différé long
- **Fins :** casualties civils.
- **Test :** a : FL-3 ; b : FL+3.

### D071 - Devon 3F : Pierre Rochard et son père (W2)
`E` · `S` · aveu · Ch. 7 · statut **proposé** · verdict **VALIDE**

- **Unité :** RustboroCity_DevonCorp_3F - CF_D071
- **Déclencheur :** 'Qu'y a-t-il dans le Coeur ?' - 'Des emplois.'
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D08 bits 12-13 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Montrer l'enregistrement de Léo** - deltas : PR+3, rC-5, PR_PREUVE · immédiat : Pierre Rochard écoute trois fois. · différé : ch. 12 : ACCUSE possible (PR>=55). · [gain : PR / perte : rC]
  - **b) Rester** - deltas : PR-2, rC+2 · immédiat : M. Rochard : 'Merci de votre discretion.' · différé : ch. 12 : Pierre Rochard protégé son père sauf registre. · [gain : rC / perte : PR]
- **Lecteurs (contenu affecté) :** STANCE_PR père (ch. 12); Sommet M3 (PRO)
- **Délai principal :** différé long
- **Fins :** F2 (demission), Maitre ch. 14.
- **Test :** a : PR_PREUVE ; b : rC+2.

## Ch. 8

### D072 - Institut Meteo occupe par Sarah
`E` · `M` · arbitrage · Ch. 8 · statut **proposé** · verdict **VALIDE**

- **Unité :** Route119_WeatherInstitute_1F/2F - CF_D072 (jalon plafond 37, toutes issues)
- **Déclencheur :** Sarah (Aqua) tient l'Institut et ses relevés de tempête.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D08 bits 14-15 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Forcer (combats)** - deltas : rA-5, rL+3 · immédiat : La Ligue saisit les données. · différé : Sarah hostile ; la tempête est 'un phénomène' pour la Ligue. · [gain : rL / perte : rA]
  - **b) Négocier (rester, montrer Kosmo si obtenu)** - deltas : rA+3, rL-3, DOS_DONNEES_INSTITUT · immédiat : Sarah montre les courbes : 'Ça monte après chaque transfert.' · différé : D080 possible ; H3 apprise ; Sommet M1. · [gain : Dossier, rA / perte : rL]
- **Lecteurs (contenu affecté) :** D080; D102; Sommet M1
- **Délai principal :** immédiat · signal de mémoire : Sarah : 'Tu t'en souviendras quand le ciel craquera.'
- **Fins :** indirect.
- **Test :** Les deux : VAR_CF_CAP>=37. b : DOS_DONNEES_INSTITUT.

### D073 - R120 : l'Absol 'porte-malheur'
`D` · `S` · arbitrage · Ch. 8 · statut **proposé** · verdict **VALIDE**

- **Unité :** Route120 - CF_D073
- **Déclencheur :** La brigade traque un Absol venu annoncer la tempête.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D09 bits 0-1 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Le capturer avant la brigade** - deltas : rL-2, rG+1 · immédiat : La brigade repart bredouille. · différé : Absol dans l'équipe ; ch. 13 : il 'sent' le Pilier (réplique). · [gain : +Équipe (Absol), rG / perte : rL]
  - **b) Laisser la brigade le chasser** - deltas : rL+2, rG-1 · immédiat : L'Absol s'enfuit vers le nord. · différé : rien. · [gain : rL / perte : -Équipe, rG]
- **Lecteurs (contenu affecté) :** équipe; rL
- **Délai principal :** immédiat
- **Fins :** aucune.
- **Test :** a : Absol reçu.

### D074 - Mission de zone Z-04 : la canopée de Cimetronelle
`E` · `M` · arbitrage · Ch. 8 · statut **proposé** · verdict **VALIDE**

- **Unité :** FortreeCity / Route119-120 - CF_D074
- **Déclencheur :** Étourmi contre Hélédelle et Tropius ; Koga veut les nuées comme appat pour son piege.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D09 bits 2-3 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Avec Alizée : reconstruire les nids** - deltas : rP+3, rI-2, Z04=RESTAURE · immédiat : Les ponts rouvrent ; Koga peste. · différé : Z-04 RESTAURE ; Koga moins sur de son piege (D075 a plus facile). · [gain : Écosystème, rP / perte : rI]
  - **b) Laisser la brigade abattre** - deltas : rL+4, rA-3, Z04=ABATTU · *si* VOTE_ABATTAGE oui · immédiat : Les nuées tombent. · différé : Z-04 ABATTU. · [gain : rL / perte : Écosystème, rA]
  - **c) Laisser Koga utiliser les nuées** - deltas : rI+3, rP-2, Z04=MIXTE · immédiat : Les nuées tournent autour d'un appat. · différé : Z-04 MIXTE ; piege pret. · [gain : Écosystème, rI / perte : rP]
- **Lecteurs (contenu affecté) :** E-ECO Z-04; D075; barrage du pont (leve en toutes issues)
- **Délai principal :** immédiat · signal de mémoire : Alizée ou Koga commente les ponts à chaque passage.
- **Fins :** variante sociale.
- **Test :** 50 rencontres R119 par issue ; Tropius 1 % / 20 %.

### D075 - Le piege de Koga : la garde de Hoopa (R2b)
`E` · `L` · arbitrage · Ch. 8 · statut **proposé** · verdict **VALIDE**

- **Unité :** FortreeCity (canopée) - CF_D075
- **Déclencheur :** Le petit voleur est pris : c'est Hoopa Confine. Koga veut l'emmener ; Hoopa regarde Red.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D09 bits 4-5 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Le garder (combat contre Koga, ou montrer la page K. à Peter)** - deltas : HO+10, rI-8, RK+5, garde=RED · immédiat : Hoopa devient suiveur (setfollowernpc) ; la Rocket apprend ou il est. · différé : climax : Hoopa present si Red au relais ou confie (D118) ; ch. 10 : Rocket vise Red. · [gain : HO, Hoopa (garde) / perte : RK, rI]
  - **b) Le laisser à la Mission** - deltas : rI+8, HO-8, garde=MISSION · immédiat : Hoopa en cage au camp de la Mission (Nénucrique). · différé : climax : present si Peter ou Koga au relais ; Sommet : PET peut voter LIBERER. · [gain : Hoopa (garde), rI / perte : HO]
  - **c) Ouvrir le piege** - deltas : HO+8, rL-5, rI-5, garde=LIBRE · immédiat : Hoopa fuit vers l'est, se retourne une fois. · différé : climax : il vient seul si HO>=70. · [gain : HO, Hoopa (garde) / perte : rI, rL]
- **Lecteurs (contenu affecté) :** climax (présence de Hoopa); Sommet (PET, DOY); ch. 10 assaut; suiveur (saillance)
- **Délai principal :** immédiat · signal de mémoire : Carnet : 'Il m'a regarde. Pas Koga. Moi.'
- **Fins :** F2 (et F5 si HO bas).
- **Test :** Save avant. a : VAR_CF_WORLD garde=1, suiveur actif, HO+10 ; b : garde=2 ; c : garde=3. Test de soft-lock : suiveur desactive en Plongee (script de carte).

### D076 - La vision de Morgane (R120)
`D` · `S` · présence · Ch. 8 · statut **proposé** · verdict **VALIDE**

- **Unité :** Route120 - CF_D076
- **Déclencheur :** Morgane voit 'un dragon qui ne choisit pas' ; Pierre Rochard attend Red plus loin.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D09 bits 6-7 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Rester jusqu au bout** - deltas : PR-2, rG+1, DOS_VISION, MORGANE_ALLIEE · immédiat : 'Le ciel juge. Il ne pardonne pas.' · différé : Sommet M1 (FERMER) ; ch. 13 : Morgane aux civils. · [gain : Dossier, rG / perte : PR]
  - **b) Rejoindre Pierre Rochard** - deltas : PR+2 · immédiat : Pierre Rochard : 'Vous etes venu.' · différé : rien. · [gain : PR / perte : -pièce et allié]
- **Lecteurs (contenu affecté) :** Sommet M1; climax (Morgane civils)
- **Délai principal :** différé court
- **Fins :** climax civils.
- **Test :** a : DOS_VISION, MORGANE_ALLIEE ; b : PR+2.

### D077 - Embuscade de la R120 : le partenaire de duo
`E` · `S` · présence · Ch. 8 · statut **proposé** · verdict **VALIDE**

- **Unité :** Route120 - CF_D077 (Méga-Anneau et Scope remis dans les deux cas)
- **Déclencheur :** Des sbires Rocket attaquent ; Pierre Rochard et Brice sont la.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D09 bits 8-9 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Pierre Rochard** - deltas : PR+4, BR-2 · immédiat : Méga-Métalosse ; 'Le Méga-Anneau est a vous.' · différé : PR. · [gain : PR / perte : BR]
  - **b) Brice** - deltas : BR+4, PR-2, BV.ACC+1 · immédiat : Brice voit les cages de primes : 'Ils les vendent au poids.' · différé : BV ACCUEILLIR +1. · [gain : BR / perte : PR]
- **Lecteurs (contenu affecté) :** PR (allié); BV
- **Délai principal :** immédiat
- **Fins :** climax alliés.
- **Test :** Les deux : ITEM_MEGA_RING et Scope recus. a : PR+4 ; b : BR+4, BVCOUNT.A+1.

### D078 - Jeannine suit Red en cachette
`D` · `S` · aveu · Ch. 8 · statut **proposé** · verdict **VALIDE**

- **Unité :** FortreeCity - CF_D078
- **Déclencheur :** Jeannine a désobéi à Koga pour voir Red 'travailler'.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D09 bits 10-11 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) La couvrir** - deltas : rI-2, JEANNINE_ALLIEE · immédiat : Elle promet une dette. · différé : ch. 10 : elle révèle le double jeu de Koga (alternative à la page) ; ch. 13 : relais (allié). · [gain : +allié (Jeannine) / perte : rI]
  - **b) La designer à Koga** - deltas : rI+2 · immédiat : Koga la renvoie à la Mission. · différé : rien. · [gain : rI / perte : -allié]
- **Lecteurs (contenu affecté) :** D095 (Koga); climax relais
- **Délai principal :** différé long
- **Fins :** climax relais.
- **Test :** a : JEANNINE_ALLIEE ; b : rI+2.

### D079 - Badge 6 : un Pokémon pour la canopée
`E` · `M` · don · Ch. 8 · statut **proposé** · verdict **VALIDE**

- **Unité :** FortreeCity_Gym - CF_D079 (E-REMOVE)
- **Déclencheur :** Alizée demande des Pokémon Vol pour repeupler la canopée.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D09 bits 12-13 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Donner un Pokémon de son équipe (choix au menu)** - deltas : rP+3, rG+1, Z04 +1 cran · immédiat : Alizée le relache dans les nids. · différé : Z-04 +1 cran ; Alizée aux civils au ch. 13 (réplique). · [gain : Écosystème, rG, rP / perte : Équipe]
  - **b) Refuser** - deltas : rP-1 · immédiat : Alizée comprend. · différé : rien. · [gain : +équipe gardee / perte : rP]
- **Lecteurs (contenu affecté) :** E-ECO Z-04; diaporama
- **Délai principal :** immédiat · signal de mémoire : Le Pokémon donne apparait dans les nids (PNJ objet) à chaque visite.
- **Fins :** variante sociale.
- **Test :** a : Pokémon retire (E-REMOVE) ; Z04 +1 cran. Prérequis : au moins 2 Pokémon (special ChoosePartyMon puis E-REMOVE).

### D080 - Montrer à Sarah ses propres données
`D` · `S` · aveu · Ch. 8 · statut **proposé** · verdict **VALIDE**

- **Unité :** Route119 (pont) - CF_D080
- **Déclencheur :** Sarah seule sur le pont, ses relevés sous le bras.
- **Prérequis :** DOS_DONNEES_INSTITUT ou DOS_ETOILES
- **Stockage :** VAR_CF_D09 bits 14-15 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Montrer (Institut + étoiles de Kosmo)** - deltas : rA+2, rL-2, SARAH_DOUTE · immédiat : 'Si on coupe le câble... tout s'ouvre.' · différé : ch. 11 : Sarah doute en public (D102 a possible). · [gain : rA / perte : rL]
  - **b) Partir** - deltas : rL+1 · immédiat : Sarah range ses courbes. · différé : ch. 11 : la coupure est plus probable. · [gain : rL / perte : -Sarah reste loyale]
- **Lecteurs (contenu affecté) :** D102; D103
- **Délai principal :** différé court
- **Fins :** F5 (câble).
- **Test :** Prérequis DOS_DONNEES_INSTITUT ou DOS_ETOILES. a : SARAH_DOUTE.

### D081 - Défi Indigo de Koga (refusable)
`E` · `S` · combat · Ch. 8 · statut **proposé** · verdict **VALIDE**

- **Unité :** FortreeCity - CF_D081 (FLAG_CF_REFUS_KOGA)
- **Déclencheur :** Koga, après le piege, propose un duel 'sans rancune'.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D10 bits 0-1 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Accepter et gagner** - deltas : rI+2, RK-1, PE-1, KOGA_AVEU · immédiat : Koga : 'Au relais, je te dirai qui j'ai paye.' · différé : ch. 10 : Koga avoue de lui-même (REL_KOGA_PETER DEMASQUE sans la page). · [gain : RK, rI / perte : PE]
  - **b) Accepter et perdre** - deltas : rI+1, HO-1, -500 P · immédiat : 'Tu manques de poison.' · différé : rien. · [gain : rI / perte : Argent, HO]
  - **c) Refuser** - deltas : rI-2, HO+1 · immédiat : Koga s'incline, froid. · différé : refus definitif. · [gain : HO / perte : rI]
- **Lecteurs (contenu affecté) :** D095; REL_KOGA_PETER
- **Délai principal :** différé court
- **Fins :** épilogue Koga (Conseil 4).
- **Test :** a : KOGA_AVEU.

## Ch. 9

### D082 - La nuit du marché : Olga, raid Aqua ou libération (exclusif)
`E` · `L` · présence · Ch. 9 · statut **proposé** · verdict **VALIDE**

- **Unité :** LilycoveCity (port, entrepôt) / AquaHideout_1F - CF_D082 (jalon plafond 42 a l aube, toutes issues ; FLAG_CF_PLANQUE_RESOLUE)
- **Déclencheur :** La même nuit : coup de filet d'Olga au marché noir, raid de la Ligue sur la planque Aqua, libération des arrivants par Ondine et Aqua.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D10 bits 2-3 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Coup de filet avec Olga** - deltas : RK-8, rI+5, rA-3, OLGA_LOKHLASS, OBJ_LETTRE_FERRAND · immédiat : Les Lokhlass d'Olga dans une caisse ; Ferrand ligote dans l'entrepôt. · différé : Olga accepte l'aide de Hoenn ; Lambda demasquable ; le raid Aqua échoue sans Red (plan du câble inconnu). · [gain : Dossier, RK, rI / perte : rA]
  - **b) Raid sur la planque Aqua (Ligue)** - deltas : rL+5, rA-8, RK+5, DOS_PLAN_CABLE · immédiat : Le plan du câble sur la table d'Arthur. · différé : D102 : négociation possible ; les Lokhlass partent chez la Rocket (Olga sans eux). · [gain : Dossier, rL / perte : RK, rA]
  - **c) Libérer les arrivants avec Ondine et Aqua** - deltas : rA+8, rL-8, RK-3, Z04=ENVAHI, REL_ONDINE_ARTHUR · immédiat : La réserve du Safari s'ouvre ; les arrivants filent dans les bois. · différé : Z-04 ENVAHI ; alliance Ondine-Arthur ; Lokhlass perdus. · [gain : RK, rA / perte : Écosystème, rL]
- **Lecteurs (contenu affecté) :** brief B (Olga avec/sans Lokhlass); D095; D102; Z-04; RK; F4 retour par la mer (Lokhlass)
- **Délai principal :** immédiat · signal de mémoire : Brice : 'Trois portes. On en a ouvert une.'
- **Fins :** F4 (canal de retour), RK, variante sociale.
- **Test :** Save avant. Chaque issue : FLAG_CF_PLANQUE_RESOLUE, VAR_CF_CAP>=42, R124 ouverte après Mont Mémoria. a : OLGA_LOKHLASS ; b : DOS_PLAN_CABLE ; c : Z04=0.

### D083 - Le toit du Grand Magasin (W6 Blue/Giovanni)
`D` · `S` · présence · Ch. 9 · statut **proposé** · verdict **VALIDE**

- **Unité :** LilycoveCity_DepartmentStoreRooftop - CF_D083
- **Déclencheur :** Blue et Giovanni parlent de Jadielle, de l'heritage, d'une defaite contre un gamin.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D10 bits 4-5 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Rester** - deltas : BL+5, GI-2 · immédiat : Blue, après : 'Tu as tout entendu. Bon.' · différé : STANCE_BLUE LIBRE si BL>=60 au ch. 13. · [gain : BL / perte : GI]
  - **b) Partir** - deltas : GI+3, BL-2 · immédiat : Giovanni, plus tard : 'Tu ne regardes pas les faiblesses. Bien.' · différé : GI (témoignage). · [gain : GI / perte : BL]
- **Lecteurs (contenu affecté) :** STANCE_BLUE; GI (D114)
- **Délai principal :** différé court
- **Fins :** variante Blue.
- **Test :** a : BL+5 ; b : GI+3.

### D084 - Blue 2 sur le toit (refusable)
`E` · `S` · combat · Ch. 9 · statut **proposé** · verdict **VALIDE**

- **Unité :** LilycoveCity_DepartmentStoreRooftop - CF_D084 (FLAG_CF_REFUS_BLUE2)
- **Déclencheur :** Blue : 'Maintenant que tu sais. Bats-toi.'
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D10 bits 6-7 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Accepter et gagner** - deltas : BL+2, rC-1 · immédiat : Blue jette un import dans sa boite. · différé : Blue T4 : un Pokémon de Bourg Palette remplace un import. · [gain : BL / perte : rC]
  - **b) Accepter et perdre** - deltas : BL+4, rI-1, -800 P · immédiat : Blue rit franchement, pour une fois. · différé : Blue vient à la veillée si BL>=55. · [gain : BL / perte : Argent, rI]
  - **c) Refuser** - deltas : BL-3, rG+1 · immédiat : 'Tu as change.' Il part. · différé : refus definitif. · [gain : rG / perte : BL]
- **Lecteurs (contenu affecté) :** brief B (Blue T4); veillée (BL)
- **Délai principal :** différé court
- **Fins :** variante Blue.
- **Test :** a/b/c : slot ; c : refus pose.

### D085 - Concours de Nénucrique : avec quel Pokémon
`D` · `S` · arbitrage · Ch. 9 · statut **proposé** · verdict **FAIBLE (liste, non comptée)** (Marc ne vote pas : les deltas rA/rG sont marginaux (revue stricte))

- **Unité :** LilycoveCity_ContestLobby - CF_D085 (E-NATIVE)
- **Déclencheur :** Nina inscrit Red ; Juan est au jury ; Marc observe.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D10 bits 8-9 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Avec un arrivant** - deltas : rA+2, rG-2 · immédiat : Marc applaudit ; un Sage grimace. · différé : Marc vote avec son ami (Pierre Rochard) au Sommet. · [gain : rA / perte : rG]
  - **b) Avec un natif** - deltas : rG+2, rA-1 · immédiat : Juan note quelque chose. · différé : Marc penche vers les Sages. · [gain : rG / perte : rA]
- **Lecteurs (contenu affecté) :** Sommet (Marc via DOY/PRO); rG
- **Délai principal :** différé court
- **Fins :** indirect.
- **Test :** Special E-NATIVE sur l'espece inscrite ; slot 1/2.

### D086 - Mont Mémoria : protéger le rite ou poursuivre Lance (Rocket)
`E` · `M` · arbitrage · Ch. 9 · statut **proposé** · verdict **VALIDE**

- **Unité :** MtPyre_Summit - CF_D086 (jalon plafond 44, toutes issues ; DOS_INSCRIPTION toujours)
- **Déclencheur :** Lance (Rocket) profane le rite et copie l'inscription du Sceau.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D10 bits 10-11 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Proteger le rite** - deltas : rG+5, RK+2, DOS_ARTICLE_CHEN, RITE_PROTEGE · immédiat : Il fuit en laissant tomber une photocopie annotee : l'article de Chen. · différé : Agatha pardonne plus tard ; la Rocket connait la loi H4 (ch. 10 plus dur). · [gain : Dossier, rG / perte : RK]
  - **b) Poursuivre Lance (Rocket)** - deltas : RK-5, rG-5, COPIE_REPRISE · immédiat : Red reprend la copie ; le rite est rompu, Agatha se dresse (combat). · différé : Agatha rancuniere ; l'assaut du ch. 10 vise le mauvais etage (relais tenu plus facilement). · [gain : RK / perte : rG]
- **Lecteurs (contenu affecté) :** D087; climax (RK); Agatha (épilogue); STANCE_CHEN
- **Délai principal :** immédiat · signal de mémoire : Agatha : 'Le rite. Je n'oublie pas qui l'a garde.' / 'qui l'a laisse.'
- **Fins :** fin cachée (article), climax.
- **Test :** Les deux : DOS_INSCRIPTION, VAR_CF_CAP>=44. a : DOS_ARTICLE_CHEN ; b : combat Agatha, COPIE_REPRISE.

### D087 - W7 : montrer l'article à Chen devant Agatha
`D` · `S` · aveu · Ch. 9 · statut **proposé** · verdict **VALIDE**

- **Unité :** MtPyre_Summit - CF_D087
- **Déclencheur :** 'Ton article, Chen. Il y a cinquante ans.'
- **Prérequis :** DOS_ARTICLE_CHEN
- **Stockage :** VAR_CF_D10 bits 12-13 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Montrer l'article annote** - deltas : rI-2, rG+2, CHEN_CONFRONTE · immédiat : Chen palit : 'Je ne savais pas qui lirait.' · différé : ch. 12 : Chen AVOUE si on le designe. · [gain : rG / perte : rI]
  - **b) Rester** - deltas : rI+1, rG-1 · immédiat : Chen nie ; Agatha sourit mal. · différé : ch. 12 : Agatha révèle l'article en séance ; Chen NIE. · [gain : rI / perte : rG]
- **Lecteurs (contenu affecté) :** D112 (Chen); fin cachée
- **Délai principal :** différé court
- **Fins :** fin cachée.
- **Test :** Prérequis DOS_ARTICLE_CHEN. a : CHEN_CONFRONTE.

### D088 - Le plan de Fuji
`E` · `M` · arbitrage · Ch. 9 · statut **proposé** · verdict **VALIDE**

- **Unité :** MtPyre_Summit (sortie) - CF_D088
- **Déclencheur :** Fuji veut libérer Hoopa 'à tout prix', quitte a briser la Fiole.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D10 bits 14-15 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Lui demander d'attendre Hoopa** - deltas : HO+3, rI-2, FUJI_ATTEND · immédiat : Fuji : 'J'attendrai. Pas eternellement.' · différé : climax : Fuji ne brise que si HO<40. · [gain : HO / perte : rI]
  - **b) Refuser son plan** - deltas : rI+2, HO-2 · immédiat : Fuji part seul. · différé : climax : Fuji au relais = BRISER. · [gain : rI / perte : HO]
- **Lecteurs (contenu affecté) :** climax (intention de Fuji)
- **Délai principal :** différé long · signal de mémoire : Fuji : 'J'attendrai.' (Carnet, si a)
- **Fins :** F5/F2.
- **Test :** a : FUJI_ATTEND.

### D089 - Auguste rejoint-il Fuji ?
`D` · `S` · présence · Ch. 9 · statut **proposé** · verdict **VALIDE**

- **Unité :** MtPyre_Exterior - CF_D089
- **Déclencheur :** Auguste hésite entre Max et Fuji.
- **Prérequis :** AUGUSTE_DOUTE (D062 a)
- **Stockage :** VAR_CF_D11 bits 0-1 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Designer Fuji (il parle)** - deltas : rM-5, rG+1, REL_AUGUSTE_FUJI · immédiat : Auguste suit Fuji. · différé : Magma perd son geologue (Sommet MAX) ; climax : Fuji competent au relais. · [gain : rG / perte : rM]
  - **b) Rester** - deltas : rM+2 · immédiat : Auguste rentre a Vermilava. · différé : rien. · [gain : rM / perte : -Fuji seul]
- **Lecteurs (contenu affecté) :** climax (Fuji); Sommet MAX
- **Délai principal :** différé long
- **Fins :** climax relais.
- **Test :** Prérequis AUGUSTE_DOUTE. a : REL_AUGUSTE_FUJI.

### D090 - W8 : Ondine et Aldo sur le port
`E` · `S` · présence · Ch. 9 · statut **proposé** · verdict **VALIDE**

- **Unité :** LilycoveCity_Harbor - CF_D090
- **Déclencheur :** Ondine a ouvert un filet ; Aldo porte les caisses vides des pêcheurs.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D11 bits 2-3 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Designer Ondine** - deltas : rA+3, rP-3, REL_ONDINE_ARTHUR · immédiat : Ondine : 'Je n'ai pas fini.' · différé : ch. 11 : Ondine du côté Aqua. · [gain : rA / perte : rP]
  - **b) Designer Aldo** - deltas : rP+3, rA-2, ONDINE_MISSION · immédiat : Ondine regarde les caisses ; elle se tait. · différé : ch. 11 : Ondine du côté Mission. · [gain : rP / perte : rA]
- **Lecteurs (contenu affecté) :** ch. 11 (camp d Ondine, D104); brief B (Ondine)
- **Délai principal :** différé court
- **Fins :** indirect.
- **Test :** a : REL_ONDINE_ARTHUR ; b : ONDINE_MISSION (prioritaire sur D082 c).

### D091 - Damien : fermer les yeux sur les petits trafics
`D` · `S` · arbitrage · Ch. 9 · statut **proposé** · verdict **VALIDE**

- **Unité :** LilycoveCity - CF_D091
- **Déclencheur :** Damien offre les noms des acheteurs de la Rocket si Red ignore ses combines.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D11 bits 4-5 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Accepter** - deltas : RK-3, rL-2 · immédiat : Damien siffle trois noms. · différé : ch. 10 : l'assaut a moins de soutien local. · [gain : RK / perte : rL]
  - **b) Le designer à la brigade** - deltas : rL+3, RK+1 · immédiat : Damien passe une nuit au poste. · différé : ch. 14 : Damien froid à la Ligue. · [gain : rL / perte : RK]
- **Lecteurs (contenu affecté) :** RK; ch. 14 Damien
- **Délai principal :** différé court
- **Fins :** variante Rocket.
- **Test :** a : RK-3 ; b : rL+3.

### D092 - Montrer l'inscription à Marc
`E` · `S` · aveu · Ch. 9 · statut **proposé** · verdict **VALIDE**

- **Unité :** LilycoveCity_ContestHall - CF_D092
- **Déclencheur :** Marc doit choisir entre les Sages et son ami Pierre Rochard.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D11 bits 6-7 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Montrer** - deltas : rG+3, rC-2, MARC_SAGES · immédiat : Marc lit trois fois : 'Les Sages avaient raison.' · différé : Pierre Rochard peut passer SCEAU (avec PR>=55). · [gain : rG / perte : rC]
  - **b) Garder** - deltas : rG-1, rC+1 · immédiat : Marc reste avec son ami. · différé : rien. · [gain : rC / perte : rG]
- **Lecteurs (contenu affecté) :** STANCE_PR (axe B); Sommet PRO
- **Délai principal :** différé court
- **Fins :** F1 via Pierre Rochard.
- **Test :** a : MARC_SAGES.

### D093 - Safari : le garde qui revend la réserve
`D` · `S` · aveu · Ch. 9 · statut **proposé** · verdict **VALIDE**

- **Unité :** SafariZone_South - CF_D093
- **Déclencheur :** Un garde du Rempart revend des arrivants saisis.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D11 bits 8-9 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Le designer** - deltas : RK-3, rL-3 · immédiat : Scandale ; la réserve ferme deux jours. · différé : Sommet : NOR plus faible (rL). · [gain : RK / perte : rL]
  - **b) Acheter un arrivant (1 000 P)** - deltas : RK+2, rA+1, -1000 P · immédiat : Le garde empoche. · différé : le trafic continue. · [gain : +Équipe, rA / perte : Argent, RK]
- **Lecteurs (contenu affecté) :** RK; rL
- **Délai principal :** immédiat
- **Fins :** variante Rocket.
- **Test :** a : RK-3 ; b : Pokémon, -1000 P.

## Ch. 10

### D094 - Assaut du relais : le partenaire de duo
`E` · `M` · présence · Ch. 10 · statut **proposé** · verdict **VALIDE**

- **Unité :** MossdeepCity_SpaceCenter_1F - CF_D094 (jalon plafond 49 après l assaut, toutes issues)
- **Déclencheur :** Ariane attaque ; deux combats en duo. Partenaires selon les relations.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D11 bits 10-11 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Brice** - deltas : BR+3, PE-1, DUO_BRICE · immédiat : Brice apprend le relais. · différé : climax : Brice competent au relais. · [gain : BR / perte : PE]
  - **b) Peter** - deltas : PE+3, rC-2, DUO_PETER · immédiat : Peter casse une porte. · différé : climax : Peter competent au relais (déjà). · [gain : PE / perte : rC]
  - **c) Pierre Rochard** - deltas : PR+3, BR-1, DUO_PR · *si* PR>=50 · immédiat : Pierre Rochard ouvre le coeur. · différé : climax : PR au relais. · [gain : PR / perte : BR]
- **Lecteurs (contenu affecté) :** climax (competence relais)
- **Délai principal :** différé long · signal de mémoire : Le partenaire : 'Au relais, je connais le chemin.'
- **Fins :** climax.
- **Test :** Les trois : VAR_CF_CAP>=49. Slot 1/2/3.

### D095 - Le faux Giovanni (Lambda)
`E` · `M` · aveu · Ch. 10 · statut **proposé** · verdict **VALIDE**

- **Unité :** MossdeepCity_SpaceCenter_2F - CF_D095
- **Déclencheur :** 'Giovanni' commande l'assaut ; la Ligue y croit.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D11 bits 12-13 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Montrer une preuve (photo, horaire vendu, lettre de Ferrand)** - deltas : RK-5, GI+5, rL-2, LAMBDA_DEMASQUE · *si* une des 3 pièces · immédiat : Lambda arrache son masque ; le vrai Giovanni desavoue. · différé : GI : témoignage possible ; Kanto n'est pas accuse. · [gain : GI, RK / perte : rL]
  - **b) Designer Koga (il connait les visages)** - deltas : RK-3, rI-3, LAMBDA_DEMASQUE, KOGA=DEMASQUE · immédiat : Koga : 'Je le connais. Je les ai payes.' · différé : Koga DEMASQUE (W10). · [gain : RK / perte : rI]
  - **c) Rester** - deltas : rI-5, GI-5, rL+2 · immédiat : La Ligue accuse Kanto ; Giovanni desavoue plus tard, seul. · différé : FK plus dur ; GI. · [gain : rL / perte : GI, rI]
- **Lecteurs (contenu affecté) :** D114; REL_KOGA_PETER; Sommet M3
- **Délai principal :** immédiat · signal de mémoire : Carnet : 'Le masque. Ou pas.'
- **Fins :** R4.
- **Test :** a : LAMBDA_DEMASQUE ; b : KOGA=DEMASQUE ; c : rI-5.

### D096 - Levy et Tatia entendent la 'voix'
`D` · `S` · présence · Ch. 10 · statut **proposé** · verdict **VALIDE**

- **Unité :** MossdeepCity_Gym (après badge 7) - CF_D096
- **Déclencheur :** Les jumeaux captent quelque chose dans le relais.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D11 bits 14-15 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Rester avec eux** - deltas : rP-2, HO+1, DOS_VOIX_RELAIS · immédiat : 'Il a faim. Il a peur. Il est enferme dans une bouteille.' · différé : Sommet M1 (LIBERER) ; D101. · [gain : Dossier, HO / perte : rP]
  - **b) Aider a evacuer le quai** - deltas : rP+3 · immédiat : Le quai est vide avant la deuxième vague. · différé : rien. · [gain : rP / perte : -pièce]
- **Lecteurs (contenu affecté) :** Sommet M1; D101
- **Délai principal :** différé court
- **Fins :** indirect.
- **Test :** a : DOS_VOIX_RELAIS ; b : rP+3.

### D097 - Le registre du coffre (Ciléo)
`E` · `S` · aveu · Ch. 10 · statut **proposé** · verdict **VALIDE**

- **Unité :** MossdeepCity_SpaceCenter_2F - CF_D097 (DOS_REGISTRE toujours)
- **Déclencheur :** Ciléo a copie le registre : la Fiole vient du coffre de Sylphe.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D12 bits 0-1 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Le garder pour le Sommet** - deltas : rC+1, PR-1 · immédiat : Ciléo : 'D'accord. Devant tout le monde.' · différé : Sommet : pièce a montrer (PARTAGEE). · [gain : rC / perte : PR]
  - **b) Le donner tout de suite à Pierre Rochard** - deltas : PR+3, rC-5, PR_PREUVE · immédiat : Pierre Rochard serre le papier. · différé : ACCUSE plus probable. · [gain : PR / perte : rC]
- **Lecteurs (contenu affecté) :** Sommet M3; STANCE_PR
- **Délai principal :** différé court
- **Fins :** F2.
- **Test :** Les deux : DOS_REGISTRE.

### D098 - La lettre d'Amos
`D` · `S` · don · Ch. 10 · statut **proposé** · verdict **VALIDE**

- **Unité :** MossdeepCity - CF_D098
- **Déclencheur :** Amos propose 'un retour digne de Giovanni, sans la Fiole'.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D12 bits 2-3 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) La donner à Giovanni** - deltas : GI+3, RK-3, rI-2 · immédiat : Giovanni dechire la lettre. · différé : Amos discredite ; ch. 13 : pas de seconde équipe Rocket. · [gain : GI, RK / perte : rI]
  - **b) La donner à Peter** - deltas : rI+3, GI-3 · immédiat : Peter : 'Enfin un nom.' · différé : rien. · [gain : rI / perte : GI]
- **Lecteurs (contenu affecté) :** RK (climax); GI
- **Délai principal :** différé court
- **Fins :** variante Rocket.
- **Test :** a : GI+3, RK-3 ; b : rI+3.

### D099 - Levy et Tatia veulent sonder Hoopa
`E` · `S` · arbitrage · Ch. 10 · statut **proposé** · verdict **VALIDE**

- **Unité :** MossdeepCity_Gym - CF_D099
- **Déclencheur :** 'Laisse-nous l'entendre. Il a peur, ou il nous fera confiance.'
- **Prérequis :** Hoopa garde par Red
- **Stockage :** VAR_CF_D12 bits 4-5 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Accepter** - deltas : HO+5, rG-2 · immédiat : Hoopa tremble, puis se calme (si HO>=40) ou fuit (sinon : HO-5 applique à la place). · différé : HO. · [gain : HO / perte : rG]
  - **b) Refuser** - deltas : rG+1, HO-1 · immédiat : Les jumeaux s'inclinent. · différé : rien. · [gain : rG / perte : HO]
- **Lecteurs (contenu affecté) :** HO
- **Délai principal :** différé long
- **Fins :** F2.
- **Test :** Prérequis garde = RED. Si HO<40 : delta réel HO-5 (annonce par la réplique).

### D100 - Défi Indigo de Peter (refusable)
`D` · `S` · combat · Ch. 10 · statut **proposé** · verdict **VALIDE**

- **Unité :** MossdeepCity - CF_D100 (FLAG_CF_REFUS_PETER)
- **Déclencheur :** Peter : 'Montre-moi ce que Hoenn t'a appris.'
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D12 bits 6-7 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Accepter et gagner** - deltas : PE+3, rG-1 · immédiat : Peter salue. · différé : PE (veillée). · [gain : PE / perte : rG]
  - **b) Accepter et perdre** - deltas : PE+1, BR-1, -1000 P · immédiat : 'Encore trop tendre.' · différé : rien. · [gain : PE / perte : Argent, BR]
  - **c) Refuser** - deltas : PE-3, rG+2 · immédiat : 'Tu ne sers pas Kanto.' · différé : refus definitif. · [gain : rG / perte : PE]
- **Lecteurs (contenu affecté) :** PE (veillée, STANCE_PETER)
- **Délai principal :** différé court
- **Fins :** climax.
- **Test :** slot 1/2/3.

### D101 - Maison de Pierre Rochard : faut-il garder le relais ?
`E` · `S` · aveu · Ch. 10 · statut **proposé** · verdict **VALIDE**

- **Unité :** MossdeepCity_StevensHouse - CF_D101 (CS Plongee remise dans les deux cas)
- **Déclencheur :** Pierre Rochard : 'Hoenn peut-il couper ce qui le nourrit ?'
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D12 bits 8-9 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Rester (accord)** - deltas : rC+3, rG-2, PR_B=CTL · immédiat : 'Alors, une charte.' · différé : PRO vote CHARTE au Sommet. · [gain : rC / perte : rG]
  - **b) Montrer la voix du relais ou le battement** - deltas : rC-3, PR+2 · *si* DOS_VOIX_RELAIS ou DOS_BATTEMENT · immédiat : Il reste longtemps à la fenetre. · différé : PRO : LIBERER si DOS_VOIX_RELAIS et PR>=60 ; SCEAU si MARC_SAGES. · [gain : PR / perte : rC]
- **Lecteurs (contenu affecté) :** Sommet PRO; climax (intention de PR)
- **Délai principal :** différé court
- **Fins :** F3/F1.
- **Test :** Les deux : FLAG_RECEIVED_HM_DIVE. a : PR_B=CTL ; b : PR_B selon pièces.
