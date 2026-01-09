package main

import "math"

func Knapsack(W int, wt []int, val []int) int {
	n := len(wt)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, W+1)
	}

	for i := 1; i <= n; i++ {
		for w := 1; w <= W; w++ {
			if wt[i-1] <= w {
				take := ____________ + dp[i-1][w-____________]
				skip := dp[i-1][w]
				dp[i][w] = int(math.Max(float64(take), float64(skip)))
			} else {
				dp[i][w] = ____________
			}
		}
	}
	return dp[n][W]
}
