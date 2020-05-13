// 0ms, 100.00%; 2.1MB, 100.00%
func checkPerfectNumber(num int) bool {
	if num < 6 {
		return false
	}
	target := num - 1
	for i, j := 2, int(math.Sqrt(float64(num))); i <= j; i++ {
		k := num / i
		if i*k != num {
			continue
		}
		target -= i + k
		if target < 0 || target > 0 && target < i+j {
			break
		}
	}
	return 0 == target
}
