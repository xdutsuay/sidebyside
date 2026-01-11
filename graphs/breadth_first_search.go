package main

import (
	"fmt"
)

type Graph struct {
	adj map[int][]int
}

func NewGraph() *Graph {
	return &Graph{
		adj: make(map[int][]int),
	}
}

func (g *Graph) AddEdge(v, w int) {
	g.adj[v] = append(g.adj[v], w)
}

func (g *Graph) BFS(s int) {
	visited := make(map[int]bool)
	queue := []int{s}

	visited[s] = true

	for len(queue) > 0 {
		u := queue[0]
		queue = queue[1:]
		fmt.Printf("%d ", u)

		for _, v := range g.adj[u] {
			if !visited[v] {
				visited[v] = true
				queue = append(queue, v)
			}
		}
	}
	fmt.Println()
}

func main() {
	g := NewGraph()
	g.AddEdge(0, 1)
	g.AddEdge(0, 2)
	g.AddEdge(1, 2)
	g.AddEdge(2, 0)
	g.AddEdge(2, 3)
	g.AddEdge(3, 3)

	fmt.Println("Following is Breadth First Traversal (starting from vertex 2)")
	g.BFS(2)
}