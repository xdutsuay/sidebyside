package main

import (
	"fmt"
)

type Graph struct {
	vertices map[int][]int
}

func (g *Graph) BFS(startVertex int) []int {
	visited := make(map[int]bool)
	queue := []int{}
	result := []int{}

	visited[startVertex] = true
	queue = append(queue, startVertex)

	for len(queue) > 0 {
		// Dequeue: take first element
		vertex := queue[0]
		queue = queue[1:]

		result = append(result, vertex)

		for _, neighbor := range g.vertices[vertex] {
			if !____________[neighbor] { // Check if visited
				visited[neighbor] = true
				queue = append(queue, ____________) // Enqueue
			}
		}
	}
	return result
}

func main() {
	g := Graph{vertices: make(map[int][]int)}
	// Setup graph...
	fmt.Println(g.BFS(0))
}