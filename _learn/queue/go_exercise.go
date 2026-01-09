package main

import "errors"

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
	// Remove from front
	q.entries = q.entries[____________:]
	return item, nil
}

func (q *Queue) Rotate(rotation int) {
	if len(q.entries) == 0 {
		return
	}
	for i := 0; i < rotation; i++ {
		item, _ := q.Get()
		q.Put(____________)
	}
}
