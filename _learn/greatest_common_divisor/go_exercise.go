package main

import "math"

func GreatestCommonDivisorRecursive(a, b int) int {
	if a == 0 {
		return int(math.Abs(float64(b)))
	}
	return GreatestCommonDivisorRecursive(____________, ____________)
}

func GreatestCommonDivisorIterative(a, b int) int {
	for b != 0 {
		a, b = ____________, ____________
	}
	return int(math.Abs(float64(a)))
}
