package main

import (
	"errors"
	"fmt"
)

type Stack struct {
	items []interface{}
	limit int
}

func NewStack(limit int) *Stack {
	return &Stack{
		items: make([]interface{}, 0),
		limit: limit,
	}
}

func (s *Stack) Push(data interface{}) error {
	if len(s.items) >= s.limit {
		return errors.New("Stack Overflow")
	}
	s.items = append(s.items, data)
	return nil
}

func (s *Stack) Pop() (interface{}, error) {
	if len(s.items) == 0 {
		return nil, errors.New("Stack Underflow")
	}
	lastIndex := len(s.items) - 1
	item := s.items[lastIndex]
	s.items = s.items[:lastIndex]
	return item, nil
}

func (s *Stack) Peek() (interface{}, error) {
	if len(s.items) == 0 {
		return nil, errors.New("Stack Underflow")
	}
	return s.items[len(s.items)-1], nil
}

func (s *Stack) IsEmpty() bool {
	return len(s.items) == 0
}

func (s *Stack) IsFull() bool {
	return len(s.items) == s.limit
}

func (s *Stack) Size() int {
	return len(s.items)
}

func main() {
	s := NewStack(5)
	s.Push(1)
	s.Push(2)
	s.Push(3)

	val, _ := s.Peek()
	fmt.Println("Top:", val)
	
	val, _ = s.Pop()
	fmt.Println("Popped:", val)
	
	fmt.Println("Size:", s.Size())
}
