// 8ms, 23.63%
class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int index = 0;
        for(auto x : nums)
        {
            if(x >= target)
                break;
            ++index;
        }
        return index;
    }
};
