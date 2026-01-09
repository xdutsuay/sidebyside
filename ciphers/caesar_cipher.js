/**
 * Caesar Cipher
 */

function encrypt(text, s) {
    let result = "";
    for (let i = 0; i < text.length; i++) {
        let charCode = text.charCodeAt(i);
        // Uppercase
        if (charCode >= 65 && charCode <= 90) {
            result += String.fromCharCode(((charCode - 65 + s) % 26) + 65);
        }
        // Lowercase
        else if (charCode >= 97 && charCode <= 122) {
            result += String.fromCharCode(((charCode - 97 + s) % 26) + 97);
        }
        else {
            result += text[i];
        }
    }
    return result;
}

function decrypt(text, s) {
    // Handling negative shift effectively by adding 26
    return encrypt(text, (26 - (s % 26)) % 26);
}

const text = "ATTACKATONCE";
const s = 4;
console.log("Text : " + text);
console.log("Shift: " + s);
const cipher = encrypt(text, s);
console.log("Cipher: " + cipher);
console.log("Decrypted: " + decrypt(cipher, s));
