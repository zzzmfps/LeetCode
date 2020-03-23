// 8ms, 59.35%; 3.1MB, 14.29%
var hashTable = map[byte][2]int{'I': {1, 1}, 'V': {2, 5}, 'X': {3, 10},
	'L': {4, 50}, 'C': {5, 100}, 'D': {6, 500}, 'M': {7, 1000}}

func romanToInt(s string) int {
	res, last := 0, 0
	for i := len(s) - 1; i > -1; i-- {
		vals, _ := hashTable[s[i]]
		if vals[0] < last {
			res -= vals[1]
		} else {
			res += vals[1]
		}
		last = vals[0]
	}
	return res
}
