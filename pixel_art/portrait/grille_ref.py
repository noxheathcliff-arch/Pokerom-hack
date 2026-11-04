"""Rendu seulement : agrandit le calque ref (ou une image) avec une grille chiffrée pour LIRE les coordonnées.
usage: python3 grille_ref.py in.png out.png zoom [x0 y0 x1 y1]"""
import sys
from PIL import Image, ImageDraw
im=Image.open(sys.argv[1]).convert('RGB'); z=int(sys.argv[3])
if len(sys.argv)>4: x0,y0,x1,y1=map(int,sys.argv[4:8])
else: x0,y0,x1,y1=0,0,im.width,im.height
im=im.crop((x0,y0,x1,y1)); big=im.resize((im.width*z,im.height*z),Image.NEAREST)
c=Image.new('RGB',(big.width+30,big.height+16),(30,30,30)); c.paste(big,(30,16)); d=ImageDraw.Draw(c)
step=8 if z>=4 else 16
for x in range(x0 - x0%step, x1+1, step):
    X=30+(x-x0)*z
    if X<30: continue
    d.line([(X,16),(X,c.height)],fill=(0,255,0) if x%32==0 else (0,140,255),width=1)
    if x%(step*2)==0: d.text((X+1,2),str(x),fill=(255,255,0))
for y in range(y0 - y0%step, y1+1, step):
    Y=16+(y-y0)*z
    if Y<16: continue
    d.line([(30,Y),(c.width,Y)],fill=(0,255,0) if y%32==0 else (0,140,255),width=1)
    if y%(step*2)==0: d.text((2,Y+1),str(y),fill=(255,255,0))
c.save(sys.argv[2])
