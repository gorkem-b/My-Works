import re

s1 = "Hello, World! 123 @Python$"

s2 = re.sub(r'[^a-zA-Z0-9]', '', s1)

print(s2)