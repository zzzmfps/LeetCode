// 0ms, 100.00%; 2.1MB, 30.00%
func isValid(s string) bool {
	st := list.New() // use as a stack
	for _, ch := range s {
		// ()40,41, []91,93, {}123,125
		if ch == 40 || ch == 91 || ch == 123 {
			st.PushBack(ch)
		} else if st.Len() == 0 {
			return false
		} else {
			diff := ch - st.Back().Value.(rune)
			if diff == 1 || diff == 2 {
				st.Remove(st.Back())
			} else {
				return false
			}
		}
	}
	return st.Len() == 0
}
