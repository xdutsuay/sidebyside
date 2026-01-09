package main

func Encrypt(text string, s int) string {
	result := ""
	for _, char := range text {
		if char >= 'A' && char <= 'Z' {
			char = rune((int(char) + s - 'A') % 26 + 'A')
			result += string(char)
		} else if char >= 'a' && char <= 'z' {
			char = rune((int(char) + s - ____________) % 26 + ____________)
			result += string(char)
		} else {
			result += string(char)
		}
	}
	return result
}

func Decrypt(text string, s int) string {
	return Encrypt(text, ____________-(s%____________))
}
