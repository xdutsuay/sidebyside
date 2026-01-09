package main

import "fmt"

func isSafe(board [][]int, row, col int) bool {
	n := len(board)

	// Check column
	for i := 0; i < row; i++ {
		if board[i][col] == 1 {
			return false
		}
	}

	// Check upper left diagonal
	for i, j := row, col; i >= 0 && j >= 0; i, j = i-1, j-1 {
		if board[i][j] == 1 {
			return false
		}
	}

	// Check upper right diagonal
	for i, j := row, col; i >= 0 && j < n; i, j = i-1, j+1 {
		if board[i][j] == 1 {
			return false
		}
	}

	return true
}

func printBoard(board [][]int) {
	for _, row := range board {
		for _, cell := range row {
			if cell == 1 {
				fmt.Print("Q ")
			} else {
				fmt.Print(". ")
			}
		}
		fmt.Println()
	}
	fmt.Println()
}

func solve(board [][]int, row int, solutions *int) {
	if row >= len(board) {
		*solutions++
		printBoard(board)
		return
	}

	for col := 0; col < len(board); col++ {
		if isSafe(board, row, col) {
			board[row][col] = 1
			solve(board, row+1, solutions)
			board[row][col] = 0 // Backtrack
		}
	}
}

func main() {
	n := 4
	board := make([][]int, n)
	for i := range board {
		board[i] = make([]int, n)
	}
	solutions := 0
	solve(board, 0, &solutions)
	fmt.Printf("Total solutions: %d\n", solutions)
}
