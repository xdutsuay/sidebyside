package main

import (
	"fmt"
)

// BubbleSort - FILL IN THE BLANKS
func BubbleSort(arr []int) {
	n := len(arr)
	for i := 0; i < n-1; i++ {
		swapped := false
		// Inner loop limit
		for j := 0; j < ____________; j++ {
			// Compare
			if arr[j] > arr[____________] {
				arr[j], arr[j+1] = arr[j+1], arr[j]
				swapped = true
			}
		}
		if !swapped {
			____________
		}
	}
}

func main() {
	arr := []int{64, 34, 25, 12, 22, 11, 90}
	fmt.Println("Unsorted array:", arr)

	BubbleSort(arr)

	fmt.Println("Sorted array:", arr)
}
