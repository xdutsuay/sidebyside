#include <iostream>
#include <vector>

/**
 * @brief Merge two subarrays of arr[].
 * First subarray is arr[l..m]
 * Second subarray is arr[m+1..r]
 */
void merge(std::vector<int> &arr, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  // Create temp arrays
  std::vector<int> L(n1), R(n2);

  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  // Merge the temp arrays back into arr[l..r]
  int i = 0; // Initial index of first subarray
  int j = 0; // Initial index of second subarray
  int k = l; // Initial index of merged subarray

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of L[], if any
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of R[], if any
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

/**
 * @brief Merge Sort algorithm
 *
 * @param arr Vector to be sorted
 * @param l Left index
 * @param r Right index
 */
void merge_sort(std::vector<int> &arr, int l, int r) {
  if (l >= r) {
    return; // Returns recursively
  }
  int m = l + (r - l) / 2;
  merge_sort(arr, l, m);
  merge_sort(arr, m + 1, r);
  merge(arr, l, m, r);
}

int main() {
  std::vector<int> arr = {12, 11, 13, 5, 6, 7};
  int arr_size = arr.size();

  std::cout << "Given array is: ";
  for (int i : arr)
    std::cout << i << " ";
  std::cout << std::endl;

  merge_sort(arr, 0, arr_size - 1);

  std::cout << "Sorted array is: ";
  for (int i : arr)
    std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}
