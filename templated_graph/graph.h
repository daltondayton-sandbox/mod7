#pragma once

#include <list>
#include <string>

struct Pair {
  Pair(int n, int w) {
    node = n;
    weight = w;
  }
  int node;
  int weight;
};

class Graph {
public:
  Graph(std::string filename);
  int shortestCost(int startNode, int endNode);

private:
  std::list<Pair> *adjList;
  int numNodes;
};
