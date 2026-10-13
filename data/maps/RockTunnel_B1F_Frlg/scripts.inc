RockTunnel_B1F_Frlg_MapScripts::
	.byte 0

RockTunnel_B1F_EventScript_Sofia::
	trainerbattle_single TRAINER_PICNICKER_SOFIA, RockTunnel_B1F_Text_SofiaIntro, RockTunnel_B1F_Text_SofiaDefeat
	msgbox RockTunnel_B1F_Text_SofiaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Martha::
	trainerbattle_single TRAINER_PICNICKER_MARTHA, RockTunnel_B1F_Text_MarthaIntro, RockTunnel_B1F_Text_MarthaDefeat
	msgbox RockTunnel_B1F_Text_MarthaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Dudley::
	trainerbattle_single TRAINER_HIKER_DUDLEY, RockTunnel_B1F_Text_DudleyIntro, RockTunnel_B1F_Text_DudleyDefeat
	msgbox RockTunnel_B1F_Text_DudleyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Allen::
	trainerbattle_single TRAINER_HIKER_ALLEN, RockTunnel_B1F_Text_AllenIntro, RockTunnel_B1F_Text_AllenDefeat
	msgbox RockTunnel_B1F_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Eric::
	trainerbattle_single TRAINER_HIKER_ERIC, RockTunnel_B1F_Text_EricIntro, RockTunnel_B1F_Text_EricDefeat
	msgbox RockTunnel_B1F_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Cooper::
	trainerbattle_single TRAINER_POKEMANIAC_COOPER, RockTunnel_B1F_Text_CooperIntro, RockTunnel_B1F_Text_CooperDefeat
	msgbox RockTunnel_B1F_Text_CooperPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Steve::
	trainerbattle_single TRAINER_POKEMANIAC_STEVE, RockTunnel_B1F_Text_SteveIntro, RockTunnel_B1F_Text_SteveDefeat
	msgbox RockTunnel_B1F_Text_StevePostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Winston::
	trainerbattle_single TRAINER_POKEMANIAC_WINSTON, RockTunnel_B1F_Text_WinstonIntro, RockTunnel_B1F_Text_WinstonDefeat
	msgbox RockTunnel_B1F_Text_WinstonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_SofiaIntro::
	.string "Tu sais comment éviter de te\n"
	.string "perdre?\p"
	.string "Il suffit de laisser des petites\n"
	.string "brindilles derrière toi.$"

RockTunnel_B1F_Text_SofiaDefeat::
	.string "Oh!\n"
	.string "J'ai fait de mon mieux!$"

RockTunnel_B1F_Text_SofiaPostBattle::
	.string "J'veux rentrer à ma maison!$"

RockTunnel_B1F_Text_DudleyIntro::
	.string "Hahaha!\n"
	.string "J'suis trop fort!$"

RockTunnel_B1F_Text_DudleyDefeat::
	.string "Oups!\n"
	.string "Niveau muscles: zéro!$"

RockTunnel_B1F_Text_DudleyPostBattle::
	.string "J'aime pas penser alors je cogne.$"

RockTunnel_B1F_Text_CooperIntro::
	.string "Tu as un POKéDEX?\n"
	.string "J'en veux un aussi!$"

RockTunnel_B1F_Text_CooperDefeat::
	.string "Zut!\n"
	.string "J'suis jaloux!$"

RockTunnel_B1F_Text_CooperPostBattle::
	.string "Tu me donneras ton POKéDEX\n"
	.string "plus tard?$"

RockTunnel_B1F_Text_SteveIntro::
	.string "Connais-tu les DRESSEURS costumés?$"

RockTunnel_B1F_Text_SteveDefeat::
	.string "Ben…\n"
	.string "C'est ça.$"

RockTunnel_B1F_Text_StevePostBattle::
	.string "Les DRESSEURS costumés se\n"
	.string "déguisent en POKéMON pour s'amuser.\p"
	.string "Ils adorent le costume de MELOFEE.$"

RockTunnel_B1F_Text_AllenIntro::
	.string "Mes POKéMON vont te faire pleurer!$"

RockTunnel_B1F_Text_AllenDefeat::
	.string "Ah!\n"
	.string "Je pleure.$"

RockTunnel_B1F_Text_AllenPostBattle::
	.string "Les montagnes regorgent de\n"
	.string "POKéMON du type ROCHE.$"

RockTunnel_B1F_Text_MarthaIntro::
	.string "J'suis paumée mais…\n"
	.string "A l'attaque!$"

RockTunnel_B1F_Text_MarthaDefeat::
	.string "Oh!\n"
	.string "Perdu!$"

RockTunnel_B1F_Text_MarthaPostBattle::
	.string "J'aime les petits POKéMON, les gros\n"
	.string "me font peur!$"

RockTunnel_B1F_Text_EricIntro::
	.string "Donne-toi à fond!$"

RockTunnel_B1F_Text_EricDefeat::
	.string "Mince!\n"
	.string "J'me suis fait détruire!$"

RockTunnel_B1F_Text_EricPostBattle::
	.string "Je vais encore m'entraîner!$"

RockTunnel_B1F_Text_WinstonIntro::
	.string "Je dessine des POKéMON quand\n"
	.string "j'suis tout seul.\l"
	.string "…\l"
	.string "Cool, non?$"

RockTunnel_B1F_Text_WinstonDefeat::
	.string "Fouii!\n"
	.string "Je suis crevé!$"

RockTunnel_B1F_Text_WinstonPostBattle::
	.string "J'suis un artiste, pas un violent.$"

