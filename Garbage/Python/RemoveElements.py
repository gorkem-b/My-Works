a = [10, 20, 30, 40, 50, 60, 70]
remove = [20, 40, 60]

res = []

for val in a:
    if val not in remove:
        res.append(val)

print(res)