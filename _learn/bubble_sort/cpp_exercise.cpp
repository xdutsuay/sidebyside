#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @brief Bubble Sort implementation in C++ - FILL IN THE BLANKS
 *
 * Instructions: Replace the ____________ with the correct logic to complete the
 * Bubble Sort algorithm.
 */
template <typename T> void bubble_sort(std::vector<T> &collection) {
  size_t n = collection.size();
  if (n == 0)
    return;

  // OUTER LOOP: Iterates through the entire array
  for (size_t i = 0; i < n - 1; ++i) {
    bool swapped = false;

    // INNER LOOP: Goes through the unsorted part of the array
    // Hint: After i iterations, the last i elements are already sorted.
    for (size_t j = 0; j < ____________; ++j) {

      // SWAP CONDITION: Compare adjacent elements
      if (collection[j] > collection[____________]) {
        std::swap(collection[j], collection[j + 1]);
        swapped = true;
      }
    }

    // OPTIMIZATION: If no swaps occurred, the array is sorted
    if (!swapped)
      ____________;
  }
}

int main() {
  std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
  std::cout << "Unsorted array: ";
  for (int i : arr)
    std::cout << i << " ";
  std::cout << std::endl;

  bubble_sort(arr);

  std::cout << "Sorted array: ";
  for (int i : arr)
    std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}
