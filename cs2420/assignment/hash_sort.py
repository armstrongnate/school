# hash sort

# create a frequency chart

# data member to index
import random

def CreateRandomList(listAmount=10):
  l = []
  for i in range(listAmount):
    l.append(random.randrange(0,listAmount))
  return l

def Compare(list1, list2):
  for i in range(len(list1)):
    if list1[i] != list2[i]:
      print "Error at index: %s" % i
      return
  print "Success!"
 
def main():   
  A = CreateRandomList(10000)
  Acopy = A[:]
  Acopy.sort()
  F = []
  for i in range(len(A)):
    F.append(0)
  for n in A:
    F[n] += 1

  i = 0
  for n in range(len(F)):
    if F[n] > 0:
      for j in range(i, i+F[n]):
        A[j] = n
      i += F[n]
  Compare(A, Acopy)

main()