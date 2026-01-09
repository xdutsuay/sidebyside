/**
 * Find the unique number in an array where every other number appears twice.
 * 
 * Given a non-empty array of integers, every element appears twice except for one.
 * Find that single one.
 * The generic solution using XOR operation is O(n) time complexity and O(1) space complexity.
 */

pub fn find_unique_number(arr: &[i32]) -> i32 {
    let mut result = 0;
    for &num in arr {
        result ^= num;
    }
    result
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_find_unique_number() {
        assert_eq!(find_unique_number(&[2, 2, 1]), 1);
        assert_eq!(find_unique_number(&[4, 1, 2, 1, 2]), 4);
        assert_eq!(find_unique_number(&[1]), 1);
    }
}

fn main() {
    let arr = vec![4, 1, 2, 1, 2];
    println!("Unique number: {}", find_unique_number(&arr));
}
