// 0ms, 100.00%; 2.2MB, 7.01%
func myPow(x float64, n int) float64 {
	if n < 0 {
		return 1.0 / helper(x, -int64(n))
	}
	return helper(x, int64(n))
}

func helper(x float64, n int64) float64 {
	ret := 1.0
	if (n & 1) == 1 {
		ret = x
		n--
	}
	switch n {
	case 0:
		return ret
	case 1:
		return ret * x
	case 2:
		return ret * x * x
	default:
		return ret * helper(helper(x, n/2), 2)
	}
}
