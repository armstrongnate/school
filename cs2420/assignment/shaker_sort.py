# shaker sort
# does the same thing as bubble sort but goes up every other pass.

import random

def CreateRandomList(listAmount=10):
	l = []
	for i in range(listAmount):
		l.append(random.randint(0,listAmount))
	return l

def ShakerSort(A):
	# switch things around until the list A is sorted
	# do a series of passes, compare each item with its neighbor, switch them if they are out of order.
	# one pass gets the biggest number to the end
	switched = True
	while switched:
		switched = False
		for i in range(len(A)-1):
			if A[i] > A[i+1]:
				A[i], A[i+1] = A[i+1], A[i]
				switched = True
		if not switched:
			break
		switched = False
		for i in range(len(A)-1, 0, -1):
			if A[i-1] > A[i]:
				A[i-1], A[i] = A[i], A[i-1]
				switched = True

def Compare(list1, list2):
	for i in range(len(list1)):
		if list1[i] != list2[i]:
			print "Error at index: %s" % i
			return
	print "Success!"

def main():
	A = CreateRandomList()
	print A # make sure A is a list with numbers in it. Can contain duplicates. Numbers 0-listAmount
	Acopy = A[:]
	ShakerSort(A)
	Acopy.sort()
	print A # hopefully sorted
	print Acopy # will be sorted
	Compare(A, Acopy) # compare the two lists. Print "All the same" if successfull. Failure otherwise.

main()