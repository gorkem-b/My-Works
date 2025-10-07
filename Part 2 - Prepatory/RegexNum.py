import re

s = "The price is 120 dollars, and the discount is 50, saving 70 more."

n = re.findall(r'\d+', s)

m = max(map(int, n))
print(m)