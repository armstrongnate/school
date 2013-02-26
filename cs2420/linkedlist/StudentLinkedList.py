# This program utilizes a Linked List to store Student objects.
# The Linked List is stored as a variabled called allStudents.
# CS2420 Assignment - Linked Lists
# Nate Armstrong

import time
from student import * 
from LinkedList import *

TOTAL_AGE = 0.0

def getAge(student):
  TOTAL_AGE += student.mAge

def insert(allStudents):
  before = time.time()
  fin = open("../program3/insert_names.txt", "r")
  for line in fin:
    words = line.split()
    s = Student(words)
    allStudents.Insert(s)
  after = time.time()
  print "# of students: %i" % allStudents.Size()
  print "Time taken to insert: %.2f minutes." % ((after - before)/60)

def traverse(allStudents):
  before = time.time()
  allStudents.Traverse(getAge)
  after = time.time()
  print "The average age of all the students is %f" % (TOTAL_AGE/allStudents.Size())
  print "Time taken to traverse: %.2f seconds.\n" % (after - before)

def retrieve(allStudents):
  before = time.time()
  count = 0

def main():
  allStudents = UnorderedUniqueContainer()
  insert(allStudents)
  traverse(allStudents)
  retrieve(allStudents)
  delete(allStudents)