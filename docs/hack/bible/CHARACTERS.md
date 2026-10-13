# Bible — Personnages (*Pokémon Heure Suspendue*)

> Partie de `GAME_DESIGN_BIBLE.md`. Toute modification passe par le GMD (changelog de la bible).
> Les **équipes-types** donnent l'intention (espèces, thème, mécanique enseignée, plafond) ; les sets complets au format Showdown sont produits par le superviseur dresseurs avec une fiche combat majeur (GM_METHOD §5.4) et validés par `tools/qa/validate_trainers.py`.
> Noms de dresseurs ≤ 10 caractères. Noms FR vanilla `◐` à vérifier sur Poképédia avant intégration (LORE_DOSSIER §0.2).

---

## 1. Le joueur
- **Assets :** Brendan / May (Émeraude) — `TRAINER_PIC_BRENDAN/MAY`, `OBJ_EVENT_GFX_BRENDAN_*/MAY_*`.
- **Situation :** enfant de Norman (champion de Clémenti-Ville) ; emménage à Bourg-en-Vol (intro vanilla du camion conservée).
- **Rôle narratif :** celui qui *lit*. Le jeu ne lui prête pas de discours ; ses choix sont des actions (délivrer, protéger Absol, refuser l'offre d'Ysaline, tendre le Diapason).
- **Choix offerts :** recevoir Absol dans l'équipe (ou le laisser libre — il reste alors visible aux étapes clés) ; ordre de certaines délivrances optionnelles ; refus explicite de l'offre d'Ysaline (pas de mauvaise fin : le refus est l'unique issue, mais il est *dit* par le joueur).

## 2. {RIVAL} — l'enfant du Prof. Seko (« le Chroniqueur »)
- **Assets :** Brendan/May rival (`TRAINER_PIC_MAY`/`BRENDAN` selon genre opposé, `OBJ_EVENT_GFX_RIVAL_*`), classe `RIVAL`, musique `MUS_VS_RIVAL`, rencontre `MUS_ENCOUNTER_MAY/BRENDAN`.
- **Objectif :** compléter le Pokédex, tout photographier, tout consigner.
- **Croyance initiale :** « Ce qui est enregistré ne disparaît jamais. »
- **Conflit :** il trouve les Figements fascinants (« des photos en vrai ») et défend un temps l'idée d'Ysaline (« préserver, c'est bien, non ? »).
- **Arc :** curiosité (ch. 0-4) → admiration pour les Figements (ch. 9) → doute devant le Xatu (ch. 11) → compréhension : on ne garde pas un instant en l'arrêtant, on le garde en s'en souvenant (Route Victoire).
- **Combats (ID vanilla réutilisés) :** Route 103 (ch. 0), Route 110 (ch. 4), Route 119 (ch. 9, remet Vol), Nénucrique toit du Grand Magasin (ch. 10), **Route Victoire** (ch. 16, ID du dernier combat de Timmy). IA : `Basic Trainer` puis `Smart Switching / Ace Pokemon` ; les deux derniers combats ajoutent `Know Opponent Party` (H5).
- **Équipe-type :** starter fort contre celui du joueur + Pokémon « de documentation » : Magnéti, Tarsal, Tarinor, Cradopaud, Ptiravi (Xatu et Noctunoir sont réservés à Augure et à Ysaline). À la Route Victoire : 6 Pokémon, une seule Méga (Méga-Gardevoir ou Méga-Gallame selon le starter du joueur).

## 3. Prof. Seko (Birch)
- **Assets :** `OBJ_EVENT_GFX_PROF_BIRCH` ; **pas de portrait de combat** → ne combat pas.
- **Rôle :** mentor léger ; remet starter, Pokédex, choix du mode (H2). Chercheur de terrain qui note que les zones figées « n'ont plus de rencontres » (première formulation de la règle, ch. 1).
- **Arc :** aucun majeur ; il est la voix de la science qui *observe* sans juger.

## 4. Maman
- **Assets :** `OBJ_EVENT_GFX_MOM`, pas de portrait.
- **Rôle :** ancrage domestique ; au ch. 8, raconte que la grand-mère du joueur a été accompagnée au Mont Mémoria par la sonneuse — Ysaline (la famille la connaît ; humanise l'antagoniste).

## 5. Norman — champion de Clémenti-Ville (badge 5)
- **Assets :** `TRAINER_PIC_LEADER_NORMAN`, `OBJ_EVENT_GFX_NORMAN`.
- **Rôle :** père ; exige 4 badges (vanilla). Remet **CS Surf** lui-même après le badge (remplace le père de Timmy).
- **Leçon :** talents et objets tenus (« le type ne dit pas tout »).
- **Équipe-type (cap 33) :** Ronflex @ Restes, Ursaring @ Orbe Flamme (Cran), Porygon2 @ Évoluroc ; As Monaflèmit (Absentéisme). IA : `Basic Trainer / Smart Switching / Ace Pokemon / HP Aware`.

## 6. Gaspard — le ruinemaniaque (allié principal)
- **Assets :** `TRAINER_PIC_RUIN_MANIAC`, `OBJ_EVENT_GFX_MANIAC` (ou `HIKER`) ; classe `RUIN_MANIAC` (« RUINEMANIAC ») ; combat d'entraînement possible au ch. 1.
- **Âge / allure :** trentaine, carnet, lampe frontale.
- **Objectif :** prouver que le peuple du Sanctuaire n'était pas un peuple de geôliers ; publier la vraie lecture du Braille.
- **Croyance :** « Une ruine qu'on ne lit pas est une ruine qu'on perd. »
- **Défaut :** il sacrifierait un site pour un savoir (Tour Mirage, quête annexe A4) ; impatient avec le Musée.
- **Rôle :** remet le **Diapason** (ch. 1) et le **Carnet de Gaspard** ; lit le Braille avec le joueur ; escorte au Pilier Céleste (PNJ suiveur).
- **Arc :** savoir à tout prix → comprend que ce que le peuple ancien a « figé » était aussi un savoir, et que le laisser partir n'est pas le perdre (il renonce à garder un fragment de la Cloche Mère, ch. 15).

## 7. Ysaline — la sonneuse (antagoniste principale)
- **Assets :** portrait **`TRAINER_PIC_ELITE_FOUR_AGATHA_FRLG`** (réutilisé, renommé ; option : PNG dédié si budget art) ; OW `OBJ_EVENT_GFX_OLD_WOMAN` ; nouvelle classe **CARILLONNEUR** (repli « SONNEUR », N2) ou `HEX_MANIAC` ; musique combat `MUS_VS_AQUA_MAGMA_LEADER` (case `GetBattleBGM`), rencontre `MUS_ENCOUNTER_SUSPICIOUS` ; ID réutilisés : ceux de Max (chef Magma) et d'Arthur (chef Aqua).
- **Âge :** ~80 ans. Sonneuse de glas du Mont Mémoria depuis cinquante ans : elle sonnait à chaque funérailles la cloche qui « laisse partir ». Grand-mère de Spectra (Conseil 4) — secret de coda.
- **Compagnon :** **Augure**, Xatu de soixante ans (voit le passé d'un œil, l'avenir de l'autre `[CANON-JEU : OAC Pokédex]`). Il se meurt.
- **Objectif :** figer le sommet du Mont Mémoria pour qu'Augure ne meure jamais. Moyen : accorder un carillon de cloches anciennes à travers Hoenn ; chaque cloche accordée fige son voisinage.
- **Croyances :** « Ils ne souffrent pas, ils attendent. » « J'ai aidé mille personnes à laisser partir. Je sais ce que ça coûte. » « Un instant parfait vaut mieux qu'une fin. »
- **Ce qu'elle n'est pas :** ni manipulatrice, ni avide de pouvoir, ni démasquée par surprise. Elle dit qui elle est dès New Lavandia.
- **Conflit interne :** elle sait que la cloche peut aussi libérer (son métier même) ; elle a « oublié » volontairement la moitié de la mélodie.
- **Arc (étapes du deuil) :** déni (ch. 4-5 : « rien ne meurt dans un instant ») → colère (ch. 7 : « Vermilava serait cendre sans moi ») → marchandage (ch. 11 : offre au joueur de figer ce qu'il aime) → dépression (ch. 15 : au sommet, épuisée) → acceptation (elle sonne le glas, ch. 15 ; épilogue).
- **Signature mécanique :** Distorsion (vitesse inversée), Requiem (compte à rebours), Prescience (dégâts différés), Vœu, Abri ; Pokémon-cloches et Pokémon du temps ; **jamais de Méga**.
- **Combats :** ch. 11 sommet du Mont Mémoria (Ysaline 1, cap 38) ; ch. 15 sommet du Pilier Céleste (Ysaline 2, cap 50). Postgame : revanche amicale au Mont Mémoria.
- **Équipe-type 1 (cap 38) :** Archéodong (Lévitation, Distorsion), Éoko (Requiem), Téraclope (Distorsion), Branette, Noarfang (Prescience). IA : `Smart Trainer / Ace Pokemon` (premier contact avec l'omniscience ; compensé par ses tells : « Le temps va tourner à l'envers. »).
- **Équipe-type 2 (cap 50) :** Archéodong, Noctunoir, Éoko, Roigada (Prescience/Distorsion), Mesmérella (Distorsion), Branette ; As : Archéodong. IA : `Smart Trainer / Prediction / Ace Pokemon / HP Aware`. **Augure n'est jamais combattu.**

## 8. Augure — le Xatu d'Ysaline
- **Assets :** `OBJ_EVENT_GFX_SPECIES(XATU)`.
- **Rôle :** cœur du mystère (R5). Figé au sommet du Mont Mémoria, face au soleil. Voyant l'avenir, il a envoyé Absol et les visions vers le joueur : il veut partir. Il s'éteint au lever du soleil après le glas (ch. 15). Dans l'épilogue, un **œuf de Natu** (`givemon`/œuf, postgame) est confié à Ysaline — pas au joueur.

## 9. Absol — le messager
- **Assets :** `OBJ_EVENT_GFX_SPECIES(ABSOL)` ; PNJ suiveur pendant l'escorte du Site Météore.
- **Rôle :** apparaît la veille de chaque Figement (affordance narrative) ; traqué par les Veilleurs ; protégé par le joueur (ch. 6).
- **Don :** après le ch. 6, le joueur peut l'accueillir (`givemon`, niveau = plafond courant − 2, talent **Super Chance**, attaques dont Prescience). L'**Absolite** est au sommet du Mont Mémoria (ch. 11).

## 10. Capitaine Rocheval — chef des Veilleurs
- **Assets :** `TRAINER_PIC_EXPERT_M`, OW `OBJ_EVENT_GFX_EXPERT_M` ; nouvelle classe **VEILLEUR** ; musique `MUS_RG_VS_GYM_LEADER` (case `GetBattleBGM`), rencontre `MUS_ENCOUNTER_INTENSE` ; ID réutilisés : Kelvin/Courtney (admins Magma).
- **Passé :** ancien Ranger ; son village de pêcheurs a connu une catastrophe il y a des années, et un Absol avait été vu la veille. Il a perdu son frère.
- **Objectif :** éliminer les Absol de Hoenn pour qu'« il n'y ait plus de veilles ».
- **Croyance :** « Ce qui annonce le malheur l'apporte. »
- **Arc :** certitude → confrontation aux preuves (ch. 11) → honte → allié : au ch. 12-15, ses Veilleurs évacuent Atalanopolis et gardent les abords des Figements. Revanche postgame.
- **Signature mécanique :** **Poursuite**, Regard Noir / Barrage, Piège de Roc, priorité (Vive-Attaque, Pisto-Poing) : punit les changements réflexes.
- **Équipe-type 1 (Site Météore, cap 29) :** Mangriff, Grahyèna (Poursuite), Cornèbre (Poursuite), Ténéfix ; IA `Basic Trainer / Smart Switching / Ace Pokemon`.
- **Équipe-type 2 (repaire, cap 38) :** Corboss, Grahyèna, Démolosse, Tarinorme (Magnépiège), Scalpion ; As Corboss.

## 11. Les Veilleurs (milice)
- **Assets :** `TRAINER_PIC_POKEMON_RANGER_M_FRLG` / `_F_FRLG` (inutilisés), OW `OBJ_EVENT_GFX_CAMPER` / `PICNICKER` ; classe **VEILLEUR** ; ID réutilisés : sbires Magma (~21+).
- **Qui :** pêcheurs, fermiers, parents inquiets. Pas de méchanceté : la peur.
- **Équipes :** Pokémon de chasse et de pièges (Mangriff, Grahyèna, Cornèbre, Tarinor, Racaillou, Ninjask), Poursuite et Regard Noir dès la mi-acte I.
- **Dans le monde :** **avis de recherche** d'Absol (panneaux), filets en travers de chemins secondaires, barrage du téléphérique (ch. 6).

## 12. Les Carillonneurs (fidèles d'Ysaline)
- **Assets :** `TRAINER_PIC_HEX_MANIAC`, `TRAINER_PIC_CHANNELER_FRLG` (inutilisé), `TRAINER_PIC_GENTLEMAN`, `TRAINER_PIC_LADY` ; OW `HEX_MANIAC`, `OLD_MAN`, `OLD_WOMAN`, `GENTLEMAN`, `WOMAN_*` ; classe **CARILLONNEUR** ; rencontre `MUS_ENCOUNTER_SUSPICIOUS`, combat `MUS_VS_AQUA_MAGMA` ; ID réutilisés : sbires Aqua (~31) + Magma restants.
- **Qui :** des endeuillés qu'Ysaline a accompagnés : veufs, orphelins, maîtres d'un Pokémon disparu. Chacun a une phrase sur ce qu'il a perdu (à écrire : une ligne par dresseur).
- **Équipes :** Pokémon-cloches et du temps : Korillon, Éoko, Archéomire, Archéodong, Natu (jamais Xatu, réservé à Augure), Hoothoot/Noarfang, Ramoloss/Flagadoss (Distorsion), Skelénox/Téraclope, Polichombr. Mécaniques : Distorsion, Prescience, Requiem, Abri, Vœu — introduites **une à la fois** (New Lavandia : Prescience ; Institut : Abri/Vœu ; Mont Mémoria : Distorsion ; Fondmer : Requiem).

### 12.1 Les deux Sonneurs (lieutenants)
| | **Bourdon** | **Tierce** |
|---|---|---|
| Assets | `TRAINER_PIC_GENTLEMAN`, OW `GENTLEMAN` | `TRAINER_PIC_LADY`, OW `WOMAN_2` |
| ID réutilisés | Matthieu (admin Aqua) | Sarah (admin Aqua) |
| Qui | veuf, ancien horloger de Poivressel | ~25 ans ; sa mère a disparu dans le naufrage de l'Épave |
| Croyance | « Les horloges mentent : le temps ne passe que si on le laisse. » | « Si le bateau ne coule jamais, elle n'est jamais morte. » |
| Arc | fidèle jusqu'au bout ; s'efface à Atalanopolis | quête « Le Dernier Quart » (Épave) : elle délivre elle-même l'Épave et quitte Ysaline |
| Combats | Institut Météo (ch. 9), Centre Spatial (duo, ch. 12), Pilier Céleste (ch. 15) | New Lavandia (ch. 5), Centre Spatial (duo, ch. 12) ; Épave (annexe) |
| Signature | Distorsion + lents puissants (Ramoloss, Archéodong, Téraclope) | Requiem + Abri (Éoko, Polichombr, Ramoloss) |

## 13. Pierre Rochard (Steven) — collectionneur, puis Maître
- **Assets :** `TRAINER_PIC_STEVEN`, `OBJ_EVENT_GFX_STEVEN`, back pic `steven` (duo).
- **Rôle :** rencontré Grotte Granite (lit la première inscription), Route 120 (Scope Devon, vanilla), **Algatia** (Centre Spatial : duo, puis remet le Méga-Bracelet), **Maître** de la Ligue.
- **Objectif :** comprendre la pierre des cloches (un métal ancien qu'il ne connaît pas).
- **Croyance :** « Les pierres gardent la mémoire du temps ; elles ne l'arrêtent pas. »
- **Ce qu'il n'est pas :** un traître. Aucun retournement.
- **Équipe Maître (cap 58) :** Méga-Métalosse, Armaldo, Kaorine, Galeking, Carchacrok, Corvaillus ; IA `Smart Trainer / Prediction / Weigh Ability Prediction / Ace Pokemon / HP Aware`.

## 14. Marc (Wallace) — gardien d'Atalanopolis
- **Assets :** `TRAINER_PIC_CHAMPION_WALLACE`, `OBJ_EVENT_GFX_WALLACE`.
- **Rôle :** hors du cratère quand la ville se fige ; indique le Pilier Céleste (rôle vanilla conservé). Ne combat pas dans l'aventure ; revanche postgame (ID vanilla Marc).

## 15. Champions d'arène
| # | Champion | Ville / carte | Leçon | Plafond | Équipe-type (intention) | IA |
|---|---|---|---|---|---|---|
| 1 | **Roxanne** | `MAP_RUSTBORO_CITY_GYM` | types et PV | 15 | Racaillou, Tarinor, Kranidos ; As Tarinor (Fermeté) | `Basic Trainer / Sequence Switching / Ace Pokemon` |
| 2 | **Bastien** | `MAP_DEWFORD_TOWN_GYM` | menace et boosts | 19 | Machoc, Méditikka, Makuhita @ Ceinture Force ; Gonflette en tour 1 (tell) | idem + `HP Aware` |
| 3 | **Voltère** | `MAP_MAUVILLE_CITY_GYM` | statut et tempo | 24 | Magnéti, Dynavolt, Voltorbe, Élecsprint ; Cage-Éclair | `Basic Trainer / Smart Switching / Ace Pokemon` |
| 4 | **Adriane** | `MAP_LAVARIDGE_TOWN_GYM_1F` | champ de bataille (soleil) | 29 | Chartor (Sécheresse), Malosse, Galopa, Camérupt ; Feu sous soleil | idem + `Assume Stab` |
| 5 | **Norman** | `MAP_PETALBURG_CITY_GYM` | talents et objets tenus | 33 | voir §5 | idem + `HP Aware` |
| 6 | **Alizée** | `MAP_FORTREE_CITY_GYM` | synergie, immunités, pivots | 38 | Altaria, Hélédelle, Airmure, Corvaillus, Tropius ; Demi-Tour | `Basic Trainer / Smart Switching / Ace Pokemon / HP Aware` |
| 7 | **Lévy & Tatia** | `MAP_MOSSDEEP_CITY_GYM` | Méga + double | 44 | Solaroc, Séléroc, Méditikka @ Méditikkanite (Méga adverse), Gardevoir ; combat double | `... / Double Ace Pokemon` |
| 8 | **Juan** | `MAP_SOOTOPOLIS_CITY_GYM_1F` | adaptation (pluie + Méga) | 50 | Bekipan (Crachin), Milobellus, Kingdra, Lanturn, Léviator @ Léviatorite (seule Méga) | `Smart Switching / Ace Pokemon / HP Aware / Assume Stab` |

Règle (STRATEGY_RESEARCH §8) : écart boss / plafond ≤ +2 (As +3) ; au moins deux réponses obtenables avant chaque combat.

## 16. Conseil 4 et Maître (Éternara)
| Membre | Thème | Mécanique | Note narrative |
|---|---|---|---|
| **Damien** (Sidney) | Ténèbres | pièges, Poursuite (écho des Veilleurs) | ligne sur « juger trop vite » |
| **Spectra** (Phoebe) | Spectre | Distorsion maîtrisée, Requiem (écho d'Ysaline) | **petite-fille d'Ysaline** ; elle remercie le joueur d'avoir « laissé partir Augure » |
| **Glacia** | Glace | grêle/neige, Voile Aurore | ligne : « La glace aussi fond. » |
| **Aragon** (Drake) | Dragon | Méga-Drattak, Danse Draco | ancien marin ; a connu le naufrage de l'Épave |
| **Pierre** | Acier/Roche | Méga-Métalosse, synthèse | voir §13 |

## 17. Personnages secondaires
| Personnage | Assets | Rôle |
|---|---|---|
| **M. Marcel** (Briney ; nom FR ◐ « M. Marcel » utilisé par ASSET_INVENTORY) et **Peeko** | OW vanilla | Peeko figé au Bois Clémenti ; bateau vers Myokara/Poivressel (portes vanilla) |
| **Conservateur Morel** (Musée Océanographique, remplace le rôle du Capt. Marin) | OW `SCIENTIST_1` | reçoit le fragment de cloche ; analyse « un alliage inconnu » |
| **Directrice du Musée de Nénucrique** | OW `WOMAN_3` | défend l'interprétation officielle ; quête « L'Exposition » |
| **Vieux couple du Mont Mémoria** | OW `OLD_MAN`, `OLD_WOMAN` | gardiens de la Cloche Mère (remplace les Gemmes) ; ils ont formé Ysaline |
| **Prof. Cosmo** (◐) | OW vanilla | Autéquia ; témoigne qu'un Absol est passé « la veille » de l'éruption figée ; indice R2 |
| **Directeur de l'Institut Météo** | OW `SCIENTIST_2` | figé au ch. 9 ; ses relevés montrent le « tintement » avant chaque Figement (indice R1/R2) |
| **Scott** | OW `SCOTT` | postgame : ouvre la Zone de Combat (pas de rôle de mystère) |
| **Voltère** (hors arène) | — | demande de délivrer New Lavandia (quête vanilla réécrite) |
