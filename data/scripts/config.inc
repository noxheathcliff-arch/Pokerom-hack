Debug_FlagsAndVarNotSetBattleConfigMessage::
	lockall
	message Debug_FlagsAndVarNotSetBattleConfigMessage_Text
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_FlagsAndVarNotSetBattleConfigMessage_Text:
	.string "Fonctionnalité inutilisable! Définissez\n"
	.string "un flag valide et une variable valide\l"
	.string "dans: 'include/config/battle.h'!$"
