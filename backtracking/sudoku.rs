const N: usize = 9;

fn print_grid(grid: &[[u8; N]; N]) {
    for row in grid {
        for cell in row {
            print!("{} ", cell);
        }
        println!();
    }
}

fn is_safe(grid: &[[u8; N]; N], row: usize, col: usize, num: u8) -> bool {
    for x in 0..N {
        if grid[row][x] == num || grid[x][col] == num {
            return false;
        }
    }

    let start_row = row - row % 3;
    let start_col = col - col % 3;
    for i in 0..3 {
        for j in 0..3 {
            if grid[i + start_row][j + start_col] == num {
                return false;
            }
        }
    }
    true
}

fn solve_sudoku(grid: &mut [[u8; N]; N], row: usize, col: usize) -> bool {
    let mut row = row;
    let mut col = col;

    if row == N - 1 && col == N {
        return true;
    }

    if col == N {
        row += 1;
        col = 0;
    }

    if grid[row][col] != 0 {
        return solve_sudoku(grid, row, col + 1);
    }

    for num in 1..=9 {
        if is_safe(grid, row, col, num) {
            grid[row][col] = num;
            if solve_sudoku(grid, row, col + 1) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    false
}

fn main() {
    let mut grid: [[u8; N]; N] = [
        [3, 0, 6, 5, 0, 8, 4, 0, 0],
        [5, 2, 0, 0, 0, 0, 0, 0, 0],
        [0, 8, 7, 0, 0, 0, 0, 3, 1],
        [0, 0, 3, 0, 1, 0, 0, 8, 0],
        [9, 0, 0, 8, 6, 3, 0, 0, 5],
        [0, 5, 0, 0, 9, 0, 6, 0, 0],
        [1, 3, 0, 0, 0, 0, 2, 5, 0],
        [0, 0, 0, 0, 0, 0, 0, 7, 4],
        [0, 0, 5, 2, 0, 6, 3, 0, 0],
    ];

    if solve_sudoku(&mut grid, 0, 0) {
        print_grid(&grid);
    } else {
        println!("No solution exists");
    }
}
