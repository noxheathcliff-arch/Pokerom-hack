#!/bin/sh
# Étape 3 — contour et selout (séquence ; chaque choix de lettre/zone est le mien)
set -e
P=../cascade
# 1. contour extérieur vin sur tout ce qui touche le vide
python3 bord.py v01_construction.txt v03_contour.txt O c4i .
# 2. cercle de séparation de l'anneau + fentes des plumes
python3 trace.py v03_contour.txt v03_contour.txt c03_lignes.txt
# 3. chaton intérieur : l'or qui touche le verre ou le liquide devient a
python3 bord.py v03_contour.txt v03_contour.txt a c q3
# 4. sertissure du rubis
python3 bord.py v03_contour.txt v03_contour.txt a c 4
# 5. fer contre or : arête h
python3 bord.py v03_contour.txt v03_contour.txt h i ca
python3 $P/px.py v03_contour.txt 8 palette.json
