# 24ms, 86.36%; 12.8MB, 100.00%
class Solution:
    def lengthLongestPath(self, input: str) -> int:
        # (level, length, isFile)
        input = [(x.count('\t'), len(x.lstrip('\t')), ('.' in x)) for x in input.split('\n')]
        st, cur_len = [input[0]], input[0][1]
        max_len = cur_len if input[0][2] else 0
        for i in range(1, len(input)):
            level, length, is_file = input[i]
            while len(st) > level:
                cur_len -= 1 + st.pop()[1]
            st.append(input[i])
            cur_len += 1 + length
            if is_file: max_len = max(max_len, cur_len)
        return max_len
