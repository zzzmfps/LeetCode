// 0ms, 100.00%; 6.4MB, 50.00%
func countAndSay(n int) string {
	res := "1"
	for i := 1; i < n; i++ {
		tmp, count, last := "", 0, rune(res[0])
		for _, c := range res {
			if c == last {
				count++
			} else {
				tmp += strconv.Itoa(count) + string(last)
				count, last = 1, c
			}
		}
		res = tmp + strconv.Itoa(count) + string(last)
	}
	return res
}
