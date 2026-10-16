#!/usr/bin/env python3
"""Generate graphics/title_screen/emerald_version.png ("VERSION CONFLUENCE").

The title-screen version banner is a 128x32 8bpp object made of two 64x32
sprites. In the PNG the two halves are stacked vertically (64x64 image, left
half on top, right half below), see src/title_screen.c.

This script:
  * keeps the original "VERSION" word (taken from the vanilla banner, which
    is read from git history so the script stays reproducible),
  * draws "CONFLUENCE" from hand-made pixel glyphs, then applies the same
    look as the original: white fill, light shading on the lower edge,
    a 2px dark drop extrusion, a black outline and a soft dark outer border,
  * bends the word into an arch like the original "EMERAUDE".

The palette (16 colours, index 0 transparent) is copied unchanged.

Usage: python3 tools/qa/make_title_version_banner.py [--preview OUT.png]
"""
import io
import os
import subprocess
import sys

from PIL import Image

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
OUT = os.path.join(ROOT, "graphics", "title_screen", "emerald_version.png")
# Last vanilla version of the banner (before this script replaced it).
ORIG_REV = "bc5090a"

# Palette indices of the original banner.
T = 0        # transparent
OUTLINE = 1  # (24,24,24)
SHADE_LO = 2  # (156,156,156)
EXTR_DARK = 3  # (74,65,74)
SHADE_MID = 4  # (189,189,189)
EXTR = 5     # (115,115,115)
SHADE_HI = 6  # (230,230,230)
WHITE = 7    # (255,255,255)
BORDER = 15  # (49,49,49)

W, H = 128, 32

GLYPHS = {
    "C": [
        "..######..",
        ".########.",
        "##########",
        "####...###",
        "####......",
        "####......",
        "####......",
        "####......",
        "####......",
        "####...###",
        "##########",
        ".########.",
        "..######..",
    ],
    "O": [
        "..#######..",
        ".#########.",
        "###########",
        "####...####",
        "####...####",
        "####...####",
        "####...####",
        "####...####",
        "####...####",
        "####...####",
        "###########",
        ".#########.",
        "..#######..",
    ],
    "N": [
        "####...####",
        "#####..####",
        "#####..####",
        "######.####",
        "######.####",
        "###########",
        "###########",
        "###########",
        "####.######",
        "####.######",
        "####..#####",
        "####..#####",
        "####...####",
    ],
    "F": [
        "#########",
        "#########",
        "#########",
        "####.....",
        "####.....",
        "########.",
        "########.",
        "########.",
        "####.....",
        "####.....",
        "####.....",
        "####.....",
        "####.....",
    ],
    "L": [
        "####....",
        "####....",
        "####....",
        "####....",
        "####....",
        "####....",
        "####....",
        "####....",
        "####....",
        "####....",
        "########",
        "########",
        "########",
    ],
    "U": [
        "####...####",
        "####...####",
        "####...####",
        "####...####",
        "####...####",
        "####...####",
        "####...####",
        "####...####",
        "####...####",
        "####...####",
        "###########",
        ".#########.",
        "..#######..",
    ],
    "E": [
        "#########",
        "#########",
        "#########",
        "####.....",
        "####.....",
        "########.",
        "########.",
        "########.",
        "####.....",
        "####.....",
        "#########",
        "#########",
        "#########",
    ],
}

WORD = "CONFLUENCE"
LETTER_GAP = 2
FILL_TOP = 12      # top row of the letters at the centre of the arch
ARCH = 4           # how much lower the ends of the word sit than the centre
VERSION_ROWS = 11  # rows 0..10 of the vanilla banner hold "VERSION"


def load_original():
    data = subprocess.check_output(
        ["git", "-C", ROOT, "show", f"{ORIG_REV}:graphics/title_screen/emerald_version.png"])
    return Image.open(io.BytesIO(data))


def unstack(img):
    """64x64 stacked sheet -> 128x32 banner (list of rows of indices)."""
    px = img.load()
    return [[px[x % 64, y + 32 * (x // 64)] for x in range(W)] for y in range(H)]


def stack(rows, palette):
    img = Image.new("P", (64, 64), 0)
    img.putpalette(palette)
    px = img.load()
    for y in range(H):
        for x in range(W):
            px[x % 64, y + 32 * (x // 64)] = rows[y][x]
    return img


def build_word_mask():
    widths = [len(GLYPHS[c][0]) for c in WORD]
    total = sum(widths) + LETTER_GAP * (len(WORD) - 1)
    x0 = (W - total) // 2
    half = total / 2.0
    cx = x0 + half
    mask = [[False] * W for _ in range(H)]
    x = x0
    for c, w in zip(WORD, widths):
        g = GLYPHS[c]
        for gx in range(w):
            col = x + gx
            # Per-column vertical offset: a parabola gives the arched look.
            t = (col + 0.5 - cx) / half
            dy = int(round(ARCH * t * t))
            for gy, line in enumerate(g):
                if line[gx] == "#":
                    mask[FILL_TOP + gy + dy][col] = True
        x += w + LETTER_GAP
    return mask


def render_word(mask):
    def m(x, y):
        return 0 <= x < W and 0 <= y < H and mask[y][x]

    out = [[T] * W for _ in range(H)]
    # Drop extrusion below the letters (2px: mid grey, then dark grey).
    for y in range(H):
        for x in range(W):
            if m(x, y):
                continue
            if m(x, y - 1):
                out[y][x] = EXTR
            elif m(x, y - 2):
                out[y][x] = EXTR_DARK
    # Fill with shading on lower/right edges, like the vanilla letters.
    for y in range(H):
        for x in range(W):
            if not m(x, y):
                continue
            c = WHITE
            below = m(x, y + 1)
            right = m(x + 1, y)
            if not below:
                c = SHADE_HI
                if not right or not m(x - 1, y):
                    c = SHADE_MID
            elif not right and not m(x + 1, y + 1):
                c = SHADE_HI
            out[y][x] = c
    # Black outline around fill + extrusion, then a soft outer border.
    for colour in (OUTLINE, BORDER):
        solid = [[out[y][x] != T for x in range(W)] for y in range(H)]
        for y in range(H):
            for x in range(W):
                if solid[y][x]:
                    continue
                near = False
                for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)) if colour == BORDER else \
                        ((1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (-1, 1), (1, -1), (-1, -1)):
                    xx, yy = x + dx, y + dy
                    if 0 <= xx < W and 0 <= yy < H and solid[yy][xx]:
                        near = True
                        break
                if near:
                    out[y][x] = colour
    return out


def main():
    orig = load_original()
    palette = orig.getpalette()[:48]
    orig_rows = unstack(orig)

    rows = render_word(build_word_mask())

    # Re-centre the vanilla "VERSION" word over the new banner.
    xs = [x for y in range(VERSION_ROWS) for x in range(W) if orig_rows[y][x]]
    vmin, vmax = min(xs), max(xs)
    shift = (W - (vmax - vmin + 1)) // 2 - vmin
    for y in range(VERSION_ROWS):
        for x in range(W):
            v = orig_rows[y][x]
            if v:
                rows[y][x + shift] = v

    img = stack(rows, palette)
    img.save(OUT, optimize=False)
    print(f"wrote {OUT}")

    if len(sys.argv) > 2 and sys.argv[1] == "--preview":
        prev = Image.new("P", (W, H), 0)
        prev.putpalette(palette)
        prev.putdata([v for r in rows for v in r])
        prev.convert("RGB").resize((W * 8, H * 8), Image.NEAREST).save(sys.argv[2])
        print(f"preview {sys.argv[2]}")


if __name__ == "__main__":
    main()
