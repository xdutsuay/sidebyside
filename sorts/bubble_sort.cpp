#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Bubble Sort implementation in C++
 * 
 * @tparam T Type of the elements (must confirm to PartialOrd/Comparable)
 * @param collection Vector to be sorted
 */
template <typename T>
void bubble_sort(std::vector<T>& collection) {
    size_t n = collection.size();
    if (n == 0) return;

    for (size_t i = 0; i < n - 1; ++i) {
        bool swapped = false;
        // Last i elements are already in place
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (collection[j] > collection[j + 1]) {
                std::swap(collection[j], collection[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (!swapped)
            break;
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Unsorted array: ";
    for (int i : arr) std::cout << i << " ";
    std::cout << std::endl;

    bubble_sort(arr);

    std::cout << "Sorted array: ";
    for (int i : arr) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
