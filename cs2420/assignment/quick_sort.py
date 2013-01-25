# quick sort

# divide list based on pivot item. index 0
# get a smaller_than set and a greater_than set.
# first time through
# 	nothing moves on bigger than 
# 	one swap occures on smaller than
# swap pivot item with last item in smaller_than list. index 0 changes.

# TO DO: Add "modified". Implemented counting of swaps and compares.

def QuickSort(A, counts):
	QuickSortR(A, counts, 0, len(A-1))

def QuickSortR(A, counts, low, high, modified=false):
	if low >= high:
		return

	pivot = low
	sp = pivot + 1 #swap position
	for i in range(pivot+1, high+1):
		if A[i] < A[pivot]:
			A[i], A[sp] = A[sp], A[i]
	A[pivot], A[sp-1] = A[sp-1], A[pivot]

	# recurse on smaller stuff
	QuickSortR(A, low, pivot-1)

	# recurse on bigger stuff	
	QuickSortR(A, pivot+1, high)

# Modified quick sort
	# pick number in the middle, swap it with the first number, pivot from there.
	# do modified portion if new param = true.

# mid = (low+high)/2
# A[low], A[mid] = A[mid], A[low]