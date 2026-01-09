package main

import "fmt"

func getFailureArray(pattern string) []int {
	failure := make([]int, len(pattern))
	i := 0
	j := 1

	for j < len(pattern) {
		if pattern[i] == pattern[j] {
			i++
			failure[j] = i
			j++
		} else if i > 0 {
			i = failure[i-1]
		} else {
			failure[j] = 0
			j++
		}
	}
	return failure
}

func KnuthMorrisPratt(text, pattern string) int {
	if len(pattern) == 0 {
		return 0
	}
	failure := getFailureArray(pattern)
	i := 0
	j := 0

	for i < len(text) {
		if pattern[j] == text[i] {
			if j == len(pattern)-1 {
				return i - j
			}
			j++
			i++
		} else if j > 0 {
			j = failure[j-1]
		} else {
			i++
		}
	}
	return -1
}

func main() {
	text := "ABABDABACDABABCABAB"
	pattern := "ABABCABAB"
	index := KnuthMorrisPratt(text, pattern)
	fmt.Printf("Pattern found at index %d\n", index)
}
