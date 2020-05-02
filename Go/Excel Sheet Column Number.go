// 0ms, 100.00%; 2.2MB, 50.00%
func titleToNumber(s string) int {
	ret := 0
	for _, c := range s {
		ret = ret*26 + int(c) - 64
	}
	return ret
}
