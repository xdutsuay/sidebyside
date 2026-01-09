#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @brief Partition function using Lomuto partition scheme
 *
 * @param arr The vector to partition
 * @param low Starting index
 * @param high Ending index
 * @return int The partition index
 */
int partition(std::vector<int> &arr, int low, int high) {
  int pivot = arr[high]; // Pivot is the last element
  int i = (low - 1);     // Index of smaller element

  for (int j = low; j < high; j++) {
    // If current element is smaller than or equal to pivot
    if (arr[j] <= pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return (i + 1);
}

/**
 * @brief Quick Sort algorithm
 *
 * @param arr Vector to be sorted
 * @param low Starting index
 * @param high Ending index
 */
void quick_sort(std::vector<int> &arr, int low, int high) {
  if (low < high) {
    // pi is partitioning index, arr[pi] is now at right place
    int pi = partition(arr, low, high);

    // Separately sort elements before partition and after partition
    quick_sort(arr, low, pi - 1);
    quick_sort(arr, pi + 1, high);
  }
}

int main() {
  std::vector<int> arr = {10, 7, 8, 9, 1, 5};
  int n = arr.size();

  std::cout << "Unsorted array: ";
  for (int i : arr)
    std::cout << i << " ";
  std::cout << std::endl;

  quick_sort(arr, 0, n - 1);

  std::cout << "Sorted array: ";
  for (int i : arr)
    std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}
