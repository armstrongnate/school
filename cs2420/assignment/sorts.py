# Nate Armstrong
# CS 2420
# Project 2 
# Sorting Algorithms
import random
import sys
import math

def main():
  useRandom = False
  useCompares = True
  startingSize = 8
  endingSize = 4096
  sys.setrecursionlimit(endingSize+10)
  total = 0
  size = startingSize
  print "\t Bubble \t Shaker \t Selection \t Quick \t Quick Mod \t Merge \t Hash \n"
  while size <= endingSize:
    total += 1
    # create list (A) that we will sort depending on random or sorted
    A = CreateRandomList(size)
    if not useRandom:
      A.sort()
      A[0], A[-1] = A[-1], A[0]

    # make a copy of A for each sorting algorithms

   # copies_of_A = [bubble_copy, shaker_copy, selection_copy, quick_copy, quick_m_copy, merge_copy, hash_copy]
   # sort_counts = [bubble_counts, shaker_counts, selection_counts, quick_counts, quick_m_counts, merge_counts, hash_counts]
    
    bubble_copy = A[:]
    shaker_copy = A[:]
    selection_copy = A[:]
    quick_copy = A[:]
    quick_m_copy = A[:]
    merge_copy = A[:]
    hash_copy = A[:]
   
    # call each algorithms, those algorithms should return compares/swaps
    all_counts = []

    counts = [0,0]
    bubble_counts = BubbleSort(bubble_copy, counts)
    all_counts.append(bubble_counts)

    counts = [0,0]
    shaker_counts = ShakerSort(shaker_copy, counts)
    all_counts.append(shaker_counts)

    counts = [0,0]
    selection_counts = SelectionSort(selection_copy, counts)
    all_counts.append(selection_counts)

    counts = [0,0]
    quick_counts = QuickSort(quick_copy, counts)
    all_counts.append(quick_counts)

    counts = [0,0]
    quick_m_counts = QuickSort(quick_m_copy, counts)
    all_counts.append(quick_m_counts)

    counts = [0,0]
    merge_counts = MergeSort(merge_copy, counts)
    all_counts.append(merge_counts)

    counts = [0,0]
    hash_counts = HashSort(hash_copy, counts)
    all_counts.append(merge_counts)
    # print out log of number of compares/swaps.
    if useCompares:
      print "%i \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f" %(getLogOfTwo(size), getCorrectFloat(bubble_counts[0]), getCorrectFloat(shaker_counts[0]), getCorrectFloat(selection_counts[0]), getCorrectFloat(quick_counts[0]), getCorrectFloat(quick_m_counts[0]), getCorrectFloat(merge_counts[0]), getCorrectFloat(hash_counts[0]))
    else:
      print "%i \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f" %(getLogOfTwo(size), getCorrectFloat(bubble_counts[1]), getCorrectFloat(shaker_counts[1]), getCorrectFloat(selection_counts[1]), getCorrectFloat(quick_counts[1]), getCorrectFloat(quick_m_counts[1]), getCorrectFloat(merge_counts[1]), getCorrectFloat(hash_counts[1]))

    size *= 2
  # ----- Method Definitions ----- #

def getLogOfTwo(x):
  return math.log(x)/math.log(2)

def getCorrectFloat(x):
  x = math.log(x)/math.log(2) # takes log base 2 of log.
  x *= 100
  x = int(x)
  x = float(x)
  x /= 100
  return x

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

def BubbleSort(bubble_copy, counts):
  # switch things around until the list A is sorted
  # do a series of passes, compare each item with its neighbor, switch them if they are out of order.
  # one pass gets the biggest number to the end
  switched = True
  while switched:
    switched = False
    for i in range(len(bubble_copy)-1):
      counts[0] += 1
      if bubble_copy[i] > bubble_copy[i+1]:
        bubble_copy[i], bubble_copy[i+1] = bubble_copy[i+1], bubble_copy[i]
        switched = True
        counts[1] += 1
  return counts

def ShakerSort(shaker_copy, counts):
  # switch things around until the list A is sorted
  # do a series of passes, compare each item with its neighbor, switch them if they are out of order.
  # one pass gets the biggest number to the end
  switched = True
  while switched:
    switched = False
    for i in range(len(shaker_copy)-1):
      counts[0] += 1
      if shaker_copy[i] > shaker_copy[i+1]:
        shaker_copy[i], shaker_copy[i+1] = shaker_copy[i+1], shaker_copy[i]
        switched = True
        counts[1] += 1
    if not switched:
      break
    switched = False
    for i in range(len(shaker_copy)-1, 0, -1):
      counts[0] += 1
      if shaker_copy[i-1] > shaker_copy[i]:
        shaker_copy[i-1], shaker_copy[i] = shaker_copy[i], shaker_copy[i-1]
        switched = True
        counts[1] += 1
  return counts

def SelectionSort(selection_copy, counts):
  # Find the smallest item in the list, put it on top.
  for i in range(len(selection_copy)):
    for j in range(i, len(selection_copy)):
      counts[0] += 1
      if selection_copy[j] < selection_copy[i]:
        selection_copy[i], selection_copy[j] = selection_copy[j], selection_copy[i]
        counts[1] += 1
  return counts

# ------------- QUICK SORT -------------- #
def QuickSort(quick_list, counts, modified=False):
  QuickSortR(quick_list, counts, 0, len(quick_list)-1, modified)
  return counts

def QuickSortR(quick_list, counts, low, high, modified):
  if low >= high:
    if modified:
      quick_m_copy = quick_list
    else:
      quick_copy = quick_list
    return
  if modified:
    quick_list[high/2], quick_list[low] = quick_list[low], quick_list[high/2]
    counts[1] += 1
    low = quick_list[high/2]
  counts[0] += 1
  pivot = low
  sp = pivot + 1 #swap position
  for i in range(pivot+1, high+1):
    counts[0] += 1
    if quick_list[i] < quick_list[pivot]:
      quick_list[i], quick_list[sp] = quick_list[sp], quick_list[i]
      counts[1] += 1
      sp += 1
  quick_list[pivot], quick_list[sp-1] = quick_list[sp-1], quick_list[pivot]
  counts[1] += 1

  # recurse on smaller stuff
  QuickSortR(quick_list, counts, low, sp-1, False)

  # recurse on bigger stuff 
  QuickSortR(quick_list, counts, sp, high, False)

def MergeSort(merge_copy, counts):
  if len(merge_copy) <= 1:
    return counts
  # divide A into two sublists
  left = merge_copy[:len(merge_copy)/2]
  right = merge_copy[len(merge_copy)/2:]
  counts[1] += len(merge_copy)/3
  
  # sort each half
  MergeSort(left, counts)
  MergeSort(right, counts)

  # merge left and right back into A
  i = 0
  j = 0
  k = 0
  counts[1] += len(merge_copy)/3
  while k < len(merge_copy):
    if i == len(left):
      merge_copy[k] == right[j]
      k += 1
      j += 1
    elif j == len(right):
      merge_copy[k] == left[i]
      k += 1
      i += 1
    elif left[i] < right[j]:
      counts[0] += 1
      merge_copy[k] == left[i]
      k += 1
      i += 1
    else:
      counts[0] += 1
      merge_copy[k] == right[j]
      k += 1
      j += 1
  return counts

def HashSort(hash_copy, counts):
  F = []
  for i in range(len(hash_copy)):
    F.append(0)
  for n in hash_copy:
    F[n] += 1
  i = 0
  for n in range(len(F)):
    counts[0] += 1
    if F[n] > 0:
      for j in range(i, i+F[n]):
        hash_copy[j] = n
        counts[1] += 1
      i += F[n]
  return counts

main()