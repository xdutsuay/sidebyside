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
      z[i] = std::min(r - i + 1, z[i - l]);
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}

int findPattern(const std::string &pattern, const std::string &text) {
  std::string combined = pattern + "$" + text;
  std::vector<int> z = zFunction(combined);
  int count = 0;
  int pLen = pattern.length();

  for (int i = 0; i < z.size(); ++i) {
    if (z[i] == pLen) {
      count++;
    }
  }
  return count;
}

int main() {
  std::string text = "abracadabra";
  std::string pattern = "abr";

  std::cout << "Occurrences: " << findPattern(pattern, text) << std::endl;
  return 0;
}
