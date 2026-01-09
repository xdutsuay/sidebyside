/**
 * @file
 * @brief Implementation to rotate a matrix by 90 degrees clockwise
 * @details
 * Rotates an N x N matrix 90 degrees clockwise in-place.
 * Space Complexity: O(1)
 * Time Complexity: O(N^2)
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

/**
 * @brief Rotates matrix 90 degrees clockwise
 * @param matrix Reference to the matrix to be rotated
 */
void rotate(std::vector<std::vector<int>> &matrix) {
  int n = matrix.size();

  // Transpose the matrix
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      std::swap(matrix[i][j], matrix[j][i]);
    }
  }

  // Reverse each row
  for (int i = 0; i < n; i++) {
    std::reverse(matrix[i].begin(), matrix[i].end());
  }
}

/**
 * @brief Self-test implementations
 */
void test() {
  std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<std::vector<int>> expected = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};

  rotate(matrix);
  assert(matrix == expected);

  std::cout << "All tests passed!" << std::endl;
}

int main() {
  test();
  return 0;
}
