PewterCity_Mart_Frlg_MapScripts::
	.byte 0

PewterCity_Mart_EventScript_Youngster::
	msgbox PewterCity_Mart_Text_BoughtWeirdFishFromShadyGuy, MSGBOX_NPC
	end

PewterCity_Mart_EventScript_Boy::
	msgbox PewterCity_Mart_Text_GoodThingsIfRaiseMonsDiligently, MSGBOX_NPC
	end

PewterCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PewterCity_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
PewterCity_Mart_Items::
	.2byte ITEM_POKE_BALL
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

PewterCity_Mart_Text_BoughtWeirdFishFromShadyGuy::
	.string "Un vieil homme m'a vendu cet\n"
	.string "étrange poisson POKéMON!\p"
	.string "Il est super nul et il m'a coûté\n"
	.string "500¥!$"

PewterCity_Mart_Text_GoodThingsIfRaiseMonsDiligently::
	.string "Si tu élèves bien tes POKéMON,\n"
	.string "même les plus faibles, il se\p"
	.string "passera rien que des bonnes\n"
	.string "choses!$"

