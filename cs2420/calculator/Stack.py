# stack.py
# the Stack class has all the functionality of a traditional stack. Methods include push, pop, top, and isEmpty

class Stack:
  def __init__(self):
    self.me = []

  def push(self, item):
    self.me.append(item)

  def pop(self):
    return self.me.pop(len(self.me)-1)

  def top(self):
    return self.me[len(self.me)-1] if len(self.me)>0 else None

  def isEmpty(self):
    return True if len(self.me) < 1 else False

  def indexOf(self, item):
    return self.me.index(item) if item in self.me else -1

  def __str__(self):
    return str(self.me)
