# 40ms, 70.63%; 13.2MB, 5.17%
from collections import Counter

class Solution:
    def mostCommonWord(self, paragraph: str, banned: list) -> str:
        tmp = paragraph.translate(''.maketrans("!?',;.", "      ")).lower().split()
        return Counter([x for x in tmp if x not in banned]).most_common(1)[0][0]
