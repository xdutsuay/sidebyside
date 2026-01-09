#include <iostream>
#include <string>
#include <vector>

std::vector<int> getFailureArray(const std::string &pattern) {
  // ... (helper function logic)
  std::vector<int> failure(pattern.length(), 0);
  // ...
  return failure;
}

int knuthMorrisPratt(const std::string &text, const std::string &pattern) {
  if (pattern.empty())
    return 0;
  std::vector<int> failure = getFailureArray(pattern);
  int i = 0; // index for text
  int j = 0; // index for pattern

  while (i < text.length()) {
    if (pattern[j] == text[i]) {
      if (j == pattern.length() - 1) {
        return i - j;
      }
      j++;
      i++;
    } else if (j > 0) {
      // Mismatch after some matches, use failure array to skip
      j = failure[____________];
    } else {
      // Mismatch at start of pattern
      i++;
    }
  }
  return -1;
}
