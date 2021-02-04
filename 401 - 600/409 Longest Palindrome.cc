// 6ms, 96.16%
class Solution {
public:
    int longestPalindrome(string s) {        
        int memo[52] = {};
        for (auto ch : s)
            if (ch < 91)    // < 'Z' + 1
                memo[ch - 65] += 1;    // - 'A'
            else
                memo[ch - 71] += 1;    // - 'a' + 26
        int res = 1, length = s.size();
        for (auto m : memo)
            if (m > 1) res += m & 0xFFFFFFFE;
        return res < length ? res : length;
    }
};
