# ARBITRATION_V3_2 — arbitrage des revues v3, limité à la démo (prologue + ch. 1)

> Arbitre : Game Mechanics Director. Date : 2026-10-14.
> Entrées : `REVIEW_V3_NARRATIVE.md` (N01–N33) et `REVIEW_V3_SYSTEMS.md` (S1–S15 + verdicts par décision).
>
> **Changement de périmètre (utilisateur, contraignant).** On ne construit que la **démo jouable : prologue (ch. 0) + chapitre 1**. Le reste du jeu reste conçu, mais il est mis de côté.
> Cet arbitrage ne tranche donc que :
> - les constats qui touchent les ch. 0–1 ;
> - les règles globales dont dépend la démo.
>
> Tout le reste est **différé** (§3), sans arbitrage. Spécification de la démo : `SLICE_DEMO_CH0-1.md`.
>
> Verdicts :
> - **A** : accepté ;
> - **M** : accepté avec modification ;
> - **R** : rejeté.

## 1. Constats arbitrés (touchent les ch. 0–1)

| # | Constat (résumé) | Verdict | Raison | Où c'est appliqué |
|---|---|---|---|---|
| N02 (partie globale) | La fausse piste de surface doit être « **des humains** ouvrent les anneaux ». R2 deviendra « une machine, et une créature dedans ». | A | La démo pose la surface. Au ch. 1, la Rocket est postée **avant** l'anneau de la R116, et le joueur doit pouvoir croire qu'elle le provoque. Le Kiosque (ch. 3) est hors démo, son correctif est différé. | `SLICE` §4.9 (scène R116) ; bible §4 (renvoi, différé) |
| N09 | La part de Red est artificielle. Il faut une contrepartie qu'il a acceptée. | M | Dans la démo, on **plante** seulement : l'affiche (D009) vient d'un contrat d'image que Red a signé à 11 ans contre la Master Ball. Brice le dit en une boîte si D009 a. La Master Ball donnée au Sommet est différée. | `SLICE` §4.6 |
| N04 (dates) | L'affiche date d'**après** la signature de Passerelle. | A | La date est citée sur l'affiche de la démo : An 0 + 5 mois. | `SLICE` §4.6 |
| N11 | L'accréditation par Norman doit être une **laisse**, pas une faveur. | A | Elle donne un sens au plafond et une menace pendant l'acte I. La réplique de D002 est réécrite. | `SLICE` §4.4 |
| N12 | La Rocket a besoin d'un **visage** recruté parmi les ruinés. | M | Dans la démo, ce visage est le **mineur ruiné** (D015) plutôt qu'un pêcheur. Il reparaîtra aux ch. 4 et 10 (différé). Ariane n'est pas en scène. | `SLICE` §4.10 |
| N17 (Roxanne) | Les Champions de Hoenn sont des figurants. | M | Pour la démo : Roxanne porte la crise des mines avec Pierre (Brock) et lit les données de Red (D016). Sa fonction de fin de partie (experte de M3) est différée. | `SLICE` §4.7–4.8 |
| N18 (budget) | Le volume de texte est intenable. | A | Plafond de la démo : **≤ 400 boîtes**. Règles : scène ≤ 15 boîtes, décision S ≤ 6, M ≤ 15, L ≤ 40. Les dresseurs de route gardent leur texte vanilla neutre, réécrit seulement s'il cite Aqua, Magma ou l'intrigue vanilla. | `SLICE` §7 |
| N30 | Les éclats rouges et bleus sont ambigus. | M | Dans la démo, Ciléo dit au prologue que le Rubis et le Saphir **stabilisent** le nœud. Cela plante la part de Red sans évoquer les titans. Le reste est différé. | `SLICE` §4.1 |
| N32 | Le monde n'a pas de mémoire bon marché (pas de Match Call). | M | Démo : **pas de télévision**. Un panneau « Bulletin des anneaux » au Centre de Mérouville, avec 1 boîte qui varie selon D010. Aucun appel ni Match Call. | `SLICE` §4.11 |
| N33 | Trop de phrases-thèses. | A | **Au plus une phrase-thèse par chapitre**. Dans la démo, c'est Brice à la fin du ch. 1. | `SLICE` §4.11 |
| N03 / N05 / N06 / N07 | Lois du mythe, autre rive, Hisui, pourquoi maintenant. | — | Différé (§3). La démo n'énonce **aucune** loi : elle montre seulement qu'un anneau **amène** (la horde) et **prend** (l'équipe, puis un objet en D014 a). L'enseignement de H1 commence ainsi, sans être verbalisé. | `SLICE` §4.1, §4.9 |
| S1 | Plancher des décisions et marge de 10 %. | A | Le test contrefactuel est maintenant dans le modèle : `cf_model.py --pivot`. Mesure sur le jeu complet après correctifs : **122 VALIDE, dont 19 fragiles** (marge 21 %). Ch. 0–4 : 43/45. La démo applique en plus son propre critère (§2). | `data/cf_model.py`, `data/cf_decisions.py` |
| S6 (ch. 0–1) | Flags orphelins `PIKA_BLESSE`, `MARCO_ALLIE`, `BOIS_SAUVES`, `BROCK_PROTEGES`. | A | Chacun reçoit un lecteur **dans la démo**. Pierre (Brock) : son sélecteur d'équipe est l'**état de Z-02** (`COMBAT_DESIGN`) ; `BROCK_PROTEGES` n'est plus qu'une saillance. | `SLICE` §5 |
| S10 | Le modèle ne borne pas les achats par l'argent. | A | Une option payante est masquée si l'argent manque (D008 b −300 P, D015 a −500 P). C'est appliqué au modèle, et le script de la démo fait le même contrôle. | `cf_model.py` ; `SLICE` §5 |
| S12 | La chaîne de M. Marco (Briney) n'est pas traitée. | A | Spécifiée : Marco visible dès la nouvelle partie, aucune traversée dans la démo, flags vanilla fixés. | `SLICE` §6 |
| S13 (E-REMOVE) | D001 retire **toute** l'équipe, mais `removepartymon` refuse de retirer le dernier Pokémon. | A | Nouvelle aide moteur **E-CLEARPARTY** (vider l'équipe, quelques lignes en ROM). C'est un prérequis de la démo. | `SLICE` §8 |
| S15 / D038 | Un « slot lu » est mal câblé. | — | Ch. 4, différé. | — |
| D004 | Le starter n'est pas une décision narrative. | A | Il reste **non compté**. | `SLICE` §5 |
| D005 | FAIBLE depuis que le Multi Exp est donné partout. | M | Effet **dans la démo** : Brice t'accompagne dès le matin (a) ou reste au labo jusqu'à Mérouville (b). Cela change sa présence à 5 scènes du ch. 1, et un barrage (§5). Le siège de Seko au Sommet (N14) reste le lecteur différé. | `cf_decisions.py` (texte) ; `SLICE` §5 |
| D013 | FAIBLE : chemins identiques. | A | Corrigé : D063 a exige `LAMBDA_REMARQUE`. Dans la démo, « Ferrand » est **reconnu** à la R116 si D013 a, ce qui donne une pièce. | `cf_decisions.py` ; `SLICE` §4.9 |
| D006, D015, D016 | Décisions fragiles (pivot de 10 à 15 %). | M | Chacune reçoit un effet visible **avant la fin de la démo** (§2). | `SLICE` §5 |
| D035 | Le refus ne doit pas fermer la R110. | — | Ch. 3, différé. | — |

**Modifications apportées au modèle (pré-appliquées, hors démo, à arbitrer plus tard dans la bible).** Elles ont été faites avant le changement de périmètre, et elles sont gardées parce que `--check` reste à 0 anomalie :
- **Fins :**
  - F4 « Le Jugement » est une intention **choisie** (D117 e) ;
  - chaque intention a une version payée : SCEAU_BRISÉ, PASSERELLE_AMPUTÉE, PACTE_REFUSÉ ;
  - une fin par défaut dépend du lieu de Red.
- **Sommet :**
  - M1 sans LIBÉRER, remplacée par un appel nominal (D108 c) ;
  - départage par Juan ;
  - Seko cède son siège (N14) ;
  - Sarah, si elle témoigne, fait abstenir Arthur.
- **Amaryllis :** porteur de la preuve de la gardienne et doute au ch. 10.
- **Voie de réparation de Hoopa :** D099, recalibrée en classe M.
- **Petits correctifs :** D039, D048, D055/D062, D066, D091, D120.
- **Personas :** le Rempart choisit le Jugement.

Mesures du modèle (`--sim 3000`) :
- **fins :** F1 28 %, F2 11,6 %, F3 19,6 %, F4 23,4 % (dont 77 % choisies), F5 17,4 % ;
- **Amaryllis :** RENONCE 31 %, SACRIFICE 31 %, PERSISTE 38 % ;
- **argent :** jamais négatif ;
- **`--golden` :** le meilleur chemin trouvé donne F2 + Intégration + Rocket démantelée. Mais les civils sont au mieux **BLESSÉS** (par construction : `cas` = AUCUN exige Red aux civils, et un Pacte confié par un allié est plafonné à BLESSÉS). Il exige aussi la chute du Consortium (`rC` 14, Mérouville au chômage) et Peter à l'écart (PE 50).

Ces modifications ne font **pas** foi dans la bible tant que l'arbitrage différé (§3) n'est pas fait.

## 2. Règle de comptage dans la démo
Une décision de la démo est **comptée** seulement si **chacune** de ses options produit, **avant la fin de la démo**, un effet observable différent sur l'un des éléments suivants :
- un PNJ présent ou absent, ou une réplique d'état ;
- un objet, un Pokémon ;
- un combat ;
- un accès ;
- une table de rencontre ;
- la scène finale.

Si l'effet n'arrive qu'après la démo, la décision est **marquée « après démo » et non comptée**.

Résultat (`SLICE` §5) : **16 décisions comptées** (D001–D003 et D005–D017), **1 non comptée** (D004, le starter).

## 3. Constats différés (non arbitrés)

| Revue | Constats différés |
|---|---|
| Narration | N01, N03, N05, N06, N07, N08, N10, N13, N14 (lecteur au Sommet ; l'effet de démo de D005 est arbitré plus haut), N15, N16, N19, N20, N21, N22, N23, N24, N25, N26, N27, N28, N29, N31 ; N02 (partie Kiosque, ch. 3) ; N09 (Master Ball au Sommet) ; N12 (pêcheur, Ariane, Lance (Rocket)) ; N17 (fonctions de fin des Champions) ; questions §B 1–10 |
| Systèmes | S2 (D048, ch. 5), S3, S4, S5 (lecture relative, D025), S7 (`PA` ≥ 80 à ramener à 70 dans `ENCOUNTERS_PLAN`), S8, S9, S11 (compteur du Tournoi, état d'anomalie E-OUT), S14, S15 ; verdicts FAIBLE hors ch. 0–1 (D030, D033, D042, D046, D055, D066, D067, D085, D091, D099, D103, D106, D120, D122, D125, D129, D130) ; doublon D039 ; estimation d'effort du jeu complet |

## 4. Questions ouvertes pour la démo
1. **Nuit du prologue.** Le RTC ne peut pas être forcé. La nuit est racontée par le texte. Faut-il une teinte nocturne scriptée (aide moteur) ou non ? Décision du GMD : **non** pour la démo.
2. **Équipe légendaire du prologue.** Elle reçoit de l'EXP pendant les 3 combats, puis elle est retirée. C'est sans effet sur le reste, mais à vérifier en test.
3. **Mesure réelle du volume de texte.** On compare le nombre de boîtes dans les scripts à la cible de 400. C'est le premier indicateur de productivité, avant de reprendre le jeu complet.
