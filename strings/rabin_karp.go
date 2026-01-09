package main

import "fmt"

const alphabetSize = 256
const modulus = 1000003

func RabinKarp(pattern, text string) bool {
	pLen := len(pattern)
	tLen := len(text)

	if pLen > tLen {
		return false
	}

	var pHash, textHash, modulusPower int64 = 0, 0, 1

	for i := 0; i < pLen; i++ {
		pHash = (int64(pattern[i]) + pHash*alphabetSize) % modulus
		textHash = (int64(text[i]) + textHash*alphabetSize) % modulus
		if i < pLen-1 {
			modulusPower = (modulusPower * alphabetSize) % modulus
		}
	}

	for i := 0; i <= tLen-pLen; i++ {
		if pHash == textHash {
			if text[i:i+pLen] == pattern {
				return true
			}
		}

		if i < tLen-pLen {
			textHash = (textHash - int64(text[i])*modulusPower) * alphabetSize
			textHash += int64(text[i+pLen])
			textHash %= modulus
			if textHash < 0 {
				textHash += modulus
			}
		}
	}
	return false
}

func main() {
	text := "ABABDABACDABABCABAB"
	pattern := "ABABCABAB"
	
	if RabinKarp(pattern, text) {
		fmt.Println("Pattern found!")
	} else {
		fmt.Println("Pattern not found.")
	}
}
