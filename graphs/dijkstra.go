package main

import (
	"container/heap"
	"fmt"
	"math"
)

type Edge struct {
	to, weight int
}

type Graph struct {
	adj [][]Edge
}

func NewGraph(V int) *Graph {
	return &Graph{
		adj: make([][]Edge, V),
	}
}

func (g *Graph) AddEdge(u, v, w int) {
	g.adj[u] = append(g.adj[u], Edge{v, w})
	g.adj[v] = append(g.adj[v], Edge{u, w})
}

// Item for Priority Queue
type Item struct {
	vertex, priority int
	index            int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].priority < pq[j].priority
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
	item.index = -1
	*pq = old[0 : n-1]
	return item
}

func (g *Graph) Dijkstra(src int) []int {
	V := len(g.adj)
	dist := make([]int, V)
	for i := range dist {
		dist[i] = math.MaxInt32
	}
	dist[src] = 0

	pq := make(PriorityQueue, 0)
	heap.Init(&pq)
	heap.Push(&pq, &Item{vertex: src, priority: 0})

	for pq.Len() > 0 {
		u := heap.Pop(&pq).(*Item).vertex

		for _, e := range g.adj[u] {
			v := e.to
			weight := e.weight
			if dist[u]+weight < dist[v] {
				dist[v] = dist[u] + weight
				heap.Push(&pq, &Item{vertex: v, priority: dist[v]})
			}
		}
	}
	return dist
}

func main() {
	g := NewGraph(9)
	g.AddEdge(0, 1, 4)
	g.AddEdge(0, 7, 8)
	g.AddEdge(1, 2, 8)
	g.AddEdge(1, 7, 11)
	g.AddEdge(2, 3, 7)
	g.AddEdge(2, 8, 2)
	g.AddEdge(2, 5, 4)
	g.AddEdge(3, 4, 9)
	g.AddEdge(3, 5, 14)
	g.AddEdge(4, 5, 10)
	g.AddEdge(5, 6, 2)
	g.AddEdge(6, 7, 1)
	g.AddEdge(6, 8, 6)
	g.AddEdge(7, 8, 7)

	dist := g.Dijkstra(0)
	fmt.Println("Vertex Distance from Source")
	for i := 0; i < 9; i++ {
		fmt.Printf("%d \t\t %d\n", i, dist[i])
	}
}