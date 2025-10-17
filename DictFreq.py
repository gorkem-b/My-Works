a = ['apple', 'banana', 'apple', 'orange', 'banana', 'banana']

b = {}

for c in a:
    if c in b:
        b[c] += 1
    else:
        b[c] = 1
print(b)