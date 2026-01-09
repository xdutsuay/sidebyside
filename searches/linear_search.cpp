#include <iostream>
#include <vector>

/**
 * @brief Linear Search implementation in C++
 *
 * @param arr Vector to search
 * @param target Value to search for
 * @return int Index of target or -1 if not found
 */
int linear_search(const std::vector<int> &arr, int target) {
  for (size_t i = 0; i < arr.size(); ++i) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  std::vector<int> arr = {10, 50, 30, 70, 80, 20};
  int target = 30;

  int result = linear_search(arr, target);

  if (result != -1)
    std::cout << "Element found at index " << result << std::endl;
  else
    std::cout << "Element not found" << std::endl;

  return 0;
}
