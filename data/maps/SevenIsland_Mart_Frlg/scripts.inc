SevenIsland_Mart_Frlg_MapScripts::
	.byte 0

SevenIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SevenIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
SevenIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

SevenIsland_Mart_EventScript_Lass::
	msgbox SevenIsland_Mart_Text_MonHavePersonalitiesOfTheirOwn, MSGBOX_NPC
	end

SevenIsland_Mart_EventScript_Hiker::
	msgbox SevenIsland_Mart_Text_PreparationsCompleteForRuins, MSGBOX_NPC
	end

SevenIsland_Mart_EventScript_Fisher::
	msgbox SevenIsland_Mart_Text_NeedToFishOnSevenIsland, MSGBOX_NPC
	end

SevenIsland_Mart_Text_MonHavePersonalitiesOfTheirOwn::
	.string "Les POKéMON ont leur propre\n"
	.string "personnalité, comme les gens.\p"
	.string "Mon PIKACHU est PRESSE. C'est\n"
	.string "un POKéMON très rapide.$"

SevenIsland_Mart_Text_PreparationsCompleteForRuins::
	.string "OK, je suis enfin prêt pour partir\n"
	.string "explorer les RUINES.$"

SevenIsland_Mart_Text_NeedToFishOnSevenIsland::
	.string "Il ne me reste plus qu'à aller\n"
	.string "pêcher sur l'ILE 7.\p"
	.string "Comme ça, je les aurai toutes\n"
	.string "explorées au moins une fois.\p"
	.string "Mais je devrais quand même\n"
	.string "mettre des POKé BALLS de côté.$"

