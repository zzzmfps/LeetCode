// 0ms, 100.00%; 2.1MB, 100.00%
func plusOne(digits []int) []int {
	for i := len(digits) - 1; i > -1; i-- {
		if digits[i] < 9 {
			digits[i]++
			return digits
		}
		digits[i] = 0
	}
	arr := make([]int, len(digits)+1)
	arr[0] = 1
	return arr
}
