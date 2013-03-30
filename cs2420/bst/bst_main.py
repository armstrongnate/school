# This program utilizes a Linked List to store Student objects.
# The Linked List is stored as a variabled called allStudents.
# CS2420 Assignment - Linked Lists
# Nate Armstrong

import sys
sys.path.append('/home/nate/school/cs2420/program3/')
from student import *
from bst_starter import *
import time

TOTAL_AGE = 0.0
test_files = {
  'insert': '../linkedlist/insert_names.txt',
  'retrieve': '../linkedlist/retrieve_names.txt',
  'delete': '../linkedlist/delete_names.txt'
}
files = {
  'insert': '../program3/insert_names.txt',
  'retrieve': '../program3/retrieve_names.txt',
  'delete': '../program3/delete_names.txt'
}

def storeAge(student):
  global TOTAL_AGE
  TOTAL_AGE += student.getAge()

def insert(allStudents):
  before = time.time()
  fin = open(files['insert'], "r")
  for line in fin:
    words = line.split()
    s = Student(words)
    if not allStudents.Insert(s):
      print "Error inserting %s." % s
  after = time.time()
  print "# of students: %i" % allStudents.Size()
  print "Time taken to insert: %.2f minutes.\n\n" % ((after - before)/60)

def traverse(allStudents):
  before = time.time()
  allStudents.Traverse(storeAge)
  after = time.time()
  print "The average age of all the students is %f" % (TOTAL_AGE/allStudents.Size())
  print "Time taken to traverse: %.2f seconds.\n\n" % (after - before)

def retrieve(allStudents):
  before = time.time()
  totalAge = 0.0 
  count = 0
  fin = open(files['retrieve'], "r")
  for line in fin:
    ssn = line.strip()
    blank_student = Student(["", "", ssn, "", "25"])
    found = False
    s = allStudents.Retrieve(blank_student)
    if s:
      found = True
      totalAge += s.getAge()
      count += 1
  if not found:
    print "No student found with SSN %s." % ssn
  after = time.time()
  if count < 1:
    print "No students retrieved."
  else:
    print "Average age of retrieved students: %f" % (totalAge/count)
  print "Time taken to retrieve: %.2f seconds.\n\n" % (after - before)

def delete(allStudents):
  before = time.time()
  fin = open(files['delete'], "r")
  for line in fin:
    ssn = line.strip()
    blank_student = Student(["", "", ssn, "", "25"])
    found = False
    if allStudents.Delete(blank_student):
      print "Deleted %s" % ssn
      found = True
      break
  if not found:
    print "No student found with SSN %s" % ssn
  after = time.time()
  print "Number of Students, now: %s" % allStudents.Size()
  print "Time taken to delete: %.2f seconds.\n\n" % (after - before)

def main():
  allStudents = BinarySearchTree()
  insert(allStudents)
  traverse(allStudents)
  retrieve(allStudents)
  delete(allStudents)

main()