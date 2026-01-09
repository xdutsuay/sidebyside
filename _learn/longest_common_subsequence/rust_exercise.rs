use std::cmp;

pub fn longest_common_subsequence(x: &str, y: &str) -> usize {
    let m = x.len();
    let n = y.len();
    let x_bytes = x.as_bytes();
    let y_bytes = y.as_bytes();

    let mut dp = vec![vec![0; n + 1]; m + 1];

    for i in 1..=m {
        for j in 1..=n {
            if x_bytes[i - 1] == y_bytes[j - 1] {
                dp[i][j] = 1 + dp[____________][____________];
            } else {
                dp[i][j] = cmp::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    dp[m][n]
}
