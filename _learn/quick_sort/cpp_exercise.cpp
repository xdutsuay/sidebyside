#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @brief Quick Sort implementation in C++ - FILL IN THE BLANKS
 *
 * Instructions: Implement the partition logic and recursive calls.
 */
int partition(std::vector<int> &arr, int low, int high) {
  int pivot = arr[____________]; // Traditionally picking last element as pivot
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    // If current element is smaller than or equal to pivot
    if (arr[j] <= ____________) {
      i++;
      // Swap arr[i] and arr[j]
      std::swap(arr[i], arr[j]);
    }
  }
  // Place pivot in correct position
  std::swap(arr[____________], arr[high]);
  return (i + 1);
}

void quick_sort(std::vector<int> &arr, int low, int high) {
  if (low < high) {
    // pi is partitioning index
    int pi = partition(arr, low, high);

    // Recursively sort elements before and after partition
    quick_sort(arr, ____________, pi - 1);
    quick_sort(arr, pi + 1, ____________);
  }
}

int main() {
  std::vector<int> arr = {10, 7, 8, 9, 1, 5};

  std::cout << "Values before: ";
  for (int x : arr)
    std::cout << x << " ";
  std::cout << "\n";

  quick_sort(arr, 0, arr.size() - 1);

  std::cout << "Values after:  ";
  for (int x : arr)
    std::cout << x << " ";
  std::cout << "\n";

  return 0;
}
