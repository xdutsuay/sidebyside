#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// Represents a state in the search
struct Node {
  int f, g, x, y;

  // For sorting in descending order (since vector::pop_back takes from end)
  // we want smallest f at end of vector if we sort normally?
  // Python code: cell.sort(); cell.reverse(); pop() -> gets smallest.
  // So Python sorts ascending, reverses to descending, pops last (smallest).
  // Here we can sort descending and pop back.
  bool operator<(const Node &other) const {
    // We want strict weak ordering.
    if (f != other.f)
      return f > other.f; // Sort descending by f
    return g > other.g;
  }
};

const int delta[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

struct Result {
  vector<vector<int>> path;
  vector<vector<int>> action;
};

Result search(vector<vector<int>> &grid, vector<int> &init, vector<int> &goal,
              int cost, vector<vector<int>> &heuristic) {
  int rows = grid.size();
  int cols = grid[0].size();

  vector<vector<int>> closed(rows, vector<int>(cols, 0));
  vector<vector<int>> action(rows, vector<int>(cols, 0));

  closed[init[0]][init[1]] = 1;

  int x = init[0];
  int y = init[1];
  int g = 0;
  int f = g + heuristic[x][y];

  vector<Node> open;
  open.push_back({f, g, x, y});

  bool found = false;
  bool resign = false;

  while (!found && !resign) {
    if (open.empty()) {
      resign = true;
      cout << "Algorithm is unable to find solution" << endl;
      return {};
    } else {
      sort(open.begin(), open.end()); // Sorts by operator< (descending f)
      Node next = open.back();
      open.pop_back();

      x = next.x;
      y = next.y;
      g = next.g;

      if (x == goal[0] && y == goal[1]) {
        found = true;
      } else {
        for (int i = 0; i < 4; i++) {
          int x2 = x + delta[i][0];
          int y2 = y + delta[i][1];

          if (x2 >= 0 && x2 < rows && y2 >= 0 && y2 < cols &&
              closed[x2][y2] == 0 && grid[x2][y2] == 0) {

            int g2 = g + cost;
            int f2 = g2 + heuristic[x2][y2];
            open.push_back({f2, g2, x2, y2});
            closed[x2][y2] = 1;
            action[x2][y2] = i;
          }
        }
      }
    }
  }

  vector<vector<int>> path;
  if (found) {
    x = goal[0];
    y = goal[1];
    path.push_back({x, y});

    while (x != init[0] || y != init[1]) {
      int x2 = x - delta[action[x][y]][0];
      int y2 = y - delta[action[x][y]][1];
      x = x2;
      y = y2;
      path.push_back({x, y});
    }
    reverse(path.begin(), path.end());
  }

  return {path, action};
}

int main() {
  vector<vector<int>> grid = {{0, 1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 1, 0},
                              {0, 0, 0, 0, 1, 0}};

  vector<int> init = {0, 0};
  vector<int> goal = {(int)grid.size() - 1, (int)grid[0].size() - 1};
  int cost = 1;

  vector<vector<int>> heuristic(grid.size(), vector<int>(grid[0].size()));
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      heuristic[i][j] = abs(i - goal[0]) + abs(j - goal[1]);
      if (grid[i][j] == 1)
        heuristic[i][j] = 99;
    }
  }

  Result res = search(grid, init, goal, cost, heuristic);

  cout << "Path: " << endl;
  for (auto &p : res.path)
    cout << "[" << p[0] << ", " << p[1] << "] ";
  cout << endl;

  return 0;
}