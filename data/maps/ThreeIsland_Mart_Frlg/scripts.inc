ThreeIsland_Mart_Frlg_MapScripts::
	.byte 0

ThreeIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart ThreeIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
ThreeIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

ThreeIsland_Mart_EventScript_Picnicker::
	msgbox ThreeIsland_Mart_Text_TrueThatCeldadonDeptStoreBigger, MSGBOX_NPC
	end

ThreeIsland_Mart_EventScript_BugCatcher::
	msgbox ThreeIsland_Mart_Text_PeopleHealWithBerriesFromForest, MSGBOX_NPC
	end

ThreeIsland_Mart_EventScript_Youngster::
	msgbox ThreeIsland_Mart_Text_BikersWereAboutToTrashMart, MSGBOX_NPC
	end

ThreeIsland_Mart_Text_TrueThatCeldadonDeptStoreBigger::
	.string "C'est vrai?\p"
	.string "Le CENTRE COMMERCIAL de\n"
	.string "CELADOPOLE est bien\p"
	.string "plus grand que cette boutique?$"

ThreeIsland_Mart_Text_PeopleHealWithBerriesFromForest::
	.string "J'achète parfois des\n"
	.string "médicaments ici.\p"
	.string "Mais beaucoup de gens utilisent\n"
	.string "aussi les BAIES des BOIS BAIES.\p"
	.string "Après tout, les BAIES sont\n"
	.string "gratuites et poussent en quantité.$"

ThreeIsland_Mart_Text_BikersWereAboutToTrashMart::
	.string "Ces MOTARDS allaient détruire\n"
	.string "la BOUTIQUE POKéMON.\p"
	.string "J'suis bien content qu'ils soient\n"
	.string "enfin partis!$"

