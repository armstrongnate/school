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

def main():
	A = CreateRandomList(1000)
	#print A # make sure A is a list with numbers in it. Can contain duplicates. Numbers 0-listAmount
	Acopy = A[:]
	SelectionSort(A)
	Acopy.sort()
	print A # hopefully sorted
	print Acopy # will be sorted
	Compare(A, Acopy) # compare the two lists. Print "All the same" if successfull. Failure otherwise.

main()