from itertools import chain
tup = ([5, 6], [6, 7, 8, 9], [3])

res = tuple(chain.from_iterable(tup))
print(res)