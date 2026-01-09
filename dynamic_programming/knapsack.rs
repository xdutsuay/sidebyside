use std::collections::HashSet;
use std::cmp;

pub fn knapsack(w_capacity: usize, wt: &[usize], val: &[usize]) -> (usize, HashSet<usize>) {
    let n = wt.len();
    let mut dp = vec![vec![0; w_capacity + 1]; n + 1];

    for i in 1..=n {
        for w in 1..=w_capacity {
            if wt[i - 1] <= w {
                dp[i][w] = cmp::max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w],
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    let mut selected_items = HashSet::new();
    let mut temp_w = w_capacity;
    for i in (1..=n).rev() {
        if dp[i][temp_w] != dp[i - 1][temp_w] {
            selected_items.insert(i);
            temp_w -= wt[i - 1];
        }
    }

    (dp[n][w_capacity], selected_items)
}

fn main() {
    let val = vec![3, 2, 4, 4];
    let wt = vec![4, 3, 2, 3];
    let w = 6;

    let (max_value, selected_items) = knapsack(w, &wt, &val);
    println!("Optimal Value: {}", max_value);
    println!("Selected Items: {:?}", selected_items);
}
