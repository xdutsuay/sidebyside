#include <iostream>
#include <vector>

/**
 * @brief Linear Search implementation in C++ - FILL IN THE BLANKS
 */
int linear_search(const std::vector<int> &arr, int target) {
  // Iterate through the entire array
  for (size_t i = 0; i < ____________; ++i) {
    // Check if current element matches target
    if (arr[i] == ____________) {
      return i;
    }
  }
  // Return -1 if not found
  return -1;
}

int main() {
  std::vector<int> arr = {10, 50, 30, 70, 80, 20};
  int target = 30;
  std::cout << linear_search(arr, target) << std::endl;
  return 0;
}
