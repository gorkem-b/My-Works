from collections import Counter

s1 = "Uwu is love, UwU is life"
s2 = "What is love? Baby don't hurt me"

count = Counter(s1.split()) + Counter(s2.split())

res = [word for word in count if count[word] == 1]

print(res)