#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int f, g, x, y;
  bool operator<(const Node &other) const {
    // Sort descending to pop min
    return f > other.f;
  }
};

// Returns path and action grid
// FILL IN THE BLANKS
pair<vector<vector<int>>, vector<vector<int>>>
search(vector<vector<int>> &grid, vector<int> &init, vector<int> &goal,
       int cost, vector<vector<int>> &heuristic) {
  // ... setup omitted ...
  vector<Node> open;
  open.push_back({/* ... */});

  while (!found && !resign) {
    if (open.empty()) {
      resign = true;
    } else {
      sort(open.begin(), open.end());
      Node next = open.back();
      open.pop_back(); // Get smallest F

      // Check goal
      if (next.x == goal[0] && next.y == goal[1]) {
        found = true;
      } else {
        // Expand neighbors
        for (int i = 0; i < 4; i++) {
          // Check bounds and if closed
          if (/* valid */) {
            int g2 = next.g + cost;
            int f2 = g2 + ____________; // Heuristic calculation
            open.push_back({f2, g2, x2, y2});
            closed[x2][y2] = 1; // Mark visited
            action[x2][y2] = i; // Store action index
          }
        }
      }
    }
  }
  // Path reconstruction
  // ...
  return {path, action};
}