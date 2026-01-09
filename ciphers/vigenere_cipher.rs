pub fn translate_message(key: &str, message: &str, encrypt: bool) -> String {
    let letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    let mut translated = String::new();
    let mut key_index = 0;
    let key_upper = key.to_uppercase();
    let key_chars: Vec<char> = key_upper.chars().collect();
    let letters_vec: Vec<char> = letters.chars().collect();

    for symbol in message.chars() {
        let upper_symbol = symbol.to_ascii_uppercase();
        if let Some(num) = letters.find(upper_symbol) {
            let mut num = num as i32;
            let key_char = key_chars[key_index];
            let key_val = letters.find(key_char).unwrap() as i32;

            if encrypt {
                num += key_val;
            } else {
                num -= key_val;
            }

            if num < 0 {
                num += 26;
            } else {
                num %= 26;
            }

            if symbol.is_uppercase() {
                translated.push(letters_vec[num as usize]);
            } else {
                translated.push(letters_vec[num as usize].to_ascii_lowercase());
            }

            key_index += 1;
            if key_index == key.len() {
                key_index = 0;
            }
        } else {
            translated.push(symbol);
        }
    }
    translated
}

fn main() {
    let text = "This is Harshil Darji from Dharmaj.";
    let key = "HDarji";

    let encrypted = translate_message(key, text, true);
    println!("Encrypted: {}", encrypted);
    let decrypted = translate_message(key, &encrypted, false);
    println!("Decrypted: {}", decrypted);
}
