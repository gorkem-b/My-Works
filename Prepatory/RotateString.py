s = "AtaUNI"
d = 2

left = s[d:] + s[:d]

right = s[-d:] + s[:-d]

print("Left Rotation:", left)
print("Right Rotation:", right)