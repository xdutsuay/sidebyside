/**
 * Binary Search implementation in JavaScript
 * @param {Array} arr - Sorted array
 * @param {number} target - Value to search for
 * @returns {number} - Index of target or -1
 */
function binarySearch(arr, target) {
    let left = 0;
    let right = arr.length - 1;

    while (left <= right) {
        let mid = Math.floor(left + (right - left) / 2);

        if (arr[mid] === target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Example usage
const arr = [2, 3, 4, 10, 40];
const target = 10;
const result = binarySearch(arr, target);

console.log(`Element found at index: ${result}`);
