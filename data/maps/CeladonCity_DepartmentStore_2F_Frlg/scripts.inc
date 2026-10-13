CeladonCity_DepartmentStore_2F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_2F_EventScript_UnusedNPC::
	msgbox CeladonCity_DepartmentStore_2F_Text_SuperRepelMorePowerfulRepel, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_2F_EventScript_Lass::
	msgbox CeladonCity_DepartmentStore_2F_Text_BuyReviveForLongOutings, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_2F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_2F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_2F_EventScript_ClerkItems::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_2F_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_2F_Items::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_2F_EventScript_ClerkTMs::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_2F_TMs
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_2F_TMs::
	.2byte ITEM_TM05
	.2byte ITEM_TM15
	.2byte ITEM_TM28
	.2byte ITEM_TM31
	.2byte ITEM_TM43
	.2byte ITEM_TM45
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_2F_Text_SuperRepelMorePowerfulRepel::
	.string "Le SUPEREPOUSSE tient les\n"
	.string "POKéMON faibles à l'écart…\p"
	.string "C'est un REPOUSSE plus puissant!$"

CeladonCity_DepartmentStore_2F_Text_BuyReviveForLongOutings::
	.string "Equipe-toi de RAPPELS avant de\n"
	.string "partir à l'aventure.$"

CeladonCity_DepartmentStore_2F_Text_FloorSign::
	.string "Les objets de premier choix!\p"
	.string "1er: MARCHE DES DRESSEURS$"

CeladonCity_DepartmentStore_2F_Text_LanceComesToBuyCapes::
	.string "PETER vient souvent ici pour\n"
	.string "acheter des capes.\p"
	.string "Je me demande combien de capes\n"
	.string "identiques il peut avoir chez lui.$"
