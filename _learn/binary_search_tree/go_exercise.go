package main

// Go implementation omitted

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
			bst.insertNode(____________, value) // Recurse right
		}
	}
}
