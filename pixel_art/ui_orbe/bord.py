"""Contour sélectif (selout) : variante de contour.py avec la lettre de sortie choisie à la main.
usage: python3 bord.py in.txt out.txt L CALQUE CONTRE [DIRS] [x1 y1 x2 y2]
  Les pixels des lettres CALQUE qui touchent (4-voisins) une lettre de CONTRE ('.' = vide, bord d'image
  compté comme vide) deviennent L.  DIRS limite les voisins regardés : h=haut b=bas g=gauche d=droite
  ('*' = les quatre).  La boîte limite la zone.  Règle mécanique : je choisis lettres, sens et zone."""
import sys
a = sys.argv
g = [list(l.rstrip('\n')) for l in open(a[1]) if l.strip() and not l.startswith('#')]
H = len(g); W = len(g[0])
L, cal, con = a[3], set(a[4]), set(a[5])
dirs = a[6] if len(a) > 6 else '*'
box = list(map(int, a[7:11])) if len(a) > 10 else [0, 0, W-1, H-1]
V = {'h': (0, -1), 'b': (0, 1), 'g': (-1, 0), 'd': (1, 0)}
vs = list(V.values()) if dirs == '*' else [V[c] for c in dirs]
def at(x, y): return g[y][x] if 0 <= x < W and 0 <= y < H else '.'
o = [r[:] for r in g]
for y in range(max(0, box[1]), min(H, box[3]+1)):
    for x in range(max(0, box[0]), min(W, box[2]+1)):
        if g[y][x] in cal and any(at(x+dx, y+dy) in con for dx, dy in vs): o[y][x] = L
open(a[2], 'w').write('\n'.join(''.join(r) for r in o)+'\n')
