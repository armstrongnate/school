## FACTORIAL ##

# N! = N * (N-1)!

def factorial(n):
	if n == 1:
		return 1
  else:
    return n * factorial(n-1)

def main():
	n = 4
	f = Factorial(n)
	print f

## TOWERS OF HANOI ##

# write solution using iteration by finding pattern. Due Monday after Spring Break for 15 extra credit points.
