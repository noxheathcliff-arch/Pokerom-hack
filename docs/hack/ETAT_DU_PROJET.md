# État du projet — Confluence (pokeemeraude-expansion)

> Résumé de reprise pour une nouvelle IA ou un nouveau contributeur. Dernière mise à jour : 2026-10-16.
> Document de suivi court. La source de vérité détaillée reste `task.md`, `DECISION_LEDGER*.md` et `ENGINE_CHANGES.md`.

## 1. Le projet en une phrase

**Confluence** est un ROM hack français de Pokémon Émeraude, construit sur `pokeemeraude-expansion` (lui-même basé sur pokeemerald-expansion, RHH et Qigast). Le scénario relie Kanto et Hoenn : Red, Brice et d'autres personnages de Kanto arrivent à Hoenn, et une Brigade du Rempart surveille les Pokémon qui tombent d'un anneau.

Le périmètre actuel est une **démo jouable : prologue (chapitre 0) + chapitre 1**. Le reste du jeu est conçu dans les docs mais pas encore implémenté.

## 2. Où on en est

- **Branche de travail :** `ccr-5b2ad437-a1o6hr` (poussée sur `origin`). Commit de tête : `713e31f`.
- **Build :** `make -j4` produit `pokeemeraude.gba`, sans erreur.
- **Tests (`make check`) :** 4978 OK, 0 échec. Une assertion `ASSUMPTIONS_FAILED` est attendue (`test/hack_engine.c:88`, plafond d'EXP en build de test).
- **QA visuelle :** faite sur le build `7321e53`. Les corrections de dialogues (`25e5135`) et de finitions (`4996323`) n'ont pas encore été rejouées en jeu.

### Ce qui est fait et vérifié en jeu (7321e53)
- Orientation des PNJ au début : Gyarados, portail, Celio qui se tourne vers Red puis vers le portail.
- Le photographe est visible dans la scène de l'affiche (C4).
- Brice soigne l'équipe quand on lui parle (PV 3 → 22 testés).
- Carte de dresseur avec le sprite de Red, badge 1 affiché.
- Pierre reconnaît Red et son combat est forcé.
- La Brigade est expliquée par un PNJ.
- Aucun débordement de texte détecté.

### Ce qui est fait mais pas rejoué en jeu
- **Dialogues (`25e5135`) :** répliques de Pierre selon le choix Charbi (protégés / relevés / abattus), Pierre connaît Roxanne, Roxanne ne reconnaît plus Red trois fois, Norman nomme la « Brigade du Rempart », Calvin reconnaît Red, typographie des dresseurs (apostrophes ’, espaces avant ! et ?).
- **Finitions moteur (`4996323`) :**
  - textes de stats en français (« Attaque de X augmente ! ») ;
  - « X veut se battre ! » et « SBIRE ROCKET » ;
  - Celio, Marco et Red se tournent vers Pikachu pendant sa course ;
  - Brice ne propose pas de soin si l'équipe est en pleine forme (`CF_PartyNeedsHeal`) ;
  - réparation des anciennes sauvegardes où Brice n'a plus de script (`CF_RepairFollowerNPCScript`) ;
  - « DURÉE JEU » avec accent.
  - Documenté en CF-24 à CF-28 dans `docs/hack/ENGINE_CHANGES.md`.

### Ce qui est ouvert
1. **Bug d'affichage des PP** (signalé par le joueur) : non reproduit. Il faut savoir : quel Pokémon, quelle attaque, quel écran, et ce qui s'est passé juste avant.
2. **Réparation d'ancienne sauvegarde** : pas testée en émulateur.
3. **Chaussures de course** : elles viennent de `FLAG_SYS_B_DASH`, posé dans `CF_DemoNewGameInit` (`src/confluence.c`). Elles ne s'appliquent qu'aux **nouvelles parties**. Maintenir B pour courir.
4. **Soin de Brice et carte de dresseur de Red** : aussi valables pour les nouvelles parties. Vérifier sur une vraie partie neuve.
5. **Rejouer la QA** (vision Sonnet + gbaplay) sur `713e31f` avant la prochaine livraison.

## 3. Règles impératives

- **Dépôt public.** Ne jamais committer `.gba`, `.sav`, `.ss`, captures d'écran, JSON de compétences, ni texte de livre.
- **ROM commerciale.** Ne jamais la publier, ni une copie, ni la ROM compilée, dans un dépôt public. Garder la ROM originale intacte.
- **Aucune dépense.** Aucune API payante ni option facturée sans accord explicite.
- **Push** : uniquement sur `ccr-5b2ad437-a1o6hr`, avec `git push -u origin ccr-5b2ad437-a1o6hr`. Pas de PR sauf demande explicite.
- **Messages de commit** : pas d'identifiant de modèle IA.
- **Textes en jeu** : lignes ≤ 208 px (`scratchpad/textwidth.py`). Apostrophe ’, guillemets “ ”, jamais « » dans les scripts.
- **Worktrees** : un nouveau worktree a besoin de `tools/compresSmol` copié depuis le dépôt principal (ignoré par git).

## 4. Commandes utiles

```
make -j4
make check -j4 ROMTEST=/opt/mgba-tools/bin/mgba-rom-test ROMTESTHYDRA=/opt/mgba-tools/bin/mgba-rom-test-hydra
```

- Émulateur headless : `/opt/mgba-tools/bin/gbaplay`.
- Scripts QA : `tools/qa/scripts/` (les fichiers `_tmp*` sont ignorés par git).
- Fichiers à consulter pour un changement de scénario : `data/scripts/cf_prologue.inc`, `data/scripts/cf_chapter1.inc`, `data/scripts/cf_brice_follower.inc`.

## 5. Conventions du scénario

- « Pierre » = Brock. « Pierre Rochard » = Steven.
- Red ne parle pas : ses choix sont des gestes proposés par un menu.
- Le nom du joueur est forcé à RED au début de partie : « Red » écrit en dur dans les textes est donc correct.
- Chronologie : l'histoire se passe un an après que Red est devenu Maître de Kanto.

## 6. Où chercher quoi

| Sujet | Document |
|---|---|
| Suivi central et exigences | `docs/hack/task.md` |
| Design du jeu | `docs/hack/GAME_DESIGN_BIBLE.md` |
| Décisions scénaristiques | `docs/hack/DECISION_LEDGER*.md` |
| Spécification de la démo | `docs/hack/SLICE_DEMO_CH0-1.md` |
| Modifications moteur (CF-xx) | `docs/hack/ENGINE_CHANGES.md` |
| Flags et variables | `docs/hack/FLAGS_VARS_REGISTRY.md` |
| Outils de QA | `docs/hack/QA_TOOLING.md` |
| Personnages et lore | `docs/hack/CHARACTER_AND_LORE.md`, `docs/hack/CAST_DOSSIER.md` |
