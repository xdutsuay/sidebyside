package main

import "math"

func LongestCommonSubsequence(x, y string) int {
	m := len(x)
	n := len(y)
	
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}
	
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if x[i-1] == y[j-1] {
				dp[i][j] = 1 + dp[i-1][____________]
			} else {
				dp[i][j] = int(math.Max(float64(dp[____________][j]), float64(dp[i][j-1])))
			}
		}
	}
	return dp[m][n]
}
