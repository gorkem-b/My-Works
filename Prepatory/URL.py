import re

s = 'My Profile: https://obs.atauni.edu.tr in the portal of https://obs.atauni.edu.tr/ogrenci'
pattern = r'https?://\S+|www\.\S+'

print("URLs:", re.findall(pattern, s))