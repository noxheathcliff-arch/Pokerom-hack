import sys
from PIL import Image
REPO='/home/user/Pokerom-hack'
out=sys.argv[1]
mons=['pikachu','eevee','rattata']
SHIFT=-1
BARS=(8,11,21,24)
# collect mon RGBA frames
frames=[]
for m in mons:
    im=Image.open(f'{REPO}/graphics/pokemon/{m}/overworld.png')
    f=im.crop((0,0,32,32)).convert('RGBA')
    pal=im.getpalette()
    # index 0 transparent
    src=im.crop((0,0,32,32)).load(); px=f.load()
    for y in range(32):
        for x in range(32):
            if src[x,y]==0: px[x,y]=(0,0,0,0)
    g=Image.new('RGBA',(32,32),(0,0,0,0)); g.paste(f,(0,SHIFT),f)
    frames.append(g)
TRANSP=(152,208,160)
BLACK=(0,0,0)
CAGE_DARK=(48,48,56); CAGE_MID=(112,120,144); CAGE_LIGHT=(192,200,216); CAGE_HI=(232,232,248)
mon_cols=[(248,208,80),(200,160,64),(168,128,64),(112,80,56),(64,48,24),(232,216,176),(216,72,40),(168,128,216),(104,88,152),(56,48,88)]
palette=[TRANSP,CAGE_DARK,CAGE_MID,CAGE_LIGHT,CAGE_HI,BLACK]+mon_cols
assert len(palette)==16
def nearest(c,cands):
    return min(cands,key=lambda i:sum((a-b)**2 for a,b in zip(palette[i],c)))
monidx=[1,3,4]+list(range(5,16))
D,M,L,H=1,2,3,4
def cage_layer():
    c={}
    def put(x,y,v): c[(x,y)]=v
    T=0  # top offset
    # handle ring rows 0..3
    for x in range(14,18): put(x,0,D)
    put(13,1,D);put(18,1,D);put(14,1,H);put(17,1,M)
    for x in range(14,18): put(x,2,D) if x in (14,17) else None
    put(13,2,D);put(18,2,D);put(14,2,L);put(17,2,M)
    for x in range(14,18): put(x,3,D)
    put(15,4,D);put(16,4,D)
    # domed top plate rows 5..8
    for x in range(8,24): put(x,5,D)
    put(7,6,D);put(24,6,D)
    for x in range(8,24): put(x,6,H)
    for x in range(5,27): put(x,7,D)
    for x in range(6,26): put(x,7,L)
    put(7,7,L);put(24,7,L)
    for x in range(4,28): put(x,8,M)
    put(4,8,D);put(27,8,D)
    for x in range(4,28): put(x,9,D)
    # bottom base rows 28..31
    for x in range(3,29): put(x,28,D)
    for x in range(4,28): put(x,29,L)
    for x in range(4,28): put(x,30,M)
    put(3,29,D);put(28,29,D);put(3,30,D);put(28,30,D)
    for x in range(3,29): put(x,31,D)
    # vertical bars rows 10..27
    for y in range(10,28):
        put(4,y,D);put(5,y,L);put(26,y,M);put(27,y,D)
        for bx in BARS:
            put(bx,y,L)
    for bx in BARS:
        put(bx,10,H)
    return c
cage=cage_layer()
sheet=Image.new('P',(32,96),0)
sheet.putpalette([v for c in palette for v in c])
for i,f in enumerate(frames):
    for y in range(32):
        for x in range(32):
            v=0
            p=f.getpixel((x,y))
            if p[3]: v=nearest(p[:3],monidx)
            if (x,y) in cage: v=cage[(x,y)]
            sheet.putpixel((x,y+32*i),v)
sheet.save(out)
big=sheet.convert('RGB').resize((32*8,96*8),Image.NEAREST); big.save(out.replace('.png','_x8.png'))
print('saved',out)
