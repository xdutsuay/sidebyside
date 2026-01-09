package main

import "fmt"

// partition splits the slice around a pivot
func partition(arr []int, low, high int) int {
	pivot := arr[____________] // Pivot is the last element
	i := low - 1

	for j := low; j < high; j++ {
		if arr[j] <= ____________ {
			i++
			// Swap
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	// Swap pivot to correct position
	arr[i+1], arr[high] = arr[high], arr[i+1]
	return i + 1
}

// quickSort recursive function
func quickSort(arr []int, low, high int) {
	if low < high {
		pi := partition(arr, low, high)

		// Recursive sorting
		quickSort(arr, low, ____________)
		quickSort(arr, ____________, high)
	}
}

func main() {
	arr := []int{10, 7, 8, 9, 1, 5}
	fmt.Println("Initial:", arr)

	quickSort(arr, 0, len(arr)-1)

	fmt.Println("Sorted: ", arr)
}
