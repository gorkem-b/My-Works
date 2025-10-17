a = ['a', 'b', 'c', 'd']
b = [3, 1, 4, 2]

x = [val for _, val in sorted(zip(b, a))]

print(x)