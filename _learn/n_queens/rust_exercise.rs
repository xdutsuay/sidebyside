fn solve(board: &mut Vec<Vec<u8>>, row: usize, solutions: &mut u32) {
    if row >= board.len() {
        *solutions += 1;
        // ...
        return;
    }

    for col in 0..board.len() {
        if is_safe(board, row, col) {
            // Place queen
            board[row][col] = 1;
            
            // Recurse
            solve(board, ____________, solutions);
            
            // Backtrack
            board[row][col] = ____________;
        }
    }
}
