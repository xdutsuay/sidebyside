const ALPHABET_SIZE: i64 = 256;
const MODULUS: i64 = 1000003;

pub fn rabin_karp(pattern: &str, text: &str) -> bool {
    let p_len = pattern.len();
    let t_len = text.len();

    if p_len > t_len {
        return false;
    }

    let p_bytes = pattern.as_bytes();
    let t_bytes = text.as_bytes();

    let mut p_hash: i64 = 0;
    let mut text_hash: i64 = 0;
    let mut modulus_power: i64 = 1;

    for i in 0..p_len {
        p_hash = (p_bytes[i] as i64 + p_hash * ALPHABET_SIZE) % MODULUS;
        text_hash = (t_bytes[i] as i64 + text_hash * ALPHABET_SIZE) % MODULUS;
        if i < p_len - 1 {
            modulus_power = (modulus_power * ALPHABET_SIZE) % MODULUS;
        }
    }

    for i in 0..=(t_len - p_len) {
        if p_hash == text_hash {
            if &text[i..i + p_len] == pattern {
                return true;
            }
        }

        if i < t_len - p_len {
            text_hash = (text_hash - (t_bytes[i] as i64 * modulus_power) % MODULUS) * ALPHABET_SIZE + (t_bytes[i + p_len] as i64);
            text_hash %= MODULUS;
            if text_hash < 0 {
                text_hash += MODULUS;
            }
        }
    }
    false
}

fn main() {
    let text = "ABABDABACDABABCABAB";
    let pattern = "ABABCABAB";
    
    if rabin_karp(pattern, text) {
        println!("Pattern found!");
    } else {
        println!("Pattern not found.");
    }
}
