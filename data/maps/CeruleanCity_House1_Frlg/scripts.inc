CeruleanCity_House1_Frlg_MapScripts::
	.byte 0

CeruleanCity_House1_EventScript_BadgeGuy::
	lock
	faceplayer
	msgbox CeruleanCity_House1_Text_BadgesHaveAmazingSecrets
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeAnotherBadge::
	message CeruleanCity_House1_Text_DescribeWhichBadge
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BADGES
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, CeruleanCity_House1_EventScript_DescribeBoulderBadge
	case 1, CeruleanCity_House1_EventScript_DescribeCascadeBadge
	case 2, CeruleanCity_House1_EventScript_DescribeThunderBadge
	case 3, CeruleanCity_House1_EventScript_DescribeRainbowBadge
	case 4, CeruleanCity_House1_EventScript_DescribeSoulBadge
	case 5, CeruleanCity_House1_EventScript_DescribeMarshBadge
	case 6, CeruleanCity_House1_EventScript_DescribeVolcanoBadge
	case 7, CeruleanCity_House1_EventScript_DescribeEarthBadge
	case 8, CeruleanCity_House1_EventScript_StopDescribingBadges
	case 127, CeruleanCity_House1_EventScript_StopDescribingBadges
	end

CeruleanCity_House1_EventScript_DescribeBoulderBadge::
	msgbox CeruleanCity_House1_Text_AttackStatFlash
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeCascadeBadge::
	msgbox CeruleanCity_House1_Text_ObeyLv30Cut
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeThunderBadge::
	msgbox CeruleanCity_House1_Text_SpeedStatFly
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeRainbowBadge::
	msgbox CeruleanCity_House1_Text_ObeyLv50Strength
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeSoulBadge::
	msgbox CeruleanCity_House1_Text_DefenseStatSurf
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeMarshBadge::
	msgbox CeruleanCity_House1_Text_ObeyLv70RockSmash
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeVolcanoBadge::
	msgbox CeruleanCity_House1_Text_SpStatsWaterfall
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeEarthBadge::
	msgbox CeruleanCity_House1_Text_AllMonsWillObeyYou
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_StopDescribingBadges::
	msgbox CeruleanCity_House1_Text_ComeVisitAnytime
	release
	end

CeruleanCity_House1_Text_BadgesHaveAmazingSecrets::
	.string "Les BADGES sont portés par des\n"
	.string "DRESSEURS de haut niveau.\p"
	.string "Mmm… Tu en as au moins un.\p"
	.string "Ces BADGES ont d'étranges pouvoirs!$"

CeruleanCity_House1_Text_DescribeWhichBadge::
	.string "Dis-moi…\p"
	.string "Lequel des 8 BADGES veux-tu que\n"
	.string "je décrive?$"

CeruleanCity_House1_Text_ComeVisitAnytime::
	.string "Reviens me voir quand tu veux.$"

CeruleanCity_House1_Text_AttackStatFlash::
	.string "L'ATTAQUE de tous tes POKéMON est\n"
	.string "augmentée.\p"
	.string "Il permet aussi d'utiliser la CS\n"
	.string "FLASH hors des combats.$"

CeruleanCity_House1_Text_ObeyLv30Cut::
	.string "Les POKéMON d'un niveau inférieur\n"
	.string "à 30 t'obéiront.\p"
	.string "Cela comprend aussi les POKéMON\n"
	.string "obtenus pendant un échange.\p"
	.string "S'ils sont d'un niveau supérieur,\n"
	.string "ils seront incontrôlables!\p"
	.string "Tu pourras aussi utiliser la CS\n"
	.string "COUPE hors des combats.$"

CeruleanCity_House1_Text_SpeedStatFly::
	.string "La VITESSE de tous tes POKéMON\n"
	.string "sera un peu augmentée.\p"
	.string "Tu pourras aussi utiliser la CS VOL\n"
	.string "hors des combats.$"

CeruleanCity_House1_Text_ObeyLv50Strength::
	.string "Les POKéMON jusqu'au niveau 50\n"
	.string "t'obéiront.\p"
	.string "Cela comprend aussi les POKéMON\n"
	.string "obtenus pendant un échange.\p"
	.string "Ceux d'un niveau supérieur seront\n"
	.string "incontrôlables!\p"
	.string "Tu pourras aussi utiliser la CS\n"
	.string "FORCE hors des combats.$"

CeruleanCity_House1_Text_DefenseStatSurf::
	.string "La DEFENSE de tous tes POKéMON\n"
	.string "sera augmentée.\p"
	.string "Tu pourras aussi utiliser la CS\n"
	.string "SURF hors des combats.$"

CeruleanCity_House1_Text_ObeyLv70RockSmash::
	.string "Les POKéMON de niveau 70 ou moins\n"
	.string "t'obéiront.\p"
	.string "Cela comprend aussi les POKéMON\n"
	.string "obtenus pendant un échange.\p"
	.string "S'ils sont d'un niveau supérieur, ils\n"
	.string "seront incontrôlables!\p"
	.string "Tu pourras aussi utiliser la CS\n"
	.string "ECLATE-ROC hors des combats.$"

CeruleanCity_House1_Text_SpStatsWaterfall::
	.string "Les stats des ATQ. SPE. et\n"
	.string "DEF. SPE. augmentent un peu. \p"
	.string "Tu pourras aussi utiliser\n"
	.string "CASCADE hors des combats.$"

CeruleanCity_House1_Text_AllMonsWillObeyYou::
	.string "Tous les POKéMON obéiront à tes\n"
	.string "ordres!$"

