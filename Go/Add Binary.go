// 0ms, 100.00%; 2.2MB, 100.00%
func newString(n int, ch byte) string {
	res := make([]byte, n)
	for i := 0; i < len(res); i++ {
		res[i] = ch
	}
	return string(res)
}

func addBinary(a string, b string) string {
	if len(a) < len(b) {
		a = newString(len(b)-len(a), '0') + a
	} else {
		b = newString(len(a)-len(b), '0') + b
	}

	carry, length := byte('0'), len(a)
	res := make([]byte, length+1)
	for i := 0; i < length; i++ {
		d1, d2 := a[length-i-1], b[length-i-1]
		if d1 == d2 {
			res[length-i] = carry
			carry = d1
		} else {
			res[length-i] = 97 - carry
		}
	}
	if carry == '1' {
		res[0] = carry
		return string(res)
	}
	return string(res[1:])
}
