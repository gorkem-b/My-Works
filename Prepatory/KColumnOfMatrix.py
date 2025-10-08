test_list = [[4, 5, 6], [8, 1, 10], [7, 12, 5]]

K = 2

res = []

for i in range(len(test_list)):
    res.append(test_list[i][K])

print("The Kth column of matrix is : " + str(res))