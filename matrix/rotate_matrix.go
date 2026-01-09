package main

import (
	"fmt"
	"reflect"
)

// Rotate rotates the matrix 90 degrees clockwise in-place
func Rotate(matrix [][]int) {
	n := len(matrix)

	// Transpose
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}

	// Reverse rows
	for i := 0; i < n; i++ {
		for j, k := 0, n-1; j < k; j, k = j+1, k-1 {
			matrix[i][j], matrix[i][k] = matrix[i][k], matrix[i][j]
		}
	}
}

func main() {
	matrix := [][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}
	expected := [][]int{
		{7, 4, 1},
		{8, 5, 2},
		{9, 6, 3},
	}

	Rotate(matrix)

	if reflect.DeepEqual(matrix, expected) {
		fmt.Println("Test Passed")
	} else {
		fmt.Println("Test Failed")
	}
}
