const N: usize = 9;

// ... is_safe ...

fn solve_sudoku(grid: &mut [[u8; N]; N], row: usize, col: usize) -> bool {
    let mut row = row;
    let mut col = col;

    if row == N - 1 && col == N {
        return true;
    }
    // ... handling row/col wrapping

    if grid[row][col] != 0 {
        return solve_sudoku(grid, row, col + 1);
    }

    for num in 1..=9 {
        if is_safe(grid, row, col, num) {
            grid[row][col] = num;
            // Recurse
            if solve_sudoku(grid, ____________, ____________) {
                return true;
            }
            // Backtrack
            grid[row][col] = ____________;
        }
    }
    false
}
