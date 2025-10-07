s = "GorkemVeGorkem"
d = {}
res = []

for c in s:
    d[c] = d.get(c, 0) + 1

for c, cnt in d.items():
    if cnt > 1:
        res.append(c)

print(res)