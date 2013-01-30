# shaker sort
# does the same thing as bubble sort but goes up every other pass.

import random

def CreateRandomList(listAmount=10):
	l = []
	for i in range(listAmount):
		l.append(random.randint(0,listAmount))
	return l

def SelectionSort(A):
	# Find the smallest item in the list, put it on top.
	for i in range(len(A)):
		for j in range(i, len(A)):
			if A[j] < A[i]:
				A[i], A[j] = A[j], A[i]

def Compare(list1, list2):
	for i in range(len(list1)):
		if list1[i] != list2[i]:
			print "Error at index: %s" % i
			return
	print "Success!"

# ------------- QUICK SORT -------------- #
def QuickSort(A, counts, modified=False):
	QuickSortR(A, counts, 0, len(A)-1, modified)

def QuickSortR(A, counts, low, high, modified):
	if low >= high:
		return
	if modified:
		A[len(A)/2], A[0], = A[0], A[len(A)/2]
	counts[0] += 1
	pivot = low
	sp = pivot + 1 #swap position
	for i in range(pivot+1, high+1):
		if A[i] < A[pivot]:
			A[i], A[sp] = A[sp], A[i]
			sp += 1
	A[pivot], A[sp-1] = A[sp-1], A[pivot]

	# recurse on smaller stuff
	QuickSortR(A, counts, low, sp-1, True)

	# recurse on bigger stuff	
	QuickSortR(A, counts, sp, high, True)

def main():
	counts = [0,0]
	A = CreateRandomList(100)
	print A
	Acopy_quick = A[:]
	QuickSort(A, counts, True)
	Acopy_quick.sort()
	print A # hopefully sorted
	print Acopy_quick # will be sorted
	print "Recursions: %i" % counts[0]
	Compare(A, Acopy_quick) # compare the two lists. Print "All the same" if successfull. Failure otherwise.

main()