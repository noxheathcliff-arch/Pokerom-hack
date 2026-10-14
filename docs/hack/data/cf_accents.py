# -*- coding: utf-8 -*-
"""Restauration des accents FR pour le rendu Markdown (les donnees sont saisies sans accents)."""
import re
W = """differe:différé differes:différés immediat:immédiat immediats:immédiats Prerequis:Prérequis prerequis:prérequis affecte:affecté
Unite:Unité Delai:Délai Declencheur:Déclencheur memoire:mémoire epilogue:épilogue Epilogue:Épilogue presence:présence Presence:Présence
piece:pièce pieces:pièces equipe:équipe Equipe:Équipe equipes:équipes Ecosysteme:Écosystème ecosysteme:écosystème cachee:cachée allie:allié allies:alliés Allie:Allié
Cileo:Ciléo donnees:données apres:après Apres:Après meme:même cote:côté Defis:Défis Defi:Défi veillee:veillée replique:réplique repliques:répliques
pecheurs:pêcheurs pecheur:pêcheur Pecheries:Pêcheries pecheries:pêcheries cable:câble Cable:Câble President:Président Leo:Léo Alizee:Alizée Voltere:Voltère
Nenucrique:Nénucrique Clementi:Clémenti Meteore:Météore Goelise:Goélise Merouville:Mérouville Autequia:Autéquia Memoria:Mémoria Pokemon:Pokémon
temoignage:témoignage temoin:témoin Temoin:Témoin temoins:témoins releves:relevés releve:relevé recu:reçu proteger:protéger resultat:résultat Resultat:Résultat entrepot:entrepôt
ecoute:écoute Ecoute:Écoute demonstration:démonstration defendue:défendue Defendre:Défendre arrete:arrête ruines:ruinés regenerer:régénérer editer:éditer Genere:Généré
Regles:Règles regles:règles regle:règle Systemes:Systèmes systemes:systèmes systeme:système Systeme:Système decomptes:décomptes decisions:décisions Decisions:Décisions decision:décision Decision:Décision
comptees:comptées comptee:comptée implemente:implémenté ecrites:écrites accentue:accentué scenaristes:scénaristes portabilite:portabilité legende:légende entrees:entrées
Etat:État etat:état seance:séance scene:scène scelle:scellé sauve:sauvé sauves:sauvés ruine:ruiné reserve:réserve supplementaire:supplémentaire tete:tête tot:tôt tempete:tempête
predicteur:prédicteur oeuf:œuf oeufs:œufs nuees:nuées noeud:nœud noeuds:nœuds hesite:hésite eclats:éclats echange:échange deplacer:déplacer Deplacer:Déplacer canopee:canopée
etoiles:étoiles desert:désert diner:dîner Diner:Dîner infirmiere:infirmière lumiere:lumière manquee:manquée moitie:moitié negociation:négociation petition:pétition presente:présente
reconnait:reconnaît deja:déjà tres:très etre:être ete:été evenement:événement Ca:Ça ca:ça Eclate-Roc:Éclate-Roc evacuation:évacuation ecrit:écrit Ecrire:Écrire ecrire:écrire
equilibre:équilibre etrangers:étrangers etranger:étranger etrangere:étrangère reponse:réponse proteges:protégés deguisement:déguisement Demanta:Démanta Heledelle:Hélédelle Etourmi:Étourmi
detruit:détruit decide:décide Desole:Désolé repart:repart releves:relevés eleveur:éleveur eclot:éclot evite:évite echoue:échoue Debarquement:Débarquement debarque:débarque
recupere:récupère deroute:déroute medecin:médecin quete:quête Quete:Quête cle:clé cles:clés phenomene:phénomène precis:précis precise:précise peche:pêche Mega-Anneau:Méga-Anneau
Mega-Metalosse:Méga-Métalosse Metalosse:Métalosse Mega:Méga generale:générale general:général securite:sécurité Securite:Sécurité periode:période blesse:blessé blesses:blessés
Blesse:Blessé abattu:abattu protege:protégé deposer:déposer depose:dépose eteint:éteint geste:geste Geste:Geste reunis:réunis reuni:réuni Reuni:Réuni liberer:libérer Liberer:Libérer
liberation:libération Liberation:Libération negocier:négocier Negocier:Négocier evenements:événements Echo:Écho echo:écho ecart:écart ecarts:écarts etape:étape strategie:stratégie
strategies:stratégies dominee:dominée epidemie:épidémie epidemies:épidémies regulee:régulée regule:régulé Cree:Crée cree:crée creer:créer reussite:réussite reel:réel reelle:réelle
mecanique:mécanique mecaniques:mécaniques numero:numéro electrique:électrique ecole:école Ecole:École eglise:église ecran:écran resume:résumé Resume:Résumé selection:sélection
interet:intérêt interets:intérêts elle-meme:elle-même lui-meme:lui-même eux-memes:eux-mêmes Hoenn:Hoenn cote:côté arrivee:arrivée Arrivee:Arrivée Recensement:Recensement
precedent:précédent precedente:précédente premiere:première derniere:dernière deuxieme:deuxième troisieme:troisième pere:père Pere:Père mere:mère frere:frère fidele:fidèle
reveille:réveille reveil:réveil eveille:éveille revele:révèle revelation:révélation Revelation:Révélation reveler:révéler revelee:révélée desobeit:désobéit desobei:désobéi desobeir:désobéir
obeit:obéit obeir:obéir Obeir:Obéir realise:réalisé realiser:réaliser mefiance:méfiance Mefiant:Méfiant mefiant:méfiant tresor:trésor Tresor:Trésor ecrase:écrase gere:gère geree:gérée
fleche:flèche verifier:vérifier verifie:vérifié Verifier:Vérifier verification:vérification Prealable:Préalable prealable:préalable etoile:étoile depart:départ Depart:Départ
deja:déjà fevrier:février cles:clés Systeme:Système epuise:épuisé ecarte:écarté Ecarte:Écarté resolu:résolu resolue:résolue resoudre:résoudre bloque:bloqué bloquee:bloquée
tenue:tenue Pilier:Pilier Celeste:Céleste celeste:céleste Atalanopolis:Atalanopolis Algatia:Algatia Pacifiville:Pacifiville Eternara:Éternara Cimetronelle:Cimetronelle
Trefonds:Tréfonds Rosyeres:Rosyères Pere:Père Sylphe:Sylphe ennemi:ennemi deleguee:déléguée Liste:Liste reveles:révélés Peter:Peter etablie:établie etabli:établi
Jadielle:Jadielle portee:portée disparait:disparaît Sequence:Séquence sequence:séquence Deja:Déjà precedemment:précédemment specifique:spécifique reference:référence references:références Recapitulatif:Récapitulatif decompte:décompte Decompte:Décompte detail:détail details:détails Detail:Détail
""".split()
PAIRS = [p.split(':', 1) for p in W if ':' in p]
PATS = [(re.compile(r'(?<![\w_])' + re.escape(a) + r'(?![\w_])'), b) for a, b in PAIRS if a != b]
PHR = [(re.compile(r'statut \*\*propose\*\*'), 'statut **proposé**'), (re.compile(r'\bmarche noir\b'), 'marché noir'),
       (re.compile(r'\b(du|au|le) marche\b'), r'\1 marché'), (re.compile(r'\bMarche noir\b'), 'Marché noir'),
       (re.compile(r'(?<![\w_])a (?=(la |l\'|le |les |un |une |son |sa |ses |ce |cette |leur |tout |toutes |Red|Brice|Peter|Chen|Seko|Max|Koga|Giovanni|Pierre|Flora|Norman|Olga|Ondine|Sarah|Fuji|Amaryllis|Arthur|Devon|Hoopa|Timmy|Erika|Adriane|Auguste|Alizee|Alizée|Marc|Juan|Leo|Léo|Kosmo|Roxanne|Bastien|Lavandia|Nenucrique|Nénucrique|Algatia|Merouville|Mérouville|Vergazon|Poivressel|Myokara|Clementi|Clémenti|Kanto|Hoenn|Jadielle|<=|>=|plafond|niv|moitie|moitié|distance|portee|portée|cote|côté|chaque|qui|quelqu|tous|deux|trois))'), 'à '),
       (re.compile(r'(?<![\w_])A (?=(la |l\'|Red|Kanto))'), 'À ')]
def fr(t):
    if not t: return t
    for p, b in PHR: t = p.sub(b, t)
    for p, b in PATS: t = p.sub(b, t)
    return t
