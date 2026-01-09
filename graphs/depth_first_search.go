package main

import (
	"fmt"
	"sort"
)

type Graph struct {
	adj map[string][]string
}

func NewGraph() *Graph {
	return &Graph{adj: make(map[string][]string)}
}

func (g *Graph) AddEdge(u, v string) {
	g.adj[u] = append(g.adj[u], v)
}

func (g *Graph) DFS(start string) []string {
	explored := make(map[string]bool)
	stack := []string{start}
	explored[start] = true
	var result []string

	for len(stack) > 0 {
		// Pop
		index := len(stack) - 1
		v := stack[index]
		stack = stack[:index]

		result = append(result, v)

		neighbors := g.adj[v]
		// Reverse iteration
		for i := len(neighbors) - 1; i >= 0; i-- {
			neighbor := neighbors[i]
			if !explored[neighbor] {
				stack = append(stack, neighbor)
				explored[neighbor] = true // Mark here to match python set logic effectively
			}
		}
	}
	return result
}

func main() {
	g := NewGraph()
	g.AddEdge("A", "B")
	g.AddEdge("A", "C")
	// ... add other edges
	
	fmt.Println(g.DFS("A"))
}