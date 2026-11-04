"""Pose O sur les pixels de bord d'une image déjà en aplats (garde les couleurs intérieures).
usage: python3 contour.py in.txt out.txt"""
import sys
g=[list(l.rstrip('\n')) for l in open(sys.argv[1]) if l.strip()]
H=len(g);W=len(g[0]); full=lambda x,y:0<=x<W and 0<=y<H and g[y][x]!='.'
o=[r[:] for r in g]
for y in range(H):
  for x in range(W):
    if full(x,y) and not all(full(x+dx,y+dy) for dx,dy in((1,0),(-1,0),(0,1),(0,-1))): o[y][x]='O'
open(sys.argv[2],'w').write('\n'.join(''.join(r) for r in o)+'\n')
