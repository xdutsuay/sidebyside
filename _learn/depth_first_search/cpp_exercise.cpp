#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

/**
 * @brief DFS implementation in C++ - FILL IN THE BLANKS
 */
class Graph {
private:
  std::map<std::string, std::vector<std::string>> adj;

public:
  void add_edge(const std::string &u, const std::string &v) {
    adj[u].push_back(v);
  }

  std::set<std::string> dfs(const std::string &start) {
    std::set<std::string> visited;
    std::stack<std::string> s;

    s.push(start);
    visited.insert(start);

    while (!s.empty()) {
      // Get top element
      std::string v = s.____________();
      s.pop();

      // Iterate over neighbors
      if (adj.count(v)) {
        auto neighbors = adj[v];
        // Reverse iterate to push to stack
        for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
          if (visited.find(*it) == ____________) { // Not visited
            s.push(*it);
            visited.insert(____________);
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
  auto res = g.dfs("A");
  return 0;
}