import re

email = "my.ownsite@our-earth.org"
valid = re.match(r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$', email)

print("Valid email address." if valid else "Invalid email address.")