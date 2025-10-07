import math

def is_perfect_sq(x):
    s = int(math.sqrt(x))
    return s * s == x

def is_fibonacci(n):
    return is_perfect_sq(5 * n * n + 4) or is_perfect_sq(5 * n * n - 4)

for i in range(1, 7):
    if is_fibonacci(i):
        print(f"{i} is a Fibonacci Number")
    else:
        print(f"{i} is not a Fibonacci Number")