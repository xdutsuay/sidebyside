/**
 * Transposes a matrix
 * @param {number[][]} matrix Input matrix
 * @returns {number[][]} Transposed matrix
 */
function transpose(matrix) {
    if (!matrix.length) return [];

    const rows = matrix.length;
    const cols = matrix[0].length;

    const result = new Array(cols).fill(0).map(() => new Array(rows).fill(0));

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

function test() {
    const matrix = [[1, 2], [3, 4]];
    const expected = [[1, 3], [2, 4]];
    const result = transpose(matrix);
    console.assert(JSON.stringify(result) === JSON.stringify(expected), "Test 1 Failed");

    const matrix2 = [[1, 2, 3], [4, 5, 6]];
    const expected2 = [[1, 4], [2, 5], [3, 6]];
    const result2 = transpose(matrix2);
    console.assert(JSON.stringify(result2) === JSON.stringify(expected2), "Test 2 Failed");

    console.log("All tests passed!");
}

test();
