s = "Gorkemullahi"
d = {}  

for char in s:  
    d[char] = d.get(char, 0) + 1 
res = min(d, key=d.get)
print(str(res))