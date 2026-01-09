package main

import (
	"fmt"
)

func Encrypt(text string, s int) string {
	result := ""
	for _, char := range text {
		if char >= 'A' && char <= 'Z' {
			char = rune((int(char) + s - 'A') % 26 + 'A')
			result += string(char)
		} else if char >= 'a' && char <= 'z' {
			char = rune((int(char) + s - 'a') % 26 + 'a')
			result += string(char)
		} else {
			result += string(char)
		}
	}
	return result
}

func Decrypt(text string, s int) string {
	return Encrypt(text, 26-(s%26))
}

func main() {
	text := "ATTACKATONCE"
	s := 4
	fmt.Println("Text :", text)
	fmt.Println("Shift:", s)
	cipher := Encrypt(text, s)
	fmt.Println("Cipher:", cipher)
	fmt.Println("Decrypted:", Decrypt(cipher, s))
}
