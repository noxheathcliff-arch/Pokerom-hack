"""Découpe le dessin fini (etape01..final, déjà dessiné à la main) en CALQUES (E2-E : une pièce = un calque).
Ne dessine rien : copie des pixels existants dans des fichiers séparés. usage: python3 extraire.py"""
import os
H,W=40,127
ETAPES={'01':'etape01_tf_silhouette','03':'etape03_tf_aplats','04':'etape04_tf_lumiere',
        '05':'etape05_tf_details','final':'etape_final_tf'}
D=os.path.dirname(os.path.abspath(__file__)); UI=os.path.dirname(D); P=os.path.join(D,'pieces')
def lire(f): return [l.rstrip('\n') for l in open(f) if not l.startswith('#') and l.strip()]
def ecrire(nom,g,note):
    open(os.path.join(P,nom),'w').write('# '+note+'\n'+'\n'.join(''.join(r) for r in g)+'\n')
MED=(52,74,0,16)          # boîte du médaillon x1 x2 y1 y2
for s,f in ETAPES.items():
    G=lire(os.path.join(UI,f+'.txt'))
    # rouleaux : colonnes 3..11 et 115..123, toutes les lignes
    ecrire(f'rouleauG_{s}.txt',[r[3:12] for r in G],'rouleau gauche, axe = colonne 4 du calque')
    ecrire(f'rouleauD_{s}.txt',[r[115:124] for r in G],'rouleau droit, axe = colonne 4 du calque')
    # bords de feuille (colonnes 12,13 | 113,114), lignes 8..32
    ecrire(f'bords_{s}.txt',[G[y][12]+G[y][13]+G[y][113]+G[y][114] for y in range(8,33)],'bords feuille G1 G2 D2 D1, lignes 8-32')
    # fond de feuille nue : gabarit de la colonne 40 (sans les filets 11-13 / 27-29) + fibres isolées gardées en place
    from collections import Counter
    T=[Counter(G[y][14:113]).most_common(1)[0][0] for y in range(H)]   # couleur dominante de la ligne
    for y in (11,12,13,27,28,29): T[y]=G[20][40]
    nu=[['.']*W for _ in range(H)]
    for y in range(8,33):
        for x in range(W): nu[y][x]=T[y]
    fib=0
    for y in range(10,30):
        for x in range(14,113):
            if G[y][x]=='P' and T[y]=='p':
                vois=[G[y+dy][x+dx] for dx in(-1,0,1) for dy in(-1,0,1) if dx or dy]
                if all(v in 'pPw' for v in vois): nu[y][x]='P'; fib+=1
    ecrire(f'feuille_{s}.txt',nu,'feuille nue (ouverte), fibres P isolées ancrées')
    # décor : ce qui diffère de la feuille nue, lignes 10-31, x 14-111, hors boîte médaillon
    dec=[['.']*W for _ in range(H)]
    for y in range(10,32):
        for x in range(14,112):
            dans=MED[0]<=x<=MED[1] and y<=MED[3]
            c=G[y][x]
            if dans:
                c=G[y][40] if y in (11,12,13) else nu[y][x]   # le filet passe SOUS le médaillon
            if c!=nu[y][x]: dec[y][x]=c
    ecrire(f'decor_{s}.txt',dec,'décor (cadre, coulure), plein format')
    # composition feuille+décor, pour trouver le médaillon et le pendentif
    comp=[r[:] for r in nu]
    for y in range(H):
        for x in range(W):
            if dec[y][x]!='.': comp[y][x]=dec[y][x]
    ecrire(f'medaillon_{s}.txt',[[G[y][x] if G[y][x]!=comp[y][x] else '.' for x in range(MED[0],MED[1]+1)] for y in range(MED[2],MED[3]+1)],'médaillon final, coin haut-gauche = (52,0)')
    ecrire(f'pendentif_{s}.txt',[[G[y][x] if G[y][x]!=comp[y][x] else '.' for x in range(58,69)] for y in range(32,36)],'pendentif, coin haut-gauche = (58,32)')
    print(s,'fibres',fib)
