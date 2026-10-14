# Données des équipes v3 — lues par teams_v3_gen.py (exec). Voir COMBAT_DESIGN.md §7.
# Chaque appel T(lid, TRAINER_ID, NOM, Classe, Pic, Genre, Musique, IA, plafond, [Pokémon], ...)
# Le plafond est celui EN VIGUEUR au moment du combat (COMBAT_DESIGN §2.1).
import re as _re

# ---------------------------------------------------------------- pools d'ID recyclés (§12)
def _rematch_pool():
    src = open(os.path.join(ROOT, "src", "battle_setup.c"), encoding="utf-8").read()
    tbl = src[src.index("gRematchTable[REMATCH_TABLE_ENTRIES]"):]
    tbl = tbl[:tbl.index("};")]
    ids = {}
    for l in open(os.path.join(ROOT, "include", "constants", "opponents.h"), encoding="utf-8"):
        mm = _re.match(r"#define (TRAINER_\w+)\s+(\d+)", l)
        if mm: ids[mm.group(1)] = int(mm.group(2))
    leaders = "ROXANNE|BRAWLY|WATTSON|FLANNERY|NORMAN|WINONA|TATE|JUAN"
    plain, lead = [], []
    for mm in _re.finditer(r"REMATCH\(([^)]*)\)", tbl):
        row = [p.strip() for p in mm.group(1).split(",")][:5]
        for x in row[1:5]:
            if x == "TRAINER_NONE" or x == row[0]: continue
            if _re.search("SIDNEY|PHOEBE|GLACIA|DRAKE|WALLACE", x): continue
            (lead if _re.search(leaders, x) else plain).append((ids[x], x))
    return [x for _, x in sorted(set(plain))], [x for _, x in sorted(set(lead))]

POOL, LEADER_RM = _rematch_pool()
_used = set()
def nid():
    for x in POOL:
        if x not in _used:
            _used.add(x); return x
    raise SystemExit("pool d'ID épuisé")

def lrm(leader, n):
    x = f"TRAINER_{leader}_{n}"
    assert x in LEADER_RM, x
    return x

RIVAL = "Rival"
ALL = {"T": "TORCHIC", "M": "MUDKIP", "G": "TREECKO"}   # clé = starter de BRICE (vanilla : suffixe d'ID)

# ================================================================ C-02 BRICE (rival, AI-RV)
# Variante = starter de Brice (fort contre celui de Red) x voie BV (PROTÉGER / ACCUEILLIR / COMPRENDRE)
ST = {
 "R103": {"T": "Torchic | Blaze | Naughty | Scratch / Growl / Ember | 6 | P",
          "M": "Mudkip | Torrent | Impish | Tackle / Growl / Water Gun | 6 | B",
          "G": "Treecko | Overgrow | Hasty | Pound / Leer / Absorb | 6 | S"},
 "R110": {"T": "Combusken | Blaze | Adamant | Double Kick / Flame Charge / Aerial Ace / Detect | 23 | P",
          "M": "Marshtomp | Torrent | Impish | Mud Shot / Water Pulse / Rock Throw / Protect | 23 | B",
          "G": "Grovyle | Overgrow | Jolly | Fury Cutter / Mega Drain / Quick Attack / Detect | 23 | P"},
 "R119": {"T": "Blaziken @ Charcoal | Blaze | Adamant | Blaze Kick / Double Kick / Aerial Ace / Bulk Up | 37 | P",
          "M": "Swampert @ Mystic Water | Torrent | Adamant | Muddy Water / Mud Shot / Rock Slide / Protect | 37 | T",
          "G": "Sceptile @ Miracle Seed | Overgrow | Jolly | Leaf Blade / X-Scissor / Quick Attack / Detect | 37 | P"},
 "CH12": {"T": "Blaziken @ Life Orb | Blaze | Adamant | Blaze Kick / Brave Bird / Bulk Up / Thunder Punch | 55 | P",
          "M": "Swampert @ Leftovers | Torrent | Adamant | Earthquake / Waterfall / Ice Beam / Protect | 55 | T",
          "G": "Sceptile @ Life Orb | Overgrow | Jolly | Leaf Blade / Dragon Claw / Earthquake / X-Scissor | 55 | P"},
 "T5":   {"T": "Blaziken @ Life Orb | Speed Boost | Adamant | Flare Blitz / Close Combat / Protect / Swords Dance | 78 | P",
          "M": "Swampert @ Leftovers | Torrent | Adamant | Earthquake / Waterfall / Ice Beam / Stealth Rock | 78 | T",
          "G": "Sceptile @ Life Orb | Unburden | Jolly | Leaf Blade / Dragon Claw / Earthquake / Swords Dance | 78 | P"},
}
BV = {
 "R119": {
  "PROTEGER":   ["Pelipper | Drizzle | Modest | Water Pulse / Air Cutter / Protect / Roost | 34 | S",
                 "Tropius | Harvest | Adamant | Leaf Tornado / Air Slash / Stomp / Synthesis | 33 | B",
                 "Manectric | Lightning Rod | Timid | Thunder Fang / Discharge / Bite / Howl | 34 | S",
                 "Linoone | Pickup | Jolly | Headbutt / Slash / Pin Missile / Rest | 33 | P"],
  "ACCUEILLIR": ["Pelipper | Drizzle | Modest | Water Pulse / Air Cutter / Protect / Roost | 34 | S",
                 "Ampharos | Static | Modest | Discharge / Power Gem / Cotton Spore / Thunder Wave | 34 | U",
                 "Heracross | Guts | Adamant | Brick Break / Horn Attack / Pin Missile / Bulk Up | 34 | P",
                 "Dubwool | Fluffy | Impish | Double Kick / Cotton Guard / Take Down / Defense Curl | 33 | B"],
  "COMPRENDRE": ["Pelipper | Drizzle | Modest | Water Pulse / Air Cutter / Protect / Roost | 34 | S",
                 "Absol | Justified | Adamant | Bite / Psycho Cut / Slash / Quick Attack | 34 | P",
                 "Relicanth | Rock Head | Impish | Ancient Power / Dive / Take Down / Rest | 33 | B",
                 "Arcanine-Hisui | Intimidate | Adamant | Rock Slide / Flame Wheel / Bite / Howl | 34 | P"],
 },
 "CH12": {
  "PROTEGER":   ["Pelipper @ Damp Rock | Drizzle | Bold | Hurricane / Surf / Roost / U-turn | 53 | D",
                 "Ludicolo @ Life Orb | Swift Swim | Modest | Surf / Giga Drain / Ice Beam / Fake Out | 52 | S",
                 "Manectric @ Magnet | Lightning Rod | Timid | Thunderbolt / Volt Switch / Flamethrower / Thunder Wave | 53 | S",
                 "Flygon @ Soft Sand | Levitate | Jolly | Earthquake / Dragon Claw / U-turn / Fire Punch | 53 | P",
                 "Tropius @ Sitrus Berry | Harvest | Impish | Air Slash / Leaf Blade / Synthesis / Dragon Dance | 52 | B"],
  "ACCUEILLIR": ["Pelipper @ Damp Rock | Drizzle | Bold | Hurricane / Surf / Roost / U-turn | 53 | D",
                 "Ampharos @ Leftovers | Static | Modest | Thunderbolt / Power Gem / Dragon Pulse / Volt Switch | 53 | U",
                 "Heracross @ Flame Orb | Guts | Jolly | Close Combat / Megahorn / Stone Edge / Knock Off | 53 | P",
                 "Dubwool @ Leftovers | Fluffy | Impish | Body Press / Cotton Guard / Double-Edge / Wild Charge | 52 | B",
                 "Hawlucha @ Sitrus Berry | Unburden | Jolly | Acrobatics / High Jump Kick / Swords Dance / Roost | 52 | P"],
  "COMPRENDRE": ["Pelipper @ Damp Rock | Drizzle | Bold | Hurricane / Surf / Roost / U-turn | 53 | D",
                 "Absol @ Life Orb | Justified | Adamant | Knock Off / Psycho Cut / Sucker Punch / Swords Dance | 53 | P",
                 "Relicanth @ Leftovers | Rock Head | Adamant | Head Smash / Waterfall / Earthquake / Rest | 52 | B",
                 "Arcanine-Hisui @ Sitrus Berry | Intimidate | Adamant | Head Smash / Flare Blitz / Extreme Speed / Wild Charge | 53 | P",
                 "Castform @ Damp Rock | Forecast | Modest | Weather Ball / Thunder / Ice Beam / Hurricane | 52 | S"],
 },
}
def _lv(m, lv):
    p = m.split("|"); p[4] = f" {lv} "; return "|".join(p)
BV["T5"] = {k: [_lv(m, 75 + (i % 3)) for i, m in enumerate(v)] for k, v in BV["CH12"].items()}

T("T-BRICE-T1-R103-" + "T", "TRAINER_BRENDAN_ROUTE_103_TORCHIC", "BRICE", RIVAL, "Brendan", "Male", "Male", "G1", 14,
  ["Wingull | Keen Eye | Hardy | Growl / Water Gun | 4 | S", ST["R103"]["T"]], note="R103 ch.0, Red a Arcko")
T("T-BRICE-T1-R103-" + "M", "TRAINER_BRENDAN_ROUTE_103_MUDKIP", "BRICE", RIVAL, "Brendan", "Male", "Male", "G1", 14,
  ["Wingull | Keen Eye | Hardy | Growl / Water Gun | 4 | S", ST["R103"]["M"]], note="R103 ch.0, Red a Poussifeu")
T("T-BRICE-T1-R103-" + "G", "TRAINER_BRENDAN_ROUTE_103_TREECKO", "BRICE", RIVAL, "Brendan", "Male", "Male", "G1", 14,
  ["Wingull | Keen Eye | Hardy | Growl / Water Gun | 4 | S", ST["R103"]["G"]], note="R103 ch.0, Red a Gobou")
for k, sfx in ALL.items():
    T(f"T-BRICE-T1-R110-{k}", f"TRAINER_BRENDAN_ROUTE_110_{sfx}", "BRICE", RIVAL, "Brendan", "Male", "Male", "RV", 22,
      ["Wingull | Keen Eye | Modest | Water Pulse / Wing Attack / Growl / Quick Attack | 20 | S",
       "Electrike | Static | Timid | Spark / Bite / Thunder Wave / Quick Attack | 20 | S", ST["R110"][k]],
      note="R110 ch.4 (avant BV)")
_bv_ids = {"R119": {"PROTEGER": "TRAINER_BRENDAN_ROUTE_119_{}", "ACCUEILLIR": "TRAINER_MAY_ROUTE_119_{}",
                    "COMPRENDRE": "TRAINER_MAY_ROUTE_110_{}"},
           "CH12": {"PROTEGER": "TRAINER_BRENDAN_LILYCOVE_{}", "ACCUEILLIR": "TRAINER_MAY_LILYCOVE_{}",
                    "COMPRENDRE": "TRAINER_BRENDAN_RUSTBORO_{}"},
           "T5":   {"PROTEGER": "TRAINER_MAY_RUSTBORO_{}", "ACCUEILLIR": "TRAINER_MAY_ROUTE_103_{}",
                    "COMPRENDRE": None}}
_t5c = iter(["TRAINER_BRENDAN_PLACEHOLDER", "TRAINER_MAY_PLACEHOLDER", None])
for stage, cap in (("R119", 35), ("CH12", 53), ("T5", 75)):
    for bv, fmt in _bv_ids[stage].items():
        for k, sfx in ALL.items():
            tid = fmt.format(sfx) if fmt else (next(_t5c) or nid())
            T(f"T-BRICE-{ {'R119':'T2','CH12':'T3','T5':'T5'}[stage] }-{stage.replace('T5','POST')}-{bv}-{k}", tid, "BRICE", RIVAL, "Brendan",
              "Male", "Male", "RV" if stage != "T5" else "E", cap, BV[stage][bv] + [ST[stage][k]],
              note=f"{stage} voie {bv}" + (" (refusable)" if stage == "CH12" else ""))

# ================================================================ C-03 BLUE (rival, E-ADAPT, AI-RV -> AI-B)
# Paquets E-ADAPT : A = contre Plante/Insecte/Glace/Fée/Psy/Spectre/Dragon ; B = contre Feu/Roche/Acier/
# Électrik/Normal/Ténèbres ; C = contre Eau/Sol/Vol/Poison/Combat (COMBAT_DESIGN §5.3)
BLUE_PKG = {
 1: {"A": ["Growlithe | Intimidate | Adamant | Bite / Ember / Flame Wheel / Roar | 20 | P",
           "Corvisquire | Keen Eye | Jolly | Pluck / Fury Attack / Power Trip / Scary Face | 19 | P"],
     "B": ["Gyarados | Intimidate | Adamant | Bite / Twister / Leer / Thrash | 20 | P",
           "Drilbur | Mold Breaker | Jolly | Metal Claw / Mud-Slap / Rapid Spin / Fury Swipes | 19 | P"],
     "C": ["Exeggcute | Chlorophyll | Modest | Bullet Seed / Confusion / Leech Seed / Uproar | 19 | U",
           "Blitzle | Motor Drive | Jolly | Shock Wave / Quick Attack / Flame Charge / Spark | 20 | P"]},
 2: {"A": ["Arcanine @ Charcoal | Intimidate | Adamant | Fire Fang / Crunch / Extreme Speed / Roar | 32 | P",
           "Corvisquire @ Sharp Beak | Keen Eye | Jolly | Drill Peck / Power Trip / Roost / Taunt | 31 | P"],
     "B": ["Gyarados @ Mystic Water | Intimidate | Adamant | Waterfall / Bite / Dragon Dance / Ice Fang | 32 | P",
           "Excadrill @ Soft Sand | Mold Breaker | Jolly | Dig / Metal Claw / Rock Slide / Rapid Spin | 31 | P"],
     "C": ["Exeggutor @ Miracle Seed | Harvest | Modest | Giga Drain / Psyshock / Leech Seed / Stun Spore | 31 | U",
           "Zebstrika @ Magnet | Lightning Rod | Timid | Volt Switch / Flame Charge / Shock Wave / Thunder Wave | 32 | S"]},
 3: {"A": ["Arcanine @ Charcoal | Intimidate | Adamant | Flare Blitz / Crunch / Extreme Speed / Wild Charge | 41 | P",
           "Corviknight @ Leftovers | Pressure | Impish | Brave Bird / Iron Head / Roost / Bulk Up | 40 | B"],
     "B": ["Gyarados @ Mystic Water | Intimidate | Adamant | Waterfall / Crunch / Dragon Dance / Ice Fang | 41 | P",
           "Excadrill @ Soft Sand | Mold Breaker | Jolly | Earthquake / Iron Head / Rock Slide / Rapid Spin | 40 | P"],
     "C": ["Exeggutor @ Miracle Seed | Harvest | Modest | Giga Drain / Psyshock / Leech Seed / Sludge Bomb | 40 | U",
           "Zebstrika @ Magnet | Lightning Rod | Timid | Volt Switch / Thunderbolt / Overheat / Thunder Wave | 41 | S"]},
 4: {"A": ["Arcanine @ Choice Band | Intimidate | Adamant | Flare Blitz / Crunch / Extreme Speed / Wild Charge | 57 | P",
           "Corviknight @ Leftovers | Pressure | Impish | Brave Bird / Iron Head / Roost / Bulk Up | 56 | B"],
     "B": ["Gyarados @ Life Orb | Intimidate | Adamant | Waterfall / Crunch / Dragon Dance / Earthquake | 57 | P",
           "Excadrill @ Focus Sash | Mold Breaker | Jolly | Earthquake / Iron Head / Rock Slide / Rapid Spin | 56 | P"],
     "C": ["Exeggutor @ Sitrus Berry | Harvest | Modest | Giga Drain / Psyshock / Leech Seed / Sludge Bomb | 56 | U",
           "Zebstrika @ Choice Specs | Lightning Rod | Timid | Volt Switch / Thunderbolt / Overheat / Discharge | 57 | S"]},
}
BLUE_PKG[5] = {k: [_lv(m, 75 + i) for i, m in enumerate(v)] for k, v in BLUE_PKG[4].items()}
BLUE_CORE = {
 1: ["Pidgeotto | Keen Eye | Jolly | Wing Attack / Quick Attack / Feather Dance / Twister | 20 | P"],
 2: ["Pidgeot @ Sharp Beak | Big Pecks | Jolly | Wing Attack / Quick Attack / Twister / Feather Dance | 32 | P",
     "Rhyhorn @ Hard Stone | Lightning Rod | Adamant | Rock Blast / Bulldoze / Horn Attack / Scary Face | 31 | T"],
 3: ["Pidgeot @ Sharp Beak | Big Pecks | Jolly | Air Slash / Quick Attack / Heat Wave / Roost | 41 | S",
     "Rhydon @ Eviolite | Lightning Rod | Adamant | Stone Edge / Earthquake / Megahorn / Hammer Arm | 40 | T"],
 4: ["Rhyperior @ Weakness Policy | Solid Rock | Adamant | Stone Edge / Earthquake / Megahorn / Ice Punch | 57 | T"],
}
BLUE_CORE[5] = [_lv(BLUE_CORE[4][0], 76)]
BLUE_ACE = {
 1: "Kadabra @ Twisted Spoon | Synchronize | Timid | Psybeam / Confusion / Disable / Reflect | 21 | S",
 2: "Alakazam @ Twisted Spoon | Magic Guard | Timid | Psychic / Shadow Ball / Calm Mind / Recover | 34 | S",
 3: "Alakazam @ Life Orb | Magic Guard | Timid | Psychic / Shadow Ball / Focus Blast / Calm Mind | 42 | S",
 4: "Pidgeot @ Pidgeotite | Big Pecks | Timid | Hurricane / Heat Wave / Roost / U-turn | 58 | S",
}
BLUE_ACE[5] = _lv(BLUE_ACE[4], 78)
BLUE_ALA = {4: "Alakazam @ Life Orb | Magic Guard | Timid | Psychic / Shadow Ball / Focus Blast / Nasty Plot | 57 | S"}
BLUE_ALA[5] = _lv(BLUE_ALA[4], 76)
BLUE_FLEX = {3: {"SCOTT": "Bisharp @ Eviolite | Defiant | Adamant | Iron Head / Sucker Punch / Swords Dance / Knock Off | 40 | P"},
             4: {"SCOTT": "Kingambit @ Black Glasses | Supreme Overlord | Adamant | Kowtow Cleave / Iron Head / Sucker Punch / Swords Dance | 56 | T",
                 "LIBRE": "Tauros @ Choice Band | Intimidate | Jolly | Double-Edge / Close Combat / Earthquake / Rock Slide | 56 | P"}}
BLUE_FLEX[5] = {k: _lv(v, 75) for k, v in BLUE_FLEX[4].items()}
_cap = {1: 20, 2: 32, 3: 40, 4: 56, 5: 75}
_where = {1: "ch.3 Tente de Scott (refusable)", 2: "Tournoi T2, finale (ch.5-8)", 3: "ch.9 toit (refusable)",
          4: "ch.14 Route Victoire (obligatoire)", 5: "postgame Zone de Combat"}
for tier in (1, 2, 3, 4, 5):
    stances = ["SCOTT"] if tier < 4 else ["SCOTT", "LIBRE"]
    for st in stances:
        for pk in "ABC":
            if tier <= 2:
                mons = BLUE_CORE[tier] + BLUE_PKG[tier][pk] + [BLUE_ACE[tier]]
            elif tier == 3:
                mons = BLUE_CORE[3] + BLUE_PKG[3][pk] + [BLUE_FLEX[3]["SCOTT"], BLUE_ACE[3]]
            else:
                mons = BLUE_CORE[tier] + [BLUE_ALA[tier]] + BLUE_PKG[tier][pk] + [BLUE_FLEX[tier][st], BLUE_ACE[tier]]
            ai = {1: "RV", 2: "RV", 3: "RV", 4: "B", 5: "E"}[tier]
            T(f"T-BLUE-T{tier}{pk}" + ("" if tier < 4 else f"-{st}"), nid(), "BLUE", "Rival Late Frlg",
              "Rival Late Frlg" if tier < 4 else "Champion Rival Frlg", "Male", "Male", ai, _cap[tier], mons,
              mods=["Risky"], note=f"{_where[tier]} ; paquet {pk} ; {st}")

# ================================================================ C-11 FLORA (Rempart)
T("T-FLORA-T1", nid(), "FLORA", "Pkmn Trainer 2" if False else "Rival", "May", "Female", "Female", "G1", 14,
  ["Zigzagoon | Pickup | Jolly | Tackle / Growl / Tail Whip / Headbutt | 11 | P",
   "Poochyena | Quick Feet | Adamant | Tackle / Howl / Bite / Leer | 12 | P",
   "Taillow | Guts | Jolly | Peck / Quick Attack / Growl / Wing Attack | 14 | P"], note="Bois Clémenti ch.1 (refusable)")
T("T-FLORA-T2", nid(), "FLORA", RIVAL, "May", "Female", "Female", "G2", 32,
  ["Mightyena | Intimidate | Adamant | Crunch / Fire Fang / Howl / Take Down | 31 | P",
   "Torkoal | White Smoke | Bold | Flamethrower / Body Slam / Protect / Will-O-Wisp | 31 | D",
   "Zangoose | Immunity | Jolly | Crush Claw / Slash / Quick Attack / Swords Dance | 32 | P",
   "Swellow @ Sharp Beak | Guts | Jolly | Aerial Ace / Quick Attack / Wing Attack / Endeavor | 33 | P"],
  note="Vergazon ch.7 (brigade, natifs)")
T("T-FLORA-T5-FIDELE", nid(), "FLORA", RIVAL, "May", "Female", "Female", "E", 75,
  ["Mightyena @ Sitrus Berry | Intimidate | Adamant | Crunch / Play Rough / Sucker Punch / Fire Fang | 75 | T",
   "Torkoal @ Heat Rock | Drought | Bold | Lava Plume / Stealth Rock / Rapid Spin / Yawn | 75 | D",
   "Breloom @ Focus Sash | Technician | Jolly | Mach Punch / Bullet Seed / Rock Tomb / Spore | 76 | P",
   "Zangoose @ Toxic Orb | Toxic Boost | Jolly | Facade / Close Combat / Knock Off / Quick Attack | 76 | P",
   "Manectric @ Magnet | Lightning Rod | Timid | Thunderbolt / Volt Switch / Flamethrower / Overheat | 75 | S",
   "Swellow @ Flame Orb | Guts | Jolly | Facade / Brave Bird / Quick Attack / U-turn | 77 | P"], note="postgame, Flora obéit")
T("T-FLORA-T5-BASCULEE", nid(), "FLORA", RIVAL, "May", "Female", "Female", "E", 75,
  ["Mightyena @ Sitrus Berry | Intimidate | Adamant | Crunch / Play Rough / Sucker Punch / Fire Fang | 75 | T",
   "Sawsbuck @ Life Orb | Sap Sipper | Jolly | Horn Leech / Double-Edge / Jump Kick / Swords Dance | 75 | P",
   "Leavanny @ Focus Sash | Swarm | Jolly | Leaf Blade / X-Scissor / Sticky Web / Swords Dance | 76 | P",
   "Zangoose @ Toxic Orb | Toxic Boost | Jolly | Facade / Close Combat / Knock Off / Quick Attack | 76 | P",
   "Manectric @ Magnet | Lightning Rod | Timid | Thunderbolt / Volt Switch / Flamethrower / Overheat | 75 | S",
   "Swellow @ Flame Orb | Guts | Jolly | Facade / Brave Bird / Quick Attack / U-turn | 77 | P"],
  note="postgame, Flora a désobéi : arrivants de Vergazon")

# ================================================================ C-33 TIMMY (sélecteur : arrivant sauvé)
_timmy4 = ["Roserade @ Sitrus Berry | Natural Cure | Timid | Giga Drain / Sludge Bomb / Leech Seed / Toxic Spikes | 56 | S",
           "Altaria @ Leftovers | Natural Cure | Bold | Dragon Pulse / Moonblast / Roost / Cotton Guard | 57 | D",
           "Magnezone @ Magnet | Magnet Pull | Modest | Thunderbolt / Flash Cannon / Volt Switch / Thunder Wave | 57 | S"]
T("T-TIMMY-T4-SAUVE", "TRAINER_WALLY_VR_1", "TIMMY", RIVAL, "Wally", "Male", "Male", "G2", 56,
  _timmy4 + ["Simisage @ Life Orb | Gluttony | Jolly | Seed Bomb / Gunk Shot / Knock Off / Acrobatics | 56 | P",
             "Gallade @ Galladite | Justified | Adamant | Sacred Sword / Psycho Cut / Leaf Blade / Swords Dance | 58 | P"],
  note="Route Victoire ch.14 (D124, refusable) ; son arrivant Feuillajou sauvé à Vergazon")
T("T-TIMMY-T4-PERDU", "TRAINER_WALLY_VR_2", "TIMMY", RIVAL, "Wally", "Male", "Male", "G2", 56,
  _timmy4 + ["Delcatty @ Sitrus Berry | Normalize | Jolly | Fake Out / Double-Edge / Play Rough / Wild Charge | 56 | P",
             "Gallade @ Galladite | Justified | Adamant | Sacred Sword / Psycho Cut / Leaf Blade / Swords Dance | 58 | P"],
  note="Route Victoire ch.14 (D124, refusable) ; arrivant abattu : il s'entraîne seul")
_timmy5 = ["Altaria @ Leftovers | Natural Cure | Bold | Dragon Pulse / Moonblast / Roost / Cotton Guard | 75 | D",
           "Roserade @ Focus Sash | Natural Cure | Timid | Leaf Storm / Sludge Bomb / Spikes / Synthesis | 75 | S",
           "Magnezone @ Choice Specs | Magnet Pull | Modest | Thunderbolt / Flash Cannon / Volt Switch / Tri Attack | 76 | S",
           "Delcatty @ Sitrus Berry | Normalize | Jolly | Fake Out / Double-Edge / Play Rough / Wild Charge | 75 | P"]
T("T-TIMMY-T5-SAUVE", "TRAINER_WALLY_VR_3", "TIMMY", RIVAL, "Wally", "Male", "Male", "E", 75,
  _timmy5 + ["Simisage @ Life Orb | Gluttony | Jolly | Seed Bomb / Gunk Shot / Knock Off / Nasty Plot | 76 | P",
             "Gallade @ Galladite | Justified | Adamant | Sacred Sword / Psycho Cut / Leaf Blade / Swords Dance | 78 | P"])
T("T-TIMMY-T5-PERDU", "TRAINER_WALLY_VR_4", "TIMMY", RIVAL, "Wally", "Male", "Male", "E", 75,
  _timmy5 + ["Gardevoir @ Choice Scarf | Trace | Timid | Moonblast / Psychic / Mystical Fire / Trick | 76 | S",
             "Gallade @ Galladite | Justified | Adamant | Sacred Sword / Psycho Cut / Leaf Blade / Swords Dance | 78 | P"])

# ================================================================ CHAMPIONS DE HOENN (badges ; T5 au postgame)
T("T-ROXANNE-T1", "TRAINER_ROXANNE_1", "ROXANNE", "Leader", "Leader Roxanne", "Female", "Female", "G1", 14,
  ["Geodude | Sturdy | Impish | Tackle / Defense Curl / Rock Throw / Rock Tomb | 12 | B",
   "Aron | Sturdy | Impish | Tackle / Harden / Metal Claw / Headbutt | 13 | B",
   "Nosepass @ Oran Berry | Sturdy | Bold | Rock Tomb / Thunder Wave / Harden / Tackle | 15 | B"],
  items="Potion", mods=["Conservative"], note="badge 1 ; Fermeté = leçon")
T("T-ROXANNE-T5", lrm("ROXANNE", 2), "ROXANNE", "Leader", "Leader Roxanne", "Female", "Female", "E", 75,
  ["Golem @ Custap Berry | Sturdy | Adamant | Stealth Rock / Earthquake / Stone Edge / Explosion | 75 | T",
   "Cradily @ Leftovers | Storm Drain | Calm | Giga Drain / Recover / Rock Slide / Toxic | 75 | D",
   "Armaldo @ Life Orb | Swift Swim | Adamant | Stone Edge / X-Scissor / Earthquake / Rapid Spin | 76 | P",
   "Aggron @ Weakness Policy | Rock Head | Adamant | Head Smash / Heavy Slam / Earthquake / Rock Polish | 76 | T",
   "Solrock @ Sitrus Berry | Levitate | Relaxed | Rock Slide / Flare Blitz / Trick Room / Stealth Rock | 75 | B",
   "Probopass @ Leftovers | Magnet Pull | Calm | Power Gem / Earth Power / Volt Switch / Thunder Wave | 78 | D"],
  items="Max Potion / Max Potion", mods=["Conservative"])

T("T-BASTIEN-T1", "TRAINER_BRAWLY_1", "BASTIEN", "Leader", "Leader Brawly", "Male", "Male", "G1", 18,
  ["Mankey | Vital Spirit | Jolly | Karate Chop / Fury Swipes / Low Kick / Focus Energy | 17 | P",
   "Machop | Guts | Adamant | Karate Chop / Low Kick / Leer / Focus Energy | 17 | P",
   "Makuhita @ Sitrus Berry | Thick Fat | Adamant | Arm Thrust / Bulk Up / Fake Out / Vital Throw | 19 | T"],
  items="Super Potion", mods=["Risky"], note="badge 2 ; Gonflette = leçon")
T("T-BASTIEN-T5", lrm("BRAWLY", 2), "BASTIEN", "Leader", "Leader Brawly", "Male", "Male", "E", 75,
  ["Hitmontop @ Leftovers | Intimidate | Impish | Fake Out / Close Combat / Rapid Spin / Sucker Punch | 75 | B",
   "Poliwrath @ Sitrus Berry | Swift Swim | Adamant | Waterfall / Close Combat / Ice Punch / Bulk Up | 75 | T",
   "Lucario @ Life Orb | Inner Focus | Timid | Aura Sphere / Flash Cannon / Vacuum Wave / Nasty Plot | 76 | S",
   "Conkeldurr @ Flame Orb | Guts | Adamant | Mach Punch / Drain Punch / Knock Off / Ice Punch | 76 | T",
   "Hariyama @ Assault Vest | Thick Fat | Adamant | Close Combat / Knock Off / Heavy Slam / Bullet Punch | 75 | T",
   "Medicham @ Medichamite | Pure Power | Jolly | High Jump Kick / Zen Headbutt / Ice Punch / Bullet Punch | 78 | P"],
  items="Max Potion / Max Potion", mods=["Risky"])

T("T-VOLTERE-T1", "TRAINER_WATTSON_1", "VOLTERE", "Leader", "Leader Wattson", "Male", "Male", "G2", 22,
  ["Voltorb | Static | Timid | Spark / Sonic Boom / Self-Destruct / Charge | 21 | S",
   "Emolga | Static | Jolly | Nuzzle / Acrobatics / Quick Attack / Shock Wave | 21 | P",
   "Magneton | Sturdy | Modest | Spark / Sonic Boom / Thunder Wave / Metal Sound | 22 | U",
   "Manectric @ Sitrus Berry | Lightning Rod | Timid | Shock Wave / Bite / Howl / Quick Attack | 23 | S"],
  items="Super Potion / Super Potion", mods=["Will Suicide"], note="badge 3 ; Paratonnerre, paralysie, Explosion annoncée")
T("T-VOLTERE-T5", lrm("WATTSON", 2), "VOLTERE", "Leader", "Leader Wattson", "Male", "Male", "E", 75,
  ["Electrode @ Light Clay | Aftermath | Timid | Reflect / Light Screen / Volt Switch / Explosion | 75 | X",
   "Emolga @ Leftovers | Motor Drive | Jolly | Nuzzle / Acrobatics / U-turn / Roost | 75 | X",
   "Rotom-Heat @ Choice Scarf | Levitate | Timid | Overheat / Volt Switch / Trick / Thunderbolt | 76 | S",
   "Magnezone @ Assault Vest | Magnet Pull | Modest | Thunderbolt / Flash Cannon / Body Press / Volt Switch | 76 | U",
   "Electivire @ Life Orb | Motor Drive | Adamant | Wild Charge / Ice Punch / Earthquake / Cross Chop | 75 | P",
   "Manectric @ Manectite | Lightning Rod | Timid | Thunderbolt / Overheat / Volt Switch / Snarl | 78 | S"],
  items="Max Potion / Max Potion", mods=["Will Suicide"])

T("T-ADRIANE-T2", "TRAINER_FLANNERY_1", "ADRIANE", "Leader", "Leader Flannery", "Female", "Female", "G2", 29,
  ["Torkoal | Drought | Bold | Flame Wheel / Body Slam / Will-O-Wisp / Curse | 29 | D",
   "Numel | Simple | Modest | Flame Burst / Magnitude / Growth / Amnesia | 28 | U",
   "Magcargo | Flame Body | Bold | Flame Burst / Rock Slide / Amnesia / Recover | 28 | D",
   "Camerupt @ Charcoal | Solid Rock | Modest | Flame Burst / Earth Power / Rock Slide / Amnesia | 31 | U"],
  items="Super Potion / Super Potion", note="badge 4 ; soleil : 1 poseur + 2 profiteurs")
T("T-ADRIANE-T5", lrm("FLANNERY", 2), "ADRIANE", "Leader", "Leader Flannery", "Female", "Female", "E", 75,
  ["Torkoal @ Heat Rock | Drought | Bold | Lava Plume / Stealth Rock / Rapid Spin / Yawn | 75 | D",
   "Ninetales @ Sitrus Berry | Flash Fire | Timid | Flamethrower / Solar Beam / Nasty Plot / Will-O-Wisp | 75 | S",
   "Coalossal @ Heavy-Duty Boots | Flash Fire | Relaxed | Rapid Spin / Stealth Rock / Flare Blitz / Stone Edge | 75 | B",
   "Volcarona @ Heavy-Duty Boots | Flame Body | Timid | Quiver Dance / Fiery Dance / Bug Buzz / Giga Drain | 76 | S",
   "Talonflame @ Choice Band | Gale Wings | Adamant | Brave Bird / Flare Blitz / U-turn / Swords Dance | 76 | P",
   "Camerupt @ Cameruptite | Solid Rock | Modest | Eruption / Earth Power / Fire Blast / Ancient Power | 78 | U"],
  items="Max Potion / Max Potion")

T("T-NORMAN-T2", "TRAINER_NORMAN_1", "NORMAN", "Leader", "Leader Norman", "Male", "Male", "G2", 33,
  ["Vigoroth | Vital Spirit | Jolly | Slash / Bulk Up / Encore / Fury Swipes | 32 | P",
   "Linoone | Gluttony | Jolly | Headbutt / Slash / Pin Missile / Belly Drum | 32 | P",
   "Exploud | Scrappy | Modest | Hyper Voice / Bite / Stomp / Howl | 32 | U",
   "Slaking @ Sitrus Berry | Truant | Adamant | Body Slam / Slack Off / Shadow Claw / Facade | 35 | T"],
  items="Super Potion / Super Potion", note="badge 5 ; Paresse = attendre est un coup ; Querelleur contre les Spectres")
T("T-NORMAN-T5", lrm("NORMAN", 2), "NORMAN", "Leader", "Leader Norman", "Male", "Male", "E", 75,
  ["Kecleon @ Leftovers | Protean | Adamant | Knock Off / Shadow Sneak / Drain Punch / Stealth Rock | 75 | B",
   "Linoone @ Sitrus Berry | Gluttony | Jolly | Belly Drum / Extreme Speed / Seed Bomb / Shadow Claw | 75 | P",
   "Exploud @ Choice Specs | Scrappy | Modest | Boomburst / Fire Blast / Focus Blast / Surf | 75 | S",
   "Zangoose @ Toxic Orb | Toxic Boost | Jolly | Facade / Close Combat / Knock Off / Quick Attack | 76 | P",
   "Swellow @ Flame Orb | Guts | Jolly | Facade / Brave Bird / Quick Attack / U-turn | 76 | P",
   "Slaking @ Choice Band | Truant | Adamant | Giga Impact / Earthquake / Knock Off / Shadow Claw | 78 | T"],
  items="Max Potion / Max Potion")

T("T-ALIZEE-T2", "TRAINER_WINONA_1", "ALIZEE", "Leader", "Leader Winona", "Female", "Female", "G2", 37,
  ["Skarmory | Sturdy | Impish | Spikes / Steel Wing / Whirlwind / Air Cutter | 36 | B",
   "Pelipper | Keen Eye | Bold | Water Pulse / Air Cutter / Protect / Stockpile | 35 | D",
   "Tropius | Chlorophyll | Adamant | Leaf Tornado / Air Slash / Stomp / Synthesis | 36 | B",
   "Swellow | Guts | Jolly | Aerial Ace / Quick Attack / Endeavor / Agility | 36 | P",
   "Altaria @ Sitrus Berry | Natural Cure | Adamant | Dragon Dance / Dragon Breath / Aerial Ace / Roost | 39 | T"],
  items="Super Potion / Super Potion", note="badge 6 ; Picots + Cyclone : nettoyer (Tour Rapide) ou ignorer")
T("T-ALIZEE-T5", lrm("WINONA", 2), "ALIZEE", "Leader", "Leader Winona", "Female", "Female", "E", 75,
  ["Skarmory @ Rocky Helmet | Sturdy | Impish | Spikes / Brave Bird / Roost / Whirlwind | 75 | B",
   "Xatu @ Leftovers | Magic Bounce | Timid | Psychic / Heat Wave / Roost / U-turn | 75 | D",
   "Pelipper @ Damp Rock | Drizzle | Bold | Hurricane / Scald / Roost / U-turn | 75 | D",
   "Tropius @ Sitrus Berry | Harvest | Impish | Air Slash / Leaf Blade / Synthesis / Dragon Dance | 75 | B",
   "Swellow @ Flame Orb | Guts | Jolly | Facade / Brave Bird / Quick Attack / U-turn | 76 | P",
   "Altaria @ Altarianite | Natural Cure | Adamant | Dragon Dance / Return / Earthquake / Roost | 78 | T"],
  items="Max Potion / Max Potion")

T("T-LEVYTATIA-T3", "TRAINER_TATE_AND_LIZA_1", "LEVY&TATIA", "Leader", "Leader Tate And Liza", "Male", "Female", "G2", 44,
  ["Solrock | Levitate | Relaxed | Trick Room / Rock Slide / Psychic / Flare Blitz | 44 | B",
   "Lunatone | Levitate | Quiet | Trick Room / Psychic / Ice Beam / Moonblast | 44 | U",
   "Claydol @ Sitrus Berry | Levitate | Quiet | Earth Power / Psychic / Ally Switch / Reflect | 45 | U",
   "Farigiraf @ Sitrus Berry | Armor Tail | Quiet | Twin Beam / Hyper Voice / Trick Room / Protect | 46 | U"],
  items="Hyper Potion / Hyper Potion", double=True, mods=["Omniscient", "Double Ace Pokemon"],
  note="badge 7 (double) ; Distorsion ; télépathes : omniscients (annoncé)")
T("T-LEVYTATIA-T5", lrm("TATE_AND_LIZA", 2), "LEVY&TATIA", "Leader", "Leader Tate And Liza", "Male", "Female", "E", 75,
  ["Indeedee-F @ Psychic Seed | Psychic Surge | Bold | Follow Me / Expanding Force / Helping Hand / Protect | 75 | D",
   "Armarouge @ Life Orb | Flash Fire | Quiet | Expanding Force / Armor Cannon / Trick Room / Protect | 75 | U",
   "Solrock @ Sitrus Berry | Levitate | Relaxed | Trick Room / Rock Slide / Flare Blitz / Protect | 75 | B",
   "Lunatone @ Sitrus Berry | Levitate | Quiet | Trick Room / Psychic / Ice Beam / Protect | 75 | U",
   "Farigiraf @ Leftovers | Armor Tail | Quiet | Twin Beam / Hyper Voice / Trick Room / Protect | 76 | U",
   "Gardevoir @ Gardevoirite | Trace | Quiet | Hyper Voice / Expanding Force / Mystical Fire / Protect | 78 | U"],
  items="Max Potion / Max Potion", double=True, mods=["Omniscient", "Double Ace Pokemon"])

T("T-JUAN-T3", "TRAINER_JUAN_1", "JUAN", "Leader", "Leader Juan", "Male", "Male", "G2", 51,
  ["Floatzel | Water Veil | Jolly | Bulk Up / Baton Pass / Aqua Jet / Waterfall | 50 | P",
   "Whiscash | Oblivious | Adamant | Dragon Dance / Earthquake / Waterfall / Zen Headbutt | 50 | T",
   "Walrein | Thick Fat | Modest | Surf / Ice Beam / Protect / Rest | 51 | U",
   "Crawdaunt @ Life Orb | Adaptability | Adamant | Crabhammer / Knock Off / Swords Dance / Aqua Jet | 51 | P",
   "Kingdra @ Sitrus Berry | Swift Swim | Adamant | Dragon Dance / Waterfall / Outrage / Iron Head | 53 | P"],
  items="Hyper Potion / Hyper Potion", mods=["Conservative", "Prefer Baton Pass", "Force Setup First Turn"],
  note="badge 8 ; chaînes de boosts et Relais : Buée Noire, Hurlement, Inconscient, Provoc")
T("T-JUAN-T5", lrm("JUAN", 2), "JUAN", "Leader", "Leader Juan", "Male", "Male", "E", 75,
  ["Floatzel @ Focus Sash | Water Veil | Jolly | Bulk Up / Baton Pass / Aqua Jet / Wave Crash | 75 | P",
   "Lanturn @ Leftovers | Volt Absorb | Calm | Scald / Thunderbolt / Volt Switch / Heal Bell | 75 | D",
   "Whiscash @ Sitrus Berry | Oblivious | Adamant | Dragon Dance / Earthquake / Waterfall / Stone Edge | 75 | T",
   "Walrein @ Leftovers | Thick Fat | Calm | Surf / Ice Beam / Protect / Rest | 76 | D",
   "Crawdaunt @ Life Orb | Adaptability | Adamant | Crabhammer / Knock Off / Swords Dance / Aqua Jet | 76 | P",
   "Kingdra @ Life Orb | Swift Swim | Adamant | Dragon Dance / Waterfall / Outrage / Iron Head | 78 | P"],
  items="Max Potion / Max Potion", mods=["Conservative", "Prefer Baton Pass"])

# ================================================================ MISSION INDIGO (Défis, refusables)
T("T-PIERRE-T1-SANS", nid(), "PIERRE", "Leader Frlg", "Leader Brock Frlg", "Male", "Male", "G2", 18,
  ["Geodude | Sturdy | Impish | Rock Throw / Magnitude / Defense Curl / Rollout | 16 | B",
   "Sudowoodo | Sturdy | Adamant | Rock Throw / Low Kick / Flail / Mimic | 16 | B",
   "Onix @ Sitrus Berry | Sturdy | Impish | Rock Tomb / Bind / Dragon Breath / Harden | 19 | B"],
  note="Défi ch.1 (mines), arrivant non sauvé")
T("T-PIERRE-T1-AVEC", nid(), "PIERRE", "Leader Frlg", "Leader Brock Frlg", "Male", "Male", "G2", 18,
  ["Geodude | Sturdy | Impish | Rock Throw / Magnitude / Defense Curl / Rollout | 16 | B",
   "Rolycoly | Steam Engine | Bold | Rapid Spin / Smack Down / Smokescreen / Ancient Power | 16 | B",
   "Sudowoodo | Sturdy | Adamant | Rock Throw / Low Kick / Flail / Mimic | 16 | B",
   "Onix @ Sitrus Berry | Sturdy | Impish | Rock Tomb / Bind / Dragon Breath / Harden | 19 | B"],
  note="Défi ch.1, Charbi sauvé aux mines")
_brock5 = ["Golem @ Custap Berry | Sturdy | Adamant | Stealth Rock / Earthquake / Stone Edge / Explosion | 75 | T",
           "Kabutops @ Life Orb | Swift Swim | Adamant | Stone Edge / Waterfall / Rapid Spin / Swords Dance | 75 | P",
           "Omastar @ White Herb | Shell Armor | Modest | Shell Smash / Hydro Pump / Ancient Power / Ice Beam | 76 | S",
           "Sudowoodo @ Leftovers | Rock Head | Adamant | Head Smash / Wood Hammer / Sucker Punch / Stealth Rock | 75 | T"]
T("T-PIERRE-T5-SANS", nid(), "PIERRE", "Leader Frlg", "Leader Brock Frlg", "Male", "Male", "E", 75,
  _brock5 + ["Carbink @ Leftovers | Sturdy | Bold | Moonblast / Power Gem / Reflect / Light Screen | 75 | B",
             "Steelix @ Steelixite | Sturdy | Impish | Heavy Slam / Earthquake / Stealth Rock / Rock Tomb | 78 | B"])
T("T-PIERRE-T5-AVEC", nid(), "PIERRE", "Leader Frlg", "Leader Brock Frlg", "Male", "Male", "E", 75,
  _brock5 + ["Coalossal @ Heavy-Duty Boots | Steam Engine | Relaxed | Rapid Spin / Flare Blitz / Stone Edge / Will-O-Wisp | 75 | B",
             "Steelix @ Steelixite | Sturdy | Impish | Heavy Slam / Earthquake / Stealth Rock / Rock Tomb | 78 | B"])

T("T-ALDO-T1", nid(), "ALDO", "Elite Four Frlg", "Elite Four Bruno Frlg", "Male", "Male", "G2", 20,
  ["Onix | Sturdy | Impish | Rock Tomb / Bind / Harden / Rock Throw | 18 | B",
   "Hitmonchan | Iron Fist | Adamant | Mach Punch / Thunder Punch / Ice Punch / Fire Punch | 19 | P",
   "Hitmonlee | Limber | Adamant | Double Kick / Rock Smash / Revenge / Meditate | 19 | P",
   "Machoke @ Sitrus Berry | Guts | Adamant | Karate Chop / Rock Tomb / Bulk Up / Low Sweep | 21 | T"],
  note="Défi ch.2 Myokara (refusable)")
T("T-ALDO-T3", nid(), "ALDO", "Elite Four Frlg", "Elite Four Bruno Frlg", "Male", "Male", "G2", 49,
  ["Hitmontop | Intimidate | Impish | Fake Out / Close Combat / Rapid Spin / Sucker Punch | 48 | B",
   "Hitmonlee @ Life Orb | Reckless | Adamant | High Jump Kick / Knock Off / Stone Edge / Blaze Kick | 48 | P",
   "Hitmonchan @ Assault Vest | Iron Fist | Adamant | Drain Punch / Mach Punch / Ice Punch / Thunder Punch | 48 | T",
   "Steelix @ Leftovers | Sturdy | Impish | Heavy Slam / Earthquake / Stealth Rock / Roar | 49 | B",
   "Machamp @ Sitrus Berry | Guts | Adamant | Close Combat / Knock Off / Bullet Punch / Stone Edge | 51 | T"],
  items="Hyper Potion / Hyper Potion", note="Tréfonds ch.11 (escorte) ou finale du Tournoi T3")
T("T-ALDO-T5", nid(), "ALDO", "Elite Four Frlg", "Elite Four Bruno Frlg", "Male", "Male", "E", 75,
  ["Hitmontop @ Leftovers | Intimidate | Impish | Fake Out / Close Combat / Rapid Spin / Sucker Punch | 75 | B",
   "Hitmonlee @ Life Orb | Reckless | Adamant | High Jump Kick / Knock Off / Stone Edge / Blaze Kick | 75 | P",
   "Hitmonchan @ Assault Vest | Iron Fist | Adamant | Drain Punch / Mach Punch / Ice Punch / Thunder Punch | 75 | T",
   "Steelix @ Leftovers | Sturdy | Impish | Heavy Slam / Earthquake / Stealth Rock / Roar | 76 | B",
   "Annihilape @ Leftovers | Defiant | Careful | Rage Fist / Drain Punch / Bulk Up / Taunt | 76 | B",
   "Machamp @ Flame Orb | Guts | Adamant | Close Combat / Knock Off / Bullet Punch / Facade | 78 | T"])

T("T-MAJORBOB-T1", nid(), "MAJOR BOB", "Leader Frlg", "Leader Lt Surge Frlg", "Male", "Male", "G2", 22,
  ["Voltorb | Soundproof | Timid | Spark / Sonic Boom / Charge / Screech | 21 | S",
   "Magnemite | Sturdy | Modest | Spark / Sonic Boom / Thunder Wave / Metal Sound | 21 | S",
   "Electabuzz | Static | Jolly | Thunder Punch / Quick Attack / Low Kick / Leer | 21 | P",
   "Raichu @ Sitrus Berry | Static | Jolly | Spark / Quick Attack / Fake Out / Electroweb | 23 | P"],
  double=True, note="exercice ch.4 Lavandia (double, refusable) : premier double, sans enjeu")
T("T-MAJORBOB-T5", nid(), "MAJOR BOB", "Leader Frlg", "Leader Lt Surge Frlg", "Male", "Male", "E", 75,
  ["Electrode @ Light Clay | Aftermath | Timid | Reflect / Light Screen / Volt Switch / Taunt | 75 | X",
   "Jolteon @ Choice Specs | Volt Absorb | Timid | Thunderbolt / Shadow Ball / Volt Switch / Hyper Voice | 75 | S",
   "Magnezone @ Leftovers | Magnet Pull | Modest | Thunderbolt / Flash Cannon / Body Press / Volt Switch | 75 | U",
   "Electivire @ Life Orb | Motor Drive | Adamant | Wild Charge / Ice Punch / Earthquake / Cross Chop | 76 | P",
   "Ampharos @ Assault Vest | Static | Modest | Thunderbolt / Dragon Pulse / Focus Blast / Volt Switch | 76 | U",
   "Raichu @ Life Orb | Lightning Rod | Timid | Thunderbolt / Grass Knot / Focus Blast / Nasty Plot | 78 | S"],
  double=True)

T("T-ERIKA-T2-MARCHE", nid(), "ERIKA", "Leader Frlg", "Leader Erika Frlg", "Female", "Female", "G2", 33,
  ["Tangela | Chlorophyll | Bold | Mega Drain / Stun Spore / Ancient Power / Knock Off | 31 | B",
   "Victreebel | Chlorophyll | Adamant | Razor Leaf / Sludge Bomb / Sleep Powder / Knock Off | 32 | P",
   "Vileplume | Chlorophyll | Modest | Mega Drain / Acid / Stun Spore / Moonblast | 32 | U",
   "Lilligant @ Miracle Seed | Own Tempo | Modest | Petal Dance / Quiver Dance / Giga Drain / Stun Spore | 34 | S"],
  mods=["Prefer Status Moves"], note="Défi ch.7 Vergazon ; contrat de parfum signé (Chlorobule)")
T("T-ERIKA-T2-INTEG", nid(), "ERIKA", "Leader Frlg", "Leader Erika Frlg", "Female", "Female", "G2", 33,
  ["Tangela | Chlorophyll | Bold | Mega Drain / Stun Spore / Ancient Power / Knock Off | 31 | B",
   "Victreebel | Chlorophyll | Adamant | Razor Leaf / Sludge Bomb / Sleep Powder / Knock Off | 32 | P",
   "Roselia | Natural Cure | Modest | Magical Leaf / Toxic Spikes / Stun Spore / Leech Seed | 32 | S",
   "Vileplume @ Miracle Seed | Chlorophyll | Modest | Giga Drain / Sludge Bomb / Moonblast / Stun Spore | 34 | U"],
  mods=["Prefer Status Moves"], note="Défi ch.7 Vergazon ; vergers d'abord (natifs)")
_erika5 = ["Tangrowth @ Rocky Helmet | Regenerator | Relaxed | Giga Drain / Knock Off / Leech Seed / Earthquake | 75 | B",
           "Victreebel @ Life Orb | Chlorophyll | Adamant | Power Whip / Sucker Punch / Weather Ball / Sunny Day | 75 | P",
           "Bellossom @ Leftovers | Healer | Calm | Quiver Dance / Giga Drain / Moonblast / Strength Sap | 75 | D",
           "Jumpluff @ Sitrus Berry | Infiltrator | Jolly | Sleep Powder / Leech Seed / Acrobatics / U-turn | 76 | X"]
T("T-ERIKA-T5-MARCHE", nid(), "ERIKA", "Leader Frlg", "Leader Erika Frlg", "Female", "Female", "E", 75,
  _erika5 + ["Lilligant @ Life Orb | Own Tempo | Timid | Quiver Dance / Petal Dance / Alluring Voice / Giga Drain | 76 | S",
             "Vileplume @ Black Sludge | Effect Spore | Calm | Giga Drain / Sludge Bomb / Strength Sap / Leech Seed | 78 | D"],
  mods=["Prefer Status Moves"])
T("T-ERIKA-T5-INTEG", nid(), "ERIKA", "Leader Frlg", "Leader Erika Frlg", "Female", "Female", "E", 75,
  _erika5 + ["Roserade @ Focus Sash | Natural Cure | Timid | Leaf Storm / Sludge Bomb / Toxic Spikes / Shadow Ball | 76 | S",
             "Vileplume @ Black Sludge | Effect Spore | Calm | Giga Drain / Sludge Bomb / Strength Sap / Leech Seed | 78 | D"],
  mods=["Prefer Status Moves"])

T("T-KOGA-T2-PIEGE", nid(), "KOGA", "Leader Frlg", "Leader Koga Frlg", "Male", "Male", "G2", 37,
  ["Forretress | Sturdy | Relaxed | Toxic Spikes / Rapid Spin / Volt Switch / Payback | 36 | B",
   "Ariados | Insomnia | Adamant | Toxic Thread / Poison Jab / Sucker Punch / Leech Life | 36 | P",
   "Golbat | Inner Focus | Jolly | Poison Fang / Wing Attack / Confuse Ray / Haze | 37 | P",
   "Weezing @ Black Sludge | Levitate | Bold | Sludge Bomb / Will-O-Wisp / Pain Split / Toxic | 39 | B"],
  mods=["Prefer Status Moves"], note="piège de Cimetronelle ch.8, si Red lui dispute Hoopa (refusable)")
T("T-KOGA-T2-DEFI", nid(), "KOGA", "Leader Frlg", "Leader Koga Frlg", "Male", "Male", "G2", 37,
  ["Golbat | Inner Focus | Jolly | Poison Fang / Wing Attack / Bite / Haze | 36 | P",
   "Venomoth | Tinted Lens | Timid | Psybeam / Venoshock / Toxic Spikes / Supersonic | 36 | S",
   "Skuntank | Aftermath | Adamant | Poison Jab / Bite / Sucker Punch / Toxic | 36 | P",
   "Weezing @ Black Sludge | Levitate | Bold | Sludge Bomb / Will-O-Wisp / Pain Split / Haze | 38 | B"],
  note="Défi Indigo ch.8 « sans rancune » (D081, refusable) après le piège")
T("T-KOGA-T3-PROPRE", nid(), "KOGA", "Leader Frlg", "Leader Koga Frlg", "Male", "Male", "G2", 47,
  ["Crobat @ Sharp Beak | Inner Focus | Jolly | Cross Poison / Brave Bird / U-turn / Taunt | 46 | P",
   "Drapion @ Life Orb | Sniper | Adamant | Poison Fang / Knock Off / Earthquake / Swords Dance | 46 | P",
   "Toxicroak @ Black Sludge | Dry Skin | Jolly | Drain Punch / Gunk Shot / Sucker Punch / Bulk Up | 46 | P",
   "Muk @ Leftovers | Poison Touch | Adamant | Gunk Shot / Knock Off / Drain Punch / Shadow Sneak | 47 | T",
   "Weezing @ Black Sludge | Levitate | Bold | Sludge Bomb / Flamethrower / Pain Split / Will-O-Wisp | 49 | B"],
  items="Hyper Potion / Hyper Potion", note="revanche ch.10 (après W10, si le GMD retient §14 C2) ; Koga démasqué : sans piège")
T("T-KOGA-T3-PIEGES", nid(), "KOGA", "Leader Frlg", "Leader Koga Frlg", "Male", "Male", "G2", 47,
  ["Forretress @ Leftovers | Sturdy | Relaxed | Spikes / Toxic Spikes / Rapid Spin / Volt Switch | 46 | B",
   "Ariados @ Focus Sash | Insomnia | Adamant | Sticky Web / Toxic Thread / Sucker Punch / Megahorn | 46 | P",
   "Crobat @ Sharp Beak | Inner Focus | Jolly | Cross Poison / Brave Bird / U-turn / Taunt | 46 | P",
   "Drapion @ Life Orb | Sniper | Adamant | Poison Fang / Knock Off / Earthquake / Swords Dance | 47 | P",
   "Weezing @ Black Sludge | Levitate | Bold | Sludge Bomb / Will-O-Wisp / Pain Split / Toxic | 49 | B"],
  items="Hyper Potion / Hyper Potion", mods=["Prefer Status Moves"], note="revanche ch.10 (§14 C2) ; Koga couvert ou ignoré : pièges complets")
T("T-KOGA-T5", nid(), "KOGA", "Leader Frlg", "Leader Koga Frlg", "Male", "Male", "E", 75,
  ["Forretress @ Leftovers | Sturdy | Relaxed | Spikes / Toxic Spikes / Rapid Spin / Volt Switch | 75 | B",
   "Crobat @ Heavy-Duty Boots | Infiltrator | Jolly | Cross Poison / Brave Bird / U-turn / Taunt | 75 | P",
   "Drapion @ Life Orb | Sniper | Adamant | Poison Fang / Knock Off / Earthquake / Swords Dance | 75 | P",
   "Toxicroak @ Black Sludge | Dry Skin | Jolly | Drain Punch / Gunk Shot / Sucker Punch / Swords Dance | 76 | P",
   "Muk-Alola @ Assault Vest | Poison Touch | Adamant | Knock Off / Poison Jab / Drain Punch / Shadow Sneak | 76 | T",
   "Weezing @ Black Sludge | Levitate | Bold | Sludge Bomb / Will-O-Wisp / Pain Split / Toxic Spikes | 78 | B"],
  mods=["Prefer Status Moves"])

T("T-JEANNINE-T1", nid(), "JEANNINE", "Ninja Boy", "Ninja Boy", "Female", "Female", "G2", 20,
  ["Zubat | Inner Focus | Jolly | Bite / Poison Fang / Astonish / Wing Attack | 19 | P",
   "Venonat | Compound Eyes | Modest | Confusion / Poison Powder / Disable / Struggle Bug | 19 | S",
   "Spinarak | Insomnia | Adamant | Poison Sting / Night Shade / Shadow Sneak / String Shot | 19 | P",
   "Koffing @ Black Sludge | Levitate | Bold | Sludge / Toxic / Clear Smog / Self-Destruct | 21 | B"],
  note="finale du Tournoi T1, Tente de Scott (ch.3-4)")
T("T-JEANNINE-T5", nid(), "JEANNINE", "Ninja Boy", "Ninja Boy", "Female", "Female", "E", 75,
  ["Toxapex @ Black Sludge | Regenerator | Bold | Toxic Spikes / Scald / Recover / Haze | 75 | B",
   "Venomoth @ Heavy-Duty Boots | Tinted Lens | Timid | Quiver Dance / Bug Buzz / Sludge Bomb / Sleep Powder | 75 | S",
   "Ariados @ Focus Sash | Insomnia | Adamant | Sticky Web / Toxic Thread / Sucker Punch / Megahorn | 75 | P",
   "Salazzle @ Life Orb | Corrosion | Timid | Fire Blast / Sludge Wave / Nasty Plot / Protect | 76 | S",
   "Weezing @ Black Sludge | Levitate | Bold | Sludge Bomb / Will-O-Wisp / Pain Split / Flamethrower | 76 | B",
   "Crobat @ Life Orb | Infiltrator | Jolly | Cross Poison / Brave Bird / U-turn / Super Fang | 78 | P"])

T("T-MORGANE-T3", nid(), "MORGANE", "Leader Frlg", "Leader Sabrina Frlg", "Female", "Female", "G2", 44,
  ["Mr. Mime @ Light Clay | Filter | Timid | Reflect / Light Screen / Psychic / Dazzling Gleam | 43 | S",
   "Bronzong @ Leftovers | Levitate | Relaxed | Future Sight / Gyro Ball / Iron Defense / Payback | 44 | B",
   "Espathra @ Sitrus Berry | Opportunist | Timid | Lumina Crash / Dazzling Gleam / Calm Mind / Protect | 44 | S",
   "Alakazam @ Life Orb | Magic Guard | Timid | Psychic / Future Sight / Focus Blast / Calm Mind | 46 | S"],
  items="Hyper Potion / Hyper Potion", mods=["Omniscient"], note="Défi après le Mont Mémoria (ch.9-10) ; elle lit tes capacités")
T("T-MORGANE-T5", nid(), "MORGANE", "Leader Frlg", "Leader Sabrina Frlg", "Female", "Female", "E", 75,
  ["Mr. Mime @ Light Clay | Filter | Timid | Reflect / Light Screen / Psychic / Dazzling Gleam | 75 | X",
   "Bronzong @ Leftovers | Levitate | Relaxed | Future Sight / Gyro Ball / Stealth Rock / Trick Room | 75 | B",
   "Espathra @ Leftovers | Opportunist | Timid | Lumina Crash / Dazzling Gleam / Calm Mind / Protect | 75 | S",
   "Hatterene @ Sitrus Berry | Magic Bounce | Quiet | Psychic / Dazzling Gleam / Mystical Fire / Calm Mind | 76 | U",
   "Venomoth @ Heavy-Duty Boots | Tinted Lens | Timid | Quiver Dance / Bug Buzz / Psychic / Sludge Bomb | 76 | S",
   "Alakazam @ Alakazite | Magic Guard | Timid | Psychic / Shadow Ball / Focus Blast / Calm Mind | 78 | S"],
  mods=["Omniscient"])

T("T-AUGUSTE-T2", nid(), "AUGUSTE", "Leader Frlg", "Leader Blaine Frlg", "Male", "Male", "G2", 32,
  ["Rapidash | Flash Fire | Jolly | Flame Charge / Stomp / Fire Spin / Agility | 31 | P",
   "Magmar | Flame Body | Modest | Flame Burst / Confuse Ray / Smog / Fire Punch | 31 | S",
   "Camerupt | Solid Rock | Modest | Flame Burst / Earth Power / Rock Slide / Amnesia | 30 | U",
   "Arcanine @ Sitrus Berry | Intimidate | Adamant | Flame Wheel / Crunch / Extreme Speed / Roar | 33 | P"],
  items="Super Potion / Super Potion", note="Défi ch.6 Vermilava ; Camérupt prêté par Magma")
_aug5 = ["Rapidash @ Choice Band | Flash Fire | Jolly | Flare Blitz / High Horsepower / Wild Charge / Morning Sun | 75 | P",
         "Magmortar @ Assault Vest | Flame Body | Modest | Fire Blast / Thunderbolt / Focus Blast / Psychic | 75 | U",
         "Ninetales @ Heat Rock | Drought | Timid | Flamethrower / Solar Beam / Nasty Plot / Will-O-Wisp | 75 | S",
         "Flareon @ Sitrus Berry | Guts | Adamant | Flare Blitz / Facade / Superpower / Quick Attack | 76 | P"]
T("T-AUGUSTE-T5-MAGMA", nid(), "AUGUSTE", "Leader Frlg", "Leader Blaine Frlg", "Male", "Male", "E", 75,
  _aug5 + ["Camerupt @ Leftovers | Solid Rock | Modest | Earth Power / Fire Blast / Stealth Rock / Yawn | 76 | U",
           "Arcanine @ Leftovers | Intimidate | Adamant | Flare Blitz / Extreme Speed / Wild Charge / Morning Sun | 78 | T"])
T("T-AUGUSTE-T5-FUJI", nid(), "AUGUSTE", "Leader Frlg", "Leader Blaine Frlg", "Male", "Male", "E", 75,
  _aug5 + ["Marowak-Alola @ Thick Club | Rock Head | Adamant | Flare Blitz / Shadow Bone / Bonemerang / Swords Dance | 76 | T",
           "Arcanine @ Leftovers | Intimidate | Adamant | Flare Blitz / Extreme Speed / Wild Charge / Morning Sun | 78 | T"])

# ---- C-20 OLGA : « une île froide qui protège » (fiche §8.13)
T("T-OLGA-T3-AVEC", nid(), "OLGA", "Elite Four Frlg", "Elite Four Lorelei Frlg", "Female", "Female", "G2", 44,
  ["Ninetales-Alola @ Light Clay | Snow Warning | Timid | Aurora Veil / Freeze-Dry / Moonblast / Encore | 44 | S",
   "Cloyster @ White Herb | Skill Link | Jolly | Shell Smash / Icicle Spear / Rock Blast / Ice Shard | 44 | P",
   "Slowbro @ Leftovers | Regenerator | Bold | Scald / Ice Beam / Slack Off / Psyshock | 44 | B",
   "Mamoswine @ Life Orb | Thick Fat | Adamant | Icicle Crash / Earthquake / Ice Shard / Stealth Rock | 45 | P",
   "Lapras @ Sitrus Berry | Water Absorb | Modest | Freeze-Dry / Surf / Thunderbolt / Perish Song | 46 | U"],
  items="Hyper Potion / Hyper Potion", mods=["Conservative"], note="Défi ch.9-10 Nénucrique ; Lokhlass de Sevii récupérés")
T("T-OLGA-T3-SANS", nid(), "OLGA", "Elite Four Frlg", "Elite Four Lorelei Frlg", "Female", "Female", "G2", 44,
  ["Ninetales-Alola @ Light Clay | Snow Warning | Timid | Aurora Veil / Freeze-Dry / Moonblast / Encore | 44 | S",
   "Cloyster @ White Herb | Skill Link | Jolly | Shell Smash / Icicle Spear / Rock Blast / Ice Shard | 44 | P",
   "Slowbro @ Leftovers | Regenerator | Bold | Scald / Ice Beam / Slack Off / Psyshock | 44 | B",
   "Weavile @ Life Orb | Pressure | Jolly | Triple Axel / Knock Off / Ice Shard / Low Kick | 45 | P",
   "Mamoswine @ Life Orb | Thick Fat | Adamant | Icicle Crash / Earthquake / Ice Shard / Stealth Rock | 46 | P"],
  items="Hyper Potion / Hyper Potion", mods=["Conservative"], note="Défi ch.9-10 ; Lokhlass perdus : Olga chasse")
_olga5 = ["Ninetales-Alola @ Light Clay | Snow Warning | Timid | Aurora Veil / Freeze-Dry / Moonblast / Encore | 75 | S",
          "Sandslash-Alola @ Heavy-Duty Boots | Slush Rush | Jolly | Triple Axel / Iron Head / Earthquake / Rapid Spin | 75 | P",
          "Cloyster @ White Herb | Skill Link | Jolly | Shell Smash / Icicle Spear / Rock Blast / Ice Shard | 76 | P",
          "Mamoswine @ Never-Melt Ice | Thick Fat | Adamant | Icicle Crash / Earthquake / Ice Shard / Stealth Rock | 76 | P"]
T("T-OLGA-T5-AVEC", nid(), "OLGA", "Elite Four Frlg", "Elite Four Lorelei Frlg", "Female", "Female", "E", 75,
  _olga5 + ["Lapras @ Leftovers | Water Absorb | Modest | Freeze-Dry / Sparkling Aria / Thunderbolt / Perish Song | 76 | U",
            "Slowbro @ Slowbronite | Regenerator | Bold | Scald / Ice Beam / Slack Off / Calm Mind | 78 | B"],
  items="Max Potion / Max Potion", mods=["Conservative"])
T("T-OLGA-T5-SANS", nid(), "OLGA", "Elite Four Frlg", "Elite Four Lorelei Frlg", "Female", "Female", "E", 75,
  _olga5 + ["Weavile @ Choice Band | Pressure | Jolly | Triple Axel / Knock Off / Ice Shard / Low Kick | 76 | P",
            "Slowbro @ Slowbronite | Regenerator | Bold | Scald / Ice Beam / Slack Off / Calm Mind | 78 | B"],
  items="Max Potion / Max Potion", mods=["Conservative"])

T("T-ONDINE-T3", nid(), "ONDINE", "Leader Frlg", "Leader Misty Frlg", "Female", "Female", "G2", 44,
  ["Golduck | Cloud Nine | Modest | Surf / Psychic / Calm Mind / Ice Beam | 43 | S",
   "Quagsire | Unaware | Relaxed | Earthquake / Waterfall / Recover / Toxic | 44 | B",
   "Mantine | Water Absorb | Calm | Air Slash / Scald / Roost / Haze | 44 | D",
   "Starmie @ Life Orb | Analytic | Timid | Surf / Psychic / Thunderbolt / Rapid Spin | 46 | S"],
  items="Hyper Potion / Hyper Potion", note="Défi ch.9 Nénucrique (port) ; Démanta : le banc qu'elle a libéré")
T("T-ONDINE-T3-AQUA", nid(), "ONDINE", "Leader Frlg", "Leader Misty Frlg", "Female", "Female", "V", 49,
  ["Golduck | Cloud Nine | Modest | Surf / Psychic / Calm Mind / Ice Beam | 48 | S",
   "Quagsire @ Leftovers | Unaware | Relaxed | Earthquake / Waterfall / Recover / Toxic | 48 | B",
   "Mantine | Water Absorb | Calm | Air Slash / Scald / Roost / Haze | 49 | D",
   "Bruxish @ Life Orb | Strong Jaw | Jolly | Psychic Fangs / Aqua Jet / Crunch / Ice Fang | 49 | P",
   "Starmie @ Life Orb | Analytic | Timid | Hydro Pump / Psychic / Thunderbolt / Ice Beam | 51 | S"],
  note="Tréfonds ch.11, Ondine dans le camp Aqua")
_ond5 = ["Golduck @ Choice Specs | Cloud Nine | Modest | Hydro Pump / Psychic / Ice Beam / Focus Blast | 75 | S",
         "Quagsire @ Leftovers | Unaware | Relaxed | Earthquake / Scald / Recover / Toxic | 75 | B"]
T("T-ONDINE-T5-AQUA", nid(), "ONDINE", "Leader Frlg", "Leader Misty Frlg", "Female", "Female", "E", 75,
  _ond5 + ["Mantine @ Heavy-Duty Boots | Water Absorb | Calm | Hurricane / Scald / Roost / Haze | 75 | D",
           "Bruxish @ Life Orb | Strong Jaw | Jolly | Psychic Fangs / Wave Crash / Crunch / Ice Fang | 76 | P",
           "Palafin @ Choice Band | Zero to Hero | Adamant | Jet Punch / Wave Crash / Close Combat / Flip Turn | 76 | P",
           "Starmie @ Life Orb | Analytic | Timid | Hydro Pump / Psychic / Thunderbolt / Ice Beam | 78 | S"])
T("T-ONDINE-T5-MISSION", nid(), "ONDINE", "Leader Frlg", "Leader Misty Frlg", "Female", "Female", "E", 75,
  _ond5 + ["Vaporeon @ Leftovers | Water Absorb | Bold | Scald / Wish / Protect / Ice Beam | 75 | B",
           "Kingler @ Life Orb | Sheer Force | Adamant | Crabhammer / X-Scissor / Rock Slide / Agility | 76 | P",
           "Tentacruel @ Black Sludge | Clear Body | Timid | Scald / Sludge Bomb / Rapid Spin / Toxic Spikes | 76 | X",
           "Starmie @ Life Orb | Analytic | Timid | Hydro Pump / Psychic / Thunderbolt / Ice Beam | 78 | S"])

T("T-AGATHA-T3-PROFANE", nid(), "AGATHA", "Elite Four Frlg", "Elite Four Agatha Frlg", "Female", "Female", "B", 40,
  ["Arbok | Intimidate | Adamant | Poison Fang / Crunch / Glare / Coil | 39 | P",
   "Crobat | Inner Focus | Jolly | Cross Poison / Air Slash / Confuse Ray / Haze | 40 | P",
   "Mismagius | Levitate | Timid | Shadow Ball / Mystical Fire / Will-O-Wisp / Pain Split | 40 | S",
   "Spiritomb @ Leftovers | Pressure | Calm | Hex / Dark Pulse / Will-O-Wisp / Sucker Punch | 41 | D",
   "Gengar @ Life Orb | Levitate | Timid | Shadow Ball / Sludge Bomb / Hex / Destiny Bond | 42 | S"],
  items="Hyper Potion / Hyper Potion", note="Mont Mémoria ch.9, rite profané : combat d'histoire")
T("T-AGATHA-T3-RITE", nid(), "AGATHA", "Elite Four Frlg", "Elite Four Agatha Frlg", "Female", "Female", "G2", 44,
  ["Arbok | Intimidate | Adamant | Poison Fang / Crunch / Glare / Coil | 43 | P",
   "Drifblim @ Sitrus Berry | Unburden | Timid | Shadow Ball / Air Slash / Will-O-Wisp / Strength Sap | 43 | X",
   "Mismagius | Levitate | Timid | Shadow Ball / Mystical Fire / Will-O-Wisp / Pain Split | 44 | S",
   "Gengar @ Life Orb | Levitate | Timid | Shadow Ball / Sludge Bomb / Hex / Focus Blast | 46 | S"],
  items="Hyper Potion", note="Défi après le rite protégé (ch.9-10) ; elle transmet")
T("T-AGATHA-T5", nid(), "AGATHA", "Elite Four Frlg", "Elite Four Agatha Frlg", "Female", "Female", "E", 75,
  ["Arbok @ Black Sludge | Intimidate | Adamant | Gunk Shot / Glare / Coil / Sucker Punch | 75 | T",
   "Crobat @ Heavy-Duty Boots | Infiltrator | Jolly | Cross Poison / Brave Bird / U-turn / Taunt | 75 | P",
   "Drifblim @ Sitrus Berry | Unburden | Timid | Shadow Ball / Air Slash / Will-O-Wisp / Strength Sap | 75 | X",
   "Spiritomb @ Leftovers | Infiltrator | Calm | Hex / Dark Pulse / Will-O-Wisp / Pain Split | 76 | D",
   "Mismagius @ Choice Specs | Levitate | Timid | Shadow Ball / Mystical Fire / Dazzling Gleam / Trick | 76 | S",
   "Gengar @ Life Orb | Levitate | Timid | Shadow Ball / Sludge Bomb / Focus Blast / Nasty Plot | 78 | S"])

# ---- C-07 PETER : Drattak (respect du Site, ch.5) x E-ADAPT
PETER_ADAPT = {
 "A": "Archaludon @ Leftovers | Stamina | Modest | Flash Cannon / Dragon Pulse / Body Press / Thunderbolt | {} | U",
 "B": "Garchomp @ Soft Sand | Rough Skin | Jolly | Earthquake / Dragon Claw / Stone Edge / Swords Dance | {} | P",
 "C": "Hydrapple @ Sitrus Berry | Regenerator | Modest | Giga Drain / Dragon Pulse / Earth Power / Nasty Plot | {} | U"}
def _peter(cap, base, drat, pk, items):
    o = 0 if cap < 70 else 75 - cap
    l = lambda x: base + x
    mons = [f"Aerodactyl @ Focus Sash | Pressure | Jolly | Stone Edge / Earthquake / Stealth Rock / Taunt | {l(0)} | P",
            f"Charizard @ Life Orb | Blaze | Timid | Flamethrower / Air Slash / Dragon Pulse / Roost | {l(0)} | S",
            PETER_ADAPT[pk].format(l(0)),
            (f"Salamence @ Life Orb | Intimidate | Adamant | Dragon Dance / Dual Wingbeat / Earthquake / Outrage | {l(1)} | P" if drat else
             f"Dragonite @ Lum Berry | Inner Focus | Adamant | Dragon Dance / Extreme Speed / Earthquake / Fire Punch | {l(1)} | P"),
            f"Gyarados @ Gyaradosite | Intimidate | Adamant | Dragon Dance / Waterfall / Crunch / Earthquake | {l(1)} | P",
            f"Dragonite @ Weakness Policy | Multiscale | Adamant | Dragon Dance / Outrage / Extreme Speed / Fire Punch | {l(2)} | T"]
    return mons
for drat in (True, False):
    for pk in "ABC":
        T(f"T-PETER-T3{pk}-{'DRATTAK' if drat else 'KANTO'}", nid(), "PETER", "Elite Four Frlg", "Elite Four Lance Frlg",
          "Male", "Male", "B", 47, _peter(47, 46, drat, pk, ""), items="Hyper Potion / Hyper Potion",
          note=f"Défi Indigo ch.10 ; paquet {pk} ; {'Drattak du Peuple du Météore' if drat else 'sans Drattak : second Dracolosse'}")
for drat in (True, False):
    for pk in "ABC":
        T(f"T-PETER-T5{pk}-{'DRATTAK' if drat else 'KANTO'}", nid(), "PETER", "Elite Four Frlg", "Elite Four Lance Frlg",
          "Male", "Male", "E", 75, _peter(75, 75, drat, pk, ""), items="Max Potion / Max Potion",
          note=f"postgame ; paquet {pk}")

# ---- C-06 GIOVANNI : « rien d'importé » ; E-ADAPT ; jamais Mewtwo
T("T-GIOVANNI-T2", nid(), "GIOVANNI", "Boss Frlg", "Leader Giovanni Frlg", "Male", "Male", "B", 29,
  ["Persian | Technician | Jolly | Fake Out / Bite / Feint / Power Gem | 28 | P",
   "Nidoking | Sheer Force | Modest | Earth Power / Sludge Wave / Thunderbolt / Ice Beam | 29 | U",
   "Rhydon @ Eviolite | Lightning Rod | Adamant | Rock Slide / Bulldoze / Megahorn / Scary Face | 31 | T"],
  note="incognito ch.6 Chemin Ardent (refusable) ; 3 Pokémon")
GIO_ADAPT = {"A": "Honchkrow @ Life Orb | Moxie | Adamant | Brave Bird / Sucker Punch / Night Slash / Heat Wave | 76 | P",
             "B": "Hippowdon @ Leftovers | Sand Stream | Impish | Earthquake / Slack Off / Stealth Rock / Whirlwind | 76 | B",
             "C": "Tyranitar @ Chople Berry | Sand Stream | Adamant | Stone Edge / Crunch / Earthquake / Dragon Dance | 76 | T"}
for pk in "ABC":
    T(f"T-GIOVANNI-T5{pk}", nid(), "GIOVANNI", "Boss Frlg", "Leader Giovanni Frlg", "Male", "Male", "E", 75,
      ["Persian @ Choice Band | Technician | Jolly | Fake Out / Knock Off / U-turn / Play Rough | 75 | P",
       "Dugtrio @ Focus Sash | Arena Trap | Jolly | Earthquake / Sucker Punch / Stone Edge / Memento | 75 | P",
       "Nidoqueen @ Leftovers | Sheer Force | Modest | Earth Power / Sludge Wave / Ice Beam / Stealth Rock | 75 | U",
       "Nidoking @ Life Orb | Sheer Force | Timid | Earth Power / Sludge Wave / Ice Beam / Thunderbolt | 76 | S",
       GIO_ADAPT[pk],
       "Rhyperior @ Weakness Policy | Solid Rock | Adamant | Earthquake / Stone Edge / Megahorn / Rock Polish | 78 | T"],
      note=f"dernier duel, postgame ; paquet {pk}")

# ---- C-12... Pierre Rochard et Marc (Maître), C-08 Pierre Rochard T5
_pr = ["Skarmory @ Rocky Helmet | Sturdy | Impish | Spikes / Brave Bird / Roost / Whirlwind | 56 | B",
       "Claydol @ Leftovers | Levitate | Relaxed | Earthquake / Psychic / Stealth Rock / Rapid Spin | 56 | B",
       "Aggron @ Sitrus Berry | Sturdy | Adamant | Heavy Slam / Stone Edge / Earthquake / Rock Polish | 57 | T",
       "Cradily @ Leftovers | Storm Drain | Calm | Giga Drain / Rock Slide / Recover / Toxic | 57 | D"]
T("T-PIERREROCHARD-T4-PROTEGE", "TRAINER_STEVEN", "PIERRE R.", "Champion", "Steven", "Male", "Male", "E", 56,
  _pr + ["Armaldo @ Life Orb | Battle Armor | Adamant | Stone Edge / X-Scissor / Earthquake / Swords Dance | 58 | P",
         "Metagross @ Metagrossite | Clear Body | Jolly | Meteor Mash / Zen Headbutt / Earthquake / Bullet Punch | 59 | P"],
  items="Hyper Potion / Hyper Potion / Full Restore", mods=["Conservative"], note="Maître ch.14 ; il protège son père")
T("T-PIERREROCHARD-T4-ACCUSE", nid(), "PIERRE R.", "Champion", "Steven", "Male", "Male", "E", 56,
  _pr + ["Probopass @ Leftovers | Magnet Pull | Calm | Power Gem / Earth Power / Volt Switch / Thunder Wave | 58 | D",
         "Metagross @ Metagrossite | Clear Body | Jolly | Meteor Mash / Zen Headbutt / Earthquake / Bullet Punch | 59 | P"],
  items="Hyper Potion / Hyper Potion / Full Restore", mods=["Conservative"], note="Maître ch.14 ; il a accusé son père : plus de fossile de Devon")
T("T-PIERREROCHARD-T5", nid(), "PIERRE R.", "Champion", "Steven", "Male", "Male", "E", 75,
  [_lv(m, 75) for m in _pr] +
  ["Armaldo @ Life Orb | Battle Armor | Adamant | Stone Edge / X-Scissor / Earthquake / Swords Dance | 76 | P",
   "Metagross @ Metagrossite | Clear Body | Jolly | Meteor Mash / Zen Headbutt / Earthquake / Bullet Punch | 78 | P"],
  items="Max Potion / Max Potion", mods=["Conservative"])
_marc = ["Pelipper @ Damp Rock | Drizzle | Bold | Hurricane / Scald / Roost / U-turn | 56 | D",
         "Tentacruel @ Black Sludge | Clear Body | Timid | Scald / Sludge Bomb / Rapid Spin / Toxic Spikes | 56 | X",
         "Ludicolo @ Life Orb | Swift Swim | Modest | Hydro Pump / Giga Drain / Ice Beam / Fake Out | 57 | S",
         "Gyarados @ Sitrus Berry | Intimidate | Adamant | Dragon Dance / Waterfall / Earthquake / Ice Fang | 57 | P",
         "Primarina @ Leftovers | Torrent | Modest | Sparkling Aria / Moonblast / Psychic / Calm Mind | 58 | U",
         "Milotic @ Leftovers | Marvel Scale | Bold | Scald / Recover / Ice Beam / Haze | 59 | B"]
T("T-MARC-T4", "TRAINER_WALLACE", "MARC", "Champion", "Champion Wallace", "Male", "Male", "E", 56, _marc,
  items="Hyper Potion / Hyper Potion / Full Restore", note="Maître ch.14 si Pierre Rochard a démissionné (aucune Méga : la beauté sans artifice)")
T("T-MARC-T5", nid(), "MARC", "Champion", "Champion Wallace", "Male", "Male", "E", 75,
  [_lv(m, 75 + (i // 2)) for i, m in enumerate(_marc[:5])] + [_lv(_marc[5], 78)], items="Max Potion / Max Potion")

# ---- Conseil 4 de Hoenn (ch.14, T4 ; T5 postgame)
_e4 = {
 "SIDNEY": ("DAMIEN", "Elite Four Sidney", "Male", [
   "Liepard | Prankster | Timid | Fake Out / Encore / Knock Off / Thunder Wave | 56 | X",
   "Thievul @ Sitrus Berry | Stakeout | Timid | Foul Play / Nasty Plot / Dark Pulse / Parting Shot | 56 | S",
   "Mightyena @ Sitrus Berry | Intimidate | Adamant | Crunch / Play Rough / Sucker Punch / Fire Fang | 56 | T",
   "Cacturne @ Leftovers | Water Absorb | Adamant | Spikes / Seed Bomb / Sucker Punch / Drain Punch | 57 | P",
   "Shiftry @ Life Orb | Wind Rider | Adamant | Leaf Blade / Knock Off / Sucker Punch / Swords Dance | 57 | P",
   "Absol @ Life Orb | Justified | Adamant | Knock Off / Psycho Cut / Sucker Punch / Swords Dance | 58 | P"], ["Risky"]),
 "PHOEBE": ("SPECTRA", "Elite Four Phoebe", "Female", [
   "Sableye @ Leftovers | Prankster | Careful | Will-O-Wisp / Knock Off / Recover / Foul Play | 56 | D",
   "Drifblim @ Sitrus Berry | Unburden | Timid | Shadow Ball / Air Slash / Will-O-Wisp / Strength Sap | 56 | X",
   "Mimikyu @ Life Orb | Disguise | Jolly | Play Rough / Shadow Claw / Shadow Sneak / Swords Dance | 56 | P",
   "Mismagius @ Choice Specs | Levitate | Timid | Shadow Ball / Mystical Fire / Dazzling Gleam / Trick | 57 | S",
   "Dusknoir @ Leftovers | Pressure | Impish | Poltergeist / Will-O-Wisp / Pain Split / Shadow Sneak | 57 | B",
   "Banette @ Banettite | Insomnia | Adamant | Shadow Claw / Gunk Shot / Will-O-Wisp / Shadow Sneak | 58 | P"], []),
 "GLACIA": ("GLACIA", "Elite Four Glacia", "Female", [
   "Glalie @ Focus Sash | Inner Focus | Jolly | Freeze-Dry / Earthquake / Spikes / Taunt | 56 | P",
   "Walrein @ Leftovers | Thick Fat | Calm | Surf / Ice Beam / Protect / Toxic | 56 | D",
   "Avalugg @ Leftovers | Sturdy | Impish | Avalanche / Body Press / Iron Defense / Rapid Spin | 56 | B",
   "Cetitan @ Sitrus Berry | Thick Fat | Adamant | Belly Drum / Ice Shard / Icicle Crash / Earthquake | 57 | T",
   "Frosmoth @ Heavy-Duty Boots | Ice Scales | Timid | Quiver Dance / Ice Beam / Bug Buzz / Giga Drain | 57 | S",
   "Baxcalibur @ Life Orb | Thermal Exchange | Jolly | Dragon Dance / Glaive Rush / Icicle Crash / Earthquake | 58 | P"], []),
 "DRAKE": ("ARAGON", "Elite Four Drake", "Male", [
   "Altaria @ Leftovers | Natural Cure | Bold | Dragon Pulse / Moonblast / Roost / Cotton Guard | 56 | D",
   "Flygon @ Choice Scarf | Levitate | Jolly | Earthquake / Outrage / U-turn / Stone Edge | 56 | P",
   "Dragalge @ Black Sludge | Adaptability | Modest | Draco Meteor / Sludge Wave / Hydro Pump / Toxic Spikes | 56 | U",
   "Haxorus @ Life Orb | Mold Breaker | Jolly | Dragon Dance / Outrage / Earthquake / Poison Jab | 57 | P",
   "Garchomp @ Soft Sand | Rough Skin | Jolly | Earthquake / Dragon Claw / Stone Edge / Swords Dance | 57 | P",
   "Salamence @ Life Orb | Intimidate | Adamant | Dragon Dance / Dual Wingbeat / Earthquake / Outrage | 58 | P"], []),
}
for key, (nm, pic, g, mons, mods) in _e4.items():
    T(f"T-{nm}-T4", f"TRAINER_{key}", nm, "Elite Four", pic, g, "Elite Four", "E", 56, mons,
      items="Hyper Potion / Hyper Potion", mods=mods, note="Conseil 4, ch.14")
_e4_t5_ace = {"SIDNEY": "Absol @ Absolite | Justified | Jolly | Knock Off / Play Rough / Sucker Punch / Swords Dance | 78 | P",
              "PHOEBE": "Banette @ Banettite | Insomnia | Adamant | Shadow Claw / Gunk Shot / Will-O-Wisp / Shadow Sneak | 78 | P",
              "GLACIA": "Glalie @ Glalitite | Inner Focus | Jolly | Freeze-Dry / Earthquake / Return / Explosion | 78 | P",
              "DRAKE": "Salamence @ Salamencite | Intimidate | Jolly | Dragon Dance / Double-Edge / Earthquake / Roost | 78 | P"}
for key, (nm, pic, g, mons, mods) in _e4.items():
    body = [_lv(m, 75 + (i % 2)) for i, m in enumerate(mons[:5])]
    if key == "GLACIA":
        body = [_lv(mons[i], 75 + (i % 2)) for i in (1, 2, 3, 4)] + [_lv(mons[5], 77)]
    if key == "PHOEBE":
        body = [_lv(m, 75 + (i % 2)) for i, m in enumerate(mons[:5])]
    T(f"T-{nm}-T5", nid(), nm, "Elite Four", pic, g, "Elite Four", "E", 75, body + [_e4_t5_ace[key]],
      items="Max Potion / Max Potion", mods=mods)

# ================================================================ ANTAGONISTES
# ---- C-05 AMARYLLIS (Aster = son Chuchmur/Ramboum, CANON ROSA)
T("T-AMARYLLIS-T2-SEULE", nid(), "AMARYLLIS", "Dragon Tamer", "Dragon Tamer", "Female", "Female", "V", 27,
  ["Aster=Loudred | Scrappy | Modest | Uproar / Bite / Howl / Stomp | 26 | U",
   "Altaria | Natural Cure | Adamant | Dragon Breath / Peck / Mist / Take Down | 26 | T",
   "Shelgon @ Sitrus Berry | Rock Head | Adamant | Dragon Breath / Headbutt / Protect / Zen Headbutt | 28 | B"],
  mods=["Force Setup First Turn"], note="Site Météore ch.5 ; Red a désigné Aragon : elle le teste seule")
T("T-AMARYLLIS-T2-DUO", nid(), "AMARYLLIS", "Dragon Tamer", "Dragon Tamer", "Female", "Female", "V", 27,
  ["Aster=Loudred | Scrappy | Modest | Uproar / Bite / Howl / Echoed Voice | 27 | U",
   "Altaria | Natural Cure | Adamant | Dragon Breath / Peck / Mist / Take Down | 27 | T",
   "Vibrava | Levitate | Jolly | Bulldoze / Dragon Breath / Bite / Sand Tomb | 27 | P",
   "Shelgon @ Sitrus Berry | Rock Head | Adamant | Dragon Breath / Headbutt / Protect / Zen Headbutt | 29 | B"],
  double=True, note="Site Météore ch.5 ; 2 contre 1 : Red et Peter (partenaire) contre elle")
_ama = ["Tyrantrum @ Life Orb | Strong Jaw | Adamant | Psychic Fangs / Head Smash / Dragon Claw / Dragon Dance | {0} | P",
        "Noivern @ Sitrus Berry | Infiltrator | Timid | Boomburst / Air Slash / Dragon Pulse / Super Fang | {0} | S",
        "Goodra @ Assault Vest | Sap Sipper | Modest | Draco Meteor / Sludge Bomb / Thunderbolt / Fire Blast | {0} | U",
        "Aster=Exploud @ Choice Specs | Scrappy | Modest | Boomburst / Fire Blast / Focus Blast / Surf | {1} | S",
        "Altaria @ Leftovers | Natural Cure | Bold | Dragon Pulse / Moonblast / Roost / Cotton Guard | {1} | D",
        "Salamence @ Salamencite | Intimidate | Jolly | Dragon Dance / Double-Edge / Earthquake / Roost | {2} | P"]
_guzz = "Guzzlord @ Leftovers | Beast Boost | Brave | Knock Off / Dragon Tail / Heavy Slam / Drain Punch | {1} | T"
def _am(lv0, extra=False):
    m = [x.format(lv0, lv0 + 1, lv0 + 2) for x in _ama]
    if extra:
        m[4] = _guzz.format(lv0, lv0 + 1)
    return m
T("T-AMARYLLIS-T3", nid(), "AMARYLLIS", "Dragon Tamer", "Dragon Tamer", "Female", "Female", "B", 47, _am(47),
  mods=["Force Setup First Turn"], note="Centre Spatial ch.10 (après l'assaut) ; Méga-Drattak")
T("T-AMARYLLIS-T4", nid(), "AMARYLLIS", "Dragon Tamer", "Dragon Tamer", "Female", "Female", "B", 53, _am(53),
  mods=["Force Setup First Turn"], note="Pilier Céleste ch.13, PA bas")
T("T-AMARYLLIS-T4-P2", nid(), "AMARYLLIS", "Dragon Tamer", "Dragon Tamer", "Female", "Female", "B", 53, _am(53, True),
  mods=["Force Setup First Turn"], note="Pilier Céleste ch.13, PA haut : l'anomalie P2 (Engloutyran) remplace Altaria")
T("T-AMARYLLIS-T5", nid(), "AMARYLLIS", "Dragon Tamer", "Dragon Tamer", "Female", "Female", "E", 75,
  [x.format(75, 76, 78) for x in _ama], mods=["Force Setup First Turn"])

# ---- Rocket (aucun objet de sac ; aucun Mewtwo)
_ar = {"BAS": ["Arbok | Intimidate | Adamant | Gunk Shot / Glare / Crunch / Coil | {0} | P",
               "Vileplume | Chlorophyll | Calm | Giga Drain / Sludge Bomb / Stun Spore / Moonblast | {0} | D",
               "Muk | Stench | Adamant | Gunk Shot / Knock Off / Shadow Sneak / Curse | {0} | T"],
       "HAUT": ["Arbok | Intimidate | Adamant | Gunk Shot / Glare / Crunch / Coil | {0} | P",
                "Vileplume | Chlorophyll | Calm | Giga Drain / Sludge Bomb / Stun Spore / Moonblast | {0} | D",
                "Liepard | Prankster | Timid | Fake Out / Thunder Wave / Knock Off / Encore | {0} | X",
                "Grimmsnarl @ Light Clay | Prankster | Careful | Reflect / Light Screen / Spirit Break / Thunder Wave | {0} | B",
                "Muk | Stench | Adamant | Gunk Shot / Knock Off / Shadow Sneak / Curse | {0} | T"]}
_ar_ace = "Honchkrow @ Life Orb | Moxie | Adamant | Brave Bird / Sucker Punch / Night Slash / Heat Wave | {} | P"
for rk in ("BAS", "HAUT"):
    T(f"T-ARIANE-T3-RK{rk}", nid(), "ARIANE", "Team Rocket Frlg", "Rocket Grunt F Frlg", "Female", "Suspicious", "V", 47,
      [x.format(46) for x in _ar[rk]] + [_ar_ace.format(48)], mods=["Prefer Status Moves"],
      note=f"assaut du Centre Spatial ch.10 ; RK {rk}")
    T(f"T-ARIANE-T4-RK{rk}", nid(), "ARIANE", "Team Rocket Frlg", "Rocket Grunt F Frlg", "Female", "Suspicious", "B", 53,
      [x.format(53) for x in _ar[rk]] + ([] if rk == "HAUT" else ["Toxicroak | Dry Skin | Jolly | Drain Punch / Gunk Shot / Sucker Punch / Bulk Up | 53 | P"]) +
      [_ar_ace.format(55)], mods=["Prefer Status Moves"], note=f"relais, climax ch.13 ; RK {rk}")
T("T-LAMBDA-T3", "TRAINER_TABITHA_MOSSDEEP", "LAMBDA", "Team Rocket Frlg", "Leader Giovanni Frlg", "Male", "Suspicious", "V", 47,
  ["Zoroark @ Life Orb | Illusion | Timid | Night Daze / Flamethrower / Focus Blast / Nasty Plot | 47 | S",
   "Weezing | Levitate | Bold | Sludge Bomb / Will-O-Wisp / Flamethrower / Explosion | 46 | B",
   "Ditto @ Choice Scarf | Imposter | Relaxed | Transform | 46 | X",
   "Persian | Technician | Jolly | Fake Out / Bite / Feint / Power Gem | 48 | P"],
  mods=["Will Suicide"], note="faux Giovanni, Centre Spatial ch.10 ; Illusion : Zoroark apparaît en Persian")
T("T-LANCE-T1", nid(), "LANCE", "Team Rocket Frlg", "Rocket Grunt M Frlg", "Male", "Suspicious", "V", 25,
  ["Nickit | Unburden | Jolly | Quick Attack / Snarl / Thief / Assurance | 23 | P",
   "Golbat | Inner Focus | Jolly | Poison Fang / Wing Attack / Bite / Haze | 24 | P",
   "Weezing @ Black Sludge | Levitate | Bold | Sludge / Clear Smog / Toxic / Self-Destruct | 26 | B"],
  mods=["Risky"], note="raid du Tunnel Mérazon ch.4 (série sans soin)")
T("T-LANCE-T3", nid(), "LANCE", "Team Rocket Frlg", "Rocket Grunt M Frlg", "Male", "Suspicious", "V", 40,
  ["Thievul | Unburden | Timid | Foul Play / Snarl / Nasty Plot / Thief | 39 | S",
   "Swoobat | Simple | Timid | Calm Mind / Air Slash / Psychic / Heat Wave | 39 | S",
   "Skuntank | Aftermath | Adamant | Poison Jab / Crunch / Sucker Punch / Toxic | 40 | P",
   "Crobat | Inner Focus | Jolly | Cross Poison / Air Slash / Bite / Haze | 40 | P",
   "Weezing @ Black Sludge | Levitate | Bold | Sludge Bomb / Will-O-Wisp / Pain Split / Toxic | 42 | B"],
  mods=["Risky"], note="profanation du Mont Mémoria ch.9")
T("T-AMOS-T4", nid(), "AMOS", "Team Rocket Frlg", "Rocket Grunt M Frlg", "Male", "Suspicious", "V", 53,
  ["Crobat | Inner Focus | Jolly | Cross Poison / Brave Bird / U-turn / Taunt | 53 | P",
   "Weezing @ Black Sludge | Levitate | Bold | Sludge Bomb / Will-O-Wisp / Pain Split / Fire Blast | 53 | B",
   "Bisharp @ Eviolite | Defiant | Adamant | Iron Head / Sucker Punch / Knock Off / Swords Dance | 53 | P",
   "Houndoom @ Life Orb | Flash Fire | Timid | Dark Pulse / Fire Blast / Sludge Bomb / Nasty Plot | 55 | S"],
  note="climax ch.13, seulement si RK haut")

# ---- Magma / Aqua
T("T-KELVIN-T2", "TRAINER_TABITHA_MT_CHIMNEY", "KELVIN", "Magma Admin", "Magma Admin", "Male", "Magma", "V", 29,
  ["Golbat | Inner Focus | Jolly | Poison Fang / Wing Attack / Bite / Haze | 27 | P",
   "Numel | Simple | Modest | Flame Burst / Magnitude / Growth / Amnesia | 27 | U",
   "Mightyena | Intimidate | Adamant | Bite / Take Down / Howl / Fire Fang | 29 | P"], note="Mont Chimnée ch.6")
T("T-COURTNEY-T2", "TRAINER_TABITHA_MAGMA_HIDEOUT", "COURTNEY", "Magma Admin", "Magma Grunt F", "Female", "Magma", "V", 29,
  ["Koffing | Levitate | Bold | Sludge / Toxic / Clear Smog / Self-Destruct | 27 | B",
   "Mightyena | Intimidate | Adamant | Bite / Take Down / Howl / Fire Fang | 27 | P",
   "Camerupt | Solid Rock | Modest | Flame Burst / Earth Power / Rock Slide / Amnesia | 29 | U"], note="Planque Magma ch.6")
T("T-MAX-T2", "TRAINER_MAXIE_MT_CHIMNEY", "MAX", "Magma Leader", "Magma Leader Maxie", "Male", "Magma", "V", 29,
  ["Mightyena | Intimidate | Adamant | Crunch / Fire Fang / Howl / Take Down | 28 | P",
   "Krokorok | Moxie | Jolly | Bulldoze / Crunch / Sand Tomb / Swagger | 27 | P",
   "Bouffalant | Sap Sipper | Adamant | Head Charge / Revenge / Rock Slide / Scary Face | 28 | T",
   "Camerupt @ Charcoal | Solid Rock | Modest | Flame Burst / Earth Power / Rock Slide / Amnesia | 31 | U"],
  note="Mont Chimnée ch.6, si Red sabote ou dénonce la démonstration ; Frison = le troupeau déplacé")
T("T-MAX-T5", "TRAINER_MAXIE_MAGMA_HIDEOUT", "MAX", "Magma Leader", "Magma Leader Maxie", "Male", "Magma", "E", 75,
  ["Torkoal @ Heat Rock | Drought | Bold | Lava Plume / Stealth Rock / Rapid Spin / Yawn | 75 | D",
   "Mightyena @ Sitrus Berry | Intimidate | Adamant | Crunch / Play Rough / Sucker Punch / Fire Fang | 75 | T",
   "Crobat @ Heavy-Duty Boots | Infiltrator | Jolly | Cross Poison / Brave Bird / U-turn / Taunt | 75 | P",
   "Krookodile @ Choice Scarf | Moxie | Jolly | Earthquake / Knock Off / Stone Edge / Close Combat | 76 | P",
   "Bouffalant @ Choice Band | Sap Sipper | Adamant | Head Charge / Earthquake / Close Combat / Megahorn | 76 | P",
   "Camerupt @ Cameruptite | Solid Rock | Modest | Eruption / Earth Power / Fire Blast / Ancient Power | 78 | U"])
_art = {"COUPE": ["Mightyena | Intimidate | Adamant | Crunch / Play Rough / Sucker Punch / Fire Fang | 48 | T",
                  "Crobat | Inner Focus | Jolly | Cross Poison / Brave Bird / U-turn / Taunt | 49 | P",
                  "Dondozo @ Leftovers | Unaware | Impish | Wave Crash / Order Up / Rest / Sleep Talk | 49 | B",
                  "Mantine | Water Absorb | Calm | Air Slash / Scald / Roost / Haze | 48 | D",
                  "Muk | Poison Touch | Adamant | Gunk Shot / Knock Off / Drain Punch / Shadow Sneak | 48 | T"],
        "NEGOCIE": ["Mightyena | Intimidate | Adamant | Crunch / Play Rough / Sucker Punch / Fire Fang | 48 | T",
                    "Crobat | Inner Focus | Jolly | Cross Poison / Brave Bird / U-turn / Taunt | 49 | P",
                    "Wailord @ Sitrus Berry | Water Veil | Modest | Water Spout / Ice Beam / Rest / Amnesia | 48 | U",
                    "Crawdaunt | Adaptability | Adamant | Crabhammer / Knock Off / Aqua Jet / Swords Dance | 48 | P",
                    "Muk | Poison Touch | Adamant | Gunk Shot / Knock Off / Drain Punch / Shadow Sneak | 48 | T"]}
_shp = "Sharpedo @ Sharpedonite | Speed Boost | Adamant | Waterfall / Crunch / Ice Fang / Protect | {} | P"
T("T-ARTHUR-T3-COUPE", "TRAINER_ARCHIE", "ARTHUR", "Aqua Leader", "Aqua Leader Archie", "Male", "Aqua", "V", 49,
  _art["COUPE"] + [_shp.format(51)], note="Tréfonds ch.11 ; il coupe : arrivants marins libérés")
T("T-ARTHUR-T3-NEGOCIE", "TRAINER_MAXIE_MOSSDEEP", "ARTHUR", "Aqua Leader", "Aqua Leader Archie", "Male", "Aqua", "V", 49,
  _art["NEGOCIE"] + [_shp.format(51)], note="Tréfonds ch.11 ; il négocie : natifs (combat refusable)")
for st in ("COUPE", "NEGOCIE"):
    T(f"T-ARTHUR-T5-{st}", nid(), "ARTHUR", "Aqua Leader", "Aqua Leader Archie", "Male", "Aqua", "E", 75,
      [_lv(m, 75 + (i % 2)) for i, m in enumerate(_art[st])] + [_shp.format(78)])
T("T-SARAH-T2", "TRAINER_SHELLY_WEATHER_INSTITUTE", "SARAH", "Aqua Admin", "Aqua Admin F", "Female", "Aqua", "V", 35,
  ["Wailmer | Water Veil | Modest | Water Pulse / Rollout / Whirlpool / Astonish | 33 | U",
   "Mightyena | Intimidate | Adamant | Bite / Take Down / Howl / Fire Fang | 34 | P",
   "Sharpedo | Rough Skin | Adamant | Aqua Jet / Bite / Scary Face / Ice Fang | 36 | P"], note="Institut Météo ch.8")
T("T-SARAH-T3", "TRAINER_SHELLY_SEAFLOOR_CAVERN", "SARAH", "Aqua Admin", "Aqua Admin F", "Female", "Aqua", "V", 49,
  ["Toxapex | Merciless | Bold | Toxic / Scald / Recover / Haze | 48 | B",
   "Mightyena | Intimidate | Adamant | Crunch / Play Rough / Sucker Punch / Fire Fang | 48 | T",
   "Wailord | Water Veil | Modest | Water Spout / Ice Beam / Rest / Amnesia | 48 | U",
   "Sharpedo @ Life Orb | Rough Skin | Adamant | Waterfall / Crunch / Ice Fang / Aqua Jet | 50 | P"],
  note="Tréfonds ch.11, seulement si Sarah reste (sinon elle négocie)")
T("T-MATTHIEU-T3", "TRAINER_MATT", "MATTHIEU", "Aqua Admin", "Aqua Admin M", "Male", "Aqua", "V", 40,
  ["Mightyena | Intimidate | Adamant | Crunch / Fire Fang / Howl / Take Down | 39 | P",
   "Crobat | Inner Focus | Jolly | Cross Poison / Air Slash / Bite / Haze | 40 | P",
   "Wailord | Water Veil | Modest | Water Spout / Ice Beam / Rest / Amnesia | 40 | U",
   "Sharpedo @ Sitrus Berry | Rough Skin | Adamant | Waterfall / Crunch / Ice Fang / Aqua Jet | 42 | P"],
  note="Planque Aqua ch.9 (D082 b : raid de la Ligue)")

# ================================================================ POSTGAME : Chen, Zone de Combat
T("T-CHEN-T5", nid(), "PROF. CHEN", "Pkmn Prof Frlg", "Professor Oak Frlg", "Male", "Male", "E", 75,
  ["Tauros | Intimidate | Jolly | Double-Edge / Earthquake / Close Combat / Rock Slide | 76 | P",
   "Kangaskhan | Scrappy | Adamant | Double-Edge / Earthquake / Sucker Punch / Fake Out | 76 | T",
   "Exeggutor | Harvest | Modest | Giga Drain / Psychic / Sludge Bomb / Leech Seed | 76 | U",
   "Arcanine | Intimidate | Adamant | Flare Blitz / Extreme Speed / Wild Charge / Close Combat | 77 | P",
   "Gyarados | Intimidate | Adamant | Waterfall / Earthquake / Crunch / Dragon Dance | 77 | P",
   "Snorlax | Thick Fat | Adamant | Body Slam / Earthquake / Curse / Rest | 78 | T"],
  note="duel du vétéran, postgame (HYPOTHÈSE non canon) ; aucun objet tenu : « les bonnes vieilles méthodes »")
_heads = [
 ("BAYAR", "Pyramid King", "Pyramid King Brandon", "Male",
  ["Regirock @ Leftovers | Clear Body | Careful | Stone Edge / Body Press / Iron Defense / Stealth Rock | 76 | B",
   "Regice @ Leftovers | Clear Body | Calm | Ice Beam / Thunderbolt / Amnesia / Focus Blast | 76 | D",
   "Registeel @ Leftovers | Clear Body | Careful | Iron Head / Body Press / Iron Defense / Toxic | 77 | B"],
  "Voie du Désert / Pyramide ; les sceaux de Bayar (fin cachée)"),
 ("CAPUCINE", "Salon Maiden", "Salon Maiden Anabel", "Female",
  ["Espeon @ Life Orb | Magic Bounce | Timid | Psychic / Dazzling Gleam / Shadow Ball / Calm Mind | 76 | S",
   "Snorlax @ Leftovers | Thick Fat | Careful | Body Slam / Earthquake / Curse / Rest | 76 | T",
   "Gardevoir @ Choice Scarf | Trace | Timid | Moonblast / Psychic / Mystical Fire / Trick | 77 | S"],
  "Tour de Combat ; télépathe : omnisciente"),
 ("CAROLE", "Arena Tycoon", "Arena Tycoon Greta", "Female",
  ["Heracross @ Flame Orb | Guts | Jolly | Close Combat / Megahorn / Facade / Knock Off | 76 | P",
   "Umbreon @ Leftovers | Synchronize | Careful | Foul Play / Wish / Protect / Toxic | 76 | B",
   "Gallade @ Life Orb | Sharpness | Jolly | Sacred Sword / Psycho Cut / Leaf Blade / Swords Dance | 77 | P"],
  "Dojo de Combat"),
 ("TAKIM", "Dome Ace", "Dome Ace Tucker", "Male",
  ["Charizard @ Heavy-Duty Boots | Solar Power | Timid | Fire Blast / Air Slash / Focus Blast / Roost | 76 | S",
   "Swampert @ Leftovers | Damp | Relaxed | Earthquake / Scald / Stealth Rock / Flip Turn | 76 | B",
   "Salamence @ Life Orb | Intimidate | Jolly | Dragon Dance / Dual Wingbeat / Earthquake / Outrage | 77 | P"],
  "Dôme de Combat"),
 ("ESTEBAN", "Palace Maven", "Palace Maven Spenser", "Male",
  ["Shiftry @ Life Orb | Wind Rider | Adamant | Leaf Blade / Knock Off / Sucker Punch / Swords Dance | 76 | P",
   "Slaking @ Choice Band | Truant | Adamant | Giga Impact / Earthquake / Knock Off / Shadow Claw | 76 | T",
   "Arcanine @ Leftovers | Intimidate | Impish | Flare Blitz / Extreme Speed / Will-O-Wisp / Morning Sun | 77 | B"],
  "Palais de Combat"),
 ("CHARLINE", "Pike Queen", "Pike Queen Lucy", "Female",
  ["Seviper @ Life Orb | Infiltrator | Naive | Gunk Shot / Flamethrower / Earthquake / Glare | 76 | P",
   "Shuckle @ Mental Herb | Sturdy | Bold | Sticky Web / Stealth Rock / Toxic / Encore | 76 | B",
   "Milotic @ Leftovers | Marvel Scale | Bold | Scald / Recover / Ice Beam / Haze | 77 | B"],
  "Pyramide/Tube de Combat"),
]
for nm, cls, pic, g, mons, nt in _heads:
    T(f"T-{nm}-T5", nid(), nm, cls, pic, g, "Male" if g == "Male" else "Female", "Z", 75, mons,
      mods=(["Omniscient"] if nm == "CAPUCINE" else []), note=nt)

# ================================================================ PARTENAIRES (battle_partners.party)
T("P-PETER-CH5", "PARTNER_PETER_CH5", "PETER", "Elite Four Frlg", "Elite Four Lance Frlg", "Male", "Male", "G2", 27,
  ["Dragonair | Shed Skin | Adamant | Dragon Tail / Aqua Tail / Thunder Wave / Slam | 27 | P",
   "Aerodactyl | Pressure | Jolly | Rock Slide / Bite / Wing Attack / Ancient Power | 28 | P",
   "Gyarados | Intimidate | Adamant | Waterfall / Bite / Ice Fang / Dragon Rage | 28 | P"], partner=True,
  note="ch.5, Red est parti avec Peter : duo contre Amaryllis")
T("P-PIERREROCHARD-CH8", "PARTNER_STEVEN", "PIERRE R.", "Rival", "Steven", "Male", "Male", "G2", 40,
  ["Metang | Clear Body | Adamant | Meteor Mash / Zen Headbutt / Bullet Punch / Iron Defense | 40 | P",
   "Skarmory | Sturdy | Impish | Steel Wing / Air Slash / Spikes / Roost | 40 | B",
   "Aggron | Sturdy | Adamant | Iron Head / Rock Slide / Earthquake / Protect | 40 | T"], partner=True,
  note="duo ch.8 (R120, présentation de la Méga) puis ch.10 si choisi")
T("P-OLGA-CH9", "PARTNER_OLGA_CH9", "OLGA", "Elite Four Frlg", "Elite Four Lorelei Frlg", "Female", "Female", "G2", 40,
  ["Ninetales-Alola | Snow Warning | Timid | Aurora Veil / Icy Wind / Moonblast / Encore | 40 | S",
   "Cloyster | Skill Link | Jolly | Icicle Spear / Rock Blast / Ice Shard / Protect | 40 | P",
   "Slowbro | Regenerator | Bold | Scald / Ice Beam / Slack Off / Protect | 41 | B"], partner=True,
  note="coup de filet de Nénucrique ch.9 (nuit du marché, branche Olga)")
