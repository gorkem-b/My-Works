import heapq

tup = (5, 20, 3, 7, 6, 8)
K = 2

smallest = heapq.nsmallest(K, tup)
largest = heapq.nlargest(K,tup)

print("K minimum elements:", smallest)
print("K maximum elements:", largest)