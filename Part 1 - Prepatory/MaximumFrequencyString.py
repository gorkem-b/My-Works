s = "hello world"

freq = {}

for char in s:
    freq[char] = freq.get(char, 0) + 1

max_char = max(freq, key=freq.get)

print(max_char)