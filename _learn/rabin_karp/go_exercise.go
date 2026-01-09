package main

// Constants omitted

func RabinKarp(pattern, text string) bool {
	// ...

	for i := 0; i <= tLen-pLen; i++ {
		if pHash == textHash {
			if text[i:i+pLen] == pattern {
				return true
			}
		}

		if i < tLen-pLen {
			// Rolling hash
			textHash = (textHash - int64(text[i])*____________) * ____________
			textHash += int64(text[i+pLen])
			textHash %= modulus
			// ...
		}
	}
	return false
}
