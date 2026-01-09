/**
 * Find the unique number in an array - FILL IN THE BLANKS
 * Hint: Use the XOR property (a ^ a = 0, a ^ 0 = a)
 */

pub fn find_unique_number(arr: &[i32]) -> i32 {
    let mut result = 0;
    for &num in arr {
        result ____________ num;
    }
    result
}

fn main() {
    let arr = vec![4, 1, 2, 1, 2];
    println!("{}", find_unique_number(&arr));
}
