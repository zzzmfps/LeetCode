// 6ms, 16.86%
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string res = "", nums = "";
        for(int i = 0; i < n; ++i) nums += i + '1';
        getNext(res, nums, n, k - 1);
        return res;
    }
    
private:
    void getNext(string &res, string &nums, int n, int k)
    {
        static int fact[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
        if(n == 0 || k > fact[n]) return;
        int tmpIdx = k / fact[n - 1];
        res += nums[tmpIdx];
        nums.erase(tmpIdx, 1);
        getNext(res, nums, n - 1, k % fact[n - 1]);
    }
};
