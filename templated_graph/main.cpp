#include "graph.h"
#include <iostream>

int main() {
  Graph g1("graph.txt");
  std::cout << "0->1: " << g1.shortestCost(0, 1) << std::endl;
  std::cout << "0->2: " << g1.shortestCost(0, 2) << std::endl;
  std::cout << "0->3: " << g1.shortestCost(0, 3) << std::endl;
  std::cout << "0->4: " << g1.shortestCost(0, 4) << std::endl;
  std::cout << "0->5: " << g1.shortestCost(0, 5) << std::endl;
  std::cout << "0->6: " << g1.shortestCost(0, 6) << std::endl;
}
