package main

import (
	"fmt"
	"strings"
	"unicode"
)

func translateMessage(key, message string, encrypt bool) string {
	letters := "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	translated := ""
	keyIndex := 0
	key = strings.ToUpper(key)

	for _, symbol := range message {
		upperSymbol := unicode.ToUpper(symbol)
		index := strings.IndexRune(letters, upperSymbol)

		if index != -1 {
			num := index
			keyVal := strings.IndexByte(letters, key[keyIndex])

			if encrypt {
				num += keyVal
			} else {
				num -= keyVal
			}

			if num < 0 {
				num += 26
			} else {
				num %= 26
			}

			if unicode.IsUpper(symbol) {
				translated += string(letters[num])
			} else {
				translated += strings.ToLower(string(letters[num]))
			}

			keyIndex++
			if keyIndex == len(key) {
				keyIndex = 0
			}
		} else {
			translated += string(symbol)
		}
	}
	return translated
}

func main() {
	text := "This is Harshil Darji from Dharmaj."
	key := "HDarji"

	encrypted := translateMessage(key, text, true)
	fmt.Println("Encrypted:", encrypted)
	decrypted := translateMessage(key, encrypted, false)
	fmt.Println("Decrypted:", decrypted)
}
