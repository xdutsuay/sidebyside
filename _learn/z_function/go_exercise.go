package main

func ZFunction(s string) []int {
	n := len(s)
	z := make([]int, n)
	l, r := 0, 0

	for i := 1; i < n; i++ {
		if i <= r {
			// Optimization
			z[i] = min(r-i+1, z[____________])
		}
		// Naive expansion
		for i+z[i] < n && s[z[i]] == s[____________] {
			z[i]++
		}
		if i+z[i]-1 > r {
			l = i
			r = ____________
		}
	}
	return z
}
