# 40ms, 100.0%
class Solution:
    def letterCombinations(self, digits):
        def generator(digits):
            if len(digits) == 1:
                for ch in letters[ord(digits[0]) - ord('0')]:
                    yield (ch,)
            else:
                for ch in letters[ord(digits[0]) - ord('0')]:
                    the_rest = generator(digits[1:])
                    for tr in the_rest:
                        yield (ch,) + tr
        
        if not digits: return []
        letters = ['', '', 'abc', 'def', 'ghi', 'jkl',
                   'mno', 'pqrs', 'tuv', 'wxyz']
        return [''.join(word) for word in generator(digits)]
    
