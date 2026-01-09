/**
 * Quick Sort implementation in Rust
 */

fn partition<T: Ord + Copy>(arr: &mut [T]) -> usize {
    let len = arr.len();
    let pivot_index = len - 1;
    let mut i = 0;

    for j in 0..pivot_index {
        if arr[j] <= arr[pivot_index] {
            arr.swap(i, j);
            i += 1;
        }
    }
    arr.swap(i, pivot_index);
    i
}

pub fn quick_sort<T: Ord + Copy>(arr: &mut [T]) {
    let len = arr.len();
    if len <= 1 {
        return;
    }

    let p = partition(arr);
    quick_sort(&mut arr[0..p]);
    quick_sort(&mut arr[p + 1..len]);
}

fn main() {
    let mut arr = vec![10, 7, 8, 9, 1, 5];
    println!("Unsorted array: {:?}", arr);
    
    quick_sort(&mut arr);
    
    println!("Sorted array: {:?}", arr);
}
