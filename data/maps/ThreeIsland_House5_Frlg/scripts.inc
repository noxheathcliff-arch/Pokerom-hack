ThreeIsland_House5_Frlg_MapScripts::
	.byte 0

ThreeIsland_House5_EventScript_LittleGirl::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_LOSTELLE, ThreeIsland_House5_EventScript_LittleGirlLostelleFound
	msgbox ThreeIsland_House5_Text_ImNotLostelle
	release
	end

ThreeIsland_House5_EventScript_LittleGirlLostelleFound::
	msgbox ThreeIsland_House5_Text_IllGoPlayWithLostelle
	release
	end

ThreeIsland_House5_Text_ImNotLostelle::
	.string "Moi?\n"
	.string "Bah non, j'm'appelle pas LOSTELLE!\p"
	.string "Elle est peut-être aux BOIS BAIES.\p"
	.string "Elle y ramasse souvent des BAIES\n"
	.string "pour faire à manger.$"

ThreeIsland_House5_Text_IllGoPlayWithLostelle::
	.string "J'irais bien jouer avec LOSTELLE\n"
	.string "aujourd'hui.$"

