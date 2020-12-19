// 6ms, 81.99%
class Solution
{
public:
    string longestPalindrome(const string& s)
    {
        if (s.empty() || s.size() == 1) return s;
        
        int start = 0, maxLen = 1;
        for (int index = 0; index < s.size();) 
        {
            if (s.size() - index <= maxLen / 2) break;
            int beg = index, end = index;
            while (end < s.size() - 1 && s[end] == s[end + 1]) 
                ++end;
            index = end + 1;
            while (end < s.size() - 1 && beg > 0 && s[beg - 1] == s[end + 1]) 
                --beg, ++end;
            int newLen = end - beg + 1;
            if (newLen > maxLen)
            {
                start = beg;
                maxLen = newLen; 
            }
        }
        return s.substr(start, maxLen);
    }
};
