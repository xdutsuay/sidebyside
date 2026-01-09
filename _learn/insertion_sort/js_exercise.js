/**
 * Insertion Sort - FILL IN THE BLANKS
 */
function insertionSort(arr) {
    for (let i = 1; i < arr.length; i++) {
        let key = arr[i];
        let j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > ____________) {
            arr[j + 1] = ____________;
            j = j - 1;
        }
        arr[j + 1] = ____________;
    }
    return arr;
}
