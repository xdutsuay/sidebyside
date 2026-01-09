/**
 * Quick Sort implementation in JavaScript - FILL IN THE BLANKS
 */
function partition(arr, low, high) {
    // Pivot selection (usually last element)
    let pivot = arr[____________];
    let i = low - 1;

    for (let j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Swap elements at i and j
            [arr[i], arr[j]] = [arr[j], arr[____________]];
        }
    }
    // Swap the pivot into its final place
    [arr[i + 1], arr[high]] = [arr[high], arr[i + 1]];
    return i + 1;
}

function quickSort(arr, low = 0, high = null) {
    if (high === null) high = arr.length - 1;

    if (low < high) {
        let pi = partition(arr, low, high);

        // Recursive calls
        quickSort(arr, low, ____________);
        quickSort(arr, ____________, high);
    }
    return arr;
}

let arr = [10, 7, 8, 9, 1, 5];
console.log("Sort result:", quickSort(arr));
