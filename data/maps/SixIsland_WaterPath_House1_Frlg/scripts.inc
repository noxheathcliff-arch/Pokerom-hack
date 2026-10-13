SixIsland_WaterPath_House1_Frlg_MapScripts::
	.byte 0

SixIsland_WaterPath_House1_EventScript_Beauty::
	lock
	faceplayer
	setvar VAR_0x8004, SPECIES_HERACROSS
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, FALSE, SixIsland_WaterPath_House1_EventScript_NoHeracrossInParty
	special GetHeracrossSizeRecordInfo
	msgbox SixIsland_WaterPath_House1_Text_MayIMeasureHeracross
	special ChoosePartyMon
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_ge VAR_RESULT, PARTY_SIZE, SixIsland_WaterPath_House1_EventScript_DontShowMon
	special CompareHeracrossSize
	goto_if_eq VAR_RESULT, 1, SixIsland_WaterPath_House1_EventScript_ShownNonHeracross
	goto_if_eq VAR_RESULT, 2, SixIsland_WaterPath_House1_EventScript_ShownSmallHeracross
	goto_if_eq VAR_RESULT, 3, SixIsland_WaterPath_House1_EventScript_ShownBigHeracross
	goto_if_eq VAR_RESULT, 4, SixIsland_WaterPath_House1_EventScript_ShownTiedHeracross
	release
	end

SixIsland_WaterPath_House1_EventScript_NoHeracrossInParty::
	msgbox SixIsland_WaterPath_House1_Text_LoveItNeedItHeracross
	release
	end

SixIsland_WaterPath_House1_EventScript_DontShowMon::
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownNonHeracross::
	msgbox SixIsland_WaterPath_House1_Text_ThisWontDo
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownSmallHeracross::
	goto_if_unset FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, SixIsland_WaterPath_House1_EventScript_ShownBigHeracross
	msgbox SixIsland_WaterPath_House1_Text_ItsXSizeYSizeWasBiggest
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownTiedHeracross::
	goto_if_unset FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, SixIsland_WaterPath_House1_EventScript_ShownBigHeracross
	msgbox SixIsland_WaterPath_House1_Text_ItsXSizeSameAsBefore
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownBigHeracross::
	setflag FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1
	msgbox SixIsland_WaterPath_House1_Text_ItsXSizeDeserveReward
	giveitem ITEM_NEST_BALL
	goto_if_eq VAR_RESULT, FALSE, SixIsland_WaterPath_House1_EventScript_NoRoomForNestBall
	msgbox SixIsland_WaterPath_House1_Text_WantToSeeBiggerOne
	release
	end

SixIsland_WaterPath_House1_EventScript_NoRoomForNestBall::
	msgbox SixIsland_WaterPath_House1_Text_YourBagIsFull
	release
	end

SixIsland_WaterPath_House1_EventScript_SizeRecord::
	lockall
	goto_if_set FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, SixIsland_WaterPath_House1_EventScript_SizeRecordNonEmpty
	msgbox SixIsland_WaterPath_House1_Text_BlankChartOfSomeSort
	releaseall
	end

SixIsland_WaterPath_House1_EventScript_SizeRecordNonEmpty::
	special GetHeracrossSizeRecordInfo
	msgbox SixIsland_WaterPath_House1_Text_BiggestHeracrossIsXSize
	releaseall
	end

SixIsland_WaterPath_House1_Text_LoveItNeedItHeracross::
	.string "SCARI, SCARHINO!\p"
	.string "Enorme et brillant, c'est le gros\n"
	.string "SCARHINO!\p"
	.string "Je l'adore, j'en veux un!\n"
	.string "SCARHINOOO!$"

SixIsland_WaterPath_House1_Text_MayIMeasureHeracross::
	.string "Waaah!\n"
	.string "C'est un SCARHINO!\p"
	.string "Dis, tu me laisses le mesurer\n"
	.string "s'te plaît?$"

SixIsland_WaterPath_House1_Text_ItsXSizeDeserveReward::
	.string "Waaaah, il mesure {STR_VAR_2}!\p"
	.string "J'avais jamais rien vu d'aussi\n"
	.string "gros! Tu mérites une récompense!$"

SixIsland_WaterPath_House1_Text_WantToSeeBiggerOne::
	.string "Je veux en voir un beaucoup plus\n"
	.string "gros que celui-là.\p"
	.string "Oh, comme je les adore!$"

SixIsland_WaterPath_House1_Text_ItsXSizeSameAsBefore::
	.string "Hein? Celui-là mesure {STR_VAR_2}…\n"
	.string "Oh non, c'est comme celui d'avant.$"

SixIsland_WaterPath_House1_Text_ItsXSizeYSizeWasBiggest::
	.string "Hein? Seulement {STR_VAR_2}…\n"
	.string "Celui d'avant était bien plus gros.\p"
	.string "Il faisait {STR_VAR_3}, le plus gros que\n"
	.string "tu m'as ramené.$"

SixIsland_WaterPath_House1_Text_ThisWontDo::
	.string "Ah, non! Ça va pas du tout!\p"
	.string "SCARHINO est bien plus\n"
	.string "impressionnant!\p"
	.string "Il est cool et il a une super\n"
	.string "corne!$"

SixIsland_WaterPath_House1_Text_YourBagIsFull::
	.string "Ton SAC est plein. La récompense\n"
	.string "ne rentrera pas!$"

SixIsland_WaterPath_House1_Text_BiggestHeracrossIsXSize::
	.string "Le plus gros SCARHINO que j'ai\n"
	.string "vu mesurait: {STR_VAR_3}!$"

SixIsland_WaterPath_House1_Text_BlankChartOfSomeSort::
	.string "C'est une sorte de classement.\p"
	.string "Il y a de la place pour mettre\n"
	.string "de nouveaux noms.$"

