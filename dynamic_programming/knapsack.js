/**
 * 0/1 Knapsack Problem using Dynamic Programming
 */

function knapsack(W, wt, val) {
    const n = wt.length;
    // Initialize DP table
    const dp = Array(n + 1).fill().map(() => Array(W + 1).fill(0));

    // Build table
    for (let i = 1; i <= n; i++) {
        for (let w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = Math.max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Reconstruct solution
    const selectedItems = new Set();
    let tempW = W;
    for (let i = n; i > 0; i--) {
        if (dp[i][tempW] !== dp[i - 1][tempW]) {
            selectedItems.add(i);
            tempW -= wt[i - 1];
        }
    }

    return {
        maxValue: dp[n][W],
        selectedItems: selectedItems
    };
}

const val = [3, 2, 4, 4];
const wt = [4, 3, 2, 3];
const W = 6;

const result = knapsack(W, wt, val);
console.log("Optimal Value:", result.maxValue);
console.log("Selected Items:", Array.from(result.selectedItems));
