ViridianForest_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	.byte 0

ViridianForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
	end

ViridianForest_EventScript_Youngster::
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
	end

ViridianForest_EventScript_Boy::
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
	end

ViridianForest_EventScript_TrainerTips1::
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips2::
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips3::
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips4::
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips5::
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
	end

ViridianForest_EventScript_ExitSign::
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
	end

ViridianForest_EventScript_Rick::
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Doug::
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Sammy::
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Anthony::
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Charlie::
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_FriendsItchingToBattle::
	.string "Je suis venu avec des amis pour\n"
	.string "attraper des POKéMON INSECTE!\p"
	.string "Ils sont tous ici pour faire des\n"
	.string "combats de POKéMON!$"

ViridianForest_Text_RickIntro::
	.string "Hé! Mais tu as des POKéMON!\n"
	.string "Yah! A l'attaque!$"

ViridianForest_Text_RickDefeat::
	.string "NON!\n"
	.string "CHENIPAN n'est pas assez fort!$"

ViridianForest_Text_RickPostBattle::
	.string "Chut!\n"
	.string "Tu fais peur aux insectes…$"

ViridianForest_Text_DougIntro::
	.string "Haha!\n"
	.string "Un DRESSEUR de POKéMON,\l"
	.string "un vrai, ne se débine jamais!!!$"

ViridianForest_Text_DougDefeat::
	.string "Oups!\n"
	.string "J'ai plus de POKéMON, moi!$"

ViridianForest_Text_DougPostBattle::
	.string "Ça craint complètement.\n"
	.string "J'vais en choper des plus balèzes!$"

ViridianForest_Text_SammyIntro::
	.string "Hop, hop! Minute!\n"
	.string "On est pas pressés!$"

ViridianForest_Text_SammyDefeat::
	.string "Houlà!\n"
	.string "J'abandonne! T'es trop fort!$"

ViridianForest_Text_SammyPostBattle::
	.string "Tu trouveras peut-être des objets\n"
	.string "par terre!\p"
	.string "Je cherche les objets que j'ai\n"
	.string "laissés tomber…$"

ViridianForest_Text_AnthonyIntro::
	.string "Je suis peut-être petit, mais faut\n"
	.string "pas me sous-estimer.$"

ViridianForest_Text_AnthonyDefeat::
	.string "Oh bah non.\n"
	.string "Tout va de travers.$"

ViridianForest_Text_AnthonyPostBattle::
	.string "J'oublierai pas cette défaite.$"

ViridianForest_Text_CharlieIntro::
	.string "Tu sais que les POKéMON\n"
	.string "peuvent évoluer?$"

ViridianForest_Text_CharlieDefeat::
	.string "Oh!\n"
	.string "Perdu!$"

ViridianForest_Text_CharliePostBattle::
	.string "Les POKéMON INSECTE évoluent\n"
	.string "vite. Je les adore!$"

ViridianForest_Text_RanOutOfPokeBalls::
	.string "J'suis à court de POKé BALL! Je ne\n"
	.string "peux plus attraper de POKéMON!\p"
	.string "Il faut toujours en avoir un max!$"

ViridianForest_Text_AvoidGrassyAreasWhenWeak::
	.string "ASTUCE\p"
	.string "Pour éviter les combats, ne\n"
	.string "marchez pas dans les hautes\l"
	.string "herbes!$"

ViridianForest_Text_UseAntidoteForPoison::
	.string "L'ANTIDOTE vendu dans les\n"
	.string "BOUTIQUES POKéMON guérit du\l"
	.string "poison.$"

ViridianForest_Text_ContactOakViaPCToRatePokedex::
	.string "ASTUCE\p"
	.string "Pour évaluer votre POKéDEX,\n"
	.string "appelez le PROF. CHEN via un PC!$"

ViridianForest_Text_CantCatchOwnedMons::
	.string "ASTUCE\p"
	.string "Interdiction de capturer les\n"
	.string "POKéMON d'un autre DRESSEUR!\p"
	.string "La capture se fait à l'état\n"
	.string "sauvage!$"

ViridianForest_Text_WeakenMonsBeforeCapture::
	.string "ASTUCE\p"
	.string "Un POKéMON blessé se capture\n"
	.string "plus facilement!\p"
	.string "En pleine forme, il peut s'enfuir!$"

ViridianForest_Text_LeavingViridianForest::
	.string "VOUS QUITTEZ LA FORET DE JADE.\n"
	.string "VOUS ALLEZ VERS ARGENTA.$"

