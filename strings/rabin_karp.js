/**
 * Rabin-Karp Algorithm
 */
const ALPHABET_SIZE = 256;
const MODULUS = 1000003;

function rabinKarp(pattern, text) {
    const pLen = pattern.length;
    const tLen = text.length;

    if (pLen > tLen) return false;

    let pHash = 0;
    let textHash = 0;
    let modulusPower = 1;

    for (let i = 0; i < pLen; i++) {
        pHash = (pattern.charCodeAt(i) + pHash * ALPHABET_SIZE) % MODULUS;
        textHash = (text.charCodeAt(i) + textHash * ALPHABET_SIZE) % MODULUS;
        if (i < pLen - 1) {
            modulusPower = (modulusPower * ALPHABET_SIZE) % MODULUS;
        }
    }

    for (let i = 0; i <= tLen - pLen; i++) {
        if (pHash === textHash) {
            if (text.substring(i, i + pLen) === pattern) {
                return true;
            }
        }

        if (i < tLen - pLen) {
            textHash = (textHash - text.charCodeAt(i) * modulusPower) * ALPHABET_SIZE + text.charCodeAt(i + pLen);
            textHash %= MODULUS;
            if (textHash < 0) textHash += MODULUS;
        }
    }
    return false;
}

const text = "ABABDABACDABABCABAB";
const pattern = "ABABCABAB";

if (rabinKarp(pattern, text)) {
    console.log("Pattern found!");
} else {
    console.log("Pattern not found.");
}
