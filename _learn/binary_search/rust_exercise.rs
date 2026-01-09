/**
 * Binary Search implementation in Rust - FILL IN THE BLANKS
 */

pub fn binary_search<T: Ord>(arr: &[T], target: &T) -> Option<usize> {
    let mut left = 0;
    let mut right = arr.len();

    while left < ____________ {
        let mid = left + (right - left) / 2;

        if &arr[mid] == ____________ {
            return Some(mid);
        }
        if &arr[mid] < target {
            left = mid + 1;
        } else {
            right = ____________;
        }
    }
    None
}

fn main() {
    let arr = vec![2, 3, 4, 10, 40];
    let target = 10;
    println!("{:?}", binary_search(&arr, &target));
}
