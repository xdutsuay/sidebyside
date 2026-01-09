package main

import "fmt"

// BinarySearch - FILL IN THE BLANKS
func BinarySearch(arr []int, target int) int {
	left := 0
	right := len(arr) - 1

	for left <= ____________ {
		mid := left + (right-left)/2

		if arr[mid] == ____________ {
			return mid
		}
		if arr[mid] < target {
			left = mid + 1
		} else {
			right = ____________
		}
	}
	return -1
}

func main() {
	arr := []int{2, 3, 4, 10, 40}
	fmt.Println(BinarySearch(arr, 10))
}
