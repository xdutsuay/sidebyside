pub fn prime_sieve(num: usize) -> Vec<usize> {
    if num == 0 {
        return vec![];
    }

    let mut sieve = vec![true; num + 1];
    let mut primes = Vec::new();

    let limit = (num as f64).sqrt() as usize;

    for p in 2..=limit {
        if sieve[p] {
            let mut i = p * p;
            while i <= num {
                sieve[i] = false;
                i += p;
            }
        }
    }

    for p in 2..=num {
        if sieve[p] {
            primes.push(p);
        }
    }
    primes
}

fn main() {
    let n = 50;
    println!("Primes up to {}: {:?}", n, prime_sieve(n));
}
