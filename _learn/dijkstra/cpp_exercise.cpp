#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int cost;
  string vertex;
  bool operator>(const Node &other) const { return cost > other.cost; }
};

class Graph {
private:
  map<string, vector<pair<string, int>>> adj;

public:
  void add_edge(string u, string v, int weight) {
    adj[u].push_back({v, weight});
  }

  int dijkstra(string start, string end) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    set<string> visited;

    pq.push({0, start});

    while (!pq.empty()) {
      Node current = pq.top();
      pq.pop();

      if (visited.count(current.vertex))
        continue;
      // Mark as visited
      visited.insert(____________);

      if (current.vertex == end)
        return current.cost;

      if (adj.find(current.vertex) != adj.end()) {
        for (auto &edge : adj[current.vertex]) {
          string v = edge.first;
          int weight = edge.second;

          if (!visited.count(v)) {
            // Push new cost
            pq.push({____________, v});
          }
        }
      }
    }
    return -1;
  }
};

int main() {
  Graph g;
  g.add_edge("A", "B", 2);
  cout << g.dijkstra("A", "B") << endl;
  return 0;
}