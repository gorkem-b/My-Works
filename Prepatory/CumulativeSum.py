import itertools
l = [1, 2, 3, 4]

cumulative_sum = list(itertools.accumulate(l))
print(cumulative_sum)