/**
 * Linear Search implementation in JavaScript - FILL IN THE BLANKS
 */
function linearSearch(arr, target) {
    for (let i = 0; i < ____________; i++) {
        // Comparison
        if (arr[i] === ____________) {
            return i;
        }
    }
    return -1;
}

const arr = [10, 50, 30, 70, 80, 20];
console.log(linearSearch(arr, 30));
