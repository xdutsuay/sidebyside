/**
 * Matrix Transposition implementation
 */

pub fn transpose(matrix: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    if matrix.is_empty() {
        return vec![];
    }

    let rows = matrix.len();
    let cols = matrix[0].len();
    let mut result = vec![vec![0; rows]; cols];

    for i in 0..rows {
        for j in 0..cols {
            result[j][i] = matrix[i][j];
        }
    }

    result
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_transpose() {
        let matrix = vec![vec![1, 2], vec![3, 4]];
        let expected = vec![vec![1, 3], vec![2, 4]];
        assert_eq!(transpose(&matrix), expected);

        let matrix2 = vec![vec![1, 2, 3], vec![4, 5, 6]];
        let expected2 = vec![vec![1, 4], vec![2, 5], vec![3, 6]];
        assert_eq!(transpose(&matrix2), expected2);
    }
}

fn main() {
    let matrix = vec![vec![1, 2, 3], vec![4, 5, 6]];
    println!("Transposed: {:?}", transpose(&matrix));
}
