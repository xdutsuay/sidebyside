#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

class Graph {
private:
  std::map<std::string, std::vector<std::string>> adj;

public:
  void add_edge(const std::string &u, const std::string &v) {
    adj[u].push_back(v);
    // Ensure v exists in map
    if (adj.find(v) == adj.end()) {
      adj[v] = std::vector<std::string>();
    }
  }

  std::set<std::string> dfs(const std::string &start) {
    std::set<std::string> visited;
    std::stack<std::string> s;

    s.push(start);
    visited.insert(start);

    while (!s.empty()) {
      std::string v = s.top();
      s.pop();

      // In our Python version, we pop, mark visited (if not already), then push
      // neighbors But standard iterative DFS often marks visited, pushes
      // neighbors Let's stick to the logic: Pop V. If V not visited, mark
      // visited. Push neighbors.

      // Wait, Python version:
      // explored = {start}, stack = [start]
      // while stack: v = pop(); explored.add(v); for adj in reversed(graph[v]):
      // if not explored: push(adj)

      // The python version pre-marks 'start' as explored.
      // Then loop: pop v. add v to explored (redundant for start? No set
      // handles it). Then push unseen neighbors.

      // Let's mimic distinct behavior:
      // In typical DFS, we visit when we pop.

      // Python implementation logic translation:
      if (visited.find(v) == visited.end()) {
        visited.insert(v);
      }

      if (adj.find(v) != adj.end()) {
        std::vector<std::string> &neighbors = adj[v];
        // Iterate in reverse to match recursion order if needed, or just push
        // Python does reversed() to process neighbors in order
        for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
          if (visited.find(*it) == visited.end()) {
            s.push(*it);
          }
        }
      }
    }
    return visited;
  }
};

int main() {
  Graph g;
  g.add_edge("A", "B");
  g.add_edge("A", "C");
  g.add_edge("A", "D");
  g.add_edge("B", "A");
  g.add_edge("B", "D");
  g.add_edge("B", "E");
  g.add_edge("C", "A");
  g.add_edge("C", "F");
  g.add_edge("D", "B");
  g.add_edge("D", "D");
  g.add_edge("E", "B");
  g.add_edge("E", "F");
  g.add_edge("F", "C");
  g.add_edge("F", "E");
  g.add_edge("F", "G");
  g.add_edge("G", "F");

  std::set<std::string> result = g.dfs("A");
  std::cout << "DFS Result: ";
  for (const auto &node : result)
    std::cout << node << " ";
  std::cout << std::endl;
  return 0;
}