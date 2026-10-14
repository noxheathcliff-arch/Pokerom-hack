# -*- coding: utf-8 -*-
"""Pokemon Confluence - modele papier des systemes caches (brief C).
Usage :
  python3 -I cf_model.py --check            # regles du registre (gain/perte, lecteurs, comptes)
  python3 -I cf_model.py --sim N            # N parties aleatoires : cumul, Sommet, fins, temoins
  python3 -I cf_model.py --golden           # recherche locale du 'chemin dore'
  python3 -I cf_model.py --render           # regenere DECISION_LEDGER_*.md (tables par decision)
Ce modele est une HYPOTHESE de calibrage (porte prototype) : il ne remplace pas un test sur ROM.
"""
import sys, os, random, copy, json, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from cf_decisions import DECISIONS

REL = ['BR', 'BL', 'FL', 'PR', 'PE', 'AM', 'TI', 'GI', 'HO']
REP = ['rL', 'rC', 'rM', 'rA', 'rI', 'rG', 'rP']
GLOB = ['PA', 'RK']
ALLV = REL + REP + GLOB
START = {k: 50 for k in REL + REP}; START.update(HO=20, PA=20, RK=20)
BAD_UP = {'PA', 'RK'}
ZONES = ['Z01', 'Z02', 'Z03', 'Z04', 'Z05', 'Z06']
ENV, MIX, RES, ABA = 0, 1, 2, 3
INCOME = {0: 0, 1: 2500, 2: 3000, 3: 4500, 4: 5500, 5: 5000, 6: 6500, 7: 4000, 8: 7500,
          9: 8500, 10: 8000, 11: 5000, 12: 7000, 13: 3000, 14: 12000, 15: 15000}
OPTIONAL_PIECES = ['DOS_JOURNAL_NOEUD', 'DOS_CLOCHETTE_PIKO', 'DOS_AFFICHE_SYLPHE', 'DOS_HORAIRE_R116',
                   'DOS_ECLATS', 'DOS_SCHEMA_CABLE', 'DOS_TRACE_ANNEAU', 'DOS_CARNET_PRIMES', 'DOS_JOURNAUX',
                   'DOS_ETOILES', 'DOS_SCEAUX_ANCIENS', 'DOS_HORAIRE_VENDU', 'DOS_LAMBDA',
                   'DOS_DONNEES_INSTITUT', 'DOS_VISION', 'DOS_ARTICLE_CHEN', 'DOS_PLAN_CABLE',
                   'OBJ_LETTRE_FERRAND', 'DOS_VOIX_RELAIS']
MANDATORY_PIECES = ['DOS_PREDICTEUR', 'DOS_BATTEMENT', 'DOS_INSCRIPTION', 'DOS_REGISTRE', 'DOS_GARDIENNE']
HIDDEN_MIN = 12
BYID = {d['id']: d for d in DECISIONS}

def new_state():
    return dict(v=dict(START), N=0, eco={z: ENV for z in ZONES}, flags=set(), choice={}, val={},
                bv={'P': 0, 'A': 0, 'C': 0}, money=3000, kiosk=0, log=[], hidden=False)

def clamp(x, lo=0, hi=100): return max(lo, min(hi, x))
def add(s, k, dv):
    if k == 'N': s['N'] = clamp(s['N'] + dv, 0, 3)
    else: s['v'][k] = clamp(s['v'][k] + dv)
def has(s, f): return f in s['flags']
def bv_lead(s):
    b = s['bv']
    # egalite : COMPRENDRE > ACCUEILLIR > PROTEGER (defaut scientifique de Brice)
    return max(['C', 'A', 'P'], key=lambda k: (b[k], {'C': 2, 'A': 1, 'P': 0}[k]))
def ecostep(s, z):
    e = s['eco'][z]; s['eco'][z] = {ENV: MIX, MIX: RES, RES: RES, ABA: MIX}[e]
def npieces(s): return sum(1 for p in OPTIONAL_PIECES if p in s['flags'])

def allowed(s, d):
    out = []
    for i, o in enumerate(d['opts']):
        if o['req'] and not o['req'](s): continue
        if d['id'] == 'D066':
            if s['v']['HO'] >= 40 and o['code'] == 'c': continue
            if s['v']['HO'] < 40 and o['code'] != 'c': continue
        if d['id'] == 'D051' and o['code'] == 'a' and not has(s, 'DOS_JOURNAUX'): continue
        if d['id'] == 'D118' and o['code'] == 'a' and not (s['val'].get('custody') == 'RED' and s['val'].get('loc') != 'R'): continue
        m = o['fx'].get('money')
        if isinstance(m, int) and m < 0 and s['money'] < -m: continue  # v3.2 : achat borne par l'argent (S10)
        out.append(i)
    return out

def apply(s, d, i):
    o = d['opts'][i]; s['choice'][d['id']] = i + 1
    for k, dv in o['d'].items():
        if d['id'] == 'D099' and k == 'HO' and o['code'] == 'a' and s['v']['HO'] < 40: dv = -5
        add(s, k, dv)
    fx = o['fx']
    for f in fx.get('set', []): s['flags'].add(f)
    for k, v in fx.get('val', {}).items(): s['val'][k] = v
    if 'eco' in fx: s['eco'][fx['eco'][0]] = fx['eco'][1]
    if 'ecostep' in fx: ecostep(s, fx['ecostep'])
    if 'bv' in fx: s['bv'][fx['bv']] += 1
    if fx.get('bvdemo'):
        dm = s['choice'].get('D054', 0)
        if dm: s['bv'][{1: 'P', 2: 'A', 3: 'C'}[dm]] += 1
    if fx.get('bvlead'): s['bv'][bv_lead(s)] += 1
    if 'N' in fx:
        n = fx['N']
        if isinstance(n, int): s['N'] = n
        else: add(s, 'N', int(n))
    if 'custody' in fx: s['val']['custody'] = fx['custody']
    m = fx.get('money')
    if isinstance(m, int): s['money'] += m
    if fx.get('pub'):
        if bv_lead(s) in ('A', 'C'):
            s['flags'].add('BRICE_PUBLIE'); add(s, 'PA', -5); add(s, 'rC', -3)
        else:
            add(s, 'rL', 5)
    if 'vote' in fx:
        bob_yes = not has(s, 'BOB_QUARTIER'); rox = s['choice'].get('D016') == 1
        if fx['vote'] == 'show': passed = bob_yes
        elif fx['vote'] == 'stay': passed = bob_yes or rox
        else:
            if s['v']['BR'] >= 55: rox = False
            passed = bob_yes or rox
        if not passed and has(s, 'FERMIER_TEMOIN') and fx['vote'] != 'show': passed = True  # v3.2 : D039 b
        if passed: s['flags'].add('VOTE_ABATTAGE')
    if d['id'] == 'D082' and o['code'] == 'a' and not has(s, 'INFO_ENTREPOT'):
        s['flags'].discard('OBJ_LETTRE_FERRAND')
    if 'defend' in fx: s['val']['def%d' % fx['defend'][0]] = fx['defend'][1]
    if fx.get('phrase'): s['flags'].add('PHRASE_SOMMET')
    if fx.get('appel'): s['flags'].add('APPEL_NOMINAL')
    if fx.get('chen'): s['val']['CHEN'] = 'AVOUE' if has(s, 'CHEN_CONFRONTE') else 'NIE'
    if fx.get('prb'):
        if has(s, 'MARC_SAGES'): s['val']['PR_B'] = 'SCE'
        elif has(s, 'DOS_VOIX_RELAIS') and s['v']['PR'] >= 60: s['val']['PR_B'] = 'LIB'
        else: s['val']['PR_B'] = 'CTL'
    for k in ('loc', 'intent', 'ama', 'flora', 'ray', 'post'):
        if k in fx: s['val'][k] = fx[k]
    if fx.get('hoopa_to_relay'): s['flags'].add('HOOPA_CONFIE')
    if fx.get('lend'): s['flags'].add('PRET_CIVILS')

# ----------------------------------------------------------------- evenements automatiques
def chapter_events(s, c):
    v = s['v']
    if c in (1, 3, 5, 7, 9, 11):
        add(s, 'RK', 4 + (3 if S(s, 'rP') < -5 else 0) - (2 if S(s, 'rP') >= 10 else 0))
    if c == 3:
        s['val']['FK'] = 1
        if s['choice'].get('D023') == 1: add(s, 'RK', 1)
    if c == 4:
        s['flags'].add('DOS_PREDICTEUR')
        if s['choice'].get('D030') == 2: s['flags'].add('EXP_SHARE')
    if c == 5: add(s, 'PA', 5)
    if c == 7:
        s['flags'].add('DOS_BATTEMENT')
        if s['choice'].get('D042') == 1: add(s, 'PA', 1)
        if s['choice'].get('D063') == 1:  # Vergazon sans Red
            if v['TI'] >= 55 and v['FL'] >= 55: s['flags'].add('TIMMY_SAUVE')
            else: add(s, 'TI', -5)
        if s['choice'].get('D054') == 3: s['flags'].add('STANCE_MAX_ECOUTE')
    if c == 8:
        add(s, 'PA', 5)
        if has(s, 'VOTE_ABATTAGE'): add(s, 'RK', 3)
    if c == 9: s['flags'].add('DOS_INSCRIPTION')
    if c == 10:
        s['flags'].add('DOS_REGISTRE'); add(s, 'PA', 5)
        if s['val'].get('KOGA') != 'DEMASQUE' and (has(s, 'JEANNINE_ALLIEE') or has(s, 'KOGA_AVEU') or has(s, 'DOS_CARNET_PRIMES')):
            s['val']['KOGA'] = 'DEMASQUE'
        s['val'].setdefault('PR_B', 'CTL')
        if v['PA'] >= 40: add(s, 'AM', 4); s['flags'].add('AMA_DOUTE')  # v3.2 N26 : anomalie qui blesse Aster
    if c == 12:
        s['flags'].add('DOS_GARDIENNE')
        # positions derivees avant le vote
        kanto = sum(1 for p in ('DOS_ARTICLE_CHEN', 'DOS_REGISTRE', 'DOS_JOURNAL_NOEUD', 'DOS_AFFICHE_SYLPHE') if p in s['flags'])
        if kanto >= 2 and (has(s, 'PETER_RESPECT') or v['PE'] >= 60): s['flags'].add('PETER_ASSUME')
        if v['PR'] >= 55 and has(s, 'PR_PREUVE'): s['flags'].add('PR_ACCUSE')
        if v['BL'] >= 60 and s['choice'].get('D083') == 1: s['flags'].add('BLUE_LIBRE')

def kiosk(s, c, rng, policy):
    if c < 3 or c > 12: return
    n = policy(c, rng)
    for _ in range(min(n, 2)):
        price = 1000 + 500 * c
        if s['money'] < price: break  # v3.2 : borne par l'argent
        s['money'] -= price; add(s, 'PA', 2); add(s, 'rC', 1); add(s, 'rP', -1); s['kiosk'] += 1

# ----------------------------------------------------------------- Sommet
LOCKS = {'NOR': {2: {2, 3}}, 'ART': {1: {2}, 2: {1}}, 'SEK': {2: {2, 3}}, 'ROC': {2: {1}, 3: {2}},
         'DOY': {2: {3}}, 'MAX': {1: {3}}}
VOTERS = ['NOR', 'PRO', 'PET', 'ROC', 'MAX', 'ART', 'DOY', 'COM', 'BRI', 'SEK']

def S(s, k):
    # position relative d'une faction : rX - moyenne des 7 reputations (somme nulle par construction)
    return s['v'][k] - sum(s['v'][r] for r in REP) / 7.0

def nzones(s, states): return sum(1 for z in ZONES if s['eco'][z] in states)

def base_votes(s, m):
    v, f, val = s['v'], s['flags'], s['val']; bv = bv_lead(s); out = {}
    cut = 'CABLE_COUPE' in f
    if m == 1:  # v3.2 : M1 = 1 FERMER / 2 CHARTE (LIBERER retire : appel nominal)
        out['NOR'] = 1 if v['rL'] >= v['rC'] else 2
        out['PRO'] = 1 if val.get('PR_B', 'CTL') in ('SCE', 'LIB') else 2
        out['PET'] = 1
        out['ROC'] = 1 if 'PR_ACCUSE' in f else 2
        out['MAX'] = 1 if ('STANCE_MAX_ECOUTE' in f or 'REL_AUGUSTE_FUJI' in f) else (2 if v['rM'] >= v['rA'] else 1)
        out['ART'] = None if (cut or 'SARAH_TEMOIN' in f) else 1
        out['DOY'] = 1
        out['COM'] = 1 if v['rP'] >= v['rC'] + 5 else 2
        out['BRI'] = {'P': 1, 'A': 1, 'C': 2}[bv]
    elif m == 2:
        out['NOR'] = None if ('FLORA_DOUTE' in f and v['FL'] >= 60) else 1
        out['PRO'] = 2
        out['PET'] = 2 if 'PETER_ASSUME' in f else 1
        out['ROC'] = 3
        out['MAX'] = 3 if S(s, 'rC') >= 5 else 1
        out['ART'] = None if (cut or 'SARAH_TEMOIN' in f) else 2
        out['DOY'] = 1 if S(s, 'rG') >= 10 else None
        out['BRI'] = {'P': 1, 'A': 2, 'C': (2 if nzones(s, (RES, MIX)) >= 3 else 1)}[bv]
        if v['rC'] > v['rP']: out['COM'] = 3
        elif nzones(s, (ENV, ABA)) >= 4: out['COM'] = 1
        else: out['COM'] = 2
        if 'BRICE_PARLE' in f: out['COM'] = out['BRI']
    else:
        out['NOR'] = 1
        out['PRO'] = 2 if 'PR_ACCUSE' in f else 1
        out['PET'] = 3 if 'PETER_ASSUME' in f else 2
        out['ROC'] = 3 if val.get('SYLPHE') == 'CONF' else 1
        out['MAX'] = 2
        out['ART'] = None if cut else 3
        out['DOY'] = 3 if S(s, 'rG') >= 0 else None
        out['COM'] = 1 if ('PETITION' in f or S(s, 'rI') < -5) else 3
        out['BRI'] = 3 if npieces(s) >= 8 else 2
        if 'BRICE_DEFERE' in f and val.get('def3'): out['BRI'] = val['def3']
    if not seko_cede(s):  # v3.2 N14 : Seko garde son siege ; Brice parle seulement
        out['SEK'] = {1: 1, 2: 1, 3: 2}[m]; out.pop('BRI', None)
    return out

def seko_cede(s):
    c = s['choice']; sc = 0
    sc += 1 if c.get('D030') == 2 else 0          # donnees confiees a Seko
    sc += 1 if c.get('D005') == 1 else 0          # lettre de Chen montree
    sc += 1 if (c.get('D067') == 1 or 'DINER_APAISE' in s['flags']) else 0
    return sc >= 2

def piece_for(s, m, x):
    f = s['flags']; e = s['eco']
    if m == 1:
        return {1: ('DOS_VISION' in f or 'DOS_DONNEES_INSTITUT' in f),
                2: ('DOS_JOURNAUX' in f or 'DOS_SCHEMA_CABLE' in f),
                3: False}[x]
    if m == 2:
        return {1: ('BRICE_PUBLIE' in f and nzones(s, (ENV,)) >= 2),
                2: ('TIMMY_SAUVE' in f or 'OLGA_LOKHLASS' in f or nzones(s, (RES,)) >= 2),
                3: ('DOS_SCHEMA_CABLE' in f or S(s, 'rC') >= 5)}[x]
    return {1: ('DOS_ARTICLE_CHEN' in f or 'DOS_JOURNAL_NOEUD' in f),
            2: ('DOS_ECLATS' in f),
            3: ('DOS_AFFICHE_SYLPHE' in f)}[x]

R4_NEED = 3
def r4_sources(s):
    f, val = s['flags'], s['val']
    n = 1  # inscription (toujours)
    if s['choice'].get('D097') == 1 or 'PR_ACCUSE' in f: n += 1
    if 'GIO_TEMOIN' in f or val.get('SYLPHE') == 'CONF': n += 1
    return n

def summit(s, rng=None):
    res = {}; detail = {}
    translate = s['v']['BR'] >= 50 or s['N'] >= 2
    for m in (1, 2, 3):
        votes = base_votes(s, m)
        x = s['val'].get('def%d' % m)
        conv = []
        flips = 0
        if x and translate and piece_for(s, m, x): flips = 1
        if m == 3 and 'PHRASE_SOMMET' in s['flags'] and x: flips += 1
        for vt in VOTERS:
            if flips <= 0: break
            if vt == 'BRI': continue
            if votes.get(vt) == x: continue
            if x in LOCKS.get(vt, {}).get(m, set()): continue
            votes[vt] = x; conv.append(vt); flips -= 1
        if m == 3 and r4_sources(s) >= R4_NEED: votes['JUAN'] = 3
        tally = collections.Counter(v for v in votes.values() if v)
        best = max(tally.values()) if tally else 0
        tied = sorted(k for k, n in tally.items() if n == best)
        if len(tied) == 1: r = tied[0]
        elif x in tied and (conv or s['N'] >= 2 or s['v']['BR'] >= 60): r = x
        else: r = max(tied) if r4_sources(s) >= 2 else tied[0]  # v3.2 S8 : Juan departage
        res[m] = r; detail[m] = (dict(votes), conv, dict(tally))
    s['val']['M1'], s['val']['M2'], s['val']['M3'] = res[1], res[2], res[3]
    if 'APPEL_NOMINAL' in s['flags']:
        for who in standers(s): s['flags'].add('DEBOUT_' + who); add(s, 'HO', 3)
    # consequences
    add(s, 'PA', {1: -15, 2: -8}[res[1]])
    if res[3] == 1: s['val']['FK'] = 0; add(s, 'rI', -5)
    elif res[3] == 2: s['val']['FK'] = 2; add(s, 'rC', -3)
    else: s['val']['FK'] = 2 if S(s, 'rI') >= 0 else 1
    return detail

def standers(s):
    v, f, val = s['v'], s['flags'], s['val']; out = []
    if val.get('PR_B') == 'LIB' or (v['PR'] >= 65 and 'DOS_VOIX_RELAIS' in f): out.append('PRO')
    if 'PETER_ASSUME' in f: out.append('PET')
    if v['rA'] >= v['rM'] and 'CABLE_COUPE' not in f: out.append('ART')
    if v['HO'] >= 60 and S(s, 'rG') >= 0: out.append('DOY')
    if bv_lead(s) == 'A': out.append('BRI')
    return out[:3]

def ch13_slide(s):
    m2 = s['val']['M2']
    for z in ZONES:
        e = s['eco'][z]
        if m2 == 1 and e == MIX: s['eco'][z] = ABA
        elif m2 == 2 and e in (ENV, ABA): s['eco'][z] = MIX

# ----------------------------------------------------------------- climax
def allies(s):
    v, f, val = s['v'], s['flags'], s['val']; A = {}
    br_rel = 'DUO_BRICE' in f or bv_lead(s) == 'C'
    A['BRICE'] = {'C'} | ({'R'} if (br_rel and v['BR'] >= 30) else set())
    if v['PE'] >= 50 or 'PETER_ASSUME' in f: A['PETER'] = {'R', 'P'}
    if v['PR'] >= 50: A['PR'] = {'R', 'P', 'C'}
    if 'FLORA_DESOBEIT' in f: A['FLORA'] = {'C'}
    if v['BL'] >= 55: A['BLUE'] = {'R', 'P'}
    if S(s, 'rG') >= 3: A['DOYENNE'] = {'P'}
    if 'REL_AUGUSTE_FUJI' in f or 'LEO_INSIDER' in f: A['FUJI'] = {'R'}
    if 'BOB_QUARTIER' in f or 'BOB_RESPECT' in f or S(s, 'rI') >= 5: A['BOB'] = {'C', 'R'}
    if 'DAMIEN_INDIC' in f: A['DAMIEN'] = {'C'}
    if 'JEANNINE_ALLIEE' in f or val.get('KOGA') == 'DEMASQUE': A['KOGA'] = {'R'}
    if 'LEO_INSIDER' in f and S(s, 'rC') >= -5: A['LEO'] = {'R'}
    if 'MORGANE_ALLIEE' in f: A['MORGANE'] = {'C'}
    if val.get('ARTHUR') == 'NEGOCIE' and S(s, 'rA') >= 0: A['AQUA'] = {'C'}
    if 'STANCE_MAX_ECOUTE' in f and S(s, 'rM') >= 0: A['MAGMA'] = {'C'}
    return A

def ally_intent(s, a):
    val, f, v = s['val'], s['flags'], s['v']
    if a == 'BRICE': return {'P': 'SCEAU', 'A': 'PACTE', 'C': 'PASSERELLE'}[bv_lead(s)]
    if a == 'PETER': return 'PACTE' if 'DEBOUT_PET' in f else 'SCEAU'
    if a == 'KOGA': return 'SCEAU'
    if a == 'BOB': return 'JUGEMENT'
    if a == 'PR': return 'PACTE' if 'DEBOUT_PRO' in f else {1: 'SCEAU', 2: 'PASSERELLE'}[val['M1']]
    if a == 'BLUE': return {1: 'SCEAU', 2: 'PASSERELLE'}.get(val.get('def1'), 'PACTE' if 'APPEL_NOMINAL' in f else 'SCEAU')
    if a == 'FUJI': return 'PACTE' if ('FUJI_ATTEND' in f and v['HO'] >= 40) else 'BRISER'
    if a == 'LEO': return 'PASSERELLE'
    return 'NONE'

def flora_decides(s):
    v, f = s['v'], s['flags']; fl = s['val'].get('flora')
    if fl == 'brice': ok = v['FL'] >= 55 and v['BR'] >= 50
    else: ok = v['FL'] >= 60 or 'FLORA_DOUTE' in f
    if ok: f.add('FLORA_DESOBEIT')

def climax(s, rng, assign=None):
    v, f, val = s['v'], s['flags'], s['val']
    A = allies(s); loc = val['loc']; others = [x for x in 'RPC' if x != loc]
    held = {}
    if assign is None:
        used = set()
        for L in others:
            cand = [a for a, comp in A.items() if L in comp and a not in used]
            if cand:
                a = rng.choice(cand); held[L] = a; used.add(a)
    else:
        held = {L: a for L, a in assign.items() if a and L != loc}
    val['held'] = held
    pilier_held = loc == 'P' or 'P' in held
    rk_lim = 80 if 'COPIE_REPRISE' in f else 70
    ra = held.get('R')
    rt = loc == 'R' or (ra is not None and (v['RK'] < rk_lim or ra in ('PETER', 'PR', 'BLUE')))
    if not pilier_held and loc != 'R': rt = False
    th = -5 - (5 if 'RITE_PREPARE' in f else 0) - (5 if 'FRAGMENT_DOYENNE' in f else 0)
    rite = held.get('P') == 'DOYENNE' or (loc == 'P' and val.get('ray') == 'rite' and S(s, 'rG') >= th)
    tc = loc == 'C' or 'C' in held
    if loc == 'R': intent, giver = val.get('intent', 'NONE'), 'RED'
    elif ra: intent, giver = ally_intent(s, ra), ra
    else: intent, giver = 'NONE', None
    cus = val.get('custody')
    hoopa = ((cus == 'RED' and (loc == 'R' or 'HOOPA_CONFIE' in f)) or
             (cus == 'MISSION' and ra in ('PETER', 'KOGA')) or
             (cus == 'LIBRE' and v['HO'] >= 70))
    ho_need = 70 if giver == 'RED' else 80
    variant = ''
    # v3.2 : chaque intention a sa version reussie et sa version payee ; F4 est une fin CHOISIE (JUGEMENT)
    if intent == 'JUGEMENT': F, variant = 'F4', 'CHOISI'
    elif rt and intent == 'PACTE':
        if hoopa and v['HO'] >= ho_need: F = 'F2'
        elif hoopa: F, variant = 'F5', 'PACTE_REFUSE'
        else: F, variant = 'F4', 'SANS_HOOPA'
    elif rt and intent == 'SCEAU':
        F = 'F1'
        if not (rite and tc and pilier_held): variant = 'SCEAU_BRISE'
    elif rt and intent == 'PASSERELLE':
        F = 'F3'
        if not (S(s, 'rC') >= 0 and S(s, 'rL') >= -5 and v['PA'] < 50): variant = 'PASSERELLE_AMPUTEE'
    elif intent == 'BRISER': F = 'F5'
    elif not rt: F, variant = ('F4', 'RED_AU_PILIER') if loc == 'P' else ('F5', 'RELAIS_PERDU')   # aucune intention portee : la fin depend du lieu de Red
    else: F, variant = 'F4', 'SANS_INTENTION'
    val['Fvar'] = variant
    # casualties
    if loc == 'C': cas = 'AUCUN'
    elif tc and ('CIVILS_PREPARES' in f or 'PRET_CIVILS' in f or held.get('C') in ('PR', 'BOB')): cas = 'BLESSES'
    elif tc: cas = 'BLESSES' if v['PA'] < 40 else 'PERTES'
    else: cas = 'PERTES'
    if F == 'F2' and giver != 'RED' and cas == 'AUCUN': cas = 'BLESSES'  # v3.2 S3 : anneau sur la place
    if variant == 'SCEAU_BRISE' and cas == 'AUCUN': cas = 'BLESSES'
    # Amaryllis
    if loc == 'P' and val.get('ama') == 'show' and v['AM'] >= 55: ama = 'RENONCE'
    elif loc != 'P' and 'OBJET_GARDIENNE_DONNE' in f and 'AMA_DOUTE' in f and held.get('P') in ('PETER', 'DOYENNE', 'BLUE', 'PR') and v['AM'] >= 55: ama = 'RENONCE'  # porteur
    elif loc != 'P' and v['AM'] < 55 and not rite and v['PA'] >= 30: ama = 'SACRIFICE'
    else: ama = 'PERSISTE'
    if v['RK'] >= 60: rk = 'FORTE'
    elif (loc == 'R' and v['RK'] <= 35 or v['RK'] <= 20) and (S(s, 'rL') >= 0 or S(s, 'rI') >= 0): rk = 'DEMANTELEE'
    else: rk = 'AFFAIBLIE'
    val.update(F=F, cas=cas, ama_issue=ama, rocket=rk, rt=rt, rite=rite, tc=tc, hoopa=hoopa)
    return F

def social(s):
    m2 = s['val']['M2']; vs = {1: 'REMPART', 2: 'INTEGRATION', 3: 'MARCHE'}[m2]
    if vs == 'INTEGRATION' and nzones(s, (ABA,)) >= 3: vs = 'REMPART'
    if vs == 'REMPART' and nzones(s, (RES,)) >= (2 if 'CIVILS_CENTRE' in s['flags'] else 3): vs = 'INTEGRATION'
    return vs

def finish(s):
    f = s['flags']
    if s['val'].get('CHEN') == 'AVOUE' and ('CREDIT_PARTAGE' in f or ('DINER_APAISE' in f and 'CHEN_LETTRE_MONTREE' not in f)):
        f.add('REL_CHEN_SEKO')
    if s['val'].get('CHEN') == 'AVOUE' and npieces(s) >= HIDDEN_MIN: s['hidden'] = True
    s['val']['VS'] = social(s)
    s['val']['MAITRE'] = 'MARC' if (s['val']['F'] == 'F2' or ('PR_ACCUSE' in s['flags'] and s['val']['M3'] == 2)) else 'PIERRE_ROCHARD'

# ----------------------------------------------------------------- partie complete
def play(rng, chooser=None, kiosk_policy=None, trace=None):
    s = new_state(); snaps = {}
    chooser = chooser or (lambda s, d, opts, rng: rng.choice(opts))
    kiosk_policy = kiosk_policy or (lambda c, rng: rng.choice([0, 0, 1, 2]))
    for c in range(0, 16):
        if c == 13:
            flora_decides(s)
        for d in [d for d in DECISIONS if d['ch'] == c]:
            if c == 13 and d['id'] in ('D117', 'D118', 'D119', 'D120', 'D121', 'D122') and 'loc' not in s['val']:
                pass
            if d['when'] and not d['when'](s): continue
            if d['id'] == 'D122':
                pass
            opts = allowed(s, d)
            if not opts: continue
            i = chooser(s, d, opts, rng)
            apply(s, d, i)
            if d['id'] == 'D116' and False: pass
        s['money'] += INCOME.get(c, 0) * 0.6
        kiosk(s, c, rng, kiosk_policy)
        chapter_events(s, c)
        if c == 12: s['summit'] = summit(s)
        if c == 13:
            flora_decides(s); ch13_slide(s); climax(s, rng)
            finish(s)
        snaps[c] = dict(s['v'], N=s['N'], money=s['money'])
    s['snaps'] = snaps
    return s

# ----------------------------------------------------------------- verifications
SYS_FAMILY = {k: 'Relations' for k in REL}; SYS_FAMILY.update({k: 'Reputations' for k in REP}); SYS_FAMILY.update(PA='Anneaux', RK='Rocket')

def option_gain_loss(o):
    g, l = set(), set()
    for k, dv in o['d'].items():
        if dv == 0: continue
        good = (dv < 0) if k in BAD_UP else (dv > 0)
        (g if good else l).add(k)
    fx = o['fx']
    if fx.get('gain'): g.add('+' + fx['gain'])
    if fx.get('loss'): l.add('-' + fx['loss'])
    if fx.get('lose_mon'): l.add('Equipe')
    if isinstance(fx.get('money'), int): (g if fx['money'] > 0 else l).add('Argent')
    if fx.get('item'): l.add('Objets')
    for f_ in fx.get('set', []):
        if f_.startswith('DOS_') or f_.startswith('OBJ_'): g.add('Dossier')
    if 'eco' in fx: (g if fx['eco'][1] == RES else l if fx['eco'][1] in (ENV, ABA) else g).add('Ecosysteme')
    if 'ecostep' in fx: g.add('Ecosysteme')
    if 'custody' in fx: g.add('Hoopa (garde)')
    return g, l

def check(verbose=True):
    issues = []; c = collections.Counter()
    for d in DECISIONS:
        c['listed'] += 1; c['type_' + d['t']] += 1; c['cls_' + d['c']] += 1; c['delay_' + d['delay']] += 1
        if d['verdict'][0] == 'V': c['robust'] += 1
        if not d['reads']: issues.append((d['id'], 'aucun lecteur'))
        if d['c'] in ('M', 'L') and not d['mem'] and d['verdict'][0] == 'V':
            c['ML_sans_signal'] += 1
        for o in d['opts']:
            if d['id'] in ('D004',): continue
            g, l = option_gain_loss(o)
            if not g or not l or (g == l and len(g) == 1):
                issues.append((d['id'] + o['code'], 'gain/perte manquant g=%s l=%s' % (sorted(g), sorted(l))))
            for k, dv in o['d'].items():
                lim = {'S': 5, 'M': 8, 'L': 10}[d['c']]
                if abs(dv) > lim: issues.append((d['id'] + o['code'], 'delta %s%+d > %d' % (k, dv, lim)))
    if verbose:
        print('COMPTES', dict(c))
        for i in issues: print('  ISSUE', i)
    return c, issues

# ----------------------------------------------------------------- personas (temoins)
PERSONAS = {
 'HOOPA': {'HO': 3, 'rA': 1, 'BR': 0.5}, 'CONSORTIUM': {'rC': 3, 'rL': 1, 'PA': -2}, 'GARDIENS': {'rG': 3, 'AM': 1, 'PE': 0.5},
 'REMPART': {'rL': 3, 'rP': 1, 'FL': 1}, 'AQUA': {'rA': 3, 'HO': 1, 'TI': 1}, 'MISSION': {'rI': 3, 'PE': 1, 'BL': 1},
 'RELATIONS': {k: 1 for k in REL}, 'ANTIROCKET': {'RK': -3, 'rP': 1}, 'ALEA': {}}
CLIMAX_PREF = {'HOOPA': ('R', 'PACTE'), 'CONSORTIUM': ('R', 'PASSERELLE'), 'GARDIENS': ('P', 'SCEAU'),
               'REMPART': ('R', 'JUGEMENT'), 'AQUA': ('R', 'BRISER'), 'MISSION': ('R', 'SCEAU'), 'RELATIONS': ('C', None),
               'ANTIROCKET': ('R', None), 'ALEA': (None, None)}
def persona_chooser(name, noise=1.5):
    w = PERSONAS[name]; pref = CLIMAX_PREF[name]
    def ch(s, d, opts, rng):
        if not w: return rng.choice(opts)
        best, bi = None, opts[0]
        for i in opts:
            o = d['opts'][i]; fx = o['fx']
            sc = sum(w.get(k, 0) * dv for k, dv in o['d'].items()) + rng.uniform(-noise, noise) * 3
            if pref[0] and fx.get('loc') == pref[0]: sc += 50
            if pref[1] and fx.get('intent') == pref[1]: sc += 50
            if best is None or sc > best: best, bi = sc, i
        return bi
    return ch


# ----------------------------------------------------------------- v3.2 : test contrefactuel (REVIEW_V3_SYSTEMS annexe A)
# Verdict strict : pivot >= 15 % -> VALIDE ; 10-15 % -> VALIDE fragile (lecteur nomme) ;
# < 10 % -> VALIDE seulement si effet immediat substantiel (SUBST) ou si les options proposees plus tard changent (pathdiv >= 15 %).
# Ch. 14 et postgame : hors modele, verdict de contenu (CONTENT).
SUBST = {'D021': 'Pokemon contre Super Canne', 'D023': 'Pokemon achete', 'D035': 'Potions / barrage R110',
         'D038': 'objet + equipe de Timmy', 'D044': 'CT immediate', 'D045': 'oeuf', 'D073': 'Absol dans l equipe'}
CONTENT = {'D123': 'V', 'D124': 'V', 'D125': 'F', 'D126': 'Vf', 'D127': 'V', 'D128': 'V', 'D129': 'F', 'D130': 'F', 'D131': 'Vf'}

def _outputs(s):
    v = s['val']; f = s['flags']
    return (v.get('F'), v.get('Fvar'), v.get('VS'), v.get('rocket'), v.get('cas'), v.get('ama_issue'), v.get('M1'), v.get('M2'),
            v.get('M3'), s['hidden'], v.get('MAITRE'), v.get('FK'), tuple(sorted(v.get('held', {}).items())),
            'REL_CHEN_SEKO' in f, 'BLUE_LIBRE' in f, 'PETER_ASSUME' in f, 'PR_ACCUSE' in f, 'TIMMY_SAUVE' in f,
            'FLORA_DESOBEIT' in f, v.get('KOGA'), seko_cede(s), 'OBJ_LETTRE_FERRAND' in f, tuple(sorted(s['eco'].items())))

def pivot(games=120):
    global climax
    orig = climax
    def det(s, rng, assign=None): return orig(s, random.Random(99), assign)
    climax = det
    names = list(PERSONAS); res = {}
    try:
        for d in DECISIONS:
            if d['ch'] >= 14: continue
            tot = piv = fin = pdv = 0
            for k in range(games):
                pn = names[k % len(names)]; outs = []; paths = []
                for force in range(len(d['opts'])):
                    ok = [True]
                    w, pref = PERSONAS[pn], CLIMAX_PREF[pn]
                    def ch(s_, d_, opts, rng, k=k, force=force, ok=ok, w=w, pref=pref):
                        if d_['id'] == d['id']:
                            if force in opts: return force
                            ok[0] = False
                        best, bi = None, opts[0]
                        for i in opts:
                            o = d_['opts'][i]; r = random.Random('%d-%s-%d' % (k, d_['id'], i)).uniform(-1.5, 1.5) * 3
                            sc = sum(w.get(x, 0) * dv for x, dv in o['d'].items()) + (r if w else r * 10)
                            if pref[0] and o['fx'].get('loc') == pref[0]: sc += 50
                            if pref[1] and o['fx'].get('intent') == pref[1]: sc += 50
                            if best is None or sc > best: best, bi = sc, i
                        return bi
                    seen = []
                    def ch2(s_, d_, opts, rng, ch=ch, seen=seen):
                        seen.append((d_['id'], tuple(opts))); return ch(s_, d_, opts, rng)
                    st = play(random.Random(1000 + k), ch2, lambda c, r: 0)
                    if ok[0] and d['id'] in st['choice']:
                        outs.append(_outputs(st)); paths.append(tuple(x for x in seen if x[0] != d['id']))
                if len(outs) >= 2:
                    tot += 1; piv += len(set(outs)) > 1; fin += len(set(o[0] for o in outs)) > 1; pdv += len(set(paths)) > 1
            res[d['id']] = (100.0 * piv / max(tot, 1), 100.0 * fin / max(tot, 1), 100.0 * pdv / max(tot, 1), tot)
    finally:
        climax = orig
    return res

def strict_verdicts(res):
    out = {}
    for d in DECISIONS:
        if d['id'] in CONTENT:
            out[d['id']] = CONTENT[d['id']]; continue
        pv, fn, pd, tot = res.get(d['id'], (0, 0, 0, 0))
        if d['verdict'][0] == 'D': out[d['id']] = 'D'
        elif pv >= 15: out[d['id']] = 'V'
        elif pv >= 10 and d['reads']: out[d['id']] = 'Vf'
        elif d['id'] in SUBST or pd >= 15: out[d['id']] = 'Vf' if pv < 10 and d['id'] in ('D035', 'D038', 'D044') else 'V'
        else: out[d['id']] = 'F'
    return out

# ----------------------------------------------------------------- simulation
def sim(n=20000, seed=1, persona=True):
    rng = random.Random(seed)
    mx = {c: {k: -1 for k in ALLV + ['N']} for c in range(16)}
    mn = {c: {k: 999 for k in ALLV + ['N']} for c in range(16)}
    endings = collections.Counter(); combos = collections.Counter(); witness = {}
    mres = {m: collections.Counter() for m in (1, 2, 3)}; mwit = {}
    hidden = 0; money_neg = 0; cas = collections.Counter(); rk = collections.Counter(); ama = collections.Counter()
    defended_vs_result = collections.Counter()
    byp = collections.defaultdict(collections.Counter); fvar = collections.Counter()
    names = list(PERSONAS)
    for i in range(n):
        pn = names[i % len(names)] if persona else 'ALEA'
        s = play(rng, persona_chooser(pn))
        s['persona'] = pn
        for c, sn in s['snaps'].items():
            for k in ALLV + ['N']:
                mx[c][k] = max(mx[c][k], sn[k]); mn[c][k] = min(mn[c][k], sn[k])
        F = s['val']['F']; VS = s['val']['VS']
        endings[F] += 1; combos[(F, VS)] += 1
        witness.setdefault((F, VS), s)
        for m in (1, 2, 3):
            r = s['val']['M%d' % m]; mres[m][r] += 1; mwit.setdefault((m, r), s)
            defended_vs_result[(m, s['val'].get('def%d' % m) == r)] += 1
        byp[pn][F] += 1; fvar[(F, s['val'].get('Fvar', ''))] += 1
        hidden += s['hidden']; cas[s['val']['cas']] += 1; rk[s['val']['rocket']] += 1; ama[s['val']['ama_issue']] += 1
        if min(sn['money'] for sn in s['snaps'].values()) < 0: money_neg += 1
    return dict(mx=mx, mn=mn, endings=endings, combos=combos, witness=witness, mres=mres, mwit=mwit,
                hidden=hidden, n=n, byp=byp, fvar=fvar, cas=cas, rk=rk, ama=ama, dvr=defended_vs_result, money_neg=money_neg)

def path_of(s):
    return ' '.join('%s%s' % (k, 'abcd'[v - 1]) for k, v in sorted(s['choice'].items()))

def key_path(s, keys):
    return ', '.join('%s=%s' % (k, 'abcd'[s['choice'][k] - 1]) for k in keys if k in s['choice'])

# ----------------------------------------------------------------- chemin dore
GOLD_REL = ['BR', 'BL', 'FL', 'PR', 'PE', 'AM', 'TI', 'GI', 'HO']
def golden_score(s):
    v = s['v']; sc = 0
    sc += 40 if s['val']['F'] == 'F2' else 0
    sc += 20 if s['val']['VS'] == 'INTEGRATION' else 0
    sc += 15 if s['val']['rocket'] == 'DEMANTELEE' else 0
    sc += 5 * sum(1 for k in GOLD_REL if v[k] >= 60)
    sc += 10 if s['val']['cas'] == 'AUCUN' else 0
    sc += 10 if s['hidden'] else 0
    sc += 10 if s['val']['ama_issue'] == 'RENONCE' else 0
    return sc

def golden(iters=4000, seed=7, restarts=6):
    best_all = None
    for r in range(restarts):
        rng = random.Random(seed + r)
        genome = {}
        def chooser(s, d, opts, rng_, g=genome):
            k = d['id']
            if k in g and g[k] in opts: return g[k]
            g[k] = rng.choice(opts); return g[k]
        kp = lambda c, rng_: 0
        cur = play(random.Random(1), chooser, kp); cur_sc = golden_score(cur)
        for it in range(iters):
            g2 = dict(genome)
            for _ in range(rng.randint(1, 3)):
                k = rng.choice(list(BYID)); d = BYID[k]
                g2[k] = rng.randrange(len(d['opts']))
            def ch2(s, d, opts, rng_, g=g2):
                k = d['id']
                if k in g and g[k] in opts: return g[k]
                g[k] = opts[0]; return g[k]
            st = play(random.Random(1), ch2, kp)
            sc = golden_score(st)
            if sc >= cur_sc:
                genome.clear(); genome.update(g2); cur, cur_sc = st, sc
        if best_all is None or cur_sc > best_all[0]: best_all = (cur_sc, cur)
    return best_all

# ----------------------------------------------------------------- rendu markdown
SYSNAME = {'BR': 'BR', 'BL': 'BL', 'FL': 'FL', 'PR': 'PR', 'PE': 'PE', 'AM': 'AM', 'TI': 'TI', 'GI': 'GI', 'HO': 'HO',
           'rL': 'rL', 'rC': 'rC', 'rM': 'rM', 'rA': 'rA', 'rI': 'rI', 'rG': 'rG', 'rP': 'rP', 'PA': 'PA', 'RK': 'RK', 'N': 'N'}
CHNAME = {0: 'Prologue', 1: 'Ch. 1', 2: 'Ch. 2', 3: 'Ch. 3', 4: 'Ch. 4', 5: 'Ch. 5', 6: 'Ch. 6', 7: 'Ch. 7',
          8: 'Ch. 8', 9: 'Ch. 9', 10: 'Ch. 10', 11: 'Ch. 11', 12: 'Ch. 12', 13: 'Ch. 13', 14: 'Ch. 14', 15: 'Postgame'}
KIND = {'presence': 'presence', 'arbitrage': 'arbitrage', 'don': 'don', 'aveu': 'aveu', 'combat': 'combat', 'discret': 'geste'}

from cf_accents import fr

def storage(d):
    if d['id'] == 'D117': return 'VAR_CF_FIN bits 5-7 (intention : 1 PACTE, 2 SCEAU, 3 PASSERELLE, 4 BRISER) ; garde = FLAG_CF_M_CLIMAX non pose'
    n = int(d['id'][1:]) - 1
    return 'VAR_CF_D%02d bits %d-%d (0 = non prise ; 1..%d = option)' % (n // 8, (n % 8) * 2, (n % 8) * 2 + 1, len(d['opts']))

def fmt_delta(o):
    parts = ['%s%+d' % (SYSNAME[k], dv) for k, dv in o['d'].items() if dv]
    fx = o['fx']
    if 'eco' in fx: parts.append('%s=%s' % (fx['eco'][0], ['ENVAHI', 'MIXTE', 'RESTAURE', 'ABATTU'][fx['eco'][1]]))
    if 'ecostep' in fx: parts.append('%s +1 cran' % fx['ecostep'])
    if 'bv' in fx: parts.append('BV.%s+1' % {'P': 'PROT', 'A': 'ACC', 'C': 'COMP'}[fx['bv']])
    if isinstance(fx.get('money'), int): parts.append('%+d P' % fx['money'])
    if 'N' in fx: parts.append('N%s' % (('=%d' % fx['N']) if isinstance(fx['N'], int) else fx['N']))
    if 'custody' in fx: parts.append('garde=%s' % fx['custody'])
    for f_ in fx.get('set', []): parts.append(f_)
    for k, v_ in fx.get('val', {}).items(): parts.append('%s=%s' % (k, v_))
    return ', '.join(parts) if parts else '-'

def render_decision(d):
    L = []
    vtag = {'V': 'VALIDE', 'F': 'FAIBLE (liste, non comptee)', 'D': 'DOUBLON (non comptee)'}[d['verdict'][0]]
    L.append('### %s - %s' % (d['id'], fr(d['title'])))
    L.append('`%s` · `%s` · %s · %s · statut **propose** · verdict **%s**%s' % (
        d['t'], d['c'], KIND[d['kind']], CHNAME[d['ch']], vtag, (' (' + d['verdict'][1] + ')') if d['verdict'][1] else ''))
    L.append('')
    L.append('- **Unite :** %s' % d['unit'])
    L.append('- **Declencheur :** %s' % fr(d['trig']))
    L.append('- **Prerequis :** %s' % d['pre'])
    L.append('- **Stockage :** %s' % storage(d))
    L.append('- **Options :**')
    for o in d['opts']:
        g, l = option_gain_loss(o)
        line = '  - **%s) %s** - deltas : %s' % (o['code'], fr(o['label']), fmt_delta(o))
        if o['reqtxt']: line += ' · *si* %s' % o['reqtxt']
        if o['imm']: line += ' · immediat : %s' % fr(o['imm'])
        if o['later']: line += ' · differe : %s' % fr(o['later'])
        if d['id'] not in ('D004',): line += ' · [gain : %s / perte : %s]' % (', '.join(sorted(g)), ', '.join(sorted(l)))
        L.append(line)
    L.append('- **Lecteurs (contenu affecte) :** %s' % '; '.join(d['reads']))
    L.append('- **Delai principal :** %s%s' % ({'I': 'immediat', 'C': 'differe court', 'L': 'differe long'}[d['delay']],
                                             (' · signal de memoire : ' + d['mem']) if d['mem'] else ''))
    L.append('- **Fins :** %s' % d['fins'])
    L.append('- **Test :** %s' % d['test'])
    L.append('')
    return '\n'.join(L)

ACTS = [('ACT0-1', 'Prologue et Acte I (ch. 0-4)', range(0, 5)),
        ('ACT2', 'Acte II (ch. 5-10)', range(5, 11)),
        ('ACT3', 'Acte III et Echo (ch. 11-14)', range(11, 15)),
        ('POST', 'Postgame (P1-P8)', range(15, 16))]

def render(outdir):
    for code, title, chs in ACTS:
        ds = [d for d in DECISIONS if d['ch'] in chs]
        head = ['# DECISION_LEDGER_%s - %s (*Pokemon Confluence*, brief C)' % (code, title), '',
                '> Genere par `docs/hack/data/cf_model.py --render` a partir de `docs/hack/data/cf_decisions.py` (source unique). Ne pas editer a la main : editer les donnees puis regenerer.',
                '> Regles, legende, decomptes et audit : `DECISION_LEDGER.md`. Systemes, seuils et allocation : `GAME_SYSTEMS.md`. **Statut de toutes les entrees : propose (rien n est implemente ni teste).**',
                '> Accents restaurés au rendu (`cf_accents.py`) : les données sont saisies sans accents. Les répliques en jeu seront écrites par les scénaristes (<= 208 px, 2 lignes, guillemets “ ”).', '']
        cnt = collections.Counter((d['t'], d['c']) for d in ds)
        head.append('**Decisions : %d** (E %d / D %d ; S %d / M %d / L %d ; comptees %d)' % (
            len(ds), sum(1 for d in ds if d['t'] == 'E'), sum(1 for d in ds if d['t'] == 'D'),
            sum(1 for d in ds if d['c'] == 'S'), sum(1 for d in ds if d['c'] == 'M'), sum(1 for d in ds if d['c'] == 'L'),
            sum(1 for d in ds if d['verdict'][0] == 'V')))
        head.append('')
        body = []
        for c in chs:
            dc = [d for d in ds if d['ch'] == c]
            if not dc: continue
            body.append('## %s' % CHNAME[c]); body.append('')
            for d in dc: body.append(render_decision(d))
        with open(os.path.join(outdir, 'DECISION_LEDGER_%s.md' % code), 'w') as fh:
            fh.write(fr('\n'.join(head + body)))
    print('rendered')

if __name__ == '__main__':
    a = sys.argv[1:]
    if '--check' in a: check()
    if '--sim' in a:
        n = int(a[a.index('--sim') + 1]); r = sim(n)
        print('FINS', dict(r['endings'])); print('COMBOS', sorted(r['combos'].items()))
        print('MOTIONS', {m: dict(c) for m, c in r['mres'].items()}); print('DEFENDUE=RESULTAT', dict(r['dvr']))
        print('PAR_PERSONA', {p: dict(c) for p, c in r['byp'].items()})
        print('VARIANTES', dict(r['fvar']))
        print('CACHEE', r['hidden'], 'CAS', dict(r['cas']), 'ROCKET', dict(r['rk']), 'AMA', dict(r['ama']), 'ARGENT<0', r['money_neg'])
        for c in (1, 3, 4, 7, 9, 10, 12, 13):
            print('CH', c, 'MAX', {k: r['mx'][c][k] for k in ALLV}, '\n      MIN', {k: r['mn'][c][k] for k in ALLV})
    if '--golden' in a:
        sc, s = golden()
        print('GOLD score', sc, s['val']['F'], s['val']['VS'], s['val']['rocket'], s['val']['cas'], s['val']['ama_issue'], 'hidden', s['hidden'])
        print('  rel', {k: s['v'][k] for k in REL}, 'rep', {k: s['v'][k] for k in REP}, 'PA', s['v']['PA'], 'RK', s['v']['RK'])
    if '--pivot' in a:
        r = pivot(); sv = strict_verdicts(r)
        for d in DECISIONS:
            pv = r.get(d['id'])
            print(d['id'], d['ch'], sv[d['id']], ('pivot %3.0f%% fin %3.0f%% chemin %3.0f%%' % pv[:3]) if pv else 'contenu')
        cnt = collections.Counter(sv.values())
        print('STRICT', dict(cnt), 'VALIDE', cnt['V'] + cnt['Vf'], 'dont fragiles', cnt['Vf'],
              'ch0-4', sum(1 for d in DECISIONS if d['ch'] <= 4 and sv[d['id']] in ('V', 'Vf')))
    if '--render' in a: render(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
