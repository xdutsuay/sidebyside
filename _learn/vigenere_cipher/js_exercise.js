/**
 * Vigenere Cipher - FILL IN THE BLANKS
 */

function translateMessage(key, message, mode) {
    // ... setup
    for (let i = 0; i < message.length; i++) {
        // ... get symbol
        if (index !== -1) {
            // ...

            if (mode === "encrypt") {
                num += keyVal;
            } else {
                num -= keyVal;
            }

            // Handle wrap around
            if (num < 0) {
                num += ____________;
            } else {
                num %= ____________;
            }

            // ...

            keyIndex++;
            if (keyIndex === key.length) {
                keyIndex = ____________;
            }
        } else {
            translated += symbol;
        }
    }
    return translated;
}
