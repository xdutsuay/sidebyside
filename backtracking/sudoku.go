package main

import "fmt"

const N = 9

func printGrid(grid [N][N]int) {
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			fmt.Printf("%d ", grid[i][j])
		}
		fmt.Println()
	}
}

func isSafe(grid [N][N]int, row, col, num int) bool {
	for x := 0; x < N; x++ {
		if grid[row][x] == num || grid[x][col] == num {
			return false
		}
	}

	startRow := row - row%3
	startCol := col - col%3
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if grid[i+startRow][j+startCol] == num {
				return false
			}
		}
	}
	return true
}

func solveSudoku(grid *[N][N]int, row, col int) bool {
	if row == N-1 && col == N {
		return true
	}

	if col == N {
		row++
		col = 0
	}

	if grid[row][col] != 0 {
		return solveSudoku(grid, row, col+1)
	}

	for num := 1; num <= 9; num++ {
		if isSafe(*grid, row, col, num) {
			grid[row][col] = num
			if solveSudoku(grid, row, col+1) {
				return true
			}
			grid[row][col] = 0
		}
	}
	return false
}

func main() {
	grid := [N][N]int{
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0},
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0},
	}

	if solveSudoku(&grid, 0, 0) {
		printGrid(grid)
	} else {
		fmt.Println("No solution exists")
	}
}
