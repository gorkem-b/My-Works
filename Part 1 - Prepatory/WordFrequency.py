s = "hello world hello everyone"
w_freq = {}

for word in s.split():
    w_freq[word] = w_freq.get(word, 0) + 1

print(w_freq)