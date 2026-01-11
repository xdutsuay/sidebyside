/**
 * Levenshtein Distance Algorithm (Optimized) in Rust
 */

use std::cmp::min;

fn levenshtein_distance_optimized(s1: &str, s2: &str) -> usize {
    let mut s1_chars: Vec<char> = s1.chars().collect();
    let mut s2_chars: Vec<char> = s2.chars().collect();

    if s1_chars.len() < s2_chars.len() {
        return levenshtein_distance_optimized(s2, s1);
    }

    if s2_chars.len() == 0 {
        return s1_chars.len();
    }

    let mut previous_row: Vec<usize> = (0..=s2_chars.len()).collect();

    for (i, c1) in s1_chars.iter().enumerate() {
        let mut current_row = vec![i + 1];

        for (j, c2) in s2_chars.iter().enumerate() {
            let insertions = previous_row[j + 1] + 1;
            let deletions = current_row[j] + 1;
            let substitutions = previous_row[j] + if c1 != c2 { 1 } else { 0 };
            current_row.push(min(insertions, min(deletions, substitutions)));
        }
        previous_row = current_row;
    }

    *previous_row.last().unwrap()
}

fn main() {
    let s1 = "kitten";
    let s2 = "sitting";
    println!("Distance between {} and {} is: {}", s1, s2, levenshtein_distance_optimized(s1, s2));
}
