// 0ms, 100.00%; 2.2MB, 83.33%
func mySqrt(x int) int {
	if x < 2 {
		return x
	}
	res := x >> 1
	for {
		tmp := (res + x/res) >> 1
		if tmp >= res {
			break
		}
		res = tmp
	}
	return res
}
