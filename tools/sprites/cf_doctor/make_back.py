#!/usr/bin/env python3
"""Doctor back pic: Steven's back pic (4 frames, throw animation) redrawn over."""
import sys
from PIL import Image

SRC = "graphics/trainers/back_pics/steven.png"
OUT = sys.argv[1]
PAL = [
    (115, 197, 164), (248, 238, 230), (230, 212, 206), (196, 172, 172), (28, 44, 52), (112, 142, 210),
    (72, 100, 172), (42, 58, 112), (70, 94, 98), (166, 180, 192), (212, 222, 230), (134, 182, 160),
    (78, 124, 110), (214, 64, 60), (252, 252, 252), (14, 18, 26),
]
src = Image.open(SRC)


def frame(f):
    return [[src.getpixel((x, f * 64 + y)) for x in range(64)] for y in range(64)]


def find_eye(g):
    for y in range(18, 34):
        for x in range(26, 60):
            if g[y][x] == 14:
                for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                    if g[y + dy][x + dx] == 15:
                        return x, y
    return 40, 26


def build(f):
    g = frame(f)
    ex, ey = find_eye(g)
    out = [[0] * 64 for _ in range(64)]
    for y in range(64):
        for x in range(64):
            v = g[y][x]
            if v == 0:
                continue
            n = v
            if v in (1, 2, 3, 4):
                if x < 20 or y >= 46:
                    n = {1: 9, 2: 8, 3: 4, 4: 15}[v]          # hands -> gloves
                elif x < ex - 4 and y >= ey + 6:
                    n = 4                                      # neck -> turtleneck
                else:
                    n = {1: 1, 2: 2, 3: 3, 4: 3}[v]
            elif y <= ey + 12 and x >= 4:
                # hair (above/behind the face)
                if v in (9, 10, 11, 7, 8, 14, 15):
                    n = {9: 11, 10: 12, 11: 8, 7: 8, 8: 4, 14: 14, 15: 15}[v]
                    if v == 11:
                        below = g[y + 1][x] if y < 63 else 0
                        n = 8 if below in (0, 15) else 12
                    if y >= ey + 8 and v in (9, 10, 11) and x < ex - 4:
                        n = 4 if v != 9 else 8                 # collar band -> turtleneck
            else:
                n = {7: 10, 8: 9, 9: 14, 10: 10, 11: 9, 12: 13, 13: 13, 5: 5, 6: 6, 14: 14, 15: 15}.get(v, v)
            out[y][x] = n
    return out


import os
exec(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'back_patch.py')).read())

sheet = Image.new('P', (64, 256))
flat = []
for r, gg, b in PAL:
    flat += [r, gg, b]
sheet.putpalette(flat)
for f in range(4):
    o = build(f)
    try:
        o = post(f, o)  # noqa
    except NameError:
        pass
    for y in range(64):
        for x in range(64):
            sheet.putpixel((x, f * 64 + y), o[y][x])
sheet.save(OUT)
print("saved", OUT)
