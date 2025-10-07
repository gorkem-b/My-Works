def binarypalindrome(num):
    binary = bin(num)
    binary = binary[2:]
    return binary == binary[-1::-1]

if __name__ == "__main__":
    num = 9
    print(binarypalindrome(num))
