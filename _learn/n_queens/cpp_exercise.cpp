#include <iostream>
#include <vector>

bool isSafe(const std::vector<std::vector<int>> &board, int row, int col) {
  // Check constraints: Column, Upper Left Diag, Upper Right Diag
  // ...
  return true;
}

void solve(std::vector<std::vector<int>> &board, int row, int &solutions) {
  if (row >= board.size()) {
    solutions++;
    // Print board...
    return;
  }

  for (int col = 0; col < board.size(); col++) {
    if (isSafe(board, row, col)) {
      // Place queen
      board[row][col] = 1;

      // Recurse
      solve(board, ____________, solutions);

      // Backtrack: remove queen
      board[row][col] = ____________;
    }
  }
}
