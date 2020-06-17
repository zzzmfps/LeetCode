// 0ms, 100.00%; 2.5MB, 100.00%
func divide(dividend, divisor int) int {
	if dividend == divisor {
		return 1
	}
	if dividend == 0 || divisor == -2147483648 {
		return 0
	}
	if dividend == -2147483648 && divisor == -1 {
		return 2147483647
	}
	negative := (dividend < 0) != (divisor < 0)
	dividend = ternary(dividend < 0, dividend, -dividend)
	divisor = ternary(divisor < 0, divisor, -divisor)

	res, exp := 0, maxExp(dividend, divisor)
	for dividend <= divisor {
		res += (1 << exp)
		dividend -= (divisor << exp)
		for exp > 0 && dividend > (divisor<<exp) {
			exp--
		}
	}
	return ternary(negative, -res, res)
}

func maxExp(dividend, divisor int) int {
	halfIntMin := -1073741825
	limit := ternary(halfIntMin > dividend, halfIntMin, dividend)
	count := 0
	for limit < divisor {
		divisor <<= 1
		count++
	}
	return ternary(count == 0, 0, count-1)
}

func ternary(flag bool, x, y int) int {
	if flag {
		return x
	}
	return y
}
