BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "Hé, hé, hé!\n"
	.string "Je sais ce que les POKéMON pensent!\p"
	.string "S'il te plaît!\n"
	.string "Je peux voir tes POKéMON?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "Bouh!\n"
	.string "C'est pas sympa!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime se battre!\n"
	.string "Même couvert de bobos, il se battra!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime se battre!\n"
	.string "Mais s'il se retrouve couvert de bobos,\l"
	.string "il se met à pleurnicher!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime se battre!\n"
	.string "Mais s'il se retrouve couvert de bobos,\l"
	.string "il deviendra sournois!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il prend soin de lui!\n"
	.string "Mais s'il est couvert de bobos, il\l"
	.string "ripostera!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il prend soin de lui!\n"
	.string "Il ne pense qu'à lui, qu'il soit ou\l"
	.string "non couvert de bobos!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il prend soin de lui!\n"
	.string "Mais s'il se retrouve couvert de bobos,\l"
	.string "il deviendra sournois!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime être sournois!\n"
	.string "Mais s'il est couvert de bobos, il\l"
	.string "ripostera!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime être sournois!\n"
	.string "Mais s'il se retrouve couvert de bobos,\l"
	.string "il se met à pleurnicher!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime être sournois!\n"
	.string "Il aime être sournois même quand il\l"
	.string "est couvert de bobos!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "C'est n'importe quoi! Comment tu veux\n"
	.string "que je parle avec un OEUF!?!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "Comme c'est mignon!\n"
	.string "Cette jeune fille prétend qu'elle peut\l"
	.string "comprendre les POKéMON!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "J'ai l'impression que cette fille dit\n"
	.string "quelque chose de profond.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "J'ai une info!\p"
	.string "Cette fille joue souvent dans le\n"
	.string "bâtiment rouge!$"

