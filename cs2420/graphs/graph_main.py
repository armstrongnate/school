from Graph import *

def main():
  fin = open('graph_in.txt', 'r')
  lines = fin.readlines()
  vertex_count = int(lines[0])
  edge_count = int(lines[1])
  graph = Graph(vertex_count)
  i = 2
  while len(lines[i].strip()) > 1:
    vertex = lines[i].strip().split(' ')
    graph.addEdge(int(vertex[0]), int(vertex[1]))
    i += 1
  print "\n\nAdjacency List:"
  print graph.vertices, '\n\n'
  for j in range(int(lines[i].strip())):
    i += 1
    test = lines[i].strip().split(' ')
    print "Solution for %s to %s:" % (test[0], test[1])
    print graph.findPathDepth(int(test[0]), int(test[1])), '\n\n'
main()