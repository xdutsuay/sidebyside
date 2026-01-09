/**
 * @file
 * @brief Find the unique number in an array where every other number appears
 * twice
 *
 * @details
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one. The generic solution using XOR operation is O(n)
 * time complexity and O(1) space complexity.
 *
 * Xor properties:
 * 1. a ^ a = 0
 * 2. a ^ 0 = a
 * 3. a ^ b ^ a = b
 *
 * @author [Your Name]
 */

#include <cassert>
#include <iostream>
#include <vector>

/**
 * @brief Finds the unique number in the vector
 * @param arr vector of integers
 * @return unique number
 */
int find_unique_number(const std::vector<int> &arr) {
  int result = 0;
  for (int num : arr) {
    result ^= num;
  }
  return result;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
  std::vector<int> arr1 = {2, 2, 1};
  assert(find_unique_number(arr1) == 1);

  std::vector<int> arr2 = {4, 1, 2, 1, 2};
  assert(find_unique_number(arr2) == 4);

  std::vector<int> arr3 = {1};
  assert(find_unique_number(arr3) == 1);

  std::cout << "All tests passed!" << std::endl;
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
  test();
  return 0;
}
