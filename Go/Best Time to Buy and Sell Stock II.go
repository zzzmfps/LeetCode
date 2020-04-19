// 4ms, 92.66%; 3.1MB, 100.00%
func maxProfit(prices []int) int {
	res, minPrice, length := 0, 0x7fffffff, len(prices)
	for i := 0; i < length; {
		for ; i < length && prices[i] <= minPrice; i++ {
			minPrice = prices[i]
		}
		if i == length {
			break
		}
		for ; i < length && prices[i] >= prices[i-1]; i++ {
		}
		res += prices[i-1] - minPrice
		minPrice = 0x7fffffff
	}
	return res
}
