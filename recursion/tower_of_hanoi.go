package main

import "fmt"

func moveDisk(fp, tp string) {
	fmt.Printf("moving disk from %s to %s\n", fp, tp)
}

func moveTower(height int, fromPole, toPole, withPole string) {
	if height >= 1 {
		moveTower(height-1, fromPole, withPole, toPole)
		moveDisk(fromPole, toPole)
		moveTower(height-1, withPole, toPole, fromPole)
	}
}

func main() {
	height := 3
	moveTower(height, "A", "B", "C")
}
