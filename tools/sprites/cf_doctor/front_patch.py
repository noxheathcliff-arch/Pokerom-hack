# executed inside front_steven.py (has `out`)
def blk(x0, y0, rows, clear=False):
    for j, r in enumerate(rows):
        for i, ch in enumerate(r):
            if ch == '_':
                continue
            out[y0 + j][x0 + i] = 0 if ch == '.' else int(ch, 16)


def row(y, x0, s):
    blk(x0, y, [s])


# ---------------- head: clear then redraw ----------------
for yy in range(0, 17):
    for xx in range(22, 48):
        out[yy][xx] = 0

row(1, 31, "8888888")
row(2, 29, "88ccbcccc88")
row(3, 27, "88ccbbc8ccbcc88")
row(4, 26, "8ccbbccc8cccbbccc8")
row(5, 25, "8ccbbcccc8cccbbcccc8")
row(6, 25, "8ccbccccc8ccccbbccc8")
row(7, 25, "8cccbcccc8ccccbcccc88")
row(8, 25, "8cbccccc111cccbcccc88")
def rowp(y, x0, *parts):
    s = "".join(parts)
    row(y, x0, s)


rowp(9, 25, "8ccbcc", "1111111", "cbcccc88")
rowp(10, 25, "8ccb", "14441114441", "cbcc88")
rowp(11, 25, "8ccb", "11111111111", "ccbc88")
rowp(12, 25, "8cc2", "1", "444", "111", "444", "1", "2", "cbc88")
rowp(13, 25, "8cc2", "1", "394", "111", "493", "1", "2", "cbc88")
rowp(14, 26, "8c2", "1", "111131111", "1", "2", "cb8")
rowp(15, 27, "88.", "3", "13333", "1113", ".88")
rowp(16, 31, "3111113")

# ---------------- neck / torso ----------------
# reset torso interior (keep black outlines)
for yy in range(17, 41):
    for xx in range(27, 40):
        if out[yy][xx] not in (0, 15):
            out[yy][xx] = 10

def cxf(y):
    return int(round(34 - (y - 17) / 23.0))

def hw(y):
    if y <= 19:
        return -1
    return {20: 0, 21: 1, 22: 1, 23: 2}.get(y, 3 if y < 25 else 4)

for yy in range(17, 41):
    cx = cxf(yy)
    if yy in (17, 18):
        for xx in range(32, 37):
            out[yy][xx] = 4
        if yy == 18:
            out[yy][31] = 14; out[yy][37] = 14
        continue
    if yy == 19:
        for xx in range(cx - 1, cx + 2):
            out[yy][xx] = 4
        out[yy][cx - 2] = 14; out[yy][cx + 2] = 14
        out[yy][cx - 3] = 10; out[yy][cx + 3] = 10
        continue
    h = hw(yy)
    # lapel band
    for k in (1, 2):
        out[yy][cx - h - k] = 14 if k == 1 else 10
        out[yy][cx + h + k] = 14 if k == 1 else 10
    if yy > 26:
        out[yy][cx - h - 1] = 10; out[yy][cx + h + 1] = 9
        out[yy][cx - h - 2] = 10; out[yy][cx + h + 2] = 9
    for xx in range(cx - h, cx + h + 1):
        if xx < cx - h // 2 - 1:
            out[yy][xx] = 5
        elif xx > cx + h // 2:
            out[yy][xx] = 6 if yy < 30 else 7
        else:
            out[yy][xx] = 6
    if yy == 20:
        out[yy][cx] = 4
# lanyard
for yy in range(21, 28):
    cx = cxf(yy)
    o = 2 if yy < 24 else 1
    out[yy][cx - o] = 9
    out[yy][cx + o] = 9
# ID card
for yy in range(28, 32):
    cx = cxf(yy)
    for xx in range(cx - 1, cx + 2):
        out[yy][xx] = 14
    if yy in (29, 30):
        out[yy][cx] = 4
# coat skirt: recolour thighs (y41..47) as coat
for yy in range(41, 46):
    for xx in range(20, 46):
        v = out[yy][xx]
        if v in (5, 6, 7):
            out[yy][xx] = {5: 14, 6: 10, 7: 9}[v]
for xx in range(20, 46):
    if out[45][xx] == 10:
        out[45][xx] = 9
# right hand glove cleanup
for xx, v in ((41, 4), (42, 8), (43, 4)):
    out[41][xx] = v
for xx, v in ((41, 4), (42, 15)):
    out[42][xx] = v

# ---------------- pokeball in the left hand ----------------
saved = [r[:] for r in out]
BALL = [
    "..fff..",
    ".fdddf.",
    "fdddddf",
    "ffffeff",
    "feeeeef",
    ".feeef.",
    "..fff..",
]
for j, r in enumerate(BALL):
    for i, ch in enumerate(r):
        if ch == '.':
            continue
        out[33 + j][6 + i] = int(ch, 16)
# fingers back over the ball
for yy in range(33, 41):
    for xx in range(12, 19):
        if saved[yy][xx] != 0:
            out[yy][xx] = saved[yy][xx]

# ---------------- shoe charms ----------------
out[60][21] = 13
out[60][23] = 11
out[61][41] = 13
