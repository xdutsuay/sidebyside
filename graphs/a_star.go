package main

import (
	"container/heap"
	"fmt"
	"math"
)

type Point struct {
	x, y int
}

type Node struct {
	pt     Point
	g, h, f int
	parent *Node
	index  int
}

type PriorityQueue []*Node

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].f < pq[j].f
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*Node)
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

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func heuristic(a, b Point) int {
	return abs(a.x-b.x) + abs(a.y-b.y)
}

func AStar(grid [][]int, start, end Point) []*Point {
	rows := len(grid)
	cols := len(grid[0])

	openList := make(PriorityQueue, 0)
	heap.Init(&openList)

	startNode := &Node{pt: start, g: 0, h: 0, f: 0}
	heap.Push(&openList, startNode)

	closedList := make(map[Point]bool)
	
	// Keep track of visited nodes to avoid re-adding
	nodeMap := make(map[Point]*Node)
	nodeMap[start] = startNode

	for openList.Len() > 0 {
		current := heap.Pop(&openList).(*Node)

		if current.pt == end {
			var path []*Point
			for curr := current; curr != nil; curr = curr.parent {
				path = append(path, &curr.pt)
			}
			// Reverse
			for i, j := 0, len(path)-1; i < j; i, j = i+1, j-1 {
				path[i], path[j] = path[j], path[i]
			}
			return path
		}

		closedList[current.pt] = true

		moves := []Point{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
		for _, move := range moves {
			neighborPt := Point{current.pt.x + move.x, current.pt.y + move.y}

			if neighborPt.x < 0 || neighborPt.x >= rows || neighborPt.y < 0 || neighborPt.y >= cols {
				continue
			}

			if grid[neighborPt.x][neighborPt.y] == 0 || closedList[neighborPt] {
				continue
			}

			gScore := current.g + 1
			hScore := heuristic(neighborPt, end)
			fScore := gScore + hScore

			if existingNode, exists := nodeMap[neighborPt]; exists {
				if gScore < existingNode.g {
					existingNode.g = gScore
					existingNode.f = fScore
					existingNode.parent = current
					heap.Fix(&openList, existingNode.index)
				}
			} else {
				neighborNode := &Node{
					pt:     neighborPt,
					g:      gScore,
					h:      hScore,
					f:      fScore,
					parent: current,
				}
				nodeMap[neighborPt] = neighborNode
				heap.Push(&openList, neighborNode)
			}
		}
	}
	return nil
}

func main() {
	// 1-Walkable, 0-Blocked
	grid := [][]int{
		{1, 0, 1, 1, 1},
		{1, 1, 1, 0, 1},
		{1, 1, 1, 0, 1},
		{0, 0, 1, 0, 1},
		{1, 1, 1, 0, 1},
	}

	path := AStar(grid, Point{0, 0}, Point{4, 4})
	if path != nil {
		fmt.Println("Path found:")
		for _, pt := range path {
			fmt.Printf("(%d, %d) ", pt.x, pt.y)
		}
		fmt.Println()
	} else {
		fmt.Println("No path found")
	}
}