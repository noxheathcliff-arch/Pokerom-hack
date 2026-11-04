"""Step 11 control sheet (render only): x1, x2, enlarged, light/dark background, mirror, silhouette, grey, inventory slot."""
import sys
from PIL import Image, ImageOps, ImageDraw
src=sys.argv[1]; out=sys.argv[2]
im=Image.open(src).convert('RGBA'); w,h=im.size
def on(bg,img,pad=4):
    t=Image.new('RGBA',(img.width+2*pad,img.height+2*pad),bg+(255,)); t.alpha_composite(img,(pad,pad)); return t
def up(img,z): return img.resize((img.width*z,img.height*z),Image.NEAREST)
sil=Image.new('RGBA',im.size,(0,0,0,0)); sil.paste((0,0,0,255),mask=im.split()[3])
grey=ImageOps.grayscale(im.convert('RGB')).convert('RGBA'); grey.putalpha(im.split()[3])
mir=ImageOps.mirror(im)
# inventory slot (GBA-style bag: light background, rounded frame)
slot=Image.new('RGBA',(w+8,h+8),(248,240,216,255)); d=ImageDraw.Draw(slot)
d.rectangle([0,0,w+7,h+7],outline=(120,96,72,255)); slot.alpha_composite(im,(4,4))
Z=max(2,256//h)
tiles=[up(on((235,230,220),im),Z), up(on((30,30,40),im),Z)]
small=[on((235,230,220),im),on((30,30,40),im),up(on((235,230,220),im),2),up(on((30,30,40),im),2),
       up(on((235,230,220),mir),2),up(on((200,200,200),sil),2),up(on((128,128,128),grey),2),up(slot,2)]
W=sum(t.width for t in tiles)+30+max(s.width for s in small)*4+40
H=max(tiles[0].height, sum(s.height for s in small[:4])+40, sum(s.height for s in small[4:])+40)+20
sheet=Image.new('RGBA',(W,max(H,tiles[0].height+20)),(52,52,62,255))
x=10
for t in tiles: sheet.alpha_composite(t,(x,10)); x+=t.width+10
cols=[small[0:2]+small[2:4],small[4:8]]
for ci,col in enumerate(cols):
    y=10
    for s in col: sheet.alpha_composite(s,(x,y)); y+=s.height+8
    x+=max(s.width for s in col)+12
sheet.save(out); print(out,sheet.size)
