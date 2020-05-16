// 8ms, 14.06%; 3.9MB, 100.00%
func moveZeroes(nums []int) {
	i := 0
	for j := 1; j < len(nums); j++ {
		if nums[i] != 0 {
			i++
		} else if nums[j] != 0 {
			nums[i], nums[j] = nums[j], nums[i]
			i++
		}
	}
}
