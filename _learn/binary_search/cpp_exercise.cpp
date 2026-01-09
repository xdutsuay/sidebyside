#include <iostream>
#include <vector>

/**
 * @brief Binary Search implementation in C++ - FILL IN THE BLANKS
 */
int binary_search(const std::vector<int> &arr, int target) {
  int left = 0;
  int right = arr.size() - 1;

  while (left <= ____________) {
    // Calculate middle index to avoid overflow
    int mid = left + (right - left) / 2;

    if (arr[mid] == ____________) {
      return mid;
    }
    if (arr[mid] < target) {
      // Target is in the right half
      left = ____________;
    } else {
      // Target is in the left half
      right = ____________;
    }
  }
  return -1;
}

int main() {
  std::vector<int> arr = {2, 3, 4, 10, 40};
  int target = 10;
  std::cout << binary_search(arr, target) << std::endl;
  return 0;
}
