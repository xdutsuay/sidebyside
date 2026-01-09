#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

/**
 * @brief BFS implementation in C++ - FILL IN THE BLANKS
 */
class Graph {
private:
  std::map<int, std::vector<int>> vertices;

public:
  void add_edge(int from_vertex, int to_vertex) {
    vertices[from_vertex].push_back(to_vertex);
    if (vertices.find(to_vertex) == vertices.end()) {
      vertices[to_vertex] = std::vector<int>();
    }
  }

  std::set<int> bfs(int start_vertex) {
    std::set<int> visited;
    std::queue<int> q;

    // Start by visiting and queuing the start_vertex
    visited.insert(start_vertex);
    q.push(start_vertex);

    while (!q.empty()) {
      int vertex = q.____________(); // Get front element
      q.pop();

      // Iterate over neighbors
      for (int adjacent_vertex : vertices[vertex]) {
        // Check if neighbor has been visited
        if (visited.find(adjacent_vertex) == ____________) { // Not found in set
          visited.insert(adjacent_vertex);
          q.push(____________);
        }
      }
    }
    return visited;
  }
};

int main() {
  Graph g;
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(2, 3);

  std::set<int> result = g.bfs(0);
  for (int v : result)
    std::cout << v << " ";
  return 0;
}