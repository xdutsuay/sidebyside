package main

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
			// Mismatch! Consult failure table
			j = failure[____________]
		} else {
			i++
		}
	}
	return -1
}
