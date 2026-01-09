/**
 * @file
 * @brief Implementation of Matrix Transposition
 * @details
 * Transposes a matrix (swaps rows and columns).
 * Time Complexity: O(R * C)
 * Space Complexity: O(R * C) for result matrix
 */

#include <cassert>
#include <iostream>
#include <vector>

/**
 * @brief Transposes a matrix
 * @param matrix Input matrix
 * @return Transposed matrix
 */
std::vector<std::vector<int>>
transpose(const std::vector<std::vector<int>> &matrix) {
  if (matrix.empty())
    return {};

  size_t rows = matrix.size();
  size_t cols = matrix[0].size();

  std::vector<std::vector<int>> result(cols, std::vector<int>(rows));

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      result[j][i] = matrix[i][j];
    }
  }

  return result;
}

/**
 * @brief Self-test implementations
 */
void test() {
  std::vector<std::vector<int>> matrix = {{1, 2}, {3, 4}};
  std::vector<std::vector<int>> expected = {{1, 3}, {2, 4}};
  assert(transpose(matrix) == expected);

  std::vector<std::vector<int>> matrix2 = {{1, 2, 3}, {4, 5, 6}};
  std::vector<std::vector<int>> expected2 = {{1, 4}, {2, 5}, {3, 6}};
  assert(transpose(matrix2) == expected2);

  std::cout << "All tests passed!" << std::endl;
}

int main() {
  test();
  return 0;
}
