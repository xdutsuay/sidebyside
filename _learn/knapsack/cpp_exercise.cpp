#include <algorithm>
#include <iostream>
#include <vector>

int knapsack(int W, const std::vector<int> &wt, const std::vector<int> &val) {
  int n = wt.size();
  // Initialize DP table
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

  for (int i = 1; i <= n; ++i) {
    for (int w = 1; w <= W; ++w) {
      if (wt[i - 1] <= w) {
        // Max of include or exclude
        dp[i][w] =
            std::max(____________ + dp[i - 1][w - ____________], // Include
                     dp[i - 1][w]                                // Exclude
            );
      } else {
        dp[i][w] = ____________; // Exclude
      }
    }
  }
  return dp[n][W];
}
