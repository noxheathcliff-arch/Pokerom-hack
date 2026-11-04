"""Places primitives DECIDED BY HAND onto a character grid (decides nothing).
usage: python3 trace.py in.txt|NEW:WxH out.txt cmds.txt
cmds: px C x y | hline C x1 x2 y | vline C x y1 y2 | rect C x1 y1 x2 y2 | frame C x1 y1 x2 y2
      disc C cx cy r | ring C cx cy r | rows C y x1 x2 [y x1 x2 ...] (explicit spans) | rep A B x1 y1 x2 y2 (replace A->B in the zone)"""
import sys
src,out,cmdf=sys.argv[1:4]
if src.startswith('NEW:'):
    W,H=map(int,src[4:].split('x')); g=[['.']*W for _ in range(H)]
else:
    g=[list(l.rstrip('\n')) for l in open(src) if not l.startswith('#') and l.strip()]
H=len(g); W=len(g[0])
def put(c,x,y):
    if 0<=x<W and 0<=y<H: g[y][x]=c
for line in open(cmdf):
    p=line.split()
    if not p or p[0].startswith('#'): continue
    if p[0]=='rep':
        A,B=p[1],p[2]; x1,y1,x2,y2=map(int,p[3:7])
        for y in range(y1,y2+1):
            for x in range(x1,x2+1):
                if g[y][x]==A: g[y][x]=B
        continue
    op,C,a=p[0],p[1],list(map(float,p[2:]))
    a=[int(v) if v==int(v) else v for v in a]
    if op=='px': put(C,a[0],a[1])
    elif op=='hline': [put(C,x,a[2]) for x in range(a[0],a[1]+1)]
    elif op=='vline': [put(C,a[0],y) for y in range(a[1],a[2]+1)]
    elif op=='rect': [put(C,x,y) for y in range(a[1],a[3]+1) for x in range(a[0],a[2]+1)]
    elif op=='frame':
        for x in range(a[0],a[2]+1): put(C,x,a[1]); put(C,x,a[3])
        for y in range(a[1],a[3]+1): put(C,a[0],y); put(C,a[2],y)
    elif op in('disc','ring'):
        cx,cy,r=a
        for y in range(H):
            for x in range(W):
                d=((x-cx)**2+(y-cy)**2)**.5
                if (op=='disc' and d<=r) or (op=='ring' and abs(d-r)<0.5): put(C,x,y)
    elif op=='rows':
        v=list(map(int,p[2:]))
        for i in range(0,len(v),3): [put(C,x,v[i]) for x in range(v[i+1],v[i+2]+1)]
    elif op=='rep':
        A,B=p[1],p[2]; x1,y1,x2,y2=map(int,p[3:7])
        for y in range(y1,y2+1):
            for x in range(x1,x2+1):
                if g[y][x]==A: g[y][x]=B
open(out,'w').write('\n'.join(''.join(r) for r in g)+'\n')
