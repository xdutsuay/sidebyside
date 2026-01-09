package main

// ... imports

func translateMessage(key, message string, encrypt bool) string {
	// ...

	for _, symbol := range message {
		// ...
		if index != -1 {
			// ...

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
            
            // ...

			keyIndex++
			if keyIndex == len(key) {
				keyIndex = ____________
			}
		} else {
			translated += string(symbol)
		}
	}
	return translated
}
