// 4ms, 98.98%; 5.4MB, 25.00%
func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	str := strconv.Itoa(x)
	length := len(str)
	for i := length >> 1; i > -1; i-- {
		if str[i] != str[length-i-1] {
			return false
		}
	}
	return true
}
