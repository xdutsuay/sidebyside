/**
 * Rotates a matrix 90 degrees clockwise in-place
 * @param {number[][]} matrix
 */
function rotate(matrix) {
    const n = matrix.length;

    // Transpose
    for (let i = 0; i < n; i++) {
        for (let j = i; j < n; j++) {
            [matrix[i][j], matrix[j][i]] = [matrix[j][i], matrix[i][j]];
        }
    }

    // Reverse rows
    for (let i = 0; i < n; i++) {
        matrix[i].reverse();
    }
    return matrix;
}

function test() {
    const matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ];
    const expected = [
        [7, 4, 1],
        [8, 5, 2],
        [9, 6, 3]
    ];

    rotate(matrix);
    console.assert(JSON.stringify(matrix) === JSON.stringify(expected), "Test Failed");
    console.log("All tests passed!");
}

test();
