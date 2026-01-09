/**
 * @function findUniqueNumber
 * @description Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 * The generic solution using XOR operation is O(n) time complexity and O(1) space complexity.
 * @param {number[]} arr - The input array of integers
 * @returns {number} The unique number
 */
function findUniqueNumber(arr) {
    let result = 0;
    for (const num of arr) {
        result ^= num;
    }
    return result;
}

// Example usage and tests
function test() {
    console.assert(findUniqueNumber([2, 2, 1]) === 1, "Test Case 1 Failed");
    console.assert(findUniqueNumber([4, 1, 2, 1, 2]) === 4, "Test Case 2 Failed");
    console.assert(findUniqueNumber([1]) === 1, "Test Case 3 Failed");
    console.log("All tests passed!");
}

test();
