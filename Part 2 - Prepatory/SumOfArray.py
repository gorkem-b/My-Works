def _sum(arr):
    sum = 0

    for x in arr:
        sum = sum + x

    return(sum)


if __name__ == "__main__":
    
    arr = [12, 3, 4, 15]
    ans = _sum(arr)
    
    print('Sum of the array is ', ans)