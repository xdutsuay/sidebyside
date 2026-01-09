#include <iostream>
#include <string>
#include <vector>

std::vector<int> getFailureArray(const std::string &pattern) {
  std::vector<int> failure(pattern.length());
  failure[0] = 0;
  int i = 0;
  int j = 1;

  while (j < pattern.length()) {
    if (pattern[i] == pattern[j]) {
      i++;
      failure[j] = i;
      j++;
    } else if (i > 0) {
      i = failure[i - 1];
    } else {
      failure[j] = 0;
      j++;
    }
  }
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
      j = failure[j - 1];
    } else {
      i++;
    }
  }
  return -1;
}

int main() {
  std::string text = "ABABDABACDABABCABAB";
  std::string pattern = "ABABCABAB";
  int index = knuthMorrisPratt(text, pattern);

  if (index != -1) {
    std::cout << "Pattern found at index " << index << std::endl;
  } else {
    std::cout << "Pattern not found" << std::endl;
  }
  return 0;
}
