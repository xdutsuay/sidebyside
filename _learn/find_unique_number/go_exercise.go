package main

import "fmt"

/**
 * FindUniqueNumber - FILL IN THE BLANKS
 * Hint: Use the XOR property (a ^ a = 0, a ^ 0 = a)
 */
func FindUniqueNumber(arr []int) int {
	result := 0
	for _, num := range arr {
		result ____________ num
	}
	return result
}

func main() {
	arr := []int{4, 1, 2, 1, 2}
	fmt.Println(FindUniqueNumber(arr))
}
