s = "abaaba"

half = len(s) // 2
sym = s[:half] == s[half:][::-1] if len(s) % 2 == 0 else s[:half] == s[half+1:][::-1]

pal = s == s[::-1]

print("Symmetrical" if sym else "Not Symmetrical")
print("Palindrome" if pal else "Not Palindrome")