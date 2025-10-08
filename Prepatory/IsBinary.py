import re

s = "101010000111"

if re.fullmatch('[01]+', s):
    print("Yes")
else:
    print("No")