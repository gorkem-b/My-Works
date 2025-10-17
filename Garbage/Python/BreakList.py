a = [1, 2, 3, 4, 5, 6, 7, 8]
n = 3 

res = [a[i:i + n] for i in range(0, len(a), n)]
print(res)