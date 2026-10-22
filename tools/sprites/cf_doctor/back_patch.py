
def post(f, o):
    H = (8, 11, 12)
    # round off spiky hair tips
    for _ in range(2):
        kill = []
        for y in range(1, 63):
            for x in range(1, 63):
                if o[y][x] in H:
                    tr = sum(1 for dy in (-1, 0, 1) for dx in (-1, 0, 1) if (dx or dy) and o[y + dy][x + dx] == 0)
                    if tr >= 6:
                        kill.append((x, y))
        for x, y in kill:
            o[y][x] = 0
    # white highlights on the coat's lit upper edges
    for y in range(1, 63):
        for x in range(1, 63):
            if o[y][x] == 10 and o[y - 1][x] in (0, 15) and y > 38:
                o[y][x] = 14
    return o
