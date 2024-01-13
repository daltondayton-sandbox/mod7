#include "graph.h"
#include <climits>
#include <fstream>
#include <queue>
#include <stdexcept>
#include <vector>

using std::ifstream;
using std::invalid_argument;
using std::list;

Graph::Graph(std::string filename) {
  ifstream input;
  input.open(filename);
  if (!input) {
    throw invalid_argument("Could not read file");
  }
  input >> numNodes;
  adjList = new list<Pair>[numNodes];
  for (int i = 0; i < numNodes; i++) {
    int value;
    int cost;
    input >> value;
    while (value >= 0) {
      input >> cost;
      adjList[i].push_back(Pair(value, cost));
      input >> value;
    }
  }
}

int Graph::shortestCost(int startNode, int endNode) {
  std::vector<int> dist(numNodes, INT_MAX);
  dist[startNode] = 0;
  std::queue<int> queue;
  queue.push(startNode);
  while (!queue.empty()) {
    int currentNode = queue.front();
    queue.pop();
    for (std::list<Pair>::iterator it = adjList[currentNode].begin();
         it != adjList[currentNode].end(); ++it) {
      Pair adjNode = *it;
      if (dist[adjNode.node] == INT_MAX) {
        dist[adjNode.node] = dist[currentNode] + 1;
        queue.push(adjNode.node);
      }
    }
  }
  return dist[endNode] == INT_MAX ? -1 : dist[endNode];
}
