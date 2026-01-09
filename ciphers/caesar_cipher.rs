fn encrypt(text: &str, s: u8) -> String {
    let mut result = String::new();
    for c in text.chars() {
        if c.is_ascii_uppercase() {
            let encoded = ((c as u8 - b'A' + s) % 26) + b'A';
            result.push(encoded as char);
        } else if c.is_ascii_lowercase() {
            let encoded = ((c as u8 - b'a' + s) % 26) + b'a';
            result.push(encoded as char);
        } else {
            result.push(c);
        }
    }
    result
}

fn decrypt(text: &str, s: u8) -> String {
    encrypt(text, (26 - (s % 26)) % 26)
}

fn main() {
    let text = "ATTACKATONCE";
    let s = 4;
    println!("Text : {}", text);
    println!("Shift: {}", s);
    let cipher = encrypt(text, s);
    println!("Cipher: {}", cipher);
    println!("Decrypted: {}", decrypt(&cipher, s));
}
