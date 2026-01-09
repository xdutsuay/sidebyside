fn is_safe(board: &Vec<Vec<u8>>, row: usize, col: usize) -> bool {
    let n = board.len();

    // Check column
    for i in 0..row {
        if board[i][col] == 1 { return false; }
    }

    // Check upper left diagonal
    let (mut i, mut j) = (row as i32, col as i32);
    while i >= 0 && j >= 0 {
        if board[i as usize][j as usize] == 1 { return false; }
        i -= 1;
        j -= 1;
    }

    // Check upper right diagonal
    let (mut i, mut j) = (row as i32, col as i32);
    while i >= 0 && j < n as i32 {
        if board[i as usize][j as usize] == 1 { return false; }
        i -= 1;
        j += 1;
    }

    true
}

fn print_board(board: &Vec<Vec<u8>>) {
    for row in board {
        for cell in row {
            print!("{} ", if *cell == 1 { "Q" } else { "." });
        }
        println!();
    }
    println!();
}

fn solve(board: &mut Vec<Vec<u8>>, row: usize, solutions: &mut u32) {
    if row >= board.len() {
        *solutions += 1;
        print_board(board);
        return;
    }

    for col in 0..board.len() {
        if is_safe(board, row, col) {
            board[row][col] = 1;
            solve(board, row + 1, solutions);
            board[row][col] = 0;
        }
    }
}

fn main() {
    let n = 4;
    let mut board = vec![vec![0; n]; n];
    let mut solutions = 0;
    solve(&mut board, 0, &mut solutions);
    println!("Total solutions: {}", solutions);
}
