def isDiff0(n):
    first = 0
    second = 0
    flag = True
    while(n > 0):
        digit = n % 10
        if(flag):
            first += digit
        else:
            second += digit
        if(flag):
            flag = False
        else:
            flag = True
        n = int(n/10)
    if(first-second == 0):
        return True
    return False


n = 1243
if(isDiff0(n)):
    print("Yes")
else:
    print("No")