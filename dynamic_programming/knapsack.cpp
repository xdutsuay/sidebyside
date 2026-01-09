#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

// Structure to hold both optimal value and subset
struct Solution {
  int maxValue;
  std::set<int> selectedItems;
};

// Reconstruct the solution
void constructSolution(const std::vector<std::vector<int>> &dp,
                       const std::vector<int> &wt, int i, int j,
                       std::set<int> &optimalSet) {
  if (i > 0 && j > 0) {
    if (dp[i - 1][j] == dp[i][j]) {
      constructSolution(dp, wt, i - 1, j, optimalSet);
    } else {
      optimalSet.insert(
          i); // Using 1-based indexing for items as in Python example
      constructSolution(dp, wt, i - 1, j - wt[i - 1], optimalSet);
    }
  }
}

// 0/1 Knapsack
Solution knapsack(int W, const std::vector<int> &wt,
                  const std::vector<int> &val) {
  int n = wt.size();
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

  for (int i = 1; i <= n; ++i) {
    for (int w = 1; w <= W; ++w) {
      if (wt[i - 1] <= w) {
        dp[i][w] =
            std::max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
      } else {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  Solution sol;
  sol.maxValue = dp[n][W];
  constructSolution(dp, wt, n, W, sol.selectedItems);
  return sol;
}

int main() {
  std::vector<int> val = {3, 2, 4, 4};
  std::vector<int> wt = {4, 3, 2, 3};
  int W = 6;

  Solution sol = knapsack(W, wt, val);

  std::cout << "Optimal Value: " << sol.maxValue << std::endl;
  std::cout << "Selected Items: ";
  for (int item : sol.selectedItems) {
    std::cout << item << " ";
  }
  std::cout << std::endl;

  return 0;
}
