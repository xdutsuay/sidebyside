#include <cmath>
#include <iostream>

int greatestCommonDivisorRecursive(int a, int b) {
  if (a == 0)
    return std::abs(b);
  return greatestCommonDivisorRecursive(____________, ____________);
}

int greatestCommonDivisorIterative(int a, int b) {
  while (b != 0) {
    int temp = ____________;
    b = ____________;
    a = temp;
  }
  return std::abs(a);
}
