# Python3 program to demonstrate working of heapq

# We use heapq class to implement Heap in Python. 
# By default Min Heap is implemented by this class. But we multiply each value by -1 so that we can use it as MaxHeap. 

from heapq import heappop, heappush, heapify

# Creating empty heap
heap = []
heapify(heap)

# Adding items to the heap using heappush
# function by multiplying them with -1
heappush(heap, -1 * 10)
heappush(heap, -1 * 30)
heappush(heap, -1 * 20)
heappush(heap, -1 * 400)

# printing the value of maximum element
print("Head value of heap : " + str(-1 * heap[0]))

# printing the elements of the heap
print("The heap elements : ")
for i in heap:
	print((-1*i), end=" ")
print("\n")

element = heappop(heap)

# printing the elements of the heap
print("The heap elements : ")
for i in heap:
	print(-1 * i, end = ' ')


# Output
# Head value of heap : 400
# The heap elements : 
# 400 30 20 10 
# The heap elements : 
# 30 10 20 