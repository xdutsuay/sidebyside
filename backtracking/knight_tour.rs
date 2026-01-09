/**
 * Knight's Tour Algorithm in Rust
 */

fn is_valid(x: i32, y: i32, n: usize, board: &Vec<Vec<i32>>) -> bool {
    x >= 0 && x < n as i32 && y >= 0 && y < n as i32 && board[x as usize][y as usize] == -1
}

fn solve_kt_util(
    x: i32,
    y: i32,
    movei: i32,
    board: &mut Vec<Vec<i32>>,
    x_move: &[i32],
    y_move: &[i32],
    n: usize,
) -> bool {
    if movei == (n * n) as i32 {
        return true;
    }

    for k in 0..8 {
        let next_x = x + x_move[k];
        let next_y = y + y_move[k];

        if is_valid(next_x, next_y, n, board) {
            board[next_x as usize][next_y as usize] = movei;
            if solve_kt_util(next_x, next_y, movei + 1, board, x_move, y_move, n) {
                return true;
            } else {
                board[next_x as usize][next_y as usize] = -1; // backtracking
            }
        }
    }
    false
}

fn solve_kt(n: usize) -> bool {
    let mut board = vec![vec![-1; n]; n];

    let x_move = [2, 1, -1, -2, -2, -1, 1, 2];
    let y_move = [1, 2, 2, 1, -1, -2, -2, -1];

    board[0][0] = 0;

    if !solve_kt_util(0, 0, 1, &mut board, &x_move, &y_move, n) {
        println!("Solution does not exist");
        return false;
    } else {
        print_solution(&board);
    }
    true
}

fn print_solution(board: &Vec<Vec<i32>>) {
    for row in board {
        for val in row {
            print!("{:3} ", val);
        }
        println!();
    }
}

fn main() {
    solve_kt(5);
}
