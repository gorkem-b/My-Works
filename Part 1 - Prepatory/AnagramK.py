from collections import OrderedDict

s = "geeksforgeeks"
k = 3

freq = OrderedDict()
for char in s:
    freq[char] = freq.get(char, 0) + 1

a = [char for char, count in freq.items() if count == 1]

if k <= len(a):
    print(a[k - 1]) 
else:
    print(None)