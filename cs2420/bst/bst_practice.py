#bst_practice

from bst_starter import *

bst = BinarySearchTree()

s = '123456789'

for c in s:
  bst.insert(c)

print bst.size()