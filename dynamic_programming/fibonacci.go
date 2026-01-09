package main

import "fmt"

type Fibonacci struct {
	sequence []int
}

func NewFibonacci() *Fibonacci {
	return &Fibonacci{
		sequence: []int{0, 1},
	}
}

func (f *Fibonacci) Get(index int) []int {
	if index <= 0 {
		return []int{}
	}
	
	for len(f.sequence) < index {
		nextVal := f.sequence[len(f.sequence)-1] + f.sequence[len(f.sequence)-2]
		f.sequence = append(f.sequence, nextVal)
	}
	
	result := make([]int, index)
	copy(result, f.sequence[:index])
	return result
}

func main() {
	fib := NewFibonacci()
	fmt.Println(fib.Get(10))
}
