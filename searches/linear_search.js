/**
 * Linear Search implementation in JavaScript
 * @param {Array} arr - Array to search
 * @param {number} target - Value to search for
 * @returns {number} - Index of target or -1
 */
function linearSearch(arr, target) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === target) {
            return i;
        }
    }
    return -1;
}

// Example usage
const arr = [10, 50, 30, 70, 80, 20];
const target = 30;
const result = linearSearch(arr, target);

console.log(`Element found at index: ${result}`);
