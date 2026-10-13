LavenderTown_Mart_Frlg_MapScripts::
	.byte 0

LavenderTown_Mart_EventScript_BaldingMan::
	msgbox LavenderTown_Mart_Text_SearchingForStatRaiseItems, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Rocker::
	msgbox LavenderTown_Mart_Text_DidYouBuyRevives, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Youngster::
	msgbox LavenderTown_Mart_Text_TrainerDuosCanChallengeYou, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavenderTown_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
LavenderTown_Mart_Items::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE
	release
	end

LavenderTown_Mart_Text_SearchingForStatRaiseItems::
	.string "Je cherche des objets permettant\n"
	.string "d'augmenter la puissance d'un\l"
	.string "POKéMON en combat.\p"
	.string "ATTAQUE +, DEFENSE +, SPECIAL +\n"
	.string "et VITESSE +, c'est ça qu'je\l"
	.string "cherche.\p"
	.string "Sais-tu où je peux en trouver?$"

LavenderTown_Mart_Text_DidYouBuyRevives::
	.string "Connais-tu le RAPPEL? Il permet de\n"
	.string "réanimer un POKéMON KO!$"

LavenderTown_Mart_Text_TrainerDuosCanChallengeYou::
	.string "Des DRESSEURS pourraient te\n"
	.string "défier avec deux POKéMON à la\p"
	.string "fois. Si ça arrive, tu devras aussi\n"
	.string "utiliser deux POKéMON.$"

LavenderTown_Mart_Text_SoldNuggetFromMountainsFor5000::
	.string "この　あいだ　やまおくで\n"
	.string "きんのたまを　ひろい　ましてね！\p"
	.string "つかえない　しなもの　ですが\n"
	.string "うったら　なんと　5000¥でした$"
