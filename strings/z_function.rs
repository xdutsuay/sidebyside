use std::cmp;

pub fn z_function(s: &str) -> Vec<usize> {
    let n = s.len();
    let s_bytes = s.as_bytes();
    let mut z = vec![0; n];
    let mut l = 0;
    let mut r = 0;

    for i in 1..n {
        if i <= r {
            z[i] = cmp::min(r - i + 1, z[i - l]);
        }
        while i + z[i] < n && s_bytes[z[i]] == s_bytes[i + z[i]] {
            z[i] += 1;
        }
        if i + z[i] - 1 > r {
            l = i;
            r = i + z[i] - 1;
        }
    }
    z
}

pub fn find_pattern(pattern: &str, text: &str) -> i32 {
    let combined = format!("{}${}", pattern, text);
    let z = z_function(&combined);
    let mut count = 0;
    let p_len = pattern.len();

    for &val in z.iter() {
        if val == p_len {
            count += 1;
        }
    }
    count
}

fn main() {
    let text = "abracadabra";
    let pattern = "abr";
    println!("Occurrences: {}", find_pattern(pattern, text));
}
