/**
 * Bubble Sort implementation in JavaScript - FILL IN THE BLANKS
 * 
 * Instructions: Replace the ____________ with the correct code.
 */
function bubbleSort(collection) {
    let len = collection.length;
    let swapped;

    for (let i = 0; i < len; i++) {
        swapped = false;
        // Inner loop: iterate through the unsorted elements
        for (let j = 0; j < ____________; j++) {

            // Compare adjacent elements
            if (collection[j] > collection[____________]) {
                // Swap elements
                let temp = collection[j];
                collection[j] = collection[j + 1];
                collection[j + 1] = temp;
                swapped = true;
            }
        }
        // Optimization: stop if already sorted
        if (!swapped) ____________;
    }
    return collection;
}

// Example usage
const arr = [64, 34, 25, 12, 22, 11, 90];
console.log("Unsorted array:", arr.slice());
console.log("Sorted array:", bubbleSort(arr));
