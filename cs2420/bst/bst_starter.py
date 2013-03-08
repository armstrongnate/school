class Node:
  def __init__(self, object, left=None, right=None):
    self.mObject = object
    self.mLeft = left
    self.mRight = right

class BinarySearchTree:
  def __init__(self):
    self.mRoot = None

  def insert(self, object):
    if self.exists(object):
      return False
    n = Node(object)
    self.mRoot = self.insert_r(self.mRoot, n)
    return True

  def insert_r(self, current, n):
    if current is None:
      current = n
    elif n.mObject < current.mObject:
      current.mLeft = self.insert_r(current.mLeft, n)
    else:
      current.mRight = self.insert_r(current.mRight, n)
    return current