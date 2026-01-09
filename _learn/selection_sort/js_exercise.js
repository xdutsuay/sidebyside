/**
 * Selection Sort - FILL IN THE BLANKS
 */
function selectionSort(arr) {
    const n = arr.length;
    for (let i = 0; i < n - 1; i++) {
        let min_idx = i;
        for (let j = i + 1; j < n; j++) {
            if (arr[j] < arr[____________]) {
                min_idx = ____________;
            }
        }
        if (min_idx !== i) {
            // Swap
            let temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = ____________;
        }
    }
    return arr;
}
