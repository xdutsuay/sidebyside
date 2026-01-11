/**
 * @file
 * @brief Levenshtein Distance Algorithm (Optimized)
 * @details
 * Compute the Levenshtein distance between two words (strings).
 * The function is optimized for efficiency by modifying rows in place.
 * Time Complexity: O(min(N, M)) space
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

/**
 * @brief Computes Levenshtein distance
 * @param s1 First string
 * @param s2 Second string
 * @return int Distance
 */
int levenshtein_distance_optimized(std::string s1, std::string s2) {
  if (s1.length() < s2.length()) {
    return levenshtein_distance_optimized(s2, s1);
  }

  if (s2.length() == 0) {
    return s1.length();
  }

  std::vector<int> previous_row(s2.length() + 1);
  std::iota(previous_row.begin(), previous_row.end(), 0);

  for (size_t i = 0; i < s1.length(); ++i) {
    std::vector<int> current_row(s2.length() + 1);
    current_row[0] = i + 1;

    for (size_t j = 0; j < s2.length(); ++j) {
      int insertions = previous_row[j + 1] + 1;
      int deletions = current_row[j] + 1;
      int substitutions = previous_row[j] + (s1[i] != s2[j]);
      current_row[j + 1] = std::min({insertions, deletions, substitutions});
    }
    previous_row = current_row;
  }

  return previous_row.back();
}

int main() {
  std::string s1 = "kitten";
  std::string s2 = "sitting";

  std::cout << "Distance between " << s1 << " and " << s2
            << " is: " << levenshtein_distance_optimized(s1, s2) << std::endl;

  return 0;
}
