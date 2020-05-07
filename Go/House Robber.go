// 0ms, 100.00%; 2MB, 100.00%
func rob(nums []int) int {
	length := len(nums)
	switch length {
    case 0:
        return 0
	case 1:
		return nums[0]
	case 2:
		return max(nums[0], nums[1])
	default:
		dp := make([]int, length, length)
		dp[0], dp[1] = nums[0], max(nums[0], nums[1])
		for i := 2; i < length; i++ {
			dp[i] = max(dp[i-2]+nums[i], dp[i-1])
		}
		return dp[length-1]
	}
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
