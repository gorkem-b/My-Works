# GitHub Copilot
s = "ThisISSparta !, 123"

upper = sum(1 for c in s if c.isupper())
lower = sum(1 for c in s if c.islower())
digits = sum(1 for c in s if c.isdigit())
special = sum(1 for c in s if not c.isalnum() and not c.isspace())

print("The no. of uppercase characters is", upper)
print("The no. of lowercase characters is", lower)
print("The no. of numerical characters is", digits)
print("The no. of special characters is", special)
