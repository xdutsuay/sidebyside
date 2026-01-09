pub fn heapify(arr: &mut [i32], n: usize, i: usize) {
    let mut largest = i;
    let left = 2 * i + 1;
    let right = 2 * i + 2;

    if left < n && arr[left] > arr[largest] { largest = left; }
    if right < n && arr[right] > arr[largest] { largest = right; }

    if largest != i {
        arr.swap(i, largest);
        heapify(arr, n, ____________);
    }
}

pub fn heap_sort(arr: &mut [i32]) {
    let n = arr.len();

    for i in (0..n / 2).rev() {
        heapify(arr, n, i);
    }

    for i in (1..n).rev() {
        arr.swap(0, i);
        // Heapify root element to get highest element at root again
        heapify(arr, ____________, 0);
    }
}
