"""Outil de rendu seulement : il NE DÉCIDE RIEN.
Lit une grille texte posée à la main (1 caractère = 1 pixel) + une palette,
et produit l'image à x1 et agrandie (avec grille) pour la regarder (règle R1).
Usage : python3 px.py etape_XX_nom.txt [zoom]
"""
import sys, json
from PIL import Image, ImageDraw

def load_palette(path="palette.json"):
    with open(path) as f:
        pal = json.load(f)
    return {k: tuple(int(v[i:i+2], 16) for i in (1, 3, 5)) for k, v in pal.items()}

def read_grid(path):
    rows = [l.rstrip("\n") for l in open(path) if not l.startswith("#")]
    rows = [r for r in rows if r.strip() != "" or False]
    w = max(len(r) for r in rows)
    return [r.ljust(w, ".") for r in rows]

def render(grid, pal, bg=None):
    h, w = len(grid), len(grid[0])
    im = Image.new("RGBA", (w, h), (0, 0, 0, 0) if bg is None else bg + (255,))
    for y, r in enumerate(grid):
        for x, c in enumerate(r):
            if c in ".":
                continue
            if c not in pal:
                raise SystemExit(f"caractère inconnu {c!r} ligne {y} col {x}")
            im.putpixel((x, y), pal[c] + (255,))
    return im

def zoom(im, z, grid=True, bg=(60, 60, 70)):
    base = Image.new("RGBA", im.size, bg + (255,))
    base.alpha_composite(im)
    big = base.resize((im.width * z, im.height * z), Image.NEAREST)
    if grid and z >= 6:
        d = ImageDraw.Draw(big)
        for i in range(0, big.width, z):
            d.line([(i, 0), (i, big.height)], fill=(0, 0, 0, 40) if i % (8*z) else (255, 255, 255, 70))
        for j in range(0, big.height, z):
            d.line([(0, j), (big.width, j)], fill=(0, 0, 0, 40) if j % (8*z) else (255, 255, 255, 70))
    return big

if __name__ == "__main__":
    src = sys.argv[1]
    z = int(sys.argv[2]) if len(sys.argv) > 2 else 12
    pal = load_palette(sys.argv[3] if len(sys.argv) > 3 else "palette.json")
    g = read_grid(src)
    im = render(g, pal)
    stem = src[:-4]
    im.save(stem + ".png")
    # vue de travail : x1 (sur clair et sombre) à côté de l'agrandi
    big = zoom(im, z)
    sheet = Image.new("RGBA", (big.width + im.width * 4 + 40, big.height + 0), (40, 40, 48, 255))
    sheet.alpha_composite(big, (0, 0))
    for i, b in enumerate([(235, 230, 220), (30, 30, 36)]):
        tile = Image.new("RGBA", (im.width + 8, im.height + 8), b + (255,))
        tile.alpha_composite(im, (4, 4))
        sheet.alpha_composite(tile, (big.width + 10, 10 + i * (im.height + 16)))
        t2 = tile.resize((tile.width * 2, tile.height * 2), Image.NEAREST)
        sheet.alpha_composite(t2, (big.width + 20 + tile.width, 10 + i * (im.height * 2 + 24)))
    sheet.save(stem + "_vue.png")
    print("ok", stem, im.size)
