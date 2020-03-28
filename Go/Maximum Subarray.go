// 4ms, 94.72%; 3.3MB, 57.14%
func maxSubArray(nums []int) int {
	res, cur := nums[0], nums[0]
	for i := 1; i < len(nums); i++ {
		if cur < 0 {
			cur = nums[i]
		} else {
			cur += nums[i]
		}
		if res < cur {
			res = cur
		}
	}
	return res
}
