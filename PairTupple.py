test_tuple1 = (4, 5)
test_tuple2 = (7, 8)

print("The original tuple 1 : " + str(test_tuple1))
print("The original tuple 2 : " + str(test_tuple2))

res = [(a, b) for a in test_tuple1 for b in test_tuple2]
res = res + [(a, b) for a in test_tuple2 for b in test_tuple1]

print("The filtered tuple : " + str(res))