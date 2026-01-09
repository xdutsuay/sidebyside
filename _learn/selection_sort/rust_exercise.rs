pub fn selection_sort(arr: &mut [i32]) {
    let len = arr.len();
    for i in 0..len {
        let mut min_idx = i;
        // Find minimum element in unsorted array
        for j in (i + 1)..len {
            if arr[j] < arr[____________] {
                min_idx = ____________;
            }
        }
        if min_idx != i {
            arr.swap(i, ____________);
        }
    }
}
