# DECISION_LEDGER_POST - Postgame (P1-P8) (*Pokémon Confluence*, brief C)

> Généré par `docs/hack/data/cf_model.py --render` a partir de `docs/hack/data/cf_decisions.py` (source unique). Ne pas éditer à la main : éditer les données puis régénérer.
> Règles, légende, décomptes et audit : `DECISION_LEDGER.md`. Systèmes, seuils et allocation : `GAME_SYSTEMS.md`. **Statut de toutes les entrées : propose (rien n est implémenté ni teste).**
> Accents restaurés au rendu (`cf_accents.py`) : les données sont saisies sans accents. Les répliques en jeu seront écrites par les scénaristes (<= 208 px, 2 lignes, guillemets “ ”).

**Décisions : 6** (E 4 / D 2 ; S 3 / M 3 / L 0 ; comptées 5)

## Postgame

### D126 - Fuji et Mewtwo
`E` · `M` · arbitrage · Postgame · statut **proposé** · verdict **VALIDE**

- **Unité :** CaveOfOrigin_Entrance (anneau) - CF_D126
- **Déclencheur :** Un anneau amene Mewtwo ; Fuji demande qu'on le laisse choisir.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D15 bits 10-11 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Le capturer** - deltas : rG-2, MEWTWO_CAPTURE · différé : Fuji : lettre amere. · [gain : +Mewtwo / perte : rG]
  - **b) Le laisser** - deltas : rG+2, MEWTWO_LIBRE · différé : Mewtwo revient à la Grotte Atelier après la lettre de Fuji (invariant 9 : toujours obtenable). · [gain : rG / perte : -Mewtwo plus tard]
- **Lecteurs (contenu affecté) :** postgame (canal Mewtwo); épilogue Fuji
- **Délai principal :** différé court · signal de mémoire : Lettre de Fuji au postgame (deux variantes).
- **Fins :** aucune.
- **Test :** a : Mewtwo ; b : rencontre ouverte après 1 jour (flag quotidien non utilise : script).

### D127 - Le dernier duel de Giovanni (refusable)
`E` · `S` · combat · Postgame · statut **proposé** · verdict **VALIDE**

- **Unité :** Route101 / SafariZone (selon D125) - CF_D127 (FLAG_CF_REFUS_GIO2)
- **Déclencheur :** 'Une dernière fois. Sans rien d'importe.'
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D15 bits 12-13 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Accepter et gagner** - deltas : GI+3, RK-5 · différé : Giovanni dissout la cellule de Hoenn (sbires retires des routes). · [gain : GI, RK / perte : -Giovanni part (plus de revanche)]
  - **b) Accepter et perdre** - deltas : GI+5, RK+2, -2000 P · différé : sbires restent ; il part 's'entrainer'. · [gain : GI / perte : Argent, RK]
  - **c) Refuser** - deltas : GI-3, RK+2, rI+2 · différé : sbires restent ; la Mission soulagee. · [gain : rI / perte : GI, RK]
- **Lecteurs (contenu affecté) :** postgame (sbires, anneaux voles)
- **Délai principal :** immédiat
- **Fins :** variante Rocket postgame.
- **Test :** slot.

### D128 - Financer une restauration (une seule zone)
`E` · `M` · arbitrage · Postgame · statut **proposé** · verdict **VALIDE**

- **Unité :** RustboroCity_DevonCorp_3F ou SlateportCity - CF_D128
- **Déclencheur :** 10 000 P : Devon (ou la charte) finance une restauration ; une seule zone.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D15 bits 14-15 (0 = non prise ; 1..3 = option)
- **Options :**
  - **a) Z-01 Littoral** - deltas : rP+3, rC-1, Z01 +1 cran, -10000 P · [gain : Écosystème, rP / perte : Argent, rC]
  - **b) Z-03 Lavandia** - deltas : rP+3, rC-1, Z03 +1 cran, -10000 P · [gain : Écosystème, rP / perte : Argent, rC]
  - **c) Z-05 Mers** - deltas : rA+3, rC-1, Z05 +1 cran, -10000 P · [gain : Écosystème, rA / perte : Argent, rC]
- **Lecteurs (contenu affecté) :** E-ECO (zone choisie)
- **Délai principal :** immédiat · signal de mémoire : Panneau 'Restauration financee' dans la zone choisie.
- **Fins :** aucune (postgame).
- **Test :** zone +1 cran ; -10 000 P.

### D129 - Le départ de Blue (Bourg-en-Vol)
`D` · `S` · présence · Postgame · statut **proposé** · verdict **VALIDE**

- **Unité :** LittlerootTown (quai) - CF_D129
- **Déclencheur :** Blue part pour Jadielle ; il tient un Pokeball d'import.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D16 bits 0-1 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Rester sur le quai** - deltas : BL+3 · différé : Blue confie son import à Red pour le 'renvoyer chez lui' par le canal de la fin. · [gain : BL / perte : -temps (Tournoi ferme ce jour)]
  - **b) Partir** - deltas : BL-2 · différé : rien. · [gain : +Tournoi ouvert ce jour / perte : BL]
- **Lecteurs (contenu affecté) :** postgame
- **Délai principal :** immédiat
- **Fins :** aucune.
- **Test :** a : Pokémon reçu.

### D130 - Tournoi des Confluences : la finale
`E` · `S` · arbitrage · Postgame · statut **proposé** · verdict **FAIBLE (liste, non comptée)** (choix de contenu postgame (adversaire), sans état lu ensuite : liste, non compte)

- **Unité :** BattleFrontier_BattleTowerLobby - CF_D130
- **Déclencheur :** Scott propose la finale contre Brice ou contre Blue.
- **Prérequis :** aucun
- **Stockage :** VAR_CF_D16 bits 2-3 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Contre Brice** - deltas : BR+2, BL-1 · différé : Brice T5 (voie BV). · [gain : BR / perte : BL]
  - **b) Contre Blue** - deltas : BL+2, BR-1 · différé : Blue T5. · [gain : BL / perte : BR]
- **Lecteurs (contenu affecté) :** postgame
- **Délai principal :** immédiat
- **Fins :** aucune.
- **Test :** slot.

### D131 - Fin cachée : ouvrir la chambre scellee de Bayar
`D` · `M` · arbitrage · Postgame · statut **proposé** · verdict **VALIDE**

- **Unité :** Route111 (ruinés) / DesertRuins - CF_D131
- **Déclencheur :** Dossier complet et Chen a avoue : Bayar montre la chambre que les anciens ont scellee avant Hoopa.
- **Prérequis :** fin cachée atteinte
- **Stockage :** VAR_CF_D16 bits 4-5 (0 = non prise ; 1..2 = option)
- **Options :**
  - **a) Ouvrir** - deltas : rG-3 · différé : les Regis s'eveillent (canal propre à la fin cachée). · [gain : +Regis plus tôt / perte : rG]
  - **b) Laisser scellé** - deltas : rG+3 · différé : Bayar : 'Cette fois, on sait pourquoi.' · [gain : rG / perte : -Regis par le canal de la fin]
- **Lecteurs (contenu affecté) :** postgame (Regis)
- **Délai principal :** immédiat · signal de mémoire : Bayar note le choix dans le registre de la Zone.
- **Fins :** fin cachée.
- **Test :** Prérequis fin cachée.
