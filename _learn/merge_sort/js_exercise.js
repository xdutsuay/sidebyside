/**
 * Merge Sort implementation in JavaScript - FILL IN THE BLANKS
 */
function merge(left, right) {
    let sortedArr = [];

    while (left.length && right.length) {
        if (left[0] < ____________) { // Compare first elements
            sortedArr.push(left.shift());
        } else {
            sortedArr.push(right.shift());
        }
    }

    return [...sortedArr, ...left, ...right];
}

function mergeSort(arr) {
    if (arr.length <= 1) return arr;

    let mid = Math.floor(arr.length / 2);
    // Recursive calls
    let left = mergeSort(arr.slice(0, ____________));
    let right = mergeSort(arr.slice(____________));

    return merge(left, right);
}

let arr = [12, 11, 13, 5, 6, 7];
console.log(mergeSort(arr));
