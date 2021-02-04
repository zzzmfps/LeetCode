// 8ms, 5.70%
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        m -= 1, n -= 1;
        while(m >= 0 && n >= 0)
            nums1[m + n + 1] = nums1[m] < nums2[n] ? nums2[n--] : nums1[m--];
        if(m)
            for(; n >= 0; --n)
                nums1[n] = nums2[n];
    }
};
