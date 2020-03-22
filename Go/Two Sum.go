// 4ms, 95.04%; 3.8MB, 13.46%
func twoSum(nums []int, target int) []int {
	hashTable := make(map[int]int)
	for i, n := range nums {
		first, exist := hashTable[n]
		if exist {
			return []int{first, i}
		}
		hashTable[target-n] = i
	}
	return nil
}
