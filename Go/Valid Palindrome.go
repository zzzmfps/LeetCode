// 0ms, 100.00%; 2.7MB, 100.00%
func isPalindrome(s string) bool {
	for i, j := 0, len(s)-1; ; i, j = i+1, j-1 {
		for ; i < len(s) && isNotNumAlpha(s[i]); i++ {
		}
		for ; j > -1 && isNotNumAlpha(s[j]); j-- {
		}
		if i >= j {
			break
		}
		if (s[i] | 32) != (s[j] | 32) { // to lowercase
			return false
		}
	}
	return true
}

func isNotNumAlpha(r byte) bool {
	// numeric: 48 ~ 57
	// alpha, uppercase: 65 ~ 90
	// alpha, lowercase: 97 ~ 122
	return r < 48 || r > 57 && r < 65 || r > 90 && r < 97 || r > 122
}
