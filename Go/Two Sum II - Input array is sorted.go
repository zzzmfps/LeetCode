// 4ms, 95.14%; 3MB, 100.00%
func twoSum(numbers []int, target int) []int {
	i, j := 0, len(numbers)-1
	for {
		sum := numbers[i] + numbers[j]
		if sum < target {
			i++
		} else if sum > target {
			j--
		} else {
			break
		}
	}
	return []int{i + 1, j + 1}
}
