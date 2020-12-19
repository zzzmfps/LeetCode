// 19ms, 52.76%
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int major = nums[0], count = 0;
        for(auto x : nums)
        {
            if(x == major) ++count;
            else           --count;
            if(!count)
            {
                major = x;
                count = 1;
            }
        }
        return major;
    }
};
