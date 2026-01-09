package main

import (
	"fmt"
	"math"
	"sort"
)

type Node struct {
	f, g, x, y int
}

var directions = [][2]int{
	{-1, 0}, {0, -1}, {1, 0}, {0, 1},
}

func search(grid [][]int, init []int, goal []int, cost int, heuristic [][]int) ([][]int, [][]int) {
	rows := len(grid)
	cols := len(grid[0])

	closed := make([][]int, rows)
	action := make([][]int, rows)
	for i := range closed {
		closed[i] = make([]int, cols)
		action[i] = make([]int, cols)
	}

	closed[init[0]][init[1]] = 1

	x, y := init[0], init[1]
	g := 0
	f := g + heuristic[x][y]

	open := []Node{{f, g, x, y}}

	found := false
	resign := false

	for !found && !resign {
		if len(open) == 0 {
			resign = true
			fmt.Println("Algorithm is unable to find solution")
			return nil, nil
		} else {
			// Sort descending by f
			sort.Slice(open, func(i, j int) bool {
				return open[i].f > open[j].f
			})
			
			next := open[len(open)-1]
			open = open[:len(open)-1]

			x, y = next.x, next.y
			g = next.g

			if x == goal[0] && y == goal[1] {
				found = true
			} else {
				for i, d := range directions {
					x2 := x + d[0]
					y2 := y + d[1]

					if x2 >= 0 && x2 < rows && y2 >= 0 && y2 < cols && 
						closed[x2][y2] == 0 && grid[x2][y2] == 0 {
						
						g2 := g + cost
						f2 := g2 + heuristic[x2][y2]
						open = append(open, Node{f2, g2, x2, y2})
						closed[x2][y2] = 1
						action[x2][y2] = i
					}
				}
			}
		}
	}

	path := [][]int{}
	if found {
		x, y = goal[0], goal[1]
		invpath := [][]int{{x, y}}

		for x != init[0] || y != init[1] {
			x2 := x - directions[action[x][y]][0]
			y2 := y - directions[action[x][y]][1]
			x, y = x2, y2
			invpath = append(invpath, []int{x, y})
		}
		
		for i := len(invpath) - 1; i >= 0; i-- {
			path = append(path, invpath[i])
		}
	}
	return path, action
}

func main() {
	grid := [][]int{
		{0, 1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 0},
		{0, 0, 0, 0, 1, 0},
	}
	init := []int{0, 0}
	goal := []int{len(grid) - 1, len(grid[0]) - 1}
	cost := 1
	
	heuristic := make([][]int, len(grid))
	for i := range heuristic {
		heuristic[i] = make([]int, len(grid[0]))
		for j := range heuristic[i] {
			heuristic[i][j] = int(math.Abs(float64(i - goal[0])) + math.Abs(float64(j - goal[1])))
			if grid[i][j] == 1 { heuristic[i][j] = 99 }
		}
	}

	path, _ := search(grid, init, goal, cost, heuristic)
	fmt.Println("Path:", path)
}