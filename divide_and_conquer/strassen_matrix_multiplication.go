package main

import (
	"fmt"
	"reflect"
)

type Matrix [][]int

func add(A, B Matrix) Matrix {
	n := len(A)
	C := make(Matrix, n)
	for i := range C {
		C[i] = make([]int, n)
		for j := 0; j < n; j++ {
			C[i][j] = A[i][j] + B[i][j]
		}
	}
	return C
}

func subtract(A, B Matrix) Matrix {
	n := len(A)
	C := make(Matrix, n)
	for i := range C {
		C[i] = make([]int, n)
		for j := 0; j < n; j++ {
			C[i][j] = A[i][j] - B[i][j]
		}
	}
	return C
}

func standardMultiply(A, B Matrix) Matrix {
	n := len(A)
	C := make(Matrix, n)
	for i := range C {
		C[i] = make([]int, n)
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				C[i][j] += A[i][k] * B[k][j]
			}
		}
	}
	return C
}

func Strassen(A, B Matrix) Matrix {
	n := len(A)
	if n <= 2 {
		return standardMultiply(A, B)
	}

	half := n / 2
	a11 := make(Matrix, half)
	a12 := make(Matrix, half)
	a21 := make(Matrix, half)
	a22 := make(Matrix, half)
	b11 := make(Matrix, half)
	b12 := make(Matrix, half)
	b21 := make(Matrix, half)
	b22 := make(Matrix, half)

	for i := 0; i < half; i++ {
		a11[i] = make([]int, half)
		a12[i] = make([]int, half)
		a21[i] = make([]int, half)
		a22[i] = make([]int, half)
		b11[i] = make([]int, half)
		b12[i] = make([]int, half)
		b21[i] = make([]int, half)
		b22[i] = make([]int, half)

		for j := 0; j < half; j++ {
			a11[i][j] = A[i][j]
			a12[i][j] = A[i][j+half]
			a21[i][j] = A[i+half][j]
			a22[i][j] = A[i+half][j+half]

			b11[i][j] = B[i][j]
			b12[i][j] = B[i][j+half]
			b21[i][j] = B[i+half][j]
			b22[i][j] = B[i+half][j+half]
		}
	}

	p1 := Strassen(a11, subtract(b12, b22))
	p2 := Strassen(add(a11, a12), b22)
	p3 := Strassen(add(a21, a22), b11)
	p4 := Strassen(a22, subtract(b21, b11))
	p5 := Strassen(add(a11, a22), add(b11, b22))
	p6 := Strassen(subtract(a12, a22), add(b21, b22))
	p7 := Strassen(subtract(a11, a21), add(b11, b12))

	c11 := add(subtract(add(p5, p4), p2), p6)
	c12 := add(p1, p2)
	c21 := add(p3, p4)
	c22 := subtract(subtract(add(p5, p1), p3), p7)

	C := make(Matrix, n)
	for i := 0; i < n; i++ {
		C[i] = make([]int, n)
	}

	for i := 0; i < half; i++ {
		for j := 0; j < half; j++ {
			C[i][j] = c11[i][j]
			C[i][j+half] = c12[i][j]
			C[i+half][j] = c21[i][j]
			C[i+half][j+half] = c22[i][j]
		}
	}

	return C
}

func main() {
	A := Matrix{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},
	}

	B := Matrix{
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1},
	}

	result := Strassen(A, B)
	if reflect.DeepEqual(result, A) {
		fmt.Println("Test Passed")
	} else {
		fmt.Println("Test Failed")
	}
}
