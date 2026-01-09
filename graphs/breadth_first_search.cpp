#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

/**
 * @brief Graph class using Adjacency List
 */
class Graph {
private:
  std::map<int, std::vector<int>> vertices;

public:
  /**
   * @brief Adds an edge to the graph
   * @param from_vertex Source vertex
   * @param to_vertex Destination vertex
   */
  void add_edge(int from_vertex, int to_vertex) {
    vertices[from_vertex].push_back(to_vertex);
    // Ensure the destination vertex exists in the map even if it has no
    // outgoing edges
    if (vertices.find(to_vertex) == vertices.end()) {
      vertices[to_vertex] = std::vector<int>();
    }
  }

  /**
   * @brief Prints the adjacency list of the graph
   */
  void print_graph() {
    for (auto const &[vertex, edges] : vertices) {
      std::cout << vertex << " : ";
      for (size_t i = 0; i < edges.size(); ++i) {
        std::cout << edges[i];
        if (i < edges.size() - 1)
          std::cout << " -> ";
      }
      std::cout << std::endl;
    }
  }

  /**
   * @brief Performs Breadth First Search
   * @param start_vertex The vertex to start BFS from
   * @return std::set<int> Set of visited vertices
   */
  std::set<int> bfs(int start_vertex) {
    std::set<int> visited;
    std::queue<int> q;

    visited.insert(start_vertex);
    q.push(start_vertex);

    while (!q.empty()) {
      int vertex = q.front();
      q.pop();

      // Loop through all adjacent vertices
      for (int adjacent_vertex : vertices[vertex]) {
        if (visited.find(adjacent_vertex) == visited.end()) {
          visited.insert(adjacent_vertex);
          q.push(adjacent_vertex);
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
  g.add_edge(1, 2);
  g.add_edge(2, 0);
  g.add_edge(2, 3);
  g.add_edge(3, 3);

  g.print_graph();

  std::set<int> result = g.bfs(2);
  std::cout << "BFS Result (starting from 2): ";
  for (int v : result) {
    std::cout << v << " ";
  }
  std::cout << std::endl;

  return 0;
}