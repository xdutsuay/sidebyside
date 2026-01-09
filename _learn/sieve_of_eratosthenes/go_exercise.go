package main

// ...

func PrimeSieve(num int) []int {
	// ... setup
	sieve := make([]bool, num+1)
	// ...

	for p := 2; p <= limit; p++ {
		if sieve[p] {
			// Mark multiples
			for i := ____________; i <= num; i += ____________ {
				sieve[i] = false
			}
		}
	}
	// ... collect
	return primes
}
