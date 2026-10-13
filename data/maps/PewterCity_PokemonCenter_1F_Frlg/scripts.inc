PewterCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PewterCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_PEWTER_CITY
	end

PewterCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

PewterCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox PewterCity_PokemonCenter_1F_Text_TeamRocketMtMoonImOnPhone, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_EventScript_Jigglypuff::
	lock
	faceplayer
	fadeoutbgm 0
	playbgm MUS_RG_JIGGLYPUFF, 0
	message PewterCity_PokemonCenter_1F_Text_Jigglypuff
	waitmessage
	delay 455
	playbgm MUS_POKE_CENTER, 1
	release
	end

PewterCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PewterCity_PokemonCenter_1F_Text_WhenJiggylypuffSingsMonsGetDrowsy, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_EventScript_GBAKid1::
	lock
	msgbox PewterCity_PokemonCenter_1F_Text_TradingMyClefairyForPikachu
	release
	end

PewterCity_PokemonCenter_1F_EventScript_GBAKid2::
	msgbox PewterCity_PokemonCenter_1F_Text_TradingPikachuWithKid, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_Text_TeamRocketMtMoonImOnPhone::
	.string "Quoi!?\p"
	.string "La TEAM ROCKET est au MONT\n"
	.string "SELENITE!\p"
	.string "Damnation!$"

PewterCity_PokemonCenter_1F_Text_Jigglypuff::
	.string "RONDOUDOU: Dou! Doudouuuu!$"

PewterCity_PokemonCenter_1F_Text_WhenJiggylypuffSingsMonsGetDrowsy::
	.string "(Bâille)\p"
	.string "Lorsque RONDOUDOU chante, tous les\n"
	.string "POKéMON piquent du nez…\p"
	.string "… Moi aussi…\n"
	.string "(Ronfl)…$"

PewterCity_PokemonCenter_1F_Text_TradingMyClefairyForPikachu::
	.string "Je veux vraiment un PIKACHU.\n"
	.string "Ça te dit un MELOFEE en échange?$"

PewterCity_PokemonCenter_1F_Text_TradingPikachuWithKid::
	.string "J'échange des POKéMON avec\n"
	.string "ce gamin.\p"
	.string "Comme j'avais deux PIKACHU,\n"
	.string "j'en ai échangé un!$"

