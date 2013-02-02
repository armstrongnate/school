import math
def getCorrectFloat(x):
  x = math.log(x)/math.log(2) # takes log base 2 of log.
  x *= 100
  x = int(x)
  x = float(x)
  x /= 100
  return x

print "correct float: %.2f" % getCorrectFloat(2224)