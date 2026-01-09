/**
 * Rabin-Karp Algorithm - FILL IN THE BLANKS
 */
// Constants omitted

function rabinKarp(pattern, text) {
    // ... setup omitted

    for (let i = 0; i <= tLen - pLen; i++) {
        if (pHash === textHash) {
            if (text.substring(i, i + pLen) === pattern) {
                return true;
            }
        }

        if (i < tLen - pLen) {
            // Rolling Hash:
            // Remove leading, Shift, Add trailing
            textHash = (textHash - text.charCodeAt(i) * ____________) * ____________ + text.charCodeAt(i + pLen);
            textHash %= MODULUS;
            if (textHash < 0) textHash += MODULUS;
        }
    }
    return false;
}
