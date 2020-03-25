// 4ms, 84.16%; 3.1MB, 100.00%
func searchInsert(nums []int, target int) int {
	i, j := 0, len(nums)-1
	if nums[j] < target {
		return len(nums)
	}
	for i < j {
		mid := i + (j-i)/2
		if nums[mid] < target {
			i = mid + 1
		} else {
			j = mid
		}
	}
	return i
}
