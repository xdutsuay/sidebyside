/**
 * @file
 * @brief Breadth First Search Algorithm
 */

#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Graph {
  map<int, list<int>> adj;

public:
  void addEdge(int v, int w);
  void BFS(int s);
};

void Graph::addEdge(int v, int w) { adj[v].push_back(w); }

void Graph::BFS(int s) {
  map<int, bool> visited;
  queue<int> q;

  visited[s] = true;
  q.push(s);

  while (!q.empty()) {
    s = q.front();
    cout << s << " ";
    q.pop();

    for (auto i : adj[s]) {
      if (!visited[i]) {
        visited[i] = true;
        q.push(i);
      }
    }
  }
}

int main() {
  Graph g;
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
  g.BFS(2);

  return 0;
}