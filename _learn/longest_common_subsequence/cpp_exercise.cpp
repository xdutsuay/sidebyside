#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int longestCommonSubsequenceLength(const std::string &x, const std::string &y) {
  int m = x.length();
  int n = y.length();
  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (x[i - 1] == y[j - 1]) {
        dp[i][j] = 1 + ____________; // Match
      } else {
        dp[i][j] = std::max(
            ____________, ____________); // Max of skipping one char from x or y
      }
    }
  }
  return dp[m][n];
}
