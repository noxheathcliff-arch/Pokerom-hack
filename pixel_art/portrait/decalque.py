"""Table lumineuse (E6, calque ref verrouille).
Les FORMES sont decidees a la main dans un fichier de zones (polygones par matiere, ecrits a la main).
L'outil ne fait que : pour chaque pixel, prendre la teinte du calque ref et choisir la couleur la plus
proche (Lab) PARMI les lettres autorisees de la zone (palette faite a la main). = decalquer.
usage: python3 decalque.py zones.txt out.txt
zones.txt : 'zone NOM LETTRES' puis 'poly x1 y1 x2 y2 ...' (plusieurs poly possibles). Ordre = priorite (derniere gagne)."""
import sys, json
from PIL import Image, ImageDraw
def lab(h):
    r,g,b=[int(h[i:i+2],16)/255 for i in (1,3,5)] if isinstance(h,str) else [c/255 for c in h]
    f=lambda c: ((c+.055)/1.055)**2.4 if c>.04045 else c/12.92
    r,g,b=f(r),f(g),f(b)
    X=(r*.4124+g*.3576+b*.1805)/.95047; Y=r*.2126+g*.7152+b*.0722; Z=(r*.0193+g*.1192+b*.9505)/1.08883
    t=lambda v: v**(1/3) if v>.008856 else 7.787*v+16/116
    return (116*t(Y)-16, 500*(t(X)-t(Y)), 200*(t(Y)-t(Z)))
pal=json.load(open('palette.json')); PL={k:lab(v) for k,v in pal.items()}
ref=Image.open('ref_256x320.png').convert('RGB'); W,H=ref.size
zid=Image.new('L',(W,H),0); zones=[]
for ln in open(sys.argv[1]):
    p=ln.split('#')[0].split()
    if not p: continue
    if p[0]=='zone': zones.append(p[2]); cur=len(zones)
    elif p[0]=='poly':
        v=list(map(int,p[1:])); ImageDraw.Draw(zid).polygon(list(zip(v[::2],v[1::2])),fill=cur)
cache={}; out=[]
for y in range(H):
    row=''
    for x in range(W):
        z=zones[zid.getpixel((x,y))-1]; c=ref.getpixel((x,y)); k=(z,c)
        if k not in cache:
            L=lab(c); cache[k]=min(z,key=lambda l: sum((a-b)**2 for a,b in zip(L,PL[l])))
        row+=cache[k]
    out.append(row)
open(sys.argv[2],'w').write('\n'.join(out)+'\n'); print('ok',sys.argv[2])
