/**
 * Vigenere Cipher
 */

function translateMessage(key, message, mode) {
    const letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    let translated = "";
    let keyIndex = 0;
    key = key.toUpperCase();

    for (let i = 0; i < message.length; i++) {
        const symbol = message[i];
        const upperSymbol = symbol.toUpperCase();
        const index = letters.indexOf(upperSymbol);

        if (index !== -1) {
            let num = index;
            const keyVal = letters.indexOf(key[keyIndex]);

            if (mode === "encrypt") {
                num += keyVal;
            } else {
                num -= keyVal;
            }

            // Handle wrap around
            if (num < 0) {
                num += 26;
            } else {
                num %= 26;
            }

            if (symbol === upperSymbol) {
                translated += letters[num];
            } else {
                translated += letters[num].toLowerCase();
            }

            keyIndex++;
            if (keyIndex === key.length) {
                keyIndex = 0;
            }
        } else {
            translated += symbol;
        }
    }
    return translated;
}

const text = "This is Harshil Darji from Dharmaj.";
const key = "HDarji";

const encrypted = translateMessage(key, text, "encrypt");
console.log("Encrypted:", encrypted);
const decrypted = translateMessage(key, encrypted, "decrypt");
console.log("Decrypted:", decrypted);
