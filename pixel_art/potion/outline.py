import sys
g=[list(l.rstrip('\n')) for l in open(sys.argv[1]) if l.strip()]
H=len(g);W=len(g[0]); ins=lambda x,y:0<=x<W and 0<=y<H and g[y][x]=='K'
o=[['.']*W for _ in range(H)]
for y in range(H):
  for x in range(W):
    if ins(x,y) and not all(ins(x+dx,y+dy) for dx,dy in((1,0),(-1,0),(0,1),(0,-1))): o[y][x]='O'
open(sys.argv[2],'w').write('\n'.join(''.join(r) for r in o)+'\n')
