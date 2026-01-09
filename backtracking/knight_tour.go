package main

import (
	"fmt"
)

func isValid(x, y, N int, board [][]int) bool {
	return x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1
}

func solveKTUtil(x, y, movei int, board [][]int, xMove, yMove []int, N int) bool {
	if movei == N*N {
		return true
	}

	for k := 0; k < 8; k++ {
		nextX := x + xMove[k]
		nextY := y + yMove[k]
		if isValid(nextX, nextY, N, board) {
			board[nextX][nextY] = movei
			if solveKTUtil(nextX, nextY, movei+1, board, xMove, yMove, N) {
				return true
			}
			board[nextX][nextY] = -1
		}
	}
	return false
}

func solveKT(N int) bool {
	board := make([][]int, N)
	for i := range board {
		board[i] = make([]int, N)
		for j := range board[i] {
			board[i][j] = -1
		}
	}

	xMove := []int{2, 1, -1, -2, -2, -1, 1, 2}
	yMove := []int{1, 2, 2, 1, -1, -2, -2, -1}

	board[0][0] = 0

	if !solveKTUtil(0, 0, 1, board, xMove, yMove, N) {
		fmt.Println("Solution does not exist")
		return false
	} else {
		printSolution(board)
	}
	return true
}

func printSolution(board [][]int) {
	for _, row := range board {
		for _, val := range row {
			fmt.Printf("%3d ", val)
		}
		fmt.Println()
	}
}

func main() {
	solveKT(5)
}
