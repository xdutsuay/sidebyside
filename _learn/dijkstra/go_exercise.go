package main

// Go imports omitted

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
			return ____________
		}

		for _, edge := range g.adj[u] {
			if !visited[edge.to] {
				heap.Push(&pq, &Item{vertex: edge.to, cost: ____________ + edge.weight})
			}
		}
	}
	return -1
}