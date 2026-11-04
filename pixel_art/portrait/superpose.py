"""Rendu seulement : pose une etape (png) sur le calque ref assombri, pour COMPARER au calque.
usage: python3 superpose.py etape.png out.png [opacite_ref 0-1] [zoom]"""
import sys
from PIL import Image
e=Image.open(sys.argv[1]).convert('RGBA'); a=float(sys.argv[3]) if len(sys.argv)>3 else .45; z=int(sys.argv[4]) if len(sys.argv)>4 else 3
r=Image.open('ref_256x320.png').convert('RGBA'); bg=Image.new('RGBA',r.size,(20,20,24,255))
base=Image.blend(bg,r,a); base.alpha_composite(e)
base.resize((base.width*z,base.height*z),Image.NEAREST).save(sys.argv[2])
