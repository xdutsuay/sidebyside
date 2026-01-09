package main

import (
	"fmt"
	"math"
)

type Edge struct {
	src, dest, weight int
}

type Graph struct {
	V, E  int
	edges []Edge
}

func NewGraph(V, E int) *Graph {
	return &Graph{
		V:     V,
		E:     E,
		edges: make([]Edge, 0, E),
	}
}

func (g *Graph) AddEdge(src, dest, weight int) {
	g.edges = append(g.edges, Edge{src, dest, weight})
}

func BellmanFord(graph *Graph, src int) {
	V := graph.V
	E := len(graph.edges)
	dist := make([]int, V)

	for i := range dist {
		dist[i] = math.MaxInt32
	}
	dist[src] = 0

	// Step 2: Relax all edges |V| - 1 times
	for i := 1; i < V; i++ {
		for j := 0; j < E; j++ {
			u := graph.edges[j].src
			v := graph.edges[j].dest
			weight := graph.edges[j].weight
			if dist[u] != math.MaxInt32 && dist[u]+weight < dist[v] {
				dist[v] = dist[u] + weight
			}
		}
	}

	// Step 3: Check for negative-weight cycles
	for j := 0; j < E; j++ {
		u := graph.edges[j].src
		v := graph.edges[j].dest
		weight := graph.edges[j].weight
		if dist[u] != math.MaxInt32 && dist[u]+weight < dist[v] {
			fmt.Println("Graph contains negative weight cycle")
			return
		}
	}

	PrintArr(dist)
}

func PrintArr(dist []int) {
	fmt.Println("Vertex   Distance from Source")
	for i := 0; i < len(dist); i++ {
		if dist[i] == math.MaxInt32 {
			fmt.Printf("%d\t\tINF\n", i)
		} else {
			fmt.Printf("%d\t\t%d\n", i, dist[i])
		}
	}
}

func main() {
	V := 5
	E := 8
	graph := NewGraph(V, E)

	// [(0, 1, -1), (0, 2, 4), (1, 2, 3), (1, 3, 2), (1, 4, 2), (3, 2, 5), (3, 1, 1), (4, 3, -3)]
	graph.AddEdge(0, 1, -1)
	graph.AddEdge(0, 2, 4)
	graph.AddEdge(1, 2, 3)
	graph.AddEdge(1, 3, 2)
	graph.AddEdge(1, 4, 2)
	graph.AddEdge(3, 2, 5)
	graph.AddEdge(3, 1, 1)
	graph.AddEdge(4, 3, -3)

	BellmanFord(graph, 0)
}