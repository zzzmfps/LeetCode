# 68ms, 81.64%; 12.6MB, 100.00%
class Solution:
    def removeDuplicates(self, S: str) -> str:
        st = []
        for c in S:
            if not st or st[-1] != c:
                st.append(c)
            else:
                st.pop()
        return ''.join(st)
