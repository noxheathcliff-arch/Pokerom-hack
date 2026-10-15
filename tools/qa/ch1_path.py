#!/usr/bin/env python3
"""QA helper: BFS over a layout's collision bits (map.bin). Prints gbaplay 'press DIR 16' steps.
usage: ch1_path.py LayoutDir W H sx sy gx gy   (ignores NPCs/ledges/behaviors; collision bit only)"""
import sys, struct, collections
d, W, H, sx, sy, gx, gy = sys.argv[1], *map(int, sys.argv[2:8])
b = open(f'data/layouts/{d}/map.bin', 'rb').read()
def free(x, y):
    if not (0 <= x < W and 0 <= y < H): return False
    v = struct.unpack_from('<H', b, 2 * (y * W + x))[0]
    return (v >> 10) & 3 == 0
q = collections.deque([(sx, sy)]); prev = {(sx, sy): None}
while q:
    c = q.popleft()
    if c == (gx, gy): break
    for n, dn in (((c[0], c[1]-1), 'UP'), ((c[0], c[1]+1), 'DOWN'), ((c[0]-1, c[1]), 'LEFT'), ((c[0]+1, c[1]), 'RIGHT')):
        if n not in prev and free(*n):
            prev[n] = (c, dn); q.append(n)
if (gx, gy) not in prev: print('NOPATH'); sys.exit(1)
out = []; c = (gx, gy)
while prev[c]: out.append(prev[c][1]); c = prev[c][0]
out.reverse()
# per-run waitfor on the saved position (robust against turn frames)
POSX, POSY = '*gSaveBlock1Ptr+SB1_POS_OFFSET', '*gSaveBlock1Ptr+SB1_POS_OFFSET+2'
runs = []
for m in out:
    if runs and runs[-1][0] == m: runs[-1][1] += 1
    else: runs.append([m, 1])
x, y = sx, sy; lines = []
for m, n in runs:
    dx, dy = {'UP': (0, -1), 'DOWN': (0, 1), 'LEFT': (-1, 0), 'RIGHT': (1, 0)}[m]
    x += dx * n; y += dy * n
    lines.append(f"waitfor16 {POSX if dx else POSY} {x if dx else y} {40*n+40} {m} 4")
print(';'.join(lines))
