package main

import "fmt"

/**
 * FindUniqueNumber finds the unique number in a slice where every other number appears twice.
 * It uses the XOR operation which is O(n) time complexity and O(1) space complexity.
 */
func FindUniqueNumber(arr []int) int {
	result := 0
	for _, num := range arr {
		result ^= num
	}
	return result
}

func main() {
	// Simple test cases
	testCases := [][]int{
		{2, 2, 1},
		{4, 1, 2, 1, 2},
		{1},
	}

	expected := []int{1, 4, 1}

	for i, tc := range testCases {
		res := FindUniqueNumber(tc)
		if res != expected[i] {
			fmt.Printf("Test Case %d Failed: Expected %d, Got %d\n", i+1, expected[i], res)
		} else {
			fmt.Printf("Test Case %d Passed\n", i+1)
		}
	}
}
