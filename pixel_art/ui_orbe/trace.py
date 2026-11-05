"""Pose des primitives DÉCIDÉES À LA MAIN sur une grille texte (l'outil ne décide rien).
Équivalent des outils d'un logiciel de dessin : je donne les points, il remplit ou trace.
usage: python3 trace.py in.txt|NEW:WxH:C out.txt cmds.txt [cmds2.txt ...]
Commandes (C = caractère de couleur) :
  px C x y | line C x1 y1 x2 y2 | hline C x1 x2 y | vline C x y1 y2 | rect C x1 y1 x2 y2
  disc C cx cy r | ell C cx cy rx ry [angle°]          ellipse pleine
  poly C x y x y ...        polygone plein, sommets posés à la main
  blob C x y x y ...        forme pleine fermée, courbe passant par mes points (Catmull-Rom)
  stroke C x y x y ...      trait de 1 px passant par mes points, nettoyé « pixel-perfect »
  rows C y x1 x2 [...]      plages explicites
  rep A B x1 y1 x2 y2       remplace A par B dans la zone
  mask ABC | mask *         verrou : les commandes suivantes ne peignent que sur ces couleurs
  nomask ABC                verrou inverse : ne peint jamais sur ces couleurs
  stamp f.txt x y           colle une pièce dessinée à la main ('.' transparent)
  miroir A y1 y2 [x1 x2]    symétrie verticale (axe = colonne A) : recopie la moitié gauche sur la droite
                            (x1 x2 = colonnes de destination, pour ne pas écraser une lumière asymétrique)
                            (outil « symétrie » d'un logiciel de dessin ; je dessine la moitié gauche)
"""
import sys, math
src, out = sys.argv[1:3]; cmdfs = sys.argv[3:]
if src.startswith('NEW:'):
    p = src[4:].split(':'); W, H = map(int, p[0].split('x')); fill = p[1] if len(p) > 1 else '.'
    g = [[fill]*W for _ in range(H)]
else:
    g = [list(l.rstrip('\n')) for l in open(src) if not l.startswith('#') and l.strip()]
H = len(g); W = len(g[0])
MASK = None; NOMASK = ''
def put(c, x, y):
    x, y = int(x), int(y)
    if 0 <= x < W and 0 <= y < H:
        if MASK is not None and g[y][x] not in MASK: return
        if g[y][x] in NOMASK: return
        g[y][x] = c

def fill_poly(C, pts):
    ys = [p[1] for p in pts]
    for y in range(max(0, int(min(ys))), min(H, int(max(ys)) + 2)):
        yc = y + 0.5; xs = []
        n = len(pts)
        for i in range(n):
            (x1, y1), (x2, y2) = pts[i], pts[(i+1) % n]
            if (y1 <= yc < y2) or (y2 <= yc < y1):
                xs.append(x1 + (yc-y1)*(x2-x1)/(y2-y1))
        xs.sort()
        for a, b in zip(xs[0::2], xs[1::2]):
            for x in range(int(math.ceil(a-0.5)), int(math.floor(b-0.5))+1): put(C, x, y)

def catmull(pts, closed, step=0.02):
    P = pts[:] ; n = len(P); res = []
    if closed: seg = range(n)
    else: P = [P[0]] + P + [P[-1]]; seg = range(1, n)
    for i in seg:
        if closed: p0, p1, p2, p3 = P[(i-1) % n], P[i], P[(i+1) % n], P[(i+2) % n]
        else: p0, p1, p2, p3 = P[i-1], P[i], P[i+1], P[i+2]
        L = max(abs(p2[0]-p1[0]), abs(p2[1]-p1[1]), 1)
        k = int(L*6) + 2
        for s in range(k):
            t = s/k
            res.append(tuple(0.5*((2*p1[j]) + (-p0[j]+p2[j])*t + (2*p0[j]-5*p1[j]+4*p2[j]-p3[j])*t*t
                                  + (-p0[j]+3*p1[j]-3*p2[j]+p3[j])*t**3) for j in (0, 1)))
    if not closed: res.append(pts[-1])
    return res

def pixel_perfect(cells):
    # enlève les doublons et les coins en « L » (A5-6)
    c = []
    for p in cells:
        if not c or c[-1] != p: c.append(p)
    i = 1
    while i < len(c)-1:
        a, b, d = c[i-1], c[i], c[i+1]
        if abs(a[0]-d[0]) == 1 and abs(a[1]-d[1]) == 1 and (b[0] == a[0] or b[1] == a[1]):
            del c[i]
        else: i += 1
    return c

def line_cells(x1, y1, x2, y2):
    n = max(abs(x2-x1), abs(y2-y1)) or 1
    return [(round(x1+(x2-x1)*k/n), round(y1+(y2-y1)*k/n)) for k in range(n+1)]

for f in cmdfs:
  for line in open(f):
    p = line.split()
    if not p or p[0].startswith('#'): continue
    op = p[0]
    if op == 'mask': MASK = None if p[1] == '*' else p[1]; continue
    if op == 'nomask': NOMASK = '' if p[1] == '*' else p[1]; continue
    if op == 'stamp':
        sp = [l.rstrip('\n') for l in open(p[1]) if not l.startswith('#') and l.strip()]
        ox, oy = int(p[2]), int(p[3])
        for y, r in enumerate(sp):
            for x, c in enumerate(r):
                if c != '.': put(c, ox+x, oy+y)
        continue
    if op == 'miroir':
        ax, y1, y2 = map(int, p[1:4])
        dx1, dx2 = (int(p[4]), int(p[5])) if len(p) > 5 else (ax+1, 2*ax)
        for y in range(max(0,y1), min(H,y2+1)):
            for x in range(max(ax+1,dx1), min(W, 2*ax+1, dx2+1)):
                if MASK is None or g[y][x] in MASK: g[y][x] = g[y][2*ax-x]
        continue
    if op == 'rep':
        A, B = p[1], p[2]; x1, y1, x2, y2 = map(int, p[3:7])
        for y in range(max(0,y1), min(H,y2+1)):
            for x in range(max(0,x1), min(W,x2+1)):
                if g[y][x] == A: g[y][x] = B
        continue
    C = p[1]; a = [float(v) for v in p[2:]]
    if op == 'px': put(C, a[0], a[1])
    elif op == 'line': [put(C, x, y) for x, y in line_cells(*map(round, a))]
    elif op == 'hline': [put(C, x, a[2]) for x in range(int(a[0]), int(a[1])+1)]
    elif op == 'vline': [put(C, a[0], y) for y in range(int(a[1]), int(a[2])+1)]
    elif op == 'rect': [put(C, x, y) for y in range(int(a[1]), int(a[3])+1) for x in range(int(a[0]), int(a[2])+1)]
    elif op == 'disc':
        cx, cy, r = a
        for y in range(int(cy-r)-1, int(cy+r)+2):
            for x in range(int(cx-r)-1, int(cx+r)+2):
                if (x-cx)**2+(y-cy)**2 <= r*r: put(C, x, y)
    elif op == 'ell':
        cx, cy, rx, ry = a[:4]; an = math.radians(a[4]) if len(a) > 4 else 0
        R = int(max(rx, ry))+2; ca, sa = math.cos(an), math.sin(an)
        for y in range(int(cy)-R, int(cy)+R+1):
            for x in range(int(cx)-R, int(cx)+R+1):
                u = (x-cx)*ca+(y-cy)*sa; v = -(x-cx)*sa+(y-cy)*ca
                if (u/rx)**2+(v/ry)**2 <= 1: put(C, x, y)
    elif op == 'poly': fill_poly(C, list(zip(a[0::2], a[1::2])))
    elif op == 'blob': fill_poly(C, catmull(list(zip(a[0::2], a[1::2])), True))
    elif op == 'stroke':
        pts = list(zip(a[0::2], a[1::2]))
        cur = catmull(pts, False) if len(pts) > 2 else pts
        cells = []
        for (x1, y1), (x2, y2) in zip(cur, cur[1:]):
            cells += line_cells(round(x1), round(y1), round(x2), round(y2))
        for x, y in pixel_perfect(cells): put(C, x, y)
    elif op == 'rows':
        v = list(map(int, a))
        for i in range(0, len(v), 3): [put(C, x, v[i]) for x in range(v[i+1], v[i+2]+1)]
    else: raise SystemExit('commande inconnue: ' + op)
open(out, 'w').write('\n'.join(''.join(r) for r in g)+'\n')
