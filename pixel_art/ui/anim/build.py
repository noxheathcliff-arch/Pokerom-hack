"""Construit UNE image de l'animation (règle E0-5 : une image à la fois, validée avant la suivante).
usage : python3 build.py N      (N = 1..21)
Pour l'image N : écrit les calques de chaque étape dans fNN/calques/, la feuille de commandes
fNN/cNN_0S.txt (stamp des calques), lance trace.py (01,03,04,05,final) et contour.py (02),
rend chaque étape avec px.py, fabrique fNN/bande_etapes.png et lance les contrôles E5-A."""
import sys, os, math, subprocess, json
from PIL import Image
D=os.path.dirname(os.path.abspath(__file__)); UI=os.path.dirname(D); PC=os.path.join(D,'pieces')
H,W=40,127
ETAPES=['01','03','04','05','final']
ORIG={'01':'etape01_tf_silhouette','02':'etape02_tf_contour','03':'etape03_tf_aplats',
      '04':'etape04_tf_lumiere','05':'etape05_tf_details','final':'etape_final_tf'}

# ---------- feuille de timing (copie exacte de ANIM_PLAN.md) ----------
#  n : (cxL, cxR, ms, décor, médaillon, pendentif, smear, éclat)
PLAN={
 1:(56,70,300,None,None, 0,False,None),
 2:(57,69,133,None,None, 0,False,None),
 3:(58,68,167,None,None, 0,False,None),
 4:(38,90, 50,None,None, 0,True ,None),
 5:(16,108,67,None,None, 0,False,None),
 6:( 4,120,83,None,None, 0,False,None),
 7:( 9,122,83,None,None,-1,False,None),
 8:( 7,118,100,None,None,1,False,None),
 9:( 7,119,117,None,None,0,False,None),
10:( 7,119,67,'demi',None,0,False,None),
11:( 7,119,83,'plein',None,0,False,None),
12:( 7,119,67,'plein','p12',0,False,None),
13:( 7,119,67,'plein','p13',0,False,None),
14:( 7,119,67,'plein','p14',0,False,None),
15:( 7,119,83,'plein','pic',0,False,None),
16:( 7,119,67,'plein','fin',0,False,1),
17:( 7,119,67,'plein','fin',0,False,3),
18:( 7,119,100,'plein','fin',0,False,5),
19:( 7,119,67,'plein','fin',0,False,3),
20:( 7,119,67,'plein','fin',0,False,1),
21:( 7,119,1000,'plein','fin',0,False,None),
}

def lire(f): return [list(l.rstrip('\n')) for l in open(f) if not l.startswith('#') and l.strip()]
def piece(nom,s): return lire(os.path.join(PC,f'{nom}_{s}.txt'))
def vide(): return [['.']*W for _ in range(H)]
def ecrire(f,g,note=None):
    open(f,'w').write(('# '+note+'\n' if note else '')+'\n'.join(''.join(r) for r in g)+'\n')
def coller(dst,src,ox=0,oy=0):
    for y,r in enumerate(src):
        for x,c in enumerate(r):
            if c!='.' and 0<=oy+y<H and 0<=ox+x<W: dst[oy+y][ox+x]=c
def vois4(g,x,y):
    for dx,dy in((1,0),(-1,0),(0,1),(0,-1)):
        X,Y=x+dx,y+dy
        yield g[Y][X] if 0<=X<W and 0<=Y<H else '.'

# ---------- calques ----------
def c_feuille(s,cxL,cxR):
    """papier visible entre les rouleaux : bords (copiés du dessin) + fond + fibres ancrées"""
    nu=piece('feuille',s); B=piece('bords',s); g=vide()
    for y in range(8,33):
        for x in range(cxL+7,cxR-6): g[y][x]=nu[y][x]
        b=B[y-8]
        g[y][cxL+5]=b[0]; g[y][cxL+6]=b[1]
        g[y][cxR-6]=b[2]; g[y][cxR-5]=b[3]
    return g

def c_decor(s,mode):
    g=vide()
    if mode is None: return g
    dec=piece('decor',s)
    for y in range(H):
        for x in range(W):
            if dec[y][x]!='.' and (mode=='plein' or abs(x-63)<=23): g[y][x]=dec[y][x]
    if mode=='demi':   # pointe du trait qui avance : plus claire (rampe lumineuse de l'encre fraîche)
        pointe={'01':None,'03':'g','04':'y','05':'w','final':'w'}[s]
        if pointe:
            for x in (40,86):
                for y in (12,28): g[y][x]=pointe
    return g

def c_pendentif(s,balance):
    """pièce rigide : on la redessine entière décalée sous sa bélière (pièces _m1/_p1 dessinées à la main)"""
    nom={0:s,-1:s+'_m1',1:s+'_p1'}[balance]
    p=piece('pendentif',nom); g=vide()
    for y,r in enumerate(p):
        for x,c in enumerate(r):
            if c!='.': g[32+y][58+x]=c
    return g

def ellipse(rx,ry,s,eteint,lueur):
    """médaillon pendant le pop (redessiné à chaque taille, jamais réduit par calcul)"""
    g=vide(); cx,cy=63,8
    def dans(x,y,a,b): return ((x-cx)/a)**2+((y-cy)/b)**2<=1.0
    gx,gy=rx*0.57,ry*0.57
    for y in range(H):
        for x in range(W):
            if not dans(x,y,rx,ry): continue
            if s=='01': g[y][x]='d'; continue
            gem=dans(x,y,gx,gy)
            a,b=(gx,gy) if gem else (rx,ry)
            bord=any(not dans(x+dx,y+dy,a,b) for dx,dy in((1,0),(-1,0),(0,1),(0,-1)))
            if bord: g[y][x]='O'; continue
            nx,ny=(x-cx)/a,(y-cy)/b; n=math.hypot(nx,ny) or 1
            l=(-nx-ny)/(n*math.sqrt(2))          # lumière en haut à gauche
            if gem:
                if s=='03': c='c'
                else: c='C' if l>0.3 else ('b' if l<-0.3 else 'c')
            else:
                if s=='03': c='g'
                else:
                    c='y' if l>0.3 else ('n' if l<-0.3 else 'g')
                    if s in('05','final') and l<-0.6: c='k'
            g[y][x]=c
    if s in('05','final'):   # un seul reflet z sur la gemme, côté lumière
        for y in range(H):
            for x in range(W):
                if g[y][x]=='C' and dans(x,y,gx,gy):
                    g[y][x]='z'; break
            else: continue
            break
    rampe={}
    if eteint: rampe={'c':'b','C':'c','z':'c'}
    elif lueur: rampe={'C':'c','z':'C'}
    if s=='03' and eteint: rampe={'c':'b'}
    for y in range(H):
        for x in range(W):
            if g[y][x] in rampe: g[y][x]=rampe[g[y][x]]
    return g

def c_medaillon(s,etat):
    if etat is None: return vide()
    if etat=='p12': return ellipse(3.5,3.5,s,True,False)
    if etat=='p13': return ellipse(8,8,s,True,False)
    if etat=='p14':                                  # E5-B : ailettes en bourgeon (évite l'apparition d'un coup en F15)
        g=ellipse(8.5,6.5,s,False,True)
        for x in(53,54,72,73):
            for y in(7,9): g[y][x]='d' if s=='01' else 'O'
        coeur={'01':'dd','02':'dd','03':'gg'}.get(s)
        for (x0,lum) in((53,'yn'),(72,'gn')):
            c=coeur or lum
            g[8][x0]=c[0]; g[8][x0+1]=c[1]
        return g
    g=vide(); coller(g,piece('medaillon',s),52,0)
    if etat=='pic' and s in('04','05','final'):     # pic lumineux : 1 cran plus clair que la pose finale
        r={'c':'C','C':'z','b':'c'}
        for y in range(0,17):
            for x in range(52,75):
                if g[y][x] in r: g[y][x]=r[g[y][x]]
    return g

def c_smear(s,cxL,cxR):
    """image étirée : traînée couleur de base, sans détail, côté centre (d'où vient le rouleau)"""
    g=vide()
    for cx,sens,L in((cxL,1,10),(cxR,-1,11)):
        for d in range(L):
            x=cx+sens*(5+d); t=d//3
            for y in range(6+t,35-t): g[y][x]='P'
        for d in range(4):
            x=cx+sens*(3+d)
            ys=(2,3,4) if d<2 else (3,)
            for y in ys: g[y][x]='g'; g[y+33][x]='g'
    if s=='01':
        for y in range(H):
            for x in range(W):
                if g[y][x]!='.': g[y][x]='d'
    return g

def c_eclat(s,taille):
    g=vide()
    if not taille: return g
    cx,cy=59,4; bras=taille//2
    g[cy][cx]='d' if s=='01' else ('w' if s=='03' else 'z')
    for k in range(1,bras+1):
        for x,y in((cx-k,cy),(cx+k,cy),(cx,cy-k),(cx,cy+k)):
            g[y][x]='d' if s=='01' else 'w'
    return g

def c_rouleau(cote,s,cx):
    g=vide(); coller(g,piece('rouleau'+cote,s),cx-4,0); return g

# ---------- une image ----------
def construire(n):
    cxL,cxR,ms,dec,med,bal,smear,ecl=PLAN[n]
    dossier=os.path.join(D,f'f{n:02d}'); cal=os.path.join(dossier,'calques'); os.makedirs(cal,exist_ok=True)
    sorties={}
    for s in ETAPES:
        calques=[('feuille',c_feuille(s,cxL,cxR)),('decor',c_decor(s,dec)),('pendentif',c_pendentif(s,bal)),
                 ('medaillon',c_medaillon(s,med))]
        if smear: calques.append(('smear',c_smear(s,cxL,cxR)))
        calques+= [('rouleauG',c_rouleau('G',s,cxL)),('rouleauD',c_rouleau('D',s,cxR))]
        if ecl: calques.append(('eclat',c_eclat(s,ecl)))
        cmd=[f'# image {n:02d} étape {s} : empilement des calques (ordre = profondeur)']
        for nom,g in calques:
            if all(c=='.' for r in g for c in r): continue
            f=os.path.join(cal,f'{nom}_{s}.txt'); ecrire(f,g)
            cmd.append(f'stamp {f} 0 0')
        if smear and s!='01':   # contour de la traînée : tout pixel de traînée qui touche le vide devient O
            cmd.append('# contour traînée : appliqué après empilement (voir build.py, contour_smear)')
        cf=os.path.join(dossier,f'c{n:02d}_{s}.txt')
        open(cf,'w').write('\n'.join(cmd)+'\n')
        out=os.path.join(dossier,f'etape{s}.txt' if s!='final' else 'final.txt')
        subprocess.run(['python3',os.path.join(UI,'trace.py'),f'NEW:{W}x{H}',out,cf],check=True)
        if smear and s!='01':
            g=lire(out); sm=dict(calques)['smear']; rl=[dict(calques)['rouleauG'],dict(calques)['rouleauD']]
            for y in range(H):
                for x in range(W):
                    if sm[y][x]!='.' and g[y][x]==sm[y][x] and all(r[y][x]=='.' for r in rl) and '.' in vois4(g,x,y):
                        g[y][x]='O'
            ecrire(out,g)
        sorties[s]=out
        if s=='01':
            o2=os.path.join(dossier,'etape02.txt')
            subprocess.run(['python3',os.path.join(UI,'contour.py'),out,o2],check=True)
            sorties['02']=o2
    # rendu
    pal=os.path.join(UI,'palette.json')
    for s in ['01','02','03','04','05','final']:
        subprocess.run(['python3',os.path.join(UI,'px.py'),sorties[s],'4',pal],check=True,capture_output=True)
    ims=[Image.open(sorties[s][:-4]+'.png') for s in ['01','02','03','04','05','final']]
    Z=3; bande=Image.new('RGBA',(W*Z+8,(H*Z+6)*6+2),(52,52,62,255))
    for i,im in enumerate(ims):
        fond=Image.new('RGBA',im.size,(235,230,220,255)); fond.alpha_composite(im)
        bande.alpha_composite(fond.resize((W*Z,H*Z),Image.NEAREST),(4,4+i*(H*Z+6)))
    bande.save(os.path.join(dossier,'bande_etapes.png'))
    return sorties,calques

# ---------- contrôles E5-A ----------
def controles(n,sorties):
    cxL,cxR,ms,dec,med,bal,smear,ecl=PLAN[n]
    pal=json.load(open(os.path.join(UI,'palette.json'))); ok=True; rap=[]
    G={s:lire(f) for s,f in sorties.items()}
    for s,g in G.items():
        inconnus={c for r in g for c in r if c!='.' and c not in pal}
        if inconnus: ok=False; rap.append(f'{s}: caractères inconnus {inconnus}')
        if len(g)!=H or any(len(r)!=W for r in g): ok=False; rap.append(f'{s}: taille fausse')
    ecl_cells=set()
    if ecl:
        e=c_eclat('final',ecl); ecl_cells={(x,y) for y in range(H) for x in range(W) if e[y][x]!='.'}
    # coins des poignées arrondis à l'étape 05 du dessin statique validé (8 px) : ils voyagent avec les rouleaux
    coins=set()
    for cote,cx in(('G',cxL),('D',cxR)):
        a,b=piece('rouleau'+cote,'01'),piece('rouleau'+cote,'final')
        for y in range(len(a)):
            for x in range(len(a[0])):
                if a[y][x]!='.' and b[y][x]=='.':
                    X,Y=cx-4+x,y; coins.add((X,Y))
                    for dx,dy in((1,0),(-1,0),(0,1),(0,-1)): coins.add((X+dx,Y+dy))
    for s in ['03','04','05','final']:
        trous=[(x,y) for y in range(H) for x in range(W) if G[s][y][x] not in '.O'
               and (x,y) not in ecl_cells and (x,y) not in coins and '.' in vois4(G[s],x,y)]
        if trous: ok=False; rap.append(f'{s}: contour ouvert en {trous[:6]} ({len(trous)})')
    # silhouette identique d'étape en étape (01 = forme de toutes les suivantes)
    m01={(x,y) for y in range(H) for x in range(W) if G['01'][y][x]!='.'}
    for s in ['02','03','04','05','final']:
        ms_={(x,y) for y in range(H) for x in range(W) if G[s][y][x]!='.'}
        if s in('05','final'): ms_|=coins & m01
        if ms_!=m01: ok=False; rap.append(f'{s}: silhouette ≠ étape 01 ({len(ms_^m01)} px)')
    # 02 = contour.py(01) et 03.. gardent les O de 02 sur le bord
    # volume des rouleaux (pièces rigides)
    for cote,cx in(('G',cxL),('D',cxR)):
        ref=sum(c!='.' for r in piece('rouleau'+cote,'final') for c in r)
        vu=sum(1 for y in range(H) for x in range(max(0,cx-4),min(W,cx+5)) if G['final'][y][x]!='.')
        rap.append(f'rouleau {cote}: {ref} px dans le calque, zone occupée {vu} px')
    # pas de jumelle de l'image précédente
    if n>1:
        prev=os.path.join(D,f'f{n-1:02d}','final.txt')
        if os.path.exists(prev) and lire(prev)==G['final']: ok=False; rap.append('final identique à l\'image précédente')
    if n==21:
        for s in ['01','02','03','04','05','final']:
            same=lire(os.path.join(UI,ORIG[s]+'.txt'))==G[s]
            if not same:
                ok=False; diff=[(x,y) for y in range(H) for x in range(W) if lire(os.path.join(UI,ORIG[s]+'.txt'))[y][x]!=G[s][y][x]]
                rap.append(f'{s}: ≠ dessin fini, {len(diff)} px ex {diff[:8]}')
            else: rap.append(f'{s}: = dessin fini (etape {ORIG[s]})')
    return ok,rap

if __name__=='__main__':
    n=int(sys.argv[1]); sorties,_=construire(n); ok,rap=controles(n,sorties)
    print(f'IMAGE {n:02d}', 'CONTRÔLES OK' if ok else 'ÉCHEC'); print('\n'.join('  '+r for r in rap))
    sys.exit(0 if ok else 1)
