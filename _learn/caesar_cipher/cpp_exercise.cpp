#include <iostream>
#include <string>

std::string encrypt(std::string text, int s) {
  std::string result = "";
  for (int i = 0; i < text.length(); i++) {
    // Encrypt Uppercase letters
    if (isupper(text[i]))
      result += char(int(text[i] + s - 65) % 26 + 65);
    // Encrypt Lowercase letters
    else if (islower(text[i]))
      result += char(int(text[i] + s - ____________) % 26 + ____________);
    else
      result += text[i];
  }
  return result;
}

std::string decrypt(std::string text, int s) {
  return encrypt(text, ____________ - (s % ____________));
}
