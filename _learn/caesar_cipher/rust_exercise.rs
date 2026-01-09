fn encrypt(text: &str, s: u8) -> String {
    let mut result = String::new();
    for c in text.chars() {
        if c.is_ascii_uppercase() {
            let encoded = ((c as u8 - b'A' + s) % 26) + b'A';
            result.push(encoded as char);
        } else if c.is_ascii_lowercase() {
            let encoded = ((c as u8 - ____________ + s) % 26) + ____________;
            result.push(encoded as char);
        } else {
            result.push(c);
        }
    }
    result
}

fn decrypt(text: &str, s: u8) -> String {
    encrypt(text, (____________ - (s % ____________)) % ____________)
}
