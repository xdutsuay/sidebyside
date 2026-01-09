/**
 * Binary Search implementation in JavaScript - FILL IN THE BLANKS
 */
function binarySearch(arr, target) {
    let left = 0;
    let right = arr.length - 1;

    while (left <= ____________) {
        let mid = Math.floor(left + (right - left) / 2);

        if (arr[mid] === ____________) {
            return mid;
        }
        if (arr[mid] < target) {
            // Target is greater, ignore left half
            left = ____________;
        } else {
            // Target is smaller, ignore right half
            right = ____________;
        }
    }
    return -1;
}

const arr = [2, 3, 4, 10, 40];
console.log(binarySearch(arr, 10));
