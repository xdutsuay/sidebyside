#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &arr) {
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    // Move elements greater than key one position ahead
    while (j >= 0 && arr[j] > ____________) {
      arr[j + 1] = ____________;
      j = j - 1;
    }
    arr[j + 1] = ____________;
  }
}
