/**
 * Euclidean GCD - FILL IN THE BLANKS
 */

function greatestCommonDivisorRecursive(a, b) {
    if (a === 0) return Math.abs(b);
    return greatestCommonDivisorRecursive(____________, ____________);
}

function greatestCommonDivisorIterative(a, b) {
    while (b !== 0) {
        let temp = ____________;
        b = ____________;
        a = temp;
    }
    return Math.abs(a);
}
