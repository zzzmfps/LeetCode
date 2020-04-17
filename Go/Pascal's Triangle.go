// 0ms, 100.00%; 2MB, 100.00%
func generate(numRows int) [][]int {
	tri := make([][]int, numRows, numRows)
	for i := 0; i < numRows; i++ {
		tri[i] = make([]int, i+1, i+1)
		tri[i][0], tri[i][i] = 1, 1
		for j := 1; j < i; j++ {
			tri[i][j] = tri[i-1][j-1] + tri[i-1][j]
		}
	}
	return tri
}
