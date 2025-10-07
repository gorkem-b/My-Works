import itertools

s = "amk"
li = [''.join(p) for p in itertools.permutations(s)]
print(li)