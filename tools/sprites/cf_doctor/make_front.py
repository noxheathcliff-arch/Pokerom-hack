#!/usr/bin/env python3
"""Doctor front pic: Steven's front sprite redrawn over (recolour + manual patches)."""
import sys
from PIL import Image

SRC = "graphics/trainers/front_pics/steven.png"
OUT = sys.argv[1]

PAL = [
    (115, 197, 164),  # 0 transparent
    (248, 238, 230),  # 1 skin light
    (230, 212, 206),  # 2 skin mid
    (196, 172, 172),  # 3 skin shadow
    (28, 44, 52),     # 4 charcoal
    (112, 142, 210),  # 5 scrubs light
    (72, 100, 172),   # 6 scrubs mid
    (42, 58, 112),    # 7 scrubs dark
    (70, 94, 98),     # 8 dark teal-grey (coat deep shadow / hair dark)
    (166, 180, 192),  # 9 coat mid
    (212, 222, 230),  # 10 coat light
    (134, 182, 160),  # 11 hair light
    (78, 124, 110),   # 12 hair mid
    (214, 64, 60),    # 13 red (ball)
    (252, 252, 252),  # 14 white
    (14, 18, 26),     # 15 black
]
src = Image.open(SRC)
g = [[src.getpixel((x, y)) for x in range(64)] for y in range(64)]
out = [[0] * 64 for _ in range(64)]

for y in range(64):
    for x in range(64):
        v = g[y][x]
        if v == 0:
            continue
        n = v
        head = y <= 16 and 24 <= x <= 46
        if head:
            n = {9: 11, 10: 12, 11: 8, 7: 8, 8: 4, 1: 1, 2: 2, 3: 3, 4: 3, 14: 14, 15: 15, 5: 3, 6: 3, 12: 13, 13: 13}.get(v, v)
        elif 17 <= y <= 21 and 29 <= x <= 39:
            # collar / neck
            n = {1: 4, 2: 4, 3: 4, 4: 4, 12: 8, 13: 4, 9: 14, 10: 10, 11: 9, 7: 9, 8: 8, 14: 14, 15: 15, 5: 5, 6: 6}.get(v, v)
        elif y >= 41:
            # trousers (and shoes)
            if y >= 59 and v in (5, 6):
                n = 7
            else:
                n = {7: 6, 8: 7, 5: 5, 6: 6, 9: 10, 10: 9, 11: 9}.get(v, v)
        else:
            # jacket -> lab coat, inner vest -> scrubs, skin (hands) -> gloves
            if v in (1, 2, 3, 4):
                n = {1: 8, 2: 4, 3: 4, 4: 15}[v]
            else:
                n = {7: 10, 8: 9, 5: 5, 6: 6, 9: 14, 10: 10, 11: 9, 12: 4, 13: 4, 14: 14, 15: 15}.get(v, v)
        out[y][x] = n

if __name__ == "__main__":
    pass

import os
exec(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'front_patch.py')).read())

im = Image.new('P', (64, 64))
flat = []
for r, gg, b in PAL:
    flat += [r, gg, b]
im.putpalette(flat)
for y in range(64):
    for x in range(64):
        im.putpixel((x, y), out[y][x])
im.save(OUT)
print("saved", OUT)
