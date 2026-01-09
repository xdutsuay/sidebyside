package main

type Node struct {
	Data interface{}
	Next *Node
}

type LinkedList struct {
	Head *Node
}

func (ll *LinkedList) InsertHead(data interface{}) {
	newNode := &Node{Data: data}
	newNode.Next = ____________
	ll.Head = ____________
}

func (ll *LinkedList) InsertTail(data interface{}) {
	newNode := &Node{Data: data}
	if ll.Head == nil {
		ll.Head = newNode
	} else {
		current := ll.Head
		while current.Next != nil { // oops, go uses for
		for current.Next != nil {
			current = current.Next
		}
		current.Next = ____________
	}
}

func (ll *LinkedList) Reverse() {
	var prev *Node = nil
	current := ll.Head
	for current != nil {
		next := current.Next
		current.Next = ____________
		prev = ____________
		current = ____________
	}
	ll.Head = prev
}
