// 0ms, 100.00%; 1.9MB, 87.50%
func bulbSwitch(n int) int {
	m, count := 1, 0
	for m*m <= n {
		m++
		count++
	}
	return count
}
