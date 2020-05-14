// 24ms, 91.76%; 6.2MB, 100.00%
func checkPossibility(nums []int) bool {
	count, prev := 1, [2]int{-2147483648, -2147483648}
	for _, n := range nums {
		if prev[1] > n {
			if count == 0 {
				return false
			}
			count--
			if prev[0] <= n {
				prev[1] = n
			}
		} else {
			prev[0], prev[1] = prev[1], n
		}
	}
	return true
}
