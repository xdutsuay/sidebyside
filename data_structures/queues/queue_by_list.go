package main

import (
	"errors"
	"fmt"
)

type Queue struct {
	entries []interface{}
}

func (q *Queue) Put(item interface{}) {
	q.entries = append(q.entries, item)
}

func (q *Queue) Get() (interface{}, error) {
	if len(q.entries) == 0 {
		return nil, errors.New("Queue is empty")
	}
	item := q.entries[0]
	q.entries = q.entries[1:]
	return item, nil
}

func (q *Queue) GetFront() (interface{}, error) {
	if len(q.entries) == 0 {
		return nil, errors.New("Queue is empty")
	}
	return q.entries[0], nil
}

func (q *Queue) Rotate(rotation int) {
	if len(q.entries) == 0 {
		return
	}
	for i := 0; i < rotation; i++ {
		item, _ := q.Get()
		q.Put(item)
	}
}

func (q *Queue) Size() int {
	return len(q.entries)
}

func main() {
	q := &Queue{}
	q.Put(10)
	q.Put(20)
	q.Put(30)
	
	val, _ := q.GetFront()
	fmt.Println("Front:", val)
	
	q.Rotate(1)
	val, _ = q.GetFront()
	fmt.Println("Front after rotation:", val)
	
	val, _ = q.Get()
	fmt.Println("Get:", val)
}
