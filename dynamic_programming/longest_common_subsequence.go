package main

import (
	"fmt"
	"math"
)

func LongestCommonSubsequence(x, y string) (int, string) {
	m := len(x)
	n := len(y)
	
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}
	
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if x[i-1] == y[j-1] {
				dp[i][j] = 1 + dp[i-1][j-1]
			} else {
				dp[i][j] = int(math.Max(float64(dp[i-1][j]), float64(dp[i][j-1])))
			}
		}
	}
	
	seq := ""
	i, j := m, n
	for i > 0 && j > 0 {
		if x[i-1] == y[j-1] {
			seq = string(x[i-1]) + seq
			i--
			j--
		} else if dp[i][j] == dp[i-1][j] {
			i--
		} else {
			j--
		}
	}
	
	return dp[m][n], seq
}

func main() {
	a := "AGGTAB"
	b := "GXTXAYB"
	length, subseq := LongestCommonSubsequence(a, b)
	fmt.Println("Length:", length)
	fmt.Println("Subsequence:", subseq)
}
