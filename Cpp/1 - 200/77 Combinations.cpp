// 60ms, 99.95%; 11.8MB, 81.82%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> p(k, 0);
        int i = 0;
        while(i >= 0) {
            ++p[i];
            if(p[i] > n - k + 1 + i) {
                --i;
            } else if(i == k - 1) {
                result.push_back(p);
            } else {
                while(i < k - 2) p[++i] = 1 + p[i];
                p[++i] = p[i];
            }
        }
        return result;
    }
};
