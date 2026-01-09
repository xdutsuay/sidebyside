/**
 * @file
 * @brief Knight's Tour Algorithm
 * @details
 * A Knight's tour is a sequence of moves of a knight on a chessboard such
 * that the knight visits every square exactly once.
 */

#include <iomanip>
#include <iostream>
#include <vector>

/**
 * @brief Checks if a position is valid
 * @param x X coordinate
 * @param y Y coordinate
 * @param N Board size
 * @param board The board
 * @return true if valid, false otherwise
 */
bool isValid(int x, int y, int N, const std::vector<std::vector<int>> &board) {
  return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

/**
 * @brief Prints the solution board
 * @param board The board
 */
void printSolution(const std::vector<std::vector<int>> &board) {
  int N = board.size();
  for (int x = 0; x < N; x++) {
    for (int y = 0; y < N; y++)
      std::cout << std::setw(3) << board[x][y] << " ";
    std::cout << std::endl;
  }
}

/**
 * @brief Recursive utility function to solve Knight Tour problem
 * @param x Current x coordinate
 * @param y Current y coordinate
 * @param movei Current move number
 * @param board The board
 * @param xMove Possible x moves
 * @param yMove Possible y moves
 * @return true if solution found, false otherwise
 */
bool solveKTUtil(int x, int y, int movei, std::vector<std::vector<int>> &board,
                 const int xMove[], const int yMove[]) {
  int N = board.size();
  int k, next_x, next_y;
  if (movei == N * N)
    return true;

  for (k = 0; k < 8; k++) {
    next_x = x + xMove[k];
    next_y = y + yMove[k];
    if (isValid(next_x, next_y, N, board)) {
      board[next_x][next_y] = movei;
      if (solveKTUtil(next_x, next_y, movei + 1, board, xMove, yMove))
        return true;
      else
        board[next_x][next_y] = -1; // backtracking
    }
  }
  return false;
}

/**
 * @brief Solves the Knight Tour problem using Backtracking
 * @param N Board size
 * @return true if solvable
 */
bool solveKT(int N) {
  std::vector<std::vector<int>> board(N, std::vector<int>(N, -1));

  // xMove[] and yMove[] define next move of Knight.
  // xMove[] is for next value of x coordinate
  // yMove[] is for next value of y coordinate
  int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
  int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

  // Since the Knight is initially at the first block
  board[0][0] = 0;

  if (!solveKTUtil(0, 0, 1, board, xMove, yMove)) {
    std::cout << "Solution does not exist";
    return false;
  } else
    printSolution(board);

  return true;
}

int main() {
  solveKT(5);
  return 0;
}
