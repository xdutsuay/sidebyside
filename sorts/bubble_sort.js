/**
 * Bubble Sort implementation in JavaScript
 * 
 * @param {Array} collection - The array to sort
 * @returns {Array} - The sorted array
 */
function bubbleSort(collection) {
    let len = collection.length;
    let swapped;

    for (let i = 0; i < len; i++) {
        swapped = false;
        for (let j = 0; j < len - i - 1; j++) {
            if (collection[j] > collection[j + 1]) {
                // Swap elements
                let temp = collection[j];
                collection[j] = collection[j + 1];
                collection[j + 1] = temp;
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (!swapped) break;
    }
    return collection;
}

// Example usage
const arr = [64, 34, 25, 12, 22, 11, 90];
console.log("Unsorted array:", arr.slice()); // Copy to display original
console.log("Sorted array:", bubbleSort(arr));
