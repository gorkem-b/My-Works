import re

with open('C:/Users/user/Desktop/New Text Document.txt') as fh:
   fstring = fh.readlines()

pattern = re.compile(r'(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})')

lst=[]

for line in fstring:
   lst.append(pattern.search(line)[0])

print(lst)