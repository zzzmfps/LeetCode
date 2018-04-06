# 56ms, 96.89%
class Solution:
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        index, pre_char, cur_num, i = 1, 0, 1, 1
        while i < len(chars):
            if chars[pre_char] == chars[i]:
                cur_num += 1
            else:
                if cur_num == 1:
                    pre_char = i
                else:
                    tmp_lst = list(str(cur_num))
                    chars[index: i] = tmp_lst
                    index += len(tmp_lst)
                    pre_char = i = index
                index += 1
                cur_num = 1
            i += 1
        chars[index:] = [] if cur_num == 1 else list(str(cur_num))
        return len(chars)
                
