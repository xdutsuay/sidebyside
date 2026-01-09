package main

import "fmt"

func merge(left, right []int) []int {
	result := make([]int, 0, len(left)+len(right))
	i, j := 0, 0

	for i < len(left) && j < len(right) {
		if left[i] <= ____________ { // Compare
			result = append(result, left[i])
			i++
		} else {
			result = append(result, right[j])
			j++
		}
	}

	result = append(result, left[i:]...)
	result = append(result, right[j:]...)
	return result
}

func mergeSort(arr []int) []int {
	if len(arr) <= 1 {
		return arr
	}

	mid := len(arr) / 2
	// Recursion
	left := mergeSort(arr[:____________])
	right := mergeSort(arr[____________:])

	return merge(left, right)
}

func main() {
	arr := []int{12, 11, 13, 5, 6, 7}
	fmt.Println(mergeSort(arr))
}
