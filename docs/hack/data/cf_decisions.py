# -*- coding: utf-8 -*-
"""Pokemon Confluence - registre des decisions (brief C, v3).
Source de donnees unique du DECISION_LEDGER (les fichiers .md sont generes par cf_model.py).
Conventions : deltas sur les systemes (bible 11.1) ; PA et RK : + = perte (mauvais pour la region).
Chaque option : gain ET perte dans deux systemes differents (verifie par cf_model.py --check).
Statut de toutes les decisions : propose (rien n'est implemente ni teste).
"""

DECISIONS = []

def O(code, label, d=None, fx=None, imm='', later='', req=None, reqtxt=''):
    return dict(code=code, label=label, d=d or {}, fx=fx or {}, imm=imm, later=later, req=req, reqtxt=reqtxt)

def D(id, ch, t, c, kind, title, unit, trig, opts, reads, fins, test, delay='I',
      when=None, pre='aucun', verdict=('V', ''), mem='', extra=''):
    DECISIONS.append(dict(id=id, ch=ch, t=t, c=c, kind=kind, title=title, unit=unit, trig=trig,
                          opts=opts, reads=reads, fins=fins, test=test, delay=delay, when=when,
                          pre=pre, verdict=verdict, mem=mem, extra=extra))

def ch(s, k):   return s['choice'].get(k, 0)
def has(s, f):  return f in s['flags']
def val(s, k):  return s['val'].get(k)

# ---------------------------------------------------------------- CH. 0 PROLOGUE
D('D001', 0, 'E', 'L', 'presence', "Qui Red rattrape dans l'anneau",
  'Route104 (plage, nuit) - CF_D001',
  "3e combat a pleine force ; un anneau s'ouvre sous Red et aspire l'equipe (E-REMOVE). Deux silhouettes a portee : Pikachu, le sac de Cileo.",
  [O('a', 'Pikachu (il saute vers Red)', {'rI': -3}, {'set': ['PIKA_BLESSE'], 'gain': 'Equipe (Pikachu au ch. 4)'},
     "Pikachu blesse reste avec Red ; Cileo perd son disque du noeud.", "ch. 4 : Seko rend Pikachu (D041) ; ch. 3 : Cileo n'a pas de preuve (Mission plus froide)."),
   O('b', 'Le sac de Cileo (disque du noeud Kanto)', {'rI': 5, 'rC': -3}, {'set': ['DOS_JOURNAL_NOEUD'], 'loss': 'Equipe (Pikachu part avec les autres)'},
     "Pikachu disparait avec l'equipe ; Cileo serre son disque.", "ch. 3 : Cileo prouve l'horodatage du noeud a Peter (rI) ; Pikachu ne revient qu'au postgame avec l'equipe.")],
  ['D041 (ch. 4)', 'ch. 3 entrepot Cileo', 'Sommet M3 (piece)', 'postgame retour equipe'],
  'aucune directe ; DOS_JOURNAL_NOEUD compte au Dossier (fin cachee).',
  "Etat : nouvelle partie. Sequence : 3 combats R104, choix a puis b (deux saves). Attendu a : flag PIKA_BLESSE, D00 bits0-1=1, rI=47 ; b : DOS_JOURNAL_NOEUD, slot=2, rI=55, rC=47 ; ch. 3 Cileo : ligne 'preuve' seulement en b.",
  delay='C', mem='Carnet : "Pikachu a saute. Pas moi." (a) / "Le disque. Pas lui." (b)')

D('D002', 0, 'E', 'M', 'aveu', "Accreditation par telephone : nom ou anonymat",
  'PetalburgCity_Gym (QG du Rempart, telephone de Seko) - CF_D002',
  "Norman exige un nom pour l'accreditation de crise d'un dresseur etranger.",
  [O('a', 'Donner son nom (Red)', {'rL': 3, 'RK': 3}, {'N': 2},
     "Norman : 'Le champion de Kanto. Bien.' Badge provisoire.", "Defis Indigo offerts des le ch. 3 ; ch. 10 : Lambda tend un piege nominatif (vague de sbires en plus)."),
   O('b', "Rester anonyme (Brice invente 'le Passeur')", {'rL': -3, 'BR': 2}, {'N': 0},
     "Norman : controle renforce ; Brice rit de son pseudonyme.", "Defis Indigo seulement apres le ch. 10 ; barrage de brigade a Clementi demande Brice comme garant.")],
  ['ch. 1 QG Clementi', 'ch. 3 Defis Indigo', 'ch. 10 piege de Lambda', 'Sommet (traduction : N)', 'epilogue presse'],
  'variantes de presse de l epilogue (N).',
  "Etat : ch. 0 apres labo. a : VAR_CF_WORLD N=2, rL=53, RK=23 ; b : N=0, rL=47, BR=52. Ch. 3 : PNJ Defi present seulement si N>=1.",
  delay='C', mem="Brice : 'Je note : Passeur. Ca sonne bien.' (b)")

D('D003', 0, 'D', 'S', 'discret', "Ronde nocturne de Brice encerclee (R101)",
  'Route101 (nuit) - CF_D003',
  "Brice compte des arrivants, encercle ; Red a le starter de Seko depuis 2 minutes.",
  [O('a', 'Intervenir tout de suite', {'BR': 3, 'HO': -1}, {'bv': 'P'},
     "Combat immediat ; Brice : 'Tu es tombe du ciel ?'", "BV PROTEGER +1."),
   O('b', 'Rester (observer le motif)', {'BR': -3}, {'bv': 'C', 'gain': 'Information (les arrivants fuient vers l anneau)'},
     "Les arrivants fuient tous vers le meme point ; Brice est griffe.", "BV COMPRENDRE +1 ; Carnet 'Ils fuient vers la lumiere'.")],
  ['calcul BV (ch. 7, ch. 12)', 'BR seuils'], 'BV -> vote de Brice et voix de l epilogue.',
  "Etat : ch. 0 R101. a : BVCOUNT.P=1, BR=53 ; b : BVCOUNT.C=1, BR=47 ; ligne Carnet presente en b.",
  delay='C')

D('D004', 0, 'E', 'S', 'arbitrage', "Starter de Seko (Arcko, Poussifeu, Gobou)",
  'LittlerootTown_ProfessorBirchsLab - CF_D004',
  "Seko presente trois natifs de Hoenn.",
  [O('a', 'Arcko', {}, {'gain': 'Equipe'}), O('b', 'Poussifeu', {}, {'gain': 'Equipe'}), O('c', 'Gobou', {}, {'gain': 'Equipe'})],
  ['equipe de Brice (starter fort)'], 'aucune',
  "Etat : labo. Attendu : starter recu ; equipe de Brice R103 = starter fort contre.",
  verdict=('F', 'choix de combat vanilla, pas une decision narrative (revue v2 D006) : liste, non compte'))

D('D005', 0, 'E', 'S', 'don', "Lettre de Chen : la montrer a Seko ou la garder",
  'LittlerootTown_ProfessorBirchsLab - CF_D005',
  "La lettre de Chen demande a Red ses observations 'avant tout le monde'.",
  [O('a', 'Montrer la lettre a Seko', {'BR': 2}, {'set': ['CHEN_LETTRE_MONTREE'], 'loss': 'Chen (rivalite aggravee)'},
     "Seko se raidit ; il ouvre son registre a Red.", "ch. 3 : Chen froid ('Vous l'avez montree.') ; REL_CHEN_SEKO plus dur (exige la publication partagee)."),
   O('b', 'Garder la lettre', {'BR': -2}, {'gain': 'Chen (confiance)'},
     "Brice voit Red ranger une lettre ; il ne demande rien.", "ch. 3 : Chen offre le Multi Exp en echange de donnees (D030).")],
  ['ch. 3 Chen (D030)', 'ch. 7 diner', 'epilogue Chen-Seko'], 'fin cachee (via REL_CHEN_SEKO).',
  "a : flag CHEN_LETTRE_MONTREE, BR=52 ; b : BR=48 ; ch. 3 : replique de Chen differente.",
  delay='C')

D('D006', 0, 'D', 'S', 'presence', "Rester chez M. Marco ou suivre Cileo",
  'Route104_MrBrineysHouse - CF_D006',
  "Apres la plage, M. Marco cherche Piko ; Cileo part seul vers Clementi.",
  [O('a', 'Rester avec M. Marco', {'rL': -2}, {'set': ['DOS_CLOCHETTE_PIKO', 'MARCO_ALLIE']},
     "M. Marco : Piko a disparu le jour d'un anneau (indice R3). Cileo est retenu une nuit par la brigade.", "ch. 2 : passage gratuit et confidences ; Sommet : clochette = piece (loi H1)."),
   O('b', 'Suivre Cileo', {'rI': 2}, {'loss': 'Information (indice R3 manque)'},
     "Cileo passe le barrage grace a Red.", "ch. 3 : Cileo plus ouvert ; Piko n'est evoque qu'au ch. 6.")],
  ['ch. 2 bateau', 'ch. 9 R3', 'Sommet M2 (piece)', 'F2 epilogue Piko'], 'F2 : Piko rendu (scene plus forte si a).',
  "a : DOS_CLOCHETTE_PIKO pose, rL=48 ; b : rI=52 ; ch. 2 : dialogue de Marco differe.",
  delay='C')

D('D007', 0, 'D', 'S', 'arbitrage', "R103 : l'arrivant blesse",
  'Route103 - CF_D007',
  "Apres le duel avec Brice, un Zigzaton de Galar blesse ; la brigade arrive.",
  [O('a', 'Le capturer (Poke Ball de Seko)', {'rL': -2}, {'bv': 'A', 'gain': 'Equipe (arrivant)'},
     "Il entre dans l'equipe ; Brice : 'On le declare ou pas ?'", "ch. 1 : Flora remarque l'arrivant (replique) ; BV ACCUEILLIR +1."),
   O('b', 'Le laisser a la brigade', {'rL': 2}, {'bv': 'P', 'loss': 'Equipe'},
     "La brigade l'emmene ; Brice note le numero.", "BV PROTEGER +1 ; ch. 1 Flora : 'Merci pour le signalement.'")],
  ['ch. 1 Flora', 'calcul BV'], 'BV.',
  "a : Pokemon recu, BVCOUNT.A=1, rL=48 ; b : BVCOUNT.P=1, rL=52.",
  delay='I')

# ---------------------------------------------------------------- CH. 1
D('D008', 1, 'E', 'M', 'combat', "Bois Clementi : Flora et la brigade (combat refusable)",
  'PetalburgWoods - CF_D008 (trainerbattle_single_declinable, FLAG_CF_REFUS_FLORA1)',
  "Flora abat des arrivants ; elle defie Red qui s'interpose.",
  [O('a', 'Accepter et gagner', {'FL': -3, 'rL': -3}, {'set': ['BOIS_SAUVES'], 'gain': 'arrivants sauves'},
     "La brigade recule ; trois arrivants s'enfuient vers le Bois.", "ch. 7 : Flora 'Tu m'as humiliee au Bois' ; Z-02 +arrivants (pas d'etat)."),
   O('b', 'Accepter et perdre', {'FL': 2, 'rL': 1}, {'money': -300, 'loss': 'arrivants abattus'},
     "Flora : 'Au moins, tu t'es battu.'", "ch. 7 : respect de Flora (+2 cumule)."),
   O('c', 'Refuser', {'FL': 3, 'BR': -2}, {'loss': 'arrivants abattus'},
     "Brice : 'On les laisse faire ?' ; Flora salue.", "refus definitif (FLAG_CF_REFUS_FLORA1) ; ch. 7 : Flora te parle d'egal a egal.")],
  ['FL seuils (ch. 7 Vergazon, ch. 13 bascule)', 'rL (Sommet NOR)'], 'FL -> Flora desobeit (civils) -> casualties variante.',
  "a/b/c avec FLAG_CF_NO_WHITEOUT pose avant le combat. Attendu : slot D008 = 1/2/3 ; c : refus flag pose, le PNJ ne repere plus.",
  delay='I', mem="Brice : 'Flora s'en souviendra. Moi aussi.'")

D('D009', 1, 'D', 'S', 'presence', "L'affiche Passerelle (Red de dos)",
  'RustboroCity - CF_D009',
  "Une affiche : 'Il a sauve Sylphe. Sylphe relie le monde.' Brice reconnait la silhouette.",
  [O('a', 'Rester devant', {'BR': 2, 'RK': 2}, {'set': ['DOS_AFFICHE_SYLPHE'], 'N': '+1'},
     "Brice se tait (une fois) ; un passant prend une photo.", "Sommet M3 : piece 'la part de Red' ; Rocket sait que Red est la."),
   O('b', 'Partir', {'BR': -1}, {'loss': 'piece manquee', 'gain': 'discretion (N inchange)'},
     "Brice : 'C'etait toi ?' Pas de reponse.", "piece recuperable seulement au ch. 12 aupres du President (moins forte : 1 voix).")],
  ['Sommet M3 (montrer)', 'ch. 12 President', 'N'], 'fin cachee (piece).',
  "a : DOS_AFFICHE_SYLPHE pose, N+1, RK=22 ; b : BR=49, aucune piece.",
  delay='L')

D('D010', 1, 'E', 'M', 'arbitrage', "Mission de zone Z-02 : les mines de Devon",
  'RustboroCity / RusturfTunnel ouest (galeries) - CF_D010',
  "Charbi et Strassie rongent les galeries ; mineurs mis a pied. Trois approches.",
  [O('a', "Deplacer avec Pierre (Brock)", {'rI': 3, 'rP': -3}, {'eco': ('Z02', 2), 'set': ['BROCK_PROTEGES']},
     "Galeries fermees une semaine ; les arrivants partent chez Pierre.", "Z-02 RESTAURE (Skitty revient) ; Pierre aligne ses proteges ; ch. 7 : ils risquent l'abattage."),
   O('b', 'Donner les releves a Roxanne', {'rC': 3, 'rP': 2, 'rA': -2}, {'eco': ('Z02', 1)},
     "Devon rouvre avec un protocole ; Roxanne cite Red.", "Z-02 MIXTE ; ch. 7 : Roxanne s'appuie sur ces releves au vote."),
   O('c', "Laisser les mineurs abattre", {'rL': 4, 'rP': 3, 'rI': -3, 'TI': -2}, {'eco': ('Z02', 3)},
     "Les galeries se vident ; un mineur pleure son Charbi apprivoise.", "Z-02 ABATTU (densite x0,5) ; Pierre amer (vote ch. 12 retrait).")],
  ['E-ECO tables Z-02', 'boutique Merouville (Corde Sortie absente si ENVAHI)', 'Pierre (Brock) equipe et vote ch. 12', 'Sommet COM', 'diaporama'], 'variante sociale (moyenne des zones).',
  "Save ch. 1 avant mission ; 50 rencontres R116 par issue ; compter Skitty (ENVAHI ~0, RESTAURE ~10). VAR_CF_ECO bits Z02 = 2/1/3. Non faite au badge 1 : MIXTE (1).",
  delay='I', mem="Brice note l'etat de la galerie dans son recensement.")

D('D011', 1, 'E', 'S', 'arbitrage', "Presentation de Passerelle : la photo publique",
  'RustboroCity_DevonCorp_3F - CF_D011',
  "Le President de Sylphe veut une photo de Red a cote du Kiosque.",
  [O('a', 'Poser (rester)', {'rC': 5, 'rP': -3}, {'N': '+1'},
     "Flash ; le President serre la main de Red.", "ch. 3 : Kiosque -10 % ; ch. 12 : 'Vous avez pose pour nous.'"),
   O('b', 'Partir', {'rC': -3, 'rP': 2}, {},
     "Le President rit jaune.", "ch. 3 : commercants de Poivressel plus chaleureux.")],
  ['ch. 3 Kiosque (prix)', 'Sommet M1/M3 (NOR rL>=rC, COM rP>=rC+5)', 'ch. 12 President'], 'F3 (rC>=50).',
  "a : rC=55, rP=47, N+1, prix Kiosque reduit ; b : rC=47, rP=52.",
  delay='C')

D('D012', 1, 'D', 'S', 'discret', "Petit voleur n 1 : le carnet de Brice",
  'RustboroCity (Devon, sortie) - CF_D012',
  "Un petit anneau prend le carnet de Brice ; une silhouette violette.",
  [O('a', 'Lui lancer une baie (donner)', {'HO': 5, 'BR': -2}, {'item': -1},
     "Il attrape la baie et disparait avec le carnet.", "ch. 7 : il rend le carnet si HO>=40 (D066)."),
   O('b', 'Le poursuivre', {'HO': -3, 'BR': 2}, {'bv': 'C'},
     "Red recupere 4 pages ; le voleur fuit vers l'est.", "indice R2b (fuite vers l'est) ; BV COMPRENDRE +1."),
   O('c', 'Ignorer', {'HO': 1, 'BR': -1}, {},
     "Brice : 'Tu ne fais rien ?!'", "ch. 7 : carnet rendu seulement si HO>=40.")],
  ['HO (rencontres suivantes, ch. 8 revelation, climax)', 'D066'], 'F2 (HO).',
  "a : HO=25 ; b : HO=17 ; c : HO=21. Saillance de Hoopa au ch. 2 selon bande de HO.",
  delay='C')

D('D013', 1, 'D', 'S', 'discret', "Devon 2F : l'ingenieur 'Ferrand'",
  'RustboroCity_DevonCorp_2F - CF_D013',
  "Un ingenieur de Passerelle pose trop de questions sur le Rubis et le Saphir.",
  [O('a', 'Rester (le laisser parler)', {'RK': 3}, {'set': ['LAMBDA_REMARQUE'], 'gain': 'information (filature ch. 7)'},
     "Il note quelque chose ; Brice : 'Il parle comme un vendeur.'", "ch. 7 : filature de Lambda proposee d'office (D063 a) ; Lambda vend les mouvements de Red."),
   O('b', 'Partir', {'BR': -1}, {'loss': 'indice manque', 'gain': 'RK inchange'},
     "Rien.", "ch. 7 : la filature exige d'avoir vu Lambda a Lavandia (ch. 4).")],
  ['D063 (ch. 7)', 'ch. 10 faux Giovanni (D095)'], 'RK.',
  "a : LAMBDA_REMARQUE, RK=23 ; ch. 7 : option filature visible. b : BR=49.",
  delay='C')

D('D014', 1, 'E', 'M', 'arbitrage', "R116 : contrebandiers Rocket avant l'anneau",
  'Route116 - CF_D014',
  "Lance (Rocket) et deux sbires attendent pres des rochers ; un anneau va s'ouvrir.",
  [O('a', 'Les affronter', {'RK': -3, 'HO': 0, 'rL': 1}, {'money': -200, 'loss': "l'anneau prend un objet du sac (liste)"},
     "Combat ; l'anneau s'ouvre quand meme et prend un objet non-cle.", "ch. 4 : Lance (Rocket) reconnait Red (replique)."),
   O('b', 'Observer cache (rester)', {'RK': 3}, {'set': ['DOS_HORAIRE_R116']},
     "Ils consultent une montre avant l'anneau (indice R1-1).", "ch. 4 raid : Red sait ou chercher le carnet (option de raid supplementaire)."),
   O('c', 'Prevenir la brigade', {'rL': 3, 'rA': -2, 'TI': -1}, {},
     "Flora arrete un sbire ; les arrivants livres sont abattus.", "ch. 4 : le Rempart se presente au raid (option c du raid renforcee).")],
  ['ch. 4 raid D040', 'R1 indices', 'RK'], 'RK -> variante Rocket.',
  "a : RK=17, objet retire ; b : DOS_HORAIRE_R116 pose, RK=23 ; c : rL=53.",
  delay='I', mem="Carnet : 'Ils attendaient. Avant.'")

D('D015', 1, 'D', 'S', 'don', "Le sbire ruine (ancien mineur)",
  'Route116 (apres D014) - CF_D015',
  "Un sbire blesse avoue : mis a pied des mines, recrute pour 200 P par nuit.",
  [O('a', "Lui donner 500 P pour rentrer", {'RK': -2, 'rP': 2}, {'money': -500},
     "Il jette son uniforme.", "ch. 7 : on le revoit mineur a Merouville (salue Red)."),
   O('b', 'Partir', {'RK': 2}, {'gain': 'argent garde'},
     "Il remet sa casquette.", "ch. 4 : il est au raid du Tunnel (un sbire de plus).")],
  ['ch. 4 raid (effectif)', 'ch. 7 Merouville PNJ', 'RK'], 'RK.',
  "a : argent -500, RK baisse de 2, PNJ ch. 7 present ; b : sbire supplementaire au raid.",
  delay='C')

D('D016', 1, 'E', 'S', 'arbitrage', "Badge 1 : Roxanne demande les donnees de Red",
  'RustboroCity_Gym - CF_D016',
  "Apres le combat, Roxanne veut transmettre les observations de Red au Rempart.",
  [O('a', 'Donner', {'rL': 3, 'BR': -2}, {},
     "Roxanne : 'Des donnees, pas des cris.'", "ch. 7 : Roxanne vote POUR l'abattage avec 'ses' chiffres sauf piece montree."),
   O('b', 'Refuser', {'rL': -2, 'BR': 2}, {},
     "Brice souffle : 'Nos chiffres restent a nous.'", "ch. 7 : Roxanne s'abstient au vote.")],
  ['ch. 7 vote d abattage (D069)', 'BR'], 'indirect (VOTE_ABATTAGE -> zones).',
  "a : rL=53, BR=48, au ch. 7 Roxanne compte pour 'pour' ; b : abstention.",
  delay='C')

D('D017', 1, 'D', 'S', 'don', "QG de Clementi : l'insigne de brigade",
  'PetalburgCity_Gym (QG) - CF_D017',
  "Norman propose un insigne qui ouvre les barrages de brigade.",
  [O('a', "Accepter l'insigne", {'rL': 3, 'rA': -3}, {'gain': 'acces (barrages sans garant)', 'set': ['INSIGNE']},
     "Les barrages s'ouvrent ; Bastien et Aqua voient l'insigne.", "ch. 6 : Aqua refuse la parole a Red tant qu'il le porte (D054 b plus dur)."),
   O('b', 'Refuser', {'rL': -2, 'rA': 1}, {'loss': 'barrages : Brice garant'},
     "Norman : 'A votre guise.'", "ch. 4 et 7 : chaque barrage demande Brice (BR>=40) ou une piece.")],
  ['barrages ch. 4, ch. 7', 'D054 (option b)', 'rA'], 'indirect.',
  "a : objet cle insigne, barrage R110 s'ouvre ; b : barrage exige Brice present.",
  delay='C')

# ---------------------------------------------------------------- CH. 2
D('D018', 2, 'E', 'M', 'arbitrage', "Mission de zone Z-01 : les pecheries de Myokara",
  'DewfordTown / Route106 - CF_D018',
  "Krabby et Qwilfish crevent les filets ; Aldo veut chasser, Bastien deplacer.",
  [O('a', 'Avec Aldo et les pecheurs : chasser', {'rP': 4, 'rA': -3}, {'eco': ('Z01', 3)},
     "Battue sur les quais ; Bastien tourne le dos.", "Z-01 ABATTU ; ch. 9 : Aldo s'engage aux cotes des pecheurs."),
   O('b', 'Avec Bastien : deplacer vers la grotte marine', {'rA': 3, 'rP': -3}, {'eco': ('Z01', 1)},
     "Les bancs partent ; le poisson manque une semaine.", "Z-01 MIXTE ; prix des Baies Oran en hausse a Myokara jusqu'au ch. 3."),
   O('c', "Escorte de nuit avec Brice (filets de Devon)", {'rP': 2, 'rA': 2, 'PR': -3}, {'eco': ('Z01', 2), 'bv': 'C', 'loss': "rencontre de Pierre Rochard manquee (DOS_ECLATS indisponible)"},
     "Toute la nuit en mer ; a l'aube, Goelise revient.", "Z-01 RESTAURE ; Pierre Rochard a quitte la Grotte Granite (D020 et D024 non rencontrees).")],
  ['E-ECO Z-01', 'Myokara boutique', 'Aldo ch. 9', 'D020/D024 (presence)', 'Sommet COM', 'diaporama Myokara'], 'variante sociale.',
  "Save avant mission ; 50 peches super canne : Krabby 60 % (ENVAHI) contre Magicarpe ; VAR_CF_ECO Z01 = 3/1/2. c : D020 et D024 marquees 'non rencontrees'.",
  delay='I', mem="Brice : 'Je mets Myokara en vert. Enfin, vert pale.'")

D('D019', 2, 'D', 'S', 'discret', "Petit voleur n 2 : le poisson du marche",
  'DewfordTown - CF_D019',
  "Le voleur prend un poisson sur l'etal ; le marchand accuse Brice.",
  [O('a', "Acheter un poisson et le lui laisser", {'HO': 5}, {'money': -200},
     "Il prend le poisson, laisse une baie.", "HO>=25 : il rend la moitie au ch. 3."),
   O('b', 'Le signaler au marchand', {'HO': -3, 'rP': 2}, {},
     "Le marchand rembourse Brice ; le voleur siffle.", "ch. 3 : il evite Red."),
   O('c', 'Ignorer', {'HO': 1, 'rP': -1}, {},
     "Brice paie de sa poche.", "rien d'immediat.")],
  ['HO'], 'F2.', "a : argent -200, HO +5 ; b : rP +2 ; c : HO +1.", delay='C')

D('D020', 2, 'E', 'S', 'aveu', "Grotte Granite : le secret des eclats",
  'GraniteCave_StevensRoom - CF_D020',
  "Pierre Rochard etudie des eclats rouges et bleus laisses par les anneaux ; il demande le silence.",
  [O('a', 'Garder le secret', {'PR': 5}, {'loss': 'piece non publique'},
     "Il remet la lettre lue ; 'Merci. Mon pere ne doit pas paniquer.'", "ch. 8 : il se confie davantage (D077)."),
   O('b', 'Montrer les eclats a Brice', {'PR': -3}, {'bv': 'C', 'set': ['DOS_ECLATS']},
     "Brice photographie tout ; Pierre Rochard se ferme.", "Sommet M3 : DOS_ECLATS (Devon savait) ; ch. 7 : Seko connait les eclats.")],
  ['PR seuils (duo ch. 10, climax, D077)', 'Sommet M3 (piece)'], 'F3/F1 via PR.',
  "Prerequis : D018 != c. a : PR=55 ; b : DOS_ECLATS, PR=47.", delay='C',
  when=lambda s: ch(s, 'D018') != 3, pre='D018 != c (Pierre Rochard encore la)')

D('D021', 2, 'E', 'S', 'don', "Badge 2 : l'arrivant de Bastien",
  'DewfordTown_Gym - CF_D021',
  "Bastien a sauve un Demanta des filets ; il le confie a qui le veut.",
  [O('a', 'Accepter', {'rA': 2, 'rP': -2}, {'gain': 'Equipe (Demanta, niv. plafond-3)'},
     "Les pecheurs regardent Red partir avec 'leur' probleme.", "ch. 11 : l'Aqua le reconnait (+1 replique, NEGOCIE plus facile si rA>=50)."),
   O('b', 'Refuser', {'rP': 2, 'rA': -2}, {'loss': 'Equipe'},
     "Bastien le garde ; un pecheur hoche la tete.", "ch. 3 : un pecheur offre une Super Canne.")],
  ['rA (D102)', 'rP'], 'indirect.', "a : Pokemon recu ; b : objet au ch. 3.", delay='I')

D('D022', 2, 'D', 'S', 'combat', "Aldo propose un duel (refusable)",
  'DewfordTown (plage) - CF_D022 (FLAG_CF_REFUS_ALDO)',
  "Aldo, escorte de la Mission arrive en avance, cherche 'un adversaire digne'.",
  [O('a', 'Accepter et gagner', {'rI': 2, 'rP': -1}, {'set': ['ALDO_RESPECT'], 'gain': 'objet (Ceinture Noire)'},
     "Aldo s'incline.", "ch. 11 : Aldo escorte Red a Fondmer (soigneur de repli)."),
   O('b', 'Accepter et perdre', {'rI': 1, 'BR': -1}, {'money': -300},
     "Aldo : 'Encore.'", "ch. 9 : Aldo s'engage avec les pecheurs."),
   O('c', 'Refuser', {'rP': 2, 'rI': -2}, {},
     "Aldo retourne aux caisses des pecheurs.", "ch. 9 : Aldo s'engage avec les pecheurs ; refus definitif.")],
  ['ch. 9 W8', 'ch. 11 Fondmer (soin)'], 'aucune.', "a : ALDO_RESPECT, objet ; c : FLAG_CF_REFUS_ALDO.", delay='C')

D('D023', 2, 'D', 'S', 'don', "R106 : le pecheur qui vend un arrivant",
  'Route106 - CF_D023',
  "Un pecheur ruine vend un Kokiyas capture plutot que de le livrer a la brigade.",
  [O('a', "L'acheter 300 P", {'rP': 2, 'rL': -2}, {'money': -300, 'gain': 'Equipe'},
     "Il compte les pieces deux fois.", "ch. 3 : rumeur 'un etranger achete' au port (RK +1 au ch. 3 si achete)."),
   O('b', 'Refuser', {'rL': 1, 'RK': 1}, {},
     "Il hausse les epaules : 'Les Rocket paieront.'", "le Kokiyas finit au marche noir (ch. 9).")],
  ['rumeur ch. 3', 'RK'], 'indirect.', "a : Pokemon recu, -300 P ; b : RK +1.", delay='I')

D('D024', 2, 'D', 'S', 'presence', "Emmener Brice a la Grotte Granite",
  'DewfordTown -> GraniteCave_1F - CF_D024',
  "Brice veut voir 'le fils de Devon' au travail.",
  [O('a', "L'emmener", {'BR': 2, 'PR': -2}, {'bv': 'C'},
     "Brice pose cent questions ; Pierre Rochard abrege.", "BV COMPRENDRE +1."),
   O('b', 'Y aller seul', {'PR': 2, 'BR': -1}, {},
     "Pierre Rochard parle librement.", "ch. 8 : il cite cette visite ('vous etiez seul, c'etait mieux').")],
  ['BV', 'PR'], 'BV.', "Prerequis D018 != c. a : BVCOUNT.C+1 ; b : PR+2.", delay='L',
  when=lambda s: ch(s, 'D018') != 3, pre='D018 != c')

# ---------------------------------------------------------------- CH. 3
D('D025', 3, 'D', 'S', 'presence', "Debarquement de la Mission : de quel cote du quai",
  'SlateportCity (port) - CF_D025',
  "La foule crie 'Kanto dehors' ; la Mission Indigo debarque.",
  [O('a', 'Rester parmi les gens du port', {'rP': 3, 'PE': -2}, {},
     "Une vendeuse offre un poisson grille a Red.", "ch. 3 : petition (D032) presentee d'office."),
   O('b', 'Rejoindre Peter sur le quai', {'PE': 3, 'rI': 2, 'rP': -3}, {},
     "Peter : 'Le champion. Enfin un visage.'", "ch. 5 : Peter attend Red au Site Meteore.")],
  ['PE', 'rI', 'rP'], 'indirect.', "a : rP=53 ; b : PE=53, rI=52.", delay='C', verdict=('F', 'effet limite a des deltas faibles et une replique ; aucun seuil pivot identifie (revue stricte)'))

D('D026', 3, 'E', 'M', 'arbitrage', "Kiosque Passerelle : premiere commande (loi H1)",
  'SlateportCity (marche, Kiosque) - CF_D026',
  "Le Kiosque livre un objet rare instantanement. Une fillette joue avec sa Goelise a cote.",
  [O('a', 'Commander (Restes, 3 000 P)', {'PA': 2, 'rC': 2, 'rP': -3}, {'money': -3000, 'gain': 'objet rare'},
     "Un anneau livre l'objet ; un second prend la Goelise de la fillette.", "H1 apprise par l'echec ; la fillette reste sur le banc jusqu'au ch. 12 (F2 : la Goelise revient)."),
   O('b', 'Ne pas commander', {'rC': -1, 'rP': 1}, {'loss': 'objet rare'},
     "Un client commande a la place ; l'anneau prend un sac.", "le Kiosque reste ouvert (commandes plafonnees, GAME_SYSTEMS 6).")],
  ['PA (P2, F3)', 'rC', 'epilogue F2 (fillette)'], 'F3 exige PA<50.',
  "a : objet, PA=22, rC=52, PNJ fillette sans Goelise ; b : rC=49. Observer l'hesitation a la 2e commande (prototype bible 11.4).",
  delay='I', mem="Carnet : 'Elle a donne. Moi, j'ai paye.'")

D('D027', 3, 'E', 'M', 'combat', "Blue 1 a la Tente de Scott (refusable)",
  'SlateportCity_BattleTentLobby - CF_D027 (FLAG_CF_REFUS_BLUE1)',
  "Blue : 'Le grand Red sans son equipe. Ca, je veux le voir.'",
  [O('a', 'Accepter et gagner', {'BL': 2, 'rC': 1, 'PE': -1}, {'N': '+1'},
     "Blue serre les dents ; Scott sort son carnet.", "Scott propose un contrat (D034) ; Blue T2 garde 1 import."),
   O('b', 'Accepter et perdre', {'BL': 4, 'rI': -2}, {'money': -500, 'N': '-1'},
     "Blue rit, puis se tait.", "Blue T2 +1 import (equipe plus forte) ; Mission : 'Le champion a perdu.'"),
   O('c', 'Refuser', {'BL': -4, 'PE': 2}, {},
     "Blue : 'Tu fuis ?' ; Peter, plus loin, approuve.", "ch. 9 : toit plus froid ; refus definitif.")],
  ['Blue T2/T3 (brief B)', 'STANCE_BLUE (BL>=60)', 'veillee (BL>=55)'], 'variante Blue (depart pour Jadielle).',
  "Jalon plafond 22 pose a la sortie de la Tente dans les 3 issues (test par issue). Slot D027=1/2/3.",
  delay='I', mem="Blue : 'On n'a pas fini, toi et moi.'")

D('D028', 3, 'D', 'S', 'discret', "L'homme au Persian au marche",
  'SlateportCity (marche) - CF_D028',
  "Un homme en costume observe le Kiosque ; un Persian a ses pieds.",
  [O('a', 'Rester a ecouter', {'GI': 3, 'rI': -1}, {},
     "'Tout s'achete. Sauf ce qui compte.' Il part.", "ch. 6 : il propose le duel incognito (D056)."),
   O('b', 'Le designer a Koga', {'rI': 3, 'GI': -5}, {},
     "Koga le suit ; l'homme disparait.", "ch. 6 : pas de duel incognito si GI<50 ; temoignage au Sommet plus difficile.")],
  ['D056 (GI>=50)', 'D114 temoignage (GI>=55)'], 'R4 source 2.',
  "a : GI=53 ; b : GI=45, rI=53 ; ch. 6 : PNJ Giovanni present seulement si GI>=50.", delay='C')

D('D029', 3, 'E', 'S', 'arbitrage', "Composant Devon pour le Capitaine Marin",
  'SlateportCity_SternsShipyard_1F - CF_D029 (FLAG_DELIVERED_DEVON_GOODS pose dans les 2 cas)',
  "Le colis scelle de Devon ; Cileo voudrait l'ouvrir.",
  [O('a', 'Livrer scelle', {'rC': 2}, {'loss': 'piece manquee'},
     "Marin remercie Devon.", "rien."),
   O('b', "Laisser Cileo l'examiner avant", {'rC': -3, 'rI': 1}, {'set': ['DOS_SCHEMA_CABLE']},
     "Schema du relais d'Algatia et du cable.", "Sommet M1 (piece CHARTE) ; ch. 11 : Marin sait que Red sait.")],
  ['Sommet M1', 'ch. 11 Marin (D106)', 'FLAG_DELIVERED_DEVON_GOODS (6 lecteurs vanilla)'], 'indirect.',
  "Les deux : FLAG_DELIVERED_DEVON_GOODS pose (grep : Route109, Dewford, Briney, Musee 1F/2F, chantier, pokenav). b : DOS_SCHEMA_CABLE, rC=47.",
  delay='L')

D('D030', 3, 'E', 'S', 'don', "Chen demande les donnees de Red",
  'SlateportCity_OceanicMuseum_1F (Chen et Seko) - CF_D030',
  "Chen veut les observations de Red avant Seko ; Seko attend dehors.",
  [O('a', 'Donner a Chen', {'BR': -3}, {'set': ['EXP_SHARE'], 'gain': 'Multi Exp des le ch. 3'},
     "Chen : 'Vous ne le regretterez pas.' Il remet le Multi Exp.", "ch. 7 : Seko accuse Chen au diner ; Brice blesse."),
   O('b', 'Donner a Seko', {'BR': 3}, {'loss': 'Multi Exp au ch. 4 seulement'},
     "Seko rougit ; Brice sourit.", "ch. 4 : Seko remet le Multi Exp avec Pikachu.")],
  ['QoL (Multi Exp, ch. 3 ou 4)', 'ch. 7 diner', 'REL_CHEN_SEKO'], 'epilogue Chen-Seko.',
  "a : FLAG_CF_EXP_SHARE pose au ch. 3 ; b : pose au ch. 4 (script Seko). BR 47/53.", delay='I')

D('D031', 3, 'D', 'S', 'discret', "Petit voleur n 3 : l'objet du Kiosque",
  'SlateportCity (chantier) - CF_D031',
  "Le voleur prend l'objet commande (ou une Poke Ball si rien n'a ete commande).",
  [O('a', 'Le laisser filer', {'HO': 5}, {'item': -1, 'loss': "objet perdu"},
     "Il tourne trois fois sur lui-meme.", "HO."),
   O('b', 'Le poursuivre dans le chantier', {'HO': -3}, {'set': ['DOS_TRACE_ANNEAU'], 'gain': 'objet recupere'},
     "Une brulure en anneau sur le quai.", "indice R2b ; piece mineure."),
   O('c', 'Le signaler a la Mission', {'HO': -5, 'rI': 2}, {},
     "Koga prend des notes.", "ch. 8 : le piege de Koga est pret plus tot (Koga plus sur de lui).")],
  ['HO', 'ch. 8 D075 (Koga)'], 'F2.', "a : HO+5, objet retire ; b : piece ; c : rI+2.", delay='C')

D('D032', 3, 'E', 'S', 'arbitrage', "La petition 'ports fermes a Kanto'",
  'SlateportCity (marche) - CF_D032',
  "Les commercants ruines par les imports font signer une petition.",
  [O('a', 'Signer', {'rP': 4, 'rI': -4}, {'set': ['PETITION']},
     "Les commercants applaudissent ; Ondine voit la signature.", "Sommet M3 : COM vote KANTO ; FK reste 'Mission'."),
   O('b', 'Refuser', {'rI': 2, 'rP': -2}, {},
     "Un commercant crache par terre.", "rien d'autre.")],
  ['Sommet M3 (COM)', 'FK'], 'FK postgame.', "a : PETITION, rP=54, rI=46.", delay='L')

D('D033', 3, 'D', 'S', 'don', "Rumeur de marche noir : payer l'informateur",
  'SlateportCity_Harbor - CF_D033',
  "Un docker vend un nom d'entrepot a Nenucrique pour 500 P.",
  [O('a', 'Payer 500 P', {'RK': 1}, {'money': -500, 'set': ['INFO_ENTREPOT'], 'gain': 'information (entrepot de Ferrand)'},
     "'Entrepot 3. Le type s'appelle Ferrand.'", "ch. 9 : coup de filet direct vers Ferrand (OBJ_LETTRE_FERRAND plus sur)."),
   O('b', 'Partir', {}, {'loss': 'information', 'gain': 'argent garde'},
     "Il crache.", "ch. 9 : Ferrand trouve seulement si Olga est suivie.")],
  ['ch. 9 D082'], 'indirect.', "a : -500 P, INFO_ENTREPOT ; ch. 9 replique d'Olga.",
  delay='C', verdict=('V', 'acces a la lettre de Ferrand (piece) au ch. 9'))

D('D034', 3, 'E', 'S', 'arbitrage', "Le contrat de Scott",
  'SlateportCity_BattleTentLobby - CF_D034',
  "Scott offre a Red une prime par victoire au Tournoi des Confluences.",
  [O('a', 'Signer', {'rC': 2, 'BL': -3}, {'money': 'tournoi'},
     "Blue : 'Tu me voles mon impresario.'", "Tournoi : primes x2 (plafonnees par chapitre) ; Blue T3 achete un import de plus."),
   O('b', 'Refuser', {'BL': 2, 'rC': -1}, {},
     "Scott : 'Je reviendrai.'", "Blue garde Scott pour lui.")],
  ['Tournoi (primes)', 'Blue T3', 'BL'], 'variante Blue.', "a : primes doublees (verifier au Tournoi) ; BL 47/52.", delay='C',
  when=lambda s: ch(s, 'D027') in (1, 2), pre='Blue 1 accepte (D027 a ou b)')

D('D035', 3, 'D', 'S', 'aveu', "Maison de la plage (R109) : les arrivants caches",
  'Route109_SeashoreHouse - CF_D035',
  "Un vieux couple cache des arrivants ; la brigade fouille la cote.",
  [O('a', 'Les designer a la brigade', {'rL': 3, 'rA': -3}, {},
     "La brigade embarque les arrivants ; le couple paie une amende.", "ch. 4 : brigade plus confiante (barrage R110 ouvert)."),
   O('b', 'Garder le secret', {'rA': 3, 'rL': -2}, {'gain': 'Potions offertes'},
     "Le couple offre trois Potions.", "ch. 9 : le couple apparait au port de Nenucrique (Aqua).")],
  ['rL/rA', 'barrage R110'], 'indirect.', "a : rL=53 ; b : 3 Potions, rA=53.", delay='I')

# ---------------------------------------------------------------- CH. 4
D('D036', 4, 'E', 'M', 'presence', "Lavandia : le quartier sud coupe",
  'MauvilleCity / NewMauville_Inside - CF_D036',
  "Major Bob coupe le quartier sud pour proteger la centrale ; une enfant frappe a la vitre.",
  [O('a', 'Retablir la ligne (Nouvelle Lavandia)', {'rP': 4, 'rL': -2}, {'set': ['BOB_QUARTIER']},
     "Red chasse les Statitik des transformateurs ; la lumiere revient.", "ch. 7 : Major Bob vote CONTRE l'abattage ; ch. 13 : il tient les civils."),
   O('b', 'Rester', {'rL': 2, 'rP': -3}, {},
     "L'enfant arrete de frapper.", "ch. 7 : Major Bob vote POUR.")],
  ['ch. 7 vote (D069)', 'climax : Major Bob allie civils', 'rP'], 'climax.',
  "a : BOB_QUARTIER, quartier eclaire (setflashlevel off), rP=54 ; b : quartier sombre jusqu'au ch. 7.",
  delay='I', mem="Carnet : 'Elle a arrete de frapper.' (b)")

D('D037', 4, 'E', 'M', 'arbitrage', "Mission de zone Z-03 : les vergers de Vergazon",
  'VerdanturfTown / Route117 - CF_D037',
  "Singes mangeurs de baies ; Erika propose un parfum, le Rempart un abattage.",
  [O('a', "Parfum d'Erika (fleur arrivante)", {'rC': 3, 'rA': -2}, {'eco': ('Z03', 1), 'set': ['ERIKA_CONTRAT']},
     "Les singes fuient vers la R117 ; Erika signe avec Devon.", "Z-03 MIXTE ; Erika reste MARCHE sauf ch. 6."),
   O('b', 'Deplacer vers le desert (Brice, Timmy)', {'rP': 3, 'rC': -2}, {'eco': ('Z03', 2), 'bv': 'A'},
     "Trois nuits de convoi.", "Z-03 RESTAURE ; arbres a baies de la R117 donnent a nouveau."),
   O('c', 'Abattage du Rempart', {'rL': 4, 'rP': 2, 'rI': -3, 'TI': -5}, {'eco': ('Z03', 3)},
     "Timmy cache son Feuillajou sous son lit.", "Z-03 ABATTU ; ch. 7 : l'arrivant de Timmy est sur la liste.")],
  ['E-ECO Z-03 (R117 baies)', 'ch. 7 Vergazon (D064)', 'Erika (D058)', 'diaporama'], 'variante sociale.',
  "50 rencontres R117 par issue ; arbres a baies (vides si ENVAHI). VAR_CF_ECO Z03.", delay='I', mem='Brice colorie Vergazon sur sa carte (vert, orange ou gris).')

D('D038', 4, 'D', 'S', 'don', "Timmy et son arrivant condamne",
  'VerdanturfTown - CF_D038',
  "Timmy cache un Feuillajou ; il n'a pas de Poke Ball pour le declarer.",
  [O('a', 'Lui donner une Poke Ball', {'TI': 5, 'rL': -3}, {'item': -1},
     "Timmy le capture en tremblant ; il est declare.", "ch. 7 : l'arrivant est 'a Timmy' (Flora hesite)."),
   O('b', 'Ne rien faire', {'rL': 1, 'TI': -1}, {},
     "Timmy le cache encore.", "ch. 7 : l'arrivant est saisi d'office sauf intervention.")],
  ['D064 (ch. 7)', 'equipe de Timmy (avec/sans)', 'D123 (ch. 14)'], 'variante Timmy.',
  "a : TI=55, une Poke Ball en moins ; b : TI=49.", delay='C')

D('D039', 4, 'D', 'S', 'discret', "Petit voleur n 4 : le piege du fermier",
  'Route117 - CF_D039',
  "Le voleur est pris dans un piege a baies ; le fermier arrive avec un baton.",
  [O('a', 'Ouvrir le piege', {'HO': 5, 'rP': -2}, {},
     "Il fuit, puis revient deposer une baie.", "HO>=40 au ch. 7 plus probable."),
   O('b', 'Laisser le fermier', {'HO': -2, 'rP': 1}, {'set': ['FERMIER_TEMOIN']},
     "Un anneau : le piege disparait avec lui.", "le fermier perd son piege (replique).")],
  ['HO'], 'F2.', "a : HO+8 ; b : HO-2.", delay='C')

D('D040', 4, 'E', 'L', 'arbitrage', "Raid du Tunnel Merazon : l'approche",
  'RusturfTunnel - CF_D040 (jalon plafond 27 a la sortie, toutes issues)',
  "La Rocket stocke des arrivants dans le tunnel ; trois approches proposees au QG de Vergazon.",
  [O('a', 'De front avec Brice', {'BR': 5, 'RK': -8, 'rL': -2}, {'bv': 'P', 'set': ['DOS_CARNET_PRIMES', 'DOS_PREDICTEUR']},
     "Combat contre Lance (Rocket) ; Brice saisit le predicteur ; page 'paiement a K.'", "R1 ; W10 au ch. 10 (montrer la page a Peter)."),
   O('b', 'Infiltration avec Koga (Mission)', {'rI': 8, 'RK': -5, 'BR': -5}, {'set': ['DOS_PREDICTEUR'], 'val': {'KOGA': 'COUVERT'}},
     "Koga empoche une page sans un mot.", "R1 ; la page 'K.' disparait : Koga COUVERT par defaut."),
   O('c', 'Laisser le Rempart mener (Flora)', {'rL': 8, 'RK': -3, 'rA': -3}, {'set': ['DOS_PREDICTEUR'], 'loss': 'cargaison abattue'},
     "La brigade abat la cargaison ; Norman garde le predicteur.", "R1 (Norman montre le predicteur) ; FL +2 si D008 c.")],
  ['R1', 'D075 (page)', 'W10 (REL_KOGA_PETER)', 'RK', 'Sommet'], 'RK -> variante Rocket ; climax relais (RK<70).',
  "Save avant raid. Chaque issue : DOS_PREDICTEUR pose, VAR_CF_CAP>=27 a la sortie ; a : DOS_CARNET_PRIMES ; b : KOGA=COUVERT ; c : rL=58.",
  delay='I', mem="Brice : 'Ils savaient ou l'anneau s'ouvrirait. Ils savaient.'")

D('D041', 4, 'E', 'S', 'arbitrage', "Retour de Pikachu : le reprendre ou le laisser a Seko",
  'MauvilleCity (Seko au Centre) - CF_D041',
  "Seko ramene Pikachu gueri (niveau plafond-2, E-LVL).",
  [O('a', "Le reprendre", {'BR': -1}, {'gain': 'Equipe (Pikachu)', 'set': ['PIKA_EQUIPE']},
     "Pikachu saute sur l'epaule de Red.", "Pikachu disponible (equipe)."),
   O('b', 'Le laisser aider le recensement', {'BR': 4}, {'loss': 'Equipe', 'bv': 'C'},
     "Pikachu part avec Brice ; Brice : 'Il compte mieux que moi.'", "ch. 12 : Pikachu dans l'equipe de Brice ; F4/F5 : epilogue commun.")],
  ['equipe Brice (brief B)', 'BV'], 'epilogue Brice.', "Prerequis D001=a. a : Pikachu dans l'equipe ; b : BR=54.",
  when=lambda s: ch(s, 'D001') == 1, pre='D001 = a', delay='I')

D('D042', 4, 'E', 'S', 'arbitrage', "Badge 3 : 'le courant d'abord' de Voltere",
  'MauvilleCity_Gym - CF_D042',
  "Voltere veut prioriser la ville sur la Nouvelle Lavandia (arrivants Electrik chasses).",
  [O('a', 'Signer', {'rC': 3, 'rA': -3}, {},
     "Voltere : 'La lumiere, c'est la vie !'", "ch. 7 : courant stable (PA +1 : consortium soutenu)."),
   O('b', 'Refuser', {'rA': 2, 'rC': -2}, {},
     "Voltere : 'Tu verras, a la premiere coupure.'", "rien.")],
  ['rC/rA', 'PA'], 'indirect.', "a : rC=53, PA+1 au ch. 7 ; b : rA=52.", delay='C', verdict=('F', 'PA+1 et deltas rC/rA marginaux ; aucun lecteur propre (revue stricte)'))

D('D043', 4, 'D', 'S', 'combat', "L'exercice de Major Bob (refusable)",
  'MauvilleCity (perimetre) - CF_D043 (FLAG_CF_REFUS_BOB)',
  "Major Bob teste les 'soldats' de passage.",
  [O('a', 'Accepter et gagner', {'rI': 3, 'rP': -1}, {'gain': 'objet (Aimant)', 'set': ['BOB_RESPECT']},
     "'Pas mal, pour un civil.'", "ch. 13 : Major Bob competent aux civils meme sans BOB_QUARTIER."),
   O('b', 'Accepter et perdre', {'rI': 1, 'BR': -1}, {'money': -300},
     "'Recommence quand tu veux.'", "rien."),
   O('c', 'Refuser', {'rI': -2, 'rP': 2}, {},
     "Un enfant du quartier : 'Il joue pas au soldat.'", "refus definitif.")],
  ['climax (allie Major Bob)'], 'climax civils.', "a : flag BOB_RESPECT ; c : refus pose.", delay='L')

D('D044', 4, 'E', 'S', 'arbitrage', "L'echantillon d'Erika",
  'VerdanturfTown - CF_D044',
  "Erika demande a Red de porter a Devon un echantillon de la fleur arrivante.",
  [O('a', 'Porter', {'rC': 2, 'rA': -1}, {},
     "Devon signe ; Erika offre une CT.", "ch. 6 : Erika achete les sources (D058 plus dur)."),
   O('b', 'Refuser', {'rA': 1, 'rC': -2}, {},
     "Erika : 'Je trouverai un autre porteur.'", "ch. 6 : Erika hesite (STANCE_ERIKA INT atteignable).")],
  ['D058', 'STANCE_ERIKA'], 'indirect.', "a : CT recue, rC=52 ; b : rC=48.", delay='C')

D('D045', 4, 'D', 'S', 'don', "R117 : les oeufs abandonnes",
  'Route117_PokemonDayCare - CF_D045',
  "Un eleveur abandonne des oeufs d'arrivants devenus trop chers.",
  [O('a', 'Prendre un oeuf', {'rL': -2, 'rA': 1}, {'gain': 'oeuf (Unys)'},
     "L'eleveur soupire de soulagement.", "oeuf eclot au ch. 5."),
   O('b', 'Refuser', {'rL': 1, 'RK': 2}, {},
     "Un homme en noir prend la caisse.", "ch. 6 : Ariane aligne un de ces arrivants.")],
  ['RK', 'Ariane T2 (brief B)'], 'indirect.', "a : oeuf ; b : RK+2.", delay='I')

# ---------------------------------------------------------------- CH. 5
D('D046', 5, 'E', 'S', 'arbitrage', "R112 : le capteur de Kelvin",
  'Route112 - CF_D046',
  "Kelvin (Magma) demande a Red de poser un capteur au Site Meteore.",
  [O('a', 'Accepter', {'rM': 3, 'rG': -2, 'PA': 1}, {},
     "Kelvin : 'Max saura que tu es raisonnable.'", "ch. 6 : la demonstration est plus precise (troupeau mieux deplace, PA +1)."),
   O('b', 'Refuser', {'rM': -2, 'rG': 1}, {},
     "Kelvin range le capteur.", "rien.")],
  ['ch. 6 demonstration', 'rM/rG (Sommet)'], 'indirect.', "a : rM=53, PA+1 ; b : rM=48.", delay='C', verdict=('F', 'PA+1 et deltas marginaux ; la precision de la demonstration est du texte (revue stricte)'))

D('D047', 5, 'D', 'S', 'discret', "Petit voleur n 5 : les lunettes de Kosmo",
  'Route113 - CF_D047',
  "Le voleur emporte les lunettes de Kosmo dans la cendre.",
  [O('a', 'Le laisser les garder', {'HO': 5}, {'loss': 'Kosmo sans donnees'},
     "Il les porte de travers.", "Kosmo n'a pas ses releves (DOS_ETOILES indisponible)."),
   O('b', 'Les reprendre', {'HO': -3}, {'set': ['DOS_ETOILES']},
     "Kosmo : 'Mes etoiles filantes... ce ne sont pas des etoiles.'", "piece : eclairs d'anneaux (Q4, H3) ; ch. 8 : negociation avec Sarah.")],
  ['HO', 'D080 (ch. 8)', 'Sommet M1'], 'F2.', "a : HO+5 ; b : DOS_ETOILES.", delay='C')

D('D048', 5, 'E', 'M', 'arbitrage', "Quete de Bayar (desert, facultative)",
  'Route111 (desert, ruines) - CF_D048 (Eclate-Roc)',
  "Des fouisseurs d'Unys menacent les ruines ; Bayar veut sceller la galerie.",
  [O('a', 'Sceller avec Bayar', {'rG': 3, 'rA': -2}, {'set': ['DOS_SCEAUX_ANCIENS', 'LUNETTES_BAYAR']},
     "Bayar : 'Les anciens ont fait pareil. Pour pire que ca.'", "fin cachee : piece des sceaux (Regis)."),
   O('b', 'Ouvrir et deplacer les fouisseurs', {'rA': 2, 'rG': -2}, {'set': ['LUNETTES_BAYAR'], 'ecostep': 'Z03'},
     "Les Kraknoix reviennent.", "Z-03 : +1 cran vers RESTAURE (MIXTE -> RESTAURE ; ABATTU -> MIXTE).")],
  ['fin cachee', 'E-ECO Z-03'], 'fin cachee.', "a : DOS_SCEAUX_ANCIENS ; b : VAR_CF_ECO Z03 +1 cran.", delay='L', mem="Bayar : 'Tu reviendras quand tu sauras ce qu'ils ont enferme.'")

D('D049', 5, 'E', 'M', 'arbitrage', "Les journaux de Lanette (W9 Leo/Lanette)",
  'Route114_LanettesHouse - CF_D049',
  "Lanette remet ses journaux horodates ; Leo demande de ne rien dire au Consortium.",
  [O('a', 'Les garder pour Brice', {'BR': 3, 'rC': -2}, {'bv': 'C', 'set': ['DOS_JOURNAUX']},
     "Brice les serre contre lui.", "ch. 7 : R2 complete (carte + journaux) ; Sommet M1 (CHARTE/FERMER)."),
   O('b', 'Les rendre au Consortium', {'rC': 4, 'BR': -3}, {'loss': 'piece'},
     "Le President remercie par lettre.", "ch. 7 : R2 tient par l'aveu de Leo seul (indice 3).")],
  ['ch. 7 R2', 'D051', 'Sommet'], 'indirect.', "a : DOS_JOURNAUX, BVCOUNT.C+1 ; b : rC=54.", delay='C',
  mem="Brice : 'Je les recopie ce soir.'")

D('D050', 5, 'E', 'M', 'presence', "Site Meteore : Peter contre Amaryllis (W1)",
  'MeteorFalls_1F_1R - CF_D050 (fin d evenement : FLAG_HIDE_ROUTE_112_TEAM_MAGMA pose, plafond 29, toutes issues)',
  "Clan contre clan ; Aragon arbitre ; Amaryllis accuse Peter 'd'etre de la region du voleur'.",
  [O('a', 'Designer Aragon (respect du Site)', {'rG': 5, 'AM': 3, 'PE': -2}, {'set': ['PETER_RESPECT', 'REL_AMA_ARAGON']},
     "Aragon parle ; Peter se retire, Drattak a son cote.", "Peter aligne Drattak (brief B) ; Amaryllis et Aragon reconcilies."),
   O('b', 'Partir avec Peter', {'PE': 5, 'rI': 3, 'rG': -5, 'AM': -5}, {},
     "Peter pietine la mousse sacree.", "Amaryllis : 'Le voleur et ses amis.' ; rite du ch. 12 plus fragile.")],
  ['brief B (Peter Drattak)', 'AM (climax)', 'rG (rite)', 'REL_AMA_ARAGON'], 'climax Pilier (AM, rG).',
  "Les deux issues : FLAG_HIDE_ROUTE_112_TEAM_MAGMA pose (lecteurs : Route112, MeteorFalls_1F_1R), VAR_CF_CAP>=29. a : rG=55, AM=53 ; b : PE=55, AM=45.",
  delay='C', mem="Carnet : 'Elle a dit voleur. Elle me regardait.'")

D('D051', 5, 'D', 'S', 'don', "Les donnees de Brice contredisent son pere",
  'MeteorFalls_1F_1R (sortie) - CF_D051',
  "Brice relit ses comptes : les arrivants suivent les contrats des noeuds.",
  [O('a', 'Montrer les journaux de Lanette', {'BR': 2, 'rL': -1}, {'bv': 'C'},
     "Brice : 'Papa se trompe. Ou on lui ment.'", "BV COMPRENDRE +1."),
   O('b', 'Rester (le laisser croire son pere)', {'BR': -1, 'rL': 1}, {'bv': 'P'},
     "Brice : 'Papa doit avoir une raison.'", "BV PROTEGER +1.")],
  ['BV'], 'BV.', "Prerequis DOS_JOURNAUX pour a. a : BVCOUNT.C+1 ; b : BVCOUNT.P+1.",
  when=lambda s: True, delay='L')

D('D052', 5, 'E', 'S', 'arbitrage', "Le fragment de meteorite de Kosmo",
  'FallarborTown_CozmosHouse - CF_D052',
  "Kosmo hesite : rendre le fragment au Peuple du Meteore ou le vendre a Devon.",
  [O('a', 'A la Doyenne', {'rG': 3, 'rC': -2}, {'set': ['FRAGMENT_DOYENNE']},
     "La Doyenne : 'Il servira au rite.'", "ch. 13 : le rite retarde Rayquaza plus longtemps (RITE possible avec rG>=45)."),
   O('b', 'A Devon (1 500 P pour Kosmo, 500 P pour Red)', {'rC': 2, 'rG': -3}, {'money': 500},
     "Kosmo paie sa toiture.", "rien.")],
  ['climax RITE (seuil rG)'], 'F1.', "a : FRAGMENT_DOYENNE ; b : +500 P.", delay='L')

D('D053', 5, 'D', 'S', 'don', "Aster, la Chuchmur de la gardienne disparue",
  'Route113 / MeteorFalls - CF_D053',
  "Une Chuchmur suit Red dans la cendre ; elle porte un ruban du Peuple du Meteore.",
  [O('a', 'La ramener a Amaryllis', {'AM': 5, 'PE': -2}, {},
     "Amaryllis se fige ; 'Aster...'", "ch. 13 : Amaryllis renonce plus facilement (AM)."),
   O('b', 'La confier a la Doyenne', {'rG': 3, 'AM': -2}, {},
     "La Doyenne la garde au chaud.", "ch. 12 : Aster au rite.")],
  ['AM (climax)', 'rG'], 'climax Pilier.', "a : AM+5 ; b : rG+3.", delay='L')

# ---------------------------------------------------------------- CH. 6
D('D054', 6, 'E', 'L', 'arbitrage', "Demonstration de Magma (W5) : soutenir, saboter, denoncer",
  'MtChimney - CF_D054',
  "Max ouvre un anneau declenche pour deplacer le troupeau d'Unys des champs ; Arthur manifeste.",
  [O('a', 'Soutenir (proteger la demonstration)', {'rM': 8, 'PA': 5, 'rA': -8}, {'eco': ('Z06', 1)},
     "Le troupeau disparait des champs ; une heure plus tard, les Pokemon des sources aussi.", "Z-06 MIXTE ; Max PERSISTE par defaut ; Auguste reste."),
   O('b', 'Saboter avec Aqua', {'rA': 8, 'rM': -8, 'PA': 2, 'rP': -3}, {'eco': ('Z06', 0)},
     "L'anneau rate a moitie ; le troupeau reste, les sources tiennent.", "Z-06 ENVAHI ; fermiers ruines ; Aqua fait confiance a Red.",
     req=lambda s: not has(s, 'INSIGNE') , reqtxt='sans l insigne de brigade (D017 b)'),
   O('c', "Denoncer (montrer l'horaire vole a Adriane)", {'rL': 5, 'rM': -5, 'rC': -3}, {'eco': ('Z06', 3)},
     "La Ligue arrete la demonstration ; la brigade abat le troupeau.", "Z-06 ABATTU ; le Consortium accuse d'avoir vendu l'horaire.")],
  ['E-ECO Z-06', 'D061 (Max)', 'D062/D089 (Auguste)', 'PA', 'Sommet'], 'PA (F3), variante sociale.',
  "Save avant. a : PA+5, Z06=1, Chamallot 20 % -> 1 % sur R112 ; b : Z06=0 ; c : Z06=3. Hoopa blesse dans les 3 issues (D055).",
  delay='I', mem="Brice (s'il est la) : 'Ca prend autant que ca donne.'")

D('D055', 6, 'D', 'M', 'don', "Petit voleur n 6 : blesse par l'anneau",
  'MtChimney (bord du cratere) - CF_D055',
  "Le voleur, a moitie aspire, retient un Chamallot par la patte. Personne ne voit sauf Red.",
  [O('a', 'Donner une Potion', {'HO': 8}, {'item': -1, 'set': ['HOOPA_SOIGNE']},
     "Il la boit, regarde Red longtemps.", "D062 : Red peut montrer a Auguste ; HO."),
   O('b', 'Rester', {'rM': 2, 'HO': -1}, {},
     "Il se libere seul et fuit vers l'est.", "indice R2b.")],
  ['HO', 'D062'], 'F2.', "a : HO+8, HOOPA_SOIGNE ; b : rM+2.", delay='C', mem="Carnet : 'Il m'a regarde boire la Potion. Lui.'")

D('D056', 6, 'E', 'M', 'combat', "Giovanni incognito (refusable)",
  'FieryPath (Chemin Ardent) - CF_D056 (FLAG_CF_REFUS_GIO1)',
  "L'homme au Persian corrige des sbires negligents, puis propose un combat a 3 Pokemon.",
  [O('a', 'Accepter et gagner', {'GI': 5, 'RK': 2}, {},
     "'Tu es devenu... interessant.'", "D114 : temoignage possible (GI>=55)."),
   O('b', 'Accepter et perdre', {'GI': 2, 'BL': -1}, {'money': -500},
     "'Tu n'es plus le meme.'", "rien d'autre."),
   O('c', 'Refuser', {'GI': -3, 'RK': -3}, {},
     "Il congedie lui-meme ses sbires : 'Vous m'avez fait honte.'", "moins de sbires au ch. 7.")],
  ['GI (D114)', 'RK'], 'R4 source 2.', "Prerequis GI>=50. a : GI+5 ; c : GI-3, RK-3, refus pose.",
  when=lambda s: s['v']['GI'] >= 50, pre='GI >= 50 (D028 a ou neutre)', delay='L', mem="Giovanni : 'On se reverra. Ailleurs.'")

D('D057', 6, 'D', 'S', 'don', "Ariane recrute a Vermilava",
  'LavaridgeTown - CF_D057',
  "Un gardien des sources ruine ; Ariane compte des billets : 'Votre Ligue les parque. Nous, on les paie.'",
  [O('a', 'Donner 1 000 P au gardien', {'RK': -4, 'rP': 2}, {'money': -1000},
     "Il rend les billets a Ariane.", "ch. 10 : Ariane a un sbire de moins ; il aide a l'evacuation (ch. 13)."),
   O('b', 'Rester', {'RK': 3}, {'gain': 'argent'},
     "Il prend l'argent.", "ch. 10 : il est au relais, en noir.")],
  ['RK', 'climax civils'], 'variante Rocket.', "a : -1000 P, RK-4 ; b : RK+3.", delay='I')

D('D058', 6, 'D', 'S', 'presence', "Erika et Adriane : les sources a vendre",
  'LavaridgeTown (sources) - CF_D058',
  "Erika veut acheter les sources taries pour un parfum ; Adriane refuse.",
  [O('a', 'Designer Adriane (elle parle)', {'rP': 3, 'rC': -2}, {'set': ['STANCE_ERIKA_INT']},
     "Erika ecoute, puis dechire son contrat.", "Erika passe INTEGRATION (equipe, vote via Mission)."),
   O('b', 'Rester', {'rC': 3, 'rP': -3}, {},
     "Erika signe ; Adriane pleure de rage.", "Erika reste MARCHE.")],
  ['STANCE_ERIKA (brief B)', 'epilogue Vermilava'], 'diaporama Vermilava.',
  "a : STANCE_ERIKA_INT ; b : rC+3.", delay='I')

D('D059', 6, 'E', 'S', 'arbitrage', "Planque Magma : l'horaire vendu par Lambda",
  'MagmaHideout_2F_1R - CF_D059',
  "Un horaire signe 'Passerelle', vendu aux deux camps par 'Ferrand'.",
  [O('a', 'Le copier pour Brice', {'rM': -2, 'BR': 1}, {'set': ['DOS_HORAIRE_VENDU']},
     "Brice : 'Le meme papier que chez Aqua ?'", "ch. 10 : preuve pour demasquer Lambda (D095)."),
   O('b', 'Le rendre a Max', {'rM': 4, 'BR': -1}, {'loss': 'piece'},
     "Max : 'Merci. On nous a vole.'", "D061 : Max ecoute plus volontiers.")],
  ['D095', 'D061'], 'indirect.', "a : DOS_HORAIRE_VENDU ; b : rM+4.", delay='C')

D('D060', 6, 'D', 'S', 'presence', "Attendre Brice au telepherique",
  'Route112_CableCarStation - CF_D060',
  "Brice est en retard ; la demonstration commence dans dix minutes.",
  [O('a', 'Attendre', {'BR': 2, 'rM': -2}, {'bvdemo': True},
     "Ils arrivent pendant la manifestation.", "Brice temoin de D054 : BV +1 (a : PROTEGER, b : ACCUEILLIR, c : COMPRENDRE)."),
   O('b', 'Monter seul', {'BR': -2, 'rM': 1}, {},
     "Max accueille Red en personne.", "Brice absent de la demonstration.")],
  ['BV'], 'BV.', "a : BVCOUNT +1 selon D054 ; b : BR-2.", delay='L')

D('D061', 6, 'E', 'S', 'aveu', "Montrer a Max les sources vides",
  'LavaridgeTown -> MagmaHideout_1F - CF_D061',
  "Apres la demonstration, les natifs des sources ont disparu (loi H1 visible).",
  [O('a', 'Montrer (Chamallot absent, releve de Brice)', {'rM': 2, 'PA': -2, 'rC': -2}, {'set': ['STANCE_MAX_ECOUTE']},
     "Max se tait longtemps ; 'Alors, on prend ailleurs.'", "Max ECOUTE : il arrete les anneaux declenches ; Sommet : MAX vote FERMER."),
   O('b', 'Partir', {'PA': 2, 'rC': 1}, {},
     "Max relance les calculs.", "ch. 8-9 : Magma declenche deux anneaux de plus (P2 plus tot).")],
  ['Sommet MAX', 'PA', 'E-OUT ch. 8'], 'PA.', "Prerequis D054 = a (sinon Max ecoute d'office si c). a : STANCE_MAX_ECOUTE ; b : PA+2.",
  when=lambda s: ch(s, 'D054') == 1, pre='D054 = a', delay='C')

D('D062', 6, 'D', 'S', 'aveu', "Auguste et le petit voleur blesse",
  'LavaridgeTown (Centre) - CF_D062',
  "Auguste boit seul ; il parle de Cramois'Ile et d'une 'creature qu'on a deja fabriquee'.",
  [O('a', 'Lui montrer la trace du voleur blesse', {'rM': -3, 'HO': 1}, {'set': ['AUGUSTE_DOUTE']},
     "Auguste : 'Encore une fois, on enchaine quelque chose.'", "ch. 9 : Auguste peut rejoindre Fuji (D089).", req=lambda s: has(s, 'HOOPA_SOIGNE'), reqtxt='HOOPA_SOIGNE (D055 a)'),
   O('b', 'Rester', {'rM': 1}, {'loss': 'Auguste reste loyal'},
     "Auguste retourne a ses cartes.", "ch. 9 : Auguste reste avec Max.")],
  ['D089 (ch. 9)', 'Sommet (Magma)'], 'climax relais (Fuji competent).',
  "Prerequis HOOPA_SOIGNE ou D055 vue. a : AUGUSTE_DOUTE ; b : rM+1.", delay='C')

# ---------------------------------------------------------------- CH. 7
D('D063', 7, 'E', 'M', 'presence', "Filature de Lambda ou course a Vergazon (exclusif)",
  'MauvilleCity -> VerdanturfTown - CF_D063',
  "'Ferrand' quitte Lavandia en hate ; au meme moment, la brigade marche sur Vergazon.",
  [O('a', 'Suivre Lambda', {'RK': -3, 'TI': -3}, {'set': ['DOS_LAMBDA']},
     "Photo du deguisement retire dans une ruelle.", "ch. 10 : demasquage immediat (D095) ; Vergazon se joue sans Red (D064 decidee par FL et D038).", req=lambda s: has(s, 'LAMBDA_REMARQUE'), reqtxt='LAMBDA_REMARQUE (D013 a)'),
   O('b', 'Courir a Vergazon', {'TI': 2, 'RK': 1}, {},
     "Red arrive avant la brigade.", "D064 jouee par Red ; Lambda disparait.")],
  ['D064', 'D095'], 'variante Timmy ; RK.', "a : DOS_LAMBDA, D064 resolue automatiquement ; b : D064 disponible.",
  when=None, delay='I', mem="Carnet : 'Un choix. L'autre continue sans moi.'")

D('D064', 7, 'E', 'M', 'arbitrage', "Vergazon : Timmy contre la brigade (W3)",
  'VerdanturfTown - CF_D064',
  "Flora execute l'ordre ; Brice recite ses chiffres ; Timmy serre son arrivant.",
  [O('a', 'Defendre Timmy (combat contre la brigade)', {'TI': 5, 'FL': -3, 'rL': -4}, {'set': ['TIMMY_SAUVE']},
     "La brigade recule ; Flora part sans un mot.", "Timmy aligne son arrivant ; Flora ne bascule que si FL>=60."),
   O('b', 'Convaincre Flora (montrer releves ou Z-03)', {'FL': 5, 'rL': -2, 'TI': 3}, {'set': ['TIMMY_SAUVE', 'FLORA_DOUTE'], 'gain': 'sauvetage sans combat'},
     "Flora baisse son arme : 'Je n'ai rien vu.'", "Flora DOUTE (bascule au ch. 13 si FL>=55).",
     req=lambda s: ch(s, 'D010') == 2 or ch(s, 'D037') in (1, 2) or has(s, 'DOS_JOURNAUX'), reqtxt='Z-02 MIXTE, Z-03 MIXTE/RESTAURE ou journaux'),
   O('c', "Laisser faire l'ordre", {'TI': -5, 'rL': 3, 'FL': 2}, {'loss': 'arrivant de Timmy abattu'},
     "Timmy ne pleure pas ; c'est pire.", "Pierre (Brock) : ses proteges abattus aussi (vote ch. 12 : retrait amer).")],
  ['equipe Timmy (brief B)', 'D122 (Flora)', 'Pierre (Brock) vote', 'D123', 'epilogue Timmy'], 'variante Timmy, Flora.',
  "Prerequis D063 = b. a : TIMMY_SAUVE, FL-3 ; b : TIMMY_SAUVE+FLORA_DOUTE ; c : TI-5. Si D063 = a : script auto (sauve si TI>=55 et FL>=55, sinon c).",
  when=lambda s: ch(s, 'D063') == 2, pre='D063 = b', delay='I', mem="Brice : 'Flora. Tu m'avais dit que tu choisirais.'")

D('D065', 7, 'E', 'S', 'aveu', "L'aveu de Leo : le proteger ou le nommer",
  'MauvilleCity (Centre) - CF_D065',
  "Leo remet l'enregistrement du 'battement' du Coeur (DOS_BATTEMENT, toujours) et demande l'anonymat.",
  [O('a', 'Le proteger', {'rC': 2, 'rL': -1}, {'set': ['LEO_INSIDER']},
     "Leo retourne au relais.", "ch. 10 et 13 : Leo ouvre le relais (allie Consortium competent)."),
   O('b', 'Le nommer publiquement', {'rC': -4, 'rL': 2}, {},
     "Leo est renvoye ; il rejoint Lanette.", "Sommet : COM et NOR lisent rC plus bas.")],
  ['climax (Leo/Lanette)', 'rC'], 'F3 (allie relais).', "Les deux : DOS_BATTEMENT pose. a : LEO_INSIDER.", delay='L')

D('D066', 7, 'D', 'S', 'discret', "Petit voleur n 7 : le carnet rendu",
  'Route116 - CF_D066',
  "Si HO>=40, le voleur depose le carnet de Brice ; sinon, rien, sauf un anneau eteint.",
  [O('a', 'Donner quelque chose en echange', {'HO': 5, 'BR': 1}, {'item': -1},
     "Il prend la baie et reste a regarder.", "HO."),
   O('b', 'Reprendre le carnet sans rien donner', {'HO': -2, 'BR': 3}, {'bv': 'C'},
     "Il part, vexe.", "Brice retrouve son recensement (BV +1 a son compteur dominant)."),
   O('c', "Laisser de la nourriture a l'anneau eteint", {'HO': 3}, {'item': -1, 'loss': 'carnet perdu'},
     "Le lendemain, la nourriture a disparu.", "HO.")],
  ['HO', 'BV'], 'F2.', "Si HO>=40 : options a/b ; sinon c seule. Valeurs HO attendues +5/-2/+3.", delay='C')

D('D067', 7, 'D', 'S', 'presence', "Diner chez les Seko : Chen contre Seko",
  'LittlerootTown_BrendansHouse_1F - CF_D067',
  "Chen et Seko se disputent la paternite des noms d'especes.",
  [O('a', 'Designer Seko', {'BR': 2, 'rI': -1}, {},
     "Seko parle de Hoenn qui perd ses natifs.", "REL_CHEN_SEKO : rivalite maintenue."),
   O('b', 'Rester (Mme Seko intervient)', {'BR': 1, 'rL': -1}, {'set': ['DINER_APAISE']},
     "Mme Seko sert le dessert ; Chen rit le premier.", "REL_CHEN_SEKO possible (si Chen avoue au ch. 12).")],
  ['REL_CHEN_SEKO (epilogue, fin cachee)'], 'fin cachee.', "b : DINER_APAISE.", delay='L')

D('D068', 7, 'E', 'L', 'aveu', "Brice et la publication (R2) : la reaction de Red",
  'LittlerootTown_BrendansHouse_2F - CF_D068 (jalon plafond 33 apres la scene, toutes issues)',
  "Brice superpose sa carte et les journaux : R2. Il decide seul (selon BV) de publier ou de remettre a son pere.",
  [O('a', 'Approuver (hocher la tete)', {'BR': 8, 'rC': -5}, {'pub': True},
     "Brice publie (ou remet) en disant 'nous'.", "si publie : PA -5 (un noeud de surcharge ferme a Poivressel), rC -3 de plus."),
   O('b', 'Tourner le dos', {'BR': -10, 'rL': 2}, {'pub': True},
     "Brice publie quand meme, seul ; il ne dit plus 'nous'.", "BR bas : traduction seche au Sommet."),
   O('c', 'Lui donner sa casquette', {'BR': 5, 'rI': -2}, {'pub': True, 'bvlead': True, 'set': ['CREDIT_PARTAGE']},
     "Brice rit, puis pleure un peu.", "Credit partage Chen-Seko (REL_CHEN_SEKO possible) ; BV +1 au compteur dominant.")],
  ['BRICE_PUBLIE (PA, rC, Sommet BRI)', 'BR (traduction, veillee)', 'REL_CHEN_SEKO'], 'F3 (PA), fin cachee.',
  "Etat BV force (PROT dominant / COMP dominant). Attendu : publie si COMP ou ACC domine (PA-5), sinon remise a Seko (rL+5). VAR_CF_CAP>=33 dans les 3 issues.",
  delay='I', mem="Brice : 'Je l'ai fait. Toi, tu as fait ca.'")

D('D069', 7, 'E', 'M', 'arbitrage', "Vote d'abattage du Rempart (W4)",
  'PetalburgCity_Gym (QG) - CF_D069',
  "Norman et Major Bob votent l'abattage general ; Roxanne apporte ses chiffres.",
  [O('a', 'Montrer une piece (battement, predicteur, journaux)', {'rL': -5, 'RK': -2}, {'vote': 'show'},
     "Le vote echoue si Major Bob est CONTRE (D036 a) ou si Roxanne s'abstient.", "VOTE_ABATTAGE non : aucune brigade au ch. 8."),
   O('b', 'Rester', {'rL': 3, 'RK': 2}, {'vote': 'stay'},
     "Le vote passe sauf si Major Bob CONTRE et Roxanne abstention.", "VOTE_ABATTAGE oui : brigade a Cimetronelle (D074 b), primes (RK +3 au ch. 8)."),
   O('c', 'Partir (Brice parle a ta place)', {'rL': -2, 'BR': -1}, {'vote': 'leave', 'bv': 'C', 'gain': 'Brice parle (BV COMP +1)'},
     "Norman : 'Le champion s'abstient.'", "issue selon Major Bob seul.")],
  ['VOTE_ABATTAGE (D074, RK ch. 8, glissement ch. 13)'], 'variante sociale (zones).',
  "Matrice : D036 x D016 x option. Attendu : VOTE_ABATTAGE selon GAME_SYSTEMS 8.4.", delay='I', mem='Norman note le vote de Red dans le registre (replique au ch. 12).')

D('D070', 7, 'D', 'S', 'don', "Badge 5 : le message de Norman pour Flora",
  'PetalburgCity_Gym - CF_D070',
  "Norman, apres le combat : 'Dites a ma fille d'obeir. Moi, elle ne m'ecoute plus.'",
  [O('a', 'Porter le message', {'FL': -3, 'rL': 3}, {},
     "Flora : 'Il t'envoie, maintenant ?'", "ch. 13 : Flora obeit plus facilement."),
   O('b', 'Le garder pour soi', {'FL': 3, 'rL': -2}, {},
     "Flora ne saura jamais.", "ch. 13 : bascule plus facile.")],
  ['FL (ch. 13)'], 'casualties civils.', "a : FL-3 ; b : FL+3.", delay='L')

D('D071', 7, 'E', 'S', 'aveu', "Devon 3F : Pierre Rochard et son pere (W2)",
  'RustboroCity_DevonCorp_3F - CF_D071',
  "'Qu'y a-t-il dans le Coeur ?' - 'Des emplois.'",
  [O('a', "Montrer l'enregistrement de Leo", {'PR': 3, 'rC': -5}, {'set': ['PR_PREUVE']},
     "Pierre Rochard ecoute trois fois.", "ch. 12 : ACCUSE possible (PR>=55)."),
   O('b', 'Rester', {'PR': -2, 'rC': 2}, {},
     "M. Rochard : 'Merci de votre discretion.'", "ch. 12 : Pierre Rochard protege son pere sauf registre.")],
  ['STANCE_PR pere (ch. 12)', 'Sommet M3 (PRO)'], 'F2 (demission), Maitre ch. 14.', "a : PR_PREUVE ; b : rC+2.", delay='L')

# ---------------------------------------------------------------- CH. 8
D('D072', 8, 'E', 'M', 'arbitrage', "Institut Meteo occupe par Sarah",
  'Route119_WeatherInstitute_1F/2F - CF_D072 (jalon plafond 37, toutes issues)',
  "Sarah (Aqua) tient l'Institut et ses releves de tempete.",
  [O('a', 'Forcer (combats)', {'rA': -5, 'rL': 3}, {},
     "La Ligue saisit les donnees.", "Sarah hostile ; la tempete est 'un phenomene' pour la Ligue."),
   O('b', 'Negocier (rester, montrer Kosmo si obtenu)', {'rA': 3, 'rL': -3}, {'set': ['DOS_DONNEES_INSTITUT']},
     "Sarah montre les courbes : 'Ca monte apres chaque transfert.'", "D080 possible ; H3 apprise ; Sommet M1.")],
  ['D080', 'D102', 'Sommet M1'], 'indirect.', "Les deux : VAR_CF_CAP>=37. b : DOS_DONNEES_INSTITUT.", delay='I', mem="Sarah : 'Tu t'en souviendras quand le ciel craquera.'")

D('D073', 8, 'D', 'S', 'arbitrage', "R120 : l'Absol 'porte-malheur'",
  'Route120 - CF_D073',
  "La brigade traque un Absol venu annoncer la tempete.",
  [O('a', "Le capturer avant la brigade", {'rL': -2, 'rG': 1}, {'gain': 'Equipe (Absol)'},
     "La brigade repart bredouille.", "Absol dans l'equipe ; ch. 13 : il 'sent' le Pilier (replique)."),
   O('b', 'Laisser la brigade le chasser', {'rL': 2, 'rG': -1}, {'loss': 'Equipe'},
     "L'Absol s'enfuit vers le nord.", "rien.")],
  ['equipe', 'rL'], 'aucune.', "a : Absol recu.", delay='I')

D('D074', 8, 'E', 'M', 'arbitrage', "Mission de zone Z-04 : la canopee de Cimetronelle",
  'FortreeCity / Route119-120 - CF_D074',
  "Etourmi contre Heledelle et Tropius ; Koga veut les nuees comme appat pour son piege.",
  [O('a', "Avec Alizee : reconstruire les nids", {'rP': 3, 'rI': -2}, {'eco': ('Z04', 2)},
     "Les ponts rouvrent ; Koga peste.", "Z-04 RESTAURE ; Koga moins sur de son piege (D075 a plus facile)."),
   O('b', 'Laisser la brigade abattre', {'rL': 4, 'rA': -3}, {'eco': ('Z04', 3)},
     "Les nuees tombent.", "Z-04 ABATTU.", req=lambda s: has(s, 'VOTE_ABATTAGE'), reqtxt='VOTE_ABATTAGE oui'),
   O('c', 'Laisser Koga utiliser les nuees', {'rI': 3, 'rP': -2}, {'eco': ('Z04', 1)},
     "Les nuees tournent autour d'un appat.", "Z-04 MIXTE ; piege pret.")],
  ['E-ECO Z-04', 'D075', 'barrage du pont (leve en toutes issues)'], 'variante sociale.', "50 rencontres R119 par issue ; Tropius 1 % / 20 %.", delay='I', mem='Alizee ou Koga commente les ponts a chaque passage.')

D('D075', 8, 'E', 'L', 'arbitrage', "Le piege de Koga : la garde de Hoopa (R2b)",
  'FortreeCity (canopee) - CF_D075',
  "Le petit voleur est pris : c'est Hoopa Confine. Koga veut l'emmener ; Hoopa regarde Red.",
  [O('a', 'Le garder (combat contre Koga, ou montrer la page K. a Peter)', {'HO': 10, 'rI': -8, 'RK': 5}, {'custody': 'RED'},
     "Hoopa devient suiveur (setfollowernpc) ; la Rocket apprend ou il est.", "climax : Hoopa present si Red au relais ou confie (D118) ; ch. 10 : Rocket vise Red."),
   O('b', 'Le laisser a la Mission', {'rI': 8, 'HO': -8}, {'custody': 'MISSION'},
     "Hoopa en cage au camp de la Mission (Nenucrique).", "climax : present si Peter ou Koga au relais ; Sommet : PET peut voter LIBERER."),
   O('c', 'Ouvrir le piege', {'HO': 8, 'rL': -5, 'rI': -5}, {'custody': 'LIBRE'},
     "Hoopa fuit vers l'est, se retourne une fois.", "climax : il vient seul si HO>=70.")],
  ['climax (presence de Hoopa)', 'Sommet (PET, DOY)', 'ch. 10 assaut', 'suiveur (saillance)'], 'F2 (et F5 si HO bas).',
  "Save avant. a : VAR_CF_WORLD garde=1, suiveur actif, HO+10 ; b : garde=2 ; c : garde=3. Test de soft-lock : suiveur desactive en Plongee (script de carte).",
  delay='I', mem="Carnet : 'Il m'a regarde. Pas Koga. Moi.'")

D('D076', 8, 'D', 'S', 'presence', "La vision de Morgane (R120)",
  'Route120 - CF_D076',
  "Morgane voit 'un dragon qui ne choisit pas' ; Pierre Rochard attend Red plus loin.",
  [O('a', 'Rester jusqu au bout', {'PR': -2, 'rG': 1}, {'set': ['DOS_VISION', 'MORGANE_ALLIEE']},
     "'Le ciel juge. Il ne pardonne pas.'", "Sommet M1 (FERMER) ; ch. 13 : Morgane aux civils."),
   O('b', 'Rejoindre Pierre Rochard', {'PR': 2}, {'loss': 'piece et allie'},
     "Pierre Rochard : 'Vous etes venu.'", "rien.")],
  ['Sommet M1', 'climax (Morgane civils)'], 'climax civils.', "a : DOS_VISION, MORGANE_ALLIEE ; b : PR+2.", delay='C')

D('D077', 8, 'E', 'S', 'presence', "Embuscade de la R120 : le partenaire de duo",
  'Route120 - CF_D077 (Mega-Anneau et Scope remis dans les deux cas)',
  "Des sbires Rocket attaquent ; Pierre Rochard et Brice sont la.",
  [O('a', 'Pierre Rochard', {'PR': 4, 'BR': -2}, {},
     "Mega-Metalosse ; 'Le Mega-Anneau est a vous.'", "PR."),
   O('b', 'Brice', {'BR': 4, 'PR': -2}, {'bv': 'A'},
     "Brice voit les cages de primes : 'Ils les vendent au poids.'", "BV ACCUEILLIR +1.")],
  ['PR (allie)', 'BV'], 'climax allies.', "Les deux : ITEM_MEGA_RING et Scope recus. a : PR+4 ; b : BR+4, BVCOUNT.A+1.", delay='I')

D('D078', 8, 'D', 'S', 'aveu', "Jeannine suit Red en cachette",
  'FortreeCity - CF_D078',
  "Jeannine a desobei a Koga pour voir Red 'travailler'.",
  [O('a', 'La couvrir', {'rI': -2}, {'set': ['JEANNINE_ALLIEE'], 'gain': 'allie (Jeannine)'},
     "Elle promet une dette.", "ch. 10 : elle revele le double jeu de Koga (alternative a la page) ; ch. 13 : relais (allie)."),
   O('b', 'La designer a Koga', {'rI': 2}, {'loss': 'allie'},
     "Koga la renvoie a la Mission.", "rien.")],
  ['D095 (Koga)', 'climax relais'], 'climax relais.', "a : JEANNINE_ALLIEE ; b : rI+2.", delay='L')

D('D079', 8, 'E', 'M', 'don', "Badge 6 : un Pokemon pour la canopee",
  'FortreeCity_Gym - CF_D079 (E-REMOVE)',
  "Alizee demande des Pokemon Vol pour repeupler la canopee.",
  [O('a', 'Donner un Pokemon de son equipe (choix au menu)', {'rP': 3, 'rG': 1}, {'lose_mon': True, 'ecostep': 'Z04'},
     "Alizee le relache dans les nids.", "Z-04 +1 cran ; Alizee aux civils au ch. 13 (replique)."),
   O('b', 'Refuser', {'rP': -1}, {'gain': 'equipe gardee'},
     "Alizee comprend.", "rien.")],
  ['E-ECO Z-04', 'diaporama'], 'variante sociale.', "a : Pokemon retire (E-REMOVE) ; Z04 +1 cran. Prerequis : au moins 2 Pokemon (special ChoosePartyMon puis E-REMOVE).", delay='I', mem='Le Pokemon donne apparait dans les nids (PNJ objet) a chaque visite.')

D('D080', 8, 'D', 'S', 'aveu', "Montrer a Sarah ses propres donnees",
  'Route119 (pont) - CF_D080',
  "Sarah seule sur le pont, ses releves sous le bras.",
  [O('a', 'Montrer (Institut + etoiles de Kosmo)', {'rA': 2, 'rL': -2}, {'set': ['SARAH_DOUTE']},
     "'Si on coupe le cable... tout s'ouvre.'", "ch. 11 : Sarah doute en public (D102 a possible)."),
   O('b', 'Partir', {'rL': 1}, {'loss': 'Sarah reste loyale'},
     "Sarah range ses courbes.", "ch. 11 : la coupure est plus probable.")],
  ['D102', 'D103'], 'F5 (cable).', "Prerequis DOS_DONNEES_INSTITUT ou DOS_ETOILES. a : SARAH_DOUTE.",
  when=lambda s: has(s, 'DOS_DONNEES_INSTITUT') or has(s, 'DOS_ETOILES'), pre='DOS_DONNEES_INSTITUT ou DOS_ETOILES', delay='C')

D('D081', 8, 'E', 'S', 'combat', "Defi Indigo de Koga (refusable)",
  'FortreeCity - CF_D081 (FLAG_CF_REFUS_KOGA)',
  "Koga, apres le piege, propose un duel 'sans rancune'.",
  [O('a', 'Accepter et gagner', {'rI': 2, 'RK': -1, 'PE': -1}, {'set': ['KOGA_AVEU']},
     "Koga : 'Au relais, je te dirai qui j'ai paye.'", "ch. 10 : Koga avoue de lui-meme (REL_KOGA_PETER DEMASQUE sans la page)."),
   O('b', 'Accepter et perdre', {'rI': 1, 'HO': -1}, {'money': -500},
     "'Tu manques de poison.'", "rien."),
   O('c', 'Refuser', {'rI': -2, 'HO': 1}, {},
     "Koga s'incline, froid.", "refus definitif.")],
  ['D095', 'REL_KOGA_PETER'], 'epilogue Koga (Conseil 4).', "a : KOGA_AVEU.", delay='C')

# ---------------------------------------------------------------- CH. 9
D('D082', 9, 'E', 'L', 'presence', "La nuit du marche : Olga, raid Aqua ou liberation (exclusif)",
  'LilycoveCity (port, entrepot) / AquaHideout_1F - CF_D082 (jalon plafond 42 a l aube, toutes issues ; FLAG_CF_PLANQUE_RESOLUE)',
  "La meme nuit : coup de filet d'Olga au marche noir, raid de la Ligue sur la planque Aqua, liberation des arrivants par Ondine et Aqua.",
  [O('a', "Coup de filet avec Olga", {'RK': -8, 'rI': 5, 'rA': -3}, {'set': ['OLGA_LOKHLASS', 'OBJ_LETTRE_FERRAND']},
     "Les Lokhlass d'Olga dans une caisse ; Ferrand ligote dans l'entrepot.", "Olga accepte l'aide de Hoenn ; Lambda demasquable ; le raid Aqua echoue sans Red (plan du cable inconnu)."),
   O('b', 'Raid sur la planque Aqua (Ligue)', {'rL': 5, 'rA': -8, 'RK': 5}, {'set': ['DOS_PLAN_CABLE']},
     "Le plan du cable sur la table d'Arthur.", "D102 : negociation possible ; les Lokhlass partent chez la Rocket (Olga sans eux)."),
   O('c', 'Liberer les arrivants avec Ondine et Aqua', {'rA': 8, 'rL': -8, 'RK': -3}, {'set': ['REL_ONDINE_ARTHUR'], 'eco': ('Z04', 0)},
     "La reserve du Safari s'ouvre ; les arrivants filent dans les bois.", "Z-04 ENVAHI ; alliance Ondine-Arthur ; Lokhlass perdus.")],
  ['brief B (Olga avec/sans Lokhlass)', 'D095', 'D102', 'Z-04', 'RK', 'F4 retour par la mer (Lokhlass)'], 'F4 (canal de retour), RK, variante sociale.',
  "Save avant. Chaque issue : FLAG_CF_PLANQUE_RESOLUE, VAR_CF_CAP>=42, R124 ouverte apres Mont Memoria. a : OLGA_LOKHLASS ; b : DOS_PLAN_CABLE ; c : Z04=0.",
  delay='I', mem="Brice : 'Trois portes. On en a ouvert une.'")

D('D083', 9, 'D', 'S', 'presence', "Le toit du Grand Magasin (W6 Blue/Giovanni)",
  'LilycoveCity_DepartmentStoreRooftop - CF_D083',
  "Blue et Giovanni parlent de Jadielle, de l'heritage, d'une defaite contre un gamin.",
  [O('a', 'Rester', {'BL': 5, 'GI': -2}, {},
     "Blue, apres : 'Tu as tout entendu. Bon.'", "STANCE_BLUE LIBRE si BL>=60 au ch. 13."),
   O('b', 'Partir', {'GI': 3, 'BL': -2}, {},
     "Giovanni, plus tard : 'Tu ne regardes pas les faiblesses. Bien.'", "GI (temoignage).")],
  ['STANCE_BLUE', 'GI (D114)'], 'variante Blue.', "a : BL+5 ; b : GI+3.", delay='C')

D('D084', 9, 'E', 'S', 'combat', "Blue 2 sur le toit (refusable)",
  'LilycoveCity_DepartmentStoreRooftop - CF_D084 (FLAG_CF_REFUS_BLUE2)',
  "Blue : 'Maintenant que tu sais. Bats-toi.'",
  [O('a', 'Accepter et gagner', {'BL': 2, 'rC': -1}, {},
     "Blue jette un import dans sa boite.", "Blue T4 : un Pokemon de Bourg Palette remplace un import."),
   O('b', 'Accepter et perdre', {'BL': 4, 'rI': -1}, {'money': -800},
     "Blue rit franchement, pour une fois.", "Blue vient a la veillee si BL>=55."),
   O('c', 'Refuser', {'BL': -3, 'rG': 1}, {},
     "'Tu as change.' Il part.", "refus definitif.")],
  ['brief B (Blue T4)', 'veillee (BL)'], 'variante Blue.', "a/b/c : slot ; c : refus pose.", delay='C')

D('D085', 9, 'D', 'S', 'arbitrage', "Concours de Nenucrique : avec quel Pokemon",
  'LilycoveCity_ContestLobby - CF_D085 (E-NATIVE)',
  "Nina inscrit Red ; Juan est au jury ; Marc observe.",
  [O('a', 'Avec un arrivant', {'rA': 2, 'rG': -2}, {},
     "Marc applaudit ; un Sage grimace.", "Marc vote avec son ami (Pierre Rochard) au Sommet."),
   O('b', 'Avec un natif', {'rG': 2, 'rA': -1}, {},
     "Juan note quelque chose.", "Marc penche vers les Sages.")],
  ['Sommet (Marc via DOY/PRO)', 'rG'], 'indirect.', "Special E-NATIVE sur l'espece inscrite ; slot 1/2.", delay='C', verdict=('F', 'Marc ne vote pas : les deltas rA/rG sont marginaux (revue stricte)'))

D('D086', 9, 'E', 'M', 'arbitrage', "Mont Memoria : proteger le rite ou poursuivre Lance (Rocket)",
  'MtPyre_Summit - CF_D086 (jalon plafond 44, toutes issues ; DOS_INSCRIPTION toujours)',
  "Lance (Rocket) profane le rite et copie l'inscription du Sceau.",
  [O('a', 'Proteger le rite', {'rG': 5, 'RK': 2}, {'set': ['DOS_ARTICLE_CHEN', 'RITE_PROTEGE']},
     "Il fuit en laissant tomber une photocopie annotee : l'article de Chen.", "Agatha pardonne plus tard ; la Rocket connait la loi H4 (ch. 10 plus dur)."),
   O('b', 'Poursuivre Lance (Rocket)', {'RK': -5, 'rG': -5}, {'set': ['COPIE_REPRISE']},
     "Red reprend la copie ; le rite est rompu, Agatha se dresse (combat).", "Agatha rancuniere ; l'assaut du ch. 10 vise le mauvais etage (relais tenu plus facilement).")],
  ['D087', 'climax (RK)', 'Agatha (epilogue)', 'STANCE_CHEN'], 'fin cachee (article), climax.',
  "Les deux : DOS_INSCRIPTION, VAR_CF_CAP>=44. a : DOS_ARTICLE_CHEN ; b : combat Agatha, COPIE_REPRISE.", delay='I', mem="Agatha : 'Le rite. Je n'oublie pas qui l'a garde.' / 'qui l'a laisse.'")

D('D087', 9, 'D', 'S', 'aveu', "W7 : montrer l'article a Chen devant Agatha",
  'MtPyre_Summit - CF_D087',
  "'Ton article, Chen. Il y a cinquante ans.'",
  [O('a', "Montrer l'article annote", {'rI': -2, 'rG': 2}, {'set': ['CHEN_CONFRONTE']},
     "Chen palit : 'Je ne savais pas qui lirait.'", "ch. 12 : Chen AVOUE si on le designe."),
   O('b', 'Rester', {'rI': 1, 'rG': -1}, {},
     "Chen nie ; Agatha sourit mal.", "ch. 12 : Agatha revele l'article en seance ; Chen NIE.")],
  ['D112 (Chen)', 'fin cachee'], 'fin cachee.', "Prerequis DOS_ARTICLE_CHEN. a : CHEN_CONFRONTE.",
  when=lambda s: has(s, 'DOS_ARTICLE_CHEN'), pre='DOS_ARTICLE_CHEN', delay='C')

D('D088', 9, 'E', 'M', 'arbitrage', "Le plan de Fuji",
  'MtPyre_Summit (sortie) - CF_D088',
  "Fuji veut liberer Hoopa 'a tout prix', quitte a briser la Fiole.",
  [O('a', "Lui demander d'attendre Hoopa", {'HO': 3, 'rI': -2}, {'set': ['FUJI_ATTEND']},
     "Fuji : 'J'attendrai. Pas eternellement.'", "climax : Fuji ne brise que si HO<40."),
   O('b', 'Refuser son plan', {'rI': 2, 'HO': -2}, {},
     "Fuji part seul.", "climax : Fuji au relais = BRISER.")],
  ['climax (intention de Fuji)'], 'F5/F2.', "a : FUJI_ATTEND.", delay='L', mem="Fuji : 'J'attendrai.' (Carnet, si a)")

D('D089', 9, 'D', 'S', 'presence', "Auguste rejoint-il Fuji ?",
  'MtPyre_Exterior - CF_D089',
  "Auguste hesite entre Max et Fuji.",
  [O('a', 'Designer Fuji (il parle)', {'rM': -5, 'rG': 1}, {'set': ['REL_AUGUSTE_FUJI']},
     "Auguste suit Fuji.", "Magma perd son geologue (Sommet MAX) ; climax : Fuji competent au relais."),
   O('b', 'Rester', {'rM': 2}, {'loss': 'Fuji seul'},
     "Auguste rentre a Vermilava.", "rien.")],
  ['climax (Fuji)', 'Sommet MAX'], 'climax relais.', "Prerequis AUGUSTE_DOUTE. a : REL_AUGUSTE_FUJI.",
  when=lambda s: has(s, 'AUGUSTE_DOUTE'), pre='AUGUSTE_DOUTE (D062 a)', delay='L')

D('D090', 9, 'E', 'S', 'presence', "W8 : Ondine et Aldo sur le port",
  'LilycoveCity_Harbor - CF_D090',
  "Ondine a ouvert un filet ; Aldo porte les caisses vides des pecheurs.",
  [O('a', 'Designer Ondine', {'rA': 3, 'rP': -3}, {'set': ['REL_ONDINE_ARTHUR']},
     "Ondine : 'Je n'ai pas fini.'", "ch. 11 : Ondine du cote Aqua."),
   O('b', 'Designer Aldo', {'rP': 3, 'rA': -2}, {'set': ['ONDINE_MISSION']},
     "Ondine regarde les caisses ; elle se tait.", "ch. 11 : Ondine du cote Mission.")],
  ['ch. 11 (camp d Ondine, D104)', 'brief B (Ondine)'], 'indirect.', "a : REL_ONDINE_ARTHUR ; b : ONDINE_MISSION (prioritaire sur D082 c).", delay='C')

D('D091', 9, 'D', 'S', 'arbitrage', "Damien : fermer les yeux sur les petits trafics",
  'LilycoveCity - CF_D091',
  "Damien offre les noms des acheteurs de la Rocket si Red ignore ses combines.",
  [O('a', 'Accepter', {'RK': -3, 'rL': -2}, {'set': ['DAMIEN_INDIC']},
     "Damien siffle trois noms.", "ch. 10 : l'assaut a moins de soutien local."),
   O('b', 'Le designer a la brigade', {'rL': 3, 'RK': 1}, {},
     "Damien passe une nuit au poste.", "ch. 14 : Damien froid a la Ligue.")],
  ['RK', 'ch. 14 Damien'], 'variante Rocket.', "a : RK-3 ; b : rL+3.", delay='C')

D('D092', 9, 'E', 'S', 'aveu', "Montrer l'inscription a Marc",
  'LilycoveCity_ContestHall - CF_D092',
  "Marc doit choisir entre les Sages et son ami Pierre Rochard.",
  [O('a', 'Montrer', {'rG': 3, 'rC': -2}, {'set': ['MARC_SAGES']},
     "Marc lit trois fois : 'Les Sages avaient raison.'", "Pierre Rochard peut passer SCEAU (avec PR>=55)."),
   O('b', 'Garder', {'rG': -1, 'rC': 1}, {},
     "Marc reste avec son ami.", "rien.")],
  ['STANCE_PR (axe B)', 'Sommet PRO'], 'F1 via Pierre Rochard.', "a : MARC_SAGES.", delay='C')

D('D093', 9, 'D', 'S', 'aveu', "Safari : le garde qui revend la reserve",
  'SafariZone_South - CF_D093',
  "Un garde du Rempart revend des arrivants saisis.",
  [O('a', 'Le designer', {'RK': -3, 'rL': -3}, {},
     "Scandale ; la reserve ferme deux jours.", "Sommet : NOR plus faible (rL)."),
   O('b', 'Acheter un arrivant (1 000 P)', {'RK': 2, 'rA': 1}, {'money': -1000, 'gain': 'Equipe'},
     "Le garde empoche.", "le trafic continue.")],
  ['RK', 'rL'], 'variante Rocket.', "a : RK-3 ; b : Pokemon, -1000 P.", delay='I')

# ---------------------------------------------------------------- CH. 10
D('D094', 10, 'E', 'M', 'presence', "Assaut du relais : le partenaire de duo",
  'MossdeepCity_SpaceCenter_1F - CF_D094 (jalon plafond 49 apres l assaut, toutes issues)',
  "Ariane attaque ; deux combats en duo. Partenaires selon les relations.",
  [O('a', 'Brice', {'BR': 3, 'PE': -1}, {'set': ['DUO_BRICE']}, "Brice apprend le relais.", "climax : Brice competent au relais."),
   O('b', 'Peter', {'PE': 3, 'rC': -2}, {'set': ['DUO_PETER']}, "Peter casse une porte.", "climax : Peter competent au relais (deja)."),
   O('c', 'Pierre Rochard', {'PR': 3, 'BR': -1}, {'set': ['DUO_PR']}, "Pierre Rochard ouvre le coeur.", "climax : PR au relais.",
     req=lambda s: s['v']['PR'] >= 50, reqtxt='PR>=50')],
  ['climax (competence relais)'], 'climax.', "Les trois : VAR_CF_CAP>=49. Slot 1/2/3.", delay='L', mem="Le partenaire : 'Au relais, je connais le chemin.'")

D('D095', 10, 'E', 'M', 'aveu', "Le faux Giovanni (Lambda)",
  'MossdeepCity_SpaceCenter_2F - CF_D095',
  "'Giovanni' commande l'assaut ; la Ligue y croit.",
  [O('a', 'Montrer une preuve (photo, horaire vendu, lettre de Ferrand)', {'RK': -5, 'GI': 5, 'rL': -2}, {'set': ['LAMBDA_DEMASQUE']},
     "Lambda arrache son masque ; le vrai Giovanni desavoue.", "GI : temoignage possible ; Kanto n'est pas accuse.",
     req=lambda s: has(s, 'DOS_LAMBDA') or has(s, 'DOS_HORAIRE_VENDU') or has(s, 'OBJ_LETTRE_FERRAND'), reqtxt='une des 3 pieces'),
   O('b', 'Designer Koga (il connait les visages)', {'RK': -3, 'rI': -3}, {'set': ['LAMBDA_DEMASQUE'], 'val': {'KOGA': 'DEMASQUE'}},
     "Koga : 'Je le connais. Je les ai payes.'", "Koga DEMASQUE (W10)."),
   O('c', 'Rester', {'rI': -5, 'GI': -5, 'rL': 2}, {},
     "La Ligue accuse Kanto ; Giovanni desavoue plus tard, seul.", "FK plus dur ; GI.")],
  ['D114', 'REL_KOGA_PETER', 'Sommet M3'], 'R4.', "a : LAMBDA_DEMASQUE ; b : KOGA=DEMASQUE ; c : rI-5.", delay='I', mem="Carnet : 'Le masque. Ou pas.'")

D('D096', 10, 'D', 'S', 'presence', "Levy et Tatia entendent la 'voix'",
  'MossdeepCity_Gym (apres badge 7) - CF_D096',
  "Les jumeaux captent quelque chose dans le relais.",
  [O('a', 'Rester avec eux', {'rP': -2, 'HO': 1}, {'set': ['DOS_VOIX_RELAIS']},
     "'Il a faim. Il a peur. Il est enferme dans une bouteille.'", "Sommet M1 (LIBERER) ; D101."),
   O('b', 'Aider a evacuer le quai', {'rP': 3}, {'loss': 'piece'},
     "Le quai est vide avant la deuxieme vague.", "rien.")],
  ['Sommet M1', 'D101'], 'indirect.', "a : DOS_VOIX_RELAIS ; b : rP+3.", delay='C')

D('D097', 10, 'E', 'S', 'aveu', "Le registre du coffre (Cileo)",
  'MossdeepCity_SpaceCenter_2F - CF_D097 (DOS_REGISTRE toujours)',
  "Cileo a copie le registre : la Fiole vient du coffre de Sylphe.",
  [O('a', 'Le garder pour le Sommet', {'rC': 1, 'PR': -1}, {},
     "Cileo : 'D'accord. Devant tout le monde.'", "Sommet : piece a montrer (PARTAGEE)."),
   O('b', 'Le donner tout de suite a Pierre Rochard', {'PR': 3, 'rC': -5}, {'set': ['PR_PREUVE']},
     "Pierre Rochard serre le papier.", "ACCUSE plus probable.")],
  ['Sommet M3', 'STANCE_PR'], 'F2.', "Les deux : DOS_REGISTRE.", delay='C')

D('D098', 10, 'D', 'S', 'don', "La lettre d'Amos",
  'MossdeepCity - CF_D098',
  "Amos propose 'un retour digne de Giovanni, sans la Fiole'.",
  [O('a', 'La donner a Giovanni', {'GI': 3, 'RK': -3, 'rI': -2}, {},
     "Giovanni dechire la lettre.", "Amos discredite ; ch. 13 : pas de seconde equipe Rocket."),
   O('b', 'La donner a Peter', {'rI': 3, 'GI': -3}, {},
     "Peter : 'Enfin un nom.'", "rien.")],
  ['RK (climax)', 'GI'], 'variante Rocket.', "a : GI+3, RK-3 ; b : rI+3.", delay='C')

D('D099', 10, 'E', 'M', 'arbitrage', "Levy et Tatia veulent sonder Hoopa",
  'MossdeepCity_Gym - CF_D099',
  "'Laisse-nous l'entendre. Il a peur, ou il nous fera confiance.'",
  [O('a', 'Accepter (ils le soignent : voie de reparation)', {'HO': 8, 'rL': -2, 'rC': -2}, {'set': ['HOOPA_REPARE']},
     "Hoopa tremble, puis se calme (si HO>=40) ou fuit (sinon : HO-5 applique a la place).", "HO."),
   O('b', 'Refuser', {'rG': 1, 'HO': -1}, {},
     "Les jumeaux s'inclinent.", "rien.")],
  ['HO'], 'F2.', "Prerequis garde = RED. Si HO<40 : delta reel HO-5 (annonce par la replique).",
  when=lambda s: s['val'].get('custody') == 'RED', pre='Hoopa garde par Red', delay='L')

D('D100', 10, 'D', 'S', 'combat', "Defi Indigo de Peter (refusable)",
  'MossdeepCity - CF_D100 (FLAG_CF_REFUS_PETER)',
  "Peter : 'Montre-moi ce que Hoenn t'a appris.'",
  [O('a', 'Accepter et gagner', {'PE': 3, 'rG': -1}, {}, "Peter salue.", "PE (veillee)."),
   O('b', 'Accepter et perdre', {'PE': 1, 'BR': -1}, {'money': -1000}, "'Encore trop tendre.'", "rien."),
   O('c', 'Refuser', {'PE': -3, 'rG': 2}, {}, "'Tu ne sers pas Kanto.'", "refus definitif.")],
  ['PE (veillee, STANCE_PETER)'], 'climax.', "slot 1/2/3.", delay='C')

D('D101', 10, 'E', 'S', 'aveu', "Maison de Pierre Rochard : faut-il garder le relais ?",
  'MossdeepCity_StevensHouse - CF_D101 (CS Plongee remise dans les deux cas)',
  "Pierre Rochard : 'Hoenn peut-il couper ce qui le nourrit ?'",
  [O('a', 'Rester (accord)', {'rC': 3, 'rG': -2}, {'val': {'PR_B': 'CTL'}},
     "'Alors, une charte.'", "PRO vote CHARTE au Sommet."),
   O('b', 'Montrer la voix du relais ou le battement', {'rC': -3, 'PR': 2}, {'prb': True},
     "Il reste longtemps a la fenetre.", "PRO : LIBERER si DOS_VOIX_RELAIS et PR>=60 ; SCEAU si MARC_SAGES.",
     req=lambda s: has(s, 'DOS_VOIX_RELAIS') or has(s, 'DOS_BATTEMENT'), reqtxt='DOS_VOIX_RELAIS ou DOS_BATTEMENT')],
  ['Sommet PRO', 'climax (intention de PR)'], 'F3/F1.', "Les deux : FLAG_RECEIVED_HM_DIVE. a : PR_B=CTL ; b : PR_B selon pieces.", delay='C')

# ---------------------------------------------------------------- CH. 11
D('D102', 11, 'E', 'L', 'arbitrage', "Le cable de Passerelle : negocier, combattre, laisser couper",
  'SeafloorCavern_Room4-9 (Caverne Fondmer ; bible : "Grotte Trefonds") - CF_D102 (jalon plafond 51, toutes issues ; FLAG_CF_FONDMER_DONE)',
  "Arthur et Sarah vont couper le cable sous la mer ; Marin et Ondine (ou pas) defendent.",
  [O('a', 'Negocier (Sarah doute, plan du cable, ou message de l infirmiere)', {'rA': 3, 'rC': 2, 'PA': -3, 'rL': -2}, {'val': {'ARTHUR': 'NEGOCIE'}, 'eco': ('Z05', 2)},
     "Arthur pose son couteau : 'On le deroute. Loin des Wailmer.'", "Z-05 RESTAURE ; ART vote LIBERER ; Aqua aux civils.",
     req=lambda s: has(s, 'SARAH_DOUTE') or has(s, 'DOS_PLAN_CABLE') or ch(s, 'D105') == 1, reqtxt='SARAH_DOUTE, DOS_PLAN_CABLE ou D105 a'),
   O('b', "Combattre Arthur", {'rA': -5, 'rL': 3, 'PA': 3}, {'eco': ('Z05', 1)},
     "Arthur tombe ; une equipe dissidente coupe une ligne secondaire.", "Z-05 MIXTE ; Aqua discreditee."),
   O('c', 'Laisser couper', {'rA': 5, 'rC': -8, 'PA': 8}, {'set': ['CABLE_COUPE'], 'val': {'ARTHUR': 'COUPE'}, 'eco': ('Z05', 0)},
     "Le noir a Algatia ; la mer s'ouvre d'anneaux.", "Z-05 ENVAHI ; F5 possible meme sans Fuji ; F3 compromise.")],
  ['Sommet ART', 'PA', 'climax (F5 si relais perdu)', 'E-ECO Z-05'], 'F5 / F3.',
  "Save avant. Chaque issue : FLAG_CF_FONDMER_DONE (prerequis du Sommet), VAR_CF_CAP>=51. c : CABLE_COUPE, PA+8.",
  delay='I', mem="Carnet : 'Le noir. Puis des anneaux partout.' (c)")

D('D103', 11, 'D', 'S', 'don', "Une porte de sortie pour Sarah",
  'SeafloorCavern_Room9 - CF_D103',
  "Sarah, apres le cable, ne sait plus ou aller.",
  [O('a', 'Lui donner la carte de recensement de Brice (un travail)', {'rA': -2, 'BR': 2}, {'set': ['SARAH_TEMOIN']},
     "'Compter. Ca, je sais faire.'", "Sommet M1 : Sarah temoigne (ART ne peut pas voter BRISER)."),
   O('b', 'Rester', {'rA': 2}, {'loss': 'temoin'},
     "Elle rejoint Arthur.", "rien.")],
  ['Sommet'], 'indirect.', "Prerequis SARAH_DOUTE. a : SARAH_TEMOIN.", when=lambda s: has(s, 'SARAH_DOUTE'), pre='SARAH_DOUTE', delay='C')

D('D104', 11, 'E', 'S', 'combat', "Ondine, camp adverse (refusable)",
  'SeafloorCavern_Room1 - CF_D104 (FLAG_CF_REFUS_ONDINE)',
  "Si Ondine est du cote Aqua, elle barre la route ; sinon elle escorte.",
  [O('a', 'Accepter et gagner', {'rI': 2, 'rA': -3}, {'set': ['ONDINE_MISSION']}, "Ondine : 'Bon. Je reviens.'", "alliance rompue."),
   O('b', 'Accepter et perdre', {'rA': 1, 'BR': -1}, {'money': -800}, "Elle passe devant.", "alliance tient."),
   O('c', 'Refuser (passer a cote)', {'rA': 2, 'rI': -2}, {}, "Elle laisse passer.", "alliance tient ; refus definitif.")],
  ['brief B (Ondine Aqua/Mission)', 'Sommet (Mission)'], 'indirect.', "Prerequis REL_ONDINE_ARTHUR sans ONDINE_MISSION.",
  when=lambda s: has(s, 'REL_ONDINE_ARTHUR') and not has(s, 'ONDINE_MISSION'), pre='Ondine cote Aqua', delay='I')

D('D105', 11, 'D', 'S', 'presence', "Le soigneur de Fondmer : Aqua ou la brigade",
  'SeafloorCavern_Entrance - CF_D105',
  "Une infirmiere d'Aqua soigne a l'entree ; Flora arrive une salle plus tard.",
  [O('a', "Accepter l'infirmiere (elle confie un message pour Arthur)", {'rA': 2, 'FL': -1}, {},
     "'Dites-lui que Sarah vit.'", "D102 a disponible."),
   O('b', 'Attendre Flora', {'FL': 2, 'rA': -1}, {},
     "Flora soigne en silence.", "FL (ch. 13).")],
  ['D102', 'FL'], 'indirect.', "Les deux soignent (soin a <=2 cartes). a : cle de negociation.", delay='I')

D('D106', 11, 'E', 'S', 'arbitrage', "Le Capitaine Marin demande un temoignage",
  'SlateportCity_SternsShipyard_1F (retour) / Route128 - CF_D106',
  "Marin veut que Red defende les droits du Consortium sur le cable au Sommet.",
  [O('a', 'Promettre', {'rC': 3, 'rA': -2}, {}, "Marin : 'Je compte sur vous.'", "Sommet : COM lit rC plus haut."),
   O('b', 'Refuser', {'rC': -2, 'rP': 2}, {}, "Marin soupire.", "rien.")],
  ['Sommet (rC)'], 'F3.', "a : rC+3.", delay='C', verdict=('F', 'delta rC marginal, doublon fonctionnel de D011/D029 (revue stricte)'))

# ---------------------------------------------------------------- CH. 12
D('D107', 12, 'E', 'M', 'aveu', "La phrase publique de Red : au Sommet ou jamais",
  'SootopolisCity_Gym_1F (apres badge 8) - CF_D107',
  "Juan : 'Au Sommet, voulez-vous parler ? Une fois. Ecrit.'",
  [O('a', 'Ecrire au Sommet', {'BR': -3}, {'N': 3, 'phrase': True, 'gain': 'une voix basculee (M3)'},
     "La phrase s'adapte : Dossier complet, Hoopa, ou 'Je pars apprendre a perdre'.", "Sommet : +1 voix basculee sur la motion 3 ; epilogue sans phrase (Carnet)."),
   O('b', "Garder la phrase pour l'epilogue", {'BR': 2}, {'loss': 'voix supplementaire'},
     "Juan hoche la tete.", "epilogue : 'Je pars apprendre a perdre.'")],
  ['Sommet M3', 'epilogue'], 'epilogue (phrase).', "a : N=3, bascule M3 ; b : BR+2.", delay='C', mem="Juan : 'Une fois. Choisissez bien.'")

D('D108', 12, 'E', 'M', 'arbitrage', "Sommet, motion 1 (le reseau) : l'option defendue",
  'SootopolisCity (place) - CF_D108 (gestes : montrer 1 piece + designer 1 votant)',
  "FERMER (sceller) / CHARTE (controle) / LIBERER (Hoopa reuni).",
  [O('a', 'Defendre FERMER', {'rG': 2, 'rC': -2}, {'defend': (1, 1)}, "", "voir GAME_SYSTEMS 9"),
   O('b', 'Defendre CHARTE', {'rC': 2, 'rG': -2}, {'defend': (1, 2)}, "", ""),
   O('c', "Montrer Hoopa a l'assemblee (appel nominal, au lieu de defendre une option)", {'HO': 3, 'rL': -3}, {'appel': True}, "", "")],
  ['resultat M1 (PA a ch. 13, intentions au climax)', 'epilogue'], 'F1/F2/F3 (PA).',
  "Matrice de vote (GAME_SYSTEMS 9.5) ; VAR_CF_SUMMIT : defendue M1 bits 0-1, resultat bits 6-7.", delay='I', mem="Brice traduit : 'Red defend ceci. Moi, je vote a moi.'")

D('D109', 12, 'E', 'M', 'arbitrage', "Sommet, motion 2 (les arrivants) : l'option defendue",
  'SootopolisCity (place) - CF_D109',
  "REMPART (renvoyer) / INTEGRATION (sanctuaires) / MARCHE (exploiter).",
  [O('a', 'Defendre REMPART', {'rL': 2, 'rA': -2}, {'defend': (2, 1)}, "", ""),
   O('b', 'Defendre INTEGRATION', {'rA': 2, 'rL': -2}, {'defend': (2, 2)}, "", ""),
   O('c', 'Defendre MARCHE', {'rC': 2, 'rP': -2}, {'defend': (2, 3)}, "", "")],
  ['variante sociale', 'glissement des zones ch. 13'], 'variante sociale.', "VAR_CF_SUMMIT bits 2-3 / 8-9.", delay='L', mem='idem D108 (le registre du Sommet est relu a la veillee).')

D('D110', 12, 'E', 'M', 'aveu', "Sommet, motion 3 (qui paie) : l'option defendue",
  'SootopolisCity (place) - CF_D110',
  "KANTO et Sylphe / HOENN et Devon / PARTAGEE (la chaine, Red compris).",
  [O('a', 'Defendre KANTO', {'rL': 2, 'rI': -3}, {'defend': (3, 1)}, "", ""),
   O('b', 'Defendre HOENN', {'rI': 2, 'rC': -3}, {'defend': (3, 2)}, "", ""),
   O('c', 'Defendre PARTAGEE', {'rG': 2, 'rC': -2}, {'defend': (3, 3)}, "", "")],
  ['FK', 'STANCE_PETER (ASSUME)', 'Maitre ch. 14', 'epilogue'], 'FK, variantes de personnages.', "VAR_CF_SUMMIT bits 4-5 / 10-11.", delay='L', mem="idem D108 ; le resultat est affiche sur la place jusqu'au ch. 14.")

D('D111', 12, 'E', 'S', 'combat', "Brice veut un duel avant de voter (refusable)",
  'SootopolisCity - CF_D111 (FLAG_CF_REFUS_BRICE4)',
  "'Je vote a moi. Mais je veux savoir si tu m'entends.'",
  [O('a', 'Accepter et gagner', {'BR': 2, 'rP': -1}, {'set': ['BRICE_DEFERE']}, "Brice : 'D'accord. Sur la motion 3, je te suis.'", "BRI vote l'option defendue de M3."),
   O('b', 'Accepter et perdre', {'BR': 3, 'rI': -1}, {'set': ['BRICE_PARLE']}, "Brice parlera le premier.", "COM suit le vote de Brice sur M2."),
   O('c', 'Refuser', {'BR': -3, 'rG': 1}, {}, "'Alors je vote sans ton avis.'", "traduction seche (comme BR<50).")],
  ['Sommet (BRI, COM)'], 'variante sociale.', "slot 1/2/3 ; tester M2/M3 avec et sans.", delay='I')

D('D112', 12, 'D', 'S', 'presence', "R4 en seance : designer Chen",
  'SootopolisCity (place) - CF_D112',
  "Agatha leve la photocopie ; tous regardent Chen.",
  [O('a', 'Designer Chen (il parle)', {'rI': -3, 'rG': 2}, {'chen': True},
     "AVOUE s'il a ete confronte (D087 a), sinon il nie mal.", "STANCE_CHEN ; fin cachee ; REL_CHEN_SEKO."),
   O('b', 'Rester (le proteger)', {'rI': 2, 'rG': -2}, {'val': {'CHEN': 'NIE'}},
     "Agatha lit l'article elle-meme.", "Chen NIE.")],
  ['fin cachee', 'epilogue Chen-Seko'], 'fin cachee.', "a : CHEN=AVOUE si CHEN_CONFRONTE, sinon NIE.", delay='L')

D('D113', 12, 'E', 'M', 'aveu', "Le President de Sylphe : confession privee ou chute publique",
  'SootopolisCity (place) - CF_D113',
  "Le registre prouve que la Fiole a dormi dans le coffre de Sylphe.",
  [O('a', 'Lui montrer en prive (il confesse)', {'rC': -3, 'rI': 2}, {'val': {'SYLPHE': 'CONF'}},
     "Il parle lui-meme : 'Je l'ai cachee. J'ai cru la vendre.'", "R4 source 2 ; F3 garde un partenaire credible."),
   O('b', 'Le montrer en seance (chute)', {'rC': -8, 'rI': 3, 'rP': 2}, {'val': {'SYLPHE': 'CHUTE'}},
     "Le President quitte la salle sous les huees.", "R4 source 2 ; F3 tres difficile (rC).")],
  ['R4 (sources)', 'Sommet ROC/M3', 'F3'], 'F3.', "Les deux comptent comme source 2. a/b : STANCE_SYLPHE.", delay='I', mem="Le President, au ch. 14 (lettre) : 'Vous m'avez laisse parler.' / 'Vous m'avez juge.'")

D('D114', 12, 'D', 'S', 'presence', "Le temoignage de Giovanni",
  'SootopolisCity (place) - CF_D114',
  "Giovanni est dans le public, sans Persian.",
  [O('a', 'Le designer', {'RK': -5, 'rI': -3}, {'set': ['GIO_TEMOIN']},
     "'J'ai ordonne le vol. Pas ce qu'ils en ont fait.' Il part.", "R4 source 2 bis ; dernier duel (postgame) d'office."),
   O('b', 'Rester', {'GI': -2, 'rI': 1}, {},
     "Il part sans un mot.", "rien.")],
  ['R4', 'D127'], 'variante Rocket.', "Prerequis GI>=55 et LAMBDA_DEMASQUE.",
  when=lambda s: s['v']['GI'] >= 55 and has(s, 'LAMBDA_DEMASQUE'), pre='GI>=55 et LAMBDA_DEMASQUE', delay='I')

D('D115', 12, 'D', 'S', 'presence', "L'interruption : vers qui courir",
  'SootopolisCity - CF_D115',
  "La tempete d'anneaux eclate ; la Rocket attaque Algatia ; le ciel gronde.",
  [O('a', 'Vers les civils de la place', {'rP': 3, 'rG': -1}, {'set': ['CIVILS_PREPARES']}, "Red ouvre un passage.", "climax : civils +1 competence (n'importe quel allie)."),
   O('b', 'Vers la Doyenne et les Sages', {'rG': 3, 'rP': -1}, {'set': ['RITE_PREPARE']}, "La Doyenne : 'Le rite. Maintenant.'", "climax : RITE avec rG>=40 au lieu de 45.")],
  ['climax'], 'F1 / casualties.', "a : CIVILS_PREPARES ; b : RITE_PREPARE.", delay='C')

# ---------------------------------------------------------------- CH. 13
D('D116', 13, 'E', 'L', 'presence', "L'affectation : ou va Red, qui tient le reste",
  'MossdeepCity / SkyPillar / SootopolisCity - CF_D116 (veillee ; soin force)',
  "Chaque allie dit ce qu'il tient ; Red va en un lieu et designe un allie pour chacun des deux autres.",
  [O('a', 'Red au relais', {'rC': 2, 'rG': -2}, {'loc': 'R'}, "", ""),
   O('b', 'Red au Pilier', {'rG': 3, 'rC': -2}, {'loc': 'P'}, "", ""),
   O('c', 'Red aux civils', {'rP': 3, 'RK': 3}, {'loc': 'C'}, "", "")],
  ['resultat de la Fiole (GAME_SYSTEMS 10)', 'variante Rocket', 'casualties'], 'toutes les fins.',
  "Table d'affectation x etats (GAME_SYSTEMS 10.6). VAR_CF_CLIMAX.", delay='I', mem="Brice : 'Tu choisis. Nous, on tient.'")

D('D117', 13, 'E', 'M', 'arbitrage', "Au relais : le geste de Red avec la Fiole",
  'MossdeepCity_SpaceCenter_2F (coeur) - CF_D117',
  "La Fiole entre les mains de Red.",
  [O('a', 'La donner a Hoopa', {'HO': 5, 'rC': -5}, {'intent': 'PACTE'}, "", ""),
   O('b', 'La confier au courrier du Pilier (rite)', {'rG': 5, 'HO': -5}, {'intent': 'SCEAU'}, "", ""),
   O('c', 'La laisser a la charte (Consortium et Ligue)', {'rC': 5, 'HO': -8}, {'intent': 'PASSERELLE'}, "", ""),
   O('d', 'La briser', {'HO': -8, 'rA': 3}, {'intent': 'BRISER'}, "", ""),
   O('e', 'Laisser le ciel juger (evacuer, abandonner le relais a Rayquaza)', {'rL': 4, 'HO': -5, 'rC': -4}, {'intent': 'JUGEMENT'}, "Red rend la Fiole au toit ouvert et fait evacuer.", "F4 Le Jugement (Y4).")],
  ['resultat de la Fiole'], 'F1-F5.', "Prerequis Red au relais.", when=lambda s: s['val'].get('loc') == 'R', pre='D116 = a', delay='I', mem='Hoopa, la Doyenne ou Lanette regardent Red ; la scene de fin le rappelle.')

D('D118', 13, 'D', 'S', 'don', "Veillee : le don de Red",
  'veillee (carte selon D116) - CF_D118',
  "Red peut donner quelque chose a un allie avant de partir.",
  [O('a', "Confier Hoopa a l'allie du relais", {'HO': -3, 'BR': 1}, {'hoopa_to_relay': True}, "Hoopa se cache derriere l'allie.", "Hoopa present au relais."),
   O('b', "Donner ses objets de soin a l'allie des civils", {'rP': 2}, {'lend': True, 'item': -3, 'loss': 'objets de soin (Hyper Potions x3)'}, "L'allie remplit ses poches.", "civils : BLESSES au lieu de PERTES avec un allie faible ; Red arrive au combat sans soins."),
   O('c', 'Ne rien donner', {'BR': -1}, {'gain': 'equipe complete'}, "", ""),
   O('d', "Confier la preuve de la gardienne a l'allie du Pilier", {'AM': 3, 'rG': -2}, {'set': ['OBJET_GARDIENNE_DONNE']}, "L'allie glisse le ruban de la gardienne dans sa manche.", "RENONCE possible sans Red au Pilier (porteur).")],
  ['resultat de la Fiole (presence de Hoopa)', 'casualties'], 'F2.', "a : prerequis garde RED et Red pas au relais.", delay='I')

D('D119', 13, 'E', 'S', 'aveu', "Pilier : Amaryllis",
  'SkyPillar_Top - CF_D119',
  "Amaryllis attend Rayquaza ; Aster tremble.",
  [O('a', 'Montrer la preuve de la mort de la gardienne', {'AM': 5, 'RK': 1}, {'ama': 'show'}, "", "RENONCE si AM>=55, sinon PERSISTE."),
   O('b', "La combattre (gagner du temps, Y3)", {'AM': -5, 'rG': 1}, {'ama': 'fight'}, "", "PERSISTE ; temps gagne.")],
  ['AM_ISSUE (epilogue, P2 dans son equipe)'], 'variante Amaryllis.', "Prerequis Red au Pilier. Si Red absent : AM>=60 et REL_AMA_ARAGON -> RENONCE ; AM<30 -> SACRIFICE ; sinon PERSISTE.",
  when=lambda s: s['val'].get('loc') == 'P', pre='D116 = b', delay='I')

D('D120', 13, 'E', 'S', 'arbitrage', "Civils : le port des pecheurs ou le Centre des arrivants",
  'SootopolisCity / LilycoveCity (civils) - CF_D120',
  "Deux quartiers sous les anneaux ; on n'en vide qu'un a temps.",
  [O('a', 'Le port des pecheurs', {'rP': 5, 'rA': -3}, {'ecostep': 'Z01', 'set': ['CIVILS_PORT']}, "", "casualties cote arrivants ; postgame : le Centre des arrivants ferme (PNJ absents)."),
   O('b', 'Le Centre des arrivants', {'rA': 5, 'rP': -3}, {'set': ['CIVILS_CENTRE']}, "", "casualties cote pecheurs ; postgame : le port de Nenucrique a moitie vide.")],
  ['epilogue (casualties)', 'variante sociale (rP)'], 'variante sociale.', "Prerequis Red aux civils.", when=lambda s: s['val'].get('loc') == 'C', pre='D116 = c', delay='I')

D('D121', 13, 'D', 'S', 'arbitrage', "Rayquaza : combattre ou tenir le rite",
  'SkyPillar_Top - CF_D121',
  "Rayquaza descend. Le combattre fait gagner du temps ; le rite le retient.",
  [O('a', 'Combattre (Y3)', {'rG': -2, 'rL': 2}, {'ray': 'fight'}, "", "temps gagne (civils), pas de rite."),
   O('b', 'Tenir le rite avec la Doyenne', {'rG': 2, 'rL': -2}, {'ray': 'rite'}, "", "RITE si rG>=45 (40 avec RITE_PREPARE).")],
  ['RITE (F1)'], 'F1.', "Prerequis Red au Pilier.", when=lambda s: s['val'].get('loc') == 'P', pre='D116 = b', delay='I')

D('D122', 13, 'D', 'S', 'presence', "Flora : obeir a Norman ou rejoindre les civils",
  'veillee - CF_D122',
  "Norman ordonne a Flora de rejoindre la brigade au Pilier.",
  [O('a', 'Designer Brice (il lui parle)', {'BR': 1, 'rL': -2}, {'flora': 'brice'}, "", "FLORA_DESOBEIT si FL>=55 et BR>=50."),
   O('b', 'Rester (la laisser choisir)', {'FL': 2, 'BR': -1}, {'flora': 'self'}, "", "FLORA_DESOBEIT si FL>=60 ou FLORA_DOUTE.")],
  ['climax (Flora allie civils)', 'epilogue Flora', 'vote NOR (abstention)'], 'casualties.', "slot ; FLORA_DESOBEIT selon seuils.", delay='I')

# ---------------------------------------------------------------- CH. 14
D('D123', 14, 'E', 'S', 'don', "Route Victoire : l'echange de Blue",
  'VictoryRoad_1F - CF_D123 (E-REMOVE + E-NATIVE)',
  "Blue : 'Donne-moi un de tes natifs. Je te donne un import. Pour voir.'",
  [O('a', 'Accepter', {'BL': 3, 'rG': -1}, {'lose_mon': True, 'gain': 'import de Blue'}, "Blue aligne ton natif au combat final.", "Blue final : variante 'natif' ; epilogue Blue (Jadielle) chaleureux."),
   O('b', 'Refuser', {'BL': -1, 'rG': 1}, {}, "'Comme tu veux.'", "Blue final : E-ADAPT pur.")],
  ['brief B (Blue final)', 'epilogue Blue'], 'variante Blue.', "a : echange effectue (verifier especes).", delay='I')

D('D124', 14, 'D', 'S', 'combat', "Timmy a la Route Victoire (refusable)",
  'VictoryRoad_1F - CF_D124 (FLAG_CF_REFUS_TIMMY)',
  "Timmy, avec ou sans son arrivant : 'Je veux savoir si je peux.'",
  [O('a', 'Accepter et gagner', {'TI': 2, 'BR': -1}, {}, "", "Timmy rentre fier (epilogue)."),
   O('b', 'Accepter et perdre', {'TI': 4, 'rL': -1}, {'money': -1000}, "", "Timmy part pour la Zone de Combat (postgame)."),
   O('c', 'Refuser', {'TI': -3, 'rP': 1}, {}, "", "epilogue Timmy triste ; refus definitif.")],
  ['epilogue Timmy', 'postgame Zone'], 'variante Timmy.', "slot 1/2/3.", delay='C')

D('D125', 14, 'E', 'S', 'presence', "Pantheon : qui sur la photo",
  'HallOfFame - CF_D125',
  "Le photographe attend ; Brice et Blue sont la.",
  [O('a', 'Avec Brice', {'BR': 3, 'BL': -2}, {'post': 'BRICE'}, "", "postgame : Brice partenaire de duo au Tournoi."),
   O('b', 'Avec Blue', {'BL': 3, 'BR': -2}, {'post': 'BLUE'}, "", "postgame : duel de Blue a Bourg-en-Vol des P1."),
   O('c', 'Seul', {'GI': 2, 'BR': -1}, {'post': 'SEUL'}, "", "postgame : dernier duel de Giovanni des P1.")],
  ['postgame (ordre des acces)'], 'aucune.', "slot ; PNJ postgame selon slot.", delay='C')

# ---------------------------------------------------------------- POSTGAME
D('D126', 15, 'E', 'M', 'arbitrage', "Fuji et Mewtwo",
  'CaveOfOrigin_Entrance (anneau) - CF_D126',
  "Un anneau amene Mewtwo ; Fuji demande qu'on le laisse choisir.",
  [O('a', 'Le capturer', {'rG': -2}, {'gain': 'Mewtwo', 'set': ['MEWTWO_CAPTURE']}, "", "Fuji : lettre amere."),
   O('b', 'Le laisser', {'rG': 2}, {'loss': 'Mewtwo plus tard', 'set': ['MEWTWO_LIBRE']}, "", "Mewtwo revient a la Grotte Atelier apres la lettre de Fuji (invariant 9 : toujours obtenable).")],
  ['postgame (canal Mewtwo)', 'epilogue Fuji'], 'aucune.', "a : Mewtwo ; b : rencontre ouverte apres 1 jour (flag quotidien non utilise : script).", delay='C', mem='Lettre de Fuji au postgame (deux variantes).')

D('D127', 15, 'E', 'S', 'combat', "Le dernier duel de Giovanni (refusable)",
  'Route101 / SafariZone (selon D125) - CF_D127 (FLAG_CF_REFUS_GIO2)',
  "'Une derniere fois. Sans rien d'importe.'",
  [O('a', 'Accepter et gagner', {'GI': 3, 'RK': -5}, {'loss': 'Giovanni part (plus de revanche)'}, "", "Giovanni dissout la cellule de Hoenn (sbires retires des routes)."),
   O('b', 'Accepter et perdre', {'GI': 5, 'RK': 2}, {'money': -2000}, "", "sbires restent ; il part 's'entrainer'."),
   O('c', 'Refuser', {'GI': -3, 'RK': 2, 'rI': 2}, {}, "", "sbires restent ; la Mission soulagee.")],
  ['postgame (sbires, anneaux voles)'], 'variante Rocket postgame.', "slot.", delay='I')

D('D128', 15, 'E', 'M', 'arbitrage', "Financer une restauration (une seule zone)",
  'RustboroCity_DevonCorp_3F ou SlateportCity - CF_D128',
  "10 000 P : Devon (ou la charte) finance une restauration ; une seule zone.",
  [O('a', 'Z-01 Littoral', {'rP': 3, 'rC': -1}, {'money': -10000, 'ecostep': 'Z01'}, "", ""),
   O('b', 'Z-03 Lavandia', {'rP': 3, 'rC': -1}, {'money': -10000, 'ecostep': 'Z03'}, "", ""),
   O('c', 'Z-05 Mers', {'rA': 3, 'rC': -1}, {'money': -10000, 'ecostep': 'Z05'}, "", "")],
  ['E-ECO (zone choisie)'], 'aucune (postgame).', "zone +1 cran ; -10 000 P.", delay='I', mem="Panneau 'Restauration financee' dans la zone choisie.")

D('D129', 15, 'D', 'S', 'presence', "Le depart de Blue (Bourg-en-Vol)",
  'LittlerootTown (quai) - CF_D129',
  "Blue part pour Jadielle ; il tient un Pokeball d'import.",
  [O('a', 'Rester sur le quai', {'BL': 3}, {'loss': 'temps (Tournoi ferme ce jour)'}, "", "Blue confie son import a Red pour le 'renvoyer chez lui' par le canal de la fin."),
   O('b', 'Partir', {'BL': -2}, {'gain': 'Tournoi ouvert ce jour'}, "", "rien.")],
  ['postgame'], 'aucune.', "a : Pokemon recu.", delay='I')

D('D130', 15, 'E', 'S', 'arbitrage', "Tournoi des Confluences : la finale",
  'BattleFrontier_BattleTowerLobby - CF_D130',
  "Scott propose la finale contre Brice ou contre Blue.",
  [O('a', 'Contre Brice', {'BR': 2, 'BL': -1}, {}, "", "Brice T5 (voie BV)."),
   O('b', 'Contre Blue', {'BL': 2, 'BR': -1}, {}, "", "Blue T5.")],
  ['postgame'], 'aucune.', "slot.", delay='I',
  verdict=('F', 'choix de contenu postgame (adversaire), sans etat lu ensuite : liste, non compte'))

D('D131', 15, 'D', 'M', 'arbitrage', "Fin cachee : ouvrir la chambre scellee de Bayar",
  'Route111 (ruines) / DesertRuins - CF_D131',
  "Dossier complet et Chen a avoue : Bayar montre la chambre que les anciens ont scellee avant Hoopa.",
  [O('a', 'Ouvrir', {'rG': -3}, {'gain': 'Regis plus tot'}, "", "les Regis s'eveillent (canal propre a la fin cachee)."),
   O('b', 'Laisser scelle', {'rG': 3}, {'loss': 'Regis par le canal de la fin'}, "", "Bayar : 'Cette fois, on sait pourquoi.'")],
  ['postgame (Regis)'], 'fin cachee.', "Prerequis fin cachee.", delay='I',
  when=lambda s: s.get('hidden', False), pre='fin cachee atteinte', mem='Bayar note le choix dans le registre de la Zone.')
