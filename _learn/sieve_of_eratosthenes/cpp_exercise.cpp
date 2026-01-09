#include <cmath>
#include <iostream>
#include <vector>

std::vector<int> primeSieve(int num) {
  if (num <= 0)
    return {};

  std::vector<bool> sieve(num + 1, true);
  std::vector<int> primes;

  for (int p = 2; p * p <= num; p++) {
    // If sieve[p] is not changed, then it is a prime
    if (sieve[p] == true) {
      // Update all multiples of p starting from p*p
      for (int i = ____________; i <= num; i += ____________)
        sieve[i] = false;
    }
  }

  // Collect primes
  for (int p = 2; p <= num; p++)
    if (sieve[p])
      primes.push_back(p);

  return primes;
}
