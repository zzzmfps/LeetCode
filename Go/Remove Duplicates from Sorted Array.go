// 8ms, 90.55%; 4.6MB, 100.00%
func removeDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	length, last := 1, nums[0]
	for i := 1; i < len(nums); i++ {
		if nums[i] != last {
			nums[length] = nums[i]
			last = nums[i]
			length++
		}
	}
	return length
}
