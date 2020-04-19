// 4ms, 93.94%; 3.1MB, 25.00%
func maxProfit(prices []int) int {
	res, minPrice := 0, 0x7fffffff
	for _, p := range prices {
		res = max(res, p-minPrice)
		minPrice = min(minPrice, p)
	}
	return res
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
