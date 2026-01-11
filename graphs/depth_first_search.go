package main

import "fmt"

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

func (g *Graph) DFS(v int, visited map[int]bool) {
	visited[v] = true
	fmt.Printf("%d ", v)

	for _, next := range g.adj[v] {
		if !visited[next] {
			g.DFS(next, visited)
		}
	}
}

func main() {
	g := NewGraph()
	g.AddEdge(0, 1)
	g.AddEdge(0, 2)
	g.AddEdge(1, 2)
	g.AddEdge(2, 0)
	g.AddEdge(2, 3)
	g.AddEdge(3, 3)

	fmt.Println("Following is Depth First Traversal (starting from vertex 2)")
	visited := make(map[int]bool)
	g.DFS(2, visited)
	fmt.Println()
}