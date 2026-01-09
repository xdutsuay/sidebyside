package main

import "fmt"

type Node struct {
	Data interface{}
	Next *Node
}

type LinkedList struct {
	Head *Node
	Size int
}

func (ll *LinkedList) InsertHead(data interface{}) {
	newNode := &Node{Data: data}
	newNode.Next = ll.Head
	ll.Head = newNode
	ll.Size++
}

func (ll *LinkedList) InsertTail(data interface{}) {
	newNode := &Node{Data: data}
	if ll.Head == nil {
		ll.Head = newNode
	} else {
		current := ll.Head
		for current.Next != nil {
			current = current.Next
		}
		current.Next = newNode
	}
	ll.Size++
}

func (ll *LinkedList) DeleteHead() interface{} {
	if ll.Head == nil {
		return nil
	}
	data := ll.Head.Data
	ll.Head = ll.Head.Next
	ll.Size--
	return data
}

func (ll *LinkedList) Reverse() {
	var prev *Node = nil
	current := ll.Head
	for current != nil {
		next := current.Next
		current.Next = prev
		prev = current
		current = next
	}
	ll.Head = prev
}

func (ll *LinkedList) PrintList() {
	current := ll.Head
	for current != nil {
		fmt.Printf("%v -> ", current.Data)
		current = current.Next
	}
	fmt.Println("nil")
}

func main() {
	ll := &LinkedList{}
	ll.InsertTail(1)
	ll.InsertTail(2)
	ll.InsertTail(3)
	ll.PrintList()
	
	ll.InsertHead(0)
	ll.PrintList()
	
	ll.Reverse()
	ll.PrintList()
	
	fmt.Println("Deleted:", ll.DeleteHead())
	ll.PrintList()
}
