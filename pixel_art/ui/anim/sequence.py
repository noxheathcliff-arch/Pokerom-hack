"""E5-B : bande, pelure d'oignon et GIF aux vraies durées (rendu seulement, ne décide rien).
usage : python3 sequence.py [suffixe]  -> bande{suf}.png, oignon{suf}.png, anim{suf}.gif"""
import sys, re
from PIL import Image, ImageDraw
suf = sys.argv[1] if len(sys.argv) > 1 else ''
D = {}
for l in open('ANIM_PLAN.md'):
    m = re.match(r'\| (\d\d) \|.*\| (\d+) ms \|', l)
    if m: D[int(m[1])] = int(m[2])
N = sorted(D)
ims = [Image.open(f'f{n:02d}/final.png').convert('RGBA') for n in N]
w, h = ims[0].size; BG = (30, 30, 40, 255)
def on(im, bg=BG):
    t = Image.new('RGBA', im.size, bg); t.alpha_composite(im); return t
# bande : x1 en haut, x3 en colonne avec numéro et durée
cols = 3; Z = 3
rows = (len(ims) + cols - 1) // cols
B = Image.new('RGBA', (cols * (w * Z + 10) + 10, rows * (h * Z + 22) + h + 30), (52, 52, 62, 255))
d = ImageDraw.Draw(B)
for i, im in enumerate(ims):                       # ligne x1
    B.alpha_composite(on(im), (10 + (i % 7) * (w + 4), 6 + (i // 7) * 0))
B = B  # (x1 en tête, chevauchement évité ci-dessous)
B = Image.new('RGBA', (cols * (w * Z + 10) + 10, rows * (h * Z + 22) + 10), (52, 52, 62, 255)); d = ImageDraw.Draw(B)
for i, (n, im) in enumerate(zip(N, ims)):
    x = 10 + (i % cols) * (w * Z + 10); y = 10 + (i // cols) * (h * Z + 22)
    d.text((x, y), f'F{n:02d}  {D[n]} ms', fill=(230, 230, 230, 255))
    B.alpha_composite(on(im).resize((w * Z, h * Z), Image.NEAREST), (x, y + 12))
B.save(f'bande{suf}.png')
X1 = Image.new('RGBA', ((w + 2) * len(ims), h), (52, 52, 62, 255))
for i, im in enumerate(ims): X1.alpha_composite(on(im), (i * (w + 2), 0))
X1.save(f'bande_x1{suf}.png')
# pelure d'oignon : image n (pleine) sur n-1 (rouge, 40 %)
O = Image.new('RGBA', (cols * (w * Z + 10) + 10, rows * (h * Z + 22) + 10), (52, 52, 62, 255)); d = ImageDraw.Draw(O)
for i in range(1, len(ims)):
    prev = ims[i - 1].copy(); a = prev.split()[3].point(lambda v: v * 100 // 255)
    red = Image.new('RGBA', prev.size, (255, 60, 60, 255)); red.putalpha(a)
    cur = ims[i].copy(); cur.putalpha(cur.split()[3].point(lambda v: v * 150 // 255))
    t = Image.new('RGBA', (w, h), BG); t.alpha_composite(red); t.alpha_composite(cur)
    j = i - 1; x = 10 + (j % cols) * (w * Z + 10); y = 10 + (j // cols) * (h * Z + 22)
    d.text((x, y), f'F{N[i]:02d} sur F{N[i-1]:02d}', fill=(230, 230, 230, 255))
    O.alpha_composite(t.resize((w * Z, h * Z), Image.NEAREST), (x, y + 12))
O.save(f'oignon{suf}.png')
fr = [on(im).convert('RGB').resize((w * 4, h * 4), Image.NEAREST) for im in ims]
fr[0].save(f'anim{suf}.gif', save_all=True, append_images=fr[1:], duration=[D[n] for n in N], loop=0, disposal=1)
print('ok', len(ims), 'images, total', sum(D.values()), 'ms')
