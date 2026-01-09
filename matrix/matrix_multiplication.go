package main

import (
	"errors"
	"fmt"
	"reflect"
)

// Multiply performs matrix multiplication
func Multiply(A, B [][]int) ([][]int, error) {
	if len(A) == 0 || len(B) == 0 || len(A[0]) == 0 || len(B[0]) == 0 {
		return nil, errors.New("matrices cannot be empty")
	}

	rowsA := len(A)
	colsA := len(A[0])
	rowsB := len(B)
	colsB := len(B[0])

	if colsA != rowsB {
		return nil, errors.New("matrix dimensions mismatch for multiplication")
	}

	result := make([][]int, rowsA)
	for i := range result {
		result[i] = make([]int, colsB)
	}

	for i := 0; i < rowsA; i++ {
		for j := 0; j < colsB; j++ {
			for k := 0; k < colsA; k++ {
				result[i][j] += A[i][k] * B[k][j]
			}
		}
	}

	return result, nil
}

func main() {
	A := [][]int{{1, 2}, {3, 4}}
	B := [][]int{{5, 6}, {7, 8}}
	expected := [][]int{{19, 22}, {43, 50}}

	result, err := Multiply(A, B)
	if err != nil {
		fmt.Println("Error:", err)
		return
	}

	if reflect.DeepEqual(result, expected) {
		fmt.Println("Test 1 Passed")
	} else {
		fmt.Println("Test 1 Failed")
	}
}
