package main

import (
	"fmt"
	"math"
)

const V = 5

func minKey(key []int, mstSet []bool) int {
	min := math.MaxInt32
	minIndex := -1

	for v := 0; v < V; v++ {
		if !mstSet[v] && key[v] < min {
			min = key[v]
			minIndex = v
		}
	}
	return minIndex
}

func printMST(parent []int, graph [][]int) {
	fmt.Println("Edge \tWeight")
	for i := 1; i < V; i++ {
		fmt.Printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]])
	}
}

func primMST(graph [][]int) {
	parent := make([]int, V)
	key := make([]int, V)
	mstSet := make([]bool, V)

	for i := 0; i < V; i++ {
		key[i] = math.MaxInt32
		mstSet[i] = false
	}

	key[0] = 0
	parent[0] = -1

	for count := 0; count < V-1; count++ {
		u := minKey(key, mstSet)
		mstSet[u] = true

		for v := 0; v < V; v++ {
			if graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v] {
				parent[v] = u
				key[v] = graph[u][v]
			}
		}
	}

	printMST(parent, graph)
}

func main() {
	/* Let us create the following graph
	    2    3
	(0)--(1)--(2)
	 |   / \   |
	6| 8/   \5 |7
	 | /     \ |
	(3)-------(4)
	      9          */
	graph := [][]int{
		{0, 2, 0, 6, 0},
		{2, 0, 3, 8, 5},
		{0, 3, 0, 0, 7},
		{6, 8, 0, 0, 9},
		{0, 5, 7, 9, 0},
	}

	primMST(graph)
}