/**
 * Sudoku Solver - FILL IN THE BLANKS
 */
const N = 9;

// ... isSafe function ...

function solveSudoku(grid, row = 0, col = 0) {
    // Base case
    if (row === N - 1 && col === N) {
        return true;
    }

    if (col === N) {
        row++;
        col = 0;
    }

    if (grid[row][col] !== 0) {
        return solveSudoku(grid, row, col + 1);
    }

    for (let num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recurse
            if (solveSudoku(grid, ____________, ____________)) {
                return true;
            }

            // Backtrack
            grid[row][col] = ____________;
        }
    }
    return false;
}
