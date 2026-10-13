const struct EasyChatWordInfo gEasyChatGroup_Conditions[] = {
    [EC_INDEX(EC_WORD_HOT)] =
    {
        .text = COMPOUND_STRING("CHAUD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABSENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXISTS)] =
    {
        .text = COMPOUND_STRING("EXISTE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEAKENED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCESS)] =
    {
        .text = COMPOUND_STRING("EXCES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KIND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPROVED)] =
    {
        .text = COMPOUND_STRING("APPROUVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AMUSING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAS)] =
    {
        .text = COMPOUND_STRING("LENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPROVED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOOD)] =
    {
        .text = COMPOUND_STRING("BON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NONE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LESS)] =
    {
        .text = COMPOUND_STRING("LENTEUR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MOMENTUM)] =
    {
        .text = COMPOUND_STRING("VITESSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UPSIDE_DOWN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOING)] =
    {
        .text = COMPOUND_STRING("FACILITE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEIRD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEIRD)] =
    {
        .text = COMPOUND_STRING("BIZARRE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOOD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BUSY)] =
    {
        .text = COMPOUND_STRING("OCCUPE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOISY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOGETHER)] =
    {
        .text = COMPOUND_STRING("ENSEMBLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FULL)] =
    {
        .text = COMPOUND_STRING("PLEIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXPENSIVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABSENT)] =
    {
        .text = COMPOUND_STRING("ABSENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CORRECT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEING)] =
    {
        .text = COMPOUND_STRING("ETANT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TASTY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEED)] =
    {
        .text = COMPOUND_STRING("J'AI BESOIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BECOMES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TASTY)] =
    {
        .text = COMPOUND_STRING("DELICIEUX"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIFFERENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SKILLED)] =
    {
        .text = COMPOUND_STRING("DOUE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENTERTAINING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOISY)] =
    {
        .text = COMPOUND_STRING("BRUYANT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOCILE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BIG)] =
    {
        .text = COMPOUND_STRING("ENORME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SKILLED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LATE)] =
    {
        .text = COMPOUND_STRING("TARD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEALTHY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CLOSE)] =
    {
        .text = COMPOUND_STRING("PROCHE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BIG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOCILE)] =
    {
        .text = COMPOUND_STRING("DOCILE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOGETHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AMUSING)] =
    {
        .text = COMPOUND_STRING("AMUSANT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MISTAKE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENTERTAINING)] =
    {
        .text = COMPOUND_STRING("DISTRAYANT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PERFECTION)] =
    {
        .text = COMPOUND_STRING("PERFECTION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCESS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PRETTY)] =
    {
        .text = COMPOUND_STRING("JOLI"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXISTS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEALTHY)] =
    {
        .text = COMPOUND_STRING("EN FORME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FABULOUS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCELLENT)] =
    {
        .text = COMPOUND_STRING("REMARQUABLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UPSIDE_DOWN)] =
    {
        .text = COMPOUND_STRING("BEBETE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TIRED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COLD)] =
    {
        .text = COMPOUND_STRING("FROID"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_REFRESHING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REFRESHING)] =
    {
        .text = COMPOUND_STRING("FRAIS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COLD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNAVOIDABLE)] =
    {
        .text = COMPOUND_STRING("INEVITABLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BADLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUCH)] =
    {
        .text = COMPOUND_STRING("IGNORANT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SKILL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OVERWHELMING)] =
    {
        .text = COMPOUND_STRING("IRRESISTIBLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUCH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FABULOUS)] =
    {
        .text = COMPOUND_STRING("FABULEUX"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LACKS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELSE)] =
    {
        .text = COMPOUND_STRING("NUNUCHE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IMPOSSIBLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXPENSIVE)] =
    {
        .text = COMPOUND_STRING("CHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNAVOIDABLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CORRECT)] =
    {
        .text = COMPOUND_STRING("CORRECTEMENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OVERWHELMING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IMPOSSIBLE)] =
    {
        .text = COMPOUND_STRING("IMPOSSIBLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMALL)] =
    {
        .text = COMPOUND_STRING("PETIT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BORED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIFFERENT)] =
    {
        .text = COMPOUND_STRING("DIFFERENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PRETTY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TIRED)] =
    {
        .text = COMPOUND_STRING("FATIGUE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SKILL)] =
    {
        .text = COMPOUND_STRING("HABILETE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LESS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOP)] =
    {
        .text = COMPOUND_STRING("MAXIMUM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NON_STOP)] =
    {
        .text = COMPOUND_STRING("NON-STOP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PREPOSTEROUS)] =
    {
        .text = COMPOUND_STRING("RIDICULE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOUSY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NONE)] =
    {
        .text = COMPOUND_STRING("AUCUN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MYSTERY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOTHING)] =
    {
        .text = COMPOUND_STRING("RIEN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NATURAL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NATURAL)] =
    {
        .text = COMPOUND_STRING("NATUREL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NON_STOP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BECOMES)] =
    {
        .text = COMPOUND_STRING("DEVIENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LUKEWARM)] =
    {
        .text = COMPOUND_STRING("TIEDE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BUSY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAST)] =
    {
        .text = COMPOUND_STRING("RAPIDE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEEMS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOW)] =
    {
        .text = COMPOUND_STRING("BAS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PERFECTION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWFUL)] =
    {
        .text = COMPOUND_STRING("TERRIBLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMALL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALONE)] =
    {
        .text = COMPOUND_STRING("SEUL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WELL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BORED)] =
    {
        .text = COMPOUND_STRING("JE M'ENNUIE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FULL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SECRET)] =
    {
        .text = COMPOUND_STRING("SECRET"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CLOSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MYSTERY)] =
    {
        .text = COMPOUND_STRING("MYSTERE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LACKS)] =
    {
        .text = COMPOUND_STRING("IL MANQUE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCELLENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEST)] =
    {
        .text = COMPOUND_STRING("MEILLEUR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PREPOSTEROUS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOUSY)] =
    {
        .text = COMPOUND_STRING("MINABLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOTHING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MISTAKE)] =
    {
        .text = COMPOUND_STRING("ERREUR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SECRET),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KIND)] =
    {
        .text = COMPOUND_STRING("AGREABLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALONE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WELL)] =
    {
        .text = COMPOUND_STRING("PIRE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SIMPLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEAKENED)] =
    {
        .text = COMPOUND_STRING("AFFAIBLI"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LATE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SIMPLE)] =
    {
        .text = COMPOUND_STRING("SIMPLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWFUL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEEMS)] =
    {
        .text = COMPOUND_STRING("ON DIRAIT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LUKEWARM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BADLY)] =
    {
        .text = COMPOUND_STRING("GRAVEMENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOMENTUM),
        .enabled = TRUE,
    },
};
