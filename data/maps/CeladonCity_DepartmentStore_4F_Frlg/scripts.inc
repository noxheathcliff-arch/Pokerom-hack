CeladonCity_DepartmentStore_4F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_4F_EventScript_Man::
	msgbox CeladonCity_DepartmentStore_4F_Text_GettingPokeDollAsPresent, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox CeladonCity_DepartmentStore_4F_Text_CanRunAwayWithPokeDoll, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_4F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_4F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_4F_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_4F_Items::
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_RETRO_MAIL
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_4F_Text_GettingPokeDollAsPresent::
	.string "Je cherche un cadeau pour ma\n"
	.string "copine.\p"
	.string "Une belle POKéPOUPEE devrait\n"
	.string "faire l'affaire!$"

CeladonCity_DepartmentStore_4F_Text_CanRunAwayWithPokeDoll::
	.string "Ecoute donc…\p"
	.string "Tu peux fuir face aux POKéMON\n"
	.string "sauvages en les occupant avec une\l"
	.string "POKéPOUPEE!$"

CeladonCity_DepartmentStore_4F_Text_FloorSign::
	.string "Un cadeau… L'amour… La vie!\n"
	.string "3ème: CADEAUX\p"
	.string "Vive les évolutions!\n"
	.string "Les PIERRES sont en vente!$"
