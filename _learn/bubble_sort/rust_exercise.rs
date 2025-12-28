/**
 * Bubble Sort implementation in Rust - FILL IN THE BLANKS
 */

pub fn bubble_sort<T: Ord + Copy>(arr: &mut [T]) {
    let n = arr.len();
    if n == 0 {
        return;
    }

    for i in 0..n {
        let mut swapped = false;
        // Inner loop range
        for j in 0..____________ {
            // Compare elements
            if arr[j] > arr[____________] {
                arr.swap(j, j + 1);
                swapped = true;
            }
        }
        if !swapped {
            ____________;
        }
    }
}

fn main() {
    let mut arr = vec![64, 34, 25, 12, 22, 11, 90];
    println!("Unsorted array: {:?}", arr);
    
    bubble_sort(&mut arr);
    
    println!("Sorted array: {:?}", arr);
}
