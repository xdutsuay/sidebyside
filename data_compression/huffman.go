package main

import (
	"container/heap"
	"fmt"
)

type Node struct {
	char        rune
	freq        int
	left, right *Node
}

type PriorityQueue []*Node

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].freq < pq[j].freq
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(*Node))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

func buildTree(text string) *Node {
	freqMap := make(map[rune]int)
	for _, c := range text {
		freqMap[c]++
	}

	pq := make(PriorityQueue, 0)
	heap.Init(&pq)

	for char, freq := range freqMap {
		heap.Push(&pq, &Node{char: char, freq: freq})
	}

	for pq.Len() > 1 {
		left := heap.Pop(&pq).(*Node)
		right := heap.Pop(&pq).(*Node)

		parent := &Node{
			char:  '$',
			freq:  left.freq + right.freq,
			left:  left,
			right: right,
		}

		heap.Push(&pq, parent)
	}

	if pq.Len() > 0 {
		return heap.Pop(&pq).(*Node)
	}
	return nil
}

func printCodes(root *Node, str string) {
	if root == nil {
		return
	}

	if root.char != '$' {
		fmt.Printf("%c: %s\n", root.char, str)
	}

	printCodes(root.left, str+"0")
	printCodes(root.right, str+"1")
}

func main() {
	text := "this is an example for huffman encoding"
	root := buildTree(text)
	printCodes(root, "")
}
