# we will be using an Adjacency list to keep track of edges and vertices
# example Adjacency list:

## [[1,2], [0,2,3], [0,1,3], [1,2,4], [3], [6,7], [5,7], [5,6]]

# example vertices list
## [False, False, False, False, False, False, False, False]
from Stack import *

class Graph:
  def __init__(self, vertex_count):
    self.vertex_visited = [False]*vertex_count
    self.vertices = []
    for i in range(vertex_count):
      l = []
      self.vertices.append(l)

  def findPathDepth(self, start, end):
    s = Stack()
    s.push(start)
    self.vertex_visited[start] = True
    while not s.isEmpty():
      c = s.top()
      if c == end:
        return s
      connections = self.getConnections(c) # for 0, this will return [1,2]. see Adjacency list above.
      all_visited = True
      first_not_visited = False
      for connection in connections:
        if not self.vertex_visited[connection]:
          first_not_visited = connection
          all_visited = False
          break
      if all_visited:
        s.pop()
      else:
        s.push(first_not_visited)
        self.vertex_visited[first_not_visited] = True
    return None

  def findPathBreadth(self, x, y):
    pass

  def addEdge(self, x, y):
    self.vertices[x].append(y)
    self.vertices[y].append(x)

  def getConnections(self, x):
    return self.vertices[x]

  def isEdge(self, x, y):
    pass