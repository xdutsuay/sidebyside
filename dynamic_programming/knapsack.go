package main

import (
	"fmt"
	"math"
)

type Solution struct {
	MaxValue      int
	SelectedItems []int
}

func Knapsack(W int, wt []int, val []int) Solution {
	n := len(wt)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, W+1)
	}

	for i := 1; i <= n; i++ {
		for w := 1; w <= W; w++ {
			if wt[i-1] <= w {
				take := val[i-1] + dp[i-1][w-wt[i-1]]
				skip := dp[i-1][w]
				dp[i][w] = int(math.Max(float64(take), float64(skip)))
			} else {
				dp[i][w] = dp[i-1][w]
			}
		}
	}

	selectedItems := []int{}
	tempW := W
	for i := n; i > 0; i-- {
		if dp[i][tempW] != dp[i-1][tempW] {
			selectedItems = append(selectedItems, i)
			tempW -= wt[i-1]
		}
	}

	return Solution{MaxValue: dp[n][W], SelectedItems: selectedItems}
}

func main() {
	val := []int{3, 2, 4, 4}
	wt := []int{4, 3, 2, 3}
	W := 6

	sol := Knapsack(W, wt, val)
	fmt.Println("Optimal Value:", sol.MaxValue)
	fmt.Println("Selected Items:", sol.SelectedItems)
}
