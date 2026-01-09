/**
 * Caesar Cipher - FILL IN THE BLANKS
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
            result += String.fromCharCode(((charCode - ____________ + s) % 26) + ____________);
        }
        else {
            result += text[i];
        }
    }
    return result;
}

function decrypt(text, s) {
    // Reverse the shift
    return encrypt(text, (26 - (s % 26)) % 26);
}
