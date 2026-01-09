package main

// ...

func solve(board [][]int, row int, solutions *int) {
	if row >= len(board) {
		*solutions++
		// ...
		return
	}

	for col := 0; col < len(board); col++ {
		if isSafe(board, row, col) {
			// Place queen
			board[row][col] = 1
			
			// Recurse
			solve(board, ____________, solutions)
			
			// Backtrack
			board[row][col] = ____________
		}
	}
}
