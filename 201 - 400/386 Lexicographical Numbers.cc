// 72ms, 66.42%; 11.2MB, 81.82%
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> res(n);
        int idx = 0;
        for (int i = 1; i < 10; ++i) helper(res, idx, i, n);
        return res;
    }

private:
    void helper(vector<int> &arr, int &idx, int target, int n)
    {
        if (target > n) return;
        arr[idx++] = target;
        target *= 10;
        for (int i = 0; i < 10; ++i) helper(arr, idx, target + i, n);
    }
};
