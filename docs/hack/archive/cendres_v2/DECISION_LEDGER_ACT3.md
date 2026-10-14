# DECISION_LEDGER — Acte III, finale, postgame (D081–D120)

> Règles, abréviations et méthode de test : `DECISION_LEDGER.md` §1. Statut de toutes les entrées : **proposé**.

## Ch. 9 — Nénucrique et le Mont Mémoria

| ID | T | Déclencheur | Options | Prérequis | Stockage | Immédiat | Différé / contenu | Systèmes | Fins | Test | Statut |
|---|---|---|---|---|---|---|---|---|---|---|---|
| D081 | E | `LILYCOVE_CITY`, blocus Aqua du port | a) échanger : levée contre une contre-expertise des fonds ; b) menacer d'appeler la Ligue ; c) proposer aux pêcheurs réfugiés de rejoindre Aqua (si rR ≥ 50, Brice négocie si B ≥ 50) | `FLAG_BADGE06_GET` | `VAR_HS_D081`, `FLAG_HS_ALLIANCE_PECHEURS` (1, c) | gardes de la planque masqués dans les trois cas | c : alliance (motion 2 : vote d'Arthur) ; b : Aqua hostile (rA−10) mais Ligue présente (rO+5) | a : rA+5 ; b : rA−10, rO+5 ; c : rA+8, rR+5, AR+10 | SO | gardes masqués ; vote | proposé |
| D082 | E | `AQUA_HIDEOUT_B1F`, preuve que Rocket a volé du matériel de plongée pour accuser Aqua | a) la montrer à Arthur tout de suite ; b) la garder pour le Conseil | — | `FLAG_HS_PREUVE_MATERIEL`, `VAR_HS_D082` (1) | a : Arthur furieux contre Rocket, s'excuse auprès de Red | a : AR+10 ; b : effet de surprise au Conseil (Marc vote avec le joueur sur la motion 1) | voir | RO, VO | flags ; vote de Marc | proposé |
| D083 | E | Arthur propose que Red mène la contre-expertise à Fondmer | accepter / refuser | D081 = a ou c | `FLAG_HS_CONTRE_EXPERTISE` (1) | accepter : objet « Kit de prélèvement » | accepter : D097 possible ; refuser : Aqua envoie Sarah seule (preuve plus faible) | accepter : AR+5 | VO, Rf | objet ; ch. 11 | proposé |
| D084 | E | `MT_PYRE_1F`, rite des morts de Cramois'Île (Agatha, Spectra) | y participer / s'abstenir | — | `FLAG_HS_RITE` (1) | scène ; Auguste présent | participer : aveu d'Auguste si AU ≥ 60 (« J'ai donné l'alerte trop tard ») | participer : AU+10, rR+5 | SO | scène ; aveu | proposé |
| D085 | E | `MT_PYRE_SUMMIT`, après le combat contre les voleurs Rocket : qui garde l'Orbe Rouge ? | a) les gardiens ; b) Max ; c) Red ; d) Spectra | combat gagné | `VAR_HS_ORBE` | Orbe remise | c : D108 possible ; b : Max peut l'utiliser seul au climax si MX ≥ 55 (V−15) ; a/d : Orbe hors jeu au climax | b : MX+10 ; c : rO−3 | VO | var ; climax | proposé |
| D086 | D | gardiens du sommet, légende | demander « L'Orbe peut-elle calmer un volcan ? » (troisième option du dialogue) / ne pas | — | `FLAG_HS_SAIT_ORBE` (1) | réponse : elle apaise, ne commande pas | requis pour utiliser l'Orbe (D108) | — | VO | flag | proposé |
| D087 | D | `LILYCOVE_CITY_DEPARTMENT_STORE`, achat de tentes (3 000 ₽) | acheter pour le camp / non | — | `FLAG_HS_TENTES` (1) | objet livré au camp | C+10 | rR+3 | SO (C) | argent ; objets au camp | proposé |
| D088 | D | port de Nénucrique, Marins qui défient « le Kantonais » (déclinable) | accepter / décliner | — | `FLAG_HS_D088` (1) | combats ou non | décliner : ils transmettent un message d'Arthur (aide pour D081) | voir | — | combat ou non | proposé |
| D089 | E | `LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP`, Blue avoue avoir perdu son titre en quelques minutes | a) l'écouter (rester) ; b) le provoquer (défi immédiat) ; c) partir | D030 | `VAR_HS_D089` | a : confession ; b : combat Blue 2 (ID `MAY_LILYCOVE_*`) | a : BL+15, Blue proposera son aide au climax ; b : BL+5 (il aime ça) ; c : BL−10 | voir | Arche, épi. Blue | scène/combat ; aide au climax | proposé |
| D090 | E | journalistes : dénoncer Rocket publiquement ? | a) oui ; b) non | `FLAG_HS_SAIT_OPERATION` ou R2 | `FLAG_HS_ROCKET_PUBLIC` (1) | a : reportage | a : Rocket avance son plan (Rk+15) mais la Ligue double la garde (pertes −1 cran) ; N+1 | a : rO+5, Rk+15 | RO, Arche | TV ; variante d'Ariane | proposé |

## Ch. 10 — Algatia

| ID | T | Déclencheur | Options | Prérequis | Stockage | Immédiat | Différé / contenu | Systèmes | Fins | Test | Statut |
|---|---|---|---|---|---|---|---|---|---|---|---|
| D091 | E | `MOSSDEEP_CITY_SPACE_CENTER_1F`, attaque Rocket : partenaire du combat double | Pierre / Brice (si B ≥ 40) | `FLAG_BADGE07_GET` | `VAR_HS_PARTENAIRE` | combat double avec le partenaire choisi | Brice : B+8, il gagne confiance pour le Conseil ; Pierre : rO+5 | voir | BR | partenaire de combat | proposé |
| D092 | E | `MOSSDEEP_CITY_SPACE_CENTER_2F`, « Lambert » démasqué (Lambda) | a) le livrer ; b) l'interroger (révèle la cible : l'Arche, Vermilava) ; c) le laisser fuir pour le suivre | combat gagné | `FLAG_HS_LAMBDA_DEMASQUE` (a/b), `VAR_HS_D092` | a : arrêté ; b : interrogatoire (plus court si D011 gardé ou D041 = b) ; c : il fuit | b : Red sait où frappera Rocket (D106 éclairé) ; c : Lambda conduit à la planque d'Ariane (postgame P2 facilité) mais V+10 | a : rO+5 ; b : Rk−10 ; c : Rk+5 | RO, VO | flags ; plafond 47 | proposé |
| D093 | E | codes de l'Arche volés | a) les faire changer par Devon ; b) les garder pour piéger Rocket | — | `VAR_HS_CODES` | a : Devon change les codes | a : pertes −1 cran ; b : si Red est au camp au climax, Ariane est piégée (arrestation facilitée), sinon pertes +1 cran | voir | Arche, RO | var ; climax | proposé |
| D094 | E | Lanette, venue au Centre Spatial : réparer le lien PC avec Kanto | a) ouvrir maintenant ; b) après la crise ; c) jamais | — | `VAR_HS_RESEAU` 2/1/0 | a : lien ouvert, Rocket peut y voir une cible (Rk+5) | a/b : postgame P1 (équipe classique) ; c : Red reste avec son équipe de Hoenn | a : Rk+5 | postgame | var ; PC | proposé |
| D095 | E | `MOSSDEEP_CITY_STEVENS_HOUSE`, Pierre offre une Méga-Gemme rare (Galekingite ◐) | la garder / la donner à Brice | — | `FLAG_HS_GEMME_BRICE` (1) | objet ou Brice ravi | donnée : l'équipe de Brice (partenaire, climax) a une Méga ; B+8 | voir | BR, Arche | objet ; équipe de Brice | proposé |
| D096 | D | `MOSSDEEP_CITY`, Kinésistes qui veulent « lire » Red (déclinable) | accepter / décliner | — | `FLAG_HS_D096` (1) | combat ou non | décliner : l'une d'elles dit à Brice ce que Red ressent (scène drôle, B+3) | voir | BR | combat ou non | proposé |

## Ch. 11 — Fondmer

| ID | T | Déclencheur | Options | Prérequis | Stockage | Immédiat | Différé / contenu | Systèmes | Fins | Test | Statut |
|---|---|---|---|---|---|---|---|---|---|---|---|
| D097 | E | `SEAFLOOR_CAVERN_ROOM1`, corail blanchi | a) prélever (preuve forte, abîme le site) ; b) photographier (preuve moyenne) | D083 | `FLAG_HS_PREUVE_CORAIL` / `_PHOTOS_FONDS` (2) | preuve | a : Rf−5 ; preuve qui compte double pour Arthur et Juan | voir | VO, Rf | flags ; Conseil | proposé |
| D098 | D | salle 1, balise du capitaine Marin | la poser / non | D026 = a ou b | `FLAG_HS_BALISE` (1) | — | Marin témoigne au Conseil (motion 1, voix publique) | rO+3 | VO | flag | proposé |
| D099 | E | `SEAFLOOR_CAVERN_ROOM9`, plongeurs Rocket | a) les poursuivre (combat) ; b) les laisser | — | `FLAG_HS_PLONGEURS` (1) | a : ils lâchent un plan de Vermilava | a : Rk−10, preuve `PLAN_VERMILAVA` (D106 éclairé) | voir | RO | flags | proposé |

## Ch. 12 — Le Conseil d'Atalanopolis

| ID | T | Déclencheur | Options | Prérequis | Stockage | Immédiat | Différé / contenu | Systèmes | Fins | Test | Statut |
|---|---|---|---|---|---|---|---|---|---|---|---|
| D100 | E | `SOOTOPOLIS_CITY`, ouverture : qui parle pour Red ? | a) Red (gestes + preuves, Brice traduit) ; b) Brice parle (si B ≥ 60) ; c) céder la parole à Auguste | — | `VAR_HS_ORATEUR` | discours | b : Marc vote avec le joueur (condition « Brice a parlé ») ; c : AU+10 ; vote d'Auguste assuré sur la motion 2 | voir | SO, VO, BR | var ; votes | proposé |
| D101 | E | motion 1 (Soupape) | complet / réduit et surveillé / arrêt et évacuation | — | `VAR_HS_CONSEIL_SOUPAPE` | vote (GAME_SYSTEMS §5) | `ETAT_VOLCAN` (§8.1) ; chantier au climax | voir §8 | VO | votes calculés | proposé |
| D102 | E | motion 2 (réfugiés) | intégration / relogement / rapatriement | — | `VAR_HS_CONSEIL_REFUGIES` | vote | SO ; épilogue (Pacifiville) | — | SO | votes | proposé |
| D103 | E | motion 3 (Arche) | garde Devon / garde Ligue / restitution | — | `VAR_HS_CONSEIL_ARCHE` | vote | promesse D028 vérifiée ; pertes au climax | — | Arche, SO | votes | proposé |
| D104 | E | preuves à produire (jusqu'à 3 parmi celles détenues) | sélection (`multichoice` dynamique) | — | `VAR_HS_PREUVES_MONTREES` (bits) | chaque preuve dite à voix haute | poids `P` pour les votes | — | VO, SO | votes selon preuves | proposé |
| D105 | D | après le vote, le camp perdant quitte la place | aller serrer la main de son chef / non | — | `FLAG_HS_MAIN_TENDUE` (1) | geste | rép. de la faction perdante +8 ; ligne au climax | voir | SO | flag | proposé |

## Ch. 13 — La Braise

| ID | T | Déclencheur | Options | Prérequis | Stockage | Immédiat | Différé / contenu | Systèmes | Fins | Test | Statut |
|---|---|---|---|---|---|---|---|---|---|---|---|
| D106 | E | Centre de Vermilava, double alerte | a) le chantier (Planque Magma) ; b) le camp et l'Arche | soin forcé | `VAR_HS_CLIMAX_LIEU` | branche | l'autre lieu : Brice si B ≥ 55 (+ Blue si BL ≥ 60 au camp) | — | VO, RO, Arche, BR | deux branches | proposé |
| D107 | E | chantier, foreuse emballée | a) arrêt d'urgence (onde de choc) ; b) la laisser finir le dégazage | D106 = a, motion 1 ≠ 3 | `FLAG_HS_ARRET_URGENCE` (1) | a : secousse, galerie fermée ; b : le dégazage continue | a : V−20 ; b : V+0 (si sabotages déjoués) sinon V+15 | voir | VO | V calculé | proposé |
| D108 | E | chantier, chaleur de Groudon | utiliser l'Orbe Rouge / non | `ORBE` = 2 et `SAIT_ORBE` | `FLAG_HS_ORBE_UTILISEE` (1) | Groudon s'apaise (scène) | V−25 ; postgame : Groudon endormi (P3 « veiller ») | voir | VO | V | proposé |
| D109 | E | camp, Ariane menace un Pokémon de l'Arche (otage) | a) la laisser fuir (otage relâché) ; b) l'arrêter (combat ; risque pour l'otage) | D106 = b | `FLAG_HS_ARIANE_ARRETEE` (1, b gagné) | a : otage sauf, Ariane fuit ; b : combat (ID `MAXIE_MAGMA_HIDEOUT`) | b : RO possible ; l'otage est blessé (famille en colère : rR−5) sauf si D093 = b (piège) | a : rR+5 ; b : rO+10 | RO, Arche | flags | proposé |
| D110 | D | après la crise, deux blessés : Max (infirmerie du chantier) et Auguste (tente du camp) | marcher jusqu'à Max / jusqu'à Auguste (le premier visité compte) | — | `VAR_HS_D110` | scène | épilogue : celui qu'on a vu parle à Red dans l'épilogue ; l'autre écrit une lettre | MX+10 ou AU+10 | épi. | var | proposé |
| D111 | E | éboulement à la sortie (si Pikachu dans l'équipe) | envoyer Pikachu retenir la roche / ne pas | `PIKACHU` = 3 | `FLAG_HS_PIKACHU_RETRAITE` (1) | a : tout le monde sort ; Pikachu épuisé | a : Pikachu quitte le combat (reste en PC, « retraite » à Bourg-en-Vol au postgame) ; non : un ouvrier blessé (C−5) | a : rR+5 | épi. Pikachu | flag ; Pikachu non sélectionnable | proposé |

## Ch. 14 — Finale

| ID | T | Déclencheur | Options | Prérequis | Stockage | Immédiat | Différé / contenu | Systèmes | Fins | Test | Statut |
|---|---|---|---|---|---|---|---|---|---|---|---|
| D112 | E | `VICTORY_ROAD_1F`, Blue propose un « pacte » : sans objets | accepter / refuser | — | `FLAG_HS_PACTE_BLUE` (1) | accepter : `B_VAR_NO_BAG_USE` pendant le combat | accepter : BL+10, épilogue « Blue rit enfin » | voir | épi. Blue | sac désactivé ; combat (ID `WALLY_VR_*`) | proposé |
| D113 | E | après la victoire contre Pierre : la Ligue offre le titre de Maître de Hoenn | accepter (une saison) / refuser | `FLAG_IS_CHAMPION` | `FLAG_HS_TITRE_HOENN` (1) | accepter : N=2 | épilogue : Red reste une saison puis part (avenir canonique préservé) ; refuser : Pierre garde le titre | voir | épi. notoriété | flag ; épilogue | proposé |
| D114 | D | épilogue, sur le quai | à qui laisser sa casquette : Brice / Lilou / la garder | — | `VAR_HS_CASQUETTE` | geste | dernière image de l'épilogue ; postgame : le PNJ la porte | B+5 ou rR+3 | épi. | var | proposé |

## Postgame — « Ce qui reste »

| ID | T | Déclencheur | Options | Prérequis | Stockage | Immédiat | Différé / contenu | Systèmes | Fins | Test | Statut |
|---|---|---|---|---|---|---|---|---|---|---|---|
| D115 | E | PC de Lanette (lien rétabli) | rapatrier l'équipe classique / la laisser au Prof. Chen | `RESEAU` ≥ 1 | `FLAG_HS_EQUIPE_CLASSIQUE` (1) | Pokémon de Kanto disponibles (niveau plafond postgame) | Blue réagit ; Brice : « Alors c'était ça, ton équipe ? » | — | postgame | `givemon` ×5 | proposé |
| D116 | E | piste d'Ariane (si en fuite) | la poursuivre (Chenal 134 → Épave) / laisser la Ligue | `RO` = EN FUITE | `FLAG_HS_CHASSE_ARIANE` (1) | combat final Rocket (slot libre) | épilogue Rocket : « Giovanni ne reviendra pas cette année » / « Ariane a rejoint Johto » (préparation GSC) | — | épi. Rocket | combat ; texte | proposé |
| D117 | E | Groudon (si éveillé ou apaisé) | le capturer / le laisser dormir (veiller avec l'Orbe) | `V` ≥ 70 atteint ou D108 | `FLAG_HS_GROUDON_CAPTURE` (1) | combat de capture ou scène | laisser : le Mont Chimnée se stabilise (dialogues de Max) ; capturer : Max inquiet (« et s'il manque ? ») | voir | monde | capture ; dialogues | proposé |
| D118 | E | Zone de Combat, Scott propose à Red et Blue un poste de « Meneurs » | accepter / refuser | `FLAG_SYS_GAME_CLEAR` | `FLAG_HS_FRONTIER_MENEUR` (1) | accepter : Red et Blue en duo dans une salle | Blue part plus tard vers Jadielle (message) ; refuser : Blue part tout de suite | BL±5 | épi. Blue | dialogue ; salle | proposé |
| D119 | D | Centre, réponse de la mère de Red (si D023) | lire / ignorer | D023 | `FLAG_HS_LETTRE_LUE` (1) | lettre | objet « Lettre de maman » ; ligne finale | — | épi. | objet | proposé |
| D120 | D | départ, quai de Poivressel (Océane réparée) | aller parler à Brice / à Auguste et Lilou / monter directement à bord | — | `VAR_HS_ADIEUX` | dernière scène | dernier plan avant les crédits du postgame ; c : Brice court sur le quai si B ≥ 60 | — | épi. | var ; scène | proposé |

**Total acte III + finale + postgame : 40 décisions** (explicites 30, discrètes 10 ; 2 combats déclinables).
**Total général : 120 décisions.**
