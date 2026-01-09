#include <iostream>
#include <vector>

bool isSafe(const std::vector<std::vector<int>> &board, int row, int col) {
  int n = board.size();

  // Check this column on upper side
  for (int i = 0; i < row; i++)
    if (board[i][col])
      return false;

  // Check upper diagonal on left side
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j])
      return false;

  // Check upper diagonal on right side
  for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    if (board[i][j])
      return false;

  return true;
}

void printBoard(const std::vector<std::vector<int>> &board) {
  for (const auto &row : board) {
    for (int cell : row) {
      std::cout << (cell ? "Q " : ". ");
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void solve(std::vector<std::vector<int>> &board, int row, int &solutions) {
  if (row >= board.size()) {
    solutions++;
    printBoard(board);
    return;
  }

  for (int col = 0; col < board.size(); col++) {
    if (isSafe(board, row, col)) {
      board[row][col] = 1;
      solve(board, row + 1, solutions);
      board[row][col] = 0; // Backtrack
    }
  }
}

int main() {
  int n = 4;
  std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
  int solutions = 0;

  solve(board, 0, solutions);
  std::cout << "Total solutions: " << solutions << std::endl;
  return 0;
}
