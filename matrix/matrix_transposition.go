package main

import (
	"fmt"
	"reflect"
)

// Transpose transposes a matrix
func Transpose(matrix [][]int) [][]int {
	if len(matrix) == 0 {
		return [][]int{}
	}

	rows := len(matrix)
	cols := len(matrix[0])

	result := make([][]int, cols)
	for i := range result {
		result[i] = make([]int, rows)
	}

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			result[j][i] = matrix[i][j]
		}
	}

	return result
}

func main() {
	matrix := [][]int{{1, 2}, {3, 4}}
	expected := [][]int{{1, 3}, {2, 4}}

	result := Transpose(matrix)

	if reflect.DeepEqual(result, expected) {
		fmt.Println("Test 1 Passed")
	} else {
		fmt.Println("Test 1 Failed")
	}
}
