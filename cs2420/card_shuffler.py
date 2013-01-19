# CARD SHUFFLING PROBLEM

## SOLUTION 1 ##
import random

def createRandomUniqueArray(size=52):
	# generate an array of random numbers between 0 and 51
	a = []
	count = 0
	while count < size:
		r = random.randrange(0, size)
		if r in a:
			a.append(r)
			count += 1
	return a

## SOLUTION 2 ##
import random
def createRandomUniqueArray(size):
	a = range(size)
	return random.shuffle(a)

## SOLUTION 3 ##
def createRandomUniqueArray(size):
	a = range(size)
	for i in range(size):
		j = random.randrange(size)
		a[i], a[j] = a[j], a[i]
	return a

