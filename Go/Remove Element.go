// 0ms, 100.00%; 2.1MB, 100.00%
func removeElement(nums []int, val int) int {
	length := 0
	for _, n := range nums {
		if n != val {
			nums[length] = n
			length++
		}
	}
	return length
}
