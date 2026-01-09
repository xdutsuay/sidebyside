package main

type Fibonacci struct {
	sequence []int
}

func (f *Fibonacci) Get(index int) []int {
	for len(f.sequence) < index {
		// next = last + second to last
		nextVal := f.sequence[len(f.sequence)-1] + ____________
		f.sequence = append(f.sequence, nextVal)
	}
	
	result := make([]int, index)
	copy(result, f.sequence[:____________])
	return result
}
