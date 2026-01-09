use std::cmp;

pub fn longest_common_subsequence(x: &str, y: &str) -> (usize, String) {
    let m = x.len();
    let n = y.len();
    let x_bytes = x.as_bytes();
    let y_bytes = y.as_bytes();

    let mut dp = vec![vec![0; n + 1]; m + 1];

    for i in 1..=m {
        for j in 1..=n {
            if x_bytes[i - 1] == y_bytes[j - 1] {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = cmp::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    let mut seq = String::new();
    let mut i = m;
    let mut j = n;

    while i > 0 && j > 0 {
        if x_bytes[i - 1] == y_bytes[j - 1] {
            seq.insert(0, x_bytes[i - 1] as char);
            i -= 1;
            j -= 1;
        } else if dp[i][j] == dp[i - 1][j] {
            i -= 1;
        } else {
            j -= 1;
        }
    }

    (dp[m][n], seq)
}

fn main() {
    let a = "AGGTAB";
    let b = "GXTXAYB";
    let (len, subseq) = longest_common_subsequence(a, b);
    println!("Length: {}", len);
    println!("Subsequence: {}", subseq);
}
