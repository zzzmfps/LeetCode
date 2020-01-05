# 68ms, 86.78%; 14.4MB, 100.00%
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        st = []
        for c in s:
            if not st or st[-1][0] != c:
                st.append([c, 1])
            else:
                st[-1][1] += 1
                if st[-1][1] == k: st.pop()
        return ''.join([x * count for x, count in st])
