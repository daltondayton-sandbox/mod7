#ifndef GRAPH_H
#define GRAPH_H
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using std::cout;
using std::deque;
using std::endl;
using std::ostream;

template <typename T> class Graph;

template <typename T> ostream &operator<<(ostream &out, const Graph<T> &g);

template <typename T> class Graph {
  friend ostream &operator<< <>(ostream &out, const Graph<T> &g);

private:
  // Declare any variables needed for your graph
  std::unordered_map<T, std::list<T>> adjList;
  int numVerticies;
  int maxVerticies;

public:
  Graph();
  Graph(int);
  Graph(const Graph<T> &obToCopy) = delete; // Prevent copy construction
  Graph &
  operator=(const Graph<T> &objToCopy) = delete; // Prevent copy assignment

  void addVertex(const T &vertex);
  void addEdge(const T &source, const T &target);
  void getPath(std::deque<T> &solution, const T &source, const T &target);

  int findVertexPos(const T &item) const; // Optional
  bool vertexExists(const T &item) const;
  int getNumVertices() const;
};

/*********************************************
 * Constructs an empty graph with a max number of verticies of 100
 *
 *********************************************/
template <typename T> Graph<T>::Graph() : numVerticies(0), maxVerticies(100) {}

/*********************************************
 * Constructs an empty graph with a given max number of verticies
 *
 *********************************************/
template <typename T>
Graph<T>::Graph(int maxVerticies)
    : numVerticies(0), maxVerticies(maxVerticies) {}

/*********************************************
 * Adds a Vertex to the GraphIf number of verticies is less than the
 * Max Possible number of verticies.
 *********************************************/
template <typename T> void Graph<T>::addVertex(const T &vertex) {
  if (numVerticies < maxVerticies && adjList.find(vertex) == adjList.end()) {
    adjList[vertex] = std::list<T>();
    numVerticies++;
  }
}

/*********************************************
 * Returns the current number of vertices
 *
 *********************************************/
template <typename T> int Graph<T>::getNumVertices() const {
  return numVerticies;
}

/*********************************************
 * Returns the position in the verticies list where the given vertex is located,
 *-1 if not found.
 *
 *********************************************/
template <typename T> int Graph<T>::findVertexPos(const T &item) const {
  return -1; // return negative one
}

/*********************************************
 * Returns the position in the verticies list where the given vertex is located,
 *-1 if not found.
 *
 *********************************************/
template <typename T> bool Graph<T>::vertexExists(const T &item) const {
  return adjList.find(item) != adjList.end();
}

/*********************************************
 * Adds an edge going in the direction of source going to target
 *
 *********************************************/
template <typename T> void Graph<T>::addEdge(const T &source, const T &target) {
  if (vertexExists(source) && vertexExists(target)) {
    adjList[source].push_back(target);
  }
}

/*
  getPath will return the shortest path from source to dest.
  Given the test graph:

[a]-----------[c]
|  \            \
|   \            \
[b]  [d]----[g]---[h]
|          /  \
|         /    \
|        /      \
|     [f]--------[i]
|    /   \       /
|   /     \     /
|  /       \   /
[e]         [j]

getPath('a', 'f') should return
'a' -> 'b' -> 'e' -> 'f'   or   'a' -> 'd' -> 'g' -> 'f'
*/

template <typename T>
void Graph<T>::getPath(std::deque<T> &solution, const T &source,
                       const T &target) {
  // Load the answer into the solution deque
  std::unordered_set<T> discoveredSet;
  std::queue<T> frontierQueue;
  std::unordered_map<T, T> parentMap;

  frontierQueue.push(source);
  discoveredSet.insert(source);
  parentMap[source] = source;

  while (!frontierQueue.empty()) {
    T current = frontierQueue.front();
    frontierQueue.pop();

    if (current == target) {
      break;
    }

    for (const T &neighbor : adjList[current]) {
      if (discoveredSet.find(neighbor) == discoveredSet.end()) {
        frontierQueue.push(neighbor);
        discoveredSet.insert(neighbor);
        parentMap[neighbor] = current;
      }
    }
  }

  T current = target;
  for (int i = 0; i < parentMap.size() - 1; i++) {
    if (current == source) {
      break;
    }
    solution.push_front(current);
    current = parentMap[current];
  }
  solution.push_front(source);
}

/*********************************************
* Returns a display of the graph in the format
* vertex: edge edge
Your display will look something like the following

    j: i f
    c: h a
    b: e a
    h: g c
    f: g i j e
    e: f b
    i: g f j
    d: g a
    g: h i f d
    a: b c d
*********************************************/
template <typename T> ostream &operator<<(ostream &out, const Graph<T> &g) {
  return out;
}

#endif
