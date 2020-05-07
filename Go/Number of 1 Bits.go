// 0ms, 100.00%; 2MB, 100.00%
var digits = []int{0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4}

func hammingWeight(num uint32) int {
	ret := 0
	for ; num > 0; num >>= 4 {
		ret += digits[num&0xf]
	}
	return ret
}
