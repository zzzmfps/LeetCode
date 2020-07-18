// 8ms, 39.68%; 2.8MB, 79.36%
func combinationSum(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	res, tmp := make([][]int, 0), make([]int, 0)
	dfs(candidates, target, &res, tmp, 0)
	return res
}

func dfs(candidates []int, target int, res *[][]int, tmp []int, index int) {
	for index < len(candidates) && candidates[index] <= target {
		tmp = append(tmp, candidates[index])
		if candidates[index] == target {
			*res = append(*res, make([]int, len(tmp))) // requires deepcopy
			copy((*res)[len(*res)-1], tmp)
			break
		} else if candidates[index] < target {
			dfs(candidates, target-candidates[index], res, tmp, index)
			index++
		}
		tmp = tmp[:len(tmp)-1]
	}
}
