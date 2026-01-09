package main

import "fmt"

type Graph struct {
	adj map[string][]string
}

func (g *Graph) DFS(start string) []string {
	explored := make(map[string]bool)
	stack := []string{start}
	explored[start] = true
	var result []string

	for len(stack) > 0 {
		// Pop logic
		index := len(stack) - 1
		v := stack[index]
		stack = stack[:index]

		result = append(result, v)

		neighbors := g.adj[v]
		for i := len(neighbors) - 1; i >= 0; i-- {
			neighbor := neighbors[i]
			if !____________[neighbor] {
				stack = append(stack, ____________)
				explored[neighbor] = true
			}
		}
	}
	return result
}