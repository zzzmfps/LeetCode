// 4ms, 63.30%; 7.7MB, 100.00%
class Solution
{
public:
    int heightChecker(const vector<int> &heights)
    {
        vector<int> tmp(heights);
        sort(tmp.begin(), tmp.end());
        int count = 0;
        for (int i = 0; i < heights.size(); ++i)
            if (heights[i] != tmp[i]) count += 1;
        return count;
    }
};
