// 7ms, 9.09%
class Solution
{
public:
    int titleToNumber(string s)
    {
        int ans = 0, end = s.length();
        for(int ridx = 0; ridx < end; ++ridx)
            ans += pow(26, ridx) * int(s[end - ridx - 1] - 'A' + 1);
        return ans;
    }
};
