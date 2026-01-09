/**
 * Quick Sort implementation in Rust - FILL IN THE BLANKS
 */

fn partition<T: Ord + Copy>(arr: &mut [T]) -> usize {
    let len = arr.len();
    let pivot_index = len - 1;
    let mut i = 0;

    for j in 0..pivot_index {
        // Compare with pivot
        if arr[j] <= arr[____________] {
            arr.swap(i, j);
            i += 1;
        }
    }
    // Move pivot to correct place
    arr.swap(i, ____________);
    i
}

pub fn quick_sort<T: Ord + Copy>(arr: &mut [T]) {
    let len = arr.len();
    if len <= 1 {
        return;
    }

    let p = partition(arr);
    // Recursively sort left and right parts
    // Note: p is the index of the pivot, it is already sorted.
    quick_sort(&mut arr[0..____________]);
    quick_sort(&mut arr[____________..len]);
}

fn main() {
    let mut arr = vec![10, 7, 8, 9, 1, 5];
    println!("Unsorted array: {:?}", arr);
    
    quick_sort(&mut arr);
    
    println!("Sorted array: {:?}", arr);
}
