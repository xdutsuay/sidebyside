/**
 * Linear Search implementation in Rust - FILL IN THE BLANKS
 */

pub fn linear_search<T: PartialEq>(arr: &[T], target: &T) -> Option<usize> {
    // Iterate with index
    for (index, item) in arr.iter().____________() {
        if item == ____________ {
            return Some(index);
        }
    }
    None
}

fn main() {
    let arr = vec![10, 50, 30, 70, 80, 20];
    let target = 30;
    println!("{:?}", linear_search(&arr, &target));
}
