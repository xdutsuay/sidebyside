#include <cctype>
#include <iostream>
#include <string>
#include <vector>

std::string translateMessage(std::string key, std::string message,
                             bool encrypt) {
  std::string translated = "";
  int keyIndex = 0;
  std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for (int i = 0; i < key.length(); i++) {
    key[i] = toupper(key[i]);
  }

  for (char symbol : message) {
    if (isalpha(symbol)) {
      int num = -1;
      char upperSymbol = toupper(symbol);
      for (int i = 0; i < 26; i++) {
        if (letters[i] == upperSymbol) {
          num = i;
          break;
        }
      }

      int keyVal = -1;
      for (int i = 0; i < 26; i++) {
        if (letters[i] == key[keyIndex]) {
          keyVal = i;
          break;
        }
      }

      if (encrypt) {
        num += keyVal;
      } else {
        num -= keyVal;
      }

      // Handle negative wrap around manually for safety or just use correct
      // logic In Python % handles negatives well, in C++ % can return negative.
      if (num < 0) {
        num += 26;
      } else {
        num %= 26;
      }

      if (isupper(symbol)) {
        translated += letters[num];
      } else {
        translated += tolower(letters[num]);
      }

      keyIndex++;
      if (keyIndex == key.length()) {
        keyIndex = 0;
      }
    } else {
      translated += symbol;
    }
  }
  return translated;
}

int main() {
  std::string text = "This is Harshil Darji from Dharmaj.";
  std::string key = "HDarji";

  std::string encrypted = translateMessage(key, text, true);
  std::cout << "Encrypted: " << encrypted << std::endl;
  std::string decrypted = translateMessage(key, encrypted, false);
  std::cout << "Decrypted: " << decrypted << std::endl;
  return 0;
}
