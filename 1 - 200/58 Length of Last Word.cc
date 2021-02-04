// 4ms, 26.54%
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        for(string::reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit)
            if(*rit == ' ')
                if(count == 0) continue;
                else           break;
            else
                ++count;
        return count;
    }
};
