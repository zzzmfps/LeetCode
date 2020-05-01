// 0ms, 100.00%; 2MB, 100.00%
const alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

func convertToTitle(n int) string {
	title := make([]byte, 0, 1)
	for n > 0 {
		m := (n - 1) % 26
		title = append(title, alphabet[m])
		n = (n - 1) / 26
	}
	reverse(title)
	return string(title)
}

func reverse(arr []byte) {
	i, j := 0, len(arr)-1
	for i < j {
		arr[i], arr[j] = arr[j], arr[i]
		i, j = i+1, j-1
	}
}
