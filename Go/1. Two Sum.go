// 4ms, 95.20%; 3MB, 61.54%
func twoSum(nums []int, target int) []int {
	length := len(nums)
	newNums := make([]int, length)
	copy(newNums, nums)
	sort.Ints(newNums)
	i, j := 0, length-1
	for i < j {
		tmp := newNums[i] + newNums[j]
		if tmp == target {
			break
		} else if tmp < target {
			i++
		} else {
			j--
		}
	}
	v1, v2 := newNums[i], newNums[j]
	for k := 0; ; k++ {
		if nums[k] == v1 {
			i = k
			break
		}
	}
	for k := length - 1; ; k-- {
		if nums[k] == v2 {
			j = k
			break
		}
	}
	return []int{i, j}
}
