package main

import (
	"container/heap"
	"fmt"
)

// Item is something we manage in a priority queue.
type Item struct {
	vertex string
	cost   int
	index  int // The index of the item in the heap.
}

// PriorityQueue implements heap.Interface and holds Items.
type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	// We want Pop to give us the lowest cost, so we use < here.
	return pq[i].cost < pq[j].cost
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*Item)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	item.index = -1 // for safety
	*pq = old[0 : n-1]
	return item
}

type Edge struct {
	to     string
	weight int
}

type Graph struct {
	adj map[string][]Edge
}

func NewGraph() *Graph {
	return &Graph{adj: make(map[string][]Edge)}
}

func (g *Graph) AddEdge(u, v string, weight int) {
	g.adj[u] = append(g.adj[u], Edge{to: v, weight: weight})
}

func (g *Graph) Dijkstra(start, end string) int {
	pq := make(PriorityQueue, 0)
	heap.Init(&pq)
	
	visited := make(map[string]bool)

	heap.Push(&pq, &Item{vertex: start, cost: 0})

	for pq.Len() > 0 {
		item := heap.Pop(&pq).(*Item)
		u := item.vertex
		cost := item.cost

		if visited[u] {
			continue
		}
		visited[u] = true

		if u == end {
			return cost
		}

		for _, edge := range g.adj[u] {
			if !visited[edge.to] {
				heap.Push(&pq, &Item{vertex: edge.to, cost: cost + edge.weight})
			}
		}
	}
	return -1
}

func main() {
	g := NewGraph()
	g.AddEdge("A", "B", 2)
	g.AddEdge("A", "C", 5)
	// ... rest of edges
	g.AddEdge("E", "B", 4)
	g.AddEdge("B", "F", 1)
	g.AddEdge("F", "C", 3)

	fmt.Println(g.Dijkstra("E", "C"))
}