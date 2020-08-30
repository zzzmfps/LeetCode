# 100ms, 88.06%; 14.2MB, 100.00%
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        st, deleted = [], []
        for i, c in enumerate(s):
            if c == '(':
                st.append(i)
            elif c == ')':
                if st:
                    st.pop()
                else:
                    deleted.append(i)
        while st:
            deleted.append(st.pop())
        if not deleted: return s

        deleted.sort()
        deleted.append(len(s))
        res, i = [], 0
        for j in deleted:
            res.append(s[i:j])
            i = j + 1
        return ''.join(res)
