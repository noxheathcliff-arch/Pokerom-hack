# Étape 5 — terminateur et ombres
python3 trace.py v03_contour.txt v05_ombres.txt c05_isole.txt
# plumes et couronne : arête haute éclairée (d), arête basse dans l'ombre (b)
python3 bord.py v05_ombres.txt v05_ombres.txt d c Oa h 0 0 21 31
python3 bord.py v05_ombres.txt v05_ombres.txt b c Oa b 0 0 21 31
python3 bord.py v05_ombres.txt v05_ombres.txt d c Oa hg 22 0 42 10
python3 bord.py v05_ombres.txt v05_ombres.txt b c Oa d 22 0 42 10
python3 bord.py v05_ombres.txt v05_ombres.txt b c Oa bd 42 0 63 31
python3 trace.py v05_ombres.txt v05_ombres.txt c05_ombres.txt
# verre : épaisseur éclairée sur le bord haut-gauche
python3 bord.py v05_ombres.txt v05_ombres.txt r q a hg 10 8 32 25
# plaque : biseau haut-gauche clair (j), bas-droite sombre (h)
python3 bord.py v05_ombres.txt v05_ombres.txt j i Oh hg 10 48 54 60
python3 bord.py v05_ombres.txt v05_ombres.txt h i O bd 10 48 54 60
# ménisque concave, éteint vers la droite
python3 trace.py v05_ombres.txt v05_ombres.txt c05b_menisque.txt
python3 ../cascade/px.py v05_ombres.txt 8 palette.json
