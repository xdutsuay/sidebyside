package main

import (
	"fmt"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func ZFunction(s string) []int {
	n := len(s)
	z := make([]int, n)
	l, r := 0, 0

	for i := 1; i < n; i++ {
		if i <= r {
			z[i] = min(r-i+1, z[i-l])
		}
		for i+z[i] < n && s[z[i]] == s[i+z[i]] {
			z[i]++
		}
		if i+z[i]-1 > r {
			l = i
			r = i + z[i] - 1
		}
	}
	return z
}

func FindPattern(pattern, text string) int {
	combined := pattern + "$" + text
	z := ZFunction(combined)
	count := 0
	pLen := len(pattern)

	for _, val := range z {
		if val == pLen {
			count++
		}
	}
	return count
}

func main() {
	text := "abracadabra"
	pattern := "abr"
	fmt.Printf("Occurrences: %d\n", FindPattern(pattern, text))
}
