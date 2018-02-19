// 11ms, 37.70%
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int tmp = 0;
        int ans = nums[0];
        for(int i = 0; i < n; ++i)
        {
            tmp += nums[i];
            ans = max(tmp, ans);
            tmp = max(tmp, 0);
        }
        return ans;
    }
};
