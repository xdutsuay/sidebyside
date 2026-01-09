/**
 * Longest Common Subsequence - FILL IN THE BLANKS
 */
function longestCommonSubsequence(x, y) {
    const m = x.length;
    const n = y.length;
    const dp = Array(m + 1).fill().map(() => Array(n + 1).fill(0));

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (x[i - 1] === y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][____________];
            } else {
                dp[i][j] = Math.max(dp[i - 1][____________], dp[____________][j - 1]);
            }
        }
    }
    return dp[m][n];
}
