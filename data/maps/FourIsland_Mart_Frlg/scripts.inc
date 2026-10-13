FourIsland_Mart_Frlg_MapScripts::
	.byte 0

FourIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FourIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
FourIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

FourIsland_Mart_EventScript_Camper::
	msgbox FourIsland_Mart_Text_IcefallCaveIsFrigid, MSGBOX_NPC
	end

FourIsland_Mart_Text_LoreleiGrewUpOnThisIsland::
	.string "Un DRESSEUR très fort et très\n"
	.string "connu a grandi sur cette île.\p"
	.string "Je suis sûr que même toi tu\n"
	.string "connais son nom.\p"
	.string "C'est OLGA, du CONSEIL 4.\p"
	.string "C'est moi qui lui ai tout appris sur\n"
	.string "les POKéMON il y a des années.$"

FourIsland_Mart_Text_IcefallCaveIsFrigid::
	.string "Les ILES SEVII se trouvent dans\n"
	.string "une région plutôt chaude.\p"
	.string "Mais il y a une exception que tu\n"
	.string "dois connaître.\p"
	.string "La GROTTE DE GLACE est ainsi\n"
	.string "à cause du POKéMON qui y vit.$"

