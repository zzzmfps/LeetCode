// 0ms, 100.00%; 2.1MB, 100.00%
func lengthOfLastWord(s string) int {
	idx1 := rfind(s, len(s)-1, false)
	if idx1 < 0 {
		return 0
	}
	idx2 := rfind(s, idx1-1, true)
	return idx1 - idx2
}

func rfind(s string, i int, findSpace bool) int {
	for ; i > -1; i-- {
		if (s[i] == ' ') == findSpace {
			break
		}
	}
	return i
}
