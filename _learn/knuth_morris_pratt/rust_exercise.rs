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
            // Skip using failure table
            j = failure[____________];
        } else {
            i += 1;
        }
    }
    None
}
