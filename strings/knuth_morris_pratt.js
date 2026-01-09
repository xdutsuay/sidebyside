/**
 * KMP Algorithm
 */

function getFailureArray(pattern) {
    const failure = Array(pattern.length).fill(0);
    let i = 0;
    let j = 1;

    while (j < pattern.length) {
        if (pattern[i] === pattern[j]) {
            i++;
            failure[j] = i;
            j++;
        } else if (i > 0) {
            i = failure[i - 1];
        } else {
            failure[j] = 0;
            j++;
        }
    }
    return failure;
}

function knuthMorrisPratt(text, pattern) {
    if (pattern.length === 0) return 0;
    const failure = getFailureArray(pattern);
    let i = 0; // text index
    let j = 0; // pattern index

    while (i < text.length) {
        if (pattern[j] === text[i]) {
            if (j === pattern.length - 1) {
                return i - j;
            }
            j++;
            i++;
        } else if (j > 0) {
            j = failure[j - 1];
        } else {
            i++;
        }
    }
    return -1;
}

const text = "ABABDABACDABABCABAB";
const pattern = "ABABCABAB";
const index = knuthMorrisPratt(text, pattern);
console.log("Pattern found at index:", index);
