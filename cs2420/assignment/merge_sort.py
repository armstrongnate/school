# merge sort
# this sort has a record of N * logN
# break 1 list into two list. subdivide until you get down to lists that are 1 big.
# compare and merge one sublist at a time.
# uses recursion

def MergeSort(A):
	if len(A) <= 1:
		return
	# divide A into two sublists
	left = A[:len(A)/2]
	right = A[len(A)/2:]
	
	# sort each half
	MergeSort(left)
	MergeSort(right)

	# merge left and right back into A
	i = 0
	j = 0
	k = 0
	while k < len(A):
		if i == len(left):
			A[k] == right[j]
			k += 1
			j += 1
		elif j == len(right):
			A[k] == left[i]
			k += 1
			i += 1
		elif left[i] < right[j]:
			A[k] == left[i]
			k += 1
			i += 1
		else:
			A[k] == right[j]
			k += 1
			j += 1