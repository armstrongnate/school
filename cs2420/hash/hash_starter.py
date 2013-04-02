class Hash:
  def __init__(self, size):
    self.mTablesize = size*2 + 1
    while not isPrime(self.mTablesize):
      self.mTablesize += 2
    self.mTable = [None]*self.mTablesize

  def Insert(self, item, key):
    if self.Exists(item):
      return False
    index = key % mTablesize
    while self.mTable[index] is not None:
      index += 1
      if index = self.mTablesize:
        index = 0
    self.mTable[index] = item

  def isPrime(x):
    if x == 2 or x == 1:
      return True
    if not x & 1:
      return False
    sqrt = int(x**.5)
    for i in range(3, sqrt+2, 2):
      if x%i == 0:
        return False
    return True