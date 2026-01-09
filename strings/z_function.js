/**
 * Z-Function Algorithm
 */

function zFunction(s) {
    const n = s.length;
    const z = Array(n).fill(0);
    let l = 0, r = 0;

    for (let i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = Math.min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] === s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

function findPattern(pattern, text) {
    const combined = pattern + "$" + text;
    const z = zFunction(combined);
    let count = 0;
    const pLen = pattern.length;

    for (let val of z) {
        if (val === pLen) {
            count++;
        }
    }
    return count;
}

const text = "abracadabra";
const pattern = "abr";
console.log("Occurrences:", findPattern(pattern, text));
