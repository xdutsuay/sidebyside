/**
 * Merges two sorted arrays into one sorted array
 * @param {Array} left 
 * @param {Array} right 
 * @returns {Array}
 */
function merge(left, right) {
    let sortedArr = [];

    while (left.length && right.length) {
        if (left[0] < right[0]) {
            sortedArr.push(left.shift());
        } else {
            sortedArr.push(right.shift());
        }
    }

    return [...sortedArr, ...left, ...right];
}

/**
 * Merge Sort algorithm
 * @param {Array} arr 
 * @returns {Array}
 */
function mergeSort(arr) {
    if (arr.length <= 1) return arr;

    let mid = Math.floor(arr.length / 2);
    let left = mergeSort(arr.slice(0, mid));
    let right = mergeSort(arr.slice(mid));

    return merge(left, right);
}

// Example usage
let arr = [12, 11, 13, 5, 6, 7];
console.log("Given array:", arr);
console.log("Sorted array:", mergeSort(arr));
