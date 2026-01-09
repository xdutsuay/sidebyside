package main

// ...

func solveSudoku(grid *[N][N]int, row, col int) bool {
    // ... base cases
    
	if grid[row][col] != 0 {
		return solveSudoku(grid, row, col+1)
	}

	for num := 1; num <= 9; num++ {
		if isSafe(*grid, row, col, num) {
			grid[row][col] = num
			// Recurse
			if solveSudoku(grid, ____________, ____________) {
				return true
			}
			// Backtrack
			grid[row][col] = ____________
		}
	}
	return false
}
