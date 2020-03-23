// 0ms, 100.00%; 2.4MB, 25.00%
func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	minLen := 0x7fffffff
	for _, str := range strs { // min length
		if minLen > len(str) {
			minLen = len(str)
		}
	}
	for i := 0; i < minLen; i++ {
		tmp := strs[0][i]
		for _, str := range strs {
			if tmp != str[i] {
				return strs[0][0:i]
			}
		}
	}
	return strs[0][0:minLen]
}
