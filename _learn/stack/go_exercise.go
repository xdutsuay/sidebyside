package main

import "errors"

type Stack struct {
	items []interface{}
	limit int
}

func (s *Stack) Push(data interface{}) error {
	if len(s.items) >= s.limit {
		return errors.New("Stack Overflow")
	}
	s.items = append(s.items, ____________)
	return nil
}

func (s *Stack) Pop() (interface{}, error) {
	if len(s.items) == 0 {
		return nil, errors.New("Stack Underflow")
	}
	lastIndex := len(s.items) - 1
	item := s.items[lastIndex]
	s.items = s.items[:____________]
	return item, nil
}
