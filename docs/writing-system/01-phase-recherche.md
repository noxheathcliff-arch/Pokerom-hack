# Système d'écriture « de niveau humain » — Phase 1 : recherche

> Statut : rapport de phase 1. Aucun skill final ni script n'est construit ici, conformément à la consigne.
> Date de rédaction : 2026-10-28.

**Légende des étiquettes**

- **[V]** : vérifié dans la source primaire (article, fiche modèle ou CGU lus directement).
- **[S]** : connu seulement par des extraits ou résumés, à vérifier avant de s'appuyer dessus.
- **Établi** : résultat publié et mesuré.
- **Hypothèse** : inférence plausible, non mesurée dans notre cas.
- **Recommandation** : choix de conception que je propose.
- **Non testé** : idée à mesurer avant de l'adopter.

**Note de méthode.** Comme demandé, j'ai confié la recherche à des agents Haiku. Leurs accès web ont échoué (erreurs DNS). J'ai donc vérifié moi-même les sources primaires sur arxiv.org et pangram.com. Tout ce qui est marqué [V] a été lu dans le texte source, pas dans un résumé d'agent.

---

## 1. Ton diagnostic

### 1.1 Causes et symptômes

Ce qu'on remarque dans un texte d'IA (formules toutes faites, triades, « ce n'est pas X, c'est Y », tirets cadratins, conclusions qui résument, phrases de longueur égale) n'est qu'un ensemble de **symptômes**. Les **causes** sont en amont :

1. **La distorsion due à l'instruction-tuning.**
   - Le réglage par instructions et par préférences (RLHF) pousse la distribution du modèle vers des choix sûrs, lisses et consensuels. *Établi* [V] : Chakrabarty et al. 2025 (arXiv 2510.13939).
   - Un modèle de base (non aligné) produit du texte que les détecteurs classent comme humain ; le même modèle après instruction-tuning, non. *Établi* [V] : 2605.19516.
   - Le réglage creuse aussi l'écart sur les traits de Biber (traits linguistiques mesurables). *Établi* [S] : Reinhart et al., 2410.16107.
   - Conséquence : les détecteurs repèrent surtout **les traces de l'alignement**, pas « l'IA » en général.
2. **L'effondrement de mode (mode collapse).** Pour une même consigne, le modèle converge vers un petit nombre de solutions. La variété intra-texte et inter-textes est donc faible. *Établi* [S] : Verbalized Sampling, 2510.01171.
3. **L'absence d'intention et de vraie révision.**
   - Un écrivain sait ce qu'il veut faire ressentir, ce qu'il retient, ce qu'il risque.
   - Il réécrit en changeant la structure, pas seulement les mots (Sommers 1980 ; Flower & Hayes 1981 ; Bereiter & Scardamalia, « knowledge-telling » vs « knowledge-transforming »).
   - Le modèle, lui, écrit d'une traite, de gauche à droite. *Établi* dans la littérature didactique ; l'application aux LLM est une *Hypothèse*.
4. **L'absence de voix singulière.**
   - Une voix, c'est un ensemble cohérent de choix improbables : lexique, rythme, ce qu'on remarque, ce qu'on tait.
   - Un modèle aligné tend vers la voix moyenne.
   - L'imitation par exemples en contexte aide un peu. L'entraînement sur le corpus d'un auteur aide beaucoup. *Établi* [V] : Chakrabarty 2025 ; Catch Me If You Can, 2509.14543.

### 1.2 Ce que des instructions seules ne peuvent pas corriger

- **Établi** [V], Chakrabarty 2025 :
  - Avec des consignes rédigées par des experts et des exemples de l'auteur en contexte, Pangram détecte encore **97 %** des extraits générés.
  - Après fine-tuning sur le corpus de l'auteur, il n'en détecte plus que **3 %**.
  - La densité de clichés n'explique qu'environ **16 %** de l'effet du détecteur ; trois traits réunis, environ **25 %**.
  - Donc **les trois quarts du signal ne viennent pas de ce qu'une liste noire peut supprimer.**
- Une instruction modifie ce que le modèle choisit parmi ses options probables. Elle ne change pas la **forme de la distribution** elle-même.
- Claude n'expose pas les probabilités des tokens (logprobs), donc pas d'échantillonneur anti-slop au niveau du token comme Antislop (2510.15061). Il n'offre pas non plus de fine-tuning sur les modèles actuels. Seul Claude 3 Haiku était réglable via Bedrock [S].
- Conséquence : un skill (instructions, exemples, boucle de révision) peut beaucoup améliorer la **qualité**. Son effet sur le **score Pangram** est probablement modeste et doit être mesuré, pas supposé. *Hypothèse*, cohérente avec les données ci-dessus.

### 1.3 Hypothèses fausses dans le brief

1. **« Un skill peut rendre l'IA indétectable. »**
   - Les données disponibles disent le contraire pour les approches en contexte (97 % détectés).
   - Le levier qui fonctionne le mieux (le fine-tuning) est hors de Claude.
2. **« Si ça passe sur un passage, ça passera sur un livre entier. »**
   - C'est l'inverse : plus le texte est long, plus il est facile à détecter (Chakraborty et al. [S]).
   - Pangram découpe le texte en fenêtres de 512 tokens qui se chevauchent [V]. Un roman de 80 000 mots en compte plus de 200.
   - Illustration : si chaque fenêtre « passait » indépendamment avec 90 % de chances, tout le livre passerait avec 0,9^200 ≈ 10⁻⁹.
   - Les fenêtres d'un même livre sont corrélées, donc ce calcul exagère, mais la direction reste vraie.
   - En plus, Pangram renvoie une **fraction** d'IA au niveau du document, pas un verdict binaire.
3. **« On peut humaniser après coup. »**
   - Pangram 4 a une tête dédiée aux humaniseurs (`humanizer_score`, seuil `is_humanized` à 0,91) et une tête « AI-assisted » [V].
   - Il normalise l'Unicode et les homoglyphes [V].
   - DAMAGE (2501.03437) a testé 19 humaniseurs et trouve Pangram robuste [S].
   - Les « erreurs artificielles » sont exclues par ton brief, à juste titre.
4. **« Un meilleur score Pangram = une meilleure écriture. »**
   - C'est la loi de Goodhart : une mesure qui devient une cible cesse d'être une bonne mesure.
   - Chakrabarty montre une corrélation : un score de détecteur plus élevé va avec moins de préférence des lecteurs experts. Une corrélation ne garantit pas qu'optimiser l'un améliore l'autre.
   - Un paraphraseur basé sur un modèle de base (HIP, 2605.19516) fait tomber les détecteurs [V] sans rien dire de la qualité ni de la fidélité au sens.
5. **« Un bon résultat est définitif. »** Pangram est réentraîné régulièrement : la version 4 a ajouté les têtes AI-assisted et humaniseur. Tout résultat est daté et lié à une version.
6. **« Un LLM peut juger la qualité d'écriture. »**
   - TTCW (2309.14556) : aucun juge LLM n'est corrélé positivement aux experts [V].
   - WQ (2504.07532) : la plupart des LLM sont proches du hasard pour juger la qualité [V].
   - Le système ne peut donc pas reposer sur Claude comme juge final.

---

## 2. Les conclusions de tes recherches

### 2.1 Comment fonctionne Pangram

**Rapport technique (arXiv 2402.14873) [V]**
- Classifieur Transformer entraîné avec du *hard negative mining* : on cherche les exemples les plus difficiles.
- Les « miroirs synthétiques » sont des textes IA générés pour imiter chaque texte humain du corpus (même sujet, même genre, même longueur).
- Le modèle apprend donc la différence de **manière**, pas de **sujet**.
- Le rapport annonce un taux d'erreur plus de 38 fois inférieur aux outils commerciaux et un faux positif très bas, y compris pour des non-natifs de l'anglais.

**Fiche modèle Pangram 4 [V]**
- Quatre têtes de sortie :
  - une tête de segment à 15 classes ;
  - une tête de provenance par token à 3 classes (Human / AI-Assisted / AI-Generated) ;
  - une tête binaire « autorat mixte » ;
  - une tête humaniseur à 4 classes.
- Fenêtres de 512 tokens qui se chevauchent ; les prédictions sont moyennées. Le plus petit segment fait environ deux phrases.
- Entrée minimale : 50 mots de prose. Hors domaine : réponses courtes, code, gabarits, manuels.
- Sortie au niveau du document : `fraction_human`, `fraction_ai_assisted`, `fraction_ai`, pondérées par caractères.
- Données d'entraînement sous licence : essais, écriture créative, livres, presse, etc.
  - Pas de données utilisateurs ni d'API.
  - Le texte IA est généré en interne (miroirs).
  - L'« AI-assisted » est produit en faisant éditer des textes humains par des IA.

### 2.2 Taux d'erreur publiés (Pangram 4) [V]

FNR = textes IA classés humains (faux négatifs). FPR = textes humains classés IA (faux positifs).

| Mesure | Corpus | Taux | n |
|---|---|---|---|
| FNR | Anglais, 26 générateurs | 0,34 % | 519 993 |
| FNR | Multilingue, 18 langues | 1,24 % | 190 149 |
| FNR | Français | 1,78 % | — |
| FNR | Écriture créative | 0,27 % | 41 940 |
| FNR | Écriture académique | 0,00 % | 48 443 |
| FPR | Écriture créative longue (anglais) | 0,000 % | 10 495 |
| FPR | Poésie | 0,078 % | 12 769 |
| FPR | Scénarios | 0,010 % | 9 989 |
| FPR | Français | 0,0026 % | — |
| FPR | FineWeb2, 104 langues | 0,0014 % | — |

**Comment lire ces chiffres**
- **Établi** : le FNR français est environ cinq fois plus élevé que l'anglais.
- **Hypothèse** : ce n'est pas forcément vrai pour la fiction. L'évaluation multilingue n'utilise que des miroirs de tutoriels, d'actualités et d'avis, **pas de fiction** [V].
- Ces chiffres sont mesurés par l'éditeur, sur ses propres corpus. Les rares évaluations indépendantes que j'ai vues vont dans le même sens : Chakrabarty (0 faux positif humain sur leur corpus, GPTZero moins bon) et DAMAGE [S]. Mais elles ne couvrent pas tout.
- **Faux positifs connus des détecteurs en général** : 61 % de faux positifs sur des essais TOEFL avec les anciens détecteurs (Liang et al. 2023 [S]). Pangram dit corriger ce point. Les textes très formatés (recettes, manuels, juridique) restent des zones de risque, et Pangram les déclare d'ailleurs hors domaine.

### 2.3 Lire un score Pangram

- **Le score est une proportion, pas une probabilité.** `fraction_ai = 0,3` veut dire « environ 30 % des caractères sont dans des segments classés IA ». Cela ne veut pas dire « 30 % de chances que ce soit de l'IA ».
- **Un résultat isolé ne prouve rien.**
  - Un texte classé humain une fois peut être reclassé avec une autre version du modèle, une autre longueur ou un autre découpage.
  - Seul un **taux sur un échantillon pré-enregistré** est interprétable, avec intervalle de confiance.
  - Exemple : 0 détection sur 10 textes donne un intervalle de Wilson à 95 % de 0 à 28 %. Ce n'est pas « indétectable ».
- **Toujours noter** la version de Pangram, la date, la longueur, le genre et la langue.
- **Ne jamais dire « indétectable ».** Au mieux : « classé humain par Pangram vX à la date D sur N textes, intervalle [a, b] ».

### 2.4 Conditions d'usage (CGU Pangram, mise à jour du 14 août 2025) [V]

- Accès interdit par un moteur, outil ou agent autre que leurs propres logiciels. → **Utiliser uniquement l'API officielle ou leur serveur MCP**, jamais de scraping de l'interface web.
- §5.2(c) : interdiction d'« interfere with or circumvent any feature of the Service ». **Optimiser un texte en boucle contre Pangram** pour le faire passer est au minimum une **zone grise**. → **Recommandation** : Pangram sert d'**instrument de mesure** sur un jeu de test figé, jamais d'oracle dans une boucle de génération.
- §5.1 : licence « solely for your internal business use ».
- Tarifs [V] :
  - Individual : 20 $/mois, 300 000 mots, essai gratuit de 7 jours.
  - Professional : 65 $/mois, 5 fois plus de mots, plus 200 $/mois de crédits API.
  - API développeur à crédits.

### 2.5 Ce que disent les recherches sur l'écriture

| Source | Résultat | Statut |
|---|---|---|
| Chakrabarty et al. 2025 (2510.13939) | IA en contexte : 97 % détectés. IA fine-tunée sur l'auteur : 3 %. Les experts préfèrent le fine-tuné (rapport de cotes 1,87). Coût d'environ 81 $ par auteur. Extraits jusqu'à 450 mots. | Établi [V] |
| Modèles de base (2605.19516) | Le texte de modèle de base passe pour humain auprès des détecteurs. Le paraphraseur HIP trompe les deux détecteurs testés. | Établi [V] |
| TTCW (2309.14556) | 14 tests de créativité (fluidité, flexibilité, originalité, élaboration). Les LLM échouent plus que les humains. Aucun juge LLM n'est corrélé aux experts. | Établi [V] |
| Agents' Room (2410.02603) | Une décomposition multi-agents guidée par la narratologie (planification, puis écriture par scène) est préférée par les experts à la génération d'un seul bloc. | Établi [V] |
| WQRM (2504.07532) | Un modèle de récompense pour la qualité d'écriture atteint 74 % d'accord avec des experts. La révision best-of-N guidée par WQRM gagne dans 66 % des cas, et 72 % quand l'écart de score dépasse 1. Les modèles sont publiés. | Établi [V] |
| Catch Me If You Can (2509.14543) | L'imitation en contexte marche pour l'actu et les e-mails, beaucoup moins pour les blogs et forums (styles informels). | Établi [V] |
| EditLens (2510.03154) | Détecte le degré d'édition par IA (F1 de 94,7 % en binaire, 90,4 % en ternaire). Publication annoncée. | Établi [V] |
| Antislop (2510.15061) | Certains motifs sont plus de 1000 fois sur-représentés chez les LLM. Un échantillonneur à retour arrière gère plus de 8000 motifs. Le fine-tuning FTPO réduit le slop de 90 %. Nécessite les logprobs (pas disponibles sur Claude). | Établi [V] |
| Verbalized Sampling (2510.01171) | Demander au modèle plusieurs réponses avec leurs probabilités verbalisées augmente la diversité de 1,6 à 2,1 fois. | Établi [S] |
| Kobak et al. ; Shaib et al. | Lexique sur-représenté depuis 2023 (« delve »…). Gabarits syntaxiques (suites de catégories grammaticales) caractéristiques des LLM. | Établi [S] |

### 2.6 Les dimensions à couvrir

**Générales (tous genres)**
- **Idées.** Une thèse ou un enjeu qui coûte quelque chose. Pas de consensus mou.
- **Lexique.** Éviter le lexique sur-représenté. Préférer le mot concret et précis au mot « joli ».
- **Syntaxe.** Varier les structures, pas seulement les longueurs. Éviter les gabarits répétés.
- **Rythme.** Une variance de longueur qui suit le sens, pas une alternance mécanique.
- **Ordre de l'information.** Connu → nouveau ; le poids en fin de phrase (Williams).
- **Voix.** Cohérente et singulière.
- **Spécificité.** Détails vérifiables ou sensoriels, pas génériques.
- **Structure asymétrique.** Pas de symétrie en trois parties ni de conclusion qui résume.
- **Révision.** Une réécriture structurelle, pas cosmétique.

**Dimensions ajoutées**
- **Prévisibilité (surprisal).** Choisir parfois l'option juste mais non attendue. *Hypothèse* : c'est probablement ce que les détecteurs captent indirectement.
- **Variation de registre** à l'intérieur d'un même texte, comme le font les humains.
- **Sous-texte et non-dit.**
- **Typographie française.** Guillemets « », tiret de dialogue, espaces insécables. *Hypothèse* : un détecteur entraîné surtout sur l'anglais pourrait réagir aux conventions typographiques. À tester.
- **Mémoire longue.** Rappels, motifs qui reviennent, cohérence sur 100 pages.
- **Découpage des paragraphes.**

**Propres à chaque genre**
- **Fiction.** Équilibre scène/résumé, point de vue tenu, style indirect libre, pas d'émotions nommées quand elles peuvent être montrées.
- **Dialogue.** Non-réponses, interruptions, malentendus, idiolectes distincts. Les personnages ne s'expliquent pas mutuellement l'intrigue.
- **Essai.** Une thèse risquée et de vraies objections, pas des objections de paille.
- **Article.** Des sources vérifiables et **aucun fait inventé**. C'est une contrainte dure, pas un choix de style.

### 2.7 Comparaison des six approches

| Approche | Effet probable sur Pangram | Effet sur la qualité | Coût | Statut |
|---|---|---|---|---|
| Instructions persistantes | Faible (97 % détectés en contexte chez Chakrabarty) | Moyen | ≈ 0 | Établi pour la détection, Hypothèse pour la qualité |
| Exemples avec analyses | Faible à moyen | Moyen à fort si les exemples sont bien choisis | Faible | Établi (Catch Me), dépend du genre |
| Boucle générer–évaluer–réviser | Non mesuré | Fort si l'évaluateur est fiable (WQRM, pas un juge LLM) | 3 à 5 fois les tokens | Établi pour la qualité (WQRM) |
| Imitation de voix (corpus) | Fort **avec entraînement**, faible en contexte | Fort | Selon la méthode | Établi |
| Outils externes (scripts, détecteurs) | Instrument de mesure, pas levier | Indirect | Faible | Recommandation |
| Fine-tuning | **Le plus fort démontré** (3 % détectés) | Positif selon les experts | Hors de Claude (modèle ouvert + GPU loué) | Établi |

- HIP (paraphrase par un modèle de base) est efficace contre les détecteurs.
- **Recommandation** : ne pas en faire le cœur du système. C'est un blanchiment après coup, il pose des risques de dérive du sens et de conformité aux CGU, et il n'améliore pas l'écriture.

---

## 3. Les ressources que tu souhaites obtenir de moi

Je ne demande que ce qui a un usage identifié.

### Priorité 1 — indispensable pour la phase 2

1. **Un accès Pangram conforme.**
   - Le plan Professional (qui inclut des crédits API) ou une clé API développeur.
   - La clé doit être stockée comme variable d'environnement de l'environnement cloud, **jamais dans le dépôt**.
   - Usage : mesurer la ligne de base puis chaque version du skill.
2. **Un corpus humain de référence**, selon les spécifications ci-dessous.
   - Usage : calibrer les faux positifs dans *nos* conditions et servir d'étalon de qualité.
3. **Tes propres textes ou ceux d'un auteur cible**, s'il y a une voix à viser.
   - Pour l'imitation en contexte : 5 000 à 20 000 mots suffisent.
   - Pour un éventuel fine-tuning : beaucoup plus (*Non testé* ; Chakrabarty utilise des corpus d'auteurs publiés).
4. **10 à 20 textes générés par IA que tu trouves mauvais**, avec une ligne sur ce qui te gêne.
   - Usage : calibrer *ton* goût, que je ne peux pas deviner.

### Spécification du corpus de test Pangram

**Genres (5)** : nouvelle, chapitre de roman, essai, scène de dialogue, article.

**Longueurs**
- **Court** : 350 à 500 mots, soit environ une fenêtre Pangram.
- **Moyen** : 1 500 à 2 500 mots.
- **Long** : 8 000 à 12 000 mots, pour roman et essai seulement.

**Quantités**
- 10 textes par genre et par longueur (court et moyen) : 100 textes.
- Plus 3 longs en roman et 3 longs en essai : 6 textes.
- Environ **182 000 mots humains**.

**Conditions IA**
- Je génère moi-même les deux conditions IA (ligne de base et méthode) à partir de consignes dérivées de chaque texte humain, sur les mêmes sujets.
- Environ 365 000 mots, soit **environ 550 000 mots par tour complet**. C'est ce qui justifie le plan Professional.

**Pilote possible pour commencer**
- 3 genres × 2 longueurs × 10 textes × 3 conditions, environ 220 000 mots.
- Avec N = 10 par cellule, c'est un **pilote**, pas une preuve.

**Contraintes sur les textes humains**
- Provenance humaine certaine : écrits avant fin 2022, ou textes inédits de toi.
- Contemporains (après 1980). Pas de prose du XIXᵉ siècle tombée dans le domaine public : trop différente de ce qu'on vise, et elle biaiserait la comparaison.
- Écrits à l'origine dans la langue cible, pas traduits.
- Jamais retouchés par une IA.
- En texte brut (.txt ou .md).

**Mise en garde** : des livres publiés peuvent faire partie des données d'entraînement de Pangram. Leur faux positif paraîtra alors meilleur qu'en réalité. Des textes inédits sont plus informatifs.

### Livres (PDF), par ordre de priorité

Ils apportent moins que le corpus : ce sont des règles, pas des données. Il faut des exemplaires acquis légalement. J'en extrairai des règles et de courts extraits annotés, jamais de reproduction.

1. Joseph M. Williams & Joseph Bizup, *Style: Lessons in Clarity and Grace*, 12ᵉ éd., Pearson, 2016. Phrase, information connue/nouvelle, cohésion.
2. Renni Browne & Dave King, *Self-Editing for Fiction Writers*, 2ᵉ éd., HarperCollins, 2004. Révision de fiction, dialogue, scène/résumé.
3. Ursula K. Le Guin, *Steering the Craft*, Mariner Books, 2015. Rythme, point de vue, voix.
4. Virginia Tufte, *Artful Sentences: Syntax as Style*, Graphics Press, 2006. Catalogue de syntaxes réelles.
5. Antoine Albalat, *Le Travail du style enseigné par les corrections manuscrites des grands écrivains*, 1903. Domaine public : **je peux le chercher moi-même** sur Gallica ou Wikisource, rien à fournir.
6. Optionnel : James Wood, *How Fiction Works*, 2008. Style indirect libre, détail.

### Ce que je peux faire sans aucun fichier

- Rédiger le protocole de test et son pré-enregistrement.
- Construire des listes noires FR/EN à partir de sources publiques (listes Antislop sous licence MIT, lexique de Kobak).
- Écrire les scripts locaux de stylométrie et de détection de motifs.
- Générer les textes de ligne de base Claude.
- Utiliser des textes du domaine public comme contrôles pour tester les scripts. Ils ne conviennent pas comme référence Pangram.

### Ce que je ne peux pas faire sans toi

- Obtenir des scores Pangram.
- Juger selon ton goût.
- Connaître la voix visée.

### Quatre questions

1. **Langue cible** : français, anglais, ou les deux ? Cela double le corpus et les mesures.
2. **Accès Pangram** : quel plan, ou une clé API ?
3. **Fine-tuning** d'un modèle ouvert (par exemple Qwen3 8B ou Gemma, sur GPU loué) : acceptable, ou hors périmètre ?
4. **Voix et usage** : quelle voix (la tienne ? un auteur ?) et combien de texte existant ? Pour quel usage ou quelle publication ?

---

## 4. La direction méthodologique envisagée

### 4.1 Architecture en couches (Recommandation)

Les couches restent séparées pour respecter tes distinctions : instructions persistantes, récupération de documents, récupération d'exemples, scripts de contrôle, entraînement réel.

| Couche | Nature | Contenu | Où ça marche |
|---|---|---|---|
| **L1** | Instructions persistantes | Un `SKILL.md` court : processus (Sommers, Flower & Hayes), règles de phrase (Williams), règles anti-slop compactes, échantillonnage verbalisé (plusieurs options, en choisir une peu probable mais juste) | claude.ai et Claude Code |
| **L2** | Récupération d'exemples | Extraits humains annotés (« ce qui marche ici et pourquoi »), chargés **par genre**, à la demande | claude.ai et Claude Code |
| **L3** | Pipeline | Planification à la Agents' Room (intention, enjeux, structure), brouillon, critique par dimension par des sous-agents Haiku (peu coûteux, un par dimension), révision structurelle. **2 tours maximum.** | Claude Code |
| **L4** | Scripts de contrôle déterministes | Variance des phrases, densité de lexique sur-représenté, gabarits syntaxiques, répétitions, typographie FR. **Aucun LLM** : rapide, gratuit, reproductible. | Claude Code |
| **L5** | Mesure externe | Pangram par l'API officielle, **uniquement** sur un jeu de test pré-enregistré, en lot, jamais dans une boucle par texte | Claude Code |
| **L6** | Entraînement réel (optionnel) | LoRA sur un modèle ouvert, ou « écrivain de voix » sur modèle de base, hors de Claude | Infrastructure séparée |

**Justification**
- L1 et L2 coûtent peu, ajoutent peu de latence et se maintiennent facilement. Ils portent la qualité.
- L3 ne se déclenche que pour les textes qui le méritent.
- L4 remplace les jugements LLM peu fiables par des mesures objectives des symptômes.
- L5 dit la vérité sur l'effet réel.
- L6 n'est construit que si L1 à L4 ne suffisent pas **et** si tu l'acceptes.

### 4.2 La place de Pangram et les précautions

1. **Pré-enregistrement.**
   - Avant toute mesure, on fige les consignes, les conditions et les métriques.
   - On note tous les échantillons et on n'en écarte aucun.
2. **Trois conditions sur les mêmes consignes** : texte humain, Claude de base, Claude + méthode.
3. **Mesures rapportées**
   - Distributions au niveau des fenêtres et des documents, médianes.
   - Taux de classement humain avec intervalles de Wilson.
   - Résultats séparés par genre et par longueur.
4. **Séparation dev/test.** On itère sur le jeu dev. Le jeu test n'est mesuré qu'une fois par version majeure. Sinon on sur-ajuste au détecteur.
5. **Garde-fou qualité**
   - Lecture à l'aveugle par toi, en préférence par paires, plus une grille TTCW adaptée.
   - **Une version qui gagne sur Pangram mais perd en qualité est rejetée.**
6. **Traçabilité** : version de Pangram, date et coût sont enregistrés avec chaque résultat.
7. **Vocabulaire** : jamais « indétectable ». On dit « taux de classement humain par Pangram vX ».

### 4.3 Métriques de progrès non mécaniques

- **Préférence à l'aveugle** : toi, et idéalement un second lecteur.
- **Taux de réécriture** : quelle part du texte tu modifies avant de l'accepter. C'est la mesure la plus honnête de l'utilité réelle.
- **Grille TTCW adaptée**, notée par un humain.
- **Indicateurs secondaires** (L4) : détails spécifiques pour 1 000 mots, densité de clichés.
  - Ce sont des **indicateurs, pas des objectifs**.

### 4.4 Ce qui reste à vérifier

- L'effet de L1 à L4 sur Pangram, **en français** : *Non testé*.
- Le FNR français plus élevé tient-il pour la fiction ? *Hypothèse*.
- EditLens est-il disponible ? WQRM fonctionne-t-il en français ? *Non testé*.
- La taille de corpus nécessaire pour un fine-tuning de voix : *Non testé*.
- La cohérence sur texte long (chapitres, livre) : *Non testé*. C'est le point le plus difficile, parce que la détection s'accumule sur la longueur.

### 4.5 Éthique (court)

- L'objectif défendable est **la qualité d'écriture**, pas la tromperie.
- Amazon KDP exige de déclarer le contenu généré par IA [S]. Les contextes académiques interdisent généralement l'usage non déclaré.
- Le système sera documenté comme outil d'amélioration de l'écriture. Pangram y sert d'instrument de contrôle, pas de cible à contourner.

---

## 5. La prochaine étape concrète

**Phase 2 : mesurer la ligne de base avant tout skill.**

1. **Toi** : réponds aux quatre questions de la section 3. Fournis l'accès Pangram (clé en variable d'environnement) et un premier lot du corpus, au moins le pilote.
2. **Moi** :
   - je rédige le protocole pré-enregistré ;
   - j'écris le script de notation par l'API Pangram et les scripts L4 ;
   - je génère les textes de ligne de base Claude à partir des consignes dérivées de ton corpus.
3. **Rapport de ligne de base** par genre et par longueur : Pangram, indicateurs L4 et ta lecture à l'aveugle.
4. **Seulement ensuite**, le skill v0 (L1 + L2). On le mesure contre la ligne de base sur le jeu dev, puis une fois sur le jeu test.

Sans cette ligne de base, il serait impossible de savoir si le skill améliore quoi que ce soit, ni dans quelle mesure.

**Note pratique.** Ce dépôt (`Pokerom-hack`) est un projet de ROM hack sans rapport avec ce travail. Le rapport y est rangé dans `docs/writing-system/` pour ne pas le perdre. Pour la phase 2 (scripts, corpus, résultats), un dépôt dédié serait plus propre.
