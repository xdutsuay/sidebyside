pub fn prime_sieve(num: usize) -> Vec<usize> {
    // ... setup 
    let mut sieve = vec![true; num + 1];
    // ...

    for p in 2..=limit {
        if sieve[p] {
            let mut i = ____________;
            while i <= num {
                sieve[i] = false;
                i += ____________;
            }
        }
    }
    // ... collect primes
    primes
}
