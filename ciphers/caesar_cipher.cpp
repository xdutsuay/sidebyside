#include <iostream>
#include <string>

std::string encrypt(std::string text, int s) {
  std::string result = "";
  // traverse text
  for (int i = 0; i < text.length(); i++) {
    // apply transformation to each character
    // Encrypt Uppercase letters
    if (isupper(text[i]))
      result += char(int(text[i] + s - 65) % 26 + 65);
    // Encrypt Lowercase letters
    else if (islower(text[i]))
      result += char(int(text[i] + s - 97) % 26 + 97);
    else
      result += text[i];
  }
  return result;
}

std::string decrypt(std::string text, int s) {
  return encrypt(text, 26 - (s % 26));
}

int main() {
  std::string text = "ATTACKATONCE";
  int s = 4;
  std::cout << "Text : " << text << std::endl;
  std::cout << "Shift: " << s << std::endl;
  std::string cipher = encrypt(text, s);
  std::cout << "Cipher: " << cipher << std::endl;
  std::cout << "Decrypted: " << decrypt(cipher, s) << std::endl;
  return 0;
}
