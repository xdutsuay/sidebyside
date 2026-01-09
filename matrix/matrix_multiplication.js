/**
 * Multiplies two matrices
 * @param {number[][]} A First matrix
 * @param {number[][]} B Second matrix
 * @returns {number[][]} Resultant matrix
 */
function multiply(A, B) {
    if (!A.length || !B.length || !A[0].length || !B[0].length) {
        throw new Error("Matrices cannot be empty");
    }

    const rowsA = A.length;
    const colsA = A[0].length;
    const rowsB = B.length;
    const colsB = B[0].length;

    if (colsA !== rowsB) {
        throw new Error("Matrix dimensions mismatch for multiplication");
    }

    const result = new Array(rowsA).fill(0).map(() => new Array(colsB).fill(0));

    for (let i = 0; i < rowsA; i++) {
        for (let j = 0; j < colsB; j++) {
            for (let k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

function test() {
    const A = [[1, 2], [3, 4]];
    const B = [[5, 6], [7, 8]];
    const expected = [[19, 22], [43, 50]];

    const result = multiply(A, B);
    console.assert(JSON.stringify(result) === JSON.stringify(expected), "Test 1 Failed");

    const C = [[1, 2, 3]];
    const D = [[4], [5], [6]];
    const expected2 = [[32]];

    const result2 = multiply(C, D);
    console.assert(JSON.stringify(result2) === JSON.stringify(expected2), "Test 2 Failed");

    console.log("All tests passed!");
}

test();
