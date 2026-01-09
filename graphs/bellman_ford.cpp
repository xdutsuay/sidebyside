/**
 * @file
 * @brief Bellman-Ford Algorithm Implementation
 * @details
 * Dijkstra's algorithm is a Greedy algorithm and time complexity is O(VLogV)
 * (with the use of Fibonacci heap). Dijkstra doesn't work for Graphs with
 * negative weight edges, Bellman-Ford works for such graphs. Bellman-Ford is
 * also simpler than Dijkstra and suites well for distributed systems. But time
 * complexity of Bellman-Ford is O(VE), which is more than Dijkstra.
 */

#include <climits>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Edge {
  int src, dest, weight;
};

struct Graph {
  int V, E;
  std::vector<Edge> edges;
};

/**
 * @brief Prints the distance array
 * @param dist Distance array
 * @param V Number of vertices
 */
void printArr(const std::vector<int> &dist, int V) {
  std::cout << "Vertex   Distance from Source\n";
  for (int i = 0; i < V; ++i) {
    if (dist[i] == INT_MAX)
      std::cout << i << "\t\tINF" << std::endl;
    else
      std::cout << i << "\t\t" << dist[i] << std::endl;
  }
}

/**
 * @brief The main function that finds shortest distances from src to
 * all other vertices using Bellman-Ford algorithm.
 * @param graph The graph
 * @param src Source vertex
 */
void BellmanFord(Graph &graph, int src) {
  int V = graph.V;
  int E = graph.E;
  std::vector<int> dist(V, INT_MAX);

  // Step 1: Initialize distances from src to all other vertices as INFINITE
  dist[src] = 0;

  // Step 2: Relax all edges |V| - 1 times.
  for (int i = 1; i <= V - 1; i++) {
    for (int j = 0; j < E; j++) {
      int u = graph.edges[j].src;
      int v = graph.edges[j].dest;
      int weight = graph.edges[j].weight;
      if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        dist[v] = dist[u] + weight;
    }
  }

  // Step 3: check for negative-weight cycles.
  for (int i = 0; i < E; i++) {
    int u = graph.edges[i].src;
    int v = graph.edges[i].dest;
    int weight = graph.edges[i].weight;
    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
      std::cout << "Graph contains negative weight cycle" << std::endl;
      return;
    }
  }

  printArr(dist, V);
}

int main() {
  int V = 5; // Number of vertices in graph
  int E = 8; // Number of edges in graph
  Graph graph;
  graph.V = V;
  graph.E = E;

  // edges = [(0, 1, -1), (0, 2, 4), (1, 2, 3), (1, 3, 2), (1, 4, 2), (3, 2, 5),
  // (3, 1, 1), (4, 3, -3)]

  graph.edges.push_back({0, 1, -1});
  graph.edges.push_back({0, 2, 4});
  graph.edges.push_back({1, 2, 3});
  graph.edges.push_back({1, 3, 2});
  graph.edges.push_back({1, 4, 2});
  graph.edges.push_back({3, 2, 5});
  graph.edges.push_back({3, 1, 1});
  graph.edges.push_back({4, 3, -3});

  BellmanFord(graph, 0);

  return 0;
}