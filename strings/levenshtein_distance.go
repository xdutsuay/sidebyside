package main

import (
	"fmt"
)

func min(a, b, c int) int {
	if a < b {
		if a < c {
			return a
		}
		return c
	}
	if b < c {
		return b
	}
	return c
}

func levenshteinDistanceOptimized(s1, s2 string) int {
	r1 := []rune(s1)
	r2 := []rune(s2)

	if len(r1) < len(r2) {
		return levenshteinDistanceOptimized(s2, s1)
	}

	if len(r2) == 0 {
		return len(r1)
	}

	previousRow := make([]int, len(r2)+1)
	for i := range previousRow {
		previousRow[i] = i
	}

	for i, c1 := range r1 {
		currentRow := make([]int, 0)
		currentRow = append(currentRow, i+1)

		for j, c2 := range r2 {
			insertions := previousRow[j+1] + 1
			deletions := currentRow[j] + 1
			substitutions := previousRow[j]
			if c1 != c2 {
				substitutions++
			}
			currentRow = append(currentRow, min(insertions, deletions, substitutions))
		}
		previousRow = currentRow
	}

	return previousRow[len(previousRow)-1]
}

func main() {
	s1 := "kitten"
	s2 := "sitting"
	fmt.Printf("Distance between %s and %s is: %d\n", s1, s2, levenshteinDistanceOptimized(s1, s2))
}
