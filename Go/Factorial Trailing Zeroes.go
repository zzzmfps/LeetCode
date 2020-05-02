// 0ms, 100.00%; 2MB, 66.67%
func trailingZeroes(n int) int {
	ret := 0
	for n > 0 {
		n /= 5
		ret += n
	}
	return ret
}
