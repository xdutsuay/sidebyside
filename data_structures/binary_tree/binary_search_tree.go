package main

import "fmt"

type Node struct {
	Value int
	Left  *Node
	Right *Node
}

type BinarySearchTree struct {
	Root *Node
}

func (bst *BinarySearchTree) Insert(value int) {
	if bst.Root == nil {
		bst.Root = &Node{Value: value}
	} else {
		bst.insertNode(bst.Root, value)
	}
}

func (bst *BinarySearchTree) insertNode(node *Node, value int) {
	if value < node.Value {
		if node.Left == nil {
			node.Left = &Node{Value: value}
		} else {
			bst.insertNode(node.Left, value)
		}
	} else if value > node.Value {
		if node.Right == nil {
			node.Right = &Node{Value: value}
		} else {
			bst.insertNode(node.Right, value)
		}
	}
}

func (bst *BinarySearchTree) Search(value int) bool {
	return bst.searchNode(bst.Root, value)
}

func (bst *BinarySearchTree) searchNode(node *Node, value int) bool {
	if node == nil {
		return false
	}
	if value < node.Value {
		return bst.searchNode(node.Left, value)
	} else if value > node.Value {
		return bst.searchNode(node.Right, value)
	} else {
		return true
	}
}

func (bst *BinarySearchTree) InOrder() {
	bst.inOrderNode(bst.Root)
	fmt.Println()
}

func (bst *BinarySearchTree) inOrderNode(node *Node) {
	if node != nil {
		bst.inOrderNode(node.Left)
		fmt.Printf("%d ", node.Value)
		bst.inOrderNode(node.Right)
	}
}

func main() {
	bst := &BinarySearchTree{}
	bst.Insert(50)
	bst.Insert(30)
	bst.Insert(20)
	bst.Insert(40)
	bst.Insert(70)
	
	bst.InOrder()
	fmt.Println("Search 40:", bst.Search(40))
}
