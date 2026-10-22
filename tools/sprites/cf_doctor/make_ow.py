#!/usr/bin/env python3
"""Doctor OW sheet (144x32): Steven's OW head over the FRLG scientist's lab-coat body."""
import sys
from PIL import Image

BODY = "graphics/object_events/pics/people/scientist_1.png"
HEAD = "graphics/object_events/pics/people/steven.png"
OUT = sys.argv[1]

PAL = [
    (115, 197, 164),  # 0 transparent
    (248, 236, 228),  # 1 skin light
    (230, 210, 204),  # 2 skin mid
    (190, 164, 164),  # 3 skin shadow
    (40, 44, 56),     # 4 gloves
    (226, 234, 230),  # 5 coat light
    (166, 182, 188),  # 6 coat mid
    (96, 114, 130),   # 7 coat dark
    (34, 38, 48),     # 8 turtleneck
    (84, 108, 176),   # 9 scrubs
    (46, 62, 120),    # 10 scrubs dark / shoes
    (140, 192, 164),  # 11 hair light
    (74, 126, 112),   # 12 hair mid
    (32, 72, 74),     # 13 hair dark
    (255, 255, 255),  # 14 white
    (14, 18, 24),     # 15 outline
]
body = Image.open(BODY)
head = Image.open(HEAD)


def grid(im, f):
    return [[im.getpixel((f * 16 + x, y)) for x in range(16)] for y in range(32)]


def top(g):
    for y, r in enumerate(g):
        if any(r):
            return y


BODY_REMAP = {0: 0, 1: 1, 2: 2, 3: 3, 4: 3, 5: 5, 6: 6, 7: 7, 8: 9, 9: 9, 10: 10, 11: 11, 12: 12, 13: 13, 14: 14, 15: 15}
HEAD_REMAP = {0: 0, 1: 1, 2: 2, 3: 3, 4: 3, 11: 11, 12: 12, 13: 13, 14: 14, 15: 15}
HEAD_ROWS = 11


def compose(f):
    b = grid(body, f)
    h = grid(head, f)
    tb, th = top(b), top(h)
    out = [[BODY_REMAP[v] for v in r] for r in b]
    # body recolour
    for y in range(32):
        for x in range(16):
            v = b[y][x]
            if v in (1, 2, 3, 4) and y >= tb + 8:
                if y >= tb + 12:
                    out[y][x] = 4
                elif 3 <= x <= 12:
                    out[y][x] = 8
                else:
                    out[y][x] = 3
            if v in (11, 12, 13) and y >= tb + 17:
                out[y][x] = 10
    # clear the old head (rows tb .. tb+9) and paste Steven's
    for y in range(tb, tb + 11):
        for x in range(16):
            out[y][x] = 0
    for j in range(HEAD_ROWS):
        for x in range(16):
            v = h[th + j][x]
            if v == 0:
                continue
            out[tb + j][x] = HEAD_REMAP.get(v, 3)
    return out


sheet = Image.new('P', (144, 32))
flat = []
for r, g_, b_ in PAL:
    flat += [r, g_, b_]
sheet.putpalette(flat)
for f in range(9):
    o = compose(f)
    for y in range(32):
        for x in range(16):
            sheet.putpixel((f * 16 + x, y), o[y][x])
sheet.save(OUT)
print("saved", OUT)
