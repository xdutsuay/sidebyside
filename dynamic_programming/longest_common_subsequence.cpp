#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Result {
  int length;
  std::string subsequence;
};

Result longestCommonSubsequence(const std::string &x, const std::string &y) {
  int m = x.length();
  int n = y.length();

  // DP table
  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

  // Build DP table
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (x[i - 1] == y[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  // Reconstruct subsequence
  std::string seq = "";
  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (x[i - 1] == y[j - 1]) {
      seq = x[i - 1] + seq;
      i--;
      j--;
    } else if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else {
      j--;
    }
  }

  return {dp[m][n], seq};
}

int main() {
  std::string a = "AGGTAB";
  std::string b = "GXTXAYB";

  Result res = longestCommonSubsequence(a, b);
  std::cout << "Length: " << res.length << std::endl;
  std::cout << "Subsequence: " << res.subsequence << std::endl;

  return 0;
}
