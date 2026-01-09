package main

import "fmt"

const INF = 99999

func FloydWarshall(graph [][]int) {
	V := len(graph)
	dist := make([][]int, V)
	for i := range graph {
		dist[i] = make([]int, V)
		copy(dist[i], graph[i])
	}

	for k := 0; k < V; k++ {
		for i := 0; i < V; i++ {
			for j := 0; j < V; j++ {
				if dist[i][k] != INF && dist[k][j] != INF && dist[i][k]+dist[k][j] < dist[i][j] {
					dist[i][j] = dist[i][k] + dist[k][j]
				}
			}
		}
	}

	PrintSolution(dist)
}

func PrintSolution(dist [][]int) {
	fmt.Println("The following matrix shows the shortest distances between every pair of vertices")
	for _, row := range dist {
		for _, val := range row {
			if val == INF {
				fmt.Print("INF     ")
			} else {
				fmt.Printf("%d     ", val)
			}
		}
		fmt.Println()
	}
}

func main() {
	/*
	        10
	   (0)------->(3)
	    |         /|\
	  5 |          |
	    |          | 1
	   \|/         |
	   (1)------->(2)
	        3
	*/
	graph := [][]int{
		{0, 5, INF, 10},
		{INF, 0, 3, INF},
		{INF, INF, 0, 1},
		{INF, INF, INF, 0},
	}

	FloydWarshall(graph)
}