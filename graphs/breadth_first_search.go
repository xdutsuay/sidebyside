package main

import (
	"fmt"
	"sort"
)

// Graph struct
type Graph struct {
	vertices map[int][]int
}

// NewGraph creates a new Graph
func NewGraph() *Graph {
	return &Graph{
		vertices: make(map[int][]int),
	}
}

// AddEdge adds an edge to the graph
func (g *Graph) AddEdge(fromVertex, toVertex int) {
	g.vertices[fromVertex] = append(g.vertices[fromVertex], toVertex)
	if _, exists := g.vertices[toVertex]; !exists {
		g.vertices[toVertex] = []int{}
	}
}

// PrintGraph prints the adjacency list
func (g *Graph) PrintGraph() {
	for v, edges := range g.vertices {
		fmt.Printf("%d : %v\n", v, edges)
	}
}

// BFS performs Breadth First Search
func (g *Graph) BFS(startVertex int) []int {
	visited := make(map[int]bool)
	queue := []int{}
	result := []int{}

	visited[startVertex] = true
	queue = append(queue, startVertex)

	for len(queue) > 0 {
		vertex := queue[0]
		queue = queue[1:] // Dequeue
		
		// Typically result for BFS isn't just visited set but order or reachable nodes
		// Here we match Python's return which is just the set of visited nodes
		result = append(result, vertex)

		for _, neighbor := range g.vertices[vertex] {
			if !visited[neighbor] {
				visited[neighbor] = true
				queue = append(queue, neighbor)
			}
		}
	}
	return result
}

func main() {
	g := NewGraph()
	g.AddEdge(0, 1)
	g.AddEdge(0, 2)
	g.AddEdge(1, 2)
	g.AddEdge(2, 0)
	g.AddEdge(2, 3)
	g.AddEdge(3, 3)

	g.PrintGraph()

	res := g.BFS(2)
	sort.Ints(res)
	fmt.Println("BFS Result (starting from 2):", res)
}