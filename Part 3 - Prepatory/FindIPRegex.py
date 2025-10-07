import re

def Validate_It(IP):
    regex = "^((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])$"
    regex1 = "((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}"

    p = re.compile(regex)
    p1 = re.compile(regex1)

    if (re.search(p, IP)):
        return "Valid IPv4"

    elif (re.search(p1, IP)):
        return "Valid IPv6"

    return "Invalid IP"

IP = "257.120.223.13"
print(Validate_It(IP))

IP = "fffe:3465:efab:23fe:2235:6565:aaab:0001"
print(Validate_It(IP))

IP = "2F33:12a0:3Ea0:0302"
print(Validate_It(IP))
