/**
 * @file
 * @brief Implementation of Matrix Multiplication
 * @details
 * Performs matrix multiplication of two 2D matrices.
 * Time Complexity: O(n^3)
 * Space Complexity: O(n^2) for result matrix
 */

#include <cassert>
#include <iostream>
#include <vector>

/**
 * @brief Multiplies two matrices
 * @param A First matrix
 * @param B Second matrix
 * @return Resultant matrix
 * @throws std::invalid_argument if dimensions don't match
 */
std::vector<std::vector<int>> multiply(const std::vector<std::vector<int>> &A,
                                       const std::vector<std::vector<int>> &B) {
  if (A.empty() || B.empty() || A[0].empty() || B[0].empty()) {
    throw std::invalid_argument("Matrices cannot be empty");
  }

  size_t rowsA = A.size();
  size_t colsA = A[0].size();
  size_t rowsB = B.size();
  size_t colsB = B[0].size();

  if (colsA != rowsB) {
    throw std::invalid_argument(
        "Matrix dimensions mismatch for multiplication");
  }

  std::vector<std::vector<int>> result(rowsA, std::vector<int>(colsB, 0));

  for (size_t i = 0; i < rowsA; ++i) {
    for (size_t j = 0; j < colsB; ++j) {
      for (size_t k = 0; k < colsA; ++k) {
        result[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  return result;
}

/**
 * @brief Self-test implementations
 */
void test() {
  std::vector<std::vector<int>> A = {{1, 2}, {3, 4}};
  std::vector<std::vector<int>> B = {{5, 6}, {7, 8}};
  std::vector<std::vector<int>> expected = {{19, 22}, {43, 50}};

  assert(multiply(A, B) == expected);

  std::vector<std::vector<int>> C = {{1, 2, 3}};
  std::vector<std::vector<int>> D = {{4}, {5}, {6}};
  std::vector<std::vector<int>> expected2 = {{32}};

  assert(multiply(C, D) == expected2);

  std::cout << "All tests passed!" << std::endl;
}

int main() {
  test();
  return 0;
}
