use std::cmp;

pub fn z_function(s: &str) -> Vec<usize> {
    let n = s.len();
    let s_bytes = s.as_bytes();
    let mut z = vec![0; n];
    let mut l = 0;
    let mut r = 0;

    for i in 1..n {
        if i <= r {
            // Optimization
            z[i] = cmp::min(r - i + 1, z[____________]);
        }
        // Naive expansion
        while i + z[i] < n && s_bytes[z[i]] == s_bytes[____________] {
            z[i] += 1;
        }
        if i + z[i] - 1 > r {
            l = i;
            r = ____________;
        }
    }
    z
}
