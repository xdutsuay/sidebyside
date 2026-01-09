/**
 * Strassen's Matrix Multiplication Algorithm
 * Only supports square matrices with dimensions that are powers of 2.
 */

function add(A, B) {
    const n = A.length;
    const C = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

function subtract(A, B) {
    const n = A.length;
    const C = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

function standardMultiply(A, B) {
    const n = A.length;
    const C = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            for (let k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

function strassen(A, B) {
    const n = A.length;
    if (n <= 2) {
        return standardMultiply(A, B);
    }

    const half = n / 2;
    const a11 = new Array(half).fill(0).map(() => new Array(half).fill(0));
    const a12 = new Array(half).fill(0).map(() => new Array(half).fill(0));
    const a21 = new Array(half).fill(0).map(() => new Array(half).fill(0));
    const a22 = new Array(half).fill(0).map(() => new Array(half).fill(0));
    const b11 = new Array(half).fill(0).map(() => new Array(half).fill(0));
    const b12 = new Array(half).fill(0).map(() => new Array(half).fill(0));
    const b21 = new Array(half).fill(0).map(() => new Array(half).fill(0));
    const b22 = new Array(half).fill(0).map(() => new Array(half).fill(0));

    for (let i = 0; i < half; i++) {
        for (let j = 0; j < half; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + half];
            a21[i][j] = A[i + half][j];
            a22[i][j] = A[i + half][j + half];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + half];
            b21[i][j] = B[i + half][j];
            b22[i][j] = B[i + half][j + half];
        }
    }

    const p1 = strassen(a11, subtract(b12, b22));
    const p2 = strassen(add(a11, a12), b22);
    const p3 = strassen(add(a21, a22), b11);
    const p4 = strassen(a22, subtract(b21, b11));
    const p5 = strassen(add(a11, a22), add(b11, b22));
    const p6 = strassen(subtract(a12, a22), add(b21, b22));
    const p7 = strassen(subtract(a11, a21), add(b11, b12));

    const c11 = add(subtract(add(p5, p4), p2), p6);
    const c12 = add(p1, p2);
    const c21 = add(p3, p4);
    const c22 = subtract(subtract(add(p5, p1), p3), p7);

    const C = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for (let i = 0; i < half; i++) {
        for (let j = 0; j < half; j++) {
            C[i][j] = c11[i][j];
            C[i][j + half] = c12[i][j];
            C[i + half][j] = c21[i][j];
            C[i + half][j + half] = c22[i][j];
        }
    }

    return C;
}

function test() {
    const A = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 15, 16]
    ];
    const B = [
        [1, 0, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 1, 0],
        [0, 0, 0, 1]
    ];

    const result = strassen(A, B);
    console.assert(JSON.stringify(result) === JSON.stringify(A), "Test Failed");
    console.log("All tests passed!");
}

test();
