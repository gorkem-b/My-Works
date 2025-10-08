a = [[1, 4, 5], [7, 3], [4], [46, 7, 3]]
res = 1 

for sub in a:
    for ele in sub:
        res *= ele
print(res)