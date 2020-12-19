// 56ms, 87.08%; 12.3MB, 75.00%
class Solution
{
public:
    int subarraysDivByK(const vector<int> &A, int K)
    {
        int *nums = new int[K] {1};
        int res = 0, sum = 0;
        for (auto a : A) {
            sum = (sum + a) % K;
            if (sum < 0) sum += K;
            res += nums[sum];
            nums[sum] += 1;
        }
        delete[] nums;
        return res;
    }
};
