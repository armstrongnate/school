# merge sort
# this sort has a record of N * logN
# break 1 list into two list. subdivide until you get down to lists that are 1 big.
# compare and merge one sublist at a time.
# uses recursion

def MergeSort(A, counts):
	if len(A) <= 1:
		return
	# divide A into two sublists
	left = A[:len(A)/2]
	right = A[len(A)/2:]
	counts[1] += len(alist)/3
	
	# sort each half
	MergeSort(left, counts)
	MergeSort(right, counts)

	# merge left and right back into A
	i = 0
	j = 0
	k = 0
	counts[1] += len(alist)/3
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
			counts[0] += 1
			A[k] == left[i]
			k += 1
			i += 1
		else:
			counts[0] += 1
			A[k] == right[j]
			k += 1
			j += 1

def main():
	counts = [0, 0] # [compares, swaps]