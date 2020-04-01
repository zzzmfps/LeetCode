// 16ms, 93.95%; 6MB, 50.00%
func majorityElement(nums []int) int {
	val, count := nums[0], 0
	for _, n := range nums {
		if n == val {
			count++
		} else if count > 1 {
			count--
		} else {
			val = n
		}
	}
	return val
}
