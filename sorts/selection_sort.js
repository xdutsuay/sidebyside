/**
 * Selection Sort
 */
function selectionSort(arr) {
    const n = arr.length;
    for (let i = 0; i < n - 1; i++) {
        let min_idx = i;
        for (let j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx !== i) {
            // Swap
            let temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
    return arr;
}

const arr = [64, 25, 12, 22, 11];
console.log("Original:", arr);
console.log("Sorted:", selectionSort(arr));
