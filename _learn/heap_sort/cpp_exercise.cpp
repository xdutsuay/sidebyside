#include <iostream>
#include <vector>

void heapify(std::vector<int> &arr, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    std::swap(arr[i], arr[largest]);
    heapify(arr, n, ____________); // Recursive call
  }
}

void heapSort(std::vector<int> &arr) {
  int n = arr.size();

  // Build heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // Extract elements
  for (int i = n - 1; i > 0; i--) {
    std::swap(arr[0], arr[i]);
    heapify(arr, ____________, 0); // Reduced heap size
  }
}
