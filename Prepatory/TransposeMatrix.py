m = [[1, 2], [3, 4], [5, 6]]
res = [[m[j][i] for j in range(len(m))] for i in range(len(m[0]))]

for row in res:
    print(row)