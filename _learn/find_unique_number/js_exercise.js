/**
 * Find the unique number in the array - FILL IN THE BLANKS
 * Hint: Use the XOR property (a ^ a = 0, a ^ 0 = a)
 */
function findUniqueNumber(arr) {
    let result = 0;
    for (const num of arr) {
    result ____________ num;
    }
    return result;
}

const arr = [4, 1, 2, 1, 2];
console.log(findUniqueNumber(arr));
