class Node:
  def __init__(self, object, left=None, right=None):
    self.mObject = object
    self.mLeft = left
    self.mRight = right

class BinarySearchTree:
  def __init__(self):
    self.mRoot = None

  def exists(self, item):
    return self.exists_r(item, self.mRoot)

  def exists_r(self, item, current):
    if not current:
      return False
    if item == current.mObject:
      return True
    if item < current.mObject:
      return self.exists_r(item, current.mLeft)
    return self.exists_r(item current.mRight)

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

  def size(self):
    return self.size_r(self.mRoot)

  def size_r(self, current):
    if current is None:
      return 0
    return 1 + self.size_r(current.mLeft) + self.size_r(current.mRight)

  def traverse(self, callback):
    self.traverse_r(self.mRoot, callback)

  def traverse_r(self, current, callback):
    # go over each one and call callback function.