/**
 * Merge Sort implementation in Rust - FILL IN THE BLANKS
 */

fn merge<T: Ord + Copy>(arr: &mut [T], mid: usize) {
    let left = arr[..mid].to_vec();
    let right = arr[mid..].to_vec();

    let mut i = 0;
    let mut j = 0;
    let mut k = 0;

    while i < left.len() && j < right.len() {
        if left[i] <= ____________ { // Compare left and right
            arr[k] = left[i];
            i += 1;
        } else {
            arr[k] = right[j];
            j += 1;
        }
        k += 1;
    }

    // Cleanup remaining
    while i < left.len() {
        arr[k] = left[i];
        i += 1;
        k += 1;
    }
    while j < right.len() {
        arr[k] = ____________;
        j += 1;
        k += 1;
    }
}

pub fn merge_sort<T: Ord + Copy>(arr: &mut [T]) {
    let len = arr.len();
    if len > 1 {
        let mid = len / 2;
        // Recursive calls
        merge_sort(&mut arr[..____________]);
        merge_sort(&mut arr[____________..]);
        merge(arr, mid);
    }
}

fn main() {
    let mut arr = vec![12, 11, 13, 5, 6, 7];
    merge_sort(&mut arr);
    println!("{:?}", arr);
}
