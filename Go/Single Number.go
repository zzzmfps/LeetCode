// 4ms, 99.32%; 4.7MB, 100.00%
func singleNumber(nums []int) int {
	res := 0
	for _, n := range nums {
		res ^= n
	}
	return res
}
