/**
 * Strassen's Matrix Multiplication Algorithm in Rust
 */

type Matrix = Vec<Vec<i32>>;

fn add(a: &Matrix, b: &Matrix) -> Matrix {
    let n = a.len();
    let mut c = vec![vec![0; n]; n];
    for i in 0..n {
        for j in 0..n {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    c
}

fn subtract(a: &Matrix, b: &Matrix) -> Matrix {
    let n = a.len();
    let mut c = vec![vec![0; n]; n];
    for i in 0..n {
        for j in 0..n {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    c
}

fn standard_multiply(a: &Matrix, b: &Matrix) -> Matrix {
    let n = a.len();
    let mut c = vec![vec![0; n]; n];
    for i in 0..n {
        for j in 0..n {
            for k in 0..n {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    c
}

pub fn strassen(a: &Matrix, b: &Matrix) -> Matrix {
    let n = a.len();
    if n <= 2 {
        return standard_multiply(a, b);
    }

    let half = n / 2;
    let mut a11 = vec![vec![0; half]; half];
    let mut a12 = vec![vec![0; half]; half];
    let mut a21 = vec![vec![0; half]; half];
    let mut a22 = vec![vec![0; half]; half];
    let mut b11 = vec![vec![0; half]; half];
    let mut b12 = vec![vec![0; half]; half];
    let mut b21 = vec![vec![0; half]; half];
    let mut b22 = vec![vec![0; half]; half];

    for i in 0..half {
        for j in 0..half {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + half];
            a21[i][j] = a[i + half][j];
            a22[i][j] = a[i + half][j + half];

            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + half];
            b21[i][j] = b[i + half][j];
            b22[i][j] = b[i + half][j + half];
        }
    }

    let p1 = strassen(&a11, &subtract(&b12, &b22));
    let p2 = strassen(&add(&a11, &a12), &b22);
    let p3 = strassen(&add(&a21, &a22), &b11);
    let p4 = strassen(&a22, &subtract(&b21, &b11));
    let p5 = strassen(&add(&a11, &a22), &add(&b11, &b22));
    let p6 = strassen(&subtract(&a12, &a22), &add(&b21, &b22));
    let p7 = strassen(&subtract(&a11, &a21), &add(&b11, &b12));

    let c11 = add(&subtract(&add(&p5, &p4), &p2), &p6);
    let c12 = add(&p1, &p2);
    let c21 = add(&p3, &p4);
    let c22 = subtract(&subtract(&add(&p5, &p1), &p3), &p7);

    let mut c = vec![vec![0; n]; n];
    for i in 0..half {
        for j in 0..half {
            c[i][j] = c11[i][j];
            c[i][j + half] = c12[i][j];
            c[i + half][j] = c21[i][j];
            c[i + half][j + half] = c22[i][j];
        }
    }

    c
}

fn main() {
    let a = vec![
        vec![1, 2, 3, 4],
        vec![5, 6, 7, 8],
        vec![9, 10, 11, 12],
        vec![13, 14, 15, 16],
    ];

    let b = vec![
        vec![1, 0, 0, 0],
        vec![0, 1, 0, 0],
        vec![0, 0, 1, 0],
        vec![0, 0, 0, 1],
    ];

    let result = strassen(&a, &b);
    println!("{:?}", result);
}
