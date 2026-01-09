/**
 * @file
 * @brief Implementation of Strassen's Matrix Multiplication Algorithm
 * @details
 * Strassen's algorithm is a divide-and-conquer algorithm for matrix
 * multiplication. It is faster than the standard matrix multiplication
 * algorithm for large matrices, with a time complexity of approximately
 * O(n^2.8074).
 *
 * This implementation supports square matrices with dimensions that are powers
 * of 2. Padding is not implemented for simplicity, as per the educational goal.
 */

#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

/**
 * @brief Adds two matrices
 */
Matrix add(const Matrix &A, const Matrix &B) {
  int n = A.size();
  Matrix C(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      C[i][j] = A[i][j] + B[i][j];
  return C;
}

/**
 * @brief Subtracts two matrices
 */
Matrix subtract(const Matrix &A, const Matrix &B) {
  int n = A.size();
  Matrix C(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      C[i][j] = A[i][j] - B[i][j];
  return C;
}

/**
 * @brief Standard matrix multiplication for small matrices (base case)
 */
Matrix standard_multiply(const Matrix &A, const Matrix &B) {
  int n = A.size();
  Matrix C(n, std::vector<int>(n, 0));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k)
        C[i][j] += A[i][k] * B[k][j];
  return C;
}

/**
 * @brief Strassen's Matrix Multiplication
 */
Matrix strassen(const Matrix &A, const Matrix &B) {
  int n = A.size();
  if (n <= 2) {
    return standard_multiply(A, B);
  }

  int half = n / 2;
  Matrix a11(half, std::vector<int>(half));
  Matrix a12(half, std::vector<int>(half));
  Matrix a21(half, std::vector<int>(half));
  Matrix a22(half, std::vector<int>(half));
  Matrix b11(half, std::vector<int>(half));
  Matrix b12(half, std::vector<int>(half));
  Matrix b21(half, std::vector<int>(half));
  Matrix b22(half, std::vector<int>(half));

  for (int i = 0; i < half; ++i) {
    for (int j = 0; j < half; ++j) {
      a11[i][j] = A[i][j];
      a12[i][j] = A[i][j + half];
      a21[i][j] = A[i + half][j];
      a22[i][j] = A[i + half][j + half];

      b11[i][j] = B[i][j];
      b12[i][j] = B[i][j + half];
      b21[i][j] = B[i + half][j];
      b22[i][j] = B[i + half][j + half];
    }
  }

  Matrix p1 = strassen(a11, subtract(b12, b22));
  Matrix p2 = strassen(add(a11, a12), b22);
  Matrix p3 = strassen(add(a21, a22), b11);
  Matrix p4 = strassen(a22, subtract(b21, b11));
  Matrix p5 = strassen(add(a11, a22), add(b11, b22));
  Matrix p6 = strassen(subtract(a12, a22), add(b21, b22));
  Matrix p7 = strassen(subtract(a11, a21), add(b11, b12));

  Matrix c11 = add(subtract(add(p5, p4), p2), p6);
  Matrix c12 = add(p1, p2);
  Matrix c21 = add(p3, p4);
  Matrix c22 = subtract(subtract(add(p5, p1), p3), p7);

  Matrix C(n, std::vector<int>(n));
  for (int i = 0; i < half; ++i) {
    for (int j = 0; j < half; ++j) {
      C[i][j] = c11[i][j];
      C[i][j + half] = c12[i][j];
      C[i + half][j] = c21[i][j];
      C[i + half][j + half] = c22[i][j];
    }
  }

  return C;
}

void test() {
  Matrix A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  Matrix B = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

  Matrix Expected = A; // Multiplying by identity matrix

  assert(strassen(A, B) == Expected);
  std::cout << "All tests passed!" << std::endl;
}

int main() {
  test();
  return 0;
}
