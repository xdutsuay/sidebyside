package main

import "fmt"

// LinearSearch returns the index of target in arr, or -1 if not found
func LinearSearch(arr []int, target int) int {
	for i, v := range arr {
		if v == target {
			return i
		}
	}
	return -1
}

func main() {
	arr := []int{10, 50, 30, 70, 80, 20}
	target := 30
	result := LinearSearch(arr, target)
	
	if result != -1 {
		fmt.Printf("Element found at index %d\n", result)
	} else {
		fmt.Println("Element not found")
	}
}
