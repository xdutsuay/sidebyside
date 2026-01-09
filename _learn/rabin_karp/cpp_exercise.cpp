#include <iostream>
#include <string>

// Constants omitted

bool rabinKarp(const std::string &pattern, const std::string &text) {
  // ... setup omitted

  for (int i = 0; i <= tLen - pLen; ++i) {
    if (pHash == textHash) {
      // Check literal match
      bool match = true;
      for (int k = 0; k < pLen; k++) {
        if (text[i + k] != pattern[k]) {
          match = false;
          break;
        }
      }
      if (match)
        return true;
    }

    if (i < tLen - pLen) {
      // Rolling Hash:
      // 1. Remove leading char
      // 2. Multiply by base (shift left)
      // 3. Add new trailing char
      textHash = (textHash - (long long)text[i] * ____________) * ____________ +
                 (long long)text[i + pLen];
      textHash %= MODULUS;
      if (textHash < 0)
        textHash += MODULUS;
    }
  }
  return false;
}
