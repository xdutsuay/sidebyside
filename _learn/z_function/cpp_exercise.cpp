#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> zFunction(const std::string &s) {
  int n = s.length();
  std::vector<int> z(n, 0);
  int l = 0, r = 0;

  for (int i = 1; i < n; ++i) {
    if (i <= r) {
      // Optimization: Use previously computed Z-value
      z[i] = std::min(r - i + 1, z[____________]);
    }
    // Naive expansion
    while (i + z[i] < n && s[z[i]] == s[____________]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = ____________;
    }
  }
  return z;
}
