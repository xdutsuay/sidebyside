/**
 * Sieve of Eratosthenes - FILL IN THE BLANKS
 */

function primeSieve(num) {
    if (num <= 0) return [];

    const sieve = Array(num + 1).fill(true);
    const primes = [];

    for (let p = 2; p * p <= num; p++) {
        if (sieve[p] === true) {
            // Mark multiples starting from p*p
            for (let i = ____________; i <= num; i += ____________) {
                sieve[i] = false;
            }
        }
    }

    // Collect primes
    for (let p = 2; p <= num; p++) {
        if (sieve[p]) {
            primes.push(p);
        }
    }
    return primes;
}
