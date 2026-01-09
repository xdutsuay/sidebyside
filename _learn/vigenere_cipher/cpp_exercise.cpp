#include <iostream>
#include <string>
// ... includes

std::string translateMessage(std::string key, std::string message,
                             bool encrypt) {
  // ... setup
  for (char symbol : message) {
    if (isalpha(symbol)) {
      // ... find index of symbol

      // ... find index of key char at keyIndex

      if (encrypt) {
        num += keyVal;
      } else {
        num -= keyVal;
      }

      // Handle negative wrap properly
      if (num < 0) {
        num += ____________;
      } else {
        num %= ____________;
      }

      // ... append char

      keyIndex++;
      if (keyIndex == key.length()) {
        keyIndex = ____________;
      }
    } else {
      translated += symbol;
    }
  }
  return translated;
}
