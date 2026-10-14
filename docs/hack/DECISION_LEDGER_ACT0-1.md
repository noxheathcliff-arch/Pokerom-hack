# DECISION_LEDGER_ACT0-1 - Prologue et Acte I (ch. 0-4) (*Pokémon Confluence*, brief C)

> Généré par `docs/hack/data/cf_model.py --render` a partir de `docs/hack/data/cf_decisions.py` (source unique). Ne pas éditer à la main : éditer les données puis régénérer.
> Règles, légende, décomptes et audit : `DECISION_LEDGER.md`. Systèmes, seuils et allocation : `GAME_SYSTEMS.md`. **Statut de toutes les entrées : propose (rien n est implémenté ni teste).**
> Accents restaurés au rendu (`cf_accents.py`) : les données sont saisies sans accents. Les répliques en jeu seront écrites par les scénaristes (<= 208 px, 2 lignes, guillemets “ ”).

**Décisions : 45** (E 24 / D 21 ; S 34 / M 9 / L 2 ; comptées 42)

## Prologue

### D001 - Qui Red rattrape dans l'anneau
`E` · `L` · présence · Prologue · statut **proposé** · verdict **VALIDE**

- **Unité :** Route104 (plage, nuit) - CF_D001
- **Déclencheur :** 3e combat a pleine force ; un anneau s'ouvre sous Red et aspire l'équipe (E-REMOVE). Deux silhouettes à portée : Pikachu, le sac de Ciléo.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D00 bits 0-1 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Pikachu (il saute vers Red)** - deltas : rI-3, PIKA_BLESSE · immédiat : Pikachu blessé reste avec Red ; Ciléo perd son disque du nœud. · différé : ch. 4 : Seko rend Pikachu (D041) ; ch. 3 : Ciléo n'a pas de preuve (Mission plus froide). · [gain : +Équipe (Pikachu au ch. 4) / perte : rI]
  - **b) Le sac de Ciléo (disque du nœud Kanto)** - deltas : rI+5, rC-3, DOS_JOURNAL_NOEUD · immédiat : Pikachu disparaît avec l'équipe ; Ciléo serre son disque. · différé : ch. 3 : Ciléo prouve l'horodatage du nœud à Peter (rI) ; Pikachu ne revient qu'au postgame avec l'équipe. · [gain : Dossier, rI / perte : -Équipe (Pikachu part avec les autres), rC]
- **Lecteurs (contenu affecté) :** D041 (ch. 4); ch. 3 entrepôt Ciléo; Sommet M3 (pièce); postgame retour équipe
- **Délai principal :** différé court · signal de mémoire : Carnet : "Pikachu a saute. Pas moi." (a) / "Le disque. Pas lui." (b)
- **Fins :** aucune directe ; DOS_JOURNAL_NOEUD compte au Dossier (fin cachée).
- **Test :** État : nouvelle partie. Séquence : 3 combats R104, choix a puis b (deux saves). Attendu a : flag PIKA_BLESSE, D00 bits0-1=1, rI=47 ; b : DOS_JOURNAL_NOEUD, slot=2, rI=55, rC=47 ; ch. 3 Ciléo : ligne 'preuve' seulement en b.

### D002 - Accreditation par telephone : nom ou anonymat
`E` · `M` · aveu · Prologue · statut **proposé** · verdict **VALIDE**

- **Unité :** PetalburgCity_Gym (QG du Rempart, telephone de Seko) - CF_D002
- **Déclencheur :** Norman exige un nom pour l'accreditation de crise d'un dresseur étranger.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D00 bits 2-3 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Donner son nom (Red)** - deltas : rL+3, RK+3, N=2 · immédiat : Norman : 'Le champion de Kanto. Bien.' Badge provisoire. · différé : Défis Indigo offerts des le ch. 3 ; ch. 10 : Lambda tend un piege nominatif (vague de sbires en plus). · [gain : rL / perte : RK]
  - **b) Rester anonyme (Brice invente 'le Passeur')** - deltas : rL-3, BR+2, N=0 · immédiat : Norman : controle renforce ; Brice rit de son pseudonyme. · différé : Défis Indigo seulement après le ch. 10 ; barrage de brigade à Clémenti demande Brice comme garant. · [gain : BR / perte : rL]
- **Lecteurs (contenu affecté) :** ch. 1 QG Clémenti; ch. 3 Défis Indigo; ch. 10 piege de Lambda; Sommet (traduction : N); épilogue presse
- **Délai principal :** différé court · signal de mémoire : Brice : 'Je note : Passeur. Ça sonne bien.' (b)
- **Fins :** variantes de presse de l épilogue (N).
- **Test :** État : ch. 0 après labo. a : VAR_CF_WORLD N=2, rL=53, RK=23 ; b : N=0, rL=47, BR=52. Ch. 3 : PNJ Défi present seulement si N>=1.

### D003 - Ronde nocturne de Brice encerclee (R101)
`D` · `S` · geste · Prologue · statut **proposé** · verdict **VALIDE**

- **Unité :** Route101 (nuit) - CF_D003
- **Déclencheur :** Brice compte des arrivants, encercle ; Red à le starter de Seko depuis 2 minutes.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D00 bits 4-5 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Intervenir tout de suite** - deltas : BR+3, HO-1, BV.PROT+1 · immédiat : Combat immédiat ; Brice : 'Tu es tombe du ciel ?' · différé : BV PROTEGER +1. · [gain : BR / perte : HO]
  - **b) Rester (observer le motif)** - deltas : BR-3, BV.COMP+1 · immédiat : Les arrivants fuient tous vers le même point ; Brice est griffe. · différé : BV COMPRENDRE +1 ; Carnet 'Ils fuient vers la lumière'. · [gain : +Information (les arrivants fuient vers l anneau) / perte : BR]
- **Lecteurs (contenu affecté) :** calcul BV (ch. 7, ch. 12); BR seuils
- **Délai principal :** différé court
- **Fins :** BV -> vote de Brice et voix de l épilogue.
- **Test :** État : ch. 0 R101. a : BVCOUNT.P=1, BR=53 ; b : BVCOUNT.C=1, BR=47 ; ligne Carnet présente en b.

### D004 - Starter de Seko (Arcko, Poussifeu, Gobou)
`E` · `S` · arbitrage · Prologue · statut **proposé** · verdict **FAIBLE (liste, non comptée)** (choix de combat vanilla, pas une décision narrative (revue v2 D006) : liste, non compte)

- **Unité :** LittlerootTown_ProfessorBirchsLab - CF_D004
- **Déclencheur :** Seko présente trois natifs de Hoenn.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D00 bits 6-7 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Arcko** - deltas : -
  - **b) Poussifeu** - deltas : -
  - **c) Gobou** - deltas : -
- **Lecteurs (contenu affecté) :** équipe de Brice (starter fort)
- **Délai principal :** immédiat
- **Fins :** aucune
- **Test :** État : labo. Attendu : starter reçu ; équipe de Brice R103 = starter fort contre.

### D005 - Lettre de Chen : la montrer à Seko ou la garder
`E` · `S` · don · Prologue · statut **proposé** · verdict **VALIDE**

- **Unité :** LittlerootTown_ProfessorBirchsLab - CF_D005
- **Déclencheur :** La lettre de Chen demande à Red ses observations 'avant tout le monde'.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D00 bits 8-9 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Montrer la lettre à Seko** - deltas : BR+2, CHEN_LETTRE_MONTREE · immédiat : Seko se raidit ; il ouvre son registre à Red. · différé : ch. 3 : Chen froid ('Vous l'avez montree.') ; REL_CHEN_SEKO plus dur (exige la publication partagee). · [gain : BR / perte : -Chen (rivalite aggravee)]
  - **b) Garder la lettre** - deltas : BR-2 · immédiat : Brice voit Red ranger une lettre ; il ne demande rien. · différé : ch. 3 : Chen offre le Multi Exp en échange de données (D030). · [gain : +Chen (confiance) / perte : BR]
- **Lecteurs (contenu affecté) :** ch. 3 Chen (D030); ch. 7 dîner; épilogue Chen-Seko
- **Délai principal :** différé court
- **Fins :** fin cachée (via REL_CHEN_SEKO).
- **Test :** a : flag CHEN_LETTRE_MONTREE, BR=52 ; b : BR=48 ; ch. 3 : réplique de Chen differente.

### D006 - Rester chez M. Marco ou suivre Ciléo
`D` · `S` · présence · Prologue · statut **proposé** · verdict **VALIDE**

- **Unité :** Route104_MrBrineysHouse - CF_D006
- **Déclencheur :** Après la plage, M. Marco cherche Piko ; Ciléo part seul vers Clémenti.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D00 bits 10-11 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Rester avec M. Marco** - deltas : rL-2, DOS_CLOCHETTE_PIKO, MARCO_ALLIE · immédiat : M. Marco : Piko a disparu le jour d'un anneau (indice R3). Ciléo est retenu une nuit par la brigade. · différé : ch. 2 : passage gratuit et confidences ; Sommet : clochette = pièce (loi H1). · [gain : Dossier / perte : rL]
  - **b) Suivre Ciléo** - deltas : rI+2 · immédiat : Ciléo passe le barrage grace à Red. · différé : ch. 3 : Ciléo plus ouvert ; Piko n'est evoque qu'au ch. 6. · [gain : rI / perte : -Information (indice R3 manque)]
- **Lecteurs (contenu affecté) :** ch. 2 bateau; ch. 9 R3; Sommet M2 (pièce); F2 épilogue Piko
- **Délai principal :** différé court
- **Fins :** F2 : Piko rendu (scène plus forte si a).
- **Test :** a : DOS_CLOCHETTE_PIKO pose, rL=48 ; b : rI=52 ; ch. 2 : dialogue de Marco différé.

### D007 - R103 : l'arrivant blessé
`D` · `S` · arbitrage · Prologue · statut **proposé** · verdict **VALIDE**

- **Unité :** Route103 - CF_D007
- **Déclencheur :** Après le duel avec Brice, un Zigzaton de Galar blessé ; la brigade arrive.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D00 bits 12-13 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Le capturer (Poke Ball de Seko)** - deltas : rL-2, BV.ACC+1 · immédiat : Il entre dans l'équipe ; Brice : 'On le declare ou pas ?' · différé : ch. 1 : Flora remarque l'arrivant (réplique) ; BV ACCUEILLIR +1. · [gain : +Équipe (arrivant) / perte : rL]
  - **b) Le laisser à la brigade** - deltas : rL+2, BV.PROT+1 · immédiat : La brigade l'emmene ; Brice note le numéro. · différé : BV PROTEGER +1 ; ch. 1 Flora : 'Merci pour le signalement.' · [gain : rL / perte : -Équipe]
- **Lecteurs (contenu affecté) :** ch. 1 Flora; calcul BV
- **Délai principal :** immédiat
- **Fins :** BV.
- **Test :** a : Pokémon reçu, BVCOUNT.A=1, rL=48 ; b : BVCOUNT.P=1, rL=52.

## Ch. 1

### D008 - Bois Clémenti : Flora et la brigade (combat refusable)
`E` · `M` · combat · Ch. 1 · statut **proposé** · verdict **VALIDE**

- **Unité :** PetalburgWoods - CF_D008 (trainerbattle_single_declinable, FLAG_CF_REFUS_FLORA1)
- **Déclencheur :** Flora abat des arrivants ; elle defie Red qui s'interpose.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D00 bits 14-15 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Accepter et gagner** - deltas : FL-3, rL-3, BOIS_SAUVES · immédiat : La brigade recule ; trois arrivants s'enfuient vers le Bois. · différé : ch. 7 : Flora 'Tu m'as humiliee au Bois' ; Z-02 +arrivants (pas d'état). · [gain : +arrivants sauvés / perte : FL, rL]
  - **b) Accepter et perdre** - deltas : FL+2, rL+1, -300 P · immédiat : Flora : 'Au moins, tu t'es battu.' · différé : ch. 7 : respect de Flora (+2 cumule). · [gain : FL, rL / perte : -arrivants abattus, Argent]
  - **c) Refuser** - deltas : FL+3, BR-2 · immédiat : Brice : 'On les laisse faire ?' ; Flora salue. · différé : refus definitif (FLAG_CF_REFUS_FLORA1) ; ch. 7 : Flora te parle d'egal a egal. · [gain : FL / perte : -arrivants abattus, BR]
- **Lecteurs (contenu affecté) :** FL seuils (ch. 7 Vergazon, ch. 13 bascule); rL (Sommet NOR)
- **Délai principal :** immédiat · signal de mémoire : Brice : 'Flora s'en souviendra. Moi aussi.'
- **Fins :** FL -> Flora désobéit (civils) -> casualties variante.
- **Test :** a/b/c avec FLAG_CF_NO_WHITEOUT pose avant le combat. Attendu : slot D008 = 1/2/3 ; c : refus flag pose, le PNJ ne repere plus.

### D009 - L'affiche Passerelle (Red de dos)
`D` · `S` · présence · Ch. 1 · statut **proposé** · verdict **VALIDE**

- **Unité :** RustboroCity - CF_D009
- **Déclencheur :** Une affiche : 'Il a sauvé Sylphe. Sylphe relie le monde.' Brice reconnaît la silhouette.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D01 bits 0-1 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Rester devant** - deltas : BR+2, RK+2, N+1, DOS_AFFICHE_SYLPHE · immédiat : Brice se tait (une fois) ; un passant prend une photo. · différé : Sommet M3 : pièce 'la part de Red' ; Rocket sait que Red est la. · [gain : BR, Dossier / perte : RK]
  - **b) Partir** - deltas : BR-1 · immédiat : Brice : 'C'etait toi ?' Pas de réponse. · différé : pièce recuperable seulement au ch. 12 aupres du Président (moins forte : 1 voix). · [gain : +discretion (N inchange) / perte : -pièce manquée, BR]
- **Lecteurs (contenu affecté) :** Sommet M3 (montrer); ch. 12 Président; N
- **Délai principal :** différé long
- **Fins :** fin cachée (pièce).
- **Test :** a : DOS_AFFICHE_SYLPHE pose, N+1, RK=22 ; b : BR=49, aucune pièce.

### D010 - Mission de zone Z-02 : les mines de Devon
`E` · `M` · arbitrage · Ch. 1 · statut **proposé** · verdict **VALIDE**

- **Unité :** RustboroCity / RusturfTunnel ouest (galeries) - CF_D010
- **Déclencheur :** Charbi et Strassie rongent les galeries ; mineurs mis a pied. Trois approches.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D01 bits 2-3 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Déplacer avec Pierre (Brock)** - deltas : rI+3, rP-3, Z02=RESTAURE, BROCK_PROTEGES · immédiat : Galeries fermees une semaine ; les arrivants partent chez Pierre. · différé : Z-02 RESTAURE (Skitty revient) ; Pierre aligne ses protégés ; ch. 7 : ils risquent l'abattage. · [gain : Écosystème, rI / perte : rP]
  - **b) Donner les relevés à Roxanne** - deltas : rC+3, rP+2, rA-2, Z02=MIXTE · immédiat : Devon rouvre avec un protocole ; Roxanne cite Red. · différé : Z-02 MIXTE ; ch. 7 : Roxanne s'appuie sur ces relevés au vote. · [gain : Écosystème, rC, rP / perte : rA]
  - **c) Laisser les mineurs abattre** - deltas : rL+4, rP+3, rI-3, TI-2, Z02=ABATTU · immédiat : Les galeries se vident ; un mineur pleure son Charbi apprivoise. · différé : Z-02 ABATTU (densite x0,5) ; Pierre amer (vote ch. 12 retrait). · [gain : rL, rP / perte : Écosystème, TI, rI]
- **Lecteurs (contenu affecté) :** E-ECO tables Z-02; boutique Mérouville (Corde Sortie absente si ENVAHI); Pierre (Brock) équipe et vote ch. 12; Sommet COM; diaporama
- **Délai principal :** immédiat · signal de mémoire : Brice note l'état de la galerie dans son recensement.
- **Fins :** variante sociale (moyenne des zones).
- **Test :** Save ch. 1 avant mission ; 50 rencontres R116 par issue ; compter Skitty (ENVAHI ~0, RESTAURE ~10). VAR_CF_ECO bits Z02 = 2/1/3. Non faite au badge 1 : MIXTE (1).

### D011 - Presentation de Passerelle : la photo publique
`E` · `S` · arbitrage · Ch. 1 · statut **proposé** · verdict **VALIDE**

- **Unité :** RustboroCity_DevonCorp_3F - CF_D011
- **Déclencheur :** Le Président de Sylphe veut une photo de Red à côté du Kiosque.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D01 bits 4-5 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Poser (rester)** - deltas : rC+5, rP-3, N+1 · immédiat : Flash ; le Président serre la main de Red. · différé : ch. 3 : Kiosque -10 % ; ch. 12 : 'Vous avez pose pour nous.' · [gain : rC / perte : rP]
  - **b) Partir** - deltas : rC-3, rP+2 · immédiat : Le Président rit jaune. · différé : ch. 3 : commercants de Poivressel plus chaleureux. · [gain : rP / perte : rC]
- **Lecteurs (contenu affecté) :** ch. 3 Kiosque (prix); Sommet M1/M3 (NOR rL>=rC, COM rP>=rC+5); ch. 12 Président
- **Délai principal :** différé court
- **Fins :** F3 (rC>=50).
- **Test :** a : rC=55, rP=47, N+1, prix Kiosque reduit ; b : rC=47, rP=52.

### D012 - Petit voleur n 1 : le carnet de Brice
`D` · `S` · geste · Ch. 1 · statut **proposé** · verdict **VALIDE**

- **Unité :** RustboroCity (Devon, sortie) - CF_D012
- **Déclencheur :** Un petit anneau prend le carnet de Brice ; une silhouette violette.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D01 bits 6-7 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Lui lancer une baie (donner)** - deltas : HO+5, BR-2 · immédiat : Il attrape la baie et disparaît avec le carnet. · différé : ch. 7 : il rend le carnet si HO>=40 (D066). · [gain : HO / perte : BR, Objets]
  - **b) Le poursuivre** - deltas : HO-3, BR+2, BV.COMP+1 · immédiat : Red récupère 4 pages ; le voleur fuit vers l'est. · différé : indice R2b (fuite vers l'est) ; BV COMPRENDRE +1. · [gain : BR / perte : HO]
  - **c) Ignorer** - deltas : HO+1, BR-1 · immédiat : Brice : 'Tu ne fais rien ?!' · différé : ch. 7 : carnet rendu seulement si HO>=40. · [gain : HO / perte : BR]
- **Lecteurs (contenu affecté) :** HO (rencontres suivantes, ch. 8 révélation, climax); D066
- **Délai principal :** différé court
- **Fins :** F2 (HO).
- **Test :** a : HO=25 ; b : HO=17 ; c : HO=21. Saillance de Hoopa au ch. 2 selon bande de HO.

### D013 - Devon 2F : l'ingenieur 'Ferrand'
`D` · `S` · geste · Ch. 1 · statut **proposé** · verdict **VALIDE**

- **Unité :** RustboroCity_DevonCorp_2F - CF_D013
- **Déclencheur :** Un ingenieur de Passerelle pose trop de questions sur le Rubis et le Saphir.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D01 bits 8-9 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Rester (le laisser parler)** - deltas : RK+3, LAMBDA_REMARQUE · immédiat : Il note quelque chose ; Brice : 'Il parle comme un vendeur.' · différé : ch. 7 : filature de Lambda proposee d'office (D063 a) ; Lambda vend les mouvements de Red. · [gain : +information (filature ch. 7) / perte : RK]
  - **b) Partir** - deltas : BR-1 · immédiat : Rien. · différé : ch. 7 : la filature exige d'avoir vu Lambda à Lavandia (ch. 4). · [gain : +RK inchange / perte : -indice manque, BR]
- **Lecteurs (contenu affecté) :** D063 (ch. 7); ch. 10 faux Giovanni (D095)
- **Délai principal :** différé court
- **Fins :** RK.
- **Test :** a : LAMBDA_REMARQUE, RK=23 ; ch. 7 : option filature visible. b : BR=49.

### D014 - R116 : contrebandiers Rocket avant l'anneau
`E` · `M` · arbitrage · Ch. 1 · statut **proposé** · verdict **VALIDE**

- **Unité :** Route116 - CF_D014
- **Déclencheur :** Lance (Rocket) et deux sbires attendent pres des rochers ; un anneau va s'ouvrir.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D01 bits 10-11 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Les affronter** - deltas : RK-3, rL+1, -200 P · immédiat : Combat ; l'anneau s'ouvre quand même et prend un objet non-clé. · différé : ch. 4 : Lance (Rocket) reconnaît Red (réplique). · [gain : RK, rL / perte : -l'anneau prend un objet du sac (liste), Argent]
  - **b) Observer cache (rester)** - deltas : RK+3, DOS_HORAIRE_R116 · immédiat : Ils consultent une montre avant l'anneau (indice R1-1). · différé : ch. 4 raid : Red sait ou chercher le carnet (option de raid supplémentaire). · [gain : Dossier / perte : RK]
  - **c) Prevenir la brigade** - deltas : rL+3, rA-2, TI-1 · immédiat : Flora arrête un sbire ; les arrivants livres sont abattus. · différé : ch. 4 : le Rempart se présente au raid (option c du raid renforcee). · [gain : rL / perte : TI, rA]
- **Lecteurs (contenu affecté) :** ch. 4 raid D040; R1 indices; RK
- **Délai principal :** immédiat · signal de mémoire : Carnet : 'Ils attendaient. Avant.'
- **Fins :** RK -> variante Rocket.
- **Test :** a : RK=17, objet retire ; b : DOS_HORAIRE_R116 pose, RK=23 ; c : rL=53.

### D015 - Le sbire ruiné (ancien mineur)
`D` · `S` · don · Ch. 1 · statut **proposé** · verdict **VALIDE**

- **Unité :** Route116 (après D014) - CF_D015
- **Déclencheur :** Un sbire blessé avoue : mis a pied des mines, recrute pour 200 P par nuit.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D01 bits 12-13 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Lui donner 500 P pour rentrer** - deltas : RK-2, rP+2, -500 P · immédiat : Il jette son uniforme. · différé : ch. 7 : on le revoit mineur à Mérouville (salue Red). · [gain : RK, rP / perte : Argent]
  - **b) Partir** - deltas : RK+2 · immédiat : Il remet sa casquette. · différé : ch. 4 : il est au raid du Tunnel (un sbire de plus). · [gain : +argent garde / perte : RK]
- **Lecteurs (contenu affecté) :** ch. 4 raid (effectif); ch. 7 Mérouville PNJ; RK
- **Délai principal :** différé court
- **Fins :** RK.
- **Test :** a : argent -500, RK baisse de 2, PNJ ch. 7 present ; b : sbire supplémentaire au raid.

### D016 - Badge 1 : Roxanne demande les données de Red
`E` · `S` · arbitrage · Ch. 1 · statut **proposé** · verdict **VALIDE**

- **Unité :** RustboroCity_Gym - CF_D016
- **Déclencheur :** Après le combat, Roxanne veut transmettre les observations de Red au Rempart.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D01 bits 14-15 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Donner** - deltas : rL+3, BR-2 · immédiat : Roxanne : 'Des données, pas des cris.' · différé : ch. 7 : Roxanne vote POUR l'abattage avec 'ses' chiffres sauf pièce montree. · [gain : rL / perte : BR]
  - **b) Refuser** - deltas : rL-2, BR+2 · immédiat : Brice souffle : 'Nos chiffres restent a nous.' · différé : ch. 7 : Roxanne s'abstient au vote. · [gain : BR / perte : rL]
- **Lecteurs (contenu affecté) :** ch. 7 vote d abattage (D069); BR
- **Délai principal :** différé court
- **Fins :** indirect (VOTE_ABATTAGE -> zones).
- **Test :** a : rL=53, BR=48, au ch. 7 Roxanne compte pour 'pour' ; b : abstention.

### D017 - QG de Clémenti : l'insigne de brigade
`D` · `S` · don · Ch. 1 · statut **proposé** · verdict **VALIDE**

- **Unité :** PetalburgCity_Gym (QG) - CF_D017
- **Déclencheur :** Norman propose un insigne qui ouvre les barrages de brigade.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D02 bits 0-1 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Accepter l'insigne** - deltas : rL+3, rA-3, INSIGNE · immédiat : Les barrages s'ouvrent ; Bastien et Aqua voient l'insigne. · différé : ch. 6 : Aqua refuse la parole à Red tant qu'il le porte (D054 b plus dur). · [gain : +acces (barrages sans garant), rL / perte : rA]
  - **b) Refuser** - deltas : rL-2, rA+1 · immédiat : Norman : 'A votre guise.' · différé : ch. 4 et 7 : chaque barrage demande Brice (BR>=40) ou une pièce. · [gain : rA / perte : -barrages : Brice garant, rL]
- **Lecteurs (contenu affecté) :** barrages ch. 4, ch. 7; D054 (option b); rA
- **Délai principal :** différé court
- **Fins :** indirect.
- **Test :** a : objet clé insigne, barrage R110 s'ouvre ; b : barrage exige Brice present.

## Ch. 2

### D018 - Mission de zone Z-01 : les pêcheries de Myokara
`E` · `M` · arbitrage · Ch. 2 · statut **proposé** · verdict **VALIDE**

- **Unité :** DewfordTown / Route106 - CF_D018
- **Déclencheur :** Krabby et Qwilfish crevent les filets ; Aldo veut chasser, Bastien déplacer.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D02 bits 2-3 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Avec Aldo et les pêcheurs : chasser** - deltas : rP+4, rA-3, Z01=ABATTU · immédiat : Battue sur les quais ; Bastien tourne le dos. · différé : Z-01 ABATTU ; ch. 9 : Aldo s'engage aux cotes des pêcheurs. · [gain : rP / perte : Écosystème, rA]
  - **b) Avec Bastien : déplacer vers la grotte marine** - deltas : rA+3, rP-3, Z01=MIXTE · immédiat : Les bancs partent ; le poisson manque une semaine. · différé : Z-01 MIXTE ; prix des Baies Oran en hausse à Myokara jusqu'au ch. 3. · [gain : Écosystème, rA / perte : rP]
  - **c) Escorte de nuit avec Brice (filets de Devon)** - deltas : rP+2, rA+2, PR-3, Z01=RESTAURE, BV.COMP+1 · immédiat : Toute la nuit en mer ; à l'aube, Goélise revient. · différé : Z-01 RESTAURE ; Pierre Rochard à quitte la Grotte Granite (D020 et D024 non rencontrees). · [gain : Écosystème, rA, rP / perte : -rencontre de Pierre Rochard manquée (DOS_ECLATS indisponible), PR]
- **Lecteurs (contenu affecté) :** E-ECO Z-01; Myokara boutique; Aldo ch. 9; D020/D024 (présence); Sommet COM; diaporama Myokara
- **Délai principal :** immédiat · signal de mémoire : Brice : 'Je mets Myokara en vert. Enfin, vert pale.'
- **Fins :** variante sociale.
- **Test :** Save avant mission ; 50 peches super canne : Krabby 60 % (ENVAHI) contre Magicarpe ; VAR_CF_ECO Z01 = 3/1/2. c : D020 et D024 marquees 'non rencontrees'.

### D019 - Petit voleur n 2 : le poisson du marché
`D` · `S` · geste · Ch. 2 · statut **proposé** · verdict **VALIDE**

- **Unité :** DewfordTown - CF_D019
- **Déclencheur :** Le voleur prend un poisson sur l'etal ; le marchand accuse Brice.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D02 bits 4-5 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Acheter un poisson et le lui laisser** - deltas : HO+5, -200 P · immédiat : Il prend le poisson, laisse une baie. · différé : HO>=25 : il rend la moitié au ch. 3. · [gain : HO / perte : Argent]
  - **b) Le signaler au marchand** - deltas : HO-3, rP+2 · immédiat : Le marchand rembourse Brice ; le voleur siffle. · différé : ch. 3 : il évite Red. · [gain : rP / perte : HO]
  - **c) Ignorer** - deltas : HO+1, rP-1 · immédiat : Brice paie de sa poche. · différé : rien d'immédiat. · [gain : HO / perte : rP]
- **Lecteurs (contenu affecté) :** HO
- **Délai principal :** différé court
- **Fins :** F2.
- **Test :** a : argent -200, HO +5 ; b : rP +2 ; c : HO +1.

### D020 - Grotte Granite : le secret des éclats
`E` · `S` · aveu · Ch. 2 · statut **proposé** · verdict **VALIDE**

- **Unité :** GraniteCave_StevensRoom - CF_D020
- **Déclencheur :** Pierre Rochard etudie des éclats rouges et bleus laisses par les anneaux ; il demande le silence.
- **Prérequis :** D018 != c (Pierre Rochard encore la)
- **Stockage :** VAR_CF_D02 bits 6-7 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Garder le secret** - deltas : PR+5 · immédiat : Il remet la lettre lue ; 'Merci. Mon père ne doit pas paniquer.' · différé : ch. 8 : il se confie davantage (D077). · [gain : PR / perte : -pièce non publique]
  - **b) Montrer les éclats à Brice** - deltas : PR-3, BV.COMP+1, DOS_ECLATS · immédiat : Brice photographie tout ; Pierre Rochard se ferme. · différé : Sommet M3 : DOS_ECLATS (Devon savait) ; ch. 7 : Seko connait les éclats. · [gain : Dossier / perte : PR]
- **Lecteurs (contenu affecté) :** PR seuils (duo ch. 10, climax, D077); Sommet M3 (pièce)
- **Délai principal :** différé court
- **Fins :** F3/F1 via PR.
- **Test :** Prérequis : D018 != c. a : PR=55 ; b : DOS_ECLATS, PR=47.

### D021 - Badge 2 : l'arrivant de Bastien
`E` · `S` · don · Ch. 2 · statut **proposé** · verdict **VALIDE**

- **Unité :** DewfordTown_Gym - CF_D021
- **Déclencheur :** Bastien a sauvé un Démanta des filets ; il le confie à qui le veut.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D02 bits 8-9 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Accepter** - deltas : rA+2, rP-2 · immédiat : Les pêcheurs regardent Red partir avec 'leur' probleme. · différé : ch. 11 : l'Aqua le reconnaît (+1 réplique, NEGOCIE plus facile si rA>=50). · [gain : +Équipe (Démanta, niv. plafond-3), rA / perte : rP]
  - **b) Refuser** - deltas : rP+2, rA-2 · immédiat : Bastien le garde ; un pêcheur hoche la tête. · différé : ch. 3 : un pêcheur offre une Super Canne. · [gain : rP / perte : -Équipe, rA]
- **Lecteurs (contenu affecté) :** rA (D102); rP
- **Délai principal :** immédiat
- **Fins :** indirect.
- **Test :** a : Pokémon reçu ; b : objet au ch. 3.

### D022 - Aldo propose un duel (refusable)
`D` · `S` · combat · Ch. 2 · statut **proposé** · verdict **VALIDE**

- **Unité :** DewfordTown (plage) - CF_D022 (FLAG_CF_REFUS_ALDO)
- **Déclencheur :** Aldo, escorte de la Mission arrive en avance, cherche 'un adversaire digne'.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D02 bits 10-11 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Accepter et gagner** - deltas : rI+2, rP-1, ALDO_RESPECT · immédiat : Aldo s'incline. · différé : ch. 11 : Aldo escorte Red a Fondmer (soigneur de repli). · [gain : +objet (Ceinture Noire), rI / perte : rP]
  - **b) Accepter et perdre** - deltas : rI+1, BR-1, -300 P · immédiat : Aldo : 'Encore.' · différé : ch. 9 : Aldo s'engage avec les pêcheurs. · [gain : rI / perte : Argent, BR]
  - **c) Refuser** - deltas : rP+2, rI-2 · immédiat : Aldo retourne aux caisses des pêcheurs. · différé : ch. 9 : Aldo s'engage avec les pêcheurs ; refus definitif. · [gain : rP / perte : rI]
- **Lecteurs (contenu affecté) :** ch. 9 W8; ch. 11 Fondmer (soin)
- **Délai principal :** différé court
- **Fins :** aucune.
- **Test :** a : ALDO_RESPECT, objet ; c : FLAG_CF_REFUS_ALDO.

### D023 - R106 : le pêcheur qui vend un arrivant
`D` · `S` · don · Ch. 2 · statut **proposé** · verdict **VALIDE**

- **Unité :** Route106 - CF_D023
- **Déclencheur :** Un pêcheur ruiné vend un Kokiyas capture plutot que de le livrer à la brigade.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D02 bits 12-13 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) L'acheter 300 P** - deltas : rP+2, rL-2, -300 P · immédiat : Il compte les pièces deux fois. · différé : ch. 3 : rumeur 'un étranger achete' au port (RK +1 au ch. 3 si achete). · [gain : +Équipe, rP / perte : Argent, rL]
  - **b) Refuser** - deltas : rL+1, RK+1 · immédiat : Il hausse les epaules : 'Les Rocket paieront.' · différé : le Kokiyas finit au marché noir (ch. 9). · [gain : rL / perte : RK]
- **Lecteurs (contenu affecté) :** rumeur ch. 3; RK
- **Délai principal :** immédiat
- **Fins :** indirect.
- **Test :** a : Pokémon reçu, -300 P ; b : RK +1.

### D024 - Emmener Brice à la Grotte Granite
`D` · `S` · présence · Ch. 2 · statut **proposé** · verdict **VALIDE**

- **Unité :** DewfordTown -> GraniteCave_1F - CF_D024
- **Déclencheur :** Brice veut voir 'le fils de Devon' au travail.
- **Prérequis :** D018 != c
- **Stockage :** VAR_CF_D02 bits 14-15 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) L'emmener** - deltas : BR+2, PR-2, BV.COMP+1 · immédiat : Brice pose cent questions ; Pierre Rochard abrege. · différé : BV COMPRENDRE +1. · [gain : BR / perte : PR]
  - **b) Y aller seul** - deltas : PR+2, BR-1 · immédiat : Pierre Rochard parle librement. · différé : ch. 8 : il cite cette visite ('vous etiez seul, c'etait mieux'). · [gain : PR / perte : BR]
- **Lecteurs (contenu affecté) :** BV; PR
- **Délai principal :** différé long
- **Fins :** BV.
- **Test :** Prérequis D018 != c. a : BVCOUNT.C+1 ; b : PR+2.

## Ch. 3

### D025 - Débarquement de la Mission : de quel côté du quai
`D` · `S` · présence · Ch. 3 · statut **proposé** · verdict **FAIBLE (liste, non comptée)** (effet limite a des deltas faibles et une réplique ; aucun seuil pivot identifie (revue stricte))

- **Unité :** SlateportCity (port) - CF_D025
- **Déclencheur :** La foule crie 'Kanto dehors' ; la Mission Indigo débarque.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D03 bits 0-1 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Rester parmi les gens du port** - deltas : rP+3, PE-2 · immédiat : Une vendeuse offre un poisson grille à Red. · différé : ch. 3 : pétition (D032) presentee d'office. · [gain : rP / perte : PE]
  - **b) Rejoindre Peter sur le quai** - deltas : PE+3, rI+2, rP-3 · immédiat : Peter : 'Le champion. Enfin un visage.' · différé : ch. 5 : Peter attend Red au Site Météore. · [gain : PE, rI / perte : rP]
- **Lecteurs (contenu affecté) :** PE; rI; rP
- **Délai principal :** différé court
- **Fins :** indirect.
- **Test :** a : rP=53 ; b : PE=53, rI=52.

### D026 - Kiosque Passerelle : première commande (loi H1)
`E` · `M` · arbitrage · Ch. 3 · statut **proposé** · verdict **VALIDE**

- **Unité :** SlateportCity (marche, Kiosque) - CF_D026
- **Déclencheur :** Le Kiosque livre un objet rare instantanement. Une fillette joue avec sa Goélise à côté.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D03 bits 2-3 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Commander (Restes, 3 000 P)** - deltas : PA+2, rC+2, rP-3, -3000 P · immédiat : Un anneau livre l'objet ; un second prend la Goélise de la fillette. · différé : H1 apprise par l'echec ; la fillette reste sur le banc jusqu'au ch. 12 (F2 : la Goélise revient). · [gain : +objet rare, rC / perte : Argent, PA, rP]
  - **b) Ne pas commander** - deltas : rC-1, rP+1 · immédiat : Un client commande à la place ; l'anneau prend un sac. · différé : le Kiosque reste ouvert (commandes plafonnees, GAME_SYSTEMS 6). · [gain : rP / perte : -objet rare, rC]
- **Lecteurs (contenu affecté) :** PA (P2, F3); rC; épilogue F2 (fillette)
- **Délai principal :** immédiat · signal de mémoire : Carnet : 'Elle a donne. Moi, j'ai paye.'
- **Fins :** F3 exige PA<50.
- **Test :** a : objet, PA=22, rC=52, PNJ fillette sans Goélise ; b : rC=49. Observer l'hesitation à la 2e commande (prototype bible 11.4).

### D027 - Blue 1 à la Tente de Scott (refusable)
`E` · `M` · combat · Ch. 3 · statut **proposé** · verdict **VALIDE**

- **Unité :** SlateportCity_BattleTentLobby - CF_D027 (FLAG_CF_REFUS_BLUE1)
- **Déclencheur :** Blue : 'Le grand Red sans son équipe. Ça, je veux le voir.'
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D03 bits 4-5 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Accepter et gagner** - deltas : BL+2, rC+1, PE-1, N+1 · immédiat : Blue serre les dents ; Scott sort son carnet. · différé : Scott propose un contrat (D034) ; Blue T2 garde 1 import. · [gain : BL, rC / perte : PE]
  - **b) Accepter et perdre** - deltas : BL+4, rI-2, -500 P, N-1 · immédiat : Blue rit, puis se tait. · différé : Blue T2 +1 import (équipe plus forte) ; Mission : 'Le champion a perdu.' · [gain : BL / perte : Argent, rI]
  - **c) Refuser** - deltas : BL-4, PE+2 · immédiat : Blue : 'Tu fuis ?' ; Peter, plus loin, approuve. · différé : ch. 9 : toit plus froid ; refus definitif. · [gain : PE / perte : BL]
- **Lecteurs (contenu affecté) :** Blue T2/T3 (brief B); STANCE_BLUE (BL>=60); veillée (BL>=55)
- **Délai principal :** immédiat · signal de mémoire : Blue : 'On n'a pas fini, toi et moi.'
- **Fins :** variante Blue (départ pour Jadielle).
- **Test :** Jalon plafond 22 pose à la sortie de la Tente dans les 3 issues (test par issue). Slot D027=1/2/3.

### D028 - L'homme au Persian au marché
`D` · `S` · geste · Ch. 3 · statut **proposé** · verdict **VALIDE**

- **Unité :** SlateportCity (marche) - CF_D028
- **Déclencheur :** Un homme en costume observe le Kiosque ; un Persian à ses pieds.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D03 bits 6-7 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Rester a ecouter** - deltas : GI+3, rI-1 · immédiat : 'Tout s'achete. Sauf ce qui compte.' Il part. · différé : ch. 6 : il propose le duel incognito (D056). · [gain : GI / perte : rI]
  - **b) Le designer à Koga** - deltas : rI+3, GI-5 · immédiat : Koga le suit ; l'homme disparaît. · différé : ch. 6 : pas de duel incognito si GI<50 ; témoignage au Sommet plus difficile. · [gain : rI / perte : GI]
- **Lecteurs (contenu affecté) :** D056 (GI>=50); D114 témoignage (GI>=55)
- **Délai principal :** différé court
- **Fins :** R4 source 2.
- **Test :** a : GI=53 ; b : GI=45, rI=53 ; ch. 6 : PNJ Giovanni present seulement si GI>=50.

### D029 - Composant Devon pour le Capitaine Marin
`E` · `S` · arbitrage · Ch. 3 · statut **proposé** · verdict **VALIDE**

- **Unité :** SlateportCity_SternsShipyard_1F - CF_D029 (FLAG_DELIVERED_DEVON_GOODS pose dans les 2 cas)
- **Déclencheur :** Le colis scellé de Devon ; Ciléo voudrait l'ouvrir.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D03 bits 8-9 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Livrer scellé** - deltas : rC+2 · immédiat : Marin remercie Devon. · différé : rien. · [gain : rC / perte : -pièce manquée]
  - **b) Laisser Ciléo l'examiner avant** - deltas : rC-3, rI+1, DOS_SCHEMA_CABLE · immédiat : Schema du relais d'Algatia et du câble. · différé : Sommet M1 (pièce CHARTE) ; ch. 11 : Marin sait que Red sait. · [gain : Dossier, rI / perte : rC]
- **Lecteurs (contenu affecté) :** Sommet M1; ch. 11 Marin (D106); FLAG_DELIVERED_DEVON_GOODS (6 lecteurs vanilla)
- **Délai principal :** différé long
- **Fins :** indirect.
- **Test :** Les deux : FLAG_DELIVERED_DEVON_GOODS pose (grep : Route109, Dewford, Briney, Musee 1F/2F, chantier, pokenav). b : DOS_SCHEMA_CABLE, rC=47.

### D030 - Chen demande les données de Red
`E` · `S` · don · Ch. 3 · statut **proposé** · verdict **VALIDE**

- **Unité :** SlateportCity_OceanicMuseum_1F (Chen et Seko) - CF_D030
- **Déclencheur :** Chen veut les observations de Red avant Seko ; Seko attend dehors.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D03 bits 10-11 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Donner à Chen** - deltas : BR-3, EXP_SHARE · immédiat : Chen : 'Vous ne le regretterez pas.' Il remet le Multi Exp. · différé : ch. 7 : Seko accuse Chen au dîner ; Brice blessé. · [gain : +Multi Exp des le ch. 3 / perte : BR]
  - **b) Donner à Seko** - deltas : BR+3 · immédiat : Seko rougit ; Brice sourit. · différé : ch. 4 : Seko remet le Multi Exp avec Pikachu. · [gain : BR / perte : -Multi Exp au ch. 4 seulement]
- **Lecteurs (contenu affecté) :** QoL (Multi Exp, ch. 3 ou 4); ch. 7 dîner; REL_CHEN_SEKO
- **Délai principal :** immédiat
- **Fins :** épilogue Chen-Seko.
- **Test :** a : FLAG_CF_EXP_SHARE pose au ch. 3 ; b **ou non prise** : pose au ch. 4 (script Seko, indépendant de D041 ; arbitrage v3.1). BR 47/53.

### D031 - Petit voleur n 3 : l'objet du Kiosque
`D` · `S` · geste · Ch. 3 · statut **proposé** · verdict **VALIDE**

- **Unité :** SlateportCity (chantier) - CF_D031
- **Déclencheur :** Le voleur prend l'objet commande (ou une Poke Ball si rien n'a été commande).
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D03 bits 12-13 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Le laisser filer** - deltas : HO+5 · immédiat : Il tourne trois fois sur lui-même. · différé : HO. · [gain : HO / perte : -objet perdu, Objets]
  - **b) Le poursuivre dans le chantier** - deltas : HO-3, DOS_TRACE_ANNEAU · immédiat : Une brulure en anneau sur le quai. · différé : indice R2b ; pièce mineure. · [gain : +objet récupère, Dossier / perte : HO]
  - **c) Le signaler à la Mission** - deltas : HO-5, rI+2 · immédiat : Koga prend des notes. · différé : ch. 8 : le piege de Koga est pret plus tôt (Koga plus sur de lui). · [gain : rI / perte : HO]
- **Lecteurs (contenu affecté) :** HO; ch. 8 D075 (Koga)
- **Délai principal :** différé court
- **Fins :** F2.
- **Test :** a : HO+5, objet retire ; b : pièce ; c : rI+2.

### D032 - La pétition 'ports fermes à Kanto'
`E` · `S` · arbitrage · Ch. 3 · statut **proposé** · verdict **VALIDE**

- **Unité :** SlateportCity (marche) - CF_D032
- **Déclencheur :** Les commercants ruinés par les imports font signer une pétition.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D03 bits 14-15 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Signer** - deltas : rP+4, rI-4, PETITION · immédiat : Les commercants applaudissent ; Ondine voit la signature. · différé : Sommet M3 : COM vote KANTO ; FK reste 'Mission'. · [gain : rP / perte : rI]
  - **b) Refuser** - deltas : rI+2, rP-2 · immédiat : Un commercant crache par terre. · différé : rien d'autre. · [gain : rI / perte : rP]
- **Lecteurs (contenu affecté) :** Sommet M3 (COM); FK
- **Délai principal :** différé long
- **Fins :** FK postgame.
- **Test :** a : PETITION, rP=54, rI=46.

### D033 - Rumeur de marché noir : payer l'informateur
`D` · `S` · don · Ch. 3 · statut **proposé** · verdict **VALIDE** (acces à la lettre de Ferrand (pièce) au ch. 9)

- **Unité :** SlateportCity_Harbor - CF_D033
- **Déclencheur :** Un docker vend un nom d'entrepôt à Nénucrique pour 500 P.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D04 bits 0-1 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Payer 500 P** - deltas : RK+1, -500 P, INFO_ENTREPOT · immédiat : 'Entrepot 3. Le type s'appelle Ferrand.' · différé : ch. 9 : coup de filet direct vers Ferrand (OBJ_LETTRE_FERRAND plus sur). · [gain : +information (entrepôt de Ferrand) / perte : Argent, RK]
  - **b) Partir** - deltas : - · immédiat : Il crache. · différé : ch. 9 : Ferrand trouve seulement si Olga est suivie. · [gain : +argent garde / perte : -information]
- **Lecteurs (contenu affecté) :** ch. 9 D082
- **Délai principal :** différé court
- **Fins :** indirect.
- **Test :** a : -500 P, INFO_ENTREPOT ; ch. 9 réplique d'Olga.

### D034 - Le contrat de Scott
`E` · `S` · arbitrage · Ch. 3 · statut **proposé** · verdict **VALIDE**

- **Unité :** SlateportCity_BattleTentLobby - CF_D034
- **Déclencheur :** Scott offre à Red une prime par victoire au Tournoi des Confluences.
- **Prérequis :** Blue 1 accepte (D027 a ou b)
- **Stockage :** VAR_CF_D04 bits 2-3 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Signer** - deltas : rC+2, BL-3 · immédiat : Blue : 'Tu me voles mon impresario.' · différé : Tournoi : primes x2 (plafonnees par chapitre) ; Blue T3 achete un import de plus. · [gain : rC / perte : BL]
  - **b) Refuser** - deltas : BL+2, rC-1 · immédiat : Scott : 'Je reviendrai.' · différé : Blue garde Scott pour lui. · [gain : BL / perte : rC]
- **Lecteurs (contenu affecté) :** Tournoi (primes); Blue T3; BL
- **Délai principal :** différé court
- **Fins :** variante Blue.
- **Test :** a : primes doublees (vérifier au Tournoi) ; BL 47/52.

### D035 - Maison de la plage (R109) : les arrivants caches
`D` · `S` · aveu · Ch. 3 · statut **proposé** · verdict **VALIDE**

- **Unité :** Route109_SeashoreHouse - CF_D035
- **Déclencheur :** Un vieux couple cache des arrivants ; la brigade fouille la côté.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D04 bits 4-5 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Les designer à la brigade** - deltas : rL+3, rA-3 · immédiat : La brigade embarque les arrivants ; le couple paie une amende. · différé : ch. 4 : brigade plus confiante (barrage R110 ouvert). · [gain : rL / perte : rA]
  - **b) Garder le secret** - deltas : rA+3, rL-2 · immédiat : Le couple offre trois Potions. · différé : ch. 9 : le couple apparait au port de Nénucrique (Aqua). · [gain : +Potions offertes, rA / perte : rL]
- **Lecteurs (contenu affecté) :** rL/rA; barrage R110
- **Délai principal :** immédiat
- **Fins :** indirect.
- **Test :** a : rL=53 ; b : 3 Potions, rA=53.

## Ch. 4

### D036 - Lavandia : le quartier sud coupe
`E` · `M` · présence · Ch. 4 · statut **proposé** · verdict **VALIDE**

- **Unité :** MauvilleCity / NewMauville_Inside - CF_D036
- **Déclencheur :** Major Bob coupe le quartier sud pour protéger la centrale ; une enfant frappe à la vitre.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D04 bits 6-7 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Retablir la ligne (Nouvelle Lavandia)** - deltas : rP+4, rL-2, BOB_QUARTIER · immédiat : Red chasse les Statitik des transformateurs ; la lumière revient. · différé : ch. 7 : Major Bob vote CONTRE l'abattage ; ch. 13 : il tient les civils. · [gain : rP / perte : rL]
  - **b) Rester** - deltas : rL+2, rP-3 · immédiat : L'enfant arrête de frapper. · différé : ch. 7 : Major Bob vote POUR. · [gain : rL / perte : rP]
- **Lecteurs (contenu affecté) :** ch. 7 vote (D069); climax : Major Bob allié civils; rP
- **Délai principal :** immédiat · signal de mémoire : Carnet : 'Elle a arrête de frapper.' (b)
- **Fins :** climax.
- **Test :** a : BOB_QUARTIER, quartier eclaire (setflashlevel off), rP=54 ; b : quartier sombre jusqu'au ch. 7.

### D037 - Mission de zone Z-03 : les vergers de Vergazon
`E` · `M` · arbitrage · Ch. 4 · statut **proposé** · verdict **VALIDE**

- **Unité :** VerdanturfTown / Route117 - CF_D037
- **Déclencheur :** Singes mangeurs de baies ; Erika propose un parfum, le Rempart un abattage.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D04 bits 8-9 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Parfum d'Erika (fleur arrivante)** - deltas : rC+3, rA-2, Z03=MIXTE, ERIKA_CONTRAT · immédiat : Les singes fuient vers la R117 ; Erika signe avec Devon. · différé : Z-03 MIXTE ; Erika reste MARCHE sauf ch. 6. · [gain : Écosystème, rC / perte : rA]
  - **b) Déplacer vers le désert (Brice, Timmy)** - deltas : rP+3, rC-2, Z03=RESTAURE, BV.ACC+1 · immédiat : Trois nuits de convoi. · différé : Z-03 RESTAURE ; arbres a baies de la R117 donnent a nouveau. · [gain : Écosystème, rP / perte : rC]
  - **c) Abattage du Rempart** - deltas : rL+4, rP+2, rI-3, TI-5, Z03=ABATTU · immédiat : Timmy cache son Feuillajou sous son lit. · différé : Z-03 ABATTU ; ch. 7 : l'arrivant de Timmy est sur la liste. · [gain : rL, rP / perte : Écosystème, TI, rI]
- **Lecteurs (contenu affecté) :** E-ECO Z-03 (R117 baies); ch. 7 Vergazon (D064); Erika (D058); diaporama
- **Délai principal :** immédiat · signal de mémoire : Brice colorie Vergazon sur sa carte (vert, orange ou gris).
- **Fins :** variante sociale.
- **Test :** 50 rencontres R117 par issue ; arbres a baies (vides si ENVAHI). VAR_CF_ECO Z03.

### D038 - Timmy et son arrivant condamne
`D` · `S` · don · Ch. 4 · statut **proposé** · verdict **VALIDE**

- **Unité :** VerdanturfTown - CF_D038
- **Déclencheur :** Timmy cache un Feuillajou ; il n'a pas de Poke Ball pour le declarer.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D04 bits 10-11 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Lui donner une Poke Ball** - deltas : TI+5, rL-3 · immédiat : Timmy le capture en tremblant ; il est declare. · différé : ch. 7 : l'arrivant est 'à Timmy' (Flora hésite). · [gain : TI / perte : Objets, rL]
  - **b) Ne rien faire** - deltas : rL+1, TI-1 · immédiat : Timmy le cache encore. · différé : ch. 7 : l'arrivant est saisi d'office sauf intervention. · [gain : rL / perte : TI]
- **Lecteurs (contenu affecté) :** D064 (ch. 7); équipe de Timmy (avec/sans); D123 (ch. 14)
- **Délai principal :** différé court
- **Fins :** variante Timmy.
- **Test :** a : TI=55, une Poke Ball en moins ; b : TI=49.

### D039 - Petit voleur n 4 : le piege du fermier
`D` · `S` · geste · Ch. 4 · statut **proposé** · verdict **VALIDE**

- **Unité :** Route117 - CF_D039
- **Déclencheur :** Le voleur est pris dans un piege a baies ; le fermier arrive avec un baton.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D04 bits 12-13 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Ouvrir le piege** - deltas : HO+5, rP-2 · immédiat : Il fuit, puis revient déposer une baie. · différé : HO>=40 au ch. 7 plus probable. · [gain : HO / perte : rP]
  - **b) Laisser le fermier** - deltas : HO-2, rP+1 · immédiat : Un anneau : le piege disparaît avec lui. · différé : le fermier perd son piege (réplique). · [gain : rP / perte : HO]
- **Lecteurs (contenu affecté) :** HO
- **Délai principal :** différé court
- **Fins :** F2.
- **Test :** a : HO+8 ; b : HO-2.

### D040 - Raid du Tunnel Merazon : l'approche
`E` · `L` · arbitrage · Ch. 4 · statut **proposé** · verdict **VALIDE**

- **Unité :** RusturfTunnel - CF_D040 (jalon plafond 27 à la sortie, toutes issues)
- **Déclencheur :** La Rocket stocke des arrivants dans le tunnel ; trois approches proposees au QG de Vergazon.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D04 bits 14-15 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) De front avec Brice** - deltas : BR+5, RK-8, rL-2, BV.PROT+1, DOS_CARNET_PRIMES, DOS_PREDICTEUR · immédiat : Combat contre Lance (Rocket) ; Brice saisit le prédicteur ; page 'paiement a K.' · différé : R1 ; W10 au ch. 10 (montrer la page à Peter). · [gain : BR, Dossier, RK / perte : rL]
  - **b) Infiltration avec Koga (Mission)** - deltas : rI+8, RK-5, BR-5, DOS_PREDICTEUR, KOGA=COUVERT · immédiat : Koga empoche une page sans un mot. · différé : R1 ; la page 'K.' disparaît : Koga COUVERT par defaut. · [gain : Dossier, RK, rI / perte : BR]
  - **c) Laisser le Rempart mener (Flora)** - deltas : rL+8, RK-3, rA-3, DOS_PREDICTEUR · immédiat : La brigade abat la cargaison ; Norman garde le prédicteur. · différé : R1 (Norman montre le prédicteur) ; FL +2 si D008 c. · [gain : Dossier, RK, rL / perte : -cargaison abattue, rA]
- **Lecteurs (contenu affecté) :** R1; D075 (page); W10 (REL_KOGA_PETER); RK; Sommet
- **Délai principal :** immédiat · signal de mémoire : Brice : 'Ils savaient ou l'anneau s'ouvrirait. Ils savaient.'
- **Fins :** RK -> variante Rocket ; climax relais (RK<70).
- **Test :** Save avant raid. Chaque issue : DOS_PREDICTEUR pose, VAR_CF_CAP>=27 à la sortie ; a : DOS_CARNET_PRIMES ; b : KOGA=COUVERT ; c : rL=58.

### D041 - Retour de Pikachu : le reprendre ou le laisser à Seko
`E` · `S` · arbitrage · Ch. 4 · statut **proposé** · verdict **VALIDE**

- **Unité :** MauvilleCity (Seko au Centre) - CF_D041
- **Déclencheur :** Seko ramene Pikachu gueri (niveau plafond-2, E-LVL).
- **Prérequis :** D001 = a
- **Stockage :** VAR_CF_D05 bits 0-1 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Le reprendre** - deltas : BR-1, PIKA_EQUIPE · immédiat : Pikachu saute sur l'epaule de Red. · différé : Pikachu disponible (équipe). · [gain : +Équipe (Pikachu) / perte : BR]
  - **b) Le laisser aider le recensement** - deltas : BR+4, BV.COMP+1 · immédiat : Pikachu part avec Brice ; Brice : 'Il compte mieux que moi.' · différé : ch. 12 : Pikachu dans l'équipe de Brice ; F4/F5 : épilogue commun. · [gain : BR / perte : -Équipe]
- **Lecteurs (contenu affecté) :** équipe Brice (brief B); BV
- **Délai principal :** immédiat
- **Fins :** épilogue Brice.
- **Test :** Prérequis D001=a. a : Pikachu dans l'équipe ; b : BR=54.

### D042 - Badge 3 : 'le courant d'abord' de Voltère
`E` · `S` · arbitrage · Ch. 4 · statut **proposé** · verdict **FAIBLE (liste, non comptée)** (PA+1 et deltas rC/rA marginaux ; aucun lecteur propre (revue stricte))

- **Unité :** MauvilleCity_Gym - CF_D042
- **Déclencheur :** Voltère veut prioriser la ville sur la Nouvelle Lavandia (arrivants Electrik chasses).
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D05 bits 2-3 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Signer** - deltas : rC+3, rA-3 · immédiat : Voltère : 'La lumière, c'est la vie !' · différé : ch. 7 : courant stable (PA +1 : consortium soutenu). · [gain : rC / perte : rA]
  - **b) Refuser** - deltas : rA+2, rC-2 · immédiat : Voltère : 'Tu verras, à la première coupure.' · différé : rien. · [gain : rA / perte : rC]
- **Lecteurs (contenu affecté) :** rC/rA; PA
- **Délai principal :** différé court
- **Fins :** indirect.
- **Test :** a : rC=53, PA+1 au ch. 7 ; b : rA=52.

### D043 - L'exercice de Major Bob (refusable)
`D` · `S` · combat · Ch. 4 · statut **proposé** · verdict **VALIDE**

- **Unité :** MauvilleCity (perimetre) - CF_D043 (FLAG_CF_REFUS_BOB)
- **Déclencheur :** Major Bob teste les 'soldats' de passage.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D05 bits 4-5 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Accepter et gagner** - deltas : rI+3, rP-1, BOB_RESPECT · immédiat : 'Pas mal, pour un civil.' · différé : ch. 13 : Major Bob competent aux civils même sans BOB_QUARTIER. · [gain : +objet (Aimant), rI / perte : rP]
  - **b) Accepter et perdre** - deltas : rI+1, BR-1, -300 P · immédiat : 'Recommence quand tu veux.' · différé : rien. · [gain : rI / perte : Argent, BR]
  - **c) Refuser** - deltas : rI-2, rP+2 · immédiat : Un enfant du quartier : 'Il joue pas au soldat.' · différé : refus definitif. · [gain : rP / perte : rI]
- **Lecteurs (contenu affecté) :** climax (allié Major Bob)
- **Délai principal :** différé long
- **Fins :** climax civils.
- **Test :** a : flag BOB_RESPECT ; c : refus pose.

### D044 - L'echantillon d'Erika
`E` · `S` · arbitrage · Ch. 4 · statut **proposé** · verdict **VALIDE**

- **Unité :** VerdanturfTown - CF_D044
- **Déclencheur :** Erika demande à Red de porter à Devon un echantillon de la fleur arrivante.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D05 bits 6-7 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Porter** - deltas : rC+2, rA-1 · immédiat : Devon signe ; Erika offre une CT. · différé : ch. 6 : Erika achete les sources (D058 plus dur). · [gain : rC / perte : rA]
  - **b) Refuser** - deltas : rA+1, rC-2 · immédiat : Erika : 'Je trouverai un autre porteur.' · différé : ch. 6 : Erika hésite (STANCE_ERIKA INT atteignable). · [gain : rA / perte : rC]
- **Lecteurs (contenu affecté) :** D058; STANCE_ERIKA
- **Délai principal :** différé court
- **Fins :** indirect.
- **Test :** a : CT recue, rC=52 ; b : rC=48.

### D045 - R117 : les œufs abandonnes
`D` · `S` · don · Ch. 4 · statut **proposé** · verdict **VALIDE**

- **Unité :** Route117_PokemonDayCare - CF_D045
- **Déclencheur :** Un éleveur abandonne des œufs d'arrivants devenus trop chers.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D05 bits 8-9 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Prendre un œuf** - deltas : rL-2, rA+1 · immédiat : L'éleveur soupire de soulagement. · différé : œuf éclot au ch. 5. · [gain : +œuf (Unys), rA / perte : rL]
  - **b) Refuser** - deltas : rL+1, RK+2 · immédiat : Un homme en noir prend la caisse. · différé : ch. 6 : Ariane aligne un de ces arrivants. · [gain : rL / perte : RK]
- **Lecteurs (contenu affecté) :** RK; Ariane T2 (brief B)
- **Délai principal :** immédiat
- **Fins :** indirect.
- **Test :** a : œuf ; b : RK+2.
