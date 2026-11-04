"""Pose O sur les pixels de bord (garde les couleurs intérieures). Ne décide rien : règle mécanique.
usage: python3 contour.py in.txt out.txt                 -> tout pixel plein qui touche le vide (4-voisins) devient O
       python3 contour.py in.txt out.txt CALQUE [CONTRE]  -> seuls les pixels des lettres CALQUE qui touchent
                                                            le vide OU une lettre de CONTRE deviennent O
ex: python3 contour.py a.txt b.txt tjJreEucChkH slmS   (vêtements cernés contre le vide et contre la peau)"""
import sys
g=[list(l.rstrip('\n')) for l in open(sys.argv[1]) if l.strip()]
H=len(g);W=len(g[0])
calque=sys.argv[3] if len(sys.argv)>3 else None
contre=set(sys.argv[4]) if len(sys.argv)>4 else set()
def bord(x,y):
    if not(0<=x<W and 0<=y<H): return True
    return g[y][x]=='.' or g[y][x] in contre
o=[r[:] for r in g]
for y in range(H):
  for x in range(W):
    c=g[y][x]
    if c=='.' or (calque and c not in calque): continue
    if any(bord(x+dx,y+dy) for dx,dy in((1,0),(-1,0),(0,1),(0,-1))): o[y][x]='O'
open(sys.argv[2],'w').write('\n'.join(''.join(r) for r in o)+'\n')
