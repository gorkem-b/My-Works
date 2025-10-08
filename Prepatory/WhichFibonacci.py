n, m = 4, 3  
a, b, count = 0, 1, 0  

while True:
    a, b = b, a + b

    if b % m == 0:
        count += 1

        if count == n:
            print(b)
            break