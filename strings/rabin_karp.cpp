#include <cmath>
#include <iostream>
#include <string>
#include <vector>

const int ALPHABET_SIZE = 256;
const int MODULUS = 1000003;

bool rabinKarp(const std::string &pattern, const std::string &text) {
  int pLen = pattern.length();
  int tLen = text.length();

  if (pLen > tLen)
    return false;

  long long pHash = 0;
  long long textHash = 0;
  long long modulusPower = 1;

  // Calculate initial hashes
  for (int i = 0; i < pLen; ++i) {
    pHash = (pattern[i] + pHash * ALPHABET_SIZE) % MODULUS;
    textHash = (text[i] + textHash * ALPHABET_SIZE) % MODULUS;
    if (i < pLen - 1) {
      modulusPower = (modulusPower * ALPHABET_SIZE) % MODULUS;
    }
  }

  for (int i = 0; i <= tLen - pLen; ++i) {
    if (pHash == textHash) {
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
      textHash =
          (textHash - (long long)text[i] * modulusPower) * ALPHABET_SIZE +
          (long long)text[i + pLen];
      textHash %= MODULUS;
      if (textHash < 0)
        textHash += MODULUS;
    }
  }
  return false;
}

int main() {
  std::string text = "ABABDABACDABABCABAB";
  std::string pattern = "ABABCABAB";

  if (rabinKarp(pattern, text)) {
    std::cout << "Pattern found!" << std::endl;
  } else {
    std::cout << "Pattern not found." << std::endl;
  }
  return 0;
}
