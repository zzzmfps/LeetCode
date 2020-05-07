// 4ms, 95.76%; 3.2MB, 100.00%
func rotate(nums []int, k int) {
	k %= len(nums)
	if k == 0 {
		return
	}
	beg, last := 0, nums[0]
	for i, j := k, 1; j < len(nums); i, j = (i+k)%len(nums), j+1 {
		last, nums[i] = nums[i], last
		if i == beg {
			i, beg = i+1, beg+1
			last = nums[i]
		}
	}
	nums[beg] = last
}
