ThreeIsland_House1_Frlg_MapScripts::
	.byte 0

ThreeIsland_House1_EventScript_Lostelle::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	msgbox ThreeIsland_House1_Text_YoureAlwaysSoCool
	release
	end

ThreeIsland_House1_EventScript_DisplayCase::
	msgbox ThreeIsland_House1_Text_RareRocksGemsDisplayed, MSGBOX_SIGN
	end

ThreeIsland_House1_Text_YoureAlwaysSoCool::
	.string "LOSTELLE: Coucou {PLAYER}!\n"
	.string "Ça marche pour toi?\p"
	.string "Un de ces jours, je t'inviterai\n"
	.string "à manger à la maison.$"

ThreeIsland_House1_Text_RareRocksGemsDisplayed::
	.string "Des pierres rares sont mises\n"
	.string "en évidence.$"

