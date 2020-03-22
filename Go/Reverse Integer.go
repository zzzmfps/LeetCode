// 0ms, 100.00%; 2.2MB, 80.00%
func reverse(x int) int {
	res := 0
	for x != 0 {
		res = res*10 + x%10
		x /= 10
	}
	if res < -2147483648 || res > 2147483647 {
		res = 0
	}
	return res
}
