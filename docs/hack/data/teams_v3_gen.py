#!/usr/bin/env python3
"""Générateur des équipes v3 (*Pokémon Confluence*, brief B).

Source unique des équipes des dresseurs majeurs. Produit :
  docs/hack/data/teams_v3.party      (format trainers.party : Normal + Difficulty: Hard)
  docs/hack/data/partners_v3.party   (partenaires de duo, format battle_partners.party)
  docs/hack/data/teams_v3_ids.csv    (allocation ID -> équipe logique, pour COMBAT_DESIGN §12)

Usage : python3 -I docs/hack/data/teams_v3_gen.py   (depuis la racine du dépôt)
Puis  : python3 -I tools/qa/validate_trainers.py -f docs/hack/data/teams_v3.party --learnsets

Notation d'un Pokémon (une chaîne) :
  "Surnom=Espèce @ Objet | Talent | Nature | Cap1 / Cap2 / Cap3 / Cap4 | Niveau | Rôle"
  Rôle (répartition d'EV) : P = Att/Vit, S = AttSpé/Vit, B = PV/Déf, D = PV/DéfSpé,
                            T = PV/Att, U = PV/AttSpé, X = PV/Vit
Aucune ligne Tera Type n'est jamais écrite (bible : Téracristal absent).
"""
import csv, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
OUT = os.path.join(ROOT, "docs", "hack", "data")

# ---------------------------------------------------------------- IA (COMBAT_DESIGN §3)
AI = {
    "G1": ["Basic Trainer", "Sequence Switching", "Ace Pokemon"],
    "G2": ["Basic Trainer", "Smart Switching", "Ace Pokemon", "HP Aware", "Assume Stab"],
    "RV": ["Basic Trainer", "Smart Switching", "Ace Pokemon", "Know Opponent Party", "Assumptions"],
    "V":  ["Basic Trainer", "Smart Switching", "Powerful Status", "Ace Pokemon", "Assumptions"],
    "B":  ["Basic Trainer", "Smart Switching", "Smart Mon Choices", "Ace Pokemon", "Assumptions",
           "Predict Switch", "PP Stall Prevention"],
    "E":  ["Basic Trainer", "Smart Switching", "Smart Mon Choices", "Ace Pokemon", "Assumptions",
           "Predict Switch", "PP Stall Prevention", "HP Aware", "Predict Incoming Mon", "Predict Move"],
    "Z":  ["Basic Trainer", "Smart Switching", "Smart Mon Choices", "Assumptions", "Predict Switch",
           "PP Stall Prevention", "HP Aware", "Predict Incoming Mon", "Predict Move",
           "Randomize Party Indices"],
}
# Montée d'un cran en Difficile (§9) : même équipe, mêmes niveaux, IA plus fine.
AI_HARD = {"G1": ["HP Aware"], "G2": ["Smart Mon Choices", "Predict Switch"],
           "RV": ["Smart Mon Choices", "Predict Switch"], "V": ["Smart Mon Choices", "Predict Switch"],
           "B": ["HP Aware", "Predict Incoming Mon", "Predict Move"], "E": ["Weigh Ability Prediction"],
           "Z": ["Weigh Ability Prediction"]}

IV_NORMAL = {1: 15, 2: 20, 3: 25, 4: 31, 5: 31}
EV_SPREAD = {"P": ("Atk", "Spe", "HP"), "S": ("SpA", "Spe", "HP"), "B": ("HP", "Def", "SpD"),
             "D": ("HP", "SpD", "Def"), "T": ("HP", "Atk", "Spe"), "U": ("HP", "SpA", "Spe"),
             "X": ("HP", "Spe", "Def")}

def evs(role, amount):
    a, b, c = EV_SPREAD[role]
    if amount == 0:
        return None
    if amount >= 252:
        return f"252 {a} / 252 {b} / 4 {c}"
    return f"{amount} {a} / {amount} {b}"

def ev_amount(tier, hard):
    if hard:
        return {1: 85, 2: 128, 3: 252, 4: 252, 5: 252}[tier]
    return {1: 0, 2: 0, 3: 0, 4: 128, 5: 252}[tier]

def tier_of(cap):
    if cap <= 25: return 1
    if cap <= 38: return 2
    if cap <= 53: return 3
    if cap <= 60: return 4
    return 5

# ---------------------------------------------------------------- registre
TRAINERS = []   # dicts
PARTNERS = []

def T(lid, tid, name, cls, pic, gender, music, ai, cap, mons, items="", double=False, mods=(),
      hard=True, note="", partner=False):
    d = dict(lid=lid, tid=tid, name=name, cls=cls, pic=pic, gender=gender, music=music, ai=ai,
             cap=cap, mons=mons, items=items, double=double, mods=list(mods), hard=hard,
             note=note, tier=tier_of(cap))
    (PARTNERS if partner else TRAINERS).append(d)

def parse(m):
    parts = [p.strip() for p in m.split("|")]
    head, ability, nature, moves, lvl, role = parts
    nick = None
    if "=" in head:
        nick, head = head.split("=", 1)
    item = None
    if "@" in head:
        head, item = [x.strip() for x in head.split("@", 1)]
    return dict(nick=nick, species=head.strip(), item=item, ability=ability, nature=nature,
                moves=[x.strip() for x in moves.split("/") if x.strip()], level=int(lvl), role=role)

def render_mon(p, tier, hard):
    sp = f"{p['nick']} ({p['species']})" if p["nick"] else p["species"]
    lines = [sp + (f" @ {p['item']}" if p["item"] else "")]
    lines.append(f"Level: {p['level']}")
    lines.append(f"Ability: {p['ability']}")
    iv = 31 if hard else IV_NORMAL[tier]
    if iv != 31:
        lines.append(f"IVs: {iv} HP / {iv} Atk / {iv} Def / {iv} SpA / {iv} SpD / {iv} Spe")
    e = evs(p["role"], ev_amount(tier, hard))
    if e:
        lines.append(f"EVs: {e}")
    lines.append(f"{p['nature']} Nature")
    lines += [f"- {mv}" for mv in p["moves"]]
    return "\n".join(lines)

def render(t, hard=False):
    flags = AI[t["ai"]] + t["mods"] + (AI_HARD[t["ai"]] if hard else [])
    seen, fl = set(), []
    for f in flags:
        if f not in seen:
            seen.add(f); fl.append(f)
    out = [f"=== {t['tid']} ===", f"Name: {t['name']}", f"Class: {t['cls']}", f"Pic: {t['pic']}",
           f"Gender: {t['gender']}", f"Music: {t['music']}"]
    if t["items"]:
        out.append(f"Items: {t['items']}")
    out.append(f"Battle Type: {'Doubles' if t['double'] else 'Singles'}")
    if hard:
        out.append("Difficulty: Hard")
    out.append("AI: " + " / ".join(fl))
    body = "\n\n".join(render_mon(parse(m), t["tier"], hard) for m in t["mons"])
    return "/* " + t["lid"] + (" (Hard)" if hard else "") + (" : " + t["note"] if t["note"] and not hard else "") + " */\n" + "\n".join(out) + "\n\n" + body + "\n"

def check_levels(t):
    """Équité : équipe <= plafond+2, As <= plafond+3 ; T5 : <= 78."""
    errs = []
    lv = [parse(m)["level"] for m in t["mons"]]
    if t["tier"] == 5:
        if max(lv) > 78: errs.append(f"{t['lid']}: niveau {max(lv)} > 78")
        return errs
    cap = t["cap"]
    *rest, ace = lv
    if ace > cap + 3: errs.append(f"{t['lid']}: As {ace} > plafond {cap}+3")
    for l in rest:
        if l > cap + 2: errs.append(f"{t['lid']}: niveau {l} > plafond {cap}+2")
    if len(t["mons"]) > 6: errs.append(f"{t['lid']}: > 6 Pokémon")
    megas = sum(1 for m in t["mons"] if (parse(m)["item"] or "").endswith("ite") and parse(m)["item"] not in ("Eviolite",))
    if megas > 1: errs.append(f"{t['lid']}: {megas} Méga")
    if megas and t["cap"] < 40: errs.append(f"{t['lid']}: Méga avant le ch. 8 (R120)")
    return errs

# ================================================================ DONNÉES
# Pools d'ID (COMBAT_DESIGN §12). Les ID vanilla conservés sont écrits en dur.
exec(open(os.path.join(OUT, "teams_v3_data.py"), encoding="utf-8").read())

# ---------------------------------------------------------------- sortie
def main():
    errs = []
    ids = {}
    for t in TRAINERS:
        errs += check_levels(t)
        if t["tid"] in ids:
            errs.append(f"collision d'ID {t['tid']} : {ids[t['tid']]} / {t['lid']}")
        ids[t["tid"]] = t["lid"]
    with open(os.path.join(OUT, "teams_v3.party"), "w", encoding="utf-8") as f:
        f.write("/* GÉNÉRÉ par teams_v3_gen.py — ne pas éditer à la main. COMBAT_DESIGN.md v3 (brief B). */\n\n")
        for t in TRAINERS:
            f.write(render(t) + "\n")
            if t["hard"]:
                f.write(render(t, hard=True) + "\n")
    with open(os.path.join(OUT, "partners_v3.party"), "w", encoding="utf-8") as f:
        f.write("/* GÉNÉRÉ par teams_v3_gen.py — partenaires de duo (battle_partners.party). */\n\n")
        for t in PARTNERS:
            errs += check_levels(t)
            f.write(render(t) + "\n")
    with open(os.path.join(OUT, "teams_v3_ids.csv"), "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(["trainer_id", "equipe", "palier", "plafond", "pokemon", "note"])
        for t in TRAINERS:
            w.writerow([t["tid"], t["lid"], f"T{t['tier']}", t["cap"], len(t["mons"]), t["note"]])
    n_hard = sum(1 for t in TRAINERS if t["hard"])
    print(f"dresseurs/variantes : {len(TRAINERS)} ; blocs Hard : {n_hard} ; partenaires : {len(PARTNERS)} ; "
          f"ID distincts : {len(ids)} ; Pokémon : {sum(len(t['mons']) for t in TRAINERS)}")
    for e in errs:
        print("ERREUR équité :", e)
    return 1 if errs else 0

if __name__ == "__main__":
    sys.exit(main())
