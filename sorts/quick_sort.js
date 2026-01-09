/**
 * Partition function using Lomuto partition scheme
 * @param {Array} arr - The array to partition
 * @param {number} low - Starting index
 * @param {number} high - Ending index
 * @returns {number} - The partition index
 */
function partition(arr, low, high) {
    let pivot = arr[high];
    let i = low - 1;

    for (let j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            [arr[i], arr[j]] = [arr[j], arr[i]]; // Swap
        }
    }
    [arr[i + 1], arr[high]] = [arr[high], arr[i + 1]]; // Swap pivot
    return i + 1;
}

/**
 * Quick Sort algorithm
 * @param {Array} arr - The array to sort
 * @param {number} low - The starting index (optional)
 * @param {number} high - The ending index (optional)
 * @returns {Array} - The sorted array
 */
function quickSort(arr, low = 0, high = null) {
    if (high === null) high = arr.length - 1;

    if (low < high) {
        let pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    return arr;
}

// Example usage
let arr = [10, 7, 8, 9, 1, 5];
console.log("Unsorted array:", arr.slice());
console.log("Sorted array:", quickSort(arr));
