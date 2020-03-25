// 0ms, 100.00%; 2.3MB, 87.50%
func strStr(haystack string, needle string) int {
	end := len(haystack) - len(needle) + 1
	for i := 0; i < end; i++ {
		flag := true
		for j := 0; j < len(needle); j++ {
			if haystack[i+j] != needle[j] {
				flag = false
				break
			}
		}
		if flag {
			return i
		}
	}
	return -1
}
