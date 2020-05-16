// 0ms, 100.00%; 2.1MB, 100.00%
var cache = make(map[int]bool)

func isHappy(n int) bool {
	tmp, mark := make(map[int]bool), true
	for n > 1 {
		if _, ok := cache[n]; ok {
			mark = cache[n]
			break
		}
		if _, ok := tmp[n]; ok {
			mark = false
			break
		}
		tmp[n] = true
		n = convert(n)
	}
	for v := range tmp {
		cache[v] = mark
	}
	return mark
}

func convert(n int) int {
	ret := 0
	for _, ch := range strconv.Itoa(n) {
		ret += int(math.Pow(float64(int(ch)-48), 2.0))
	}
	return ret
}
