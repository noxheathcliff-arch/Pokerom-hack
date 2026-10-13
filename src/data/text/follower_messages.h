extern const u8 EventScript_FollowerIsShivering[];
extern const u8 EventScript_FollowerNostalgia[];
extern const u8 EventScript_FollowerHopping[];
extern const u8 EventScript_FollowerJumpOnPlayer[];
extern const u8 EventScript_FollowerCuddling[];
extern const u8 EventScript_FollowerShiverCuddling[];
extern const u8 EventScript_FollowerGetCloser[];
extern const u8 EventScript_FollowerPokingPlayer[];
extern const u8 EventScript_FollowerLookAround[];
extern const u8 EventScript_FollowerLookAway[];
extern const u8 EventScript_FollowerLookAwayBark[];
extern const u8 EventScript_FollowerLookAwayPoke[];
extern const u8 EventScript_FollowerPokeGround[];
extern const u8 EventScript_FollowerStartled[];
extern const u8 EventScript_FollowerFastHopping[];
extern const u8 EventScript_FollowerDizzy[];
extern const u8 EventScript_FollowerLookAroundScared[];
extern const u8 EventScript_FollowerDance[];
extern const u8 EventScript_FollowerLookUp[];

// 'Generic', unconditional happy messages
static const u8 sHappyMsg00[] = _("{STR_VAR_1} vous touche le ventre!");
static const u8 sHappyMsg01[] = _("{STR_VAR_1} a l'air embarrassé.");
static const u8 sHappyMsg02[] = _("{STR_VAR_1} a l'air vraiment super\ncontent.");
static const u8 sHappyMsg03[] = _("{STR_VAR_1} se réjouit de voir\nles vagues.");
static const u8 sHappyMsg04[] = _("{STR_VAR_1} vous suit avec entrain.");
static const u8 sHappyMsg05[] = _("{STR_VAR_1} est plein de vie!");
static const u8 sHappyMsg06[] = _("{STR_VAR_1} est absolument ravi!");
static const u8 sHappyMsg07[] = _("{STR_VAR_1} est tout excité!");
static const u8 sHappyMsg08[] = _("{STR_VAR_1} renifle les alentours.");
static const u8 sHappyMsg09[] = _("{STR_VAR_1} sautille de joie!");
static const u8 sHappyMsg10[] = _("{STR_VAR_1} frétille de joie.");
static const u8 sHappyMsg11[] = _("Il renifle la fumée.");
static const u8 sHappyMsg12[] = _("{STR_VAR_1} vous touche le ventre!");
static const u8 sHappyMsg13[] = _("Il s'étire pour se mettre à l'aise.");
static const u8 sHappyMsg14[] = _("On dirait que {STR_VAR_1} veut passer\ndevant!");
static const u8 sHappyMsg15[] = _("{STR_VAR_1} fait de son mieux pour\nvous suivre.");
static const u8 sHappyMsg16[] = _("{STR_VAR_1} se blottit contre vous!");
static const u8 sHappyMsg17[] = _("{STR_VAR_1} fait des cabrioles.");
static const u8 sHappyMsg18[] = _("{STR_VAR_1} a l'air très content.");
static const u8 sHappyMsg19[] = _("{STR_VAR_1} est si heureux qu'il ne\ntient pas en place.");
static const u8 sHappyMsg20[] = _("{STR_VAR_1} vous dévisage lentement.");
static const u8 sHappyMsg21[] = _("{STR_VAR_1} se sent prêt!");
static const u8 sHappyMsg22[] = _("{STR_VAR_1} écoute avec précaution\nles bruits alentour.");
static const u8 sHappyMsg23[] = _("{STR_VAR_1} a l'air très intéressé!");
static const u8 sHappyMsg24[] = _("{STR_VAR_1} y met de la force!");
static const u8 sHappyMsg25[] = _("{STR_VAR_1} a le regard qui brille!");
static const u8 sHappyMsg26[] = _("{STR_VAR_1} se tourne vers vous et\nsourit!");
static const u8 sHappyMsg27[] = _("Il renifle une fleur.");
static const u8 sHappyMsg28[] = _("{STR_VAR_1} vous salue!");
static const u8 sHappyMsg29[] = _("{STR_VAR_1} se retourne en souriant!");
static const u8 sHappyMsg30[] = _("Ah! {STR_VAR_1} vous fait un câlin!");
// Conditional messages begin here, index 31
static const u8 sHappyMsg31[] = _("Il aime le beau temps on dirait!");
static const u8 sHappyMsg32[] = _("{STR_VAR_1} est prêt à en découdre!");

const struct FollowerMsgInfo gFollowerHappyMessages[] = {
    {sHappyMsg00, EventScript_FollowerPokingPlayer},
    {sHappyMsg01}, {sHappyMsg02}, {sHappyMsg03}, {sHappyMsg04}, {sHappyMsg05}, {sHappyMsg06}, {sHappyMsg07},
    {sHappyMsg08, EventScript_FollowerLookAround},
    {sHappyMsg09, EventScript_FollowerHopping},
    {sHappyMsg10}, {sHappyMsg11},
    {sHappyMsg12, EventScript_FollowerPokingPlayer},
    {sHappyMsg13, EventScript_FollowerLookAround},
    {sHappyMsg14}, {sHappyMsg15},
    {sHappyMsg16, EventScript_FollowerCuddling},
    {sHappyMsg17}, {sHappyMsg18},
    {sHappyMsg19, EventScript_FollowerFastHopping},
    {sHappyMsg20}, {sHappyMsg21}, {sHappyMsg22}, {sHappyMsg23}, {sHappyMsg24}, {sHappyMsg25}, {sHappyMsg26}, {sHappyMsg27}, {sHappyMsg28}, {sHappyMsg29},
    {sHappyMsg30, EventScript_FollowerCuddling},
    {sHappyMsg31}, {sHappyMsg32},
};

// Unconditional neutral messages
static const u8 sNeutralMsg00[] = _("{STR_VAR_1} s'amuse à gratter le sol.");
static const u8 sNeutralMsg01[] = _("{STR_VAR_1} est en alerte!");
static const u8 sNeutralMsg02[] = _("{STR_VAR_1} a le regard dans le vide…");
static const u8 sNeutralMsg03[] = _("{STR_VAR_1} vit sa vie.");
static const u8 sNeutralMsg04[] = _("{STR_VAR_1} bâille bruyamment.");
static const u8 sNeutralMsg05[] = _("{STR_VAR_1} inspecte les alentours.");
static const u8 sNeutralMsg06[] = _("{STR_VAR_1} se retourne et vous\nsourit.");
static const u8 sNeutralMsg07[] = _("{STR_VAR_1} scrute les alentours.");
static const u8 sNeutralMsg08[] = _("{STR_VAR_1} pousse un cri de guerre.");
static const u8 sNeutralMsg09[] = _("{STR_VAR_1} danse super bien!");
static const u8 sNeutralMsg10[] = _("{STR_VAR_1} se sent d'attaque!");
static const u8 sNeutralMsg11[] = _("{STR_VAR_1} regarde fixement au loin.");
static const u8 sNeutralMsg12[] = _("{STR_VAR_1} est tout tendu.");
static const u8 sNeutralMsg13[] = _("{STR_VAR_1} crie au loin!");

const struct FollowerMsgInfo gFollowerNeutralMessages[] = {
    {sNeutralMsg00, EventScript_FollowerPokeGround},
    {sNeutralMsg01},
    {sNeutralMsg02, EventScript_FollowerLookAway},
    {sNeutralMsg03, EventScript_FollowerLookAround},
    {sNeutralMsg04},
    {sNeutralMsg05, EventScript_FollowerLookAround},
    {sNeutralMsg06}, {sNeutralMsg07}, {sNeutralMsg08},
    {sNeutralMsg09, EventScript_FollowerDance},
    {sNeutralMsg10},
    {sNeutralMsg11, EventScript_FollowerLookAway},
    {sNeutralMsg12},
    {sNeutralMsg13, EventScript_FollowerLookAwayBark},
};

// Unconditional sad messages
static const u8 sSadMsg00[] = _("{STR_VAR_1} est étourdi.");
static const u8 sSadMsg01[] = _("{STR_VAR_1} vous marche sur les\npieds.");
static const u8 sSadMsg02[] = _("{STR_VAR_1} a l'air un peu fatigué.");
// Conditional messages begin, index 3
static const u8 sSadMsg03[] = _("{STR_VAR_1} a l'air déprimé…");
static const u8 sSadMsg04[] = _("Attention!\nIl va tomber…");
static const u8 sSadMsg05[] = _("{STR_VAR_1} va sûrement tomber!");
static const u8 sSadMsg06[] = _("{STR_VAR_1} vous suit de son mieux!");
static const u8 sSadMsg07[] = _("{STR_VAR_1} est inquiet…");

const struct FollowerMsgInfo gFollowerSadMessages[] = {
    {sSadMsg00, EventScript_FollowerDizzy},
    {sSadMsg01}, {sSadMsg02},
    {sSadMsg03}, {sSadMsg04}, {sSadMsg05}, {sSadMsg06}, {sSadMsg07},
};

// Unconditional upset messages
static const u8 sUpsetMsg00[] = _("{STR_VAR_1} a l'air fâché!");
static const u8 sUpsetMsg01[] = _("{STR_VAR_1} fait une drôle de tête…");
static const u8 sUpsetMsg02[] = _("{STR_VAR_1} tremble de froid…");
// Conditional messages, index 3
static const u8 sUpsetMsg03[] = _("{STR_VAR_1} se met à l'abri dans les\nhautes herbes.");

const struct FollowerMsgInfo gFollowerUpsetMessages[] = {
    {sUpsetMsg00}, {sUpsetMsg01},
    {sUpsetMsg02, EventScript_FollowerIsShivering},
    {sUpsetMsg03},
};

// Unconditional angry messages
static const u8 sAngryMsg00[] = _("{STR_VAR_1} pousse un grand cri!");
static const u8 sAngryMsg01[] = _("{STR_VAR_1} a l'air fâché!");
static const u8 sAngryMsg02[] = _("{STR_VAR_1} s'est mis en colère!");
static const u8 sAngryMsg03[] = _("{STR_VAR_1} détourne le regard…");
static const u8 sAngryMsg04[] = _("{STR_VAR_1} pousse un cri.");

const struct FollowerMsgInfo gFollowerAngryMessages[] = {
    {sAngryMsg00}, {sAngryMsg01}, {sAngryMsg02},
    {sAngryMsg03, EventScript_FollowerLookAway},
    {sAngryMsg04},
};

// Unconditional pensive messages
static const u8 sPensiveMsg00[] = _("{STR_VAR_1} regarde en bas fixement.");
static const u8 sPensiveMsg01[] = _("{STR_VAR_1} regarde alentour, l'air\nvague.");
static const u8 sPensiveMsg02[] = _("{STR_VAR_1} regarde en bas.");
static const u8 sPensiveMsg03[] = _("{STR_VAR_1} somnole…");
static const u8 sPensiveMsg04[] = _("{STR_VAR_1} vit sa vie.");
static const u8 sPensiveMsg05[] = _("{STR_VAR_1} est dans la lune…");
static const u8 sPensiveMsg06[] = _("{STR_VAR_1} bâille à s'en décrocher\nla mâchoire.");
static const u8 sPensiveMsg07[] = _("{STR_VAR_1} est relaxé.");
static const u8 sPensiveMsg08[] = _("{STR_VAR_1} vous fixe du regard…");
static const u8 sPensiveMsg09[] = _("{STR_VAR_1} vous dévisage…");
static const u8 sPensiveMsg10[] = _("{STR_VAR_1} vous regarde fixement.");
static const u8 sPensiveMsg11[] = _("{STR_VAR_1} regarde dans le vide…");
static const u8 sPensiveMsg12[] = _("{STR_VAR_1} renifle le sol.");
static const u8 sPensiveMsg13[] = _("{STR_VAR_1} a le regard dans le vide…");
static const u8 sPensiveMsg14[] = _("{STR_VAR_1} regarde droit dans votre\ndirection.");
static const u8 sPensiveMsg15[] = _("{STR_VAR_1} est tout tendu.");
static const u8 sPensiveMsg16[] = _("{STR_VAR_1} se tourne vers vous en\nse balançant doucement.");
static const u8 sPensiveMsg17[] = _("{STR_VAR_1} a l'air inquiet…");
static const u8 sPensiveMsg18[] = _("{STR_VAR_1} regarde les traces de\npas.");
static const u8 sPensiveMsg19[] = _("{STR_VAR_1} vous regarde dans\nles yeux.");

const struct FollowerMsgInfo gFollowerPensiveMessages[] = {
    {sPensiveMsg00},
    {sPensiveMsg01, EventScript_FollowerLookAround},
    {sPensiveMsg02}, {sPensiveMsg03}, {sPensiveMsg04},
    {sPensiveMsg05, EventScript_FollowerLookAround},
    {sPensiveMsg06}, {sPensiveMsg07}, {sPensiveMsg08}, {sPensiveMsg09}, {sPensiveMsg10},
    {sPensiveMsg11, EventScript_FollowerLookAway},
    {sPensiveMsg12, EventScript_FollowerPokeGround},
    {sPensiveMsg13, EventScript_FollowerLookAway},
    {sPensiveMsg14}, {sPensiveMsg15}, {sPensiveMsg16}, {sPensiveMsg17}, {sPensiveMsg18}, {sPensiveMsg19},
};

// All 'love' messages are unconditional
static const u8 sLoveMsg00[] = _("{STR_VAR_1} s'est blotti tout\ncontre vous.");
static const u8 sLoveMsg01[] = _("{STR_VAR_1} rougit!");
static const u8 sLoveMsg02[] = _("Ah! {STR_VAR_1} vous fait un câlin!");
static const u8 sLoveMsg03[] = _("Ah! {STR_VAR_1} a envie de s'amuser!");
static const u8 sLoveMsg04[] = _("{STR_VAR_1} se frotte contre vos\njambes.");
static const u8 sLoveMsg05[] = _("{STR_VAR_1} rougit de plaisir!");
static const u8 sLoveMsg06[] = _("Ah! {STR_VAR_1} se blottit contre\nvous!");
static const u8 sLoveMsg07[] = _("{STR_VAR_1} vous regarde en espérant\ndes caresses…");
static const u8 sLoveMsg08[] = _("{STR_VAR_1} se blottit contre vous!");
static const u8 sLoveMsg09[] = _("{STR_VAR_1} se blottit contre vos\njambes!");

const struct FollowerMsgInfo gFollowerLoveMessages[] = {
    {sLoveMsg00, EventScript_FollowerGetCloser},
    {sLoveMsg01},
    {sLoveMsg02, EventScript_FollowerCuddling},
    {sLoveMsg03},
    {sLoveMsg04, EventScript_FollowerCuddling},
    {sLoveMsg05},
    {sLoveMsg06, EventScript_FollowerCuddling},
    {sLoveMsg07},
    {sLoveMsg08, EventScript_FollowerGetCloser},
    {sLoveMsg09},
};

// Unconditional surprised messages
static const u8 sSurpriseMsg00[] = _("{STR_VAR_1} vacille et va tomber!");
static const u8 sSurpriseMsg01[] = _("{STR_VAR_1} s'est cogné contre\nvous!");
static const u8 sSurpriseMsg02[] = _("{STR_VAR_1} ne se retourne pas malgré\nvotre appel.");
static const u8 sSurpriseMsg03[] = _("{STR_VAR_1} regarde en bas.");
static const u8 sSurpriseMsg04[] = _("{STR_VAR_1} a manqué de trébucher!");
static const u8 sSurpriseMsg05[] = _("{STR_VAR_1} se met à gémir\ntout à coup.");
static const u8 sSurpriseMsg06[] = _("{STR_VAR_1} se sent d'attaque!");
static const u8 sSurpriseMsg07[] = _("{STR_VAR_1} se retourne tout à coup\net crie!");
static const u8 sSurpriseMsg08[] = _("{STR_VAR_1} se retourne d'un coup!");
static const u8 sSurpriseMsg09[] = _("{STR_VAR_1} est surpris que vous lui\nadressiez la parole!");
static const u8 sSurpriseMsg10[] = _("Snif! Snif!\nÇa sent bon on dirait!");
static const u8 sSurpriseMsg11[] = _("{STR_VAR_1} a l'air rassuré.");
static const u8 sSurpriseMsg12[] = _("{STR_VAR_1} vacille et va tomber!");
static const u8 sSurpriseMsg13[] = _("{STR_VAR_1} va sûrement tomber!");
static const u8 sSurpriseMsg14[] = _("{STR_VAR_1} vous suit prudemment.");
static const u8 sSurpriseMsg15[] = _("{STR_VAR_1} est tout tendu.");
static const u8 sSurpriseMsg16[] = _("{STR_VAR_1} sent quelque chose\nd'inhabituel…");
static const u8 sSurpriseMsg17[] = _("{STR_VAR_1} a peur et se blottit\ncontre vous!");
static const u8 sSurpriseMsg18[] = _("{STR_VAR_1} sent quelque chose\nd'inhabituel…");
static const u8 sSurpriseMsg19[] = _("{STR_VAR_1} est tout tendu.");
// Conditional messages, index 20
static const u8 sSurpriseMsg20[] = _("{STR_VAR_1} est surpris par la pluie!");

const struct FollowerMsgInfo gFollowerSurpriseMessages[] = {
    {sSurpriseMsg00},
    {sSurpriseMsg01, EventScript_FollowerPokingPlayer},
    {sSurpriseMsg02}, {sSurpriseMsg03}, {sSurpriseMsg04}, {sSurpriseMsg05}, {sSurpriseMsg06},
    {sSurpriseMsg07, EventScript_FollowerLookAwayBark},
    {sSurpriseMsg08, EventScript_FollowerLookAway},
    {sSurpriseMsg09},
    {sSurpriseMsg10, EventScript_FollowerLookAround},
    {sSurpriseMsg11}, {sSurpriseMsg12}, {sSurpriseMsg13}, {sSurpriseMsg14}, {sSurpriseMsg15}, {sSurpriseMsg16},
    {sSurpriseMsg17, EventScript_FollowerCuddling},
    {sSurpriseMsg18},
    {sSurpriseMsg19, EventScript_FollowerLookAround},
    {sSurpriseMsg20},
};

// Unconditional curious messages
static const u8 sCuriousMsg00[] = _("{STR_VAR_1} cherche quelque chose\nfrénétiquement.");
static const u8 sCuriousMsg01[] = _("{STR_VAR_1} ne faisait pas attention\net s'est cogné!");
static const u8 sCuriousMsg02[] = _("Snif! Snif!\nIl aurait senti quelque chose?");
static const u8 sCuriousMsg03[] = _("{STR_VAR_1} s'amuse à projeter des\ngravillons.");
static const u8 sCuriousMsg04[] = _("{STR_VAR_1} scrute les alentours\navec intérêt.");
static const u8 sCuriousMsg05[] = _("{STR_VAR_1} vous renifle.");
static const u8 sCuriousMsg06[] = _("{STR_VAR_1} a l'air tout intimidé.");

const struct FollowerMsgInfo gFollowerCuriousMessages[] = {
    {sCuriousMsg00, EventScript_FollowerLookAround},
    {sCuriousMsg01, EventScript_FollowerPokingPlayer},
    {sCuriousMsg02}, {sCuriousMsg03},
    {sCuriousMsg04, EventScript_FollowerLookAround},
    {sCuriousMsg05}, {sCuriousMsg06},
};

// Unconditional music messages
static const u8 sMusicMsg00[] = _("{STR_VAR_1} bouge avec adresse!");
static const u8 sMusicMsg01[] = _("{STR_VAR_1} bouge avec légèreté!");
static const u8 sMusicMsg02[] = _("{STR_VAR_1} se met à danser\ntout à coup!");
static const u8 sMusicMsg03[] = _("{STR_VAR_1} vous suit, l'air guilleret!");
static const u8 sMusicMsg04[] = _("{STR_VAR_1} a l'air de vouloir jouer\navec vous.");
static const u8 sMusicMsg05[] = _("{STR_VAR_1} fait des petits bonds.");
static const u8 sMusicMsg06[] = _("{STR_VAR_1} fredonne.");
static const u8 sMusicMsg07[] = _("{STR_VAR_1} vous mord la\nchaussure!");
static const u8 sMusicMsg08[] = _("{STR_VAR_1} se retourne et vous\nsourit.");
static const u8 sMusicMsg09[] = _("{STR_VAR_1} y met de la force!");
static const u8 sMusicMsg10[] = _("{STR_VAR_1} danse avec beaucoup\nd'entrain!");
static const u8 sMusicMsg11[] = _("{STR_VAR_1} a l'air très heureux!");
static const u8 sMusicMsg12[] = _("{STR_VAR_1} bondit partout!");
static const u8 sMusicMsg13[] = _("Snif! Snif!\nIl a repéré une bonne odeur!");
// Conditional music messages, index 14
static const u8 sMusicMsg14[] = _("{STR_VAR_1} adore la pluie!");

const struct FollowerMsgInfo gFollowerMusicMessages[] = {
    {sMusicMsg00, EventScript_FollowerLookAround},
    {sMusicMsg01},
    {sMusicMsg02, EventScript_FollowerDance},
    {sMusicMsg03},
    {sMusicMsg04, EventScript_FollowerHopping},
    {sMusicMsg05, EventScript_FollowerHopping},
    {sMusicMsg06}, {sMusicMsg07}, {sMusicMsg08}, {sMusicMsg09},
    {sMusicMsg10, EventScript_FollowerDance},
    {sMusicMsg11},
    {sMusicMsg12, EventScript_FollowerHopping},
    {sMusicMsg13, EventScript_FollowerNostalgia},
    {sMusicMsg14}
};


static const u8 sPoisonedMsg00[] = _("{STR_VAR_1} tremble à cause\ndu poison…");

const struct FollowerMsgInfo gFollowerPoisonedMessages[] = {
    {sPoisonedMsg00, EventScript_FollowerIsShivering},
};
