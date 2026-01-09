package main

func InsertionSort(arr []int) {
	for i := 1; i < len(arr); i++ {
		key := arr[i]
		j := i - 1

		// Move elements of arr[0..i-1], that are
		// greater than key, to one position ahead
		for j >= 0 && arr[j] > ____________ {
			arr[j+1] = ____________
			j = j - 1
		}
		arr[j+1] = ____________
	}
}
