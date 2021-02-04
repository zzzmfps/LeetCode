// 30ms, 57.85%
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.empty()) return 0;
        int maxLen = 1, count = 1;
        for(int i = s.length() - 1, j = i; i > 0; --i)
        {
            int index = s.find(s[i - 1], i);
            if(index != string::npos)
            {
                j = index - 1;
                s.resize(index);
                count = index - i + 1;
            }              
            else
                ++count;
            maxLen = count > maxLen ? count : maxLen;
        }
        return maxLen;
    }
};
