#include <cmath>
#include <iostream>

int greatestCommonDivisorRecursive(int a, int b) {
  if (a == 0)
    return std::abs(b);
  return greatestCommonDivisorRecursive(b % a, a);
}

int greatestCommonDivisorIterative(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return std::abs(a);
}

int main() {
  int a = 24, b = 40;
  std::cout << "GCD Recursive (" << a << ", " << b
            << ") = " << greatestCommonDivisorRecursive(a, b) << std::endl;
  std::cout << "GCD Iterative (" << a << ", " << b
            << ") = " << greatestCommonDivisorIterative(a, b) << std::endl;
  return 0;
}
