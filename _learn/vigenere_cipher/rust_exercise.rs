pub fn translate_message(key: &str, message: &str, encrypt: bool) -> String {
    // ... setup

    for symbol in message.chars() {
        // ... 
        if let Some(num) = letters.find(upper_symbol) {
            // ...

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

            // ...

            key_index += 1;
            if key_index == key.len() {
                key_index = ____________;
            }
        } else {
            translated.push(symbol);
        }
    }
    translated
}
