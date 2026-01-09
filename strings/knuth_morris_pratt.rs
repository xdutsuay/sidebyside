fn get_failure_array(pattern: &str) -> Vec<usize> {
    let pattern_bytes = pattern.as_bytes();
    let mut failure = vec![0; pattern.len()];
    let mut i = 0;
    let mut j = 1;

    while j < pattern.len() {
        if pattern_bytes[i] == pattern_bytes[j] {
            i += 1;
            failure[j] = i;
            j += 1;
        } else if i > 0 {
            i = failure[i - 1];
        } else {
            failure[j] = 0;
            j += 1;
        }
    }
    failure
}

pub fn knuth_morris_pratt(text: &str, pattern: &str) -> Option<usize> {
    if pattern.is_empty() { return Some(0); }
    let failure = get_failure_array(pattern);
    let text_bytes = text.as_bytes();
    let pattern_bytes = pattern.as_bytes();
    
    let mut i = 0;
    let mut j = 0;

    while i < text.len() {
        if pattern_bytes[j] == text_bytes[i] {
            if j == pattern.len() - 1 {
                return Some(i - j);
            }
            j += 1;
            i += 1;
        } else if j > 0 {
            j = failure[j - 1];
        } else {
            i += 1;
        }
    }
    None
}

fn main() {
    let text = "ABABDABACDABABCABAB";
    let pattern = "ABABCABAB";
    match knuth_morris_pratt(text, pattern) {
        Some(index) => println!("Pattern found at index {}", index),
        None => println!("Pattern not found"),
    }
}
