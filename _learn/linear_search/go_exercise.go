package main

import "fmt"

// LinearSearch - FILL IN THE BLANKS
func LinearSearch(arr []int, target int) int {
	// Range loop
	for i, v := range ____________ {
		if v == ____________ {
			return i
		}
	}
	return -1
}

func main() {
	arr := []int{10, 50, 30, 70, 80, 20}
	fmt.Println(LinearSearch(arr, 30))
}
