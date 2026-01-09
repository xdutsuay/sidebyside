use std::cmp;

pub fn knapsack(w_capacity: usize, wt: &[usize], val: &[usize]) -> usize {
    let n = wt.len();
    let mut dp = vec![vec![0; w_capacity + 1]; n + 1];

    for i in 1..=n {
        for w in 1..=w_capacity {
            if wt[i - 1] <= w {
                dp[i][w] = cmp::max(
                    ____________ + dp[i - 1][w - ____________], // Include
                    dp[i - 1][w],                               // Exclude
                );
            } else {
                dp[i][w] = ____________;
            }
        }
    }
    dp[n][w_capacity]
}
