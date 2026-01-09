/**
 * N-Queens - FILL IN THE BLANKS
 */

function solve(board, row) {
    if (row >= board.length) {
        solutions++;
        // ...
        return;
    }

    for (let col = 0; col < board.length; col++) {
        if (isSafe(board, row, col)) {
            // Place queen
            board[row][col] = 1;

            // Recurse to next row
            solve(board, ____________);

            // Backtrack: Remove queen to explore other possibilities
            board[row][col] = ____________;
        }
    }
}
