const struct AbilityInfo gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("Pas de capacité spéciale."),
        .aiRating = 0,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STENCH] =
    {
        .name = _("Puanteur"),
        .description = COMPOUND_STRING(
            "Repousse POKéMON sauvage."
        ),
        .aiRating = 1,
    },

    [ABILITY_DRIZZLE] =
    {
        .name = _("Crachin"),
        .description = COMPOUND_STRING(
            "Le Pokémon invoque la pluie quand il\n"
            "entre au combat."
        ),
        .aiRating = 9,
    },

    [ABILITY_SPEED_BOOST] =
    {
        .name = _("Turbo"),
        .description = COMPOUND_STRING(
            "Améliore la VITESSE."
        ),
        .aiRating = 9,
    },

    [ABILITY_BATTLE_ARMOR] =
    {
        .name = _("Armurbaston"),
        .description = COMPOUND_STRING(
            "Bloque les coups critiques."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_STURDY] =
    {
        .name = _("Fermeté"),
        .description = COMPOUND_STRING(
            "Protège des capacités mettant K.O. en\n"
            "un coup."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DAMP] =
    {
        .name = _("Moiteur"),
        .description = COMPOUND_STRING(
            "Empêche auto-destruction."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_LIMBER] =
    {
        .name = _("Échauffement"),
        .description = COMPOUND_STRING(
            "Empêche la paralysie."
        ),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SAND_VEIL] =
    {
        .name = _("Voile Sable"),
        .description = COMPOUND_STRING(
            "Evasion si tempête sable."
        ),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_STATIC] =
    {
        .name = _("Statik"),
        .description = COMPOUND_STRING(
            "Paralyse au toucher."
        ),
        .aiRating = 4,
    },

    [ABILITY_VOLT_ABSORB] =
    {
        .name = _("Absorbe-Volt"),
        .description = COMPOUND_STRING(
            "Change l'électricité en PV."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_WATER_ABSORB] =
    {
        .name = _("Absorbe-Eau"),
        .description = COMPOUND_STRING(
            "Change l'eau en PV."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_OBLIVIOUS] =
    {
        .name = _("Benêt"),
        .description = COMPOUND_STRING(
            "Empêche l'attirance."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_CLOUD_NINE] =
    {
        .name = _("Ciel Gris"),
        .description = COMPOUND_STRING(
            "Ignore les effets du climat."
        ),
        .aiRating = 5,
    },

    [ABILITY_COMPOUND_EYES] =
    {
        .name = _("Œil Composé"),
        .description = COMPOUND_STRING(
            "Augmente la précision."
        ),
        .aiRating = 7,
    },

    [ABILITY_INSOMNIA] =
    {
        .name = _("Insomnia"),
        .description = COMPOUND_STRING(
            "Empêche de s'endormir."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_COLOR_CHANGE] =
    {
        .name = _("Homochromie"),
        .description = COMPOUND_STRING(
            "Le Pokémon adopte le type de la\n"
            "capacité ennemie."
        ),
        .aiRating = 2,
    },

    [ABILITY_IMMUNITY] =
    {
        .name = _("Vaccin"),
        .description = COMPOUND_STRING(
            "Empêche l'empoisonnement."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_FLASH_FIRE] =
    {
        .name = _("Torche"),
        .description = COMPOUND_STRING(
            "Puissance monte si brûlé."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SHIELD_DUST] =
    {
        .name = _("Écran Poudre"),
        .description = COMPOUND_STRING(
            "Empêche le cumul d'effets."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_OWN_TEMPO] =
    {
        .name = _("Tempo Perso"),
        .description = COMPOUND_STRING(
            "Empêche la confusion."
        ),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SUCTION_CUPS] =
    {
        .name = _("Ventouse"),
        .description = COMPOUND_STRING(
            "Fixe solidement le corps."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_INTIMIDATE] =
    {
        .name = _("Intimidation"),
        .description = COMPOUND_STRING(
            "Baisse l'ATTAQUE ennemie."
        ),
        .aiRating = 7,
    },

    [ABILITY_SHADOW_TAG] =
    {
        .name = _("Marque Ombre"),
        .description = COMPOUND_STRING(
            "Empêche la fuite ennemie."
        ),
        .aiRating = 10,
    },

    [ABILITY_ROUGH_SKIN] =
    {
        .name = _("Peau Dure"),
        .description = COMPOUND_STRING(
            "Blesse quand touché."
        ),
        .aiRating = 6,
    },

    [ABILITY_WONDER_GUARD] =
    {
        .name = _("Garde Mystik"),
        .description = COMPOUND_STRING(
            "Reçoit seul. “sup. eff.”."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_LEVITATE] =
    {
        .name = _("Lévitation"),
        .description = COMPOUND_STRING(
            "Ignore les attaques SOL."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EFFECT_SPORE] =
    {
        .name = _("Pose Spore"),
        .description = COMPOUND_STRING(
            "Laisse spores si touché."
        ),
        .aiRating = 4,
    },

    [ABILITY_SYNCHRONIZE] =
    {
        .name = _("Synchro"),
        .description = COMPOUND_STRING(
            "Transfère statuts."
        ),
        .aiRating = 4,
    },

    [ABILITY_CLEAR_BODY] =
    {
        .name = _("Corps Sain"),
        .description = COMPOUND_STRING(
            "Empêche réduction de cap."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_NATURAL_CURE] =
    {
        .name = _("Médic Nature"),
        .description = COMPOUND_STRING(
            "Soigne POKéMON changeant."
        ),
        .aiRating = 7,
    },

    [ABILITY_LIGHTNING_ROD] =
    {
        .name = _("Paratonnerre"),
        .description = COMPOUND_STRING(
            "Attire l'électricité et augmente l'Atq.\n"
            "Spé."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SERENE_GRACE] =
    {
        .name = _("Sérénité"),
        .description = COMPOUND_STRING(
            "Favorise le cumul d'effet."
        ),
        .aiRating = 8,
    },

    [ABILITY_SWIFT_SWIM] =
    {
        .name = _("Glissade"),
        .description = COMPOUND_STRING(
            "Monte VITESSE s'il pleut."
        ),
        .aiRating = 6,
    },

    [ABILITY_CHLOROPHYLL] =
    {
        .name = _("Chlorophylle"),
        .description = COMPOUND_STRING(
            "Augmente vitesse au soleil."
        ),
        .aiRating = 6,
    },

    [ABILITY_ILLUMINATE] =
    {
        .name = _("Lumiattirance"),
        .description = COMPOUND_STRING(
            "Augmente les rencontres."
        ),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_TRACE] =
    {
        .name = _("Calque"),
        .description = COMPOUND_STRING(
            "Imite la capacité spéciale."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE, //B_UPDATED_ABILITY_DATA >= GEN_4
    },

    [ABILITY_HUGE_POWER] =
    {
        .name = _("Coloforce"),
        .description = COMPOUND_STRING(
            "Augmente ATTAQUE."
        ),
        .aiRating = 10,
    },

    [ABILITY_POISON_POINT] =
    {
        .name = _("Point Poison"),
        .description = COMPOUND_STRING(
            "Empoisonne quand touché."
        ),
        .aiRating = 4,
    },

    [ABILITY_INNER_FOCUS] =
    {
        .name = _("Attention"),
        .description = COMPOUND_STRING(
            "Empêche la peur."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MAGMA_ARMOR] =
    {
        .name = _("Armumagma"),
        .description = COMPOUND_STRING(
            "Empêche le gel."
        ),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_WATER_VEIL] =
    {
        .name = _("Ignifu-Voile"),
        .description = COMPOUND_STRING(
            "Empêche les brûlures."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_MAGNET_PULL] =
    {
        .name = _("Magnépiège"),
        .description = COMPOUND_STRING(
            "Piège les POKéMON ACIER."
        ),
        .aiRating = 9,
    },

    [ABILITY_SOUNDPROOF] =
    {
        .name = _("Anti-Bruit"),
        .description = COMPOUND_STRING(
            "Évite les attaques sonores."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_RAIN_DISH] =
    {
        .name = _("Cuvette"),
        .description = COMPOUND_STRING(
            "Gagne quelques PV si pluie."
        ),
        .aiRating = 3,
    },

    [ABILITY_SAND_STREAM] =
    {
        .name = _("Sable Volant"),
        .description = COMPOUND_STRING(
            "Lance une tempête de sable."
        ),
        .aiRating = 9,
    },

    [ABILITY_PRESSURE] =
    {
        .name = _("Pression"),
        .description = COMPOUND_STRING(
            "Force l'ennemi à dépenser plus de PP."
        ),
        .aiRating = 5,
    },

    [ABILITY_THICK_FAT] =
    {
        .name = _("Isograisse"),
        .description = COMPOUND_STRING(
            "Contre chaleur et froid."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EARLY_BIRD] =
    {
        .name = _("Matinal"),
        .description = COMPOUND_STRING(
            "Se réveille rapidement."
        ),
        .aiRating = 4,
    },

    [ABILITY_FLAME_BODY] =
    {
        .name = _("Corps Ardent"),
        .description = COMPOUND_STRING(
            "Brûle l'ennemi quand touché."
        ),
        .aiRating = 4,
    },

    [ABILITY_RUN_AWAY] =
    {
        .name = _("Fuite"),
        .description = COMPOUND_STRING(
            "Améliore chances de fuite."
        ),
        .aiRating = 0,
    },

    [ABILITY_KEEN_EYE] =
    {
        .name = _("Regard Vif"),
        .description = COMPOUND_STRING(
            "Empêche perte de précision."
        ),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_HYPER_CUTTER] =
    {
        .name = _("Hyper Cutter"),
        .description = COMPOUND_STRING(
            "Empêche réduction ATTAQUE."
        ),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PICKUP] =
    {
        .name = _("Ramassage"),
        .description = COMPOUND_STRING(
            "Permet parfois au Pokémon de ramasser\n"
            "des objets."
        ),
        .aiRating = 1,
    },

    [ABILITY_TRUANT] =
    {
        .name = _("Absentéisme"),
        .description = COMPOUND_STRING(
            "Frappe tous les 2 tours."
        ),
        .aiRating = -2,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HUSTLE] =
    {
        .name = _("Agitation"),
        .description = COMPOUND_STRING(
            "Substitue préc. par puiss."
        ),
        .aiRating = 7,
    },

    [ABILITY_CUTE_CHARM] =
    {
        .name = _("Joli Sourire"),
        .description = COMPOUND_STRING(
            "Séduit quand touché."
        ),
        .aiRating = 2,
    },

    [ABILITY_PLUS] =
    {
        .name = _("Plus"),
        .description = COMPOUND_STRING(
            "Puissance + avec MINUS."
        ),
        .aiRating = 0,
    },

    [ABILITY_MINUS] =
    {
        .name = _("Moins"),
        .description = COMPOUND_STRING(
            "Puissance + avec PLUS."
        ),
        .aiRating = 0,
    },

    [ABILITY_FORECAST] =
    {
        .name = _("Météo"),
        .description = COMPOUND_STRING(
            "Change selon le climat."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_4,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_STICKY_HOLD] =
    {
        .name = _("Glu"),
        .description = COMPOUND_STRING(
            "Empêche le vol d'objets."
        ),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SHED_SKIN] =
    {
        .name = _("Mue"),
        .description = COMPOUND_STRING(
            "Mue pour se soigner."
        ),
        .aiRating = 7,
    },

    [ABILITY_GUTS] =
    {
        .name = _("Cran"),
        .description = COMPOUND_STRING(
            "Augmente ATT. quand blessé."
        ),
        .aiRating = 6,
    },

    [ABILITY_MARVEL_SCALE] =
    {
        .name = _("Écaille Spéciale"),
        .description = COMPOUND_STRING(
            "Augmente DEF. quand blessé."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_LIQUID_OOZE] =
    {
        .name = _("Suintement"),
        .description = COMPOUND_STRING(
            "Blesse quand drainé."
        ),
        .aiRating = 3,
    },

    [ABILITY_OVERGROW] =
    {
        .name = _("Engrais"),
        .description = COMPOUND_STRING(
            "Augmente attaques PLANTE."
        ),
        .aiRating = 5,
    },

    [ABILITY_BLAZE] =
    {
        .name = _("Brasier"),
        .description = COMPOUND_STRING(
            "Augmente attaques feu."
        ),
        .aiRating = 5,
    },

    [ABILITY_TORRENT] =
    {
        .name = _("Torrent"),
        .description = COMPOUND_STRING(
            "Augmente attaques EAU."
        ),
        .aiRating = 5,
    },

    [ABILITY_SWARM] =
    {
        .name = _("Essaim"),
        .description = COMPOUND_STRING(
            "Augmente attaques INSECT."
        ),
        .aiRating = 5,
    },

    [ABILITY_ROCK_HEAD] =
    {
        .name = _("Tête de Roc"),
        .description = COMPOUND_STRING(
            "Empêche dégâts du recul."
        ),
        .aiRating = 5,
    },

    [ABILITY_DROUGHT] =
    {
        .name = _("Sécheresse"),
        .description = COMPOUND_STRING(
            "Invoque le soleil."
        ),
        .aiRating = 9,
    },

    [ABILITY_ARENA_TRAP] =
    {
        .name = _("Piège Sable"),
        .description = COMPOUND_STRING(
            "Empêche la fuite."
        ),
        .aiRating = 9,
    },

    [ABILITY_VITAL_SPIRIT] =
    {
        .name = _("Esprit Vital"),
        .description = COMPOUND_STRING(
            "Empêche le sommeil."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
        .name = _("Écran Fumée"),
        .description = COMPOUND_STRING(
            "Empêche réduction des cap."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_PURE_POWER] =
    {
        .name = _("Force Pure"),
        .description = COMPOUND_STRING(
            "Augmente l'ATTAQUE."
        ),
        .aiRating = 10,
    },

    [ABILITY_SHELL_ARMOR] =
    {
        .name = _("Coque Armure"),
        .description = COMPOUND_STRING(
            "Bloque les coups critiques."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_AIR_LOCK] =
    {
        .name = _("Air Lock"),
        .description = COMPOUND_STRING(
            "Ignore les effets du climat."
        ),
        .aiRating = 5,
    },

    [ABILITY_TANGLED_FEET] =
    {
        .name = _("Pieds Confus"),
        .description = COMPOUND_STRING(
            "Augmente l'esquive si le Pokémon est\n"
            "confus."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
        .name = _("Motorisé"),
        .description = COMPOUND_STRING(
            "Augmente la Vit. si touché par une cap.\n"
            "Électrik."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_RIVALRY] =
    {
        .name = _("Rivalité"),
        .description = COMPOUND_STRING(
            "Devient plus fort si l'ennemi est du même\n"
            "sexe."
        ),
        .aiRating = 1,
    },

    [ABILITY_STEADFAST] =
    {
        .name = _("Impassible"),
        .description = COMPOUND_STRING(
            "Augmente la Vitesse quand le Pokémon a\n"
            "peur."
        ),
        .aiRating = 2,
    },

    [ABILITY_SNOW_CLOAK] =
    {
        .name = _("Rideau Neige"),
        .description = COMPOUND_STRING(
            "Augmente l'Esquive du Pokémon quand il\n"
            "neige."
        ),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_GLUTTONY] =
    {
        .name = _("Gloutonnerie"),
        .description = COMPOUND_STRING(
            "Encourage l'utilisation d'une Baie tenue."
        ),
        .aiRating = 3,
    },

    [ABILITY_ANGER_POINT] =
    {
        .name = _("Colérique"),
        .description = COMPOUND_STRING(
            "Monte l'Attaque au max après un coup\n"
            "critique."
        ),
        .aiRating = 4,
    },

    [ABILITY_UNBURDEN] =
    {
        .name = _("Délestage"),
        .description = COMPOUND_STRING(
            "Augmente la Vit. si l'objet tenu est\n"
            "utilisé ou perdu."
        ),
        .aiRating = 7,
    },

    [ABILITY_HEATPROOF] =
    {
        .name = _("Ignifugé"),
        .description = COMPOUND_STRING(
            "Réduit la puissance des capacités de\n"
            "type Feu."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SIMPLE] =
    {
        .name = _("Simple"),
        .description = COMPOUND_STRING(
            "Le Pokémon est sujet à des variations\n"
            "de stats."
        ),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_DRY_SKIN] =
    {
        .name = _("Peau Sèche"),
        .description = COMPOUND_STRING(
            "Perd des PV à la chaleur. L'eau les\n"
            "restaure."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DOWNLOAD] =
    {
        .name = _("Télécharge"),
        .description = COMPOUND_STRING(
            "Ajuste la puissance selon l'ennemi."
        ),
        .aiRating = 7,
    },

    [ABILITY_IRON_FIST] =
    {
        .name = _("Poing de Fer"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des capacités\n"
            "coups de poing."
        ),
        .aiRating = 6,
    },

    [ABILITY_POISON_HEAL] =
    {
        .name = _("Soin Poison"),
        .description = COMPOUND_STRING(
            "Restaure des PV si le Pokémon est\n"
            "empoisonné."
        ),
        .aiRating = 8,
    },

    [ABILITY_ADAPTABILITY] =
    {
        .name = _("Adaptabilité"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des capacités de\n"
            "même type."
        ),
        .aiRating = 8,
    },

    [ABILITY_SKILL_LINK] =
    {
        .name = _("Multi-Coups"),
        .description = COMPOUND_STRING(
            "Augmente la fréquence des attaques\n"
            "multiples."
        ),
        .aiRating = 7,
    },

    [ABILITY_HYDRATION] =
    {
        .name = _("Hydratation"),
        .description = COMPOUND_STRING(
            "Soigne les problèmes de statut s'il pleut."
        ),
        .aiRating = 4,
    },

    [ABILITY_SOLAR_POWER] =
    {
        .name = _("Force Soleil"),
        .description = COMPOUND_STRING(
            "Augmente l'Atq. Spé. mais baisse les PV\n"
            "au soleil."
        ),
        .aiRating = 3,
    },

    [ABILITY_QUICK_FEET] =
    {
        .name = _("Pied Véloce"),
        .description = COMPOUND_STRING(
            "Augmente la Vitesse en cas de problème\n"
            "de statut."
        ),
        .aiRating = 5,
    },

    [ABILITY_NORMALIZE] =
    {
        .name = _("Normalise"),
        .description = COMPOUND_STRING(
            "Toutes les capacités sont de type\n"
            "Normal."
        ),
        .aiRating = -1,
    },

    [ABILITY_SNIPER] =
    {
        .name = _("Sniper"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des coups\n"
            "critiques."
        ),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_GUARD] =
    {
        .name = _("Garde Magik"),
        .description = COMPOUND_STRING(
            "Seules les attaques peuvent blesser le\n"
            "Pokémon."
        ),
        .aiRating = 9,
    },

    [ABILITY_NO_GUARD] =
    {
        .name = _("Annule Garde"),
        .description = COMPOUND_STRING(
            "Attaques du Pokémon et de l'ennemi\n"
            "réussissent."
        ),
        .aiRating = 8,
    },

    [ABILITY_STALL] =
    {
        .name = _("Frein"),
        .description = COMPOUND_STRING(
            "Attaque toujours après l'ennemi, même\n"
            "plus lent."
        ),
        .aiRating = -1,
    },

    [ABILITY_TECHNICIAN] =
    {
        .name = _("Technicien"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des capacités les\n"
            "plus faibles."
        ),
        .aiRating = 8,
    },

    [ABILITY_LEAF_GUARD] =
    {
        .name = _("Feuille Garde"),
        .description = COMPOUND_STRING(
            "Empêche les problèmes de statut au\n"
            "soleil."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_KLUTZ] =
    {
        .name = _("Maladresse"),
        .description = COMPOUND_STRING(
            "Le Pokémon ne peut utiliser aucun objet\n"
            "tenu."
        ),
        .aiRating = -1,
    },

    [ABILITY_MOLD_BREAKER] =
    {
        .name = _("Brise Moule"),
        .description = COMPOUND_STRING(
            "Cap. utilisables quelles que soient les\n"
            "cap. spé."
        ),
        .aiRating = 7,
    },

    [ABILITY_SUPER_LUCK] =
    {
        .name = _("Chanceux"),
        .description = COMPOUND_STRING(
            "Augmente la fréquence des coups\n"
            "critiques."
        ),
        .aiRating = 3,
    },

    [ABILITY_AFTERMATH] =
    {
        .name = _("Boom Final"),
        .description = COMPOUND_STRING(
            "Blesse l'ennemi qui porte le coup de\n"
            "grâce."
        ),
        .aiRating = 5,
    },

    [ABILITY_ANTICIPATION] =
    {
        .name = _("Anticipation"),
        .description = COMPOUND_STRING(
            "Prévoit les capacités ennemies\n"
            "dangereuses."
        ),
        .aiRating = 2,
    },

    [ABILITY_FOREWARN] =
    {
        .name = _("Prédiction"),
        .description = COMPOUND_STRING(
            "Découvre la capacité ennemie la plus\n"
            "puissante."
        ),
        .aiRating = 2,
    },

    [ABILITY_UNAWARE] =
    {
        .name = _("Inconscient"),
        .description = COMPOUND_STRING(
            "Ignore les changements de stats de\n"
            "l'ennemi."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_TINTED_LENS] =
    {
        .name = _("Lentiteintée"),
        .description = COMPOUND_STRING(
            "Améliore les capacités “pas très\n"
            "efficaces”."
        ),
        .aiRating = 7,
    },

    [ABILITY_FILTER] =
    {
        .name = _("Filtre"),
        .description = COMPOUND_STRING(
            "Affaiblit les capacités “super\n"
            "efficaces”."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SLOW_START] =
    {
        .name = _("Début Calme"),
        .description = COMPOUND_STRING(
            "Divise temporairement Vitesse et\n"
            "Attaque par 2."
        ),
        .aiRating = -2,
    },

    [ABILITY_SCRAPPY] =
    {
        .name = _("Querelleur"),
        .description = COMPOUND_STRING(
            "Les capacités touchent les Pokémon\n"
            "Spectre."
        ),
        .aiRating = 6,
    },

    [ABILITY_STORM_DRAIN] =
    {
        .name = _("Lavabo"),
        .description = COMPOUND_STRING(
            "Attire l'eau et augmente l'Atq. Spé."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_ICE_BODY] =
    {
        .name = _("Corps Gel"),
        .description = COMPOUND_STRING(
            "Récupère des PV lors des tempêtes de\n"
            "grêle."
        ),
        .aiRating = 3,
    },

    [ABILITY_SOLID_ROCK] =
    {
        .name = _("Solide Roc"),
        .description = COMPOUND_STRING(
            "Affaiblit les capacités “super\n"
            "efficaces”."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SNOW_WARNING] =
    {
        .name = _("Alerte Neige"),
    #if B_SNOW_WARNING >= GEN_9
        .description = COMPOUND_STRING(
            "Déclenche une tempête de grêle pendant\n"
            "un combat."
        ),
    #else
        .description = COMPOUND_STRING("Invoque la neige."),
    #endif
        .aiRating = 8,
    },

    [ABILITY_HONEY_GATHER] =
    {
        .name = _("Cherche Miel"),
        .description = COMPOUND_STRING(
            "Le Pokémon peut parfois trouver du Miel."
        ),
        .aiRating = 0,
    },

    [ABILITY_FRISK] =
    {
        .name = _("Fouille"),
        .description = COMPOUND_STRING(
            "Permet de connaître l'objet tenu par\n"
            "l'ennemi."
        ),
        .aiRating = 3,
    },

    [ABILITY_RECKLESS] =
    {
        .name = _("Téméraire"),
        .description = COMPOUND_STRING(
            "Booste les cap. ayant des dégâts de\n"
            "contrecoups."
        ),
        .aiRating = 6,
    },

    [ABILITY_MULTITYPE] =
    {
        .name = _("Multi-Type"),
        .description = COMPOUND_STRING(
            "Modifie le type en fonction de la Plaque\n"
            "tenue."
        ),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_FLOWER_GIFT] =
    {
        .name = _("Don Floral"),
        .description = COMPOUND_STRING(
            "Pokémon de l'équipe plus puissants au\n"
            "soleil."
        ),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_5,
        .breakable = TRUE,
    },

    [ABILITY_BAD_DREAMS] =
    {
        .name = _("Mauvais Rêve"),
        .description = COMPOUND_STRING(
            "Réduit les PV d'un ennemi endormi."
        ),
        .aiRating = 4,
    },

    [ABILITY_PICKPOCKET] =
    {
        .name = _("Pickpocket"),
        .description = COMPOUND_STRING(
            "Vole l'objet de l'ennemi si son attaque\n"
            "touche."
        ),
        .aiRating = 3,
    },

    [ABILITY_SHEER_FORCE] =
    {
        .name = _("Sans Limite"),
        .description = COMPOUND_STRING(
            "Frappe plus fort mais annule les effets\n"
            "cumulés."
        ),
        .aiRating = 8,
    },

    [ABILITY_CONTRARY] =
    {
        .name = _("Contestation"),
        .description = COMPOUND_STRING(
            "Inverse les variations de stats."
        ),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_UNNERVE] =
    {
        .name = _("Tension"),
        .description = COMPOUND_STRING(
            "L'ennemi stresse et ne peut plus manger\n"
            "de Baies."
        ),
        .aiRating = 3,
    },

    [ABILITY_DEFIANT] =
    {
        .name = _("Acharné"),
        .description = COMPOUND_STRING(
            "Monte l'Attaque quand les stats\n"
            "baissent."
        ),
        .aiRating = 5,
    },

    [ABILITY_DEFEATIST] =
    {
        .name = _("Défaitiste"),
        .description = COMPOUND_STRING(
            "Baisse les stats quand les PV tombent à\n"
            "la moitié."
        ),
        .aiRating = -1,
    },

    [ABILITY_CURSED_BODY] =
    {
        .name = _("Corps Maudit"),
        .description = COMPOUND_STRING(
            "Peut empêcher l'ennemi de réutiliser une\n"
            "attaque."
        ),
        .aiRating = 4,
    },

    [ABILITY_HEALER] =
    {
        .name = _("Cœur Soin"),
        .description = COMPOUND_STRING(
            "Guérit parfois le statut des alliés\n"
            "alentour."
        ),
        .aiRating = 0,
    },

    [ABILITY_FRIEND_GUARD] =
    {
        .name = _("Garde-Ami"),
        .description = COMPOUND_STRING(
            "Diminue les dégâts subis par les alliés."
        ),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_WEAK_ARMOR] =
    {
        .name = _("Armurouillée"),
        .description = COMPOUND_STRING(
            "Un coup physique baisse la Défense,\n"
            "monte la Vitesse."
        ),
        .aiRating = 2,
    },

    [ABILITY_HEAVY_METAL] =
    {
        .name = _("Heavy Metal"),
        .description = COMPOUND_STRING(
            "Double le poids du Pokémon."
        ),
        .aiRating = -1,
        .breakable = TRUE,
    },

    [ABILITY_LIGHT_METAL] =
    {
        .name = _("Light Metal"),
        .description = COMPOUND_STRING(
            "Divise par 2 le poids du Pokémon."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MULTISCALE] =
    {
        .name = _("Multiécaille"),
        .description = COMPOUND_STRING(
            "Reçoit moins de dégâts si les PV sont au\n"
            "maximum."
        ),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_TOXIC_BOOST] =
    {
        .name = _("Rage Poison"),
        .description = COMPOUND_STRING(
            "Booste les att. physiques si le statut\n"
            "est poison."
        ),
        .aiRating = 6,
    },

    [ABILITY_FLARE_BOOST] =
    {
        .name = _("Rage Brûlure"),
        .description = COMPOUND_STRING(
            "Booste les att. spéciales si le statut\n"
            "est brûlure."
        ),
        .aiRating = 5,
    },

    [ABILITY_HARVEST] =
    {
        .name = _("Récolte"),
        .description = COMPOUND_STRING(
            "Les Baies utilisées peuvent repousser."
        ),
        .aiRating = 5,
    },

    [ABILITY_TELEPATHY] =
    {
        .name = _("Télépathe"),
        .description = COMPOUND_STRING(
            "Anticipe et évite les attaques de ses\n"
            "alliés."
        ),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_MOODY] =
    {
        .name = _("Lunatique"),
        .description = COMPOUND_STRING(
            "Monte une stat tout en en baissant une\n"
            "autre."
        ),
        .aiRating = 10,
    },

    [ABILITY_OVERCOAT] =
    {
        .name = _("Envelocape"),
        .description = COMPOUND_STRING(
            "Neutralise les dégâts dus à la météo."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_POISON_TOUCH] =
    {
        .name = _("Toxitouche"),
        .description = COMPOUND_STRING(
            "Peut empoisonner l'ennemi par simple\n"
            "contact."
        ),
        .aiRating = 4,
    },

    [ABILITY_REGENERATOR] =
    {
        .name = _("Régé-Force"),
        .description = COMPOUND_STRING(
            "Restaure un peu de PV si le Pokémon est\n"
            "retiré."
        ),
        .aiRating = 8,
    },

    [ABILITY_BIG_PECKS] =
    {
        .name = _("Cœur de Coq"),
        .description = COMPOUND_STRING(
            "Protège des effets qui baissent la\n"
            "Défense."
        ),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_SAND_RUSH] =
    {
        .name = _("Baigne Sable"),
        .description = COMPOUND_STRING(
            "Augmente la Vitesse lors des tempêtes\n"
            "de sable."
        ),
        .aiRating = 6,
    },

    [ABILITY_WONDER_SKIN] =
    {
        .name = _("Peau Miracle"),
        .description = COMPOUND_STRING(
            "Résiste mieux aux attaques de statut."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANALYTIC] =
    {
        .name = _("Analyste"),
        .description = COMPOUND_STRING(
            "Booste les capacités s'il attaque en\n"
            "dernier."
        ),
        .aiRating = 5,
    },

    [ABILITY_ILLUSION] =
    {
        .name = _("Illusion"),
        .description = COMPOUND_STRING(
            "Prend l'apparence du dernier Pokémon de\n"
            "l'équipe."
        ),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_IMPOSTER] =
    {
        .name = _("Imposteur"),
        .description = COMPOUND_STRING(
            "Donne l'apparence du Pokémon adverse."
        ),
        .aiRating = 9,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_INFILTRATOR] =
    {
        .name = _("Infiltration"),
        .description = COMPOUND_STRING(
            "Traverse les barrières de l'ennemi pour\n"
            "attaquer."
        ),
        .aiRating = 6,
    },

    [ABILITY_MUMMY] =
    {
        .name = _("Momie"),
        .description = COMPOUND_STRING(
            "Momifie le talent de l'ennemi qui le\n"
            "touche."
        ),
        .aiRating = 5,
    },

    [ABILITY_MOXIE] =
    {
        .name = _("Impudence"),
        .description = COMPOUND_STRING(
            "Monte l'Attaque quand il met un ennemi\n"
            "K.O."
        ),
        .aiRating = 7,
    },

    [ABILITY_JUSTIFIED] =
    {
        .name = _("Cœur Noble"),
        .description = COMPOUND_STRING(
            "Monte l'Attaque si une att. Ténèbres le\n"
            "touche."
        ),
        .aiRating = 4,
    },

    [ABILITY_RATTLED] =
    {
        .name = _("Phobique"),
        .description = COMPOUND_STRING(
            "Sa peur de certains types augmente sa\n"
            "Vitesse."
        ),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_BOUNCE] =
    {
        .name = _("Miroir Magik"),
        .description = COMPOUND_STRING(
            "Renvoie les attaques de statut."
        ),
        .aiRating = 9,
        .breakable = TRUE,
    },

    [ABILITY_SAP_SIPPER] =
    {
        .name = _("Herbivore"),
        .description = COMPOUND_STRING(
            "Augmente l'Attaque après une attaque\n"
            "Plante."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_PRANKSTER] =
    {
        .name = _("Farceur"),
        .description = COMPOUND_STRING(
            "Utilise les attaques de statut en\n"
            "premier."
        ),
        .aiRating = 8,
    },

    [ABILITY_SAND_FORCE] =
    {
        .name = _("Force Sable"),
        .description = COMPOUND_STRING(
            "Renforce des capacités en cas de\n"
            "tempête de sable."
        ),
        .aiRating = 4,
    },

    [ABILITY_IRON_BARBS] =
    {
        .name = _("Épine de Fer"),
        .description = COMPOUND_STRING(
            "Blesse l'ennemi au moindre contact."
        ),
        .aiRating = 6,
    },

    [ABILITY_ZEN_MODE] =
    {
        .name = _("Mode Transe"),
        .description = COMPOUND_STRING(
            "Transforme le Pokémon dans les moments\n"
            "délicats."
        ),
        .aiRating = -1,
        .cantBeCopied = TRUE,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeOverwritten = B_UPDATED_ABILITY_DATA >= GEN_7,
        .failsOnImposter = TRUE,
    },

    [ABILITY_VICTORY_STAR] =
    {
        .name = _("Victorieux"),
        .description = COMPOUND_STRING(
            "Monte la Précision des Pokémon de\n"
            "l'équipe."
        ),
        .aiRating = 6,
    },

    [ABILITY_TURBOBLAZE] =
    {
        .name = _("Turbo Brasier"),
        .description = COMPOUND_STRING(
            "Les cap. spé. adverses ne bloquent pas\n"
            "ses cap."
        ),
        .aiRating = 7,
    },

    [ABILITY_TERAVOLT] =
    {
        .name = _("Téra-Voltage"),
        .description = COMPOUND_STRING(
            "Les cap. spé. adverses ne bloquent pas\n"
            "ses cap."
        ),
        .aiRating = 7,
    },

    [ABILITY_AROMA_VEIL] =
    {
        .name = _("Aroma-Voile"),
        .description = COMPOUND_STRING(
            "Protège l'équipe des effets limitant le\n"
            "libre arbitre."
        ),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_FLOWER_VEIL] =
    {
        .name = _("Flora-Voile"),
        .description = COMPOUND_STRING(
            "Empêche les alliés de type Plante de\n"
            "subir des diminutions de stats."
        ),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_CHEEK_POUCH] =
    {
        .name = _("Bajoues"),
        .description = COMPOUND_STRING(
            "Rend des PV lorsque le Pokémon consomme\n"
            "une Baie."
        ),
        .aiRating = 4,
    },

    [ABILITY_PROTEAN] =
    {
        .name = _("Protéen"),
        .description = COMPOUND_STRING(
            "Le Pokémon prend le type de la capacité\n"
            "qu'il utilise."
        ),
        .aiRating = 8,
    },

    [ABILITY_FUR_COAT] =
    {
        .name = _("Toison Épaisse"),
        .description = COMPOUND_STRING(
            "Divise les dégâts des attaques\n"
            "physiques par deux."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MAGICIAN] =
    {
        .name = _("Magicien"),
        .description = COMPOUND_STRING(
            "Les capacités volent aussi l'objet tenu\n"
            "par la cible."
        ),
        .aiRating = 3,
    },

    [ABILITY_BULLETPROOF] =
    {
        .name = _("Pare-Balles"),
        .description = COMPOUND_STRING(
            "Protège de certaines capacités\n"
            "projetant des bombes, balles…"
        ),
        .breakable = TRUE,
        .aiRating = 7,
    },

    [ABILITY_COMPETITIVE] =
    {
        .name = _("Battant"),
        .description = COMPOUND_STRING(
            "Monte l'Attaque quand les stats\n"
            "baissent."
        ),
        .aiRating = 5,
    },

    [ABILITY_STRONG_JAW] =
    {
        .name = _("Prognathe"),
        .description = COMPOUND_STRING(
            "Grâce à une puissante mâchoire, les\n"
            "morsures sont plus fortes."
        ),
        .aiRating = 6,
    },

    [ABILITY_REFRIGERATE] =
    {
        .name = _("Peau Gelée"),
        .description = COMPOUND_STRING(
            "Les capacités de type Normal deviennent\n"
            "de type Glace."
        ),
        .aiRating = 8,
    },

    [ABILITY_SWEET_VEIL] =
    {
        .name = _("Gluco-Voile"),
        .description = COMPOUND_STRING(
            "Les Pokémon de l'équipe ne peuvent pas\n"
            "s'endormir."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_STANCE_CHANGE] =
    {
        .name = _("Déclic Tactique"),
        .description = COMPOUND_STRING(
            "Change de forme selon la façon dont le\n"
            "Pokémon se bat."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GALE_WINGS] =
    {
        .name = _("Ailes Bourrasque"),
        .description = COMPOUND_STRING(
            "Les attaques de type Vol sont\n"
            "prioritaires."
        ),
        .aiRating = 6,
    },

    [ABILITY_MEGA_LAUNCHER] =
    {
        .name = _("Méga Blaster"),
        .description = COMPOUND_STRING(
            "Augmente la puissance de certaines\n"
            "capacités de type aura."
        ),
        .aiRating = 7,
    },

    [ABILITY_GRASS_PELT] =
    {
        .name = _("Toison Herbue"),
        .description = COMPOUND_STRING(
            "Augmente la Défense si Champ Herbu est\n"
            "actif."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SYMBIOSIS] =
    {
        .name = _("Symbiose"),
        .description = COMPOUND_STRING(
            "Permet aux alliés d'utiliser l'objet porté\n"
            "par ce Pokémon."
        ),
        .aiRating = 0,
    },

    [ABILITY_TOUGH_CLAWS] =
    {
        .name = _("Griffe Dure"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des attaques\n"
            "directes."
        ),
        .aiRating = 7,
    },

    [ABILITY_PIXILATE] =
    {
        .name = _("Peau Féérique"),
        .description = COMPOUND_STRING(
            "Les capacités de type Normal deviennent\n"
            "de type Fée."
        ),
        .aiRating = 8,
    },

    [ABILITY_GOOEY] =
    {
        .name = _("Poisseux"),
        .description = COMPOUND_STRING(
            "Diminue la Vitesse de l'attaquant qui le\n"
            "touche."
        ),
        .aiRating = 5,
    },

    [ABILITY_AERILATE] =
    {
        .name = _("Peau Céleste"),
        .description = COMPOUND_STRING(
            "Les capacités de type Normal deviennent\n"
            "de type Vol."
        ),
        .aiRating = 8,
    },

    [ABILITY_PARENTAL_BOND] =
    {
        .name = _("Amour Filial"),
        .description = COMPOUND_STRING(
            "Attaque en famille."
        ),
        .aiRating = 10,
    },

    [ABILITY_DARK_AURA] =
    {
        .name = _("Aura Ténébreuse"),
        .description = COMPOUND_STRING(
            "Renforce les attaques de type Ténèbres\n"
            "de tous les Pokémon."
        ),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_FAIRY_AURA] =
    {
        .name = _("Aura Féérique"),
        .description = COMPOUND_STRING(
            "Renforce les attaques de type Fée de\n"
            "tous les Pokémon."
        ),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_AURA_BREAK] =
    {
        .name = _("Aura Inversée"),
        .description = COMPOUND_STRING(
            "L'effet des auras est inversé."
        ),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PRIMORDIAL_SEA] =
    {
        .name = _("Mer Primaire"),
        .description = COMPOUND_STRING(
            "Altère les conditions météo et rend\n"
            "inefficaces les attaques Feu."
        ),
        .aiRating = 10,
    },

    [ABILITY_DESOLATE_LAND] =
    {
        .name = _("Terre Finale"),
        .description = COMPOUND_STRING(
            "Altère les conditions météo et rend\n"
            "inefficaces les attaques Eau."
        ),
        .aiRating = 10,
    },

    [ABILITY_DELTA_STREAM] =
    {
        .name = _("Souffle Delta"),
        .description = COMPOUND_STRING(
            "Altère les conditions météo et annule les\n"
            "faiblesses du type Vol."
        ),
        .aiRating = 10,
    },

    [ABILITY_STAMINA] =
    {
        .name = _("Endurance"),
        .description = COMPOUND_STRING(
            "Augmente la Défense du Pokémon lorsqu'il\n"
            "subit une attaque."
        ),
        .aiRating = 6,
    },

    [ABILITY_WIMP_OUT] =
    {
        .name = _("Escampette"),
        .description = COMPOUND_STRING(
            "Le Pokémon perd confiance quand ses PV\n"
            "tombent à la moitié et s'enfuit dans sa\n"
            "Poké Ball."
        ),
        .aiRating = 3,
    },

    [ABILITY_EMERGENCY_EXIT] =
    {
        .name = _("Repli Tactique"),
        .description = COMPOUND_STRING(
            "Le Pokémon évite les situations\n"
            "inutilement dangereuses. Quand ses PV\n"
            "tombent à la moitié, il se réfugie dans sa\n"
            "Poké Ball."
        ),
        .aiRating = 3,
    },

    [ABILITY_WATER_COMPACTION] =
    {
        .name = _("Sable Humide"),
        .description = COMPOUND_STRING(
            "Augmente beaucoup la Défense du\n"
            "Pokémon quand il subit une capacité de\n"
            "type Eau."
        ),
        .aiRating = 4,
    },

    [ABILITY_MERCILESS] =
    {
        .name = _("Cruauté"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon attaque un\n"
            "adversaire empoisonné, le coup est\n"
            "forcément critique."
        ),
        .aiRating = 4,
    },

    [ABILITY_SHIELDS_DOWN] =
    {
        .name = _("Bouclier-Carcan"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon perd la moitié de ses\n"
            "PV, son enveloppe se brise et il adopte\n"
            "une posture offensive."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STAKEOUT] =
    {
        .name = _("Filature"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon attaque une cible qui\n"
            "vient d'entrer sur le terrain en\n"
            "remplacement d'un autre Pokémon, les\n"
            "dégâts infligés sont doublés."
        ),
        .aiRating = 6,
    },

    [ABILITY_WATER_BUBBLE] =
    {
        .name = _("Aquabulle"),
        .description = COMPOUND_STRING(
            "Réduit les dégâts des capacités de type\n"
            "Feu subies par le Pokémon. Il est\n"
            "également immunisé contre les brûlures."
        ),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_STEELWORKER] =
    {
        .name = _("Expert Acier"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des attaques de\n"
            "type Acier."
        ),
        .aiRating = 6,
    },

    [ABILITY_BERSERK] =
    {
        .name = _("Folle Furie"),
        .description = COMPOUND_STRING(
            "Augmente l'Attaque Spéciale du Pokémon\n"
            "lorsqu'il tombe à la moitié de ses PV à\n"
            "cause d'une attaque."
        ),
        .aiRating = 5,
    },

    [ABILITY_SLUSH_RUSH] =
    {
        .name = _("Chasse-Neige"),
        .description = COMPOUND_STRING(
            "Augmente la Vitesse du Pokémon quand il\n"
            "grêle."
        ),
        .aiRating = 5,
    },

    [ABILITY_LONG_REACH] =
    {
        .name = _("Longue Portée"),
        .description = COMPOUND_STRING(
            "Le Pokémon est capable d'utiliser toutes\n"
            "ses capacités sans entrer en contact\n"
            "direct avec sa cible."
        ),
        .aiRating = 3,
    },

    [ABILITY_LIQUID_VOICE] =
    {
        .name = _("Hydrata-Son"),
        .description = COMPOUND_STRING(
            "Toutes les attaques sonores du Pokémon\n"
            "prennent le type Eau."
        ),
        .aiRating = 5,
    },

    [ABILITY_TRIAGE] =
    {
        .name = _("Prioguérison"),
        .description = COMPOUND_STRING(
            "Rend les capacités de soin prioritaires."
        ),
        .aiRating = 7,
    },

    [ABILITY_GALVANIZE] =
    {
        .name = _("Peau Électrique"),
        .description = COMPOUND_STRING(
            "Les capacités de type Normal deviennent\n"
            "de type Électrik. Leur puissance\n"
            "augmente légèrement."
        ),
        .aiRating = 8,
    },

    [ABILITY_SURGE_SURFER] =
    {
        .name = _("Surf Caudal"),
        .description = COMPOUND_STRING(
            "La Vitesse du Pokémon est doublée sur\n"
            "un Champ Électrifié."
        ),
        .aiRating = 4,
    },

    [ABILITY_SCHOOLING] =
    {
        .name = _("Banc"),
        .description = COMPOUND_STRING(
            "Le Pokémon se rassemble avec ses\n"
            "congénères quand ses PV sont élevés.\n"
            "Plus ses PV baissent, plus le banc\n"
            "s'amenuise."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_DISGUISE] =
    {
        .name = _("Fantômasque"),
        .description = COMPOUND_STRING(
            "Le déguisement qui recouvre le corps du\n"
            "Pokémon est capable de le protéger\n"
            "d'une attaque."
        ),
        .aiRating = 8,
        .breakable = TRUE,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_BATTLE_BOND] =
    {
        .name = _("Synergie"),
        .description = COMPOUND_STRING(
            "En battant un ennemi, ce Pokémon\n"
            "renforce ses liens avec son Dresseur,\n"
            "ce qui augmente son Attaque, son\n"
            "Attaque Spéciale et sa Vitesse."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_CONSTRUCT] =
    {
        .name = _("Rassemblement"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon perd la moitié de ses\n"
            "PV, ses Cellules se rassemblent pour\n"
            "l'encourager, ce qui lui permet de\n"
            "prendre sa Forme Parfaite."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_CORROSION] =
    {
        .name = _("Corrosion"),
        .description = COMPOUND_STRING(
            "Permet d'empoisonner les Pokémon de\n"
            "type Acier ou Poison."
        ),
        .aiRating = 5,
    },

    [ABILITY_COMATOSE] =
    {
        .name = _("Hypersommeil"),
        .description = COMPOUND_STRING(
            "Le Pokémon rêve en permanence et ne se\n"
            "réveille jamais. Il est capable d'attaquer\n"
            "normalement tout en dormant."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_QUEENLY_MAJESTY] =
    {
        .name = _("Prestance Royale"),
        .description = COMPOUND_STRING(
            "L'adversaire est impressionné par la\n"
            "majesté du Pokémon et ne peut pas le\n"
            "viser avec une attaque prioritaire."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_INNARDS_OUT] =
    {
        .name = _("Expuls'Organes"),
        .description = COMPOUND_STRING(
            "Le Pokémon inflige à l'adversaire l'ayant\n"
            "mis K.O. des dégâts égaux au nombre de\n"
            "PV qu'il lui restait avant le coup de\n"
            "grâce."
        ),
        .aiRating = 5,
    },

    [ABILITY_DANCER] =
    {
        .name = _("Danseuse"),
        .description = COMPOUND_STRING(
            "Si n'importe quel Pokémon utilise une\n"
            "capacité dansante, ce Pokémon peut se\n"
            "mettre aussi à danser."
        ),
        .aiRating = 5,
    },

    [ABILITY_BATTERY] =
    {
        .name = _("Batterie"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des capacités\n"
            "spéciales des alliés."
        ),
        .aiRating = 0,
    },

    [ABILITY_FLUFFY] =
    {
        .name = _("Boule de Poils"),
        .description = COMPOUND_STRING(
            "Divise par deux les dégâts des attaques\n"
            "directes subies par le Pokémon, mais\n"
            "double les dégâts des capacités de type\n"
            "Feu."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_DAZZLING] =
    {
        .name = _("Corps Coloré"),
        .description = COMPOUND_STRING(
            "L'adversaire est abasourdi par le\n"
            "Pokémon et ne peut pas le viser avec\n"
            "une capacité prioritaire."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SOUL_HEART] =
    {
        .name = _("Animacœur"),
        .description = COMPOUND_STRING(
            "Augmente l'Attaque Spéciale du Pokémon\n"
            "lorsqu'un autre Pokémon est mis K.O."
        ),
        .aiRating = 7,
    },

    [ABILITY_TANGLING_HAIR] =
    {
        .name = _("Mèche Rebelle"),
        .description = COMPOUND_STRING(
            "Baisse la Vitesse de l'attaquant lorsque\n"
            "le Pokémon subit une attaque directe."
        ),
        .aiRating = 5,
    },

    [ABILITY_RECEIVER] =
    {
        .name = _("Receveur"),
        .description = COMPOUND_STRING(
            "Le Pokémon reçoit le talent d'un allié mis\n"
            "K.O."
        ),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POWER_OF_ALCHEMY] =
    {
        .name = _("Osmose"),
        .description = COMPOUND_STRING(
            "Le Pokémon acquiert le talent d'un allié\n"
            "mis K.O."
        ),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_BEAST_BOOST] =
    {
        .name = _("Boost Chimère"),
        .description = COMPOUND_STRING(
            "Augmente la stat la plus élevée du\n"
            "Pokémon quand il met K.O. un autre\n"
            "Pokémon."
        ),
        .aiRating = 7,
    },

    [ABILITY_RKS_SYSTEM] =
    {
        .name = _("Système Alpha"),
        .description = COMPOUND_STRING(
            "Change le type du Pokémon en fonction\n"
            "de la ROM équipée."
        ),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_ELECTRIC_SURGE] =
    {
        .name = _("Créa-Élec"),
        .description = COMPOUND_STRING(
            "Le Pokémon crée un Champ Électrifié au\n"
            "moment où il entre au combat."
        ),
        .aiRating = 8,
    },

    [ABILITY_PSYCHIC_SURGE] =
    {
        .name = _("Créa-Psy"),
        .description = COMPOUND_STRING(
            "Le Pokémon crée un Champ Psychique au\n"
            "moment où il entre au combat."
        ),
        .aiRating = 8,
    },

    [ABILITY_MISTY_SURGE] =
    {
        .name = _("Créa-Brume"),
        .description = COMPOUND_STRING(
            "Le Pokémon crée un Champ Brumeux au\n"
            "moment où il entre au combat."
        ),
        .aiRating = 8,
    },

    [ABILITY_GRASSY_SURGE] =
    {
        .name = _("Créa-Herbe"),
        .description = COMPOUND_STRING(
            "Le Pokémon crée un Champ Herbu au\n"
            "moment où il entre au combat."
        ),
        .aiRating = 8,
    },

    [ABILITY_FULL_METAL_BODY] =
    {
        .name = _("Métallo-Garde"),
        .description = COMPOUND_STRING(
            "Empêche les stats du Pokémon de baisser\n"
            "à cause d'une capacité ou d'un talent."
        ),
        .aiRating = 4,
    },

    [ABILITY_SHADOW_SHIELD] =
    {
        .name = _("Spectro-Bouclier"),
        .description = COMPOUND_STRING(
            "Le Pokémon subit moins de dégâts quand\n"
            "ses PV sont au maximum."
        ),
        .aiRating = 8,
    },

    [ABILITY_PRISM_ARMOR] =
    {
        .name = _("Prisme-Armure"),
        .description = COMPOUND_STRING(
            "Diminue la puissance des attaques super\n"
            "efficaces subies."
        ),
        .aiRating = 6,
    },

    [ABILITY_NEUROFORCE] =
    {
        .name = _("Cérébro-Force"),
        .description = COMPOUND_STRING(
            "Augmente encore plus la puissance des\n"
            "attaques super efficaces."
        ),
        .aiRating = 6,
    },

    [ABILITY_INTREPID_SWORD] =
    {
        .name = _("Lame Indomptable"),
        .description = COMPOUND_STRING(
            "Augmente l'Attaque du Pokémon quand il\n"
            "entre au combat."
        ),
        .aiRating = 3,
    },

    [ABILITY_DAUNTLESS_SHIELD] =
    {
        .name = _("Égide Inflexible"),
        .description = COMPOUND_STRING(
            "Augmente la Défense du Pokémon quand il\n"
            "entre au combat."
        ),
        .aiRating = 3,
    },

    [ABILITY_LIBERO] =
    {
        .name = _("Libéro"),
        .description = COMPOUND_STRING(
            "Le Pokémon prend le type de la capacité\n"
            "qu'il utilise."
        ),
    },

    [ABILITY_BALL_FETCH] =
    {
        .name = _("Ramasse Ball"),
        .description = COMPOUND_STRING(
            "Si le Pokémon ne tient aucun objet, il\n"
            "ramassera la Poké Ball lors du premier\n"
            "lancer raté du combat."
        ),
        .aiRating = 0,
    },

    [ABILITY_COTTON_DOWN] =
    {
        .name = _("Effilochage"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon est touché par une\n"
            "attaque, il dissémine des aigrettes qui\n"
            "diminuent la Vitesse de tout le monde,\n"
            "sauf la sienne."
        ),
        .aiRating = 3,
    },

    [ABILITY_PROPELLER_TAIL] =
    {
        .name = _("Propulseur"),
        .description = COMPOUND_STRING(
            "Permet d'ignorer l'effet des capacités\n"
            "ou des talents qui attirent les\n"
            "capacités."
        ),
        .aiRating = 2,
    },

    [ABILITY_MIRROR_ARMOR] =
    {
        .name = _("Armure Miroir"),
        .description = COMPOUND_STRING(
            "Le Pokémon renvoie les effets\n"
            "réducteurs de stats qu'il reçoit."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_GULP_MISSILE] =
    {
        .name = _("Dégobage"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon utilise Surf ou Plongée,\n"
            "il revient avec une proie. Lorsqu'il subit\n"
            "des dégâts par la suite, il attaque en\n"
            "recrachant sa proie."
        ),
        .aiRating = 3,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeCopied = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeTraced = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STALWART] =
    {
        .name = _("Nerfs d'Acier"),
        .description = COMPOUND_STRING(
            "Permet d'ignorer l'effet des capacités\n"
            "ou des talents qui attirent les\n"
            "capacités."
        ),
        .aiRating = 2,
    },

    [ABILITY_STEAM_ENGINE] =
    {
        .name = _("Turbine"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon est touché par des\n"
            "capacités de type Eau ou Feu, sa\n"
            "Vitesse augmente énormément."
        ),
        .aiRating = 3,
    },

    [ABILITY_PUNK_ROCK] =
    {
        .name = _("Punk Rock"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des capacités\n"
            "basées sur le son. Le Pokémon ne subit\n"
            "que la moitié des dégâts quand il est\n"
            "touché par ce genre de capacités."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SAND_SPIT] =
    {
        .name = _("Expul'Sable"),
        .description = COMPOUND_STRING(
            "Le Pokémon déclenche une tempête de\n"
            "sable quand il subit une attaque."
        ),
        .aiRating = 5,
    },

    [ABILITY_ICE_SCALES] =
    {
        .name = _("Écailles Glacées"),
        .description = COMPOUND_STRING(
            "Le Pokémon est protégé par des écailles\n"
            "de glace. Les dégâts qu'il subit par des\n"
            "capacités spéciales sont divisés par\n"
            "deux."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_RIPEN] =
    {
        .name = _("Mûrissement"),
        .description = COMPOUND_STRING(
            "Le Pokémon fait mûrir la Baie qu'il tient\n"
            "et double ainsi son effet."
        ),
        .aiRating = 4,
    },

    [ABILITY_ICE_FACE] =
    {
        .name = _("Tête de Gel"),
        .description = COMPOUND_STRING(
            "Le glaçon sur sa tête encaisse les\n"
            "attaques physiques à la place du\n"
            "Pokémon. Le glaçon se reforme quand il\n"
            "grêle."
        ),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .breakable = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_SPOT] =
    {
        .name = _("Cercle d'Énergie"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des capacités des\n"
            "Pokémon qui se trouvent à proximité."
        ),
        .aiRating = 2,
    },

    [ABILITY_MIMICRY] =
    {
        .name = _("Mimétisme"),
        .description = COMPOUND_STRING(
            "Le Pokémon adopte le même type que le\n"
            "terrain lorsqu'un champ est actif."
        ),
        .aiRating = 2,
    },

    [ABILITY_SCREEN_CLEANER] =
    {
        .name = _("Brise-Barrière"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon entre au combat, les\n"
            "effets de Mur Lumière, Protection et\n"
            "Voile Aurore disparaissent pour les\n"
            "alliés comme pour les ennemis."
        ),
        .aiRating = 3,
    },

    [ABILITY_STEELY_SPIRIT] =
    {
        .name = _("Boost Acier"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des attaques de\n"
            "type Acier du Pokémon et de ses alliés."
        ),
        .aiRating = 2,
    },

    [ABILITY_PERISH_BODY] =
    {
        .name = _("Corps Condamné"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon est directement\n"
            "touché par une attaque, l'assaillant et\n"
            "lui tomberont K.O. dans trois tours."
        ),
        .aiRating = -1,
    },

    [ABILITY_WANDERING_SPIRIT] =
    {
        .name = _("Âme Vagabonde"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon est directement\n"
            "touché par une attaque, il échange son\n"
            "talent avec celui de l'assaillant."
        ),
        .aiRating = 2,
    },

    [ABILITY_GORILLA_TACTICS] =
    {
        .name = _("Entêtement"),
        .description = COMPOUND_STRING(
            "Augmente l'Attaque, mais empêche\n"
            "d'utiliser toute autre capacité que celle\n"
            "utilisée en premier par le Pokémon."
        ),
        .aiRating = 4,
    },

    [ABILITY_NEUTRALIZING_GAS] =
    {
        .name = _("Gaz Inhibiteur"),
        .description = COMPOUND_STRING(
            "Si un Pokémon avec Gaz Inhibiteur est\n"
            "sur le terrain, les effets des talents\n"
            "de tous les autres Pokémon sont\n"
            "annulés."
        ),
        .aiRating = 5,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_PASTEL_VEIL] =
    {
        .name = _("Voile Pastel"),
        .description = COMPOUND_STRING(
            "Protège le Pokémon et ses alliés contre\n"
            "toutes les altérations de statut liées à\n"
            "l'empoisonnement."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_HUNGER_SWITCH] =
    {
        .name = _("Déclic Fringale"),
        .description = COMPOUND_STRING(
            "À la fin de chaque tour, le Pokémon\n"
            "alterne entre ses formes Mode Rassasié\n"
            "et Mode Affamé."
        ),
        .aiRating = 2,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUICK_DRAW] =
    {
        .name = _("Tir Vif"),
        .description = COMPOUND_STRING(
            "Permet parfois au Pokémon d'agir en\n"
            "premier."
        ),
        .aiRating = 4,
    },

    [ABILITY_UNSEEN_FIST] =
    {
        .name = _("Poing Invisible"),
        .description = COMPOUND_STRING(
            "Si le Pokémon utilise une attaque\n"
            "directe, celle-ci pourra passer outre\n"
            "les protections de la cible."
        ),
        .aiRating = 6,
    },

    [ABILITY_CURIOUS_MEDICINE] =
    {
        .name = _("Breuvage Suspect"),
        .description = COMPOUND_STRING(
            "Quand il entre au combat, le Pokémon\n"
            "répand une substance qui annule les\n"
            "changements de stats de ses alliés."
        ),
        .aiRating = 3,
    },

    [ABILITY_TRANSISTOR] =
    {
        .name = _("Transistor"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des attaques de\n"
            "type Électrik."
        ),
        .aiRating = 6,
    },

    [ABILITY_DRAGONS_MAW] =
    {
        .name = _("Dent de Dragon"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des attaques de\n"
            "type Dragon."
        ),
        .aiRating = 6,
    },

    [ABILITY_CHILLING_NEIGH] =
    {
        .name = _("Blanche Ruade"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon met un ennemi K.O., il\n"
            "émet un hennissement glaçant, ce qui\n"
            "augmente son Attaque."
        ),
        .aiRating = 7,
    },

    [ABILITY_GRIM_NEIGH] =
    {
        .name = _("Sombre Ruade"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon met un ennemi K.O., il\n"
            "émet un hennissement terrifiant qui\n"
            "augmente son Attaque Spéciale."
        ),
        .aiRating = 7,
    },

    [ABILITY_AS_ONE_ICE_RIDER] =
    {
        .name = _("Osmose Équine"),
        .description = COMPOUND_STRING(
            "Le talent Tension de Sylveroy est\n"
            "cumulé."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_AS_ONE_SHADOW_RIDER] =
    {
        .name = _("Osmose Équine"),
        .description = COMPOUND_STRING(
            "Le talent Sombre Ruade de Spectreval\n"
            "est cumulé."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_LINGERING_AROMA] =
    {
        .name = _("Odeur Tenace"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon subit une attaque\n"
            "directe, le talent de l'attaquant est\n"
            "remplacé par Odeur Tenace."
        ),
        .aiRating = 5,
    },

    [ABILITY_SEED_SOWER] =
    {
        .name = _("Semencier"),
        .description = COMPOUND_STRING(
            "Le Pokémon crée un champ herbu quand il\n"
            "subit une attaque."
        ),
        .aiRating = 5,
    },

    [ABILITY_THERMAL_EXCHANGE] =
    {
        .name = _("Thermodynamique"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon est touché par une\n"
            "capacité de type Feu, son Attaque\n"
            "augmente. Il ne peut pas être brûlé."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANGER_SHELL] =
    {
        .name = _("Courroupace"),
        .description = COMPOUND_STRING(
            "Le Pokémon enrage s'il a moins de la\n"
            "moitié de ses PV après avoir subi une\n"
            "attaque. Sa Déf., Déf. Spé. baissent, et\n"
            "son Atq., Atq. Spé., Vit. augmentent."
        ),
        .aiRating = 3,
    },

    [ABILITY_PURIFYING_SALT] =
    {
        .name = _("Sel Purificateur"),
        .description = COMPOUND_STRING(
            "Le sel pur immunise le Pokémon contre\n"
            "les altérations de statut, et diminue de\n"
            "moitié les dégâts des capacités de type\n"
            "Spectre."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_WELL_BAKED_BODY] =
    {
        .name = _("Bien Cuit"),
        .description = COMPOUND_STRING(
            "Si le Pokémon est touché par une\n"
            "capacité de type Feu, il ne subit aucun\n"
            "dégât et sa Défense augmente beaucoup."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_WIND_RIDER] =
    {
        .name = _("Aéroporté"),
        .description = COMPOUND_STRING(
            "L'Attaque du Pokémon augmente si un\n"
            "vent arrière souffle ou s'il est touché\n"
            "par une capacité faisant appel au vent."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_GUARD_DOG] =
    {
        .name = _("Chien de Garde"),
        .description = COMPOUND_STRING(
            "L'Attaque du Pokémon augmente s'il subit\n"
            "l'effet du talent Intimidation. Les\n"
            "capacités ou objets qui font changer de\n"
            "Pokémon n'ont aucun effet sur lui."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ROCKY_PAYLOAD] =
    {
        .name = _("Porte-Roche"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des capacités de\n"
            "type Roche."
        ),
        .aiRating = 6,
    },

    [ABILITY_WIND_POWER] =
    {
        .name = _("Turbine Éolienne"),
        .description = COMPOUND_STRING(
            "Si le Pokémon est touché par une\n"
            "capacité faisant appel au vent, il se\n"
            "charge en électricité."
        ),
        .aiRating = 4,
    },

    [ABILITY_ZERO_TO_HERO] =
    {
        .name = _("Supermutation"),
        .description = COMPOUND_STRING(
            "Le Pokémon prend sa Forme Super en\n"
            "quittant le combat."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_COMMANDER] =
    {
        .name = _("Commandant"),
        .description = COMPOUND_STRING(
            "Si un Oyacata allié est sur le terrain\n"
            "quand ce Pokémon rejoint le combat, ce\n"
            "dernier entre dans sa bouche et devient\n"
            "son commandant."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_ELECTROMORPHOSIS] =
    {
        .name = _("Grecharge"),
        .description = COMPOUND_STRING(
            "Si le Pokémon subit des dégâts, il se\n"
            "charge en électricité."
        ),
        .aiRating = 5,
    },

    [ABILITY_PROTOSYNTHESIS] =
    {
        .name = _("Paléosynthèse"),
        .description = COMPOUND_STRING(
            "Quand le soleil brille ou que le Pokémon\n"
            "tient une capsule d'Énergie Booster, sa\n"
            "stat la plus élevée augmente."
        ),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUARK_DRIVE] =
    {
        .name = _("Charge Quantique"),
        .description = COMPOUND_STRING(
            "Quand un champ électrifié est actif ou\n"
            "que le Pokémon tient une capsule\n"
            "d'Énergie Booster, sa stat la plus élevée\n"
            "augmente."
        ),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GOOD_AS_GOLD] =
    {
        .name = _("Corps en Or"),
        .description = COMPOUND_STRING(
            "Le corps en or pur et robuste du\n"
            "Pokémon l'immunise contre les capacités\n"
            "de statut des autres Pokémon."
        ),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_VESSEL_OF_RUIN] =
    {
        .name = _("Urne du Fléau"),
        .description = COMPOUND_STRING(
            "Le pouvoir de l'urne qui appelle le fléau\n"
            "affaiblit l'Attaque Spéciale de tous les\n"
            "autres Pokémon."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SWORD_OF_RUIN] =
    {
        .name = _("Épée du Fléau"),
        .description = COMPOUND_STRING(
            "Le pouvoir de l'épée qui appelle le fléau\n"
            "affaiblit la Défense de tous les autres\n"
            "Pokémon."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_TABLETS_OF_RUIN] =
    {
        .name = _("Bois du Fléau"),
        .description = COMPOUND_STRING(
            "Le pouvoir du bois qui appelle le fléau\n"
            "affaiblit l'Attaque de tous les autres\n"
            "Pokémon."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_BEADS_OF_RUIN] =
    {
        .name = _("Perles du Fléau"),
        .description = COMPOUND_STRING(
            "Le pouvoir des perles qui appellent le\n"
            "fléau affaiblit la Défense Spéciale de\n"
            "tous les autres Pokémon."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ORICHALCUM_PULSE] =
    {
        .name = _("Pouls Orichalque"),
        .description = COMPOUND_STRING(
            "Le Pokémon invoque le soleil quand il\n"
            "rejoint le combat. Quand le soleil brille,\n"
            "une pulsation primitive augmente son\n"
            "Attaque."
        ),
        .aiRating = 8,
    },

    [ABILITY_HADRON_ENGINE] =
    {
        .name = _("Moteur à Hadrons"),
        .description = COMPOUND_STRING(
            "Le Pokémon crée un champ électrifié\n"
            "quand il rejoint le combat. Une machine\n"
            "du futur fait monter son Attaque\n"
            "Spéciale si un champ électrifié est actif."
        ),
        .aiRating = 8,
    },

    [ABILITY_OPPORTUNIST] =
    {
        .name = _("Opportuniste"),
        .description = COMPOUND_STRING(
            "Quand les stats de l'ennemi augmentent,\n"
            "le Pokémon en profite pour augmenter\n"
            "ses stats de la même manière."
        ),
        .aiRating = 5,
    },

    [ABILITY_CUD_CHEW] =
    {
        .name = _("Ruminant"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon mange une Baie, il la\n"
            "régurgite à la fin du tour suivant et la\n"
            "mange une nouvelle fois."
        ),
        .aiRating = 4,
    },

    [ABILITY_SHARPNESS] =
    {
        .name = _("Incisif"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des capacités\n"
            "tranchantes."
        ),
        .aiRating = 7,
    },

    [ABILITY_SUPREME_OVERLORD] =
    {
        .name = _("Général Suprême"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon entre sur le terrain,\n"
            "son Attaque et son Attaque Spéciale\n"
            "augmentent légèrement pour chaque allié\n"
            "mis K.O. auparavant."
        ),
        .aiRating = 6,
    },

    [ABILITY_COSTAR] =
    {
        .name = _("Collab"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon entre sur le terrain, il\n"
            "copie les changements de stats de son\n"
            "allié."
        ),
        .aiRating = 5,
    },

    [ABILITY_TOXIC_DEBRIS] =
    {
        .name = _("Dépôt Toxique"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon est touché par une\n"
            "capacité physique, il répand des pics\n"
            "toxiques dans le camp adverse."
        ),
        .aiRating = 4,
    },

    [ABILITY_ARMOR_TAIL] =
    {
        .name = _("Armure Caudale"),
        .description = COMPOUND_STRING(
            "Une étrange queue recouvre la tête du\n"
            "Pokémon, ce qui empêche ce dernier et\n"
            "ses alliés d'être visés par une capacité\n"
            "prioritaire."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_EARTH_EATER] =
    {
        .name = _("Absorbe-Terre"),
        .description = COMPOUND_STRING(
            "Si le Pokémon est touché par une\n"
            "capacité de type Sol, il regagne des PV\n"
            "au lieu de subir des dégâts."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MYCELIUM_MIGHT] =
    {
        .name = _("Force Fongique"),
        .description = COMPOUND_STRING(
            "Le Pokémon agit toujours plus lentement\n"
            "quand il utilise une capacité de statut,\n"
            "mais il ignore les talents adverses."
        ),
        .aiRating = 2,
    },

    [ABILITY_HOSPITALITY] =
    {
        .name = _("Aux Petits Soins"),
        .description = COMPOUND_STRING(
            "Quand il rejoint le combat, ce Pokémon\n"
            "est aux petits soins avec son allié et\n"
            "restaure quelques PV."
        ),
        .aiRating = 5,
    },

    [ABILITY_MINDS_EYE] =
    {
        .name = _("Œil Révélateur"),
        .description = COMPOUND_STRING(
            "Le Pokémon ignore les changements\n"
            "d'Esquive des cibles et peut toucher les\n"
            "Pokémon Spectre avec des capacités\n"
            "Normal ou Combat."
        ),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_TEAL_MASK] =
    {
        .name = _("Force Mémorielle"),
        .description = COMPOUND_STRING(
            "Le Pokémon fait briller le Masque en\n"
            "puisant dans ses souvenirs, ce qui\n"
            "augmente ses stats."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK] =
    {
        .name = _("Force Mémorielle"),
        .description = COMPOUND_STRING(
            "Le Pokémon fait briller le Masque en\n"
            "puisant dans ses souvenirs, ce qui\n"
            "augmente ses stats."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_WELLSPRING_MASK] =
    {
        .name = _("Force Mémorielle"),
        .description = COMPOUND_STRING(
            "Le Pokémon fait briller le Masque en\n"
            "puisant dans ses souvenirs, ce qui\n"
            "augmente ses stats."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK] =
    {
        .name = _("Force Mémorielle"),
        .description = COMPOUND_STRING(
            "Le Pokémon fait briller le Masque en\n"
            "puisant dans ses souvenirs, ce qui\n"
            "augmente ses stats."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TOXIC_CHAIN] =
    {
        .name = _("Chaîne Toxique"),
        .description = COMPOUND_STRING(
            "Grâce aux pouvoirs de sa chaîne\n"
            "imprégnée de toxines, le Pokémon peut\n"
            "empoisonner gravement sa cible en la\n"
            "touchant avec une capacité."
        ),
        .aiRating = 8,
    },

    [ABILITY_SUPERSWEET_SYRUP] =
    {
        .name = _("Nectar Mielleux"),
        .description = COMPOUND_STRING(
            "La première fois que le Pokémon entre\n"
            "au combat, une odeur de nectar sucré\n"
            "se répand sur le terrain, ce qui baisse\n"
            "l'Esquive de l'adversaire."
        ),
        .aiRating = 5,
    },

    [ABILITY_TERA_SHIFT] =
    {
        .name = _("Téramorphose"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon rejoint le combat, il\n"
            "absorbe l'énergie alentour et prend sa\n"
            "Forme Téracristal."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TERA_SHELL] =
    {
        .name = _("Téra-Carapace"),
        .description = COMPOUND_STRING(
            "Grâce à sa carapace, les capacités\n"
            "subies par ce Pokémon quand ses PV\n"
            "sont au maximum ne sont pas très\n"
            "efficaces."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_TERAFORM_ZERO] =
    {
        .name = _("Téraformation 0"),
        .description = COMPOUND_STRING(
            "Lorsque Terapagos prend sa Forme\n"
            "Stellaire, il utilise son pouvoir enfoui\n"
            "pour annuler les effets de la météo et\n"
            "des champs actifs."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POISON_PUPPETEER] =
    {
        .name = _("Emprise Toxique"),
        .description = COMPOUND_STRING(
            "Lorsque Pêchaminus empoisonne un\n"
            "Pokémon grâce à l'une de ses capacités,\n"
            "ce dernier devient également confus."
        ),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_PIERCING_DRILL] =
    {
        .name = _("Transperceuse"),
        .description = COMPOUND_STRING(
            "Le Pokémon ignore les effets de\n"
            "protection des adversaires."
        ),
    },

    [ABILITY_DRAGONIZE] =
    {
        .name = _("Peau Draconique"),
        .description = COMPOUND_STRING(
            "Les capacités de type Normal du Pokémon\n"
            "prennent le type Dragon et leur\n"
            "puissance est multipliée par 1,2."
        ),
    },

    [ABILITY_EELEVATE] =
    {
        .name = _("Eelevate"),
        .description = COMPOUND_STRING("Unimplemented."),
    },

    [ABILITY_314] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("No special ability."),
    },

    [ABILITY_MEGA_SOL] =
    {
        .name = _("Méga-Soleil"),
        .description = COMPOUND_STRING(
            "Le Pokémon peut utiliser ses capacités\n"
            "comme si le soleil brillait, même si ce\n"
            "n'est pas le cas."
        ),
    },

    [ABILITY_FIRE_MANE] =
    {
        .name = _("Fire Mane"),
        .description = COMPOUND_STRING("Unimplemented."),
    },

    [ABILITY_317] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("No special ability."),
    },

    [ABILITY_SPICY_SPRAY] =
    {
        .name = _("Habanéruption"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon subit des dégâts d'une\n"
            "capacité, il brûle l'adversaire."
        ),
    },
};
