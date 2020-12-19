# 32ms, 32.71%; 12.7MB, 100.00%
class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        st = []
        for c in S:
            if st and st[-1] == '(' and c == ')':
                st.pop()
            else:
                st.append(c)
        return len(st)
