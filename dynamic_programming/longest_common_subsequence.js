/**
 * Longest Common Subsequence
 */

function longestCommonSubsequence(x, y) {
    const m = x.length;
    const n = y.length;

    // Initialize DP table
    const dp = Array(m + 1).fill().map(() => Array(n + 1).fill(0));

    // Build DP table
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (x[i - 1] === y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct subsequence
    let seq = "";
    let i = m;
    let j = n;
    while (i > 0 && j > 0) {
        if (x[i - 1] === y[j - 1]) {
            seq = x[i - 1] + seq;
            i--;
            j--;
        } else if (dp[i][j] === dp[i - 1][j]) {
            i--;
        } else {
            j--;
        }
    }

    return {
        length: dp[m][n],
        subsequence: seq
    };
}

const a = "AGGTAB";
const b = "GXTXAYB";
const result = longestCommonSubsequence(a, b);
console.log("Length:", result.length);
console.log("Subsequence:", result.subsequence);
