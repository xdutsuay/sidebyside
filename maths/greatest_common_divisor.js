/**
 * Euclidean GCD
 */

function greatestCommonDivisorRecursive(a, b) {
    if (a === 0) return Math.abs(b);
    return greatestCommonDivisorRecursive(b % a, a);
}

function greatestCommonDivisorIterative(a, b) {
    while (b !== 0) {
        let temp = b;
        b = a % b;
        a = temp;
    }
    return Math.abs(a);
}

const a = 24;
const b = 40;
console.log(`GCD Recursive (${a}, ${b}) = ${greatestCommonDivisorRecursive(a, b)}`);
console.log(`GCD Iterative (${a}, ${b}) = ${greatestCommonDivisorIterative(a, b)}`);
