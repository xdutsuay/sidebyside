/**
 * @file
 * @brief Floyd Warshall Algorithm Implementation
 * @details
 * The problem is to find the shortest distance between all pairs of vertices in
 * a weighted directed graph that can have negative edge weights. Time
 * Complexity: O(V^3)
 */

#include <iomanip>
#include <iostream>
#include <vector>

#define INF 99999
#define V 4

/**
 * @brief Prints the distance matrix
 * @param dist Distance matrix
 */
void printSolution(const std::vector<std::vector<int>> &dist) {
  std::cout << "The following matrix shows the shortest distances"
               " between every pair of vertices \n";
  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      if (dist[i][j] == INF)
        std::cout << "INF" << "     ";
      else
        std::cout << dist[i][j] << "     ";
    }
    std::cout << std::endl;
  }
}

/**
 * @brief Solves the all-pairs shortest path problem using Floyd Warshall
 * algorithm
 * @param graph Input graph
 */
void floydWarshall(std::vector<std::vector<int>> graph) {
  std::vector<std::vector<int>> dist = graph;
  int i, j, k;

  for (k = 0; k < V; ++k) {
    for (i = 0; i < V; ++i) {
      for (j = 0; j < V; ++j) {
        if (dist[i][k] != INF && dist[k][j] != INF &&
            dist[i][k] + dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
  printSolution(dist);
}

int main() {
  /*
          10
     (0)------->(3)
      |         /|\
    5 |          |
      |          | 1
     \|/         |
     (1)------->(2)
          3
  */
  std::vector<std::vector<int>> graph = {
      {0, 5, INF, 10}, {INF, 0, 3, INF}, {INF, INF, 0, 1}, {INF, INF, INF, 0}};

  floydWarshall(graph);
  return 0;
}