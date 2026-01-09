package main

import (
	"container/list"
	"fmt"
	"math/big"
)

type edge struct {
	to   string
	cost int
}

func bidirectionalDijkstra(source, destination string, graphForward, graphBackward map[string][]edge) (int64, bool) {
	queueForward := list.New()
	queueBackward := list.New()

	fwdDistance := make(map[string]int64)
	bwdDistance := make(map[string]int64)
	parentFwd := make(map[string]string)
	parentBwd := make(map[string]string)

	visitedForward := make(map[string]bool)
	visitedBackward := make(map[string]bool)

	fwdCosts := make(map[string]int64)
	bwdCosts := make(map[string]int64)

	var updateFwd, updateBwd func(edge)
	updateFwd = func(e edge) {
		if e.to != source && !visitedForward[e.to] {
			newDist := fwdDistance[source] + int64(e.cost)
			if newDist < fwdCosts[e.to] {
				fwdCosts[e.to] = newDist
				queueForward.PushBack(edge{e.to, newDist})
				parentFwd[e.to] = source
				visitedForward[e.to] = true
			}
		}
	}

	var updateBwd func(edge)
	updateBwd = func(e edge) {
		if e.to != destination && !visitedBackward[e.to] {
			newDist := bwdDistance[destination] + int64(e.cost)
			if newDist < bwdCosts[e.to] {
				bwdCosts[e.to] = newDist
				queueBackward.PushFront(edge{e.to, newDist})
				parentBwd[e.to] = destination
				visitedBackward[e.to] = true
			}
		}
	}

	fwdDistance[source] = 0
	fwdCosts[source] = 0
	queueForward.PushBack(edge{destination, 0})

	bwdDistance[destination] = 0
	bwdCosts[destination] = 0
	queueBackward.PushFront(edge{source, 0})

	for queueForward.Len() > 0 && queueBackward.Len() > 0 {
		var node *list.Element

		if queueForward.Len() >= queueBackward.Len() {
			node = queueForward.Front()
		} else {
			node = queueBackward.Back()
		}

		switch {
		case node == queueForward.Front():
			fwdElement := (*node).Value.(edge)
			updateFwd(fwdElement)

		case node == queueBackward.Back():
			bwdElement := (*node).Value.(edge)
			updateBwd(bwdElement)
		}

		queueForward.Remove(node)
		queueBackward.Remove(node)

		if fwdElement.to == destination {
			break
		}
		if bwdElement.to == source {
			break
		}
	}

	if queueForward.Len() > 0 || queueBackward.Len() > 0 {
		return -1, false
	}

	minCost := big.NewInt(0)
	for node := range fwdDistance {
		newDist := fwdDistance[node] + bwdDistance[node]
		if newDist < minCost.Int64() {
			minCost = big.NewInt(newDist)
		}
	}

	return int64(minCost), true
}

func main() {
	graphForward := map[string][]edge{
		"B": {{"C", 1}},
		"C": {{"D", 1}},
		"D": {{"F", 1}},
		"E": {{"B", 1}, {"G", 2}},
		"F": {},
		"G": {{"F", 1}},
	}

	graphBackward := map[string][]edge{
		"B": {{"E", 1}},
		"C": {{"B", 1}},
		"D": {{"C", 1}},
		"F": {{"D", 1}, {"G", 1}},
		"E": {{"None", big.NewInt(0)}},
		"G": {{"E", 2}},
	}

	var source, destination string
	fmt.Print("Enter the source: ")
	fmt.Scanln(&source)
	fmt.Print("Enter the destination: ")
	fmt.Scanln(&destination)

	dist, reachable := bidirectionalDijkstra(source, destination, graphForward, graphBackward)

	if !reachable {
		fmt.Println(-1)
	} else {
		fmt.Printf("The shortest path from %s to %s is %d\n", source, destination, dist)
	}
}