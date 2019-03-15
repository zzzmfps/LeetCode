# 48ms, 39.91%; 13MB, 5.00%
class Solution:
    def simplifyPath(self, path: str) -> str:
        tmp = [x for x in path.split('/') if x and x != '.']
        st = []
        for t in tmp:
            if t == '..':
                if st: st.pop()
            else:
                st.append(t)
        return '/' + '/'.join(st)
