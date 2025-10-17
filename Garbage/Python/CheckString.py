import re

regex = r'^[a-z]$|^([a-z]).*\1$'

def check(string):

    if re.search(regex, string):
        print(string, ": Valid")
    else:
        print(string, ": Invalid")

if __name__ == '__main__':
    check("abba")
    check("a")
    check("abcd")
