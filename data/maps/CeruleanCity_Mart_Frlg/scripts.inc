CeruleanCity_Mart_Frlg_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Youngster::
	msgbox CeruleanCity_Mart_Text_RepelWorksOnWeakMons, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_Woman::
	msgbox CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeruleanCity_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeruleanCity_Mart_Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

CeruleanCity_Mart_Text_RepelWorksOnWeakMons::
	.string "Le REPOUSSE tient les POKéMON\n"
	.string "sauvages à l'écart.\p"
	.string "Mets tes POKéMON les plus costauds\n"
	.string "en premier pour une plus grande\p"
	.string "efficacité! Si ton premier POKéMON\n"
	.string "est fort, l'effet est boosté.$"

CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy::
	.string "Tu connais les SUPER BONBONS? On\n"
	.string "ne les trouve pas à la vente.\p"
	.string "Quand un POKéMON en mange un, il\n"
	.string "gagne un niveau!$"

