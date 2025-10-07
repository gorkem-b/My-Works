a = [123, 456, 789]
res = []

for val in a:
    total = 0
    while val > 0:
        total += val % 10
        val //= 10
    res.append(total)

print(res)