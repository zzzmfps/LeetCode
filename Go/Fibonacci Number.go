// 0ms, 100.00%; 1.9MB, 100.00%
func fib(N int) int {
	if N == 0 {
		return 0
	}
	a, b := 0, 1
	for i := 2; i <= N; i++ {
		a, b = b, a+b
	}
	return b
}
