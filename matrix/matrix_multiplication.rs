/**
 * Matrix Multiplication implementation
 */

pub fn multiply(a: &Vec<Vec<i32>>, b: &Vec<Vec<i32>>) -> Result<Vec<Vec<i32>>, String> {
    if a.is_empty() || b.is_empty() || a[0].is_empty() || b[0].is_empty() {
        return Err("Matrices cannot be empty".to_string());
    }

    let rows_a = a.len();
    let cols_a = a[0].len();
    let rows_b = b.len();
    let cols_b = b[0].len();

    if cols_a != rows_b {
        return Err("Matrix dimensions mismatch for multiplication".to_string());
    }

    let mut result = vec![vec![0; cols_b]; rows_a];

    for i in 0..rows_a {
        for j in 0..cols_b {
            for k in 0..cols_a {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    Ok(result)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_multiply() {
        let a = vec![vec![1, 2], vec![3, 4]];
        let b = vec![vec![5, 6], vec![7, 8]];
        let expected = vec![vec![19, 22], vec![43, 50]];
        assert_eq!(multiply(&a, &b).unwrap(), expected);

        let c = vec![vec![1, 2, 3]];
        let d = vec![vec![4], vec![5], vec![6]];
        let expected2 = vec![vec![32]];
        assert_eq!(multiply(&c, &d).unwrap(), expected2);
    }
}

fn main() {
    let a = vec![vec![1, 2], vec![3, 4]];
    let b = vec![vec![5, 6], vec![7, 8]];
    match multiply(&a, &b) {
        Ok(res) => println!("Result: {:?}", res),
        Err(e) => println!("Error: {}", e),
    }
}
