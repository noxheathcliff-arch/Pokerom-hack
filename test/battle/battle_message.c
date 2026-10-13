#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Battle Message: Send-in message depends on foe HP")
{
    u32 hp;

    PARAMETRIZE { hp = 100; }
    PARAMETRIZE { hp = 69; }
    PARAMETRIZE { hp = 39; }
    PARAMETRIZE { hp = 9; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(hp); MaxHP(100); }
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        if (hp > 69)
            MESSAGE("Okéoké! Go!");
        else if (hp > 39)
            MESSAGE("Okéoké! Fonce!");
        else if (hp > 9)
            MESSAGE("En avant, Okéoké!");
        else
            MESSAGE("L'ennemi est faible!\nAttaque, Okéoké!");
    }
}

SINGLE_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (Singles)")
{
    GIVEN {
        PLAYER(SPECIES_GASTLY);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GIRAFARIG);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("2\nveut se battre!{PAUSE 49}");
        MESSAGE("2 envoie\nun Qulbutoké!");
        MESSAGE("Fantominus! Go!");
        MESSAGE("2 retire Qulbutoké!");
        MESSAGE("2 envoie\nun Girafarig!");
    }
}

AI_SINGLE_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (AI Singles)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_SMART_TRAINER);
        PLAYER(SPECIES_GASTLY);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE);  }
        OPPONENT(SPECIES_GIRAFARIG) { Moves(MOVE_PSYCHIC); }
    } WHEN {
        TURN { EXPECT_SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("Un combat est lancé\npar " AI_TRAINER_NAME "!\p");
        MESSAGE("Un Qulbutoké est envoyé\npar " AI_TRAINER_NAME "!");
        MESSAGE("Fantominus! Go!");
        MESSAGE("Qulbutoké est retiré par\n" AI_TRAINER_NAME "!");
        MESSAGE("Un Girafarig est envoyé\npar " AI_TRAINER_NAME "!");
    }
}

DOUBLE_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (Doubles)")
{
    GIVEN {
        PLAYER(SPECIES_GASTLY);
        PLAYER(SPECIES_HAUNTER);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GIRAFARIG);
        OPPONENT(SPECIES_FARIGIRAF);
    } WHEN {
        TURN {
            SWITCH(opponentLeft, 3);
            SWITCH(opponentRight, 2);
        }
    } SCENE {
        MESSAGE("2\nveut se battre!{PAUSE 49}");
        MESSAGE("2 envoie\nun Qulbutoké et un Okéoké!");
        MESSAGE("Fantominus et\nSpectrum! Go!");
        MESSAGE("2 retire Qulbutoké!");
        MESSAGE("2 envoie\nun Farigiraf!");
        MESSAGE("2 retire Okéoké!");
        MESSAGE("2 envoie\nun Girafarig!");
    }
}

AI_DOUBLE_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (AI Doubles)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_SMART_TRAINER);
        PLAYER(SPECIES_GASTLY);
        PLAYER(SPECIES_HAUNTER);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE);  }
        OPPONENT(SPECIES_WYNAUT)    { Moves(MOVE_TACKLE);  }
        OPPONENT(SPECIES_GIRAFARIG) { Moves(MOVE_PSYCHIC); }
        OPPONENT(SPECIES_FARIGIRAF) { Moves(MOVE_PSYCHIC); }
    } WHEN {
        TURN {
            EXPECT_SWITCH(opponentLeft, 3);
            EXPECT_SWITCH(opponentRight, 2);
        }
    } SCENE {
        MESSAGE("Un combat est lancé\npar " AI_TRAINER_NAME "!\p");
        MESSAGE("Un Qulbutoké et un Okéoké\nsont envoyés par\l" AI_TRAINER_NAME "!");
        MESSAGE("Fantominus et\nSpectrum! Go!");
        MESSAGE("Qulbutoké est retiré par " AI_TRAINER_NAME "!");
        MESSAGE("Un Farigiraf est envoyé\npar " AI_TRAINER_NAME "!");
        MESSAGE("Okéoké est retiré par " AI_TRAINER_NAME "!");
        MESSAGE("Un Girafarig est envoyé\npar " AI_TRAINER_NAME "!");
    }
}

MULTI_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (Multi)")
{
    GIVEN {
        PLAYER(SPECIES_GASTLY);
        PARTNER(SPECIES_HAUNTER);
        PARTNER(SPECIES_GENGAR);
        OPPONENT_A(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_FARIGIRAF);
        OPPONENT_B(SPECIES_WYNAUT);
        OPPONENT_B(SPECIES_GIRAFARIG);
    } WHEN {
        TURN {
            SWITCH(playerRight, 1);
            SWITCH(opponentLeft, 1);
            SWITCH(opponentRight, 1);
        }
    } SCENE {
        MESSAGE("2 et 4\nveulent se battre!");
        MESSAGE("2 envoie\nun Qulbutoké!\p4 envoie\nun Okéoké!");
        MESSAGE("3 envoie\nSpectrum!\pFantominus! Go!");
        MESSAGE("2 retire Qulbutoké!");
        MESSAGE("2 envoie\nun Farigiraf!");
        MESSAGE("3 retire Spectrum!");
        MESSAGE("3 envoie\nEctoplasma!");
        MESSAGE("4 retire Okéoké!");
        MESSAGE("4 envoie\nun Girafarig!");
    }
}

AI_MULTI_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (AI Multi)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_SMART_TRAINER);
        PLAYER(SPECIES_GASTLY);
        PARTNER(SPECIES_HAUNTER);
        PARTNER(SPECIES_GENGAR);
        OPPONENT_A(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE);  }
        OPPONENT_A(SPECIES_FARIGIRAF) { Moves(MOVE_PSYCHIC); }
        OPPONENT_B(SPECIES_WYNAUT)    { Moves(MOVE_TACKLE);  }
        OPPONENT_B(SPECIES_GIRAFARIG) { Moves(MOVE_PSYCHIC); }
    } WHEN {
        TURN {
            SWITCH(playerRight, 1);
            EXPECT_SWITCH(opponentLeft, 1);
            EXPECT_SWITCH(opponentRight, 1);
        }
    } SCENE {
        MESSAGE("Un combat est lancé\npar " AI_TRAINER_NAME " et\l" AI_TRAINER_2_NAME "!\p");
        MESSAGE("Un Qulbutoké est envoyé\npar " AI_TRAINER_NAME "!\pUn Okéoké est envoyé\npar " AI_TRAINER_2_NAME "!");
        MESSAGE("Spectrum est envoyé par\n" AI_PARTNER_NAME "!\pFantominus! Go!");
        MESSAGE("Qulbutoké est retiré par " AI_TRAINER_NAME "!");
        MESSAGE("Un Farigiraf est envoyé\npar " AI_TRAINER_NAME "!");
        MESSAGE(AI_PARTNER_NAME " retire Spectrum!");
        MESSAGE("Ectoplasma est envoyé par " AI_PARTNER_NAME "!");
        MESSAGE("Okéoké est retiré par " AI_TRAINER_2_NAME "!");
        MESSAGE("Un Girafarig est envoyé\npar " AI_TRAINER_2_NAME "!");
    }
}

TWO_VS_ONE_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (2v1)")
{
    GIVEN {
        PLAYER(SPECIES_GASTLY);
        PARTNER(SPECIES_HAUNTER);
        PARTNER(SPECIES_GENGAR);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GIRAFARIG);
        OPPONENT(SPECIES_FARIGIRAF);
    } WHEN {
        TURN {
            SWITCH(opponentLeft, 3);
            SWITCH(playerRight, 1);
            SWITCH(opponentRight, 2);
        }
    } SCENE {
        MESSAGE("2\nveut se battre!");
        MESSAGE("2 envoie\nun Qulbutoké et un Okéoké!");
        MESSAGE("3 envoie\nSpectrum!\pFantominus! Go!");
        MESSAGE("2 retire Qulbutoké!");
        MESSAGE("2 envoie\nun Farigiraf!");
        MESSAGE("2 retire Okéoké!");
        MESSAGE("2 envoie\nun Girafarig!");
        MESSAGE("3 retire Spectrum!");
        MESSAGE("3 envoie\nEctoplasma!");
    }
}

AI_TWO_VS_ONE_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (AI 2v1)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_SMART_TRAINER);
        PLAYER(SPECIES_GASTLY);
        PARTNER(SPECIES_HAUNTER);
        PARTNER(SPECIES_GENGAR);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE);  }
        OPPONENT(SPECIES_WYNAUT)    { Moves(MOVE_TACKLE);  }
        OPPONENT(SPECIES_GIRAFARIG) { Moves(MOVE_PSYCHIC); }
        OPPONENT(SPECIES_FARIGIRAF) { Moves(MOVE_PSYCHIC); }
    } WHEN {
        TURN {
            EXPECT_SWITCH(opponentLeft, 3);
            SWITCH(playerRight, 1);
            EXPECT_SWITCH(opponentRight, 2);
        }
    } SCENE {
        MESSAGE("Un combat est lancé\npar " AI_TRAINER_NAME "!\p");
        MESSAGE("Un Qulbutoké et un Okéoké\nsont envoyés par\l" AI_TRAINER_NAME "!");
        MESSAGE("Spectrum est envoyé par\n" AI_PARTNER_NAME "!\pFantominus! Go!");
        MESSAGE("Qulbutoké est retiré par " AI_TRAINER_NAME "!");
        MESSAGE("Un Farigiraf est envoyé\npar " AI_TRAINER_NAME "!");
        MESSAGE("Okéoké est retiré par " AI_TRAINER_NAME "!");
        MESSAGE("Un Girafarig est envoyé\npar " AI_TRAINER_NAME "!");
        MESSAGE(AI_PARTNER_NAME " retire Spectrum!");
        MESSAGE("Ectoplasma est envoyé par " AI_PARTNER_NAME "!");
    }
}

ONE_VS_TWO_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (1v2)")
{
    GIVEN {
        PLAYER(SPECIES_GASTLY);
        PLAYER(SPECIES_HAUNTER);
        OPPONENT_A(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_FARIGIRAF);
        OPPONENT_B(SPECIES_WYNAUT);
        OPPONENT_B(SPECIES_GIRAFARIG);
    } WHEN {
        TURN {
            SWITCH(opponentLeft, 1);
            SWITCH(opponentRight, 1);
        }
    } SCENE {
        MESSAGE("2 et 4\nveulent se battre!");
        MESSAGE("2 envoie\nun Qulbutoké!\p4 envoie\nun Okéoké!");
        MESSAGE("Fantominus et\nSpectrum! Go!");
        MESSAGE("2 retire Qulbutoké!");
        MESSAGE("2 envoie\nun Farigiraf!");
        MESSAGE("4 retire Okéoké!");
        MESSAGE("4 envoie\nun Girafarig!");
    }
}

AI_ONE_VS_TWO_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (AI 1v2)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_SMART_TRAINER);
        PLAYER(SPECIES_GASTLY);
        PLAYER(SPECIES_HAUNTER);
        OPPONENT_A(SPECIES_WOBBUFFET)   { Moves(MOVE_TACKLE);  }
        OPPONENT_A(SPECIES_FARIGIRAF)   { Moves(MOVE_PSYCHIC); }
        OPPONENT_B(SPECIES_WYNAUT)      { Moves(MOVE_TACKLE);  }
        OPPONENT_B(SPECIES_GIRAFARIG)   { Moves(MOVE_PSYCHIC); }
    } WHEN {
        TURN { 
            EXPECT_SWITCH(opponentLeft, 1);
            EXPECT_SWITCH(opponentRight, 1);
        }
    } SCENE {
        MESSAGE("Un combat est lancé\npar " AI_TRAINER_NAME " et\l" AI_TRAINER_2_NAME "!\p");
        MESSAGE("Un Qulbutoké est envoyé\npar " AI_TRAINER_NAME "!\pUn Okéoké est envoyé\npar " AI_TRAINER_2_NAME "!");
        MESSAGE("Fantominus et\nSpectrum! Go!");
        MESSAGE("Qulbutoké est retiré par " AI_TRAINER_NAME "!");
        MESSAGE("Un Farigiraf est envoyé\npar " AI_TRAINER_NAME "!");
        MESSAGE("Okéoké est retiré par " AI_TRAINER_2_NAME "!");
        MESSAGE("Un Girafarig est envoyé\npar " AI_TRAINER_2_NAME "!");
    }
}

TO_DO_BATTLE_TEST("Battle Message: Switch-out message changes based on conditions")
/*{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        if (???)
            MESSAGE("Wynaut, that's enough! Come back!");
        else if (???)
            MESSAGE("Wynaut, come back!");
        else if (???)
            MESSAGE("Wynaut, OK! Come back!");
        else
            MESSAGE("Wynaut, good! Come back!");
    }
}*/
