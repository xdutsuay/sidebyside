package main

import (
	"fmt"
	"math"
)

func PrimeSieve(num int) []int {
	if num <= 0 {
		return []int{}
	}

	sieve := make([]bool, num+1)
	for i := range sieve {
		sieve[i] = true
	}
	var primes []int

	limit := int(math.Sqrt(float64(num)))

	for p := 2; p <= limit; p++ {
		if sieve[p] {
			for i := p * p; i <= num; i += p {
				sieve[i] = false
			}
		}
	}

	for p := 2; p <= num; p++ {
		if sieve[p] {
			primes = append(primes, p)
		}
	}
	return primes
}

func main() {
	n := 50
	fmt.Printf("Primes up to %d: %v\n", n, PrimeSieve(n))
}
