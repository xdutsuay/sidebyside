/**
 * Rotate Matrix 90 degrees clockwise
 */

pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
    let n = matrix.len();

    // Transpose
    for i in 0..n {
        for j in i..n {
            let temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Reverse rows
    for i in 0..n {
        matrix[i].reverse();
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_rotate() {
        let mut matrix = vec![
            vec![1, 2, 3],
            vec![4, 5, 6],
            vec![7, 8, 9],
        ];
        let expected = vec![
            vec![7, 4, 1],
            vec![8, 5, 2],
            vec![9, 6, 3],
        ];
        rotate(&mut matrix);
        assert_eq!(matrix, expected);
    }
}

fn main() {
    let mut matrix = vec![
        vec![1, 2, 3],
        vec![4, 5, 6],
        vec![7, 8, 9],
    ];
    rotate(&mut matrix);
    println!("{:?}", matrix);
}
