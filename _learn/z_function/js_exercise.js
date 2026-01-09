/**
 * Z-Function Algorithm - FILL IN THE BLANKS
 */

function zFunction(s) {
    const n = s.length;
    const z = Array(n).fill(0);
    let l = 0, r = 0;

    for (let i = 1; i < n; i++) {
        if (i <= r) {
            // Optimization: Use previously computed Z-value
            z[i] = Math.min(r - i + 1, z[____________]);
        }
        // Naive expansion
        while (i + z[i] < n && s[z[i]] === s[____________]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = ____________;
        }
    }
    return z;
}
