// 4ms, 31.14%; 2.5MB, 32.74%
type sortSlice []int

func (s sortSlice) Len() int {
	return len(s)
}
func (s sortSlice) Less(i, j int) bool {
	return s[i] < s[j]
}
func (s sortSlice) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func nextPermutation(nums []int) {
	index := inverseLastOrderPair(nums)
	sort.Sort(sortSlice(nums[index+1:]))
}

func inverseLastOrderPair(nums []int) int {
	for cur := len(nums) - 2; cur >= 0; cur-- {
		for i := len(nums) - 1; i > cur; i-- {
			if nums[cur] < nums[i] {
				nums[cur], nums[i] = nums[i], nums[cur]
				return cur
			}
		}
	}
	return -1
}
