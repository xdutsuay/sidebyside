package main

import (
	"fmt"
	"math"
)

func GreatestCommonDivisorRecursive(a, b int) int {
	if a == 0 {
		return int(math.Abs(float64(b)))
	}
	return GreatestCommonDivisorRecursive(b%a, a)
}

func GreatestCommonDivisorIterative(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return int(math.Abs(float64(a)))
}

func main() {
	a, b := 24, 40
	fmt.Printf("GCD Recursive (%d, %d) = %d\n", a, b, GreatestCommonDivisorRecursive(a, b))
	fmt.Printf("GCD Iterative (%d, %d) = %d\n", a, b, GreatestCommonDivisorIterative(a, b))
}
