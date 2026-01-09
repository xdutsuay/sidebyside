pub fn selection_sort(arr: &mut [i32]) {
    let len = arr.len();
    for i in 0..len {
        let mut min_idx = i;
        for j in (i + 1)..len {
            if arr[j] < arr[min_idx] {
                min_idx = j;
            }
        }
        if min_idx != i {
            arr.swap(i, min_idx);
        }
    }
}

fn main() {
    let mut arr = [64, 25, 12, 22, 11];
    println!("Original: {:?}", arr);
    selection_sort(&mut arr);
    println!("Sorted: {:?}", arr);
}
