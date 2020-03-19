// 4ms, 91.22%; 3.4MB, 100.00%
func minTimeToVisitAllPoints(points [][]int) int {
	res := 0
	for i := 1; i < len(points); i++ {
		dx := float64(points[i][0] - points[i-1][0])
		dy := float64(points[i][1] - points[i-1][1])
		res += int(math.Max(math.Abs(dx), math.Abs(dy)))
	}
	return res
}
