#include <cassert>
#include <iostream>
#include <vector>

/**
 * @brief Find the unique number in the vector - FILL IN THE BLANKS
 *
 * Hint: Use the XOR property (a ^ a = 0, a ^ 0 = a)
 */
int find_unique_number(const std::vector<int> &arr) {
  int result = 0;
  for (int num : arr) {
    result ____________ num;
  }
  return result;
}

int main() {
  std::vector<int> arr = {4, 1, 2, 1, 2};
  std::cout << find_unique_number(arr) << std::endl;
  return 0;
}
