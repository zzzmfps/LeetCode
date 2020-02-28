# 24ms, 84.69%; 12.6MB, 100.00%
class Solution:
    def decodeString(self, s: str) -> str:
        ''' Split `s` by '[' and ']', for example:
        ### sd3[ac]2[e3[ad2[e]r]]ag
        ### sd3, ac, 2, e3, ad2, e, r, ' ', ag
        ### sd acacac e adeer adeer adeer e adeer adeer adeer ag
        '''
        s = s.replace('[', ']').split(']')
        res, st = [], []
        i, length = 0, len(s)
        while i < length:
            _new = s[i]
            if s[i].isalpha():
                while st:
                    tmp = st.pop()
                    pre, num = self.__divide_alpha_num(tmp)
                    _new = pre + _new * num
                    if not s[i + 1] or s[i + 1].isalpha():
                        i += 1
                        _new += s[i]
                    elif st:
                        i += 1
                        st.append(_new + s[i])
                        break
                else:
                    res.append(_new)
            elif _new:
                st.append(_new)
            i += 1
        return ''.join(res)

    def __divide_alpha_num(self, s: str) -> int:
        ''' Assuming that `s` consists of alpha and num followed, e.g. abc12. '''
        for i, c in enumerate(s):
            if c.isdigit(): break
        return s[:i], int(s[i:])
    
