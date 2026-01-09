package main

import "fmt"

func SelectionSort(arr []int) {
	n := len(arr)
	for i := 0; i < n-1; i++ {
		min_idx := i
		for j := i + 1; j < n; j++ {
			if arr[j] < arr[min_idx] {
				min_idx = j
			}
		}
		if min_idx != i {
			arr[i], arr[min_idx] = arr[min_idx], arr[i]
		}
	}
}

func main() {
	arr := []int{64, 25, 12, 22, 11}
	fmt.Println("Original:", arr)
	SelectionSort(arr)
	fmt.Println("Sorted:", arr)
}
