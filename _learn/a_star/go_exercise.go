package main

// Go code omitted

func search(grid [][]int, init []int, goal []int, cost int, heuristic [][]int) ([][]int, [][]int) {
	// ... setup ...
	open := []Node{{f, g, x, y}}

	for !found && !resign {
		if len(open) == 0 {
			resign = true;
		} else {
			sort.Slice(open, func(i, j int) bool {
				return open[i].f > open[j].f
			})
			
			next := open[len(open)-1]
			open = open[:len(open)-1]
            
            // ...

			if x == goal[0] && y == goal[1] {
				found = true;
			} else {
				for i, d := range directions {
					// ... check valid ...
					if /* valid */ {
						g2 := g + cost
						f2 := g2 + ____________ // Heuristic
						open = append(open, Node{f2, g2, x2, y2})
						closed[x2][y2] = 1
						action[x2][y2] = i
					}
				}
			}
		}
	}
	return path, action
}