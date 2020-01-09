// 0ms, 100.00%; 2.4MB, 100.00%
func minAddToMakeValid(S string) int {
	st := list.New()
	for _, c := range S {
		if st.Len() > 0 && st.Back().Value == '(' && c == ')' {
			st.Remove(st.Back())
		} else {
			st.PushBack(c)
		}
	}
	return st.Len()
}
