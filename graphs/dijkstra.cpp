#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

// Structure to represent a node in the priority queue
struct Node {
  int cost;
  string vertex;

  // Overload < operator for priority_queue (min-heap behavior)
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
    // Min-heap
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    set<string> visited;

    pq.push({0, start});

    while (!pq.empty()) {
      Node current = pq.top();
      pq.pop();

      string u = current.vertex;
      int cost = current.cost;

      if (visited.count(u))
        continue;
      visited.insert(u);

      if (u == end)
        return cost;

      if (adj.find(u) != adj.end()) {
        for (auto &edge : adj[u]) {
          string v = edge.first;
          int weight = edge.second;

          if (visited.count(v))
            continue;

          pq.push({cost + weight, v});
        }
      }
    }
    return -1;
  }
};

int main() {
  Graph g;
  g.add_edge("A", "B", 2);
  g.add_edge("A", "C", 5);
  g.add_edge("B", "A", 2);
  g.add_edge("B", "D", 3);
  g.add_edge("B", "E", 1);
  g.add_edge("B", "F", 1);
  g.add_edge("C", "A", 5);
  g.add_edge("C", "F", 3);
  g.add_edge("D", "B", 3);
  g.add_edge("E", "B", 4);
  g.add_edge("E", "F", 3);
  g.add_edge("F", "C", 3);
  g.add_edge("F", "E", 3);

  cout << g.dijkstra("E", "C") << endl; // Expected: 6
  return 0;
}