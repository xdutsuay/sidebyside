#include <iostream>
#include <vector>

#define N 9

bool isSafe(const std::vector<std::vector<int>> &grid, int row, int col,
            int num) {
  // Check row and column
  for (int x = 0; x < N; x++)
    if (grid[row][x] == num || grid[x][col] == num)
      return false;

  // Check 3x3 box
  int startRow = row - row % 3;
  int startCol = col - col % 3;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (grid[i + startRow][j + startCol] == num)
        return false;

  return true;
}

bool solveSudoku(std::vector<std::vector<int>> &grid, int row, int col) {
  // Base case
  if (row == N - 1 && col == N)
    return true;

  // Move to next row
  if (col == N) {
    row++;
    col = 0;
  }

  // Skip filled cells
  if (grid[row][col] != 0)
    return solveSudoku(grid, row, col + 1);

  for (int num = 1; num <= 9; num++) {
    if (isSafe(grid, row, col, num)) {
      grid[row][col] = num;
      // Recurse
      if (solveSudoku(grid, ____________, ____________))
        return true;
      // Backtrack
      grid[row][col] = ____________;
    }
  }
  return false;
}
