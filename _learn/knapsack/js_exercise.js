/**
 * 0/1 Knapsack Problem - FILL IN THE BLANKS
 */
function knapsack(W, wt, val) {
    const n = wt.length;
    const dp = Array(n + 1).fill().map(() => Array(W + 1).fill(0));

    for (let i = 1; i <= n; i++) {
        for (let w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                // Max of include or exclude
                dp[i][w] = Math.max(
                    ____________ + dp[i - 1][w - ____________],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = ____________;
            }
        }
    }
    return dp[n][W];
}
