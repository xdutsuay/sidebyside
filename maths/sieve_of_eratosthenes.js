/**
 * Sieve of Eratosthenes
 */

function primeSieve(num) {
    if (num <= 0) return [];

    const sieve = Array(num + 1).fill(true);
    const primes = [];

    for (let p = 2; p * p <= num; p++) {
        if (sieve[p] === true) {
            for (let i = p * p; i <= num; i += p) {
                sieve[i] = false;
            }
        }
    }

    for (let p = 2; p <= num; p++) {
        if (sieve[p]) {
            primes.push(p);
        }
    }
    return primes;
}

const n = 50;
console.log(`Primes up to ${n}:`, primeSieve(n));
