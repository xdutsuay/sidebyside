#include <iostream>
#include <vector>

/**
 * @brief Merge Sort implementation in C++ - FILL IN THE BLANKS
 */

void merge(std::vector<int> &arr, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  std::vector<int> L(n1), R(n2);

  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  int i = 0, j = 0, k = l;

  // Merge temp arrays back into arr
  while (i < n1 && j < n2) {
    if (L[i] <= ____________) { // Compare element from L and R
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy remaining elements
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = ____________;
    j++;
    k++;
  }
}

void merge_sort(std::vector<int> &arr, int l, int r) {
  if (l >= r)
    return;

  int m = l + (r - l) / 2;
  // Recursive calls
  merge_sort(arr, l, ____________);
  merge_sort(arr, ____________, r);

  // Merge the sorted halves
  merge(arr, l, m, r);
}

int main() {
  std::vector<int> arr = {12, 11, 13, 5, 6, 7};
  merge_sort(arr, 0, arr.size() - 1);
  for (int x : arr)
    std::cout << x << " ";
  std::cout << std::endl;
  return 0;
}
