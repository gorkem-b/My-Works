s = "I am  best for   CS"  
li = ["best", "CS", "for"]  
k = "r"  

for word in li:
    s = s.replace(word, k)

print(s)