/**
 * Linear Search implementation in Rust
 */

pub fn linear_search<T: PartialEq>(arr: &[T], target: &T) -> Option<usize> {
    for (index, item) in arr.iter().enumerate() {
        if item == target {
            return Some(index);
        }
    }
    None
}

fn main() {
    let arr = vec![10, 50, 30, 70, 80, 20];
    let target = 30;
    
    match linear_search(&arr, &target) {
        Some(index) => println!("Element found at index {}", index),
        None => println!("Element not found"),
    }
}
