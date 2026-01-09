#include <cmath>
#include <iostream>
#include <vector>

std::vector<int> primeSieve(int num) {
  if (num <= 0)
    return {};

  std::vector<bool> sieve(num + 1, true);
  std::vector<int> primes;
  int start = 2;
  int end = std::sqrt(num);

  for (int p = 2; p * p <= num; p++) {
    // If sieve[p] is not changed, then it is a prime
    if (sieve[p] == true) {
      // Update all multiples of p
      for (int i = p * p; i <= num; i += p)
        sieve[i] = false;
    }
  }

  // Print all prime numbers
  for (int p = 2; p <= num; p++)
    if (sieve[p])
      primes.push_back(p);

  return primes;
}

int main() {
  int n = 50;
  std::vector<int> primes = primeSieve(n);
  std::cout << "Primes up to " << n << ": ";
  for (int p : primes)
    std::cout << p << " ";
  std::cout << std::endl;
  return 0;
}
