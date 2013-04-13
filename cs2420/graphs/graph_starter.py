# we will be using an Adjacency list to keep track of edges and vertices
# example Adjacency list:

## [[1,2], [0,2,3], [0,1,3], [1,2,4], [3], [6,7], [5,7], [5,6]]

# example vertices list
## [False, False, False, False, False, False, False, False]

class Graph:
  def __init__(self, vertex_count):
    self.vertices = [False]*vertex_count

  def findPathDepth(start, end):
    # uses a stack
    # always reaching straight down until we hit what we are looking for. Once a dead end, back up and try other direction.

    # mark all vertices in vertices list (above) as not visited
    s = Stack()
    s.push(start)
    vertices[start] = True
    while not s.isEmpty():
      c = s.top()
      if c == end:
        # build path and return items in stack as a list starting from bottom up. [4,3,2,1,0].reverse()
      n = getConnections(c) # for 0, this will return [1,2]. see Adjacency list above.
      # if all of n has been visited:
        s.pop()
      else:
        s.push(f) # f being the first one that hasn't been visited
        vertices[f] = True
    return None

  def findPathBreadth(x, y):
    # uses a queue
    pass

  def addEdge(x, y):
    pass

  def getConnections(x):
    pass

  def isEdge(x, y):
    pass