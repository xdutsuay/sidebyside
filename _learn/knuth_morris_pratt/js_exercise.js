/**
 * KMP Algorithm - FILL IN THE BLANKS
 */

function knuthMorrisPratt(text, pattern) {
    if (pattern.length === 0) return 0;
    const failure = getFailureArray(pattern);
    let i = 0;
    let j = 0;

    while (i < text.length) {
        if (pattern[j] === text[i]) {
            if (j === pattern.length - 1) {
                return i - j;
            }
            j++;
            i++;
        } else if (j > 0) {
            // Use failure table to skip
            j = failure[____________];
        } else {
            i++;
        }
    }
    return -1;
}
